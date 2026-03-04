#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f9470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9470  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9472  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f9478  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f947e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004f9480  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f9482(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9482  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004f9484  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f9486  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004f9488  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004f948a  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004f948c  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004f948e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9490  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9491  750f                   -jne 0x4f94a2
    if (!cpu.flags.zf)
    {
        goto L_0x004f94a2;
    }
    // 004f9493  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004f9495  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9497  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9498  7704                   -ja 0x4f949e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f949e;
    }
    // 004f949a  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f949c  eb02                   -jmp 0x4f94a0
    goto L_0x004f94a0;
L_0x004f949e:
    // 004f949e  d9eb                   +fldpi 
    cpu.fpu.push(3.1415926535897932);
L_0x004f94a0:
    // 004f94a0  eb1a                   -jmp 0x4f94bc
    goto L_0x004f94bc;
L_0x004f94a2:
    // 004f94a2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f94a4  e8110d0200             -call 0x51a1ba
    cpu.esp -= 4;
    sub_51a1ba(app, cpu);
    if (cpu.terminate) return;
    // 004f94a9  3c00                   +cmp al, 0
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
    // 004f94ab  750f                   -jne 0x4f94bc
    if (!cpu.flags.zf)
    {
        goto L_0x004f94bc;
    }
    // 004f94ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f94af  e82572feff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004f94b4  db2d9c715600           -fld xword ptr [0x56719c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5665180) /* 0x56719c */)));
    // 004f94ba  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
L_0x004f94bc:
    // 004f94bc  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f94be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f94bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f94bf  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004f94c3  e8baffffff             -call 0x4f9482
    cpu.esp -= 4;
    sub_4f9482(app, cpu);
    if (cpu.terminate) return;
    // 004f94c8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f9500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9503  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9506  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004f950a  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004f950e  8b74246c               -mov esi, dword ptr [esp + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004f9512  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004f9516  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004f9519  83fa0b                 +cmp edx, 0xb
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
    // 004f951c  0f8762020000           -ja 0x4f9784
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f9784;
    }
    // 004f9522  ff2495d0944f00         -jmp dword ptr [edx*4 + 0x4f94d0]
    cpu.ip = app->getMemory<x86::reg32>(5215440 + cpu.edx * 4); goto dynamic_jump;
  case 0x004f9529:
    // 004f9529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f952a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f952b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f952c  b898d95400             -mov eax, 0x54d998
    cpu.eax = 5560728 /*0x54d998*/;
    // 004f9531  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9532  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9538  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f953f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9542  beac4d9f00             -mov esi, 0x9f4dac
    cpu.esi = 10440108 /*0x9f4dac*/;
    // 004f9547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9548  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f954a  b854445600             -mov eax, 0x564454
    cpu.eax = 5653588 /*0x564454*/;
    // 004f954f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9550  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f9556  e8f57a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f955b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f955e:
    // 004f955e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9561  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9563  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9564  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9567:
    // 004f9567  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9568  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9569  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f956a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f956b  6834d95400             -push 0x54d934
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560628 /*0x54d934*/;
    cpu.esp -= 4;
    // 004f9570  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9575  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f957c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f957f  bfac4d9f00             -mov edi, 0x9f4dac
    cpu.edi = 10440108 /*0x9f4dac*/;
    // 004f9584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9585  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9587  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f958c  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9592  e8b97a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9597  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f959a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f959e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f959f  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f95a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f95a6  e8a2750300             -call 0x530b4d
    cpu.esp -= 4;
    sub_530b4d(app, cpu);
    if (cpu.terminate) return;
    // 004f95ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95ac  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f95af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f95b5:
    // 004f95b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f95b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f95b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f95b8  6868d95400             -push 0x54d968
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560680 /*0x54d968*/;
    cpu.esp -= 4;
    // 004f95bd  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f95c2  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f95c9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f95cc  b9ac4d9f00             -mov ecx, 0x9f4dac
    cpu.ecx = 10440108 /*0x9f4dac*/;
    // 004f95d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f95d2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f95d4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f95d9  890db4ab5600           -mov dword ptr [0x56abb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ecx;
    // 004f95df  e86c7a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f95e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f95e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f95e9  0f846fffffff           -je 0x4f955e
    if (cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f95ef  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004f95f9  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f9603  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9606  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9608  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9609  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f960c:
    // 004f960c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f960d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f960e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f960f  68ccd95400             -push 0x54d9cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560780 /*0x54d9cc*/;
    cpu.esp -= 4;
    // 004f9614  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9619  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9620  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9623  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9628  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9629  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f962b  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9630  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f9635  e8167a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f963a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f963d  83fb10                 +cmp ebx, 0x10
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
    // 004f9640  732d                   -jae 0x4f966f
    if (!cpu.flags.cf)
    {
        goto L_0x004f966f;
    }
    // 004f9642  83fb02                 +cmp ebx, 2
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
    // 004f9645  0f83a4000000           -jae 0x4f96ef
    if (!cpu.flags.cf)
    {
        goto L_0x004f96ef;
    }
    // 004f964b  83fb01                 +cmp ebx, 1
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
    // 004f964e  0f850affffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9654  8b0da44d9f00           -mov ecx, dword ptr [0x9f4da4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f965a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f965b  e809630300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f9660  891d984d9f00           -mov dword ptr [0x9f4d98], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ebx;
    // 004f9666  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9669  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f966f:
    // 004f966f  0f86e9feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9675  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f967b  7326                   -jae 0x4f96a3
    if (!cpu.flags.cf)
    {
        goto L_0x004f96a3;
    }
    // 004f967d  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9680  0f85d8feffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
L_0x004f9686:
    // 004f9686  c7059c4d9f000c000000   -mov dword ptr [0x9f4d9c], 0xc
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 12 /*0xc*/;
    // 004f9690  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f969a  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f969d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96a0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96a3:
    // 004f96a3  0f86b5feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96a9  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96af  0f82a9feffff           -jb 0x4f955e
    if (cpu.flags.cf)
    {
        goto L_0x004f955e;
    }
    // 004f96b5  765e                   -jbe 0x4f9715
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9715;
    }
    // 004f96b7  81fb00400000           +cmp ebx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96bd  0f859bfeffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96c3  83fe08                 +cmp esi, 8
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
    // 004f96c6  7370                   -jae 0x4f9738
    if (!cpu.flags.cf)
    {
        goto L_0x004f9738;
    }
    // 004f96c8  83fe01                 +cmp esi, 1
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
    // 004f96cb  7205                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cd  7603                   -jbe 0x4f96d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cf  83fe02                 -cmp esi, 2
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
L_0x004f96d2:
    // 004f96d2  c7059c4d9f000b000000   -mov dword ptr [0x9f4d9c], 0xb
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 11 /*0xb*/;
    // 004f96dc  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f96e6  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f96e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ec  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96ef:
    // 004f96ef  0f8769feffff           -ja 0x4f955e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f9  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004f96fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f96fe  e8325e0300             -call 0x52f535
    cpu.esp -= 4;
    sub_52f535(app, cpu);
    if (cpu.terminate) return;
    // 004f9703  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004f9707  a3a44d9f00             -mov dword ptr [0x9f4da4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.eax;
    // 004f970c  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f970f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9711  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9712  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9715:
    // 004f9715  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 004f971a  e8d1090000             -call 0x4fa0f0
    cpu.esp -= 4;
    sub_4fa0f0(app, cpu);
    if (cpu.terminate) return;
    // 004f971f  89359c4d9f00           -mov dword ptr [0x9f4d9c], esi
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.esi;
    // 004f9725  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f972f  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9735  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9738:
    // 004f9738  762d                   -jbe 0x4f9767
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9767;
    }
    // 004f973a  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f973d  7293                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f973f  0f8641ffffff           -jbe 0x4f9686
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9686;
    }
    // 004f9745  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9748  7588                   -jne 0x4f96d2
    if (!cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f974a  c7059c4d9f000d000000   -mov dword ptr [0x9f4d9c], 0xd
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 13 /*0xd*/;
    // 004f9754  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f975e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9761  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9762  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9764  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9767:
    // 004f9767  c7059c4d9f000e000000   -mov dword ptr [0x9f4d9c], 0xe
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 14 /*0xe*/;
    // 004f9771  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f977b  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f977e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f977f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9780  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9781  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9784:
L_0x004f9784:
    // 004f9784  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9786  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9787  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9788  6800da5400             -push 0x54da00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560832 /*0x54da00*/;
    cpu.esp -= 4;
    // 004f978d  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9792  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9799  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f979c  baac4d9f00             -mov edx, 0x9f4dac
    cpu.edx = 10440108 /*0x9f4dac*/;
    // 004f97a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97a4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97a9  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f97af  e89c780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f97b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f97b7  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f97ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4f97c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f97c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f97c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f97c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f97c6  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004f97cb  e81061feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f97d0  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f97d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f97d8  0f85d5000000           -jne 0x4f98b3
    if (!cpu.flags.zf)
    {
        goto L_0x004f98b3;
    }
L_0x004f97de:
    // 004f97de  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f97e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f97e6  7425                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97e9  e8735e0300             -call 0x52f661
    cpu.esp -= 4;
    sub_52f661(app, cpu);
    if (cpu.terminate) return;
    // 004f97ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f97f0  741b                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97f2  bf3cda5400             -mov edi, 0x54da3c
    cpu.edi = 5560892 /*0x54da3c*/;
    // 004f97f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97f8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97fa  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97ff  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9805  e846780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f980a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f980d:
    // 004f980d  8b2d844d9f00           -mov ebp, dword ptr [0x9f4d84]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004f9813  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9815  0f84a3000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f981b  8b5538                 -mov edx, dword ptr [ebp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 004f981e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9820  83faff                 +cmp edx, -1
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
    // 004f9823  0f8495000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f9829  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f982b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f982d  e8ce190200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004f9832  893d844d9f00           -mov dword ptr [0x9f4d84], edi
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.edi;
L_0x004f9838:
    // 004f9838  8b2d884d9f00           -mov ebp, dword ptr [0x9f4d88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f983e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9840  740e                   -je 0x4f9850
    if (cpu.flags.zf)
    {
        goto L_0x004f9850;
    }
    // 004f9842  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9844  e84780feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9849  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f984b  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
L_0x004f9850:
    // 004f9850  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9857  7443                   -je 0x4f989c
    if (cpu.flags.zf)
    {
        goto L_0x004f989c;
    }
    // 004f9859  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f985f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9861  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f9863  7e25                   -jle 0x4f988a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f988a;
    }
    // 004f9865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f9867:
    // 004f9867  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f986c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f986e  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9871  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9873  7407                   -je 0x4f987c
    if (cpu.flags.zf)
    {
        goto L_0x004f987c;
    }
    // 004f9875  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f9877  e81480feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f987c:
    // 004f987c  8b1d804d9f00           -mov ebx, dword ptr [0x9f4d80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9882  42                     -inc edx
    (cpu.edx)++;
    // 004f9883  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9886  39da                   +cmp edx, ebx
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
    // 004f9888  7cdd                   -jl 0x4f9867
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f9867;
    }
L_0x004f988a:
    // 004f988a  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f988f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9891  e8fa7ffeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9896  8935944d9f00           -mov dword ptr [0x9f4d94], esi
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.esi;
L_0x004f989c:
    // 004f989c  8b2d744d9f00           -mov ebp, dword ptr [0x9f4d74]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f98a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f98a3  e82a8c0300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f98a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98aa  7550                   -jne 0x4f98fc
    if (!cpu.flags.zf)
    {
        goto L_0x004f98fc;
    }
    // 004f98ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f98b3:
    // 004f98b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f98b4  e8b0600300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f98b9  e920ffffff             -jmp 0x4f97de
    goto L_0x004f97de;
L_0x004f98be:
    // 004f98be  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004f98c4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f98c6  0f846cffffff           -je 0x4f9838
    if (cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f98cd  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f98d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98d6  0f855cffffff           -jne 0x4f9838
    if (!cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98dc  be50da5400             -mov esi, 0x54da50
    cpu.esi = 5560912 /*0x54da50*/;
    // 004f98e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f98e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f98e4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f98e9  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f98ef  e85c770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f98f4  83c40c                 +add esp, 0xc
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
    // 004f98f7  e93cffffff             -jmp 0x4f9838
    goto L_0x004f9838;
L_0x004f98fc:
    // 004f98fc  b870da5400             -mov eax, 0x54da70
    cpu.eax = 5560944 /*0x54da70*/;
    // 004f9901  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9902  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9904  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9909  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f990e  e83d770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9913  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f9916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9923  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9925  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9927  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004f992d  833da8715600ff         +cmp dword ptr [0x5671a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9934  7463                   -je 0x4f9999
    if (cpu.flags.zf)
    {
        goto L_0x004f9999;
    }
    // 004f9936  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9938  e83321ffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f993d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f993e  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9945  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f994a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f994c  e89f000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9951  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9955  0f8579000000           -jne 0x4f99d4
    if (!cpu.flags.zf)
    {
        goto L_0x004f99d4;
    }
    // 004f995b  e8c0030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f9960  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9962  0f8477000000           -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f9968  e883040000             -call 0x4f9df0
    cpu.esp -= 4;
    sub_4f9df0(app, cpu);
    if (cpu.terminate) return;
    // 004f996d  e84efeffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f9972  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9977  e8645ffeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f997c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f997e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f9980  e86b000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9985  83f80a                 +cmp eax, 0xa
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
    // 004f9988  7455                   -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f998a  e891030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f998f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9991  7451                   -je 0x4f99e4
    if (cpu.flags.zf)
    {
        goto L_0x004f99e4;
    }
    // 004f9993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9995  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9998  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9999:
    // 004f9999  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f999a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f999b  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f99a0  be98da5400             -mov esi, 0x54da98
    cpu.esi = 5560984 /*0x54da98*/;
    // 004f99a5  bf23010000             -mov edi, 0x123
    cpu.edi = 291 /*0x123*/;
    // 004f99aa  68a4da5400             -push 0x54daa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560996 /*0x54daa4*/;
    cpu.esp -= 4;
    // 004f99af  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f99b5  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f99bb  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f99c1  e84a76f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f99c6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f99ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99d4:
    // 004f99d4  e8e7fdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f99d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f99db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99df:
    // 004f99df  e8dcfdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f99e4:
    // 004f99e4  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f99f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f99f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f99f1  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f99f6  89157c4d9f00           -mov dword ptr [0x9f4d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */) = cpu.edx;
    // 004f99fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f99fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f99ff  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9a04  8915884d9f00           -mov dword ptr [0x9f4d88], edx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.edx;
    // 004f9a0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9a0b  8915a84d9f00           -mov dword ptr [0x9f4da8], edx
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.edx;
    // 004f9a11  8915a44d9f00           -mov dword ptr [0x9f4da4], edx
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.edx;
    // 004f9a17  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9a1c  8915a04d9f00           -mov dword ptr [0x9f4da0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */) = cpu.edx;
    // 004f9a22  8915944d9f00           -mov dword ptr [0x9f4d94], edx
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.edx;
    // 004f9a28  e891760300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9a2f  7510                   -jne 0x4f9a41
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a41;
    }
    // 004f9a31  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a38  7505                   -jne 0x4f9a3f
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a3f;
    }
    // 004f9a3a  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x004f9a3f:
    // 004f9a3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a41:
    // 004f9a41  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f9a46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9a50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9a51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9a52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9a54  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a5b  741d                   -je 0x4f9a7a
    if (cpu.flags.zf)
    {
        goto L_0x004f9a7a;
    }
L_0x004f9a5d:
    // 004f9a5d  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a63  7d1c                   -jge 0x4f9a81
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f9a81;
    }
    // 004f9a65  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9a6a  8b04d0                 -mov eax, dword ptr [eax + edx*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 004f9a6d  a3a8715600             -mov dword ptr [0x5671a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */) = cpu.eax;
    // 004f9a72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a7a:
    // 004f9a7a  e841000000             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004f9a7f  ebdc                   -jmp 0x4f9a5d
    goto L_0x004f9a5d;
L_0x004f9a81:
    // 004f9a81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9a83  be88da5400             -mov esi, 0x54da88
    cpu.esi = 5560968 /*0x54da88*/;
    // 004f9a88  bfecda5400             -mov edi, 0x54daec
    cpu.edi = 5561068 /*0x54daec*/;
    // 004f9a8d  bd76010000             -mov ebp, 0x176
    cpu.ebp = 374 /*0x176*/;
    // 004f9a92  68fcda5400             -push 0x54dafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561084 /*0x54dafc*/;
    cpu.esp -= 4;
    // 004f9a97  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f9a9d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9aa3  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9aa9  e86275f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f9aae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9ab1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ac1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9ac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ac4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ac5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9ac8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9aca  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9acc  8915804d9f00           -mov dword ptr [0x9f4d80], edx
    app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */) = cpu.edx;
    // 004f9ad2  e8991fffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f9ad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ad8  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9adf  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f9ae4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9ae6  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9aeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9aec  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9af1  e8c8750300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9af6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9af8  0f8529010000           -jne 0x4f9c27
    if (!cpu.flags.zf)
    {
        goto L_0x004f9c27;
    }
    // 004f9afe  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b05  0f8427010000           -je 0x4f9c32
    if (cpu.flags.zf)
    {
        goto L_0x004f9c32;
    }
    // 004f9b0b  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b12  7433                   -je 0x4f9b47
    if (cpu.flags.zf)
    {
        goto L_0x004f9b47;
    }
    // 004f9b14  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f9b16:
    // 004f9b16  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b1b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b1d  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9b20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9b22  7407                   -je 0x4f9b2b
    if (cpu.flags.zf)
    {
        goto L_0x004f9b2b;
    }
    // 004f9b24  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9b26  e8657dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f9b2b:
    // 004f9b2b  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b2e  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b34  75e0                   -jne 0x4f9b16
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b16;
    }
    // 004f9b36  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b3b  e8507dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9b40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9b42  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
L_0x004f9b47:
    // 004f9b47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9b48  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004f9b4d  b914db5400             -mov ecx, 0x54db14
    cpu.ecx = 5561108 /*0x54db14*/;
    // 004f9b52  bba9010000             -mov ebx, 0x1a9
    cpu.ebx = 425 /*0x1a9*/;
    // 004f9b57  b828db5400             -mov eax, 0x54db28
    cpu.eax = 5561128 /*0x54db28*/;
    // 004f9b5c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b5e  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f9b64  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f9b6a  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004f9b6f  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9b75  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f9b7b  e8a07afeff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9b80  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
    // 004f9b85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f9b87:
    // 004f9b87  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b8c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b8f  895406fc               -mov dword ptr [esi + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b93  895406f8               -mov dword ptr [esi + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b97  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b9d  75e8                   -jne 0x4f9b87
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b87;
    }
    // 004f9b9f  8b3d904d9f00           -mov edi, dword ptr [0x9f4d90]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9ba5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9ba7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9ba9  7639                   -jbe 0x4f9be4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9be4;
    }
    // 004f9bab  bf14db5400             -mov edi, 0x54db14
    cpu.edi = 5561108 /*0x54db14*/;
L_0x004f9bb0:
    // 004f9bb0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9bb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bb5  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9bba  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bbf  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bc4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9bc5  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bcb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9bcc  e8be770300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9bd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bd3  0f8499000000           -je 0x4f9c72
    if (cpu.flags.zf)
    {
        goto L_0x004f9c72;
    }
L_0x004f9bd9:
    // 004f9bd9  8b2d904d9f00           -mov ebp, dword ptr [0x9f4d90]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9bdf  46                     -inc esi
    (cpu.esi)++;
    // 004f9be0  39ee                   +cmp esi, ebp
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
    // 004f9be2  72cc                   -jb 0x4f9bb0
    if (cpu.flags.cf)
    {
        goto L_0x004f9bb0;
    }
L_0x004f9be4:
    // 004f9be4  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9be9  e8f25cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9bee  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bf4  e8d9880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9bf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bfb  741b                   -je 0x4f9c18
    if (cpu.flags.zf)
    {
        goto L_0x004f9c18;
    }
    // 004f9bfd  ba70da5400             -mov edx, 0x54da70
    cpu.edx = 5560944 /*0x54da70*/;
    // 004f9c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9c03  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c05  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c0a  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f9c10  e83b740000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c15  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c18:
    // 004f9c18  a1804d9f00             -mov eax, dword ptr [0x9f4d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9c1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c1e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c27:
    // 004f9c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c29  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c32:
    // 004f9c32  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9c37  e8a45cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9c3c  8b35744d9f00           -mov esi, dword ptr [0x9f4d74]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9c42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9c43  e88a880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9c48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c4a  741b                   -je 0x4f9c67
    if (cpu.flags.zf)
    {
        goto L_0x004f9c67;
    }
    // 004f9c4c  bf70da5400             -mov edi, 0x54da70
    cpu.edi = 5560944 /*0x54da70*/;
    // 004f9c51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9c52  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c54  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c59  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9c5f  e8ec730000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c64  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c67:
    // 004f9c67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c69  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c72:
    // 004f9c72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f9c74  e8b7020000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9c79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c7b  0f8558ffffff           -jne 0x4f9bd9
    if (!cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c81  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9c86  f6403c10               +test byte ptr [eax + 0x3c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) & 16 /*0x10*/));
    // 004f9c8a  0f8449ffffff           -je 0x4f9bd9
    if (cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c90  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9c95  bdc1010000             -mov ebp, 0x1c1
    cpu.ebp = 449 /*0x1c1*/;
    // 004f9c9a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9ca0  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9ca3  b834db5400             -mov eax, 0x54db34
    cpu.eax = 5561140 /*0x54db34*/;
    // 004f9ca8  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9cae  42                     -inc edx
    (cpu.edx)++;
    // 004f9caf  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9cb5  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9cbb  e86079feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9cc0  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cc6  8b15944d9f00           -mov edx, dword ptr [0x9f4d94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9ccc  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004f9ccf  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9cd1  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f9cd4  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9cd9  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004f9cdc  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9cdf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ce1  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f9ce4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9ce6  e84571feff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f9ceb  8b15804d9f00           -mov edx, dword ptr [0x9f4d80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cf1  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9cf6  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004f9cf9  01d0                   +add eax, edx
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
    // 004f9cfb  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9d01  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9d04  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f9d07  c6041100               -mov byte ptr [ecx + edx], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 004f9d0b  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004f9d0d  ff05804d9f00           +inc dword ptr [0x9f4d80]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9d13  e9c1feffff             -jmp 0x4f9bd9
    goto L_0x004f9bd9;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d25  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d28  8b15a8715600           -mov edx, dword ptr [0x5671a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d2e  83faff                 +cmp edx, -1
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
    // 004f9d31  750b                   -jne 0x4f9d3e
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d3e;
    }
L_0x004f9d33:
    // 004f9d33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9d35  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9d3e:
    // 004f9d3e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9d40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d41  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9d46  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d4b  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d51  8b1d744d9f00           -mov ebx, dword ptr [0x9f4d74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d57  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d58  e832760300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9d5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d5f  75d2                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d61  a1a8715600             -mov eax, dword ptr [0x5671a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d66  e8c5010000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9d6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d6d  75c4                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d6f  833d7c4d9f0000         +cmp dword ptr [0x9f4d7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9d76  746b                   -je 0x4f9de3
    if (cpu.flags.zf)
    {
        goto L_0x004f9de3;
    }
    // 004f9d78  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004f9d7d:
    // 004f9d7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d7f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9d81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d84  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d86  8b3d8c4d9f00           -mov edi, dword ptr [0x9f4d8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9d8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d8d  68a04d9f00             -push 0x9f4da0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440096 /*0x9f4da0*/;
    cpu.esp -= 4;
    // 004f9d92  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d99  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d9f  e895760300             -call 0x531439
    cpu.esp -= 4;
    sub_531439(app, cpu);
    if (cpu.terminate) return;
    // 004f9da4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9da6  758b                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9da8  833d784d9f0000         +cmp dword ptr [0x9f4d78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9daf  7424                   -je 0x4f9dd5
    if (cpu.flags.zf)
    {
        goto L_0x004f9dd5;
    }
    // 004f9db1  a1a04d9f00             -mov eax, dword ptr [0x9f4da0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9db6  e8e5000000             -call 0x4f9ea0
    cpu.esp -= 4;
    sub_4f9ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f9dbb  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9dc0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9dc2  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004f9dc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9dc9  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9dcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9dd0  e88d830300             -call 0x532162
    cpu.esp -= 4;
    sub_532162(app, cpu);
    if (cpu.terminate) return;
L_0x004f9dd5:
    // 004f9dd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9dda  83c410                 +add esp, 0x10
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
    // 004f9ddd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9dde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9de3:
    // 004f9de3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9de8  eb93                   -jmp 0x4f9d7d
    goto L_0x004f9d7d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f9df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9df2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9df3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9df4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9df5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9df6  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9dfc  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9e01  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9e03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9e05  e83668feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9e0a  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9e0f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9e13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9e16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e1a  8b0da04d9f00           -mov ecx, dword ptr [0x9f4da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9e20  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9e25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9e26  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004f9e2a  e81f6c0300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004f9e2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9e31  740f                   -je 0x4f9e42
    if (cpu.flags.zf)
    {
        goto L_0x004f9e42;
    }
L_0x004f9e33:
    // 004f9e33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9e35  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9e42:
    // 004f9e42  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f9e44  035c2414               -add ebx, dword ptr [esp + 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004f9e48  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004f9e4d  68603d9f00             -push 0x9f3d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10435936 /*0x9f3d60*/;
    cpu.esp -= 4;
    // 004f9e52  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e54  bf2ef53ce7             -mov edi, 0xe73cf52e
    cpu.edi = 3879531822 /*0xe73cf52e*/;
    // 004f9e59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9e5a  668915603d9f00         -mov word ptr [0x9f3d60], dx
    app->getMemory<x86::reg16>(x86::reg32(10435936) /* 0x9f3d60 */) = cpu.dx;
    // 004f9e61  893d943d9f00           -mov dword ptr [0x9f3d94], edi
    app->getMemory<x86::reg32>(x86::reg32(10435988) /* 0x9f3d94 */) = cpu.edi;
    // 004f9e67  2eff15ec445300         -call dword ptr cs:[0x5344ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457132) /* 0x5344ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9e70  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e73  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f9e7c  74b5                   -je 0x4f9e33
    if (cpu.flags.zf)
    {
        goto L_0x004f9e33;
    }
    // 004f9e7e  b8603d9f00             -mov eax, 0x9f3d60
    cpu.eax = 10435936 /*0x9f3d60*/;
    // 004f9e83  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004f9e86  a3784d9f00             -mov dword ptr [0x9f4d78], eax
    app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */) = cpu.eax;
    // 004f9e8b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9e90  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ea3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ea4  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eaa  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9eaf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9eb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9eb3  e88867feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9eb8  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9ebd  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ec1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ec2  8b0da8715600           -mov ecx, dword ptr [0x5671a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9ec8  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9ecd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ece  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f9ed2  e866690300             -call 0x53083d
    cpu.esp -= 4;
    sub_53083d(app, cpu);
    if (cpu.terminate) return;
    // 004f9ed7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9ed9  7509                   -jne 0x4f9ee4
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ee4;
    }
    // 004f9edb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9edf  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004f9ee2  760d                   -jbe 0x4f9ef1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9ef1;
    }
L_0x004f9ee4:
    // 004f9ee4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ee6  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ef0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9ef1:
    // 004f9ef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ef2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ef6  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004f9efa  8d503c                 -lea edx, [eax + 0x3c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f9efd  806220f8               -and byte ptr [edx + 0x20], 0xf8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(32) /* 0x20 */) &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004f9f01  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9f06  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f9f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f0c  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9f12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f13  e819800300             -call 0x531f31
    cpu.esp -= 4;
    sub_531f31(app, cpu);
    if (cpu.terminate) return;
    // 004f9f18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9f1a  7405                   -je 0x4f9f21
    if (cpu.flags.zf)
    {
        goto L_0x004f9f21;
    }
    // 004f9f1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f9f21:
    // 004f9f21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f22  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9f28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9f34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9f38  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f9f40  0f85af000000           -jne 0x4f9ff5
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ff5;
    }
L_0x004f9f46:
    // 004f9f46  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9f4b  bf50db5400             -mov edi, 0x54db50
    cpu.edi = 5561168 /*0x54db50*/;
    // 004f9f50  bd5a020000             -mov ebp, 0x25a
    cpu.ebp = 602 /*0x25a*/;
    // 004f9f55  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 004f9f5a  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9f5f  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9f65  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9f6b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9f71  bf88da5400             -mov edi, 0x54da88
    cpu.edi = 5560968 /*0x54da88*/;
    // 004f9f76  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9f7c  bd50db5400             -mov ebp, 0x54db50
    cpu.ebp = 5561168 /*0x54db50*/;
    // 004f9f81  e89a76feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9f86  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9f8b  c700f0000000           -mov dword ptr [eax], 0xf0
    app->getMemory<x86::reg32>(cpu.eax) = 240 /*0xf0*/;
L_0x004f9f91:
    // 004f9f91  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9f99  8b158c4d9f00           -mov edx, dword ptr [0x9f4d8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9f9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9fa1  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9fa7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9fa8  e89a670300             -call 0x530747
    cpu.esp -= 4;
    sub_530747(app, cpu);
    if (cpu.terminate) return;
    // 004f9fad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9fb1  7556                   -jne 0x4fa009
    if (!cpu.flags.zf)
    {
        goto L_0x004fa009;
    }
    // 004f9fb3  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9fb8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9fbb  3b08                   +cmp ecx, dword ptr [eax]
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
    // 004f9fbd  765c                   -jbe 0x4fa01b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa01b;
    }
    // 004f9fbf  e8cc78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9fc4  b86f020000             -mov eax, 0x26f
    cpu.eax = 623 /*0x26f*/;
    // 004f9fc9  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9fcf  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f9fd5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9fd7  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f9fdc  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9fe1  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f9fe7  e83476feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9fec  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9ff1  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004f9ff3  eb9c                   -jmp 0x4f9f91
    goto L_0x004f9f91;
L_0x004f9ff5:
    // 004f9ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9ff7  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f9ff9  e89278feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9ffe  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
    // 004fa004  e93dffffff             -jmp 0x4f9f46
    goto L_0x004f9f46;
L_0x004fa009:
    // 004fa009  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004fa00e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa010  e87b78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa015  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
L_0x004fa01b:
    // 004fa01b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa020  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa035  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa038  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa03a  740b                   -je 0x4fa047
    if (cpu.flags.zf)
    {
        goto L_0x004fa047;
    }
    // 004fa03c  833da04d9f0000         +cmp dword ptr [0x9f4da0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa043  7509                   -jne 0x4fa04e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa04e;
    }
    // 004fa045  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fa047:
    // 004fa047  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa049  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa04e:
    // 004fa04e  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004fa053  be70db5400             -mov esi, 0x54db70
    cpu.esi = 5561200 /*0x54db70*/;
    // 004fa058  bf87020000             -mov edi, 0x287
    cpu.edi = 647 /*0x287*/;
    // 004fa05d  ba70000000             -mov edx, 0x70
    cpu.edx = 112 /*0x70*/;
    // 004fa062  b880db5400             -mov eax, 0x54db80
    cpu.eax = 5561216 /*0x54db80*/;
    // 004fa067  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004fa06d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fa073  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa079  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fa07f  e89c75feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa084  bb70000000             -mov ebx, 0x70
    cpu.ebx = 112 /*0x70*/;
    // 004fa089  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa08b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa08d  e8ae65feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004fa092  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa093  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa095  c70670000000           -mov dword ptr [esi], 0x70
    app->getMemory<x86::reg32>(cpu.esi) = 112 /*0x70*/;
    // 004fa09b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa09c  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004fa0a3  68a44d9f00             -push 0x9f4da4
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440100 /*0x9f4da4*/;
    cpu.esp -= 4;
    // 004fa0a8  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004fa0ae  c7461010000000         -mov dword ptr [esi + 0x10], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 16 /*0x10*/;
    // 004fa0b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0b6  c7462cb80b0000         -mov dword ptr [esi + 0x2c], 0xbb8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 3000 /*0xbb8*/;
    // 004fa0bd  e8fe700300             -call 0x5311c0
    cpu.esp -= 4;
    sub_5311c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa0c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa0c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa0c6  e8c577feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa0cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa0cd  7c0c                   -jl 0x4fa0db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa0db;
    }
    // 004fa0cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa0d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa0db:
    // 004fa0db  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004fa0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa0e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fa0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa0f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa0f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa0f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0f6  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004fa0fb  b994db5400             -mov ecx, 0x54db94
    cpu.ecx = 5561236 /*0x54db94*/;
    // 004fa100  bbaa020000             -mov ebx, 0x2aa
    cpu.ebx = 682 /*0x2aa*/;
    // 004fa105  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa10a  bd88da5400             -mov ebp, 0x54da88
    cpu.ebp = 5560968 /*0x54da88*/;
    // 004fa10f  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fa115  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fa11b  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004fa120  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa126  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fa12c  e8ef74feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa131  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa133  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x004fa139:
    // 004fa139  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004fa13e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa13f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004fa141  8b35a44d9f00           -mov esi, dword ptr [0x9f4da4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa147  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa148  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14c  e8fd680300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004fa151  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa153  7541                   -jne 0x4fa196
    if (!cpu.flags.zf)
    {
        goto L_0x004fa196;
    }
    // 004fa155  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004fa158  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa15a  764d                   -jbe 0x4fa1a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa1a9;
    }
    // 004fa15c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa15e  babd020000             -mov edx, 0x2bd
    cpu.edx = 701 /*0x2bd*/;
    // 004fa163  e82877feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa168  b894db5400             -mov eax, 0x54db94
    cpu.eax = 5561236 /*0x54db94*/;
    // 004fa16d  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa173  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fa179  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fa17e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa180  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa185  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004fa18b  e89074feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa190  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa192  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004fa194  eba3                   -jmp 0x4fa139
    goto L_0x004fa139;
L_0x004fa196:
    // 004fa196  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa198  e8f376feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa19d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa1a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1a9:
    // 004fa1a9  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004fa1ac  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 004fa1af  a3a84d9f00             -mov dword ptr [0x9f4da8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.eax;
    // 004fa1b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa1b6  e8d576feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa1bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa1bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa1d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1d1  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa1d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa1d9  7502                   -jne 0x4fa1dd
    if (!cpu.flags.zf)
    {
        goto L_0x004fa1dd;
    }
    // 004fa1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1dd:
    // 004fa1dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa1de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1e4  bbb8db5400             -mov ebx, 0x54dbb8
    cpu.ebx = 5561272 /*0x54dbb8*/;
    // 004fa1e9  e840590300             -call 0x52fb2e
    cpu.esp -= 4;
    sub_52fb2e(app, cpu);
    if (cpu.terminate) return;
    // 004fa1ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa1f1  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004fa1f6  891db4ab5600           -mov dword ptr [0x56abb4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ebx;
    // 004fa1fc  e84f6e0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004fa201  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fa204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa205  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa206  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa210  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa211  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa214  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa219  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004fa21c  e82ff8ffff             -call 0x4f9a50
    cpu.esp -= 4;
    sub_4f9a50(app, cpu);
    if (cpu.terminate) return;
    // 004fa221  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa223  0f84c4000000           -je 0x4fa2ed
    if (cpu.flags.zf)
    {
        goto L_0x004fa2ed;
    }
    // 004fa229  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa22e  83786800               +cmp dword ptr [eax + 0x68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa232  0f8583000000           -jne 0x4fa2bb
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2bb;
    }
    // 004fa238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa23d:
    // 004fa23d  e8def6ffff             -call 0x4f9920
    cpu.esp -= 4;
    sub_4f9920(app, cpu);
    if (cpu.terminate) return;
    // 004fa242  a39c4d9f00             -mov dword ptr [0x9f4d9c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.eax;
    // 004fa247  833d9c4d9f0000         +cmp dword ptr [0x9f4d9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa24e  0f858f000000           -jne 0x4fa2e3
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2e3;
    }
    // 004fa254  c7059c4d9f0002000000   -mov dword ptr [0x9f4d9c], 2
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2 /*0x2*/;
    // 004fa25e  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa263  8b6868                 -mov ebp, dword ptr [eax + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 004fa266  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fa268  7558                   -jne 0x4fa2c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2c2;
    }
L_0x004fa26a:
    // 004fa26a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa26f:
    // 004fa26f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa271  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa272  8b15844d9f00           -mov edx, dword ptr [0x9f4d84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa278  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004fa27b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa27d  a3984d9f00             -mov dword ptr [0x9f4d98], eax
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.eax;
    // 004fa282  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004fa284:
    // 004fa284  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa289  3b5834                 +cmp ebx, dword ptr [eax + 0x34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa28c  744d                   -je 0x4fa2db
    if (cpu.flags.zf)
    {
        goto L_0x004fa2db;
    }
    // 004fa28e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa28f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa291  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004fa295  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa296  2eff154c475300         -call dword ptr cs:[0x53474c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457740) /* 0x53474c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa29d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa29f  742e                   -je 0x4fa2cf
    if (cpu.flags.zf)
    {
        goto L_0x004fa2cf;
    }
    // 004fa2a1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2a6  2eff15a4475300         -call dword ptr cs:[0x5347a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457828) /* 0x5347a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2ad  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2b2  2eff152c475300         -call dword ptr cs:[0x53472c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457708) /* 0x53472c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2b9  ebc9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2bb:
    // 004fa2bb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fa2bd  e97bffffff             -jmp 0x4fa23d
    goto L_0x004fa23d;
L_0x004fa2c2:
    // 004fa2c2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa2c4  e867fdffff             -call 0x4fa030
    cpu.esp -= 4;
    sub_4fa030(app, cpu);
    if (cpu.terminate) return;
    // 004fa2c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa2cb  759d                   -jne 0x4fa26a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa26a;
    }
    // 004fa2cd  eba0                   -jmp 0x4fa26f
    goto L_0x004fa26f;
L_0x004fa2cf:
    // 004fa2cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa2d4  e80756feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2d9  eba9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2db:
    // 004fa2db  e8f0feffff             -call 0x4fa1d0
    cpu.esp -= 4;
    sub_4fa1d0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fa2e3:
    // 004fa2e3  e8d8f4ffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa2ed:
    // 004fa2ed  c7059c4d9f0002000080   -mov dword ptr [0x9f4d9c], 0x80000002
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2147483650 /*0x80000002*/;
    // 004fa2f7  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa2fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4fa310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa312  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa315  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa317  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa31c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa31e  8915ac715600           -mov dword ptr [0x5671ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */) = cpu.edx;
    // 004fa324  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa326  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004fa32c  c74038ffffffff         -mov dword ptr [eax + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004fa333  68604d9f00             -push 0x9f4d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440032 /*0x9f4d60*/;
    cpu.esp -= 4;
    // 004fa338  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 004fa33b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004fa340  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fa345  b810a24f00             -mov eax, 0x4fa210
    cpu.eax = 5218832 /*0x4fa210*/;
    // 004fa34a  890d984d9f00           -mov dword ptr [0x9f4d98], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ecx;
    // 004fa350  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004fa355  e84654feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004fa35a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa35c  0f84c7000000           -je 0x4fa429
    if (cpu.flags.zf)
    {
        goto L_0x004fa429;
    }
    // 004fa362  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
L_0x004fa367:
    // 004fa367  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa36e  7416                   -je 0x4fa386
    if (cpu.flags.zf)
    {
        goto L_0x004fa386;
    }
    // 004fa370  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa376  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa378  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa37a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa37d  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa37f  e85c55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa384  ebe1                   -jmp 0x4fa367
    goto L_0x004fa367;
L_0x004fa386:
    // 004fa386  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004fa38b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004fa38d:
    // 004fa38d  8b2d984d9f00           -mov ebp, dword ptr [0x9f4d98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
    // 004fa393  39e9                   +cmp ecx, ebp
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
    // 004fa395  753e                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa399  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa39e  7535                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa3a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3a2  e88955feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fa3a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3a9  7421                   -je 0x4fa3cc
    if (cpu.flags.zf)
    {
        goto L_0x004fa3cc;
    }
    // 004fa3ab  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ad  e87ed2feff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004fa3b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3b4  7c1f                   -jl 0x4fa3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa3d5;
    }
L_0x004fa3b6:
    // 004fa3b6  8b2dd8435600           -mov ebp, dword ptr [0x5643d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa3bc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa3be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa3c0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa3c3  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa3c5  e81655feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3ca  ebc1                   -jmp 0x4fa38d
    goto L_0x004fa38d;
L_0x004fa3cc:
    // 004fa3cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ce  e80d55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3d3  ebe1                   -jmp 0x4fa3b6
    goto L_0x004fa3b6;
L_0x004fa3d5:
    // 004fa3d5  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa3dc  7540                   -jne 0x4fa41e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa41e;
    }
L_0x004fa3de:
    // 004fa3de  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e2  c7473400000000         -mov dword ptr [edi + 0x34], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa3e9  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa3ee  8b0d704d9f00           -mov ecx, dword ptr [0x9f4d70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa3f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa3f5  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fa3fc:
    // 004fa3fc  837f3400               +cmp dword ptr [edi + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa400  7413                   -je 0x4fa415
    if (cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa402  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa409  750a                   -jne 0x4fa415
    if (!cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa40b  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004fa411  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa413  7520                   -jne 0x4fa435
    if (!cpu.flags.zf)
    {
        goto L_0x004fa435;
    }
L_0x004fa415:
    // 004fa415  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa419  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa41e:
    // 004fa41e  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa425  75b7                   -jne 0x4fa3de
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3de;
    }
    // 004fa427  ebd3                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa429:
    // 004fa429  c7059c4d9f0001000000   -mov dword ptr [0x9f4d9c], 1
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 1 /*0x1*/;
    // 004fa433  ebc7                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa435:
    // 004fa435  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa43a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa43c  e8af0e0200             -call 0x51b2f0
    cpu.esp -= 4;
    sub_51b2f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa441  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004fa444  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa447  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fa450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa451  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa452  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa454  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa456  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa45b  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa462  8b15704d9f00           -mov edx, dword ptr [0x9f4d70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa468  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa469  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa470  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa475  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa481  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa482  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa484  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa486  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa48d  750f                   -jne 0x4fa49e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa49e;
    }
    // 004fa48f  833dac71560000         +cmp dword ptr [0x5671ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa496  752a                   -jne 0x4fa4c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa4c2;
    }
L_0x004fa498:
    // 004fa498  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa49b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa49e:
    // 004fa49e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa49f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa4a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a4  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa4a9  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa4b0  8b3d704d9f00           -mov edi, dword ptr [0x9f4d70]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa4b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa4b7  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4c0  ebd6                   -jmp 0x4fa498
    goto L_0x004fa498;
L_0x004fa4c2:
    // 004fa4c2  e829000000             -call 0x4fa4f0
    cpu.esp -= 4;
    sub_4fa4f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa4c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa4c9  74cd                   -je 0x4fa498
    if (cpu.flags.zf)
    {
        goto L_0x004fa498;
    }
    // 004fa4cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa4cd  ff15ac715600           -call dword ptr [0x5671ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4d3  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa4d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4e0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4e3  e918140200             -jmp 0x51b900
    return sub_51b900(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4f0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4f3  e9a8130200             -jmp 0x51b8a0
    return sub_51b8a0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa501  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa503  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa505  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fa507  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa50a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa50c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa50e  e83d150200             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 004fa513  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa517  7c04                   -jl 0x4fa51d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa51d;
    }
    // 004fa519  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa51b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa51c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa51d:
    // 004fa51d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fa51f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa531  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa533  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa535  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa537  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa53a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa53c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa53e  e8ed0f0200             -call 0x51b530
    cpu.esp -= 4;
    sub_51b530(app, cpu);
    if (cpu.terminate) return;
    // 004fa543  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa544  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa554  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa55a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa55c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fa55e  83fbff                 +cmp ebx, -1
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
    // 004fa561  0f857d000000           -jne 0x4fa5e4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5e4;
    }
    // 004fa567  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x004fa56c:
    // 004fa56c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fa56e  7454                   -je 0x4fa5c4
    if (cpu.flags.zf)
    {
        goto L_0x004fa5c4;
    }
    // 004fa570  66837e2a00             +cmp word ptr [esi + 0x2a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa575  7513                   -jne 0x4fa58a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa58a;
    }
    // 004fa577  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa579  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa57b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa57e  c1e204                 +shl edx, 4
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
    // 004fa581  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa583  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004fa586  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x004fa58a:
    // 004fa58a  66837e2c00             +cmp word ptr [esi + 0x2c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa58f  7513                   -jne 0x4fa5a4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5a4;
    }
    // 004fa591  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa593  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa595  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa598  c1e202                 +shl edx, 2
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
    // 004fa59b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa59d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004fa5a0  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x004fa5a4:
    // 004fa5a4  66837e2e00             +cmp word ptr [esi + 0x2e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa5a9  7513                   -jne 0x4fa5be
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5be;
    }
    // 004fa5ab  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa5ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa5af  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa5b2  c1e202                 +shl edx, 2
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
    // 004fa5b5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa5b7  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004fa5ba  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x004fa5be:
    // 004fa5be  66c746280600           -mov word ptr [esi + 0x28], 6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 6 /*0x6*/;
L_0x004fa5c4:
    // 004fa5c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa5c5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fa5c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa5c9  bbb0715600             -mov ebx, 0x5671b0
    cpu.ebx = 5665200 /*0x5671b0*/;
    // 004fa5ce  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 004fa5d4  e857abffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004fa5d9  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa5df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa5e4:
    // 004fa5e4  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 004fa5e9  eb81                   -jmp 0x4fa56c
    goto L_0x004fa56c;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fa5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa5f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa5f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa5f3  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa5fa  7417                   -je 0x4fa613
    if (cpu.flags.zf)
    {
        goto L_0x004fa613;
    }
L_0x004fa5fc:
    // 004fa5fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa5fe  7c1a                   -jl 0x4fa61a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa61a;
    }
    // 004fa600  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa606  7312                   -jae 0x4fa61a
    if (!cpu.flags.cf)
    {
        goto L_0x004fa61a;
    }
    // 004fa608  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004fa60d  8b44d004               -mov eax, dword ptr [eax + edx*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 004fa611  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa612  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa613:
    // 004fa613  e8a8f4ffff             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004fa618  ebe2                   -jmp 0x4fa5fc
    goto L_0x004fa5fc;
L_0x004fa61a:
    // 004fa61a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa61c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa61d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4fa620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa624  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa626  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa628  8915ac4e9f00           -mov dword ptr [0x9f4eac], edx
    app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */) = cpu.edx;
    // 004fa62e  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa635  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa637  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa63a  891558445600           -mov dword ptr [0x564458], edx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.edx;
    // 004fa640  e83b0e0200             -call 0x51b480
    cpu.esp -= 4;
    sub_51b480(app, cpu);
    if (cpu.terminate) return;
    // 004fa645  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa648  e8e3090200             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 004fa64d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa64f  7525                   -jne 0x4fa676
    if (!cpu.flags.zf)
    {
        goto L_0x004fa676;
    }
    // 004fa651  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa658  7c14                   -jl 0x4fa66e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa66e;
    }
    // 004fa65a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa65b  b8d8db5400             -mov eax, 0x54dbd8
    cpu.eax = 5561304 /*0x54dbd8*/;
    // 004fa660  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa662  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa664  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fa666  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa669  e8127b0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004fa66e:
    // 004fa66e  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa671  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa673  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa674  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa675  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa676:
    // 004fa676  8b5e4c                 -mov ebx, dword ptr [esi + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004fa679  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004fa67c  8b5640                 -mov edx, dword ptr [esi + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004fa67f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa680  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa683  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004fa686  e885100200             -call 0x51b710
    cpu.esp -= 4;
    sub_51b710(app, cpu);
    if (cpu.terminate) return;
    // 004fa68b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa68e  e82d0b0200             -call 0x51b1c0
    cpu.esp -= 4;
    sub_51b1c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa693  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa696  e8450b0200             -call 0x51b1e0
    cpu.esp -= 4;
    sub_51b1e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa69b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa69e  e88d020200             -call 0x51a930
    cpu.esp -= 4;
    sub_51a930(app, cpu);
    if (cpu.terminate) return;
    // 004fa6a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa6a5  750f                   -jne 0x4fa6b6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa6b6;
    }
    // 004fa6a7  c7463401000000         -mov dword ptr [esi + 0x34], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 004fa6ae  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa6b6:
    // 004fa6b6  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa6b9  e8420b0200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004fa6be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa6c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa6d0  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa6d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa6dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fa6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa6e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa6e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa6e5  8b1dac4e9f00           -mov ebx, dword ptr [0x9f4eac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */);
    // 004fa6eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa6ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fa6ef  7507                   -jne 0x4fa6f8
    if (!cpu.flags.zf)
    {
        goto L_0x004fa6f8;
    }
L_0x004fa6f1:
    // 004fa6f1  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004fa6f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa6f8:
    // 004fa6f8  e823000000             -call 0x4fa720
    cpu.esp -= 4;
    sub_4fa720(app, cpu);
    if (cpu.terminate) return;
    // 004fa6fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa6ff  74f0                   -je 0x4fa6f1
    if (cpu.flags.zf)
    {
        goto L_0x004fa6f1;
    }
    // 004fa701  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa703  ff15ac4e9f00           -call dword ptr [0x9f4eac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa709  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004fa70c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fa710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa710  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa713  e9e8110200             -jmp 0x51b900
    return sub_51b900(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa720  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa723  e978110200             -jmp 0x51b8a0
    return sub_51b8a0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa731  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa733  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa735  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fa737  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa73a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa73c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa73e  e80d130200             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 004fa743  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa745  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa747  7c04                   -jl 0x4fa74d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa74d;
    }
    // 004fa749  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa74b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa74c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa74d:
    // 004fa74d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fa74f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa751  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa761  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa763  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa765  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa767  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa76a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa76c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa76e  e8bd0d0200             -call 0x51b530
    cpu.esp -= 4;
    sub_51b530(app, cpu);
    if (cpu.terminate) return;
    // 004fa773  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa774  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa782  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa784  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fa787  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa78d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa78f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fa791  83fbff                 +cmp ebx, -1
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
    // 004fa794  0f8585000000           -jne 0x4fa81f
    if (!cpu.flags.zf)
    {
        goto L_0x004fa81f;
    }
    // 004fa79a  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x004fa79f:
    // 004fa79f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fa7a1  7459                   -je 0x4fa7fc
    if (cpu.flags.zf)
    {
        goto L_0x004fa7fc;
    }
    // 004fa7a3  66837e2a00             +cmp word ptr [esi + 0x2a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa7a8  7513                   -jne 0x4fa7bd
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7bd;
    }
    // 004fa7aa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7ac  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7ae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7b1  c1e204                 +shl edx, 4
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
    // 004fa7b4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa7b6  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004fa7b9  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x004fa7bd:
    // 004fa7bd  66837e2c00             +cmp word ptr [esi + 0x2c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa7c2  7515                   -jne 0x4fa7d9
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7d9;
    }
    // 004fa7c4  c704240a000000         -mov dword ptr [esp], 0xa
    app->getMemory<x86::reg32>(cpu.esp) = 10 /*0xa*/;
    // 004fa7cb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7cd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7cf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7d2  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa7d5  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x004fa7d9:
    // 004fa7d9  66837e2e00             +cmp word ptr [esi + 0x2e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa7de  7516                   -jne 0x4fa7f6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7f6;
    }
    // 004fa7e0  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004fa7e5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fa7ea  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7ef  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa7f2  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x004fa7f6:
    // 004fa7f6  66c746280300           -mov word ptr [esi + 0x28], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 3 /*0x3*/;
L_0x004fa7fc:
    // 004fa7fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa7fd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fa7ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa801  bbd0715600             -mov ebx, 0x5671d0
    cpu.ebx = 5665232 /*0x5671d0*/;
    // 004fa806  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 004fa80c  e81fa9ffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004fa811  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa817  83c404                 +add esp, 4
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
    // 004fa81a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa81f:
    // 004fa81f  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 004fa824  e976ffffff             -jmp 0x4fa79f
    goto L_0x004fa79f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fa830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa831  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa832  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa833  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fa836  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fa83a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fa83d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004fa841  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004fa846  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fa848  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004fa84a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004fa84e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa853  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fa858  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004fa85a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa85e  a3bc4e9f00             -mov dword ptr [0x9f4ebc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */) = cpu.eax;
    // 004fa863  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004fa865  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa869  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa86e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa870  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004fa872  a3c04e9f00             -mov dword ptr [0x9f4ec0], eax
    app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */) = cpu.eax;
    // 004fa877  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fa87c  a3c84e9f00             -mov dword ptr [0x9f4ec8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */) = cpu.eax;
    // 004fa881  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fa884  8b15bc4e9f00           -mov edx, dword ptr [0x9f4ebc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fa88a  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa890  a3cc4e9f00             -mov dword ptr [0x9f4ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */) = cpu.eax;
    // 004fa895  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fa899  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fa89d  e88e070000             -call 0x4fb030
    cpu.esp -= 4;
    sub_4fb030(app, cpu);
    if (cpu.terminate) return;
    // 004fa8a2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa8a4  8b1db84e9f00           -mov ebx, dword ptr [0x9f4eb8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */);
    // 004fa8aa  8915b04e9f00           -mov dword ptr [0x9f4eb0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */) = cpu.edx;
    // 004fa8b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa8b2  7e23                   -jle 0x4fa8d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fa8d7;
    }
L_0x004fa8b4:
    // 004fa8b4  a1b04e9f00             -mov eax, dword ptr [0x9f4eb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004fa8b9  80b8c450560000         +cmp byte ptr [eax + 0x5650c4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656772) /* 0x5650c4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fa8c0  7524                   -jne 0x4fa8e6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa8e6;
    }
L_0x004fa8c2:
    // 004fa8c2  8b35b04e9f00           -mov esi, dword ptr [0x9f4eb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004fa8c8  46                     -inc esi
    (cpu.esi)++;
    // 004fa8c9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fa8cd  8935b04e9f00           -mov dword ptr [0x9f4eb0], esi
    app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */) = cpu.esi;
    // 004fa8d3  39fe                   +cmp esi, edi
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
    // 004fa8d5  7cdd                   -jl 0x4fa8b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa8b4;
    }
L_0x004fa8d7:
    // 004fa8d7  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa8dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fa8e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004fa8e6:
    // 004fa8e6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004fa8e9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fa8ec  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa8ee  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 004fa8f2  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa8f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa8f8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa8fa  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 004fa8fe  a3f44e9f00             -mov dword ptr [0x9f4ef4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */) = cpu.eax;
    // 004fa903  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa905  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa907  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004fa90a  a3e44e9f00             -mov dword ptr [0x9f4ee4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */) = cpu.eax;
    // 004fa90f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa911  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa913  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa915  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa918  a3e84e9f00             -mov dword ptr [0x9f4ee8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */) = cpu.eax;
    // 004fa91d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa91f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa921  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004fa923  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa929  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa92c  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004fa92f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004fa931  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa934  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa936  8b15e44e9f00           -mov edx, dword ptr [0x9f4ee4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa93c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa93f  890df84e9f00           -mov dword ptr [0x9f4ef8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ecx;
    // 004fa945  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004fa947  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa94a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa94c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa94e  8b15e84e9f00           -mov edx, dword ptr [0x9f4ee8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004fa954  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa957  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fa959  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa95b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa95e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa960  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa962  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004fa965  8915f04e9f00           -mov dword ptr [0x9f4ef0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */) = cpu.edx;
    // 004fa96b  8b15f84e9f00           -mov edx, dword ptr [0x9f4ef8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fa971  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa974  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa976  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004fa97b  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fa97e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa980  a1f44e9f00             -mov eax, dword ptr [0x9f4ef4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa985  8915f04e9f00           -mov dword ptr [0x9f4ef0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */) = cpu.edx;
    // 004fa98b  8b15c04e9f00           -mov edx, dword ptr [0x9f4ec0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004fa991  40                     -inc eax
    (cpu.eax)++;
    // 004fa992  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa995  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fa997  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa999  a3d04e9f00             -mov dword ptr [0x9f4ed0], eax
    app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */) = cpu.eax;
    // 004fa99e  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa9a3  40                     -inc eax
    (cpu.eax)++;
    // 004fa9a4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9a7  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fa9a9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9ab  a3d84e9f00             -mov dword ptr [0x9f4ed8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440408) /* 0x9f4ed8 */) = cpu.eax;
    // 004fa9b0  a1e84e9f00             -mov eax, dword ptr [0x9f4ee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004fa9b5  40                     -inc eax
    (cpu.eax)++;
    // 004fa9b6  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9b9  8b35f44e9f00           -mov esi, dword ptr [0x9f4ef4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa9bf  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fa9c1  0faf35cc4e9f00         -imul esi, dword ptr [0x9f4ecc]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */))));
    // 004fa9c8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9ca  a3d44e9f00             -mov dword ptr [0x9f4ed4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440404) /* 0x9f4ed4 */) = cpu.eax;
    // 004fa9cf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fa9d3  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 004fa9da  8b15c84e9f00           -mov edx, dword ptr [0x9f4ec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fa9e0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9e2  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa9e7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9ea  890d004f9f00           -mov dword ptr [0x9f4f00], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.ecx;
    // 004fa9f0  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fa9f4  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa9fa  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa9fc  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004faa03  8b15e84e9f00           -mov edx, dword ptr [0x9f4ee8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faa09  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004faa0b  8b3de84e9f00           -mov edi, dword ptr [0x9f4ee8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faa11  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faa13  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004faa16  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004faa18  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004faa1a  8915b44e9f00           -mov dword ptr [0x9f4eb4], edx
    app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */) = cpu.edx;
    // 004faa20  892de04e9f00           -mov dword ptr [0x9f4ee0], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */) = cpu.ebp;
    // 004faa26  e815000000             -call 0x4faa40
    cpu.esp -= 4;
    sub_4faa40(app, cpu);
    if (cpu.terminate) return;
    // 004faa2b  8b1db84e9f00           -mov ebx, dword ptr [0x9f4eb8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */);
    // 004faa31  e98cfeffff             -jmp 0x4fa8c2
    goto L_0x004fa8c2;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4faa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004faa40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004faa41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004faa42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004faa43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004faa44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004faa45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004faa46  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004faa4b  8b1dc04e9f00           -mov ebx, dword ptr [0x9f4ec0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004faa51  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004faa57  8b35d04e9f00           -mov esi, dword ptr [0x9f4ed0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */);
    // 004faa5d  8b3dbc4e9f00           -mov edi, dword ptr [0x9f4ebc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faa63  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
    // 004faa68  a1e04e9f00             -mov eax, dword ptr [0x9f4ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */);
    // 004faa6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004faa6f  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004faa74  a1b44e9f00             -mov eax, dword ptr [0x9f4eb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */);
    // 004faa79  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004faa7b  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004faa80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004faa85  39f9                   +cmp ecx, edi
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
    // 004faa87  0f8cc0000000           -jl 0x4fab4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab4d;
    }
L_0x004faa8d:
    // 004faa8d  8b35d04e9f00           -mov esi, dword ptr [0x9f4ed0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */);
    // 004faa93  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004faa98  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004faa9a  8b3dcc4e9f00           -mov edi, dword ptr [0x9f4ecc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faaa0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004faaa2  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004faaa5  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
    // 004faaaa  a1e04e9f00             -mov eax, dword ptr [0x9f4ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */);
    // 004faaaf  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004faab5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004faab7  8b2dcc4e9f00           -mov ebp, dword ptr [0x9f4ecc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faabd  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004faac2  a1b44e9f00             -mov eax, dword ptr [0x9f4eb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */);
    // 004faac7  49                     -dec ecx
    (cpu.ecx)--;
    // 004faac8  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004faaca  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004faad0  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004faad5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004faada  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004faadc  7c60                   -jl 0x4fab3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab3e;
    }
L_0x004faade:
    // 004faade  e8fd000000             -call 0x4fabe0
    cpu.esp -= 4;
    sub_4fabe0(app, cpu);
    if (cpu.terminate) return;
    // 004faae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004faae5  0f84dd000000           -je 0x4fabc8
    if (cpu.flags.zf)
    {
        goto L_0x004fabc8;
    }
    // 004faaeb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004faaf0:
    // 004faaf0  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faaf5  8b35dc4e9f00           -mov esi, dword ptr [0x9f4edc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004faafb  8b3dc44e9f00           -mov edi, dword ptr [0x9f4ec4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fab01  8b2df84e9f00           -mov ebp, dword ptr [0x9f4ef8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fab07  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fab0a  49                     -dec ecx
    (cpu.ecx)--;
    // 004fab0b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab0d  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab12  8935dc4e9f00           -mov dword ptr [0x9f4edc], esi
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.esi;
    // 004fab18  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fab1e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab20  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fab22  893dc44e9f00           -mov dword ptr [0x9f4ec4], edi
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.edi;
    // 004fab28  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004fab2e  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fab30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fab32  892df84e9f00           -mov dword ptr [0x9f4ef8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ebp;
    // 004fab38  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004fab3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fab3c  7da0                   -jge 0x4faade
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004faade;
    }
L_0x004fab3e:
    // 004fab3e  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fab44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fab46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fab4d:
    // 004fab4d  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
L_0x004fab53:
    // 004fab53  e888000000             -call 0x4fabe0
    cpu.esp -= 4;
    sub_4fabe0(app, cpu);
    if (cpu.terminate) return;
    // 004fab58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fab5a  745c                   -je 0x4fabb8
    if (cpu.flags.zf)
    {
        goto L_0x004fabb8;
    }
    // 004fab5c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004fab61  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
L_0x004fab67:
    // 004fab67  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab6c  8b2ddc4e9f00           -mov ebp, dword ptr [0x9f4edc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fab72  8b3dc44e9f00           -mov edi, dword ptr [0x9f4ec4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fab78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fab7b  41                     -inc ecx
    (cpu.ecx)++;
    // 004fab7c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fab7e  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab83  892ddc4e9f00           -mov dword ptr [0x9f4edc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.ebp;
    // 004fab89  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fab8b  8b2df84e9f00           -mov ebp, dword ptr [0x9f4ef8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fab91  893dc44e9f00           -mov dword ptr [0x9f4ec4], edi
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.edi;
    // 004fab97  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fab99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab9b  8b3dbc4e9f00           -mov edi, dword ptr [0x9f4ebc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faba1  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004faba3  892df84e9f00           -mov dword ptr [0x9f4ef8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ebp;
    // 004faba9  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004fabaf  39f9                   +cmp ecx, edi
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
    // 004fabb1  7ca0                   -jl 0x4fab53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab53;
    }
    // 004fabb3  e9d5feffff             -jmp 0x4faa8d
    goto L_0x004faa8d;
L_0x004fabb8:
    // 004fabb8  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fabbe  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fabc0  0f85c7feffff           -jne 0x4faa8d
    if (!cpu.flags.zf)
    {
        goto L_0x004faa8d;
    }
    // 004fabc6  eb9f                   -jmp 0x4fab67
    goto L_0x004fab67;
L_0x004fabc8:
    // 004fabc8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fabca  0f856effffff           -jne 0x4fab3e
    if (!cpu.flags.zf)
    {
        goto L_0x004fab3e;
    }
    // 004fabd0  e91bffffff             -jmp 0x4faaf0
    goto L_0x004faaf0;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fabe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fabe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fabe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fabe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fabe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fabe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fabe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fabe6  8b35c04e9f00           -mov esi, dword ptr [0x9f4ec0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004fabec  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fabee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fabf0  0f855d020000           -jne 0x4fae53
    if (!cpu.flags.zf)
    {
        goto L_0x004fae53;
    }
L_0x004fabf6:
    // 004fabf6  8b0d084f9f00           -mov ecx, dword ptr [0x9f4f08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */);
    // 004fabfc  a1f84e9f00             -mov eax, dword ptr [0x9f4ef8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fac01  8b1d144f9f00           -mov ebx, dword ptr [0x9f4f14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */);
    // 004fac07  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fac0c  a31c4f9f00             -mov dword ptr [0x9f4f1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.eax;
    // 004fac11  a1dc4e9f00             -mov eax, dword ptr [0x9f4edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fac16  8b3d104f9f00           -mov edi, dword ptr [0x9f4f10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */);
    // 004fac1c  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004fac21  a3204f9f00             -mov dword ptr [0x9f4f20], eax
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.eax;
    // 004fac26  a1c44e9f00             -mov eax, dword ptr [0x9f4ec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fac2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fac2d  a3fc4e9f00             -mov dword ptr [0x9f4efc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.eax;
    // 004fac32  a3244f9f00             -mov dword ptr [0x9f4f24], eax
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.eax;
    // 004fac37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fac3c  39f9                   +cmp ecx, edi
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
    // 004fac3e  0f8fce000000           -jg 0x4fad12
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fad12;
    }
    // 004fac44  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
L_0x004fac4a:
    // 004fac4a  e851020000             -call 0x4faea0
    cpu.esp -= 4;
    sub_4faea0(app, cpu);
    if (cpu.terminate) return;
    // 004fac4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fac51  0f8428020000           -je 0x4fae7f
    if (cpu.flags.zf)
    {
        goto L_0x004fae7f;
    }
    // 004fac57  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fac5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fac5f  7537                   -jne 0x4fac98
    if (!cpu.flags.zf)
    {
        goto L_0x004fac98;
    }
    // 004fac61  3b0d084f9f00           +cmp ecx, dword ptr [0x9f4f08]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fac67  7e2a                   -jle 0x4fac93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fac93;
    }
    // 004fac69  a1204f9f00             -mov eax, dword ptr [0x9f4f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fac6e  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004fac73  a1244f9f00             -mov eax, dword ptr [0x9f4f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fac78  891d144f9f00           -mov dword ptr [0x9f4f14], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.ebx;
    // 004fac7e  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004fac83  a11c4f9f00             -mov eax, dword ptr [0x9f4f1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fac88  890d084f9f00           -mov dword ptr [0x9f4f08], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.ecx;
    // 004fac8e  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
L_0x004fac93:
    // 004fac93  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004fac98:
    // 004fac98  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fac9d  8b2dec4e9f00           -mov ebp, dword ptr [0x9f4eec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004faca3  8b3d204f9f00           -mov edi, dword ptr [0x9f4f20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004faca9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004facac  41                     -inc ecx
    (cpu.ecx)++;
    // 004facad  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facaf  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facb1  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004facb6  892dec4e9f00           -mov dword ptr [0x9f4eec], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.ebp;
    // 004facbc  893d204f9f00           -mov dword ptr [0x9f4f20], edi
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.edi;
    // 004facc2  8b2dfc4e9f00           -mov ebp, dword ptr [0x9f4efc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004facc8  8b3d244f9f00           -mov edi, dword ptr [0x9f4f24]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004facce  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facd0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facd2  892dfc4e9f00           -mov dword ptr [0x9f4efc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.ebp;
    // 004facd8  893d244f9f00           -mov dword ptr [0x9f4f24], edi
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.edi;
    // 004facde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004face0  8b2d004f9f00           -mov ebp, dword ptr [0x9f4f00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004face6  8b3d1c4f9f00           -mov edi, dword ptr [0x9f4f1c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004facec  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004facee  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004facf0  892d004f9f00           -mov dword ptr [0x9f4f00], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.ebp;
    // 004facf6  893d1c4f9f00           -mov dword ptr [0x9f4f1c], edi
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.edi;
    // 004facfc  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004facfe  8b2d104f9f00           -mov ebp, dword ptr [0x9f4f10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */);
    // 004fad04  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fad0a  39e9                   +cmp ecx, ebp
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
    // 004fad0c  0f8e38ffffff           -jle 0x4fac4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fac4a;
    }
L_0x004fad12:
    // 004fad12  8b1d144f9f00           -mov ebx, dword ptr [0x9f4f14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */);
    // 004fad18  a1f84e9f00             -mov eax, dword ptr [0x9f4ef8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fad1d  8b3dc84e9f00           -mov edi, dword ptr [0x9f4ec8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fad23  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fad25  8b0d084f9f00           -mov ecx, dword ptr [0x9f4f08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */);
    // 004fad2b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fad2d  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004fad30  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fad35  a31c4f9f00             -mov dword ptr [0x9f4f1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.eax;
    // 004fad3a  a1dc4e9f00             -mov eax, dword ptr [0x9f4edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fad3f  8b2d0c4f9f00           -mov ebp, dword ptr [0x9f4f0c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */);
    // 004fad45  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fad47  8b3dc84e9f00           -mov edi, dword ptr [0x9f4ec8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fad4d  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004fad52  a3204f9f00             -mov dword ptr [0x9f4f20], eax
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.eax;
    // 004fad57  a1c44e9f00             -mov eax, dword ptr [0x9f4ec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fad5c  49                     -dec ecx
    (cpu.ecx)--;
    // 004fad5d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fad5f  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fad65  a3fc4e9f00             -mov dword ptr [0x9f4efc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.eax;
    // 004fad6a  a3244f9f00             -mov dword ptr [0x9f4f24], eax
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.eax;
    // 004fad6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fad74  39e9                   +cmp ecx, ebp
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
    // 004fad76  0f8cc8000000           -jl 0x4fae44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fae44;
    }
L_0x004fad7c:
    // 004fad7c  e81f010000             -call 0x4faea0
    cpu.esp -= 4;
    sub_4faea0(app, cpu);
    if (cpu.terminate) return;
    // 004fad81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fad83  0f8409010000           -je 0x4fae92
    if (cpu.flags.zf)
    {
        goto L_0x004fae92;
    }
    // 004fad89  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fad8b  7535                   -jne 0x4fadc2
    if (!cpu.flags.zf)
    {
        goto L_0x004fadc2;
    }
    // 004fad8d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004fad92  a1204f9f00             -mov eax, dword ptr [0x9f4f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fad97  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fad9d  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004fada2  a1244f9f00             -mov eax, dword ptr [0x9f4f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fada7  890d084f9f00           -mov dword ptr [0x9f4f08], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.ecx;
    // 004fadad  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004fadb2  a11c4f9f00             -mov eax, dword ptr [0x9f4f1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fadb7  891d144f9f00           -mov dword ptr [0x9f4f14], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.ebx;
    // 004fadbd  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
L_0x004fadc2:
    // 004fadc2  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fadc7  8b1dec4e9f00           -mov ebx, dword ptr [0x9f4eec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004fadcd  8b3d204f9f00           -mov edi, dword ptr [0x9f4f20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fadd3  8b2dfc4e9f00           -mov ebp, dword ptr [0x9f4efc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004fadd9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004faddc  49                     -dec ecx
    (cpu.ecx)--;
    // 004faddd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004faddf  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fade1  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fade6  891dec4e9f00           -mov dword ptr [0x9f4eec], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.ebx;
    // 004fadec  893d204f9f00           -mov dword ptr [0x9f4f20], edi
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.edi;
    // 004fadf2  8b1d244f9f00           -mov ebx, dword ptr [0x9f4f24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fadf8  8b3d004f9f00           -mov edi, dword ptr [0x9f4f00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004fadfe  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fae00  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fae02  891d244f9f00           -mov dword ptr [0x9f4f24], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.ebx;
    // 004fae08  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae0e  892dfc4e9f00           -mov dword ptr [0x9f4efc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.ebp;
    // 004fae14  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fae16  8b2d1c4f9f00           -mov ebp, dword ptr [0x9f4f1c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fae1c  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fae22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fae24  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae26  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae28  893d004f9f00           -mov dword ptr [0x9f4f00], edi
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.edi;
    // 004fae2e  892d1c4f9f00           -mov dword ptr [0x9f4f1c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.ebp;
    // 004fae34  8b3d0c4f9f00           -mov edi, dword ptr [0x9f4f0c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */);
    // 004fae3a  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae3c  39f9                   +cmp ecx, edi
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
    // 004fae3e  0f8d38ffffff           -jge 0x4fad7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fad7c;
    }
L_0x004fae44:
    // 004fae44  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fae4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fae53:
    // 004fae53  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fae58  a3084f9f00             -mov dword ptr [0x9f4f08], eax
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.eax;
    // 004fae5d  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fae62  48                     -dec eax
    (cpu.eax)--;
    // 004fae63  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004fae65  a3104f9f00             -mov dword ptr [0x9f4f10], eax
    app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */) = cpu.eax;
    // 004fae6a  a1d84e9f00             -mov eax, dword ptr [0x9f4ed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440408) /* 0x9f4ed8 */);
    // 004fae6f  890d0c4f9f00           -mov dword ptr [0x9f4f0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */) = cpu.ecx;
    // 004fae75  a3144f9f00             -mov dword ptr [0x9f4f14], eax
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.eax;
    // 004fae7a  e977fdffff             -jmp 0x4fabf6
    goto L_0x004fabf6;
L_0x004fae7f:
    // 004fae7f  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fae87  0f8585feffff           -jne 0x4fad12
    if (!cpu.flags.zf)
    {
        goto L_0x004fad12;
    }
    // 004fae8d  e906feffff             -jmp 0x4fac98
    goto L_0x004fac98;
L_0x004fae92:
    // 004fae92  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fae94  75ae                   -jne 0x4fae44
    if (!cpu.flags.zf)
    {
        goto L_0x004fae44;
    }
    // 004fae96  e927ffffff             -jmp 0x4fadc2
    goto L_0x004fadc2;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4faea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004faea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004faea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004faea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004faea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004faea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004faea5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004faea6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004faea9  8b15b04e9f00           -mov edx, dword ptr [0x9f4eb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004faeaf  8b2dc04e9f00           -mov ebp, dword ptr [0x9f4ec0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004faeb5  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004faeb9  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004faebb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004faebd  0f8582000000           -jne 0x4faf45
    if (!cpu.flags.zf)
    {
        goto L_0x004faf45;
    }
L_0x004faec3:
    // 004faec3  8b0d284f9f00           -mov ecx, dword ptr [0x9f4f28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */);
    // 004faec9  8b15004f9f00           -mov edx, dword ptr [0x9f4f00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004faecf  8b35344f9f00           -mov esi, dword ptr [0x9f4f34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */);
    // 004faed5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004faed7  a1ec4e9f00             -mov eax, dword ptr [0x9f4eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004faedc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004faedf  8b1d304f9f00           -mov ebx, dword ptr [0x9f4f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440496) /* 0x9f4f30 */);
    // 004faee5  8b3dfc4e9f00           -mov edi, dword ptr [0x9f4efc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004faeeb  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004faeef  39d9                   +cmp ecx, ebx
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
    // 004faef1  7f34                   -jg 0x4faf27
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004faf27;
    }
L_0x004faef3:
    // 004faef3  3b10                   +cmp edx, dword ptr [eax]
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
    // 004faef5  0f8376000000           -jae 0x4faf71
    if (!cpu.flags.cf)
    {
        goto L_0x004faf71;
    }
    // 004faefb  3b0d284f9f00           +cmp ecx, dword ptr [0x9f4f28]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004faf01  7e1d                   -jle 0x4faf20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004faf20;
    }
    // 004faf03  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004faf08  893dfc4e9f00           -mov dword ptr [0x9f4efc], edi
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.edi;
    // 004faf0e  8915004f9f00           -mov dword ptr [0x9f4f00], edx
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.edx;
    // 004faf14  8935344f9f00           -mov dword ptr [0x9f4f34], esi
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.esi;
    // 004faf1a  890d284f9f00           -mov dword ptr [0x9f4f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.ecx;
L_0x004faf20:
    // 004faf20  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x004faf27:
    // 004faf27  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004faf2b  7f5b                   -jg 0x4faf88
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004faf88;
    }
    // 004faf2d  3b10                   +cmp edx, dword ptr [eax]
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
    // 004faf2f  7357                   -jae 0x4faf88
    if (!cpu.flags.cf)
    {
        goto L_0x004faf88;
    }
    // 004faf31  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004faf35  41                     -inc ecx
    (cpu.ecx)++;
    // 004faf36  47                     -inc edi
    (cpu.edi)++;
    // 004faf37  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004faf39  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004faf3c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faf3e  885fff                 -mov byte ptr [edi - 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004faf41  01ee                   +add esi, ebp
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004faf43  ebe2                   -jmp 0x4faf27
    goto L_0x004faf27;
L_0x004faf45:
    // 004faf45  a1e84e9f00             -mov eax, dword ptr [0x9f4ee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faf4a  a3284f9f00             -mov dword ptr [0x9f4f28], eax
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.eax;
    // 004faf4f  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faf54  48                     -dec eax
    (cpu.eax)--;
    // 004faf55  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004faf57  a3304f9f00             -mov dword ptr [0x9f4f30], eax
    app->getMemory<x86::reg32>(x86::reg32(10440496) /* 0x9f4f30 */) = cpu.eax;
    // 004faf5c  a1d44e9f00             -mov eax, dword ptr [0x9f4ed4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440404) /* 0x9f4ed4 */);
    // 004faf61  890d2c4f9f00           -mov dword ptr [0x9f4f2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440492) /* 0x9f4f2c */) = cpu.ecx;
    // 004faf67  a3344f9f00             -mov dword ptr [0x9f4f34], eax
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.eax;
    // 004faf6c  e952ffffff             -jmp 0x4faec3
    goto L_0x004faec3;
L_0x004faf71:
    // 004faf71  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004faf75  41                     -inc ecx
    (cpu.ecx)++;
    // 004faf76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004faf79  47                     -inc edi
    (cpu.edi)++;
    // 004faf7a  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faf7c  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004faf7e  39d9                   +cmp ecx, ebx
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
    // 004faf80  0f8e6dffffff           -jle 0x4faef3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004faef3;
    }
    // 004faf86  eb9f                   -jmp 0x4faf27
    goto L_0x004faf27;
L_0x004faf88:
    // 004faf88  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004faf8b  a12c4f9f00             -mov eax, dword ptr [0x9f4f2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440492) /* 0x9f4f2c */);
    // 004faf90  8b35284f9f00           -mov esi, dword ptr [0x9f4f28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */);
    // 004faf96  8b0d344f9f00           -mov ecx, dword ptr [0x9f4f34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */);
    // 004faf9c  8b15ec4e9f00           -mov edx, dword ptr [0x9f4eec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004fafa2  8b3dfc4e9f00           -mov edi, dword ptr [0x9f4efc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004fafa8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fafac  4e                     -dec esi
    (cpu.esi)--;
    // 004fafad  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafb0  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafb2  a1004f9f00             -mov eax, dword ptr [0x9f4f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004fafb7  4f                     -dec edi
    (cpu.edi)--;
    // 004fafb8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fafba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fafbc  7506                   -jne 0x4fafc4
    if (!cpu.flags.zf)
    {
        goto L_0x004fafc4;
    }
L_0x004fafbe:
    // 004fafbe  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafc2  7d1e                   -jge 0x4fafe2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fafe2;
    }
L_0x004fafc4:
    // 004fafc4  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafc8  7c4e                   -jl 0x4fb018
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb018;
    }
    // 004fafca  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafcc  734a                   -jae 0x4fb018
    if (!cpu.flags.cf)
    {
        goto L_0x004fb018;
    }
    // 004fafce  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fafd2  4e                     -dec esi
    (cpu.esi)--;
    // 004fafd3  4f                     -dec edi
    (cpu.edi)--;
    // 004fafd4  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafd6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fafd8  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafdb  29c8                   +sub eax, ecx
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
    // 004fafdd  885f01                 -mov byte ptr [edi + 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004fafe0  ebe2                   -jmp 0x4fafc4
    goto L_0x004fafc4;
L_0x004fafe2:
    // 004fafe2  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafe4  720b                   -jb 0x4faff1
    if (cpu.flags.cf)
    {
        goto L_0x004faff1;
    }
    // 004fafe6  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafe9  4f                     -dec edi
    (cpu.edi)--;
    // 004fafea  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafec  4e                     -dec esi
    (cpu.esi)--;
    // 004fafed  29c8                   +sub eax, ecx
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
    // 004fafef  ebcd                   -jmp 0x4fafbe
    goto L_0x004fafbe;
L_0x004faff1:
    // 004faff1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004faff6  8915ec4e9f00           -mov dword ptr [0x9f4eec], edx
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.edx;
    // 004faffc  893dfc4e9f00           -mov dword ptr [0x9f4efc], edi
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.edi;
    // 004fb002  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fb007  890d344f9f00           -mov dword ptr [0x9f4f34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.ecx;
    // 004fb00d  8935284f9f00           -mov dword ptr [0x9f4f28], esi
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.esi;
    // 004fb013  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004fb016  ebac                   -jmp 0x4fafc4
    goto L_0x004fafc4;
L_0x004fb018:
    // 004fb018  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb01b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fb01e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb01f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb020  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb021  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb022  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb023  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb024  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fb030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb031  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fb035  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fb038  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fb03b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fb03d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb03f  7e0f                   -jle 0x4fb050
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb050;
    }
L_0x004fb041:
    // 004fb041  48                     -dec eax
    (cpu.eax)--;
    // 004fb042  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004fb048  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb04b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb04d  7ff2                   -jg 0x4fb041
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fb041;
    }
    // 004fb04f  90                     -nop 
    ;
L_0x004fb050:
    // 004fb050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fb060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb060  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb061  8b15c0505600           -mov edx, dword ptr [0x5650c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 004fb067  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb069  7502                   -jne 0x4fb06d
    if (!cpu.flags.zf)
    {
        goto L_0x004fb06d;
    }
    // 004fb06b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb06c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb06d:
    // 004fb06d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb06e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fb070  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb072  e81968feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fb077  890dc0505600           -mov dword ptr [0x5650c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */) = cpu.ecx;
    // 004fb07d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb07e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb07f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb086  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb088  baecdb5400             -mov edx, 0x54dbec
    cpu.edx = 5561324 /*0x54dbec*/;
    // 004fb08d  b9fcdb5400             -mov ecx, 0x54dbfc
    cpu.ecx = 5561340 /*0x54dbfc*/;
    // 004fb092  bb73000000             -mov ebx, 0x73
    cpu.ebx = 115 /*0x73*/;
    // 004fb097  b80cdc5400             -mov eax, 0x54dc0c
    cpu.eax = 5561356 /*0x54dc0c*/;
    // 004fb09c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fb0a2  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fb0a8  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 004fb0ad  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fb0b3  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fb0b9  e86265feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fb0be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb0c0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fb0c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb0c4  7509                   -jne 0x4fb0cf
    if (!cpu.flags.zf)
    {
        goto L_0x004fb0cf;
    }
    // 004fb0c6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb0c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb0cf:
    // 004fb0cf  beecdb5400             -mov esi, 0x54dbec
    cpu.esi = 5561324 /*0x54dbec*/;
    // 004fb0d4  b8fcdb5400             -mov eax, 0x54dbfc
    cpu.eax = 5561340 /*0x54dbfc*/;
    // 004fb0d9  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 004fb0de  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fb0e4  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fb0e9  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fb0ef  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 004fb0f4  b818dc5400             -mov eax, 0x54dc18
    cpu.eax = 5561368 /*0x54dc18*/;
    // 004fb0f9  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fb0ff  e81c65feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fb104  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb108  750b                   -jne 0x4fb115
    if (!cpu.flags.zf)
    {
        goto L_0x004fb115;
    }
    // 004fb10a  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb10c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb10e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb10f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb110  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb111  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb112  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb113  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb114  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb115:
    // 004fb115  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004fb11a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb11b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb11d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb11f  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb124  e807f7ffff             -call 0x4fa830
    cpu.esp -= 4;
    sub_4fa830(app, cpu);
    if (cpu.terminate) return;
    // 004fb129  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb12b  e86067feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fb130  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb132  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb133  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb134  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb135  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb137  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb138  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fb140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb141  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb142  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb148  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb14a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fb14c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb151  e80a2d0200             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 004fb156  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb158  e823ffffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb15d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb164  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fb170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb172  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb178  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb17a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fb17c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb181  e8da2d0200             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 004fb186  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb188  e8f3feffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb18d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb193  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb194  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fb1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb1a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb1a3  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb1a9  e8b2feffff             -call 0x4fb060
    cpu.esp -= 4;
    sub_4fb060(app, cpu);
    if (cpu.terminate) return;
    // 004fb1ae  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb1b0  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004fb1b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb1b7  e8548d0000             -call 0x503f10
    cpu.esp -= 4;
    sub_503f10(app, cpu);
    if (cpu.terminate) return;
    // 004fb1bc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb1be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb1c0  e8bbfeffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb1c5  a3c0505600             -mov dword ptr [0x5650c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */) = cpu.eax;
    // 004fb1ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb1cc  7405                   -je 0x4fb1d3
    if (cpu.flags.zf)
    {
        goto L_0x004fb1d3;
    }
    // 004fb1ce  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004fb1d3:
    // 004fb1d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fb1d5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4fb1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb1e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb1e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb1e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb1e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb1e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb1e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fb1e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fb1e9  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004fb1f0  0f849c000000           -je 0x4fb292
    if (cpu.flags.zf)
    {
        goto L_0x004fb292;
    }
    // 004fb1f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb1f8  0f8c9b000000           -jl 0x4fb299
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb299;
    }
    // 004fb1fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fb200:
    // 004fb200  e86b730000             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 004fb205  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb207  0f8596000000           -jne 0x4fb2a3
    if (!cpu.flags.zf)
    {
        goto L_0x004fb2a3;
    }
    // 004fb20d  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004fb214  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fb216  8b14853ca1a000         -mov edx, dword ptr [eax*4 + 0xa0a13c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4);
    // 004fb21d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fb21f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fb221  0f8c83000000           -jl 0x4fb2aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb2aa;
    }
L_0x004fb227:
    // 004fb227  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb229  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004fb22d  39c1                   +cmp ecx, eax
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
    // 004fb22f  0f8da9000000           -jge 0x4fb2de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb2de;
    }
    // 004fb235  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004fb238  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fb23a  7437                   -je 0x4fb273
    if (cpu.flags.zf)
    {
        goto L_0x004fb273;
    }
    // 004fb23c  3c04                   +cmp al, 4
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
    // 004fb23e  7433                   -je 0x4fb273
    if (cpu.flags.zf)
    {
        goto L_0x004fb273;
    }
    // 004fb240  c7059021550024dc5400   -mov dword ptr [0x552190], 0x54dc24
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5561380 /*0x54dc24*/;
    // 004fb24a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb24c  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004fb24f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb250  be34dc5400             -mov esi, 0x54dc34
    cpu.esi = 5561396 /*0x54dc34*/;
    // 004fb255  bf47000000             -mov edi, 0x47
    cpu.edi = 71 /*0x47*/;
    // 004fb25a  6878dc5400             -push 0x54dc78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561464 /*0x54dc78*/;
    cpu.esp -= 4;
    // 004fb25f  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fb265  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fb26b  e8a05df0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb270  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004fb273:
    // 004fb273  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fb27a  807a0404               +cmp byte ptr [edx + 4], 4
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
    // 004fb27e  7562                   -jne 0x4fb2e2
    if (!cpu.flags.zf)
    {
        goto L_0x004fb2e2;
    }
    // 004fb280  837c031400             +cmp dword ptr [ebx + eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb285  7457                   -je 0x4fb2de
    if (cpu.flags.zf)
    {
        goto L_0x004fb2de;
    }
    // 004fb287  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fb28c:
    // 004fb28c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb291  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb292:
    // 004fb292  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004fb297  ebf3                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb299:
    // 004fb299  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb29e  e95dffffff             -jmp 0x4fb200
    goto L_0x004fb200;
L_0x004fb2a3:
    // 004fb2a3  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004fb2a8  ebe2                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb2aa:
    // 004fb2aa  be24dc5400             -mov esi, 0x54dc24
    cpu.esi = 5561380 /*0x54dc24*/;
    // 004fb2af  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb2b0  bf34dc5400             -mov edi, 0x54dc34
    cpu.edi = 5561396 /*0x54dc34*/;
    // 004fb2b5  bd3b000000             -mov ebp, 0x3b
    cpu.ebp = 59 /*0x3b*/;
    // 004fb2ba  6848dc5400             -push 0x54dc48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561416 /*0x54dc48*/;
    cpu.esp -= 4;
    // 004fb2bf  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fb2c5  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004fb2cb  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004fb2d1  e83a5df0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb2d6  83c408                 +add esp, 8
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
    // 004fb2d9  e949ffffff             -jmp 0x4fb227
    goto L_0x004fb227;
L_0x004fb2de:
    // 004fb2de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fb2e0  ebaa                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb2e2:
    // 004fb2e2  837c020c00             +cmp dword ptr [edx + eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb2e7  74f5                   -je 0x4fb2de
    if (cpu.flags.zf)
    {
        goto L_0x004fb2de;
    }
    // 004fb2e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb2ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fb300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb302  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fb303  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004fb305  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004fb307  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb308  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb30b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb30d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004fb30f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fb313  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fb316  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb318  744c                   -je 0x4fb366
    if (cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb31a  4b                     -dec ebx
    (cpu.ebx)--;
    // 004fb31b  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004fb31e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fb320  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004fb323  39f2                   +cmp edx, esi
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
    // 004fb325  732c                   -jae 0x4fb353
    if (!cpu.flags.cf)
    {
        goto L_0x004fb353;
    }
L_0x004fb327:
    // 004fb327  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb329  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb32b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb32d  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004fb32f  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004fb331  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004fb334  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004fb337  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fb339  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fb33b  ff1424                 -call dword ptr [esp]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb33e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb340  7504                   -jne 0x4fb346
    if (!cpu.flags.zf)
    {
        goto L_0x004fb346;
    }
    // 004fb342  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fb344  eb22                   -jmp 0x4fb368
    goto L_0x004fb368;
L_0x004fb346:
    // 004fb346  7d04                   -jge 0x4fb34c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb34c;
    }
    // 004fb348  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fb34a  eb03                   -jmp 0x4fb34f
    goto L_0x004fb34f;
L_0x004fb34c:
    // 004fb34c  8d0c3b                 -lea ecx, [ebx + edi]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.edi * 1);
L_0x004fb34f:
    // 004fb34f  39f1                   +cmp ecx, esi
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
    // 004fb351  72d4                   -jb 0x4fb327
    if (cpu.flags.cf)
    {
        goto L_0x004fb327;
    }
L_0x004fb353:
    // 004fb353  39f1                   +cmp ecx, esi
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
    // 004fb355  750f                   -jne 0x4fb366
    if (!cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb357  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fb359  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fb35b  ff1424                 -call dword ptr [esp]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb35e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb360  7504                   -jne 0x4fb366
    if (!cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb362  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb364  eb02                   -jmp 0x4fb368
    goto L_0x004fb368;
L_0x004fb366:
    // 004fb366  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fb368:
    // 004fb368  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb36b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb36c  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb36e  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb370  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb371  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb372  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb373  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fb380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb380  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb385  a36c435600             -mov dword ptr [0x56436c], eax
    app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */) = cpu.eax;
    // 004fb38a  a1384f9f00             -mov eax, dword ptr [0x9f4f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb38f  a370435600             -mov dword ptr [0x564370], eax
    app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */) = cpu.eax;
    // 004fb394  a1544f9f00             -mov eax, dword ptr [0x9f4f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb399  a374435600             -mov dword ptr [0x564374], eax
    app->getMemory<x86::reg32>(x86::reg32(5653364) /* 0x564374 */) = cpu.eax;
    // 004fb39e  a174435600             -mov eax, dword ptr [0x564374]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653364) /* 0x564374 */);
    // 004fb3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fb3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3b0  ff05484f9f00           -inc dword ptr [0x9f4f48]
    (app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */))++;
    // 004fb3b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3c0  ff0d484f9f00           -dec dword ptr [0x9f4f48]
    (app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */))--;
    // 004fb3c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb3d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb3d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb3d3  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004fb3d8  bfc0b34f00             -mov edi, 0x4fb3c0
    cpu.edi = 5223360 /*0x4fb3c0*/;
    // 004fb3dd  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 004fb3e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb3e4  a3444f9f00             -mov dword ptr [0x9f4f44], eax
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.eax;
    // 004fb3e9  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb3ef  8915484f9f00           -mov dword ptr [0x9f4f48], edx
    app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */) = cpu.edx;
    // 004fb3f5  89154c4f9f00           -mov dword ptr [0x9f4f4c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.edx;
    // 004fb3fb  893568435600           -mov dword ptr [0x564368], esi
    app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */) = cpu.esi;
    // 004fb401  893d5c445600           -mov dword ptr [0x56445c], edi
    app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */) = cpu.edi;
    // 004fb407  893d60445600           -mov dword ptr [0x564460], edi
    app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */) = cpu.edi;
    // 004fb40d  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 004fb412  ba80b34f00             -mov edx, 0x4fb380
    cpu.edx = 5223296 /*0x4fb380*/;
    // 004fb417  a3404f9f00             -mov dword ptr [0x9f4f40], eax
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.eax;
    // 004fb41c  b8b0b34f00             -mov eax, 0x4fb3b0
    cpu.eax = 5223344 /*0x4fb3b0*/;
    // 004fb421  891568445600           -mov dword ptr [0x564468], edx
    app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */) = cpu.edx;
    // 004fb427  a364445600             -mov dword ptr [0x564464], eax
    app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */) = cpu.eax;
    // 004fb42c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb42e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb42f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb430  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb431  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fb440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb536(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb536;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
L_entry_0x004fb536:
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb527(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb527;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
L_entry_0x004fb527:
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb51b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb51b;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004fb51b:
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb50b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb50b;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
L_entry_0x004fb50b:
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4ea;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
L_entry_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4d0;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_entry_0x004fb4d0:
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4c0;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
L_entry_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb470;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x004fb470:
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
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
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fb560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb560  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb562  7510                   -jne 0x4fb574
    if (!cpu.flags.zf)
    {
        goto L_0x004fb574;
    }
L_0x004fb564:
    // 004fb564  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb566  7407                   -je 0x4fb56f
    if (cpu.flags.zf)
    {
        goto L_0x004fb56f;
    }
    // 004fb568  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb56d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004fb56f:
    // 004fb56f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb571  750d                   -jne 0x4fb580
    if (!cpu.flags.zf)
    {
        goto L_0x004fb580;
    }
    // 004fb573  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb574:
    // 004fb574  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb575  8b0d544f9f00           -mov ecx, dword ptr [0x9f4f54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb57b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004fb57d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb57e  ebe4                   -jmp 0x4fb564
    goto L_0x004fb564;
L_0x004fb580:
    // 004fb580  a1384f9f00             -mov eax, dword ptr [0x9f4f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb585  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004fb587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fb590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb590  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb5a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb5a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb5a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb5a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb5a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb5a5  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fb5a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fb5aa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fb5ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb5ae  e87d43feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fb5b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb5b5  0f85a5000000           -jne 0x4fb660
    if (!cpu.flags.zf)
    {
        goto L_0x004fb660;
    }
    // 004fb5bb  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004fb5c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb5c2  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fb5c8:
    // 004fb5c8  8b0d4c4f9f00           -mov ecx, dword ptr [0x9f4f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb5ce  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb5d0  0f8e9b000000           -jle 0x4fb671
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb671;
    }
    // 004fb5d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004fb5d8:
    // 004fb5d8  8b3d444f9f00           -mov edi, dword ptr [0x9f4f44]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb5de  39f8                   +cmp eax, edi
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
    // 004fb5e0  0f8d99000000           -jge 0x4fb67f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb67f;
    }
    // 004fb5e6  8b2d4c4f9f00           -mov ebp, dword ptr [0x9f4f4c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb5ec  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb5ee  0f8e84000000           -jle 0x4fb678
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb678;
    }
    // 004fb5f4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004fb5f6:
    // 004fb5f6  a1504f9f00             -mov eax, dword ptr [0x9f4f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb5fb  39c6                   +cmp esi, eax
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
    // 004fb5fd  7e02                   -jle 0x4fb601
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb601;
    }
    // 004fb5ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004fb601:
    // 004fb601  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb607  39c8                   +cmp eax, ecx
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
    // 004fb609  0f8d77000000           -jge 0x4fb686
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb686;
    }
    // 004fb60f  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb615  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb617  7e02                   -jle 0x4fb61b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb61b;
    }
    // 004fb619  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004fb61b:
    // 004fb61b  89156c435600           -mov dword ptr [0x56436c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */) = cpu.edx;
    // 004fb621  a16c435600             -mov eax, dword ptr [0x56436c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */);
    // 004fb626  a33c4f9f00             -mov dword ptr [0x9f4f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.eax;
    // 004fb62b  891d70435600           -mov dword ptr [0x564370], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */) = cpu.ebx;
    // 004fb631  a170435600             -mov eax, dword ptr [0x564370]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */);
    // 004fb636  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb63b  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb640  e84b12fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb645  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb647  e8e442feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fb64c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb64e  743a                   -je 0x4fb68a
    if (cpu.flags.zf)
    {
        goto L_0x004fb68a;
    }
    // 004fb650  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb652  e8a990ffff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 004fb657  83c470                 +add esp, 0x70
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
    // 004fb65a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb660:
    // 004fb660  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb662  e86990ffff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 004fb667  e824f7feff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004fb66c  e957ffffff             -jmp 0x4fb5c8
    goto L_0x004fb5c8;
L_0x004fb671:
    // 004fb671  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fb673  e960ffffff             -jmp 0x4fb5d8
    goto L_0x004fb5d8;
L_0x004fb678:
    // 004fb678  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb67a  e977ffffff             -jmp 0x4fb5f6
    goto L_0x004fb5f6;
L_0x004fb67f:
    // 004fb67f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fb681  e970ffffff             -jmp 0x4fb5f6
    goto L_0x004fb5f6;
L_0x004fb686:
    // 004fb686  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fb688  eb91                   -jmp 0x4fb61b
    goto L_0x004fb61b;
L_0x004fb68a:
    // 004fb68a  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004fb690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb691  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb697  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fb69a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6a0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb6a2  e919feffff             -jmp 0x4fb4c0
    return sub_4fb4c0(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fb6a9  e922feffff             -jmp 0x4fb4d0
    return sub_4fb4d0(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6ae  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fb6b0  e935feffff             -jmp 0x4fb4ea
    return sub_4fb4ea(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6b5  39fb                   +cmp ebx, edi
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
    // 004fb6b7  0f854efeffff           -jne 0x4fb50b
    if (!cpu.flags.zf)
    {
        return sub_4fb50b(app, cpu);
    }
    // 004fb6bd  e959feffff             -jmp 0x4fb51b
    return sub_4fb51b(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6c2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb6c6  3b05384f9f00           +cmp eax, dword ptr [0x9f4f38]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb6cc  0f8555feffff           -jne 0x4fb527
    if (!cpu.flags.zf)
    {
        return sub_4fb527(app, cpu);
    }
    // 004fb6d2  e95ffeffff             -jmp 0x4fb536
    return sub_4fb536(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6d7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb6db  ff156c445600           -call dword ptr [0x56446c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb6e1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb6e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb6e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb6e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb6e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fb6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb6f1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004fb6f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fb6f8  e813000000             -call 0x4fb710
    cpu.esp -= 4;
    sub_4fb710(app, cpu);
    if (cpu.terminate) return;
    // 004fb6fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb6fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fb700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb700  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb701  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb706  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb708  e803000000             -call 0x4fb710
    cpu.esp -= 4;
    sub_4fb710(app, cpu);
    if (cpu.terminate) return;
    // 004fb70d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb70e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fb710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb713  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb714  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb715  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb718  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fb71b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004fb720  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004fb722  83f801                 +cmp eax, 1
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
    // 004fb725  7328                   -jae 0x4fb74f
    if (!cpu.flags.cf)
    {
        goto L_0x004fb74f;
    }
    // 004fb727  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb729  751b                   -jne 0x4fb746
    if (!cpu.flags.zf)
    {
        goto L_0x004fb746;
    }
    // 004fb72b  b33a                   -mov bl, 0x3a
    cpu.bl = 58 /*0x3a*/;
    // 004fb72d  b014                   -mov al, 0x14
    cpu.al = 20 /*0x14*/;
L_0x004fb72f:
    // 004fb72f  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 004fb732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb733  2eff1544475300         -call dword ptr cs:[0x534744]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457732) /* 0x534744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb73a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004fb73c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004fb73e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb741  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004fb742  39d0                   +cmp eax, edx
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
    // 004fb744  7525                   -jne 0x4fb76b
    if (!cpu.flags.zf)
    {
        goto L_0x004fb76b;
    }
L_0x004fb746:
    // 004fb746  83c404                 +add esp, 4
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
    // 004fb749  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb74a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb74b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb74c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb74d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb74e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb74f:
    // 004fb74f  7710                   -ja 0x4fb761
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fb761;
    }
    // 004fb751  b345                   -mov bl, 0x45
    cpu.bl = 69 /*0x45*/;
    // 004fb753  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004fb758  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 004fb75d  b090                   -mov al, 0x90
    cpu.al = 144 /*0x90*/;
    // 004fb75f  ebce                   -jmp 0x4fb72f
    goto L_0x004fb72f;
L_0x004fb761:
    // 004fb761  39e8                   +cmp eax, ebp
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
    // 004fb763  75e1                   -jne 0x4fb746
    if (!cpu.flags.zf)
    {
        goto L_0x004fb746;
    }
    // 004fb765  b346                   -mov bl, 0x46
    cpu.bl = 70 /*0x46*/;
    // 004fb767  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 004fb769  ebc4                   -jmp 0x4fb72f
    goto L_0x004fb72f;
L_0x004fb76b:
    // 004fb76b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fb76d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb76e  0fb6fb                 -movzx edi, bl
    cpu.edi = x86::reg32(cpu.bl);
    // 004fb771  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb772  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb773  2eff15ac475300         -call dword ptr cs:[0x5347ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457836) /* 0x5347ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb77a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fb77c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb77d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb77e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb77f  2eff15ac475300         -call dword ptr cs:[0x5347ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457836) /* 0x5347ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb786  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb789  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb78a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb78b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb78c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb78d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb78e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4fb790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb792  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb793  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb794  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb795  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fb798  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb79a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004fb79c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fb79e  803800                 +cmp byte ptr [eax], 0
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
    // 004fb7a1  7529                   -jne 0x4fb7cc
    if (!cpu.flags.zf)
    {
        goto L_0x004fb7cc;
    }
    // 004fb7a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fb7a8:
    // 004fb7a8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004fb7aa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb7ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb7ae  7520                   -jne 0x4fb7d0
    if (!cpu.flags.zf)
    {
        goto L_0x004fb7d0;
    }
    // 004fb7b0  8d4114                 -lea eax, [ecx + 0x14]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004fb7b3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fb7b5  e8562bffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004fb7ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb7bc  7412                   -je 0x4fb7d0
    if (cpu.flags.zf)
    {
        goto L_0x004fb7d0;
    }
    // 004fb7be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb7c3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fb7c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb7cc:
    // 004fb7cc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fb7ce  ebd8                   -jmp 0x4fb7a8
    goto L_0x004fb7a8;
L_0x004fb7d0:
    // 004fb7d0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb7d4  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004fb7d6  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004fb7d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb7da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fb7dc  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004fb7df  e85ce8feff             -call 0x4ea040
    cpu.esp -= 4;
    sub_4ea040(app, cpu);
    if (cpu.terminate) return;
    // 004fb7e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb7e6  750b                   -jne 0x4fb7f3
    if (!cpu.flags.zf)
    {
        goto L_0x004fb7f3;
    }
    // 004fb7e8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fb7ea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fb7ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb7f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb7f3:
    // 004fb7f3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb7f6  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004fb7f9  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004fb7fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb7fd  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004fb800  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb802  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fb804  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb808  e83389feff             -call 0x4e4140
    cpu.esp -= 4;
    sub_4e4140(app, cpu);
    if (cpu.terminate) return;
    // 004fb80d  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004fb810  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb812  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fb815  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb816  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb817  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb818  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb819  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb81a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fb820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb820  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004fb823  7506                   -jne 0x4fb82b
    if (!cpu.flags.zf)
    {
        goto L_0x004fb82b;
    }
    // 004fb825  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb82a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb82b:
    // 004fb82b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb82d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb82b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb82b;
    // 004fb820  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004fb823  7506                   -jne 0x4fb82b
    if (!cpu.flags.zf)
    {
        goto L_0x004fb82b;
    }
    // 004fb825  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb82a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb82b:
L_entry_0x004fb82b:
    // 004fb82b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb82d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fb830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb830  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb831  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb833  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb835  8a4111                 -mov al, byte ptr [ecx + 0x11]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004fb838  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004fb83b  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004fb83e  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004fb841  81e1ffffff00           -and ecx, 0xffffff
    cpu.ecx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004fb847  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb84a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fb850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb850  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004fb853  75d6                   -jne 0x4fb82b
    if (!cpu.flags.zf)
    {
        return sub_4fb82b(app, cpu);
    }
    // 004fb855  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb85a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fb860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb860  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb861  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb862  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb863  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb864  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fb866  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fb869  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fb86b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fb86e  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004fb871  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb876  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004fb879  8b1406                 -mov edx, dword ptr [esi + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 004fb87c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb87e  7405                   -je 0x4fb885
    if (cpu.flags.zf)
    {
        goto L_0x004fb885;
    }
    // 004fb880  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb881  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb882  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb883  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb885:
    // 004fb885  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb886  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb887  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fb88c  e88f310100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fb891  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb893  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb898  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fb89a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fb89c  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004fb89f  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fb8a2  ba30b84f00             -mov edx, 0x4fb830
    cpu.edx = 5224496 /*0x4fb830*/;
    // 004fb8a7  e824240100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004fb8ac  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb8b1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fb8b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fb8b5  8d481c                 -lea ecx, [eax + 0x1c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004fb8b8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb8ba  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004fb8bd  e89e240100             -call 0x50dd60
    cpu.esp -= 4;
    sub_50dd60(app, cpu);
    if (cpu.terminate) return;
    // 004fb8c2  e83942feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004fb8c7  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb8cd  89443154               -mov dword ptr [ecx + esi + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */ + cpu.esi * 1) = cpu.eax;
    // 004fb8d1  e83a43feff             -call 0x4dfc10
    cpu.esp -= 4;
    sub_4dfc10(app, cpu);
    if (cpu.terminate) return;
    // 004fb8d6  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb8dc  8944315c               -mov dword ptr [ecx + esi + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */ + cpu.esi * 1) = cpu.eax;
    // 004fb8e0  e8fbf9feff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004fb8e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb8e7  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb8ec  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fb8ee  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb8f1  c7405c01000000         -mov dword ptr [eax + 0x5c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 1 /*0x1*/;
    // 004fb8f8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fb8fd  894854                 -mov dword ptr [eax + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 004fb900  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb902  c74060ff000000         -mov dword ptr [eax + 0x60], 0xff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = 255 /*0xff*/;
    // 004fb909  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004fb90e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb90f  b8a0bd4f00             -mov eax, 0x4fbda0
    cpu.eax = 5225888 /*0x4fbda0*/;
    // 004fb914  893d644f9f00           -mov dword ptr [0x9f4f64], edi
    app->getMemory<x86::reg32>(x86::reg32(10440548) /* 0x9f4f64 */) = cpu.edi;
    // 004fb91a  e8813efeff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004fb91f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb921  7427                   -je 0x4fb94a
    if (cpu.flags.zf)
    {
        goto L_0x004fb94a;
    }
    // 004fb923  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fb928  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fb92a  833e00                 +cmp dword ptr [esi], 0
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
    // 004fb92d  7508                   -jne 0x4fb937
    if (!cpu.flags.zf)
    {
        goto L_0x004fb937;
    }
    // 004fb92f  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004fb932  e82943feff             -call 0x4dfc60
    cpu.esp -= 4;
    sub_4dfc60(app, cpu);
    if (cpu.terminate) return;
L_0x004fb937:
    // 004fb937  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fb93c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb93e  e8fd300100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fb943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb944  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb945  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb948  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb949  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb94a:
    // 004fb94a  b9acdc5400             -mov ecx, 0x54dcac
    cpu.ecx = 5561516 /*0x54dcac*/;
    // 004fb94f  bbb8dc5400             -mov ebx, 0x54dcb8
    cpu.ebx = 5561528 /*0x54dcb8*/;
    // 004fb954  beb6000000             -mov esi, 0xb6
    cpu.esi = 182 /*0xb6*/;
    // 004fb959  68ccdc5400             -push 0x54dccc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561548 /*0x54dccc*/;
    cpu.esp -= 4;
    // 004fb95e  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004fb964  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004fb96a  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004fb970  e89b56f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb975  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb978  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fb97d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb97f  e8bc300100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fb984  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb985  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb986  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb987  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb988  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb989  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb98a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fb990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb990  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb991  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb992  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb993  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb996  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fb998  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fb99b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004fb99d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fb99f  833d604f9f0000         +cmp dword ptr [0x9f4f60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb9a6  0f8440010000           -je 0x4fbaec
    if (cpu.flags.zf)
    {
        goto L_0x004fbaec;
    }
L_0x004fb9ac:
    // 004fb9ac  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb9af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb9b1  7c08                   -jl 0x4fb9bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb9bb;
    }
    // 004fb9b3  81faff000000           +cmp edx, 0xff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb9b9  7e31                   -jle 0x4fb9ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb9ec;
    }
L_0x004fb9bb:
    // 004fb9bb  beacdc5400             -mov esi, 0x54dcac
    cpu.esi = 5561516 /*0x54dcac*/;
    // 004fb9c0  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb9c3  b810dd5400             -mov eax, 0x54dd10
    cpu.eax = 5561616 /*0x54dd10*/;
    // 004fb9c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb9c9  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004fb9ce  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fb9d4  6864dd5400             -push 0x54dd64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561700 /*0x54dd64*/;
    cpu.esp -= 4;
    // 004fb9d9  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fb9de  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fb9e4  e82756f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb9e9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004fb9ec:
    // 004fb9ec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb9ee  7c05                   -jl 0x4fb9f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb9f5;
    }
    // 004fb9f0  83fb1f                 +cmp ebx, 0x1f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb9f3  7e2e                   -jle 0x4fba23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fba23;
    }
L_0x004fb9f5:
    // 004fb9f5  beacdc5400             -mov esi, 0x54dcac
    cpu.esi = 5561516 /*0x54dcac*/;
    // 004fb9fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb9fb  b810dd5400             -mov eax, 0x54dd10
    cpu.eax = 5561616 /*0x54dd10*/;
    // 004fba00  bacb000000             -mov edx, 0xcb
    cpu.edx = 203 /*0xcb*/;
    // 004fba05  68a0dd5400             -push 0x54dda0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561760 /*0x54dda0*/;
    cpu.esp -= 4;
    // 004fba0a  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fba10  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fba15  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fba1b  e8f055f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fba20  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004fba23:
    // 004fba23  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fba28  e833250100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004fba2d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fba2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fba31  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004fba38  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fba3a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fba3d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fba3f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fba42  8b15604f9f00           -mov edx, dword ptr [0x9f4f60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fba48  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fba4a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fba4c  0f84cc000000           -je 0x4fbb1e
    if (cpu.flags.zf)
    {
        goto L_0x004fbb1e;
    }
    // 004fba52  833a00                 +cmp dword ptr [edx], 0
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
    // 004fba55  7507                   -jne 0x4fba5e
    if (!cpu.flags.zf)
    {
        goto L_0x004fba5e;
    }
    // 004fba57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fba59  e802feffff             -call 0x4fb860
    cpu.esp -= 4;
    sub_4fb860(app, cpu);
    if (cpu.terminate) return;
L_0x004fba5e:
    // 004fba5e  c6411000               -mov byte ptr [ecx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004fba62  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004fba69  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004fba70  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004fba77  c7412400000000         -mov dword ptr [ecx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004fba7e  c7412800000000         -mov dword ptr [ecx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004fba85  c7412c00000000         -mov dword ptr [ecx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004fba8c  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004fba8f  89691c                 -mov dword ptr [ecx + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004fba92  884111                 -mov byte ptr [ecx + 0x11], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(17) /* 0x11 */) = cpu.al;
    // 004fba95  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004fba98  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004fba9b  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004fba9e  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 004fbaa1  833a00                 +cmp dword ptr [edx], 0
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
    // 004fbaa4  0f84ab000000           -je 0x4fbb55
    if (cpu.flags.zf)
    {
        goto L_0x004fbb55;
    }
    // 004fbaaa  8d421c                 -lea eax, [edx + 0x1c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004fbaad  e86e2f0100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
L_0x004fbab2:
    // 004fbab2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fbab4  8b4260                 -mov eax, dword ptr [edx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    // 004fbab7  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004fbaba  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fbabc  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004fbabf  8b4260                 -mov eax, dword ptr [edx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    // 004fbac2  40                     -inc eax
    (cpu.eax)++;
    // 004fbac3  25ffffff00             +and eax, 0xffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/))));
    // 004fbac8  894260                 -mov dword ptr [edx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004fbacb  7507                   -jne 0x4fbad4
    if (!cpu.flags.zf)
    {
        goto L_0x004fbad4;
    }
    // 004fbacd  c7426001000000         -mov dword ptr [edx + 0x60], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = 1 /*0x1*/;
L_0x004fbad4:
    // 004fbad4  833a00                 +cmp dword ptr [edx], 0
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
    // 004fbad7  740a                   -je 0x4fbae3
    if (cpu.flags.zf)
    {
        goto L_0x004fbae3;
    }
    // 004fbad9  8d421c                 -lea eax, [edx + 0x1c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004fbadc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fbade  e85d2f0100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
L_0x004fbae3:
    // 004fbae3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fbae5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fbae8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbae9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbaea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbaeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbaec:
    // 004fbaec  b9acdc5400             -mov ecx, 0x54dcac
    cpu.ecx = 5561516 /*0x54dcac*/;
    // 004fbaf1  be10dd5400             -mov esi, 0x54dd10
    cpu.esi = 5561616 /*0x54dd10*/;
    // 004fbaf6  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 004fbafb  6820dd5400             -push 0x54dd20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561632 /*0x54dd20*/;
    cpu.esp -= 4;
    // 004fbb00  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004fbb06  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fbb0c  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004fbb11  e8fa54f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fbb16  83c404                 +add esp, 4
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
    // 004fbb19  e98efeffff             -jmp 0x4fb9ac
    goto L_0x004fb9ac;
L_0x004fbb1e:
    // 004fbb1e  baacdc5400             -mov edx, 0x54dcac
    cpu.edx = 5561516 /*0x54dcac*/;
    // 004fbb23  b910dd5400             -mov ecx, 0x54dd10
    cpu.ecx = 5561616 /*0x54dd10*/;
    // 004fbb28  bbd3000000             -mov ebx, 0xd3
    cpu.ebx = 211 /*0xd3*/;
    // 004fbb2d  68dcdd5400             -push 0x54dddc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561820 /*0x54dddc*/;
    cpu.esp -= 4;
    // 004fbb32  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fbb38  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fbb3e  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fbb44  e8c754f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fbb49  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fbb4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fbb4e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fbb51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbb55:
    // 004fbb55  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fbb57  e956ffffff             -jmp 0x4fbab2
    goto L_0x004fbab2;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4fbb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fbb60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fbb61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fbb62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fbb63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fbb65  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004fbb68  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fbb6b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004fbb72  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fbb74  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fbb77  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fbb79  8b1d604f9f00           -mov ebx, dword ptr [0x9f4f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fbb7f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fbb82  01c3                   +add ebx, eax
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
    // 004fbb84  7419                   -je 0x4fbb9f
    if (cpu.flags.zf)
    {
        goto L_0x004fbb9f;
    }
L_0x004fbb86:
    // 004fbb86  8d431c                 -lea eax, [ebx + 0x1c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004fbb89  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fbb8b  e810250100             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 004fbb90  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004fbb93  e8983ffeff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004fbb98  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004fbb9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbb9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbb9f:
    // 004fbb9f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fbba0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fbba1  baacdc5400             -mov edx, 0x54dcac
    cpu.edx = 5561516 /*0x54dcac*/;
    // 004fbba6  be10de5400             -mov esi, 0x54de10
    cpu.esi = 5561872 /*0x54de10*/;
    // 004fbbab  bffb000000             -mov edi, 0xfb
    cpu.edi = 251 /*0xfb*/;
    // 004fbbb0  6820de5400             -push 0x54de20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561888 /*0x54de20*/;
    cpu.esp -= 4;
    // 004fbbb5  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fbbbb  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fbbc1  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fbbc7  e84454f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fbbcc  83c404                 +add esp, 4
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
    // 004fbbcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbbd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbbd1  ebb3                   -jmp 0x4fbb86
    goto L_0x004fbb86;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fbbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fbbe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fbbe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fbbe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fbbe3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fbbe4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fbbe7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fbbe9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fbbeb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fbbed  7505                   -jne 0x4fbbf4
    if (!cpu.flags.zf)
    {
        goto L_0x004fbbf4;
    }
    // 004fbbef  be60de5400             -mov esi, 0x54de60
    cpu.esi = 5561952 /*0x54de60*/;
L_0x004fbbf4:
    // 004fbbf4  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004fbbf6  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fbbf8  49                     -dec ecx
    (cpu.ecx)--;
    // 004fbbf9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fbbfb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004fbbfd  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004fbbff  49                     -dec ecx
    (cpu.ecx)--;
    // 004fbc00  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004fbc03  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fbc06  804b0c01               -or byte ptr [ebx + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004fbc0a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fbc0c  e8ff540000             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004fbc11  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004fbc14  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fbc16  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fbc18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fbc1a  e8d1e8feff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004fbc1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fbc22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbc23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbc24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbc25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbc26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fbc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fbc30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fbc31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fbc32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fbc33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fbc34  81ec18010000           -sub esp, 0x118
    (cpu.esp) -= x86::reg32(x86::sreg32(280 /*0x118*/));
    // 004fbc3a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fbc3c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004fbc3e  899c2414010000         -mov dword ptr [esp + 0x114], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.ebx;
    // 004fbc45  b27c                   -mov dl, 0x7c
    cpu.dl = 124 /*0x7c*/;
    // 004fbc47  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004fbc49:
    // 004fbc49  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004fbc4b  3ac2                   +cmp al, dl
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
    // 004fbc4d  7412                   -je 0x4fbc61
    if (cpu.flags.zf)
    {
        goto L_0x004fbc61;
    }
    // 004fbc4f  3c00                   +cmp al, 0
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
    // 004fbc51  740c                   -je 0x4fbc5f
    if (cpu.flags.zf)
    {
        goto L_0x004fbc5f;
    }
    // 004fbc53  46                     -inc esi
    (cpu.esi)++;
    // 004fbc54  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004fbc56  3ac2                   +cmp al, dl
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
    // 004fbc58  7407                   -je 0x4fbc61
    if (cpu.flags.zf)
    {
        goto L_0x004fbc61;
    }
    // 004fbc5a  46                     -inc esi
    (cpu.esi)++;
    // 004fbc5b  3c00                   +cmp al, 0
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
    // 004fbc5d  75ea                   -jne 0x4fbc49
    if (!cpu.flags.zf)
    {
        goto L_0x004fbc49;
    }
L_0x004fbc5f:
    // 004fbc5f  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004fbc61:
    // 004fbc61  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fbc63  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 004fbc6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fbc6c  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004fbc73  89942410010000         -mov dword ptr [esp + 0x110], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004fbc7a  8994240c010000         -mov dword ptr [esp + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004fbc81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fbc83  7544                   -jne 0x4fbcc9
    if (!cpu.flags.zf)
    {
        goto L_0x004fbcc9;
    }
    // 004fbc85  8d8c240c010000         -lea ecx, [esp + 0x10c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004fbc8c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fbc8e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fbc90  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fbc92  e88979feff             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004fbc97  89842410010000         -mov dword ptr [esp + 0x110], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */) = cpu.eax;
    // 004fbc9e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004fbca0  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004fbca3:
    // 004fbca3  83bc241401000000       +cmp dword ptr [esp + 0x114], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbcab  740a                   -je 0x4fbcb7
    if (cpu.flags.zf)
    {
        goto L_0x004fbcb7;
    }
    // 004fbcad  83bc241001000000       +cmp dword ptr [esp + 0x110], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbcb5  742e                   -je 0x4fbce5
    if (cpu.flags.zf)
    {
        goto L_0x004fbce5;
    }
L_0x004fbcb7:
    // 004fbcb7  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004fbcbe  81c418010000           -add esp, 0x118
    (cpu.esp) += x86::reg32(x86::sreg32(280 /*0x118*/));
    // 004fbcc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbcc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbcc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbcc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbcc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbcc9:
    // 004fbcc9  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004fbccb  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fbccd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fbccf  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fbcd1  46                     -inc esi
    (cpu.esi)++;
    // 004fbcd2  e85951feff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004fbcd7  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004fbcd9  89b42408010000         -mov dword ptr [esp + 0x108], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.esi;
    // 004fbce0  88140c                 -mov byte ptr [esp + ecx], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1) = cpu.dl;
    // 004fbce3  ebbe                   -jmp 0x4fbca3
    goto L_0x004fbca3;
L_0x004fbce5:
    // 004fbce5  8d9c2404010000         -lea ebx, [esp + 0x104]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004fbcec  ba90b74f00             -mov edx, 0x4fb790
    cpu.edx = 5224336 /*0x4fb790*/;
    // 004fbcf1  b8904f9f00             -mov eax, 0x9f4f90
    cpu.eax = 10440592 /*0x9f4f90*/;
    // 004fbcf6  e8b52c0100             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 004fbcfb  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004fbd02  81c418010000           -add esp, 0x118
    (cpu.esp) += x86::reg32(x86::sreg32(280 /*0x118*/));
    // 004fbd08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fbd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fbd10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fbd11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fbd12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fbd13  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fbd15  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fbd17  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fbd19  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004fbd1f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004fbd22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbd24  740f                   -je 0x4fbd35
    if (cpu.flags.zf)
    {
        goto L_0x004fbd35;
    }
    // 004fbd26  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 004fbd29  750a                   -jne 0x4fbd35
    if (!cpu.flags.zf)
    {
        goto L_0x004fbd35;
    }
    // 004fbd2b  c703ffffffff           -mov dword ptr [ebx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967295 /*0xffffffff*/;
    // 004fbd31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbd35:
    // 004fbd35  ba20b84f00             -mov edx, 0x4fb820
    cpu.edx = 5224480 /*0x4fb820*/;
    // 004fbd3a  8d471c                 -lea eax, [edi + 0x1c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004fbd3d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fbd3f  e8ac260100             -call 0x50e3f0
    cpu.esp -= 4;
    sub_50e3f0(app, cpu);
    if (cpu.terminate) return;
    // 004fbd44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbd46  740a                   -je 0x4fbd52
    if (cpu.flags.zf)
    {
        goto L_0x004fbd52;
    }
    // 004fbd48  c70601000000           -mov dword ptr [esi], 1
    app->getMemory<x86::reg32>(cpu.esi) = 1 /*0x1*/;
    // 004fbd4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbd52:
    // 004fbd52  ba20b84f00             -mov edx, 0x4fb820
    cpu.edx = 5224480 /*0x4fb820*/;
    // 004fbd57  8d4738                 -lea eax, [edi + 0x38]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004fbd5a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fbd5c  e88f260100             -call 0x50e3f0
    cpu.esp -= 4;
    sub_50e3f0(app, cpu);
    if (cpu.terminate) return;
    // 004fbd61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fbda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004fbda0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fbda1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fbda2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fbda3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fbda4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fbda5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fbda6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fbda9  8b15644f9f00           -mov edx, dword ptr [0x9f4f64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440548) /* 0x9f4f64 */);
    // 004fbdaf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004fbdb6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fbdb8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fbdbb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fbdbd  8b3d604f9f00           -mov edi, dword ptr [0x9f4f60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fbdc3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fbdc6  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fbdc8  8b475c                 -mov eax, dword ptr [edi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(92) /* 0x5c */);
    // 004fbdcb  c70701000000           -mov dword ptr [edi], 1
    app->getMemory<x86::reg32>(cpu.edi) = 1 /*0x1*/;
    // 004fbdd1  e87a3efeff             -call 0x4dfc50
    cpu.esp -= 4;
    sub_4dfc50(app, cpu);
    if (cpu.terminate) return;
    // 004fbdd6  833df071560000         +cmp dword ptr [0x5671f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665264) /* 0x5671f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbddd  0f8567000000           -jne 0x4fbe4a
    if (!cpu.flags.zf)
    {
        goto L_0x004fbe4a;
    }
    // 004fbde3  8d6f1c                 -lea ebp, [edi + 0x1c]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004fbde6  8d4738                 -lea eax, [edi + 0x38]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004fbde9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004fbded:
    // 004fbded  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbdf0  7568                   -jne 0x4fbe5a
    if (!cpu.flags.zf)
    {
        goto L_0x004fbe5a;
    }
    // 004fbdf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fbdf4:
    // 004fbdf4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fbdf6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbdf8  e863210100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004fbdfd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fbdff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fbe01  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004fbe04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbe06  741d                   -je 0x4fbe25
    if (cpu.flags.zf)
    {
        goto L_0x004fbe25;
    }
    // 004fbe08  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fbe0a  8b5f64                 -mov ebx, dword ptr [edi + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(100) /* 0x64 */);
    // 004fbe0d  8a4211                 -mov al, byte ptr [edx + 0x11]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004fbe10  39d8                   +cmp eax, ebx
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
    // 004fbe12  7e11                   -jle 0x4fbe25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fbe25;
    }
    // 004fbe14  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbe16  e885220100             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 004fbe1b  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004fbe22  8b7718                 -mov esi, dword ptr [edi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
L_0x004fbe25:
    // 004fbe25  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbe28  7409                   -je 0x4fbe33
    if (cpu.flags.zf)
    {
        goto L_0x004fbe33;
    }
    // 004fbe2a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fbe2c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbe2e  e80d2c0100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
L_0x004fbe33:
    // 004fbe33  837f1800               +cmp dword ptr [edi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbe37  752a                   -jne 0x4fbe63
    if (!cpu.flags.zf)
    {
        goto L_0x004fbe63;
    }
    // 004fbe39  8b4754                 -mov eax, dword ptr [edi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 004fbe3c  e82f3dfeff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
L_0x004fbe41:
    // 004fbe41  833df071560000         +cmp dword ptr [0x5671f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665264) /* 0x5671f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbe48  74a3                   -je 0x4fbded
    if (cpu.flags.zf)
    {
        goto L_0x004fbded;
    }
L_0x004fbe4a:
    // 004fbe4a  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004fbe50  83c408                 +add esp, 8
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
    // 004fbe53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fbe59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fbe5a:
    // 004fbe5a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbe5c  e8bf2b0100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fbe61  eb91                   -jmp 0x4fbdf4
    goto L_0x004fbdf4;
L_0x004fbe63:
    // 004fbe63  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004fbe66  c1e01e                 -shl eax, 0x1e
    cpu.eax <<= 30 /*0x1e*/ % 32;
    // 004fbe69  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004fbe6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbe6e  755d                   -jne 0x4fbecd
    if (!cpu.flags.zf)
    {
        goto L_0x004fbecd;
    }
    // 004fbe70  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004fbe73  83f80a                 +cmp eax, 0xa
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
    // 004fbe76  0f878f020000           -ja 0x4fc10b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fc10b;
    }
    // 004fbe7c  ff248568bd4f00         -jmp dword ptr [eax*4 + 0x4fbd68]
    cpu.ip = app->getMemory<x86::reg32>(5225832 + cpu.eax * 4); goto dynamic_jump;
  case 0x004fbe83:
    // 004fbe83  8a5624                 -mov dl, byte ptr [esi + 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004fbe86  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fbe88  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004fbe8b  0f84a5000000           -je 0x4fbf36
    if (cpu.flags.zf)
    {
        goto L_0x004fbf36;
    }
    // 004fbe91  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fbe96  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
L_0x004fbe9b:
    // 004fbe9b  f6462408               +test byte ptr [esi + 0x24], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 8 /*0x8*/));
    // 004fbe9f  7403                   -je 0x4fbea4
    if (cpu.flags.zf)
    {
        goto L_0x004fbea4;
    }
    // 004fbea1  80ce08                 -or dh, 8
    cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004fbea4:
    // 004fbea4  f6462410               +test byte ptr [esi + 0x24], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 16 /*0x10*/));
    // 004fbea8  7403                   -je 0x4fbead
    if (cpu.flags.zf)
    {
        goto L_0x004fbead;
    }
    // 004fbeaa  80ce01                 -or dh, 1
    cpu.dh |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004fbead:
    // 004fbead  f6462420               +test byte ptr [esi + 0x24], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 32 /*0x20*/));
    // 004fbeb1  7403                   -je 0x4fbeb6
    if (cpu.flags.zf)
    {
        goto L_0x004fbeb6;
    }
    // 004fbeb3  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004fbeb6:
    // 004fbeb6  8b462c                 -mov eax, dword ptr [esi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fbeb9  e872fdffff             -call 0x4fbc30
    cpu.esp -= 4;
    sub_4fbc30(app, cpu);
    if (cpu.terminate) return;
    // 004fbebe  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004fbec1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbec3  0f8491000000           -je 0x4fbf5a
    if (cpu.flags.zf)
    {
        goto L_0x004fbf5a;
    }
  [[fallthrough]];
  case 0x004fbec9:
L_0x004fbec9:
    // 004fbec9  c6461001               -mov byte ptr [esi + 0x10], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
L_0x004fbecd:
    // 004fbecd  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbed0  0f846e020000           -je 0x4fc144
    if (cpu.flags.zf)
    {
        goto L_0x004fc144;
    }
    // 004fbed6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbed8  e8432b0100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fbedd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004fbedf:
    // 004fbedf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fbee3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fbee5  e8661f0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004fbeea  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004fbeec  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004fbef3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fbef5  7409                   -je 0x4fbf00
    if (cpu.flags.zf)
    {
        goto L_0x004fbf00;
    }
    // 004fbef7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fbef9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fbefb  e8402b0100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
L_0x004fbf00:
    // 004fbf00  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fbf04  7423                   -je 0x4fbf29
    if (cpu.flags.zf)
    {
        goto L_0x004fbf29;
    }
    // 004fbf06  804e0c08               -or byte ptr [esi + 0xc], 8
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004fbf0a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004fbf0d  c1e01e                 -shl eax, 0x1e
    cpu.eax <<= 30 /*0x1e*/ % 32;
    // 004fbf10  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004fbf13  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004fbf16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbf18  0f842d020000           -je 0x4fc14b
    if (cpu.flags.zf)
    {
        goto L_0x004fc14b;
    }
    // 004fbf1e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004fbf23  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004fbf26  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fbf29:
    // 004fbf29  8b475c                 -mov eax, dword ptr [edi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(92) /* 0x5c */);
    // 004fbf2c  e81f3dfeff             -call 0x4dfc50
    cpu.esp -= 4;
    sub_4dfc50(app, cpu);
    if (cpu.terminate) return;
    // 004fbf31  e90bffffff             -jmp 0x4fbe41
    goto L_0x004fbe41;
L_0x004fbf36:
    // 004fbf36  8a4e24                 -mov cl, byte ptr [esi + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004fbf39  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004fbf3e  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004fbf41  7405                   -je 0x4fbf48
    if (cpu.flags.zf)
    {
        goto L_0x004fbf48;
    }
    // 004fbf43  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x004fbf48:
    // 004fbf48  f6462404               +test byte ptr [esi + 0x24], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */) & 4 /*0x4*/));
    // 004fbf4c  0f8449ffffff           -je 0x4fbe9b
    if (cpu.flags.zf)
    {
        goto L_0x004fbe9b;
    }
    // 004fbf52  80ca20                 +or dl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004fbf55  e941ffffff             -jmp 0x4fbe9b
    goto L_0x004fbe9b;
L_0x004fbf5a:
    // 004fbf5a  e8913dfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fbf5f  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fbf63  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fbf66  e962ffffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
  case 0x004fbf6b:
    // 004fbf6b  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004fbf6e  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fbf71  e8ea7efeff             -call 0x4e3e60
    cpu.esp -= 4;
    sub_4e3e60(app, cpu);
    if (cpu.terminate) return;
    // 004fbf76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbf78  7415                   -je 0x4fbf8f
    if (cpu.flags.zf)
    {
        goto L_0x004fbf8f;
    }
    // 004fbf7a  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004fbf7d  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fbf80  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fbf83  e8587bfeff             -call 0x4e3ae0
    cpu.esp -= 4;
    sub_4e3ae0(app, cpu);
    if (cpu.terminate) return;
    // 004fbf88  c6461001               -mov byte ptr [esi + 0x10], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004fbf8c  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004fbf8f:
    // 004fbf8f  e85c3dfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fbf94  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fbf97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbf99  0f842effffff           -je 0x4fbecd
    if (cpu.flags.zf)
    {
        goto L_0x004fbecd;
    }
    // 004fbf9f  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fbfa3  e925ffffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
  case 0x004fbfa8:
    // 004fbfa8  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004fbfab  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fbfae  e8ad7efeff             -call 0x4e3e60
    cpu.esp -= 4;
    sub_4e3e60(app, cpu);
    if (cpu.terminate) return;
    // 004fbfb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbfb5  7415                   -je 0x4fbfcc
    if (cpu.flags.zf)
    {
        goto L_0x004fbfcc;
    }
    // 004fbfb7  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004fbfba  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fbfbd  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fbfc0  e8fb7cfeff             -call 0x4e3cc0
    cpu.esp -= 4;
    sub_4e3cc0(app, cpu);
    if (cpu.terminate) return;
    // 004fbfc5  c6461001               -mov byte ptr [esi + 0x10], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004fbfc9  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004fbfcc:
    // 004fbfcc  e81f3dfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fbfd1  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fbfd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbfd6  0f84f1feffff           -je 0x4fbecd
    if (cpu.flags.zf)
    {
        goto L_0x004fbecd;
    }
    // 004fbfdc  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fbfe0  e9e8feffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
  case 0x004fbfe5:
    // 004fbfe5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fbfea  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004fbfef  8b462c                 -mov eax, dword ptr [esi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fbff2  e839fcffff             -call 0x4fbc30
    cpu.esp -= 4;
    sub_4fbc30(app, cpu);
    if (cpu.terminate) return;
    // 004fbff7  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004fbffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fbffc  7411                   -je 0x4fc00f
    if (cpu.flags.zf)
    {
        goto L_0x004fc00f;
    }
    // 004fbffe  e8dd7ffeff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004fc003  c7462401000000         -mov dword ptr [esi + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004fc00a  e9bafeffff             -jmp 0x4fbec9
    goto L_0x004fbec9;
L_0x004fc00f:
    // 004fc00f  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004fc012  e9b2feffff             -jmp 0x4fbec9
    goto L_0x004fbec9;
  case 0x004fc017:
    // 004fc017  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fc019  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc01d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fc020  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fc022  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc024  e85779feff             -call 0x4e3980
    cpu.esp -= 4;
    sub_4e3980(app, cpu);
    if (cpu.terminate) return;
    // 004fc029  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc02b  740f                   -je 0x4fc03c
    if (cpu.flags.zf)
    {
        goto L_0x004fc03c;
    }
    // 004fc02d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004fc030  c6461001               -mov byte ptr [esi + 0x10], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004fc034  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004fc037  e991feffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
L_0x004fc03c:
    // 004fc03c  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fc040  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004fc043  e8a83cfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fc048  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fc04b  e97dfeffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
  case 0x004fc050:
    // 004fc050  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004fc053  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004fc056  e8d581feff             -call 0x4e4230
    cpu.esp -= 4;
    sub_4e4230(app, cpu);
    if (cpu.terminate) return;
    // 004fc05b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc05d  741d                   -je 0x4fc07c
    if (cpu.flags.zf)
    {
        goto L_0x004fc07c;
    }
    // 004fc05f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fc064:
    // 004fc064  884610                 -mov byte ptr [esi + 0x10], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004fc067  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fc069  0f855efeffff           -jne 0x4fbecd
    if (!cpu.flags.zf)
    {
        goto L_0x004fbecd;
    }
    // 004fc06f  e87c3cfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fc074  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fc077  e951feffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
L_0x004fc07c:
    // 004fc07c  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004fc081  ebe1                   -jmp 0x4fc064
    goto L_0x004fc064;
  case 0x004fc083:
    // 004fc083  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004fc08a  e93afeffff             -jmp 0x4fbec9
    goto L_0x004fbec9;
  case 0x004fc08f:
    // 004fc08f  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fc092  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fc094  0f8433feffff           -je 0x4fbecd
    if (cpu.flags.zf)
    {
        goto L_0x004fbecd;
    }
    // 004fc09a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fc09f  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 004fc0a4  8d4114                 -lea eax, [ecx + 0x14]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004fc0a7  e884fbffff             -call 0x4fbc30
    cpu.esp -= 4;
    sub_4fbc30(app, cpu);
    if (cpu.terminate) return;
    // 004fc0ac  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004fc0af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc0b1  7414                   -je 0x4fc0c7
    if (cpu.flags.zf)
    {
        goto L_0x004fc0c7;
    }
    // 004fc0b3  c6461001               -mov byte ptr [esi + 0x10], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004fc0b7  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004fc0ba  e83181feff             -call 0x4e41f0
    cpu.esp -= 4;
    sub_4e41f0(app, cpu);
    if (cpu.terminate) return;
    // 004fc0bf  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004fc0c2  e906feffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
L_0x004fc0c7:
    // 004fc0c7  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fc0cb  e8203cfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fc0d0  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fc0d3  e9f5fdffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
  case 0x004fc0d8:
    // 004fc0d8  b8904f9f00             -mov eax, 0x9f4f90
    cpu.eax = 10440592 /*0x9f4f90*/;
    // 004fc0dd  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fc0e0  e86b200100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004fc0e5  e9dffdffff             -jmp 0x4fbec9
    goto L_0x004fbec9;
  case 0x004fc0ea:
    // 004fc0ea  8b462c                 -mov eax, dword ptr [esi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004fc0ed  e80e75feff             -call 0x4e3600
    cpu.esp -= 4;
    sub_4e3600(app, cpu);
    if (cpu.terminate) return;
    // 004fc0f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc0f4  0f85cffdffff           -jne 0x4fbec9
    if (!cpu.flags.zf)
    {
        goto L_0x004fbec9;
    }
    // 004fc0fa  c64610fe               -mov byte ptr [esi + 0x10], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = 254 /*0xfe*/;
    // 004fc0fe  e8ed3bfeff             -call 0x4dfcf0
    cpu.esp -= 4;
    sub_4dfcf0(app, cpu);
    if (cpu.terminate) return;
    // 004fc103  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004fc106  e9c2fdffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
L_0x004fc10b:
    // 004fc10b  c70598215500f7010000   -mov dword ptr [0x552198], 0x1f7
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 503 /*0x1f7*/;
    // 004fc115  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004fc118  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004fc11b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc11c  b9acdc5400             -mov ecx, 0x54dcac
    cpu.ecx = 5561516 /*0x54dcac*/;
    // 004fc121  bb64de5400             -mov ebx, 0x54de64
    cpu.ebx = 5561956 /*0x54de64*/;
    // 004fc126  6878de5400             -push 0x54de78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561976 /*0x54de78*/;
    cpu.esp -= 4;
    // 004fc12b  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004fc131  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004fc137  e8d44ef0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fc13c  83c408                 +add esp, 8
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
    // 004fc13f  e989fdffff             -jmp 0x4fbecd
    goto L_0x004fbecd;
L_0x004fc144:
    // 004fc144  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004fc146  e994fdffff             -jmp 0x4fbedf
    goto L_0x004fbedf;
L_0x004fc14b:
    // 004fc14b  8b560d                 -mov edx, dword ptr [esi + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004fc14e  c1fa18                 +sar edx, 0x18
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
    // 004fc151  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004fc154  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fc157  8b475c                 -mov eax, dword ptr [edi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(92) /* 0x5c */);
    // 004fc15a  e8f13afeff             -call 0x4dfc50
    cpu.esp -= 4;
    sub_4dfc50(app, cpu);
    if (cpu.terminate) return;
    // 004fc15f  e9ddfcffff             -jmp 0x4fbe41
    goto L_0x004fbe41;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fc170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc170  833d604f9f0000         +cmp dword ptr [0x9f4f60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc177  0f84b1000000           -je 0x4fc22e
    if (cpu.flags.zf)
    {
        goto L_0x004fc22e;
    }
    // 004fc17d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc17e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc17f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc180  bb904f9f00             -mov ebx, 0x9f4f90
    cpu.ebx = 10440592 /*0x9f4f90*/;
L_0x004fc185:
    // 004fc185  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc187  e8d41d0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004fc18c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc18e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc190  0f8599000000           -jne 0x4fc22f
    if (!cpu.flags.zf)
    {
        goto L_0x004fc22f;
    }
    // 004fc196  c705f071560001000000   -mov dword ptr [0x5671f0], 1
    app->getMemory<x86::reg32>(x86::reg32(5665264) /* 0x5671f0 */) = 1 /*0x1*/;
    // 004fc1a0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc1a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004fc1a4:
    // 004fc1a4  8b15604f9f00           -mov edx, dword ptr [0x9f4f60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc1aa  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc1ac  3b1a                   +cmp ebx, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc1ae  7437                   -je 0x4fc1e7
    if (cpu.flags.zf)
    {
        goto L_0x004fc1e7;
    }
    // 004fc1b0  8b4254                 -mov eax, dword ptr [edx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004fc1b3  e87839feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004fc1b8  3b1a                   +cmp ebx, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc1ba  740b                   -je 0x4fc1c7
    if (cpu.flags.zf)
    {
        goto L_0x004fc1c7;
    }
L_0x004fc1bc:
    // 004fc1bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc1be  e81d37feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fc1c3  3b1a                   +cmp ebx, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc1c5  75f5                   -jne 0x4fc1bc
    if (!cpu.flags.zf)
    {
        goto L_0x004fc1bc;
    }
L_0x004fc1c7:
    // 004fc1c7  8b4254                 -mov eax, dword ptr [edx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004fc1ca  e8313afeff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004fc1cf  8b425c                 -mov eax, dword ptr [edx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 004fc1d2  e8a93afeff             -call 0x4dfc80
    cpu.esp -= 4;
    sub_4dfc80(app, cpu);
    if (cpu.terminate) return;
    // 004fc1d7  8d4238                 -lea eax, [edx + 0x38]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 004fc1da  e8011c0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004fc1df  8d421c                 -lea eax, [edx + 0x1c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004fc1e2  e8f91b0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
L_0x004fc1e7:
    // 004fc1e7  83c168                 -add ecx, 0x68
    (cpu.ecx) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 004fc1ea  81f9000d0000           +cmp ecx, 0xd00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3328 /*0xd00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc1f0  75b2                   -jne 0x4fc1a4
    if (!cpu.flags.zf)
    {
        goto L_0x004fc1a4;
    }
    // 004fc1f2  a1684f9f00             -mov eax, dword ptr [0x9f4f68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440552) /* 0x9f4f68 */);
    // 004fc1f7  e8844f0000             -call 0x501180
    cpu.esp -= 4;
    sub_501180(app, cpu);
    if (cpu.terminate) return;
    // 004fc1fc  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc201  e87a4f0000             -call 0x501180
    cpu.esp -= 4;
    sub_501180(app, cpu);
    if (cpu.terminate) return;
    // 004fc206  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fc20b  e8d01b0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004fc210  b8904f9f00             -mov eax, 0x9f4f90
    cpu.eax = 10440592 /*0x9f4f90*/;
    // 004fc215  e8c61b0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004fc21a  a16c4f9f00             -mov eax, dword ptr [0x9f4f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440556) /* 0x9f4f6c */);
    // 004fc21f  e83cf1feff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004fc224  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fc226  a3604f9f00             -mov dword ptr [0x9f4f60], eax
    app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */) = cpu.eax;
    // 004fc22b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc22c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc22d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fc22e:
    // 004fc22e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc22f:
    // 004fc22f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004fc232  e8a97dfeff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004fc237  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fc239  e8424f0000             -call 0x501180
    cpu.esp -= 4;
    sub_501180(app, cpu);
    if (cpu.terminate) return;
    // 004fc23e  e942ffffff             -jmp 0x4fc185
    goto L_0x004fc185;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fc250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc251  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc254  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fc256  833d604f9f0000         +cmp dword ptr [0x9f4f60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc25d  0f85c9000000           -jne 0x4fc32c
    if (!cpu.flags.zf)
    {
        goto L_0x004fc32c;
    }
    // 004fc263  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc265  7505                   -jne 0x4fc26c
    if (!cpu.flags.zf)
    {
        goto L_0x004fc26c;
    }
    // 004fc267  b840000000             -mov eax, 0x40
    cpu.eax = 64 /*0x40*/;
L_0x004fc26c:
    // 004fc26c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fc26e  0f8493000000           -je 0x4fc307
    if (cpu.flags.zf)
    {
        goto L_0x004fc307;
    }
L_0x004fc274:
    // 004fc274  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc275  e8b671feff             -call 0x4e3430
    cpu.esp -= 4;
    sub_4e3430(app, cpu);
    if (cpu.terminate) return;
    // 004fc27a  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fc27f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fc281  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc283  e8481a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004fc288  b8904f9f00             -mov eax, 0x9f4f90
    cpu.eax = 10440592 /*0x9f4f90*/;
    // 004fc28d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fc28f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc291  e83a1a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004fc296  bb000d0000             -mov ebx, 0xd00
    cpu.ebx = 3328 /*0xd00*/;
    // 004fc29b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc29f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fc2a3  e8684e0000             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004fc2a8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc2ac  a3604f9f00             -mov dword ptr [0x9f4f60], eax
    app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */) = cpu.eax;
    // 004fc2b1  e85644feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004fc2b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc2b8  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004fc2bb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fc2bd  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004fc2c0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc2c4  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004fc2c8  e8434e0000             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004fc2cd  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc2d1  b930000000             -mov ecx, 0x30
    cpu.ecx = 48 /*0x30*/;
    // 004fc2d6  a3684f9f00             -mov dword ptr [0x9f4f68], eax
    app->getMemory<x86::reg32>(x86::reg32(10440552) /* 0x9f4f68 */) = cpu.eax;
    // 004fc2db  e82c44feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004fc2e0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fc2e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc2e6  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004fc2e8  8b0d684f9f00           -mov ecx, dword ptr [0x9f4f68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440552) /* 0x9f4f68 */);
    // 004fc2ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fc2f0:
    // 004fc2f0  4b                     -dec ebx
    (cpu.ebx)--;
    // 004fc2f1  83fbff                 +cmp ebx, -1
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
    // 004fc2f4  741b                   -je 0x4fc311
    if (cpu.flags.zf)
    {
        goto L_0x004fc311;
    }
    // 004fc2f6  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fc2fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fc2fd  e84e1b0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004fc302  83c130                 +add ecx, 0x30
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fc305  ebe9                   -jmp 0x4fc2f0
    goto L_0x004fc2f0;
L_0x004fc307:
    // 004fc307  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004fc30c  e963ffffff             -jmp 0x4fc274
    goto L_0x004fc274;
L_0x004fc311:
    // 004fc311  e8caeffeff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004fc316  a36c4f9f00             -mov dword ptr [0x9f4f6c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440556) /* 0x9f4f6c */) = cpu.eax;
    // 004fc31b  b870c14f00             -mov eax, 0x4fc170
    cpu.eax = 5226864 /*0x4fc170*/;
    // 004fc320  891d704f9f00           -mov dword ptr [0x9f4f70], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440560) /* 0x9f4f70 */) = cpu.ebx;
    // 004fc326  e84d67ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004fc32b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fc32c:
    // 004fc32c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fc331  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc334  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc335  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fc340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc343  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc344  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc347  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc349  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc34b  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc34e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc355  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc357  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc35a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc35c  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc362  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc365  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc367  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc36a  7524                   -jne 0x4fc390
    if (!cpu.flags.zf)
    {
        goto L_0x004fc390;
    }
    // 004fc36c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc36e:
    // 004fc36e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc370  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fc372  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc374  e897f9ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc379  833c2400               +cmp dword ptr [esp], 0
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
    // 004fc37d  741b                   -je 0x4fc39a
    if (cpu.flags.zf)
    {
        goto L_0x004fc39a;
    }
    // 004fc37f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fc381  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc384  7562                   -jne 0x4fc3e8
    if (!cpu.flags.zf)
    {
        goto L_0x004fc3e8;
    }
    // 004fc386  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc388  83c404                 +add esp, 4
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
    // 004fc38b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc38c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc38d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc38e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc38f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc390:
    // 004fc390  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc393  e888260100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc398  ebd4                   -jmp 0x4fc36e
    goto L_0x004fc36e;
L_0x004fc39a:
    // 004fc39a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc39c  7436                   -je 0x4fc3d4
    if (cpu.flags.zf)
    {
        goto L_0x004fc3d4;
    }
    // 004fc39e  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004fc3a1  c1e21e                 -shl edx, 0x1e
    cpu.edx <<= 30 /*0x1e*/ % 32;
    // 004fc3a4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fc3a7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fc3a9  7414                   -je 0x4fc3bf
    if (cpu.flags.zf)
    {
        goto L_0x004fc3bf;
    }
    // 004fc3ab  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004fc3b0  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc3b3  7533                   -jne 0x4fc3e8
    if (!cpu.flags.zf)
    {
        goto L_0x004fc3e8;
    }
    // 004fc3b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc3b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc3ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc3bf:
    // 004fc3bf  8b580d                 -mov ebx, dword ptr [eax + 0xd]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004fc3c2  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004fc3c5  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc3c8  751e                   -jne 0x4fc3e8
    if (!cpu.flags.zf)
    {
        goto L_0x004fc3e8;
    }
    // 004fc3ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc3cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc3cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc3d4:
    // 004fc3d4  bbfdffffff             -mov ebx, 0xfffffffd
    cpu.ebx = 4294967293 /*0xfffffffd*/;
    // 004fc3d9  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc3dc  750a                   -jne 0x4fc3e8
    if (!cpu.flags.zf)
    {
        goto L_0x004fc3e8;
    }
    // 004fc3de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc3e0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc3e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc3e8:
    // 004fc3e8  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc3eb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fc3ed  e84e260100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc3f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fc3f4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc3f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc3fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4fc400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc402  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc403  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc404  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc405  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc408  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc40a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc40c  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc40f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc416  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc418  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc41b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc41d  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc423  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc426  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc428  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004fc42a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004fc42c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fc42e  7524                   -jne 0x4fc454
    if (!cpu.flags.zf)
    {
        goto L_0x004fc454;
    }
    // 004fc430  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc432:
    // 004fc432  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc434  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fc436  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc438  e8d3f8ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc43d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc43f  7403                   -je 0x4fc444
    if (cpu.flags.zf)
    {
        goto L_0x004fc444;
    }
    // 004fc441  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
L_0x004fc444:
    // 004fc444  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc447  7515                   -jne 0x4fc45e
    if (!cpu.flags.zf)
    {
        goto L_0x004fc45e;
    }
    // 004fc449  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc44b  83c404                 +add esp, 4
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
    // 004fc44e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc44f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc450  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc451  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc452  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc453  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc454:
    // 004fc454  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc457  e8c4250100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc45c  ebd4                   -jmp 0x4fc432
    goto L_0x004fc432;
L_0x004fc45e:
    // 004fc45e  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc461  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fc463  e8d8250100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc468  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc46a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc46d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc46e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc46f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc470  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc471  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fc480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc485  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc488  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fc48a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc48c  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc48f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc496  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc498  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc49b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc49d  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc4a3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc4a6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc4a8  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc4ab  7526                   -jne 0x4fc4d3
    if (!cpu.flags.zf)
    {
        goto L_0x004fc4d3;
    }
    // 004fc4ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc4af:
    // 004fc4af  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc4b1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fc4b3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fc4b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc4b7  e854f8ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc4bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc4be  741d                   -je 0x4fc4dd
    if (cpu.flags.zf)
    {
        goto L_0x004fc4dd;
    }
    // 004fc4c0  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc4c3  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc4c6  7527                   -jne 0x4fc4ef
    if (!cpu.flags.zf)
    {
        goto L_0x004fc4ef;
    }
    // 004fc4c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc4ca  83c404                 +add esp, 4
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
    // 004fc4cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc4d3:
    // 004fc4d3  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc4d6  e845250100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc4db  ebd2                   -jmp 0x4fc4af
    goto L_0x004fc4af;
L_0x004fc4dd:
    // 004fc4dd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004fc4df  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc4e2  750b                   -jne 0x4fc4ef
    if (!cpu.flags.zf)
    {
        goto L_0x004fc4ef;
    }
    // 004fc4e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc4e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc4e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc4ef:
    // 004fc4ef  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc4f2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fc4f4  e847250100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc4f9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc4fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc4fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc4ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc500  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc502  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc503  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fc510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc514  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fc515  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc518  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc51a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc51c  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc51f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc526  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc528  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc52b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc52d  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc533  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc536  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc538  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc53b  753b                   -jne 0x4fc578
    if (!cpu.flags.zf)
    {
        goto L_0x004fc578;
    }
    // 004fc53d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc53f:
    // 004fc53f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc541  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fc543  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc545  e8c6f7ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc54a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc54c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc54e  741a                   -je 0x4fc56a
    if (cpu.flags.zf)
    {
        goto L_0x004fc56a;
    }
    // 004fc550  833c2400               +cmp dword ptr [esp], 0
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
    // 004fc554  7414                   -je 0x4fc56a
    if (cpu.flags.zf)
    {
        goto L_0x004fc56a;
    }
    // 004fc556  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004fc559  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc55c  7524                   -jne 0x4fc582
    if (!cpu.flags.zf)
    {
        goto L_0x004fc582;
    }
L_0x004fc55e:
    // 004fc55e  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004fc561  e87a7dfeff             -call 0x4e42e0
    cpu.esp -= 4;
    sub_4e42e0(app, cpu);
    if (cpu.terminate) return;
L_0x004fc566:
    // 004fc566  804a0c02               -or byte ptr [edx + 0xc], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004fc56a:
    // 004fc56a  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc56d  754c                   -jne 0x4fc5bb
    if (!cpu.flags.zf)
    {
        goto L_0x004fc5bb;
    }
    // 004fc56f  83c404                 +add esp, 4
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
    // 004fc572  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc573  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc574  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc575  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc576  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc577  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc578:
    // 004fc578  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc57b  e8a0240100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc580  ebbd                   -jmp 0x4fc53f
    goto L_0x004fc53f;
L_0x004fc582:
    // 004fc582  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc585  74d7                   -je 0x4fc55e
    if (cpu.flags.zf)
    {
        goto L_0x004fc55e;
    }
    // 004fc587  83fd07                 +cmp ebp, 7
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
    // 004fc58a  75da                   -jne 0x4fc566
    if (!cpu.flags.zf)
    {
        goto L_0x004fc566;
    }
    // 004fc58c  bdacdc5400             -mov ebp, 0x54dcac
    cpu.ebp = 5561516 /*0x54dcac*/;
    // 004fc591  b8acde5400             -mov eax, 0x54deac
    cpu.eax = 5562028 /*0x54deac*/;
    // 004fc596  bb70030000             -mov ebx, 0x370
    cpu.ebx = 880 /*0x370*/;
    // 004fc59b  68bcde5400             -push 0x54debc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562044 /*0x54debc*/;
    cpu.esp -= 4;
    // 004fc5a0  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004fc5a6  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fc5ab  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fc5b1  e85a4af0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fc5b6  83c404                 +add esp, 4
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
    // 004fc5b9  ebab                   -jmp 0x4fc566
    goto L_0x004fc566;
L_0x004fc5bb:
    // 004fc5bb  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc5be  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fc5c0  e87b240100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc5c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc5c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc5c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc5ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc5cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc5cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc5cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4fc600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004fc600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc602  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc603  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc604  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fc605  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fc607  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc609  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc60c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004fc613  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc615  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc618  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fc61a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc61c  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc621  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004fc624  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc626  01d0                   +add eax, edx
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
    // 004fc628  0f858c000000           -jne 0x4fc6ba
    if (!cpu.flags.zf)
    {
        goto L_0x004fc6ba;
    }
L_0x004fc62e:
    // 004fc62e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fc630  7530                   -jne 0x4fc662
    if (!cpu.flags.zf)
    {
        goto L_0x004fc662;
    }
    // 004fc632  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc633  baacdc5400             -mov edx, 0x54dcac
    cpu.edx = 5561516 /*0x54dcac*/;
    // 004fc638  beecde5400             -mov esi, 0x54deec
    cpu.esi = 5562092 /*0x54deec*/;
    // 004fc63d  bfad030000             -mov edi, 0x3ad
    cpu.edi = 941 /*0x3ad*/;
    // 004fc642  68fcde5400             -push 0x54defc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562108 /*0x54defc*/;
    cpu.esp -= 4;
    // 004fc647  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fc64d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fc653  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fc659  e8b249f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fc65e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc661  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fc662:
    // 004fc662  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004fc665  83f80a                 +cmp eax, 0xa
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
    // 004fc668  0f87ed000000           -ja 0x4fc75b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fc75b;
    }
    // 004fc66e  ff2485d0c54f00         -jmp dword ptr [eax*4 + 0x4fc5d0]
    cpu.ip = app->getMemory<x86::reg32>(5227984 + cpu.eax * 4); goto dynamic_jump;
  case 0x004fc675:
    // 004fc675  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004fc678  c1e01e                 -shl eax, 0x1e
    cpu.eax <<= 30 /*0x1e*/ % 32;
    // 004fc67b  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004fc67e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc680  744e                   -je 0x4fc6d0
    if (cpu.flags.zf)
    {
        goto L_0x004fc6d0;
    }
    // 004fc682  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004fc685  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc687  7447                   -je 0x4fc6d0
    if (cpu.flags.zf)
    {
        goto L_0x004fc6d0;
    }
    // 004fc689  e85279feff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
L_0x004fc68e:
    // 004fc68e  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004fc691  c1e01f                 -shl eax, 0x1f
    cpu.eax <<= 31 /*0x1f*/ % 32;
    // 004fc694  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004fc697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc699  0f85cc000000           -jne 0x4fc76b
    if (!cpu.flags.zf)
    {
        goto L_0x004fc76b;
    }
L_0x004fc69f:
    // 004fc69f  b8744f9f00             -mov eax, 0x9f4f74
    cpu.eax = 10440564 /*0x9f4f74*/;
    // 004fc6a4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fc6a6  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004fc6ad  e81e180100             -call 0x50ded0
    cpu.esp -= 4;
    sub_50ded0(app, cpu);
    if (cpu.terminate) return;
    // 004fc6b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc6b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc6b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc6b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc6b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc6b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc6b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc6ba:
    // 004fc6ba  ba20b84f00             -mov edx, 0x4fb820
    cpu.edx = 5224480 /*0x4fb820*/;
    // 004fc6bf  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fc6c2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004fc6c4  e8d71e0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004fc6c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fc6cb  e95effffff             -jmp 0x4fc62e
    goto L_0x004fc62e;
L_0x004fc6d0:
    // 004fc6d0  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004fc6d3  ebb9                   -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc6d5:
    // 004fc6d5  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004fc6d8  e80379feff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004fc6dd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc6df  ebad                   -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc6e1:
    // 004fc6e1  8b4b28                 -mov ecx, dword ptr [ebx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004fc6e4  eba8                   -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc6e6:
    // 004fc6e6  8b4b24                 -mov ecx, dword ptr [ebx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004fc6e9  eba3                   -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc6eb:
L_0x004fc6eb:
    // 004fc6eb  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004fc6ed  eb9f                   -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc6ef:
    // 004fc6ef  8b732c                 -mov esi, dword ptr [ebx + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 004fc6f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fc6f4  7498                   -je 0x4fc68e
    if (cpu.flags.zf)
    {
        goto L_0x004fc68e;
    }
    // 004fc6f6  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004fc6f9  c1e01e                 -shl eax, 0x1e
    cpu.eax <<= 30 /*0x1e*/ % 32;
    // 004fc6fc  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004fc6ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc701  7506                   -jne 0x4fc709
    if (!cpu.flags.zf)
    {
        goto L_0x004fc709;
    }
    // 004fc703  807b1001               +cmp byte ptr [ebx + 0x10], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fc707  741a                   -je 0x4fc723
    if (cpu.flags.zf)
    {
        goto L_0x004fc723;
    }
L_0x004fc709:
    // 004fc709  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004fc70c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fc70e  7407                   -je 0x4fc717
    if (cpu.flags.zf)
    {
        goto L_0x004fc717;
    }
    // 004fc710  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fc712  e8c978feff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
L_0x004fc717:
    // 004fc717  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc719  e87251feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fc71e  e96bffffff             -jmp 0x4fc68e
    goto L_0x004fc68e;
L_0x004fc723:
    // 004fc723  b8904f9f00             -mov eax, 0x9f4f90
    cpu.eax = 10440592 /*0x9f4f90*/;
    // 004fc728  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fc72a  e8a1170100             -call 0x50ded0
    cpu.esp -= 4;
    sub_50ded0(app, cpu);
    if (cpu.terminate) return;
    // 004fc72f  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004fc732  e957ffffff             -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc737:
    // 004fc737  8b732c                 -mov esi, dword ptr [ebx + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 004fc73a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fc73c  0f844cffffff           -je 0x4fc68e
    if (cpu.flags.zf)
    {
        goto L_0x004fc68e;
    }
    // 004fc742  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004fc745  e89678feff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004fc74a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc74c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004fc751  e83a51feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fc756  e933ffffff             -jmp 0x4fc68e
    goto L_0x004fc68e;
  case 0x004fc75b:
L_0x004fc75b:
    // 004fc75b  807b1001               +cmp byte ptr [ebx + 0x10], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fc75f  758a                   -jne 0x4fc6eb
    if (!cpu.flags.zf)
    {
        goto L_0x004fc6eb;
    }
    // 004fc761  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004fc766  e923ffffff             -jmp 0x4fc68e
    goto L_0x004fc68e;
L_0x004fc76b:
    // 004fc76b  8b432c                 -mov eax, dword ptr [ebx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 004fc76e  e80d4a0000             -call 0x501180
    cpu.esp -= 4;
    sub_501180(app, cpu);
    if (cpu.terminate) return;
    // 004fc773  e927ffffff             -jmp 0x4fc69f
    goto L_0x004fc69f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fc780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc781  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fc782  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fc785  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fc787  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc789  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc78c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc793  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc795  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc798  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc79a  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc7a0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc7a3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc7a5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fc7a7  0f8484000000           -je 0x4fc831
    if (cpu.flags.zf)
    {
        goto L_0x004fc831;
    }
    // 004fc7ad  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc7b0  0f847b000000           -je 0x4fc831
    if (cpu.flags.zf)
    {
        goto L_0x004fc831;
    }
    // 004fc7b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc7b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc7b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc7b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc7ba  8d711c                 -lea esi, [ecx + 0x1c]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc7bd  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x004fc7c1:
    // 004fc7c1  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc7c4  0f856e000000           -jne 0x4fc838
    if (!cpu.flags.zf)
    {
        goto L_0x004fc838;
    }
    // 004fc7ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc7cc:
    // 004fc7cc  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fc7d0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fc7d2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fc7d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc7d6  e835f5ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc7db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc7dd  7405                   -je 0x4fc7e4
    if (cpu.flags.zf)
    {
        goto L_0x004fc7e4;
    }
    // 004fc7df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fc7e4:
    // 004fc7e4  21442410               -and dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) &= x86::reg32(x86::sreg32(cpu.eax));
    // 004fc7e8  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc7eb  7409                   -je 0x4fc7f6
    if (cpu.flags.zf)
    {
        goto L_0x004fc7f6;
    }
    // 004fc7ed  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fc7ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc7f1  e84a220100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
L_0x004fc7f6:
    // 004fc7f6  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc7fb  741c                   -je 0x4fc819
    if (cpu.flags.zf)
    {
        goto L_0x004fc819;
    }
    // 004fc7fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fc7ff  e82c31feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fc804  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc806  7439                   -je 0x4fc841
    if (cpu.flags.zf)
    {
        goto L_0x004fc841;
    }
    // 004fc808  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fc80a  e821aefeff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004fc80f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fc814  e8c730feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004fc819:
    // 004fc819  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fc81e  75a1                   -jne 0x4fc7c1
    if (!cpu.flags.zf)
    {
        goto L_0x004fc7c1;
    }
    // 004fc820  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fc822  e819fbffff             -call 0x4fc340
    cpu.esp -= 4;
    sub_4fc340(app, cpu);
    if (cpu.terminate) return;
    // 004fc827  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc828  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc829  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc82a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fc82b:
    // 004fc82b  83c408                 +add esp, 8
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
    // 004fc82e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc82f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc830  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc831:
    // 004fc831  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 004fc836  ebf3                   -jmp 0x4fc82b
    goto L_0x004fc82b;
L_0x004fc838:
    // 004fc838  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc83a  e8e1210100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc83f  eb8b                   -jmp 0x4fc7cc
    goto L_0x004fc7cc;
L_0x004fc841:
    // 004fc841  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004fc845  a1604f9f00             -mov eax, dword ptr [0x9f4f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc84a  01d0                   +add eax, edx
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
    // 004fc84c  8b405c                 -mov eax, dword ptr [eax + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004fc84f  e80c34feff             -call 0x4dfc60
    cpu.esp -= 4;
    sub_4dfc60(app, cpu);
    if (cpu.terminate) return;
    // 004fc854  ebc3                   -jmp 0x4fc819
    goto L_0x004fc819;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fc860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fc863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc865  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc868  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc86a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc86c  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc86f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc876  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc878  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc87b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc87d  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc883  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc886  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc888  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004fc88a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004fc88c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fc88e  7524                   -jne 0x4fc8b4
    if (!cpu.flags.zf)
    {
        goto L_0x004fc8b4;
    }
    // 004fc890  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc892:
    // 004fc892  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc894  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fc896  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc898  e873f4ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc89d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc89f  7403                   -je 0x4fc8a4
    if (cpu.flags.zf)
    {
        goto L_0x004fc8a4;
    }
    // 004fc8a1  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x004fc8a4:
    // 004fc8a4  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc8a7  7515                   -jne 0x4fc8be
    if (!cpu.flags.zf)
    {
        goto L_0x004fc8be;
    }
    // 004fc8a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc8ab  83c404                 +add esp, 4
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
    // 004fc8ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc8b4:
    // 004fc8b4  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc8b7  e864210100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc8bc  ebd4                   -jmp 0x4fc892
    goto L_0x004fc892;
L_0x004fc8be:
    // 004fc8be  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc8c1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fc8c3  e878210100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc8c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fc8ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc8cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc8d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fc8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc8e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc8e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc8e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fc8e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fc8e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fc8e5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc8e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fc8ea  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fc8ec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fc8ee  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc8f1  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fc8f8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc8fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc8fd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fc8ff  8b0d604f9f00           -mov ecx, dword ptr [0x9f4f60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc905  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc908  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fc90a  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc90d  752f                   -jne 0x4fc93e
    if (!cpu.flags.zf)
    {
        goto L_0x004fc93e;
    }
    // 004fc90f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fc911:
    // 004fc911  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fc913  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fc915  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fc917  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fc919  e8f2f3ffff             -call 0x4fbd10
    cpu.esp -= 4;
    sub_4fbd10(app, cpu);
    if (cpu.terminate) return;
    // 004fc91e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc920  743d                   -je 0x4fc95f
    if (cpu.flags.zf)
    {
        goto L_0x004fc95f;
    }
    // 004fc922  80480c04               -or byte ptr [eax + 0xc], 4
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004fc926  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fc929  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fc92b  741b                   -je 0x4fc948
    if (cpu.flags.zf)
    {
        goto L_0x004fc948;
    }
    // 004fc92d  897820                 -mov dword ptr [eax + 0x20], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edi;
L_0x004fc930:
    // 004fc930  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc933  7566                   -jne 0x4fc99b
    if (!cpu.flags.zf)
    {
        goto L_0x004fc99b;
    }
    // 004fc935  83c404                 +add esp, 4
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
    // 004fc938  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc93a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc93b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc93c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc93d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc93e:
    // 004fc93e  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc941  e8da200100             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 004fc946  ebc9                   -jmp 0x4fc911
    goto L_0x004fc911;
L_0x004fc948:
    // 004fc948  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004fc94b  80480c08               -or byte ptr [eax + 0xc], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004fc94f  8b500d                 -mov edx, dword ptr [eax + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004fc952  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004fc955  c1fa18                 +sar edx, 0x18
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
    // 004fc958  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004fc95b  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fc95d  ebd1                   -jmp 0x4fc930
    goto L_0x004fc930;
L_0x004fc95f:
    // 004fc95f  bbacdc5400             -mov ebx, 0x54dcac
    cpu.ebx = 5561516 /*0x54dcac*/;
    // 004fc964  be38df5400             -mov esi, 0x54df38
    cpu.esi = 5562168 /*0x54df38*/;
    // 004fc969  bfa6040000             -mov edi, 0x4a6
    cpu.edi = 1190 /*0x4a6*/;
    // 004fc96e  6848df5400             -push 0x54df48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562184 /*0x54df48*/;
    cpu.esp -= 4;
    // 004fc973  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004fc979  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fc97f  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fc985  e88646f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fc98a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc98d  833900                 +cmp dword ptr [ecx], 0
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
    // 004fc990  7509                   -jne 0x4fc99b
    if (!cpu.flags.zf)
    {
        goto L_0x004fc99b;
    }
    // 004fc992  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc995  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc996  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc997  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc999  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc99a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc99b:
    // 004fc99b  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004fc99e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fc9a0  e89b200100             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 004fc9a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fc9a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fc9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fc9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fc9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fc9b2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fc9b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fc9b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fc9b8  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004fc9bb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004fc9c2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fc9c4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fc9c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fc9c9  8b15604f9f00           -mov edx, dword ptr [0x9f4f60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440544) /* 0x9f4f60 */);
    // 004fc9cf  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004fc9d2  01d0                   +add eax, edx
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
    // 004fc9d4  7503                   -jne 0x4fc9d9
    if (!cpu.flags.zf)
    {
        goto L_0x004fc9d9;
    }
L_0x004fc9d6:
    // 004fc9d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fc9d9:
    // 004fc9d9  ba20b84f00             -mov edx, 0x4fb820
    cpu.edx = 5224480 /*0x4fb820*/;
    // 004fc9de  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fc9e1  e8ba1b0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004fc9e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fc9e8  74ec                   -je 0x4fc9d6
    if (cpu.flags.zf)
    {
        goto L_0x004fc9d6;
    }
    // 004fc9ea  884811                 -mov byte ptr [eax + 0x11], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = cpu.cl;
    // 004fc9ed  e86ef1ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fc9f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fc9f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fca00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fca00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fca01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fca02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fca04  e847040000             -call 0x4fce50
    cpu.esp -= 4;
    sub_4fce50(app, cpu);
    if (cpu.terminate) return;
    // 004fca09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca0b  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004fca10  e87befffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fca15  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fca17  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca19  e8c2f1ffff             -call 0x4fbbe0
    cpu.esp -= 4;
    sub_4fbbe0(app, cpu);
    if (cpu.terminate) return;
    // 004fca1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fca20  e83bf1ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fca25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fca30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fca30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fca31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fca32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fca34  e817040000             -call 0x4fce50
    cpu.esp -= 4;
    sub_4fce50(app, cpu);
    if (cpu.terminate) return;
    // 004fca39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca3b  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004fca40  e84befffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fca45  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fca47  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca49  e892f1ffff             -call 0x4fbbe0
    cpu.esp -= 4;
    sub_4fbbe0(app, cpu);
    if (cpu.terminate) return;
    // 004fca4e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fca50  e80bf1ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fca55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fca60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fca60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fca61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fca62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fca64  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fca66  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fca68  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fca6a  e8e1030000             -call 0x4fce50
    cpu.esp -= 4;
    sub_4fce50(app, cpu);
    if (cpu.terminate) return;
    // 004fca6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fca73  e818efffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fca78  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fca7a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca7c  e85ff1ffff             -call 0x4fbbe0
    cpu.esp -= 4;
    sub_4fbbe0(app, cpu);
    if (cpu.terminate) return;
    // 004fca81  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fca83  897924                 -mov dword ptr [ecx + 0x24], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004fca86  e8d5f0ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fca8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fca8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fca90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fca90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fca91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fca92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fca94  e88778feff             -call 0x4e4320
    cpu.esp -= 4;
    sub_4e4320(app, cpu);
    if (cpu.terminate) return;
    // 004fca99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fca9b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fcaa0  e8ebeeffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fcaa5  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004fcaa8  e8b3f0ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fcaad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcaae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcaaf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fcab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fcab0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fcab1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fcab2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fcab3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fcab6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fcab8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fcaba  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004fcabc  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fcabf  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004fcac3  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004fcac7  e85478feff             -call 0x4e4320
    cpu.esp -= 4;
    sub_4e4320(app, cpu);
    if (cpu.terminate) return;
    // 004fcacc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fcace  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004fcad3  e8b8eeffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fcad8  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004fcadb  897824                 -mov dword ptr [eax + 0x24], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004fcade  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fcae1  89682c                 -mov dword ptr [eax + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 004fcae4  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004fcae7  e874f0ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fcaec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fcaef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcaf0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcaf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcaf2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fcb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fcb00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fcb01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fcb02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fcb03  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fcb06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fcb08  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fcb0a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004fcb0c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fcb0f  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004fcb13  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004fcb17  e80478feff             -call 0x4e4320
    cpu.esp -= 4;
    sub_4e4320(app, cpu);
    if (cpu.terminate) return;
    // 004fcb1c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fcb1e  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004fcb23  e868eeffff             -call 0x4fb990
    cpu.esp -= 4;
    sub_4fb990(app, cpu);
    if (cpu.terminate) return;
    // 004fcb28  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004fcb2b  897824                 -mov dword ptr [eax + 0x24], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004fcb2e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fcb31  89682c                 -mov dword ptr [eax + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 004fcb34  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004fcb37  e824f0ffff             -call 0x4fbb60
    cpu.esp -= 4;
    sub_4fbb60(app, cpu);
    if (cpu.terminate) return;
    // 004fcb3c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fcb3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcb40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcb41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fcb42  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
