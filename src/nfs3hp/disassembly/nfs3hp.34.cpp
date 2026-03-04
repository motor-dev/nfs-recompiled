#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4ec2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4ec4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004e4ec9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4ecb  e8a0feffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4ed0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ed1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4ee2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e4ee4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4ee6  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 004e4eeb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4eed  e86efdffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e4ef2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ef3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ef4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e4f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4f02  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4f04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4f06  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 004e4f0b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4f0d  e84efdffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e4f12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e4f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4f22  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e4f24  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 004e4f29  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4f2b  e840feffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4f30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4f40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4f41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4f42  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4f44  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 004e4f49  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4f4b  e820feffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4f50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4f62  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e4f64  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 004e4f69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4f6b  e800feffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4f70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4f82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4f84  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 004e4f89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4f8b  e8e0fdffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4f90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e4fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4fa2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e4fa4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4fa6  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004e4fab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4fad  e8aefcffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e4fb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4fb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4fb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e4fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4fc2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4fc4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4fc6  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004e4fcb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4fcd  e88efcffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e4fd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4fd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4fd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e4fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e4fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e4fe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4fe2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e4fe4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004e4fe9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e4feb  e880fdffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e4ff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e5000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e5001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e5002  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e5004  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004e5009  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e500b  e860fdffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e5010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e5020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e5021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e5022  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e5024  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004e5029  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e502b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e502d  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e5032  e829fcffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e5037  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5038  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5039  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e5040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e5041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e5042  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e5044  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004e5049  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e504b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e504d  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e5052  e809fcffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e5057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5058  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e5060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e5061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e5062  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e5064  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004e5069  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e506b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e506d  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e5072  e8e9fbffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e5077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5078  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e5080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e5081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e5082  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e5084  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004e5089  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e508b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e508d  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e5092  e8c9fbffff             -call 0x4e4c60
    cpu.esp -= 4;
    sub_4e4c60(app, cpu);
    if (cpu.terminate) return;
    // 004e5097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5098  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e50a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e50a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e50a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e50a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e50a4  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 004e50a9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e50ab  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e50b0  e8bbfcffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e50b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e50b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e50b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e50c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e50c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e50c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e50c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e50c4  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 004e50c9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e50cb  ba44a75400             -mov edx, 0x54a744
    cpu.edx = 5547844 /*0x54a744*/;
    // 004e50d0  e89bfcffff             -call 0x4e4d70
    cpu.esp -= 4;
    sub_4e4d70(app, cpu);
    if (cpu.terminate) return;
    // 004e50d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e50d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e50d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e50e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e50e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e50e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e50e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e50e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e50e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e50e6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e50e8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e50ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e50ef  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e50f5  837b7800               +cmp dword ptr [ebx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e50f9  7425                   -je 0x4e5120
    if (cpu.flags.zf)
    {
        goto L_0x004e5120;
    }
L_0x004e50fb:
    // 004e50fb  46                     -inc esi
    (cpu.esi)++;
    // 004e50fc  8b4378                 -mov eax, dword ptr [ebx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(120) /* 0x78 */);
    // 004e50ff  8b9098000000           -mov edx, dword ptr [eax + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004e5105  895378                 -mov dword ptr [ebx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004e5108  e813190000             -call 0x4e6a20
    cpu.esp -= 4;
    sub_4e6a20(app, cpu);
    if (cpu.terminate) return;
    // 004e510d  837b7800               +cmp dword ptr [ebx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5111  75e8                   -jne 0x4e50fb
    if (!cpu.flags.zf)
    {
        goto L_0x004e50fb;
    }
    // 004e5113  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e5119  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e511f  90                     -nop 
    ;
L_0x004e5120:
    // 004e5120  8b4378                 -mov eax, dword ptr [ebx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(120) /* 0x78 */);
    // 004e5123  89437c                 -mov dword ptr [ebx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 004e5126  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e512c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e512d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5133  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e5135  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5136  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5137  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5138  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5139  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e5140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e5141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e5142  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e5144  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e5146  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e5148  8b8884000000           -mov ecx, dword ptr [eax + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 004e514e  89483c                 -mov dword ptr [eax + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004e5151  8b8888000000           -mov ecx, dword ptr [eax + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 004e5157  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004e515a  8b8888000000           -mov ecx, dword ptr [eax + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 004e5160  8bb884000000           -mov edi, dword ptr [eax + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 004e5166  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e5168  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004e516b  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e516e  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004e5171  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e5174  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004e5177  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e517a  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e517d  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e5180  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e5183  c780bc00000000000000   -mov dword ptr [eax + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 004e518d  8b88bc000000           -mov ecx, dword ptr [eax + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 004e5193  8988b8000000           -mov dword ptr [eax + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 004e5199  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004e51a0  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 004e51a7  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 004e51ae  c7405401000000         -mov dword ptr [eax + 0x54], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 1 /*0x1*/;
    // 004e51b5  89506c                 -mov dword ptr [eax + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 004e51b8  897068                 -mov dword ptr [eax + 0x68], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.esi;
    // 004e51bb  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e51c1  8b8aac000000           -mov ecx, dword ptr [edx + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e51c7  8988ac000000           -mov dword ptr [eax + 0xac], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ecx;
    // 004e51cd  8b8aa8000000           -mov ecx, dword ptr [edx + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 004e51d3  8988a8000000           -mov dword ptr [eax + 0xa8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ecx;
    // 004e51d9  8db88c000000           -lea edi, [eax + 0x8c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004e51df  8db28c000000           -lea esi, [edx + 0x8c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 004e51e5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e51e6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e51e7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e51e8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e51e9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e51ea  8b8aa4000000           -mov ecx, dword ptr [edx + 0xa4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 004e51f0  8988a4000000           -mov dword ptr [eax + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 004e51f6  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e51fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e51fd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5203  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5208  83787000               +cmp dword ptr [eax + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e520c  7412                   -je 0x4e5220
    if (cpu.flags.zf)
    {
        goto L_0x004e5220;
    }
L_0x004e520e:
    // 004e520e  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e5211  83787000               +cmp dword ptr [eax + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5215  75f7                   -jne 0x4e520e
    if (!cpu.flags.zf)
    {
        goto L_0x004e520e;
    }
    // 004e5217  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e521d  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x004e5220:
    // 004e5220  895870                 -mov dword ptr [eax + 0x70], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 004e5223  c7437000000000         -mov dword ptr [ebx + 0x70], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 004e522a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e522f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5235  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5236  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e523c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e523e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e523f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5240  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4e5250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e5250  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e5251  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e5252  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e5253  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e5256  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e5258  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004e525b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004e525d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e525f  66f7c3ff0f             +test bx, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & 4095 /*0xfff*/));
    // 004e5264  740c                   -je 0x4e5272
    if (cpu.flags.zf)
    {
        goto L_0x004e5272;
    }
    // 004e5266  8d8b00100000           -lea ecx, [ebx + 0x1000]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4096) /* 0x1000 */);
    // 004e526c  81e100f0ff7f           -and ecx, 0x7ffff000
    cpu.ecx &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x004e5272:
    // 004e5272  bad0a35400             -mov edx, 0x54a3d0
    cpu.edx = 5546960 /*0x54a3d0*/;
    // 004e5277  bb48a75400             -mov ebx, 0x54a748
    cpu.ebx = 5547848 /*0x54a748*/;
    // 004e527c  bfcd040000             -mov edi, 0x4cd
    cpu.edi = 1229 /*0x4cd*/;
    // 004e5281  b8f8a45400             -mov eax, 0x54a4f8
    cpu.eax = 5547256 /*0x54a4f8*/;
    // 004e5286  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e528c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e5292  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e5294  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e5296  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e529c  e87fc3ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004e52a1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e52a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e52a5  0f8486000000           -je 0x4e5331
    if (cpu.flags.zf)
    {
        goto L_0x004e5331;
    }
L_0x004e52ab:
    // 004e52ab  b8d0a35400             -mov eax, 0x54a3d0
    cpu.eax = 5546960 /*0x54a3d0*/;
    // 004e52b0  ba48a75400             -mov edx, 0x54a748
    cpu.edx = 5547848 /*0x54a748*/;
    // 004e52b5  bbd3040000             -mov ebx, 0x4d3
    cpu.ebx = 1235 /*0x4d3*/;
    // 004e52ba  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e52bf  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e52c5  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e52cb  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004e52d0  b858a75400             -mov eax, 0x54a758
    cpu.eax = 5547864 /*0x54a758*/;
    // 004e52d5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e52d7  e844c3ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004e52dc  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004e52e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e52e3  e824b4ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e52e8  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
    // 004e52ee  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 004e52f4  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004e52f9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e52fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e52fd  e89ebe0100             -call 0x5011a0
    cpu.esp -= 4;
    sub_5011a0(app, cpu);
    if (cpu.terminate) return;
    // 004e5302  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004e5307  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004e530c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e530e  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 004e5313  e888be0100             -call 0x5011a0
    cpu.esp -= 4;
    sub_5011a0(app, cpu);
    if (cpu.terminate) return;
    // 004e5318  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e531b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e531d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e531f  e81cfeffff             -call 0x4e5140
    cpu.esp -= 4;
    sub_4e5140(app, cpu);
    if (cpu.terminate) return;
    // 004e5324  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e5327  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5328  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e5329  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e532a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e5330  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e5331:
    // 004e5331  b8d0a35400             -mov eax, 0x54a3d0
    cpu.eax = 5546960 /*0x54a3d0*/;
    // 004e5336  ba48a75400             -mov edx, 0x54a748
    cpu.edx = 5547848 /*0x54a748*/;
    // 004e533b  bbcf040000             -mov ebx, 0x4cf
    cpu.ebx = 1231 /*0x4cf*/;
    // 004e5340  6804a55400             -push 0x54a504
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547268 /*0x54a504*/;
    cpu.esp -= 4;
    // 004e5345  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e534a  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e5350  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e5356  e8b5bcf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e535b  83c404                 +add esp, 4
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
    // 004e535e  e948ffffff             -jmp 0x4e52ab
    goto L_0x004e52ab;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e53c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004e53c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e53c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e53c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e53c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e53c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e53c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e53c6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e53c9  e832a7ffff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004e53ce  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e53d4  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004e53da  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 004e53e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e53e2  e839a7ffff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004e53e7  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004e53ec  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
  [[fallthrough]];
  case 0x004e53ee:
L_0x004e53ee:
    // 004e53ee  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e53f3  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e53f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e53fa  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5400  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5405  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004e5408  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e540b  0f84aa000000           -je 0x4e54bb
    if (cpu.flags.zf)
    {
        goto L_0x004e54bb;
    }
    // 004e5411  8378240f               +cmp dword ptr [eax + 0x24], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5415  7507                   -jne 0x4e541e
    if (!cpu.flags.zf)
    {
        goto L_0x004e541e;
    }
    // 004e5417  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x004e541e:
    // 004e541e  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5423  897824                 -mov dword ptr [eax + 0x24], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004e5426  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e542c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e542d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5433  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5438  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e543b  4a                     -dec edx
    (cpu.edx)--;
    // 004e543c  83fa13                 +cmp edx, 0x13
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
    // 004e543f  77ad                   -ja 0x4e53ee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e5441  ff249564534e00         -jmp dword ptr [edx*4 + 0x4e5364]
    cpu.ip = app->getMemory<x86::reg32>(5133156 + cpu.edx * 4); goto dynamic_jump;
  case 0x004e5448:
    // 004e5448  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e544d  3b781c                 +cmp edi, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5450  7408                   -je 0x4e545a
    if (cpu.flags.zf)
    {
        goto L_0x004e545a;
    }
    // 004e5452  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e5455  e846bf0100             -call 0x5013a0
    cpu.esp -= 4;
    sub_5013a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e545a:
    // 004e545a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e545c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e545d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5462  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004e5465  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e5468  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e546b  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e5471  e8fabd0100             -call 0x501270
    cpu.esp -= 4;
    sub_501270(app, cpu);
    if (cpu.terminate) return;
    // 004e5476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e5478  0f8538010000           -jne 0x4e55b6
    if (!cpu.flags.zf)
    {
        goto L_0x004e55b6;
    }
L_0x004e547e:
    // 004e547e  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5483  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e5489  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e548a  6864a75400             -push 0x54a764
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547876 /*0x54a764*/;
    cpu.esp -= 4;
    // 004e548f  e85cb4ffff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004e5494  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5499  83c408                 +add esp, 8
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
    // 004e549c  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e54a2  e879150000             -call 0x4e6a20
    cpu.esp -= 4;
    sub_4e6a20(app, cpu);
    if (cpu.terminate) return;
    // 004e54a7  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e54ac  89781c                 -mov dword ptr [eax + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004e54af  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e54b6  e933ffffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e54bb:
    // 004e54bb  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004e54be  e95bffffff             -jmp 0x4e541e
    goto L_0x004e541e;
  case 0x004e54c3:
    // 004e54c3  e898110000             -call 0x4e6660
    cpu.esp -= 4;
    sub_4e6660(app, cpu);
    if (cpu.terminate) return;
    // 004e54c8  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e54cd  3b7878                 +cmp edi, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e54d0  7510                   -jne 0x4e54e2
    if (!cpu.flags.zf)
    {
        goto L_0x004e54e2;
    }
    // 004e54d2  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e54d8  e893a6ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e54dd  e90cffffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e54e2:
    // 004e54e2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e54e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e54e9  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e54ef  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e54f5  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004e54f8  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004e54fb  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 004e5501  895178                 -mov dword ptr [ecx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004e5504  898180000000           -mov dword ptr [ecx + 0x80], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004e550a  8b5978                 -mov ebx, dword ptr [ecx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004e550d  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e550f  7503                   -jne 0x4e5514
    if (!cpu.flags.zf)
    {
        goto L_0x004e5514;
    }
    // 004e5511  89597c                 -mov dword ptr [ecx + 0x7c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.ebx;
L_0x004e5514:
    // 004e5514  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e551a  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004e5520  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004e5523  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 004e5526  8bb090000000           -mov esi, dword ptr [eax + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */);
    // 004e552c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e552e  895160                 -mov dword ptr [ecx + 0x60], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004e5531  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004e5537  83fa0d                 +cmp edx, 0xd
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e553a  7517                   -jne 0x4e5553
    if (!cpu.flags.zf)
    {
        goto L_0x004e5553;
    }
L_0x004e553c:
    // 004e553c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5541  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5548  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e554e  e99bfeffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e5553:
    // 004e5553  83fa14                 +cmp edx, 0x14
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
    // 004e5556  74e4                   -je 0x4e553c
    if (cpu.flags.zf)
    {
        goto L_0x004e553c;
    }
    // 004e5558  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e555a  74e0                   -je 0x4e553c
    if (cpu.flags.zf)
    {
        goto L_0x004e553c;
    }
    // 004e555c  83fa11                 +cmp edx, 0x11
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e555f  74db                   -je 0x4e553c
    if (cpu.flags.zf)
    {
        goto L_0x004e553c;
    }
    // 004e5561  83fa12                 +cmp edx, 0x12
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5564  74d6                   -je 0x4e553c
    if (cpu.flags.zf)
    {
        goto L_0x004e553c;
    }
    // 004e5566  83fa13                 +cmp edx, 0x13
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
    // 004e5569  74d1                   -je 0x4e553c
    if (cpu.flags.zf)
    {
        goto L_0x004e553c;
    }
    // 004e556b  e8b0140000             -call 0x4e6a20
    cpu.esp -= 4;
    sub_4e6a20(app, cpu);
    if (cpu.terminate) return;
    // 004e5570  ebca                   -jmp 0x4e553c
    goto L_0x004e553c;
  case 0x004e5572:
    // 004e5572  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5576  7534                   -jne 0x4e55ac
    if (!cpu.flags.zf)
    {
        goto L_0x004e55ac;
    }
L_0x004e5578:
    // 004e5578  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e557d  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004e5584  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e558a  e871a6ffff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004e558f  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5595  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 004e559b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e559d  e87ea5ffff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004e55a2  83c404                 +add esp, 4
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
    // 004e55a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e55ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e55ac:
    // 004e55ac  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e55af  e8ecbd0100             -call 0x5013a0
    cpu.esp -= 4;
    sub_5013a0(app, cpu);
    if (cpu.terminate) return;
    // 004e55b4  ebc2                   -jmp 0x4e5578
    goto L_0x004e5578;
L_0x004e55b6:
    // 004e55b6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e55bb  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e55c1  e85a140000             -call 0x4e6a20
    cpu.esp -= 4;
    sub_4e6a20(app, cpu);
    if (cpu.terminate) return;
    // 004e55c6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e55cb  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e55d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e55d2  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e55d8  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e55de  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e55e1  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e55e4  0f8eca000000           -jle 0x4e56b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e56b4;
    }
    // 004e55ea  89a9a0000000           -mov dword ptr [ecx + 0xa0], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.ebp;
    // 004e55f0  3b413c                 +cmp eax, dword ptr [ecx + 0x3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e55f3  7e36                   -jle 0x4e562b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e562b;
    }
    // 004e55f5  bbd0a35400             -mov ebx, 0x54a3d0
    cpu.ebx = 5546960 /*0x54a3d0*/;
    // 004e55fa  be88a75400             -mov esi, 0x54a788
    cpu.esi = 5547912 /*0x54a788*/;
    // 004e55ff  b877050000             -mov eax, 0x577
    cpu.eax = 1399 /*0x577*/;
    // 004e5604  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e560a  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e5610  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e5615  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004e5618  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5619  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e561d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e561e  689ca75400             -push 0x54a79c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547932 /*0x54a79c*/;
    cpu.esp -= 4;
    // 004e5623  e8e8b9f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e5628  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e562b:
    // 004e562b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e562e  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5634  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e5636  3b423c                 +cmp eax, dword ptr [edx + 0x3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5639  7e0d                   -jle 0x4e5648
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e5648;
    }
    // 004e563b  68d0a75400             -push 0x54a7d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547984 /*0x54a7d0*/;
    cpu.esp -= 4;
    // 004e5640  e8abb2ffff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004e5645  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e5648:
    // 004e5648  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e564e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e5651  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
L_0x004e5654:
    // 004e5654  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5659  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e565c  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004e565f  8b4850                 -mov ecx, dword ptr [eax + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e5662  8b5858                 -mov ebx, dword ptr [eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004e5665  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e5667  894854                 -mov dword ptr [eax + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 004e566a  3b6820                 +cmp ebp, dword ptr [eax + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e566d  756c                   -jne 0x4e56db
    if (!cpu.flags.zf)
    {
        goto L_0x004e56db;
    }
L_0x004e566f:
    // 004e566f  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5674  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e5677  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e567a  89b8b8000000           -mov dword ptr [eax + 0xb8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edi;
L_0x004e5680:
    // 004e5680  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5685  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5688  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e568b  83782013               +cmp dword ptr [eax + 0x20], 0x13
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e568f  7552                   -jne 0x4e56e3
    if (!cpu.flags.zf)
    {
        goto L_0x004e56e3;
    }
L_0x004e5691:
    // 004e5691  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5696  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x004e569d:
    // 004e569d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e56a2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e56a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e56a9  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e56af  e93afdffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e56b4:
    // 004e56b4  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004e56b7  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004e56ba  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e56bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e56c0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e56c2  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004e56c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e56ca  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 004e56d0  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004e56d3  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004e56d6  e979ffffff             -jmp 0x4e5654
    goto L_0x004e5654;
L_0x004e56db:
    // 004e56db  83782012               +cmp dword ptr [eax + 0x20], 0x12
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e56df  748e                   -je 0x4e566f
    if (cpu.flags.zf)
    {
        goto L_0x004e566f;
    }
    // 004e56e1  eb9d                   -jmp 0x4e5680
    goto L_0x004e5680;
L_0x004e56e3:
    // 004e56e3  83782012               +cmp dword ptr [eax + 0x20], 0x12
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e56e7  74a8                   -je 0x4e5691
    if (cpu.flags.zf)
    {
        goto L_0x004e5691;
    }
    // 004e56e9  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 004e56f0  ebab                   -jmp 0x4e569d
    goto L_0x004e569d;
  case 0x004e56f2:
    // 004e56f2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e56f7  3b781c                 +cmp edi, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e56fa  7408                   -je 0x4e5704
    if (cpu.flags.zf)
    {
        goto L_0x004e5704;
    }
    // 004e56fc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e56ff  e89cbc0100             -call 0x5013a0
    cpu.esp -= 4;
    sub_5013a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e5704:
    // 004e5704  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e5706  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5707  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e570c  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004e570f  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e5712  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e5715  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e571b  e850bb0100             -call 0x501270
    cpu.esp -= 4;
    sub_501270(app, cpu);
    if (cpu.terminate) return;
    // 004e5720  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e5722  0f8456fdffff           -je 0x4e547e
    if (cpu.flags.zf)
    {
        goto L_0x004e547e;
    }
    // 004e5728  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e572d  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004e5733  e8e8120000             -call 0x4e6a20
    cpu.esp -= 4;
    sub_4e6a20(app, cpu);
    if (cpu.terminate) return;
    // 004e5738  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e573d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5743  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5744  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e574a  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5750  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e5753  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5756  0f8e06020000           -jle 0x4e5962
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e5962;
    }
    // 004e575c  89a9a0000000           -mov dword ptr [ecx + 0xa0], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.ebp;
    // 004e5762  3b413c                 +cmp eax, dword ptr [ecx + 0x3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5765  7e36                   -jle 0x4e579d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e579d;
    }
    // 004e5767  bbd0a35400             -mov ebx, 0x54a3d0
    cpu.ebx = 5546960 /*0x54a3d0*/;
    // 004e576c  be88a75400             -mov esi, 0x54a788
    cpu.esi = 5547912 /*0x54a788*/;
    // 004e5771  b8a5050000             -mov eax, 0x5a5
    cpu.eax = 1445 /*0x5a5*/;
    // 004e5776  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e577c  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e5782  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e5787  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004e578a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e578b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e578f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e5790  689ca75400             -push 0x54a79c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547932 /*0x54a79c*/;
    cpu.esp -= 4;
    // 004e5795  e876b8f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e579a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e579d:
    // 004e579d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e57a0  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e57a5  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e57a7  3b503c                 +cmp edx, dword ptr [eax + 0x3c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e57aa  7e0d                   -jle 0x4e57b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e57b9;
    }
    // 004e57ac  68d0a75400             -push 0x54a7d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5547984 /*0x54a7d0*/;
    cpu.esp -= 4;
    // 004e57b1  e83ab1ffff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004e57b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e57b9:
    // 004e57b9  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e57bf  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e57c2  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
L_0x004e57c5:
    // 004e57c5  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e57ca  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e57cd  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004e57d0  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e57d3  8b5858                 -mov ebx, dword ptr [eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004e57d6  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e57d8  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004e57db  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e57e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e57e2  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004e57e8:
    // 004e57e8  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e57ed  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e57f2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e57f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e57f9  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e57ff  3b3dbc455600           +cmp edi, dword ptr [0x5645bc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5805  743b                   -je 0x4e5842
    if (cpu.flags.zf)
    {
        goto L_0x004e5842;
    }
L_0x004e5807:
    // 004e5807  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e580c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e580f  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004e5812  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e5815  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e5818  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e581b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e581e  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e5821  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e5824  89b8bc000000           -mov dword ptr [eax + 0xbc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edi;
    // 004e582a  8b90bc000000           -mov edx, dword ptr [eax + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 004e5830  8990b8000000           -mov dword ptr [eax + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 004e5836  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e5839  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e583e  39c7                   +cmp edi, eax
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
    // 004e5840  75c5                   -jne 0x4e5807
    if (!cpu.flags.zf)
    {
        goto L_0x004e5807;
    }
L_0x004e5842:
    // 004e5842  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5847  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e584d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e584e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5854  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5859  83782014               +cmp dword ptr [eax + 0x20], 0x14
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e585d  0f8426010000           -je 0x4e5989
    if (cpu.flags.zf)
    {
        goto L_0x004e5989;
    }
    // 004e5863  c7402002000000         -mov dword ptr [eax + 0x20], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 004e586a  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 004e5870  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e5872  e8a9a2ffff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004e5877:
    // 004e5877  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e587c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5882  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5883  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5889  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e588e  83782002               +cmp dword ptr [eax + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5892  0f850a010000           -jne 0x4e59a2
    if (!cpu.flags.zf)
    {
        goto L_0x004e59a2;
    }
    // 004e5898  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e589b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e589e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e58a1  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e58a4  89b8b8000000           -mov dword ptr [eax + 0xb8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edi;
L_0x004e58aa:
    // 004e58aa  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e58af  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 004e58b2  89505c                 -mov dword ptr [eax + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 004e58b5  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e58bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e58bc  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e58c2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e58c7  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004e58ca  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e58cd  e87ebb0100             -call 0x501450
    cpu.esp -= 4;
    sub_501450(app, cpu);
    if (cpu.terminate) return;
    // 004e58d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e58d4  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e58d9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e58df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e58e0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e58e6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e58eb  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004e58ee  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e58f0  8990b0000000           -mov dword ptr [eax + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 004e58f6  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e58f9  8b98b0000000           -mov ebx, dword ptr [eax + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 004e58ff  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e5901  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004e5904  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e590a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e590b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5911  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5917  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e5919  e8f20d0000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e591e  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5921  0f8f0e010000           -jg 0x4e5a35
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5a35;
    }
L_0x004e5927:
    // 004e5927  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e592c  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e592f  0f8578000000           -jne 0x4e59ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e59ad;
    }
    // 004e5935  e8d60d0000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e593a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e593c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5941  e89a0d0000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5946  39c2                   +cmp edx, eax
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
    // 004e5948  7463                   -je 0x4e59ad
    if (cpu.flags.zf)
    {
        goto L_0x004e59ad;
    }
    // 004e594a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e594f  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5955  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e595b  e810a2ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5960  ebc5                   -jmp 0x4e5927
    goto L_0x004e5927;
L_0x004e5962:
    // 004e5962  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004e5965  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004e5968  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e596b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e596e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e5970  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004e5976  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e5978  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 004e597e  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004e5981  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004e5984  e93cfeffff             -jmp 0x4e57c5
    goto L_0x004e57c5;
L_0x004e5989:
    // 004e5989  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e5990  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 004e5996  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e5998  e883a1ffff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004e599d  e94cfaffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e59a2:
    // 004e59a2  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e59a5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e59a8  e9fdfeffff             -jmp 0x4e58aa
    goto L_0x004e58aa;
L_0x004e59ad:
    // 004e59ad  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e59b2  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e59b8  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e59bb  0f852dfaffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e59c1:
    // 004e59c1  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e59c6  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e59c9  7522                   -jne 0x4e59ed
    if (!cpu.flags.zf)
    {
        goto L_0x004e59ed;
    }
    // 004e59cb  e8500d0000             -call 0x4e6720
    cpu.esp -= 4;
    sub_4e6720(app, cpu);
    if (cpu.terminate) return;
    // 004e59d0  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004e59d3  7f18                   -jg 0x4e59ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e59ed;
    }
    // 004e59d5  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e59da  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e59e0  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e59e6  e885a1ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e59eb  ebd4                   -jmp 0x4e59c1
    goto L_0x004e59c1;
L_0x004e59ed:
    // 004e59ed  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e59f2  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e59f8  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e59fb  0f85edf9ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e5a01  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5a08  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5a0e  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5a13  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5a16  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e5a1c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e5a1f  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e5a22  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5a25  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e5a28  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5a2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5a2f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e5a35:
    // 004e5a35  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5a3b  3b7924                 +cmp edi, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5a3e  7524                   -jne 0x4e5a64
    if (!cpu.flags.zf)
    {
        goto L_0x004e5a64;
    }
    // 004e5a40  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e5a42  e8990c0000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5a47  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5a4a  7f18                   -jg 0x4e5a64
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5a64;
    }
    // 004e5a4c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5a51  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5a57  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5a5d  e80ea1ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5a62  ebd1                   -jmp 0x4e5a35
    goto L_0x004e5a35;
L_0x004e5a64:
    // 004e5a64  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5a69  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5a6f  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5a72  0f8576f9ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e5a78:
    // 004e5a78  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5a7d  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004e5a83  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e5a86  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e5a89  e822b90100             -call 0x5013b0
    cpu.esp -= 4;
    sub_5013b0(app, cpu);
    if (cpu.terminate) return;
    // 004e5a8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e5a90  7509                   -jne 0x4e5a9b
    if (!cpu.flags.zf)
    {
        goto L_0x004e5a9b;
    }
    // 004e5a92  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e5a94  e8479effff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5a99  ebdd                   -jmp 0x4e5a78
    goto L_0x004e5a78;
L_0x004e5a9b:
    // 004e5a9b  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5aa0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5aa6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5aa7  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5aad  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5ab2  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5ab5  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5ab8  3bb8b0000000           +cmp edi, dword ptr [eax + 0xb0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5abe  7416                   -je 0x4e5ad6
    if (cpu.flags.zf)
    {
        goto L_0x004e5ad6;
    }
    // 004e5ac0  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5ac3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5ac6  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5ac9  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 004e5acf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e5ad1  e81a4a0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x004e5ad6:
    // 004e5ad6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5adb  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5ade  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5ae1  c7402003000000         -mov dword ptr [eax + 0x20], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 004e5ae8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5aee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5aef  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004e5af5:
    // 004e5af5  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5afb  837a4c08               +cmp dword ptr [edx + 0x4c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5aff  0f838a010000           -jae 0x4e5c8f
    if (!cpu.flags.cf)
    {
        goto L_0x004e5c8f;
    }
    // 004e5b05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e5b07  e8040c0000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e5b0c  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5b0f  0f8fde000000           -jg 0x4e5bf3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5bf3;
    }
L_0x004e5b15:
    // 004e5b15  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b1a  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5b1d  752d                   -jne 0x4e5b4c
    if (!cpu.flags.zf)
    {
        goto L_0x004e5b4c;
    }
    // 004e5b1f  e8ec0b0000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e5b24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e5b26  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b2b  e8b00b0000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5b30  39c2                   +cmp edx, eax
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
    // 004e5b32  7418                   -je 0x4e5b4c
    if (cpu.flags.zf)
    {
        goto L_0x004e5b4c;
    }
    // 004e5b34  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b39  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5b3f  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5b45  e826a0ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5b4a  ebc9                   -jmp 0x4e5b15
    goto L_0x004e5b15;
L_0x004e5b4c:
    // 004e5b4c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b51  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5b57  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5b5a  0f858ef8ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e5b60:
    // 004e5b60  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b66  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5b69  7527                   -jne 0x4e5b92
    if (!cpu.flags.zf)
    {
        goto L_0x004e5b92;
    }
    // 004e5b6b  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5b70  e8ab0b0000             -call 0x4e6720
    cpu.esp -= 4;
    sub_4e6720(app, cpu);
    if (cpu.terminate) return;
    // 004e5b75  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 004e5b78  7f18                   -jg 0x4e5b92
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5b92;
    }
    // 004e5b7a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b7f  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5b85  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5b8b  e8e09fffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5b90  ebce                   -jmp 0x4e5b60
    goto L_0x004e5b60;
L_0x004e5b92:
    // 004e5b92  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5b97  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5b9d  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5ba0  0f8548f8ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e5ba6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5bac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5bad  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5bb3  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5bb8  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5bbb  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e5bbe  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5bc1  e82a490000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e5bc6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5bcb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5bce  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e5bd4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e5bd7  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e5bda  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5bdd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e5be0  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5be3  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5be6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5bec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5bed  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e5bf3:
    // 004e5bf3  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5bf9  3b7924                 +cmp edi, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5bfc  7524                   -jne 0x4e5c22
    if (!cpu.flags.zf)
    {
        goto L_0x004e5c22;
    }
    // 004e5bfe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e5c00  e8db0a0000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5c05  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5c08  7f18                   -jg 0x4e5c22
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5c22;
    }
    // 004e5c0a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c0f  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5c15  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5c1b  e8509fffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5c20  ebd1                   -jmp 0x4e5bf3
    goto L_0x004e5bf3;
L_0x004e5c22:
    // 004e5c22  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c27  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5c2d  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5c30  0f85b8f7ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e5c36:
    // 004e5c36  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c3b  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004e5c41  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e5c44  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e5c47  e864b70100             -call 0x5013b0
    cpu.esp -= 4;
    sub_5013b0(app, cpu);
    if (cpu.terminate) return;
    // 004e5c4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e5c4e  7509                   -jne 0x4e5c59
    if (!cpu.flags.zf)
    {
        goto L_0x004e5c59;
    }
    // 004e5c50  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e5c52  e8899cffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5c57  ebdd                   -jmp 0x4e5c36
    goto L_0x004e5c36;
L_0x004e5c59:
    // 004e5c59  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c5e  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5c64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5c65  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5c6b  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c70  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e5c73  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5c76  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e5c79  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5c7c  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e5c7f  01504c                 -add dword ptr [eax + 0x4c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e5c82  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5c88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5c89  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e5c8f:
    // 004e5c8f  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5c94  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5c97  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e5c9c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e5c9e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e5ca0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e5ca2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e5ca9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e5cab  3d6c454353             +cmp eax, 0x5343456c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1396917612 /*0x5343456c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5cb0  7516                   -jne 0x4e5cc8
    if (!cpu.flags.zf)
    {
        goto L_0x004e5cc8;
    }
    // 004e5cb2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5cb7  3b7878                 +cmp edi, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5cba  740c                   -je 0x4e5cc8
    if (cpu.flags.zf)
    {
        goto L_0x004e5cc8;
    }
    // 004e5cbc  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e5cc3  e926f7ffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e5cc8:
    // 004e5cc8  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5ccd  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5cd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5cd4  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5cda  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5cdf  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5ce2  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004e5ce5  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 004e5ce8  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e5ceb  8b704c                 -mov esi, dword ptr [eax + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e5cee  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004e5cf0  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 004e5cf3  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e5cf6  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e5cfb  39c7                   +cmp edi, eax
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
    // 004e5cfd  742f                   -je 0x4e5d2e
    if (cpu.flags.zf)
    {
        goto L_0x004e5d2e;
    }
L_0x004e5cff:
    // 004e5cff  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d04  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5d07  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e5d0c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e5d0e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e5d10  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e5d12  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e5d19  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e5d1b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e5d1d  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5d22  23506c                 -and edx, dword ptr [eax + 0x6c]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */)));
    // 004e5d25  3b5068                 +cmp edx, dword ptr [eax + 0x68]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5d28  0f85a9000000           -jne 0x4e5dd7
    if (!cpu.flags.zf)
    {
        goto L_0x004e5dd7;
    }
L_0x004e5d2e:
    // 004e5d2e  3b3dbc455600           +cmp edi, dword ptr [0x5645bc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5d34  750a                   -jne 0x4e5d40
    if (!cpu.flags.zf)
    {
        goto L_0x004e5d40;
    }
    // 004e5d36  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d3b  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
L_0x004e5d40:
    // 004e5d40  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d45  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5d4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5d4c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5d52  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d58  83794808               +cmp dword ptr [ecx + 0x48], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5d5c  0f838a000000           -jae 0x4e5dec
    if (!cpu.flags.cf)
    {
        goto L_0x004e5dec;
    }
L_0x004e5d62:
    // 004e5d62  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d67  3b782c                 +cmp edi, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5d6a  0f850a010000           -jne 0x4e5e7a
    if (!cpu.flags.zf)
    {
        goto L_0x004e5e7a;
    }
    // 004e5d70  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5d76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5d77  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5d7d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5d82  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
L_0x004e5d87:
    // 004e5d87  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5d8c  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5d8f  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 004e5d92  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004e5d94  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5d97  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004e5d9e  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e5da2  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5da5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e5da8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e5dab  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e5db0  39c7                   +cmp edi, eax
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
    // 004e5db2  75d3                   -jne 0x4e5d87
    if (!cpu.flags.zf)
    {
        goto L_0x004e5d87;
    }
    // 004e5db4  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5db9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5dbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5dc0  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5dc6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5dcb  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e5dd2  e917f6ffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e5dd7:
    // 004e5dd7  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e5dda  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e5ddf  39c7                   +cmp edi, eax
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
    // 004e5de1  0f8518ffffff           -jne 0x4e5cff
    if (!cpu.flags.zf)
    {
        goto L_0x004e5cff;
    }
    // 004e5de7  e942ffffff             -jmp 0x4e5d2e
    goto L_0x004e5d2e;
L_0x004e5dec:
    // 004e5dec  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5df2  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004e5df5  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004e5df8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e5dfb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e5dfd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004e5dff  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5e02  0f8c5affffff           -jl 0x4e5d62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e5d62;
    }
L_0x004e5e08:
    // 004e5e08  8b0db8455600           -mov ecx, dword ptr [0x5645b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5e0e  3b0dbc455600           +cmp ecx, dword ptr [0x5645bc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5e14  0f8432030000           -je 0x4e614c
    if (cpu.flags.zf)
    {
        goto L_0x004e614c;
    }
    // 004e5e1a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004e5e1c  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004e5e1f  8b5940                 -mov ebx, dword ptr [ecx + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004e5e22  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004e5e25  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5e2a  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e5e2d  e8de080000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e5e32  39d0                   +cmp eax, edx
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
    // 004e5e34  0f8768010000           -ja 0x4e5fa2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e5fa2;
    }
L_0x004e5e3a:
    // 004e5e3a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5e3f  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5e42  0f8577000000           -jne 0x4e5ebf
    if (!cpu.flags.zf)
    {
        goto L_0x004e5ebf;
    }
    // 004e5e48  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5e4d  e8be080000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e5e52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e5e54  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5e59  e882080000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5e5e  39c2                   +cmp edx, eax
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
    // 004e5e60  745d                   -je 0x4e5ebf
    if (cpu.flags.zf)
    {
        goto L_0x004e5ebf;
    }
    // 004e5e62  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5e67  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5e6d  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5e73  e8f89cffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5e78  ebc0                   -jmp 0x4e5e3a
    goto L_0x004e5e3a;
L_0x004e5e7a:
    // 004e5e7a  bbd0a35400             -mov ebx, 0x54a3d0
    cpu.ebx = 5546960 /*0x54a3d0*/;
    // 004e5e7f  be88a75400             -mov esi, 0x54a788
    cpu.esi = 5547912 /*0x54a788*/;
    // 004e5e84  ba38060000             -mov edx, 0x638
    cpu.edx = 1592 /*0x638*/;
    // 004e5e89  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e5e8f  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e5e95  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e5e9b  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004e5e9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e5e9f  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5ea5  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004e5ea8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e5ea9  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e5eac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5ead  6800a85400             -push 0x54a800
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548032 /*0x54a800*/;
    cpu.esp -= 4;
    // 004e5eb2  e859b1f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e5eb7  83c410                 +add esp, 0x10
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
    // 004e5eba  e949ffffff             -jmp 0x4e5e08
    goto L_0x004e5e08;
L_0x004e5ebf:
    // 004e5ebf  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5ec4  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5eca  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5ecd  0f851bf5ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e5ed3:
    // 004e5ed3  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5ed8  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5edb  7527                   -jne 0x4e5f04
    if (!cpu.flags.zf)
    {
        goto L_0x004e5f04;
    }
    // 004e5edd  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5ee2  e8f9070000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5ee7  83f808                 +cmp eax, 8
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
    // 004e5eea  7718                   -ja 0x4e5f04
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e5f04;
    }
    // 004e5eec  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5ef1  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5ef7  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5efd  e86e9cffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5f02  ebcf                   -jmp 0x4e5ed3
    goto L_0x004e5ed3;
L_0x004e5f04:
    // 004e5f04  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5f09  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5f0f  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5f12  0f85d6f4ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e5f18:
    // 004e5f18  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5f1e  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5f21  7532                   -jne 0x4e5f55
    if (!cpu.flags.zf)
    {
        goto L_0x004e5f55;
    }
    // 004e5f23  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004e5f26  8b5a40                 -mov ebx, dword ptr [edx + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004e5f29  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004e5f2c  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5f31  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e5f34  e8e7070000             -call 0x4e6720
    cpu.esp -= 4;
    sub_4e6720(app, cpu);
    if (cpu.terminate) return;
    // 004e5f39  39d0                   +cmp eax, edx
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
    // 004e5f3b  7718                   -ja 0x4e5f55
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e5f55;
    }
    // 004e5f3d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5f42  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5f48  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5f4e  e81d9cffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5f53  ebc3                   -jmp 0x4e5f18
    goto L_0x004e5f18;
L_0x004e5f55:
    // 004e5f55  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5f5a  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5f60  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5f63  0f8585f4ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e5f69  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5f6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5f70  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e5f76  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5f7b  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5f7e  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e5f84  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e5f87  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e5f8a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e5f8d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e5f90  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5f95  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5f9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5f9c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e5fa2:
    // 004e5fa2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5fa7  3b7844                 +cmp edi, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5faa  0f8fef000000           -jg 0x4e609f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e609f;
    }
L_0x004e5fb0:
    // 004e5fb0  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5fb6  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5fb9  7527                   -jne 0x4e5fe2
    if (!cpu.flags.zf)
    {
        goto L_0x004e5fe2;
    }
    // 004e5fbb  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e5fc0  e81b070000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e5fc5  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 004e5fc8  7f18                   -jg 0x4e5fe2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e5fe2;
    }
    // 004e5fca  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5fcf  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e5fd5  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e5fdb  e8909bffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e5fe0  ebce                   -jmp 0x4e5fb0
    goto L_0x004e5fb0;
L_0x004e5fe2:
    // 004e5fe2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e5fe7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e5fed  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e5ff0  0f85f8f3ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e5ff6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e5ffc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e5ffd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6003  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6008  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e600b  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6011  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e6014  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6017  e8d4440000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e601c  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6022  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6027  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e602a  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e602d  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e602f  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e6032  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6035  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e6038  89784c                 -mov dword ptr [eax + 0x4c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edi;
L_0x004e603b:
    // 004e603b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6041  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6042  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e6048:
    // 004e6048  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e604e  3b7a44                 +cmp edi, dword ptr [edx + 0x44]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6051  0f8c25010000           -jl 0x4e617c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e617c;
    }
L_0x004e6057:
    // 004e6057  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e605c  3b7844                 +cmp edi, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e605f  0f8da2020000           -jge 0x4e6307
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6307;
    }
L_0x004e6065:
    // 004e6065  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e606b  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e606e  0f8519020000           -jne 0x4e628d
    if (!cpu.flags.zf)
    {
        goto L_0x004e628d;
    }
    // 004e6074  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6079  e862060000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e607e  3b4240                 +cmp eax, dword ptr [edx + 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6081  0f8f06020000           -jg 0x4e628d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e628d;
    }
    // 004e6087  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e608c  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e6092  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e6098  e8d39affff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e609d  ebc6                   -jmp 0x4e6065
    goto L_0x004e6065;
L_0x004e609f:
    // 004e609f  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e60a5  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e60a8  7527                   -jne 0x4e60d1
    if (!cpu.flags.zf)
    {
        goto L_0x004e60d1;
    }
    // 004e60aa  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e60af  e82c060000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e60b4  3b4248                 +cmp eax, dword ptr [edx + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e60b7  7f18                   -jg 0x4e60d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e60d1;
    }
    // 004e60b9  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e60be  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e60c4  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e60ca  e8a19affff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e60cf  ebce                   -jmp 0x4e609f
    goto L_0x004e609f;
L_0x004e60d1:
    // 004e60d1  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e60d6  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e60dc  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e60df  0f8509f3ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e60e5  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e60eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e60ec  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e60f2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e60f7  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e60fa  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6100  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e6103  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6106  e8e5430000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e610b  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6111  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6116  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e6119  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e611c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e611e  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e6121  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004e6124  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004e6126  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004e6129  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e612c  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e612f  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6132  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e6135  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6137  e8b4430000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e613c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6141  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e6144  29500c                 +sub dword ptr [eax + 0xc], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e6147  e9effeffff             -jmp 0x4e603b
    goto L_0x004e603b;
L_0x004e614c:
    // 004e614c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e614f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e6154  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e6156  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e6158  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e615a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e6161  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e6163  3d6c454353             +cmp eax, 0x5343456c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1396917612 /*0x5343456c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6168  7509                   -jne 0x4e6173
    if (!cpu.flags.zf)
    {
        goto L_0x004e6173;
    }
    // 004e616a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e616c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e616e  e9d5feffff             -jmp 0x4e6048
    goto L_0x004e6048;
L_0x004e6173:
    // 004e6173  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e6175  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e6177  e9ccfeffff             -jmp 0x4e6048
    goto L_0x004e6048;
L_0x004e617c:
    // 004e617c  8b4244                 -mov eax, dword ptr [edx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 004e617f  8b4a40                 -mov ecx, dword ptr [edx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004e6182  8d1408                 -lea edx, [eax + ecx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004e6185  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e618a  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e618d  e87e050000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e6192  39d0                   +cmp eax, edx
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
    // 004e6194  0f87bdfeffff           -ja 0x4e6057
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e6057;
    }
L_0x004e619a:
    // 004e619a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e619f  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e61a2  7532                   -jne 0x4e61d6
    if (!cpu.flags.zf)
    {
        goto L_0x004e61d6;
    }
    // 004e61a4  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e61a9  e862050000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e61ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e61b0  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e61b5  e826050000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e61ba  39c2                   +cmp edx, eax
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
    // 004e61bc  7418                   -je 0x4e61d6
    if (cpu.flags.zf)
    {
        goto L_0x004e61d6;
    }
    // 004e61be  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e61c3  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e61c9  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e61cf  e89c99ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e61d4  ebc4                   -jmp 0x4e619a
    goto L_0x004e619a;
L_0x004e61d6:
    // 004e61d6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e61db  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e61e1  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e61e4  0f8504f2ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e61ea:
    // 004e61ea  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e61f0  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e61f3  7527                   -jne 0x4e621c
    if (!cpu.flags.zf)
    {
        goto L_0x004e621c;
    }
    // 004e61f5  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e61fa  e821050000             -call 0x4e6720
    cpu.esp -= 4;
    sub_4e6720(app, cpu);
    if (cpu.terminate) return;
    // 004e61ff  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 004e6202  7f18                   -jg 0x4e621c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e621c;
    }
    // 004e6204  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6209  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e620f  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e6215  e85699ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e621a  ebce                   -jmp 0x4e61ea
    goto L_0x004e61ea;
L_0x004e621c:
    // 004e621c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6221  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e6227  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e622a  0f85bef1ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e6230  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6236  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6237  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e623d  8b1db8455600           -mov ebx, dword ptr [0x5645b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6243  8b5b4c                 -mov ebx, dword ptr [ebx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 004e6246  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e624b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e624e  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6251  e89a420000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e6256  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e625b  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e625e  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e6264  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e626a  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e626d  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 004e6270  01d9                   +add ecx, ebx
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
    // 004e6272  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e6275  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e6278  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e627b  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e6281  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6282  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6288  e9cafdffff             -jmp 0x4e6057
    goto L_0x004e6057;
L_0x004e628d:
    // 004e628d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6292  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e6298  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e629b  756a                   -jne 0x4e6307
    if (!cpu.flags.zf)
    {
        goto L_0x004e6307;
    }
L_0x004e629d:
    // 004e629d  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e62a2  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004e62a8  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e62ae  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004e62b1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e62b4  e8f7b00100             -call 0x5013b0
    cpu.esp -= 4;
    sub_5013b0(app, cpu);
    if (cpu.terminate) return;
    // 004e62b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e62bb  7509                   -jne 0x4e62c6
    if (!cpu.flags.zf)
    {
        goto L_0x004e62c6;
    }
    // 004e62bd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e62bf  e81c96ffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e62c4  ebd7                   -jmp 0x4e629d
    goto L_0x004e629d;
L_0x004e62c6:
    // 004e62c6  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e62cb  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e62d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e62d2  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e62d8  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e62dd  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e62e0  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e62e3  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e62e9  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e62ec  014a0c                 -add dword ptr [edx + 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e62ef  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004e62f2  295044                 +sub dword ptr [eax + 0x44], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e62f5  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e62fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e62fc  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6302  e950fdffff             -jmp 0x4e6057
    goto L_0x004e6057;
L_0x004e6307:
    // 004e6307  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e630c  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e630f  0f85d9f0ffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e6315  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e631b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e631c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6322  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e6324  0f8598000000           -jne 0x4e63c2
    if (!cpu.flags.zf)
    {
        goto L_0x004e63c2;
    }
    // 004e632a  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6330  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6335  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004e6338  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e633b  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004e633e  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e6341  0188b8000000           -add dword ptr [eax + 0xb8], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6347  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e634d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e634e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6354  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6359  8b35b8455600           -mov esi, dword ptr [0x5645b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e635f  39f0                   +cmp eax, esi
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
    // 004e6361  0f842a020000           -je 0x4e6591
    if (cpu.flags.zf)
    {
        goto L_0x004e6591;
    }
    // 004e6367  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e6369  3b7e4c                 +cmp edi, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e636c  0f85c6010000           -jne 0x4e6538
    if (!cpu.flags.zf)
    {
        goto L_0x004e6538;
    }
    // 004e6372  8b0dbc455600           -mov ecx, dword ptr [0x5645bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6378  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e637b  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004e637e  e88d030000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e6383  39d0                   +cmp eax, edx
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
    // 004e6385  0f8f07010000           -jg 0x4e6492
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e6492;
    }
L_0x004e638b:
    // 004e638b  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6390  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6393  7563                   -jne 0x4e63f8
    if (!cpu.flags.zf)
    {
        goto L_0x004e63f8;
    }
    // 004e6395  e876030000             -call 0x4e6710
    cpu.esp -= 4;
    sub_4e6710(app, cpu);
    if (cpu.terminate) return;
    // 004e639a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e639c  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e63a1  e83a030000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e63a6  39c2                   +cmp edx, eax
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
    // 004e63a8  744e                   -je 0x4e63f8
    if (cpu.flags.zf)
    {
        goto L_0x004e63f8;
    }
    // 004e63aa  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e63af  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e63b5  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e63bb  e8b097ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e63c0  ebc9                   -jmp 0x4e638b
    goto L_0x004e638b;
L_0x004e63c2:
    // 004e63c2  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e63c7  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e63cd  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e63d0  014a10                 -add dword ptr [edx + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e63d3  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004e63d6  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e63d9  018ab8000000           +add dword ptr [edx + 0xb8], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e63df  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e63e6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e63ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e63ed  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e63f3  e9f6efffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e63f8:
    // 004e63f8  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e63fd  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e6403  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6406  0f85e2efffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
L_0x004e640c:
    // 004e640c  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6412  3b7a24                 +cmp edi, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6415  7533                   -jne 0x4e644a
    if (!cpu.flags.zf)
    {
        goto L_0x004e644a;
    }
    // 004e6417  8b0dbc455600           -mov ecx, dword ptr [0x5645bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e641d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e6420  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e6423  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e6425  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e6427  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004e6429  e8f2020000             -call 0x4e6720
    cpu.esp -= 4;
    sub_4e6720(app, cpu);
    if (cpu.terminate) return;
    // 004e642e  39c8                   +cmp eax, ecx
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
    // 004e6430  7f18                   -jg 0x4e644a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e644a;
    }
    // 004e6432  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6437  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e643d  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e6443  e82897ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e6448  ebc2                   -jmp 0x4e640c
    goto L_0x004e640c;
L_0x004e644a:
    // 004e644a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e644f  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e6455  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6458  0f8590efffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e645e  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6464  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6465  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e646b  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6470  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6473  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e6479  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e647c  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e647f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6482  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e6485  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e648b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e648c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e6492:
    // 004e6492  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6497  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e649a  752d                   -jne 0x4e64c9
    if (!cpu.flags.zf)
    {
        goto L_0x004e64c9;
    }
    // 004e649c  8b0dbc455600           -mov ecx, dword ptr [0x5645bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e64a2  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e64a5  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004e64a8  e833020000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e64ad  39d0                   +cmp eax, edx
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
    // 004e64af  7f18                   -jg 0x4e64c9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e64c9;
    }
    // 004e64b1  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e64b6  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e64bc  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e64c2  e8a996ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e64c7  ebc9                   -jmp 0x4e6492
    goto L_0x004e6492;
L_0x004e64c9:
    // 004e64c9  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e64ce  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e64d4  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e64d7  0f8511efffff           -jne 0x4e53ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e53ee;
    }
    // 004e64dd  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e64e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e64e4  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e64ea  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e64ef  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e64f2  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e64f5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e64f7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e64f9  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e64ff  894a4c                 -mov dword ptr [edx + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 004e6502  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 004e6505  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e6508  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e650b  e8e03f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e6510  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e6515  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6518  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e651b  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6520  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6523  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004e6526  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e6528  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004e652b:
    // 004e652b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6531  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6532  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e6538:
    // 004e6538  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e653d  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004e6540  2b504c                 -sub edx, dword ptr [eax + 0x4c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
    // 004e6543  3b5054                 +cmp edx, dword ptr [eax + 0x54]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6546  0f8ca2eeffff           -jl 0x4e53ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e53ee;
    }
    // 004e654c  3b7878                 +cmp edi, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e654f  0f85d4000000           -jne 0x4e6629
    if (!cpu.flags.zf)
    {
        goto L_0x004e6629;
    }
    // 004e6555  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
L_0x004e655a:
    // 004e655a  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e655f  3b7824                 +cmp edi, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6562  7557                   -jne 0x4e65bb
    if (!cpu.flags.zf)
    {
        goto L_0x004e65bb;
    }
    // 004e6564  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e656a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e656c  e86f010000             -call 0x4e66e0
    cpu.esp -= 4;
    sub_4e66e0(app, cpu);
    if (cpu.terminate) return;
    // 004e6571  03424c                 -add eax, dword ptr [edx + 0x4c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 004e6574  83f808                 +cmp eax, 8
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
    // 004e6577  7742                   -ja 0x4e65bb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e65bb;
    }
    // 004e6579  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e657e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004e6584  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004e658a  e8e195ffff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004e658f  ebc9                   -jmp 0x4e655a
    goto L_0x004e655a;
L_0x004e6591:
    // 004e6591  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 004e6597  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6598  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e659e  8b15bc455600           -mov edx, dword ptr [0x5645bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e65a4  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004e65a7  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e65aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e65ac  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e65b1  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e65b3  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004e65b6  e970ffffff             -jmp 0x4e652b
    goto L_0x004e652b;
L_0x004e65bb:
    // 004e65bb  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e65c0  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004e65c6  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004e65c9  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e65cb  746d                   -je 0x4e663a
    if (cpu.flags.zf)
    {
        goto L_0x004e663a;
    }
L_0x004e65cd:
    // 004e65cd  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e65d2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e65d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e65d9  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e65df  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e65e4  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
L_0x004e65e9:
    // 004e65e9  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e65ee  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e65f1  c702fdffffff           -mov dword ptr [edx], 0xfffffffd
    app->getMemory<x86::reg32>(cpu.edx) = 4294967293 /*0xfffffffd*/;
    // 004e65f7  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e65fa  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004e6601  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e6605  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e6608  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e660b  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e660e  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e6613  39c7                   +cmp edi, eax
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
    // 004e6615  75d2                   -jne 0x4e65e9
    if (!cpu.flags.zf)
    {
        goto L_0x004e65e9;
    }
    // 004e6617  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e661c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6622  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6623  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e6629:
    // 004e6629  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e662e  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004e6635  e9b4edffff             -jmp 0x4e53ee
    goto L_0x004e53ee;
L_0x004e663a:
    // 004e663a  a1bc455600             -mov eax, dword ptr [0x5645bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */);
    // 004e663f  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004e6642  a3bc455600             -mov dword ptr [0x5645bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653948) /* 0x5645bc */) = cpu.eax;
    // 004e6647  39c3                   +cmp ebx, eax
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
    // 004e6649  0f850bffffff           -jne 0x4e655a
    if (!cpu.flags.zf)
    {
        goto L_0x004e655a;
    }
    // 004e664f  e979ffffff             -jmp 0x4e65cd
    goto L_0x004e65cd;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e6660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6662  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6663  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e6665  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e666b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e666c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6672  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e6675  3b4314                 +cmp eax, dword ptr [ebx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6678  7430                   -je 0x4e66aa
    if (cpu.flags.zf)
    {
        goto L_0x004e66aa;
    }
L_0x004e667a:
    // 004e667a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e667d  3b4310                 +cmp eax, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6680  7428                   -je 0x4e66aa
    if (cpu.flags.zf)
    {
        goto L_0x004e66aa;
    }
    // 004e6682  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e6685  8338fe                 +cmp dword ptr [eax], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6688  7531                   -jne 0x4e66bb
    if (!cpu.flags.zf)
    {
        goto L_0x004e66bb;
    }
    // 004e668a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e668d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e6690  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e6693  2983bc000000           -sub dword ptr [ebx + 0xbc], eax
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(188) /* 0xbc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6699  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e669c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e669f  014318                 -add dword ptr [ebx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004e66a2:
    // 004e66a2  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e66a5  3b4314                 +cmp eax, dword ptr [ebx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e66a8  75d0                   -jne 0x4e667a
    if (!cpu.flags.zf)
    {
        goto L_0x004e667a;
    }
L_0x004e66aa:
    // 004e66aa  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e66b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e66b1  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e66b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e66b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e66b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e66ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e66bb:
    // 004e66bb  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e66be  8338ff                 +cmp dword ptr [eax], -1
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
    // 004e66c1  75e7                   -jne 0x4e66aa
    if (!cpu.flags.zf)
    {
        goto L_0x004e66aa;
    }
    // 004e66c3  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004e66c6  3b4314                 +cmp eax, dword ptr [ebx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e66c9  7506                   -jne 0x4e66d1
    if (!cpu.flags.zf)
    {
        goto L_0x004e66d1;
    }
    // 004e66cb  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004e66ce  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x004e66d1:
    // 004e66d1  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004e66d4  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004e66d7  ebc9                   -jmp 0x4e66a2
    goto L_0x004e66a2;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e66e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e66e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e66e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e66e3  e878ffffff             -call 0x4e6660
    cpu.esp -= 4;
    sub_4e6660(app, cpu);
    if (cpu.terminate) return;
    // 004e66e8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e66eb  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e66ee  7210                   -jb 0x4e6700
    if (cpu.flags.cf)
    {
        goto L_0x004e6700;
    }
    // 004e66f0  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e66f3  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e66f6  7510                   -jne 0x4e6708
    if (!cpu.flags.zf)
    {
        goto L_0x004e6708;
    }
    // 004e66f8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e66fb  3b4214                 +cmp eax, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e66fe  7508                   -jne 0x4e6708
    if (!cpu.flags.zf)
    {
        goto L_0x004e6708;
    }
L_0x004e6700:
    // 004e6700  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e6703  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004e6706  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6707  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6708:
    // 004e6708  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e670b  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004e670e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e670f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e6710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6710  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6711  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6713  e848ffffff             -call 0x4e6660
    cpu.esp -= 4;
    sub_4e6660(app, cpu);
    if (cpu.terminate) return;
    // 004e6718  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e671b  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004e671e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e671f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e6720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6720  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6721  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6723  e838ffffff             -call 0x4e6660
    cpu.esp -= 4;
    sub_4e6660(app, cpu);
    if (cpu.terminate) return;
    // 004e6728  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e672b  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e672e  7708                   -ja 0x4e6738
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e6738;
    }
    // 004e6730  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e6733  2b4204                 -sub eax, dword ptr [edx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004e6736  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6737  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6738:
    // 004e6738  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e673a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e673b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e6740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6741  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6743  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e6744  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e6745  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e6747  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6749  7441                   -je 0x4e678c
    if (cpu.flags.zf)
    {
        goto L_0x004e678c;
    }
    // 004e674b  83787800               +cmp dword ptr [eax + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e674f  7417                   -je 0x4e6768
    if (cpu.flags.zf)
    {
        goto L_0x004e6768;
    }
    // 004e6751  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 004e6754  8b8094000000           -mov eax, dword ptr [eax + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004e675a  83f80d                 +cmp eax, 0xd
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
    // 004e675d  735f                   -jae 0x4e67be
    if (!cpu.flags.cf)
    {
        goto L_0x004e67be;
    }
    // 004e675f  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6762  0f8464000000           -je 0x4e67cc
    if (cpu.flags.zf)
    {
        goto L_0x004e67cc;
    }
L_0x004e6768:
    // 004e6768  837b2002               +cmp dword ptr [ebx + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e676c  745e                   -je 0x4e67cc
    if (cpu.flags.zf)
    {
        goto L_0x004e67cc;
    }
    // 004e676e  837b2001               +cmp dword ptr [ebx + 0x20], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6772  7458                   -je 0x4e67cc
    if (cpu.flags.zf)
    {
        goto L_0x004e67cc;
    }
    // 004e6774  837b200e               +cmp dword ptr [ebx + 0x20], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6778  7456                   -je 0x4e67d0
    if (cpu.flags.zf)
    {
        goto L_0x004e67d0;
    }
    // 004e677a  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004e677d  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e6780  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6782  7553                   -jne 0x4e67d7
    if (!cpu.flags.zf)
    {
        goto L_0x004e67d7;
    }
    // 004e6784  31e8                   -xor eax, ebp
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004e6786:
    // 004e6786  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6787  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6788  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6789  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e678a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e678b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e678c:
    // 004e678c  b9d0a35400             -mov ecx, 0x54a3d0
    cpu.ecx = 5546960 /*0x54a3d0*/;
    // 004e6791  bb44a85400             -mov ebx, 0x54a844
    cpu.ebx = 5548100 /*0x54a844*/;
    // 004e6796  be1b090000             -mov esi, 0x91b
    cpu.esi = 2331 /*0x91b*/;
    // 004e679b  6854a85400             -push 0x54a854
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548116 /*0x54a854*/;
    cpu.esp -= 4;
    // 004e67a0  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e67a6  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e67ac  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e67b2  e859a8f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e67b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e67ba  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e67bc  ebc8                   -jmp 0x4e6786
    goto L_0x004e6786;
L_0x004e67be:
    // 004e67be  760c                   -jbe 0x4e67cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e67cc;
    }
    // 004e67c0  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e67c3  72a3                   -jb 0x4e6768
    if (cpu.flags.cf)
    {
        goto L_0x004e6768;
    }
    // 004e67c5  7605                   -jbe 0x4e67cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e67cc;
    }
    // 004e67c7  83f817                 +cmp eax, 0x17
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e67ca  759c                   -jne 0x4e6768
    if (!cpu.flags.zf)
    {
        goto L_0x004e6768;
    }
L_0x004e67cc:
    // 004e67cc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e67ce  ebb6                   -jmp 0x4e6786
    goto L_0x004e6786;
L_0x004e67d0:
    // 004e67d0  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004e67d5  ebaf                   -jmp 0x4e6786
    goto L_0x004e6786;
L_0x004e67d7:
    // 004e67d7  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e67dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e67de  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e67e4  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e67e7  8338ff                 +cmp dword ptr [eax], -1
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
    // 004e67ea  750e                   -jne 0x4e67fa
    if (!cpu.flags.zf)
    {
        goto L_0x004e67fa;
    }
    // 004e67ec  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004e67ef  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004e67f2  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004e67f5  3b4314                 +cmp eax, dword ptr [ebx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e67f8  7469                   -je 0x4e6863
    if (cpu.flags.zf)
    {
        goto L_0x004e6863;
    }
L_0x004e67fa:
    // 004e67fa  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e67fd  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e6800  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004e6803  3b5314                 +cmp edx, dword ptr [ebx + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6806  7370                   -jae 0x4e6878
    if (!cpu.flags.cf)
    {
        goto L_0x004e6878;
    }
    // 004e6808  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004e680b  2b7314                 -sub esi, dword ptr [ebx + 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
    // 004e680e  39c6                   +cmp esi, eax
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
    // 004e6810  7c51                   -jl 0x4e6863
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e6863;
    }
L_0x004e6812:
    // 004e6812  8b7314                 -mov esi, dword ptr [ebx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e6815  8d50f8                 -lea edx, [eax - 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004e6818  2993b8000000           -sub dword ptr [ebx + 0xb8], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(184) /* 0xb8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e681e  0193bc000000           -add dword ptr [ebx + 0xbc], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(188) /* 0xbc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6824  014314                 -add dword ptr [ebx + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e6827  833efd                 +cmp dword ptr [esi], -3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e682a  7522                   -jne 0x4e684e
    if (!cpu.flags.zf)
    {
        goto L_0x004e684e;
    }
    // 004e682c  3b7318                 +cmp esi, dword ptr [ebx + 0x18]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e682f  7566                   -jne 0x4e6897
    if (!cpu.flags.zf)
    {
        goto L_0x004e6897;
    }
    // 004e6831  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e6834  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004e6837:
    // 004e6837  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e683c  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004e6841  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004e6846  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e6849  e8d292ffff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
L_0x004e684e:
    // 004e684e  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e6854  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6855  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e685b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e685d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e685e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e685f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6863:
    // 004e6863  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e6869  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e686a  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6870  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6872  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6873  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6874  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6875  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6876  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6877  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6878:
    // 004e6878  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004e687b  2b7314                 -sub esi, dword ptr [ebx + 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */)));
    // 004e687e  39c6                   +cmp esi, eax
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
    // 004e6880  7d90                   -jge 0x4e6812
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6812;
    }
    // 004e6882  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e6888  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6889  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e688f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e6891  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6892  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6893  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6894  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6895  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6896  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6897:
    // 004e6897  c706feffffff           -mov dword ptr [esi], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.esi) = 4294967294 /*0xfffffffe*/;
    // 004e689d  eb98                   -jmp 0x4e6837
    goto L_0x004e6837;
}

/* align: skip 0x90 */
void Application::sub_4e68a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e68a0  058c000000             +add eax, 0x8c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e68a5  c702feffffff           -mov dword ptr [edx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.edx) = 4294967294 /*0xfffffffe*/;
    // 004e68ab  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e68ae  e96d92ffff             -jmp 0x4dfb20
    return sub_4dfb20(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e68c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e68c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e68c2  7406                   -je 0x4e68ca
    if (cpu.flags.zf)
    {
        goto L_0x004e68ca;
    }
    // 004e68c4  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
L_0x004e68ca:
    // 004e68ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e68d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e68d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e68d2  7406                   -je 0x4e68da
    if (cpu.flags.zf)
    {
        goto L_0x004e68da;
    }
    // 004e68d4  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
L_0x004e68da:
    // 004e68da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e68e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e68e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e68e1  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e68e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e68e9  7412                   -je 0x4e68fd
    if (cpu.flags.zf)
    {
        goto L_0x004e68fd;
    }
    // 004e68eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e68ed  837a2007               +cmp dword ptr [edx + 0x20], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e68f1  7506                   -jne 0x4e68f9
    if (!cpu.flags.zf)
    {
        goto L_0x004e68f9;
    }
    // 004e68f3  837a7800               +cmp dword ptr [edx + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e68f7  7404                   -je 0x4e68fd
    if (cpu.flags.zf)
    {
        goto L_0x004e68fd;
    }
L_0x004e68f9:
    // 004e68f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e68fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e68fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e68fd:
    // 004e68fd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e6902  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6903  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e6910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6911  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6912  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6913  8b1db8455600           -mov ebx, dword ptr [0x5645b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6919  8b83ac000000           -mov eax, dword ptr [ebx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e691f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6920  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6926  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e6928:
    // 004e6928  8983b4000000           -mov dword ptr [ebx + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 004e692e  8b5b70                 -mov ebx, dword ptr [ebx + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 004e6931  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e6933  75f3                   -jne 0x4e6928
    if (!cpu.flags.zf)
    {
        goto L_0x004e6928;
    }
    // 004e6935  8b1db8455600           -mov ebx, dword ptr [0x5645b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e693b  8b9bac000000           -mov ebx, dword ptr [ebx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(172) /* 0xac */);
    // 004e6941  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6942  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6948  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6949  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e694a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e694b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e6950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6950  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 004e6956  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e6960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6960  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6961  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e6963  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e6965  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6967  83f8ff                 +cmp eax, -1
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
    // 004e696a  7408                   -je 0x4e6974
    if (cpu.flags.zf)
    {
        goto L_0x004e6974;
    }
    // 004e696c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e696e  740d                   -je 0x4e697d
    if (cpu.flags.zf)
    {
        goto L_0x004e697d;
    }
L_0x004e6970:
    // 004e6970  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e6972  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6973  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6974:
    // 004e6974  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e6979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e697b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e697c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e697d:
    // 004e697d  e85effffff             -call 0x4e68e0
    cpu.esp -= 4;
    sub_4e68e0(app, cpu);
    if (cpu.terminate) return;
    // 004e6982  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6984  74ea                   -je 0x4e6970
    if (cpu.flags.zf)
    {
        goto L_0x004e6970;
    }
    // 004e6986  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e6988  e833ffffff             -call 0x4e68c0
    cpu.esp -= 4;
    sub_4e68c0(app, cpu);
    if (cpu.terminate) return;
    // 004e698d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e698f  75df                   -jne 0x4e6970
    if (!cpu.flags.zf)
    {
        goto L_0x004e6970;
    }
    // 004e6991  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e6996  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e6998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6999  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e69a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e69a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e69a1  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e69a7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e69a9  7502                   -jne 0x4e69ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e69ad;
    }
    // 004e69ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e69ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e69ad:
    // 004e69ad  c7423001000000         -mov dword ptr [edx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 004e69b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e69b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e69c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e69c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e69c1  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e69c7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e69c9  7502                   -jne 0x4e69cd
    if (!cpu.flags.zf)
    {
        goto L_0x004e69cd;
    }
    // 004e69cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e69cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e69cd:
    // 004e69cd  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004e69d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e69d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e69e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e69e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e69e1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e69e3  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e69e9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e69eb  7429                   -je 0x4e6a16
    if (cpu.flags.zf)
    {
        goto L_0x004e6a16;
    }
    // 004e69ed  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 004e69f0  49                     -dec ecx
    (cpu.ecx)--;
    // 004e69f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e69f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e69f5  7e15                   -jle 0x4e6a0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e6a0c;
    }
    // 004e69f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x004e69f8:
    // 004e69f8  8d989c000000           -lea ebx, [eax + 0x9c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 004e69fe  42                     -inc edx
    (cpu.edx)++;
    // 004e69ff  899898000000           -mov dword ptr [eax + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 004e6a05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e6a07  39ca                   +cmp edx, ecx
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
    // 004e6a09  7ced                   -jl 0x4e69f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e69f8;
    }
    // 004e6a0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e6a0c:
    // 004e6a0c  c7809800000000000000   -mov dword ptr [eax + 0x98], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
L_0x004e6a16:
    // 004e6a16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e6a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6a21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6a22  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e6a24  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6a2a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e6a2c  7503                   -jne 0x4e6a31
    if (!cpu.flags.zf)
    {
        goto L_0x004e6a31;
    }
    // 004e6a2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6a31:
    // 004e6a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6a32  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e6a38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6a39  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6a3f  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6a44  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004e6a47  899398000000           -mov dword ptr [ebx + 0x98], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 004e6a4d  895874                 -mov dword ptr [eax + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 004e6a50  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6a56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6a57  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6a5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4e6a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6a73  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e6a75  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6a7b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e6a7d  7506                   -jne 0x4e6a85
    if (!cpu.flags.zf)
    {
        goto L_0x004e6a85;
    }
L_0x004e6a7f:
    // 004e6a7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6a81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6a84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6a85:
    // 004e6a85  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e6a8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6a8c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6a92  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6a97  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004e6a9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e6a9c  740d                   -je 0x4e6aab
    if (cpu.flags.zf)
    {
        goto L_0x004e6aab;
    }
L_0x004e6a9e:
    // 004e6a9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6aa0  7409                   -je 0x4e6aab
    if (cpu.flags.zf)
    {
        goto L_0x004e6aab;
    }
    // 004e6aa2  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004e6aa8  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e6aa9  75f3                   -jne 0x4e6a9e
    if (!cpu.flags.zf)
    {
        goto L_0x004e6a9e;
    }
L_0x004e6aab:
    // 004e6aab  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6ab0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6ab6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6ab7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6abd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e6abf  75be                   -jne 0x4e6a7f
    if (!cpu.flags.zf)
    {
        goto L_0x004e6a7f;
    }
    // 004e6ac1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e6ac6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ac8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ac9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e6ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6ad1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6ad2  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6ad8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e6ada  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e6adc  7505                   -jne 0x4e6ae3
    if (!cpu.flags.zf)
    {
        goto L_0x004e6ae3;
    }
    // 004e6ade  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6ae0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ae1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ae2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6ae3:
    // 004e6ae3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6ae4  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e6aea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6aeb  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6af1  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6af6  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004e6af9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6afb  7413                   -je 0x4e6b10
    if (cpu.flags.zf)
    {
        goto L_0x004e6b10;
    }
L_0x004e6afd:
    // 004e6afd  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004e6b03  43                     -inc ebx
    (cpu.ebx)++;
    // 004e6b04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6b06  75f5                   -jne 0x4e6afd
    if (!cpu.flags.zf)
    {
        goto L_0x004e6afd;
    }
    // 004e6b08  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e6b0e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_0x004e6b10:
    // 004e6b10  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6b15  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6b1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6b1c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6b22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e6b24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b25  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e6b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6b31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6b32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6b33  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e6b35  8b15b8455600           -mov edx, dword ptr [0x5645b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6b3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e6b3d  7506                   -jne 0x4e6b45
    if (!cpu.flags.zf)
    {
        goto L_0x004e6b45;
    }
    // 004e6b3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6b41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6b45:
    // 004e6b45  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004e6b4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6b4c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6b52  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6b57  83787400               +cmp dword ptr [eax + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6b5b  7536                   -jne 0x4e6b93
    if (!cpu.flags.zf)
    {
        goto L_0x004e6b93;
    }
    // 004e6b5d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e6b5f  7463                   -je 0x4e6bc4
    if (cpu.flags.zf)
    {
        goto L_0x004e6bc4;
    }
    // 004e6b61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e6b62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e6b63  bbd0a35400             -mov ebx, 0x54a3d0
    cpu.ebx = 5546960 /*0x54a3d0*/;
    // 004e6b68  be80a85400             -mov esi, 0x54a880
    cpu.esi = 5548160 /*0x54a880*/;
    // 004e6b6d  bfe60a0000             -mov edi, 0xae6
    cpu.edi = 2790 /*0xae6*/;
    // 004e6b72  6890a85400             -push 0x54a890
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548176 /*0x54a890*/;
    cpu.esp -= 4;
    // 004e6b77  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e6b7d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e6b83  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e6b89  e882a4f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e6b8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e6b91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6b92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e6b93:
    // 004e6b93  a1b8455600             -mov eax, dword ptr [0x5645b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653944) /* 0x5645b8 */);
    // 004e6b98  8b5874                 -mov ebx, dword ptr [eax + 0x74]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004e6b9b  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004e6b9e  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 004e6ba4  895074                 -mov dword ptr [eax + 0x74], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004e6ba7  c7839800000000000000   -mov dword ptr [ebx + 0x98], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 004e6bb1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6bb7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6bb8  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6bbe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e6bc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6bc4:
    // 004e6bc4  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004e6bca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e6bcb  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e6bd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6bd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6bd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e6be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6be1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6be2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6be3  66833d5446560000       +cmp word ptr [0x564654], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e6beb  0f8cc1000000           -jl 0x4e6cb2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e6cb2;
    }
    // 004e6bf1  0fbf05c4455600         -movsx eax, word ptr [0x5645c4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6bf8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e6bfb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6bfd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e6c00  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c02  8b1560465600           -mov edx, dword ptr [0x564660]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6c08  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c0c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004e6c0e  a15c465600             -mov eax, dword ptr [0x56465c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e6c13  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004e6c16  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e6c1b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004e6c1e  0fbf1554465600         -movsx edx, word ptr [0x564654]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */)));
    // 004e6c25  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c27  8b15cc455600           -mov edx, dword ptr [0x5645cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653964) /* 0x5645cc */);
    // 004e6c2d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004e6c30  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e6c32  66a3c4455600           -mov word ptr [0x5645c4], ax
    app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */) = cpu.ax;
    // 004e6c38  a158465600             -mov eax, dword ptr [0x564658]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654104) /* 0x564658 */);
    // 004e6c3d  a354465600             -mov dword ptr [0x564654], eax
    app->getMemory<x86::reg32>(x86::reg32(5654100) /* 0x564654 */) = cpu.eax;
    // 004e6c42  66c70558465600ffff     -mov word ptr [0x564658], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5654104) /* 0x564658 */) = 65535 /*0xffff*/;
    // 004e6c4b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6c4d  66890d5a465600         -mov word ptr [0x56465a], cx
    app->getMemory<x86::reg16>(x86::reg32(5654106) /* 0x56465a */) = cpu.cx;
L_0x004e6c54:
    // 004e6c54  ff05c8455600           -inc dword ptr [0x5645c8]
    (app->getMemory<x86::reg32>(x86::reg32(5653960) /* 0x5645c8 */))++;
    // 004e6c5a  0fbf05c4455600         -movsx eax, word ptr [0x5645c4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6c61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e6c64  8b15d0455600           -mov edx, dword ptr [0x5645d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653968) /* 0x5645d0 */);
    // 004e6c6a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e6c6f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c71  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e6c73  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e6c75  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e6c77  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e6c7e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e6c80  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6c82  b8d4455600             -mov eax, 0x5645d4
    cpu.eax = 5653972 /*0x5645d4*/;
    // 004e6c87  e8140c0000             -call 0x4e78a0
    cpu.esp -= 4;
    sub_4e78a0(app, cpu);
    if (cpu.terminate) return;
    // 004e6c8c  0fbf05c4455600         -movsx eax, word ptr [0x5645c4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6c93  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e6c96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6c98  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e6c9b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6c9d  8b1560465600           -mov edx, dword ptr [0x564660]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6ca3  807c020100             +cmp byte ptr [edx + eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6ca8  0f8694000000           -jbe 0x4e6d42
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e6d42;
    }
L_0x004e6cae:
    // 004e6cae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6caf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6cb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6cb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6cb2:
    // 004e6cb2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6cb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e6cb6:
    // 004e6cb6  0fbf0dc4455600         -movsx ecx, word ptr [0x5645c4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6cbd  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004e6cc0  8b1d60465600           -mov ebx, dword ptr [0x564660]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6cc6  8a4c1901               -mov cl, byte ptr [ecx + ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.ebx * 1);
    // 004e6cca  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e6cd0  39ca                   +cmp edx, ecx
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
    // 004e6cd2  7d80                   -jge 0x4e6c54
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6c54;
    }
    // 004e6cd4  0fbf0dc4455600         -movsx ecx, word ptr [0x5645c4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6cdb  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004e6cde  8b1d60465600           -mov ebx, dword ptr [0x564660]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6ce4  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e6ce6  8a1dc6455600           -mov bl, byte ptr [0x5645c6]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5653958) /* 0x5645c6 */);
    // 004e6cec  3a5c0104               +cmp bl, byte ptr [ecx + eax + 4]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6cf0  7d06                   -jge 0x4e6cf8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6cf8;
    }
L_0x004e6cf2:
    // 004e6cf2  83c003                 +add eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e6cf5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e6cf6  ebbe                   -jmp 0x4e6cb6
    goto L_0x004e6cb6;
L_0x004e6cf8:
    // 004e6cf8  0fbf1dc4455600         -movsx ebx, word ptr [0x5645c4]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6cff  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004e6d02  8b0d60465600           -mov ecx, dword ptr [0x564660]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6d08  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e6d0a  8a1dc6455600           -mov bl, byte ptr [0x5645c6]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5653958) /* 0x5645c6 */);
    // 004e6d10  3a5c0105               +cmp bl, byte ptr [ecx + eax + 5]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6d14  7fdc                   -jg 0x4e6cf2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e6cf2;
    }
    // 004e6d16  0fbf15c4455600         -movsx edx, word ptr [0x5645c4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6d1d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004e6d20  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e6d22  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004e6d25  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6d27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e6d29  8b1560465600           -mov edx, dword ptr [0x564660]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6d2f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6d31  8a440206               -mov al, byte ptr [edx + eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */ + cpu.eax * 1);
    // 004e6d35  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004e6d37  66a3c4455600           -mov word ptr [0x5645c4], ax
    app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */) = cpu.ax;
    // 004e6d3d  e912ffffff             -jmp 0x4e6c54
    goto L_0x004e6c54;
L_0x004e6d42:
    // 004e6d42  66833d5446560000       +cmp word ptr [0x564654], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e6d4a  0f8d5effffff           -jge 0x4e6cae
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6cae;
    }
    // 004e6d50  b8686d4e00             -mov eax, 0x4e6d68
    cpu.eax = 5139816 /*0x4e6d68*/;
    // 004e6d55  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6d57  e884080000             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004e6d5c  890d0c485600           -mov dword ptr [0x56480c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */) = cpu.ecx;
    // 004e6d62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6d65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e6d68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6d68  e8b3150000             -call 0x4e8320
    cpu.esp -= 4;
    sub_4e8320(app, cpu);
    if (cpu.terminate) return;
    // 004e6d6d  3b05c8455600           +cmp eax, dword ptr [0x5645c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653960) /* 0x5645c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6d73  7d03                   -jge 0x4e6d78
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6d78;
    }
L_0x004e6d75:
    // 004e6d75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6d77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6d78:
    // 004e6d78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6d7a  668b15c2455600         -mov dx, word ptr [0x5645c2]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5653954) /* 0x5645c2 */);
    // 004e6d81  e85a0f0000             -call 0x4e7ce0
    cpu.esp -= 4;
    sub_4e7ce0(app, cpu);
    if (cpu.terminate) return;
    // 004e6d86  39d0                   +cmp eax, edx
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
    // 004e6d88  7deb                   -jge 0x4e6d75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e6d75;
    }
    // 004e6d8a  e851feffff             -call 0x4e6be0
    cpu.esp -= 4;
    sub_4e6be0(app, cpu);
    if (cpu.terminate) return;
    // 004e6d8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6d91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e6d94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6d94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e6d96  7515                   -jne 0x4e6dad
    if (!cpu.flags.zf)
    {
        goto L_0x004e6dad;
    }
    // 004e6d98  66a1c0455600           -mov ax, word ptr [0x5645c0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5653952) /* 0x5645c0 */);
    // 004e6d9e  66a3c2455600           -mov word ptr [0x5645c2], ax
    app->getMemory<x86::reg16>(x86::reg32(5653954) /* 0x5645c2 */) = cpu.ax;
    // 004e6da4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6da6  66a1c0455600           -mov ax, word ptr [0x5645c0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5653952) /* 0x5645c0 */);
    // 004e6dac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6dad:
    // 004e6dad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6dae  668b15c0455600         -mov dx, word ptr [0x5645c0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5653952) /* 0x5645c0 */);
    // 004e6db5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6db7  66a3c2455600           -mov word ptr [0x5645c2], ax
    app->getMemory<x86::reg16>(x86::reg32(5653954) /* 0x5645c2 */) = cpu.ax;
    // 004e6dbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6dbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6dc0  66a1c0455600           -mov ax, word ptr [0x5645c0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5653952) /* 0x5645c0 */);
    // 004e6dc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e6dc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6dc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6dc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e6dca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e6dcb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e6dcc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e6dcd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6dcf  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6dd6  0f847a000000           -je 0x4e6e56
    if (cpu.flags.zf)
    {
        goto L_0x004e6e56;
    }
    // 004e6ddc  8b0d5c465600           -mov ecx, dword ptr [0x56465c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e6de2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e6de4  7577                   -jne 0x4e6e5d
    if (!cpu.flags.zf)
    {
        goto L_0x004e6e5d;
    }
    // 004e6de6  89155c465600           -mov dword ptr [0x56465c], edx
    app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */) = cpu.edx;
    // 004e6dec  813a50464478           +cmp dword ptr [edx], 0x78444650
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2017740368 /*0x78444650*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6df2  0f859e000000           -jne 0x4e6e96
    if (!cpu.flags.zf)
    {
        goto L_0x004e6e96;
    }
    // 004e6df8  807a0400               +cmp byte ptr [edx + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6dfc  0f85cf000000           -jne 0x4e6ed1
    if (!cpu.flags.zf)
    {
        goto L_0x004e6ed1;
    }
    // 004e6e02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e6e04  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e6e07  a360465600             -mov dword ptr [0x564660], eax
    app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */) = cpu.eax;
    // 004e6e0c  8a4a06                 -mov cl, byte ptr [edx + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004e6e0f  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004e6e12  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004e6e19  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e6e1b  8b0d60465600           -mov ecx, dword ptr [0x564660]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e6e21  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e6e23  890dcc455600           -mov dword ptr [0x5645cc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653964) /* 0x5645cc */) = cpu.ecx;
    // 004e6e29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e6e2b  8a420b                 -mov al, byte ptr [edx + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 004e6e2e  8a5207                 -mov dl, byte ptr [edx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004e6e31  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e6e37  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004e6e3a  be88734e00             -mov esi, 0x4e7388
    cpu.esi = 5141384 /*0x4e7388*/;
    // 004e6e3f  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004e6e42  89352c9ba000           -mov dword ptr [0xa09b2c], esi
    app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */) = cpu.esi;
    // 004e6e48  8915d0455600           -mov dword ptr [0x5645d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653968) /* 0x5645d0 */) = cpu.edx;
    // 004e6e4e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x004e6e50:
    // 004e6e50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6e56:
    // 004e6e56  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e6e5b  ebf3                   -jmp 0x4e6e50
    goto L_0x004e6e50;
L_0x004e6e5d:
    // 004e6e5d  beb8a85400             -mov esi, 0x54a8b8
    cpu.esi = 5548216 /*0x54a8b8*/;
    // 004e6e62  bfc8a85400             -mov edi, 0x54a8c8
    cpu.edi = 5548232 /*0x54a8c8*/;
    // 004e6e67  bded000000             -mov ebp, 0xed
    cpu.ebp = 237 /*0xed*/;
    // 004e6e6c  68d4a85400             -push 0x54a8d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548244 /*0x54a8d4*/;
    cpu.esp -= 4;
    // 004e6e71  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e6e77  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e6e7d  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e6e83  e888a1f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e6e88  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e6e8d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e6e90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6e95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6e96:
    // 004e6e96  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e6e97  bab8a85400             -mov edx, 0x54a8b8
    cpu.edx = 5548216 /*0x54a8b8*/;
    // 004e6e9c  b9c8a85400             -mov ecx, 0x54a8c8
    cpu.ecx = 5548232 /*0x54a8c8*/;
    // 004e6ea1  bbf9000000             -mov ebx, 0xf9
    cpu.ebx = 249 /*0xf9*/;
    // 004e6ea6  681ca95400             -push 0x54a91c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548316 /*0x54a91c*/;
    cpu.esp -= 4;
    // 004e6eab  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e6eb1  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e6eb7  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e6ebd  e84ea1f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e6ec2  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004e6ec7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e6eca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ecb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ecc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ecd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ece  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ecf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6ed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e6ed1:
    // 004e6ed1  bfb8a85400             -mov edi, 0x54a8b8
    cpu.edi = 5548216 /*0x54a8b8*/;
    // 004e6ed6  bdc8a85400             -mov ebp, 0x54a8c8
    cpu.ebp = 5548232 /*0x54a8c8*/;
    // 004e6edb  b803010000             -mov eax, 0x103
    cpu.eax = 259 /*0x103*/;
    // 004e6ee0  6850a95400             -push 0x54a950
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548368 /*0x54a950*/;
    cpu.esp -= 4;
    // 004e6ee5  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e6eeb  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e6ef1  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e6ef6  e815a1f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e6efb  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004e6f00  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e6f03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6f04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6f05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6f06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6f07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6f08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e6f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e6f0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e6f0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e6f0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e6f0f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e6f12  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e6f14  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e6f1b  0f84f5000000           -je 0x4e7016
    if (cpu.flags.zf)
    {
        goto L_0x004e7016;
    }
    // 004e6f21  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e6f28  0f84f4000000           -je 0x4e7022
    if (cpu.flags.zf)
    {
        goto L_0x004e7022;
    }
    // 004e6f2e  a364465600             -mov dword ptr [0x564664], eax
    app->getMemory<x86::reg32>(x86::reg32(5654116) /* 0x564664 */) = cpu.eax;
    // 004e6f33  66891dc0455600         -mov word ptr [0x5645c0], bx
    app->getMemory<x86::reg16>(x86::reg32(5653952) /* 0x5645c0 */) = cpu.bx;
    // 004e6f3a  66891dc2455600         -mov word ptr [0x5645c2], bx
    app->getMemory<x86::reg16>(x86::reg32(5653954) /* 0x5645c2 */) = cpu.bx;
    // 004e6f41  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004e6f46  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e6f48:
    // 004e6f48  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e6f4b  66899050465600         -mov word ptr [eax + 0x564650], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5654096) /* 0x564650 */) = cpu.dx;
    // 004e6f52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e6f54  66899852465600         -mov word ptr [eax + 0x564652], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5654098) /* 0x564652 */) = cpu.bx;
    // 004e6f5b  83f808                 +cmp eax, 8
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
    // 004e6f5e  75e8                   -jne 0x4e6f48
    if (!cpu.flags.zf)
    {
        goto L_0x004e6f48;
    }
    // 004e6f60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e6f61  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e6f63  8835c6455600           -mov byte ptr [0x5645c6], dh
    app->getMemory<x86::reg8>(x86::reg32(5653958) /* 0x5645c6 */) = cpu.dh;
    // 004e6f69  a15c465600             -mov eax, dword ptr [0x56465c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e6f6e  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004e6f71  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e6f73  66a3c4455600           -mov word ptr [0x5645c4], ax
    app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */) = cpu.ax;
    // 004e6f79  e8a2130000             -call 0x4e8320
    cpu.esp -= 4;
    sub_4e8320(app, cpu);
    if (cpu.terminate) return;
    // 004e6f7e  a3c8455600             -mov dword ptr [0x5645c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653960) /* 0x5645c8 */) = cpu.eax;
    // 004e6f83  bfd4455600             -mov edi, 0x5645d4
    cpu.edi = 5653972 /*0x5645d4*/;
    // 004e6f88  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004e6f8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004e6f8b:
    // 004e6f8b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e6f8d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004e6f8f  3c00                   +cmp al, 0
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
    // 004e6f91  7410                   -je 0x4e6fa3
    if (cpu.flags.zf)
    {
        goto L_0x004e6fa3;
    }
    // 004e6f93  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004e6f96  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e6f99  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004e6f9c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e6f9f  3c00                   +cmp al, 0
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
    // 004e6fa1  75e8                   -jne 0x4e6f8b
    if (!cpu.flags.zf)
    {
        goto L_0x004e6f8b;
    }
L_0x004e6fa3:
    // 004e6fa3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e6fa4  ff05c8455600           -inc dword ptr [0x5645c8]
    (app->getMemory<x86::reg32>(x86::reg32(5653960) /* 0x5645c8 */))++;
    // 004e6faa  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e6fae  e86d2b0000             -call 0x4e9b20
    cpu.esp -= 4;
    sub_4e9b20(app, cpu);
    if (cpu.terminate) return;
    // 004e6fb3  a164465600             -mov eax, dword ptr [0x564664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654116) /* 0x564664 */);
    // 004e6fb8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e6fbc  e88f070000             -call 0x4e7750
    cpu.esp -= 4;
    sub_4e7750(app, cpu);
    if (cpu.terminate) return;
    // 004e6fc1  0fbf05c4455600         -movsx eax, word ptr [0x5645c4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e6fc8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e6fcb  8b15d0455600           -mov edx, dword ptr [0x5645d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653968) /* 0x5645d0 */);
    // 004e6fd1  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e6fd6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e6fd8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e6fda  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e6fdc  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e6fde  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e6fe5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e6fe7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e6fe9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e6feb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004e6ff0  e8ab080000             -call 0x4e78a0
    cpu.esp -= 4;
    sub_4e78a0(app, cpu);
    if (cpu.terminate) return;
    // 004e6ff5  b8686d4e00             -mov eax, 0x4e6d68
    cpu.eax = 5139816 /*0x4e6d68*/;
    // 004e6ffa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e6ffc  bd946d4e00             -mov ebp, 0x4e6d94
    cpu.ebp = 5139860 /*0x4e6d94*/;
    // 004e7001  e81a050000             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 004e7006  892d0c485600           -mov dword ptr [0x56480c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */) = cpu.ebp;
    // 004e700c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e700e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e700f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e7012  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7013  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7014  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7015  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7016:
    // 004e7016  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e701b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e701e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e701f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7021  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7022:
    // 004e7022  b9b8a85400             -mov ecx, 0x54a8b8
    cpu.ecx = 5548216 /*0x54a8b8*/;
    // 004e7027  bb8ca95400             -mov ebx, 0x54a98c
    cpu.ebx = 5548428 /*0x54a98c*/;
    // 004e702c  bea5010000             -mov esi, 0x1a5
    cpu.esi = 421 /*0x1a5*/;
    // 004e7031  68a0a95400             -push 0x54a9a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548448 /*0x54a9a0*/;
    cpu.esp -= 4;
    // 004e7036  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e703c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7042  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e7048  e8c39ff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e704d  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7052  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7055  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e7058  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e705a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e705b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e705c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e705c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e705d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e705e  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7065  741c                   -je 0x4e7083
    if (cpu.flags.zf)
    {
        goto L_0x004e7083;
    }
    // 004e7067  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e706e  741b                   -je 0x4e708b
    if (cpu.flags.zf)
    {
        goto L_0x004e708b;
    }
    // 004e7070  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7072  7c4c                   -jl 0x4e70c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e70c0;
    }
    // 004e7074  83f87f                 +cmp eax, 0x7f
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
    // 004e7077  7f47                   -jg 0x4e70c0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e70c0;
    }
    // 004e7079  a2c6455600             -mov byte ptr [0x5645c6], al
    app->getMemory<x86::reg8>(x86::reg32(5653958) /* 0x5645c6 */) = cpu.al;
    // 004e707e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7080  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7081  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7082  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7083:
    // 004e7083  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7088  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7089  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e708a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e708b:
    // 004e708b  bfb8a85400             -mov edi, 0x54a8b8
    cpu.edi = 5548216 /*0x54a8b8*/;
    // 004e7090  bdd4a95400             -mov ebp, 0x54a9d4
    cpu.ebp = 5548500 /*0x54a9d4*/;
    // 004e7095  b83a020000             -mov eax, 0x23a
    cpu.eax = 570 /*0x23a*/;
    // 004e709a  68e4a95400             -push 0x54a9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548516 /*0x54a9e4*/;
    cpu.esp -= 4;
    // 004e709f  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e70a5  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e70ab  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e70b0  e85b9ff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e70b5  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e70ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e70bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e70c0:
    // 004e70c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e70c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e70c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e70c3  b9b8a85400             -mov ecx, 0x54a8b8
    cpu.ecx = 5548216 /*0x54a8b8*/;
    // 004e70c8  bbd4a95400             -mov ebx, 0x54a9d4
    cpu.ebx = 5548500 /*0x54a9d4*/;
    // 004e70cd  be43020000             -mov esi, 0x243
    cpu.esi = 579 /*0x243*/;
    // 004e70d2  6814aa5400             -push 0x54aa14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548564 /*0x54aa14*/;
    cpu.esp -= 4;
    // 004e70d7  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e70dd  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e70e3  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e70e9  e8229ff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e70ee  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e70f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e70f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e70fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e70fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e70fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e70fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e70fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e70ff  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7106  744e                   -je 0x4e7156
    if (cpu.flags.zf)
    {
        goto L_0x004e7156;
    }
    // 004e7108  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e710f  744e                   -je 0x4e715f
    if (cpu.flags.zf)
    {
        goto L_0x004e715f;
    }
    // 004e7111  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7113  0f8c7c000000           -jl 0x4e7195
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7195;
    }
    // 004e7119  8b0d5c465600           -mov ecx, dword ptr [0x56465c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e711f  8a4907                 -mov cl, byte ptr [ecx + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004e7122  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e7128  39c8                   +cmp eax, ecx
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
    // 004e712a  7d69                   -jge 0x4e7195
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e7195;
    }
    // 004e712c  83fa01                 +cmp edx, 1
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
    // 004e712f  0f849b000000           -je 0x4e71d0
    if (cpu.flags.zf)
    {
        goto L_0x004e71d0;
    }
    // 004e7135  66833d5646560001       +cmp word ptr [0x564656], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5654102) /* 0x564656 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e713d  0f85b2000000           -jne 0x4e71f5
    if (!cpu.flags.zf)
    {
        goto L_0x004e71f5;
    }
    // 004e7143  66a358465600           -mov word ptr [0x564658], ax
    app->getMemory<x86::reg16>(x86::reg32(5654104) /* 0x564658 */) = cpu.ax;
    // 004e7149  6689155a465600         -mov word ptr [0x56465a], dx
    app->getMemory<x86::reg16>(x86::reg32(5654106) /* 0x56465a */) = cpu.dx;
    // 004e7150  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7152  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7153  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7154  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7155  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7156:
    // 004e7156  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e715b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e715c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e715d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e715e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e715f:
    // 004e715f  bdb8a85400             -mov ebp, 0x54a8b8
    cpu.ebp = 5548216 /*0x54a8b8*/;
    // 004e7164  b848aa5400             -mov eax, 0x54aa48
    cpu.eax = 5548616 /*0x54aa48*/;
    // 004e7169  bad0020000             -mov edx, 0x2d0
    cpu.edx = 720 /*0x2d0*/;
    // 004e716e  6858aa5400             -push 0x54aa58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548632 /*0x54aa58*/;
    cpu.esp -= 4;
    // 004e7173  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e7179  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e717e  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e7184  e8879ef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7189  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e718e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7191  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7192  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7193  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7194  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7195:
    // 004e7195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7196  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7197  bbb8a85400             -mov ebx, 0x54a8b8
    cpu.ebx = 5548216 /*0x54a8b8*/;
    // 004e719c  be48aa5400             -mov esi, 0x54aa48
    cpu.esi = 5548616 /*0x54aa48*/;
    // 004e71a1  bfd9020000             -mov edi, 0x2d9
    cpu.edi = 729 /*0x2d9*/;
    // 004e71a6  6884aa5400             -push 0x54aa84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548676 /*0x54aa84*/;
    cpu.esp -= 4;
    // 004e71ab  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e71b1  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e71b7  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e71bd  e84e9ef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e71c2  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e71c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e71ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e71d0:
    // 004e71d0  66a354465600           -mov word ptr [0x564654], ax
    app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */) = cpu.ax;
    // 004e71d6  66891556465600         -mov word ptr [0x564656], dx
    app->getMemory<x86::reg16>(x86::reg32(5654102) /* 0x564656 */) = cpu.dx;
    // 004e71dd  66c70558465600ffff     -mov word ptr [0x564658], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5654104) /* 0x564658 */) = 65535 /*0xffff*/;
    // 004e71e6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e71e8  6689355a465600         -mov word ptr [0x56465a], si
    app->getMemory<x86::reg16>(x86::reg32(5654106) /* 0x56465a */) = cpu.si;
    // 004e71ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e71f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e71f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e71f5:
    // 004e71f5  66a354465600           -mov word ptr [0x564654], ax
    app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */) = cpu.ax;
    // 004e71fb  66891556465600         -mov word ptr [0x564656], dx
    app->getMemory<x86::reg16>(x86::reg32(5654102) /* 0x564656 */) = cpu.dx;
    // 004e7202  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7204  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7205  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7206  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e7208(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7208  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7209  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e720a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e720b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e720c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e720e  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7215  0f84e0000000           -je 0x4e72fb
    if (cpu.flags.zf)
    {
        goto L_0x004e72fb;
    }
    // 004e721b  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7222  0f84dd000000           -je 0x4e7305
    if (cpu.flags.zf)
    {
        goto L_0x004e7305;
    }
    // 004e7228  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e722a  0f8c0c010000           -jl 0x4e733c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e733c;
    }
    // 004e7230  a15c465600             -mov eax, dword ptr [0x56465c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e7235  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004e7238  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e723d  39c2                   +cmp edx, eax
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
    // 004e723f  0f8df7000000           -jge 0x4e733c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e733c;
    }
    // 004e7245  e8d69b0100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e724a  0fbf05c4455600         -movsx eax, word ptr [0x5645c4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */)));
    // 004e7251  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e7254  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7256  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e7259  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e725b  8b0d60465600           -mov ecx, dword ptr [0x564660]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654112) /* 0x564660 */);
    // 004e7261  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e7263  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e7265  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004e7267  a15c465600             -mov eax, dword ptr [0x56465c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */);
    // 004e726c  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004e726f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e7274  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004e7277  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e7279  8b15cc455600           -mov edx, dword ptr [0x5645cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653964) /* 0x5645cc */);
    // 004e727f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e7281  8a1c02                 -mov bl, byte ptr [edx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004e7284  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004e728b  8b15d0455600           -mov edx, dword ptr [0x5645d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653968) /* 0x5645d0 */);
    // 004e7291  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e7296  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e7298  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e729a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e729c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e729e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e72a5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e72a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e72a9  b8d4455600             -mov eax, 0x5645d4
    cpu.eax = 5653972 /*0x5645d4*/;
    // 004e72ae  e861070000             -call 0x4e7a14
    cpu.esp -= 4;
    sub_4e7a14(app, cpu);
    if (cpu.terminate) return;
    // 004e72b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e72b5  0f85bd000000           -jne 0x4e7378
    if (!cpu.flags.zf)
    {
        goto L_0x004e7378;
    }
    // 004e72bb  e860100000             -call 0x4e8320
    cpu.esp -= 4;
    sub_4e8320(app, cpu);
    if (cpu.terminate) return;
    // 004e72c0  a3c8455600             -mov dword ptr [0x5645c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653960) /* 0x5645c8 */) = cpu.eax;
    // 004e72c5  66891dc4455600         -mov word ptr [0x5645c4], bx
    app->getMemory<x86::reg16>(x86::reg32(5653956) /* 0x5645c4 */) = cpu.bx;
    // 004e72cc  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004e72d1  66891554465600         -mov word ptr [0x564654], dx
    app->getMemory<x86::reg16>(x86::reg32(5654100) /* 0x564654 */) = cpu.dx;
    // 004e72d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e72da  66891d56465600         -mov word ptr [0x564656], bx
    app->getMemory<x86::reg16>(x86::reg32(5654102) /* 0x564656 */) = cpu.bx;
    // 004e72e1  66891558465600         -mov word ptr [0x564658], dx
    app->getMemory<x86::reg16>(x86::reg32(5654104) /* 0x564658 */) = cpu.dx;
    // 004e72e8  66891d5a465600         -mov word ptr [0x56465a], bx
    app->getMemory<x86::reg16>(x86::reg32(5654106) /* 0x56465a */) = cpu.bx;
    // 004e72ef  e8889b0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e72f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e72f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e72f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e72f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e72f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e72fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e72fb:
    // 004e72fb  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7300  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7301  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7303  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7304  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7305:
    // 004e7305  bdb8a85400             -mov ebp, 0x54a8b8
    cpu.ebp = 5548216 /*0x54a8b8*/;
    // 004e730a  b8a8aa5400             -mov eax, 0x54aaa8
    cpu.eax = 5548712 /*0x54aaa8*/;
    // 004e730f  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 004e7314  68c0aa5400             -push 0x54aac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548736 /*0x54aac0*/;
    cpu.esp -= 4;
    // 004e7319  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e731f  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e7324  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e732a  e8e19cf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e732f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7334  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7337  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7338  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7339  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e733a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e733b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e733c:
    // 004e733c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e733d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e733e  bbb8a85400             -mov ebx, 0x54a8b8
    cpu.ebx = 5548216 /*0x54a8b8*/;
    // 004e7343  bea8aa5400             -mov esi, 0x54aaa8
    cpu.esi = 5548712 /*0x54aaa8*/;
    // 004e7348  bf0c030000             -mov edi, 0x30c
    cpu.edi = 780 /*0x30c*/;
    // 004e734d  68f8aa5400             -push 0x54aaf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548792 /*0x54aaf8*/;
    cpu.esp -= 4;
    // 004e7352  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e7358  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e735e  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e7364  e8a79cf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7369  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e736e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7371  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7372  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7373  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7374  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7375  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7376  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7377  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7378:
    // 004e7378  e8ff9a0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e737d  b8eeffffff             -mov eax, 0xffffffee
    cpu.eax = 4294967278 /*0xffffffee*/;
    // 004e7382  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e7388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7388  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e738f  7409                   -je 0x4e739a
    if (cpu.flags.zf)
    {
        goto L_0x004e739a;
    }
    // 004e7391  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7398  7506                   -jne 0x4e73a0
    if (!cpu.flags.zf)
    {
        goto L_0x004e73a0;
    }
L_0x004e739a:
    // 004e739a  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e739f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e73a0:
    // 004e73a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e73a1  e8a6040000             -call 0x4e784c
    cpu.esp -= 4;
    sub_4e784c(app, cpu);
    if (cpu.terminate) return;
    // 004e73a6  b8686d4e00             -mov eax, 0x4e6d68
    cpu.eax = 5139816 /*0x4e6d68*/;
    // 004e73ab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e73ad  e82e020000             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004e73b2  890d5c465600           -mov dword ptr [0x56465c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654108) /* 0x56465c */) = cpu.ecx;
    // 004e73b8  890d0c485600           -mov dword ptr [0x56480c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */) = cpu.ecx;
    // 004e73be  890d2c9ba000           -mov dword ptr [0xa09b2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */) = cpu.ecx;
    // 004e73c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e73c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e73c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e73d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e73d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e73d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e73d3  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e73da  7450                   -je 0x4e742c
    if (cpu.flags.zf)
    {
        goto L_0x004e742c;
    }
    // 004e73dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e73dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e73de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e73e0  7c51                   -jl 0x4e7433
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7433;
    }
    // 004e73e2  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e73e5  7f4c                   -jg 0x4e7433
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e7433;
    }
L_0x004e73e7:
    // 004e73e7  e8349a0100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e73ec  bb3c9ba000             -mov ebx, 0xa09b3c
    cpu.ebx = 10525500 /*0xa09b3c*/;
    // 004e73f1  8815f59aa000           -mov byte ptr [0xa09af5], dl
    app->getMemory<x86::reg8>(x86::reg32(10525429) /* 0xa09af5 */) = cpu.dl;
    // 004e73f7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e73f9:
    // 004e73f9  807b0c01               +cmp byte ptr [ebx + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e73fd  7519                   -jne 0x4e7418
    if (!cpu.flags.zf)
    {
        goto L_0x004e7418;
    }
    // 004e73ff  833b00                 +cmp dword ptr [ebx], 0
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
    // 004e7402  7c14                   -jl 0x4e7418
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7418;
    }
    // 004e7404  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7406  e895a00100             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 004e740b  8b532e                 -mov edx, dword ptr [ebx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 004e740e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7410  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e7413  e828a10100             -call 0x501540
    cpu.esp -= 4;
    sub_501540(app, cpu);
    if (cpu.terminate) return;
L_0x004e7418:
    // 004e7418  41                     -inc ecx
    (cpu.ecx)++;
    // 004e7419  83c360                 -add ebx, 0x60
    (cpu.ebx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e741c  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e741f  7cd8                   -jl 0x4e73f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e73f9;
    }
    // 004e7421  e8569a0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7426  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7428  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7429  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e742a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e742b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e742c:
    // 004e742c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e7431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7432  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7433:
    // 004e7433  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7434  b928ab5400             -mov ecx, 0x54ab28
    cpu.ecx = 5548840 /*0x54ab28*/;
    // 004e7439  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e743a  bb38ab5400             -mov ebx, 0x54ab38
    cpu.ebx = 5548856 /*0x54ab38*/;
    // 004e743f  be51000000             -mov esi, 0x51
    cpu.esi = 81 /*0x51*/;
    // 004e7444  6848ab5400             -push 0x54ab48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548872 /*0x54ab48*/;
    cpu.esp -= 4;
    // 004e7449  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e744f  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7455  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e745b  e8b09bf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7460  83c408                 +add esp, 8
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
    // 004e7463  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7464  eb81                   -jmp 0x4e73e7
    goto L_0x004e73e7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e7470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7472  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7479  7425                   -je 0x4e74a0
    if (cpu.flags.zf)
    {
        goto L_0x004e74a0;
    }
    // 004e747b  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e747e  7f28                   -jg 0x4e74a8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e74a8;
    }
    // 004e7480  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e7482  7c24                   -jl 0x4e74a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e74a8;
    }
    // 004e7484  881502475600           -mov byte ptr [0x564702], dl
    app->getMemory<x86::reg8>(x86::reg32(5654274) /* 0x564702 */) = cpu.dl;
    // 004e748a  8b0d90465600           -mov ecx, dword ptr [0x564690]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e7490  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e7492  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7494  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7496  e8851f0000             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 004e749b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e749d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e749e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e749f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e74a0:
    // 004e74a0  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e74a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e74a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e74a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e74a8:
    // 004e74a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e74a9  b974ab5400             -mov ecx, 0x54ab74
    cpu.ecx = 5548916 /*0x54ab74*/;
    // 004e74ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e74af  bb84ab5400             -mov ebx, 0x54ab84
    cpu.ebx = 5548932 /*0x54ab84*/;
    // 004e74b4  be7c000000             -mov esi, 0x7c
    cpu.esi = 124 /*0x7c*/;
    // 004e74b9  6898ab5400             -push 0x54ab98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5548952 /*0x54ab98*/;
    cpu.esp -= 4;
    // 004e74be  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e74c4  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e74ca  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e74d0  e83b9bf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e74d5  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e74da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e74dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e74de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e74df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e74e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e74f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e74f0  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e74f7  7506                   -jne 0x4e74ff
    if (!cpu.flags.zf)
    {
        goto L_0x004e74ff;
    }
    // 004e74f9  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e74fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e74ff:
    // 004e74ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7500  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e7505  e866a10100             -call 0x501670
    cpu.esp -= 4;
    sub_501670(app, cpu);
    if (cpu.terminate) return;
    // 004e750a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e750c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e750e  7c04                   -jl 0x4e7514
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7514;
    }
    // 004e7510  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7512  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7513  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7514:
    // 004e7514  0fbe1502475600         -movsx edx, byte ptr [0x564702]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654274) /* 0x564702 */)));
    // 004e751b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e751d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e751e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4e7520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7522  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7523  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7524  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7527  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e7529  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e752b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e752e  8b1d70465600           -mov ebx, dword ptr [0x564670]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5654128) /* 0x564670 */);
    // 004e7534  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e7539  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004e753c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e753e  891570465600           -mov dword ptr [0x564670], edx
    app->getMemory<x86::reg32>(x86::reg32(5654128) /* 0x564670 */) = cpu.edx;
    // 004e7544  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e7546:
    // 004e7546  8baae8f79e00           -mov ebp, dword ptr [edx + 0x9ef7e8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418152) /* 0x9ef7e8 */);
    // 004e754c  39ee                   +cmp esi, ebp
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
    // 004e754e  7545                   -jne 0x4e7595
    if (!cpu.flags.zf)
    {
        goto L_0x004e7595;
    }
L_0x004e7550:
    // 004e7550  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004e7552:
    // 004e7552  40                     -inc eax
    (cpu.eax)++;
    // 004e7553  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e7556  83f810                 +cmp eax, 0x10
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
    // 004e7559  7ceb                   -jl 0x4e7546
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7546;
    }
    // 004e755b  83f9ff                 +cmp ecx, -1
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
    // 004e755e  7445                   -je 0x4e75a5
    if (cpu.flags.zf)
    {
        goto L_0x004e75a5;
    }
    // 004e7560  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004e7563  89b1e8f79e00           -mov dword ptr [ecx + 0x9ef7e8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418152) /* 0x9ef7e8 */) = cpu.esi;
    // 004e7569  89b9ecf79e00           -mov dword ptr [ecx + 0x9ef7ec], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418156) /* 0x9ef7ec */) = cpu.edi;
    // 004e756f  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004e7574  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e7577  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e7579  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e757b  89b1f4f79e00           -mov dword ptr [ecx + 0x9ef7f4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418164) /* 0x9ef7f4 */) = cpu.esi;
    // 004e7581  8981f0f79e00           -mov dword ptr [ecx + 0x9ef7f0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418160) /* 0x9ef7f0 */) = cpu.eax;
    // 004e7587  ff0d70465600           -dec dword ptr [0x564670]
    (app->getMemory<x86::reg32>(x86::reg32(5654128) /* 0x564670 */))--;
    // 004e758d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7590  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7591  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7592  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7593  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7594  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7595:
    // 004e7595  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004e7597  75b9                   -jne 0x4e7552
    if (!cpu.flags.zf)
    {
        goto L_0x004e7552;
    }
    // 004e7599  83f9ff                 +cmp ecx, -1
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
    // 004e759c  75b4                   -jne 0x4e7552
    if (!cpu.flags.zf)
    {
        goto L_0x004e7552;
    }
    // 004e759e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e75a0  74ae                   -je 0x4e7550
    if (cpu.flags.zf)
    {
        goto L_0x004e7550;
    }
    // 004e75a2  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e75a3  ebad                   -jmp 0x4e7552
    goto L_0x004e7552;
L_0x004e75a5:
    // 004e75a5  b8f8ab5400             -mov eax, 0x54abf8
    cpu.eax = 5549048 /*0x54abf8*/;
    // 004e75aa  ba08ac5400             -mov edx, 0x54ac08
    cpu.edx = 5549064 /*0x54ac08*/;
    // 004e75af  b960000000             -mov ecx, 0x60
    cpu.ecx = 96 /*0x60*/;
    // 004e75b4  6818ac5400             -push 0x54ac18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549080 /*0x54ac18*/;
    cpu.esp -= 4;
    // 004e75b9  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e75be  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e75c4  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004e75ca  e8419af1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e75cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e75d2  ff0d70465600           -dec dword ptr [0x564670]
    (app->getMemory<x86::reg32>(x86::reg32(5654128) /* 0x564670 */))--;
    // 004e75d8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e75db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e75dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e75dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e75de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e75df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e75e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e75e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e75e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e75e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e75e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e75e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e75e6  8b1de8f79e00           -mov ebx, dword ptr [0x9ef7e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10418152) /* 0x9ef7e8 */);
    // 004e75ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e75ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e75f0  39d9                   +cmp ecx, ebx
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
    // 004e75f2  7413                   -je 0x4e7607
    if (cpu.flags.zf)
    {
        goto L_0x004e7607;
    }
L_0x004e75f4:
    // 004e75f4  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e75f7  42                     -inc edx
    (cpu.edx)++;
    // 004e75f8  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e75fd  7d08                   -jge 0x4e7607
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e7607;
    }
    // 004e75ff  3b88e8f79e00           +cmp ecx, dword ptr [eax + 0x9ef7e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10418152) /* 0x9ef7e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7605  75ed                   -jne 0x4e75f4
    if (!cpu.flags.zf)
    {
        goto L_0x004e75f4;
    }
L_0x004e7607:
    // 004e7607  83fa10                 +cmp edx, 0x10
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
    // 004e760a  7d0b                   -jge 0x4e7617
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e7617;
    }
    // 004e760c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004e760f  3b8ae8f79e00           +cmp ecx, dword ptr [edx + 0x9ef7e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418152) /* 0x9ef7e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7615  7405                   -je 0x4e761c
    if (cpu.flags.zf)
    {
        goto L_0x004e761c;
    }
L_0x004e7617:
    // 004e7617  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7618  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e761a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e761b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e761c:
    // 004e761c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e761e  89aae8f79e00           -mov dword ptr [edx + 0x9ef7e8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418152) /* 0x9ef7e8 */) = cpu.ebp;
    // 004e7624  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7625  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7626  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7627  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7628  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e7630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7632  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7633  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7634  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7635  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7636  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e7638  8b156c465600           -mov edx, dword ptr [0x56466c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654124) /* 0x56466c */);
    // 004e763e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e7640  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e7642  0f8594000000           -jne 0x4e76dc
    if (!cpu.flags.zf)
    {
        goto L_0x004e76dc;
    }
L_0x004e7648:
    // 004e7648  a174465600             -mov eax, dword ptr [0x564674]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654132) /* 0x564674 */);
    // 004e764d  3b05a0c17900           +cmp eax, dword ptr [0x79c1a0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7653  0f8471000000           -je 0x4e76ca
    if (cpu.flags.zf)
    {
        goto L_0x004e76ca;
    }
    // 004e7659  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004e765e  a374465600             -mov dword ptr [0x564674], eax
    app->getMemory<x86::reg32>(x86::reg32(5654132) /* 0x564674 */) = cpu.eax;
    // 004e7663  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e7665:
    // 004e7665  8b99e8f79e00           -mov ebx, dword ptr [ecx + 0x9ef7e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418152) /* 0x9ef7e8 */);
    // 004e766b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e766d  7450                   -je 0x4e76bf
    if (cpu.flags.zf)
    {
        goto L_0x004e76bf;
    }
    // 004e766f  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004e7674  3b81f0f79e00           +cmp eax, dword ptr [ecx + 0x9ef7f0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418160) /* 0x9ef7f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e767a  7c43                   -jl 0x4e76bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e76bf;
    }
    // 004e767c  83b9f4f79e0000         +cmp dword ptr [ecx + 0x9ef7f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418164) /* 0x9ef7f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7683  753a                   -jne 0x4e76bf
    if (!cpu.flags.zf)
    {
        goto L_0x004e76bf;
    }
    // 004e7685  c781f4f79e0001000000   -mov dword ptr [ecx + 0x9ef7f4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418164) /* 0x9ef7f4 */) = 1 /*0x1*/;
    // 004e768f  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004e7694  8b91f0f79e00           -mov edx, dword ptr [ecx + 0x9ef7f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418160) /* 0x9ef7f0 */);
    // 004e769a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e769c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e769e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e76a0  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e76a2  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e76a4  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004e76a9  8b99ecf79e00           -mov ebx, dword ptr [ecx + 0x9ef7ec]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418156) /* 0x9ef7ec */);
    // 004e76af  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e76b1  8981f0f79e00           -mov dword ptr [ecx + 0x9ef7f0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418160) /* 0x9ef7f0 */) = cpu.eax;
    // 004e76b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e76b9  8981f4f79e00           -mov dword ptr [ecx + 0x9ef7f4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10418164) /* 0x9ef7f4 */) = cpu.eax;
L_0x004e76bf:
    // 004e76bf  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e76c2  81f900010000           +cmp ecx, 0x100
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
    // 004e76c8  759b                   -jne 0x4e7665
    if (!cpu.flags.zf)
    {
        goto L_0x004e7665;
    }
L_0x004e76ca:
    // 004e76ca  833d6c46560000         +cmp dword ptr [0x56466c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654124) /* 0x56466c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e76d1  751b                   -jne 0x4e76ee
    if (!cpu.flags.zf)
    {
        goto L_0x004e76ee;
    }
    // 004e76d3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e76d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e76db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e76dc:
    // 004e76dc  833dbc43560000         +cmp dword ptr [0x5643bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e76e3  7402                   -je 0x4e76e7
    if (cpu.flags.zf)
    {
        goto L_0x004e76e7;
    }
    // 004e76e5  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x004e76e7:
    // 004e76e7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e76e9  e95affffff             -jmp 0x4e7648
    goto L_0x004e7648;
L_0x004e76ee:
    // 004e76ee  833dbc43560000         +cmp dword ptr [0x5643bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e76f5  7402                   -je 0x4e76f9
    if (cpu.flags.zf)
    {
        goto L_0x004e76f9;
    }
    // 004e76f7  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x004e76f9:
    // 004e76f9  8b0d68465600           -mov ecx, dword ptr [0x564668]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654120) /* 0x564668 */);
    // 004e76ff  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e7701  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e7703  890d68465600           -mov dword ptr [0x564668], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654120) /* 0x564668 */) = cpu.ecx;
    // 004e7709  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e770b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e770c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e770d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e770e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e770f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7710  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7711  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4e7720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7721  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7722  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7724  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004e7729  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e772b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e772d:
    // 004e772d  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004e7732  39c8                   +cmp eax, ecx
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
    // 004e7734  7d04                   -jge 0x4e773a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e773a;
    }
    // 004e7736  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e7738  7405                   -je 0x4e773f
    if (cpu.flags.zf)
    {
        goto L_0x004e773f;
    }
L_0x004e773a:
    // 004e773a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e773c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e773d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e773e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e773f:
    // 004e773f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e7741  e8eafeffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004e7746  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7748  ebe3                   -jmp 0x4e772d
    goto L_0x004e772d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e7750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7753  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e7755  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e775c  0f849f000000           -je 0x4e7801
    if (cpu.flags.zf)
    {
        goto L_0x004e7801;
    }
    // 004e7762  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7769  0f859b000000           -jne 0x4e780a
    if (!cpu.flags.zf)
    {
        goto L_0x004e780a;
    }
    // 004e776f  e8ac960100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7774  e83ba00100             -call 0x5017b4
    cpu.esp -= 4;
    sub_5017b4(app, cpu);
    if (cpu.terminate) return;
    // 004e7779  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e777b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e777d  0f8cbd000000           -jl 0x4e7840
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7840;
    }
    // 004e7783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7784  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004e7786  a28c475600             -mov byte ptr [0x56478c], al
    app->getMemory<x86::reg8>(x86::reg32(5654412) /* 0x56478c */) = cpu.al;
    // 004e778b  c6050047560001         -mov byte ptr [0x564700], 1
    app->getMemory<x86::reg8>(x86::reg32(5654272) /* 0x564700 */) = 1 /*0x1*/;
    // 004e7792  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e7794  89358c465600           -mov dword ptr [0x56468c], esi
    app->getMemory<x86::reg32>(x86::reg32(5654156) /* 0x56468c */) = cpu.esi;
    // 004e779a  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e779d  a202475600             -mov byte ptr [0x564702], al
    app->getMemory<x86::reg8>(x86::reg32(5654274) /* 0x564702 */) = cpu.al;
    // 004e77a2  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004e77a5  a203475600             -mov byte ptr [0x564703], al
    app->getMemory<x86::reg8>(x86::reg32(5654275) /* 0x564703 */) = cpu.al;
    // 004e77aa  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 004e77ad  a204475600             -mov byte ptr [0x564704], al
    app->getMemory<x86::reg8>(x86::reg32(5654276) /* 0x564704 */) = cpu.al;
    // 004e77b2  8a420a                 -mov al, byte ptr [edx + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004e77b5  a205475600             -mov byte ptr [0x564705], al
    app->getMemory<x86::reg8>(x86::reg32(5654277) /* 0x564705 */) = cpu.al;
    // 004e77ba  891d7c465600           -mov dword ptr [0x56467c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */) = cpu.ebx;
    // 004e77c0  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004e77c2  8815fc465600           -mov byte ptr [0x5646fc], dl
    app->getMemory<x86::reg8>(x86::reg32(5654268) /* 0x5646fc */) = cpu.dl;
    // 004e77c8  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e77ca  883509475600           -mov byte ptr [0x564709], dh
    app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */) = cpu.dh;
    // 004e77d0  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e77d2  881d0a475600           -mov byte ptr [0x56470a], bl
    app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */) = cpu.bl;
    // 004e77d8  c705144756000f000000   -mov dword ptr [0x564714], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5654292) /* 0x564714 */) = 15 /*0xf*/;
    // 004e77e2  c6050b475600ff         -mov byte ptr [0x56470b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */) = 255 /*0xff*/;
    // 004e77e9  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004e77eb  a20c475600             -mov byte ptr [0x56470c], al
    app->getMemory<x86::reg8>(x86::reg32(5654284) /* 0x56470c */) = cpu.al;
    // 004e77f0  e84f110000             -call 0x4e8944
    cpu.esp -= 4;
    sub_4e8944(app, cpu);
    if (cpu.terminate) return;
    // 004e77f5  e882960100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e77fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e77fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e77fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e77fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e77ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7800  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7801:
    // 004e7801  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7806  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7807  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7808  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7809  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e780a:
    // 004e780a  bd34ac5400             -mov ebp, 0x54ac34
    cpu.ebp = 5549108 /*0x54ac34*/;
    // 004e780f  b844ac5400             -mov eax, 0x54ac44
    cpu.eax = 5549124 /*0x54ac44*/;
    // 004e7814  bab1000000             -mov edx, 0xb1
    cpu.edx = 177 /*0xb1*/;
    // 004e7819  6854ac5400             -push 0x54ac54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549140 /*0x54ac54*/;
    cpu.esp -= 4;
    // 004e781e  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e7824  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e7829  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e782f  e8dc97f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7834  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004e7839  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e783c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e783d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e783e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e783f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7840:
    // 004e7840  e837960100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7845  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7847  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7848  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7849  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e784a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e784c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e784c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e784d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e784f  e80c7e0100             -call 0x4ff660
    cpu.esp -= 4;
    sub_4ff660(app, cpu);
    if (cpu.terminate) return;
    // 004e7854  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e785b  7409                   -je 0x4e7866
    if (cpu.flags.zf)
    {
        goto L_0x004e7866;
    }
    // 004e785d  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7864  7507                   -jne 0x4e786d
    if (!cpu.flags.zf)
    {
        goto L_0x004e786d;
    }
L_0x004e7866:
    // 004e7866  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e786b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e786c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e786d:
    // 004e786d  e8b6020000             -call 0x4e7b28
    cpu.esp -= 4;
    sub_4e7b28(app, cpu);
    if (cpu.terminate) return;
    // 004e7872  803d0847560000         +cmp byte ptr [0x564708], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7879  7412                   -je 0x4e788d
    if (cpu.flags.zf)
    {
        goto L_0x004e788d;
    }
    // 004e787b  b8a8854e00             -mov eax, 0x4e85a8
    cpu.eax = 5146024 /*0x4e85a8*/;
    // 004e7880  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e7882  e859fdffff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004e7887  883508475600           -mov byte ptr [0x564708], dh
    app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */) = cpu.dh;
L_0x004e788d:
    // 004e788d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e788e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e7890  890d309ba000           -mov dword ptr [0xa09b30], ecx
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.ecx;
    // 004e7896  e8199f0100             -call 0x5017b4
    cpu.esp -= 4;
    sub_5017b4(app, cpu);
    if (cpu.terminate) return;
    // 004e789b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e789d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e789e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e789f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e78a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e78a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e78a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e78a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e78a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e78a5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e78a7  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e78ae  746b                   -je 0x4e791b
    if (cpu.flags.zf)
    {
        goto L_0x004e791b;
    }
    // 004e78b0  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e78b7  746b                   -je 0x4e7924
    if (cpu.flags.zf)
    {
        goto L_0x004e7924;
    }
    // 004e78b9  803dfd46560000         +cmp byte ptr [0x5646fd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e78c0  0f85b2000000           -jne 0x4e7978
    if (!cpu.flags.zf)
    {
        goto L_0x004e7978;
    }
    // 004e78c6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e78c8  0f858d000000           -jne 0x4e795b
    if (!cpu.flags.zf)
    {
        goto L_0x004e795b;
    }
    // 004e78ce  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e78d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e78d5  e846d6ffff             -call 0x4e4f20
    cpu.esp -= 4;
    sub_4e4f20(app, cpu);
    if (cpu.terminate) return;
L_0x004e78da:
    // 004e78da  e841950100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e78df  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 004e78e1  e85e100000             -call 0x4e8944
    cpu.esp -= 4;
    sub_4e8944(app, cpu);
    if (cpu.terminate) return;
    // 004e78e6  8835fd465600           -mov byte ptr [0x5646fd], dh
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = cpu.dh;
    // 004e78ec  e88b950100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
L_0x004e78f1:
    // 004e78f1  a009475600             -mov al, byte ptr [0x564709]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */);
    // 004e78f6  fe0509475600           -inc byte ptr [0x564709]
    (app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */))++;
    // 004e78fc  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004e7901  b88c475600             -mov eax, 0x56478c
    cpu.eax = 5654412 /*0x56478c*/;
    // 004e7906  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e7908  e82395ffff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004e790d  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e790f  883d0b485600           -mov byte ptr [0x56480b], bh
    app->getMemory<x86::reg8>(x86::reg32(5654539) /* 0x56480b */) = cpu.bh;
    // 004e7915  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7917  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7918  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7919  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e791a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e791b:
    // 004e791b  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7920  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7921  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7922  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7924:
    // 004e7924  b934ac5400             -mov ecx, 0x54ac34
    cpu.ecx = 5549108 /*0x54ac34*/;
    // 004e7929  bba4ac5400             -mov ebx, 0x54aca4
    cpu.ebx = 5549220 /*0x54aca4*/;
    // 004e792e  bec5010000             -mov esi, 0x1c5
    cpu.esi = 453 /*0x1c5*/;
    // 004e7933  68b4ac5400             -push 0x54acb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549236 /*0x54acb4*/;
    cpu.esp -= 4;
    // 004e7938  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e793e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7944  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e794a  e8c196f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e794f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7954  83c404                 +add esp, 4
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
    // 004e7957  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7958  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e795a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e795b:
    // 004e795b  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7960  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e7962  e879d6ffff             -call 0x4e4fe0
    cpu.esp -= 4;
    sub_4e4fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e7967  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e796c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e796e  e8edd6ffff             -call 0x4e5060
    cpu.esp -= 4;
    sub_4e5060(app, cpu);
    if (cpu.terminate) return;
    // 004e7973  e962ffffff             -jmp 0x4e78da
    goto L_0x004e78da;
L_0x004e7978:
    // 004e7978  e8a3940100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e797d  0fbe1509475600         -movsx edx, byte ptr [0x564709]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */)));
    // 004e7984  0fbe050a475600         -movsx eax, byte ptr [0x56470a]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */)));
    // 004e798b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e798d  83f813                 +cmp eax, 0x13
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
    // 004e7990  7d20                   -jge 0x4e79b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e79b2;
    }
    // 004e7992  e8e5940100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7997  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e7999  7536                   -jne 0x4e79d1
    if (!cpu.flags.zf)
    {
        goto L_0x004e79d1;
    }
    // 004e799b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e79a0  e8cbf0ffff             -call 0x4e6a70
    cpu.esp -= 4;
    sub_4e6a70(app, cpu);
    if (cpu.terminate) return;
    // 004e79a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e79a7  7517                   -jne 0x4e79c0
    if (!cpu.flags.zf)
    {
        goto L_0x004e79c0;
    }
    // 004e79a9  b8f3ffffff             -mov eax, 0xfffffff3
    cpu.eax = 4294967283 /*0xfffffff3*/;
    // 004e79ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e79b2:
    // 004e79b2  e8c5940100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
L_0x004e79b7:
    // 004e79b7  b8f3ffffff             -mov eax, 0xfffffff3
    cpu.eax = 4294967283 /*0xfffffff3*/;
    // 004e79bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e79bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e79c0:
    // 004e79c0  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e79c5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e79c7  e814d5ffff             -call 0x4e4ee0
    cpu.esp -= 4;
    sub_4e4ee0(app, cpu);
    if (cpu.terminate) return;
    // 004e79cc  e920ffffff             -jmp 0x4e78f1
    goto L_0x004e78f1;
L_0x004e79d1:
    // 004e79d1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004e79d6  e895f0ffff             -call 0x4e6a70
    cpu.esp -= 4;
    sub_4e6a70(app, cpu);
    if (cpu.terminate) return;
    // 004e79db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e79dd  74d8                   -je 0x4e79b7
    if (cpu.flags.zf)
    {
        goto L_0x004e79b7;
    }
    // 004e79df  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004e79e4  b88c475600             -mov eax, 0x56478c
    cpu.eax = 5654412 /*0x56478c*/;
    // 004e79e9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e79eb  e8a0390000             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 004e79f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e79f2  740c                   -je 0x4e7a00
    if (cpu.flags.zf)
    {
        goto L_0x004e7a00;
    }
    // 004e79f4  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e79f9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e79fb  e8a0d5ffff             -call 0x4e4fa0
    cpu.esp -= 4;
    sub_4e4fa0(app, cpu);
    if (cpu.terminate) return;
L_0x004e7a00:
    // 004e7a00  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7a05  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e7a07  e854d6ffff             -call 0x4e5060
    cpu.esp -= 4;
    sub_4e5060(app, cpu);
    if (cpu.terminate) return;
    // 004e7a0c  e9e0feffff             -jmp 0x4e78f1
    goto L_0x004e78f1;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e7a14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7a14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7a15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7a16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7a17  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e7a19  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e7a1b  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7a22  7424                   -je 0x4e7a48
    if (cpu.flags.zf)
    {
        goto L_0x004e7a48;
    }
    // 004e7a24  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7a2b  7424                   -je 0x4e7a51
    if (cpu.flags.zf)
    {
        goto L_0x004e7a51;
    }
    // 004e7a2d  803dfd46560004         +cmp byte ptr [0x5646fd], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7a34  7452                   -je 0x4e7a88
    if (cpu.flags.zf)
    {
        goto L_0x004e7a88;
    }
    // 004e7a36  803dfd46560002         +cmp byte ptr [0x5646fd], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7a3d  7452                   -je 0x4e7a91
    if (cpu.flags.zf)
    {
        goto L_0x004e7a91;
    }
    // 004e7a3f  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004e7a44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7a48:
    // 004e7a48  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7a51:
    // 004e7a51  b934ac5400             -mov ecx, 0x54ac34
    cpu.ecx = 5549108 /*0x54ac34*/;
    // 004e7a56  bbe0ac5400             -mov ebx, 0x54ace0
    cpu.ebx = 5549280 /*0x54ace0*/;
    // 004e7a5b  be1b020000             -mov esi, 0x21b
    cpu.esi = 539 /*0x21b*/;
    // 004e7a60  68f4ac5400             -push 0x54acf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549300 /*0x54acf4*/;
    cpu.esp -= 4;
    // 004e7a65  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e7a6b  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7a71  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e7a77  e89495f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7a7c  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7a81  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7a84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7a88:
    // 004e7a88  b8eeffffff             -mov eax, 0xffffffee
    cpu.eax = 4294967278 /*0xffffffee*/;
    // 004e7a8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7a90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7a91:
    // 004e7a91  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7a96  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e7a98  e8c3d4ffff             -call 0x4e4f60
    cpu.esp -= 4;
    sub_4e4f60(app, cpu);
    if (cpu.terminate) return;
    // 004e7a9d  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7aa2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e7aa4  e8b7d5ffff             -call 0x4e5060
    cpu.esp -= 4;
    sub_4e5060(app, cpu);
    if (cpu.terminate) return;
    // 004e7aa9  e872930100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7aae  8b0d80465600           -mov ecx, dword ptr [0x564680]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e7ab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e7ab6:
    // 004e7ab6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e7ab8  8a15ff465600           -mov dl, byte ptr [0x5646ff]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */);
    // 004e7abe  8d1452                 -lea edx, [edx + edx*2]
    cpu.edx = x86::reg32(cpu.edx + cpu.edx * 2);
    // 004e7ac1  39d0                   +cmp eax, edx
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
    // 004e7ac3  7d0d                   -jge 0x4e7ad2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e7ad2;
    }
    // 004e7ac5  3b0d84465600           +cmp ecx, dword ptr [0x564684]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7acb  7405                   -je 0x4e7ad2
    if (cpu.flags.zf)
    {
        goto L_0x004e7ad2;
    }
    // 004e7acd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e7ace  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e7ad0  ebe4                   -jmp 0x4e7ab6
    goto L_0x004e7ab6;
L_0x004e7ad2:
    // 004e7ad2  890d84465600           -mov dword ptr [0x564684], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.ecx;
    // 004e7ad8  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e7ada  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e7adc  741e                   -je 0x4e7afc
    if (cpu.flags.zf)
    {
        goto L_0x004e7afc;
    }
L_0x004e7ade:
    // 004e7ade  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e7ae0  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e7ae2  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7ae7  e8b4edffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e7aec  a198465600             -mov eax, dword ptr [0x564698]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */);
    // 004e7af1  ff0d98465600           -dec dword ptr [0x564698]
    (app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */))--;
    // 004e7af7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e7af9  75e3                   -jne 0x4e7ade
    if (!cpu.flags.zf)
    {
        goto L_0x004e7ade;
    }
    // 004e7afb  90                     -nop 
    ;
L_0x004e7afc:
    // 004e7afc  b304                   -mov bl, 4
    cpu.bl = 4 /*0x4*/;
    // 004e7afe  e879930100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7b03  881dfd465600           -mov byte ptr [0x5646fd], bl
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = cpu.bl;
    // 004e7b09  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004e7b0e  b88c475600             -mov eax, 0x56478c
    cpu.eax = 5654412 /*0x56478c*/;
    // 004e7b13  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e7b15  e81693ffff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004e7b1a  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e7b1c  883d0b485600           -mov byte ptr [0x56480b], bh
    app->getMemory<x86::reg8>(x86::reg32(5654539) /* 0x56480b */) = cpu.bh;
    // 004e7b22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7b24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e7b28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7b28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7b29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7b2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7b2b  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7b32  744c                   -je 0x4e7b80
    if (cpu.flags.zf)
    {
        goto L_0x004e7b80;
    }
    // 004e7b34  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7b3b  744c                   -je 0x4e7b89
    if (cpu.flags.zf)
    {
        goto L_0x004e7b89;
    }
    // 004e7b3d  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e7b42  e8291b0000             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 004e7b47  8b15fc9aa000           -mov edx, dword ptr [0xa09afc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004e7b4d  bd34ac5400             -mov ebp, 0x54ac34
    cpu.ebp = 5549108 /*0x54ac34*/;
    // 004e7b52  b9c6020000             -mov ecx, 0x2c6
    cpu.ecx = 710 /*0x2c6*/;
    // 004e7b57  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x004e7b5d:
    // 004e7b5d  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e7b62  e869140000             -call 0x4e8fd0
    cpu.esp -= 4;
    sub_4e8fd0(app, cpu);
    if (cpu.terminate) return;
    // 004e7b67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7b69  0f8584000000           -jne 0x4e7bf3
    if (!cpu.flags.zf)
    {
        goto L_0x004e7bf3;
    }
    // 004e7b6f  3b15fc9aa000           +cmp edx, dword ptr [0xa09afc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7b75  724d                   -jb 0x4e7bc4
    if (cpu.flags.cf)
    {
        goto L_0x004e7bc4;
    }
    // 004e7b77  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e7b79  e8b2faffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004e7b7e  ebdd                   -jmp 0x4e7b5d
    goto L_0x004e7b5d;
L_0x004e7b80:
    // 004e7b80  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7b85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7b88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7b89:
    // 004e7b89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7b8a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7b8b  b934ac5400             -mov ecx, 0x54ac34
    cpu.ecx = 5549108 /*0x54ac34*/;
    // 004e7b90  bb24ad5400             -mov ebx, 0x54ad24
    cpu.ebx = 5549348 /*0x54ad24*/;
    // 004e7b95  beb3020000             -mov esi, 0x2b3
    cpu.esi = 691 /*0x2b3*/;
    // 004e7b9a  6834ad5400             -push 0x54ad34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549364 /*0x54ad34*/;
    cpu.esp -= 4;
    // 004e7b9f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e7ba5  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7bab  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e7bb1  e85a94f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7bb6  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7bbb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7bbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7bc0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7bc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7bc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7bc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7bc4:
    // 004e7bc4  b824ad5400             -mov eax, 0x54ad24
    cpu.eax = 5549348 /*0x54ad24*/;
    // 004e7bc9  6860ad5400             -push 0x54ad60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549408 /*0x54ad60*/;
    cpu.esp -= 4;
    // 004e7bce  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e7bd4  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004e7bda  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e7bdf  e82c94f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7be4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7be7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e7be9  e842faffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004e7bee  e96affffff             -jmp 0x4e7b5d
    goto L_0x004e7b5d;
L_0x004e7bf3:
    // 004e7bf3  e828920100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7bf8  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 004e7bfa  e8f9030000             -call 0x4e7ff8
    cpu.esp -= 4;
    sub_4e7ff8(app, cpu);
    if (cpu.terminate) return;
    // 004e7bff  88150b475600           -mov byte ptr [0x56470b], dl
    app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */) = cpu.dl;
    // 004e7c05  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e7c07  88350c475600           -mov byte ptr [0x56470c], dh
    app->getMemory<x86::reg8>(x86::reg32(5654284) /* 0x56470c */) = cpu.dh;
    // 004e7c0d  883509475600           -mov byte ptr [0x564709], dh
    app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */) = cpu.dh;
    // 004e7c13  88350a475600           -mov byte ptr [0x56470a], dh
    app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */) = cpu.dh;
    // 004e7c19  8835fd465600           -mov byte ptr [0x5646fd], dh
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = cpu.dh;
    // 004e7c1f  88358c475600           -mov byte ptr [0x56478c], dh
    app->getMemory<x86::reg8>(x86::reg32(5654412) /* 0x56478c */) = cpu.dh;
    // 004e7c25  8835fc465600           -mov byte ptr [0x5646fc], dh
    app->getMemory<x86::reg8>(x86::reg32(5654268) /* 0x5646fc */) = cpu.dh;
    // 004e7c2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7c2d  e82e7a0100             -call 0x4ff660
    cpu.esp -= 4;
    sub_4ff660(app, cpu);
    if (cpu.terminate) return;
    // 004e7c32  803d0847560000         +cmp byte ptr [0x564708], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7c39  7410                   -je 0x4e7c4b
    if (cpu.flags.zf)
    {
        goto L_0x004e7c4b;
    }
    // 004e7c3b  b8a8854e00             -mov eax, 0x4e85a8
    cpu.eax = 5146024 /*0x4e85a8*/;
    // 004e7c40  e89bf9ffff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004e7c45  883508475600           -mov byte ptr [0x564708], dh
    app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */) = cpu.dh;
L_0x004e7c4b:
    // 004e7c4b  e82c920100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7c50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7c52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7c53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7c55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e7c58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7c58  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7c59  8a25f49aa000           -mov ah, byte ptr [0xa09af4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
    // 004e7c5f  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 004e7c64  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004e7c66  743a                   -je 0x4e7ca2
    if (cpu.flags.zf)
    {
        goto L_0x004e7ca2;
    }
    // 004e7c68  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7c6f  7435                   -je 0x4e7ca6
    if (cpu.flags.zf)
    {
        goto L_0x004e7ca6;
    }
    // 004e7c71  e8aa910100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7c76  803dfd46560000         +cmp byte ptr [0x5646fd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7c7d  741e                   -je 0x4e7c9d
    if (cpu.flags.zf)
    {
        goto L_0x004e7c9d;
    }
    // 004e7c7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7c81  a0ff465600             -mov al, byte ptr [0x5646ff]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */);
    // 004e7c86  e8299b0100             -call 0x5017b4
    cpu.esp -= 4;
    sub_5017b4(app, cpu);
    if (cpu.terminate) return;
    // 004e7c8b  8b1598465600           -mov edx, dword ptr [0x564698]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */);
    // 004e7c91  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e7c93  803d0d47560002         +cmp byte ptr [0x56470d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7c9a  7501                   -jne 0x4e7c9d
    if (!cpu.flags.zf)
    {
        goto L_0x004e7c9d;
    }
    // 004e7c9c  4a                     -dec edx
    (cpu.edx)--;
L_0x004e7c9d:
    // 004e7c9d  e8da910100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
L_0x004e7ca2:
    // 004e7ca2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7ca4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7ca5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7ca6:
    // 004e7ca6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7ca7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7ca8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7ca9  bb34ac5400             -mov ebx, 0x54ac34
    cpu.ebx = 5549108 /*0x54ac34*/;
    // 004e7cae  bea4ad5400             -mov esi, 0x54ada4
    cpu.esi = 5549476 /*0x54ada4*/;
    // 004e7cb3  bf4b030000             -mov edi, 0x34b
    cpu.edi = 843 /*0x34b*/;
    // 004e7cb8  68b8ad5400             -push 0x54adb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549496 /*0x54adb8*/;
    cpu.esp -= 4;
    // 004e7cbd  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e7cc3  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e7cc9  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e7ccf  e83c93f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7cd4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7cd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7cd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7cda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7cdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7cdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7cdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e7ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7ce0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7ce1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7ce2  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7ce9  7428                   -je 0x4e7d13
    if (cpu.flags.zf)
    {
        goto L_0x004e7d13;
    }
    // 004e7ceb  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7cf2  7427                   -je 0x4e7d1b
    if (cpu.flags.zf)
    {
        goto L_0x004e7d1b;
    }
    // 004e7cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7cf5  e826910100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7cfa  803dfd46560000         +cmp byte ptr [0x5646fd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7d01  754d                   -jne 0x4e7d50
    if (!cpu.flags.zf)
    {
        goto L_0x004e7d50;
    }
L_0x004e7d03:
    // 004e7d03  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 004e7d08  e86f910100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7d0d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7d0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7d13:
    // 004e7d13  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7d18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7d1b:
    // 004e7d1b  bf34ac5400             -mov edi, 0x54ac34
    cpu.edi = 5549108 /*0x54ac34*/;
    // 004e7d20  bdecad5400             -mov ebp, 0x54adec
    cpu.ebp = 5549548 /*0x54adec*/;
    // 004e7d25  b8c2030000             -mov eax, 0x3c2
    cpu.eax = 962 /*0x3c2*/;
    // 004e7d2a  6800ae5400             -push 0x54ae00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549568 /*0x54ae00*/;
    cpu.esp -= 4;
    // 004e7d2f  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e7d35  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e7d3b  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e7d40  e8cb92f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7d45  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e7d4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7d4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7d50:
    // 004e7d50  803dfd46560001         +cmp byte ptr [0x5646fd], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7d57  74aa                   -je 0x4e7d03
    if (cpu.flags.zf)
    {
        goto L_0x004e7d03;
    }
    // 004e7d59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7d5a  803dff46560000         +cmp byte ptr [0x5646ff], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7d61  7532                   -jne 0x4e7d95
    if (!cpu.flags.zf)
    {
        goto L_0x004e7d95;
    }
    // 004e7d63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7d64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7d65  b934ac5400             -mov ecx, 0x54ac34
    cpu.ecx = 5549108 /*0x54ac34*/;
    // 004e7d6a  bbecad5400             -mov ebx, 0x54adec
    cpu.ebx = 5549548 /*0x54adec*/;
    // 004e7d6f  bed3030000             -mov esi, 0x3d3
    cpu.esi = 979 /*0x3d3*/;
    // 004e7d74  6830ae5400             -push 0x54ae30
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549616 /*0x54ae30*/;
    cpu.esp -= 4;
    // 004e7d79  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e7d7f  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e7d85  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e7d8b  e88092f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7d90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7d93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7d94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e7d95:
    // 004e7d95  e8befeffff             -call 0x4e7c58
    cpu.esp -= 4;
    sub_4e7c58(app, cpu);
    if (cpu.terminate) return;
    // 004e7d9a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7d9c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e7d9f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e7da1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e7da4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e7da6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e7da9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7dab  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e7dae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e7db0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e7db2  8a0dff465600           -mov cl, byte ptr [0x5646ff]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */);
    // 004e7db8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7dba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e7dbd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e7dbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7dc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7dc2  e8b5900100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7dc7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7dc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7dca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7dcb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e7dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7dd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7dd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e7dd3  89156c475600           -mov dword ptr [0x56476c], edx
    app->getMemory<x86::reg32>(x86::reg32(5654380) /* 0x56476c */) = cpu.edx;
    // 004e7dd9  e8a2790100             -call 0x4ff780
    cpu.esp -= 4;
    sub_4ff780(app, cpu);
    if (cpu.terminate) return;
    // 004e7dde  833d0c48560000         +cmp dword ptr [0x56480c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7de5  7502                   -jne 0x4e7de9
    if (!cpu.flags.zf)
    {
        goto L_0x004e7de9;
    }
    // 004e7de7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7de8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7de9:
    // 004e7de9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7deb  ff150c485600           -call dword ptr [0x56480c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e7df1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7df2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e7df4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7df4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e7df5  833d6c47560000         +cmp dword ptr [0x56476c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654380) /* 0x56476c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7dfc  7502                   -jne 0x4e7e00
    if (!cpu.flags.zf)
    {
        goto L_0x004e7e00;
    }
L_0x004e7dfe:
    // 004e7dfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7dff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7e00:
    // 004e7e00  e8dbfeffff             -call 0x4e7ce0
    cpu.esp -= 4;
    sub_4e7ce0(app, cpu);
    if (cpu.terminate) return;
    // 004e7e05  3b056c475600           +cmp eax, dword ptr [0x56476c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654380) /* 0x56476c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7e0b  7c4f                   -jl 0x4e7e5c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e7e5c;
    }
L_0x004e7e0d:
    // 004e7e0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004e7e12:
    // 004e7e12  e8b9ffffff             -call 0x4e7dd0
    cpu.esp -= 4;
    sub_4e7dd0(app, cpu);
    if (cpu.terminate) return;
L_0x004e7e17:
    // 004e7e17  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004e7e1c  3b0570475600           +cmp eax, dword ptr [0x564770]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654384) /* 0x564770 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7e22  7eda                   -jle 0x4e7dfe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e7dfe;
    }
    // 004e7e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7e25  bf34ac5400             -mov edi, 0x54ac34
    cpu.edi = 5549108 /*0x54ac34*/;
    // 004e7e2a  bd8cae5400             -mov ebp, 0x54ae8c
    cpu.ebp = 5549708 /*0x54ae8c*/;
    // 004e7e2f  b812040000             -mov eax, 0x412
    cpu.eax = 1042 /*0x412*/;
    // 004e7e34  68a4ae5400             -push 0x54aea4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549732 /*0x54aea4*/;
    cpu.esp -= 4;
    // 004e7e39  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e7e3f  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e7e45  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e7e4a  e8c191f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7e4f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7e52  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7e54  e877ffffff             -call 0x4e7dd0
    cpu.esp -= 4;
    sub_4e7dd0(app, cpu);
    if (cpu.terminate) return;
    // 004e7e59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7e5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7e5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7e5c:
    // 004e7e5c  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7e61  e8eaeaffff             -call 0x4e6950
    cpu.esp -= 4;
    sub_4e6950(app, cpu);
    if (cpu.terminate) return;
    // 004e7e66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7e68  7415                   -je 0x4e7e7f
    if (cpu.flags.zf)
    {
        goto L_0x004e7e7f;
    }
    // 004e7e6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e7e6c  a0ff465600             -mov al, byte ptr [0x5646ff]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */);
    // 004e7e71  e83e990100             -call 0x5017b4
    cpu.esp -= 4;
    sub_5017b4(app, cpu);
    if (cpu.terminate) return;
    // 004e7e76  83f801                 +cmp eax, 1
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
    // 004e7e79  7f83                   -jg 0x4e7dfe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e7dfe;
    }
    // 004e7e7b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e7e7d  eb93                   -jmp 0x4e7e12
    goto L_0x004e7e12;
L_0x004e7e7f:
    // 004e7e7f  e85ceaffff             -call 0x4e68e0
    cpu.esp -= 4;
    sub_4e68e0(app, cpu);
    if (cpu.terminate) return;
    // 004e7e84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7e86  748f                   -je 0x4e7e17
    if (cpu.flags.zf)
    {
        goto L_0x004e7e17;
    }
    // 004e7e88  833d0c48560000         +cmp dword ptr [0x56480c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7e8f  7586                   -jne 0x4e7e17
    if (!cpu.flags.zf)
    {
        goto L_0x004e7e17;
    }
    // 004e7e91  e977ffffff             -jmp 0x4e7e0d
    goto L_0x004e7e0d;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e7e98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7e98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7e99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7e9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7e9b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7e9d  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e7ea4  7444                   -je 0x4e7eea
    if (cpu.flags.zf)
    {
        goto L_0x004e7eea;
    }
    // 004e7ea6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e7ea8  7e44                   -jle 0x4e7eee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e7eee;
    }
    // 004e7eaa  833d0c48560000         +cmp dword ptr [0x56480c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7eb1  740a                   -je 0x4e7ebd
    if (cpu.flags.zf)
    {
        goto L_0x004e7ebd;
    }
    // 004e7eb3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7eb5  ff150c485600           -call dword ptr [0x56480c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5654540) /* 0x56480c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e7ebb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004e7ebd:
    // 004e7ebd  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004e7ec2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e7ec4  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004e7ec9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e7ecc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7ece  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004e7ed1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e7ed3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e7ed5  891d70475600           -mov dword ptr [0x564770], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654384) /* 0x564770 */) = cpu.ebx;
    // 004e7edb  89156c475600           -mov dword ptr [0x56476c], edx
    app->getMemory<x86::reg32>(x86::reg32(5654380) /* 0x56476c */) = cpu.edx;
    // 004e7ee1  e88a110100             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004e7ee6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e7ee8  743a                   -je 0x4e7f24
    if (cpu.flags.zf)
    {
        goto L_0x004e7f24;
    }
L_0x004e7eea:
    // 004e7eea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7eeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7eec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7eed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7eee:
    // 004e7eee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e7eef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7ef0  bb34ac5400             -mov ebx, 0x54ac34
    cpu.ebx = 5549108 /*0x54ac34*/;
    // 004e7ef5  bedcae5400             -mov esi, 0x54aedc
    cpu.esi = 5549788 /*0x54aedc*/;
    // 004e7efa  bf26040000             -mov edi, 0x426
    cpu.edi = 1062 /*0x426*/;
    // 004e7eff  68f4ae5400             -push 0x54aef4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549812 /*0x54aef4*/;
    cpu.esp -= 4;
    // 004e7f04  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e7f0a  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e7f10  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e7f16  e8f590f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e7f1b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e7f1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7f24:
    // 004e7f24  e8cbfeffff             -call 0x4e7df4
    cpu.esp -= 4;
    sub_4e7df4(app, cpu);
    if (cpu.terminate) return;
    // 004e7f29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e7f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e7f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7f32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e7f34  8a25f49aa000           -mov ah, byte ptr [0xa09af4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
    // 004e7f3a  b9f1ffffff             -mov ecx, 0xfffffff1
    cpu.ecx = 4294967281 /*0xfffffff1*/;
    // 004e7f3f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004e7f41  750a                   -jne 0x4e7f4d
    if (!cpu.flags.zf)
    {
        goto L_0x004e7f4d;
    }
    // 004e7f43  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 004e7f48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7f4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7f4d:
    // 004e7f4d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e7f4e  e8cd8e0100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7f53  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004e7f55  81fb5343446c           +cmp ebx, 0x6c444353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816413011 /*0x6c444353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7f5b  7514                   -jne 0x4e7f71
    if (!cpu.flags.zf)
    {
        goto L_0x004e7f71;
    }
    // 004e7f5d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7f5f  e814010000             -call 0x4e8078
    cpu.esp -= 4;
    sub_4e8078(app, cpu);
    if (cpu.terminate) return;
    // 004e7f64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7f66  e8118f0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7f6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f6c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7f6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7f70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7f71:
    // 004e7f71  81fb5343486c           +cmp ebx, 0x6c484353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816675155 /*0x6c484353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7f77  742c                   -je 0x4e7fa5
    if (cpu.flags.zf)
    {
        goto L_0x004e7fa5;
    }
    // 004e7f79  81fb5343436c           +cmp ebx, 0x6c434353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816347475 /*0x6c434353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7f7f  7438                   -je 0x4e7fb9
    if (cpu.flags.zf)
    {
        goto L_0x004e7fb9;
    }
    // 004e7f81  81fb53434c6c           +cmp ebx, 0x6c4c4353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816937299 /*0x6c4c4353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7f87  7444                   -je 0x4e7fcd
    if (cpu.flags.zf)
    {
        goto L_0x004e7fcd;
    }
    // 004e7f89  81fb5343456c           +cmp ebx, 0x6c454353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816478547 /*0x6c454353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e7f8f  7550                   -jne 0x4e7fe1
    if (!cpu.flags.zf)
    {
        goto L_0x004e7fe1;
    }
    // 004e7f91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7f93  e854030000             -call 0x4e82ec
    cpu.esp -= 4;
    sub_4e82ec(app, cpu);
    if (cpu.terminate) return;
    // 004e7f98  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7f9a  e8dd8e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7f9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fa0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7fa2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fa4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7fa5:
    // 004e7fa5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7fa7  e820010000             -call 0x4e80cc
    cpu.esp -= 4;
    sub_4e80cc(app, cpu);
    if (cpu.terminate) return;
    // 004e7fac  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7fae  e8c98e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7fb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7fb6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7fb9:
    // 004e7fb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7fbb  e898020000             -call 0x4e8258
    cpu.esp -= 4;
    sub_4e8258(app, cpu);
    if (cpu.terminate) return;
    // 004e7fc0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7fc2  e8b58e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7fc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fc8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7fca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fcc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7fcd:
    // 004e7fcd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e7fcf  e8f0020000             -call 0x4e82c4
    cpu.esp -= 4;
    sub_4e82c4(app, cpu);
    if (cpu.terminate) return;
    // 004e7fd4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e7fd6  e8a18e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7fdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fdc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7fde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7fe0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e7fe1:
    // 004e7fe1  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e7fe6  e8b5e8ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e7feb  e88c8e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e7ff0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7ff1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e7ff3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7ff4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e7ff5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e7ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e7ff8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e7ff9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e7ffa  e8218e0100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e7fff  833d8046560000         +cmp dword ptr [0x564680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8006  7454                   -je 0x4e805c
    if (cpu.flags.zf)
    {
        goto L_0x004e805c;
    }
L_0x004e8008:
    // 004e8008  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e800d  3b0584465600           +cmp eax, dword ptr [0x564684]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8013  741e                   -je 0x4e8033
    if (cpu.flags.zf)
    {
        goto L_0x004e8033;
    }
    // 004e8015  8b1580465600           -mov edx, dword ptr [0x564680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e801b  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8020  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e8022  a380465600             -mov dword ptr [0x564680], eax
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.eax;
    // 004e8027  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e802c  e86fe8ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8031  ebd5                   -jmp 0x4e8008
    goto L_0x004e8008;
L_0x004e8033:
    // 004e8033  8b1580465600           -mov edx, dword ptr [0x564680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8039  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e803e  e85de8ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8043  833d8846560000         +cmp dword ptr [0x564688], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e804a  7410                   -je 0x4e805c
    if (cpu.flags.zf)
    {
        goto L_0x004e805c;
    }
    // 004e804c  8b1588465600           -mov edx, dword ptr [0x564688]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
    // 004e8052  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e8057  e844e8ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e805c:
    // 004e805c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e805e  893580465600           -mov dword ptr [0x564680], esi
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.esi;
    // 004e8064  893584465600           -mov dword ptr [0x564684], esi
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.esi;
    // 004e806a  893588465600           -mov dword ptr [0x564688], esi
    app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */) = cpu.esi;
    // 004e8070  e8078e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e8075  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e8078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8078  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8079  8b1598465600           -mov edx, dword ptr [0x564698]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */);
    // 004e807f  ff0598465600           -inc dword ptr [0x564698]
    (app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */))++;
    // 004e8085  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e8088  01159c465600           -add dword ptr [0x56469c], edx
    (app->getMemory<x86::reg32>(x86::reg32(5654172) /* 0x56469c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e808e  8338ff                 +cmp dword ptr [eax], -1
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
    // 004e8091  751a                   -jne 0x4e80ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e80ad;
    }
L_0x004e8093:
    // 004e8093  833d8046560000         +cmp dword ptr [0x564680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e809a  7519                   -jne 0x4e80b5
    if (!cpu.flags.zf)
    {
        goto L_0x004e80b5;
    }
    // 004e809c  a380465600             -mov dword ptr [0x564680], eax
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.eax;
    // 004e80a1  a384465600             -mov dword ptr [0x564684], eax
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.eax;
    // 004e80a6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004e80ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e80ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e80ad:
    // 004e80ad  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004e80b3  ebde                   -jmp 0x4e8093
    goto L_0x004e8093;
L_0x004e80b5:
    // 004e80b5  8b1584465600           -mov edx, dword ptr [0x564684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */);
    // 004e80bb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004e80bd  a384465600             -mov dword ptr [0x564684], eax
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.eax;
    // 004e80c2  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004e80c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e80c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e80cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e80cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e80cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e80ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e80cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e80d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e80d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e80d2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e80d5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e80d7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004e80dc  803d0b47560000         +cmp byte ptr [0x56470b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e80e3  7e0c                   -jle 0x4e80f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e80f1;
    }
    // 004e80e5  8a1d0b475600           -mov bl, byte ptr [0x56470b]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */);
    // 004e80eb  fe0d0b475600           -dec byte ptr [0x56470b]
    (app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */))--;
L_0x004e80f1:
    // 004e80f1  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004e80f4  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004e80f7  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e80f9  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e80fd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e80ff  7e05                   -jle 0x4e8106
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8106;
    }
    // 004e8101  83fb5c                 +cmp ebx, 0x5c
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
    // 004e8104  7e31                   -jle 0x4e8137
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8137;
    }
L_0x004e8106:
    // 004e8106  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8107  ba34ac5400             -mov edx, 0x54ac34
    cpu.edx = 5549108 /*0x54ac34*/;
    // 004e810c  b934af5400             -mov ecx, 0x54af34
    cpu.ecx = 5549876 /*0x54af34*/;
    // 004e8111  6a5c                   -push 0x5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 92 /*0x5c*/;
    cpu.esp -= 4;
    // 004e8113  beaa040000             -mov esi, 0x4aa
    cpu.esi = 1194 /*0x4aa*/;
    // 004e8118  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e811e  6844af5400             -push 0x54af44
    app->getMemory<x86::reg32>(cpu.esp-4) = 5549892 /*0x54af44*/;
    cpu.esp -= 4;
    // 004e8123  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e8129  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e812f  e8dc8ef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8134  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e8137:
    // 004e8137  803d0047560000         +cmp byte ptr [0x564700], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654272) /* 0x564700 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e813e  7550                   -jne 0x4e8190
    if (!cpu.flags.zf)
    {
        goto L_0x004e8190;
    }
L_0x004e8140:
    // 004e8140  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e8144  bfa0465600             -mov edi, 0x5646a0
    cpu.edi = 5654176 /*0x5646a0*/;
    // 004e8149  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e814b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e814c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e814e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004e8151  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e8153  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004e8155  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004e8158  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004e815a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e815b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e815d  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e8162  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004e8164  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e8166  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e8169  e83ea00100             -call 0x5021ac
    cpu.esp -= 4;
    sub_5021ac(app, cpu);
    if (cpu.terminate) return;
    // 004e816e  c605fc46560001         -mov byte ptr [0x5646fc], 1
    app->getMemory<x86::reg8>(x86::reg32(5654268) /* 0x5646fc */) = 1 /*0x1*/;
    // 004e8175  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e817a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e817c  e81fe7ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8181  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e8186  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e8189  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e818f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8190:
    // 004e8190  a00a475600             -mov al, byte ptr [0x56470a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */);
    // 004e8195  fe050a475600           -inc byte ptr [0x56470a]
    (app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */))++;
    // 004e819b  a009475600             -mov al, byte ptr [0x564709]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */);
    // 004e81a0  fe0d09475600           -dec byte ptr [0x564709]
    (app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */))--;
    // 004e81a6  bf74475600             -mov edi, 0x564774
    cpu.edi = 5654388 /*0x564774*/;
    // 004e81ab  be80475600             -mov esi, 0x564780
    cpu.esi = 5654400 /*0x564780*/;
    // 004e81b0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e81b1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e81b2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e81b3  ba80475600             -mov edx, 0x564780
    cpu.edx = 5654400 /*0x564780*/;
    // 004e81b8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e81bc  e86fa10100             -call 0x502330
    cpu.esp -= 4;
    sub_502330(app, cpu);
    if (cpu.terminate) return;
    // 004e81c1  803d0c47560000         +cmp byte ptr [0x56470c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654284) /* 0x56470c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e81c8  7440                   -je 0x4e820a
    if (cpu.flags.zf)
    {
        goto L_0x004e820a;
    }
    // 004e81ca  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004e81cf  bf74475600             -mov edi, 0x564774
    cpu.edi = 5654388 /*0x564774*/;
    // 004e81d4  be80475600             -mov esi, 0x564780
    cpu.esi = 5654400 /*0x564780*/;
    // 004e81d9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e81db  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004e81dd  7405                   -je 0x4e81e4
    if (cpu.flags.zf)
    {
        goto L_0x004e81e4;
    }
    // 004e81df  19c0                   +sbb eax, eax
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
    // 004e81e1  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004e81e4:
    // 004e81e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e81e6  7422                   -je 0x4e820a
    if (cpu.flags.zf)
    {
        goto L_0x004e820a;
    }
    // 004e81e8  803dfd46560002         +cmp byte ptr [0x5646fd], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e81ef  7412                   -je 0x4e8203
    if (cpu.flags.zf)
    {
        goto L_0x004e8203;
    }
    // 004e81f1  803dfd46560003         +cmp byte ptr [0x5646fd], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e81f8  7409                   -je 0x4e8203
    if (cpu.flags.zf)
    {
        goto L_0x004e8203;
    }
    // 004e81fa  e8f9070000             -call 0x4e89f8
    cpu.esp -= 4;
    sub_4e89f8(app, cpu);
    if (cpu.terminate) return;
    // 004e81ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8201  7c13                   -jl 0x4e8216
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8216;
    }
L_0x004e8203:
    // 004e8203  c605fd46560003         -mov byte ptr [0x5646fd], 3
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = 3 /*0x3*/;
L_0x004e820a:
    // 004e820a  c6050c47560001         -mov byte ptr [0x56470c], 1
    app->getMemory<x86::reg8>(x86::reg32(5654284) /* 0x56470c */) = 1 /*0x1*/;
    // 004e8211  e92affffff             -jmp 0x4e8140
    goto L_0x004e8140;
L_0x004e8216:
    // 004e8216  bf34ac5400             -mov edi, 0x54ac34
    cpu.edi = 5549108 /*0x54ac34*/;
    // 004e821b  b834af5400             -mov eax, 0x54af34
    cpu.eax = 5549876 /*0x54af34*/;
    // 004e8220  bac7040000             -mov edx, 0x4c7
    cpu.edx = 1223 /*0x4c7*/;
    // 004e8225  68bcaf5400             -push 0x54afbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550012 /*0x54afbc*/;
    cpu.esp -= 4;
    // 004e822a  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e8230  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e8235  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e823b  e8d08df1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8240  83c404                 +add esp, 4
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
    // 004e8243  c605fd46560003         -mov byte ptr [0x5646fd], 3
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = 3 /*0x3*/;
    // 004e824a  c6050c47560001         -mov byte ptr [0x56470c], 1
    app->getMemory<x86::reg8>(x86::reg32(5654284) /* 0x56470c */) = 1 /*0x1*/;
    // 004e8251  e9eafeffff             -jmp 0x4e8140
    goto L_0x004e8140;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e8258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8258  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8259  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e825a  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e825d  8a0d0e475600           -mov cl, byte ptr [0x56470e]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
    // 004e8263  3a0d0f475600           +cmp cl, byte ptr [0x56470f]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8269  7511                   -jne 0x4e827c
    if (!cpu.flags.zf)
    {
        goto L_0x004e827c;
    }
    // 004e826b  0fbe0d0e475600         -movsx ecx, byte ptr [0x56470e]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */)));
    // 004e8272  833c8d1c47560000       +cmp dword ptr [ecx*4 + 0x56471c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e827a  7e0c                   -jle 0x4e8288
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8288;
    }
L_0x004e827c:
    // 004e827c  8a0d0f475600           -mov cl, byte ptr [0x56470f]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */);
    // 004e8282  fe050f475600           -inc byte ptr [0x56470f]
    (app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */))++;
L_0x004e8288:
    // 004e8288  803d0f47560014         +cmp byte ptr [0x56470f], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e828f  7c0a                   -jl 0x4e829b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e829b;
    }
    // 004e8291  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8292  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e8294  881d0f475600           -mov byte ptr [0x56470f], bl
    app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */) = cpu.bl;
    // 004e829a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e829b:
    // 004e829b  0fbe0d0f475600         -movsx ecx, byte ptr [0x56470f]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
    // 004e82a2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004e82a4  89148d1c475600         -mov dword ptr [ecx*4 + 0x56471c], edx
    app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.ecx * 4) = cpu.edx;
    // 004e82ab  8b0d7c465600           -mov ecx, dword ptr [0x56467c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e82b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e82b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e82b5  e8e6e5ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e82ba  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004e82bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e82c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e82c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e82c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e82c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e82c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e82c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e82c8  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e82cb  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004e82cd  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e82d2  e849cdffff             -call 0x4e5020
    cpu.esp -= 4;
    sub_4e5020(app, cpu);
    if (cpu.terminate) return;
    // 004e82d7  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e82dc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e82de  e8bde5ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e82e3  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004e82e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e82e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e82ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e82ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e82ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e82ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e82ee  ff0578465600           -inc dword ptr [0x564678]
    (app->getMemory<x86::reg32>(x86::reg32(5654136) /* 0x564678 */))++;
    // 004e82f4  803dfe46560000         +cmp byte ptr [0x5646fe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654270) /* 0x5646fe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e82fb  750c                   -jne 0x4e8309
    if (!cpu.flags.zf)
    {
        goto L_0x004e8309;
    }
    // 004e82fd  8b0d84465600           -mov ecx, dword ptr [0x564684]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */);
    // 004e8303  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x004e8309:
    // 004e8309  8b0d7c465600           -mov ecx, dword ptr [0x56467c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e830f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8311  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e8313  e888e5ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8318  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004e831d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e831e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e831f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e8320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8320  a178465600             -mov eax, dword ptr [0x564678]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654136) /* 0x564678 */);
    // 004e8325  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e8328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8328  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8329  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e832a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e832b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e832c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e832d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e832f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e8331  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e8333  803d0d47560002         +cmp byte ptr [0x56470d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e833a  0f850e010000           -jne 0x4e844e
    if (!cpu.flags.zf)
    {
        goto L_0x004e844e;
    }
L_0x004e8340:
    // 004e8340  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8345  3b0584465600           +cmp eax, dword ptr [0x564684]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e834b  0f8482000000           -je 0x4e83d3
    if (cpu.flags.zf)
    {
        goto L_0x004e83d3;
    }
    // 004e8351  8b3d80465600           -mov edi, dword ptr [0x564680]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8357  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e835c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e835e  a380465600             -mov dword ptr [0x564680], eax
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.eax;
    // 004e8363  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004e8366  833d8846560000         +cmp dword ptr [0x564688], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e836d  7410                   -je 0x4e837f
    if (cpu.flags.zf)
    {
        goto L_0x004e837f;
    }
    // 004e836f  8b1588465600           -mov edx, dword ptr [0x564688]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
    // 004e8375  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e837a  e821e5ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e837f:
    // 004e837f  893d88465600           -mov dword ptr [0x564688], edi
    app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */) = cpu.edi;
    // 004e8385  a198465600             -mov eax, dword ptr [0x564698]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */);
    // 004e838a  ff0d98465600           -dec dword ptr [0x564698]
    (app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */))--;
    // 004e8390  292d9c465600           -sub dword ptr [0x56469c], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5654172) /* 0x56469c */)) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e8396  a194465600             -mov eax, dword ptr [0x564694]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */);
    // 004e839b  ff0594465600           -inc dword ptr [0x564694]
    (app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */))++;
    // 004e83a1  0fbe050e475600         -movsx eax, byte ptr [0x56470e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */)));
    // 004e83a8  8b14851c475600         -mov edx, dword ptr [eax*4 + 0x56471c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4);
    // 004e83af  ff0c851c475600         -dec dword ptr [eax*4 + 0x56471c]
    (app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4))--;
    // 004e83b6  0fbe050e475600         -movsx eax, byte ptr [0x56470e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */)));
    // 004e83bd  833c851c47560000       +cmp dword ptr [eax*4 + 0x56471c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e83c5  0f8e95000000           -jle 0x4e8460
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8460;
    }
L_0x004e83cb:
    // 004e83cb  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e83cd  88250d475600           -mov byte ptr [0x56470d], ah
    app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */) = cpu.ah;
L_0x004e83d3:
    // 004e83d3  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e83d8  3b0584465600           +cmp eax, dword ptr [0x564684]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e83de  0f85e0000000           -jne 0x4e84c4
    if (!cpu.flags.zf)
    {
        goto L_0x004e84c4;
    }
    // 004e83e4  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e83e9  8338ff                 +cmp dword ptr [eax], -1
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
    // 004e83ec  0f84ae000000           -je 0x4e84a0
    if (cpu.flags.zf)
    {
        goto L_0x004e84a0;
    }
    // 004e83f2  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e83f7  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e83fa  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004e83fc  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8401  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e8404  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004e8406  803d0d47560001         +cmp byte ptr [0x56470d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e840d  7519                   -jne 0x4e8428
    if (!cpu.flags.zf)
    {
        goto L_0x004e8428;
    }
    // 004e840f  0fbe3d01475600         -movsx edi, byte ptr [0x564701]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654273) /* 0x564701 */)));
    // 004e8416  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e8418  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004e841a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004e841c  e89f920100             -call 0x5016c0
    cpu.esp -= 4;
    sub_5016c0(app, cpu);
    if (cpu.terminate) return;
    // 004e8421  c6050d47560002         -mov byte ptr [0x56470d], 2
    app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */) = 2 /*0x2*/;
L_0x004e8428:
    // 004e8428  803d0d47560000         +cmp byte ptr [0x56470d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e842f  7507                   -jne 0x4e8438
    if (!cpu.flags.zf)
    {
        goto L_0x004e8438;
    }
    // 004e8431  c6050d47560001         -mov byte ptr [0x56470d], 1
    app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */) = 1 /*0x1*/;
L_0x004e8438:
    // 004e8438  803d0d47560002         +cmp byte ptr [0x56470d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e843f  7505                   -jne 0x4e8446
    if (!cpu.flags.zf)
    {
        goto L_0x004e8446;
    }
    // 004e8441  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004e8446:
    // 004e8446  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e8448  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8449  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e844a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e844b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e844c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e844d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e844e:
    // 004e844e  803d0d47560001         +cmp byte ptr [0x56470d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8455  0f84e5feffff           -je 0x4e8340
    if (cpu.flags.zf)
    {
        goto L_0x004e8340;
    }
    // 004e845b  e973ffffff             -jmp 0x4e83d3
    goto L_0x004e83d3;
L_0x004e8460:
    // 004e8460  a00a475600             -mov al, byte ptr [0x56470a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */);
    // 004e8465  fe0d0a475600           -dec byte ptr [0x56470a]
    (app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */))--;
    // 004e846b  a00e475600             -mov al, byte ptr [0x56470e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
    // 004e8470  3a050f475600           +cmp al, byte ptr [0x56470f]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8476  0f844fffffff           -je 0x4e83cb
    if (cpu.flags.zf)
    {
        goto L_0x004e83cb;
    }
    // 004e847c  a00e475600             -mov al, byte ptr [0x56470e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
    // 004e8481  fe050e475600           -inc byte ptr [0x56470e]
    (app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */))++;
    // 004e8487  803d0e47560014         +cmp byte ptr [0x56470e], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e848e  0f8c37ffffff           -jl 0x4e83cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e83cb;
    }
    // 004e8494  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004e8496  a20e475600             -mov byte ptr [0x56470e], al
    app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */) = cpu.al;
    // 004e849b  e92bffffff             -jmp 0x4e83cb
    goto L_0x004e83cb;
L_0x004e84a0:
    // 004e84a0  8b1580465600           -mov edx, dword ptr [0x564680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e84a6  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e84ab  e8f0e3ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e84b0  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004e84b6  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004e84bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e84be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e84bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e84c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e84c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e84c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e84c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e84c4:
    // 004e84c4  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e84c9  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e84cc  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004e84ce  8b1d80465600           -mov ebx, dword ptr [0x564680]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e84d4  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004e84d7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e84d9  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004e84db  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e84e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e84e2  a380465600             -mov dword ptr [0x564680], eax
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.eax;
    // 004e84e7  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004e84ea  833d8846560000         +cmp dword ptr [0x564688], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e84f1  7410                   -je 0x4e8503
    if (cpu.flags.zf)
    {
        goto L_0x004e8503;
    }
    // 004e84f3  8b1588465600           -mov edx, dword ptr [0x564688]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */);
    // 004e84f9  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e84fe  e89de3ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e8503:
    // 004e8503  891d88465600           -mov dword ptr [0x564688], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */) = cpu.ebx;
    // 004e8509  a198465600             -mov eax, dword ptr [0x564698]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */);
    // 004e850e  ff0d98465600           -dec dword ptr [0x564698]
    (app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */))--;
    // 004e8514  290d9c465600           -sub dword ptr [0x56469c], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5654172) /* 0x56469c */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e851a  a194465600             -mov eax, dword ptr [0x564694]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */);
    // 004e851f  ff0594465600           -inc dword ptr [0x564694]
    (app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */))++;
    // 004e8525  0fbe050e475600         -movsx eax, byte ptr [0x56470e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */)));
    // 004e852c  8b14851c475600         -mov edx, dword ptr [eax*4 + 0x56471c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4);
    // 004e8533  ff0c851c475600         -dec dword ptr [eax*4 + 0x56471c]
    (app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4))--;
    // 004e853a  0fbe050e475600         -movsx eax, byte ptr [0x56470e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */)));
    // 004e8541  833c851c47560000       +cmp dword ptr [eax*4 + 0x56471c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8549  0f8ff7feffff           -jg 0x4e8446
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e8446;
    }
    // 004e854f  a00a475600             -mov al, byte ptr [0x56470a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */);
    // 004e8554  fe0d0a475600           -dec byte ptr [0x56470a]
    (app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */))--;
    // 004e855a  a00e475600             -mov al, byte ptr [0x56470e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
    // 004e855f  3a050f475600           +cmp al, byte ptr [0x56470f]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8565  0f84dbfeffff           -je 0x4e8446
    if (cpu.flags.zf)
    {
        goto L_0x004e8446;
    }
    // 004e856b  a00e475600             -mov al, byte ptr [0x56470e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
    // 004e8570  fe050e475600           -inc byte ptr [0x56470e]
    (app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */))++;
    // 004e8576  803d0e47560014         +cmp byte ptr [0x56470e], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e857d  0f8cc3feffff           -jl 0x4e8446
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8446;
    }
    // 004e8583  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004e8585  880d0e475600           -mov byte ptr [0x56470e], cl
    app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */) = cpu.cl;
    // 004e858b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e858d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e858e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e858f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8590  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8591  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e85a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004e85a8  e8c30a0100             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004e85ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e85af  7403                   -je 0x4e85b4
    if (cpu.flags.zf)
    {
        goto L_0x004e85b4;
    }
    // 004e85b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e85b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e85b4:
    // 004e85b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e85b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e85b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e85b7  e864880100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e85bc  a0fd465600             -mov al, byte ptr [0x5646fd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
    // 004e85c1  3c04                   +cmp al, 4
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
    // 004e85c3  770c                   -ja 0x4e85d1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e85c5  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004e85ca  ff248594854e00         -jmp dword ptr [eax*4 + 0x4e8594]
    cpu.ip = app->getMemory<x86::reg32>(5146004 + cpu.eax * 4); goto dynamic_jump;
  case 0x004e85d1:
L_0x004e85d1:
    // 004e85d1  e8a6880100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e85d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e85d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e85d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e85da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e85db  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e85dc:
    // 004e85dc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e85de:
    // 004e85de  3a0d00475600           +cmp cl, byte ptr [0x564700]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654272) /* 0x564700 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e85e4  750d                   -jne 0x4e85f3
    if (!cpu.flags.zf)
    {
        goto L_0x004e85f3;
    }
    // 004e85e6  a110475600             -mov eax, dword ptr [0x564710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */);
    // 004e85eb  3b0514475600           +cmp eax, dword ptr [0x564714]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654292) /* 0x564714 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e85f1  7dde                   -jge 0x4e85d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e85d1;
    }
L_0x004e85f3:
    // 004e85f3  3a0d0b475600           +cmp cl, byte ptr [0x56470b]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e85f9  7526                   -jne 0x4e8621
    if (!cpu.flags.zf)
    {
        goto L_0x004e8621;
    }
    // 004e85fb  833d18475600ff         +cmp dword ptr [0x564718], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654296) /* 0x564718 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8602  74cd                   -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e8604  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e8609  e8b2e2ffff             -call 0x4e68c0
    cpu.esp -= 4;
    sub_4e68c0(app, cpu);
    if (cpu.terminate) return;
    // 004e860e  3b0518475600           +cmp eax, dword ptr [0x564718]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654296) /* 0x564718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8614  0f8c93000000           -jl 0x4e86ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e86ad;
    }
L_0x004e861a:
    // 004e861a  c6050b475600ff         -mov byte ptr [0x56470b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */) = 255 /*0xff*/;
L_0x004e8621:
    // 004e8621  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e8626  e815e1ffff             -call 0x4e6740
    cpu.esp -= 4;
    sub_4e6740(app, cpu);
    if (cpu.terminate) return;
    // 004e862b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e862d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e862f  0f8e95000000           -jle 0x4e86ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e86ca;
    }
L_0x004e8635:
    // 004e8635  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e8637  e8f4f8ffff             -call 0x4e7f30
    cpu.esp -= 4;
    sub_4e7f30(app, cpu);
    if (cpu.terminate) return;
    // 004e863c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e863e  0f8cc1000000           -jl 0x4e8705
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8705;
    }
    // 004e8644  83f803                 +cmp eax, 3
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
    // 004e8647  0f85ea000000           -jne 0x4e8737
    if (!cpu.flags.zf)
    {
        goto L_0x004e8737;
    }
    // 004e864d  ff0510475600           -inc dword ptr [0x564710]
    (app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */))++;
L_0x004e8653:
    // 004e8653  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e8655  7f87                   -jg 0x4e85de
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e85de;
    }
    // 004e8657  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e865a  7e82                   -jle 0x4e85de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e85de;
    }
    // 004e865c  803d0047560000         +cmp byte ptr [0x564700], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654272) /* 0x564700 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8663  0f8468ffffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e8669  a110475600             -mov eax, dword ptr [0x564710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */);
    // 004e866e  3b0514475600           +cmp eax, dword ptr [0x564714]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654292) /* 0x564714 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8674  7d27                   -jge 0x4e869d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e869d;
    }
    // 004e8676  833d1047560000         +cmp dword ptr [0x564710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e867d  0f85cf000000           -jne 0x4e8752
    if (!cpu.flags.zf)
    {
        goto L_0x004e8752;
    }
L_0x004e8683:
    // 004e8683  833d1047560000         +cmp dword ptr [0x564710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e868a  0f8441ffffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e8690  e84be2ffff             -call 0x4e68e0
    cpu.esp -= 4;
    sub_4e68e0(app, cpu);
    if (cpu.terminate) return;
    // 004e8695  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8697  0f8434ffffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
L_0x004e869d:
    // 004e869d  e856030000             -call 0x4e89f8
    cpu.esp -= 4;
    sub_4e89f8(app, cpu);
    if (cpu.terminate) return;
    // 004e86a2  e8d5870100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e86a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e86a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e86ad:
    // 004e86ad  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e86b2  e899e2ffff             -call 0x4e6950
    cpu.esp -= 4;
    sub_4e6950(app, cpu);
    if (cpu.terminate) return;
    // 004e86b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e86b9  0f855bffffff           -jne 0x4e861a
    if (!cpu.flags.zf)
    {
        goto L_0x004e861a;
    }
    // 004e86bf  e8b8870100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e86c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e86c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e86c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e86ca:
    // 004e86ca  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e86cd  0f8e62ffffff           -jle 0x4e8635
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8635;
    }
    // 004e86d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e86d5  0f8478ffffff           -je 0x4e8653
    if (cpu.flags.zf)
    {
        goto L_0x004e8653;
    }
    // 004e86db  833d1047560000         +cmp dword ptr [0x564710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e86e2  0f84e9feffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e86e8  803d0047560000         +cmp byte ptr [0x564700], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654272) /* 0x564700 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e86ef  0f84dcfeffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e86f5  e8fe020000             -call 0x4e89f8
    cpu.esp -= 4;
    sub_4e89f8(app, cpu);
    if (cpu.terminate) return;
    // 004e86fa  e87d870100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e86ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8701  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8702  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8703  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8704  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8705:
    // 004e8705  b834ac5400             -mov eax, 0x54ac34
    cpu.eax = 5549108 /*0x54ac34*/;
    // 004e870a  bb00b05400             -mov ebx, 0x54b000
    cpu.ebx = 5550080 /*0x54b000*/;
    // 004e870f  be1c060000             -mov esi, 0x61c
    cpu.esi = 1564 /*0x61c*/;
    // 004e8714  6814b05400             -push 0x54b014
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550100 /*0x54b014*/;
    cpu.esp -= 4;
    // 004e8719  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e871e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e8724  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e872a  e8e188f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e872f  83c404                 +add esp, 4
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
    // 004e8732  e91cffffff             -jmp 0x4e8653
    goto L_0x004e8653;
L_0x004e8737:
    // 004e8737  83f801                 +cmp eax, 1
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
    // 004e873a  0f8513ffffff           -jne 0x4e8653
    if (!cpu.flags.zf)
    {
        goto L_0x004e8653;
    }
    // 004e8740  803dfd46560001         +cmp byte ptr [0x5646fd], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8747  0f8584feffff           -jne 0x4e85d1
    if (!cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e874d  e901ffffff             -jmp 0x4e8653
    goto L_0x004e8653;
L_0x004e8752:
    // 004e8752  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e8757  e8f4e1ffff             -call 0x4e6950
    cpu.esp -= 4;
    sub_4e6950(app, cpu);
    if (cpu.terminate) return;
    // 004e875c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e875e  0f8539ffffff           -jne 0x4e869d
    if (!cpu.flags.zf)
    {
        goto L_0x004e869d;
    }
    // 004e8764  e91affffff             -jmp 0x4e8683
    goto L_0x004e8683;
  case 0x004e8769:
    // 004e8769  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 004e876b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e876d:
    // 004e876d  3a0d0b475600           +cmp cl, byte ptr [0x56470b]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8773  7525                   -jne 0x4e879a
    if (!cpu.flags.zf)
    {
        goto L_0x004e879a;
    }
    // 004e8775  833d18475600ff         +cmp dword ptr [0x564718], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654296) /* 0x564718 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e877c  0f844ffeffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e8782  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e8787  e834e1ffff             -call 0x4e68c0
    cpu.esp -= 4;
    sub_4e68c0(app, cpu);
    if (cpu.terminate) return;
    // 004e878c  3b0518475600           +cmp eax, dword ptr [0x564718]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654296) /* 0x564718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8792  7c3b                   -jl 0x4e87cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e87cf;
    }
L_0x004e8794:
    // 004e8794  881d0b475600           -mov byte ptr [0x56470b], bl
    app->getMemory<x86::reg8>(x86::reg32(5654283) /* 0x56470b */) = cpu.bl;
L_0x004e879a:
    // 004e879a  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e879f  e89cdfffff             -call 0x4e6740
    cpu.esp -= 4;
    sub_4e6740(app, cpu);
    if (cpu.terminate) return;
    // 004e87a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e87a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e87a8  7e3e                   -jle 0x4e87e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e87e8;
    }
L_0x004e87aa:
    // 004e87aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e87ac  e87ff7ffff             -call 0x4e7f30
    cpu.esp -= 4;
    sub_4e7f30(app, cpu);
    if (cpu.terminate) return;
    // 004e87b1  83f801                 +cmp eax, 1
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
    // 004e87b4  7409                   -je 0x4e87bf
    if (cpu.flags.zf)
    {
        goto L_0x004e87bf;
    }
L_0x004e87b6:
    // 004e87b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e87b8  7fb3                   -jg 0x4e876d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e876d;
    }
    // 004e87ba  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e87bd  7eae                   -jle 0x4e876d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e876d;
    }
L_0x004e87bf:
    // 004e87bf  e830f6ffff             -call 0x4e7df4
    cpu.esp -= 4;
    sub_4e7df4(app, cpu);
    if (cpu.terminate) return;
    // 004e87c4  e8b3860100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e87c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e87cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e87cf:
    // 004e87cf  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e87d4  e877e1ffff             -call 0x4e6950
    cpu.esp -= 4;
    sub_4e6950(app, cpu);
    if (cpu.terminate) return;
    // 004e87d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e87db  75b7                   -jne 0x4e8794
    if (!cpu.flags.zf)
    {
        goto L_0x004e8794;
    }
    // 004e87dd  e89a860100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e87e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e87e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e87e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e87e8:
    // 004e87e8  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e87eb  7ebd                   -jle 0x4e87aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e87aa;
    }
    // 004e87ed  ebc7                   -jmp 0x4e87b6
    goto L_0x004e87b6;
  case 0x004e87ef:
    // 004e87ef  e864f4ffff             -call 0x4e7c58
    cpu.esp -= 4;
    sub_4e7c58(app, cpu);
    if (cpu.terminate) return;
    // 004e87f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e87f6  0f8fd5fdffff           -jg 0x4e85d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e85d1;
    }
    // 004e87fc  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8801  e86a0e0000             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 004e8806  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e880b  e8c0070000             -call 0x4e8fd0
    cpu.esp -= 4;
    sub_4e8fd0(app, cpu);
    if (cpu.terminate) return;
    // 004e8810  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8812  0f84b9fdffff           -je 0x4e85d1
    if (cpu.flags.zf)
    {
        goto L_0x004e85d1;
    }
    // 004e8818  a00a475600             -mov al, byte ptr [0x56470a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */);
    // 004e881d  fe0d0a475600           -dec byte ptr [0x56470a]
    (app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */))--;
    // 004e8823  e8d0f7ffff             -call 0x4e7ff8
    cpu.esp -= 4;
    sub_4e7ff8(app, cpu);
    if (cpu.terminate) return;
    // 004e8828  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004e882a  e815010000             -call 0x4e8944
    cpu.esp -= 4;
    sub_4e8944(app, cpu);
    if (cpu.terminate) return;
    // 004e882f  8815fd465600           -mov byte ptr [0x5646fd], dl
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = cpu.dl;
    // 004e8835  e842860100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e883a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e883c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e883d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e883e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e883f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8840:
    // 004e8840  e8aff5ffff             -call 0x4e7df4
    cpu.esp -= 4;
    sub_4e7df4(app, cpu);
    if (cpu.terminate) return;
    // 004e8845  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e884a  e871e0ffff             -call 0x4e68c0
    cpu.esp -= 4;
    sub_4e68c0(app, cpu);
    if (cpu.terminate) return;
    // 004e884f  3d88130000             +cmp eax, 0x1388
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5000 /*0x1388*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8854  0f8e77fdffff           -jle 0x4e85d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e85d1;
    }
    // 004e885a  833d8046560000         +cmp dword ptr [0x564680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8861  7443                   -je 0x4e88a6
    if (cpu.flags.zf)
    {
        goto L_0x004e88a6;
    }
L_0x004e8863:
    // 004e8863  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8868  3b0584465600           +cmp eax, dword ptr [0x564684]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e886e  7426                   -je 0x4e8896
    if (cpu.flags.zf)
    {
        goto L_0x004e8896;
    }
    // 004e8870  8b1580465600           -mov edx, dword ptr [0x564680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e8876  a180465600             -mov eax, dword ptr [0x564680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e887b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e887d  a380465600             -mov dword ptr [0x564680], eax
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.eax;
    // 004e8882  3b1588465600           +cmp edx, dword ptr [0x564688]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5654152) /* 0x564688 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8888  74d9                   -je 0x4e8863
    if (cpu.flags.zf)
    {
        goto L_0x004e8863;
    }
    // 004e888a  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e888f  e80ce0ffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8894  ebcd                   -jmp 0x4e8863
    goto L_0x004e8863;
L_0x004e8896:
    // 004e8896  8b1580465600           -mov edx, dword ptr [0x564680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */);
    // 004e889c  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e88a1  e8fadfffff             -call 0x4e68a0
    cpu.esp -= 4;
    sub_4e68a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e88a6:
    // 004e88a6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e88a8  893580465600           -mov dword ptr [0x564680], esi
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.esi;
    // 004e88ae  893584465600           -mov dword ptr [0x564684], esi
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.esi;
    // 004e88b4  c6050947560001         -mov byte ptr [0x564709], 1
    app->getMemory<x86::reg8>(x86::reg32(5654281) /* 0x564709 */) = 1 /*0x1*/;
    // 004e88bb  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e88bd  881d0a475600           -mov byte ptr [0x56470a], bl
    app->getMemory<x86::reg8>(x86::reg32(5654282) /* 0x56470a */) = cpu.bl;
    // 004e88c3  893510475600           -mov dword ptr [0x564710], esi
    app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */) = cpu.esi;
    // 004e88c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e88cb  893594465600           -mov dword ptr [0x564694], esi
    app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */) = cpu.esi;
    // 004e88d1  893598465600           -mov dword ptr [0x564698], esi
    app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */) = cpu.esi;
    // 004e88d7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e88d9  89359c465600           -mov dword ptr [0x56469c], esi
    app->getMemory<x86::reg32>(x86::reg32(5654172) /* 0x56469c */) = cpu.esi;
    // 004e88df  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e88e1  883d0e475600           -mov byte ptr [0x56470e], bh
    app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */) = cpu.bh;
    // 004e88e7  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004e88e9  a20f475600             -mov byte ptr [0x56470f], al
    app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */) = cpu.al;
    // 004e88ee  0fbe050f475600         -movsx eax, byte ptr [0x56470f]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
    // 004e88f5  c704851c475600ffffffff -mov dword ptr [eax*4 + 0x56471c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4) = 4294967295 /*0xffffffff*/;
    // 004e8900  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e8902  88250d475600           -mov byte ptr [0x56470d], ah
    app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */) = cpu.ah;
L_0x004e8908:
    // 004e8908  a17c465600             -mov eax, dword ptr [0x56467c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654140) /* 0x56467c */);
    // 004e890d  e82edeffff             -call 0x4e6740
    cpu.esp -= 4;
    sub_4e6740(app, cpu);
    if (cpu.terminate) return;
    // 004e8912  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8914  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8916  7e22                   -jle 0x4e893a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e893a;
    }
L_0x004e8918:
    // 004e8918  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e891a  e811f6ffff             -call 0x4e7f30
    cpu.esp -= 4;
    sub_4e7f30(app, cpu);
    if (cpu.terminate) return;
L_0x004e891f:
    // 004e891f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e8921  7fe5                   -jg 0x4e8908
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e8908;
    }
    // 004e8923  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8926  7ee0                   -jle 0x4e8908
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8908;
    }
    // 004e8928  c605fd46560002         -mov byte ptr [0x5646fd], 2
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = 2 /*0x2*/;
    // 004e892f  e848850100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e8934  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8936  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8937  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8938  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8939  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e893a:
    // 004e893a  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e893d  7ed9                   -jle 0x4e8918
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8918;
    }
    // 004e893f  ebde                   -jmp 0x4e891f
    goto L_0x004e891f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e8944(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8944  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8945  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8946  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8947  ba28834e00             -mov edx, 0x4e8328
    cpu.edx = 5145384 /*0x4e8328*/;
    // 004e894c  b94c784e00             -mov ecx, 0x4e784c
    cpu.ecx = 5142604 /*0x4e784c*/;
    // 004e8951  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8953  8915b4785600           -mov dword ptr [0x5678b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */) = cpu.edx;
    // 004e8959  890d309ba000           -mov dword ptr [0xa09b30], ecx
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.ecx;
    // 004e895f  891d10475600           -mov dword ptr [0x564710], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654288) /* 0x564710 */) = cpu.ebx;
    // 004e8965  891d94465600           -mov dword ptr [0x564694], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654164) /* 0x564694 */) = cpu.ebx;
    // 004e896b  891d98465600           -mov dword ptr [0x564698], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654168) /* 0x564698 */) = cpu.ebx;
    // 004e8971  891d9c465600           -mov dword ptr [0x56469c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654172) /* 0x56469c */) = cpu.ebx;
    // 004e8977  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8979  891d80465600           -mov dword ptr [0x564680], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654144) /* 0x564680 */) = cpu.ebx;
    // 004e897f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8981  891d84465600           -mov dword ptr [0x564684], ebx
    app->getMemory<x86::reg32>(x86::reg32(5654148) /* 0x564684 */) = cpu.ebx;
    // 004e8987  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e898c  890d90465600           -mov dword ptr [0x564690], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */) = cpu.ecx;
    // 004e8992  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e8994  8825fd465600           -mov byte ptr [0x5646fd], ah
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = cpu.ah;
    // 004e899a  30da                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e899c  88150e475600           -mov byte ptr [0x56470e], dl
    app->getMemory<x86::reg8>(x86::reg32(5654286) /* 0x56470e */) = cpu.dl;
    // 004e89a2  30fe                   -xor dh, bh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e89a4  88350f475600           -mov byte ptr [0x56470f], dh
    app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */) = cpu.dh;
    // 004e89aa  0fbe050f475600         -movsx eax, byte ptr [0x56470f]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654287) /* 0x56470f */)));
    // 004e89b1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e89b3  890c851c475600         -mov dword ptr [eax*4 + 0x56471c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5654300) /* 0x56471c */ + cpu.eax * 4) = cpu.ecx;
    // 004e89ba  c605fe46560001         -mov byte ptr [0x5646fe], 1
    app->getMemory<x86::reg8>(x86::reg32(5654270) /* 0x5646fe */) = 1 /*0x1*/;
    // 004e89c1  30ef                   -xor bh, ch
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004e89c3  883d0d475600           -mov byte ptr [0x56470d], bh
    app->getMemory<x86::reg8>(x86::reg32(5654285) /* 0x56470d */) = cpu.bh;
    // 004e89c9  803d0847560000         +cmp byte ptr [0x564708], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e89d0  7406                   -je 0x4e89d8
    if (cpu.flags.zf)
    {
        goto L_0x004e89d8;
    }
    // 004e89d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e89d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e89d8:
    // 004e89d8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004e89dd  b8a8854e00             -mov eax, 0x4e85a8
    cpu.eax = 5146024 /*0x4e85a8*/;
    // 004e89e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e89e4  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 004e89e6  e835ebffff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 004e89eb  882d08475600           -mov byte ptr [0x564708], ch
    app->getMemory<x86::reg8>(x86::reg32(5654280) /* 0x564708 */) = cpu.ch;
    // 004e89f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e89f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e89f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e89f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e89f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e89f9  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e89fc  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8a01  e8ca050000             -call 0x4e8fd0
    cpu.esp -= 4;
    sub_4e8fd0(app, cpu);
    if (cpu.terminate) return;
    // 004e8a06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8a08  0f84b9000000           -je 0x4e8ac7
    if (cpu.flags.zf)
    {
        goto L_0x004e8ac7;
    }
    // 004e8a0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e8a0f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8a11  803dfc46560000         +cmp byte ptr [0x5646fc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5654268) /* 0x5646fc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8a18  0f84b3000000           -je 0x4e8ad1
    if (cpu.flags.zf)
    {
        goto L_0x004e8ad1;
    }
L_0x004e8a1e:
    // 004e8a1e  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e8a22  e8f9100000             -call 0x4e9b20
    cpu.esp -= 4;
    sub_4e9b20(app, cpu);
    if (cpu.terminate) return;
    // 004e8a27  a002475600             -mov al, byte ptr [0x564702]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654274) /* 0x564702 */);
    // 004e8a2c  88442414               -mov byte ptr [esp + 0x14], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 004e8a30  a003475600             -mov al, byte ptr [0x564703]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654275) /* 0x564703 */);
    // 004e8a35  88442413               -mov byte ptr [esp + 0x13], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.al;
    // 004e8a39  a004475600             -mov al, byte ptr [0x564704]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654276) /* 0x564704 */);
    // 004e8a3e  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004e8a42  a005475600             -mov al, byte ptr [0x564705]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5654277) /* 0x564705 */);
    // 004e8a47  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e8a4b  88442416               -mov byte ptr [esp + 0x16], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */) = cpu.al;
    // 004e8a4f  b8a0465600             -mov eax, 0x5646a0
    cpu.eax = 5654176 /*0x5646a0*/;
    // 004e8a54  e88f930100             -call 0x501de8
    cpu.esp -= 4;
    sub_501de8(app, cpu);
    if (cpu.terminate) return;
    // 004e8a59  a390465600             -mov dword ptr [0x564690], eax
    app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */) = cpu.eax;
    // 004e8a5e  833d9046560000         +cmp dword ptr [0x564690], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8a65  0f8c9b000000           -jl 0x4e8b06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8b06;
    }
    // 004e8a6b  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8a70  e827720100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e8a75  a201475600             -mov byte ptr [0x564701], al
    app->getMemory<x86::reg8>(x86::reg32(5654273) /* 0x564701 */) = cpu.al;
    // 004e8a7a  0fbe1501475600         -movsx edx, byte ptr [0x564701]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5654273) /* 0x564701 */)));
    // 004e8a81  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e8a88  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8a8a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e8a8d  8a80479ba000           -mov al, byte ptr [eax + 0xa09b47]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525511) /* 0xa09b47 */);
    // 004e8a93  a2ff465600             -mov byte ptr [0x5646ff], al
    app->getMemory<x86::reg8>(x86::reg32(5654271) /* 0x5646ff */) = cpu.al;
    // 004e8a98  c605fd46560002         -mov byte ptr [0x5646fd], 2
    app->getMemory<x86::reg8>(x86::reg32(5654269) /* 0x5646fd */) = 2 /*0x2*/;
    // 004e8a9f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e8aa1  8835fc465600           -mov byte ptr [0x5646fc], dh
    app->getMemory<x86::reg8>(x86::reg32(5654268) /* 0x5646fc */) = cpu.dh;
    // 004e8aa7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e8aa9  66890d06475600         -mov word ptr [0x564706], cx
    app->getMemory<x86::reg16>(x86::reg32(5654278) /* 0x564706 */) = cpu.cx;
    // 004e8ab0  b8987e4e00             -mov eax, 0x4e7e98
    cpu.eax = 5144216 /*0x4e7e98*/;
    // 004e8ab5  e8a66b0100             -call 0x4ff660
    cpu.esp -= 4;
    sub_4ff660(app, cpu);
    if (cpu.terminate) return;
L_0x004e8aba:
    // 004e8aba  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8abf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ac0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ac2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e8ac5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ac6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8ac7:
    // 004e8ac7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e8acc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e8acf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ad0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8ad1:
    // 004e8ad1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8ad2  ba34ac5400             -mov edx, 0x54ac34
    cpu.edx = 5549108 /*0x54ac34*/;
    // 004e8ad7  b940b05400             -mov ecx, 0x54b040
    cpu.ecx = 5550144 /*0x54b040*/;
    // 004e8adc  bb14070000             -mov ebx, 0x714
    cpu.ebx = 1812 /*0x714*/;
    // 004e8ae1  6850b05400             -push 0x54b050
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550160 /*0x54b050*/;
    cpu.esp -= 4;
    // 004e8ae6  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e8aec  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e8af2  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e8af8  e81385f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8afd  83c404                 +add esp, 4
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
    // 004e8b00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b01  e918ffffff             -jmp 0x4e8a1e
    goto L_0x004e8a1e;
L_0x004e8b06:
    // 004e8b06  66a106475600           -mov ax, word ptr [0x564706]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5654278) /* 0x564706 */);
    // 004e8b0c  66ff0506475600         -inc word ptr [0x564706]
    (app->getMemory<x86::reg16>(x86::reg32(5654278) /* 0x564706 */))++;
    // 004e8b13  66813d064756001027     +cmp word ptr [0x564706], 0x2710
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5654278) /* 0x564706 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10000 /*0x2710*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e8b1c  769c                   -jbe 0x4e8aba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e8aba;
    }
    // 004e8b1e  bf34ac5400             -mov edi, 0x54ac34
    cpu.edi = 5549108 /*0x54ac34*/;
    // 004e8b23  bd40b05400             -mov ebp, 0x54b040
    cpu.ebp = 5550144 /*0x54b040*/;
    // 004e8b28  b837070000             -mov eax, 0x737
    cpu.eax = 1847 /*0x737*/;
    // 004e8b2d  6874b05400             -push 0x54b074
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550196 /*0x54b074*/;
    cpu.esp -= 4;
    // 004e8b32  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e8b38  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e8b3e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e8b43  e8c884f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8b48  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e8b4b  a190465600             -mov eax, dword ptr [0x564690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8b50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b53  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e8b56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e8b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8b60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8b61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8b62  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8b69  7422                   -je 0x4e8b8d
    if (cpu.flags.zf)
    {
        goto L_0x004e8b8d;
    }
    // 004e8b6b  83f87f                 +cmp eax, 0x7f
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
    // 004e8b6e  7f25                   -jg 0x4e8b95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e8b95;
    }
    // 004e8b70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8b72  7c21                   -jl 0x4e8b95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8b95;
    }
    // 004e8b74  a202475600             -mov byte ptr [0x564702], al
    app->getMemory<x86::reg8>(x86::reg32(5654274) /* 0x564702 */) = cpu.al;
    // 004e8b79  8b0d90465600           -mov ecx, dword ptr [0x564690]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5654160) /* 0x564690 */);
    // 004e8b7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8b81  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e8b83  e8740a0000             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 004e8b88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8b8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8b8d:
    // 004e8b8d  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004e8b92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8b94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8b95:
    // 004e8b95  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8b96  bac0b05400             -mov edx, 0x54b0c0
    cpu.edx = 5550272 /*0x54b0c0*/;
    // 004e8b9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e8b9c  b9ccb05400             -mov ecx, 0x54b0cc
    cpu.ecx = 5550284 /*0x54b0cc*/;
    // 004e8ba1  bb74000000             -mov ebx, 0x74
    cpu.ebx = 116 /*0x74*/;
    // 004e8ba6  68dcb05400             -push 0x54b0dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550300 /*0x54b0dc*/;
    cpu.esp -= 4;
    // 004e8bab  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e8bb1  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e8bb7  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e8bbd  e84e84f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8bc2  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e8bc7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e8bca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8bcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8bcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e8bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8bd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e8bd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e8bd4  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004e8bda  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e8bdc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e8bde  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004e8be3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e8be5:
    // 004e8be5  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e8be8  89540cf4               -mov dword ptr [esp + ecx - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.edx;
    // 004e8bec  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8bf2  75f1                   -jne 0x4e8be5
    if (!cpu.flags.zf)
    {
        goto L_0x004e8be5;
    }
    // 004e8bf4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e8bf6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e8bf8  7e12                   -jle 0x4e8c0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e8c0c;
    }
L_0x004e8bfa:
    // 004e8bfa  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004e8bfc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e8bfe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e8c00  41                     -inc ecx
    (cpu.ecx)++;
    // 004e8c01  e89a980100             -call 0x5024a0
    cpu.esp -= 4;
    sub_5024a0(app, cpu);
    if (cpu.terminate) return;
    // 004e8c06  39f9                   +cmp ecx, edi
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
    // 004e8c08  7cf0                   -jl 0x4e8bfa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8bfa;
    }
    // 004e8c0a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004e8c0c:
    // 004e8c0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8c0e  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004e8c14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e8c1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8c1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8c1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8c1f  e804000000             -call 0x4e8c28
    cpu.esp -= 4;
    sub_4e8c28(app, cpu);
    if (cpu.terminate) return;
    // 004e8c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e8c28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8c28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8c29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8c2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e8c2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e8c2d  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8c34  741e                   -je 0x4e8c54
    if (cpu.flags.zf)
    {
        goto L_0x004e8c54;
    }
    // 004e8c36  83fbff                 +cmp ebx, -1
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
    // 004e8c39  7522                   -jne 0x4e8c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004e8c5d;
    }
    // 004e8c3b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e8c3d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004e8c3f:
    // 004e8c3f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e8c41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e8c43  41                     -inc ecx
    (cpu.ecx)++;
    // 004e8c44  e8dfffffff             -call 0x4e8c28
    cpu.esp -= 4;
    sub_4e8c28(app, cpu);
    if (cpu.terminate) return;
    // 004e8c49  83f918                 +cmp ecx, 0x18
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8c4c  7cf1                   -jl 0x4e8c3f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8c3f;
    }
    // 004e8c4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8c50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8c54:
    // 004e8c54  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e8c59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8c5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8c5d:
    // 004e8c5d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e8c5f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e8c66  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8c68  803c8544a1a00000       +cmp byte ptr [eax*4 + 0xa0a144], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10527044) /* 0xa0a144 */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8c70  742e                   -je 0x4e8ca0
    if (cpu.flags.zf)
    {
        goto L_0x004e8ca0;
    }
    // 004e8c72  ba0cb15400             -mov edx, 0x54b10c
    cpu.edx = 5550348 /*0x54b10c*/;
    // 004e8c77  b91cb15400             -mov ecx, 0x54b11c
    cpu.ecx = 5550364 /*0x54b11c*/;
    // 004e8c7c  be6f000000             -mov esi, 0x6f
    cpu.esi = 111 /*0x6f*/;
    // 004e8c81  682cb15400             -push 0x54b12c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550380 /*0x54b12c*/;
    cpu.esp -= 4;
    // 004e8c86  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e8c8c  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e8c92  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e8c98  e87383f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8c9d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e8ca0:
    // 004e8ca0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e8ca2  e8c9980100             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 004e8ca7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8ca9  7563                   -jne 0x4e8d0e
    if (!cpu.flags.zf)
    {
        goto L_0x004e8d0e;
    }
    // 004e8cab  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004e8cb2  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e8cb7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8cb9  8d9100060000           -lea edx, [ecx + 0x600]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
    // 004e8cbf  8b34853ca1a000         -mov esi, dword ptr [eax*4 + 0xa0a13c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4);
L_0x004e8cc6:
    // 004e8cc6  8b4107                 -mov eax, dword ptr [ecx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004e8cc9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004e8ccc  39d8                   +cmp eax, ebx
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
    // 004e8cce  7507                   -jne 0x4e8cd7
    if (!cpu.flags.zf)
    {
        goto L_0x004e8cd7;
    }
    // 004e8cd0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e8cd2  e899090000             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
L_0x004e8cd7:
    // 004e8cd7  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e8cda  39d1                   +cmp ecx, edx
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
    // 004e8cdc  75e8                   -jne 0x4e8cc6
    if (!cpu.flags.zf)
    {
        goto L_0x004e8cc6;
    }
    // 004e8cde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e8cdf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8ce1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e8ce3  668b5606               -mov dx, word ptr [esi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004e8ce7  e8e4feffff             -call 0x4e8bd0
    cpu.esp -= 4;
    sub_4e8bd0(app, cpu);
    if (cpu.terminate) return;
    // 004e8cec  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004e8cf3  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8cf5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e8cf7  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e8cf9  893c853ca1a000         -mov dword ptr [eax*4 + 0xa0a13c], edi
    app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4) = cpu.edi;
    // 004e8d00  88348544a1a000         -mov byte ptr [eax*4 + 0xa0a144], dh
    app->getMemory<x86::reg8>(x86::reg32(10527044) /* 0xa0a144 */ + cpu.eax * 4) = cpu.dh;
    // 004e8d07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8d09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d0d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8d0e:
    // 004e8d0e  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e8d13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e8d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8d22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e8d23  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e8d25  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e8d27  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8d2e  746c                   -je 0x4e8d9c
    if (cpu.flags.zf)
    {
        goto L_0x004e8d9c;
    }
    // 004e8d30  813a424e4b6c           +cmp dword ptr [edx], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e8d36  7432                   -je 0x4e8d6a
    if (cpu.flags.zf)
    {
        goto L_0x004e8d6a;
    }
    // 004e8d38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e8d39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e8d3a  be98b15400             -mov esi, 0x54b198
    cpu.esi = 5550488 /*0x54b198*/;
    // 004e8d3f  bfa4b15400             -mov edi, 0x54b1a4
    cpu.edi = 5550500 /*0x54b1a4*/;
    // 004e8d44  bd5b000000             -mov ebp, 0x5b
    cpu.ebp = 91 /*0x5b*/;
    // 004e8d49  68b0b15400             -push 0x54b1b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550512 /*0x54b1b0*/;
    cpu.esp -= 4;
    // 004e8d4e  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e8d54  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e8d5a  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e8d60  e8ab82f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8d65  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e8d68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e8d6a:
    // 004e8d6a  e841980100             -call 0x5025b0
    cpu.esp -= 4;
    sub_5025b0(app, cpu);
    if (cpu.terminate) return;
    // 004e8d6f  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004e8d71  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e8d73  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e8d76  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8d78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e8d7b  053ca1a000             -add eax, 0xa0a13c
    (cpu.eax) += x86::reg32(x86::sreg32(10527036 /*0xa0a13c*/));
    // 004e8d80  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004e8d82  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004e8d85  b81c8c4e00             -mov eax, 0x4e8c1c
    cpu.eax = 5147676 /*0x4e8c1c*/;
    // 004e8d8a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e8d8c  a3249ba000             -mov dword ptr [0xa09b24], eax
    app->getMemory<x86::reg32>(x86::reg32(10525476) /* 0xa09b24 */) = cpu.eax;
    // 004e8d91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e8d93  e888980100             -call 0x502620
    cpu.esp -= 4;
    sub_502620(app, cpu);
    if (cpu.terminate) return;
    // 004e8d98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8d9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8d9c:
    // 004e8d9c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e8da1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8da2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8da3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8da4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e8db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8db1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8db3  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8dba  7507                   -jne 0x4e8dc3
    if (!cpu.flags.zf)
    {
        goto L_0x004e8dc3;
    }
    // 004e8dbc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e8dc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8dc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8dc3:
    // 004e8dc3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e8dc5  e8a6970100             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 004e8dca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8dcc  7434                   -je 0x4e8e02
    if (cpu.flags.zf)
    {
        goto L_0x004e8e02;
    }
    // 004e8dce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e8dcf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8dd1  b9d0b15400             -mov ecx, 0x54b1d0
    cpu.ecx = 5550544 /*0x54b1d0*/;
    // 004e8dd6  bbe0b15400             -mov ebx, 0x54b1e0
    cpu.ebx = 5550560 /*0x54b1e0*/;
    // 004e8ddb  be47000000             -mov esi, 0x47
    cpu.esi = 71 /*0x47*/;
    // 004e8de0  68f4b15400             -push 0x54b1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550580 /*0x54b1f4*/;
    cpu.esp -= 4;
    // 004e8de5  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e8deb  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e8df1  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e8df7  e81482f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8dfc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e8dff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8e00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8e01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e8e02:
    // 004e8e02  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e8e09  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8e0b  8b04853ca1a000         -mov eax, dword ptr [eax*4 + 0xa0a13c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4);
    // 004e8e12  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e8e15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8e16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e8e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8e22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e8e23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e8e24  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e8e27  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e8e29  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004e8e2c  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8e33  0f8498000000           -je 0x4e8ed1
    if (cpu.flags.zf)
    {
        goto L_0x004e8ed1;
    }
    // 004e8e39  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e8e3b  752e                   -jne 0x4e8e6b
    if (!cpu.flags.zf)
    {
        goto L_0x004e8e6b;
    }
    // 004e8e3d  ba28b25400             -mov edx, 0x54b228
    cpu.edx = 5550632 /*0x54b228*/;
    // 004e8e42  b938b25400             -mov ecx, 0x54b238
    cpu.ecx = 5550648 /*0x54b238*/;
    // 004e8e47  bb4c000000             -mov ebx, 0x4c
    cpu.ebx = 76 /*0x4c*/;
    // 004e8e4c  684cb25400             -push 0x54b24c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550668 /*0x54b24c*/;
    cpu.esp -= 4;
    // 004e8e51  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e8e57  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e8e5d  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e8e63  e8a881f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e8e68  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e8e6b:
    // 004e8e6b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e8e6e  e83dffffff             -call 0x4e8db0
    cpu.esp -= 4;
    sub_4e8db0(app, cpu);
    if (cpu.terminate) return;
    // 004e8e73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8e75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8e77  7c5d                   -jl 0x4e8ed6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8ed6;
    }
    // 004e8e79  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e8e7a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e8e7e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004e8e85  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e8e87  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e8e89  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004e8e90  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004e8e94  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e8e96  8b813ca1a000           -mov eax, dword ptr [ecx + 0xa0a13c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10527036) /* 0xa0a13c */);
    // 004e8e9c  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004e8ea0  e84b160000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e8ea5  8b913ca1a000           -mov edx, dword ptr [ecx + 0xa0a13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10527036) /* 0xa0a13c */);
    // 004e8eab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8ead  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e8eaf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e8eb1:
    // 004e8eb1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8eb3  668b5a06               -mov bx, word ptr [edx + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004e8eb7  39d9                   +cmp ecx, ebx
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
    // 004e8eb9  7d4b                   -jge 0x4e8f06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e8f06;
    }
    // 004e8ebb  807a0404               +cmp byte ptr [edx + 4], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8ebf  752c                   -jne 0x4e8eed
    if (!cpu.flags.zf)
    {
        goto L_0x004e8eed;
    }
    // 004e8ec1  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004e8ec4  8b5b14                 -mov ebx, dword ptr [ebx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004e8ec7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e8ec9  7513                   -jne 0x4e8ede
    if (!cpu.flags.zf)
    {
        goto L_0x004e8ede;
    }
L_0x004e8ecb:
    // 004e8ecb  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e8ece  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e8ecf  ebe0                   -jmp 0x4e8eb1
    goto L_0x004e8eb1;
L_0x004e8ed1:
    // 004e8ed1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
L_0x004e8ed6:
    // 004e8ed6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e8ed9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8eda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8edb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8edc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8edd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8ede:
    // 004e8ede  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e8ee2  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004e8ee4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e8ee6  01f3                   +add ebx, esi
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
    // 004e8ee8  895d14                 -mov dword ptr [ebp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e8eeb  ebde                   -jmp 0x4e8ecb
    goto L_0x004e8ecb;
L_0x004e8eed:
    // 004e8eed  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004e8ef0  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004e8ef3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e8ef5  74d4                   -je 0x4e8ecb
    if (cpu.flags.zf)
    {
        goto L_0x004e8ecb;
    }
    // 004e8ef7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e8efb  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8efd  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e8eff  01f3                   +add ebx, esi
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
    // 004e8f01  895d0c                 -mov dword ptr [ebp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e8f04  ebc5                   -jmp 0x4e8ecb
    goto L_0x004e8ecb;
L_0x004e8f06:
    // 004e8f06  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e8f0a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e8f11  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8f13  8934853ca1a000         -mov dword ptr [eax*4 + 0xa0a13c], esi
    app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4) = cpu.esi;
    // 004e8f1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8f1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f1d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e8f20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4e8f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004e8f28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e8f29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e8f2a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e8f2c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e8f2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8f30  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004e8f32  7d05                   -jge 0x4e8f39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e8f39;
    }
    // 004e8f34  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e8f37  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004e8f39:
    // 004e8f39  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e8f3b  7d05                   -jge 0x4e8f42
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e8f42;
    }
    // 004e8f3d  83cb10                 -or ebx, 0x10
    cpu.ebx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e8f40  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004e8f42:
    // 004e8f42  39ca                   +cmp edx, ecx
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
    // 004e8f44  7c07                   -jl 0x4e8f4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8f4d;
    }
    // 004e8f46  741d                   -je 0x4e8f65
    if (cpu.flags.zf)
    {
        goto L_0x004e8f65;
    }
    // 004e8f48  87d1                   -xchg ecx, edx
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.edx;
        cpu.edx = tmp;
    }
    // 004e8f4a  83cb04                 -or ebx, 4
    cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e8f4d:
    // 004e8f4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e8f4f  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004e8f51  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004e8f54  83d000                 +adc eax, 0
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
    // 004e8f57  0fb680b8785600         -movzx eax, byte ptr [eax + 0x5678b8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5667000) /* 0x5678b8 */));
    // 004e8f5e  2effa3718f4e00         -jmp dword ptr cs:[ebx + 0x4e8f71]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 5148529); goto dynamic_jump;
L_0x004e8f65:
    // 004e8f65  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 004e8f6a  2effa3718f4e00         -jmp dword ptr cs:[ebx + 0x4e8f71]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 5148529); goto dynamic_jump;
  case 0x004e8f91:
    // 004e8f91  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004e8f93  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
  [[fallthrough]];
  case 0x004e8f98:
    // 004e8f98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8f9a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8f9b:
    // 004e8f9b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004e8f9d  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004e8fa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fa3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fa4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8fa5:
    // 004e8fa5  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004e8faa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fac  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8fad:
    // 004e8fad  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004e8faf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fb1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8fb2:
    // 004e8fb2  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004e8fb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fb9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8fba:
    // 004e8fba  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004e8fbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fc1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004e8fc2:
    // 004e8fc2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004e8fc4  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004e8fc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fcb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4e8fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e8fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e8fd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e8fd3  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e8fda  7507                   -jne 0x4e8fe3
    if (!cpu.flags.zf)
    {
        goto L_0x004e8fe3;
    }
    // 004e8fdc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e8fe1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8fe2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8fe3:
    // 004e8fe3  e8387e0100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e8fe8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e8fea  e8ad6c0100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e8fef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e8ff1  7c0b                   -jl 0x4e8ffe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e8ffe;
    }
    // 004e8ff3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e8ff5  e8827e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e8ffa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e8ffc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e8ffd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e8ffe:
    // 004e8ffe  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e9003  e8747e0100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9008  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e900a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e900b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4e9010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9011  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e9013:
    // 004e9013  8b823c9ba000           -mov eax, dword ptr [edx + 0xa09b3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10525500) /* 0xa09b3c */);
    // 004e9019  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e901c  e84f060000             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 004e9021  81fa00060000           +cmp edx, 0x600
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9027  75ea                   -jne 0x4e9013
    if (!cpu.flags.zf)
    {
        goto L_0x004e9013;
    }
    // 004e9029  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e902a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9033  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9034  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9037  7f2c                   -jg 0x4e9065
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e9065;
    }
    // 004e9039  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e903c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004e903e  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004e9041  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e9043  39d8                   +cmp eax, ebx
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
    // 004e9045  7c1e                   -jl 0x4e9065
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9065;
    }
    // 004e9047  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004e904a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004e904c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004e904f  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004e9052  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e9054  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004e9057  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9059  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004e905b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e905d  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004e9060  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9062  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9063  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9064  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9065:
    // 004e9065  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e906a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e906b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e906c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e906d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e906e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e9070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9071  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004e9075  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e9078  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e907b  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004e9082  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004e9084  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e9088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9088  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9089  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e908a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e908b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e908d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e908f  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e9092  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e9098  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e909b  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 004e909e  0f8475000000           -je 0x4e9119
    if (cpu.flags.zf)
    {
        goto L_0x004e9119;
    }
    // 004e90a4  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004e90a8  742f                   -je 0x4e90d9
    if (cpu.flags.zf)
    {
        goto L_0x004e90d9;
    }
    // 004e90aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e90ac  e8af960100             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 004e90b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e90b3  743b                   -je 0x4e90f0
    if (cpu.flags.zf)
    {
        goto L_0x004e90f0;
    }
    // 004e90b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e90b7  750e                   -jne 0x4e90c7
    if (!cpu.flags.zf)
    {
        goto L_0x004e90c7;
    }
    // 004e90b9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e90bb  7d0a                   -jge 0x4e90c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e90c7;
    }
L_0x004e90bd:
    // 004e90bd  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004e90c2  e8b9970100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
L_0x004e90c7:
    // 004e90c7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e90ca  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e90d0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e90d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e90d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e90d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e90d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e90d9:
    // 004e90d9  83fb01                 +cmp ebx, 1
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
    // 004e90dc  7503                   -jne 0x4e90e1
    if (!cpu.flags.zf)
    {
        goto L_0x004e90e1;
    }
    // 004e90de  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x004e90e1:
    // 004e90e1  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e90e4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e90e7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004e90ee  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004e90f0:
    // 004e90f0  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 004e90f4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e90f6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e90f9  e8e2970100             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
    // 004e90fe  83f8ff                 +cmp eax, -1
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
    // 004e9101  0f85e4000000           -jne 0x4e91eb
    if (!cpu.flags.zf)
    {
        goto L_0x004e91eb;
    }
    // 004e9107  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e910a  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e9110  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e9115  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9116  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9117  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9118  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9119:
    // 004e9119  83fb01                 +cmp ebx, 1
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
    // 004e911c  720d                   -jb 0x4e912b
    if (cpu.flags.cf)
    {
        goto L_0x004e912b;
    }
    // 004e911e  7611                   -jbe 0x4e9131
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e9131;
    }
    // 004e9120  83fb02                 +cmp ebx, 2
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
    // 004e9123  0f848a000000           -je 0x4e91b3
    if (cpu.flags.zf)
    {
        goto L_0x004e91b3;
    }
    // 004e9129  eb92                   -jmp 0x4e90bd
    goto L_0x004e90bd;
L_0x004e912b:
    // 004e912b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e912d  7445                   -je 0x4e9174
    if (cpu.flags.zf)
    {
        goto L_0x004e9174;
    }
    // 004e912f  eb8c                   -jmp 0x4e90bd
    goto L_0x004e90bd;
L_0x004e9131:
    // 004e9131  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e9133  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9135  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004e9138  e8f3feffff             -call 0x4e9030
    cpu.esp -= 4;
    sub_4e9030(app, cpu);
    if (cpu.terminate) return;
    // 004e913d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e913f  0f84a6000000           -je 0x4e91eb
    if (cpu.flags.zf)
    {
        goto L_0x004e91eb;
    }
    // 004e9145  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e9147  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e914a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004e914c  e88f970100             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
    // 004e9151  83f8ff                 +cmp eax, -1
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
    // 004e9154  7512                   -jne 0x4e9168
    if (!cpu.flags.zf)
    {
        goto L_0x004e9168;
    }
    // 004e9156  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e9159  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e915f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e9164  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9165  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9166  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9167  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9168:
    // 004e9168  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e916a  e801ffffff             -call 0x4e9070
    cpu.esp -= 4;
    sub_4e9070(app, cpu);
    if (cpu.terminate) return;
    // 004e916f  e977000000             -jmp 0x4e91eb
    goto L_0x004e91eb;
L_0x004e9174:
    // 004e9174  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e9177  e8e4970100             -call 0x502960
    cpu.esp -= 4;
    sub_502960(app, cpu);
    if (cpu.terminate) return;
    // 004e917c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004e917f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e9181  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9183  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9185  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e9187  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e9189  e8a2feffff             -call 0x4e9030
    cpu.esp -= 4;
    sub_4e9030(app, cpu);
    if (cpu.terminate) return;
    // 004e918e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9190  7459                   -je 0x4e91eb
    if (cpu.flags.zf)
    {
        goto L_0x004e91eb;
    }
    // 004e9192  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e9194  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e9197  e844970100             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
    // 004e919c  83f8ff                 +cmp eax, -1
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
    // 004e919f  75c7                   -jne 0x4e9168
    if (!cpu.flags.zf)
    {
        goto L_0x004e9168;
    }
    // 004e91a1  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e91a4  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e91aa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e91af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e91b3:
    // 004e91b3  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004e91b5  80e2ef                 -and dl, 0xef
    cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004e91b8  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e91bb  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004e91be  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e91c1  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004e91c3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e91c5  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e91c8  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004e91cf  e80c970100             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
    // 004e91d4  83f8ff                 +cmp eax, -1
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
    // 004e91d7  7512                   -jne 0x4e91eb
    if (!cpu.flags.zf)
    {
        goto L_0x004e91eb;
    }
    // 004e91d9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e91dc  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e91e2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e91e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e91eb:
    // 004e91eb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e91ee  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e91f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e91f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e91f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9200  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9202  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9203  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e9206  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e9209  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004e920d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004e920f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e9212  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e9218  f6410c01               +test byte ptr [ecx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004e921c  7523                   -jne 0x4e9241
    if (!cpu.flags.zf)
    {
        goto L_0x004e9241;
    }
    // 004e921e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004e9223  e858960100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004e9228  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e922b  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004e922e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e9231  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 004e9234  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e923a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e923c  e9c9010000             -jmp 0x4e940a
    goto L_0x004e940a;
L_0x004e9241:
    // 004e9241  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004e9244  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e9246  7512                   -jne 0x4e925a
    if (!cpu.flags.zf)
    {
        goto L_0x004e925a;
    }
    // 004e9248  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e924b  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e9251  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9253  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e9256  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9257  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9258  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e925a:
    // 004e925a  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e925d  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004e9261  7507                   -jne 0x4e926a
    if (!cpu.flags.zf)
    {
        goto L_0x004e926a;
    }
    // 004e9263  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e9265  e856970100             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004e926a:
    // 004e926a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e926c  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004e926f  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004e9273  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 004e9276  0f84fc000000           -je 0x4e9378
    if (cpu.flags.zf)
    {
        goto L_0x004e9378;
    }
    // 004e927c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004e9280:
    // 004e9280  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004e9283  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9285  7452                   -je 0x4e92d9
    if (cpu.flags.zf)
    {
        goto L_0x004e92d9;
    }
    // 004e9287  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e928b  39da                   +cmp edx, ebx
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
    // 004e928d  7602                   -jbe 0x4e9291
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e9291;
    }
    // 004e928f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004e9291:
    // 004e9291  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004e9294  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e9296  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004e9299  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e929d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e929e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e92a0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e92a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e92a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e92a5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004e92a8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e92aa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004e92ac  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004e92af  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004e92b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e92b2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e92b3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e92b7  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004e92ba  8d3417                 -lea esi, [edi + edx]
    cpu.esi = x86::reg32(cpu.edi + cpu.edx * 1);
    // 004e92bd  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e92bf  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004e92c2  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e92c6  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004e92c9  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e92cb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e92cd  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e92cf  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004e92d2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e92d6  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x004e92d9:
    // 004e92d9  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e92dd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e92df  0f8410010000           -je 0x4e93f5
    if (cpu.flags.zf)
    {
        goto L_0x004e93f5;
    }
    // 004e92e5  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e92e8  730a                   -jae 0x4e92f4
    if (!cpu.flags.cf)
    {
        goto L_0x004e92f4;
    }
    // 004e92ea  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004e92ee  0f8470000000           -je 0x4e9364
    if (cpu.flags.zf)
    {
        goto L_0x004e9364;
    }
L_0x004e92f4:
    // 004e92f4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004e92f7  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e92fa  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004e9301  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e9305  8a4d0d                 -mov cl, byte ptr [ebp + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004e9308  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004e930b  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004e930e  750d                   -jne 0x4e931d
    if (!cpu.flags.zf)
    {
        goto L_0x004e931d;
    }
    // 004e9310  81fb00020000           +cmp ebx, 0x200
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
    // 004e9316  7605                   -jbe 0x4e931d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e931d;
    }
    // 004e9318  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e931a  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004e931d:
    // 004e931d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e9320  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004e9323  e828970100             -call 0x502a50
    cpu.esp -= 4;
    sub_502a50(app, cpu);
    if (cpu.terminate) return;
    // 004e9328  83f8ff                 +cmp eax, -1
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
    // 004e932b  7509                   -jne 0x4e9336
    if (!cpu.flags.zf)
    {
        goto L_0x004e9336;
    }
    // 004e932d  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004e9331  e9bf000000             -jmp 0x4e93f5
    goto L_0x004e93f5;
L_0x004e9336:
    // 004e9336  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9338  7509                   -jne 0x4e9343
    if (!cpu.flags.zf)
    {
        goto L_0x004e9343;
    }
    // 004e933a  804d0c10               +or byte ptr [ebp + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004e933e  e9b2000000             -jmp 0x4e93f5
    goto L_0x004e93f5;
L_0x004e9343:
    // 004e9343  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e9346  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e934a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e934e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e9350  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9352  01c1                   +add ecx, eax
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
    // 004e9354  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004e9357  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e935b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004e935f  e91cffffff             -jmp 0x4e9280
    goto L_0x004e9280;
L_0x004e9364:
    // 004e9364  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e9366  e87d980100             -call 0x502be8
    cpu.esp -= 4;
    sub_502be8(app, cpu);
    if (cpu.terminate) return;
    // 004e936b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e936d  0f8482000000           -je 0x4e93f5
    if (cpu.flags.zf)
    {
        goto L_0x004e93f5;
    }
    // 004e9373  e908ffffff             -jmp 0x4e9280
    goto L_0x004e9280;
L_0x004e9378:
    // 004e9378  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e937b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e937d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e937f  b1ff                   -mov cl, 0xff
    cpu.cl = 255 /*0xff*/;
    // 004e9381  31d7                   -xor edi, edx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e9383:
    // 004e9383  3b7d04                 +cmp edi, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9386  750b                   -jne 0x4e9393
    if (!cpu.flags.zf)
    {
        goto L_0x004e9393;
    }
    // 004e9388  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e938a  e859980100             -call 0x502be8
    cpu.esp -= 4;
    sub_502be8(app, cpu);
    if (cpu.terminate) return;
    // 004e938f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9391  7462                   -je 0x4e93f5
    if (cpu.flags.zf)
    {
        goto L_0x004e93f5;
    }
L_0x004e9393:
    // 004e9393  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004e9396  4e                     -dec esi
    (cpu.esi)--;
    // 004e9397  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004e939a  897504                 -mov dword ptr [ebp + 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004e939d  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e93a0  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 004e93a3  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004e93a5  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 004e93a7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e93ac  83f80d                 +cmp eax, 0xd
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
    // 004e93af  7529                   -jne 0x4e93da
    if (!cpu.flags.zf)
    {
        goto L_0x004e93da;
    }
    // 004e93b1  3b7d04                 +cmp edi, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e93b4  750b                   -jne 0x4e93c1
    if (!cpu.flags.zf)
    {
        goto L_0x004e93c1;
    }
    // 004e93b6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e93b8  e82b980100             -call 0x502be8
    cpu.esp -= 4;
    sub_502be8(app, cpu);
    if (cpu.terminate) return;
    // 004e93bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e93bf  7434                   -je 0x4e93f5
    if (cpu.flags.zf)
    {
        goto L_0x004e93f5;
    }
L_0x004e93c1:
    // 004e93c1  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004e93c4  4e                     -dec esi
    (cpu.esi)--;
    // 004e93c5  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004e93c8  897504                 -mov dword ptr [ebp + 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004e93cb  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e93ce  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 004e93d1  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004e93d3  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 004e93d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004e93da:
    // 004e93da  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e93dd  7506                   -jne 0x4e93e5
    if (!cpu.flags.zf)
    {
        goto L_0x004e93e5;
    }
    // 004e93df  804d0c10               +or byte ptr [ebp + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004e93e3  eb10                   -jmp 0x4e93f5
    goto L_0x004e93f5;
L_0x004e93e5:
    // 004e93e5  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004e93e7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e93eb  40                     -inc eax
    (cpu.eax)++;
    // 004e93ec  42                     -inc edx
    (cpu.edx)++;
    // 004e93ed  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e93f1  39da                   +cmp edx, ebx
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
    // 004e93f3  758e                   -jne 0x4e9383
    if (!cpu.flags.zf)
    {
        goto L_0x004e9383;
    }
L_0x004e93f5:
    // 004e93f5  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004e93f8  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e93fc  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e9402  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9404  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e9408  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004e940a:
    // 004e940a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e940d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e940e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e940f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9410  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9424  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9426  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e9428  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e942f  0f84c1000000           -je 0x4e94f6
    if (cpu.flags.zf)
    {
        goto L_0x004e94f6;
    }
    // 004e9435  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9438  7f05                   -jg 0x4e943f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e943f;
    }
    // 004e943a  83fbff                 +cmp ebx, -1
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
    // 004e943d  7d2f                   -jge 0x4e946e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e946e;
    }
L_0x004e943f:
    // 004e943f  ba78b25400             -mov edx, 0x54b278
    cpu.edx = 5550712 /*0x54b278*/;
    // 004e9444  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9445  bf88b25400             -mov edi, 0x54b288
    cpu.edi = 5550728 /*0x54b288*/;
    // 004e944a  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004e944f  6894b25400             -push 0x54b294
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550740 /*0x54b294*/;
    cpu.esp -= 4;
    // 004e9454  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e945a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e9460  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e9466  e8a57bf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e946b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e946e:
    // 004e946e  e8ad790100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e9473  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9475  e822680100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e947a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e947c  0f8c80000000           -jl 0x4e9502
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9502;
    }
    // 004e9482  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004e9489  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e948b  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e9490  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e9493  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e9495  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e9497  0f8e76000000           -jle 0x4e9513
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9513;
    }
L_0x004e949d:
    // 004e949d  0fb6793b               -movzx edi, byte ptr [ecx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */));
    // 004e94a1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e94a3  0f8471000000           -je 0x4e951a
    if (cpu.flags.zf)
    {
        goto L_0x004e951a;
    }
    // 004e94a9  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e94ae  8da900060000           -lea ebp, [ecx + 0x600]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
L_0x004e94b4:
    // 004e94b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e94b6  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004e94b9  39fa                   +cmp edx, edi
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
    // 004e94bb  7524                   -jne 0x4e94e1
    if (!cpu.flags.zf)
    {
        goto L_0x004e94e1;
    }
    // 004e94bd  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004e94c1  751e                   -jne 0x4e94e1
    if (!cpu.flags.zf)
    {
        goto L_0x004e94e1;
    }
    // 004e94c3  833900                 +cmp dword ptr [ecx], 0
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
    // 004e94c6  7c19                   -jl 0x4e94e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e94e1;
    }
    // 004e94c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e94ca  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e94cd  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004e94d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e94d2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004e94d5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e94d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e94d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e94dc  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e94de  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004e94e1:
    // 004e94e1  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e94e4  39e9                   +cmp ecx, ebp
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
    // 004e94e6  75cc                   -jne 0x4e94b4
    if (!cpu.flags.zf)
    {
        goto L_0x004e94b4;
    }
    // 004e94e8  e88f790100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e94ed  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e94ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e94f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e94f6:
    // 004e94f6  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 004e94fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e94fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e94ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9500  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9501  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9502:
    // 004e9502  e875790100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9507  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 004e950c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e950e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e950f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9511  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9512  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9513:
    // 004e9513  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004e9518  eb83                   -jmp 0x4e949d
    goto L_0x004e949d;
L_0x004e951a:
    // 004e951a  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004e951d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004e9520  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e9522  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9524  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9526  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e9529  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e952b  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e952e  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004e9531  e846790100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9536  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9538  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e953a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e953b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e953c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e953d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e953e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4e9540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9541  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9542  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9543  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e9545  e852670100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e954a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e954c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e954e  0f8c75000000           -jl 0x4e95c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e95c9;
    }
    // 004e9554  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004e955b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e955d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e9560  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9562  81c23c9ba000           -add edx, 0xa09b3c
    (cpu.edx) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004e9568  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e956b  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004e956e  39d8                   +cmp eax, ebx
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
    // 004e9570  7460                   -je 0x4e95d2
    if (cpu.flags.zf)
    {
        goto L_0x004e95d2;
    }
    // 004e9572  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9573  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 004e9577  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e9579  745d                   -je 0x4e95d8
    if (cpu.flags.zf)
    {
        goto L_0x004e95d8;
    }
    // 004e957b  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e9580  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004e9582:
    // 004e9582  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9584  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004e9587  39fa                   +cmp edx, edi
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
    // 004e9589  752e                   -jne 0x4e95b9
    if (!cpu.flags.zf)
    {
        goto L_0x004e95b9;
    }
    // 004e958b  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004e958f  7528                   -jne 0x4e95b9
    if (!cpu.flags.zf)
    {
        goto L_0x004e95b9;
    }
    // 004e9591  833900                 +cmp dword ptr [ecx], 0
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
    // 004e9594  7c23                   -jl 0x4e95b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e95b9;
    }
    // 004e9596  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9598  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e959b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004e959e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e95a0  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004e95a7  e8f47e0100             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 004e95ac  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004e95af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e95b1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e95b4  e8877f0100             -call 0x501540
    cpu.esp -= 4;
    sub_501540(app, cpu);
    if (cpu.terminate) return;
L_0x004e95b9:
    // 004e95b9  43                     -inc ebx
    (cpu.ebx)++;
    // 004e95ba  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e95bd  83fb10                 +cmp ebx, 0x10
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
    // 004e95c0  7cc0                   -jl 0x4e9582
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9582;
    }
    // 004e95c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e95c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e95c9:
    // 004e95c9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e95ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e95d2:
    // 004e95d2  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e95d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e95d8:
    // 004e95d8  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004e95db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e95dd  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004e95e0  e8bb7e0100             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 004e95e5  8b522e                 -mov edx, dword ptr [edx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 004e95e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e95ea  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e95ed  e84e7f0100             -call 0x501540
    cpu.esp -= 4;
    sub_501540(app, cpu);
    if (cpu.terminate) return;
    // 004e95f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e95f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e95f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e95fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e95fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e95fd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e95ff  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9606  7455                   -je 0x4e965d
    if (cpu.flags.zf)
    {
        goto L_0x004e965d;
    }
    // 004e9608  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e960b  7f04                   -jg 0x4e9611
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e9611;
    }
    // 004e960d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e960f  7d35                   -jge 0x4e9646
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e9646;
    }
L_0x004e9611:
    // 004e9611  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9612  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9613  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9614  bbc0b25400             -mov ebx, 0x54b2c0
    cpu.ebx = 5550784 /*0x54b2c0*/;
    // 004e9619  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e961a  beccb25400             -mov esi, 0x54b2cc
    cpu.esi = 5550796 /*0x54b2cc*/;
    // 004e961f  bf7b000000             -mov edi, 0x7b
    cpu.edi = 123 /*0x7b*/;
    // 004e9624  68d4b25400             -push 0x54b2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550804 /*0x54b2d4*/;
    cpu.esp -= 4;
    // 004e9629  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e962f  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e9635  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e963b  e8d079f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9640  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e9643  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9644  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9645  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e9646:
    // 004e9646  e8d5770100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e964b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e964d  e8eefeffff             -call 0x4e9540
    cpu.esp -= 4;
    sub_4e9540(app, cpu);
    if (cpu.terminate) return;
    // 004e9652  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e9654  e823780100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9659  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e965b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e965c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e965d:
    // 004e965d  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e9662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9663  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9670  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9671  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e9674  8a25f49aa000           -mov ah, byte ptr [0xa09af4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
    // 004e967a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e967c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004e967e  750a                   -jne 0x4e968a
    if (!cpu.flags.zf)
    {
        goto L_0x004e968a;
    }
    // 004e9680  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 004e9685  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9687  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9688  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9689  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e968a:
    // 004e968a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e968b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e968c  e88f770100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e9691  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9693  e804660100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e9698  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e969a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e969c  7c56                   -jl 0x4e96f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e96f4;
    }
    // 004e969e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e96a1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e96a3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e96a6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e96a8  8a98779ba000           -mov bl, byte ptr [eax + 0xa09b77]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525559) /* 0xa09b77 */);
    // 004e96ae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e96b0  7439                   -je 0x4e96eb
    if (cpu.flags.zf)
    {
        goto L_0x004e96eb;
    }
    // 004e96b2  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e96b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e96b9:
    // 004e96b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e96bb  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004e96be  39d8                   +cmp eax, ebx
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
    // 004e96c0  7512                   -jne 0x4e96d4
    if (!cpu.flags.zf)
    {
        goto L_0x004e96d4;
    }
    // 004e96c2  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004e96c6  750c                   -jne 0x4e96d4
    if (!cpu.flags.zf)
    {
        goto L_0x004e96d4;
    }
    // 004e96c8  833900                 +cmp dword ptr [ecx], 0
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
    // 004e96cb  7c07                   -jl 0x4e96d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e96d4;
    }
    // 004e96cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e96cf  e8ec8effff             -call 0x4e25c0
    cpu.esp -= 4;
    sub_4e25c0(app, cpu);
    if (cpu.terminate) return;
L_0x004e96d4:
    // 004e96d4  42                     -inc edx
    (cpu.edx)++;
    // 004e96d5  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e96d8  83fa10                 +cmp edx, 0x10
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
    // 004e96db  7cdc                   -jl 0x4e96b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e96b9;
    }
L_0x004e96dd:
    // 004e96dd  e89a770100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e96e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e96e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e96e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e96e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e96e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e96e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e96ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e96eb:
    // 004e96eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e96ed  e8ce8effff             -call 0x4e25c0
    cpu.esp -= 4;
    sub_4e25c0(app, cpu);
    if (cpu.terminate) return;
    // 004e96f2  ebe9                   -jmp 0x4e96dd
    goto L_0x004e96dd;
L_0x004e96f4:
    // 004e96f4  bef8ffffff             -mov esi, 0xfffffff8
    cpu.esi = 4294967288 /*0xfffffff8*/;
    // 004e96f9  e87e770100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e96fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e9700  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9702  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9704  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9705  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9706  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9713  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9714  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9717  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004e971a  e87d650100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e971f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9721  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9723  7c5a                   -jl 0x4e977f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e977f;
    }
    // 004e9725  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004e972c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e972e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e9731  81c23c9ba000           -add edx, 0xa09b3c
    (cpu.edx) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004e9737  0fb6723b               -movzx esi, byte ptr [edx + 0x3b]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 004e973b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e973d  0f8466000000           -je 0x4e97a9
    if (cpu.flags.zf)
    {
        goto L_0x004e97a9;
    }
    // 004e9743  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e9748  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e974b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004e974d:
    // 004e974d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e974f  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004e9752  39f2                   +cmp edx, esi
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
    // 004e9754  7514                   -jne 0x4e976a
    if (!cpu.flags.zf)
    {
        goto L_0x004e976a;
    }
    // 004e9756  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004e975a  750e                   -jne 0x4e976a
    if (!cpu.flags.zf)
    {
        goto L_0x004e976a;
    }
    // 004e975c  833900                 +cmp dword ptr [ecx], 0
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
    // 004e975f  7c09                   -jl 0x4e976a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e976a;
    }
    // 004e9761  31f2                   -xor edx, esi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e9763  8a5133                 -mov dl, byte ptr [ecx + 0x33]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */);
    // 004e9766  39ea                   +cmp edx, ebp
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9768  751c                   -jne 0x4e9786
    if (!cpu.flags.zf)
    {
        goto L_0x004e9786;
    }
L_0x004e976a:
    // 004e976a  43                     -inc ebx
    (cpu.ebx)++;
    // 004e976b  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e976e  83fb10                 +cmp ebx, 0x10
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
    // 004e9771  7cda                   -jl 0x4e974d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e974d;
    }
L_0x004e9773:
    // 004e9773  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e9775:
    // 004e9775  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9777  83c404                 +add esp, 4
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
    // 004e977a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e977b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e977c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e977d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e977e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e977f:
    // 004e977f  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 004e9784  ebef                   -jmp 0x4e9775
    goto L_0x004e9775;
L_0x004e9786:
    // 004e9786  6683794200             +cmp word ptr [ecx + 0x42], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e978b  74dd                   -je 0x4e976a
    if (cpu.flags.zf)
    {
        goto L_0x004e976a;
    }
    // 004e978d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004e9790  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004e9793  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9795  e816950100             -call 0x502cb0
    cpu.esp -= 4;
    sub_502cb0(app, cpu);
    if (cpu.terminate) return;
    // 004e979a  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e979d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e979f  c1fa10                 +sar edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004e97a2  e889950100             -call 0x502d30
    cpu.esp -= 4;
    sub_502d30(app, cpu);
    if (cpu.terminate) return;
    // 004e97a7  ebc1                   -jmp 0x4e976a
    goto L_0x004e976a;
L_0x004e97a9:
    // 004e97a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e97ab  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e97ae  8a4233                 -mov al, byte ptr [edx + 0x33]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */);
    // 004e97b1  39d8                   +cmp eax, ebx
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
    // 004e97b3  74be                   -je 0x4e9773
    if (cpu.flags.zf)
    {
        goto L_0x004e9773;
    }
    // 004e97b5  66837a4200             +cmp word ptr [edx + 0x42], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e97ba  74b7                   -je 0x4e9773
    if (cpu.flags.zf)
    {
        goto L_0x004e9773;
    }
    // 004e97bc  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004e97bf  884233                 -mov byte ptr [edx + 0x33], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004e97c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e97c4  e8e7940100             -call 0x502cb0
    cpu.esp -= 4;
    sub_502cb0(app, cpu);
    if (cpu.terminate) return;
    // 004e97c9  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e97cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e97ce  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004e97d1  e85a950100             -call 0x502d30
    cpu.esp -= 4;
    sub_502d30(app, cpu);
    if (cpu.terminate) return;
    // 004e97d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e97d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e97da  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e97dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e97de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e97df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e97e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e97e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e97e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e97e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e97e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e97e7  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e97ee  7454                   -je 0x4e9844
    if (cpu.flags.zf)
    {
        goto L_0x004e9844;
    }
    // 004e97f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e97f2  7c05                   -jl 0x4e97f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e97f9;
    }
    // 004e97f4  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e97f7  7e34                   -jle 0x4e982d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e982d;
    }
L_0x004e97f9:
    // 004e97f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e97fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e97fb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e97fc  bbfcb25400             -mov ebx, 0x54b2fc
    cpu.ebx = 5550844 /*0x54b2fc*/;
    // 004e9801  be08b35400             -mov esi, 0x54b308
    cpu.esi = 5550856 /*0x54b308*/;
    // 004e9806  bf78000000             -mov edi, 0x78
    cpu.edi = 120 /*0x78*/;
    // 004e980b  6818b35400             -push 0x54b318
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550872 /*0x54b318*/;
    cpu.esp -= 4;
    // 004e9810  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e9816  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e981c  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e9822  e8e977f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9827  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e982a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e982b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e982c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e982d:
    // 004e982d  e8ee750100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e9832  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9834  e8d7feffff             -call 0x4e9710
    cpu.esp -= 4;
    sub_4e9710(app, cpu);
    if (cpu.terminate) return;
    // 004e9839  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e983b  e83c760100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9840  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9842  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9843  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9844:
    // 004e9844  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e9849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e984a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9851  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9852  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9853  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9856  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9858  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e985a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e985c  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9863  0f848f000000           -je 0x4e98f8
    if (cpu.flags.zf)
    {
        goto L_0x004e98f8;
    }
    // 004e9869  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e986f  81fbff3f0000           +cmp ebx, 0x3fff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16383 /*0x3fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9875  0f8e89000000           -jle 0x4e9904
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9904;
    }
    // 004e987b  bfff3f0000             -mov edi, 0x3fff
    cpu.edi = 16383 /*0x3fff*/;
L_0x004e9880:
    // 004e9880  e89b750100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e9885  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9887  e810640100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e988c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e988e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9890  0f8c84000000           -jl 0x4e991a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e991a;
    }
    // 004e9896  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9897  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e989a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e989c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e989f  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004e98a4  8a403b                 -mov al, byte ptr [eax + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004e98a7  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004e98ac  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004e98b0  0f8475000000           -je 0x4e992b
    if (cpu.flags.zf)
    {
        goto L_0x004e992b;
    }
    // 004e98b6  be3c9ba000             -mov esi, 0xa09b3c
    cpu.esi = 10525500 /*0xa09b3c*/;
    // 004e98bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e98bd:
    // 004e98bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e98bf  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e98c3  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 004e98c6  39d8                   +cmp eax, ebx
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
    // 004e98c8  7516                   -jne 0x4e98e0
    if (!cpu.flags.zf)
    {
        goto L_0x004e98e0;
    }
    // 004e98ca  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e98ce  7510                   -jne 0x4e98e0
    if (!cpu.flags.zf)
    {
        goto L_0x004e98e0;
    }
    // 004e98d0  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e98d3  7c0b                   -jl 0x4e98e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e98e0;
    }
    // 004e98d5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004e98d7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e98d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e98db  e810950100             -call 0x502df0
    cpu.esp -= 4;
    sub_502df0(app, cpu);
    if (cpu.terminate) return;
L_0x004e98e0:
    // 004e98e0  41                     -inc ecx
    (cpu.ecx)++;
    // 004e98e1  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e98e4  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e98e7  7cd4                   -jl 0x4e98bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e98bd;
    }
    // 004e98e9  e88e750100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e98ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e98f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e98f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e98f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e98f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e98f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e98f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e98f8:
    // 004e98f8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e98fd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9900  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9901  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9902  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9904:
    // 004e9904  81fb00c0ffff           +cmp ebx, 0xffffc000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294950912 /*0xffffc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e990a  0f8d70ffffff           -jge 0x4e9880
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e9880;
    }
    // 004e9910  bf00c0ffff             -mov edi, 0xffffc000
    cpu.edi = 4294950912 /*0xffffc000*/;
    // 004e9915  e966ffffff             -jmp 0x4e9880
    goto L_0x004e9880;
L_0x004e991a:
    // 004e991a  e85d750100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e991f  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e9924  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9927  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9928  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9929  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e992a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e992b:
    // 004e992b  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004e992d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e992f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9931  e8ba940100             -call 0x502df0
    cpu.esp -= 4;
    sub_502df0(app, cpu);
    if (cpu.terminate) return;
    // 004e9936  e841750100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e993b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e993d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e993e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9941  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9942  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9943  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9944  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9952  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9953  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9954  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9955  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e9958  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e995a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004e995e  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9965  0f8408010000           -je 0x4e9a73
    if (cpu.flags.zf)
    {
        goto L_0x004e9a73;
    }
    // 004e996b  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e996e  7f04                   -jg 0x4e9974
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e9974;
    }
    // 004e9970  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9972  7d33                   -jge 0x4e99a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e99a7;
    }
L_0x004e9974:
    // 004e9974  be58b35400             -mov esi, 0x54b358
    cpu.esi = 5550936 /*0x54b358*/;
    // 004e9979  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e997d  bf64b35400             -mov edi, 0x54b364
    cpu.edi = 5550948 /*0x54b364*/;
    // 004e9982  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e9983  bd47000000             -mov ebp, 0x47
    cpu.ebp = 71 /*0x47*/;
    // 004e9988  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e998e  686cb35400             -push 0x54b36c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5550956 /*0x54b36c*/;
    cpu.esp -= 4;
    // 004e9993  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e9999  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e999f  e86c76f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e99a4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e99a7:
    // 004e99a7  e874740100             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004e99ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e99ae  e8e9620100             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 004e99b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e99b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e99b7  0f8cbd000000           -jl 0x4e9a7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9a7a;
    }
    // 004e99bd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e99c0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e99c2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e99c5  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004e99ca  8b5042                 -mov edx, dword ptr [eax + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 004e99cd  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e99d1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e99d4  39da                   +cmp edx, ebx
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
    // 004e99d6  0f84aa000000           -je 0x4e9a86
    if (cpu.flags.zf)
    {
        goto L_0x004e9a86;
    }
    // 004e99dc  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e99e0  0fb6783b               -movzx edi, byte ptr [eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */));
    // 004e99e4  885045                 -mov byte ptr [eax + 0x45], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(69) /* 0x45 */) = cpu.dl;
    // 004e99e7  8d53c0                 -lea edx, [ebx - 0x40]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-64) /* -0x40 */);
    // 004e99ea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e99ec  0f84a5000000           -je 0x4e9a97
    if (cpu.flags.zf)
    {
        goto L_0x004e9a97;
    }
    // 004e99f2  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 004e99f7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004e99fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e99fc  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004e99fe:
    // 004e99fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9a00  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004e9a03  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004e9a05  39f8                   +cmp eax, edi
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
    // 004e9a07  754f                   -jne 0x4e9a58
    if (!cpu.flags.zf)
    {
        goto L_0x004e9a58;
    }
    // 004e9a09  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004e9a0d  7549                   -jne 0x4e9a58
    if (!cpu.flags.zf)
    {
        goto L_0x004e9a58;
    }
    // 004e9a0f  3b29                   +cmp ebp, dword ptr [ecx]
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
    // 004e9a11  7f45                   -jg 0x4e9a58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e9a58;
    }
    // 004e9a13  8a6137                 -mov ah, byte ptr [ecx + 0x37]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */);
    // 004e9a16  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e9a1a  80fc01                 +cmp ah, 1
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
    // 004e9a1d  740f                   -je 0x4e9a2e
    if (cpu.flags.zf)
    {
        goto L_0x004e9a2e;
    }
    // 004e9a1f  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004e9a22  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e9a25  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e9a28  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004e9a2b  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x004e9a2e:
    // 004e9a2e  8b462f                 -mov eax, dword ptr [esi + 0x2f]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(47) /* 0x2f */);
    // 004e9a31  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004e9a34  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e9a36  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004e9a39  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9a3c  7e51                   -jle 0x4e9a8f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9a8f;
    }
    // 004e9a3e  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x004e9a43:
    // 004e9a43  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004e9a46  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9a48  7404                   -je 0x4e9a4e
    if (cpu.flags.zf)
    {
        goto L_0x004e9a4e;
    }
    // 004e9a4a  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
L_0x004e9a4e:
    // 004e9a4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9a50  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 004e9a53  e898940100             -call 0x502ef0
    cpu.esp -= 4;
    sub_502ef0(app, cpu);
    if (cpu.terminate) return;
L_0x004e9a58:
    // 004e9a58  43                     -inc ebx
    (cpu.ebx)++;
    // 004e9a59  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e9a5c  83fb10                 +cmp ebx, 0x10
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
    // 004e9a5f  7c9d                   -jl 0x4e99fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e99fe;
    }
    // 004e9a61  e816740100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9a66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e9a68:
    // 004e9a68  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9a6a  83c408                 +add esp, 8
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
    // 004e9a6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9a6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9a6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9a70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9a71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9a72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9a73:
    // 004e9a73  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 004e9a78  ebee                   -jmp 0x4e9a68
    goto L_0x004e9a68;
L_0x004e9a7a:
    // 004e9a7a  e8fd730100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9a7f  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 004e9a84  ebe2                   -jmp 0x4e9a68
    goto L_0x004e9a68;
L_0x004e9a86:
    // 004e9a86  e8f1730100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9a8b  31da                   +xor edx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004e9a8d  ebd9                   -jmp 0x4e9a68
    goto L_0x004e9a68;
L_0x004e9a8f:
    // 004e9a8f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9a91  7db0                   -jge 0x4e9a43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e9a43;
    }
    // 004e9a93  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e9a95  ebac                   -jmp 0x4e9a43
    goto L_0x004e9a43;
L_0x004e9a97:
    // 004e9a97  80783701               +cmp byte ptr [eax + 0x37], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(55) /* 0x37 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9a9b  7410                   -je 0x4e9aad
    if (cpu.flags.zf)
    {
        goto L_0x004e9aad;
    }
    // 004e9a9d  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004e9aa0  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004e9aa3  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004e9aa6  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004e9aa9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004e9aad:
    // 004e9aad  8b502f                 -mov edx, dword ptr [eax + 0x2f]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 004e9ab0  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e9ab4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e9ab7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e9ab9  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004e9abc  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004e9ac0  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9ac3  7e41                   -jle 0x4e9b06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9b06;
    }
    // 004e9ac5  c74424047f000000       -mov dword ptr [esp + 4], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 127 /*0x7f*/;
L_0x004e9acd:
    // 004e9acd  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004e9ad0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e9ad2  740e                   -je 0x4e9ae2
    if (cpu.flags.zf)
    {
        goto L_0x004e9ae2;
    }
    // 004e9ad4  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e9ad8  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004e9adb  0fbe12                 -movsx edx, byte ptr [edx]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 004e9ade  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004e9ae2:
    // 004e9ae2  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e9ae6  88500f                 -mov byte ptr [eax + 0xf], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 004e9ae9  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e9aed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9aef  e8fc930100             -call 0x502ef0
    cpu.esp -= 4;
    sub_502ef0(app, cpu);
    if (cpu.terminate) return;
    // 004e9af4  e883730100             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004e9af9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9afb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9afd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e9b00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9b06:
    // 004e9b06  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9b08  7dc3                   -jge 0x4e9acd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e9acd;
    }
    // 004e9b0a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e9b0c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004e9b10  ebbb                   -jmp 0x4e9acd
    goto L_0x004e9acd;
}

}
