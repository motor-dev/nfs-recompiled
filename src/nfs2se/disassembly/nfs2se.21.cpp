#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4847d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004847d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004847d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004847d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004847d7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004847da  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004847de  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004847e0  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004847e2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004847e4  66a9ff0f               +test ax, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 4095 /*0xfff*/));
    // 004847e8  740c                   -je 0x4847f6
    if (cpu.flags.zf)
    {
        goto L_0x004847f6;
    }
    // 004847ea  8db800100000           -lea edi, [eax + 0x1000]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4096) /* 0x1000 */);
    // 004847f0  81e700f0ff7f           -and edi, 0x7ffff000
    cpu.edi &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x004847f6:
    // 004847f6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004847fb  b888e84b00             -mov eax, 0x4be888
    cpu.eax = 4974728 /*0x4be888*/;
    // 00484800  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00484802  e8793effff             -call 0x478680
    cpu.esp -= 4;
    sub_478680(app, cpu);
    if (cpu.terminate) return;
    // 00484807  8b1510a04c00           -mov edx, dword ptr [0x4ca010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */);
    // 0048480d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00484810  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00484817  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484819  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048481c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048481e  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00484825  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00484827  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048482a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048482c  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00484832  b8b0e84b00             -mov eax, 0x4be8b0
    cpu.eax = 4974768 /*0x4be8b0*/;
    // 00484837  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048483d  e8523effff             -call 0x478694
    cpu.esp -= 4;
    sub_478694(app, cpu);
    if (cpu.terminate) return;
    // 00484842  8b1510a04c00           -mov edx, dword ptr [0x4ca010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */);
    // 00484848  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048484a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00484851  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484853  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00484856  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484858  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048485f  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00484862  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00484868  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048486a  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00484870  e867a8ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00484875  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00484878  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0048487e  89be84000000           -mov dword ptr [esi + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 00484884  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00484889  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048488b  e8b0c50000             -call 0x490e40
    cpu.esp -= 4;
    sub_490e40(app, cpu);
    if (cpu.terminate) return;
    // 00484890  8b3d10a04c00           -mov edi, dword ptr [0x4ca010]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */);
    // 00484896  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0048489d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048489f  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004848a2  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004848a4  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004848a7  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004848aa  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004848af  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004848b5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004848b7  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004848bd  e87ec50000             -call 0x490e40
    cpu.esp -= 4;
    sub_490e40(app, cpu);
    if (cpu.terminate) return;
    // 004848c2  8b3d10a04c00           -mov edi, dword ptr [0x4ca010]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */);
    // 004848c8  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004848cf  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004848d1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004848d4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004848d6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004848d9  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004848db  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004848de  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004848e2  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004848e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004848ea  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004848f0  e8c7fdffff             -call 0x4846bc
    cpu.esp -= 4;
    sub_4846bc(app, cpu);
    if (cpu.terminate) return;
    // 004848f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004848f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4848fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004848fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004848fd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004848ff  e8d0feffff             -call 0x4847d4
    cpu.esp -= 4;
    sub_4847d4(app, cpu);
    if (cpu.terminate) return;
    // 00484904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484905  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484909  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048490e  e8c1feffff             -call 0x4847d4
    cpu.esp -= 4;
    sub_4847d4(app, cpu);
    if (cpu.terminate) return;
    // 00484913  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484914  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484918(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484918  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484919  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048491a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048491b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048491c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048491d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00484920  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484922  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00484924  e8c72fffff             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00484929  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048492d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048492f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00484933  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00484937  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048493b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048493c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484940  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484942  e8d9740100             -call 0x49be20
    cpu.esp -= 4;
    sub_49be20(app, cpu);
    if (cpu.terminate) return;
    // 00484947  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00484949  0f8590000000           -jne 0x4849df
    if (!cpu.flags.zf)
    {
        goto L_0x004849df;
    }
    // 0048494f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00484952  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00484956  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048495a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048495e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484962  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00484966:
    // 00484966  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048496a  2d00200000             -sub eax, 0x2000
    (cpu.eax) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 0048496f  662500e0               -and ax, 0xe000
    cpu.ax &= x86::reg16(x86::sreg16(57344 /*0xe000*/));
    // 00484973  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00484977  3d00000400             +cmp eax, 0x40000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(262144 /*0x40000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048497c  0f8f7a000000           -jg 0x4849fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004849fc;
    }
L_0x00484982:
    // 00484982  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00484987  b81ce94b00             -mov eax, 0x4be91c
    cpu.eax = 4974876 /*0x4be91c*/;
    // 0048498c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048498e  e8d53cffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00484993  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484995  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0048499a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048499c  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004849a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004849a3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004849a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004849a7:
    // 004849a7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004849aa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004849ac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004849ae  e8f9740100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 004849b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004849b5  74f0                   -je 0x4849a7
    if (cpu.flags.zf)
    {
        goto L_0x004849a7;
    }
    // 004849b7  e8fb28ffff             -call 0x4772b7
    cpu.esp -= 4;
    sub_4772b7(app, cpu);
    if (cpu.terminate) return;
    // 004849bc  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004849c0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004849c2  7e4f                   -jle 0x484a13
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484a13;
    }
    // 004849c4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004849c6:
    // 004849c6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004849c9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004849cb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004849cd  e8da740100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 004849d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004849d4  7533                   -jne 0x484a09
    if (!cpu.flags.zf)
    {
        goto L_0x00484a09;
    }
    // 004849d6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004849d8  e8a336ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 004849dd  ebe7                   -jmp 0x4849c6
    goto L_0x004849c6;
L_0x004849df:
    // 004849df  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004849e3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004849e7  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004849eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004849ec  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004849f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004849f2  e829740100             -call 0x49be20
    cpu.esp -= 4;
    sub_49be20(app, cpu);
    if (cpu.terminate) return;
    // 004849f7  e96affffff             -jmp 0x484966
    goto L_0x00484966;
L_0x004849fc:
    // 004849fc  c744240800000400       -mov dword ptr [esp + 8], 0x40000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 262144 /*0x40000*/;
    // 00484a04  e979ffffff             -jmp 0x484982
    goto L_0x00484982;
L_0x00484a09:
    // 00484a09  81ef00200000           -sub edi, 0x2000
    (cpu.edi) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 00484a0f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00484a11  7fb3                   -jg 0x4849c6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004849c6;
    }
L_0x00484a13:
    // 00484a13  e89f28ffff             -call 0x4772b7
    cpu.esp -= 4;
    sub_4772b7(app, cpu);
    if (cpu.terminate) return;
    // 00484a18  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484a1a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00484a1c:
    // 00484a1c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484a20  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00484a22  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484a24  e883740100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 00484a29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484a2b  7509                   -jne 0x484a36
    if (!cpu.flags.zf)
    {
        goto L_0x00484a36;
    }
    // 00484a2d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484a2f  e84c36ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00484a34  ebe6                   -jmp 0x484a1c
    goto L_0x00484a1c;
L_0x00484a36:
    // 00484a36  e87c28ffff             -call 0x4772b7
    cpu.esp -= 4;
    sub_4772b7(app, cpu);
    if (cpu.terminate) return;
    // 00484a3b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484a3d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00484a40  e807740100             -call 0x49be4c
    cpu.esp -= 4;
    sub_49be4c(app, cpu);
    if (cpu.terminate) return;
    // 00484a45  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484a4a  7409                   -je 0x484a55
    if (cpu.flags.zf)
    {
        goto L_0x00484a55;
    }
    // 00484a4c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484a50  e8f7730100             -call 0x49be4c
    cpu.esp -= 4;
    sub_49be4c(app, cpu);
    if (cpu.terminate) return;
L_0x00484a55:
    // 00484a55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484a57  e87040ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00484a5c  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00484a63  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00484a66  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484a68  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00484a6b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484a6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484a71  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00484a74  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00484a76  a3a04b5200             -mov dword ptr [0x524ba0], eax
    app->getMemory<x86::reg32>(x86::reg32(5393312) /* 0x524ba0 */) = cpu.eax;
    // 00484a7b  83f801                 +cmp eax, 1
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
    // 00484a7e  7d0a                   -jge 0x484a8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484a8a;
    }
    // 00484a80  c705a04b520001000000   -mov dword ptr [0x524ba0], 1
    app->getMemory<x86::reg32>(x86::reg32(5393312) /* 0x524ba0 */) = 1 /*0x1*/;
L_0x00484a8a:
    // 00484a8a  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 00484a8f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484a91  8b0da04b5200           -mov ecx, dword ptr [0x524ba0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5393312) /* 0x524ba0 */);
    // 00484a97  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00484a9a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00484a9c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484aa0  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 00484aa7  a3a44b5200             -mov dword ptr [0x524ba4], eax
    app->getMemory<x86::reg32>(x86::reg32(5393316) /* 0x524ba4 */) = cpu.eax;
    // 00484aac  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484aae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484ab2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484ab4  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00484ab7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00484aba  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484abc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484abe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00484ac1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00484ac3  a314a04c00             -mov dword ptr [0x4ca014], eax
    app->getMemory<x86::reg32>(x86::reg32(5021716) /* 0x4ca014 */) = cpu.eax;
    // 00484ac8  3dda000000             +cmp eax, 0xda
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(218 /*0xda*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484acd  7f25                   -jg 0x484af4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00484af4;
    }
    // 00484acf  3da3000000             +cmp eax, 0xa3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(163 /*0xa3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484ad4  7c2a                   -jl 0x484b00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484b00;
    }
L_0x00484ad6:
    // 00484ad6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00484add  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00484adf  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484ae1  a318a04c00             -mov dword ptr [0x4ca018], eax
    app->getMemory<x86::reg32>(x86::reg32(5021720) /* 0x4ca018 */) = cpu.eax;
    // 00484ae6  a1a44b5200             -mov eax, dword ptr [0x524ba4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5393316) /* 0x524ba4 */);
    // 00484aeb  83c420                 +add esp, 0x20
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
    // 00484aee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484af0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484af1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484af2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484af3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484af4:
    // 00484af4  c70514a04c00da000000   -mov dword ptr [0x4ca014], 0xda
    app->getMemory<x86::reg32>(x86::reg32(5021716) /* 0x4ca014 */) = 218 /*0xda*/;
    // 00484afe  ebd6                   -jmp 0x484ad6
    goto L_0x00484ad6;
L_0x00484b00:
    // 00484b00  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00484b05  890dc4a74c00           -mov dword ptr [0x4ca7c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023684) /* 0x4ca7c4 */) = cpu.ecx;
    // 00484b0b  890d14a04c00           -mov dword ptr [0x4ca014], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021716) /* 0x4ca014 */) = cpu.ecx;
    // 00484b11  ebc3                   -jmp 0x484ad6
    goto L_0x00484ad6;
}

/* align: skip 0x90 */
void Application::sub_484b14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b15  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b16  bada000000             -mov edx, 0xda
    cpu.edx = 218 /*0xda*/;
    // 00484b1b  b92c010000             -mov ecx, 0x12c
    cpu.ecx = 300 /*0x12c*/;
    // 00484b20  891514a04c00           -mov dword ptr [0x4ca014], edx
    app->getMemory<x86::reg32>(x86::reg32(5021716) /* 0x4ca014 */) = cpu.edx;
    // 00484b26  890d18a04c00           -mov dword ptr [0x4ca018], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021720) /* 0x4ca018 */) = cpu.ecx;
    // 00484b2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484b34  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00484b3a  39d0                   +cmp eax, edx
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
    // 00484b3c  7403                   -je 0x484b41
    if (cpu.flags.zf)
    {
        goto L_0x00484b41;
    }
    // 00484b3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484b41:
    // 00484b41  c7422408000000         -mov dword ptr [edx + 0x24], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 8 /*0x8*/;
    // 00484b48  8b92a8000000           -mov edx, dword ptr [edx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00484b4e  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00484b53  e888a3ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00484b58  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00484b5e  e8b9a3ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00484b63  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00484b69  e83aa4ffff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00484b6e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00484b74  e8bba4ffff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 00484b79  c781ac00000000000000   -mov dword ptr [ecx + 0xac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 00484b83  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 00484b89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484b8b  e8a0a0ffff             -call 0x47ec30
    cpu.esp -= 4;
    sub_47ec30(app, cpu);
    if (cpu.terminate) return;
    // 00484b90  890d24a04c00           -mov dword ptr [0x4ca024], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */) = cpu.ecx;
    // 00484b96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484b9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b9e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484b9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484ba1  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00484ba7  39c8                   +cmp eax, ecx
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
    // 00484ba9  7440                   -je 0x484beb
    if (cpu.flags.zf)
    {
        goto L_0x00484beb;
    }
    // 00484bab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484bad  83797000               +cmp dword ptr [ecx + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484bb1  740e                   -je 0x484bc1
    if (cpu.flags.zf)
    {
        goto L_0x00484bc1;
    }
L_0x00484bb3:
    // 00484bb3  3b5070                 +cmp edx, dword ptr [eax + 0x70]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484bb6  7409                   -je 0x484bc1
    if (cpu.flags.zf)
    {
        goto L_0x00484bc1;
    }
    // 00484bb8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00484bbb  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 00484bbf  75f2                   -jne 0x484bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00484bb3;
    }
L_0x00484bc1:
    // 00484bc1  8b4a70                 -mov ecx, dword ptr [edx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 00484bc4  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00484bc7  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00484bcd  e8fa3effff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00484bd2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484bd4  e8f33effff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00484bd9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00484bdb  892d28a04c00           -mov dword ptr [0x4ca028], ebp
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.ebp;
    // 00484be1  892d24a04c00           -mov dword ptr [0x4ca024], ebp
    app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */) = cpu.ebp;
    // 00484be7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484be8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484be9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484beb:
    // 00484beb  e840ffffff             -call 0x484b30
    cpu.esp -= 4;
    sub_484b30(app, cpu);
    if (cpu.terminate) return;
L_0x00484bf0:
    // 00484bf0  8b4970                 -mov ecx, dword ptr [ecx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 00484bf3  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00484bf9  e8ce3effff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00484bfe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c00  e8c73effff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00484c05  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484c07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484c09  75e5                   -jne 0x484bf0
    if (!cpu.flags.zf)
    {
        goto L_0x00484bf0;
    }
    // 00484c0b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00484c0d  892d28a04c00           -mov dword ptr [0x4ca028], ebp
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.ebp;
    // 00484c13  892d24a04c00           -mov dword ptr [0x4ca024], ebp
    app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */) = cpu.ebp;
    // 00484c19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484c21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484c22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484c23  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484c25  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00484c27  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00484c29  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484c2d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00484c33  e8d0a3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00484c38  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484c3a  e8c51c0000             -call 0x486904
    cpu.esp -= 4;
    sub_486904(app, cpu);
    if (cpu.terminate) return;
    // 00484c3f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484c41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c43  746a                   -je 0x484caf
    if (cpu.flags.zf)
    {
        goto L_0x00484caf;
    }
    // 00484c45  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00484c4a  e8ad57ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 00484c4f  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00484c56  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00484c5c  89a990000000           -mov dword ptr [ecx + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 00484c62  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c66  7456                   -je 0x484cbe
    if (cpu.flags.zf)
    {
        goto L_0x00484cbe;
    }
    // 00484c68  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00484c6b  898898000000           -mov dword ptr [eax + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00484c71  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
L_0x00484c74:
    // 00484c74  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 00484c79  740d                   -je 0x484c88
    if (cpu.flags.zf)
    {
        goto L_0x00484c88;
    }
    // 00484c7b  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c7f  7507                   -jne 0x484c88
    if (!cpu.flags.zf)
    {
        goto L_0x00484c88;
    }
    // 00484c81  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00484c88:
    // 00484c88  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00484c8e  e88da3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00484c93  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00484c99  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00484c9f  e83ca2ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00484ca4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00484ca9:
    // 00484ca9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484caa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cac  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00484caf:
    // 00484caf  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00484cb5  e866a3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00484cba  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484cbc  ebeb                   -jmp 0x484ca9
    goto L_0x00484ca9;
L_0x00484cbe:
    // 00484cbe  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00484cc1  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00484cc4  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00484cc7  ebab                   -jmp 0x484c74
    goto L_0x00484c74;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484ccc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ccc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ccd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484cce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484ccf  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484cd2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484cd4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00484cd6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00484cd8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00484cdb  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484cdf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00484ce5  e81ea3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00484cea  837e7800               +cmp dword ptr [esi + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484cee  7418                   -je 0x484d08
    if (cpu.flags.zf)
    {
        goto L_0x00484d08;
    }
L_0x00484cf0:
    // 00484cf0  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00484cf3  8b9098000000           -mov edx, dword ptr [eax + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00484cf9  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00484cfc  e8231b0000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 00484d01  837e7800               +cmp dword ptr [esi + 0x78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d05  75e9                   -jne 0x484cf0
    if (!cpu.flags.zf)
    {
        goto L_0x00484cf0;
    }
    // 00484d07  90                     -nop 
    ;
L_0x00484d08:
    // 00484d08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484d0a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00484d0f  e8f01b0000             -call 0x486904
    cpu.esp -= 4;
    sub_486904(app, cpu);
    if (cpu.terminate) return;
    // 00484d14  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00484d16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484d18  e8df56ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 00484d1d  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00484d24  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00484d27  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00484d2d  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00484d33  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00484d36  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00484d39  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00484d3c  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d40  740d                   -je 0x484d4f
    if (cpu.flags.zf)
    {
        goto L_0x00484d4f;
    }
    // 00484d42  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d46  7507                   -jne 0x484d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00484d4f;
    }
    // 00484d48  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00484d4f:
    // 00484d4f  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00484d55  e8c6a2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00484d5a  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00484d60  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00484d66  e875a1ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00484d6b  83ff0b                 +cmp edi, 0xb
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d6e  7418                   -je 0x484d88
    if (cpu.flags.zf)
    {
        goto L_0x00484d88;
    }
    // 00484d70  83ff0d                 +cmp edi, 0xd
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d73  7413                   -je 0x484d88
    if (cpu.flags.zf)
    {
        goto L_0x00484d88;
    }
    // 00484d75  83ff14                 +cmp edi, 0x14
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d78  740e                   -je 0x484d88
    if (cpu.flags.zf)
    {
        goto L_0x00484d88;
    }
    // 00484d7a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484d7f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484d82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d85  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00484d88:
    // 00484d88  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 00484d8e  e889a1ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00484d93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484d98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484d9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d9e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484da4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484da4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484da5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484da6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484da8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00484dad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484daf  e818ffffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484db4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484db5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484db6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484db8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484db9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484dba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484dbc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00484dc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484dc3  e804ffffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484dc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484dcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484dcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484dce  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484dd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484dd2  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00484dd7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484dd9  e842feffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484dde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ddf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484de0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484de4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484de4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484de5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484de6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484de8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484dea  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00484def  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484df1  e82afeffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484dfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484dfe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484e00  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00484e05  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e07  e8c0feffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484e0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e14  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00484e19  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e1b  e8acfeffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484e20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484e28  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00484e2d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e2f  e898feffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484e34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e3a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e3c  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00484e41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e43  e884feffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484e48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e4e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484e50  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e52  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00484e57  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e59  e8c2fdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484e5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484e64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e66  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e68  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e6a  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00484e6f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e71  e8aafdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484e76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e7e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484e80  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00484e85  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e87  e840feffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484e8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e92  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484e94  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00484e99  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e9b  e82cfeffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484ea0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ea1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484ea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ea4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484ea5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ea6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484ea8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00484ead  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484eaf  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484eb1  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484eb6  e865fdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484ebb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ebc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ebd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ec2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484ec4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00484ec9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484ecb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484ecd  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484ed2  e849fdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484ed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ed8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ed9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484edc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484edc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484edd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ede  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484ee0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00484ee5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484ee7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484ee9  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484eee  e82dfdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484ef3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ef8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484ef9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484efa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484efc  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00484f01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484f03  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484f05  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484f0a  e811fdffff             -call 0x484c20
    cpu.esp -= 4;
    sub_484c20(app, cpu);
    if (cpu.terminate) return;
    // 00484f0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484f16  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484f18  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00484f1d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484f1f  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484f24  e8a3fdffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484f2e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484f30  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00484f35  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484f37  ba44e94b00             -mov edx, 0x4be944
    cpu.edx = 4974916 /*0x4be944*/;
    // 00484f3c  e88bfdffff             -call 0x484ccc
    cpu.esp -= 4;
    sub_484ccc(app, cpu);
    if (cpu.terminate) return;
    // 00484f41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484f46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484f47  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484f49  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484f4b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00484f51  e8b2a0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00484f56  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 00484f5a  7418                   -je 0x484f74
    if (cpu.flags.zf)
    {
        goto L_0x00484f74;
    }
L_0x00484f5c:
    // 00484f5c  41                     -inc ecx
    (cpu.ecx)++;
    // 00484f5d  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00484f60  8b9898000000           -mov ebx, dword ptr [eax + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00484f66  895a78                 -mov dword ptr [edx + 0x78], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.ebx;
    // 00484f69  e8b6180000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 00484f6e  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 00484f72  75e8                   -jne 0x484f5c
    if (!cpu.flags.zf)
    {
        goto L_0x00484f5c;
    }
L_0x00484f74:
    // 00484f74  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00484f77  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00484f7a  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00484f80  e89ba0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00484f85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484f87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484f8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f8e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484f90  8bb084000000           -mov esi, dword ptr [eax + 0x84]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00484f96  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 00484f99  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 00484f9f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00484fa2  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 00484fa8  8bb884000000           -mov edi, dword ptr [eax + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00484fae  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484fb0  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00484fb3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00484fb6  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00484fb9  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484fbc  897014                 -mov dword ptr [eax + 0x14], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00484fbf  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484fc2  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00484fc5  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484fc8  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00484fcb  c780bc00000000000000   -mov dword ptr [eax + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 00484fd5  8bb0bc000000           -mov esi, dword ptr [eax + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 00484fdb  89b0b8000000           -mov dword ptr [eax + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 00484fe1  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00484fe8  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00484fef  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 00484ff6  c7405401000000         -mov dword ptr [eax + 0x54], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 1 /*0x1*/;
    // 00484ffd  89586c                 -mov dword ptr [eax + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 00485000  895068                 -mov dword ptr [eax + 0x68], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00485003  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485009  8b9aac000000           -mov ebx, dword ptr [edx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048500f  8998ac000000           -mov dword ptr [eax + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 00485015  8b9aa8000000           -mov ebx, dword ptr [edx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048501b  8998a8000000           -mov dword ptr [eax + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 00485021  8db88c000000           -lea edi, [eax + 0x8c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00485027  8db28c000000           -lea esi, [edx + 0x8c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 0048502d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048502e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048502f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485030  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485031  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485032  8b9aa4000000           -mov ebx, dword ptr [edx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00485038  8998a4000000           -mov dword ptr [eax + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0048503e  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00485044  e8bf9fffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485049  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048504e  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 00485052  740c                   -je 0x485060
    if (cpu.flags.zf)
    {
        goto L_0x00485060;
    }
L_0x00485054:
    // 00485054  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00485057  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048505b  75f7                   -jne 0x485054
    if (!cpu.flags.zf)
    {
        goto L_0x00485054;
    }
    // 0048505d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00485060:
    // 00485060  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00485063  c7417000000000         -mov dword ptr [ecx + 0x70], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048506a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048506f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485075  e8a69fffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048507a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048507c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048507d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048507e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485080  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485081  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485082  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485083  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485086  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00485089  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048508b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048508d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048508f  66f7c3ff0f             +test bx, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & 4095 /*0xfff*/));
    // 00485094  740c                   -je 0x4850a2
    if (cpu.flags.zf)
    {
        goto L_0x004850a2;
    }
    // 00485096  8d8b00100000           -lea ecx, [ebx + 0x1000]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4096) /* 0x1000 */);
    // 0048509c  81e100f0ff7f           -and ecx, 0x7ffff000
    cpu.ecx &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x004850a2:
    // 004850a2  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004850a7  b888e84b00             -mov eax, 0x4be888
    cpu.eax = 4974728 /*0x4be888*/;
    // 004850ac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004850ae  e8cd35ffff             -call 0x478680
    cpu.esp -= 4;
    sub_478680(app, cpu);
    if (cpu.terminate) return;
    // 004850b3  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004850b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004850ba  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004850bc  b848e94b00             -mov eax, 0x4be948
    cpu.eax = 4974920 /*0x4be948*/;
    // 004850c1  e8a235ffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004850c6  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004850cb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004850cd  e80aa0ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 004850d2  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
    // 004850d8  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 004850de  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004850e3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004850e5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004850e7  e854bd0000             -call 0x490e40
    cpu.esp -= 4;
    sub_490e40(app, cpu);
    if (cpu.terminate) return;
    // 004850ec  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 004850f1  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004850f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004850f8  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 004850fd  e83ebd0000             -call 0x490e40
    cpu.esp -= 4;
    sub_490e40(app, cpu);
    if (cpu.terminate) return;
    // 00485102  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00485105  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00485107  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485109  e87efeffff             -call 0x484f8c
    cpu.esp -= 4;
    sub_484f8c(app, cpu);
    if (cpu.terminate) return;
    // 0048510e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485111  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485114  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00485168  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485169  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048516a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048516b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048516c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048516d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048516e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485171  e8569dffff             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00485176  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048517c  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00485182  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00485188  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048518a  e8519dffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 0048518f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00485194  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
  [[fallthrough]];
  case 0x00485196:
L_0x00485196:
    // 00485196  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048519b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004851a1  e8629effff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004851a6  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004851ab  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004851ae  83fa08                 +cmp edx, 8
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
    // 004851b1  0f848f000000           -je 0x485246
    if (cpu.flags.zf)
    {
        goto L_0x00485246;
    }
    // 004851b7  8378240f               +cmp dword ptr [eax + 0x24], 0xf
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
    // 004851bb  7507                   -jne 0x4851c4
    if (!cpu.flags.zf)
    {
        goto L_0x004851c4;
    }
    // 004851bd  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x004851c4:
    // 004851c4  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004851c9  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004851cc  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004851d2  e8499effff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004851d7  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004851dc  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004851df  4a                     -dec edx
    (cpu.edx)--;
    // 004851e0  83fa13                 +cmp edx, 0x13
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
    // 004851e3  77b1                   -ja 0x485196
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 004851e5  ff249518514800         -jmp dword ptr [edx*4 + 0x485118]
    cpu.ip = app->getMemory<x86::reg32>(4739352 + cpu.edx * 4); goto dynamic_jump;
  case 0x004851ec:
    // 004851ec  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004851f1  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004851f4  7408                   -je 0x4851fe
    if (cpu.flags.zf)
    {
        goto L_0x004851fe;
    }
    // 004851f6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004851f9  e84e6c0100             -call 0x49be4c
    cpu.esp -= 4;
    sub_49be4c(app, cpu);
    if (cpu.terminate) return;
L_0x004851fe:
    // 004851fe  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485200  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485201  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485206  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 00485209  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048520c  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048520f  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00485215  e8066c0100             -call 0x49be20
    cpu.esp -= 4;
    sub_49be20(app, cpu);
    if (cpu.terminate) return;
    // 0048521a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048521c  0f8539010000           -jne 0x48535b
    if (!cpu.flags.zf)
    {
        goto L_0x0048535b;
    }
L_0x00485222:
    // 00485222  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485227  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048522d  e8f2150000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 00485232  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485237  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0048523a  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00485241  e950ffffff             -jmp 0x485196
    goto L_0x00485196;
L_0x00485246:
    // 00485246  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00485249  e976ffffff             -jmp 0x4851c4
    goto L_0x004851c4;
  case 0x0048524e:
    // 0048524e  e8a9120000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485253  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485258  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048525b  752e                   -jne 0x48528b
    if (!cpu.flags.zf)
    {
        goto L_0x0048528b;
    }
    // 0048525d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485260  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485262  e8c914fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485267  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048526c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485272  e8a59cffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485277  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048527c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048527f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485281  e8aa14fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485286  e90bffffff             -jmp 0x485196
    goto L_0x00485196;
L_0x0048528b:
    // 0048528b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485291  e8729dffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485296  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048529c  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048529f  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004852a2  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 004852a8  895178                 -mov dword ptr [ecx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004852ab  898180000000           -mov dword ptr [ecx + 0x80], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004852b1  8b5978                 -mov ebx, dword ptr [ecx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 004852b4  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004852b6  7503                   -jne 0x4852bb
    if (!cpu.flags.zf)
    {
        goto L_0x004852bb;
    }
    // 004852b8  89597c                 -mov dword ptr [ecx + 0x7c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.ebx;
L_0x004852bb:
    // 004852bb  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004852c1  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004852c7  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004852ca  8b4a50                 -mov ecx, dword ptr [edx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004852cd  8bb090000000           -mov esi, dword ptr [eax + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */);
    // 004852d3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004852d5  894a60                 -mov dword ptr [edx + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 004852d8  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004852de  83fa0d                 +cmp edx, 0xd
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
    // 004852e1  7515                   -jne 0x4852f8
    if (!cpu.flags.zf)
    {
        goto L_0x004852f8;
    }
L_0x004852e3:
    // 004852e3  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004852e8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004852ee  e82d9dffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004852f3  e99efeffff             -jmp 0x485196
    goto L_0x00485196;
L_0x004852f8:
    // 004852f8  83fa14                 +cmp edx, 0x14
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
    // 004852fb  74e6                   -je 0x4852e3
    if (cpu.flags.zf)
    {
        goto L_0x004852e3;
    }
    // 004852fd  39d7                   +cmp edi, edx
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
    // 004852ff  74e2                   -je 0x4852e3
    if (cpu.flags.zf)
    {
        goto L_0x004852e3;
    }
    // 00485301  83fa11                 +cmp edx, 0x11
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
    // 00485304  74dd                   -je 0x4852e3
    if (cpu.flags.zf)
    {
        goto L_0x004852e3;
    }
    // 00485306  83fa12                 +cmp edx, 0x12
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
    // 00485309  74d8                   -je 0x4852e3
    if (cpu.flags.zf)
    {
        goto L_0x004852e3;
    }
    // 0048530b  83fa13                 +cmp edx, 0x13
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
    // 0048530e  74d3                   -je 0x4852e3
    if (cpu.flags.zf)
    {
        goto L_0x004852e3;
    }
    // 00485310  e80f150000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 00485315  ebcc                   -jmp 0x4852e3
    goto L_0x004852e3;
  case 0x00485317:
    // 00485317  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 0048531b  7534                   -jne 0x485351
    if (!cpu.flags.zf)
    {
        goto L_0x00485351;
    }
L_0x0048531d:
    // 0048531d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485322  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00485329  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048532f  e8749cffff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00485334  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048533a  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 00485340  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485342  e8999bffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00485347  83c404                 +add esp, 4
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
    // 0048534a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485350  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485351:
    // 00485351  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485354  e8f36a0100             -call 0x49be4c
    cpu.esp -= 4;
    sub_49be4c(app, cpu);
    if (cpu.terminate) return;
    // 00485359  ebc2                   -jmp 0x48531d
    goto L_0x0048531d;
L_0x0048535b:
    // 0048535b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485360  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00485366  e8b9140000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 0048536b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485370  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485376  e88d9cffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048537b  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485381  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485384  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 00485387  7e67                   -jle 0x4853f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004853f0;
    }
    // 00485389  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0048538f:
    // 0048538f  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00485392  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485397  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048539a  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0048539d  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004853a0  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004853a3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004853a5  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004853a8  3b7820                 +cmp edi, dword ptr [eax + 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004853ab  7567                   -jne 0x485414
    if (!cpu.flags.zf)
    {
        goto L_0x00485414;
    }
L_0x004853ad:
    // 004853ad  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004853b2  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004853b5  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004853b8  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x004853be:
    // 004853be  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004853c3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004853c6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004853c9  83782013               +cmp dword ptr [eax + 0x20], 0x13
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
    // 004853cd  754d                   -jne 0x48541c
    if (!cpu.flags.zf)
    {
        goto L_0x0048541c;
    }
L_0x004853cf:
    // 004853cf  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004853d4  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x004853db:
    // 004853db  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004853e0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004853e6  e8359cffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004853eb  e9a6fdffff             -jmp 0x485196
    goto L_0x00485196;
L_0x004853f0:
    // 004853f0  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004853f3  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004853f6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004853f9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004853fc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004853fe  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00485404  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485406  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0048540c  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048540f  e97bffffff             -jmp 0x48538f
    goto L_0x0048538f;
L_0x00485414:
    // 00485414  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 00485418  7493                   -je 0x4853ad
    if (cpu.flags.zf)
    {
        goto L_0x004853ad;
    }
    // 0048541a  eba2                   -jmp 0x4853be
    goto L_0x004853be;
L_0x0048541c:
    // 0048541c  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 00485420  74ad                   -je 0x4853cf
    if (cpu.flags.zf)
    {
        goto L_0x004853cf;
    }
    // 00485422  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 00485429  ebb0                   -jmp 0x4853db
    goto L_0x004853db;
  case 0x0048542b:
    // 0048542b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485430  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485433  7408                   -je 0x48543d
    if (cpu.flags.zf)
    {
        goto L_0x0048543d;
    }
    // 00485435  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485438  e80f6a0100             -call 0x49be4c
    cpu.esp -= 4;
    sub_49be4c(app, cpu);
    if (cpu.terminate) return;
L_0x0048543d:
    // 0048543d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048543f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485440  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485445  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 00485448  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048544b  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048544e  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00485454  e8c7690100             -call 0x49be20
    cpu.esp -= 4;
    sub_49be20(app, cpu);
    if (cpu.terminate) return;
    // 00485459  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048545b  0f84c1fdffff           -je 0x485222
    if (cpu.flags.zf)
    {
        goto L_0x00485222;
    }
    // 00485461  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485466  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048546c  e8b3130000             -call 0x486824
    cpu.esp -= 4;
    sub_486824(app, cpu);
    if (cpu.terminate) return;
    // 00485471  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485476  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048547c  e8879bffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485481  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485487  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048548a  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048548d  0f8eb8010000           -jle 0x48564b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048564b;
    }
    // 00485493  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x00485499:
    // 00485499  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048549c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004854a1  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004854a4  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004854a7  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004854aa  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004854ad  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004854af  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004854b2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004854b8  e8639bffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004854bd:
    // 004854bd  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004854c2  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 004854c7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004854cd  e8369bffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004854d2  3b2d28a04c00           +cmp ebp, dword ptr [0x4ca028]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004854d8  743b                   -je 0x485515
    if (cpu.flags.zf)
    {
        goto L_0x00485515;
    }
L_0x004854da:
    // 004854da  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004854df  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004854e2  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004854e5  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004854e8  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004854eb  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004854ee  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004854f1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004854f4  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004854f7  89a8bc000000           -mov dword ptr [eax + 0xbc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 004854fd  8b90bc000000           -mov edx, dword ptr [eax + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 00485503  8990b8000000           -mov dword ptr [eax + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 00485509  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048550c  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 00485511  39c5                   +cmp ebp, eax
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
    // 00485513  75c5                   -jne 0x4854da
    if (!cpu.flags.zf)
    {
        goto L_0x004854da;
    }
L_0x00485515:
    // 00485515  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048551a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485520  e8fb9affff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00485525  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048552a  83782014               +cmp dword ptr [eax + 0x20], 0x14
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
    // 0048552e  0f843b010000           -je 0x48566f
    if (cpu.flags.zf)
    {
        goto L_0x0048566f;
    }
    // 00485534  c7402002000000         -mov dword ptr [eax + 0x20], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0048553b  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00485541  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485543  e89899ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00485548:
    // 00485548  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048554d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485553  e8b09affff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485558  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048555d  83782002               +cmp dword ptr [eax + 0x20], 2
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
    // 00485561  0f8521010000           -jne 0x485688
    if (!cpu.flags.zf)
    {
        goto L_0x00485688;
    }
    // 00485567  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048556a  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048556d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485570  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485573  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x00485579:
    // 00485579  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048557e  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00485581  89505c                 -mov dword ptr [eax + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 00485584  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048558a  e8919affff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048558f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485594  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 00485597  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048559a  e83d690100             -call 0x49bedc
    cpu.esp -= 4;
    sub_49bedc(app, cpu);
    if (cpu.terminate) return;
    // 0048559f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004855a1  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004855a6  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004855ac  e8579affff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004855b1  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004855b6  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004855b9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004855bb  8988b0000000           -mov dword ptr [eax + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 004855c1  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004855c4  8b88b0000000           -mov ecx, dword ptr [eax + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 004855ca  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004855cc  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004855cf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004855d5  e8469affff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004855da  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004855e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004855e2  e8150f0000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 004855e7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004855ea  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004855ed  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 004855f0  0f8f4e010000           -jg 0x485744
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485744;
    }
L_0x004855f6:
    // 004855f6  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004855fc  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855ff  0f858e000000           -jne 0x485693
    if (!cpu.flags.zf)
    {
        goto L_0x00485693;
    }
    // 00485605  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485607  e8f00e0000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 0048560c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048560f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00485612  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00485614  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485616  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048561b  e8500f0000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485620  39c2                   +cmp edx, eax
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
    // 00485622  746f                   -je 0x485693
    if (cpu.flags.zf)
    {
        goto L_0x00485693;
    }
    // 00485624  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485629  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048562f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485632  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485634  e8f710fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485639  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048563e  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485644  e8d398ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485649  ebab                   -jmp 0x4855f6
    goto L_0x004855f6;
L_0x0048564b:
    // 0048564b  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048564e  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00485651  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00485654  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485657  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485659  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048565f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485661  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00485667  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048566a  e92afeffff             -jmp 0x485499
    goto L_0x00485499;
L_0x0048566f:
    // 0048566f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00485676  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048567c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048567e  e85d98ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00485683  e90efbffff             -jmp 0x485196
    goto L_0x00485196;
L_0x00485688:
    // 00485688  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048568b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048568e  e9e6feffff             -jmp 0x485579
    goto L_0x00485579;
L_0x00485693:
    // 00485693  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485698  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048569e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004856a1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004856a3  e88810fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004856a8  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004856ad  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856b0  0f85e0faffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x004856b6:
    // 004856b6  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004856bb  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856be  7531                   -jne 0x4856f1
    if (!cpu.flags.zf)
    {
        goto L_0x004856f1;
    }
    // 004856c0  e8eb0e0000             -call 0x4865b0
    cpu.esp -= 4;
    sub_4865b0(app, cpu);
    if (cpu.terminate) return;
    // 004856c5  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004856c8  7f27                   -jg 0x4856f1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004856f1;
    }
    // 004856ca  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004856cf  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004856d5  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004856d8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004856da  e85110fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004856df  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004856e4  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004856ea  e82d98ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004856ef  ebc5                   -jmp 0x4856b6
    goto L_0x004856b6;
L_0x004856f1:
    // 004856f1  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004856f6  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004856fc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004856ff  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485701  e82a10fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485706  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048570b  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048570e  0f8582faffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00485714  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048571a  e8e998ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048571f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485724  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485727  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048572d  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00485730  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00485733  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485736  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485739  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048573f  e8dc98ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00485744:
    // 00485744  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048574a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048574d  7533                   -jne 0x485782
    if (!cpu.flags.zf)
    {
        goto L_0x00485782;
    }
    // 0048574f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485751  e81a0e0000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485756  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 00485759  7f27                   -jg 0x485782
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485782;
    }
    // 0048575b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485760  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485766  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485769  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048576b  e8c00ffcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485770  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485775  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048577b  e89c97ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485780  ebc2                   -jmp 0x485744
    goto L_0x00485744;
L_0x00485782:
    // 00485782  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485787  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048578d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485790  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485792  e8990ffcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485797  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048579c  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048579f  0f85f1f9ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x004857a5:
    // 004857a5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004857aa  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004857b0  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004857b3  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004857b6  e8f1660100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 004857bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857bd  7509                   -jne 0x4857c8
    if (!cpu.flags.zf)
    {
        goto L_0x004857c8;
    }
    // 004857bf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004857c1  e89694ffff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 004857c6  ebdd                   -jmp 0x4857a5
    goto L_0x004857a5;
L_0x004857c8:
    // 004857c8  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004857cd  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004857d3  e83098ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004857d8  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004857dd  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004857e0  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004857e3  3ba8b0000000           +cmp ebp, dword ptr [eax + 0xb0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004857e9  7416                   -je 0x485801
    if (cpu.flags.zf)
    {
        goto L_0x00485801;
    }
    // 004857eb  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004857ee  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004857f1  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004857f4  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 004857fa  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004857fc  e84fafffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x00485801:
    // 00485801  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485806  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485809  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048580c  c7402003000000         -mov dword ptr [eax + 0x20], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 00485813  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485819  e80298ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048581e:
    // 0048581e  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485824  837a4c08               +cmp dword ptr [edx + 0x4c], 8
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
    // 00485828  0f83ed010000           -jae 0x485a1b
    if (!cpu.flags.cf)
    {
        goto L_0x00485a1b;
    }
    // 0048582e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485830  e8c70c0000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485835  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485838  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048583b  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048583e  0f8f21010000           -jg 0x485965
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485965;
    }
L_0x00485844:
    // 00485844  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048584a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048584d  7546                   -jne 0x485895
    if (!cpu.flags.zf)
    {
        goto L_0x00485895;
    }
    // 0048584f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485851  e8a60c0000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485856  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00485859  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048585c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048585e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485860  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485865  e8060d0000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 0048586a  39c2                   +cmp edx, eax
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
    // 0048586c  7427                   -je 0x485895
    if (cpu.flags.zf)
    {
        goto L_0x00485895;
    }
    // 0048586e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485873  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485879  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048587c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048587e  e8ad0efcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485883  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485888  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048588e  e88996ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485893  ebaf                   -jmp 0x485844
    goto L_0x00485844;
L_0x00485895:
    // 00485895  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048589a  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004858a0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004858a3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004858a5  e8860efcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004858aa  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004858af  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004858b2  0f85def8ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x004858b8:
    // 004858b8  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004858be  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004858c1  7536                   -jne 0x4858f9
    if (!cpu.flags.zf)
    {
        goto L_0x004858f9;
    }
    // 004858c3  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004858c8  e8e30c0000             -call 0x4865b0
    cpu.esp -= 4;
    sub_4865b0(app, cpu);
    if (cpu.terminate) return;
    // 004858cd  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 004858d0  7f27                   -jg 0x4858f9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004858f9;
    }
    // 004858d2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004858d7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004858dd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004858e0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004858e2  e8490efcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004858e7  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004858ec  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004858f2  e82596ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004858f7  ebbf                   -jmp 0x4858b8
    goto L_0x004858b8;
L_0x004858f9:
    // 004858f9  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004858fe  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485904  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485907  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485909  e8220efcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 0048590e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485913  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485916  0f857af8ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 0048591c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485922  e8e196ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485927  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048592c  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048592f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00485932  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485935  e816aeffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048593a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048593f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485942  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00485948  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048594b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048594e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485951  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485954  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485957  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048595a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485960  e8bb96ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00485965:
    // 00485965  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048596b  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048596e  7533                   -jne 0x4859a3
    if (!cpu.flags.zf)
    {
        goto L_0x004859a3;
    }
    // 00485970  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485972  e8f90b0000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485977  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048597a  7f27                   -jg 0x4859a3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004859a3;
    }
    // 0048597c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485981  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485987  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048598a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048598c  e89f0dfcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485991  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485996  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048599c  e87b95ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004859a1  ebc2                   -jmp 0x485965
    goto L_0x00485965;
L_0x004859a3:
    // 004859a3  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004859a8  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004859ae  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004859b1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004859b3  e8780dfcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004859b8  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004859bd  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004859c0  0f85d0f7ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x004859c6:
    // 004859c6  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004859cb  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004859d1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004859d4  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004859d7  e8d0640100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 004859dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004859de  7509                   -jne 0x4859e9
    if (!cpu.flags.zf)
    {
        goto L_0x004859e9;
    }
    // 004859e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004859e2  e87592ffff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 004859e7  ebdd                   -jmp 0x4859c6
    goto L_0x004859c6;
L_0x004859e9:
    // 004859e9  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004859ee  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004859f4  e80f96ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004859f9  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004859fe  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00485a01  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485a04  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00485a07  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485a0a  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00485a0d  01504c                 -add dword ptr [eax + 0x4c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485a10  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485a16  e80596ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00485a1b:
    // 00485a1b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485a20  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485a23  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00485a28  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485a2a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00485a2c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485a2e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485a35  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485a37  3d6c454353             +cmp eax, 0x5343456c
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
    // 00485a3c  7516                   -jne 0x485a54
    if (!cpu.flags.zf)
    {
        goto L_0x00485a54;
    }
    // 00485a3e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485a43  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485a46  740c                   -je 0x485a54
    if (cpu.flags.zf)
    {
        goto L_0x00485a54;
    }
    // 00485a48  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00485a4f  e942f7ffff             -jmp 0x485196
    goto L_0x00485196;
L_0x00485a54:
    // 00485a54  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485a59  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485a5f  e8a495ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485a64  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485a69  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485a6c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00485a6f  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00485a72  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485a75  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485a78  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485a7a  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 00485a7d  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00485a80  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 00485a85  39c5                   +cmp ebp, eax
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
    // 00485a87  742f                   -je 0x485ab8
    if (cpu.flags.zf)
    {
        goto L_0x00485ab8;
    }
L_0x00485a89:
    // 00485a89  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485a8e  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485a91  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00485a96  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485a98  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00485a9a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485a9c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485aa3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485aa5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485aa7  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485aac  23506c                 -and edx, dword ptr [eax + 0x6c]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */)));
    // 00485aaf  3b5068                 +cmp edx, dword ptr [eax + 0x68]
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
    // 00485ab2  0f85a3000000           -jne 0x485b5b
    if (!cpu.flags.zf)
    {
        goto L_0x00485b5b;
    }
L_0x00485ab8:
    // 00485ab8  3b2d28a04c00           +cmp ebp, dword ptr [0x4ca028]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485abe  750a                   -jne 0x485aca
    if (!cpu.flags.zf)
    {
        goto L_0x00485aca;
    }
    // 00485ac0  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ac5  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
L_0x00485aca:
    // 00485aca  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485acf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485ad5  e84695ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00485ada  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ae0  83794808               +cmp dword ptr [ecx + 0x48], 8
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
    // 00485ae4  0f8386000000           -jae 0x485b70
    if (!cpu.flags.cf)
    {
        goto L_0x00485b70;
    }
L_0x00485aea:
    // 00485aea  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485aef  3b682c                 +cmp ebp, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485af2  0f8594000000           -jne 0x485b8c
    if (!cpu.flags.zf)
    {
        goto L_0x00485b8c;
    }
    // 00485af8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485afe  e80595ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485b03  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485b08  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
L_0x00485b0d:
    // 00485b0d  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485b12  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485b15  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 00485b18  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00485b1a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485b1d  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 00485b24  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00485b28  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485b2b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485b2e  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00485b31  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 00485b36  39c5                   +cmp ebp, eax
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
    // 00485b38  75d3                   -jne 0x485b0d
    if (!cpu.flags.zf)
    {
        goto L_0x00485b0d;
    }
    // 00485b3a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485b3f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485b45  e8d694ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00485b4a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485b4f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00485b56  e93bf6ffff             -jmp 0x485196
    goto L_0x00485196;
L_0x00485b5b:
    // 00485b5b  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00485b5e  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 00485b63  39c5                   +cmp ebp, eax
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
    // 00485b65  0f851effffff           -jne 0x485a89
    if (!cpu.flags.zf)
    {
        goto L_0x00485a89;
    }
    // 00485b6b  e948ffffff             -jmp 0x485ab8
    goto L_0x00485ab8;
L_0x00485b70:
    // 00485b70  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485b76  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 00485b79  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 00485b7c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485b7f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00485b81  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00485b83  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
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
    // 00485b86  0f8c5effffff           -jl 0x485aea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485aea;
    }
L_0x00485b8c:
    // 00485b8c  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485b91  8b1d24a04c00           -mov ebx, dword ptr [0x4ca024]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485b97  39d8                   +cmp eax, ebx
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
    // 00485b99  0f848e030000           -je 0x485f2d
    if (cpu.flags.zf)
    {
        goto L_0x00485f2d;
    }
    // 00485b9f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00485ba1  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00485ba4  034340                 -add eax, dword ptr [ebx + 0x40]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */)));
    // 00485ba7  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485bad  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485bb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485bb2  e845090000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485bb7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485bba  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00485bbd  39c8                   +cmp eax, ecx
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
    // 00485bbf  0f877a010000           -ja 0x485d3f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485d3f;
    }
L_0x00485bc5:
    // 00485bc5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485bca  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485bcd  754a                   -jne 0x485c19
    if (!cpu.flags.zf)
    {
        goto L_0x00485c19;
    }
    // 00485bcf  8b0d28a04c00           -mov ecx, dword ptr [0x4ca028]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485bd5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485bd7  e820090000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485bdc  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00485bdf  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00485be2  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485be7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485be9  e882090000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485bee  39c2                   +cmp edx, eax
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
    // 00485bf0  7427                   -je 0x485c19
    if (cpu.flags.zf)
    {
        goto L_0x00485c19;
    }
    // 00485bf2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485bf7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485bfd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485c00  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485c02  e8290bfcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485c07  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c0c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485c12  e80593ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485c17  ebac                   -jmp 0x485bc5
    goto L_0x00485bc5;
L_0x00485c19:
    // 00485c19  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c1e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485c24  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485c27  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485c29  e8020bfcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485c2e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c33  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c36  0f855af5ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x00485c3c:
    // 00485c3c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c41  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c44  7536                   -jne 0x485c7c
    if (!cpu.flags.zf)
    {
        goto L_0x00485c7c;
    }
    // 00485c46  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485c4b  e820090000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485c50  83f808                 +cmp eax, 8
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
    // 00485c53  7727                   -ja 0x485c7c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485c7c;
    }
    // 00485c55  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c5a  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485c60  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485c63  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485c65  e8c60afcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485c6a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c6f  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485c75  e8a292ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485c7a  ebc0                   -jmp 0x485c3c
    goto L_0x00485c3c;
L_0x00485c7c:
    // 00485c7c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c81  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485c87  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485c8a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485c8c  e89f0afcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485c91  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485c96  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c99  0f85f7f4ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x00485c9f:
    // 00485c9f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ca4  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485ca7  753e                   -jne 0x485ce7
    if (!cpu.flags.zf)
    {
        goto L_0x00485ce7;
    }
    // 00485ca9  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485cac  034840                 -add ecx, dword ptr [eax + 0x40]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 00485caf  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485cb4  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00485cb7  e8f4080000             -call 0x4865b0
    cpu.esp -= 4;
    sub_4865b0(app, cpu);
    if (cpu.terminate) return;
    // 00485cbc  39d0                   +cmp eax, edx
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
    // 00485cbe  7727                   -ja 0x485ce7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485ce7;
    }
    // 00485cc0  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485cc5  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485ccb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485cce  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485cd0  e85b0afcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485cd5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485cda  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485ce0  e83792ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485ce5  ebb8                   -jmp 0x485c9f
    goto L_0x00485c9f;
L_0x00485ce7:
    // 00485ce7  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485cec  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485cf2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485cf5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485cf7  e8340afcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485cfc  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d01  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485d04  0f858cf4ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00485d0a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485d10  e8f392ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485d15  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485d1a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485d1d  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 00485d23  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00485d26  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00485d29  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485d2c  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485d2f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d34  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485d3a  e8e192ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00485d3f:
    // 00485d3f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d44  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485d47  0f8f17010000           -jg 0x485e64
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485e64;
    }
L_0x00485d4d:
    // 00485d4d  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d53  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485d56  7536                   -jne 0x485d8e
    if (!cpu.flags.zf)
    {
        goto L_0x00485d8e;
    }
    // 00485d58  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485d5d  e80e080000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485d62  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 00485d65  7f27                   -jg 0x485d8e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485d8e;
    }
    // 00485d67  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d6c  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485d72  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485d75  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485d77  e8b409fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485d7c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d81  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485d87  e89091ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485d8c  ebbf                   -jmp 0x485d4d
    goto L_0x00485d4d;
L_0x00485d8e:
    // 00485d8e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485d93  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485d99  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485d9c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485d9e  e88d09fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485da3  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485da8  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485dab  0f85e5f3ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00485db1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485db7  e84c92ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485dbc  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485dc1  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485dc4  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485dca  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00485dcd  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485dd0  e87ba9ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00485dd5  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485ddb  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485de0  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00485de3  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485de6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00485de8  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00485deb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485dee  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485df1  89684c                 -mov dword ptr [eax + 0x4c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ebp;
L_0x00485df4:
    // 00485df4  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485dfa  e82192ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00485dff:
    // 00485dff  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e04  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e07  0f8c50010000           -jl 0x485f5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485f5d;
    }
L_0x00485e0d:
    // 00485e0d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e12  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e15  0f8d1f030000           -jge 0x48613a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048613a;
    }
L_0x00485e1b:
    // 00485e1b  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e21  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e24  0f858b020000           -jne 0x4860b5
    if (!cpu.flags.zf)
    {
        goto L_0x004860b5;
    }
    // 00485e2a  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485e2f  e83c070000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485e34  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 00485e37  0f8f78020000           -jg 0x4860b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004860b5;
    }
    // 00485e3d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e42  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485e48  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485e4b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485e4d  e8de08fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485e52  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e57  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485e5d  e8ba90ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485e62  ebb7                   -jmp 0x485e1b
    goto L_0x00485e1b;
L_0x00485e64:
    // 00485e64  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e6a  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e6d  7536                   -jne 0x485ea5
    if (!cpu.flags.zf)
    {
        goto L_0x00485ea5;
    }
    // 00485e6f  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485e74  e8f7060000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485e79  3b4248                 +cmp eax, dword ptr [edx + 0x48]
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
    // 00485e7c  7f27                   -jg 0x485ea5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485ea5;
    }
    // 00485e7e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e83  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485e89  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485e8c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485e8e  e89d08fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485e93  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485e98  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485e9e  e87990ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485ea3  ebbf                   -jmp 0x485e64
    goto L_0x00485e64;
L_0x00485ea5:
    // 00485ea5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485eaa  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485eb0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485eb3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485eb5  e87608fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485eba  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ebf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485ec2  0f85cef2ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00485ec8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00485ece  e83591ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00485ed3  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ed8  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485edb  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485ee1  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00485ee4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485ee7  e864a8ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00485eec  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485ef2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ef7  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00485efa  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485efd  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00485eff  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00485f02  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00485f05  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00485f07  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00485f0a  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00485f0d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485f10  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485f13  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485f16  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00485f18  e833a8ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00485f1d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485f22  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00485f25  29500c                 +sub dword ptr [eax + 0xc], edx
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
    // 00485f28  e9c7feffff             -jmp 0x485df4
    goto L_0x00485df4;
L_0x00485f2d:
    // 00485f2d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00485f30  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00485f35  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485f37  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00485f39  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485f3b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485f42  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485f44  3d6c454353             +cmp eax, 0x5343456c
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
    // 00485f49  7509                   -jne 0x485f54
    if (!cpu.flags.zf)
    {
        goto L_0x00485f54;
    }
    // 00485f4b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485f4d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485f4f  e9abfeffff             -jmp 0x485dff
    goto L_0x00485dff;
L_0x00485f54:
    // 00485f54  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485f56  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485f58  e9a2feffff             -jmp 0x485dff
    goto L_0x00485dff;
L_0x00485f5d:
    // 00485f5d  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00485f60  035040                 -add edx, dword ptr [eax + 0x40]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 00485f63  8d4a08                 -lea ecx, [edx + 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485f66  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485f6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485f6e  e889050000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485f73  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485f76  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00485f79  39c8                   +cmp eax, ecx
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
    // 00485f7b  0f878cfeffff           -ja 0x485e0d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485e0d;
    }
L_0x00485f81:
    // 00485f81  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485f86  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485f89  754a                   -jne 0x485fd5
    if (!cpu.flags.zf)
    {
        goto L_0x00485fd5;
    }
    // 00485f8b  8b0d28a04c00           -mov ecx, dword ptr [0x4ca028]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485f91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485f93  e864050000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00485f98  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00485f9b  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00485f9e  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00485fa3  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485fa5  e8c6050000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00485faa  39c2                   +cmp edx, eax
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
    // 00485fac  7427                   -je 0x485fd5
    if (cpu.flags.zf)
    {
        goto L_0x00485fd5;
    }
    // 00485fae  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485fb3  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00485fb9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485fbc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00485fbe  e86d07fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485fc3  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485fc8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00485fce  e8498fffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00485fd3  ebac                   -jmp 0x485f81
    goto L_0x00485f81;
L_0x00485fd5:
    // 00485fd5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485fda  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00485fe0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485fe3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485fe5  e84607fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00485fea  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485fef  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485ff2  0f859ef1ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x00485ff8:
    // 00485ff8  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00485ffe  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486001  7536                   -jne 0x486039
    if (!cpu.flags.zf)
    {
        goto L_0x00486039;
    }
    // 00486003  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486008  e8a3050000             -call 0x4865b0
    cpu.esp -= 4;
    sub_4865b0(app, cpu);
    if (cpu.terminate) return;
    // 0048600d  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 00486010  7f27                   -jg 0x486039
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00486039;
    }
    // 00486012  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486017  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048601d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00486020  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00486022  e80907fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486027  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048602c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00486032  e8e58effff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00486037  ebbf                   -jmp 0x485ff8
    goto L_0x00485ff8;
L_0x00486039:
    // 00486039  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048603e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00486044  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00486047  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00486049  e8e206fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 0048604e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486053  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486056  0f853af1ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 0048605c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486062  e8a18fffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00486067  8b1d24a04c00           -mov ebx, dword ptr [0x4ca024]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048606d  8b5b4c                 -mov ebx, dword ptr [ebx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 00486070  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486075  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486078  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048607b  e8d0a6ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00486080  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486085  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00486088  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048608e  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486094  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486097  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0048609a  01d9                   +add ecx, ebx
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
    // 0048609c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048609f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004860a2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004860a5  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 004860ab  e8708fffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004860b0  e958fdffff             -jmp 0x485e0d
    goto L_0x00485e0d;
L_0x004860b5:
    // 004860b5  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004860ba  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004860c0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004860c3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004860c5  e86606fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004860ca  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004860cf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004860d2  7566                   -jne 0x48613a
    if (!cpu.flags.zf)
    {
        goto L_0x0048613a;
    }
L_0x004860d4:
    // 004860d4  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004860d9  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004860df  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004860e5  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004860e8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004860eb  e8bc5d0100             -call 0x49beac
    cpu.esp -= 4;
    sub_49beac(app, cpu);
    if (cpu.terminate) return;
    // 004860f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004860f2  7509                   -jne 0x4860fd
    if (!cpu.flags.zf)
    {
        goto L_0x004860fd;
    }
    // 004860f4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004860f6  e8618bffff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 004860fb  ebd7                   -jmp 0x4860d4
    goto L_0x004860d4;
L_0x004860fd:
    // 004860fd  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486102  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486108  e8fb8effff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048610d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486112  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00486115  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486118  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 0048611e  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00486121  014a0c                 -add dword ptr [edx + 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486124  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00486127  295044                 +sub dword ptr [eax + 0x44], edx
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
    // 0048612a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486130  e8eb8effff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00486135  e9d3fcffff             -jmp 0x485e0d
    goto L_0x00485e0d;
L_0x0048613a:
    // 0048613a  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048613f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486142  0f854ef0ffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00486148  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048614e  e8b58effff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00486153  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486155  0f85bc000000           -jne 0x486217
    if (!cpu.flags.zf)
    {
        goto L_0x00486217;
    }
    // 0048615b  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486161  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486166  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00486169  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048616c  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048616f  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00486172  0188b8000000           -add dword ptr [eax + 0xb8], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486178  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048617e  e89d8effff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00486183  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486188  8b3524a04c00           -mov esi, dword ptr [0x4ca024]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048618e  39f0                   +cmp eax, esi
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
    // 00486190  0f849d020000           -je 0x486433
    if (cpu.flags.zf)
    {
        goto L_0x00486433;
    }
    // 00486196  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486198  3b6e4c                 +cmp ebp, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048619b  0f852a020000           -jne 0x4863cb
    if (!cpu.flags.zf)
    {
        goto L_0x004863cb;
    }
    // 004861a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004861a3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004861a6  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004861a9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004861ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004861ad  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004861af  e848030000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 004861b4  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004861b7  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004861ba  39c8                   +cmp eax, ecx
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
    // 004861bc  0f8f45010000           -jg 0x486307
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00486307;
    }
L_0x004861c2:
    // 004861c2  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004861c8  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004861cb  0f857a000000           -jne 0x48624b
    if (!cpu.flags.zf)
    {
        goto L_0x0048624b;
    }
    // 004861d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004861d3  e824030000             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 004861d8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004861db  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004861de  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004861e0  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004861e5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004861e7  e884030000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 004861ec  39c2                   +cmp edx, eax
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
    // 004861ee  745b                   -je 0x48624b
    if (cpu.flags.zf)
    {
        goto L_0x0048624b;
    }
    // 004861f0  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004861f5  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 004861fb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004861fe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00486200  e82b05fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486205  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048620a  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00486210  e8078dffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00486215  ebab                   -jmp 0x4861c2
    goto L_0x004861c2;
L_0x00486217:
    // 00486217  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048621d  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486222  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00486225  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486228  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048622b  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048622e  0188b8000000           +add dword ptr [eax + 0xb8], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486234  c7422007000000         -mov dword ptr [edx + 0x20], 7
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048623b  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00486241  e8da8dffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00486246  e94befffff             -jmp 0x485196
    goto L_0x00485196;
L_0x0048624b:
    // 0048624b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486250  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00486256  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00486259  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048625b  e8d004fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486260  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486265  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486268  0f8528efffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
L_0x0048626e:
    // 0048626e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486273  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486276  753c                   -jne 0x4862b4
    if (!cpu.flags.zf)
    {
        goto L_0x004862b4;
    }
    // 00486278  8b0d28a04c00           -mov ecx, dword ptr [0x4ca028]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 0048627e  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00486281  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 00486284  e827030000             -call 0x4865b0
    cpu.esp -= 4;
    sub_4865b0(app, cpu);
    if (cpu.terminate) return;
    // 00486289  39d0                   +cmp eax, edx
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
    // 0048628b  7f27                   -jg 0x4862b4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004862b4;
    }
    // 0048628d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486292  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00486298  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048629b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048629d  e88e04fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004862a2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004862a7  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 004862ad  e86a8cffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004862b2  ebba                   -jmp 0x48626e
    goto L_0x0048626e;
L_0x004862b4:
    // 004862b4  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004862b9  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 004862bf  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004862c2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004862c4  e86704fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 004862c9  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004862ce  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004862d1  0f85bfeeffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 004862d7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004862dd  e8268dffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004862e2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004862e7  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004862ea  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004862f0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004862f3  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004862f6  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004862f9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004862fc  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486302  e8198dffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00486307:
    // 00486307  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048630c  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048630f  753c                   -jne 0x48634d
    if (!cpu.flags.zf)
    {
        goto L_0x0048634d;
    }
    // 00486311  8b0d28a04c00           -mov ecx, dword ptr [0x4ca028]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486317  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048631a  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0048631d  e84e020000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00486322  39d0                   +cmp eax, edx
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
    // 00486324  7f27                   -jg 0x48634d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048634d;
    }
    // 00486326  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048632b  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00486331  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00486334  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00486336  e8f503fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 0048633b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486340  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 00486346  e8d18bffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 0048634b  ebba                   -jmp 0x486307
    goto L_0x00486307;
L_0x0048634d:
    // 0048634d  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486352  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00486358  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048635b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048635d  e8ce03fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486362  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486367  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048636a  0f8526eeffff           -jne 0x485196
    if (!cpu.flags.zf)
    {
        goto L_0x00485196;
    }
    // 00486370  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486376  e88d8cffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048637b  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486381  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00486384  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00486387  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486389  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048638b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486390  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 00486393  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00486396  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00486399  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048639c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048639e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004863a0  e8aba3ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 004863a5  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004863aa  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004863ad  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004863b0  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004863b5  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004863b8  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004863bb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004863bd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004863c0:
    // 004863c0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004863c6  e8558cffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x004863cb:
    // 004863cb  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004863d0  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004863d3  2b504c                 -sub edx, dword ptr [eax + 0x4c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
    // 004863d6  3b5054                 +cmp edx, dword ptr [eax + 0x54]
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
    // 004863d9  0f8cb7edffff           -jl 0x485196
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485196;
    }
    // 004863df  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863e2  0f85ec000000           -jne 0x4864d4
    if (!cpu.flags.zf)
    {
        goto L_0x004864d4;
    }
    // 004863e8  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
L_0x004863ed:
    // 004863ed  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004863f2  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863f5  7564                   -jne 0x48645b
    if (!cpu.flags.zf)
    {
        goto L_0x0048645b;
    }
    // 004863f7  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004863fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004863ff  e86c010000             -call 0x486570
    cpu.esp -= 4;
    sub_486570(app, cpu);
    if (cpu.terminate) return;
    // 00486404  03424c                 -add eax, dword ptr [edx + 0x4c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 00486407  83f808                 +cmp eax, 8
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
    // 0048640a  774f                   -ja 0x48645b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048645b;
    }
    // 0048640c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486411  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 00486417  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048641a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048641c  e80f03fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486421  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486426  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048642c  e8eb8affff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00486431  ebba                   -jmp 0x4863ed
    goto L_0x004863ed;
L_0x00486433:
    // 00486433  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00486439  e8ca8bffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048643e  8b1528a04c00           -mov edx, dword ptr [0x4ca028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 00486444  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00486447  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048644a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048644c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486451  29ca                   +sub edx, ecx
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
    // 00486453  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00486456  e965ffffff             -jmp 0x4863c0
    goto L_0x004863c0;
L_0x0048645b:
    // 0048645b  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486460  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00486466  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00486469  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048646b  e8c002fcff             -call 0x446730
    cpu.esp -= 4;
    sub_446730(app, cpu);
    if (cpu.terminate) return;
    // 00486470  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486475  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00486478  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048647a  7469                   -je 0x4864e5
    if (cpu.flags.zf)
    {
        goto L_0x004864e5;
    }
L_0x0048647c:
    // 0048647c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486481  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486487  e87c8bffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048648c  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486491  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
L_0x00486496:
    // 00486496  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 0048649b  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048649e  c702fdffffff           -mov dword ptr [edx], 0xfffffffd
    app->getMemory<x86::reg32>(cpu.edx) = 4294967293 /*0xfffffffd*/;
    // 004864a4  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004864a7  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004864ae  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004864b2  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004864b5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004864b8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004864bb  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 004864c0  39c5                   +cmp ebp, eax
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
    // 004864c2  75d2                   -jne 0x486496
    if (!cpu.flags.zf)
    {
        goto L_0x00486496;
    }
    // 004864c4  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004864c9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004864cf  e84c8bffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x004864d4:
    // 004864d4  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004864d9  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 004864e0  e9b1ecffff             -jmp 0x485196
    goto L_0x00485196;
L_0x004864e5:
    // 004864e5  a128a04c00             -mov eax, dword ptr [0x4ca028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */);
    // 004864ea  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004864ed  a328a04c00             -mov dword ptr [0x4ca028], eax
    app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 004864f2  39c3                   +cmp ebx, eax
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
    // 004864f4  0f85f3feffff           -jne 0x4863ed
    if (!cpu.flags.zf)
    {
        goto L_0x004863ed;
    }
    // 004864fa  eb80                   -jmp 0x48647c
    goto L_0x0048647c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4864fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004864fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004864fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004864ff  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486505  e8fe8affff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048650a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048650d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00486510  7430                   -je 0x486542
    if (cpu.flags.zf)
    {
        goto L_0x00486542;
    }
L_0x00486512:
    // 00486512  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00486515  3b4210                 +cmp eax, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486518  7428                   -je 0x486542
    if (cpu.flags.zf)
    {
        goto L_0x00486542;
    }
    // 0048651a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048651d  8338fe                 +cmp dword ptr [eax], -2
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
    // 00486520  752d                   -jne 0x48654f
    if (!cpu.flags.zf)
    {
        goto L_0x0048654f;
    }
    // 00486522  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00486525  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486528  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048652b  2982bc000000           -sub dword ptr [edx + 0xbc], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(188) /* 0xbc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00486531  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00486534  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486537  014218                 -add dword ptr [edx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048653a:
    // 0048653a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048653d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 00486540  75d0                   -jne 0x486512
    if (!cpu.flags.zf)
    {
        goto L_0x00486512;
    }
L_0x00486542:
    // 00486542  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 00486548  e8d38affff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048654d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048654e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048654f:
    // 0048654f  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00486552  8338ff                 +cmp dword ptr [eax], -1
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
    // 00486555  75eb                   -jne 0x486542
    if (!cpu.flags.zf)
    {
        goto L_0x00486542;
    }
    // 00486557  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048655a  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048655d  7506                   -jne 0x486565
    if (!cpu.flags.zf)
    {
        goto L_0x00486565;
    }
    // 0048655f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00486562  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00486565:
    // 00486565  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00486568  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048656b  ebcd                   -jmp 0x48653a
    goto L_0x0048653a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486570  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486571  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486573  e884ffffff             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 00486578  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048657b  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0048657e  7210                   -jb 0x486590
    if (cpu.flags.cf)
    {
        goto L_0x00486590;
    }
    // 00486580  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00486583  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 00486586  7510                   -jne 0x486598
    if (!cpu.flags.zf)
    {
        goto L_0x00486598;
    }
    // 00486588  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048658b  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048658e  7508                   -jne 0x486598
    if (!cpu.flags.zf)
    {
        goto L_0x00486598;
    }
L_0x00486590:
    // 00486590  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00486593  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00486596  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486597  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486598:
    // 00486598  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048659b  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048659e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048659f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4865a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004865a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004865a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004865a3  e854ffffff             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 004865a8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004865ab  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004865ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4865b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004865b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004865b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004865b3  e844ffffff             -call 0x4864fc
    cpu.esp -= 4;
    sub_4864fc(app, cpu);
    if (cpu.terminate) return;
    // 004865b8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004865bb  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 004865be  7708                   -ja 0x4865c8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004865c8;
    }
    // 004865c0  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004865c3  2b4204                 -sub eax, dword ptr [edx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004865c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004865c8:
    // 004865c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004865ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4865cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004865cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004865cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004865ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004865cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004865d0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004865d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004865d4  7437                   -je 0x48660d
    if (cpu.flags.zf)
    {
        goto L_0x0048660d;
    }
    // 004865d6  83787800               +cmp dword ptr [eax + 0x78], 0
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
    // 004865da  7413                   -je 0x4865ef
    if (cpu.flags.zf)
    {
        goto L_0x004865ef;
    }
    // 004865dc  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 004865df  8b8094000000           -mov eax, dword ptr [eax + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 004865e5  83f80d                 +cmp eax, 0xd
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
    // 004865e8  7328                   -jae 0x486612
    if (!cpu.flags.cf)
    {
        goto L_0x00486612;
    }
    // 004865ea  83f80b                 +cmp eax, 0xb
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
    // 004865ed  7431                   -je 0x486620
    if (cpu.flags.zf)
    {
        goto L_0x00486620;
    }
L_0x004865ef:
    // 004865ef  83792002               +cmp dword ptr [ecx + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865f3  742b                   -je 0x486620
    if (cpu.flags.zf)
    {
        goto L_0x00486620;
    }
    // 004865f5  83792001               +cmp dword ptr [ecx + 0x20], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865f9  7425                   -je 0x486620
    if (cpu.flags.zf)
    {
        goto L_0x00486620;
    }
    // 004865fb  8379200e               +cmp dword ptr [ecx + 0x20], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865ff  7426                   -je 0x486627
    if (cpu.flags.zf)
    {
        goto L_0x00486627;
    }
    // 00486601  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00486604  8b6914                 -mov ebp, dword ptr [ecx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00486607  39e8                   +cmp eax, ebp
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
    // 00486609  7526                   -jne 0x486631
    if (!cpu.flags.zf)
    {
        goto L_0x00486631;
    }
    // 0048660b  31e8                   +xor eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp))));
L_0x0048660d:
    // 0048660d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048660e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048660f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486610  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486611  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486612:
    // 00486612  760c                   -jbe 0x486620
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486620;
    }
    // 00486614  83f814                 +cmp eax, 0x14
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
    // 00486617  72d6                   -jb 0x4865ef
    if (cpu.flags.cf)
    {
        goto L_0x004865ef;
    }
    // 00486619  7605                   -jbe 0x486620
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486620;
    }
    // 0048661b  83f817                 +cmp eax, 0x17
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
    // 0048661e  75cf                   -jne 0x4865ef
    if (!cpu.flags.zf)
    {
        goto L_0x004865ef;
    }
L_0x00486620:
    // 00486620  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486623  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486624  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486625  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486626  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486627:
    // 00486627  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048662c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048662d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048662e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048662f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486630  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486631:
    // 00486631  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00486637  e8cc89ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048663c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048663f  8338ff                 +cmp dword ptr [eax], -1
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
    // 00486642  750e                   -jne 0x486652
    if (!cpu.flags.zf)
    {
        goto L_0x00486652;
    }
    // 00486644  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00486647  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048664a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048664d  3b4114                 +cmp eax, dword ptr [ecx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486650  7466                   -je 0x4866b8
    if (cpu.flags.zf)
    {
        goto L_0x004866b8;
    }
L_0x00486652:
    // 00486652  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00486655  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486658  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048665b  3b5114                 +cmp edx, dword ptr [ecx + 0x14]
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
    // 0048665e  736a                   -jae 0x4866ca
    if (!cpu.flags.cf)
    {
        goto L_0x004866ca;
    }
    // 00486660  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00486663  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 00486666  39c3                   +cmp ebx, eax
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
    // 00486668  7c4e                   -jl 0x4866b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004866b8;
    }
L_0x0048666a:
    // 0048666a  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048666d  8d50f8                 -lea edx, [eax - 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00486670  2991b8000000           -sub dword ptr [ecx + 0xb8], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486676  0191bc000000           -add dword ptr [ecx + 0xbc], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048667c  014114                 -add dword ptr [ecx + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048667f  833bfd                 +cmp dword ptr [ebx], -3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486682  7522                   -jne 0x4866a6
    if (!cpu.flags.zf)
    {
        goto L_0x004866a6;
    }
    // 00486684  3b5918                 +cmp ebx, dword ptr [ecx + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486687  755d                   -jne 0x4866e6
    if (!cpu.flags.zf)
    {
        goto L_0x004866e6;
    }
    // 00486689  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048668c  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0048668f:
    // 0048668f  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486694  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00486699  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0048669e  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004866a1  e83a88ffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
L_0x004866a6:
    // 004866a6  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004866ac  e86f89ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004866b1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004866b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004866b8:
    // 004866b8  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004866be  e85d89ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004866c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004866c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004866ca:
    // 004866ca  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004866cd  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004866d0  39c3                   +cmp ebx, eax
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
    // 004866d2  7d96                   -jge 0x48666a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048666a;
    }
    // 004866d4  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004866da  e84189ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004866df  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004866e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004866e6:
    // 004866e6  c703feffffff           -mov dword ptr [ebx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967294 /*0xfffffffe*/;
    // 004866ec  eba1                   -jmp 0x48668f
    goto L_0x0048668f;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4866f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004866f0  058c000000             +add eax, 0x8c
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
    // 004866f5  c702feffffff           -mov dword ptr [edx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.edx) = 4294967294 /*0xfffffffe*/;
    // 004866fb  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004866fe  e9dd87ffff             -jmp 0x47eee0
    return sub_47eee0(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_486704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486704  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486706  7406                   -je 0x48670e
    if (cpu.flags.zf)
    {
        goto L_0x0048670e;
    }
    // 00486708  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
L_0x0048670e:
    // 0048670e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486710  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486712  7406                   -je 0x48671a
    if (cpu.flags.zf)
    {
        goto L_0x0048671a;
    }
    // 00486714  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
L_0x0048671a:
    // 0048671a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48671c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048671c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048671d  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486723  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486725  7412                   -je 0x486739
    if (cpu.flags.zf)
    {
        goto L_0x00486739;
    }
    // 00486727  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486729  837a2007               +cmp dword ptr [edx + 0x20], 7
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
    // 0048672d  7506                   -jne 0x486735
    if (!cpu.flags.zf)
    {
        goto L_0x00486735;
    }
    // 0048672f  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 00486733  7404                   -je 0x486739
    if (cpu.flags.zf)
    {
        goto L_0x00486739;
    }
L_0x00486735:
    // 00486735  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486737  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486738  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486739:
    // 00486739  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048673e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048673f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486740  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486741  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486747  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048674d  e8b688ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00486752  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00486754:
    // 00486754  8982b4000000           -mov dword ptr [edx + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0048675a  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0048675d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048675f  75f3                   -jne 0x486754
    if (!cpu.flags.zf)
    {
        goto L_0x00486754;
    }
    // 00486761  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486766  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048676c  e8af88ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00486771  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486772  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486774(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486774  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 0048677a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48677c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048677c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048677d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048677f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486781  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486783  83f8ff                 +cmp eax, -1
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
    // 00486786  7408                   -je 0x486790
    if (cpu.flags.zf)
    {
        goto L_0x00486790;
    }
    // 00486788  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048678a  740d                   -je 0x486799
    if (cpu.flags.zf)
    {
        goto L_0x00486799;
    }
L_0x0048678c:
    // 0048678c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048678e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048678f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486790:
    // 00486790  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00486795  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486797  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486798  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486799:
    // 00486799  e87effffff             -call 0x48671c
    cpu.esp -= 4;
    sub_48671c(app, cpu);
    if (cpu.terminate) return;
    // 0048679e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004867a0  74ea                   -je 0x48678c
    if (cpu.flags.zf)
    {
        goto L_0x0048678c;
    }
    // 004867a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004867a4  e85bffffff             -call 0x486704
    cpu.esp -= 4;
    sub_486704(app, cpu);
    if (cpu.terminate) return;
    // 004867a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004867ab  75df                   -jne 0x48678c
    if (!cpu.flags.zf)
    {
        goto L_0x0048678c;
    }
    // 004867ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004867b2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004867b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4867b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004867b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004867b9  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004867bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004867c1  7502                   -jne 0x4867c5
    if (!cpu.flags.zf)
    {
        goto L_0x004867c5;
    }
    // 004867c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004867c5:
    // 004867c5  c7423001000000         -mov dword ptr [edx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 004867cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4867d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004867d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004867d1  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004867d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004867d9  7502                   -jne 0x4867dd
    if (!cpu.flags.zf)
    {
        goto L_0x004867dd;
    }
    // 004867db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004867dd:
    // 004867dd  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004867e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4867e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004867e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004867e9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004867eb  8b1524a04c00           -mov edx, dword ptr [0x4ca024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004867f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004867f3  742a                   -je 0x48681f
    if (cpu.flags.zf)
    {
        goto L_0x0048681f;
    }
    // 004867f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004867f6  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 004867f9  49                     -dec ecx
    (cpu.ecx)--;
    // 004867fa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004867fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004867fe  7e14                   -jle 0x486814
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486814;
    }
L_0x00486800:
    // 00486800  8d989c000000           -lea ebx, [eax + 0x9c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00486806  42                     -inc edx
    (cpu.edx)++;
    // 00486807  899898000000           -mov dword ptr [eax + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 0048680d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048680f  39ca                   +cmp edx, ecx
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
    // 00486811  7ced                   -jl 0x486800
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486800;
    }
    // 00486813  90                     -nop 
    ;
L_0x00486814:
    // 00486814  c7809800000000000000   -mov dword ptr [eax + 0x98], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0048681e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048681f:
    // 0048681f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486824  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486825  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486826  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486828  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048682e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486830  7503                   -jne 0x486835
    if (!cpu.flags.zf)
    {
        goto L_0x00486835;
    }
    // 00486832  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486834  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486835:
    // 00486835  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048683b  e8c887ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00486840  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486845  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00486848  898a98000000           -mov dword ptr [edx + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048684e  895074                 -mov dword ptr [eax + 0x74], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00486851  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486857  e8c487ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048685c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486860  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486862  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486864  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048686a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048686c  7505                   -jne 0x486873
    if (!cpu.flags.zf)
    {
        goto L_0x00486873;
    }
L_0x0048686e:
    // 0048686e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486870  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486871  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486872  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486873:
    // 00486873  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00486879  e88a87ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048687e  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486883  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00486886  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486888  740d                   -je 0x486897
    if (cpu.flags.zf)
    {
        goto L_0x00486897;
    }
L_0x0048688a:
    // 0048688a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048688c  7409                   -je 0x486897
    if (cpu.flags.zf)
    {
        goto L_0x00486897;
    }
    // 0048688e  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00486894  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486895  75f3                   -jne 0x48688a
    if (!cpu.flags.zf)
    {
        goto L_0x0048688a;
    }
L_0x00486897:
    // 00486897  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048689c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004868a2  e87987ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004868a7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004868a9  75c3                   -jne 0x48686e
    if (!cpu.flags.zf)
    {
        goto L_0x0048686e;
    }
    // 004868ab  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004868b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4868b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004868b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004868b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004868b6  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004868bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004868be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004868c0  7505                   -jne 0x4868c7
    if (!cpu.flags.zf)
    {
        goto L_0x004868c7;
    }
    // 004868c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004868c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004868c7:
    // 004868c7  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004868cd  e83687ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004868d2  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004868d7  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004868da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004868dc  740e                   -je 0x4868ec
    if (cpu.flags.zf)
    {
        goto L_0x004868ec;
    }
L_0x004868de:
    // 004868de  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004868e4  42                     -inc edx
    (cpu.edx)++;
    // 004868e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004868e7  75f5                   -jne 0x4868de
    if (!cpu.flags.zf)
    {
        goto L_0x004868de;
    }
    // 004868e9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004868ec:
    // 004868ec  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 004868f1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004868f7  e82487ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004868fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004868fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486904  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486905  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486906  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486908  8b0d24a04c00           -mov ecx, dword ptr [0x4ca024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 0048690e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486910  7505                   -jne 0x486917
    if (!cpu.flags.zf)
    {
        goto L_0x00486917;
    }
    // 00486912  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486914  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486915  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486916  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486917:
    // 00486917  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048691d  e8e686ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00486922  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486927  83787400               +cmp dword ptr [eax + 0x74], 0
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
    // 0048692b  7504                   -jne 0x486931
    if (!cpu.flags.zf)
    {
        goto L_0x00486931;
    }
    // 0048692d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048692f  742e                   -je 0x48695f
    if (cpu.flags.zf)
    {
        goto L_0x0048695f;
    }
L_0x00486931:
    // 00486931  a124a04c00             -mov eax, dword ptr [0x4ca024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */);
    // 00486936  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00486939  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048693c  8b8998000000           -mov ecx, dword ptr [ecx + 0x98]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00486942  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 00486945  c7829800000000000000   -mov dword ptr [edx + 0x98], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0048694f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486955  e8c686ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048695a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048695c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048695d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048695e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048695f:
    // 0048695f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00486965  e8b686ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048696a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048696c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048696d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048696e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_486970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486972  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486974  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486976  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048697d  7421                   -je 0x4869a0
    if (cpu.flags.zf)
    {
        goto L_0x004869a0;
    }
    // 0048697f  833d88ab4c0000         +cmp dword ptr [0x4cab88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486986  7522                   -jne 0x4869aa
    if (!cpu.flags.zf)
    {
        goto L_0x004869aa;
    }
    // 00486988  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048698a  7e28                   -jle 0x4869b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004869b4;
    }
    // 0048698c  8a15b1a04c00           -mov dl, byte ptr [0x4ca0b1]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
    // 00486992  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00486994  7428                   -je 0x4869be
    if (cpu.flags.zf)
    {
        goto L_0x004869be;
    }
    // 00486996  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0048699b:
    // 0048699b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048699c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048699d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004869a0:
    // 004869a0  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004869a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869a7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004869aa:
    // 004869aa  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004869af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004869b4:
    // 004869b4  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004869b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869bb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004869be:
    // 004869be  e82d72ffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 004869c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004869c5  7cd4                   -jl 0x48699b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048699b;
    }
    // 004869c7  e8700e0000             -call 0x48783c
    cpu.esp -= 4;
    sub_48783c(app, cpu);
    if (cpu.terminate) return;
    // 004869cc  8815b4a04c00           -mov byte ptr [0x4ca0b4], dl
    app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */) = cpu.dl;
    // 004869d2  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004869d6  a2b2a04c00             -mov byte ptr [0x4ca0b2], al
    app->getMemory<x86::reg8>(x86::reg32(5021874) /* 0x4ca0b2 */) = cpu.al;
    // 004869db  893d30a04c00           -mov dword ptr [0x4ca030], edi
    app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */) = cpu.edi;
    // 004869e1  8815b0a04c00           -mov byte ptr [0x4ca0b0], dl
    app->getMemory<x86::reg8>(x86::reg32(5021872) /* 0x4ca0b0 */) = cpu.dl;
    // 004869e7  8815bda04c00           -mov byte ptr [0x4ca0bd], dl
    app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */) = cpu.dl;
    // 004869ed  8815bea04c00           -mov byte ptr [0x4ca0be], dl
    app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */) = cpu.dl;
    // 004869f3  8935c8a04c00           -mov dword ptr [0x4ca0c8], esi
    app->getMemory<x86::reg32>(x86::reg32(5021896) /* 0x4ca0c8 */) = cpu.esi;
    // 004869f9  890d40a04c00           -mov dword ptr [0x4ca040], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021760) /* 0x4ca040 */) = cpu.ecx;
    // 004869ff  c605b1a04c0001         -mov byte ptr [0x4ca0b1], 1
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = 1 /*0x1*/;
    // 00486a06  c605bfa04c00ff         -mov byte ptr [0x4ca0bf], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */) = 255 /*0xff*/;
    // 00486a0d  8b0d588a5200           -mov ecx, dword ptr [0x528a58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */);
    // 00486a13  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00486a15  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00486a17:
    // 00486a17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486a19  e86216ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00486a1e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486a22  e8dd0a0000             -call 0x487504
    cpu.esp -= 4;
    sub_487504(app, cpu);
    if (cpu.terminate) return;
    // 00486a27  3b35c4a04c00           +cmp esi, dword ptr [0x4ca0c4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486a2d  7e08                   -jle 0x486a37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486a37;
    }
    // 00486a2f  3b0d588a5200           +cmp ecx, dword ptr [0x528a58]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486a35  77e0                   -ja 0x486a17
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00486a17;
    }
L_0x00486a37:
    // 00486a37  a1c4a04c00             -mov eax, dword ptr [0x4ca0c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
    // 00486a3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486a44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486a44  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486a4b  740f                   -je 0x486a5c
    if (cpu.flags.zf)
    {
        goto L_0x00486a5c;
    }
    // 00486a4d  803db1a04c0002         +cmp byte ptr [0x4ca0b1], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486a54  750c                   -jne 0x486a62
    if (!cpu.flags.zf)
    {
        goto L_0x00486a62;
    }
    // 00486a56  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00486a5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486a5c:
    // 00486a5c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486a61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486a62:
    // 00486a62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486a63  a2b3a04c00             -mov byte ptr [0x4ca0b3], al
    app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */) = cpu.al;
    // 00486a68  8815b6a04c00           -mov byte ptr [0x4ca0b6], dl
    app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */) = cpu.dl;
    // 00486a6e  b1ff                   -mov cl, 0xff
    cpu.cl = 255 /*0xff*/;
    // 00486a70  880db7a04c00           -mov byte ptr [0x4ca0b7], cl
    app->getMemory<x86::reg8>(x86::reg32(5021879) /* 0x4ca0b7 */) = cpu.cl;
    // 00486a76  880db8a04c00           -mov byte ptr [0x4ca0b8], cl
    app->getMemory<x86::reg8>(x86::reg32(5021880) /* 0x4ca0b8 */) = cpu.cl;
    // 00486a7c  880db9a04c00           -mov byte ptr [0x4ca0b9], cl
    app->getMemory<x86::reg8>(x86::reg32(5021881) /* 0x4ca0b9 */) = cpu.cl;
    // 00486a82  e8690e0000             -call 0x4878f0
    cpu.esp -= 4;
    sub_4878f0(app, cpu);
    if (cpu.terminate) return;
    // 00486a87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486a90  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486a97  740f                   -je 0x486aa8
    if (cpu.flags.zf)
    {
        goto L_0x00486aa8;
    }
    // 00486a99  803db1a04c0000         +cmp byte ptr [0x4ca0b1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486aa0  750c                   -jne 0x486aae
    if (!cpu.flags.zf)
    {
        goto L_0x00486aae;
    }
    // 00486aa2  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 00486aa7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486aa8:
    // 00486aa8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486aad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486aae:
    // 00486aae  a148a04c00             -mov eax, dword ptr [0x4ca048]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */);
    // 00486ab3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486ac2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486ac4  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486acb  7411                   -je 0x486ade
    if (cpu.flags.zf)
    {
        goto L_0x00486ade;
    }
    // 00486acd  833d88ab4c0000         +cmp dword ptr [0x4cab88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ad4  7410                   -je 0x486ae6
    if (cpu.flags.zf)
    {
        goto L_0x00486ae6;
    }
    // 00486ad6  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00486adb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486adc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486add  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ade:
    // 00486ade  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486ae3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ae4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ae5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ae6:
    // 00486ae6  e805de0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486aeb  e80071ffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00486af0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486af4  7c7d                   -jl 0x486b73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486b73;
    }
    // 00486af6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486af7  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00486af9  a234a14c00             -mov byte ptr [0x4ca134], al
    app->getMemory<x86::reg8>(x86::reg32(5022004) /* 0x4ca134 */) = cpu.al;
    // 00486afe  c605b4a04c0001         -mov byte ptr [0x4ca0b4], 1
    app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */) = 1 /*0x1*/;
    // 00486b05  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00486b07  893540a04c00           -mov dword ptr [0x4ca040], esi
    app->getMemory<x86::reg32>(x86::reg32(5021760) /* 0x4ca040 */) = cpu.esi;
    // 00486b0d  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00486b10  a2b6a04c00             -mov byte ptr [0x4ca0b6], al
    app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */) = cpu.al;
    // 00486b15  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 00486b18  a2b7a04c00             -mov byte ptr [0x4ca0b7], al
    app->getMemory<x86::reg8>(x86::reg32(5021879) /* 0x4ca0b7 */) = cpu.al;
    // 00486b1d  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00486b20  a2b8a04c00             -mov byte ptr [0x4ca0b8], al
    app->getMemory<x86::reg8>(x86::reg32(5021880) /* 0x4ca0b8 */) = cpu.al;
    // 00486b25  8a420a                 -mov al, byte ptr [edx + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 00486b28  a2b9a04c00             -mov byte ptr [0x4ca0b9], al
    app->getMemory<x86::reg8>(x86::reg32(5021881) /* 0x4ca0b9 */) = cpu.al;
    // 00486b2d  891d30a04c00           -mov dword ptr [0x4ca030], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */) = cpu.ebx;
    // 00486b33  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00486b35  8815b0a04c00           -mov byte ptr [0x4ca0b0], dl
    app->getMemory<x86::reg8>(x86::reg32(5021872) /* 0x4ca0b0 */) = cpu.dl;
    // 00486b3b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00486b3d  8835bda04c00           -mov byte ptr [0x4ca0bd], dh
    app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */) = cpu.dh;
    // 00486b43  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00486b45  881dbea04c00           -mov byte ptr [0x4ca0be], bl
    app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */) = cpu.bl;
    // 00486b4b  c705c8a04c000f000000   -mov dword ptr [0x4ca0c8], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5021896) /* 0x4ca0c8 */) = 15 /*0xf*/;
    // 00486b55  c605bfa04c00ff         -mov byte ptr [0x4ca0bf], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */) = 255 /*0xff*/;
    // 00486b5c  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00486b5e  a2c0a04c00             -mov byte ptr [0x4ca0c0], al
    app->getMemory<x86::reg8>(x86::reg32(5021888) /* 0x4ca0c0 */) = cpu.al;
    // 00486b63  e8d40c0000             -call 0x48783c
    cpu.esp -= 4;
    sub_48783c(app, cpu);
    if (cpu.terminate) return;
    // 00486b68  e897dd0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486b6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486b6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486b73:
    // 00486b73  e88cdd0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486b78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486b7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486b80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486b81  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486b83  e868da0000             -call 0x4945f0
    cpu.esp -= 4;
    sub_4945f0(app, cpu);
    if (cpu.terminate) return;
    // 00486b88  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486b8f  7410                   -je 0x486ba1
    if (cpu.flags.zf)
    {
        goto L_0x00486ba1;
    }
    // 00486b91  833d88ab4c0000         +cmp dword ptr [0x4cab88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486b98  750e                   -jne 0x486ba8
    if (!cpu.flags.zf)
    {
        goto L_0x00486ba8;
    }
    // 00486b9a  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 00486b9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ba1:
    // 00486ba1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486ba6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ba7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ba8:
    // 00486ba8  e86f010000             -call 0x486d1c
    cpu.esp -= 4;
    sub_486d1c(app, cpu);
    if (cpu.terminate) return;
    // 00486bad  803dbca04c0000         +cmp byte ptr [0x4ca0bc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486bb4  7412                   -je 0x486bc8
    if (cpu.flags.zf)
    {
        goto L_0x00486bc8;
    }
    // 00486bb6  b804754800             -mov eax, 0x487504
    cpu.eax = 4748548 /*0x487504*/;
    // 00486bbb  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00486bbd  e87214ffff             -call 0x478034
    cpu.esp -= 4;
    sub_478034(app, cpu);
    if (cpu.terminate) return;
    // 00486bc2  8835bca04c00           -mov byte ptr [0x4ca0bc], dh
    app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */) = cpu.dh;
L_0x00486bc8:
    // 00486bc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486bc9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486bcb  890d88ab4c00           -mov dword ptr [0x4cab88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */) = cpu.ecx;
    // 00486bd1  e81a70ffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00486bd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486bd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486bdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486bdc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486bdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486bde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486bdf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486be1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486be3  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00486be9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00486beb  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00486bed  750b                   -jne 0x486bfa
    if (!cpu.flags.zf)
    {
        goto L_0x00486bfa;
    }
    // 00486bef  bff6ffffff             -mov edi, 0xfffffff6
    cpu.edi = 4294967286 /*0xfffffff6*/;
    // 00486bf4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486bf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bf9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bfa:
    // 00486bfa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486bfb  e8f0dc0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486c00  803db1a04c0000         +cmp byte ptr [0x4ca0b1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486c07  7567                   -jne 0x486c70
    if (!cpu.flags.zf)
    {
        goto L_0x00486c70;
    }
    // 00486c09  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486c0b  7549                   -jne 0x486c56
    if (!cpu.flags.zf)
    {
        goto L_0x00486c56;
    }
    // 00486c0d  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486c12  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486c14  e8e3e1ffff             -call 0x484dfc
    cpu.esp -= 4;
    sub_484dfc(app, cpu);
    if (cpu.terminate) return;
L_0x00486c19:
    // 00486c19  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 00486c1b  e81c0c0000             -call 0x48783c
    cpu.esp -= 4;
    sub_48783c(app, cpu);
    if (cpu.terminate) return;
    // 00486c20  8835b1a04c00           -mov byte ptr [0x4ca0b1], dh
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = cpu.dh;
L_0x00486c26:
    // 00486c26  a0bda04c00             -mov al, byte ptr [0x4ca0bd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */);
    // 00486c2b  fe05bda04c00           -inc byte ptr [0x4ca0bd]
    (app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */))++;
    // 00486c31  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00486c36  b834a14c00             -mov eax, 0x4ca134
    cpu.eax = 5022004 /*0x4ca134*/;
    // 00486c3b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486c3d  e8ba37ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 00486c42  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 00486c44  883db3a14c00           -mov byte ptr [0x4ca1b3], bh
    app->getMemory<x86::reg8>(x86::reg32(5022131) /* 0x4ca1b3 */) = cpu.bh;
    // 00486c4a  e8b5dc0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486c4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c50  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c56:
    // 00486c56  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486c5b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486c5d  e81ae2ffff             -call 0x484e7c
    cpu.esp -= 4;
    sub_484e7c(app, cpu);
    if (cpu.terminate) return;
    // 00486c62  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486c67  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486c69  e86ee2ffff             -call 0x484edc
    cpu.esp -= 4;
    sub_484edc(app, cpu);
    if (cpu.terminate) return;
    // 00486c6e  eba9                   -jmp 0x486c19
    goto L_0x00486c19;
L_0x00486c70:
    // 00486c70  0fbe15bda04c00         -movsx edx, byte ptr [0x4ca0bd]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */)));
    // 00486c77  0fbe05bea04c00         -movsx eax, byte ptr [0x4ca0be]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */)));
    // 00486c7e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486c80  83f813                 +cmp eax, 0x13
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
    // 00486c83  7c11                   -jl 0x486c96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486c96;
    }
    // 00486c85  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00486c8a  e875dc0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486c8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c90  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486c92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c96:
    // 00486c96  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486c98  7530                   -jne 0x486cca
    if (!cpu.flags.zf)
    {
        goto L_0x00486cca;
    }
    // 00486c9a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00486c9f  e8bcfbffff             -call 0x486860
    cpu.esp -= 4;
    sub_486860(app, cpu);
    if (cpu.terminate) return;
    // 00486ca4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ca6  7511                   -jne 0x486cb9
    if (!cpu.flags.zf)
    {
        goto L_0x00486cb9;
    }
    // 00486ca8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00486cad  e852dc0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486cb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486cb3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486cb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486cb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486cb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486cb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486cb9:
    // 00486cb9  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486cbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486cc0  e807e1ffff             -call 0x484dcc
    cpu.esp -= 4;
    sub_484dcc(app, cpu);
    if (cpu.terminate) return;
    // 00486cc5  e95cffffff             -jmp 0x486c26
    goto L_0x00486c26;
L_0x00486cca:
    // 00486cca  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00486ccf  e88cfbffff             -call 0x486860
    cpu.esp -= 4;
    sub_486860(app, cpu);
    if (cpu.terminate) return;
    // 00486cd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486cd6  7511                   -jne 0x486ce9
    if (!cpu.flags.zf)
    {
        goto L_0x00486ce9;
    }
    // 00486cd8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00486cdd  e822dc0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486ce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486ce5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ce9:
    // 00486ce9  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00486cee  b834a14c00             -mov eax, 0x4ca134
    cpu.eax = 5022004 /*0x4ca134*/;
    // 00486cf3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486cf5  e8a9390000             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00486cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486cfc  740c                   -je 0x486d0a
    if (cpu.flags.zf)
    {
        goto L_0x00486d0a;
    }
    // 00486cfe  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486d03  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486d05  e842e1ffff             -call 0x484e4c
    cpu.esp -= 4;
    sub_484e4c(app, cpu);
    if (cpu.terminate) return;
L_0x00486d0a:
    // 00486d0a  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486d0f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486d11  e8c6e1ffff             -call 0x484edc
    cpu.esp -= 4;
    sub_484edc(app, cpu);
    if (cpu.terminate) return;
    // 00486d16  e90bffffff             -jmp 0x486c26
    goto L_0x00486c26;
}

/* align: skip 0x90 */
void Application::sub_486d1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486d1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486d1d  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486d24  7507                   -jne 0x486d2d
    if (!cpu.flags.zf)
    {
        goto L_0x00486d2d;
    }
    // 00486d26  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486d2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d2d:
    // 00486d2d  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 00486d32  e8c97bffff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
    // 00486d37  8b15588a5200           -mov edx, dword ptr [0x528a58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */);
    // 00486d3d  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x00486d43:
    // 00486d43  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 00486d48  e81332ffff             -call 0x479f60
    cpu.esp -= 4;
    sub_479f60(app, cpu);
    if (cpu.terminate) return;
    // 00486d4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486d4f  7516                   -jne 0x486d67
    if (!cpu.flags.zf)
    {
        goto L_0x00486d67;
    }
    // 00486d51  3b15588a5200           +cmp edx, dword ptr [0x528a58]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486d57  7207                   -jb 0x486d60
    if (cpu.flags.cf)
    {
        goto L_0x00486d60;
    }
    // 00486d59  e82213ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00486d5e  ebe3                   -jmp 0x486d43
    goto L_0x00486d43;
L_0x00486d60:
    // 00486d60  b8efffffff             -mov eax, 0xffffffef
    cpu.eax = 4294967279 /*0xffffffef*/;
    // 00486d65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d67:
    // 00486d67  e884db0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486d6c  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 00486d6e  e869020000             -call 0x486fdc
    cpu.esp -= 4;
    sub_486fdc(app, cpu);
    if (cpu.terminate) return;
    // 00486d73  8815bfa04c00           -mov byte ptr [0x4ca0bf], dl
    app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */) = cpu.dl;
    // 00486d79  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00486d7b  8835c0a04c00           -mov byte ptr [0x4ca0c0], dh
    app->getMemory<x86::reg8>(x86::reg32(5021888) /* 0x4ca0c0 */) = cpu.dh;
    // 00486d81  8835bda04c00           -mov byte ptr [0x4ca0bd], dh
    app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */) = cpu.dh;
    // 00486d87  8835bea04c00           -mov byte ptr [0x4ca0be], dh
    app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */) = cpu.dh;
    // 00486d8d  8835b1a04c00           -mov byte ptr [0x4ca0b1], dh
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = cpu.dh;
    // 00486d93  883534a14c00           -mov byte ptr [0x4ca134], dh
    app->getMemory<x86::reg8>(x86::reg32(5022004) /* 0x4ca134 */) = cpu.dh;
    // 00486d99  8835b0a04c00           -mov byte ptr [0x4ca0b0], dh
    app->getMemory<x86::reg8>(x86::reg32(5021872) /* 0x4ca0b0 */) = cpu.dh;
    // 00486d9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486da1  e84ad80000             -call 0x4945f0
    cpu.esp -= 4;
    sub_4945f0(app, cpu);
    if (cpu.terminate) return;
    // 00486da6  803dbca04c0000         +cmp byte ptr [0x4ca0bc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486dad  7410                   -je 0x486dbf
    if (cpu.flags.zf)
    {
        goto L_0x00486dbf;
    }
    // 00486daf  b804754800             -mov eax, 0x487504
    cpu.eax = 4748548 /*0x487504*/;
    // 00486db4  e87b12ffff             -call 0x478034
    cpu.esp -= 4;
    sub_478034(app, cpu);
    if (cpu.terminate) return;
    // 00486db9  8835bca04c00           -mov byte ptr [0x4ca0bc], dh
    app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */) = cpu.dh;
L_0x00486dbf:
    // 00486dbf  e840db0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486dc4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486dc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486dc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486dc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486dc8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486dc9  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00486dcf  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00486dd4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00486dd6  7509                   -jne 0x486de1
    if (!cpu.flags.zf)
    {
        goto L_0x00486de1;
    }
    // 00486dd8  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00486ddd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486de0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486de1:
    // 00486de1  e80adb0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486de6  803db1a04c0000         +cmp byte ptr [0x4ca0b1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486ded  741e                   -je 0x486e0d
    if (cpu.flags.zf)
    {
        goto L_0x00486e0d;
    }
    // 00486def  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486df1  a0b3a04c00             -mov al, byte ptr [0x4ca0b3]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */);
    // 00486df6  e8f56dffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00486dfb  8b154ca04c00           -mov edx, dword ptr [0x4ca04c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */);
    // 00486e01  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486e03  803dc1a04c0002         +cmp byte ptr [0x4ca0c1], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e0a  7501                   -jne 0x486e0d
    if (!cpu.flags.zf)
    {
        goto L_0x00486e0d;
    }
    // 00486e0c  4a                     -dec edx
    (cpu.edx)--;
L_0x00486e0d:
    // 00486e0d  e8f2da0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486e12  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486e14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486e18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486e18  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486e1f  7506                   -jne 0x486e27
    if (!cpu.flags.zf)
    {
        goto L_0x00486e27;
    }
    // 00486e21  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486e26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486e27:
    // 00486e27  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486e28  e8c3da0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486e2d  803db1a04c0000         +cmp byte ptr [0x4ca0b1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e34  750e                   -jne 0x486e44
    if (!cpu.flags.zf)
    {
        goto L_0x00486e44;
    }
L_0x00486e36:
    // 00486e36  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00486e3b  e8c4da0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486e40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486e42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486e44:
    // 00486e44  803db1a04c0001         +cmp byte ptr [0x4ca0b1], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e4b  74e9                   -je 0x486e36
    if (cpu.flags.zf)
    {
        goto L_0x00486e36;
    }
    // 00486e4d  803db3a04c0000         +cmp byte ptr [0x4ca0b3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e54  750e                   -jne 0x486e64
    if (!cpu.flags.zf)
    {
        goto L_0x00486e64;
    }
    // 00486e56  baf9ffffff             -mov edx, 0xfffffff9
    cpu.edx = 4294967289 /*0xfffffff9*/;
    // 00486e5b  e8a4da0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486e60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486e62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486e64:
    // 00486e64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486e65  e85effffff             -call 0x486dc8
    cpu.esp -= 4;
    sub_486dc8(app, cpu);
    if (cpu.terminate) return;
    // 00486e6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e6c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00486e6f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486e71  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00486e74  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486e76  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00486e79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e7b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00486e7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486e80  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486e82  8a0db3a04c00           -mov cl, byte ptr [0x4ca0b3]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */);
    // 00486e88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486e8a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486e8d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00486e8f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e92  e86dda0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486e97  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486e9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486e9c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486e9d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e9f  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00486ea6  7404                   -je 0x486eac
    if (cpu.flags.zf)
    {
        goto L_0x00486eac;
    }
    // 00486ea8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486eaa  7f02                   -jg 0x486eae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00486eae;
    }
L_0x00486eac:
    // 00486eac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ead  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486eae:
    // 00486eae  e89512ffff             -call 0x478148
    cpu.esp -= 4;
    sub_478148(app, cpu);
    if (cpu.terminate) return;
    // 00486eb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486eb5  7509                   -jne 0x486ec0
    if (!cpu.flags.zf)
    {
        goto L_0x00486ec0;
    }
    // 00486eb7  e85cffffff             -call 0x486e18
    cpu.esp -= 4;
    sub_486e18(app, cpu);
    if (cpu.terminate) return;
    // 00486ebc  39d0                   +cmp eax, edx
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
    // 00486ebe  7d47                   -jge 0x486f07
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486f07;
    }
L_0x00486ec0:
    // 00486ec0  e857f8ffff             -call 0x48671c
    cpu.esp -= 4;
    sub_48671c(app, cpu);
    if (cpu.terminate) return;
    // 00486ec5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ec7  753e                   -jne 0x486f07
    if (!cpu.flags.zf)
    {
        goto L_0x00486f07;
    }
    // 00486ec9  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486ece  e8a1f8ffff             -call 0x486774
    cpu.esp -= 4;
    sub_486774(app, cpu);
    if (cpu.terminate) return;
    // 00486ed3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ed5  7417                   -je 0x486eee
    if (cpu.flags.zf)
    {
        goto L_0x00486eee;
    }
    // 00486ed7  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486edc  e823f8ffff             -call 0x486704
    cpu.esp -= 4;
    sub_486704(app, cpu);
    if (cpu.terminate) return;
    // 00486ee1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ee3  7509                   -jne 0x486eee
    if (!cpu.flags.zf)
    {
        goto L_0x00486eee;
    }
    // 00486ee5  e85e12ffff             -call 0x478148
    cpu.esp -= 4;
    sub_478148(app, cpu);
    if (cpu.terminate) return;
    // 00486eea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486eec  741e                   -je 0x486f0c
    if (cpu.flags.zf)
    {
        goto L_0x00486f0c;
    }
L_0x00486eee:
    // 00486eee  891520a14c00           -mov dword ptr [0x4ca120], edx
    app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */) = cpu.edx;
    // 00486ef4  833db8a14c0000         +cmp dword ptr [0x4ca1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486efb  74af                   -je 0x486eac
    if (cpu.flags.zf)
    {
        goto L_0x00486eac;
    }
    // 00486efd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486eff  ff15b8a14c00           -call dword ptr [0x4ca1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486f05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f07:
    // 00486f07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00486f0c:
    // 00486f0c  e877d70000             -call 0x494688
    cpu.esp -= 4;
    sub_494688(app, cpu);
    if (cpu.terminate) return;
    // 00486f11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486f15  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486f16  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486f18  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00486f1e  b9f1ffffff             -mov ecx, 0xfffffff1
    cpu.ecx = 4294967281 /*0xfffffff1*/;
    // 00486f23  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00486f25  750a                   -jne 0x486f31
    if (!cpu.flags.zf)
    {
        goto L_0x00486f31;
    }
    // 00486f27  b9f6ffffff             -mov ecx, 0xfffffff6
    cpu.ecx = 4294967286 /*0xfffffff6*/;
    // 00486f2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486f2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f31:
    // 00486f31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486f32  e8b9d90000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486f37  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00486f39  81fb5343446c           +cmp ebx, 0x6c444353
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
    // 00486f3f  7514                   -jne 0x486f55
    if (!cpu.flags.zf)
    {
        goto L_0x00486f55;
    }
    // 00486f41  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f43  e814010000             -call 0x48705c
    cpu.esp -= 4;
    sub_48705c(app, cpu);
    if (cpu.terminate) return;
    // 00486f48  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486f4a  e8b5d90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486f4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f50  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486f52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f55:
    // 00486f55  81fb5343486c           +cmp ebx, 0x6c484353
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
    // 00486f5b  742c                   -je 0x486f89
    if (cpu.flags.zf)
    {
        goto L_0x00486f89;
    }
    // 00486f5d  81fb5343436c           +cmp ebx, 0x6c434353
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
    // 00486f63  7438                   -je 0x486f9d
    if (cpu.flags.zf)
    {
        goto L_0x00486f9d;
    }
    // 00486f65  81fb53434c6c           +cmp ebx, 0x6c4c4353
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
    // 00486f6b  7444                   -je 0x486fb1
    if (cpu.flags.zf)
    {
        goto L_0x00486fb1;
    }
    // 00486f6d  81fb5343456c           +cmp ebx, 0x6c454353
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
    // 00486f73  7550                   -jne 0x486fc5
    if (!cpu.flags.zf)
    {
        goto L_0x00486fc5;
    }
    // 00486f75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f77  e8d0020000             -call 0x48724c
    cpu.esp -= 4;
    sub_48724c(app, cpu);
    if (cpu.terminate) return;
    // 00486f7c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486f7e  e881d90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486f83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f84  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f89:
    // 00486f89  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f8b  e820010000             -call 0x4870b0
    cpu.esp -= 4;
    sub_4870b0(app, cpu);
    if (cpu.terminate) return;
    // 00486f90  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486f92  e86dd90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486f97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486f9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f9d:
    // 00486f9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f9f  e814020000             -call 0x4871b8
    cpu.esp -= 4;
    sub_4871b8(app, cpu);
    if (cpu.terminate) return;
    // 00486fa4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486fa6  e859d90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486fab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486fae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486faf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486fb1:
    // 00486fb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486fb3  e86c020000             -call 0x487224
    cpu.esp -= 4;
    sub_487224(app, cpu);
    if (cpu.terminate) return;
    // 00486fb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486fba  e845d90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486fbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fc0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486fc2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486fc5:
    // 00486fc5  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00486fca  e821f7ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00486fcf  e830d90000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00486fd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fd5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486fd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486fdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486fdc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486fdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486fde  e80dd90000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00486fe3  833d34a04c0000         +cmp dword ptr [0x4ca034], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486fea  7454                   -je 0x487040
    if (cpu.flags.zf)
    {
        goto L_0x00487040;
    }
L_0x00486fec:
    // 00486fec  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00486ff1  3b0538a04c00           +cmp eax, dword ptr [0x4ca038]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ff7  741e                   -je 0x487017
    if (cpu.flags.zf)
    {
        goto L_0x00487017;
    }
    // 00486ff9  8b1534a04c00           -mov edx, dword ptr [0x4ca034]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00486fff  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487004  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487006  a334a04c00             -mov dword ptr [0x4ca034], eax
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.eax;
    // 0048700b  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487010  e8dbf6ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00487015  ebd5                   -jmp 0x486fec
    goto L_0x00486fec;
L_0x00487017:
    // 00487017  8b1534a04c00           -mov edx, dword ptr [0x4ca034]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 0048701d  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487022  e8c9f6ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00487027  833d3ca04c0000         +cmp dword ptr [0x4ca03c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048702e  7410                   -je 0x487040
    if (cpu.flags.zf)
    {
        goto L_0x00487040;
    }
    // 00487030  8b153ca04c00           -mov edx, dword ptr [0x4ca03c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
    // 00487036  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048703b  e8b0f6ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
L_0x00487040:
    // 00487040  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00487042  893534a04c00           -mov dword ptr [0x4ca034], esi
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.esi;
    // 00487048  893538a04c00           -mov dword ptr [0x4ca038], esi
    app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */) = cpu.esi;
    // 0048704e  89353ca04c00           -mov dword ptr [0x4ca03c], esi
    app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */) = cpu.esi;
    // 00487054  e8abd80000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048705a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048705b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48705c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048705c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048705d  8b154ca04c00           -mov edx, dword ptr [0x4ca04c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */);
    // 00487063  ff054ca04c00           -inc dword ptr [0x4ca04c]
    (app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */))++;
    // 00487069  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048706c  011550a04c00           -add dword ptr [0x4ca050], edx
    (app->getMemory<x86::reg32>(x86::reg32(5021776) /* 0x4ca050 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487072  8338ff                 +cmp dword ptr [eax], -1
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
    // 00487075  751a                   -jne 0x487091
    if (!cpu.flags.zf)
    {
        goto L_0x00487091;
    }
L_0x00487077:
    // 00487077  833d34a04c0000         +cmp dword ptr [0x4ca034], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048707e  7519                   -jne 0x487099
    if (!cpu.flags.zf)
    {
        goto L_0x00487099;
    }
    // 00487080  a334a04c00             -mov dword ptr [0x4ca034], eax
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.eax;
    // 00487085  a338a04c00             -mov dword ptr [0x4ca038], eax
    app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */) = cpu.eax;
    // 0048708a  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0048708f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487090  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487091:
    // 00487091  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00487097  ebde                   -jmp 0x487077
    goto L_0x00487077;
L_0x00487099:
    // 00487099  8b1538a04c00           -mov edx, dword ptr [0x4ca038]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */);
    // 0048709f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004870a1  a338a04c00             -mov dword ptr [0x4ca038], eax
    app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */) = cpu.eax;
    // 004870a6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004870ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004870ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4870b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004870b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004870b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004870b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004870b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004870b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004870b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004870b6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004870b9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004870bb  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004870c0  803dbfa04c0000         +cmp byte ptr [0x4ca0bf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004870c7  7e0b                   -jle 0x4870d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004870d4;
    }
    // 004870c9  a0bfa04c00             -mov al, byte ptr [0x4ca0bf]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */);
    // 004870ce  fe0dbfa04c00           -dec byte ptr [0x4ca0bf]
    (app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */))--;
L_0x004870d4:
    // 004870d4  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004870d7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004870d9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004870dd  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004870df  803db4a04c0000         +cmp byte ptr [0x4ca0b4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004870e6  7551                   -jne 0x487139
    if (!cpu.flags.zf)
    {
        goto L_0x00487139;
    }
L_0x004870e8:
    // 004870e8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004870ec  bf54a04c00             -mov edi, 0x4ca054
    cpu.edi = 5021780 /*0x4ca054*/;
    // 004870f1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004870f3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004870f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004870f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004870fb  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004870fe  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00487100  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00487102  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00487105  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00487107  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487108  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048710a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048710d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048710f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487111  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00487113  e898d00000             -call 0x4941b0
    cpu.esp -= 4;
    sub_4941b0(app, cpu);
    if (cpu.terminate) return;
    // 00487118  882db0a04c00           -mov byte ptr [0x4ca0b0], ch
    app->getMemory<x86::reg8>(x86::reg32(5021872) /* 0x4ca0b0 */) = cpu.ch;
    // 0048711e  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487123  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00487125  e8c6f5ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 0048712a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048712f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487132  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487133  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487134  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487135  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487137  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487138  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487139:
    // 00487139  a0bea04c00             -mov al, byte ptr [0x4ca0be]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */);
    // 0048713e  fe05bea04c00           -inc byte ptr [0x4ca0be]
    (app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */))++;
    // 00487144  a0bda04c00             -mov al, byte ptr [0x4ca0bd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */);
    // 00487149  fe0dbda04c00           -dec byte ptr [0x4ca0bd]
    (app->getMemory<x86::reg8>(x86::reg32(5021885) /* 0x4ca0bd */))--;
    // 0048714f  bf24a14c00             -mov edi, 0x4ca124
    cpu.edi = 5021988 /*0x4ca124*/;
    // 00487154  be2ca14c00             -mov esi, 0x4ca12c
    cpu.esi = 5021996 /*0x4ca12c*/;
    // 00487159  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048715a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048715b  ba2ca14c00             -mov edx, 0x4ca12c
    cpu.edx = 5021996 /*0x4ca12c*/;
    // 00487160  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487162  e8d94d0100             -call 0x49bf40
    cpu.esp -= 4;
    sub_49bf40(app, cpu);
    if (cpu.terminate) return;
    // 00487167  803dc0a04c0000         +cmp byte ptr [0x4ca0c0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021888) /* 0x4ca0c0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048716e  743c                   -je 0x4871ac
    if (cpu.flags.zf)
    {
        goto L_0x004871ac;
    }
    // 00487170  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00487175  bf24a14c00             -mov edi, 0x4ca124
    cpu.edi = 5021988 /*0x4ca124*/;
    // 0048717a  be2ca14c00             -mov esi, 0x4ca12c
    cpu.esi = 5021996 /*0x4ca12c*/;
    // 0048717f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487181  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 00487183  7405                   -je 0x48718a
    if (cpu.flags.zf)
    {
        goto L_0x0048718a;
    }
    // 00487185  19c0                   +sbb eax, eax
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
    // 00487187  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048718a:
    // 0048718a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048718c  741e                   -je 0x4871ac
    if (cpu.flags.zf)
    {
        goto L_0x004871ac;
    }
    // 0048718e  803db1a04c0002         +cmp byte ptr [0x4ca0b1], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487195  740e                   -je 0x4871a5
    if (cpu.flags.zf)
    {
        goto L_0x004871a5;
    }
    // 00487197  803db1a04c0003         +cmp byte ptr [0x4ca0b1], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048719e  7405                   -je 0x4871a5
    if (cpu.flags.zf)
    {
        goto L_0x004871a5;
    }
    // 004871a0  e84b070000             -call 0x4878f0
    cpu.esp -= 4;
    sub_4878f0(app, cpu);
    if (cpu.terminate) return;
L_0x004871a5:
    // 004871a5  c605b1a04c0003         -mov byte ptr [0x4ca0b1], 3
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = 3 /*0x3*/;
L_0x004871ac:
    // 004871ac  c605c0a04c0001         -mov byte ptr [0x4ca0c0], 1
    app->getMemory<x86::reg8>(x86::reg32(5021888) /* 0x4ca0c0 */) = 1 /*0x1*/;
    // 004871b3  e930ffffff             -jmp 0x4870e8
    goto L_0x004870e8;
}

/* align: skip  */
void Application::sub_4871b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004871b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004871b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004871ba  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004871bd  8a0dc2a04c00           -mov cl, byte ptr [0x4ca0c2]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
    // 004871c3  3a0dc3a04c00           +cmp cl, byte ptr [0x4ca0c3]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004871c9  7511                   -jne 0x4871dc
    if (!cpu.flags.zf)
    {
        goto L_0x004871dc;
    }
    // 004871cb  0fbe0dc2a04c00         -movsx ecx, byte ptr [0x4ca0c2]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */)));
    // 004871d2  833c8dd0a04c0000       +cmp dword ptr [ecx*4 + 0x4ca0d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004871da  7e0c                   -jle 0x4871e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004871e8;
    }
L_0x004871dc:
    // 004871dc  8a0dc3a04c00           -mov cl, byte ptr [0x4ca0c3]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */);
    // 004871e2  fe05c3a04c00           -inc byte ptr [0x4ca0c3]
    (app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */))++;
L_0x004871e8:
    // 004871e8  803dc3a04c0014         +cmp byte ptr [0x4ca0c3], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004871ef  7c0a                   -jl 0x4871fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004871fb;
    }
    // 004871f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004871f2  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004871f4  881dc3a04c00           -mov byte ptr [0x4ca0c3], bl
    app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */) = cpu.bl;
    // 004871fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004871fb:
    // 004871fb  0fbe0dc3a04c00         -movsx ecx, byte ptr [0x4ca0c3]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */)));
    // 00487202  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00487204  89148dd0a04c00         -mov dword ptr [ecx*4 + 0x4ca0d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.ecx * 4) = cpu.edx;
    // 0048720b  8b0d30a04c00           -mov ecx, dword ptr [0x4ca030]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487211  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487213  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487215  e8d6f4ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 0048721a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048721f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487220  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487221  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487224  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487225  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487226  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487228  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048722b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048722d  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487232  e86ddcffff             -call 0x484ea4
    cpu.esp -= 4;
    sub_484ea4(app, cpu);
    if (cpu.terminate) return;
    // 00487237  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048723c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048723e  e8adf4ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00487243  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00487248  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487249  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048724a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48724c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048724c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048724d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048724e  ff052ca04c00           -inc dword ptr [0x4ca02c]
    (app->getMemory<x86::reg32>(x86::reg32(5021740) /* 0x4ca02c */))++;
    // 00487254  803db2a04c0000         +cmp byte ptr [0x4ca0b2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021874) /* 0x4ca0b2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048725b  750c                   -jne 0x487269
    if (!cpu.flags.zf)
    {
        goto L_0x00487269;
    }
    // 0048725d  8b0d38a04c00           -mov ecx, dword ptr [0x4ca038]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */);
    // 00487263  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x00487269:
    // 00487269  8b0d30a04c00           -mov ecx, dword ptr [0x4ca030]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048726f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487271  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487273  e878f4ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00487278  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0048727d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048727e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048727f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487280  a12ca04c00             -mov eax, dword ptr [0x4ca02c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021740) /* 0x4ca02c */);
    // 00487285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487288  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487289  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048728a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048728b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048728c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048728d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048728f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00487291  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00487293  803dc1a04c0002         +cmp byte ptr [0x4ca0c1], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048729a  0f850e010000           -jne 0x4873ae
    if (!cpu.flags.zf)
    {
        goto L_0x004873ae;
    }
L_0x004872a0:
    // 004872a0  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 004872a5  3b0538a04c00           +cmp eax, dword ptr [0x4ca038]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004872ab  0f8482000000           -je 0x487333
    if (cpu.flags.zf)
    {
        goto L_0x00487333;
    }
    // 004872b1  8b3d34a04c00           -mov edi, dword ptr [0x4ca034]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 004872b7  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 004872bc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004872be  a334a04c00             -mov dword ptr [0x4ca034], eax
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.eax;
    // 004872c3  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004872c6  833d3ca04c0000         +cmp dword ptr [0x4ca03c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004872cd  7410                   -je 0x4872df
    if (cpu.flags.zf)
    {
        goto L_0x004872df;
    }
    // 004872cf  8b153ca04c00           -mov edx, dword ptr [0x4ca03c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
    // 004872d5  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 004872da  e811f4ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
L_0x004872df:
    // 004872df  893d3ca04c00           -mov dword ptr [0x4ca03c], edi
    app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */) = cpu.edi;
    // 004872e5  a14ca04c00             -mov eax, dword ptr [0x4ca04c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */);
    // 004872ea  ff0d4ca04c00           -dec dword ptr [0x4ca04c]
    (app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */))--;
    // 004872f0  292d50a04c00           -sub dword ptr [0x4ca050], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5021776) /* 0x4ca050 */)) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004872f6  a148a04c00             -mov eax, dword ptr [0x4ca048]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */);
    // 004872fb  ff0548a04c00           -inc dword ptr [0x4ca048]
    (app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */))++;
    // 00487301  0fbe05c2a04c00         -movsx eax, byte ptr [0x4ca0c2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */)));
    // 00487308  8b1485d0a04c00         -mov edx, dword ptr [eax*4 + 0x4ca0d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4);
    // 0048730f  ff0c85d0a04c00         -dec dword ptr [eax*4 + 0x4ca0d0]
    (app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4))--;
    // 00487316  0fbe05c2a04c00         -movsx eax, byte ptr [0x4ca0c2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */)));
    // 0048731d  833c85d0a04c0000       +cmp dword ptr [eax*4 + 0x4ca0d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487325  0f8e95000000           -jle 0x4873c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004873c0;
    }
L_0x0048732b:
    // 0048732b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048732d  8825c1a04c00           -mov byte ptr [0x4ca0c1], ah
    app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */) = cpu.ah;
L_0x00487333:
    // 00487333  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487338  3b0538a04c00           +cmp eax, dword ptr [0x4ca038]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048733e  0f85e0000000           -jne 0x487424
    if (!cpu.flags.zf)
    {
        goto L_0x00487424;
    }
    // 00487344  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487349  8338ff                 +cmp dword ptr [eax], -1
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
    // 0048734c  0f84ae000000           -je 0x487400
    if (cpu.flags.zf)
    {
        goto L_0x00487400;
    }
    // 00487352  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487357  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048735a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048735c  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487361  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00487364  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00487366  803dc1a04c0001         +cmp byte ptr [0x4ca0c1], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048736d  7519                   -jne 0x487388
    if (!cpu.flags.zf)
    {
        goto L_0x00487388;
    }
    // 0048736f  0fbe3db5a04c00         -movsx edi, byte ptr [0x4ca0b5]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021877) /* 0x4ca0b5 */)));
    // 00487376  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00487378  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048737a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048737c  e81f74ffff             -call 0x47e7a0
    cpu.esp -= 4;
    sub_47e7a0(app, cpu);
    if (cpu.terminate) return;
    // 00487381  c605c1a04c0002         -mov byte ptr [0x4ca0c1], 2
    app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */) = 2 /*0x2*/;
L_0x00487388:
    // 00487388  803dc1a04c0000         +cmp byte ptr [0x4ca0c1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048738f  7507                   -jne 0x487398
    if (!cpu.flags.zf)
    {
        goto L_0x00487398;
    }
    // 00487391  c605c1a04c0001         -mov byte ptr [0x4ca0c1], 1
    app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */) = 1 /*0x1*/;
L_0x00487398:
    // 00487398  803dc1a04c0002         +cmp byte ptr [0x4ca0c1], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048739f  7505                   -jne 0x4873a6
    if (!cpu.flags.zf)
    {
        goto L_0x004873a6;
    }
    // 004873a1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004873a6:
    // 004873a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004873a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004873ae:
    // 004873ae  803dc1a04c0001         +cmp byte ptr [0x4ca0c1], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004873b5  0f84e5feffff           -je 0x4872a0
    if (cpu.flags.zf)
    {
        goto L_0x004872a0;
    }
    // 004873bb  e973ffffff             -jmp 0x487333
    goto L_0x00487333;
L_0x004873c0:
    // 004873c0  a0bea04c00             -mov al, byte ptr [0x4ca0be]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */);
    // 004873c5  fe0dbea04c00           -dec byte ptr [0x4ca0be]
    (app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */))--;
    // 004873cb  a0c2a04c00             -mov al, byte ptr [0x4ca0c2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
    // 004873d0  3a05c3a04c00           +cmp al, byte ptr [0x4ca0c3]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004873d6  0f844fffffff           -je 0x48732b
    if (cpu.flags.zf)
    {
        goto L_0x0048732b;
    }
    // 004873dc  a0c2a04c00             -mov al, byte ptr [0x4ca0c2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
    // 004873e1  fe05c2a04c00           -inc byte ptr [0x4ca0c2]
    (app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */))++;
    // 004873e7  803dc2a04c0014         +cmp byte ptr [0x4ca0c2], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004873ee  0f8c37ffffff           -jl 0x48732b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048732b;
    }
    // 004873f4  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004873f6  a2c2a04c00             -mov byte ptr [0x4ca0c2], al
    app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */) = cpu.al;
    // 004873fb  e92bffffff             -jmp 0x48732b
    goto L_0x0048732b;
L_0x00487400:
    // 00487400  8b1534a04c00           -mov edx, dword ptr [0x4ca034]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487406  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048740b  e8e0f2ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
    // 00487410  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00487416  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0048741c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048741e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048741f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487420  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487421  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487422  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487423  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487424:
    // 00487424  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487429  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048742c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048742e  8b1d34a04c00           -mov ebx, dword ptr [0x4ca034]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487434  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00487437  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487439  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048743b  a134a04c00             -mov eax, dword ptr [0x4ca034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */);
    // 00487440  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487442  a334a04c00             -mov dword ptr [0x4ca034], eax
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.eax;
    // 00487447  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048744a  833d3ca04c0000         +cmp dword ptr [0x4ca03c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487451  7410                   -je 0x487463
    if (cpu.flags.zf)
    {
        goto L_0x00487463;
    }
    // 00487453  8b153ca04c00           -mov edx, dword ptr [0x4ca03c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */);
    // 00487459  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048745e  e88df2ffff             -call 0x4866f0
    cpu.esp -= 4;
    sub_4866f0(app, cpu);
    if (cpu.terminate) return;
L_0x00487463:
    // 00487463  891d3ca04c00           -mov dword ptr [0x4ca03c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021756) /* 0x4ca03c */) = cpu.ebx;
    // 00487469  a14ca04c00             -mov eax, dword ptr [0x4ca04c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */);
    // 0048746e  ff0d4ca04c00           -dec dword ptr [0x4ca04c]
    (app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */))--;
    // 00487474  290d50a04c00           -sub dword ptr [0x4ca050], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5021776) /* 0x4ca050 */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048747a  a148a04c00             -mov eax, dword ptr [0x4ca048]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */);
    // 0048747f  ff0548a04c00           -inc dword ptr [0x4ca048]
    (app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */))++;
    // 00487485  0fbe05c2a04c00         -movsx eax, byte ptr [0x4ca0c2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */)));
    // 0048748c  8b1485d0a04c00         -mov edx, dword ptr [eax*4 + 0x4ca0d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4);
    // 00487493  ff0c85d0a04c00         -dec dword ptr [eax*4 + 0x4ca0d0]
    (app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4))--;
    // 0048749a  0fbe05c2a04c00         -movsx eax, byte ptr [0x4ca0c2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */)));
    // 004874a1  833c85d0a04c0000       +cmp dword ptr [eax*4 + 0x4ca0d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004874a9  0f8ff7feffff           -jg 0x4873a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004873a6;
    }
    // 004874af  a0bea04c00             -mov al, byte ptr [0x4ca0be]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */);
    // 004874b4  fe0dbea04c00           -dec byte ptr [0x4ca0be]
    (app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */))--;
    // 004874ba  a0c2a04c00             -mov al, byte ptr [0x4ca0c2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
    // 004874bf  3a05c3a04c00           +cmp al, byte ptr [0x4ca0c3]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004874c5  0f84dbfeffff           -je 0x4873a6
    if (cpu.flags.zf)
    {
        goto L_0x004873a6;
    }
    // 004874cb  a0c2a04c00             -mov al, byte ptr [0x4ca0c2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
    // 004874d0  fe05c2a04c00           -inc byte ptr [0x4ca0c2]
    (app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */))++;
    // 004874d6  803dc2a04c0014         +cmp byte ptr [0x4ca0c2], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004874dd  0f8cc3feffff           -jl 0x4873a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004873a6;
    }
    // 004874e3  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004874e5  880dc2a04c00           -mov byte ptr [0x4ca0c2], cl
    app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */) = cpu.cl;
    // 004874eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_487504(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00487504  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487505  e83e0cffff             -call 0x478148
    cpu.esp -= 4;
    sub_478148(app, cpu);
    if (cpu.terminate) return;
    // 0048750a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048750c  7404                   -je 0x487512
    if (cpu.flags.zf)
    {
        goto L_0x00487512;
    }
    // 0048750e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487510  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487511  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487512:
    // 00487512  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487513  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487514  e8d7d30000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00487519  a0b1a04c00             -mov al, byte ptr [0x4ca0b1]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
    // 0048751e  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487520  770c                   -ja 0x48752e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487522  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00487527  ff2485f4744800         -jmp dword ptr [eax*4 + 0x4874f4]
    cpu.ip = app->getMemory<x86::reg32>(4748532 + cpu.eax * 4); goto dynamic_jump;
  case 0x0048752e:
L_0x0048752e:
    // 0048752e  e8d1d30000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487533  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487535  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487536  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487537  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487538  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00487539:
    // 00487539  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048753b:
    // 0048753b  3a0db4a04c00           +cmp cl, byte ptr [0x4ca0b4]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487541  750d                   -jne 0x487550
    if (!cpu.flags.zf)
    {
        goto L_0x00487550;
    }
    // 00487543  a1c4a04c00             -mov eax, dword ptr [0x4ca0c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
    // 00487548  3b05c8a04c00           +cmp eax, dword ptr [0x4ca0c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021896) /* 0x4ca0c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048754e  7dde                   -jge 0x48752e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048752e;
    }
L_0x00487550:
    // 00487550  3a0dbfa04c00           +cmp cl, byte ptr [0x4ca0bf]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487556  7526                   -jne 0x48757e
    if (!cpu.flags.zf)
    {
        goto L_0x0048757e;
    }
    // 00487558  833dcca04c00ff         +cmp dword ptr [0x4ca0cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021900) /* 0x4ca0cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048755f  74cd                   -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487561  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487566  e899f1ffff             -call 0x486704
    cpu.esp -= 4;
    sub_486704(app, cpu);
    if (cpu.terminate) return;
    // 0048756b  3b05cca04c00           +cmp eax, dword ptr [0x4ca0cc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021900) /* 0x4ca0cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487571  0f8c8f000000           -jl 0x487606
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487606;
    }
L_0x00487577:
    // 00487577  c605bfa04c00ff         -mov byte ptr [0x4ca0bf], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */) = 255 /*0xff*/;
L_0x0048757e:
    // 0048757e  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 00487583  e844f0ffff             -call 0x4865cc
    cpu.esp -= 4;
    sub_4865cc(app, cpu);
    if (cpu.terminate) return;
    // 00487588  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048758a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048758c  0f8e91000000           -jle 0x487623
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487623;
    }
L_0x00487592:
    // 00487592  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487594  e87bf9ffff             -call 0x486f14
    cpu.esp -= 4;
    sub_486f14(app, cpu);
    if (cpu.terminate) return;
    // 00487599  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048759b  7c0f                   -jl 0x4875ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004875ac;
    }
    // 0048759d  83f803                 +cmp eax, 3
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
    // 004875a0  0f85b8000000           -jne 0x48765e
    if (!cpu.flags.zf)
    {
        goto L_0x0048765e;
    }
    // 004875a6  ff05c4a04c00           -inc dword ptr [0x4ca0c4]
    (app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */))++;
L_0x004875ac:
    // 004875ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004875ae  7f8b                   -jg 0x48753b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048753b;
    }
    // 004875b0  83faf6                 +cmp edx, -0xa
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
    // 004875b3  7e86                   -jle 0x48753b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048753b;
    }
    // 004875b5  803db4a04c0000         +cmp byte ptr [0x4ca0b4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004875bc  0f846cffffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004875c2  a1c4a04c00             -mov eax, dword ptr [0x4ca0c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
    // 004875c7  3b05c8a04c00           +cmp eax, dword ptr [0x4ca0c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021896) /* 0x4ca0c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004875cd  7d27                   -jge 0x4875f6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004875f6;
    }
    // 004875cf  833dc4a04c0000         +cmp dword ptr [0x4ca0c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004875d6  0f859d000000           -jne 0x487679
    if (!cpu.flags.zf)
    {
        goto L_0x00487679;
    }
L_0x004875dc:
    // 004875dc  833dc4a04c0000         +cmp dword ptr [0x4ca0c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004875e3  0f8445ffffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004875e9  e82ef1ffff             -call 0x48671c
    cpu.esp -= 4;
    sub_48671c(app, cpu);
    if (cpu.terminate) return;
    // 004875ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004875f0  0f8438ffffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
L_0x004875f6:
    // 004875f6  e8f5020000             -call 0x4878f0
    cpu.esp -= 4;
    sub_4878f0(app, cpu);
    if (cpu.terminate) return;
    // 004875fb  e804d30000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487600  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487602  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487603  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487604  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487605  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487606:
    // 00487606  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048760b  e864f1ffff             -call 0x486774
    cpu.esp -= 4;
    sub_486774(app, cpu);
    if (cpu.terminate) return;
    // 00487610  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487612  0f855fffffff           -jne 0x487577
    if (!cpu.flags.zf)
    {
        goto L_0x00487577;
    }
    // 00487618  e8e7d20000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0048761d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048761f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487620  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487621  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487622  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487623:
    // 00487623  83f8f6                 +cmp eax, -0xa
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
    // 00487626  0f8e66ffffff           -jle 0x487592
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487592;
    }
    // 0048762c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048762e  0f8478ffffff           -je 0x4875ac
    if (cpu.flags.zf)
    {
        goto L_0x004875ac;
    }
    // 00487634  833dc4a04c0000         +cmp dword ptr [0x4ca0c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048763b  0f84edfeffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487641  803db4a04c0000         +cmp byte ptr [0x4ca0b4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021876) /* 0x4ca0b4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487648  0f84e0feffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 0048764e  e89d020000             -call 0x4878f0
    cpu.esp -= 4;
    sub_4878f0(app, cpu);
    if (cpu.terminate) return;
    // 00487653  e8acd20000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487658  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048765a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048765b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048765c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048765d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048765e:
    // 0048765e  83f801                 +cmp eax, 1
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
    // 00487661  0f8545ffffff           -jne 0x4875ac
    if (!cpu.flags.zf)
    {
        goto L_0x004875ac;
    }
    // 00487667  803db1a04c0001         +cmp byte ptr [0x4ca0b1], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048766e  0f85bafeffff           -jne 0x48752e
    if (!cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487674  e933ffffff             -jmp 0x4875ac
    goto L_0x004875ac;
L_0x00487679:
    // 00487679  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048767e  e8f1f0ffff             -call 0x486774
    cpu.esp -= 4;
    sub_486774(app, cpu);
    if (cpu.terminate) return;
    // 00487683  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487685  0f856bffffff           -jne 0x4875f6
    if (!cpu.flags.zf)
    {
        goto L_0x004875f6;
    }
    // 0048768b  e94cffffff             -jmp 0x4875dc
    goto L_0x004875dc;
  case 0x00487690:
    // 00487690  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00487692:
    // 00487692  3a0dbfa04c00           +cmp cl, byte ptr [0x4ca0bf]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487698  7526                   -jne 0x4876c0
    if (!cpu.flags.zf)
    {
        goto L_0x004876c0;
    }
    // 0048769a  833dcca04c00ff         +cmp dword ptr [0x4ca0cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021900) /* 0x4ca0cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876a1  0f8487feffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004876a7  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 004876ac  e853f0ffff             -call 0x486704
    cpu.esp -= 4;
    sub_486704(app, cpu);
    if (cpu.terminate) return;
    // 004876b1  3b05cca04c00           +cmp eax, dword ptr [0x4ca0cc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021900) /* 0x4ca0cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876b7  7c6f                   -jl 0x487728
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487728;
    }
L_0x004876b9:
    // 004876b9  c605bfa04c00ff         -mov byte ptr [0x4ca0bf], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5021887) /* 0x4ca0bf */) = 255 /*0xff*/;
L_0x004876c0:
    // 004876c0  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 004876c5  e802efffff             -call 0x4865cc
    cpu.esp -= 4;
    sub_4865cc(app, cpu);
    if (cpu.terminate) return;
    // 004876ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004876cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004876ce  7e71                   -jle 0x487741
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487741;
    }
L_0x004876d0:
    // 004876d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004876d2  e83df8ffff             -call 0x486f14
    cpu.esp -= 4;
    sub_486f14(app, cpu);
    if (cpu.terminate) return;
    // 004876d7  83f801                 +cmp eax, 1
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
    // 004876da  756a                   -jne 0x487746
    if (!cpu.flags.zf)
    {
        goto L_0x00487746;
    }
L_0x004876dc:
    // 004876dc  833d20a14c0000         +cmp dword ptr [0x4ca120], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876e3  0f8445feffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004876e9  e82af7ffff             -call 0x486e18
    cpu.esp -= 4;
    sub_486e18(app, cpu);
    if (cpu.terminate) return;
    // 004876ee  3b0520a14c00           +cmp eax, dword ptr [0x4ca120]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876f4  7c63                   -jl 0x487759
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487759;
    }
    // 004876f6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004876f8  891d20a14c00           -mov dword ptr [0x4ca120], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */) = cpu.ebx;
    // 004876fe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487703  e880cf0000             -call 0x494688
    cpu.esp -= 4;
    sub_494688(app, cpu);
    if (cpu.terminate) return;
    // 00487708  833db8a14c0000         +cmp dword ptr [0x4ca1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048770f  0f8419feffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487715  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487717  ff15b8a14c00           -call dword ptr [0x4ca1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048771d  e8e2d10000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487722  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487724  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487727  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487728:
    // 00487728  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048772d  e842f0ffff             -call 0x486774
    cpu.esp -= 4;
    sub_486774(app, cpu);
    if (cpu.terminate) return;
    // 00487732  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487734  7583                   -jne 0x4876b9
    if (!cpu.flags.zf)
    {
        goto L_0x004876b9;
    }
    // 00487736  e8c9d10000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0048773b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048773d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048773e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048773f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487740  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487741:
    // 00487741  83f8f6                 +cmp eax, -0xa
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
    // 00487744  7e8a                   -jle 0x4876d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004876d0;
    }
L_0x00487746:
    // 00487746  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487748  0f8f44ffffff           -jg 0x487692
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487692;
    }
    // 0048774e  83faf6                 +cmp edx, -0xa
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
    // 00487751  0f8e3bffffff           -jle 0x487692
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487692;
    }
    // 00487757  eb83                   -jmp 0x4876dc
    goto L_0x004876dc;
L_0x00487759:
    // 00487759  a130a04c00             -mov eax, dword ptr [0x4ca030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021744) /* 0x4ca030 */);
    // 0048775e  e811f0ffff             -call 0x486774
    cpu.esp -= 4;
    sub_486774(app, cpu);
    if (cpu.terminate) return;
    // 00487763  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487765  7444                   -je 0x4877ab
    if (cpu.flags.zf)
    {
        goto L_0x004877ab;
    }
    // 00487767  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487769  a0b3a04c00             -mov al, byte ptr [0x4ca0b3]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */);
    // 0048776e  e87d64ffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00487773  83f801                 +cmp eax, 1
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
    // 00487776  0f8fb2fdffff           -jg 0x48752e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048752e;
    }
    // 0048777c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048777e  891520a14c00           -mov dword ptr [0x4ca120], edx
    app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */) = cpu.edx;
    // 00487784  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487786  e8fdce0000             -call 0x494688
    cpu.esp -= 4;
    sub_494688(app, cpu);
    if (cpu.terminate) return;
    // 0048778b  833db8a14c0000         +cmp dword ptr [0x4ca1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487792  0f8496fdffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487798  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048779a  ff15b8a14c00           -call dword ptr [0x4ca1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004877a0  e85fd10000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004877a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004877a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004877ab:
    // 004877ab  e86cefffff             -call 0x48671c
    cpu.esp -= 4;
    sub_48671c(app, cpu);
    if (cpu.terminate) return;
    // 004877b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004877b2  0f8476fdffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004877b8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004877ba  892d20a14c00           -mov dword ptr [0x4ca120], ebp
    app->getMemory<x86::reg32>(x86::reg32(5021984) /* 0x4ca120 */) = cpu.ebp;
    // 004877c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004877c5  e8bece0000             -call 0x494688
    cpu.esp -= 4;
    sub_494688(app, cpu);
    if (cpu.terminate) return;
    // 004877ca  833db8a14c0000         +cmp dword ptr [0x4ca1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004877d1  0f8457fdffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 004877d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004877d9  ff15b8a14c00           -call dword ptr [0x4ca1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004877df  e820d10000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004877e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004877e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877e9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004877ea:
    // 004877ea  e8d9f5ffff             -call 0x486dc8
    cpu.esp -= 4;
    sub_486dc8(app, cpu);
    if (cpu.terminate) return;
    // 004877ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004877f1  0f8f37fdffff           -jg 0x48752e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048752e;
    }
    // 004877f7  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 004877fc  e8ff70ffff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
    // 00487801  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 00487806  e85527ffff             -call 0x479f60
    cpu.esp -= 4;
    sub_479f60(app, cpu);
    if (cpu.terminate) return;
    // 0048780b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048780d  0f841bfdffff           -je 0x48752e
    if (cpu.flags.zf)
    {
        goto L_0x0048752e;
    }
    // 00487813  a0bea04c00             -mov al, byte ptr [0x4ca0be]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */);
    // 00487818  fe0dbea04c00           -dec byte ptr [0x4ca0be]
    (app->getMemory<x86::reg8>(x86::reg32(5021886) /* 0x4ca0be */))--;
    // 0048781e  e8b9f7ffff             -call 0x486fdc
    cpu.esp -= 4;
    sub_486fdc(app, cpu);
    if (cpu.terminate) return;
    // 00487823  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00487825  e812000000             -call 0x48783c
    cpu.esp -= 4;
    sub_48783c(app, cpu);
    if (cpu.terminate) return;
    // 0048782a  8815b1a04c00           -mov byte ptr [0x4ca0b1], dl
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = cpu.dl;
    // 00487830  e8cfd00000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00487835  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487837  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487838  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487839  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048783a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_48783c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048783c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048783d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048783e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048783f  ba88724800             -mov edx, 0x487288
    cpu.edx = 4747912 /*0x487288*/;
    // 00487844  b9806b4800             -mov ecx, 0x486b80
    cpu.ecx = 4746112 /*0x486b80*/;
    // 00487849  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048784b  8915b4a14c00           -mov dword ptr [0x4ca1b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */) = cpu.edx;
    // 00487851  890d88ab4c00           -mov dword ptr [0x4cab88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */) = cpu.ecx;
    // 00487857  891dc4a04c00           -mov dword ptr [0x4ca0c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021892) /* 0x4ca0c4 */) = cpu.ebx;
    // 0048785d  891d48a04c00           -mov dword ptr [0x4ca048], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021768) /* 0x4ca048 */) = cpu.ebx;
    // 00487863  891d4ca04c00           -mov dword ptr [0x4ca04c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021772) /* 0x4ca04c */) = cpu.ebx;
    // 00487869  891d50a04c00           -mov dword ptr [0x4ca050], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021776) /* 0x4ca050 */) = cpu.ebx;
    // 0048786f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487871  891d34a04c00           -mov dword ptr [0x4ca034], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021748) /* 0x4ca034 */) = cpu.ebx;
    // 00487877  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487879  891d38a04c00           -mov dword ptr [0x4ca038], ebx
    app->getMemory<x86::reg32>(x86::reg32(5021752) /* 0x4ca038 */) = cpu.ebx;
    // 0048787f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00487884  890d44a04c00           -mov dword ptr [0x4ca044], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */) = cpu.ecx;
    // 0048788a  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048788c  8825b1a04c00           -mov byte ptr [0x4ca0b1], ah
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = cpu.ah;
    // 00487892  30da                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00487894  8815c2a04c00           -mov byte ptr [0x4ca0c2], dl
    app->getMemory<x86::reg8>(x86::reg32(5021890) /* 0x4ca0c2 */) = cpu.dl;
    // 0048789a  30fe                   -xor dh, bh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048789c  8835c3a04c00           -mov byte ptr [0x4ca0c3], dh
    app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */) = cpu.dh;
    // 004878a2  0fbe05c3a04c00         -movsx eax, byte ptr [0x4ca0c3]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021891) /* 0x4ca0c3 */)));
    // 004878a9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004878ab  890c85d0a04c00         -mov dword ptr [eax*4 + 0x4ca0d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021904) /* 0x4ca0d0 */ + cpu.eax * 4) = cpu.ecx;
    // 004878b2  c605b2a04c0001         -mov byte ptr [0x4ca0b2], 1
    app->getMemory<x86::reg8>(x86::reg32(5021874) /* 0x4ca0b2 */) = 1 /*0x1*/;
    // 004878b9  30ef                   -xor bh, ch
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004878bb  883dc1a04c00           -mov byte ptr [0x4ca0c1], bh
    app->getMemory<x86::reg8>(x86::reg32(5021889) /* 0x4ca0c1 */) = cpu.bh;
    // 004878c1  803dbca04c0000         +cmp byte ptr [0x4ca0bc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004878c8  7406                   -je 0x4878d0
    if (cpu.flags.zf)
    {
        goto L_0x004878d0;
    }
    // 004878ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004878cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004878d0:
    // 004878d0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004878d5  b804754800             -mov eax, 0x487504
    cpu.eax = 4748548 /*0x487504*/;
    // 004878da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004878dc  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 004878de  e8bd06ffff             -call 0x477fa0
    cpu.esp -= 4;
    sub_477fa0(app, cpu);
    if (cpu.terminate) return;
    // 004878e3  882dbca04c00           -mov byte ptr [0x4ca0bc], ch
    app->getMemory<x86::reg8>(x86::reg32(5021884) /* 0x4ca0bc */) = cpu.ch;
    // 004878e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004878eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4878f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004878f0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004878f3  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 004878f8  e86326ffff             -call 0x479f60
    cpu.esp -= 4;
    sub_479f60(app, cpu);
    if (cpu.terminate) return;
    // 004878fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004878ff  7509                   -jne 0x48790a
    if (!cpu.flags.zf)
    {
        goto L_0x0048790a;
    }
    // 00487901  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00487906  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487909  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048790a:
    // 0048790a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048790b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048790f  e88c19ffff             -call 0x4792a0
    cpu.esp -= 4;
    sub_4792a0(app, cpu);
    if (cpu.terminate) return;
    // 00487914  a0b6a04c00             -mov al, byte ptr [0x4ca0b6]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */);
    // 00487919  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0048791d  a0b7a04c00             -mov al, byte ptr [0x4ca0b7]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021879) /* 0x4ca0b7 */);
    // 00487922  8844240b               -mov byte ptr [esp + 0xb], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.al;
    // 00487926  a0b8a04c00             -mov al, byte ptr [0x4ca0b8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021880) /* 0x4ca0b8 */);
    // 0048792b  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0048792f  a0b9a04c00             -mov al, byte ptr [0x4ca0b9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5021881) /* 0x4ca0b9 */);
    // 00487934  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487938  8844240e               -mov byte ptr [esp + 0xe], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0048793c  b854a04c00             -mov eax, 0x4ca054
    cpu.eax = 5021780 /*0x4ca054*/;
    // 00487941  e84acc0000             -call 0x494590
    cpu.esp -= 4;
    sub_494590(app, cpu);
    if (cpu.terminate) return;
    // 00487946  a344a04c00             -mov dword ptr [0x4ca044], eax
    app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */) = cpu.eax;
    // 0048794b  833d44a04c0000         +cmp dword ptr [0x4ca044], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487952  7c5b                   -jl 0x4879af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004879af;
    }
    // 00487954  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487955  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 0048795a  e89dd30000             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0048795f  a2b5a04c00             -mov byte ptr [0x4ca0b5], al
    app->getMemory<x86::reg8>(x86::reg32(5021877) /* 0x4ca0b5 */) = cpu.al;
    // 00487964  0fbe15b5a04c00         -movsx edx, byte ptr [0x4ca0b5]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5021877) /* 0x4ca0b5 */)));
    // 0048796b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487972  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487974  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00487977  8a800b845200           -mov al, byte ptr [eax + 0x52840b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407755) /* 0x52840b */);
    // 0048797d  a2b3a04c00             -mov byte ptr [0x4ca0b3], al
    app->getMemory<x86::reg8>(x86::reg32(5021875) /* 0x4ca0b3 */) = cpu.al;
    // 00487982  c605b1a04c0002         -mov byte ptr [0x4ca0b1], 2
    app->getMemory<x86::reg8>(x86::reg32(5021873) /* 0x4ca0b1 */) = 2 /*0x2*/;
    // 00487989  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048798b  8815b0a04c00           -mov byte ptr [0x4ca0b0], dl
    app->getMemory<x86::reg8>(x86::reg32(5021872) /* 0x4ca0b0 */) = cpu.dl;
    // 00487991  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487993  66891dbaa04c00         -mov word ptr [0x4ca0ba], bx
    app->getMemory<x86::reg16>(x86::reg32(5021882) /* 0x4ca0ba */) = cpu.bx;
    // 0048799a  b89c6e4800             -mov eax, 0x486e9c
    cpu.eax = 4746908 /*0x486e9c*/;
    // 0048799f  e84ccc0000             -call 0x4945f0
    cpu.esp -= 4;
    sub_4945f0(app, cpu);
    if (cpu.terminate) return;
    // 004879a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a5  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 004879aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879ab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004879ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004879af:
    // 004879af  66a1baa04c00           -mov ax, word ptr [0x4ca0ba]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5021882) /* 0x4ca0ba */);
    // 004879b5  66ff05baa04c00         -inc word ptr [0x4ca0ba]
    (app->getMemory<x86::reg16>(x86::reg32(5021882) /* 0x4ca0ba */))++;
    // 004879bc  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 004879c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879c2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004879c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4879d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004879d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004879d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004879d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004879d3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004879d6  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004879da  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004879dd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004879e1  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004879e5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004879e9  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004879ed  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004879f1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004879f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004879f7  bdd0070000             -mov ebp, 0x7d0
    cpu.ebp = 2000 /*0x7d0*/;
    // 004879fc  e88f460100             -call 0x49c090
    cpu.esp -= 4;
    sub_49c090(app, cpu);
    if (cpu.terminate) return;
    // 00487a01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a03  0f8494000000           -je 0x487a9d
    if (cpu.flags.zf)
    {
        goto L_0x00487a9d;
    }
    // 00487a09  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487a0d  2b1424                 -sub edx, dword ptr [esp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00487a10  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487a12  0f8c8e000000           -jl 0x487aa6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487aa6;
    }
    // 00487a18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00487a1a:
    // 00487a1a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487a1e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487a20  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487a24  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00487a26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a28  0f8c81000000           -jl 0x487aaf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487aaf;
    }
    // 00487a2e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00487a30:
    // 00487a30  39cb                   +cmp ebx, ecx
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
    // 00487a32  0f8e9c010000           -jle 0x487bd4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487bd4;
    }
    // 00487a38  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487a3a  0f8c78000000           -jl 0x487ab8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ab8;
    }
L_0x00487a40:
    // 00487a40  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487a44  2b0424                 -sub eax, dword ptr [esp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00487a47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a49  0f8c8c000000           -jl 0x487adb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487adb;
    }
L_0x00487a4f:
    // 00487a4f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487a53  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00487a57  2b4c2404               -sub ecx, dword ptr [esp + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00487a5b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487a5d  0f8c7f000000           -jl 0x487ae2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ae2;
    }
    // 00487a63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00487a65:
    // 00487a65  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00487a69  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00487a6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487a6f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487a72  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487a74  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00487a76  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487a78  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487a7a  7c6f                   -jl 0x487aeb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487aeb;
    }
    // 00487a7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487a81:
    // 00487a81  8a1dec844c00           -mov bl, byte ptr [0x4c84ec]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00487a87  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487a8b  80fb08                 +cmp bl, 8
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487a8e  0f85a3000000           -jne 0x487b37
    if (!cpu.flags.zf)
    {
        goto L_0x00487b37;
    }
L_0x00487a94:
    // 00487a94  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487a97  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487a9b  7e55                   -jle 0x487af2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487af2;
    }
L_0x00487a9d:
    // 00487a9d  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00487aa0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aa1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aa2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aa3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00487aa6:
    // 00487aa6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487aa8  f7d8                   +neg eax
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
    // 00487aaa  e96bffffff             -jmp 0x487a1a
    goto L_0x00487a1a;
L_0x00487aaf:
    // 00487aaf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487ab1  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00487ab3  e978ffffff             -jmp 0x487a30
    goto L_0x00487a30;
L_0x00487ab8:
    // 00487ab8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487abc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487abf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487ac2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00487ac6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487aca  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487ace  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00487ad2  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00487ad6  e965ffffff             -jmp 0x487a40
    goto L_0x00487a40;
L_0x00487adb:
    // 00487adb  f7d8                   +neg eax
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
    // 00487add  e96dffffff             -jmp 0x487a4f
    goto L_0x00487a4f;
L_0x00487ae2:
    // 00487ae2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487ae4  f7d8                   +neg eax
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
    // 00487ae6  e97affffff             -jmp 0x487a65
    goto L_0x00487a65;
L_0x00487aeb:
    // 00487aeb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00487af0  eb8f                   -jmp 0x487a81
    goto L_0x00487a81;
L_0x00487af2:
    // 00487af2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487af6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487af8  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00487afe  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 00487b01  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00487b07  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00487b09  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487b0c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00487b10  40                     -inc eax
    (cpu.eax)++;
    // 00487b11  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487b13  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487b16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487b18  0f8d76ffffff           -jge 0x487a94
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487a94;
    }
    // 00487b1e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487b22  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487b26  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00487b2a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487b2c  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487b2e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00487b32  e95dffffff             -jmp 0x487a94
    goto L_0x00487a94;
L_0x00487b37:
    // 00487b37  80fb0f                 +cmp bl, 0xf
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487b3a  754d                   -jne 0x487b89
    if (!cpu.flags.zf)
    {
        goto L_0x00487b89;
    }
L_0x00487b3c:
    // 00487b3c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487b3f  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487b43  0f8f54ffffff           -jg 0x487a9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a9d;
    }
    // 00487b49  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487b4d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487b4f  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00487b55  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00487b58  0315f0844c00           -add edx, dword ptr [0x4c84f0]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00487b5e  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 00487b62  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487b65  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00487b69  40                     -inc eax
    (cpu.eax)++;
    // 00487b6a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487b6c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487b6f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487b71  7dc9                   -jge 0x487b3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487b3c;
    }
    // 00487b73  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487b77  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487b7b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00487b7f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487b81  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487b83  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00487b87  ebb3                   -jmp 0x487b3c
    goto L_0x00487b3c;
L_0x00487b89:
    // 00487b89  80fb10                 +cmp bl, 0x10
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487b8c  74ae                   -je 0x487b3c
    if (cpu.flags.zf)
    {
        goto L_0x00487b3c;
    }
L_0x00487b8e:
    // 00487b8e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487b91  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487b95  0f8f02ffffff           -jg 0x487a9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a9d;
    }
    // 00487b9b  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00487b9c  0f84fbfeffff           -je 0x487a9d
    if (cpu.flags.zf)
    {
        goto L_0x00487a9d;
    }
    // 00487ba2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487ba6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487ba8  e8c3460100             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
    // 00487bad  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487bb0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00487bb4  43                     -inc ebx
    (cpu.ebx)++;
    // 00487bb5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00487bb7  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00487bba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487bbc  7dd0                   -jge 0x487b8e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487b8e;
    }
    // 00487bbe  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487bc2  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487bc6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00487bca  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487bcc  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487bce  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00487bd2  ebba                   -jmp 0x487b8e
    goto L_0x00487b8e;
L_0x00487bd4:
    // 00487bd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487bd6  0f8ca1000000           -jl 0x487c7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487c7d;
    }
L_0x00487bdc:
    // 00487bdc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487be0  2b0c24                 -sub ecx, dword ptr [esp]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00487be3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487be5  0f8cb5000000           -jl 0x487ca0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ca0;
    }
    // 00487beb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00487bed:
    // 00487bed  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487bf1  2b542404               -sub edx, dword ptr [esp + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00487bf5  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00487bf9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487bfb  0f8ca8000000           -jl 0x487ca9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ca9;
    }
L_0x00487c01:
    // 00487c01  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00487c05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487c07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487c0a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487c0c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00487c0e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487c10  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487c12  0f8c98000000           -jl 0x487cb0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487cb0;
    }
    // 00487c18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487c1d:
    // 00487c1d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00487c21  8a25ec844c00           -mov ah, byte ptr [0x4c84ec]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00487c27  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487c2a  0f858a000000           -jne 0x487cba
    if (!cpu.flags.zf)
    {
        goto L_0x00487cba;
    }
L_0x00487c30:
    // 00487c30  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487c34  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487c38  0f8f5ffeffff           -jg 0x487a9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a9d;
    }
    // 00487c3e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487c40  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487c42  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487c45  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00487c4b  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 00487c4e  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00487c54  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00487c56  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487c5a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00487c5e  40                     -inc eax
    (cpu.eax)++;
    // 00487c5f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487c61  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00487c65  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487c67  7dc7                   -jge 0x487c30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487c30;
    }
    // 00487c69  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487c6d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487c70  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00487c74  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487c76  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487c78  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00487c7b  ebb3                   -jmp 0x487c30
    goto L_0x00487c30;
L_0x00487c7d:
    // 00487c7d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487c81  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487c85  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00487c89  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00487c8d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487c91  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487c94  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487c97  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00487c9b  e93cffffff             -jmp 0x487bdc
    goto L_0x00487bdc;
L_0x00487ca0:
    // 00487ca0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487ca2  f7d8                   +neg eax
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
    // 00487ca4  e944ffffff             -jmp 0x487bed
    goto L_0x00487bed;
L_0x00487ca9:
    // 00487ca9  f7da                   +neg edx
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
    // 00487cab  e951ffffff             -jmp 0x487c01
    goto L_0x00487c01;
L_0x00487cb0:
    // 00487cb0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00487cb5  e963ffffff             -jmp 0x487c1d
    goto L_0x00487c1d;
L_0x00487cba:
    // 00487cba  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487cbd  754f                   -jne 0x487d0e
    if (!cpu.flags.zf)
    {
        goto L_0x00487d0e;
    }
L_0x00487cbf:
    // 00487cbf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487cc3  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487cc7  0f8fd0fdffff           -jg 0x487a9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a9d;
    }
    // 00487ccd  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487ccf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487cd1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487cd4  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00487cda  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00487cdd  0315f0844c00           -add edx, dword ptr [0x4c84f0]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00487ce3  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 00487ce7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487ceb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00487cef  40                     -inc eax
    (cpu.eax)++;
    // 00487cf0  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487cf2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00487cf6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487cf8  7dc5                   -jge 0x487cbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487cbf;
    }
    // 00487cfa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487cfe  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487d01  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00487d05  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487d07  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487d09  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00487d0c  ebb1                   -jmp 0x487cbf
    goto L_0x00487cbf;
L_0x00487d0e:
    // 00487d0e  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487d11  74ac                   -je 0x487cbf
    if (cpu.flags.zf)
    {
        goto L_0x00487cbf;
    }
L_0x00487d13:
    // 00487d13  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487d17  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487d1b  0f8f7cfdffff           -jg 0x487a9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a9d;
    }
    // 00487d21  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00487d22  0f8475fdffff           -je 0x487a9d
    if (cpu.flags.zf)
    {
        goto L_0x00487a9d;
    }
    // 00487d28  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00487d2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487d2c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487d2f  e83c450100             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
    // 00487d34  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487d38  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00487d3c  43                     -inc ebx
    (cpu.ebx)++;
    // 00487d3d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00487d3f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00487d43  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487d45  7dcc                   -jge 0x487d13
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487d13;
    }
    // 00487d47  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487d4b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487d4e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00487d52  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487d54  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487d56  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00487d59  ebb8                   -jmp 0x487d13
    goto L_0x00487d13;
}

/* align: skip  */
void Application::sub_487d5b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487d5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487d5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487d5d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00487d60  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487d62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487d64  7514                   -jne 0x487d7a
    if (!cpu.flags.zf)
    {
        goto L_0x00487d7a;
    }
    // 00487d66  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487d6c  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00487d6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487d71  7507                   -jne 0x487d7a
    if (!cpu.flags.zf)
    {
        goto L_0x00487d7a;
    }
L_0x00487d73:
    // 00487d73  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487d75  e97f000000             -jmp 0x487df9
    goto L_0x00487df9;
L_0x00487d7a:
    // 00487d7a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487d7c  e8a6450100             -call 0x49c327
    cpu.esp -= 4;
    sub_49c327(app, cpu);
    if (cpu.terminate) return;
    // 00487d81  eb1f                   -jmp 0x487da2
    goto L_0x00487da2;
L_0x00487d83:
    // 00487d83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d85  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00487d88  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487d8a  8a0c04                 -mov cl, byte ptr [esp + eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00487d8d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d8f  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00487d92  8a8098fc4b00           -mov al, byte ptr [eax + 0x4bfc98]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4979864) /* 0x4bfc98 */);
    // 00487d98  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00487d9d  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00487d9f  7409                   -je 0x487daa
    if (cpu.flags.zf)
    {
        goto L_0x00487daa;
    }
    // 00487da1  43                     -inc ebx
    (cpu.ebx)++;
L_0x00487da2:
    // 00487da2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487da4  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00487da6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487da8  75d9                   -jne 0x487d83
    if (!cpu.flags.zf)
    {
        goto L_0x00487d83;
    }
L_0x00487daa:
    // 00487daa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487dac  74c5                   -je 0x487d73
    if (cpu.flags.zf)
    {
        goto L_0x00487d73;
    }
    // 00487dae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00487db0  eb30                   -jmp 0x487de2
    goto L_0x00487de2;
L_0x00487db2:
    // 00487db2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487db4  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 00487db7  8a0c0c                 -mov cl, byte ptr [esp + ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1);
    // 00487dba  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00487dbd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00487dc3  8a8098fc4b00           -mov al, byte ptr [eax + 0x4bfc98]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4979864) /* 0x4bfc98 */);
    // 00487dc9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00487dce  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00487dd0  740f                   -je 0x487de1
    if (cpu.flags.zf)
    {
        goto L_0x00487de1;
    }
    // 00487dd2  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00487dd5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00487dd6  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ddc  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00487ddf  eb16                   -jmp 0x487df7
    goto L_0x00487df7;
L_0x00487de1:
    // 00487de1  42                     -inc edx
    (cpu.edx)++;
L_0x00487de2:
    // 00487de2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487de4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00487de6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487de8  75c8                   -jne 0x487db2
    if (!cpu.flags.zf)
    {
        goto L_0x00487db2;
    }
    // 00487dea  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487df0  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00487df7:
    // 00487df7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00487df9:
    // 00487df9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00487dfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487dff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487dff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487e00  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00487e02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487e03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487e04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e05  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487e08  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00487e0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487e0c  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00487e0f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e10  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00487e13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487e14  e84d450100             -call 0x49c366
    cpu.esp -= 4;
    sub_49c366(app, cpu);
    if (cpu.terminate) return;
    // 00487e19  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00487e1b  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00487e1d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00487e1f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00487e20  760c                   -jbe 0x487e2e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487e2e;
    }
    // 00487e22  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00487e25  dc0520ea4b00           -fadd qword ptr [0x4bea20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4975136) /* 0x4bea20 */));
    // 00487e2b  dd5dec                 -fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00487e2e:
    // 00487e2e  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00487e31  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00487e34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e36  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e38  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_487e3b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487e3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487e3c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00487e3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487e3f  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00487e42  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487e45  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00487e47  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487e4a  e8b0ffffff             -call 0x487dff
    cpu.esp -= 4;
    sub_487dff(app, cpu);
    if (cpu.terminate) return;
    // 00487e4f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00487e51  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e53  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487e60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487e62  e8f5e4feff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 00487e67  8b1588a84c00           -mov edx, dword ptr [0x4ca888]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023880) /* 0x4ca888 */);
    // 00487e6d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487e6f  7548                   -jne 0x487eb9
    if (!cpu.flags.zf)
    {
        goto L_0x00487eb9;
    }
    // 00487e71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487e72  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00487e77  e88c71ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00487e7c  a174b55100             -mov eax, dword ptr [0x51b574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354868) /* 0x51b574 */);
    // 00487e81  e82abeffff             -call 0x483cb0
    cpu.esp -= 4;
    sub_483cb0(app, cpu);
    if (cpu.terminate) return;
    // 00487e86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487e88  7521                   -jne 0x487eab
    if (!cpu.flags.zf)
    {
        goto L_0x00487eab;
    }
    // 00487e8a  833d80b5510000         +cmp dword ptr [0x51b580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354880) /* 0x51b580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487e91  7418                   -je 0x487eab
    if (cpu.flags.zf)
    {
        goto L_0x00487eab;
    }
    // 00487e93  803d93b5510001         +cmp byte ptr [0x51b593], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487e9a  7626                   -jbe 0x487ec2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487ec2;
    }
    // 00487e9c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00487ea1  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00487ea6  e8fdb6ffff             -call 0x4835a8
    cpu.esp -= 4;
    sub_4835a8(app, cpu);
    if (cpu.terminate) return;
L_0x00487eab:
    // 00487eab  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00487eb0  e86b71ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00487eb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487eb9:
    // 00487eb9  ff1588a84c00           -call dword ptr [0x4ca888]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023880) /* 0x4ca888 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ebf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ec0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ec1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487ec2:
    // 00487ec2  8b1d78b55100           -mov ebx, dword ptr [0x51b578]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5354872) /* 0x51b578 */);
    // 00487ec8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487eca  7533                   -jne 0x487eff
    if (!cpu.flags.zf)
    {
        goto L_0x00487eff;
    }
    // 00487ecc  a17cb55100             -mov eax, dword ptr [0x51b57c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354876) /* 0x51b57c */);
    // 00487ed1  e872e5feff             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 00487ed6  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487edd  7459                   -je 0x487f38
    if (cpu.flags.zf)
    {
        goto L_0x00487f38;
    }
    // 00487edf  a180b55100             -mov eax, dword ptr [0x51b580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354880) /* 0x51b580 */);
    // 00487ee4  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00487ee7  e8c4440100             -call 0x49c3b0
    cpu.esp -= 4;
    sub_49c3b0(app, cpu);
    if (cpu.terminate) return;
    // 00487eec  e86be4feff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 00487ef1  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00487ef6  e82571ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00487efb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487eff:
    // 00487eff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487f01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487f02  8b3d48b15100           -mov edi, dword ptr [0x51b148]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */);
    // 00487f08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f09  8b2d44b15100           -mov ebp, dword ptr [0x51b144]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */);
    // 00487f0f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487f10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487f11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487f12  a174b55100             -mov eax, dword ptr [0x51b574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354868) /* 0x51b574 */);
    // 00487f17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f18  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00487f1a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00487f1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f1d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487f1f  31fa                   -xor edx, edi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487f21  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487f23  e810c0ffff             -call 0x483f38
    cpu.esp -= 4;
    sub_483f38(app, cpu);
    if (cpu.terminate) return;
    // 00487f28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f2a  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00487f2f  e8ec70ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00487f34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487f38:
    // 00487f38  a180b55100             -mov eax, dword ptr [0x51b580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354880) /* 0x51b580 */);
    // 00487f3d  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00487f40  e89b8c0000             -call 0x490be0
    cpu.esp -= 4;
    sub_490be0(app, cpu);
    if (cpu.terminate) return;
    // 00487f45  e812e4feff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 00487f4a  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00487f4f  e8cc70ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00487f54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487f58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487f59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487f5a  891dbca14c00           -mov dword ptr [0x4ca1bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ebx;
    // 00487f60  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487f62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00487f64:
    // 00487f64  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487f66  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487f68  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00487f6a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487f6c  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 00487f6f  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00487f74  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00487f77  8b2c9d105e5200         -mov ebp, dword ptr [ebx*4 + 0x525e10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5398032) /* 0x525e10 */ + cpu.ebx * 4);
    // 00487f7e  8b3cbd105a5200         -mov edi, dword ptr [edi*4 + 0x525a10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.edi * 4);
    // 00487f85  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487f88  8b0485105c5200         -mov eax, dword ptr [eax*4 + 0x525c10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5397520) /* 0x525c10 */ + cpu.eax * 4);
    // 00487f8f  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00487f91  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487f93  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00487f95  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487f97  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487f99  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 00487f9c  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 00487fa2  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 00487fa5  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00487fab  8b048548555200         -mov eax, dword ptr [eax*4 + 0x525548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.eax * 4);
    // 00487fb2  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 00487fb5  8b0c8d30515200         -mov ecx, dword ptr [ecx*4 + 0x525130]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.ecx * 4);
    // 00487fbc  8b3cbda84b5200         -mov edi, dword ptr [edi*4 + 0x524ba8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.edi * 4);
    // 00487fc3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00487fc5  8b1c9d105a5200         -mov ebx, dword ptr [ebx*4 + 0x525a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.ebx * 4);
    // 00487fcc  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00487fce  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00487fd0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00487fd2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487fd4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00487fd6  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 00487fdc  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 00487fdf  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00487fe5  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 00487fe8  8b0dbca14c00           -mov ecx, dword ptr [0x4ca1bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */);
    // 00487fee  8b048548555200         -mov eax, dword ptr [eax*4 + 0x525548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.eax * 4);
    // 00487ff5  8b3cbda84b5200         -mov edi, dword ptr [edi*4 + 0x524ba8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.edi * 4);
    // 00487ffc  8b1c9d30515200         -mov ebx, dword ptr [ebx*4 + 0x525130]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.ebx * 4);
    // 00488003  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00488005  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00488007  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048800d  250000ffff             -and eax, 0xffff0000
    cpu.eax &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00488012  09e8                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00488014  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00488015  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 0048801b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048801d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00488020  0f853effffff           -jne 0x487f64
    if (!cpu.flags.zf)
    {
        goto L_0x00487f64;
    }
    // 00488026  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488027  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488029  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048802a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48802b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048802b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048802c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048802d  891dbca14c00           -mov dword ptr [0x4ca1bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ebx;
    // 00488033  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488035  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488036  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00488037:
    // 00488037  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00488039  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048803b  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0048803d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048803f  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 00488042  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00488047  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0048804a  8b2c9d105e5200         -mov ebp, dword ptr [ebx*4 + 0x525e10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5398032) /* 0x525e10 */ + cpu.ebx * 4);
    // 00488051  8b3cbd105a5200         -mov edi, dword ptr [edi*4 + 0x525a10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.edi * 4);
    // 00488058  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048805b  8b0485105c5200         -mov eax, dword ptr [eax*4 + 0x525c10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5397520) /* 0x525c10 */ + cpu.eax * 4);
    // 00488062  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488064  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488066  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00488068  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048806a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048806c  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0048806f  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 00488075  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 00488078  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048807e  8b048548555200         -mov eax, dword ptr [eax*4 + 0x525548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.eax * 4);
    // 00488085  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 00488088  8b0c8d30515200         -mov ecx, dword ptr [ecx*4 + 0x525130]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.ecx * 4);
    // 0048808f  8b3cbda84b5200         -mov edi, dword ptr [edi*4 + 0x524ba8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.edi * 4);
    // 00488096  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488098  8b1c9d105a5200         -mov ebx, dword ptr [ebx*4 + 0x525a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.ebx * 4);
    // 0048809f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004880a1  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004880a3  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004880a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004880a7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004880a9  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004880af  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004880b2  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004880b8  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 004880bb  8b0dbca14c00           -mov ecx, dword ptr [0x4ca1bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */);
    // 004880c1  8b048548555200         -mov eax, dword ptr [eax*4 + 0x525548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.eax * 4);
    // 004880c8  8b3cbda84b5200         -mov edi, dword ptr [edi*4 + 0x524ba8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.edi * 4);
    // 004880cf  8b1c9d30515200         -mov ebx, dword ptr [ebx*4 + 0x525130]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.ebx * 4);
    // 004880d6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004880d8  01d8                   +add eax, ebx
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
    // 004880da  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004880db  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 004880e1  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004880e4  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004880e7  0f854affffff           -jne 0x488037
    if (!cpu.flags.zf)
    {
        goto L_0x00488037;
    }
    // 004880ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4880f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004880f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004880f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004880f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004880f6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004880f8  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 004880fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004880ff:
    // 004880ff  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00488101  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00488103  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488105  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488108  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0048810a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048810d  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00488112  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488114  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488116  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488118  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0048811b  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048811d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00488120  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488126  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 00488129  8b1495105e5200         -mov edx, dword ptr [edx*4 + 0x525e10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5398032) /* 0x525e10 */ + cpu.edx * 4);
    // 00488130  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488136  8b0c8d105c5200         -mov ecx, dword ptr [ecx*4 + 0x525c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5397520) /* 0x525c10 */ + cpu.ecx * 4);
    // 0048813d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048813f  8b0485105a5200         -mov eax, dword ptr [eax*4 + 0x525a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.eax * 4);
    // 00488146  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488148  8b2cad105a5200         -mov ebp, dword ptr [ebp*4 + 0x525a10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5397008) /* 0x525a10 */ + cpu.ebp * 4);
    // 0048814f  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488151  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488153  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 00488156  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488158  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0048815b  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00488160  8b149548555200         -mov edx, dword ptr [edx*4 + 0x525548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.edx * 4);
    // 00488167  81e1ff010000           -and ecx, 0x1ff
    cpu.ecx &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048816d  8b0485a84b5200         -mov eax, dword ptr [eax*4 + 0x524ba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.eax * 4);
    // 00488174  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488177  8b0c8d30515200         -mov ecx, dword ptr [ecx*4 + 0x525130]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.ecx * 4);
    // 0048817e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488180  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488182  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00488184  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 00488187  8943f8                 -mov dword ptr [ebx - 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0048818a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048818c  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00488192  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00488195  8b149548555200         -mov edx, dword ptr [edx*4 + 0x525548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5395784) /* 0x525548 */ + cpu.edx * 4);
    // 0048819c  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004881a1  8b2cada84b5200         -mov ebp, dword ptr [ebp*4 + 0x524ba8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5393320) /* 0x524ba8 */ + cpu.ebp * 4);
    // 004881a8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004881aa  8b0dbca14c00           -mov ecx, dword ptr [0x4ca1bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */);
    // 004881b0  8b048530515200         -mov eax, dword ptr [eax*4 + 0x525130]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5394736) /* 0x525130 */ + cpu.eax * 4);
    // 004881b7  01d0                   +add eax, edx
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
    // 004881b9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004881ba  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 004881c0  90                     -nop 
    ;
    // 004881c1  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004881c4  0f8535ffffff           -jne 0x4880ff
    if (!cpu.flags.zf)
    {
        goto L_0x004880ff;
    }
    // 004881ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4881ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004881ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004881cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004881d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004881d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004881d2:
    // 004881d2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004881d4  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004881d7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004881d9  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004881db  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004881de  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 004881e4  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004881e7  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 004881ed  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004881f3  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004881f5  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004881f7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004881fa  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004881fc  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004881ff  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00488201  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 00488207  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00488209  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 0048820f  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 00488212  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488214  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0048821a  897afc                 -mov dword ptr [edx - 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0048821d  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048821f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00488220  8972f8                 -mov dword ptr [edx - 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00488223  75ad                   -jne 0x4881d2
    if (!cpu.flags.zf)
    {
        goto L_0x004881d2;
    }
    // 00488225  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488226  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488227  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488228  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488229  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48822a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048822a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048822b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048822c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048822d  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 00488233  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00488235  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00488237  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00488239  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048823c  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048823e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488241  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00488247  893dc0a14c00           -mov dword ptr [0x4ca1c0], edi
    app->getMemory<x86::reg32>(x86::reg32(5022144) /* 0x4ca1c0 */) = cpu.edi;
L_0x0048824d:
    // 0048824d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048824f  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00488251  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00488253  8b35c0a14c00           -mov esi, dword ptr [0x4ca1c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022144) /* 0x4ca1c0 */);
    // 00488259  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048825b  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048825e  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 00488264  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00488266  893dc0a14c00           -mov dword ptr [0x4ca1c0], edi
    app->getMemory<x86::reg32>(x86::reg32(5022144) /* 0x4ca1c0 */) = cpu.edi;
    // 0048826c  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048826e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00488271  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 00488277  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048827a  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 00488280  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 00488286  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488288  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048828a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048828d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048828f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488292  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 00488294  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 0048829a  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048829c  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 004882a2  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004882a5  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004882a7  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004882ad  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004882b0  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004882b2  8b0dbca14c00           -mov ecx, dword ptr [0x4ca1bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */);
    // 004882b8  8973f8                 -mov dword ptr [ebx - 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 004882bb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004882bc  890dbca14c00           -mov dword ptr [0x4ca1bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022140) /* 0x4ca1bc */) = cpu.ecx;
    // 004882c2  7589                   -jne 0x48824d
    if (!cpu.flags.zf)
    {
        goto L_0x0048824d;
    }
    // 004882c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4882c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004882c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004882ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004882cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004882cc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004882ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004882d0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004882d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004882d4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004882d6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004882d8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004882da:
    // 004882da  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004882dc  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004882df  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004882e2  8a5603                 -mov dl, byte ptr [esi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004882e5  8a80c4a14c00           -mov al, byte ptr [eax + 0x4ca1c4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 004882eb  8a9bc4a14c00           -mov bl, byte ptr [ebx + 0x4ca1c4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 004882f1  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004882f4  8a89c4a14c00           -mov cl, byte ptr [ecx + 0x4ca1c4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 004882fa  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004882fd  8a92c4a14c00           -mov dl, byte ptr [edx + 0x4ca1c4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 00488303  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488305  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00488307  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048830a  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048830d  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048830f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488311  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00488313  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488315  8a4efc                 -mov cl, byte ptr [esi - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00488318  8a56fd                 -mov dl, byte ptr [esi - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */);
    // 0048831b  8a46fe                 -mov al, byte ptr [esi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0048831e  8a5eff                 -mov bl, byte ptr [esi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00488321  8a89c4a14c00           -mov cl, byte ptr [ecx + 0x4ca1c4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 00488327  8a92c4a14c00           -mov dl, byte ptr [edx + 0x4ca1c4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 0048832d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00488330  8a80c4a14c00           -mov al, byte ptr [eax + 0x4ca1c4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 00488336  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00488339  8a9bc4a14c00           -mov bl, byte ptr [ebx + 0x4ca1c4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5022148) /* 0x4ca1c4 */);
    // 0048833f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00488341  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488343  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00488346  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488349  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048834b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048834d  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00488350  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488352  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00488355  7f83                   -jg 0x4882da
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004882da;
    }
    // 00488357  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488358  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488359  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048835a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048835b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_488360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488360  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00488363  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00488365  d85c2408               +fcomp dword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00488369  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048836b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048836c  771b                   -ja 0x488389
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00488389;
    }
    // 0048836e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00488372  dc0570ea4b00           -fadd qword ptr [0x4bea70]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4975216) /* 0x4bea70 */));
    // 00488378  e8d320ffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0048837d  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00488380  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488383  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488386  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00488389:
    // 00488389  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048838d  dc0568ea4b00           -fadd qword ptr [0x4bea68]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4975208) /* 0x4bea68 */));
    // 00488393  e8b820ffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 00488398  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048839b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048839e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004883a1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4883a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004883a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004883a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004883a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004883a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004883a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004883aa  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004883ad  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004883b1  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 004883b6  bb71000000             -mov ebx, 0x71
    cpu.ebx = 113 /*0x71*/;
    // 004883bb  bf00180200             -mov edi, 0x21800
    cpu.edi = 137216 /*0x21800*/;
    // 004883c0  be0000802c             -mov esi, 0x2c800000
    cpu.esi = 746586112 /*0x2c800000*/;
    // 004883c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004883c7:
    // 004883c7  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004883cb  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004883ce  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004883d2  dc0598ea4b00           -fadd qword ptr [0x4bea98]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4975256) /* 0x4bea98 */));
    // 004883d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004883da  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 004883dd  dc0d78ea4b00           -fmul qword ptr [0x4bea78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4975224) /* 0x4bea78 */));
    // 004883e3  8982105a5200           -mov dword ptr [edx + 0x525a10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5397008) /* 0x525a10 */) = cpu.eax;
    // 004883e9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004883ec  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004883ef  e86cffffff             -call 0x488360
    cpu.esp -= 4;
    sub_488360(app, cpu);
    if (cpu.terminate) return;
    // 004883f4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004883f7  dc0d80ea4b00           -fmul qword ptr [0x4bea80]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4975232) /* 0x4bea80 */));
    // 004883fd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488400  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488402  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00488405  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048840b  e850ffffff             -call 0x488360
    cpu.esp -= 4;
    sub_488360(app, cpu);
    if (cpu.terminate) return;
    // 00488410  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00488413  c1e50b                 -shl ebp, 0xb
    cpu.ebp <<= 11 /*0xb*/ % 32;
    // 00488416  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048841b  dc0d88ea4b00           -fmul qword ptr [0x4bea88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4975240) /* 0x4bea88 */));
    // 00488421  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488423  8982105c5200           -mov dword ptr [edx + 0x525c10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5397520) /* 0x525c10 */) = cpu.eax;
    // 00488429  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048842c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048842f  e82cffffff             -call 0x488360
    cpu.esp -= 4;
    sub_488360(app, cpu);
    if (cpu.terminate) return;
    // 00488434  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00488437  dc0d90ea4b00           -fmul qword ptr [0x4bea90]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4975248) /* 0x4bea90 */));
    // 0048843d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488440  81c700080000           -add edi, 0x800
    (cpu.edi) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 00488446  81c600008000           -add esi, 0x800000
    (cpu.esi) += x86::reg32(x86::sreg32(8388608 /*0x800000*/));
    // 0048844c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00488450  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488453  41                     -inc ecx
    (cpu.ecx)++;
    // 00488454  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00488457  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048845b  e800ffffff             -call 0x488360
    cpu.esp -= 4;
    sub_488360(app, cpu);
    if (cpu.terminate) return;
    // 00488460  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00488466  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048846b  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 0048846e  c1e517                 -shl ebp, 0x17
    cpu.ebp <<= 23 /*0x17*/ % 32;
    // 00488471  43                     -inc ebx
    (cpu.ebx)++;
    // 00488472  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488474  89820c5e5200           -mov dword ptr [edx + 0x525e0c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5398028) /* 0x525e0c */) = cpu.eax;
    // 0048847a  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048847d  0f8c44ffffff           -jl 0x4883c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004883c7;
    }
    // 00488483  ba67ffffff             -mov edx, 0xffffff67
    cpu.edx = 4294967143 /*0xffffff67*/;
    // 00488488  b99cfdffff             -mov ecx, 0xfffffd9c
    cpu.ecx = 4294966684 /*0xfffffd9c*/;
    // 0048848d  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
    // 00488492  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488496  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00488498:
    // 00488498  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048849b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 004884a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004884a2  0f8c08010000           -jl 0x4885b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004885b0;
    }
    // 004884a8  3dff000000             +cmp eax, 0xff
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
    // 004884ad  7e05                   -jle 0x4884b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004884b4;
    }
    // 004884af  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004884b4:
    // 004884b4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004884b6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004884b9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004884bc  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004884bf  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004884c2  7e02                   -jle 0x4884c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004884c6;
    }
    // 004884c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004884c6:
    // 004884c6  83fd0f                 +cmp ebp, 0xf
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004884c9  0f85e8000000           -jne 0x4885b7
    if (!cpu.flags.zf)
    {
        goto L_0x004885b7;
    }
    // 004884cf  c1e31a                 -shl ebx, 0x1a
    cpu.ebx <<= 26 /*0x1a*/ % 32;
    // 004884d2  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
L_0x004884d5:
    // 004884d5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004884d7  8981ac575200           -mov dword ptr [ecx + 0x5257ac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5396396) /* 0x5257ac */) = cpu.eax;
    // 004884dd  42                     -inc edx
    (cpu.edx)++;
    // 004884de  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004884e1  81fa99000000           +cmp edx, 0x99
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153 /*0x99*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004884e7  7caf                   -jl 0x488498
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488498;
    }
    // 004884e9  ba7dffffff             -mov edx, 0xffffff7d
    cpu.edx = 4294967165 /*0xffffff7d*/;
    // 004884ee  b9f4fdffff             -mov ecx, 0xfffffdf4
    cpu.ecx = 4294966772 /*0xfffffdf4*/;
    // 004884f3  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004884f8  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 004884fd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004884ff:
    // 004884ff  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00488502  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 00488507  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488509  0f8cb3000000           -jl 0x4885c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004885c2;
    }
    // 0048850f  3dff000000             +cmp eax, 0xff
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
    // 00488514  7e02                   -jle 0x488518
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488518;
    }
    // 00488516  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00488518:
    // 00488518  837c24080f             +cmp dword ptr [esp + 8], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048851d  0f85a6000000           -jne 0x4885c9
    if (!cpu.flags.zf)
    {
        goto L_0x004885c9;
    }
    // 00488523  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488525  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488528  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048852b  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048852e  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488531  7e05                   -jle 0x488538
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488538;
    }
    // 00488533  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
L_0x00488538:
    // 00488538  c1e315                 -shl ebx, 0x15
    cpu.ebx <<= 21 /*0x15*/ % 32;
    // 0048853b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048853e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488541  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00488543  42                     -inc edx
    (cpu.edx)++;
    // 00488544  898138535200           -mov dword ptr [ecx + 0x525338], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5395256) /* 0x525338 */) = cpu.eax;
    // 0048854a  81fa83000000           +cmp edx, 0x83
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488550  7cad                   -jl 0x4884ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004884ff;
    }
    // 00488552  ba4fffffff             -mov edx, 0xffffff4f
    cpu.edx = 4294967119 /*0xffffff4f*/;
    // 00488557  b93cfdffff             -mov ecx, 0xfffffd3c
    cpu.ecx = 4294966588 /*0xfffffd3c*/;
    // 0048855c  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 00488561  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 00488566  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00488568:
    // 00488568  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048856b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 00488570  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488572  7c70                   -jl 0x4885e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004885e4;
    }
    // 00488574  3dff000000             +cmp eax, 0xff
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
    // 00488579  7e02                   -jle 0x48857d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048857d;
    }
    // 0048857b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048857d:
    // 0048857d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048857f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488582  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00488585  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00488588  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048858b  7e02                   -jle 0x48858f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048858f;
    }
    // 0048858d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0048858f:
    // 0048858f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00488592  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488595  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00488597  42                     -inc edx
    (cpu.edx)++;
    // 00488598  8981684e5200           -mov dword ptr [ecx + 0x524e68], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5394024) /* 0x524e68 */) = cpu.eax;
    // 0048859e  81fab1000000           +cmp edx, 0xb1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(177 /*0xb1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004885a4  7cc2                   -jl 0x488568
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488568;
    }
    // 004885a6  83c410                 +add esp, 0x10
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
    // 004885a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004885b0:
    // 004885b0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004885b2  e9fdfeffff             -jmp 0x4884b4
    goto L_0x004884b4;
L_0x004885b7:
    // 004885b7  c1e31b                 -shl ebx, 0x1b
    cpu.ebx <<= 27 /*0x1b*/ % 32;
    // 004885ba  c1e00b                 +shl eax, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004885bd  e913ffffff             -jmp 0x4884d5
    goto L_0x004884d5;
L_0x004885c2:
    // 004885c2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004885c4  e94fffffff             -jmp 0x488518
    goto L_0x00488518;
L_0x004885c9:
    // 004885c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004885cb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004885ce  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004885d1  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 004885d4  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004885d7  0f8e5bffffff           -jle 0x488538
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488538;
    }
    // 004885dd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004885df  e954ffffff             -jmp 0x488538
    goto L_0x00488538;
L_0x004885e4:
    // 004885e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004885e6  eb95                   -jmp 0x48857d
    goto L_0x0048857d;
}

/* align: skip  */
void Application::sub_4885e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004885e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004885ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004885eb  81ec480a0000           -sub esp, 0xa48
    (cpu.esp) -= x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004885f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004885f3  899424100a0000         -mov dword ptr [esp + 0xa10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.edx;
    // 004885fa  899c240c0a0000         -mov dword ptr [esp + 0xa0c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebx;
    // 00488601  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00488603  8b94245c0a0000         -mov edx, dword ptr [esp + 0xa5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 0048860a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048860c  0f85e8010000           -jne 0x4887fa
    if (!cpu.flags.zf)
    {
        goto L_0x004887fa;
    }
    // 00488612  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00488617:
    // 00488617  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488619  8a15ec844c00           -mov dl, byte ptr [0x4c84ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0048861f  83fa0f                 +cmp edx, 0xf
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
    // 00488622  7409                   -je 0x48862d
    if (cpu.flags.zf)
    {
        goto L_0x0048862d;
    }
    // 00488624  83fa10                 +cmp edx, 0x10
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
    // 00488627  0f85f7010000           -jne 0x488824
    if (!cpu.flags.zf)
    {
        goto L_0x00488824;
    }
L_0x0048862d:
    // 0048862d  3b1510605200           +cmp edx, dword ptr [0x526010]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5398544) /* 0x526010 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488633  740d                   -je 0x488642
    if (cpu.flags.zf)
    {
        goto L_0x00488642;
    }
    // 00488635  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488637  e868fdffff             -call 0x4883a4
    cpu.esp -= 4;
    sub_4883a4(app, cpu);
    if (cpu.terminate) return;
    // 0048863c  891510605200           -mov dword ptr [0x526010], edx
    app->getMemory<x86::reg32>(x86::reg32(5398544) /* 0x526010 */) = cpu.edx;
L_0x00488642:
    // 00488642  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488644  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488646  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048864c  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048864f  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00488655  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00488658  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048865e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00488661  6683e6fe               -and si, 0xfffe
    cpu.si &= x86::reg16(x86::sreg16(65534 /*0xfffe*/));
    // 00488665  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00488667  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00488669  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048866b  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0048866e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00488671  8b8424580a0000         -mov eax, dword ptr [esp + 0xa58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2648) /* 0xa58 */);
    // 00488678  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048867b  899424080a0000         -mov dword ptr [esp + 0xa08], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edx;
    // 00488682  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488689  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048868b  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
    // 00488692  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00488694  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488696  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00488699  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048869b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048869d  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 004886a3  898424040a0000         -mov dword ptr [esp + 0xa04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */) = cpu.eax;
    // 004886aa  39d6                   +cmp esi, edx
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
    // 004886ac  7d22                   -jge 0x4886d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004886d0;
    }
    // 004886ae  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 004886b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004886b3  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004886b6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004886b8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004886ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004886bc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004886bf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004886c1  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004886c4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004886c7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004886c9  0184240c0a0000         -add dword ptr [esp + 0xa0c], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004886d0:
    // 004886d0  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004886d7  8b3de4844c00           -mov edi, dword ptr [0x4c84e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 004886dd  39f8                   +cmp eax, edi
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
    // 004886df  7e07                   -jle 0x4886e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004886e8;
    }
    // 004886e1  89bc24080a0000         -mov dword ptr [esp + 0xa08], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edi;
L_0x004886e8:
    // 004886e8  8b8424100a0000         -mov eax, dword ptr [esp + 0xa10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004886ef  8b2de0844c00           -mov ebp, dword ptr [0x4c84e0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 004886f5  39e8                   +cmp eax, ebp
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
    // 004886f7  7d47                   -jge 0x488740
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488740;
    }
    // 004886f9  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488700  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00488702  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00488704  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00488707  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488709  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048870b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048870e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00488710  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00488712  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00488715  0faf8424040a0000       -imul eax, dword ptr [esp + 0xa04]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */))));
    // 0048871d  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488724  8bac240c0a0000         -mov ebp, dword ptr [esp + 0xa0c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048872b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048872e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488730  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488732  899c24100a0000         -mov dword ptr [esp + 0xa10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.ebx;
    // 00488739  89ac240c0a0000         -mov dword ptr [esp + 0xa0c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebp;
L_0x00488740:
    // 00488740  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00488747  8b15e8844c00           -mov edx, dword ptr [0x4c84e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0048874d  39d0                   +cmp eax, edx
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
    // 0048874f  7e07                   -jle 0x488758
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488758;
    }
    // 00488751  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
L_0x00488758:
    // 00488758  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048875f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00488761  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488763  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488765  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00488768  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048876a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048876c  83f802                 +cmp eax, 2
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
    // 0048876f  0f8c77000000           -jl 0x4887ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004887ec;
    }
    // 00488775  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048877c  8b8c245c0a0000         -mov ecx, dword ptr [esp + 0xa5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 00488783  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00488786  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488788  0f85a7000000           -jne 0x488835
    if (!cpu.flags.zf)
    {
        goto L_0x00488835;
    }
    // 0048878e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488795  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048879c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004887a3  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004887a5  7d45                   -jge 0x4887ec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004887ec;
    }
    // 004887a7  898424200a0000         -mov dword ptr [esp + 0xa20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */) = cpu.eax;
L_0x004887ae:
    // 004887ae  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004887b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004887b2  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 004887b8  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004887bb  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 004887c1  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004887c4  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 004887ca  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004887cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004887ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004887d0  45                     -inc ebp
    (cpu.ebp)++;
    // 004887d1  e882f7ffff             -call 0x487f58
    cpu.esp -= 4;
    sub_487f58(app, cpu);
    if (cpu.terminate) return;
    // 004887d6  8b8424200a0000         -mov eax, dword ptr [esp + 0xa20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */);
    // 004887dd  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004887e4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004887e6  39d5                   +cmp ebp, edx
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
    // 004887e8  7cc4                   -jl 0x4887ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004887ae;
    }
    // 004887ea  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004887ec:
    // 004887ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004887ee  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004887f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887f7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004887fa:
    // 004887fa  83fa01                 +cmp edx, 1
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
    // 004887fd  750a                   -jne 0x488809
    if (!cpu.flags.zf)
    {
        goto L_0x00488809;
    }
L_0x004887ff:
    // 004887ff  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00488804  e90efeffff             -jmp 0x488617
    goto L_0x00488617;
L_0x00488809:
    // 00488809  83fa02                 +cmp edx, 2
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
    // 0048880c  74f1                   -je 0x4887ff
    if (cpu.flags.zf)
    {
        goto L_0x004887ff;
    }
    // 0048880e  83fa03                 +cmp edx, 3
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
    // 00488811  74ec                   -je 0x4887ff
    if (cpu.flags.zf)
    {
        goto L_0x004887ff;
    }
    // 00488813  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488818  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048881e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048881f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488820  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488821  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488824:
    // 00488824  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00488829  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048882f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488830  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488831  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488832  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488835:
    // 00488835  83f903                 +cmp ecx, 3
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
    // 00488838  0f8578010000           -jne 0x4889b6
    if (!cpu.flags.zf)
    {
        goto L_0x004889b6;
    }
    // 0048883e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488845  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048884c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 00488853  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488855  7d71                   -jge 0x4888c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004888c8;
    }
    // 00488857  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00488859  4a                     -dec edx
    (cpu.edx)--;
    // 0048885a  899424180a0000         -mov dword ptr [esp + 0xa18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */) = cpu.edx;
    // 00488861  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00488864  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488867  898424140a0000         -mov dword ptr [esp + 0xa14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */) = cpu.eax;
    // 0048886e  899424280a0000         -mov dword ptr [esp + 0xa28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */) = cpu.edx;
L_0x00488875:
    // 00488875  8b9c24180a0000         -mov ebx, dword ptr [esp + 0xa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */);
    // 0048887c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048887e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488880  e849f9ffff             -call 0x4881ce
    cpu.esp -= 4;
    sub_4881ce(app, cpu);
    if (cpu.terminate) return;
    // 00488885  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00488887  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488889  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048888f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00488892  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00488898  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048889b  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 004888a1  8b9c24280a0000         -mov ebx, dword ptr [esp + 0xa28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */);
    // 004888a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004888aa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004888ac  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004888af  e8a4f6ffff             -call 0x487f58
    cpu.esp -= 4;
    sub_487f58(app, cpu);
    if (cpu.terminate) return;
    // 004888b4  8b8424140a0000         -mov eax, dword ptr [esp + 0xa14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */);
    // 004888bb  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004888c2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004888c4  39d5                   +cmp ebp, edx
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
    // 004888c6  7cad                   -jl 0x488875
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488875;
    }
L_0x004888c8:
    // 004888c8  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004888cf  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004888d6  8b8c24100a0000         -mov ecx, dword ptr [esp + 0xa10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004888dd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004888df  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004888e1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004888e4  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004888e9  0f8fae000000           -jg 0x48899d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048899d;
    }
L_0x004888ef:
    // 004888ef  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004888f6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004888f9  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488900  899424340a0000         -mov dword ptr [esp + 0xa34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */) = cpu.edx;
    // 00488907  8b9424040a0000         -mov edx, dword ptr [esp + 0xa04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048890e  45                     -inc ebp
    (cpu.ebp)++;
    // 0048890f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00488912  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00488914  899424240a0000         -mov dword ptr [esp + 0xa24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.edx;
    // 0048891b  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00488922  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488925  4a                     -dec edx
    (cpu.edx)--;
    // 00488926  89bc24300a0000         -mov dword ptr [esp + 0xa30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */) = cpu.edi;
    // 0048892d  899424380a0000         -mov dword ptr [esp + 0xa38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */) = cpu.edx;
    // 00488934  39d5                   +cmp ebp, edx
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
    // 00488936  0f8db0feffff           -jge 0x4887ec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004887ec;
    }
L_0x0048893c:
    // 0048893c  8bbc24240a0000         -mov edi, dword ptr [esp + 0xa24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00488943  8b8c24340a0000         -mov ecx, dword ptr [esp + 0xa34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 0048894a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048894c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048894e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00488950  e8d5f8ffff             -call 0x48822a
    cpu.esp -= 4;
    sub_48822a(app, cpu);
    if (cpu.terminate) return;
    // 00488955  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00488957  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488959  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048895f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00488962  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00488968  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048896b  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00488971  8b9c24300a0000         -mov ebx, dword ptr [esp + 0xa30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */);
    // 00488978  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048897a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048897c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048897f  e8d4f5ffff             -call 0x487f58
    cpu.esp -= 4;
    sub_487f58(app, cpu);
    if (cpu.terminate) return;
    // 00488984  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488986  3bac24380a0000         +cmp ebp, dword ptr [esp + 0xa38]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048898d  7cad                   -jl 0x48893c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048893c;
    }
    // 0048898f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488991  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00488997  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488998  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488999  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048899a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048899d:
    // 0048899d  e8f6f7feff             -call 0x478198
    cpu.esp -= 4;
    sub_478198(app, cpu);
    if (cpu.terminate) return;
    // 004889a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004889a4  0f8545ffffff           -jne 0x4888ef
    if (!cpu.flags.zf)
    {
        goto L_0x004888ef;
    }
    // 004889aa  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004889b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004889b6:
    // 004889b6  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004889bd  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004889c4  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004889cb  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004889cd  7d45                   -jge 0x488a14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488a14;
    }
    // 004889cf  8984241c0a0000         -mov dword ptr [esp + 0xa1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */) = cpu.eax;
L_0x004889d6:
    // 004889d6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004889d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004889da  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 004889e0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004889e3  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 004889e9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004889ec  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 004889f2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004889f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004889f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004889f8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004889fb  e82bf6ffff             -call 0x48802b
    cpu.esp -= 4;
    sub_48802b(app, cpu);
    if (cpu.terminate) return;
    // 00488a00  8b84241c0a0000         -mov eax, dword ptr [esp + 0xa1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */);
    // 00488a07  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00488a0e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488a10  39d5                   +cmp ebp, edx
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
    // 00488a12  7cc2                   -jl 0x4889d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004889d6;
    }
L_0x00488a14:
    // 00488a14  83bc245c0a000002       +cmp dword ptr [esp + 0xa5c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488a1c  0f85cafdffff           -jne 0x4887ec
    if (!cpu.flags.zf)
    {
        goto L_0x004887ec;
    }
    // 00488a22  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 00488a29  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00488a30  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488a37  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00488a39  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488a3b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00488a3e  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488a43  0f8fab000000           -jg 0x488af4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00488af4;
    }
L_0x00488a49:
    // 00488a49  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 00488a50  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 00488a57  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 00488a5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00488a61  8984242c0a0000         -mov dword ptr [esp + 0xa2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */) = cpu.eax;
    // 00488a68  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 00488a6f  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 00488a76  48                     -dec eax
    (cpu.eax)--;
    // 00488a77  45                     -inc ebp
    (cpu.ebp)++;
    // 00488a78  8984243c0a0000         -mov dword ptr [esp + 0xa3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */) = cpu.eax;
    // 00488a7f  39c5                   +cmp ebp, eax
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
    // 00488a81  0f8d65fdffff           -jge 0x4887ec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004887ec;
    }
L_0x00488a87:
    // 00488a87  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00488a89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488a8b  8b8c242c0a0000         -mov ecx, dword ptr [esp + 0xa2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */);
    // 00488a92  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00488a98  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00488a9b  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00488aa1  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00488aa4  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00488aaa  8b9424400a0000         -mov edx, dword ptr [esp + 0xa40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 00488ab1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488ab3  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488ab6  8b8424400a0000         -mov eax, dword ptr [esp + 0xa40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 00488abd  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488abf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00488ac1  899424000a0000         -mov dword ptr [esp + 0xa00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */) = cpu.edx;
    // 00488ac8  e825f6ffff             -call 0x4880f2
    cpu.esp -= 4;
    sub_4880f2(app, cpu);
    if (cpu.terminate) return;
    // 00488acd  8b8424000a0000         -mov eax, dword ptr [esp + 0xa00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */);
    // 00488ad4  8b9c243c0a0000         -mov ebx, dword ptr [esp + 0xa3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */);
    // 00488adb  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 00488ae2  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488ae4  7ca1                   -jl 0x488a87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488a87;
    }
    // 00488ae6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488ae8  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00488aee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488aef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488af0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488af1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488af4:
    // 00488af4  e89ff6feff             -call 0x478198
    cpu.esp -= 4;
    sub_478198(app, cpu);
    if (cpu.terminate) return;
    // 00488af9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488afb  0f8548ffffff           -jne 0x488a49
    if (!cpu.flags.zf)
    {
        goto L_0x00488a49;
    }
    // 00488b01  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 00488b07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b0a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_488b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b12  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488b14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488b16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488b18  7505                   -jne 0x488b1f
    if (!cpu.flags.zf)
    {
        goto L_0x00488b1f;
    }
L_0x00488b1a:
    // 00488b1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488b1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b1f:
    // 00488b1f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00488b24  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488b26  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488b28  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488b2a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488b31  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488b33  3dfbc00000             +cmp eax, 0xc0fb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49403 /*0xc0fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b38  750a                   -jne 0x488b44
    if (!cpu.flags.zf)
    {
        goto L_0x00488b44;
    }
    // 00488b3a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488b3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b44:
    // 00488b44  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488b49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488b4b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488b4d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488b4f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488b51  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488b58  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488b5a  3d46474942             +cmp eax, 0x42494746
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1112098630 /*0x42494746*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b5f  75b9                   -jne 0x488b1a
    if (!cpu.flags.zf)
    {
        goto L_0x00488b1a;
    }
    // 00488b61  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00488b66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488b68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488b6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b6d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488b6f  e89cffffff             -call 0x488b10
    cpu.esp -= 4;
    sub_488b10(app, cpu);
    if (cpu.terminate) return;
    // 00488b74  83f801                 +cmp eax, 1
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
    // 00488b77  7207                   -jb 0x488b80
    if (cpu.flags.cf)
    {
        goto L_0x00488b80;
    }
    // 00488b79  7609                   -jbe 0x488b84
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b84;
    }
    // 00488b7b  83f802                 +cmp eax, 2
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
    // 00488b7e  7420                   -je 0x488ba0
    if (cpu.flags.zf)
    {
        goto L_0x00488ba0;
    }
L_0x00488b80:
    // 00488b80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b84:
    // 00488b84  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00488b87  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00488b8c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488b8e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488b90  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488b92  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488b99  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488b9b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488b9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488ba0:
    // 00488ba0  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00488ba3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488ba8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488baa  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488bac  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488bae  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488bb5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488bb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488bb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488bbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488bbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488bbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488bbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488bbf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00488bc2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00488bc4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00488bc6  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00488bca  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00488bcd  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488bd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488bd3  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00488bd7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00488bd9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00488bdb  e88cffffff             -call 0x488b6c
    cpu.esp -= 4;
    sub_488b6c(app, cpu);
    if (cpu.terminate) return;
    // 00488be0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00488be2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488be4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488be6  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00488bea  e821ffffff             -call 0x488b10
    cpu.esp -= 4;
    sub_488b10(app, cpu);
    if (cpu.terminate) return;
    // 00488bef  83f801                 +cmp eax, 1
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
    // 00488bf2  7327                   -jae 0x488c1b
    if (!cpu.flags.cf)
    {
        goto L_0x00488c1b;
    }
L_0x00488bf4:
    // 00488bf4  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00488bf7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488bf9  7406                   -je 0x488c01
    if (cpu.flags.zf)
    {
        goto L_0x00488c01;
    }
    // 00488bfb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x00488c01:
    // 00488c01  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00488c05  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488c07  7407                   -je 0x488c10
    if (cpu.flags.zf)
    {
        goto L_0x00488c10;
    }
    // 00488c09  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x00488c10:
    // 00488c10  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488c12  83c410                 +add esp, 0x10
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
    // 00488c15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c18  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488c1b:
    // 00488c1b  0f8777000000           -ja 0x488c98
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00488c98;
    }
    // 00488c21  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488c25  8d5f06                 -lea ebx, [edi + 6]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00488c28  39f3                   +cmp ebx, esi
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
    // 00488c2a  73c8                   -jae 0x488bf4
    if (!cpu.flags.cf)
    {
        goto L_0x00488bf4;
    }
L_0x00488c2c:
    // 00488c2c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488c2e  0f85e0000000           -jne 0x488d14
    if (!cpu.flags.zf)
    {
        goto L_0x00488d14;
    }
L_0x00488c34:
    // 00488c34  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488c36  0f8558010000           -jne 0x488d94
    if (!cpu.flags.zf)
    {
        goto L_0x00488d94;
    }
    // 00488c3c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488c40  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488c44  0f854a010000           -jne 0x488d94
    if (!cpu.flags.zf)
    {
        goto L_0x00488d94;
    }
L_0x00488c4a:
    // 00488c4a  833c2400               +cmp dword ptr [esp], 0
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
    // 00488c4e  741b                   -je 0x488c6b
    if (cpu.flags.zf)
    {
        goto L_0x00488c6b;
    }
    // 00488c50  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00488c55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488c57  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488c59  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488c5b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488c5d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488c64  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488c66  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00488c69  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00488c6b:
    // 00488c6b  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00488c6f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488c71  7419                   -je 0x488c8c
    if (cpu.flags.zf)
    {
        goto L_0x00488c8c;
    }
    // 00488c73  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00488c78  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00488c7b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488c7d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488c7f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488c81  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488c88  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488c8a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00488c8c:
    // 00488c8c  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 00488c8f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00488c92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c95  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488c98:
    // 00488c98  83f802                 +cmp eax, 2
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
    // 00488c9b  0f8553ffffff           -jne 0x488bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00488bf4;
    }
    // 00488ca1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488ca5  8d5f10                 -lea ebx, [edi + 0x10]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00488ca8  39cb                   +cmp ebx, ecx
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
    // 00488caa  0f8344ffffff           -jae 0x488bf4
    if (!cpu.flags.cf)
    {
        goto L_0x00488bf4;
    }
L_0x00488cb0:
    // 00488cb0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488cb2  0f851e010000           -jne 0x488dd6
    if (!cpu.flags.zf)
    {
        goto L_0x00488dd6;
    }
    // 00488cb8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488cbc  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488cc0  0f8510010000           -jne 0x488dd6
    if (!cpu.flags.zf)
    {
        goto L_0x00488dd6;
    }
L_0x00488cc6:
    // 00488cc6  833c2400               +cmp dword ptr [esp], 0
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
    // 00488cca  741b                   -je 0x488ce7
    if (cpu.flags.zf)
    {
        goto L_0x00488ce7;
    }
    // 00488ccc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488cd1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488cd3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488cd5  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488cd7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488cd9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488ce0  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488ce2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00488ce5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00488ce7:
    // 00488ce7  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00488ceb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488ced  7419                   -je 0x488d08
    if (cpu.flags.zf)
    {
        goto L_0x00488d08;
    }
    // 00488cef  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488cf4  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00488cf7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488cf9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488cfb  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488cfd  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488d04  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488d06  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00488d08:
    // 00488d08  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00488d0b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00488d0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d11  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488d14:
    // 00488d14  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488d18  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00488d1a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00488d1c  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00488d1e  81ce20202020           -or esi, 0x20202020
    cpu.esi |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
L_0x00488d24:
    // 00488d24  39d7                   +cmp edi, edx
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
    // 00488d26  7d65                   -jge 0x488d8d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488d8d;
    }
    // 00488d28  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00488d2b  0d20202020             -or eax, 0x20202020
    cpu.eax |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
    // 00488d30  39f0                   +cmp eax, esi
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
    // 00488d32  7459                   -je 0x488d8d
    if (cpu.flags.zf)
    {
        goto L_0x00488d8d;
    }
    // 00488d34  8b470a                 -mov eax, dword ptr [edi + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00488d37  8d7f0e                 -lea edi, [edi + 0xe]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00488d3a  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 00488d3f  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00488d44  7522                   -jne 0x488d68
    if (!cpu.flags.zf)
    {
        goto L_0x00488d68;
    }
    // 00488d46  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00488d48  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00488d4b  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 00488d50  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00488d55  7511                   -jne 0x488d68
    if (!cpu.flags.zf)
    {
        goto L_0x00488d68;
    }
L_0x00488d57:
    // 00488d57  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00488d59  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00488d5c  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 00488d61  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00488d66  74ef                   -je 0x488d57
    if (cpu.flags.zf)
    {
        goto L_0x00488d57;
    }
L_0x00488d68:
    // 00488d68  8a47fc                 -mov al, byte ptr [edi - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00488d6b  8d7ffd                 -lea edi, [edi - 3]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-3) /* -0x3 */);
    // 00488d6e  3c00                   +cmp al, 0
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
    // 00488d70  74b2                   -je 0x488d24
    if (cpu.flags.zf)
    {
        goto L_0x00488d24;
    }
    // 00488d72  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00488d74  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00488d77  3c00                   +cmp al, 0
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
    // 00488d79  74a9                   -je 0x488d24
    if (cpu.flags.zf)
    {
        goto L_0x00488d24;
    }
    // 00488d7b  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00488d7d  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00488d80  3c00                   +cmp al, 0
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
    // 00488d82  74a0                   -je 0x488d24
    if (cpu.flags.zf)
    {
        goto L_0x00488d24;
    }
    // 00488d84  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00488d86  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00488d89  3c00                   +cmp al, 0
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
    // 00488d8b  7497                   -je 0x488d24
    if (cpu.flags.zf)
    {
        goto L_0x00488d24;
    }
L_0x00488d8d:
    // 00488d8d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00488d8f  e9a0feffff             -jmp 0x488c34
    goto L_0x00488c34;
L_0x00488d94:
    // 00488d94  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488d96  7412                   -je 0x488daa
    if (cpu.flags.zf)
    {
        goto L_0x00488daa;
    }
    // 00488d98  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 00488d9b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00488d9d  e8811b0000             -call 0x48a923
    cpu.esp -= 4;
    sub_48a923(app, cpu);
    if (cpu.terminate) return;
    // 00488da2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488da4  0f84a0feffff           -je 0x488c4a
    if (cpu.flags.zf)
    {
        goto L_0x00488c4a;
    }
L_0x00488daa:
    // 00488daa  8d7b06                 -lea edi, [ebx + 6]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 00488dad  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488daf  49                     -dec ecx
    (cpu.ecx)--;
    // 00488db0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488db2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00488db4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00488db6  49                     -dec ecx
    (cpu.ecx)--;
    // 00488db7  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488dbb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488dbf  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488dc1  47                     -inc edi
    (cpu.edi)++;
    // 00488dc2  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00488dc5  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00488dc9  39c3                   +cmp ebx, eax
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
    // 00488dcb  0f825bfeffff           -jb 0x488c2c
    if (cpu.flags.cf)
    {
        goto L_0x00488c2c;
    }
    // 00488dd1  e91efeffff             -jmp 0x488bf4
    goto L_0x00488bf4;
L_0x00488dd6:
    // 00488dd6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488dd8  7412                   -je 0x488dec
    if (cpu.flags.zf)
    {
        goto L_0x00488dec;
    }
    // 00488dda  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00488ddd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00488ddf  e83f1b0000             -call 0x48a923
    cpu.esp -= 4;
    sub_48a923(app, cpu);
    if (cpu.terminate) return;
    // 00488de4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488de6  0f84dafeffff           -je 0x488cc6
    if (cpu.flags.zf)
    {
        goto L_0x00488cc6;
    }
L_0x00488dec:
    // 00488dec  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00488def  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488df1  49                     -dec ecx
    (cpu.ecx)--;
    // 00488df2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488df4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00488df6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00488df8  49                     -dec ecx
    (cpu.ecx)--;
    // 00488df9  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488dfd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488e01  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488e03  47                     -inc edi
    (cpu.edi)++;
    // 00488e04  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00488e07  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00488e0b  39c3                   +cmp ebx, eax
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
    // 00488e0d  0f829dfeffff           -jb 0x488cb0
    if (cpu.flags.cf)
    {
        goto L_0x00488cb0;
    }
    // 00488e13  e9dcfdffff             -jmp 0x488bf4
    goto L_0x00488bf4;
}

/* align: skip  */
void Application::sub_488e18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e19  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488e1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e1d  6814605200             -push 0x526014
    app->getMemory<x86::reg32>(cpu.esp-4) = 5398548 /*0x526014*/;
    cpu.esp -= 4;
    // 00488e22  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488e26  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e28  e88ffdffff             -call 0x488bbc
    cpu.esp -= 4;
    sub_488bbc(app, cpu);
    if (cpu.terminate) return;
    // 00488e2d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488e30  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488e33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e39  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00488e3e  e8d5ffffff             -call 0x488e18
    cpu.esp -= 4;
    sub_488e18(app, cpu);
    if (cpu.terminate) return;
    // 00488e43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488e48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e4b  e8c8ffffff             -call 0x488e18
    cpu.esp -= 4;
    sub_488e18(app, cpu);
    if (cpu.terminate) return;
    // 00488e50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488e54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488e56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488e58  e8bbffffff             -call 0x488e18
    cpu.esp -= 4;
    sub_488e18(app, cpu);
    if (cpu.terminate) return;
    // 00488e5d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00488e5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488e61  7403                   -je 0x488e66
    if (cpu.flags.zf)
    {
        goto L_0x00488e66;
    }
    // 00488e63  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
L_0x00488e66:
    // 00488e66  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488e68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488e6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e6d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00488e72  e8ddffffff             -call 0x488e54
    cpu.esp -= 4;
    sub_488e54(app, cpu);
    if (cpu.terminate) return;
    // 00488e77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e7f  e8d0ffffff             -call 0x488e54
    cpu.esp -= 4;
    sub_488e54(app, cpu);
    if (cpu.terminate) return;
    // 00488e84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488e88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488e89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488e8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488e8b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488e8e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00488e91  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00488e93  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00488e95:
    // 00488e95  b22c                   -mov dl, 0x2c
    cpu.dl = 44 /*0x2c*/;
    // 00488e97  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00488e99:
    // 00488e99  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00488e9b  3ac2                   +cmp al, dl
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
    // 00488e9d  7412                   -je 0x488eb1
    if (cpu.flags.zf)
    {
        goto L_0x00488eb1;
    }
    // 00488e9f  3c00                   +cmp al, 0
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
    // 00488ea1  740c                   -je 0x488eaf
    if (cpu.flags.zf)
    {
        goto L_0x00488eaf;
    }
    // 00488ea3  46                     -inc esi
    (cpu.esi)++;
    // 00488ea4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00488ea6  3ac2                   +cmp al, dl
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
    // 00488ea8  7407                   -je 0x488eb1
    if (cpu.flags.zf)
    {
        goto L_0x00488eb1;
    }
    // 00488eaa  46                     -inc esi
    (cpu.esi)++;
    // 00488eab  3c00                   +cmp al, 0
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
    // 00488ead  75ea                   -jne 0x488e99
    if (!cpu.flags.zf)
    {
        goto L_0x00488e99;
    }
L_0x00488eaf:
    // 00488eaf  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00488eb1:
    // 00488eb1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00488eb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488eb5  7403                   -je 0x488eba
    if (cpu.flags.zf)
    {
        goto L_0x00488eba;
    }
    // 00488eb7  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
L_0x00488eba:
    // 00488eba  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488ebd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00488ebf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488ec1  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488ec4  e88bffffff             -call 0x488e54
    cpu.esp -= 4;
    sub_488e54(app, cpu);
    if (cpu.terminate) return;
    // 00488ec9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00488ecc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488ece  7406                   -je 0x488ed6
    if (cpu.flags.zf)
    {
        goto L_0x00488ed6;
    }
    // 00488ed0  c6012c                 -mov byte ptr [ecx], 0x2c
    app->getMemory<x86::reg8>(cpu.ecx) = 44 /*0x2c*/;
    // 00488ed3  41                     -inc ecx
    (cpu.ecx)++;
    // 00488ed4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x00488ed6:
    // 00488ed6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488ed8  75bb                   -jne 0x488e95
    if (!cpu.flags.zf)
    {
        goto L_0x00488e95;
    }
    // 00488eda  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488edd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488edf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488ee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488ee4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488ee5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00488eea  e899ffffff             -call 0x488e88
    cpu.esp -= 4;
    sub_488e88(app, cpu);
    if (cpu.terminate) return;
    // 00488eef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ef0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488ef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488ef4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488ef5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488ef7  e88cffffff             -call 0x488e88
    cpu.esp -= 4;
    sub_488e88(app, cpu);
    if (cpu.terminate) return;
    // 00488efc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488efd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488f05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488f07  e804fcffff             -call 0x488b10
    cpu.esp -= 4;
    sub_488b10(app, cpu);
    if (cpu.terminate) return;
    // 00488f0c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488f0e  83f801                 +cmp eax, 1
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
    // 00488f11  7207                   -jb 0x488f1a
    if (cpu.flags.cf)
    {
        goto L_0x00488f1a;
    }
    // 00488f13  760b                   -jbe 0x488f20
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488f20;
    }
    // 00488f15  83f802                 +cmp eax, 2
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
    // 00488f18  7421                   -je 0x488f3b
    if (cpu.flags.zf)
    {
        goto L_0x00488f3b;
    }
L_0x00488f1a:
    // 00488f1a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488f1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488f20:
    // 00488f20  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00488f23  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00488f28  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488f2a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488f2c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488f2e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488f35  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00488f37  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488f39  ebdf                   -jmp 0x488f1a
    goto L_0x00488f1a;
L_0x00488f3b:
    // 00488f3b  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488f3e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488f43  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488f45  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00488f47  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00488f49  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00488f50  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00488f52  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488f54  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488f56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488f5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488f5f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488f64  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488f66  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488f6a  6814605200             -push 0x526014
    app->getMemory<x86::reg32>(cpu.esp-4) = 5398548 /*0x526014*/;
    cpu.esp -= 4;
    // 00488f6f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00488f71  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488f73  e844fcffff             -call 0x488bbc
    cpu.esp -= 4;
    sub_488bbc(app, cpu);
    if (cpu.terminate) return;
    // 00488f78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488f7a  7405                   -je 0x488f81
    if (cpu.flags.zf)
    {
        goto L_0x00488f81;
    }
    // 00488f7c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488f7f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00488f81:
    // 00488f81  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f87  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
