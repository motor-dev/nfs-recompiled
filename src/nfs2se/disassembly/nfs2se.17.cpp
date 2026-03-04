#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8b 0xc0 */
void Application::sub_478fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478fd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478fd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478fdb  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478fe0  e86ba60100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478fe5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478fe7  e80c000000             -call 0x478ff8
    cpu.esp -= 4;
    sub_478ff8(app, cpu);
    if (cpu.terminate) return;
    // 00478fec  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478ff1  e862a60100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478ff6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ff7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478ff8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478ff9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00478ffb  7405                   -je 0x479002
    if (cpu.flags.zf)
    {
        goto L_0x00479002;
    }
    // 00478ffd  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00479002:
    // 00479002  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00479005  80e5df                 -and ch, 0xdf
    cpu.ch &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 00479008  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047900a  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0047900d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047900e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479011  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479012  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479013  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479014  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479015  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479017  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00479019:
    // 00479019  8b96b4b55100           -mov edx, dword ptr [esi + 0x51b5b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354932) /* 0x51b5b4 */);
    // 0047901f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479021  7421                   -je 0x479044
    if (cpu.flags.zf)
    {
        goto L_0x00479044;
    }
    // 00479023  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00479025  8b86b0b55100           -mov eax, dword ptr [esi + 0x51b5b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354928) /* 0x51b5b0 */);
L_0x0047902b:
    // 0047902b  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047902e  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00479030  39f9                   +cmp ecx, edi
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
    // 00479032  7223                   -jb 0x479057
    if (cpu.flags.cf)
    {
        goto L_0x00479057;
    }
    // 00479034  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00479037  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0047903a  39d1                   +cmp ecx, edx
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
    // 0047903c  7319                   -jae 0x479057
    if (!cpu.flags.cf)
    {
        goto L_0x00479057;
    }
L_0x0047903e:
    // 0047903e  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 00479042  740d                   -je 0x479051
    if (cpu.flags.zf)
    {
        goto L_0x00479051;
    }
L_0x00479044:
    // 00479044  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00479047  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047904d  7cca                   -jl 0x479019
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479019;
    }
    // 0047904f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479051:
    // 00479051  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479052  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479053  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479054  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479055  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479056  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479057:
    // 00479057  39d8                   +cmp eax, ebx
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
    // 00479059  75d0                   -jne 0x47902b
    if (!cpu.flags.zf)
    {
        goto L_0x0047902b;
    }
    // 0047905b  ebe1                   -jmp 0x47903e
    goto L_0x0047903e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479060  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479061  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00479066  e8a5ffffff             -call 0x479010
    cpu.esp -= 4;
    sub_479010(app, cpu);
    if (cpu.terminate) return;
    // 0047906b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047906c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479071  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479073  e898ffffff             -call 0x479010
    cpu.esp -= 4;
    sub_479010(app, cpu);
    if (cpu.terminate) return;
    // 00479078  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479080  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479081  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479083  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047908a  7507                   -jne 0x479093
    if (!cpu.flags.zf)
    {
        goto L_0x00479093;
    }
    // 0047908c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00479091  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479092  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479093:
    // 00479093  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479095  e89a110000             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 0047909a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047909c  751c                   -jne 0x4790ba
    if (!cpu.flags.zf)
    {
        goto L_0x004790ba;
    }
    // 0047909e  8b04d5008a5200         -mov eax, dword ptr [edx*8 + 0x528a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.edx * 8);
    // 004790a5  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004790ab  7519                   -jne 0x4790c6
    if (!cpu.flags.zf)
    {
        goto L_0x004790c6;
    }
    // 004790ad  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004790b1  770e                   -ja 0x4790c1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004790c1;
    }
    // 004790b3  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004790b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004790ba:
    // 004790ba  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004790bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004790c1:
    // 004790c1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004790c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004790c6:
    // 004790c6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004790cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4790d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004790d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004790d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004790d3  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004790da  7507                   -jne 0x4790e3
    if (!cpu.flags.zf)
    {
        goto L_0x004790e3;
    }
    // 004790dc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004790e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004790e3:
    // 004790e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004790e5  e84a110000             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 004790ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004790ec  752d                   -jne 0x47911b
    if (!cpu.flags.zf)
    {
        goto L_0x0047911b;
    }
    // 004790ee  8b04cd008a5200         -mov eax, dword ptr [ecx*8 + 0x528a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.ecx * 8);
    // 004790f5  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004790f9  7627                   -jbe 0x479122
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479122;
    }
    // 004790fb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004790fd  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00479101  39ca                   +cmp edx, ecx
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
    // 00479103  7d16                   -jge 0x47911b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047911b;
    }
    // 00479105  8b44900c               -mov eax, dword ptr [eax + edx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 00479109  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047910e  7520                   -jne 0x479130
    if (!cpu.flags.zf)
    {
        goto L_0x00479130;
    }
    // 00479110  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 00479114  7413                   -je 0x479129
    if (cpu.flags.zf)
    {
        goto L_0x00479129;
    }
    // 00479116  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00479119  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047911a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047911b:
    // 0047911b  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00479120  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479121  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479122:
    // 00479122  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00479127  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479128  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479129:
    // 00479129  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 0047912e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047912f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479130:
    // 00479130  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00479135  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479136  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479138(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479138  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479139  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047913a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047913d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047913f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00479143  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00479149  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0047914e  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00479150  740f                   -je 0x479161
    if (cpu.flags.zf)
    {
        goto L_0x00479161;
    }
    // 00479152  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479154  7512                   -jne 0x479168
    if (!cpu.flags.zf)
    {
        goto L_0x00479168;
    }
    // 00479156  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0047915b:
    // 0047915b  83c410                 +add esp, 0x10
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
    // 0047915e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047915f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479160  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479161:
    // 00479161  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00479166  ebf3                   -jmp 0x47915b
    goto L_0x0047915b;
L_0x00479168:
    // 00479168  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047916a  e811ffffff             -call 0x479080
    cpu.esp -= 4;
    sub_479080(app, cpu);
    if (cpu.terminate) return;
    // 0047916f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479171  7ce8                   -jl 0x47915b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047915b;
    }
    // 00479173  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479174  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479175  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479176  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00479178  8b14d5008a5200         -mov edx, dword ptr [edx*8 + 0x528a00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.edx * 8);
    // 0047917f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00479183  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479185  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00479189  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047918b  e8c0750000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00479190  8b14cd008a5200         -mov edx, dword ptr [ecx*8 + 0x528a00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.ecx * 8);
    // 00479197  807a0401               +cmp byte ptr [edx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047919b  7204                   -jb 0x4791a1
    if (cpu.flags.cf)
    {
        goto L_0x004791a1;
    }
    // 0047919d  0fb76a06               -movzx ebp, word ptr [edx + 6]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */));
L_0x004791a1:
    // 004791a1  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004791a5  7248                   -jb 0x4791ef
    if (cpu.flags.cf)
    {
        goto L_0x004791ef;
    }
    // 004791a7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004791a9  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x004791ad:
    // 004791ad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004791af  7e28                   -jle 0x4791d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004791d9;
    }
    // 004791b1  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 004791b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004791b6:
    // 004791b6  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004791ba  7239                   -jb 0x4791f5
    if (cpu.flags.cf)
    {
        goto L_0x004791f5;
    }
    // 004791bc  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004791bf  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004791c2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004791c4  740c                   -je 0x4791d2
    if (cpu.flags.zf)
    {
        goto L_0x004791d2;
    }
    // 004791c6  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004791c8  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004791cc  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004791ce  894c030c               -mov dword ptr [ebx + eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ecx;
L_0x004791d2:
    // 004791d2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791d5  39e8                   +cmp eax, ebp
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
    // 004791d7  7cdd                   -jl 0x4791b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004791b6;
    }
L_0x004791d9:
    // 004791d9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004791dd  8934c5008a5200         -mov dword ptr [eax*8 + 0x528a00], esi
    app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.eax * 8) = cpu.esi;
    // 004791e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004791e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791e9  83c410                 +add esp, 0x10
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
    // 004791ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004791ef:
    // 004791ef  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004791f3  ebb8                   -jmp 0x4791ad
    goto L_0x004791ad;
L_0x004791f5:
    // 004791f5  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004791f8  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004791fb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004791fd  74d3                   -je 0x4791d2
    if (cpu.flags.zf)
    {
        goto L_0x004791d2;
    }
    // 004791ff  29d1                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479201  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 00479204  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479208  895c0108               -mov dword ptr [ecx + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 0047920c  ebc4                   -jmp 0x4791d2
    goto L_0x004791d2;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479210  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479211  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479212  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479214  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00479216  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047921d  740c                   -je 0x47922b
    if (cpu.flags.zf)
    {
        goto L_0x0047922b;
    }
    // 0047921f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479221  7510                   -jne 0x479233
    if (!cpu.flags.zf)
    {
        goto L_0x00479233;
    }
    // 00479223  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x00479228:
    // 00479228  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479229  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047922a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047922b:
    // 0047922b  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00479230  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479231  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479232  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479233:
    // 00479233  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479235  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479237  e894feffff             -call 0x4790d0
    cpu.esp -= 4;
    sub_4790d0(app, cpu);
    if (cpu.terminate) return;
    // 0047923c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047923e  7ce8                   -jl 0x479228
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479228;
    }
    // 00479240  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479241  8b3cf5008a5200         -mov edi, dword ptr [esi*8 + 0x528a00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.esi * 8);
    // 00479248  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047924b  8a5704                 -mov dl, byte ptr [edi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047924e  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00479251  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479254  7517                   -jne 0x47926d
    if (!cpu.flags.zf)
    {
        goto L_0x0047926d;
    }
    // 00479256  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479258  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047925b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047925d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047925f  e8ec740000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00479264  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00479267  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047926a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047926b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047926c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047926d:
    // 0047926d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047926f  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00479272  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479274  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00479276  e8d5740000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0047927b  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047927e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479280  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479281  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479282  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479283  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479284(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479284  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479285  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00479287  e810100000             -call 0x47a29c
    cpu.esp -= 4;
    sub_47a29c(app, cpu);
    if (cpu.terminate) return;
    // 0047928c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047928d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479291  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00479293  e898ac0100             -call 0x493f30
    cpu.esp -= 4;
    sub_493f30(app, cpu);
    if (cpu.terminate) return;
    // 00479298  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479299  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4792a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004792a2  7506                   -jne 0x4792aa
    if (!cpu.flags.zf)
    {
        goto L_0x004792aa;
    }
    // 004792a4  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004792a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004792aa:
    // 004792aa  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 004792b0  c64004ff               -mov byte ptr [eax + 4], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 255 /*0xff*/;
    // 004792b4  c640053c               -mov byte ptr [eax + 5], 0x3c
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 60 /*0x3c*/;
    // 004792b8  c640067f               -mov byte ptr [eax + 6], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 127 /*0x7f*/;
    // 004792bc  c6400740               -mov byte ptr [eax + 7], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 004792c0  c640087f               -mov byte ptr [eax + 8], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004792c4  c6400940               -mov byte ptr [eax + 9], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = 64 /*0x40*/;
    // 004792c8  c6400a7f               -mov byte ptr [eax + 0xa], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = 127 /*0x7f*/;
    // 004792cc  c6400b00               -mov byte ptr [eax + 0xb], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 004792d0  66c7400c0000           -mov word ptr [eax + 0xc], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004792d6  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004792dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004792de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4792e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004792e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004792e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004792e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792e5  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 004792eb  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 004792f0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004792f2  740d                   -je 0x479301
    if (cpu.flags.zf)
    {
        goto L_0x00479301;
    }
    // 004792f4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004792f6  7512                   -jne 0x47930a
    if (!cpu.flags.zf)
    {
        goto L_0x0047930a;
    }
L_0x004792f8:
    // 004792f8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004792fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479300  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479301:
    // 00479301  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00479306  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479307  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479308  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479309  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047930a:
    // 0047930a  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047930d  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00479310  e81f0f0000             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 00479315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479317  7cdf                   -jl 0x4792f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004792f8;
    }
    // 00479319  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047931c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047931f  8b04c5008a5200         -mov eax, dword ptr [eax*8 + 0x528a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.eax * 8);
    // 00479326  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047932a  7206                   -jb 0x479332
    if (cpu.flags.cf)
    {
        goto L_0x00479332;
    }
    // 0047932c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047932e  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x00479332:
    // 00479332  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479334  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479336  7cc0                   -jl 0x4792f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004792f8;
    }
    // 00479338  39d9                   +cmp ecx, ebx
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
    // 0047933a  7ebc                   -jle 0x4792f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004792f8;
    }
    // 0047933c  80780402               +cmp byte ptr [eax + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479340  720f                   -jb 0x479351
    if (cpu.flags.cf)
    {
        goto L_0x00479351;
    }
    // 00479342  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479344  8b44880c               -mov eax, dword ptr [eax + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00479348  e843b20100             -call 0x494590
    cpu.esp -= 4;
    sub_494590(app, cpu);
    if (cpu.terminate) return;
    // 0047934d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047934e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047934f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479350  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479351:
    // 00479351  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479353  8b448808               -mov eax, dword ptr [eax + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00479357  e834b20100             -call 0x494590
    cpu.esp -= 4;
    sub_494590(app, cpu);
    if (cpu.terminate) return;
    // 0047935c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047935d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047935e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047935f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479360  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 00479363  7507                   -jne 0x47936c
    if (!cpu.flags.zf)
    {
        goto L_0x0047936c;
    }
    // 00479365  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047936a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047936b  90                     -nop 
    ;
L_0x0047936c:
    // 0047936c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047936e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47936c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047936c;
    // 00479360  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 00479363  7507                   -jne 0x47936c
    if (!cpu.flags.zf)
    {
        goto L_0x0047936c;
    }
    // 00479365  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047936a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047936b  90                     -nop 
    ;
L_0x0047936c:
L_entry_0x0047936c:
    // 0047936c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047936e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479371  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479372  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479378  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047937a  7434                   -je 0x4793b0
    if (cpu.flags.zf)
    {
        goto L_0x004793b0;
    }
    // 0047937c  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047937f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479381  7407                   -je 0x47938a
    if (cpu.flags.zf)
    {
        goto L_0x0047938a;
    }
    // 00479383  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x0047938a:
    // 0047938a  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479390  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479392  b844b75100             -mov eax, 0x51b744
    cpu.eax = 5355332 /*0x51b744*/;
    // 00479397  e8445b0000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 0047939c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047939e:
    // 0047939e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004793a3  3b10                   +cmp edx, dword ptr [eax]
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
    // 004793a5  7409                   -je 0x4793b0
    if (cpu.flags.zf)
    {
        goto L_0x004793b0;
    }
    // 004793a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004793a9  7405                   -je 0x4793b0
    if (cpu.flags.zf)
    {
        goto L_0x004793b0;
    }
    // 004793ab  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004793ae  7403                   -je 0x4793b3
    if (cpu.flags.zf)
    {
        goto L_0x004793b3;
    }
L_0x004793b0:
    // 004793b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004793b3:
    // 004793b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004793b5  e8a2580000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 004793ba  ebe2                   -jmp 0x47939e
    goto L_0x0047939e;
}

/* align: skip  */
void Application::sub_4793bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004793bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004793bd  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004793c2  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004793c5  e892690000             -call 0x47fd5c
    cpu.esp -= 4;
    sub_47fd5c(app, cpu);
    if (cpu.terminate) return;
    // 004793ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004793cc  7707                   -ja 0x4793d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004793d5;
    }
L_0x004793ce:
    // 004793ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004793d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793d1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004793d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004793d5:
    // 004793d5  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004793da  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004793dd  e86e680000             -call 0x47fc50
    cpu.esp -= 4;
    sub_47fc50(app, cpu);
    if (cpu.terminate) return;
    // 004793e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004793e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004793e6  74e6                   -je 0x4793ce
    if (cpu.flags.zf)
    {
        goto L_0x004793ce;
    }
L_0x004793e8:
    // 004793e8  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004793eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004793ed  740a                   -je 0x4793f9
    if (cpu.flags.zf)
    {
        goto L_0x004793f9;
    }
    // 004793ef  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004793f4  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004793f7  752c                   -jne 0x479425
    if (!cpu.flags.zf)
    {
        goto L_0x00479425;
    }
L_0x004793f9:
    // 004793f9  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004793fe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479400  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00479403:
    // 00479403  e888670000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479408  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047940b  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047940e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479413  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00479416  e835680000             -call 0x47fc50
    cpu.esp -= 4;
    sub_47fc50(app, cpu);
    if (cpu.terminate) return;
    // 0047941b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047941d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047941f  75c7                   -jne 0x4793e8
    if (!cpu.flags.zf)
    {
        goto L_0x004793e8;
    }
    // 00479421  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479423  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479424  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479425:
    // 00479425  83c038                 +add eax, 0x38
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
    // 00479428  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047942a  ebd7                   -jmp 0x479403
    goto L_0x00479403;
}

/* align: skip  */
void Application::sub_47942c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047942c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047942d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047942e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479430  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479436  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00479439  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047943b  0f85dc000000           -jne 0x47951d
    if (!cpu.flags.zf)
    {
        goto L_0x0047951d;
    }
L_0x00479441:
    // 00479441  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00479448  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047944a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047944d  8d888c000000           -lea ecx, [eax + 0x8c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00479453  b864de4b00             -mov eax, 0x4bde64
    cpu.eax = 4972132 /*0x4bde64*/;
    // 00479458  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047945a  e809f2ffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0047945f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479461  a340b75100             -mov dword ptr [0x51b740], eax
    app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */) = cpu.eax;
    // 00479466  e8715c0000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047946b  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479470  e847f6ffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 00479475  8b0d40b75100           -mov ecx, dword ptr [0x51b740]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047947b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047947d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047947f  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00479482  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00479485  e8b2660000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0047948a  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047948f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479491  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479493  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00479496  e8a1660000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0047949b  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004794a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004794a2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004794a4  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004794a7  e890660000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 004794ac  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004794b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004794b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004794b5  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004794b8  e87f660000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 004794bd  8b0d40b75100           -mov ecx, dword ptr [0x51b740]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004794c3  81c18c000000           -add ecx, 0x8c
    (cpu.ecx) += x86::reg32(x86::sreg32(140 /*0x8c*/));
L_0x004794c9:
    // 004794c9  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004794ce  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004794d0  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004794d3  e8b8660000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 004794d8  83c128                 +add ecx, 0x28
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004794db  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004794dc  75eb                   -jne 0x4794c9
    if (!cpu.flags.zf)
    {
        goto L_0x004794c9;
    }
    // 004794de  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004794e3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004794e8  b8bc934700             -mov eax, 0x4793bc
    cpu.eax = 4690876 /*0x4793bc*/;
    // 004794ed  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004794f2  e8a9eaffff             -call 0x477fa0
    cpu.esp -= 4;
    sub_477fa0(app, cpu);
    if (cpu.terminate) return;
    // 004794f7  6844b75100             -push 0x51b744
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355332 /*0x51b744*/;
    cpu.esp -= 4;
    // 004794fc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00479501  b8589b4700             -mov eax, 0x479b58
    cpu.eax = 4692824 /*0x479b58*/;
    // 00479506  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479508  e893560000             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 0047950d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047950f  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479514  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00479516  39d9                   +cmp ecx, ebx
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
    // 00479518  740d                   -je 0x479527
    if (cpu.flags.zf)
    {
        goto L_0x00479527;
    }
    // 0047951a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047951b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047951c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047951d:
    // 0047951d  e81a000000             -call 0x47953c
    cpu.esp -= 4;
    sub_47953c(app, cpu);
    if (cpu.terminate) return;
    // 00479522  e91affffff             -jmp 0x479441
    goto L_0x00479441;
L_0x00479527:
    // 00479527  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479529  e82e570000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0047952e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479533  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00479535  39d9                   +cmp ecx, ebx
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
    // 00479537  74ee                   -je 0x479527
    if (cpu.flags.zf)
    {
        goto L_0x00479527;
    }
    // 00479539  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047953a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047953b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47953c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047953c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047953d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047953e  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479544  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479546  7503                   -jne 0x47954b
    if (!cpu.flags.zf)
    {
        goto L_0x0047954b;
    }
    // 00479548  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479549  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047954a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047954b:
    // 0047954b  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00479552  e819feffff             -call 0x479370
    cpu.esp -= 4;
    sub_479370(app, cpu);
    if (cpu.terminate) return;
    // 00479557  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00479559:
    // 00479559  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047955e  3b10                   +cmp edx, dword ptr [eax]
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
    // 00479560  7409                   -je 0x47956b
    if (cpu.flags.zf)
    {
        goto L_0x0047956b;
    }
    // 00479562  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479564  e8f3560000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00479569  ebee                   -jmp 0x479559
    goto L_0x00479559;
L_0x0047956b:
    // 0047956b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047956c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047956d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047956e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047956f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479572  e895660000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 00479577  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479579  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047957b  743c                   -je 0x4795b9
    if (cpu.flags.zf)
    {
        goto L_0x004795b9;
    }
L_0x0047957d:
    // 0047957d  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00479580  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479582  7407                   -je 0x47958b
    if (cpu.flags.zf)
    {
        goto L_0x0047958b;
    }
    // 00479584  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479586  e841f5ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0047958b:
    // 0047958b  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047958e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479590  7407                   -je 0x479599
    if (cpu.flags.zf)
    {
        goto L_0x00479599;
    }
    // 00479592  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479594  e85ff5ffff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
L_0x00479599:
    // 00479599  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047959e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004795a1  e8ea650000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 004795a6  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004795ab  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004795ae  e859660000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 004795b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004795b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004795b7  75c4                   -jne 0x47957d
    if (!cpu.flags.zf)
    {
        goto L_0x0047957d;
    }
L_0x004795b9:
    // 004795b9  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004795be  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004795c1  e846660000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 004795c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004795c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004795ca  743c                   -je 0x479608
    if (cpu.flags.zf)
    {
        goto L_0x00479608;
    }
L_0x004795cc:
    // 004795cc  8b7a1c                 -mov edi, dword ptr [edx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004795cf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004795d1  7407                   -je 0x4795da
    if (cpu.flags.zf)
    {
        goto L_0x004795da;
    }
    // 004795d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004795d5  e8f2f4ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x004795da:
    // 004795da  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004795dd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004795df  7407                   -je 0x4795e8
    if (cpu.flags.zf)
    {
        goto L_0x004795e8;
    }
    // 004795e1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004795e3  e810f5ffff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
L_0x004795e8:
    // 004795e8  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004795ed  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004795f0  e89b650000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 004795f5  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004795fa  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004795fd  e80a660000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 00479602  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479604  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479606  75c4                   -jne 0x4795cc
    if (!cpu.flags.zf)
    {
        goto L_0x004795cc;
    }
L_0x00479608:
    // 00479608  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047960d  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00479610  e8f7650000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 00479615  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479617  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479619  743c                   -je 0x479657
    if (cpu.flags.zf)
    {
        goto L_0x00479657;
    }
L_0x0047961b:
    // 0047961b  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0047961e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479620  7407                   -je 0x479629
    if (cpu.flags.zf)
    {
        goto L_0x00479629;
    }
    // 00479622  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479624  e8a3f4ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x00479629:
    // 00479629  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047962c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047962e  7407                   -je 0x479637
    if (cpu.flags.zf)
    {
        goto L_0x00479637;
    }
    // 00479630  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00479632  e8c1f4ffff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
L_0x00479637:
    // 00479637  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047963c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047963f  e84c650000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479644  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479649  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047964c  e8bb650000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 00479651  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479655  75c4                   -jne 0x47961b
    if (!cpu.flags.zf)
    {
        goto L_0x0047961b;
    }
L_0x00479657:
    // 00479657  b8bc934700             -mov eax, 0x4793bc
    cpu.eax = 4690876 /*0x4793bc*/;
    // 0047965c  e8d3e9ffff             -call 0x478034
    cpu.esp -= 4;
    sub_478034(app, cpu);
    if (cpu.terminate) return;
    // 00479661  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479666  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479669  e80e650000             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0047966e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479673  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00479676  e801650000             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0047967b  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479680  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479683  e8f4640000             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 00479688  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047968d  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00479690  e8e7640000             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 00479695  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047969a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047969d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047969f  7407                   -je 0x4796a8
    if (cpu.flags.zf)
    {
        goto L_0x004796a8;
    }
    // 004796a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004796a3  e808200000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
L_0x004796a8:
    // 004796a8  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004796ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004796af  e818f4ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004796b4  890d40b75100           -mov dword ptr [0x51b740], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */) = cpu.ecx;
    // 004796ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4796c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004796c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004796c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004796c6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004796c8  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004796cd  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004796d0  e837650000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 004796d5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004796d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004796d9  7503                   -jne 0x4796de
    if (!cpu.flags.zf)
    {
        goto L_0x004796de;
    }
    // 004796db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004796dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004796de:
    // 004796de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004796df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004796e0  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004796e7  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004796ee  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004796f5  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004796fc  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479703  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00479706  a178854c00             -mov eax, dword ptr [0x4c8578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */);
    // 0047970b  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047970e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00479710  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479713  40                     -inc eax
    (cpu.eax)++;
    // 00479714  8b1d50824c00           -mov ebx, dword ptr [0x4c8250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 0047971a  a378854c00             -mov dword ptr [0x4c8578], eax
    app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */) = cpu.eax;
    // 0047971f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479721  49                     -dec ecx
    (cpu.ecx)--;
    // 00479722  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479724  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00479726  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00479728  49                     -dec ecx
    (cpu.ecx)--;
    // 00479729  b8a0de4b00             -mov eax, 0x4bdea0
    cpu.eax = 4972192 /*0x4bdea0*/;
    // 0047972e  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00479731  e832efffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00479736  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479738  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047973b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047973c:
    // 0047973c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047973e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00479740  3c00                   +cmp al, 0
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
    // 00479742  7410                   -je 0x479754
    if (cpu.flags.zf)
    {
        goto L_0x00479754;
    }
    // 00479744  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00479747  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047974a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047974d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479750  3c00                   +cmp al, 0
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
    // 00479752  75e8                   -jne 0x47973c
    if (!cpu.flags.zf)
    {
        goto L_0x0047973c;
    }
L_0x00479754:
    // 00479754  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479755  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047975a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047975c  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047975f  e82c640000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479764  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047976a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047976c  b844b75100             -mov eax, 0x51b744
    cpu.eax = 5355332 /*0x51b744*/;
    // 00479771  e86a570000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00479776  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00479779  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047977d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479781  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479783  e83cffffff             -call 0x4796c4
    cpu.esp -= 4;
    sub_4796c4(app, cpu);
    if (cpu.terminate) return;
    // 00479788  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479789  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47978c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047978c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047978d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047978e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479790  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479795  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479798  e86f640000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 0047979d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047979f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004797a1  7503                   -jne 0x4797a6
    if (!cpu.flags.zf)
    {
        goto L_0x004797a6;
    }
    // 004797a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004797a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004797a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004797a6:
    // 004797a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004797a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004797a8  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004797af  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004797b6  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004797bd  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004797c4  a178854c00             -mov eax, dword ptr [0x4c8578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */);
    // 004797c9  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004797cc  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004797ce  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004797d1  8b1550824c00           -mov edx, dword ptr [0x4c8250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004797d7  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004797da  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004797dc  40                     -inc eax
    (cpu.eax)++;
    // 004797dd  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004797e0  a378854c00             -mov dword ptr [0x4c8578], eax
    app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */) = cpu.eax;
    // 004797e5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004797e7  49                     -dec ecx
    (cpu.ecx)--;
    // 004797e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004797ea  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004797ec  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004797ee  49                     -dec ecx
    (cpu.ecx)--;
    // 004797ef  b8a0de4b00             -mov eax, 0x4bdea0
    cpu.eax = 4972192 /*0x4bdea0*/;
    // 004797f4  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004797f7  e86ceeffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004797fc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004797fe  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00479801  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00479802:
    // 00479802  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479804  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00479806  3c00                   +cmp al, 0
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
    // 00479808  7410                   -je 0x47981a
    if (cpu.flags.zf)
    {
        goto L_0x0047981a;
    }
    // 0047980a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047980d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479810  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00479813  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479816  3c00                   +cmp al, 0
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
    // 00479818  75e8                   -jne 0x479802
    if (!cpu.flags.zf)
    {
        goto L_0x00479802;
    }
L_0x0047981a:
    // 0047981a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047981b  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479820  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00479822  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479825  e866630000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0047982a  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479830  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00479832  b844b75100             -mov eax, 0x51b744
    cpu.eax = 5355332 /*0x51b744*/;
    // 00479837  e8a4560000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 0047983c  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047983f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479840  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479841  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479842  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479843  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479844  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479845  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479847  e840ffffff             -call 0x47978c
    cpu.esp -= 4;
    sub_47978c(app, cpu);
    if (cpu.terminate) return;
    // 0047984c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047984d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479850  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479851  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479852  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479855  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00479857  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 0047985c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047985f  e8a8630000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 00479864  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479866  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00479869  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047986b  746d                   -je 0x4798da
    if (cpu.flags.zf)
    {
        goto L_0x004798da;
    }
    // 0047986d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047986e  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00479875  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047987c  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00479883  c7462002000000         -mov dword ptr [esi + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0047988a  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00479891  a178854c00             -mov eax, dword ptr [0x4c8578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */);
    // 00479896  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047989d  8b1550824c00           -mov edx, dword ptr [0x4c8250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004798a3  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004798a6  40                     -inc eax
    (cpu.eax)++;
    // 004798a7  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004798aa  a378854c00             -mov dword ptr [0x4c8578], eax
    app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */) = cpu.eax;
    // 004798af  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004798b1  752d                   -jne 0x4798e0
    if (!cpu.flags.zf)
    {
        goto L_0x004798e0;
    }
    // 004798b3  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x004798b6:
    // 004798b6  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004798bb  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004798bf  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004798c2  e8c9620000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 004798c7  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004798cd  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004798cf  b844b75100             -mov eax, 0x51b744
    cpu.eax = 5355332 /*0x51b744*/;
    // 004798d4  e807560000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 004798d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004798da:
    // 004798da  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004798dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004798e0:
    // 004798e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004798e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004798e3  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004798e5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004798e7  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004798e9  49                     -dec ecx
    (cpu.ecx)--;
    // 004798ea  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004798ec  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004798ee  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004798f0  49                     -dec ecx
    (cpu.ecx)--;
    // 004798f1  b8a0de4b00             -mov eax, 0x4bdea0
    cpu.eax = 4972192 /*0x4bdea0*/;
    // 004798f6  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004798f9  e86aedffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004798fe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479900  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00479903  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00479905  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00479906:
    // 00479906  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479908  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047990a  3c00                   +cmp al, 0
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
    // 0047990c  7410                   -je 0x47991e
    if (cpu.flags.zf)
    {
        goto L_0x0047991e;
    }
    // 0047990e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00479911  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479914  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00479917  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047991a  3c00                   +cmp al, 0
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
    // 0047991c  75e8                   -jne 0x479906
    if (!cpu.flags.zf)
    {
        goto L_0x00479906;
    }
L_0x0047991e:
    // 0047991e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047991f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479920  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479922  eb92                   -jmp 0x4798b6
    goto L_0x004798b6;
}

/* align: skip  */
void Application::sub_479924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479925  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479927  e840faffff             -call 0x47936c
    cpu.esp -= 4;
    sub_47936c(app, cpu);
    if (cpu.terminate) return;
    // 0047992c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047992d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479930  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479931  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479932  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479935  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479937  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047993a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047993c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047993e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479943  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479946  e8c1620000             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 0047994b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047994d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047994f  7506                   -jne 0x479957
    if (!cpu.flags.zf)
    {
        goto L_0x00479957;
    }
    // 00479951  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479955  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479956  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479957:
    // 00479957  a178854c00             -mov eax, dword ptr [0x4c8578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */);
    // 0047995c  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047995f  40                     -inc eax
    (cpu.eax)++;
    // 00479960  8b1d40b75100           -mov ebx, dword ptr [0x51b740]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479966  a378854c00             -mov dword ptr [0x4c8578], eax
    app->getMemory<x86::reg32>(x86::reg32(5014904) /* 0x4c8578 */) = cpu.eax;
    // 0047996b  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0047996e  c7412003000000         -mov dword ptr [ecx + 0x20], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 00479975  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047997c  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00479983  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479985  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00479988  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047998b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047998e  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479991  a150824c00             -mov eax, dword ptr [0x4c8250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 00479996  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479998  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047999b  8d4370                 -lea eax, [ebx + 0x70]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0047999e  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004799a1  e8ea610000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 004799a6  8b1540b75100           -mov edx, dword ptr [0x51b740]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 004799ac  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004799ae  b844b75100             -mov eax, 0x51b744
    cpu.eax = 5355332 /*0x51b744*/;
    // 004799b3  e828550000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 004799b8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004799bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004799be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4799c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004799c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004799c5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004799c7  e864ffffff             -call 0x479930
    cpu.esp -= 4;
    sub_479930(app, cpu);
    if (cpu.terminate) return;
    // 004799cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4799d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004799d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004799d1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004799d3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004799d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004799d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004799d9  e852ffffff             -call 0x479930
    cpu.esp -= 4;
    sub_479930(app, cpu);
    if (cpu.terminate) return;
    // 004799de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4799e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004799e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004799e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004799e2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004799e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004799e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004799e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004799ea  e841ffffff             -call 0x479930
    cpu.esp -= 4;
    sub_479930(app, cpu);
    if (cpu.terminate) return;
    // 004799ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004799f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4799f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004799f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004799f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004799f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004799f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004799f8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004799fa  ba60934700             -mov edx, 0x479360
    cpu.edx = 4690784 /*0x479360*/;
    // 004799ff  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479a04  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479a06  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479a09  e812650000             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 00479a0e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479a10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479a12  7438                   -je 0x479a4c
    if (cpu.flags.zf)
    {
        goto L_0x00479a4c;
    }
    // 00479a14  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479a15  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00479a18  83fe01                 +cmp esi, 1
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
    // 00479a1b  7528                   -jne 0x479a45
    if (!cpu.flags.zf)
    {
        goto L_0x00479a45;
    }
L_0x00479a1d:
    // 00479a1d  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00479a20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00479a22  740e                   -je 0x479a32
    if (cpu.flags.zf)
    {
        goto L_0x00479a32;
    }
    // 00479a24  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00479a26  e8a1f0ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00479a2b  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00479a32:
    // 00479a32  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479a37  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479a3a  e851610000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479a3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479a40:
    // 00479a40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479a44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479a45:
    // 00479a45  83fe02                 +cmp esi, 2
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
    // 00479a48  74d3                   -je 0x479a1d
    if (cpu.flags.zf)
    {
        goto L_0x00479a1d;
    }
    // 00479a4a  ebe6                   -jmp 0x479a32
    goto L_0x00479a32;
L_0x00479a4c:
    // 00479a4c  e81ff9ffff             -call 0x479370
    cpu.esp -= 4;
    sub_479370(app, cpu);
    if (cpu.terminate) return;
    // 00479a51  ba60934700             -mov edx, 0x479360
    cpu.edx = 4690784 /*0x479360*/;
    // 00479a56  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479a5b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479a5d  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00479a60  e8bb640000             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 00479a65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479a67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479a69  7516                   -jne 0x479a81
    if (!cpu.flags.zf)
    {
        goto L_0x00479a81;
    }
    // 00479a6b  ba60934700             -mov edx, 0x479360
    cpu.edx = 4690784 /*0x479360*/;
    // 00479a70  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479a75  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479a77  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00479a7a  e8a1640000             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 00479a7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00479a81:
    // 00479a81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479a83  74bb                   -je 0x479a40
    if (cpu.flags.zf)
    {
        goto L_0x00479a40;
    }
    // 00479a85  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00479a88  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479a8a  7411                   -je 0x479a9d
    if (cpu.flags.zf)
    {
        goto L_0x00479a9d;
    }
    // 00479a8c  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479a91  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479a94  7407                   -je 0x479a9d
    if (cpu.flags.zf)
    {
        goto L_0x00479a9d;
    }
    // 00479a96  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479a98  e85bf0ffff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
L_0x00479a9d:
    // 00479a9d  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479aa2  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479aa5  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479aac  e8df600000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479ab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ab2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ab3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ab4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479ab5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479ab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479ab8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479ab9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479abb  8b0d40b75100           -mov ecx, dword ptr [0x51b740]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479ac1  ba60934700             -mov edx, 0x479360
    cpu.edx = 4690784 /*0x479360*/;
    // 00479ac6  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00479ac9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479acb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479acd  e84e640000             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 00479ad2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479ad4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479ad6  7506                   -jne 0x479ade
    if (!cpu.flags.zf)
    {
        goto L_0x00479ade;
    }
L_0x00479ad8:
    // 00479ad8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479ada  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479adb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479adc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479add  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479ade:
    // 00479ade  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479ae3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479ae5  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479ae8  e8a3600000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479aed  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479af1  74e5                   -je 0x479ad8
    if (cpu.flags.zf)
    {
        goto L_0x00479ad8;
    }
    // 00479af3  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00479af6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479af7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479af8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479af9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479afc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479afc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479afd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479afe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479aff  8b0d40b75100           -mov ecx, dword ptr [0x51b740]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479b05  ba60934700             -mov edx, 0x479360
    cpu.edx = 4690784 /*0x479360*/;
    // 00479b0a  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00479b0d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479b0f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479b11  e80a640000             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 00479b16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479b18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479b1a  7504                   -jne 0x479b20
    if (!cpu.flags.zf)
    {
        goto L_0x00479b20;
    }
    // 00479b1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479b20:
    // 00479b20  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479b25  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00479b27  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00479b2a  e861600000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479b2f  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479b33  7409                   -je 0x479b3e
    if (cpu.flags.zf)
    {
        goto L_0x00479b3e;
    }
    // 00479b35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479b3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479b3e:
    // 00479b3e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00479b43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479b46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00479b58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479b59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479b5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479b5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479b5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479b5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479b5e  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00479b64  e863530000             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00479b69  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479b6b  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479b70  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00479b72  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479b79  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x00479b80:
    // 00479b80  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479b85  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00479b89  743d                   -je 0x479bc8
    if (cpu.flags.zf)
    {
        goto L_0x00479bc8;
    }
    // 00479b8b  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479b8e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479b90  0f85b0030000           -jne 0x479f46
    if (!cpu.flags.zf)
    {
        goto L_0x00479f46;
    }
L_0x00479b96:
    // 00479b96  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479b9b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00479ba2  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479ba9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479bab  e8f8530000             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00479bb0  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479bb5  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00479bbb  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00479bc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479bc7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479bc8:
    // 00479bc8  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479bcb  e880600000             -call 0x47fc50
    cpu.esp -= 4;
    sub_47fc50(app, cpu);
    if (cpu.terminate) return;
    // 00479bd0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00479bd2  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00479bd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479bdb  0f8454030000           -je 0x479f35
    if (cpu.flags.zf)
    {
        goto L_0x00479f35;
    }
    // 00479be1  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479be6  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00479be9  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00479bec  4a                     -dec edx
    (cpu.edx)--;
    // 00479bed  83fa03                 +cmp edx, 3
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
    // 00479bf0  760e                   -jbe 0x479c00
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00479c00;
    }
    // 00479bf2  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479bf7  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479bfe  eb80                   -jmp 0x479b80
    goto L_0x00479b80;
L_0x00479c00:
    // 00479c00  ff2495489b4700         -jmp dword ptr [edx*4 + 0x479b48]
    cpu.ip = app->getMemory<x86::reg32>(4692808 + cpu.edx * 4); goto dynamic_jump;
  case 0x00479c07:
    // 00479c07  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00479c09  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00479c0c  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479c13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00479c14:
    // 00479c14  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479c16  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00479c18  3c00                   +cmp al, 0
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
    // 00479c1a  7410                   -je 0x479c2c
    if (cpu.flags.zf)
    {
        goto L_0x00479c2c;
    }
    // 00479c1c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00479c1f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479c22  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00479c25  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479c28  3c00                   +cmp al, 0
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
    // 00479c2a  75e8                   -jne 0x479c14
    if (!cpu.flags.zf)
    {
        goto L_0x00479c14;
    }
L_0x00479c2c:
    // 00479c2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479c2d  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00479c30  8d4d10                 -lea ecx, [ebp + 0x10]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479c33  e894eeffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00479c38  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479c3b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479c3d  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00479c44  e8cb180000             -call 0x47b514
    cpu.esp -= 4;
    sub_47b514(app, cpu);
    if (cpu.terminate) return;
    // 00479c49  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479c50  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479c57  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00479c59  0f8435010000           -je 0x479d94
    if (cpu.flags.zf)
    {
        goto L_0x00479d94;
    }
    // 00479c5f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479c62  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479c64  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 00479c69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479c6c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00479c6e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479c71  8d8890010000           -lea ecx, [eax + 0x190]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 00479c77  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479c79  0f8505010000           -jne 0x479d84
    if (!cpu.flags.zf)
    {
        goto L_0x00479d84;
    }
    // 00479c7f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479c81  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00479c84  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479c87  e8c0e9ffff             -call 0x47864c
    cpu.esp -= 4;
    sub_47864c(app, cpu);
    if (cpu.terminate) return;
    // 00479c8c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00479c8f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479c91  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00479c94:
    // 00479c94  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479c96  e85da90100             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 00479c9b  e82caa0100             -call 0x4946cc
    cpu.esp -= 4;
    sub_4946cc(app, cpu);
    if (cpu.terminate) return;
    // 00479ca0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479ca7  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479cae  e83dcbfcff             -call 0x4467f0
    cpu.esp -= 4;
    sub_4467f0(app, cpu);
    if (cpu.terminate) return;
    // 00479cb3  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479cba  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00479cbd  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479cc4  e8ff190000             -call 0x47b6c8
    cpu.esp -= 4;
    sub_47b6c8(app, cpu);
    if (cpu.terminate) return;
    // 00479cc9  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479cd0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479cd7  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00479cda  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00479cdd  e8d6190000             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00479ce2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479ce4  750e                   -jne 0x479cf4
    if (!cpu.flags.zf)
    {
        goto L_0x00479cf4;
    }
    // 00479ce6  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479ced  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x00479cf4:
    // 00479cf4  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479cfb  e8b0cafcff             -call 0x4467b0
    cpu.esp -= 4;
    sub_4467b0(app, cpu);
    if (cpu.terminate) return;
    // 00479d00  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00479d07  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479d09  e8a2190000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00479d0e  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d15  89b42400010000         -mov dword ptr [esp + 0x100], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.esi;
    // 00479d1c  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d20  7530                   -jne 0x479d52
    if (!cpu.flags.zf)
    {
        goto L_0x00479d52;
    }
    // 00479d22  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d29  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479d2e  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00479d31  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d34  741c                   -je 0x479d52
    if (cpu.flags.zf)
    {
        goto L_0x00479d52;
    }
    // 00479d36  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d3d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00479d40  e8b3edffff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
    // 00479d45  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d4c  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00479d4f  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00479d52:
    // 00479d52  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d59  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d5d  743a                   -je 0x479d99
    if (cpu.flags.zf)
    {
        goto L_0x00479d99;
    }
    // 00479d5f  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479d64  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479d6b  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479d6e  e81d5e0000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479d73  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479d78  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479d7f  e9fcfdffff             -jmp 0x479b80
    goto L_0x00479b80;
L_0x00479d84:
    // 00479d84  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479d89  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00479d8c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00479d8f  e900ffffff             -jmp 0x479c94
    goto L_0x00479c94;
L_0x00479d94:
    // 00479d94  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00479d97  ebb9                   -jmp 0x479d52
    goto L_0x00479d52;
L_0x00479d99:
    // 00479d99  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479d9e  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479da5  83c038                 +add eax, 0x38
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
    // 00479da8  e8e35d0000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479dad  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479db2  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479db9  e9c2fdffff             -jmp 0x479b80
    goto L_0x00479b80;
  case 0x00479dbe:
    // 00479dbe  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479dc1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00479dc3  7407                   -je 0x479dcc
    if (cpu.flags.zf)
    {
        goto L_0x00479dcc;
    }
    // 00479dc5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00479dc7  e8e4180000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
L_0x00479dcc:
    // 00479dcc  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479dd1  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00479dd8  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479ddf  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 00479de3  7449                   -je 0x479e2e
    if (cpu.flags.zf)
    {
        goto L_0x00479e2e;
    }
    // 00479de5  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 00479dea  e809a80100             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 00479def  e8d8a80100             -call 0x4946cc
    cpu.esp -= 4;
    sub_4946cc(app, cpu);
    if (cpu.terminate) return;
    // 00479df4  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479df9  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00479dfc  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00479dff  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479e02  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479e09  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00479e0c  e80b170000             -call 0x47b51c
    cpu.esp -= 4;
    sub_47b51c(app, cpu);
    if (cpu.terminate) return;
    // 00479e11  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479e18  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00479e1b  e8acecffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00479e20  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479e27  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00479e2e:
    // 00479e2e  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479e33  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479e3a  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479e3d  e84e5d0000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479e42  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479e47  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479e4e  e92dfdffff             -jmp 0x479b80
    goto L_0x00479b80;
  case 0x00479e53:
    // 00479e53  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479e56  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479e58  0f8498000000           -je 0x479ef6
    if (cpu.flags.zf)
    {
        goto L_0x00479ef6;
    }
    // 00479e5e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479e61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479e63  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 00479e68  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479e6b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00479e6d  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 00479e72  e881a70100             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 00479e77  e850a80100             -call 0x4946cc
    cpu.esp -= 4;
    sub_4946cc(app, cpu);
    if (cpu.terminate) return;
    // 00479e7c  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479e81  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479e84  e867c9fcff             -call 0x4467f0
    cpu.esp -= 4;
    sub_4467f0(app, cpu);
    if (cpu.terminate) return;
    // 00479e89  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479e8e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00479e91  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479e94  e82f180000             -call 0x47b6c8
    cpu.esp -= 4;
    sub_47b6c8(app, cpu);
    if (cpu.terminate) return;
    // 00479e99  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479e9e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00479ea1  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00479ea4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479ea7  e80c180000             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00479eac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479eae  7503                   -jne 0x479eb3
    if (!cpu.flags.zf)
    {
        goto L_0x00479eb3;
    }
    // 00479eb0  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00479eb3:
    // 00479eb3  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479eb8  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479ebb  e8f0c8fcff             -call 0x4467b0
    cpu.esp -= 4;
    sub_4467b0(app, cpu);
    if (cpu.terminate) return;
L_0x00479ec0:
    // 00479ec0  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479ec7  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479ecb  0f84c8feffff           -je 0x479d99
    if (cpu.flags.zf)
    {
        goto L_0x00479d99;
    }
    // 00479ed1  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479ed6  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479edd  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479ee0  e8ab5c0000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479ee5  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479eea  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479ef1  e98afcffff             -jmp 0x479b80
    goto L_0x00479b80;
L_0x00479ef6:
    // 00479ef6  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00479ef9  ebc5                   -jmp 0x479ec0
    goto L_0x00479ec0;
  case 0x00479efb:
    // 00479efb  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00479efe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479f00  7407                   -je 0x479f09
    if (cpu.flags.zf)
    {
        goto L_0x00479f09;
    }
    // 00479f02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479f04  e8a7170000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
L_0x00479f09:
    // 00479f09  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479f0e  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479f11  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00479f18  c740ec00000000         -mov dword ptr [eax - 0x14], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00479f1f  e86c5c0000             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 00479f24  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479f29  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00479f30  e94bfcffff             -jmp 0x479b80
    goto L_0x00479b80;
L_0x00479f35:
    // 00479f35  a140b75100             -mov eax, dword ptr [0x51b740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355328) /* 0x51b740 */);
    // 00479f3a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479f3c  e8db4f0000             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00479f41  e93afcffff             -jmp 0x479b80
    goto L_0x00479b80;
L_0x00479f46:
    // 00479f46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479f48  e863170000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00479f4d  e944fcffff             -jmp 0x479b96
    goto L_0x00479b96;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479f60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479f63  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479f6a  7507                   -jne 0x479f73
    if (!cpu.flags.zf)
    {
        goto L_0x00479f73;
    }
    // 00479f6c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00479f71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f73:
    // 00479f73  e878a90100             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00479f78  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479f7a  e87dad0100             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 00479f7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479f81  7c0b                   -jl 0x479f8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479f8e;
    }
    // 00479f83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479f85  e87aa90100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00479f8a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479f8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479f8e:
    // 00479f8e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00479f93  e86ca90100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00479f98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479f9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479f9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_479fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479fa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479fa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479fa3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479fa5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00479fa7  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479fae  7415                   -je 0x479fc5
    if (cpu.flags.zf)
    {
        goto L_0x00479fc5;
    }
    // 00479fb0  83fb7f                 +cmp ebx, 0x7f
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
    // 00479fb3  7f05                   -jg 0x479fba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00479fba;
    }
    // 00479fb5  83fbff                 +cmp ebx, -1
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
    // 00479fb8  7d12                   -jge 0x479fcc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00479fcc;
    }
L_0x00479fba:
    // 00479fba  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x00479fbf:
    // 00479fbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479fc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479fc2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479fc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479fc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479fc5:
    // 00479fc5  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00479fca  ebf3                   -jmp 0x479fbf
    goto L_0x00479fbf;
L_0x00479fcc:
    // 00479fcc  e81fa90100             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00479fd1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479fd3  e824ad0100             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 00479fd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479fda  0f8c6d000000           -jl 0x47a04d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a04d;
    }
    // 00479fe0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00479fe7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479fe9  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 00479fee  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00479ff1  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479ff3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479ff5  7e66                   -jle 0x47a05d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a05d;
    }
L_0x00479ff7:
    // 00479ff7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479ff8  0fb6793b               -movzx edi, byte ptr [ecx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */));
    // 00479ffc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00479ffe  7464                   -je 0x47a064
    if (cpu.flags.zf)
    {
        goto L_0x0047a064;
    }
    // 0047a000  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 0047a005  8da900060000           -lea ebp, [ecx + 0x600]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
L_0x0047a00b:
    // 0047a00b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a00d  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0047a010  39fa                   +cmp edx, edi
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
    // 0047a012  7524                   -jne 0x47a038
    if (!cpu.flags.zf)
    {
        goto L_0x0047a038;
    }
    // 0047a014  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0047a018  751e                   -jne 0x47a038
    if (!cpu.flags.zf)
    {
        goto L_0x0047a038;
    }
    // 0047a01a  833900                 +cmp dword ptr [ecx], 0
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
    // 0047a01d  7c19                   -jl 0x47a038
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a038;
    }
    // 0047a01f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a021  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047a024  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047a027  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a029  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047a02c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a02e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a030  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047a033  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a035  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0047a038:
    // 0047a038  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047a03b  39e9                   +cmp ecx, ebp
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
    // 0047a03d  75cc                   -jne 0x47a00b
    if (!cpu.flags.zf)
    {
        goto L_0x0047a00b;
    }
    // 0047a03f  e8c0a80100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047a044  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047a046  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a047  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a04a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a04b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a04c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a04d:
    // 0047a04d  e8b2a80100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047a052  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0047a057  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a05a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a05b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a05c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a05d:
    // 0047a05d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047a062  eb93                   -jmp 0x479ff7
    goto L_0x00479ff7;
L_0x0047a064:
    // 0047a064  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0047a067  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047a06a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047a06c  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047a06f  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a071  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a073  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047a076  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047a078  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047a07b  e884a80100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047a080  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a082  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a083  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a085  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a086  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a087  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47a090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a090  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a091  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a092  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a093  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a094  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a095  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a096  81ec1c0c0000           -sub esp, 0xc1c
    (cpu.esp) -= x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0047a09c  898424100c0000         -mov dword ptr [esp + 0xc10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */) = cpu.eax;
    // 0047a0a3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047a0a8  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0047a0ad  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0047a0b2  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0047a0b7  899424140c0000         -mov dword ptr [esp + 0xc14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.edx;
    // 0047a0be  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047a0c0  898c24080c0000         -mov dword ptr [esp + 0xc08], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = cpu.ecx;
    // 0047a0c7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047a0c9:
    // 0047a0c9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047a0cc  89740cf4               -mov dword ptr [esp + ecx - 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.esi;
    // 0047a0d0  81f9000c0000           +cmp ecx, 0xc00
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
    // 0047a0d6  75f1                   -jne 0x47a0c9
    if (!cpu.flags.zf)
    {
        goto L_0x0047a0c9;
    }
    // 0047a0d8  8bb424100c0000         -mov esi, dword ptr [esp + 0xc10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047a0df  8b34f5008a5200         -mov esi, dword ptr [esi*8 + 0x528a00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.esi * 8);
    // 0047a0e6  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a0ea  7206                   -jb 0x47a0f2
    if (cpu.flags.cf)
    {
        goto L_0x0047a0f2;
    }
    // 0047a0ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a0ee  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x0047a0f2:
    // 0047a0f2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047a0f4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047a0f6  89bc24180c0000         -mov dword ptr [esp + 0xc18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.edi;
    // 0047a0fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a0ff  0f8ea6000000           -jle 0x47a1ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a1ab;
    }
    // 0047a105  8b9424100c0000         -mov edx, dword ptr [esp + 0xc10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047a10c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047a10f  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047a112  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a114  899424000c0000         -mov dword ptr [esp + 0xc00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.edx;
    // 0047a11b  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047a11e  8984240c0c0000         -mov dword ptr [esp + 0xc0c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */) = cpu.eax;
    // 0047a125  899424040c0000         -mov dword ptr [esp + 0xc04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.edx;
    // 0047a12c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0047a12e:
    // 0047a12e  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a132  0f82b8000000           -jb 0x47a1f0
    if (cpu.flags.cf)
    {
        goto L_0x0047a1f0;
    }
    // 0047a138  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047a13a  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
L_0x0047a13d:
    // 0047a13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a13f  744a                   -je 0x47a18b
    if (cpu.flags.zf)
    {
        goto L_0x0047a18b;
    }
    // 0047a141  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a145  0f82ad000000           -jb 0x47a1f8
    if (cpu.flags.cf)
    {
        goto L_0x0047a1f8;
    }
    // 0047a14b  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0047a14e  8d550c                 -lea edx, [ebp + 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047a151  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047a154  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a156  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a158  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0047a15b:
    // 0047a15b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a15d  8b9424000c0000         -mov edx, dword ptr [esp + 0xc00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 0047a164  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047a166  8b92048a5200           -mov edx, dword ptr [edx + 0x528a04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5409284) /* 0x528a04 */);
    // 0047a16c  e83fa00100             -call 0x4941b0
    cpu.esp -= 4;
    sub_4941b0(app, cpu);
    if (cpu.terminate) return;
    // 0047a171  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047a173  83f807                 +cmp eax, 7
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
    // 0047a176  740b                   -je 0x47a183
    if (cpu.flags.zf)
    {
        goto L_0x0047a183;
    }
    // 0047a178  c78424080c000008000000 -mov dword ptr [esp + 0xc08], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = 8 /*0x8*/;
L_0x0047a183:
    // 0047a183  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a185  0f8c86000000           -jl 0x47a211
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a211;
    }
L_0x0047a18b:
    // 0047a18b  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 0047a192  8b94240c0c0000         -mov edx, dword ptr [esp + 0xc0c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */);
    // 0047a199  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a19c  40                     -inc eax
    (cpu.eax)++;
    // 0047a19d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a1a0  898424180c0000         -mov dword ptr [esp + 0xc18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.eax;
    // 0047a1a7  39d1                   +cmp ecx, edx
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
    // 0047a1a9  7c83                   -jl 0x47a12e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a12e;
    }
L_0x0047a1ab:
    // 0047a1ab  8b9424140c0000         -mov edx, dword ptr [esp + 0xc14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
    // 0047a1b2  83faff                 +cmp edx, -1
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
    // 0047a1b5  7e21                   -jle 0x47a1d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a1d8;
    }
    // 0047a1b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a1b9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a1bb  7c1b                   -jl 0x47a1d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a1d8;
    }
    // 0047a1bd  8bbc24140c0000         -mov edi, dword ptr [esp + 0xc14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
L_0x0047a1c4:
    // 0047a1c4  8b8424100c0000         -mov eax, dword ptr [esp + 0xc10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047a1cb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047a1cd  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a1ce  e88d9e0100             -call 0x494060
    cpu.esp -= 4;
    sub_494060(app, cpu);
    if (cpu.terminate) return;
    // 0047a1d3  39f9                   +cmp ecx, edi
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
    // 0047a1d5  7eed                   -jle 0x47a1c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a1c4;
    }
    // 0047a1d7  90                     -nop 
    ;
L_0x0047a1d8:
    // 0047a1d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a1da  7c46                   -jl 0x47a222
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a222;
    }
    // 0047a1dc  8b8424080c0000         -mov eax, dword ptr [esp + 0xc08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */);
    // 0047a1e3  81c41c0c0000           +add esp, 0xc1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3100 /*0xc1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a1e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a1f0:
    // 0047a1f0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047a1f3  e945ffffff             -jmp 0x47a13d
    goto L_0x0047a13d;
L_0x0047a1f8:
    // 0047a1f8  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0047a1fb  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 0047a202  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047a205  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a207  01da                   +add edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a209  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047a20c  e94affffff             -jmp 0x47a15b
    goto L_0x0047a15b;
L_0x0047a211:
    // 0047a211  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 0047a218  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047a219  898424140c0000         -mov dword ptr [esp + 0xc14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.eax;
    // 0047a220  eb89                   -jmp 0x47a1ab
    goto L_0x0047a1ab;
L_0x0047a222:
    // 0047a222  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a224  81c41c0c0000           -add esp, 0xc1c
    (cpu.esp) += x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0047a22a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a22b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a22c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a22d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a22e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a22f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a230  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a234  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a236  7c0f                   -jl 0x47a247
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a247;
    }
    // 0047a238  83f80a                 +cmp eax, 0xa
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
    // 0047a23b  7d0a                   -jge 0x47a247
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a247;
    }
    // 0047a23d  833cc5008a520000       +cmp dword ptr [eax*8 + 0x528a00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a245  7506                   -jne 0x47a24d
    if (!cpu.flags.zf)
    {
        goto L_0x0047a24d;
    }
L_0x0047a247:
    // 0047a247  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047a24c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a24d:
    // 0047a24d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a24f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a253  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a254  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 0047a25a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a25c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047a25e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047a263  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047a265:
    // 0047a265  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047a268  89540cf4               -mov dword ptr [esp + ecx - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.edx;
    // 0047a26c  81f9000c0000           +cmp ecx, 0xc00
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
    // 0047a272  75f1                   -jne 0x47a265
    if (!cpu.flags.zf)
    {
        goto L_0x0047a265;
    }
    // 0047a274  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a276  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047a278  7e12                   -jle 0x47a28c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a28c;
    }
L_0x0047a27a:
    // 0047a27a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047a27c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047a27e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a280  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a281  e8ca9b0100             -call 0x493e50
    cpu.esp -= 4;
    sub_493e50(app, cpu);
    if (cpu.terminate) return;
    // 0047a286  39f9                   +cmp ecx, edi
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
    // 0047a288  7cf0                   -jl 0x47a27a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a27a;
    }
    // 0047a28a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047a28c:
    // 0047a28c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a28e  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 0047a294  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a295  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a296  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a297  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a298  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a29c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a29c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a29d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a29e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a29f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a2a0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a2a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a2a4  8a156cab4c00           -mov dl, byte ptr [0x4cab6c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 0047a2aa  bff7ffffff             -mov edi, 0xfffffff7
    cpu.edi = 4294967287 /*0xfffffff7*/;
    // 0047a2af  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047a2b1  7449                   -je 0x47a2fc
    if (cpu.flags.zf)
    {
        goto L_0x0047a2fc;
    }
    // 0047a2b3  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a2b9  754b                   -jne 0x47a306
    if (!cpu.flags.zf)
    {
        goto L_0x0047a306;
    }
    // 0047a2bb  ba008a5200             -mov edx, 0x528a00
    cpu.edx = 5409280 /*0x528a00*/;
    // 0047a2c0  8b2d008a5200           -mov ebp, dword ptr [0x528a00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */);
    // 0047a2c6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a2c8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047a2ca  740e                   -je 0x47a2da
    if (cpu.flags.zf)
    {
        goto L_0x0047a2da;
    }
L_0x0047a2cc:
    // 0047a2cc  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a2cd  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047a2d0  83f90a                 +cmp ecx, 0xa
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
    // 0047a2d3  7d46                   -jge 0x47a31b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a31b;
    }
    // 0047a2d5  833a00                 +cmp dword ptr [edx], 0
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
    // 0047a2d8  75f2                   -jne 0x47a2cc
    if (!cpu.flags.zf)
    {
        goto L_0x0047a2cc;
    }
L_0x0047a2da:
    // 0047a2da  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0047a2dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a2de  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047a2e1  e8aafdffff             -call 0x47a090
    cpu.esp -= 4;
    sub_47a090(app, cpu);
    if (cpu.terminate) return;
    // 0047a2e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a2e8  7c26                   -jl 0x47a310
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a310;
    }
    // 0047a2ea  ba24a34700             -mov edx, 0x47a324
    cpu.edx = 4694820 /*0x47a324*/;
    // 0047a2ef  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047a2f1  891584ab4c00           -mov dword ptr [0x4cab84], edx
    app->getMemory<x86::reg32>(x86::reg32(5024644) /* 0x4cab84 */) = cpu.edx;
    // 0047a2f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a2f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a2f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a2fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a2fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a2fc:
    // 0047a2fc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047a301  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a302  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a303  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a304  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a305  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a306:
    // 0047a306  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047a30b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a30c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a30d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a30e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a30f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a310:
    // 0047a310  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047a316  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a317  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a318  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a319  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a31a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a31b:
    // 0047a31b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a31d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a31f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a320  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a321  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a324  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a325  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a326  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a327  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a329  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 0047a32f  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 0047a334  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047a336  741a                   -je 0x47a352
    if (cpu.flags.zf)
    {
        goto L_0x0047a352;
    }
    // 0047a338  83f9ff                 +cmp ecx, -1
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
    // 0047a33b  751e                   -jne 0x47a35b
    if (!cpu.flags.zf)
    {
        goto L_0x0047a35b;
    }
    // 0047a33d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047a33f:
    // 0047a33f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a341  42                     -inc edx
    (cpu.edx)++;
    // 0047a342  e8ddffffff             -call 0x47a324
    cpu.esp -= 4;
    sub_47a324(app, cpu);
    if (cpu.terminate) return;
    // 0047a347  83fa0a                 +cmp edx, 0xa
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
    // 0047a34a  7cf3                   -jl 0x47a33f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a33f;
    }
    // 0047a34c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a34e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a34f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a350  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a351  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a352:
    // 0047a352  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047a357  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a358  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a359  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a35a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a35b:
    // 0047a35b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a35d  e8d2feffff             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 0047a362  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a364  7550                   -jne 0x47a3b6
    if (!cpu.flags.zf)
    {
        goto L_0x0047a3b6;
    }
    // 0047a366  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a367  ba00845200             -mov edx, 0x528400
    cpu.edx = 5407744 /*0x528400*/;
    // 0047a36c  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x0047a372:
    // 0047a372  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0047a375  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047a378  39c8                   +cmp eax, ecx
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
    // 0047a37a  7507                   -jne 0x47a383
    if (!cpu.flags.zf)
    {
        goto L_0x0047a383;
    }
    // 0047a37c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047a37e  e87d450000             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
L_0x0047a383:
    // 0047a383  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047a386  39da                   +cmp edx, ebx
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
    // 0047a388  75e8                   -jne 0x47a372
    if (!cpu.flags.zf)
    {
        goto L_0x0047a372;
    }
    // 0047a38a  8b04cd008a5200         -mov eax, dword ptr [ecx*8 + 0x528a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.ecx * 8);
    // 0047a391  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a395  7206                   -jb 0x47a39d
    if (cpu.flags.cf)
    {
        goto L_0x0047a39d;
    }
    // 0047a397  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047a399  668b7006               -mov si, word ptr [eax + 6]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x0047a39d:
    // 0047a39d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047a39f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a3a1  e8aafeffff             -call 0x47a250
    cpu.esp -= 4;
    sub_47a250(app, cpu);
    if (cpu.terminate) return;
    // 0047a3a6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a3a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a3aa  8914cd008a5200         -mov dword ptr [ecx*8 + 0x528a00], edx
    app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.ecx * 8) = cpu.edx;
    // 0047a3b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a3b6:
    // 0047a3b6  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047a3bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47a3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a3c0  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047a3c7  740f                   -je 0x47a3d8
    if (cpu.flags.zf)
    {
        goto L_0x0047a3d8;
    }
    // 0047a3c9  83fa7f                 +cmp edx, 0x7f
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
    // 0047a3cc  7f04                   -jg 0x47a3d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047a3d2;
    }
    // 0047a3ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a3d0  7d0c                   -jge 0x47a3de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a3de;
    }
L_0x0047a3d2:
    // 0047a3d2  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047a3d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a3d8:
    // 0047a3d8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047a3dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a3de:
    // 0047a3de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a3df  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a3e0  8815b6a04c00           -mov byte ptr [0x4ca0b6], dl
    app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */) = cpu.dl;
    // 0047a3e6  8b0d44a04c00           -mov ecx, dword ptr [0x4ca044]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 0047a3ec  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047a3ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a3f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a3f2  e8a9fbffff             -call 0x479fa0
    cpu.esp -= 4;
    sub_479fa0(app, cpu);
    if (cpu.terminate) return;
    // 0047a3f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a3f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a3fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a3fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a3fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a3fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a400  eb0b                   -jmp 0x47a40d
    goto L_0x0047a40d;
L_0x0047a402:
    // 0047a402  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047a404  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047a406  7409                   -je 0x47a411
    if (cpu.flags.zf)
    {
        goto L_0x0047a411;
    }
    // 0047a408  42                     -inc edx
    (cpu.edx)++;
    // 0047a409  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047a40a  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0047a40c  40                     -inc eax
    (cpu.eax)++;
L_0x0047a40d:
    // 0047a40d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a40f  75f1                   -jne 0x47a402
    if (!cpu.flags.zf)
    {
        goto L_0x0047a402;
    }
L_0x0047a411:
    // 0047a411  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a413  7407                   -je 0x47a41c
    if (cpu.flags.zf)
    {
        goto L_0x0047a41c;
    }
    // 0047a415  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047a416  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0047a419  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047a41a  ebf5                   -jmp 0x47a411
    goto L_0x0047a411;
L_0x0047a41c:
    // 0047a41c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a41e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a41f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a420  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a421(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a421  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a423  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a426  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047a42a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047a42c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a430  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047a433  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a437  e8da910100             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 0047a43c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a43f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a440  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a441  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a442(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a442  83f861                 +cmp eax, 0x61
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
    // 0047a445  7c08                   -jl 0x47a44f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a44f;
    }
    // 0047a447  83f87a                 +cmp eax, 0x7a
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
    // 0047a44a  7f03                   -jg 0x47a44f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047a44f;
    }
    // 0047a44c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0047a44f:
    // 0047a44f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a450  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a451  9b                     -wait 
    /*nothing*/;
    // 0047a452  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 0047a455  9b                     -wait 
    /*nothing*/;
    // 0047a456  ff3424                 -push dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 0047a459  c64424011f             -mov byte ptr [esp + 1], 0x1f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 0047a45e  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 0047a461  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 0047a463  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a467  9b                     -wait 
    /*nothing*/;
    // 0047a468  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047a46c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_47a470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a470  0fb68084854c00         -movzx eax, byte ptr [eax + 0x4c8584]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014916) /* 0x4c8584 */));
    // 0047a477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47a480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a482  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a483  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047a486  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a488  8b1df4a74c00           -mov ebx, dword ptr [0x4ca7f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */);
    // 0047a48e  890d78a84c00           -mov dword ptr [0x4ca878], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023864) /* 0x4ca878 */) = cpu.ecx;
    // 0047a494  39d8                   +cmp eax, ebx
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
    // 0047a496  750c                   -jne 0x47a4a4
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4a4;
    }
    // 0047a498  3b15f8a74c00           +cmp edx, dword ptr [0x4ca7f8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023736) /* 0x4ca7f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a49e  0f8439010000           -je 0x47a5dd
    if (cpu.flags.zf)
    {
        goto L_0x0047a5dd;
    }
L_0x0047a4a4:
    // 0047a4a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a4a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a4a6  a3f4a74c00             -mov dword ptr [0x4ca7f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */) = cpu.eax;
    // 0047a4ab  8915f8a74c00           -mov dword ptr [0x4ca7f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5023736) /* 0x4ca7f8 */) = cpu.edx;
    // 0047a4b1  e82a770100             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 0047a4b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a4b8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0047a4bb  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a4c1  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0047a4c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a4c7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a4cc  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047a4d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a4d2  e809770100             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 0047a4d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a4d9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047a4db  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047a4de  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0047a4e2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a4e8  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 0047a4ec  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0047a4f0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a4f2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a4f7  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0047a4fa  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0047a4fe  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047a502  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a508  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 0047a50f  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0047a513  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a515  8d2c9500000000         -lea ebp, [edx*4]
    cpu.ebp = x86::reg32(cpu.edx * 4);
    // 0047a51c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a51e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047a521  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a523  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a525  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a527  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047a52a  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0047a52d  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a52f  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047a533  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047a539  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0047a540  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047a544  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a546  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a548  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a54a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047a54d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a54f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a551:
    // 0047a551  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0047a554  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047a557  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047a55b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047a55f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047a561  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047a564  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047a568  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047a56c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a56e  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047a571  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a575  037c2424               -add edi, dword ptr [esp + 0x24]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0047a579  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047a57d  01442438               -add dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a581  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047a585  01442434               -add dword ptr [esp + 0x34], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a589  2b74242c               -sub esi, dword ptr [esp + 0x2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0047a58d  2b6c2428               -sub ebp, dword ptr [esp + 0x28]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0047a591  2b5c2430               -sub ebx, dword ptr [esp + 0x30]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0047a595  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047a599  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047a59c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a59e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a5a2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a5a6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047a5a9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047a5ad  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a5b1  0b442418               -or eax, dword ptr [esp + 0x18]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0047a5b5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a5b8  0b442410               -or eax, dword ptr [esp + 0x10]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0047a5bc  81c100000010           -add ecx, 0x10000000
    (cpu.ecx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 0047a5c2  e895bfffff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0047a5c7  8982f8a74c00           -mov dword ptr [edx + 0x4ca7f8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5023736) /* 0x4ca7f8 */) = cpu.eax;
    // 0047a5cd  83fa40                 +cmp edx, 0x40
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
    // 0047a5d0  0f857bffffff           -jne 0x47a551
    if (!cpu.flags.zf)
    {
        goto L_0x0047a551;
    }
    // 0047a5d6  e809b30100             -call 0x4958e4
    cpu.esp -= 4;
    sub_4958e4(app, cpu);
    if (cpu.terminate) return;
    // 0047a5db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a5dd:
    // 0047a5dd  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047a5e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47a5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a5f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a5f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a5f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a5f3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047a5f5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047a5f7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047a5f9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047a5fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a5fd  7436                   -je 0x47a635
    if (cpu.flags.zf)
    {
        goto L_0x0047a635;
    }
L_0x0047a5ff:
    // 0047a5ff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a601  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047a603  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0047a606  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0047a609  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047a60e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a610  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047a614  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047a616  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047a61d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047a61f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047a621  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a623  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a625  7414                   -je 0x47a63b
    if (cpu.flags.zf)
    {
        goto L_0x0047a63b;
    }
    // 0047a627  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047a629  7e04                   -jle 0x47a62f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a62f;
    }
    // 0047a62b  4a                     -dec edx
    (cpu.edx)--;
    // 0047a62c  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x0047a62f:
    // 0047a62f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047a631  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a633  75ca                   -jne 0x47a5ff
    if (!cpu.flags.zf)
    {
        goto L_0x0047a5ff;
    }
L_0x0047a635:
    // 0047a635  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a637  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a638  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a639  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a63a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a63b:
    // 0047a63b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a63d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a63e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a63f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a644(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a644  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a645  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a646  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a647  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a648  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a64a  8d48e0                 -lea ecx, [eax - 0x20]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
    // 0047a64d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047a654  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a656  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047a659  8b154ca84c00           -mov edx, dword ptr [0x4ca84c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023820) /* 0x4ca84c */);
    // 0047a65f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a661  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0047a664  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047a669  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a66b  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047a66f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047a671  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047a678  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047a67a  39f0                   +cmp eax, esi
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
    // 0047a67c  7507                   -jne 0x47a685
    if (!cpu.flags.zf)
    {
        goto L_0x0047a685;
    }
    // 0047a67e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a680  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a681  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a682  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a683  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a684  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a685:
    // 0047a685  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0047a68a  8b1d3ca84c00           -mov ebx, dword ptr [0x4ca83c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023804) /* 0x4ca83c */);
    // 0047a690  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a692  e859ffffff             -call 0x47a5f0
    cpu.esp -= 4;
    sub_47a5f0(app, cpu);
    if (cpu.terminate) return;
    // 0047a697  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a698  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a699  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a69a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a69b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a69c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a69c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a69d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a69e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a69f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a6a0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a6a3  8b3570a84c00           -mov esi, dword ptr [0x4ca870]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023856) /* 0x4ca870 */);
    // 0047a6a9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047a6ab  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047a6ae  a174a84c00             -mov eax, dword ptr [0x4ca874]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023860) /* 0x4ca874 */);
    // 0047a6b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a6b5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047a6b7  7e26                   -jle 0x47a6df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a6df;
    }
L_0x0047a6b9:
    // 0047a6b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a6bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a6bd  6689fb                 -mov bx, di
    cpu.bx = cpu.di;
    // 0047a6c0  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047a6c4  39d9                   +cmp ecx, ebx
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
    // 0047a6c6  750f                   -jne 0x47a6d7
    if (!cpu.flags.zf)
    {
        goto L_0x0047a6d7;
    }
    // 0047a6c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a6ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a6cc  668b0c24               -mov cx, word ptr [esp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp);
    // 0047a6d0  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047a6d3  39cb                   +cmp ebx, ecx
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
    // 0047a6d5  7412                   -je 0x47a6e9
    if (cpu.flags.zf)
    {
        goto L_0x0047a6e9;
    }
L_0x0047a6d7:
    // 0047a6d7  42                     -inc edx
    (cpu.edx)++;
    // 0047a6d8  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047a6db  39f2                   +cmp edx, esi
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
    // 0047a6dd  7cda                   -jl 0x47a6b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a6b9;
    }
L_0x0047a6df:
    // 0047a6df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a6e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a6e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a6e9:
    // 0047a6e9  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047a6ec  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047a6ef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a6f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a6f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a6f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a6f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a6fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a6fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a6fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a6fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a6fe  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0047a701  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047a705  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047a708  a15ca84c00             -mov eax, dword ptr [0x4ca85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */);
    // 0047a70d  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0047a712  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a716  a168a84c00             -mov eax, dword ptr [0x4ca868]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023848) /* 0x4ca868 */);
    // 0047a71b  8b35cca74c00           -mov esi, dword ptr [0x4ca7cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */);
    // 0047a721  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047a725  a16ca84c00             -mov eax, dword ptr [0x4ca86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023852) /* 0x4ca86c */);
    // 0047a72a  8b15d4a74c00           -mov edx, dword ptr [0x4ca7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023700) /* 0x4ca7d4 */);
    // 0047a730  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0047a734  a174a84c00             -mov eax, dword ptr [0x4ca874]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023860) /* 0x4ca874 */);
    // 0047a739  8b0dd8a74c00           -mov ecx, dword ptr [0x4ca7d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023704) /* 0x4ca7d8 */);
    // 0047a73f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047a743  a1d0a74c00             -mov eax, dword ptr [0x4ca7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023696) /* 0x4ca7d0 */);
    // 0047a748  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a74a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a74c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047a750  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0047a754  a1cca74c00             -mov eax, dword ptr [0x4ca7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */);
    // 0047a759  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0047a75d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a761  a160a84c00             -mov eax, dword ptr [0x4ca860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023840) /* 0x4ca860 */);
    // 0047a766  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a768  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a76a  0f85fe000000           -jne 0x47a86e
    if (!cpu.flags.zf)
    {
        goto L_0x0047a86e;
    }
L_0x0047a770:
    // 0047a770  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0047a775  e8cafeffff             -call 0x47a644
    cpu.esp -= 4;
    sub_47a644(app, cpu);
    if (cpu.terminate) return;
    // 0047a77a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a77c  0f85f7000000           -jne 0x47a879
    if (!cpu.flags.zf)
    {
        goto L_0x0047a879;
    }
L_0x0047a782:
    // 0047a782  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047a786  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0047a78a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047a78c  45                     -inc ebp
    (cpu.ebp)++;
    // 0047a78d  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a791  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047a793  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0047a797  83f820                 +cmp eax, 0x20
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
    // 0047a79a  0f8efc000000           -jle 0x47a89c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a89c;
    }
    // 0047a7a0  e89ffeffff             -call 0x47a644
    cpu.esp -= 4;
    sub_47a644(app, cpu);
    if (cpu.terminate) return;
    // 0047a7a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a7a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047a7a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a7ab  74d5                   -je 0x47a782
    if (cpu.flags.zf)
    {
        goto L_0x0047a782;
    }
    // 0047a7ad  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047a7b2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a7b5  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047a7b9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047a7bb  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047a7c2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047a7c4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047a7c9  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047a7cd  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0047a7d0  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047a7d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047a7d6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047a7dd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047a7df  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047a7e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a7e5  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047a7e9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047a7ed  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047a7f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a7f3  740d                   -je 0x47a802
    if (cpu.flags.zf)
    {
        goto L_0x0047a802;
    }
    // 0047a7f5  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047a7f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a7fb  e89cfeffff             -call 0x47a69c
    cpu.esp -= 4;
    sub_47a69c(app, cpu);
    if (cpu.terminate) return;
    // 0047a800  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a802:
    // 0047a802  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0047a805  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047a808  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0047a80b  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0047a80f  8b4707                 -mov eax, dword ptr [edi + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 0047a812  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047a816  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047a819  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a81b  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047a81f  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0047a823  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047a825  7561                   -jne 0x47a888
    if (!cpu.flags.zf)
    {
        goto L_0x0047a888;
    }
L_0x0047a827:
    // 0047a827  8b1d40a84c00           -mov ebx, dword ptr [0x4ca840]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023808) /* 0x4ca840 */);
    // 0047a82d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a82f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a830  8a4703                 -mov al, byte ptr [edi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 0047a833  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047a837  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a838  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a83a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a83e  8a4702                 -mov al, byte ptr [edi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0047a841  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a843  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a844  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047a848  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a84c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a84d  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047a851  8b1d50a84c00           -mov ebx, dword ptr [0x4ca850]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023824) /* 0x4ca850 */);
    // 0047a857  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a859  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047a85d  ff542420               -call dword ptr [esp + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a861  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047a864  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047a867  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a869  e914ffffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a86e:
    // 0047a86e  ff1560a84c00           -call dword ptr [0x4ca860]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023840) /* 0x4ca860 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a874  e9f7feffff             -jmp 0x47a770
    goto L_0x0047a770;
L_0x0047a879:
    // 0047a879  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047a87c  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047a87f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047a883  e9fafeffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a888:
    // 0047a888  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047a88c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047a890  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a894  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047a896  ff54243c               -call dword ptr [esp + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a89a  eb8b                   -jmp 0x47a827
    goto L_0x0047a827;
L_0x0047a89c:
    // 0047a89c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a89e  7535                   -jne 0x47a8d5
    if (!cpu.flags.zf)
    {
        goto L_0x0047a8d5;
    }
    // 0047a8a0  833d64a84c0000         +cmp dword ptr [0x4ca864], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023844) /* 0x4ca864 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8a7  0f8598000000           -jne 0x47a945
    if (!cpu.flags.zf)
    {
        goto L_0x0047a945;
    }
L_0x0047a8ad:
    // 0047a8ad  a1d4a74c00             -mov eax, dword ptr [0x4ca7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023700) /* 0x4ca7d4 */);
    // 0047a8b2  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047a8b6  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8b8  a1d8a74c00             -mov eax, dword ptr [0x4ca7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023704) /* 0x4ca7d8 */);
    // 0047a8bd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8bf  8935cca74c00           -mov dword ptr [0x4ca7cc], esi
    app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */) = cpu.esi;
    // 0047a8c5  8915d0a74c00           -mov dword ptr [0x4ca7d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023696) /* 0x4ca7d0 */) = cpu.edx;
    // 0047a8cb  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0047a8ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a8d5:
    // 0047a8d5  83f80a                 +cmp eax, 0xa
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
    // 0047a8d8  7521                   -jne 0x47a8fb
    if (!cpu.flags.zf)
    {
        goto L_0x0047a8fb;
    }
    // 0047a8da  8b15e4a74c00           -mov edx, dword ptr [0x4ca7e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023716) /* 0x4ca7e4 */);
    // 0047a8e0  8b3de8a74c00           -mov edi, dword ptr [0x4ca7e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023720) /* 0x4ca7e8 */);
    // 0047a8e6  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047a8ea  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a8ec  01d0                   +add eax, edx
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
    // 0047a8ee  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a8f2  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0047a8f6  e987feffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a8fb:
    // 0047a8fb  833dd4874c0000         +cmp dword ptr [0x4c87d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015508) /* 0x4c87d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a902  7509                   -jne 0x47a90d
    if (!cpu.flags.zf)
    {
        goto L_0x0047a90d;
    }
L_0x0047a904:
    // 0047a904  0374241c               +add esi, dword ptr [esp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a908  e975feffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a90d:
    // 0047a90d  83f809                 +cmp eax, 9
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
    // 0047a910  75f2                   -jne 0x47a904
    if (!cpu.flags.zf)
    {
        goto L_0x0047a904;
    }
    // 0047a912  8b1dd0874c00           -mov ebx, dword ptr [0x4c87d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5015504) /* 0x4c87d0 */);
    // 0047a918  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a91a  0f8e62feffff           -jle 0x47a782
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a782;
    }
    // 0047a920  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047a923  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047a925:
    // 0047a925  a1d4874c00             -mov eax, dword ptr [0x4c87d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015508) /* 0x4c87d4 */);
    // 0047a92a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a92c  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a92e  39fe                   +cmp esi, edi
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
    // 0047a930  7d07                   -jge 0x47a939
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a939;
    }
    // 0047a932  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047a934  e949feffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a939:
    // 0047a939  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a93c  39da                   +cmp edx, ebx
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
    // 0047a93e  7ce5                   -jl 0x47a925
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a925;
    }
    // 0047a940  e93dfeffff             -jmp 0x47a782
    goto L_0x0047a782;
L_0x0047a945:
    // 0047a945  ff1564a84c00           -call dword ptr [0x4ca864]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023844) /* 0x4ca864 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a94b  e95dffffff             -jmp 0x47a8ad
    goto L_0x0047a8ad;
}

/* align: skip  */
void Application::sub_47a950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a951  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a953  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a955  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047a957  e8fc050000             -call 0x47af58
    cpu.esp -= 4;
    sub_47af58(app, cpu);
    if (cpu.terminate) return;
    // 0047a95c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a95e  e895fdffff             -call 0x47a6f8
    cpu.esp -= 4;
    sub_47a6f8(app, cpu);
    if (cpu.terminate) return;
    // 0047a963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a965(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a965  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a966  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a967  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a968  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a969  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047a96f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047a971  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047a973  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047a975  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a976  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0047a97b  2eff1590544b00         -call dword ptr cs:[0x4b5490]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936848) /* 0x4b5490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a982  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a984  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a986  7507                   -jne 0x47a98f
    if (!cpu.flags.zf)
    {
        goto L_0x0047a98f;
    }
    // 0047a988  e8b5b10100             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 0047a98d  eb20                   -jmp 0x47a9af
    goto L_0x0047a9af;
L_0x0047a98f:
    // 0047a98f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047a991  7520                   -jne 0x47a9b3
    if (!cpu.flags.zf)
    {
        goto L_0x0047a9b3;
    }
    // 0047a993  40                     -inc eax
    (cpu.eax)++;
    // 0047a994  39c6                   +cmp esi, eax
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
    // 0047a996  7602                   -jbe 0x47a99a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047a99a;
    }
    // 0047a998  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047a99a:
    // 0047a99a  e8b4b10100             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 0047a99f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047a9a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9a3  7519                   -jne 0x47a9be
    if (!cpu.flags.zf)
    {
        goto L_0x0047a9be;
    }
    // 0047a9a5  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x0047a9aa:
    // 0047a9aa  e891b20100             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
L_0x0047a9af:
    // 0047a9af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a9b1  eb28                   -jmp 0x47a9db
    goto L_0x0047a9db;
L_0x0047a9b3:
    // 0047a9b3  39f0                   +cmp eax, esi
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
    // 0047a9b5  7607                   -jbe 0x47a9be
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047a9be;
    }
    // 0047a9b7  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0047a9bc  ebec                   -jmp 0x47a9aa
    goto L_0x0047a9aa;
L_0x0047a9be:
    // 0047a9be  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047a9c0  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a9c1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047a9c3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0047a9c4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0047a9c6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0047a9c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a9c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a9cb  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047a9ce  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047a9d0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047a9d2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047a9d5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047a9d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9d8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0047a9d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047a9db:
    // 0047a9db  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047a9e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a9e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a9e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a9e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a9e8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047a9eb  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047a9ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9ef  7419                   -je 0x47aa0a
    if (cpu.flags.zf)
    {
        goto L_0x0047aa0a;
    }
    // 0047a9f1  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0047a9f3  b25c                   -mov dl, 0x5c
    cpu.dl = 92 /*0x5c*/;
    // 0047a9f5  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0047a9f8  88542402               -mov byte ptr [esp + 2], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 0047a9fc  b43a                   -mov ah, 0x3a
    cpu.ah = 58 /*0x3a*/;
    // 0047a9fe  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047aa00  88642401               -mov byte ptr [esp + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.ah;
    // 0047aa04  88742403               -mov byte ptr [esp + 3], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 0047aa08  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0047aa0a:
    // 0047aa0a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047aa0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa0f  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047aa13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa14  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047aa18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa19  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047aa1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047aa1f  2eff15a4544b00         -call dword ptr cs:[0x4b54a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936868) /* 0x4b54a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047aa26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047aa28  7507                   -jne 0x47aa31
    if (!cpu.flags.zf)
    {
        goto L_0x0047aa31;
    }
    // 0047aa2a  e813b10100             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 0047aa2f  eb1d                   -jmp 0x47aa4e
    goto L_0x0047aa4e;
L_0x0047aa31:
    // 0047aa31  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047aa35  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047aa37  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047aa3b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047aa3e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047aa42  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047aa45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047aa49  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047aa4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047aa4e:
    // 0047aa4e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047aa51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47aa60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aa60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047aa61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047aa63  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047aa65  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047aa67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047aa69  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047aa6b  7e41                   -jle 0x47aaae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047aaae;
    }
L_0x0047aa6d:
    // 0047aa6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047aa6f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047aa71  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047aa73  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047aa75  743b                   -je 0x47aab2
    if (cpu.flags.zf)
    {
        goto L_0x0047aab2;
    }
    // 0047aa77  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aa79  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047aa7b  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
L_0x0047aa7e:
    // 0047aa7e  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0047aa80  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047aa82  7425                   -je 0x47aaa9
    if (cpu.flags.zf)
    {
        goto L_0x0047aaa9;
    }
    // 0047aa84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047aa86  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0047aa88  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047aa8a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047aa8c  742f                   -je 0x47aabd
    if (cpu.flags.zf)
    {
        goto L_0x0047aabd;
    }
    // 0047aa8e  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047aa90  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0047aa93  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aa95  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0047aa97  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047aa9d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x0047aaa0:
    // 0047aaa0  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aaa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047aaa4  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0047aaa6  881431                 -mov byte ptr [ecx + esi], dl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.dl;
L_0x0047aaa9:
    // 0047aaa9  40                     -inc eax
    (cpu.eax)++;
    // 0047aaaa  39d8                   +cmp eax, ebx
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
    // 0047aaac  7cbf                   -jl 0x47aa6d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047aa6d;
    }
L_0x0047aaae:
    // 0047aaae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aab2:
    // 0047aab2  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047aab4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aab6  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 0047aab9  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047aabb  ebc1                   -jmp 0x47aa7e
    goto L_0x0047aa7e;
L_0x0047aabd:
    // 0047aabd  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047aabf  80e6f0                 -and dh, 0xf0
    cpu.dh &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0047aac2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aac4  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0047aac6  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0047aacc  ebd2                   -jmp 0x47aaa0
    goto L_0x0047aaa0;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47aad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aad0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0047aad1:
    // 0047aad1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047aad3  40                     -inc eax
    (cpu.eax)++;
    // 0047aad4  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047aad7  7506                   -jne 0x47aadf
    if (!cpu.flags.zf)
    {
        goto L_0x0047aadf;
    }
    // 0047aad9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047aada  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047aadb  75f4                   -jne 0x47aad1
    if (!cpu.flags.zf)
    {
        goto L_0x0047aad1;
    }
    // 0047aadd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aade  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aadf:
    // 0047aadf  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0047aae1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047aae2  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047aae3  75ec                   -jne 0x47aad1
    if (!cpu.flags.zf)
    {
        goto L_0x0047aad1;
    }
    // 0047aae5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47aae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aae8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0047aae9:
    // 0047aae9  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047aaec  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0047aaef  750b                   -jne 0x47aafc
    if (!cpu.flags.zf)
    {
        goto L_0x0047aafc;
    }
    // 0047aaf1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047aaf4  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047aaf7  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047aaf8  75ef                   -jne 0x47aae9
    if (!cpu.flags.zf)
    {
        goto L_0x0047aae9;
    }
    // 0047aafa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aafb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aafc:
    // 0047aafc  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0047aaff  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047ab02  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab05  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab06  75e1                   -jne 0x47aae9
    if (!cpu.flags.zf)
    {
        goto L_0x0047aae9;
    }
    // 0047ab08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ab0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ab0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ab0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ab0f  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 0047ab14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0047ab16:
    // 0047ab16  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047ab18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ab1a  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047ab1e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047ab20  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047ab27  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047ab29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ab2b  750d                   -jne 0x47ab3a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab3a;
    }
    // 0047ab2d  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047ab30  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab33  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab34  75e0                   -jne 0x47ab16
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab16;
    }
    // 0047ab36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ab3a:
    // 0047ab3a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047ab3c  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047ab3e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047ab41  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047ab44  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047ab47  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047ab4a  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047ab4d  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab50  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab51  75c3                   -jne 0x47ab16
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab16;
    }
    // 0047ab53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ab58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ab59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0047ab5a:
    // 0047ab5a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ab5c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047ab5e  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 0047ab61  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047ab63  750c                   -jne 0x47ab71
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab71;
    }
    // 0047ab65  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ab68  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab6b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab6c  75ec                   -jne 0x47ab5a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab5a;
    }
    // 0047ab6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ab71:
    // 0047ab71  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047ab73  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ab76  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ab79  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047ab7a  75de                   -jne 0x47ab5a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ab5a;
    }
    // 0047ab7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ab80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ab81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ab82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ab83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ab84  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0047ab8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ab8c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047ab8e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ab90  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ab93  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0047ab99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ab9b  83f804                 +cmp eax, 4
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
    // 0047ab9e  0f8580000000           -jne 0x47ac24
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac24;
    }
    // 0047aba4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047aba6:
    // 0047aba6  8b0cada07b5200         -mov ecx, dword ptr [ebp*4 + 0x527ba0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405600) /* 0x527ba0 */ + cpu.ebp * 4);
    // 0047abad  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0047abb4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047abb6  890df4874c00           -mov dword ptr [0x4c87f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5015540) /* 0x4c87f4 */) = cpu.ecx;
    // 0047abbc  890cada07b5200         -mov dword ptr [ebp*4 + 0x527ba0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405600) /* 0x527ba0 */ + cpu.ebp * 4) = cpu.ecx;
    // 0047abc3  83fa08                 +cmp edx, 8
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
    // 0047abc6  752d                   -jne 0x47abf5
    if (!cpu.flags.zf)
    {
        goto L_0x0047abf5;
    }
    // 0047abc8  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047abcf  7524                   -jne 0x47abf5
    if (!cpu.flags.zf)
    {
        goto L_0x0047abf5;
    }
    // 0047abd1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047abd3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047abd5  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 0047abda  e8317a0100             -call 0x492610
    cpu.esp -= 4;
    sub_492610(app, cpu);
    if (cpu.terminate) return;
    // 0047abdf  ba7c5c4900             -mov edx, 0x495c7c
    cpu.edx = 4807804 /*0x495c7c*/;
    // 0047abe4  a358b75100             -mov dword ptr [0x51b758], eax
    app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */) = cpu.eax;
    // 0047abe9  890dfc874c00           -mov dword ptr [0x4c87fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5015548) /* 0x4c87fc */) = cpu.ecx;
    // 0047abef  8915f4874c00           -mov dword ptr [0x4c87f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5015540) /* 0x4c87f4 */) = cpu.edx;
L_0x0047abf5:
    // 0047abf5  b9dc874c00             -mov ecx, 0x4c87dc
    cpu.ecx = 5015516 /*0x4c87dc*/;
    // 0047abfa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047abfc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047abfe  e819800100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047ac03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ac05  8b842400040000         -mov eax, dword ptr [esp + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0047ac0c  891dfc874c00           -mov dword ptr [0x4c87fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5015548) /* 0x4c87fc */) = cpu.ebx;
    // 0047ac12  8904ada07b5200         -mov dword ptr [ebp*4 + 0x527ba0], eax
    app->getMemory<x86::reg32>(x86::reg32(5405600) /* 0x527ba0 */ + cpu.ebp * 4) = cpu.eax;
    // 0047ac19  81c404040000           +add esp, 0x404
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1028 /*0x404*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ac1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac24:
    // 0047ac24  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0047ac29  e978ffffff             -jmp 0x47aba6
    goto L_0x0047aba6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ac30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ac31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ac32  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047ac35  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047ac38  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047ac3b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0047ac3e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047ac41  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047ac44  e837ffffff             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0047ac49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ac4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ac4d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ac50  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047ac53  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ac55  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047ac58  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047ac5b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ac5d  e81effffff             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0047ac62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ac64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ac65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ac66  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047ac69  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047ac6c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047ac6f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0047ac72  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047ac75  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047ac78  e803ffffff             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0047ac7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ac80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ac81  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ac84  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047ac87  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ac89  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047ac8c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047ac8f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ac91  e8eafeffff             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0047ac96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47aca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aca1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047aca6  e811000000             -call 0x47acbc
    cpu.esp -= 4;
    sub_47acbc(app, cpu);
    if (cpu.terminate) return;
    // 0047acab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47acb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047acb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047acb1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047acb3  e804000000             -call 0x47acbc
    cpu.esp -= 4;
    sub_47acbc(app, cpu);
    if (cpu.terminate) return;
    // 0047acb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47acbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047acbc  e823000000             -call 0x47ace4
    cpu.esp -= 4;
    sub_47ace4(app, cpu);
    if (cpu.terminate) return;
    // 0047acc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047acc3  7402                   -je 0x47acc7
    if (cpu.flags.zf)
    {
        goto L_0x0047acc7;
    }
    // 0047acc5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0047acc7:
    // 0047acc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47acc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047acc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047acc9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047acce  e811000000             -call 0x47ace4
    cpu.esp -= 4;
    sub_47ace4(app, cpu);
    if (cpu.terminate) return;
    // 0047acd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47acd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047acd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047acd9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047acdb  e804000000             -call 0x47ace4
    cpu.esp -= 4;
    sub_47ace4(app, cpu);
    if (cpu.terminate) return;
    // 0047ace0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ace1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ace4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ace4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ace5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ace6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ace7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ace8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047aceb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047aced  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047acf1  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047acf3  e8bc8e0100             -call 0x493bb4
    cpu.esp -= 4;
    sub_493bb4(app, cpu);
    if (cpu.terminate) return;
    // 0047acf8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047acfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047acfc  7417                   -je 0x47ad15
    if (cpu.flags.zf)
    {
        goto L_0x0047ad15;
    }
L_0x0047acfe:
    // 0047acfe  833d3cac4c0000         +cmp dword ptr [0x4cac3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024828) /* 0x4cac3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ad05  0f8590000000           -jne 0x47ad9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad9b;
    }
    // 0047ad0b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ad0d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ad10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ad15:
    // 0047ad15  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0047ad1a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0047ad1c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ad20  e88f990100             -call 0x4946b4
    cpu.esp -= 4;
    sub_4946b4(app, cpu);
    if (cpu.terminate) return;
    // 0047ad25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ad26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ad28  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ad2c  e897060000             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 0047ad31  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ad34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ad36  7511                   -jne 0x47ad49
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad49;
    }
    // 0047ad38  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ad3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ad3e  74be                   -je 0x47acfe
    if (cpu.flags.zf)
    {
        goto L_0x0047acfe;
    }
    // 0047ad40  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ad42  e869090000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047ad47  ebb5                   -jmp 0x47acfe
    goto L_0x0047acfe;
L_0x0047ad49:
    // 0047ad49  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ad4d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047ad4f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ad51  e84ed9ffff             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 0047ad56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ad58  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ad5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ad5c  742f                   -je 0x47ad8d
    if (cpu.flags.zf)
    {
        goto L_0x0047ad8d;
    }
    // 0047ad5e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ad61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ad63  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0047ad68  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ad6b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047ad6d  05c8000000             +add eax, 0xc8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ad72  e83d990100             -call 0x4946b4
    cpu.esp -= 4;
    sub_4946b4(app, cpu);
    if (cpu.terminate) return;
    // 0047ad77  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ad7a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ad7e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047ad80  e833090000             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 0047ad85  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ad88  a354824c00             -mov dword ptr [0x4c8254], eax
    app->getMemory<x86::reg32>(x86::reg32(5014100) /* 0x4c8254 */) = cpu.eax;
L_0x0047ad8d:
    // 0047ad8d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ad91  e81a090000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047ad96  e963ffffff             -jmp 0x47acfe
    goto L_0x0047acfe;
L_0x0047ad9b:
    // 0047ad9b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ad9f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047ada1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ada3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ada5  ff153cac4c00           -call dword ptr [0x4cac3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024828) /* 0x4cac3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047adab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047adad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047adaf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047adb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47adc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047adc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047adc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047adc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047adc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047adc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047adc5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047adc7  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047adca  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047adcc  8b400d                 -mov eax, dword ptr [eax + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0047adcf  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047add2  a3d4a74c00             -mov dword ptr [0x4ca7d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5023700) /* 0x4ca7d4 */) = cpu.eax;
    // 0047add7  8b420e                 -mov eax, dword ptr [edx + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0047adda  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047addf  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047ade2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047ade7  a3d8a74c00             -mov dword ptr [0x4ca7d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5023704) /* 0x4ca7d8 */) = cpu.eax;
    // 0047adec  8b420f                 -mov eax, dword ptr [edx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0047adef  891548a84c00           -mov dword ptr [0x4ca848], edx
    app->getMemory<x86::reg32>(x86::reg32(5023816) /* 0x4ca848 */) = cpu.edx;
    // 0047adf5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047adf8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047adfa  a3e4a74c00             -mov dword ptr [0x4ca7e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5023716) /* 0x4ca7e4 */) = cpu.eax;
    // 0047adff  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0047ae02  891d44a84c00           -mov dword ptr [0x4ca844], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023812) /* 0x4ca844 */) = cpu.ebx;
    // 0047ae08  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047ae0b  8935e0a74c00           -mov dword ptr [0x4ca7e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5023712) /* 0x4ca7e0 */) = cpu.esi;
    // 0047ae11  a3e8a74c00             -mov dword ptr [0x4ca7e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5023720) /* 0x4ca7e8 */) = cpu.eax;
    // 0047ae16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ae18  a1e4a74c00             -mov eax, dword ptr [0x4ca7e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023716) /* 0x4ca7e4 */);
    // 0047ae1d  893d78a84c00           -mov dword ptr [0x4ca878], edi
    app->getMemory<x86::reg32>(x86::reg32(5023864) /* 0x4ca878 */) = cpu.edi;
    // 0047ae23  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ae25  893d74a84c00           -mov dword ptr [0x4ca874], edi
    app->getMemory<x86::reg32>(x86::reg32(5023860) /* 0x4ca874 */) = cpu.edi;
    // 0047ae2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ae2d  891deca74c00           -mov dword ptr [0x4ca7ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023724) /* 0x4ca7ec */) = cpu.ebx;
    // 0047ae33  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ae35  891df0a74c00           -mov dword ptr [0x4ca7f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023728) /* 0x4ca7f0 */) = cpu.ebx;
    // 0047ae3b  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0047ae3f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047ae41  a33ca84c00             -mov dword ptr [0x4ca83c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023804) /* 0x4ca83c */) = cpu.eax;
    // 0047ae46  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047ae49  890d50a84c00           -mov dword ptr [0x4ca850], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023824) /* 0x4ca850 */) = cpu.ecx;
    // 0047ae4f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ae51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ae53  891d4ca84c00           -mov dword ptr [0x4ca84c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023820) /* 0x4ca84c */) = cpu.ebx;
    // 0047ae59  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ae5b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ae5e  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0047ae64  a3dca74c00             -mov dword ptr [0x4ca7dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5023708) /* 0x4ca7dc */) = cpu.eax;
    // 0047ae69  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0047ae6c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ae6e  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047ae71  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ae73  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ae76  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0047ae7c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0047ae7f  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047ae82  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047ae84  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0047ae87  a340a84c00             -mov dword ptr [0x4ca840], eax
    app->getMemory<x86::reg32>(x86::reg32(5023808) /* 0x4ca840 */) = cpu.eax;
    // 0047ae8c  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047ae8f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047ae92  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047ae95  83f802                 +cmp eax, 2
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
    // 0047ae98  740c                   -je 0x47aea6
    if (cpu.flags.zf)
    {
        goto L_0x0047aea6;
    }
    // 0047ae9a  813d3ca84c00ff000000   +cmp dword ptr [0x4ca83c], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023804) /* 0x4ca83c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aea4  7e38                   -jle 0x47aede
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047aede;
    }
L_0x0047aea6:
    // 0047aea6  c70568a84c006c5d4900   -mov dword ptr [0x4ca868], 0x495d6c
    app->getMemory<x86::reg32>(x86::reg32(5023848) /* 0x4ca868 */) = 4808044 /*0x495d6c*/;
L_0x0047aeb0:
    // 0047aeb0  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0047aeb5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047aeb7  b8fca74c00             -mov eax, 0x4ca7fc
    cpu.eax = 5023740 /*0x4ca7fc*/;
    // 0047aebc  893df4a74c00           -mov dword ptr [0x4ca7f4], edi
    app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */) = cpu.edi;
    // 0047aec2  893df8a74c00           -mov dword ptr [0x4ca7f8], edi
    app->getMemory<x86::reg32>(x86::reg32(5023736) /* 0x4ca7f8 */) = cpu.edi;
    // 0047aec8  e80f420000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047aecd  e8b6a90100             -call 0x495888
    cpu.esp -= 4;
    sub_495888(app, cpu);
    if (cpu.terminate) return;
    // 0047aed2  893d6ca84c00           -mov dword ptr [0x4ca86c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023852) /* 0x4ca86c */) = cpu.edi;
    // 0047aed8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aed9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aeda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aedb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aedc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aedd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aede:
    // 0047aede  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047aee3  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047aee6  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047aeea  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047aeec  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047aef3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047aef5  3dff000000             +cmp eax, 0xff
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
    // 0047aefa  77aa                   -ja 0x47aea6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047aea6;
    }
    // 0047aefc  c70568a84c00405d4900   -mov dword ptr [0x4ca868], 0x495d40
    app->getMemory<x86::reg32>(x86::reg32(5023848) /* 0x4ca868 */) = 4808000 /*0x495d40*/;
    // 0047af06  eba8                   -jmp 0x47aeb0
    goto L_0x0047aeb0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47af10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047af11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047af12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047af13  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 0047af18  bec8a74c00             -mov esi, 0x4ca7c8
    cpu.esi = 5023688 /*0x4ca7c8*/;
    // 0047af1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047af1f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047af21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47af28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047af29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047af2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047af2b  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 0047af30  bfc8a74c00             -mov edi, 0x4ca7c8
    cpu.edi = 5023688 /*0x4ca7c8*/;
    // 0047af35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047af37  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047af39  e8a6a90100             -call 0x4958e4
    cpu.esp -= 4;
    sub_4958e4(app, cpu);
    if (cpu.terminate) return;
    // 0047af3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47af50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af50  a1eca74c00             -mov eax, dword ptr [0x4ca7ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023724) /* 0x4ca7ec */);
    // 0047af55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47af58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af58  a3cca74c00             -mov dword ptr [0x4ca7cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */) = cpu.eax;
    // 0047af5d  8915d0a74c00           -mov dword ptr [0x4ca7d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023696) /* 0x4ca7d0 */) = cpu.edx;
    // 0047af63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47af64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af64  a3e0a74c00             -mov dword ptr [0x4ca7e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5023712) /* 0x4ca7e0 */) = cpu.eax;
    // 0047af69  e91aa90100             -jmp 0x495888
    return sub_495888(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47af70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af70  a1e0a74c00             -mov eax, dword ptr [0x4ca7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023712) /* 0x4ca7e0 */);
    // 0047af75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47af80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047af81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047af82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047af83  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047af86  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047af88  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047af8c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047af90  0fb635ec844c00         -movzx esi, byte ptr [0x4c84ec]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */));
    // 0047af97  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047af9a  83c607                 -add esi, 7
    (cpu.esi) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047af9d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047af9f  6683e6f8               -and si, 0xfff8
    cpu.si &= x86::reg16(x86::sreg16(65528 /*0xfff8*/));
    // 0047afa3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0047afa7:
    // 0047afa7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047afab  4a                     -dec edx
    (cpu.edx)--;
    // 0047afac  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047afb0  83faff                 +cmp edx, -1
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
    // 0047afb3  0f847f000000           -je 0x47b038
    if (cpu.flags.zf)
    {
        goto L_0x0047b038;
    }
    // 0047afb9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0047afbc  3b7c2408               +cmp edi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047afc0  7d22                   -jge 0x47afe4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047afe4;
    }
L_0x0047afc2:
    // 0047afc2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047afc4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047afc6  e8e5ad0100             -call 0x495db0
    cpu.esp -= 4;
    sub_495db0(app, cpu);
    if (cpu.terminate) return;
    // 0047afcb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047afcd  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047afd0  7315                   -jae 0x47afe7
    if (!cpu.flags.cf)
    {
        goto L_0x0047afe7;
    }
    // 0047afd2  83fe08                 +cmp esi, 8
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
    // 0047afd5  7504                   -jne 0x47afdb
    if (!cpu.flags.zf)
    {
        goto L_0x0047afdb;
    }
    // 0047afd7  41                     -inc ecx
    (cpu.ecx)++;
    // 0047afd8  8851ff                 -mov byte ptr [ecx - 1], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
L_0x0047afdb:
    // 0047afdb  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047afdf  47                     -inc edi
    (cpu.edi)++;
    // 0047afe0  39df                   +cmp edi, ebx
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
    // 0047afe2  7cde                   -jl 0x47afc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047afc2;
    }
L_0x0047afe4:
    // 0047afe4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047afe5  ebc0                   -jmp 0x47afa7
    goto L_0x0047afa7;
L_0x0047afe7:
    // 0047afe7  7713                   -ja 0x47affc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047affc;
    }
    // 0047afe9  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047afec  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0047aff0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047aff4  47                     -inc edi
    (cpu.edi)++;
    // 0047aff5  39df                   +cmp edi, ebx
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
    // 0047aff7  7cc9                   -jl 0x47afc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047afc2;
    }
    // 0047aff9  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047affa  ebab                   -jmp 0x47afa7
    goto L_0x0047afa7;
L_0x0047affc:
    // 0047affc  83fe18                 +cmp esi, 0x18
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047afff  72da                   -jb 0x47afdb
    if (cpu.flags.cf)
    {
        goto L_0x0047afdb;
    }
    // 0047b001  7617                   -jbe 0x47b01a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047b01a;
    }
    // 0047b003  83fe20                 +cmp esi, 0x20
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
    // 0047b006  75d3                   -jne 0x47afdb
    if (!cpu.flags.zf)
    {
        goto L_0x0047afdb;
    }
    // 0047b008  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b00b  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047b00e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b012  47                     -inc edi
    (cpu.edi)++;
    // 0047b013  39df                   +cmp edi, ebx
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
    // 0047b015  7cab                   -jl 0x47afc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047afc2;
    }
    // 0047b017  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047b018  eb8d                   -jmp 0x47afa7
    goto L_0x0047afa7;
L_0x0047b01a:
    // 0047b01a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047b01f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b021  e885ae0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b026  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047b029  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b02d  47                     -inc edi
    (cpu.edi)++;
    // 0047b02e  39df                   +cmp edi, ebx
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
    // 0047b030  7c90                   -jl 0x47afc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047afc2;
    }
    // 0047b032  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047b033  e96fffffff             -jmp 0x47afa7
    goto L_0x0047afa7;
L_0x0047b038:
    // 0047b038  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b03b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b03c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b03d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b03e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b044  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b045  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b046  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b047  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b049  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0047b04e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047b051  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047b053  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047b059  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b05b  a1e4844c00             -mov eax, dword ptr [0x4c84e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0047b060  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b062  8b1de0844c00           -mov ebx, dword ptr [0x4c84e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047b068  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b06a  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0047b06f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b071  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047b074  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0047b077  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b079  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047b07c  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047b07f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047b081  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0047b084  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0047b087  83f908                 +cmp ecx, 8
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
    // 0047b08a  7505                   -jne 0x47b091
    if (!cpu.flags.zf)
    {
        goto L_0x0047b091;
    }
    // 0047b08c  0500030000             -add eax, 0x300
    (cpu.eax) += x86::reg32(x86::sreg32(768 /*0x300*/));
L_0x0047b091:
    // 0047b091  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b092  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b093  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b098  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b099  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b09a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b09b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b09c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b09d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b09e  81ec08030000           -sub esp, 0x308
    (cpu.esp) -= x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047b0a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b0a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b0a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b0aa  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0047b0af  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047b0b5  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047b0b8  8b2de8844c00           -mov ebp, dword ptr [0x4c84e8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0047b0be  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047b0c0  8b1de0844c00           -mov ebx, dword ptr [0x4c84e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047b0c6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b0c8  a1e4844c00             -mov eax, dword ptr [0x4c84e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0047b0cd  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b0cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b0d1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b0d6  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0047b0dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b0df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b0e1  e8c5ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b0e6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b0eb  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b0ee  0f8564010000           -jne 0x47b258
    if (!cpu.flags.zf)
    {
        goto L_0x0047b258;
    }
    // 0047b0f4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0047b0f6:
    // 0047b0f6  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047b0f9  e8adad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b0fe  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b103  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b106  0f8553010000           -jne 0x47b25f
    if (!cpu.flags.zf)
    {
        goto L_0x0047b25f;
    }
    // 0047b10c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0047b10e:
    // 0047b10e  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0047b111  e895ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b116  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b11b  8d4103                 -lea eax, [ecx + 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0047b11e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b120  e886ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b125  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b12a  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b12d  0f8536010000           -jne 0x47b269
    if (!cpu.flags.zf)
    {
        goto L_0x0047b269;
    }
    // 0047b133  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0047b138:
    // 0047b138  8d4105                 -lea eax, [ecx + 5]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0047b13b  e86bad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b140  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b145  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b148  0f8522010000           -jne 0x47b270
    if (!cpu.flags.zf)
    {
        goto L_0x0047b270;
    }
    // 0047b14e  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
L_0x0047b153:
    // 0047b153  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0047b156  e850ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b15b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b160  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047b166  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047b169  e83dad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b16e  a1d8844c00             -mov eax, dword ptr [0x4c84d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014744) /* 0x4c84d8 */);
    // 0047b173  2b05e8844c00           -sub eax, dword ptr [0x4c84e8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
    // 0047b179  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0047b17c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b181  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 0047b188  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b18a  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0047b191  e815ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b196  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b19b  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0047b1a2  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047b1a5  e801ad0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b1aa  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b1af  8d410e                 -lea eax, [ecx + 0xe]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047b1b2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047b1b4  e8f2ac0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b1b9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b1be  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047b1c1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047b1c3  e8e3ac0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b1c8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b1cd  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0047b1d2  8d4111                 -lea eax, [ecx + 0x11]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 0047b1d5  83c612                 -add esi, 0x12
    (cpu.esi) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0047b1d8  e8ceac0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047b1dd  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b1e0  7532                   -jne 0x47b214
    if (!cpu.flags.zf)
    {
        goto L_0x0047b214;
    }
    // 0047b1e2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047b1e4  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047b1e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b1eb  e8a0270100             -call 0x48d990
    cpu.esp -= 4;
    sub_48d990(app, cpu);
    if (cpu.terminate) return;
    // 0047b1f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047b1f2:
    // 0047b1f2  46                     -inc esi
    (cpu.esi)++;
    // 0047b1f3  46                     -inc esi
    (cpu.esi)++;
    // 0047b1f4  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 0047b1f7  46                     -inc esi
    (cpu.esi)++;
    // 0047b1f8  8a5c0402               -mov bl, byte ptr [esp + eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 0047b1fc  8a4c0401               -mov cl, byte ptr [esp + eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0047b200  885efd                 -mov byte ptr [esi - 3], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0047b203  884efe                 -mov byte ptr [esi - 2], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.cl;
    // 0047b206  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047b209  8856ff                 -mov byte ptr [esi - 1], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0047b20c  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b211  75df                   -jne 0x47b1f2
    if (!cpu.flags.zf)
    {
        goto L_0x0047b1f2;
    }
    // 0047b213  90                     -nop 
    ;
L_0x0047b214:
    // 0047b214  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0047b219  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047b21f  8b1ddc844c00           -mov ebx, dword ptr [0x4c84dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047b225  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b227  8b15e0844c00           -mov edx, dword ptr [0x4c84e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047b22d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b22f  a1e4844c00             -mov eax, dword ptr [0x4c84e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0047b234  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b235  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b237  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047b239  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b23b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b23d  e83efdffff             -call 0x47af80
    cpu.esp -= 4;
    sub_47af80(app, cpu);
    if (cpu.terminate) return;
    // 0047b242  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047b249  742c                   -je 0x47b277
    if (cpu.flags.zf)
    {
        goto L_0x0047b277;
    }
    // 0047b24b  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047b251  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b252  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b253  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b254  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b255  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b256  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b257  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b258:
    // 0047b258  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047b25a  e997feffff             -jmp 0x47b0f6
    goto L_0x0047b0f6;
L_0x0047b25f:
    // 0047b25f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0047b264  e9a5feffff             -jmp 0x47b10e
    goto L_0x0047b10e;
L_0x0047b269:
    // 0047b269  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047b26b  e9c8feffff             -jmp 0x47b138
    goto L_0x0047b138;
L_0x0047b270:
    // 0047b270  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047b272  e9dcfeffff             -jmp 0x47b153
    goto L_0x0047b153;
L_0x0047b277:
    // 0047b277  8b9c2404030000         -mov ebx, dword ptr [esp + 0x304]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0047b27e  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0047b281  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047b283  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b285  e83aac0100             -call 0x495ec4
    cpu.esp -= 4;
    sub_495ec4(app, cpu);
    if (cpu.terminate) return;
    // 0047b28a  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047b290  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b291  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b292  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b293  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b294  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b295  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b296  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47b298(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b298  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b299  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b29a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b29b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b29c  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b29f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b2a1  e89efdffff             -call 0x47b044
    cpu.esp -= 4;
    sub_47b044(app, cpu);
    if (cpu.terminate) return;
    // 0047b2a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b2a8  e823e90000             -call 0x489bd0
    cpu.esp -= 4;
    sub_489bd0(app, cpu);
    if (cpu.terminate) return;
    // 0047b2ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b2af  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b2b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b2b3  750a                   -jne 0x47b2bf
    if (!cpu.flags.zf)
    {
        goto L_0x0047b2bf;
    }
    // 0047b2b5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b2b7  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b2ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b2bf:
    // 0047b2bf  e8d4fdffff             -call 0x47b098
    cpu.esp -= 4;
    sub_47b098(app, cpu);
    if (cpu.terminate) return;
    // 0047b2c4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b2c6  e8d5820100             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 0047b2cb  e88cb0ffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047b2d0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b2d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b2d4  e837000000             -call 0x47b310
    cpu.esp -= 4;
    sub_47b310(app, cpu);
    if (cpu.terminate) return;
    // 0047b2d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b2db  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b2dd  e8e2820100             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
    // 0047b2e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b2e4  e84fe90000             -call 0x489c38
    cpu.esp -= 4;
    sub_489c38(app, cpu);
    if (cpu.terminate) return;
    // 0047b2e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b2eb  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b2ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b2f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47b300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b301  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047b306  e811000000             -call 0x47b31c
    cpu.esp -= 4;
    sub_47b31c(app, cpu);
    if (cpu.terminate) return;
    // 0047b30b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b30c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b310  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b311  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b313  e804000000             -call 0x47b31c
    cpu.esp -= 4;
    sub_47b31c(app, cpu);
    if (cpu.terminate) return;
    // 0047b318  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b31c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b31c  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047b31f  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047b322  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047b326  8b1550824c00           -mov edx, dword ptr [0x4c8250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 0047b32c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047b32e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047b332  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047b334  e823000000             -call 0x47b35c
    cpu.esp -= 4;
    sub_47b35c(app, cpu);
    if (cpu.terminate) return;
    // 0047b339  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047b33c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b341  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b346  e811000000             -call 0x47b35c
    cpu.esp -= 4;
    sub_47b35c(app, cpu);
    if (cpu.terminate) return;
    // 0047b34b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b34c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b351  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b353  e804000000             -call 0x47b35c
    cpu.esp -= 4;
    sub_47b35c(app, cpu);
    if (cpu.terminate) return;
    // 0047b358  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b359  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b35c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b35c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b35d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b35e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b35f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b360  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b363  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b365  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b367  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b36b  e804dcffff             -call 0x478f74
    cpu.esp -= 4;
    sub_478f74(app, cpu);
    if (cpu.terminate) return;
    // 0047b370  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047b372  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b374  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b378  e823d3ffff             -call 0x4786a0
    cpu.esp -= 4;
    sub_4786a0(app, cpu);
    if (cpu.terminate) return;
    // 0047b37d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047b37f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b381  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b383  e89c010000             -call 0x47b524
    cpu.esp -= 4;
    sub_47b524(app, cpu);
    if (cpu.terminate) return;
    // 0047b388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b38a  7508                   -jne 0x47b394
    if (!cpu.flags.zf)
    {
        goto L_0x0047b394;
    }
    // 0047b38c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b38f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b390  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b391  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b392  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b393  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b394:
    // 0047b394  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b397  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047b399  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047b39b  e820030000             -call 0x47b6c0
    cpu.esp -= 4;
    sub_47b6c0(app, cpu);
    if (cpu.terminate) return;
    // 0047b3a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b3a2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b3a5  e806030000             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047b3aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b3ac  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b3af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47b3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b3c0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b3c2  e939c5fcff             -jmp 0x447900
    return sub_447900(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47b3c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b3c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b3c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b3ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b3cb  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b3ce  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047b3d2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047b3d4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047b3d6  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047b3d8  ba05030000             -mov edx, 0x305
    cpu.edx = 773 /*0x305*/;
    // 0047b3dd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b3df  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047b3e3  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047b3e7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b3e9  7504                   -jne 0x47b3ef
    if (!cpu.flags.zf)
    {
        goto L_0x0047b3ef;
    }
    // 0047b3eb  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047b3ef:
    // 0047b3ef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047b3f1  7502                   -jne 0x47b3f5
    if (!cpu.flags.zf)
    {
        goto L_0x0047b3f5;
    }
    // 0047b3f3  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x0047b3f5:
    // 0047b3f5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047b3f9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b3fd  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047b3ff  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047b405  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b407  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047b40e  e8fdbdfcff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0047b413  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b415  0f85b1000000           -jne 0x47b4cc
    if (!cpu.flags.zf)
    {
        goto L_0x0047b4cc;
    }
    // 0047b41b  833d84884c0000         +cmp dword ptr [0x4c8884], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015684) /* 0x4c8884 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b422  7409                   -je 0x47b42d
    if (cpu.flags.zf)
    {
        goto L_0x0047b42d;
    }
    // 0047b424  803d00884c0000         +cmp byte ptr [0x4c8800], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5015552) /* 0x4c8800 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047b42b  750d                   -jne 0x47b43a
    if (!cpu.flags.zf)
    {
        goto L_0x0047b43a;
    }
L_0x0047b42d:
    // 0047b42d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b431  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b434  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b435  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b436  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b437  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047b43a:
    // 0047b43a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047b43e  b800884c00             -mov eax, 0x4c8800
    cpu.eax = 5015552 /*0x4c8800*/;
    // 0047b443  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047b445  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b447  e8c4bdfcff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0047b44c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b44e  74dd                   -je 0x47b42d
    if (cpu.flags.zf)
    {
        goto L_0x0047b42d;
    }
    // 0047b450  8b1d8c884c00           -mov ebx, dword ptr [0x4c888c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5015692) /* 0x4c888c */);
    // 0047b456  8b1580884c00           -mov edx, dword ptr [0x4c8880]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5015680) /* 0x4c8880 */);
    // 0047b45c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b45e  e8bdb8fcff             -call 0x446d20
    cpu.esp -= 4;
    sub_446d20(app, cpu);
    if (cpu.terminate) return;
    // 0047b463  a38c884c00             -mov dword ptr [0x4c888c], eax
    app->getMemory<x86::reg32>(x86::reg32(5015692) /* 0x4c888c */) = cpu.eax;
    // 0047b468  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b46a  751e                   -jne 0x47b48a
    if (!cpu.flags.zf)
    {
        goto L_0x0047b48a;
    }
L_0x0047b46c:
    // 0047b46c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b470  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047b472  75b9                   -jne 0x47b42d
    if (!cpu.flags.zf)
    {
        goto L_0x0047b42d;
    }
    // 0047b474  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b476  e8b5b3fcff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0047b47b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047b47d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b481  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b484  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b485  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b486  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b487  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047b48a:
    // 0047b48a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b48e  a180884c00             -mov eax, dword ptr [0x4c8880]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015680) /* 0x4c8880 */);
    // 0047b493  ff1584884c00           -call dword ptr [0x4c8884]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5015684) /* 0x4c8884 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047b499  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047b49c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b49e  74cc                   -je 0x47b46c
    if (cpu.flags.zf)
    {
        goto L_0x0047b46c;
    }
    // 0047b4a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b4a2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b4a4  e867b5fcff             -call 0x446a10
    cpu.esp -= 4;
    sub_446a10(app, cpu);
    if (cpu.terminate) return;
    // 0047b4a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b4ab  74bf                   -je 0x47b46c
    if (cpu.flags.zf)
    {
        goto L_0x0047b46c;
    }
    // 0047b4ad  a188884c00             -mov eax, dword ptr [0x4c8888]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015688) /* 0x4c8888 */);
    // 0047b4b2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b4b7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b4b9  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047b4bd  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047b4bf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b4c3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b4c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4c9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047b4cc:
    // 0047b4cc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047b4d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b4d3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047b4d5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b4d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b4d9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047b4dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b4df  e8ecbbfcff             -call 0x4470d0
    cpu.esp -= 4;
    sub_4470d0(app, cpu);
    if (cpu.terminate) return;
    // 0047b4e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b4e6  0f8541ffffff           -jne 0x47b42d
    if (!cpu.flags.zf)
    {
        goto L_0x0047b42d;
    }
    // 0047b4ec  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b4ee  e83db3fcff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0047b4f3  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047b4f9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047b4fb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047b501  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0047b505  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b509  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b50c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b50d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b50e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b50f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b514  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b516  e8adfeffff             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 0047b51b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b51c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b51c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b51e  e8a5feffff             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 0047b523  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b524(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b524  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b525  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b526  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b527  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b52a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047b52c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047b52e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047b530  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b532  7504                   -jne 0x47b538
    if (!cpu.flags.zf)
    {
        goto L_0x0047b538;
    }
    // 0047b534  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047b538:
    // 0047b538  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b53a  7502                   -jne 0x47b53e
    if (!cpu.flags.zf)
    {
        goto L_0x0047b53e;
    }
    // 0047b53c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x0047b53e:
    // 0047b53e  ba32030000             -mov edx, 0x332
    cpu.edx = 818 /*0x332*/;
    // 0047b543  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047b545  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b547  e8c4bcfcff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0047b54c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b54e  751a                   -jne 0x47b56a
    if (!cpu.flags.zf)
    {
        goto L_0x0047b56a;
    }
    // 0047b550  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047b552  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047b556  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0047b558:
    // 0047b558  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b55c  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047b563  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b566  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b567  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b568  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b56a:
    // 0047b56a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047b56f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b571  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047b573  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047b575  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b577  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047b57b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b57d  e84ebbfcff             -call 0x4470d0
    cpu.esp -= 4;
    sub_4470d0(app, cpu);
    if (cpu.terminate) return;
    // 0047b582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b584  75d2                   -jne 0x47b558
    if (!cpu.flags.zf)
    {
        goto L_0x0047b558;
    }
    // 0047b586  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047b588  e8a3b2fcff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0047b58d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b58f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047b595  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047b599  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047b59f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b5a3  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047b5aa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047b5ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b5ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b5af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b5b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b5b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b5b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b5b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b5b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b5b7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b5ba  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047b5be  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047b5c0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047b5c2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047b5c4  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 0047b5c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b5cb  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047b5cf  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047b5d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b5d5  7504                   -jne 0x47b5db
    if (!cpu.flags.zf)
    {
        goto L_0x0047b5db;
    }
    // 0047b5d7  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047b5db:
    // 0047b5db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047b5dd  7502                   -jne 0x47b5e1
    if (!cpu.flags.zf)
    {
        goto L_0x0047b5e1;
    }
    // 0047b5df  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x0047b5e1:
    // 0047b5e1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b5e5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047b5e9  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047b5eb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047b5f1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b5f3  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047b5fa  e811bcfcff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0047b5ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b601  751f                   -jne 0x47b622
    if (!cpu.flags.zf)
    {
        goto L_0x0047b622;
    }
    // 0047b603  833d84884c0000         +cmp dword ptr [0x4c8884], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015684) /* 0x4c8884 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b60a  7409                   -je 0x47b615
    if (cpu.flags.zf)
    {
        goto L_0x0047b615;
    }
    // 0047b60c  803d00884c0000         +cmp byte ptr [0x4c8800], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5015552) /* 0x4c8800 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047b613  7542                   -jne 0x47b657
    if (!cpu.flags.zf)
    {
        goto L_0x0047b657;
    }
L_0x0047b615:
    // 0047b615  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b619  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b61c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b61d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b61e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b61f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047b622:
    // 0047b622  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b624  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047b626  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b628  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b62a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b62c  e89fbafcff             -call 0x4470d0
    cpu.esp -= 4;
    sub_4470d0(app, cpu);
    if (cpu.terminate) return;
    // 0047b631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b633  740d                   -je 0x47b642
    if (cpu.flags.zf)
    {
        goto L_0x0047b642;
    }
    // 0047b635  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b637  e834b1fcff             -call 0x446770
    cpu.esp -= 4;
    sub_446770(app, cpu);
    if (cpu.terminate) return;
    // 0047b63c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047b640  ebd3                   -jmp 0x47b615
    goto L_0x0047b615;
L_0x0047b642:
    // 0047b642  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b644  e8e7b1fcff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0047b649  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047b64f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047b655  ebbe                   -jmp 0x47b615
    goto L_0x0047b615;
L_0x0047b657:
    // 0047b657  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b65b  b800884c00             -mov eax, 0x4c8800
    cpu.eax = 5015552 /*0x4c8800*/;
    // 0047b660  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047b662  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b664  e8a7bbfcff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0047b669  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b66b  74a8                   -je 0x47b615
    if (cpu.flags.zf)
    {
        goto L_0x0047b615;
    }
    // 0047b66d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047b66f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047b673  e8f8b0fcff             -call 0x446770
    cpu.esp -= 4;
    sub_446770(app, cpu);
    if (cpu.terminate) return;
    // 0047b678  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b67a  ff1584884c00           -call dword ptr [0x4c8884]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5015684) /* 0x4c8884 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047b680  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047b683  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047b685  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047b689  a188884c00             -mov eax, dword ptr [0x4c8888]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015688) /* 0x4c8888 */);
    // 0047b68e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b690  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047b692  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047b696  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b699  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47b6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6a0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047b6a2  e80dffffff             -call 0x47b5b4
    cpu.esp -= 4;
    sub_47b5b4(app, cpu);
    if (cpu.terminate) return;
    // 0047b6a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b6a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6a8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047b6aa  e805ffffff             -call 0x47b5b4
    cpu.esp -= 4;
    sub_47b5b4(app, cpu);
    if (cpu.terminate) return;
    // 0047b6af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6b0  e97bb1fcff             -jmp 0x446830
    return sub_446830(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b6b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6b8  e963b6fcff             -jmp 0x446d20
    return sub_446d20(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6c0  e92bb4fcff             -jmp 0x446af0
    return sub_446af0(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b6c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b6c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b6cb  e840b3fcff             -call 0x446a10
    cpu.esp -= 4;
    sub_446a10(app, cpu);
    if (cpu.terminate) return;
    // 0047b6d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b6d2  7502                   -jne 0x47b6d6
    if (!cpu.flags.zf)
    {
        goto L_0x0047b6d6;
    }
    // 0047b6d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b6d6:
    // 0047b6d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b6d8  e883b2fcff             -call 0x446960
    cpu.esp -= 4;
    sub_446960(app, cpu);
    if (cpu.terminate) return;
    // 0047b6dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b6df(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6df  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b6e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b6e1  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047b6e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b6e6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b6e8  e801ab0100             -call 0x4961ee
    cpu.esp -= 4;
    sub_4961ee(app, cpu);
    if (cpu.terminate) return;
    // 0047b6ed  3df4010000             +cmp eax, 0x1f4
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
    // 0047b6f2  7c03                   -jl 0x47b6f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047b6f7;
    }
    // 0047b6f4  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x0047b6f7:
    // 0047b6f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b6f9  e857ab0100             -call 0x496255
    cpu.esp -= 4;
    sub_496255(app, cpu);
    if (cpu.terminate) return;
    // 0047b6fe  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b700  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b702  7402                   -je 0x47b706
    if (cpu.flags.zf)
    {
        goto L_0x0047b706;
    }
    // 0047b704  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0047b706:
    // 0047b706  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b708  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047b70b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b70c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b70d  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
