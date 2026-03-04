#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4543e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004543e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004543e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004543e3  e8a8500700             -call 0x4c9490
    cpu.esp -= 4;
    sub_4c9490(app, cpu);
    if (cpu.terminate) return;
    // 004543e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004543ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4543f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004543f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004543f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004543f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004543f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004543f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004543f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004543f7  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004543fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004543fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004543fe  6850985300             -push 0x539850
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478480 /*0x539850*/;
    cpu.esp -= 4;
    // 00454403  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 00454408  685c985300             -push 0x53985c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478492 /*0x53985c*/;
    cpu.esp -= 4;
    // 0045440d  8d4594                 -lea eax, [ebp - 0x6c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-108) /* -0x6c */);
    // 00454410  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454411  e87ab20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454416  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00454419  8d4594                 -lea eax, [ebp - 0x6c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-108) /* -0x6c */);
    // 0045441c  e86f68ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00454421  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454424  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454426  e8654efeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 0045442b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045442d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0045442f:
    // 0045442f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00454431  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00454433  7420                   -je 0x454455
    if (cpu.flags.zf)
    {
        goto L_0x00454455;
    }
    // 00454435  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00454437  fec0                   -inc al
    (cpu.al)++;
    // 00454439  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045443e  f680f04e560040         +test byte ptr [eax + 0x564ef0], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 64 /*0x40*/));
    // 00454445  740b                   -je 0x454452
    if (cpu.flags.zf)
    {
        goto L_0x00454452;
    }
    // 00454447  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00454449  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0045444b  e890c60900             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 00454450  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
L_0x00454452:
    // 00454452  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00454453  ebda                   -jmp 0x45442f
    goto L_0x0045442f;
L_0x00454455:
    // 00454455  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045445a  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0045445f  bae0000000             -mov edx, 0xe0
    cpu.edx = 224 /*0xe0*/;
    // 00454464  b820010000             -mov eax, 0x120
    cpu.eax = 288 /*0x120*/;
    // 00454469  e822ad0900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 0045446e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00454471  e82a690900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00454476  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045447d  7507                   -jne 0x454486
    if (!cpu.flags.zf)
    {
        goto L_0x00454486;
    }
    // 0045447f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00454484  eb02                   -jmp 0x454488
    goto L_0x00454488;
L_0x00454486:
    // 00454486  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00454488:
    // 00454488  e823ad0900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0045448d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045448f  7441                   -je 0x4544d2
    if (cpu.flags.zf)
    {
        goto L_0x004544d2;
    }
    // 00454491  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454494  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00454496  e8d5ad0900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045449b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045449d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045449f  7431                   -je 0x4544d2
    if (cpu.flags.zf)
    {
        goto L_0x004544d2;
    }
    // 004544a1  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 004544a6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004544a9  8b5102                 -mov edx, dword ptr [ecx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004544ac  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004544af  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004544b2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004544b4  b820010000             -mov eax, 0x120
    cpu.eax = 288 /*0x120*/;
    // 004544b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004544bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004544c0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004544c2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004544c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004544c8  e8f3af0900             -call 0x4ef4c0
    cpu.esp -= 4;
    sub_4ef4c0(app, cpu);
    if (cpu.terminate) return;
    // 004544cd  e8be680900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x004544d2:
    // 004544d2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004544d5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004544d7  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004544da  e8b11e0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004544df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544e1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004544e4  e817ba0900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 004544e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004544eb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004544ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454503  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454505  833d6c29660009         +cmp dword ptr [0x66296c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045450c  742d                   -je 0x45453b
    if (cpu.flags.zf)
    {
        goto L_0x0045453b;
    }
    // 0045450e  e8edefffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00454513  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454515  740a                   -je 0x454521
    if (cpu.flags.zf)
    {
        goto L_0x00454521;
    }
    // 00454517  e8e4efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 0045451c  a388476600             -mov dword ptr [0x664788], eax
    app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */) = cpu.eax;
L_0x00454521:
    // 00454521  8b0dd4d46f00           -mov ecx, dword ptr [0x6fd4d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 00454527  83f903                 +cmp ecx, 3
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
    // 0045452a  7e05                   -jle 0x454531
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454531;
    }
    // 0045452c  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0045452f  eb05                   -jmp 0x454536
    goto L_0x00454536;
L_0x00454531:
    // 00454531  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
L_0x00454536:
    // 00454536  a384476600             -mov dword ptr [0x664784], eax
    app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */) = cpu.eax;
L_0x0045453b:
    // 0045453b  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 00454540  a38c476600             -mov dword ptr [0x66478c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */) = cpu.eax;
    // 00454545  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 0045454a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045454c  a390476600             -mov dword ptr [0x664790], eax
    app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */) = cpu.eax;
    // 00454551  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 00454556  e895feffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 0045455b  a3ac955500             -mov dword ptr [0x5595ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */) = cpu.eax;
    // 00454560  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454562  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 00454567  e884feffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 0045456c  a3b0955500             -mov dword ptr [0x5595b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */) = cpu.eax;
    // 00454571  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454573  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454574  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454575  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454576  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_454580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454583  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454584  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454586  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00454589  833d6c29660009         +cmp dword ptr [0x66296c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454590  742d                   -je 0x4545bf
    if (cpu.flags.zf)
    {
        goto L_0x004545bf;
    }
    // 00454592  e869efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00454597  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454599  740a                   -je 0x4545a5
    if (cpu.flags.zf)
    {
        goto L_0x004545a5;
    }
    // 0045459b  e860efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 004545a0  a388476600             -mov dword ptr [0x664788], eax
    app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */) = cpu.eax;
L_0x004545a5:
    // 004545a5  8b0dd4d46f00           -mov ecx, dword ptr [0x6fd4d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 004545ab  83f903                 +cmp ecx, 3
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
    // 004545ae  7e05                   -jle 0x4545b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004545b5;
    }
    // 004545b0  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004545b3  eb05                   -jmp 0x4545ba
    goto L_0x004545ba;
L_0x004545b5:
    // 004545b5  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
L_0x004545ba:
    // 004545ba  a384476600             -mov dword ptr [0x664784], eax
    app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */) = cpu.eax;
L_0x004545bf:
    // 004545bf  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 004545c4  6864985300             -push 0x539864
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478500 /*0x539864*/;
    cpu.esp -= 4;
    // 004545c9  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004545cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004545ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004545cf  891dd4955500           -mov dword ptr [0x5595d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */) = cpu.ebx;
    // 004545d5  891d74955500           -mov dword ptr [0x559574], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608820) /* 0x559574 */) = cpu.ebx;
    // 004545db  e8b0b00800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004545e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004545e3  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004545e6  e8a566ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 004545eb  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004545f2  7407                   -je 0x4545fb
    if (cpu.flags.zf)
    {
        goto L_0x004545fb;
    }
    // 004545f4  ba74985300             -mov edx, 0x539874
    cpu.edx = 5478516 /*0x539874*/;
    // 004545f9  eb05                   -jmp 0x454600
    goto L_0x00454600;
L_0x004545fb:
    // 004545fb  ba7c985300             -mov edx, 0x53987c
    cpu.edx = 5478524 /*0x53987c*/;
L_0x00454600:
    // 00454600  e8dbab0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454605  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454607  e8841d0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045460c  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454611  b884985300             -mov eax, 0x539884
    cpu.eax = 5478532 /*0x539884*/;
    // 00454616  e895170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045461b  66a39c476600           -mov word ptr [0x66479c], ax
    app->getMemory<x86::reg16>(x86::reg32(6703004) /* 0x66479c */) = cpu.ax;
    // 00454621  b88c985300             -mov eax, 0x53988c
    cpu.eax = 5478540 /*0x53988c*/;
    // 00454626  e885170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045462b  66a3a2476600           -mov word ptr [0x6647a2], ax
    app->getMemory<x86::reg16>(x86::reg32(6703010) /* 0x6647a2 */) = cpu.ax;
    // 00454631  b894985300             -mov eax, 0x539894
    cpu.eax = 5478548 /*0x539894*/;
    // 00454636  e875170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045463b  66a3a0476600           -mov word ptr [0x6647a0], ax
    app->getMemory<x86::reg16>(x86::reg32(6703008) /* 0x6647a0 */) = cpu.ax;
    // 00454641  b89c985300             -mov eax, 0x53989c
    cpu.eax = 5478556 /*0x53989c*/;
    // 00454646  e865170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045464b  66a39e476600           -mov word ptr [0x66479e], ax
    app->getMemory<x86::reg16>(x86::reg32(6703006) /* 0x66479e */) = cpu.ax;
    // 00454651  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454653  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454655  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454656  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454657  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454658  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_454660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454661  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454662  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454663  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454665  8b1570955500           -mov edx, dword ptr [0x559570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045466b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045466d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045466f  7510                   -jne 0x454681
    if (!cpu.flags.zf)
    {
        goto L_0x00454681;
    }
    // 00454671  b928975300             -mov ecx, 0x539728
    cpu.ecx = 5478184 /*0x539728*/;
    // 00454676  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045467b  890d24925500           -mov dword ptr [0x559224], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */) = cpu.ecx;
L_0x00454681:
    // 00454681  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454682  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454683  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_454690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454692  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454693  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454695  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454697  8b1570955500           -mov edx, dword ptr [0x559570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045469d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045469f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004546a1  740f                   -je 0x4546b2
    if (cpu.flags.zf)
    {
        goto L_0x004546b2;
    }
    // 004546a3  c7052492550030975300   -mov dword ptr [0x559224], 0x539730
    app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */) = 5478192 /*0x539730*/;
    // 004546ad  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
L_0x004546b2:
    // 004546b2  8b1d8c476600           -mov ebx, dword ptr [0x66478c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */);
    // 004546b8  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 004546bd  39d8                   +cmp eax, ebx
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
    // 004546bf  7415                   -je 0x4546d6
    if (cpu.flags.zf)
    {
        goto L_0x004546d6;
    }
    // 004546c1  8b15ac955500           -mov edx, dword ptr [0x5595ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */);
    // 004546c7  a38c476600             -mov dword ptr [0x66478c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */) = cpu.eax;
    // 004546cc  e81ffdffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 004546d1  a3ac955500             -mov dword ptr [0x5595ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */) = cpu.eax;
L_0x004546d6:
    // 004546d6  8b3590476600           -mov esi, dword ptr [0x664790]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */);
    // 004546dc  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 004546e1  39f0                   +cmp eax, esi
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
    // 004546e3  7415                   -je 0x4546fa
    if (cpu.flags.zf)
    {
        goto L_0x004546fa;
    }
    // 004546e5  8b15b0955500           -mov edx, dword ptr [0x5595b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */);
    // 004546eb  a390476600             -mov dword ptr [0x664790], eax
    app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */) = cpu.eax;
    // 004546f0  e8fbfcffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 004546f5  a3b0955500             -mov dword ptr [0x5595b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */) = cpu.eax;
L_0x004546fa:
    // 004546fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004546fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454700  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454701  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_454710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454710  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454711  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454713  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00454730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454732  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454733  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454735  8b0d70955500           -mov ecx, dword ptr [0x559570]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045473b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045473d  83f904                 +cmp ecx, 4
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
    // 00454740  7734                   -ja 0x454776
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454742  ff248d18474500         -jmp dword ptr [ecx*4 + 0x454718]
    cpu.ip = app->getMemory<x86::reg32>(4540184 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00454749:
    // 00454749  e8e24ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045474e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454750  7524                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454752  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00454757  eb1d                   -jmp 0x454776
    goto L_0x00454776;
  case 0x00454759:
    // 00454759  e8d24ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045475e  83f801                 +cmp eax, 1
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
    // 00454761  7513                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454763  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454765  eb0f                   -jmp 0x454776
    goto L_0x00454776;
  case 0x00454767:
    // 00454767  e8c44ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045476c  83f802                 +cmp eax, 2
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
    // 0045476f  7505                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
  [[fallthrough]];
  case 0x00454771:
    // 00454771  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00454776:
    // 00454776  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454778  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454779  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045477a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045477b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454784  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454786  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454788  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045478b  e86056ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00454790  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454792  7407                   -je 0x45479b
    if (cpu.flags.zf)
    {
        goto L_0x0045479b;
    }
    // 00454794  ba964a0000             -mov edx, 0x4a96
    cpu.edx = 19094 /*0x4a96*/;
    // 00454799  eb05                   -jmp 0x4547a0
    goto L_0x004547a0;
L_0x0045479b:
    // 0045479b  ba40e4ff00             -mov edx, 0xffe440
    cpu.edx = 16770112 /*0xffe440*/;
L_0x004547a0:
    // 004547a0  e82b44feff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 004547a5  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004547a8  8b15504f5500           -mov edx, dword ptr [0x554f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590864) /* 0x554f50 */);
    // 004547ae  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004547b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004547b2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004547b4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x004547b7:
    // 004547b7  3b75f8                 +cmp esi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004547ba  7d0f                   -jge 0x4547cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004547cb;
    }
    // 004547bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004547be  e86dffffff             -call 0x454730
    cpu.esp -= 4;
    sub_454730(app, cpu);
    if (cpu.terminate) return;
    // 004547c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004547c5  7401                   -je 0x4547c8
    if (cpu.flags.zf)
    {
        goto L_0x004547c8;
    }
    // 004547c7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004547c8:
    // 004547c8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004547c9  ebec                   -jmp 0x4547b7
    goto L_0x004547b7;
L_0x004547cb:
    // 004547cb  a1d4955500             -mov eax, dword ptr [0x5595d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
    // 004547d0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004547d2  83f812                 +cmp eax, 0x12
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
    // 004547d5  7d0a                   -jge 0x4547e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004547e1;
    }
    // 004547d7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004547d9  891dd4955500           -mov dword ptr [0x5595d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */) = cpu.ebx;
    // 004547df  eb60                   -jmp 0x454841
    goto L_0x00454841;
L_0x004547e1:
    // 004547e1  833dd495550000         +cmp dword ptr [0x5595d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004547e8  7e57                   -jle 0x454841
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454841;
    }
    // 004547ea  bb9d000000             -mov ebx, 0x9d
    cpu.ebx = 157 /*0x9d*/;
    // 004547ef  a19a476600             -mov eax, dword ptr [0x66479a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703002) /* 0x66479a */);
    // 004547f4  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 004547f9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004547fc  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 00454801  e88a310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454806  ba9b000000             -mov edx, 0x9b
    cpu.edx = 155 /*0x9b*/;
    // 0045480b  b8b7000000             -mov eax, 0xb7
    cpu.eax = 183 /*0xb7*/;
    // 00454810  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00454812  e8297a0400             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 00454817  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454819  7426                   -je 0x454841
    if (cpu.flags.zf)
    {
        goto L_0x00454841;
    }
    // 0045481b  bb9d000000             -mov ebx, 0x9d
    cpu.ebx = 157 /*0x9d*/;
    // 00454820  a19e476600             -mov eax, dword ptr [0x66479e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703006) /* 0x66479e */);
    // 00454825  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045482a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045482d  e85e310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454832  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454839  7406                   -je 0x454841
    if (cpu.flags.zf)
    {
        goto L_0x00454841;
    }
    // 0045483b  ff0dd4955500           -dec dword ptr [0x5595d4]
    (app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */))--;
L_0x00454841:
    // 00454841  a1d4955500             -mov eax, dword ptr [0x5595d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
    // 00454846  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00454849  39f8                   +cmp eax, edi
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
    // 0045484b  7d57                   -jge 0x4548a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004548a4;
    }
    // 0045484d  bb9c010000             -mov ebx, 0x19c
    cpu.ebx = 412 /*0x19c*/;
    // 00454852  a1a0476600             -mov eax, dword ptr [0x6647a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703008) /* 0x6647a0 */);
    // 00454857  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045485c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045485f  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 00454864  e827310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454869  ba9a010000             -mov edx, 0x19a
    cpu.edx = 410 /*0x19a*/;
    // 0045486e  b8b7000000             -mov eax, 0xb7
    cpu.eax = 183 /*0xb7*/;
    // 00454873  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00454875  e8c6790400             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 0045487a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045487c  7426                   -je 0x4548a4
    if (cpu.flags.zf)
    {
        goto L_0x004548a4;
    }
    // 0045487e  bb9c010000             -mov ebx, 0x19c
    cpu.ebx = 412 /*0x19c*/;
    // 00454883  a19c476600             -mov eax, dword ptr [0x66479c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703004) /* 0x66479c */);
    // 00454888  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045488d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00454890  e8fb300800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454895  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045489c  7406                   -je 0x4548a4
    if (cpu.flags.zf)
    {
        goto L_0x004548a4;
    }
    // 0045489e  ff05d4955500           -inc dword ptr [0x5595d4]
    (app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */))++;
L_0x004548a4:
    // 004548a4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004548a6  bf9b000000             -mov edi, 0x9b
    cpu.edi = 155 /*0x9b*/;
    // 004548ab  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004548ae  8b35d4955500           -mov esi, dword ptr [0x5595d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
L_0x004548b4:
    // 004548b4  3b75f8                 +cmp esi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004548b7  0f8df6000000           -jge 0x4549b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004549b3;
    }
    // 004548bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004548bf  e86cfeffff             -call 0x454730
    cpu.esp -= 4;
    sub_454730(app, cpu);
    if (cpu.terminate) return;
    // 004548c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004548c6  0f84e1000000           -je 0x4549ad
    if (cpu.flags.zf)
    {
        goto L_0x004549ad;
    }
    // 004548cc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004548cf  83fa12                 +cmp edx, 0x12
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
    // 004548d2  0f8dd5000000           -jge 0x4549ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004549ad;
    }
    // 004548d8  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004548db  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004548de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004548df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004548e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004548e6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004548e8  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004548eb  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004548f0  e8bb51feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004548f5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004548f7  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004548fc  e88fd8ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00454901  a174955500             -mov eax, dword ptr [0x559574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608820) /* 0x559574 */);
    // 00454906  8b148598955500         -mov edx, dword ptr [eax*4 + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608856) /* 0x559598 */ + cpu.eax * 4);
    // 0045490d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045490f  e84c46feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 00454914  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454916  83f814                 +cmp eax, 0x14
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
    // 00454919  7e05                   -jle 0x454920
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454920;
    }
    // 0045491b  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
L_0x00454920:
    // 00454920  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454927  742d                   -je 0x454956
    if (cpu.flags.zf)
    {
        goto L_0x00454956;
    }
    // 00454929  69d29a000000           -imul edx, edx, 0x9a
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(154 /*0x9a*/)));
    // 0045492f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00454934  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454936  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454939  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045493b  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454940  8d988c010000           -lea ebx, [eax + 0x18c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(396) /* 0x18c */);
    // 00454946  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454948  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045494a  e891a20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 0045494f  ba59010000             -mov edx, 0x159
    cpu.edx = 345 /*0x159*/;
    // 00454954  eb35                   -jmp 0x45498b
    goto L_0x0045498b;
L_0x00454956:
    // 00454956  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045495d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045495f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454961  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00454964  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454966  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454968  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0045496d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454970  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454972  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454977  8d9884010000           -lea ebx, [eax + 0x184]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(388) /* 0x184 */);
    // 0045497d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045497f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454981  e85aa20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454986  ba45010000             -mov edx, 0x145
    cpu.edx = 325 /*0x145*/;
L_0x0045498b:
    // 0045498b  a1b8955500             -mov eax, dword ptr [0x5595b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */);
    // 00454990  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454992  e8f92f0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454997  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 0045499c  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004549a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004549a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004549a5  e836a20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004549aa  83c70f                 +add edi, 0xf
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004549ad:
    // 004549ad  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004549ae  e901ffffff             -jmp 0x4548b4
    goto L_0x004548b4;
L_0x004549b3:
    // 004549b3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004549b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4549c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004549c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004549c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004549c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004549c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004549c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004549c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004549c7  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004549ca  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004549cf  e88c5cffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004549d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004549d6  0f8409020000           -je 0x454be5
    if (cpu.flags.zf)
    {
        goto L_0x00454be5;
    }
    // 004549dc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004549de  eb05                   -jmp 0x4549e5
    goto L_0x004549e5;
L_0x004549e0:
    // 004549e0  83fb04                 +cmp ebx, 4
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
    // 004549e3  7d53                   -jge 0x454a38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454a38;
    }
L_0x004549e5:
    // 004549e5  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004549ec  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 004549f1  8b9698955500           -mov edx, dword ptr [esi + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5608856) /* 0x559598 */);
    // 004549f7  e86445feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 004549fc  89442ed4               -mov dword ptr [esi + ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1) = cpu.eax;
    // 00454a00  83f814                 +cmp eax, 0x14
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
    // 00454a03  7e08                   -jle 0x454a0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a0d;
    }
    // 00454a05  c7442ed414000000       -mov dword ptr [esi + ebp - 0x2c], 0x14
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1) = 20 /*0x14*/;
L_0x00454a0d:
    // 00454a0d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 00454a14  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 00454a19  8b9698955500           -mov edx, dword ptr [esi + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5608856) /* 0x559598 */);
    // 00454a1f  e83c45feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 00454a24  89442ee4               -mov dword ptr [esi + ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1) = cpu.eax;
    // 00454a28  83f814                 +cmp eax, 0x14
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
    // 00454a2b  7e08                   -jle 0x454a35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a35;
    }
    // 00454a2d  c7442ee414000000       -mov dword ptr [esi + ebp - 0x1c], 0x14
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1) = 20 /*0x14*/;
L_0x00454a35:
    // 00454a35  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00454a36  eba8                   -jmp 0x4549e0
    goto L_0x004549e0;
L_0x00454a38:
    // 00454a38  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00454a3a  e9ec000000             -jmp 0x454b2b
    goto L_0x00454b2b;
L_0x00454a3f:
    // 00454a3f  3b4c2ad4               +cmp ecx, dword ptr [edx + ebp - 0x2c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454a43  7d08                   -jge 0x454a4d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454a4d;
    }
    // 00454a45  a1bc955500             -mov eax, dword ptr [0x5595bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */);
    // 00454a4a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00454a4d:
    // 00454a4d  8b54b5d4               -mov edx, dword ptr [ebp + esi*4 - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */ + cpu.esi * 4);
    // 00454a51  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00454a58  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a5a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00454a5d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00454a5f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00454a62  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00454a67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454a69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454a6c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454a6e  ba47010000             -mov edx, 0x147
    cpu.edx = 327 /*0x147*/;
    // 00454a73  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454a78  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00454a7a  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00454a7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454a81  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a85  e856a10600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454a8a  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454a91  740d                   -je 0x454aa0
    if (cpu.flags.zf)
    {
        goto L_0x00454aa0;
    }
    // 00454a93  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 00454a98  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454a9b  8d5f0e                 -lea ebx, [edi + 0xe]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00454a9e  eb0a                   -jmp 0x454aaa
    goto L_0x00454aaa;
L_0x00454aa0:
    // 00454aa0  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 00454aa5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454aa8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00454aaa:
    // 00454aaa  e8e12e0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454aaf  8b54b5e4               -mov edx, dword ptr [ebp + esi*4 - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */ + cpu.esi * 4);
    // 00454ab3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00454aba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454abc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00454abf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00454ac1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00454ac4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00454ac9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454acb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454ace  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454ad0  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454ad5  8d98af010000           -lea ebx, [eax + 0x1af]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(431) /* 0x1af */);
    // 00454adb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454add  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454adf  e8fca00600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454ae4  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454aeb  7412                   -je 0x454aff
    if (cpu.flags.zf)
    {
        goto L_0x00454aff;
    }
    // 00454aed  ba81010000             -mov edx, 0x181
    cpu.edx = 385 /*0x181*/;
    // 00454af2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454af5  8d5f0e                 -lea ebx, [edi + 0xe]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00454af8  e8932e0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454afd  eb0f                   -jmp 0x454b0e
    goto L_0x00454b0e;
L_0x00454aff:
    // 00454aff  ba54010000             -mov edx, 0x154
    cpu.edx = 340 /*0x154*/;
    // 00454b04  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454b07  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454b09  e8522a0800             -call 0x4d7560
    cpu.esp -= 4;
    sub_4d7560(app, cpu);
    if (cpu.terminate) return;
L_0x00454b0e:
    // 00454b0e  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454b13  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00454b18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454b1c  e8bfa00600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454b21  46                     -inc esi
    (cpu.esi)++;
    // 00454b22  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454b25  0f8d82000000           -jge 0x454bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454bad;
    }
L_0x00454b2b:
    // 00454b2b  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00454b31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b33  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00454b36  7405                   -je 0x454b3d
    if (cpu.flags.zf)
    {
        goto L_0x00454b3d;
    }
    // 00454b38  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x00454b3d:
    // 00454b3d  8d1c36                 -lea ebx, [esi + esi]
    cpu.ebx = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00454b40  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00454b45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454b47  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00454b4a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00454b4f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00454b51  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00454b53  8dbb27010000           -lea edi, [ebx + 0x127]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(295) /* 0x127 */);
    // 00454b59  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00454b60  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454b62  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00454b65  8b80c4955500           -mov eax, dword ptr [eax + 0x5595c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608900) /* 0x5595c4 */);
    // 00454b6b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b6d  ba7a010000             -mov edx, 0x17a
    cpu.edx = 378 /*0x17a*/;
    // 00454b72  e8d9cc0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454b77  e814d6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00454b7c  a1b8955500             -mov eax, dword ptr [0x5595b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */);
    // 00454b81  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454b84  a1c0955500             -mov eax, dword ptr [0x5595c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */);
    // 00454b89  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454b8c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00454b8f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454b92  8b4c2ae4               -mov ecx, dword ptr [edx + ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1);
    // 00454b96  3b4c28d4               +cmp ecx, dword ptr [eax + ebp - 0x2c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454b9a  0f8e9ffeffff           -jle 0x454a3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a3f;
    }
    // 00454ba0  a1b4955500             -mov eax, dword ptr [0x5595b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */);
    // 00454ba5  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454ba8  e9a0feffff             -jmp 0x454a4d
    goto L_0x00454a4d;
L_0x00454bad:
    // 00454bad  8b35ac955500           -mov esi, dword ptr [0x5595ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */);
    // 00454bb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00454bb5  7411                   -je 0x454bc8
    if (cpu.flags.zf)
    {
        goto L_0x00454bc8;
    }
    // 00454bb7  bb4e000000             -mov ebx, 0x4e
    cpu.ebx = 78 /*0x4e*/;
    // 00454bbc  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 00454bc1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00454bc3  e8c82d0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00454bc8:
    // 00454bc8  8b3db0955500           -mov edi, dword ptr [0x5595b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */);
    // 00454bce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00454bd0  7411                   -je 0x454be3
    if (cpu.flags.zf)
    {
        goto L_0x00454be3;
    }
    // 00454bd2  bb4e000000             -mov ebx, 0x4e
    cpu.ebx = 78 /*0x4e*/;
    // 00454bd7  ba63010000             -mov edx, 0x163
    cpu.edx = 355 /*0x163*/;
    // 00454bdc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00454bde  e8ad2d0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00454be3:
    // 00454be3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00454be5:
    // 00454be5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454be7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454be8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454be9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454bea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454beb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454bec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_454bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454bf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454bf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454bf3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454bf5  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00454bfb  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00454c00  e85b5affff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00454c05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454c07  0f84d2000000           -je 0x454cdf
    if (cpu.flags.zf)
    {
        goto L_0x00454cdf;
    }
    // 00454c0d  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 00454c12  6864985300             -push 0x539864
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478500 /*0x539864*/;
    cpu.esp -= 4;
    // 00454c17  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00454c1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454c1e  e86daa0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454c23  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00454c26  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00454c2c  e85f60ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00454c31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454c33  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454c3a  7462                   -je 0x454c9e
    if (cpu.flags.zf)
    {
        goto L_0x00454c9e;
    }
    // 00454c3c  baa4985300             -mov edx, 0x5398a4
    cpu.edx = 5478564 /*0x5398a4*/;
    // 00454c41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c43  e898a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c48  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c4a  e841170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c4f  baac985300             -mov edx, 0x5398ac
    cpu.edx = 5478572 /*0x5398ac*/;
    // 00454c54  a3b4955500             -mov dword ptr [0x5595b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */) = cpu.eax;
    // 00454c59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c5b  e880a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c62  e829170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c67  bab4985300             -mov edx, 0x5398b4
    cpu.edx = 5478580 /*0x5398b4*/;
    // 00454c6c  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454c71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c73  e868a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c7a  e811170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c7f  babc985300             -mov edx, 0x5398bc
    cpu.edx = 5478588 /*0x5398bc*/;
    // 00454c84  a3bc955500             -mov dword ptr [0x5595bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */) = cpu.eax;
    // 00454c89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c8b  e850a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c90  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00454c92  e8f9160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c97  a3c0955500             -mov dword ptr [0x5595c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */) = cpu.eax;
    // 00454c9c  eb41                   -jmp 0x454cdf
    goto L_0x00454cdf;
L_0x00454c9e:
    // 00454c9e  bac4985300             -mov edx, 0x5398c4
    cpu.edx = 5478596 /*0x5398c4*/;
    // 00454ca3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454ca5  e836a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454caa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cac  e8df160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454cb1  bacc985300             -mov edx, 0x5398cc
    cpu.edx = 5478604 /*0x5398cc*/;
    // 00454cb6  a3b4955500             -mov dword ptr [0x5595b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */) = cpu.eax;
    // 00454cbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454cbd  e81ea50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454cc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cc4  e8c7160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454cc9  8b0db4955500           -mov ecx, dword ptr [0x5595b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */);
    // 00454ccf  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454cd4  a3c0955500             -mov dword ptr [0x5595c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */) = cpu.eax;
    // 00454cd9  890dbc955500           -mov dword ptr [0x5595bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */) = cpu.ecx;
L_0x00454cdf:
    // 00454cdf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454ce1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_454cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454cf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454cf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454cf2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454cf4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cf6  e8b57c0100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00454cfb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00454cfe  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00454d01  e8daf90000             -call 0x4646e0
    cpu.esp -= 4;
    sub_4646e0(app, cpu);
    if (cpu.terminate) return;
    // 00454d06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454d11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454d13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d15  bad4985300             -mov edx, 0x5398d4
    cpu.edx = 5478612 /*0x5398d4*/;
    // 00454d1a  e821ddfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454d1f  baf04c4500             -mov edx, 0x454cf0
    cpu.edx = 4541680 /*0x454cf0*/;
    // 00454d24  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454d26  e8957d0100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00454d2b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454d2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454d2f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454d31  e81a7c0100             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00454d36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454d38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454d41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454d45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_454d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454d51  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454d55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_454d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454d62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454d63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454d64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454d65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454d66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454d6a  bae0985300             -mov edx, 0x5398e0
    cpu.edx = 5478624 /*0x5398e0*/;
    // 00454d6f  e83c61ffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00454d74  e8c7dcfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454d79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454d7b  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454d80  8b0445da635500         -mov eax, dword ptr [eax*2 + 0x5563da]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5596122) /* 0x5563da */ + cpu.eax * 2);
    // 00454d87  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00454d8a  e8c1ca0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454d8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454d90  68e8985300             -push 0x5398e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478632 /*0x5398e8*/;
    cpu.esp -= 4;
    // 00454d95  6800476600             -push 0x664700
    app->getMemory<x86::reg32>(cpu.esp-4) = 6702848 /*0x664700*/;
    cpu.esp -= 4;
    // 00454d9a  e8f1a80800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454d9f  c7423c00476600         -mov dword ptr [edx + 0x3c], 0x664700
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = 6702848 /*0x664700*/;
    // 00454da6  8b154cbb6f00           -mov edx, dword ptr [0x6fbb4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00454dac  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00454daf  83fa01                 +cmp edx, 1
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
    // 00454db2  7545                   -jne 0x454df9
    if (!cpu.flags.zf)
    {
        goto L_0x00454df9;
    }
    // 00454db4  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454db9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00454dbb  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00454dc0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454dc2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454dc5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454dc7  8b0455da635500         -mov eax, dword ptr [edx*2 + 0x5563da]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5596122) /* 0x5563da */ + cpu.edx * 2);
    // 00454dce  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00454dd1  bf80466600             -mov edi, 0x664680
    cpu.edi = 6702720 /*0x664680*/;
    // 00454dd6  e875ca0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454ddb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00454ddd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00454dde:
    // 00454dde  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00454de0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00454de2  3c00                   +cmp al, 0
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
    // 00454de4  7410                   -je 0x454df6
    if (cpu.flags.zf)
    {
        goto L_0x00454df6;
    }
    // 00454de6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00454de9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00454dec  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00454def  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00454df2  3c00                   +cmp al, 0
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
    // 00454df4  75e8                   -jne 0x454dde
    if (!cpu.flags.zf)
    {
        goto L_0x00454dde;
    }
L_0x00454df6:
    // 00454df6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454df7  eb36                   -jmp 0x454e2f
    goto L_0x00454e2f;
L_0x00454df9:
    // 00454df9  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454dfe  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00454e01  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00454e06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454e08  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454e0b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454e0d  8b0455da635500         -mov eax, dword ptr [edx*2 + 0x5563da]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5596122) /* 0x5563da */ + cpu.edx * 2);
    // 00454e14  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00454e17  e834ca0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454e1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454e1d  68ec985300             -push 0x5398ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478636 /*0x5398ec*/;
    cpu.esp -= 4;
    // 00454e22  6880466600             -push 0x664680
    app->getMemory<x86::reg32>(cpu.esp-4) = 6702720 /*0x664680*/;
    cpu.esp -= 4;
    // 00454e27  e864a80800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454e2c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00454e2f:
    // 00454e2f  c7413c80466600         -mov dword ptr [ecx + 0x3c], 0x664680
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 6702720 /*0x664680*/;
    // 00454e36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_454e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454e43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454e44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454e45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454e47  8b0d94476600           -mov ecx, dword ptr [0x664794]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454e4d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00454e4f  41                     -inc ecx
    (cpu.ecx)++;
    // 00454e50  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 00454e55  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00454e57  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454e59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454e5c  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454e5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454e60  891594476600           -mov dword ptr [0x664794], edx
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.edx;
    // 00454e66  e8f5feffff             -call 0x454d60
    cpu.esp -= 4;
    sub_454d60(app, cpu);
    if (cpu.terminate) return;
    // 00454e6b  8b0d94476600           -mov ecx, dword ptr [0x664794]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454e71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454e73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454e80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454e81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454e82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454e84  8b1580476600           -mov edx, dword ptr [0x664780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6702976) /* 0x664780 */);
    // 00454e8a  891594476600           -mov dword ptr [0x664794], edx
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.edx;
    // 00454e90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454e92  891598476600           -mov dword ptr [0x664798], edx
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.edx;
    // 00454e98  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454e9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454e9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_454ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454ea3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454ea4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454ea6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454ea8  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454ead  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454eaf  a380476600             -mov dword ptr [0x664780], eax
    app->getMemory<x86::reg32>(x86::reg32(6702976) /* 0x664780 */) = cpu.eax;
    // 00454eb4  891594476600           -mov dword ptr [0x664794], edx
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.edx;
    // 00454eba  891598476600           -mov dword ptr [0x664798], edx
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.edx;
    // 00454ec0  bad4985300             -mov edx, 0x5398d4
    cpu.edx = 5478612 /*0x5398d4*/;
    // 00454ec5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454ec7  e874dbfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454ecc  baf04c4500             -mov edx, 0x454cf0
    cpu.edx = 4541680 /*0x454cf0*/;
    // 00454ed1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00454ed3  e8e87b0100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00454ed8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454eda  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454edc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454ede  baf4985300             -mov edx, 0x5398f4
    cpu.edx = 5478644 /*0x5398f4*/;
    // 00454ee3  e8687a0100             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00454ee8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454eea  e851dbfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454eef  c74064404e4500         -mov dword ptr [eax + 0x64], 0x454e40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4542016 /*0x454e40*/;
    // 00454ef6  e865feffff             -call 0x454d60
    cpu.esp -= 4;
    sub_454d60(app, cpu);
    if (cpu.terminate) return;
    // 00454efb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454efd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454efe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454eff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454f00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454f01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 1e001900140010000c000800040000000c00000008000000060000000500000004000000030000000200000001000000140000000f0000000c0000000a0000000800000004000000030000000200000008000000070000000600000005000000040000000300000002000000010000000a00000009000000080000000700000006000000050000000300000002000000100000000800000006000000000000000000000000000000000000000000000014000000100000000c00000000000000000000000000000000000000000000000100000004000000080000000a00000014000000280000003c0000005000000002000000080000001000000014000000190000003c0000004b00000064000000 */
void Application::sub_455020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455020  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455021  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455025  742a                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 00455027  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0045502e  7421                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 00455030  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 00455037  7e18                   -jle 0x455051
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455051;
    }
    // 00455039  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 0045503f  66833c45ca227a0000     +cmp word ptr [eax*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455048  7407                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 0045504a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045504f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455050  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00455051:
    // 00455051  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455053  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455054  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455060  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455061  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455063  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455064  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455075  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455076  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455078  e8039f0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 0045507d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045507f  0f85ab000000           -jne 0x455130
    if (!cpu.flags.zf)
    {
        goto L_0x00455130;
    }
    // 00455085  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045508a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045508c  e87f0b0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455091  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00455093:
    // 00455093  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455099  7d40                   -jge 0x4550db
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004550db;
    }
    // 0045509b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045509d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045509f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004550a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004550a3  e8280c0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004550a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004550aa  742c                   -je 0x4550d8
    if (cpu.flags.zf)
    {
        goto L_0x004550d8;
    }
    // 004550ac  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004550b2  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004550b5  668b1475104f4500       -mov dx, word ptr [esi*2 + 0x454f10]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4542224) /* 0x454f10 */ + cpu.esi * 2);
    // 004550bd  6689144d2ed46f00       -mov word ptr [ecx*2 + 0x6fd42e], dx
    app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.ecx * 2) = cpu.dx;
    // 004550c5  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004550cb  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004550ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004550d0  66013c454ed46f00       +add word ptr [eax*2 + 0x6fd44e], di
    {
        auto tmp1 = app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004550d8:
    // 004550d8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004550d9  ebb8                   -jmp 0x455093
    goto L_0x00455093;
L_0x004550db:
    // 004550db  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004550e0  b80ed46f00             -mov eax, 0x6fd40e
    cpu.eax = 7328782 /*0x6fd40e*/;
    // 004550e5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004550ea  e81db60800             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004550ef  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004550f1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004550f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004550f5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004550f7  e8140b0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004550fc  eb05                   -jmp 0x455103
    goto L_0x00455103;
L_0x004550fe:
    // 004550fe  83fe08                 +cmp esi, 8
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
    // 00455101  7f26                   -jg 0x455129
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455129;
    }
L_0x00455103:
    // 00455103  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00455105  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00455107  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455109  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045510b  e8c00b0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455110  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455112  7412                   -je 0x455126
    if (cpu.flags.zf)
    {
        goto L_0x00455126;
    }
    // 00455114  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045511a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0045511d  66893c450ed46f00       -mov word ptr [eax*2 + 0x6fd40e], di
    app->getMemory<x86::reg16>(x86::reg32(7328782) /* 0x6fd40e */ + cpu.eax * 2) = cpu.di;
    // 00455125  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00455126:
    // 00455126  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455127  ebd5                   -jmp 0x4550fe
    goto L_0x004550fe;
L_0x00455129:
    // 00455129  66ff050cd46f00         -inc word ptr [0x6fd40c]
    (app->getMemory<x86::reg16>(x86::reg32(7328780) /* 0x6fd40c */))++;
L_0x00455130:
    // 00455130  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455131  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455132  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455133  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455134  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455136  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_455140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455143  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455144  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455145  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455146  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455148  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045514d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045514f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00455151  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00455156  e8b50a0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 0045515b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455160  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455162  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455164  e8670b0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455169  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045516b  7426                   -je 0x455193
    if (cpu.flags.zf)
    {
        goto L_0x00455193;
    }
    // 0045516d  833d307d670001         +cmp dword ptr [0x677d30], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455174  7e1d                   -jle 0x455193
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455193;
    }
    // 00455176  8bb020020000           -mov esi, dword ptr [eax + 0x220]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045517c  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0045517f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455181  66891475ded36f00       -mov word ptr [esi*2 + 0x6fd3de], dx
    app->getMemory<x86::reg16>(x86::reg32(7328734) /* 0x6fd3de */ + cpu.esi * 2) = cpu.dx;
    // 00455189  c780c402000002000000   -mov dword ptr [eax + 0x2c4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */) = 2 /*0x2*/;
L_0x00455193:
    // 00455193  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00455198  b8bed36f00             -mov eax, 0x6fd3be
    cpu.eax = 7328702 /*0x6fd3be*/;
    // 0045519d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004551a2  e865b50800             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004551a7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004551a9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004551ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004551ad  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004551af  e85c0a0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004551b4  eb18                   -jmp 0x4551ce
    goto L_0x004551ce;
L_0x004551b6:
    // 004551b6  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004551bc  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004551bf  66893c45bed36f00       -mov word ptr [eax*2 + 0x6fd3be], di
    app->getMemory<x86::reg16>(x86::reg32(7328702) /* 0x6fd3be */ + cpu.eax * 2) = cpu.di;
    // 004551c7  47                     -inc edi
    (cpu.edi)++;
L_0x004551c8:
    // 004551c8  46                     -inc esi
    (cpu.esi)++;
    // 004551c9  83fe08                 +cmp esi, 8
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
    // 004551cc  7f32                   -jg 0x455200
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455200;
    }
L_0x004551ce:
    // 004551ce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004551d0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004551d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004551d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004551d6  e8f50a0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004551db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004551dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004551df  74e7                   -je 0x4551c8
    if (cpu.flags.zf)
    {
        goto L_0x004551c8;
    }
    // 004551e1  f6800002000008         +test byte ptr [eax + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 004551e8  74cc                   -je 0x4551b6
    if (cpu.flags.zf)
    {
        goto L_0x004551b6;
    }
    // 004551ea  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004551f0  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004551f3  66833c45ded36f0000     +cmp word ptr [eax*2 + 0x6fd3de], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(7328734) /* 0x6fd3de */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004551fc  74ca                   -je 0x4551c8
    if (cpu.flags.zf)
    {
        goto L_0x004551c8;
    }
    // 004551fe  ebb6                   -jmp 0x4551b6
    goto L_0x004551b6;
L_0x00455200:
    // 00455200  66ff05bcd36f00         -inc word ptr [0x6fd3bc]
    (app->getMemory<x86::reg16>(x86::reg32(7328700) /* 0x6fd3bc */))++;
    // 00455207  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455208  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455209  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_455210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455212  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455213  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455214  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455215  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455217  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045521a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045521d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00455223  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00455225:
    // 00455225  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045522b  7d4a                   -jge 0x455277
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455277;
    }
    // 0045522d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 00455234  8b86c8fa5e00           -mov eax, dword ptr [esi + 0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 0045523a  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00455241  7431                   -je 0x455274
    if (cpu.flags.zf)
    {
        goto L_0x00455274;
    }
    // 00455243  e8d8fdffff             -call 0x455020
    cpu.esp -= 4;
    sub_455020(app, cpu);
    if (cpu.terminate) return;
    // 00455248  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045524a  7528                   -jne 0x455274
    if (!cpu.flags.zf)
    {
        goto L_0x00455274;
    }
    // 0045524c  6902ac090000           -imul eax, dword ptr [edx], 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455252  b9ac090000             -mov ecx, 0x9ac
    cpu.ecx = 2476 /*0x9ac*/;
    // 00455257  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045525a  8bb6c8fa5e00           -mov esi, dword ptr [esi + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 00455260  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455262  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455263  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00455265  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00455268  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045526a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045526c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045526f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00455271  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455272  ff02                   +inc dword ptr [edx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00455274:
    // 00455274  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455275  ebae                   -jmp 0x455225
    goto L_0x00455225;
L_0x00455277:
    // 00455277  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455279  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_455280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455284  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455285  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455287  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045528a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045528d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00455293  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00455295:
    // 00455295  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045529b  7d4a                   -jge 0x4552e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004552e7;
    }
    // 0045529d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004552a4  8b86c8fa5e00           -mov eax, dword ptr [esi + 0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 004552aa  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 004552b1  7431                   -je 0x4552e4
    if (cpu.flags.zf)
    {
        goto L_0x004552e4;
    }
    // 004552b3  e868fdffff             -call 0x455020
    cpu.esp -= 4;
    sub_455020(app, cpu);
    if (cpu.terminate) return;
    // 004552b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004552ba  7528                   -jne 0x4552e4
    if (!cpu.flags.zf)
    {
        goto L_0x004552e4;
    }
    // 004552bc  6902ac090000           -imul eax, dword ptr [edx], 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 004552c2  b9ac090000             -mov ecx, 0x9ac
    cpu.ecx = 2476 /*0x9ac*/;
    // 004552c7  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004552ca  8bb6c8fa5e00           -mov esi, dword ptr [esi + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 004552d0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004552d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004552d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004552d5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004552d8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004552da  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004552dc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004552df  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004552e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552e2  ff02                   +inc dword ptr [edx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004552e4:
    // 004552e4  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004552e5  ebae                   -jmp 0x455295
    goto L_0x00455295;
L_0x004552e7:
    // 004552e7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004552e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4552f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004552f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004552f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004552f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004552f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004552f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004552f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004552f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004552f8  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004552ff  753f                   -jne 0x455340
    if (!cpu.flags.zf)
    {
        goto L_0x00455340;
    }
    // 00455301  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00455306  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455308  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045530a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045530c  e8ff080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
L_0x00455311:
    // 00455311  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455317  7d27                   -jge 0x455340
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455340;
    }
    // 00455319  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045531b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045531d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045531f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455321  e8aa090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455326  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455328  7413                   -je 0x45533d
    if (cpu.flags.zf)
    {
        goto L_0x0045533d;
    }
    // 0045532a  f6800002000080         +test byte ptr [eax + 0x200], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 128 /*0x80*/));
    // 00455331  740a                   -je 0x45533d
    if (cpu.flags.zf)
    {
        goto L_0x0045533d;
    }
    // 00455333  c780c402000002000000   -mov dword ptr [eax + 0x2c4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */) = 2 /*0x2*/;
L_0x0045533d:
    // 0045533d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045533e  ebd1                   -jmp 0x455311
    goto L_0x00455311;
L_0x00455340:
    // 00455340  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00455345  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455347  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00455349  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045534e  e8bd080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455353  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455358  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045535a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045535c  e86f090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455363  745f                   -je 0x4553c4
    if (cpu.flags.zf)
    {
        goto L_0x004553c4;
    }
    // 00455365  8bb038020000           -mov esi, dword ptr [eax + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */);
    // 0045536b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045536d  83c63c                 -add esi, 0x3c
    (cpu.esi) += x86::reg32(x86::sreg32(60 /*0x3c*/));
L_0x00455370:
    // 00455370  3b3d307d6700           +cmp edi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455376  7d21                   -jge 0x455399
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455399;
    }
    // 00455378  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045537d  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00455382  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455384  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455386  e845090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 0045538b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045538d  7407                   -je 0x455396
    if (cpu.flags.zf)
    {
        goto L_0x00455396;
    }
    // 0045538f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455390  89b038020000           -mov dword ptr [eax + 0x238], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */) = cpu.esi;
L_0x00455396:
    // 00455396  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455397  ebd7                   -jmp 0x455370
    goto L_0x00455370;
L_0x00455399:
    // 00455399  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0045539b:
    // 0045539b  3b3d307d6700           +cmp edi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004553a1  7d21                   -jge 0x4553c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004553c4;
    }
    // 004553a3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004553a8  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004553ad  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004553af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553b1  e81a090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004553b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004553b8  7407                   -je 0x4553c1
    if (cpu.flags.zf)
    {
        goto L_0x004553c1;
    }
    // 004553ba  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553bb  89b038020000           -mov dword ptr [eax + 0x238], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */) = cpu.esi;
L_0x004553c1:
    // 004553c1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553c2  ebd7                   -jmp 0x45539b
    goto L_0x0045539b;
L_0x004553c4:
    // 004553c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004553c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004553cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553cd  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004553d2  e839080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004553d7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004553d9:
    // 004553d9  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004553df  7d1b                   -jge 0x4553fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004553fc;
    }
    // 004553e1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004553e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004553e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004553e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553e9  e8e2080000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004553ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004553f0  7406                   -je 0x4553f8
    if (cpu.flags.zf)
    {
        goto L_0x004553f8;
    }
    // 004553f2  89b8bc020000           -mov dword ptr [eax + 0x2bc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */) = cpu.edi;
L_0x004553f8:
    // 004553f8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553f9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553fa  ebdd                   -jmp 0x4553d9
    goto L_0x004553d9;
L_0x004553fc:
    // 004553fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455400  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455401  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455413  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455414  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455416  833da0d36f0000         +cmp dword ptr [0x6fd3a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045541d  0f85af000000           -jne 0x4554d2
    if (!cpu.flags.zf)
    {
        goto L_0x004554d2;
    }
    // 00455423  e8782a0700             -call 0x4c7ea0
    cpu.esp -= 4;
    sub_4c7ea0(app, cpu);
    if (cpu.terminate) return;
    // 00455428  e8a393ffff             -call 0x44e7d0
    cpu.esp -= 4;
    sub_44e7d0(app, cpu);
    if (cpu.terminate) return;
    // 0045542d  e8dea0ffff             -call 0x44f510
    cpu.esp -= 4;
    sub_44f510(app, cpu);
    if (cpu.terminate) return;
    // 00455432  ba307d6700             -mov edx, 0x677d30
    cpu.edx = 6782256 /*0x677d30*/;
    // 00455437  b8b0476600             -mov eax, 0x6647b0
    cpu.eax = 6703024 /*0x6647b0*/;
    // 0045543c  e8cffdffff             -call 0x455210
    cpu.esp -= 4;
    sub_455210(app, cpu);
    if (cpu.terminate) return;
    // 00455441  ba347d6700             -mov edx, 0x677d34
    cpu.edx = 6782260 /*0x677d34*/;
    // 00455446  b870e26600             -mov eax, 0x66e270
    cpu.eax = 6742640 /*0x66e270*/;
    // 0045544b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045544d  e82efeffff             -call 0x455280
    cpu.esp -= 4;
    sub_455280(app, cpu);
    if (cpu.terminate) return;
    // 00455452  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455454  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455456  e8b5070000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 0045545b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00455460  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455462  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455464  e8a7070000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455469  e882feffff             -call 0x4552f0
    cpu.esp -= 4;
    sub_4552f0(app, cpu);
    if (cpu.terminate) return;
    // 0045546e  833db8d36f0001         +cmp dword ptr [0x6fd3b8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455475  7505                   -jne 0x45547c
    if (!cpu.flags.zf)
    {
        goto L_0x0045547c;
    }
    // 00455477  e8f4fbffff             -call 0x455070
    cpu.esp -= 4;
    sub_455070(app, cpu);
    if (cpu.terminate) return;
L_0x0045547c:
    // 0045547c  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455483  7505                   -jne 0x45548a
    if (!cpu.flags.zf)
    {
        goto L_0x0045548a;
    }
    // 00455485  e8b6fcffff             -call 0x455140
    cpu.esp -= 4;
    sub_455140(app, cpu);
    if (cpu.terminate) return;
L_0x0045548a:
    // 0045548a  e821a5ffff             -call 0x44f9b0
    cpu.esp -= 4;
    sub_44f9b0(app, cpu);
    if (cpu.terminate) return;
    // 0045548f  e8ec9a0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 00455494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455496  751e                   -jne 0x4554b6
    if (!cpu.flags.zf)
    {
        goto L_0x004554b6;
    }
    // 00455498  e853beffff             -call 0x4512f0
    cpu.esp -= 4;
    sub_4512f0(app, cpu);
    if (cpu.terminate) return;
    // 0045549d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045549f  e87c93ffff             -call 0x44e820
    cpu.esp -= 4;
    sub_44e820(app, cpu);
    if (cpu.terminate) return;
    // 004554a4  8b35b0d36f00           -mov esi, dword ptr [0x6fd3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004554aa  83fe01                 +cmp esi, 1
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
    // 004554ad  7507                   -jne 0x4554b6
    if (!cpu.flags.zf)
    {
        goto L_0x004554b6;
    }
    // 004554af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004554b1  e86a93ffff             -call 0x44e820
    cpu.esp -= 4;
    sub_44e820(app, cpu);
    if (cpu.terminate) return;
L_0x004554b6:
    // 004554b6  e835a1ffff             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    if (cpu.terminate) return;
    // 004554bb  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004554c2  7e0e                   -jle 0x4554d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004554d2;
    }
    // 004554c4  e8b79a0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 004554c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004554cb  7505                   -jne 0x4554d2
    if (!cpu.flags.zf)
    {
        goto L_0x004554d2;
    }
    // 004554cd  e88efbffff             -call 0x455060
    cpu.esp -= 4;
    sub_455060(app, cpu);
    if (cpu.terminate) return;
L_0x004554d2:
    // 004554d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4554e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004554e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004554e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004554e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004554e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004554e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004554e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004554e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004554ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004554ec  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004554ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004554f1:
    // 004554f1  3b048d307d6700         +cmp eax, dword ptr [ecx*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.ecx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004554f8  7d28                   -jge 0x455522
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455522;
    }
    // 004554fa  69d0ac090000           -imul edx, eax, 0x9ac
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455500  69d9c09a0000           -imul ebx, ecx, 0x9ac0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455506  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00455509  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045550c  3bbea0496600           +cmp edi, dword ptr [esi + 0x6649a0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6703520) /* 0x6649a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455512  750b                   -jne 0x45551f
    if (!cpu.flags.zf)
    {
        goto L_0x0045551f;
    }
    // 00455514  b8b0476600             -mov eax, 0x6647b0
    cpu.eax = 6703024 /*0x6647b0*/;
    // 00455519  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045551b  01d0                   +add eax, edx
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
    // 0045551d  eb05                   -jmp 0x455524
    goto L_0x00455524;
L_0x0045551f:
    // 0045551f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455520  ebcf                   -jmp 0x4554f1
    goto L_0x004554f1;
L_0x00455522:
    // 00455522  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455524:
    // 00455524  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455526  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455527  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455528  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455529  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045552a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045552b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_455530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455531  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455532  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455534  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455536  742a                   -je 0x455562
    if (cpu.flags.zf)
    {
        goto L_0x00455562;
    }
    // 00455538  8b8820020000           -mov ecx, dword ptr [eax + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045553e  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00455541  8b0c4d2cd46f00         -mov ecx, dword ptr [ecx*2 + 0x6fd42c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.ecx * 2);
    // 00455548  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045554b  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0045554d  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00455553  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455556  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 0045555d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455560  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00455562:
    // 00455562  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455563  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455573  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455575  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455577  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045557a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045557c  743b                   -je 0x4555b9
    if (cpu.flags.zf)
    {
        goto L_0x004555b9;
    }
    // 0045557e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455584  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045558b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045558d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455590  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455592  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455595  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455597  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045559c  8d7034                 -lea esi, [eax + 0x34]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0045559f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004555a0:
    // 004555a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004555a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004555a4  3c00                   +cmp al, 0
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
    // 004555a6  7410                   -je 0x4555b8
    if (cpu.flags.zf)
    {
        goto L_0x004555b8;
    }
    // 004555a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004555ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004555b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555b4  3c00                   +cmp al, 0
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
    // 004555b6  75e8                   -jne 0x4555a0
    if (!cpu.flags.zf)
    {
        goto L_0x004555a0;
    }
L_0x004555b8:
    // 004555b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004555b9:
    // 004555b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4555c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004555c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004555c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004555c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004555c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004555c5  8b80bc020000           -mov eax, dword ptr [eax + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */);
    // 004555cb  83c02f                 -add eax, 0x2f
    (cpu.eax) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 004555ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004555d0  e87bc20700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004555d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004555d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004555d8:
    // 004555d8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004555da  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004555dc  3c00                   +cmp al, 0
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
    // 004555de  7410                   -je 0x4555f0
    if (cpu.flags.zf)
    {
        goto L_0x004555f0;
    }
    // 004555e0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004555e3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555e6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004555e9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555ec  3c00                   +cmp al, 0
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
    // 004555ee  75e8                   -jne 0x4555d8
    if (!cpu.flags.zf)
    {
        goto L_0x004555d8;
    }
L_0x004555f0:
    // 004555f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455602  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455603  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455605  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455607  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045560a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045560c  7442                   -je 0x455650
    if (cpu.flags.zf)
    {
        goto L_0x00455650;
    }
    // 0045560e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455614  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045561b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045561d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455620  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455622  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455625  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455627  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045562c  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045562f  e81c3cfeff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 00455634  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455636  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00455637:
    // 00455637  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00455639  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045563b  3c00                   +cmp al, 0
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
    // 0045563d  7410                   -je 0x45564f
    if (cpu.flags.zf)
    {
        goto L_0x0045564f;
    }
    // 0045563f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00455642  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00455645  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00455648  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045564b  3c00                   +cmp al, 0
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
    // 0045564d  75e8                   -jne 0x455637
    if (!cpu.flags.zf)
    {
        goto L_0x00455637;
    }
L_0x0045564f:
    // 0045564f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00455650:
    // 00455650  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_455660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455661  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455662  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455663  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455665  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455667  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045566a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045566c  7444                   -je 0x4556b2
    if (cpu.flags.zf)
    {
        goto L_0x004556b2;
    }
    // 0045566e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455674  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045567b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045567d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455680  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455682  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455685  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455687  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045568c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045568e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00455691  e81a44feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00455696  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455698  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00455699:
    // 00455699  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045569b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045569d  3c00                   +cmp al, 0
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
    // 0045569f  7410                   -je 0x4556b1
    if (cpu.flags.zf)
    {
        goto L_0x004556b1;
    }
    // 004556a1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004556a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004556a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004556aa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004556ad  3c00                   +cmp al, 0
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
    // 004556af  75e8                   -jne 0x455699
    if (!cpu.flags.zf)
    {
        goto L_0x00455699;
    }
L_0x004556b1:
    // 004556b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004556b2:
    // 004556b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4556c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004556c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004556c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004556c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004556c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004556c5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004556c7  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004556ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004556cc  7447                   -je 0x455715
    if (cpu.flags.zf)
    {
        goto L_0x00455715;
    }
    // 004556ce  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004556d4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004556db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004556dd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004556e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004556e2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004556e5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004556e7  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 004556ec  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004556f1  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004556f4  e8b743feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004556f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004556fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004556fc:
    // 004556fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004556fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00455700  3c00                   +cmp al, 0
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
    // 00455702  7410                   -je 0x455714
    if (cpu.flags.zf)
    {
        goto L_0x00455714;
    }
    // 00455704  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00455707  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045570a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045570d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00455710  3c00                   +cmp al, 0
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
    // 00455712  75e8                   -jne 0x4556fc
    if (!cpu.flags.zf)
    {
        goto L_0x004556fc;
    }
L_0x00455714:
    // 00455714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00455715:
    // 00455715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455716  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455718  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455721  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455722  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455724  83ec04                 +sub esp, 4
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
    // 00455727  8b80b8020000           -mov eax, dword ptr [eax + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
    // 0045572d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00455730  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00455733  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00455735  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00455737  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455739  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0045573a  7353                   -jae 0x45578f
    if (!cpu.flags.cf)
    {
        goto L_0x0045578f;
    }
    // 0045573c  8b0d68bc6f00           -mov ecx, dword ptr [0x6fbc68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 00455742  83f903                 +cmp ecx, 3
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
    // 00455745  7405                   -je 0x45574c
    if (cpu.flags.zf)
    {
        goto L_0x0045574c;
    }
    // 00455747  83f904                 +cmp ecx, 4
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
    // 0045574a  7516                   -jne 0x455762
    if (!cpu.flags.zf)
    {
        goto L_0x00455762;
    }
L_0x0045574c:
    // 0045574c  b857010000             -mov eax, 0x157
    cpu.eax = 343 /*0x157*/;
    // 00455751  e8fac00700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00455756  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00455759  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045575a  d80d10995300           +fmul dword ptr [0x539910]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478672) /* 0x539910 */));
    // 00455760  eb14                   -jmp 0x455776
    goto L_0x00455776;
L_0x00455762:
    // 00455762  b856010000             -mov eax, 0x156
    cpu.eax = 342 /*0x156*/;
    // 00455767  e8e4c00700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0045576c  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0045576f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455770  d80d14995300           -fmul dword ptr [0x539914]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478676) /* 0x539914 */));
L_0x00455776:
    // 00455776  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00455779  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0045577c  6800995300             -push 0x539900
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478656 /*0x539900*/;
    cpu.esp -= 4;
    // 00455781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455782  e8099f0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00455787  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045578a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045578c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045578d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045578e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045578f:
    // 0045578f  680c995300             -push 0x53990c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478668 /*0x53990c*/;
    cpu.esp -= 4;
    // 00455794  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455795  e8f69e0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045579a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045579d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045579f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4557b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004557b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004557b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004557b3  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004557b6  740d                   -je 0x4557c5
    if (cpu.flags.zf)
    {
        goto L_0x004557c5;
    }
    // 004557b8  f6800002000002         +test byte ptr [eax + 0x200], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 2 /*0x2*/));
    // 004557bf  7504                   -jne 0x4557c5
    if (!cpu.flags.zf)
    {
        goto L_0x004557c5;
    }
L_0x004557c1:
    // 004557c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004557c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004557c5:
    // 004557c5  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004557c8  7409                   -je 0x4557d3
    if (cpu.flags.zf)
    {
        goto L_0x004557d3;
    }
    // 004557ca  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004557d1  74ee                   -je 0x4557c1
    if (cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557d3:
    // 004557d3  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004557d6  7409                   -je 0x4557e1
    if (cpu.flags.zf)
    {
        goto L_0x004557e1;
    }
    // 004557d8  f6800002000002         +test byte ptr [eax + 0x200], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 2 /*0x2*/));
    // 004557df  75e0                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557e1:
    // 004557e1  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004557e4  7409                   -je 0x4557ef
    if (cpu.flags.zf)
    {
        goto L_0x004557ef;
    }
    // 004557e6  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004557ed  75d2                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557ef:
    // 004557ef  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004557f2  7408                   -je 0x4557fc
    if (cpu.flags.zf)
    {
        goto L_0x004557fc;
    }
    // 004557f4  3b98c4020000           +cmp ebx, dword ptr [eax + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004557fa  75c5                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557fc:
    // 004557fc  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004557ff  7408                   -je 0x455809
    if (cpu.flags.zf)
    {
        goto L_0x00455809;
    }
    // 00455801  3b98c4020000           +cmp ebx, dword ptr [eax + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455807  74b8                   -je 0x4557c1
    if (cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x00455809:
    // 00455809  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045580e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045580f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_455840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00455840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455842  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455843  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455844  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455845  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455847  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00455849  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045584b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045584d  a118965500             -mov eax, dword ptr [0x559618]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608984) /* 0x559618 */);
    // 00455852  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455854  83f808                 +cmp eax, 8
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
    // 00455857  0f8758030000           -ja 0x455bb5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 0045585d  ff248510584500         -jmp dword ptr [eax*4 + 0x455810]
    cpu.ip = app->getMemory<x86::reg32>(4544528 + cpu.eax * 4); goto dynamic_jump;
  case 0x00455864:
    // 00455864  8b9320020000           -mov edx, dword ptr [ebx + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0045586a  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455870  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00455873  83c034                 +add eax, 0x34
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00455876  e845460900             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 0045587b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045587d  e933030000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455882:
    // 00455882  8bb3d4020000           -mov esi, dword ptr [ebx + 0x2d4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 00455888  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045588a  743f                   -je 0x4558cb
    if (cpu.flags.zf)
    {
        goto L_0x004558cb;
    }
    // 0045588c  8bb9d4020000           -mov edi, dword ptr [ecx + 0x2d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */);
    // 00455892  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00455894  7435                   -je 0x4558cb
    if (cpu.flags.zf)
    {
        goto L_0x004558cb;
    }
    // 00455896  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455898  7d05                   -jge 0x45589f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045589f;
    }
    // 0045589a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0045589f:
    // 0045589f  8bbbd4020000           -mov edi, dword ptr [ebx + 0x2d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 004558a5  3bb9d4020000           +cmp edi, dword ptr [ecx + 0x2d4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558ab  7d05                   -jge 0x4558b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004558b2;
    }
    // 004558ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004558b2:
    // 004558b2  8bb3d4020000           -mov esi, dword ptr [ebx + 0x2d4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 004558b8  3bb1d4020000           +cmp esi, dword ptr [ecx + 0x2d4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558be  0f85f1020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 004558c4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004558c6  e9ea020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558cb:
    // 004558cb  83b9d402000000         +cmp dword ptr [ecx + 0x2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558d2  740a                   -je 0x4558de
    if (cpu.flags.zf)
    {
        goto L_0x004558de;
    }
    // 004558d4  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004558d9  e9d7020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558de:
    // 004558de  83bbd402000000         +cmp dword ptr [ebx + 0x2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558e5  740a                   -je 0x4558f1
    if (cpu.flags.zf)
    {
        goto L_0x004558f1;
    }
    // 004558e7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004558ec  e9c4020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558f1:
    // 004558f1  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 004558f7  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558fd  7e05                   -jle 0x455904
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455904;
    }
    // 004558ff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455904:
    // 00455904  8bbbcc020000           -mov edi, dword ptr [ebx + 0x2cc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045590a  3bb9cc020000           +cmp edi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455910  7d05                   -jge 0x455917
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455917;
    }
    // 00455912  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455917:
    // 00455917  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045591d  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455923  0f858c020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455929  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045592b  e985020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455930:
    // 00455930  8bbbc8020000           -mov edi, dword ptr [ebx + 0x2c8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00455936  3bb9c8020000           +cmp edi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045593c  7e05                   -jle 0x455943
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455943;
    }
    // 0045593e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455943:
    // 00455943  8bb3c8020000           -mov esi, dword ptr [ebx + 0x2c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00455949  3bb1c8020000           +cmp esi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045594f  7d05                   -jge 0x455956
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455956;
    }
    // 00455951  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455956:
    // 00455956  8bbbc8020000           -mov edi, dword ptr [ebx + 0x2c8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 0045595c  3bb9c8020000           +cmp edi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455962  0f854d020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455968  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045596a  e946020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x0045596f:
    // 0045596f  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 00455975  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045597b  7e05                   -jle 0x455982
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455982;
    }
    // 0045597d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455982:
    // 00455982  8bbbcc020000           -mov edi, dword ptr [ebx + 0x2cc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 00455988  3bb9cc020000           +cmp edi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045598e  7d05                   -jge 0x455995
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455995;
    }
    // 00455990  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455995:
    // 00455995  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045599b  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004559a1  0f850e020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 004559a7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004559a9  e907020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x004559ae:
    // 004559ae  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004559b4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559b7  8b34454cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd44c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559be  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 004559c4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559c7  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559ce  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004559d1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004559d4  39c6                   +cmp esi, eax
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
    // 004559d6  7d05                   -jge 0x4559dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004559dd;
    }
    // 004559d8  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004559dd:
    // 004559dd  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004559e3  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559e6  8b34454cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd44c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559ed  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 004559f3  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559f6  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559fd  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455a00  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455a03  39c6                   +cmp esi, eax
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
    // 00455a05  7e05                   -jle 0x455a0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455a0c;
    }
    // 00455a07  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455a0c:
    // 00455a0c  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455a12  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a15  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455a1b  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a1e  668b047d4ed46f00       -mov ax, word ptr [edi*2 + 0x6fd44e]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.edi * 2);
    // 00455a26  663b04754ed46f00       +cmp ax, word ptr [esi*2 + 0x6fd44e]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.esi * 2)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455a2e  7504                   -jne 0x455a34
    if (!cpu.flags.zf)
    {
        goto L_0x00455a34;
    }
    // 00455a30  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00455a32  eb08                   -jmp 0x455a3c
    goto L_0x00455a3c;
L_0x00455a34:
    // 00455a34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455a36  0f8579010000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455a3c:
    // 00455a3c  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a43  740e                   -je 0x455a53
    if (cpu.flags.zf)
    {
        goto L_0x00455a53;
    }
    // 00455a45  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a4c  7505                   -jne 0x455a53
    if (!cpu.flags.zf)
    {
        goto L_0x00455a53;
    }
    // 00455a4e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455a53:
    // 00455a53  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a5a  0f8555010000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455a60  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a67  0f8448010000           -je 0x455bb5
    if (cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455a6d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00455a72  e93e010000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455a77:
    // 00455a77  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455a7d  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a80  8b34452cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455a87  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455a8d  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a90  8b04452cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455a97  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455a9a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455a9d  39c6                   +cmp esi, eax
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
    // 00455a9f  7d05                   -jge 0x455aa6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455aa6;
    }
    // 00455aa1  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455aa6:
    // 00455aa6  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455aac  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455aaf  8b34452cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455ab6  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455abc  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455abf  8b04452cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455ac6  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455ac9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455acc  39c6                   +cmp esi, eax
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
    // 00455ace  7e05                   -jle 0x455ad5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455ad5;
    }
    // 00455ad0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455ad5:
    // 00455ad5  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455adb  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455ade  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455ae4  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455ae7  668b047d2ed46f00       -mov ax, word ptr [edi*2 + 0x6fd42e]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.edi * 2);
    // 00455aef  663b04752ed46f00       +cmp ax, word ptr [esi*2 + 0x6fd42e]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.esi * 2)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455af7  7504                   -jne 0x455afd
    if (!cpu.flags.zf)
    {
        goto L_0x00455afd;
    }
    // 00455af9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00455afb  eb08                   -jmp 0x455b05
    goto L_0x00455b05;
L_0x00455afd:
    // 00455afd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455aff  0f85b0000000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455b05:
    // 00455b05  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b0c  740e                   -je 0x455b1c
    if (cpu.flags.zf)
    {
        goto L_0x00455b1c;
    }
    // 00455b0e  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b15  7505                   -jne 0x455b1c
    if (!cpu.flags.zf)
    {
        goto L_0x00455b1c;
    }
    // 00455b17  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455b1c:
    // 00455b1c  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b23  0f858c000000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b29  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b30  0f847f000000           -je 0x455bb5
    if (cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b36  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00455b3b  e975000000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455b40:
    // 00455b40  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b46  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b4c  7e05                   -jle 0x455b53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455b53;
    }
    // 00455b4e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455b53:
    // 00455b53  8bb338020000           -mov esi, dword ptr [ebx + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b59  3bb138020000           +cmp esi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b5f  7d05                   -jge 0x455b66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455b66;
    }
    // 00455b61  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455b66:
    // 00455b66  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b6c  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b72  7541                   -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b74  eb3d                   -jmp 0x455bb3
    goto L_0x00455bb3;
  case 0x00455b76:
    // 00455b76  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455b7c  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455b82  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455b84  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455b85  7305                   -jae 0x455b8c
    if (!cpu.flags.cf)
    {
        goto L_0x00455b8c;
    }
    // 00455b87  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455b8c:
    // 00455b8c  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455b92  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455b98  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455b9a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455b9b  7605                   -jbe 0x455ba2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00455ba2;
    }
    // 00455b9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455ba2:
    // 00455ba2  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455ba8  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455bae  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455bb0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455bb1  7502                   -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455bb3:
    // 00455bb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
  [[fallthrough]];
  case 0x00455bb5:
L_0x00455bb5:
    // 00455bb5  833d1c96550001         +cmp dword ptr [0x55961c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608988) /* 0x55961c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bbc  7502                   -jne 0x455bc0
    if (!cpu.flags.zf)
    {
        goto L_0x00455bc0;
    }
    // 00455bbe  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00455bc0:
    // 00455bc0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455bc2  7536                   -jne 0x455bfa
    if (!cpu.flags.zf)
    {
        goto L_0x00455bfa;
    }
    // 00455bc4  8bb338020000           -mov esi, dword ptr [ebx + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455bca  3bb138020000           +cmp esi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bd0  7e05                   -jle 0x455bd7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455bd7;
    }
    // 00455bd2  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455bd7:
    // 00455bd7  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455bdd  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455be3  7d05                   -jge 0x455bea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455bea;
    }
    // 00455be5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455bea:
    // 00455bea  8b8138020000           -mov eax, dword ptr [ecx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */);
    // 00455bf0  3b8338020000           +cmp eax, dword ptr [ebx + 0x238]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bf6  7502                   -jne 0x455bfa
    if (!cpu.flags.zf)
    {
        goto L_0x00455bfa;
    }
    // 00455bf8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00455bfa:
    // 00455bfa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00455bfc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455c00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455c01  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_455c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455c11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455c12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455c13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455c14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455c16  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00455c19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455c1b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00455c1d  eb05                   -jmp 0x455c24
    goto L_0x00455c24;
L_0x00455c1f:
    // 00455c1f  83f810                 +cmp eax, 0x10
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
    // 00455c22  7d36                   -jge 0x455c5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455c5a;
    }
L_0x00455c24:
    // 00455c24  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00455c26  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00455c29  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00455c2c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00455c2e  66c781d8955500ffff     -mov word ptr [ecx + 0x5595d8], 0xffff
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5608920) /* 0x5595d8 */) = 65535 /*0xffff*/;
    // 00455c37  69cec09a0000           -imul ecx, esi, 0x9ac0
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455c3d  bfb0476600             -mov edi, 0x6647b0
    cpu.edi = 6703024 /*0x6647b0*/;
    // 00455c42  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00455c44  69c8ac090000           -imul ecx, eax, 0x9ac
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455c4a  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00455c4c  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 00455c53  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455c54  894c2fc0               -mov dword ptr [edi + ebp - 0x40], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.ecx;
    // 00455c58  ebc5                   -jmp 0x455c1f
    goto L_0x00455c1f;
L_0x00455c5a:
    // 00455c5a  b940584500             -mov ecx, 0x455840
    cpu.ecx = 4544576 /*0x455840*/;
    // 00455c5f  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00455c62  891518965500           -mov dword ptr [0x559618], edx
    app->getMemory<x86::reg32>(x86::reg32(5608984) /* 0x559618 */) = cpu.edx;
    // 00455c68  891d1c965500           -mov dword ptr [0x55961c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608988) /* 0x55961c */) = cpu.ebx;
    // 00455c6e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00455c73  8b14b5307d6700         -mov edx, dword ptr [esi*4 + 0x677d30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4);
    // 00455c7a  e879880900             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 00455c7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00455c81:
    // 00455c81  3b14b5307d6700         +cmp edx, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455c88  7d38                   -jge 0x455cc2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455cc2;
    }
    // 00455c8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455c8c:
    // 00455c8c  3b04b5307d6700         +cmp eax, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455c93  7d2a                   -jge 0x455cbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455cbf;
    }
    // 00455c95  69dec09a0000           -imul ebx, esi, 0x9ac0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455c9b  69c8ac090000           -imul ecx, eax, 0x9ac
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455ca1  81c3b0476600           -add ebx, 0x6647b0
    (cpu.ebx) += x86::reg32(x86::sreg32(6703024 /*0x6647b0*/));
    // 00455ca7  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00455ca9  3b4c95c0               +cmp ecx, dword ptr [ebp + edx*4 - 0x40]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */ + cpu.edx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455cad  750d                   -jne 0x455cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00455cbc;
    }
    // 00455caf  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00455cb1  c1e105                 +shl ecx, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00455cb4  66898451d8955500       -mov word ptr [ecx + edx*2 + 0x5595d8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5608920) /* 0x5595d8 */ + cpu.edx * 2) = cpu.ax;
L_0x00455cbc:
    // 00455cbc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455cbd  ebcd                   -jmp 0x455c8c
    goto L_0x00455c8c;
L_0x00455cbf:
    // 00455cbf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455cc0  ebbf                   -jmp 0x455c81
    goto L_0x00455c81;
L_0x00455cc2:
    // 00455cc2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455cc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455cd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455cd5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00455cd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455cda  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00455cdd  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00455cdf  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00455ce2  83fa10                 +cmp edx, 0x10
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
    // 00455ce5  0f8fd4000000           -jg 0x455dbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455dbf;
    }
    // 00455ceb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455ced  7545                   -jne 0x455d34
    if (!cpu.flags.zf)
    {
        goto L_0x00455d34;
    }
    // 00455cef  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00455cf2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455cf4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455cf6  6683b8d895550000       +cmp word ptr [eax + 0x5595d8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5608920) /* 0x5595d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455cfe  0f8cbb000000           -jl 0x455dbf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00455dbf;
    }
    // 00455d04  8b80d6955500           -mov eax, dword ptr [eax + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455d0a  8b0cb5307d6700         -mov ecx, dword ptr [esi*4 + 0x677d30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4);
    // 00455d11  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455d14  39c8                   +cmp eax, ecx
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
    // 00455d16  0f8fa3000000           -jg 0x455dbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455dbf;
    }
    // 00455d1c  69d0ac090000           -imul edx, eax, 0x9ac
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d22  69c6c09a0000           -imul eax, esi, 0x9ac0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455d28  05b0476600             -add eax, 0x6647b0
    (cpu.eax) += x86::reg32(x86::sreg32(6703024 /*0x6647b0*/));
    // 00455d2d  01d0                   +add eax, edx
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
    // 00455d2f  e98d000000             -jmp 0x455dc1
    goto L_0x00455dc1;
L_0x00455d34:
    // 00455d34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455d36  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00455d38  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00455d3b  eb55                   -jmp 0x455d92
    goto L_0x00455d92;
L_0x00455d3d:
    // 00455d3d  69c0ac090000           -imul eax, eax, 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d43  69d6c09a0000           -imul edx, esi, 0x9ac0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455d49  bbb0476600             -mov ebx, 0x6647b0
    cpu.ebx = 6703024 /*0x6647b0*/;
    // 00455d4e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455d50  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00455d53  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455d55  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00455d57  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455d5a  e851faffff             -call 0x4557b0
    cpu.esp -= 4;
    sub_4557b0(app, cpu);
    if (cpu.terminate) return;
    // 00455d5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455d61  7429                   -je 0x455d8c
    if (cpu.flags.zf)
    {
        goto L_0x00455d8c;
    }
    // 00455d63  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455d66  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455d69  751b                   -jne 0x455d86
    if (!cpu.flags.zf)
    {
        goto L_0x00455d86;
    }
    // 00455d6b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00455d6e  8b80d6955500           -mov eax, dword ptr [eax + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455d74  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455d77  69c0ac090000           -imul eax, eax, 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d7d  0345f0                 -add eax, dword ptr [ebp - 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00455d80  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455d82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00455d86:
    // 00455d86  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455d89  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x00455d8c:
    // 00455d8c  41                     -inc ecx
    (cpu.ecx)++;
    // 00455d8d  83f910                 +cmp ecx, 0x10
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
    // 00455d90  7d2d                   -jge 0x455dbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455dbf;
    }
L_0x00455d92:
    // 00455d92  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00455d94  8d0409                 -lea eax, [ecx + ecx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00455d97  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00455d9a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455d9c  668b9ad8955500         -mov bx, word ptr [edx + 0x5595d8]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5608920) /* 0x5595d8 */);
    // 00455da3  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00455da6  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00455da9  7ce1                   -jl 0x455d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00455d8c;
    }
    // 00455dab  8b82d6955500           -mov eax, dword ptr [edx + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455db1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455db4  3b04b5307d6700         +cmp eax, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455dbb  7e80                   -jle 0x455d3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455d3d;
    }
    // 00455dbd  ebcd                   -jmp 0x455d8c
    goto L_0x00455d8c;
L_0x00455dbf:
    // 00455dbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455dc1:
    // 00455dc1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455dc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_455dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455dd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455dd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455dd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455dd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455dd5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00455dd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455dda  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00455ddd  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00455de0  bfd8955500             -mov edi, 0x5595d8
    cpu.edi = 5608920 /*0x5595d8*/;
    // 00455de5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00455de8  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455ded  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455def  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00455df2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00455df4  e8f7460900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00455df9  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00455dfc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00455dfe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00455e00  e80bfeffff             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455e05  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00455e08  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00455e0b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455e0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00455e10  e8bbfeffff             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455e15  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455e1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00455e1c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455e1e  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00455e21  e8ca460900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00455e26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00455e28  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455e2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_455e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455e32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455e33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455e34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455e35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455e37  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00455e3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00455e3c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00455e3e  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00455e43  e81848ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00455e48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455e4a  0f84bb010000           -je 0x45600b
    if (cpu.flags.zf)
    {
        goto L_0x0045600b;
    }
    // 00455e50  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
    // 00455e55  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00455e58  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00455e5a  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00455e5d  7407                   -je 0x455e66
    if (cpu.flags.zf)
    {
        goto L_0x00455e66;
    }
    // 00455e5f  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 00455e64  eb1a                   -jmp 0x455e80
    goto L_0x00455e80;
L_0x00455e66:
    // 00455e66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455e68  7405                   -je 0x455e6f
    if (cpu.flags.zf)
    {
        goto L_0x00455e6f;
    }
    // 00455e6a  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
L_0x00455e6f:
    // 00455e6f  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455e75  7509                   -jne 0x455e80
    if (!cpu.flags.zf)
    {
        goto L_0x00455e80;
    }
    // 00455e77  668b1d427d6700         -mov bx, word ptr [0x677d42]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 00455e7e  eb07                   -jmp 0x455e87
    goto L_0x00455e87;
L_0x00455e80:
    // 00455e80  668b1d467d6700         -mov bx, word ptr [0x677d46]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(6782278) /* 0x677d46 */);
L_0x00455e87:
    // 00455e87  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455e8a  66895df4               -mov word ptr [ebp - 0xc], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.bx;
    // 00455e8e  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00455e91  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00455e94  b9400000a0             -mov ecx, 0xa0000040
    cpu.ecx = 2684354624 /*0xa0000040*/;
    // 00455e99  e852080800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 00455e9e  ba400000ff             -mov edx, 0xff000040
    cpu.edx = 4278190144 /*0xff000040*/;
    // 00455ea3  bb222222d0             -mov ebx, 0xd0222222
    cpu.ebx = 3491897890 /*0xd0222222*/;
    // 00455ea8  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00455eab  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455eb1  7507                   -jne 0x455eba
    if (!cpu.flags.zf)
    {
        goto L_0x00455eba;
    }
    // 00455eb3  c745f040e4ffff         -mov dword ptr [ebp - 0x10], 0xffffe440
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 4294960192 /*0xffffe440*/;
L_0x00455eba:
    // 00455eba  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00455ec1  740f                   -je 0x455ed2
    if (cpu.flags.zf)
    {
        goto L_0x00455ed2;
    }
    // 00455ec3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00455ec8  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00455ecd  e82ebafdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00455ed2:
    // 00455ed2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455ed3  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00455ed6  8b5642                 -mov edx, dword ptr [esi + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455ed9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455eda  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455edd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ee0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455ee1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455ee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455ee4  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455ee7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455eea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455eed  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455ef0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455ef3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00455ef6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ef9  e862290800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00455efe  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00455f01  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00455f04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455f05  8b5642                 -mov edx, dword ptr [esi + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455f08  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f0b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455f0e  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455f11  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455f13  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00455f16  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455f19  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455f1c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455f1f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455f22  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f25  e8062a0800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 00455f2a  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00455f31  740c                   -je 0x455f3f
    if (cpu.flags.zf)
    {
        goto L_0x00455f3f;
    }
    // 00455f33  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00455f38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455f3a  e8c1b9fdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00455f3f:
    // 00455f3f  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00455f44  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 00455f49  e8b2c1ffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00455f4e  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00455f51  890d50945500           -mov dword ptr [0x559450], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = cpu.ecx;
    // 00455f57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455f59  7448                   -je 0x455fa3
    if (cpu.flags.zf)
    {
        goto L_0x00455fa3;
    }
    // 00455f5b  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00455f5e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f62  8b4646                 -mov eax, dword ptr [esi + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(70) /* 0x46 */);
    // 00455f65  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f69  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00455f6b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455f6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f6f  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00455f72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f73  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00455f76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f77  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455f7a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f7d  48                     -dec eax
    (cpu.eax)--;
    // 00455f7e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00455f83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f84  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455f87  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455f8a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f8d  c1f910                 +sar ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00455f90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f91  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00455f93  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00455f95  e836bdffff             -call 0x451cd0
    cpu.esp -= 4;
    sub_451cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455f9a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455f9d  66894642               -mov word ptr [esi + 0x42], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00455fa1  eb06                   -jmp 0x455fa9
    goto L_0x00455fa9;
L_0x00455fa3:
    // 00455fa3  66c746420100           -mov word ptr [esi + 0x42], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = 1 /*0x1*/;
L_0x00455fa9:
    // 00455fa9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455fac  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455faf  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455fb2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fb5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455fb8  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00455fbb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455fbd  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455fc3  7508                   -jne 0x455fcd
    if (!cpu.flags.zf)
    {
        goto L_0x00455fcd;
    }
    // 00455fc5  66a1447d6700           -mov ax, word ptr [0x677d44]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782276) /* 0x677d44 */);
    // 00455fcb  eb06                   -jmp 0x455fd3
    goto L_0x00455fd3;
L_0x00455fcd:
    // 00455fcd  66a1407d6700           -mov ax, word ptr [0x677d40]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782272) /* 0x677d40 */);
L_0x00455fd3:
    // 00455fd3  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00455fd4  e8b7190800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00455fd9  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455fdc  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455fdf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fe2  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00455fe5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455fe7  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00455fea  4b                     -dec ebx
    (cpu.ebx)--;
    // 00455feb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fee  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455ff1  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00455ff3  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455ff6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ff9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455ffc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455ffe  8b45f2                 -mov eax, dword ptr [ebp - 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00456001  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456004  e887190800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456009  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045600b:
    // 0045600b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045600d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045600e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045600f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456022  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456026  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00456029  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045602b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045602d  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456032  e82946ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456037  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045603b  0f84c4000000           -je 0x456105
    if (cpu.flags.zf)
    {
        goto L_0x00456105;
    }
    // 00456041  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456044  66a1427d6700           -mov ax, word ptr [0x677d42]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 0045604a  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045604d  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045604e  e89d060800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 00456053  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00456057  668945e8               -mov word ptr [ebp - 0x18], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ax;
    // 0045605b  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045605f  668b5144               -mov dx, word ptr [ecx + 0x44]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456063  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456065  668945ea               -mov word ptr [ebp - 0x16], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = cpu.ax;
    // 00456069  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045606c  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00456070  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456073  668945ee               -mov word ptr [ebp - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 00456077  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0045607b  668b5946               -mov bx, word ptr [ecx + 0x46]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 0045607f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456082  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00456084  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00456086  668945f0               -mov word ptr [ebp - 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ax;
    // 0045608a  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045608e  668b5944               -mov bx, word ptr [ecx + 0x44]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456092  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00456094  668945f2               -mov word ptr [ebp - 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.ax;
    // 00456098  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045609b  668955f6               -mov word ptr [ebp - 0xa], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.dx;
    // 0045609f  668945f4               -mov word ptr [ebp - 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ax;
    // 004560a3  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004560a7  755a                   -jne 0x456103
    if (!cpu.flags.zf)
    {
        goto L_0x00456103;
    }
    // 004560a9  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004560ac  e83f610400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004560b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004560b3  741b                   -je 0x4560d0
    if (cpu.flags.zf)
    {
        goto L_0x004560d0;
    }
    // 004560b5  668b714a               -mov si, word ptr [ecx + 0x4a]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */);
    // 004560b9  4e                     -dec esi
    (cpu.esi)--;
    // 004560ba  6689714a               -mov word ptr [ecx + 0x4a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */) = cpu.si;
    // 004560be  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004560c1  7d06                   -jge 0x4560c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004560c9;
    }
    // 004560c3  66c7414a0000           -mov word ptr [ecx + 0x4a], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */) = 0 /*0x0*/;
L_0x004560c9:
    // 004560c9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004560ce  eb35                   -jmp 0x456105
    goto L_0x00456105;
L_0x004560d0:
    // 004560d0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004560d3  e818610400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004560d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004560da  7427                   -je 0x456103
    if (cpu.flags.zf)
    {
        goto L_0x00456103;
    }
    // 004560dc  66ff414a               -inc word ptr [ecx + 0x4a]
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */))++;
    // 004560e0  8b5146                 -mov edx, dword ptr [ecx + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 004560e3  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004560e6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004560e9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004560ec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004560ee  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004560f1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004560f4  39c2                   +cmp edx, eax
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
    // 004560f6  7e04                   -jle 0x4560fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004560fc;
    }
    // 004560f8  66ff494a               +dec word ptr [ecx + 0x4a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */);
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
L_0x004560fc:
    // 004560fc  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00456101  eb02                   -jmp 0x456105
    goto L_0x00456105;
L_0x00456103:
    // 00456103  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00456105:
    // 00456105  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456107  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456108  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456109  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045610a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045610b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456113  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456114  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456116  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456119  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045611b  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456120  e83b45ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456125  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456127  7439                   -je 0x456162
    if (cpu.flags.zf)
    {
        goto L_0x00456162;
    }
    // 00456129  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045612d  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00456131  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00456135  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00456139  668b4146               -mov ax, word ptr [ecx + 0x46]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 0045613d  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00456141  668b4144               -mov ax, word ptr [ecx + 0x44]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456145  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456148  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
    // 0045614c  66a1427d6700           -mov ax, word ptr [0x677d42]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 00456152  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456155  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456156  e895050800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 0045615b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045615e  6601411e               -add word ptr [ecx + 0x1e], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x00456162:
    // 00456162  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456164  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456165  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456166  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456167  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456170  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456172  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456174  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456179  e8e244ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0045617e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456180  7440                   -je 0x4561c2
    if (cpu.flags.zf)
    {
        goto L_0x004561c2;
    }
    // 00456182  b818995300             -mov eax, 0x539918
    cpu.eax = 5478680 /*0x539918*/;
    // 00456187  e824fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045618c  66a3407d6700           -mov word ptr [0x677d40], ax
    app->getMemory<x86::reg16>(x86::reg32(6782272) /* 0x677d40 */) = cpu.ax;
    // 00456192  b820995300             -mov eax, 0x539920
    cpu.eax = 5478688 /*0x539920*/;
    // 00456197  e814fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045619c  66a3467d6700           -mov word ptr [0x677d46], ax
    app->getMemory<x86::reg16>(x86::reg32(6782278) /* 0x677d46 */) = cpu.ax;
    // 004561a2  b828995300             -mov eax, 0x539928
    cpu.eax = 5478696 /*0x539928*/;
    // 004561a7  e804fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004561ac  66a3447d6700           -mov word ptr [0x677d44], ax
    app->getMemory<x86::reg16>(x86::reg32(6782276) /* 0x677d44 */) = cpu.ax;
    // 004561b2  b830995300             -mov eax, 0x539930
    cpu.eax = 5478704 /*0x539930*/;
    // 004561b7  e8f4fb0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004561bc  66a3427d6700           -mov word ptr [0x677d42], ax
    app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */) = cpu.ax;
L_0x004561c2:
    // 004561c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4561d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004561d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004561d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004561d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004561d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004561d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004561d7  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 004561dc  e87f44ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004561e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004561e3  7415                   -je 0x4561fa
    if (cpu.flags.zf)
    {
        goto L_0x004561fa;
    }
    // 004561e5  6683794000             +cmp word ptr [ecx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004561ea  740e                   -je 0x4561fa
    if (cpu.flags.zf)
    {
        goto L_0x004561fa;
    }
    // 004561ec  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004561ef  e89cb60800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004561f4  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x004561fa:
    // 004561fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_456200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456203  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456205  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456206  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456208  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0045620b  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456211  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456214  7d0d                   -jge 0x456223
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456223;
    }
    // 00456216  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045621d  7427                   -je 0x456246
    if (cpu.flags.zf)
    {
        goto L_0x00456246;
    }
    // 0045621f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456221  7523                   -jne 0x456246
    if (!cpu.flags.zf)
    {
        goto L_0x00456246;
    }
L_0x00456223:
    // 00456223  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00456225  668915747d6700         -mov word ptr [0x677d74], dx
    app->getMemory<x86::reg16>(x86::reg32(6782324) /* 0x677d74 */) = cpu.dx;
    // 0045622c  668915727d6700         -mov word ptr [0x677d72], dx
    app->getMemory<x86::reg16>(x86::reg32(6782322) /* 0x677d72 */) = cpu.dx;
    // 00456233  668915707d6700         -mov word ptr [0x677d70], dx
    app->getMemory<x86::reg16>(x86::reg32(6782320) /* 0x677d70 */) = cpu.dx;
    // 0045623a  668915767d6700         -mov word ptr [0x677d76], dx
    app->getMemory<x86::reg16>(x86::reg32(6782326) /* 0x677d76 */) = cpu.dx;
    // 00456241  e9c9000000             -jmp 0x45630f
    goto L_0x0045630f;
L_0x00456246:
    // 00456246  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00456248:
    // 00456248  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045624d  3b0c85f4975500         +cmp ecx, dword ptr [eax*4 + 0x5597f4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456254  0f8db5000000           -jge 0x45630f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045630f;
    }
    // 0045625a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045625d  8bbc88d4965500         -mov edi, dword ptr [eax + ecx*4 + 0x5596d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5609172) /* 0x5596d4 */ + cpu.ecx * 4);
    // 00456264  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456265  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00456268  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456269  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045626c  e81f940800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456271  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456274  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456279  8d3409                 -lea esi, [ecx + ecx]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0045627c  e8ef8f0900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00456281  8a15583a7a00           -mov dl, byte ptr [0x7a3a58]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00456287  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00456289  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0045628c  7407                   -je 0x456295
    if (cpu.flags.zf)
    {
        goto L_0x00456295;
    }
    // 0045628e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00456293  eb02                   -jmp 0x456297
    goto L_0x00456297;
L_0x00456295:
    // 00456295  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00456297:
    // 00456297  e8f4000800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045629c  668986707d6700         -mov word ptr [esi + 0x677d70], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6782320) /* 0x677d70 */) = cpu.ax;
    // 004562a3  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562a6  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 004562a9  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004562ac  6689044d507d6700       -mov word ptr [ecx*2 + 0x677d50], ax
    app->getMemory<x86::reg16>(x86::reg32(6782288) /* 0x677d50 */ + cpu.ecx * 2) = cpu.ax;
    // 004562b4  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562b7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004562ba  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004562bd  6689044d587d6700       -mov word ptr [ecx*2 + 0x677d58], ax
    app->getMemory<x86::reg16>(x86::reg32(6782296) /* 0x677d58 */ + cpu.ecx * 2) = cpu.ax;
    // 004562c5  8b5302                 -mov edx, dword ptr [ebx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004562c8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004562cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004562cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004562d0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004562d2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004562d4  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562d7  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004562da  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004562dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004562df  6689044d687d6700       -mov word ptr [ecx*2 + 0x677d68], ax
    app->getMemory<x86::reg16>(x86::reg32(6782312) /* 0x677d68 */ + cpu.ecx * 2) = cpu.ax;
    // 004562e7  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004562ea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004562ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004562ef  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004562f2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004562f4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004562f6  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562f9  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004562fc  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004562ff  41                     -inc ecx
    (cpu.ecx)++;
    // 00456300  01d0                   +add eax, edx
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
    // 00456302  6689044d5e7d6700       -mov word ptr [ecx*2 + 0x677d5e], ax
    app->getMemory<x86::reg16>(x86::reg32(6782302) /* 0x677d5e */ + cpu.ecx * 2) = cpu.ax;
    // 0045630a  e939ffffff             -jmp 0x456248
    goto L_0x00456248;
L_0x0045630f:
    // 0045630f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456311  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456312  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456313  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456314  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456315  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456316  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456317  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456326  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456328  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0045632b  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0045632e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00456333  a17c7d6700             -mov eax, dword ptr [0x677d7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
    // 00456338  39f8                   +cmp eax, edi
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
    // 0045633a  720c                   -jb 0x456348
    if (cpu.flags.cf)
    {
        goto L_0x00456348;
    }
    // 0045633c  7628                   -jbe 0x456366
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00456366;
    }
    // 0045633e  83f802                 +cmp eax, 2
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
    // 00456341  7462                   -je 0x4563a5
    if (cpu.flags.zf)
    {
        goto L_0x004563a5;
    }
    // 00456343  e999000000             -jmp 0x4563e1
    goto L_0x004563e1;
L_0x00456348:
    // 00456348  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045634a  0f8591000000           -jne 0x4563e1
    if (!cpu.flags.zf)
    {
        goto L_0x004563e1;
    }
    // 00456350  8b0d787d6700           -mov ecx, dword ptr [0x677d78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 00456356  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00456358  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0045635b  890d787d6700           -mov dword ptr [0x677d78], ecx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ecx;
    // 00456361  e97b000000             -jmp 0x4563e1
    goto L_0x004563e1;
L_0x00456366:
    // 00456366  8b1d787d6700           -mov ebx, dword ptr [0x677d78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 0045636c  81fb00010000           +cmp ebx, 0x100
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
    // 00456372  7d1b                   -jge 0x45638f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045638f;
    }
    // 00456374  8d730c                 -lea esi, [ebx + 0xc]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00456377  8935787d6700           -mov dword ptr [0x677d78], esi
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.esi;
    // 0045637d  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456383  7e0a                   -jle 0x45638f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045638f;
    }
    // 00456385  c705787d670000010000   -mov dword ptr [0x677d78], 0x100
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = 256 /*0x100*/;
L_0x0045638f:
    // 0045638f  db05787d6700           -fild dword ptr [0x677d78]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */))));
    // 00456395  d80d489a5300           -fmul dword ptr [0x539a48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478984) /* 0x539a48 */));
    // 0045639b  dc05509a5300           -fadd qword ptr [0x539a50]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5478992) /* 0x539a50 */));
    // 004563a1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004563a3  eb39                   -jmp 0x4563de
    goto L_0x004563de;
L_0x004563a5:
    // 004563a5  8b15787d6700           -mov edx, dword ptr [0x677d78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 004563ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004563ad  7419                   -je 0x4563c8
    if (cpu.flags.zf)
    {
        goto L_0x004563c8;
    }
    // 004563af  8d4aec                 -lea ecx, [edx - 0x14]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-20) /* -0x14 */);
    // 004563b2  890d787d6700           -mov dword ptr [0x677d78], ecx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ecx;
    // 004563b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004563ba  7e04                   -jle 0x4563c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004563c0;
    }
    // 004563bc  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004563be  eb08                   -jmp 0x4563c8
    goto L_0x004563c8;
L_0x004563c0:
    // 004563c0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004563c2  8935787d6700           -mov dword ptr [0x677d78], esi
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.esi;
L_0x004563c8:
    // 004563c8  db05787d6700           -fild dword ptr [0x677d78]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */))));
    // 004563ce  d80d489a5300           -fmul dword ptr [0x539a48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478984) /* 0x539a48 */));
    // 004563d4  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004563d6  dc05589a5300           -fadd qword ptr [0x539a58]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479000) /* 0x539a58 */));
    // 004563dc  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004563de:
    // 004563de  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004563e1:
    // 004563e1  a118985500             -mov eax, dword ptr [0x559818]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 004563e6  66813c45667d67004001   +cmp word ptr [eax*2 + 0x677d66], 0x140
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6782310) /* 0x677d66 */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(320 /*0x140*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004563f0  7e12                   -jle 0x456404
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00456404;
    }
    // 004563f2  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 004563f7  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 004563fc  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004563ff  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00456402  eb10                   -jmp 0x456414
    goto L_0x00456414;
L_0x00456404:
    // 00456404  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 00456409  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 0045640e  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00456411  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
L_0x00456414:
    // 00456414  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00456416  e93c010000             -jmp 0x456557
    goto L_0x00456557;
L_0x0045641b:
    // 0045641b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045641d  7564                   -jne 0x456483
    if (!cpu.flags.zf)
    {
        goto L_0x00456483;
    }
    // 0045641f  833d787d67003c         +cmp dword ptr [0x677d78], 0x3c
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456426  750b                   -jne 0x456433
    if (!cpu.flags.zf)
    {
        goto L_0x00456433;
    }
    // 00456428  a3787d6700             -mov dword ptr [0x677d78], eax
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.eax;
    // 0045642d  40                     -inc eax
    (cpu.eax)++;
    // 0045642e  a37c7d6700             -mov dword ptr [0x677d7c], eax
    app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */) = cpu.eax;
L_0x00456433:
    // 00456433  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00456435  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
    // 0045643a  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0045643d  eb44                   -jmp 0x456483
    goto L_0x00456483;
L_0x0045643f:
    // 0045643f  813d787d670000010000   +cmp dword ptr [0x677d78], 0x100
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456449  750e                   -jne 0x456459
    if (!cpu.flags.zf)
    {
        goto L_0x00456459;
    }
    // 0045644b  c745f80000803f         -mov dword ptr [ebp - 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1065353216 /*0x3f800000*/;
    // 00456452  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
    // 00456457  eb10                   -jmp 0x456469
    goto L_0x00456469;
L_0x00456459:
    // 00456459  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0045645c  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0045645e  dc05609a5300           -fadd qword ptr [0x539a60]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479008) /* 0x539a60 */));
    // 00456464  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00456466  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00456469:
    // 00456469  837de000               +cmp dword ptr [ebp - 0x20], 0
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
    // 0045646d  7414                   -je 0x456483
    if (cpu.flags.zf)
    {
        goto L_0x00456483;
    }
    // 0045646f  ff057c7d6700           +inc dword ptr [0x677d7c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456475  eb0c                   -jmp 0x456483
    goto L_0x00456483;
L_0x00456477:
    // 00456477  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0045647a  dc05689a5300           +fadd qword ptr [0x539a68]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479016) /* 0x539a68 */));
    // 00456480  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00456483:
    // 00456483  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00456486  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00456488  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0045648a  dd5dd4                 +fstp qword ptr [ebp - 0x2c]
    app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0045648d  dc5dd4                 +fcomp qword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 00456490  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00456492  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00456493  0f87b8000000           -ja 0x456551
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00456551;
    }
    // 00456499  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0045649b  dc5dd4                 +fcomp qword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 0045649e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004564a0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004564a1  0f82aa000000           -jb 0x456551
    if (cpu.flags.cf)
    {
        goto L_0x00456551;
    }
    // 004564a7  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004564aa  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004564ac  d80d709a5300           -fmul dword ptr [0x539a70]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5479024) /* 0x539a70 */));
    // 004564b2  a118985500             -mov eax, dword ptr [0x559818]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 004564b7  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004564b9  df0445667d6700         -fild word ptr [eax*2 + 0x677d66]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(6782310) /* 0x677d66 */ + cpu.eax * 2))));
    // 004564c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004564c2  dc65d4                 -fsub qword ptr [ebp - 0x2c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 004564c5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004564c7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004564c9  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004564cc  df04455e7d6700         -fild word ptr [eax*2 + 0x677d5e]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(6782302) /* 0x677d5e */ + cpu.eax * 2))));
    // 004564d3  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564d5  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004564d8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004564db  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004564de  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004564e0  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004564e3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004564e5  d805749a5300           -fadd dword ptr [0x539a74]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5479028) /* 0x539a74 */));
    // 004564eb  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004564ee  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564f0  e861980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004564f5  db5de4                 -fistp dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004564f8  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564fa  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564fc  e855980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00456501  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00456503  e84e980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00456508  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0045650a  db5df0                 -fistp dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0045650d  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00456510  83fe0e                 +cmp esi, 0xe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456513  7507                   -jne 0x45651c
    if (!cpu.flags.zf)
    {
        goto L_0x0045651c;
    }
    // 00456515  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0045651a  eb05                   -jmp 0x456521
    goto L_0x00456521;
L_0x0045651c:
    // 0045651c  b8ffffff40             -mov eax, 0x40ffffff
    cpu.eax = 1090519039 /*0x40ffffff*/;
L_0x00456521:
    // 00456521  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456522  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456523  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456526  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456528  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045652b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045652d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045652f  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456532  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456535  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456538  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045653a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045653c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045653d  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456540  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00456542  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00456544  a18e7d6700             -mov eax, dword ptr [0x677d8e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782350) /* 0x677d8e */);
    // 00456549  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045654c  e82f260800             -call 0x4d8b80
    cpu.esp -= 4;
    sub_4d8b80(app, cpu);
    if (cpu.terminate) return;
L_0x00456551:
    // 00456551  46                     -inc esi
    (cpu.esi)++;
    // 00456552  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456555  7d22                   -jge 0x456579
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456579;
    }
L_0x00456557:
    // 00456557  a17c7d6700             -mov eax, dword ptr [0x677d7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
    // 0045655c  83f801                 +cmp eax, 1
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
    // 0045655f  0f82b6feffff           -jb 0x45641b
    if (cpu.flags.cf)
    {
        goto L_0x0045641b;
    }
    // 00456565  0f86d4feffff           -jbe 0x45643f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045643f;
    }
    // 0045656b  83f802                 +cmp eax, 2
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
    // 0045656e  0f8403ffffff           -je 0x456477
    if (cpu.flags.zf)
    {
        goto L_0x00456477;
    }
    // 00456574  e90affffff             -jmp 0x456483
    goto L_0x00456483;
L_0x00456579:
    // 00456579  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045657b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045657d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045657e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045657f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456580  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456581  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456582  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_456590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456594  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456595  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456596  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456598  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0045659b  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004565a1  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004565a4  750c                   -jne 0x4565b2
    if (!cpu.flags.zf)
    {
        goto L_0x004565b2;
    }
    // 004565a6  bbae010000             -mov ebx, 0x1ae
    cpu.ebx = 430 /*0x1ae*/;
    // 004565ab  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004565b0  eb24                   -jmp 0x4565d6
    goto L_0x004565d6;
L_0x004565b2:
    // 004565b2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004565b4  740a                   -je 0x4565c0
    if (cpu.flags.zf)
    {
        goto L_0x004565c0;
    }
    // 004565b6  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004565b9  7405                   -je 0x4565c0
    if (cpu.flags.zf)
    {
        goto L_0x004565c0;
    }
    // 004565bb  83fa08                 +cmp edx, 8
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
    // 004565be  750c                   -jne 0x4565cc
    if (!cpu.flags.zf)
    {
        goto L_0x004565cc;
    }
L_0x004565c0:
    // 004565c0  bb9a010000             -mov ebx, 0x19a
    cpu.ebx = 410 /*0x19a*/;
    // 004565c5  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 004565ca  eb0a                   -jmp 0x4565d6
    goto L_0x004565d6;
L_0x004565cc:
    // 004565cc  bb86010000             -mov ebx, 0x186
    cpu.ebx = 390 /*0x186*/;
    // 004565d1  bad1010000             -mov edx, 0x1d1
    cpu.edx = 465 /*0x1d1*/;
L_0x004565d6:
    // 004565d6  8b3d4cbb6f00           -mov edi, dword ptr [0x6fbb4c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004565dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004565de  752b                   -jne 0x45660b
    if (!cpu.flags.zf)
    {
        goto L_0x0045660b;
    }
    // 004565e0  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004565e5  e866b20700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004565ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004565eb  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004565f0  8b0c8544965500         -mov ecx, dword ptr [eax*4 + 0x559644]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5609028) /* 0x559644 */ + cpu.eax * 4);
    // 004565f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004565f8  68789a5300             -push 0x539a78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479032 /*0x539a78*/;
    cpu.esp -= 4;
    // 004565fd  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00456600  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456601  e88a900800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456606  83c410                 +add esp, 0x10
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
    // 00456609  eb3c                   -jmp 0x456647
    goto L_0x00456647;
L_0x0045660b:
    // 0045660b  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045660e  740a                   -je 0x45661a
    if (cpu.flags.zf)
    {
        goto L_0x0045661a;
    }
    // 00456610  83ff02                 +cmp edi, 2
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
    // 00456613  7405                   -je 0x45661a
    if (cpu.flags.zf)
    {
        goto L_0x0045661a;
    }
    // 00456615  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456618  750f                   -jne 0x456629
    if (!cpu.flags.zf)
    {
        goto L_0x00456629;
    }
L_0x0045661a:
    // 0045661a  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045661f  8b0c8568965500         -mov ecx, dword ptr [eax*4 + 0x559668]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5609064) /* 0x559668 */ + cpu.eax * 4);
    // 00456626  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456627  eb0d                   -jmp 0x456636
    goto L_0x00456636;
L_0x00456629:
    // 00456629  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045662e  8b34858c965500         -mov esi, dword ptr [eax*4 + 0x55968c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5609100) /* 0x55968c */ + cpu.eax * 4);
    // 00456635  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00456636:
    // 00456636  68809a5300             -push 0x539a80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479040 /*0x539a80*/;
    cpu.esp -= 4;
    // 0045663b  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045663e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045663f  e84c900800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456644  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00456647:
    // 00456647  68fd8c4800             -push 0x488cfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4754685 /*0x488cfd*/;
    cpu.esp -= 4;
    // 0045664c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045664e  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456653  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00456656  e835bbffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0045665b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045665d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045665e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045665f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456660  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456661  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456662  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456663  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_456670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456674  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456675  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456676  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456678  8b15609c5500           -mov edx, dword ptr [0x559c60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
    // 0045667e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00456680  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456682  7407                   -je 0x45668b
    if (cpu.flags.zf)
    {
        goto L_0x0045668b;
    }
    // 00456684  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00456686  e967010000             -jmp 0x4567f2
    goto L_0x004567f2;
L_0x0045668b:
    // 0045668b  8b0dacd46f00           -mov ecx, dword ptr [0x6fd4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456691  3b0d8c7d6700           +cmp ecx, dword ptr [0x677d8c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782348) /* 0x677d8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456697  740c                   -je 0x4566a5
    if (cpu.flags.zf)
    {
        goto L_0x004566a5;
    }
    // 00456699  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045669e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045669f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004566a5:
    // 004566a5  e8e6feffff             -call 0x456590
    cpu.esp -= 4;
    sub_456590(app, cpu);
    if (cpu.terminate) return;
    // 004566aa  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004566af  8b1d24985500           -mov ebx, dword ptr [0x559824]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */);
    // 004566b5  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004566ba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004566bc  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004566bf  8b1445ae965500         -mov edx, dword ptr [eax*2 + 0x5596ae]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609134) /* 0x5596ae */ + cpu.eax * 2);
    // 004566c6  891d24985500           -mov dword ptr [0x559824], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */) = cpu.ebx;
    // 004566cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004566cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004566d0  8b1c45c0965500         -mov ebx, dword ptr [eax*2 + 0x5596c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609152) /* 0x5596c0 */ + cpu.eax * 2);
    // 004566d7  a1907d6700             -mov eax, dword ptr [0x677d90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782352) /* 0x677d90 */);
    // 004566dc  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004566df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004566e2  e849000800             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 004566e7  8b151c985500           -mov edx, dword ptr [0x55981c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */);
    // 004566ed  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004566f0  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 004566f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004566f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004566fa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004566fc  89151c985500           -mov dword ptr [0x55981c], edx
    app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */) = cpu.edx;
    // 00456702  81fa00010000           +cmp edx, 0x100
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
    // 00456708  7d04                   -jge 0x45670e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045670e;
    }
    // 0045670a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045670c  eb07                   -jmp 0x456715
    goto L_0x00456715;
L_0x0045670e:
    // 0045670e  b9ff010000             -mov ecx, 0x1ff
    cpu.ecx = 511 /*0x1ff*/;
    // 00456713  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00456715:
    // 00456715  e8c62e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 0045671a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045671c  7467                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 0045671e  833d2098550000         +cmp dword ptr [0x559820], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456725  745e                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 00456727  8b3d18985500           -mov edi, dword ptr [0x559818]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045672d  47                     -inc edi
    (cpu.edi)++;
    // 0045672e  893d18985500           -mov dword ptr [0x559818], edi
    app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */) = cpu.edi;
    // 00456734  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456737  7d16                   -jge 0x45674f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045674f;
    }
    // 00456739  a18e7d6700             -mov eax, dword ptr [0x677d8e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782350) /* 0x677d8e */);
    // 0045673e  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00456741  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456744  e8b7000000             -call 0x456800
    cpu.esp -= 4;
    sub_456800(app, cpu);
    if (cpu.terminate) return;
    // 00456749  66a3907d6700           -mov word ptr [0x677d90], ax
    app->getMemory<x86::reg16>(x86::reg32(6782352) /* 0x677d90 */) = cpu.ax;
L_0x0045674f:
    // 0045674f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456751  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456756  89157c7d6700           -mov dword ptr [0x677d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */) = cpu.edx;
    // 0045675c  8915787d6700           -mov dword ptr [0x677d78], edx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.edx;
    // 00456762  8b3c85f4975500         -mov edi, dword ptr [eax*4 + 0x5597f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 00456769  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045676f  39fa                   +cmp edx, edi
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
    // 00456771  7f12                   -jg 0x456785
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00456785;
    }
    // 00456773  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00456779  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045677b  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00456780  e86b2e0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
L_0x00456785:
    // 00456785  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045678a  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 00456790  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00456793  8b1c85f4975500         -mov ebx, dword ptr [eax*4 + 0x5597f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 0045679a  81c1ffffff00           -add ecx, 0xffffff
    (cpu.ecx) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004567a0  39da                   +cmp edx, ebx
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
    // 004567a2  7f42                   -jg 0x4567e6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004567a6  7e3e                   -jle 0x4567e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a8  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004567ab  6683b86e7d670000       +cmp word ptr [eax + 0x677d6e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6782318) /* 0x677d6e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004567b3  7420                   -je 0x4567d5
    if (cpu.flags.zf)
    {
        goto L_0x004567d5;
    }
    // 004567b5  8b98547d6700           -mov ebx, dword ptr [eax + 0x677d54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782292) /* 0x677d54 */);
    // 004567bb  8b904c7d6700           -mov edx, dword ptr [eax + 0x677d4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782284) /* 0x677d4c */);
    // 004567c1  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004567c4  8b806c7d6700           -mov eax, dword ptr [eax + 0x677d6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782316) /* 0x677d6c */);
    // 004567ca  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004567cd  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004567d0  e88b090800             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x004567d5:
    // 004567d5  e8062e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 004567da  e841fbffff             -call 0x456320
    cpu.esp -= 4;
    sub_456320(app, cpu);
    if (cpu.terminate) return;
    // 004567df  a320985500             -mov dword ptr [0x559820], eax
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = cpu.eax;
    // 004567e4  eb0a                   -jmp 0x4567f0
    goto L_0x004567f0;
L_0x004567e6:
    // 004567e6  c7052098550001000000   -mov dword ptr [0x559820], 1
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = 1 /*0x1*/;
L_0x004567f0:
    // 004567f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004567f2:
    // 004567f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456805  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456807  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456809  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045680b  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00456810  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00456815  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00456817  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00456819  e872890900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 0045681e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456820  e87b450900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00456825  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045682c  7507                   -jne 0x456835
    if (!cpu.flags.zf)
    {
        goto L_0x00456835;
    }
    // 0045682e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00456833  eb02                   -jmp 0x456837
    goto L_0x00456837;
L_0x00456835:
    // 00456835  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456837:
    // 00456837  e874890900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0045683c  833d807d670000         +cmp dword ptr [0x677d80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456843  741f                   -je 0x456864
    if (cpu.flags.zf)
    {
        goto L_0x00456864;
    }
    // 00456845  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045684b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045684e  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456853  8b94ba64975500         -mov edx, dword ptr [edx + edi*4 + 0x559764]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5609316) /* 0x559764 */ + cpu.edi * 4);
    // 0045685a  e881890900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045685f  e8aca10900             -call 0x4f0a10
    cpu.esp -= 4;
    sub_4f0a10(app, cpu);
    if (cpu.terminate) return;
L_0x00456864:
    // 00456864  e827450900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00456869  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045686b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045686e  e81dfb0700             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00456873  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456875  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456877  e884960900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 0045687c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045687e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045687f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456880  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_456890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456893  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456894  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456896  833d2898550000         +cmp dword ptr [0x559828], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045689d  742a                   -je 0x4568c9
    if (cpu.flags.zf)
    {
        goto L_0x004568c9;
    }
    // 0045689f  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004568a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004568a7  a14cbb6f00             -mov eax, dword ptr [0x6fbb4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004568ac  890d28985500           -mov dword ptr [0x559828], ecx
    app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */) = cpu.ecx;
    // 004568b2  e8292c0700             -call 0x4c94e0
    cpu.esp -= 4;
    sub_4c94e0(app, cpu);
    if (cpu.terminate) return;
    // 004568b7  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 004568bc  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004568c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004568c4  e8272d0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
L_0x004568c9:
    // 004568c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004568cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4568d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004568d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004568d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004568d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004568d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004568d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004568d6  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004568d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004568db  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004568e0  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004568e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004568e7  891528985500           -mov dword ptr [0x559828], edx
    app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */) = cpu.edx;
    // 004568ed  a38c7d6700             -mov dword ptr [0x677d8c], eax
    app->getMemory<x86::reg32>(x86::reg32(6782348) /* 0x677d8c */) = cpu.eax;
    // 004568f2  891d18985500           -mov dword ptr [0x559818], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */) = cpu.ebx;
    // 004568f8  891d1c985500           -mov dword ptr [0x55981c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */) = cpu.ebx;
    // 004568fe  b8889a5300             -mov eax, 0x539a88
    cpu.eax = 5479048 /*0x539a88*/;
    // 00456903  891d787d6700           -mov dword ptr [0x677d78], ebx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ebx;
    // 00456909  e8a2f40700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045690e  66a3927d6700           -mov word ptr [0x677d92], ax
    app->getMemory<x86::reg16>(x86::reg32(6782354) /* 0x677d92 */) = cpu.ax;
    // 00456914  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456919  8b148520965500         -mov edx, dword ptr [eax*4 + 0x559620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608992) /* 0x559620 */ + cpu.eax * 4);
    // 00456920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456921  68b4317a00             -push 0x7a31b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008116 /*0x7a31b4*/;
    cpu.esp -= 4;
    // 00456926  68909a5300             -push 0x539a90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479056 /*0x539a90*/;
    cpu.esp -= 4;
    // 0045692b  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045692e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045692f  e85c8d0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456934  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00456937  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045693a  ba9c9a5300             -mov edx, 0x539a9c
    cpu.edx = 5479068 /*0x539a9c*/;
    // 0045693f  e84c43ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00456944  a3807d6700             -mov dword ptr [0x677d80], eax
    app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */) = cpu.eax;
    // 00456949  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045694b  e8f0c0feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00456950  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456952  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456954  741a                   -je 0x456970
    if (cpu.flags.zf)
    {
        goto L_0x00456970;
    }
    // 00456956  baa89a5300             -mov edx, 0x539aa8
    cpu.edx = 5479080 /*0x539aa8*/;
    // 0045695b  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456960  e87b880900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00456965  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456967  e824fa0700             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045696c  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00456970:
    // 00456970  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456972  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456974  e887feffff             -call 0x456800
    cpu.esp -= 4;
    sub_456800(app, cpu);
    if (cpu.terminate) return;
    // 00456979  66a3907d6700           -mov word ptr [0x677d90], ax
    app->getMemory<x86::reg16>(x86::reg32(6782352) /* 0x677d90 */) = cpu.ax;
    // 0045697f  e87cf8ffff             -call 0x456200
    cpu.esp -= 4;
    sub_456200(app, cpu);
    if (cpu.terminate) return;
    // 00456984  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456986  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456988  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456989  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_456990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456990  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456991  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456993  e8f82b0700             -call 0x4c9590
    cpu.esp -= 4;
    sub_4c9590(app, cpu);
    if (cpu.terminate) return;
    // 00456998  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045699a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045699b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4569a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004569a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004569a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004569a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004569a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004569a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004569a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004569a7  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004569ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004569af  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 004569b4  e897ae0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004569b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004569ba  68b09a5300             -push 0x539ab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479088 /*0x539ab0*/;
    cpu.esp -= 4;
    // 004569bf  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004569c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004569c6  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004569cb  e8c08c0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004569d0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004569d3  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004569d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004569db  e840b6ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004569e0  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x004569e4:
    // 004569e4  3b594c                 +cmp ebx, dword ptr [ecx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004569e7  7d29                   -jge 0x456a12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456a12;
    }
    // 004569e9  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 004569ec  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004569ee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004569f0  e8cb2dfeff             -call 0x4397c0
    cpu.esp -= 4;
    sub_4397c0(app, cpu);
    if (cpu.terminate) return;
    // 004569f5  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004569fa  e821b6ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004569ff  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00456a02  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00456a05  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456a07  39f0                   +cmp eax, esi
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
    // 00456a09  7e04                   -jle 0x456a0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00456a0f;
    }
    // 00456a0b  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x00456a0f:
    // 00456a0f  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456a10  ebd2                   -jmp 0x4569e4
    goto L_0x004569e4;
L_0x00456a12:
    // 00456a12  6683411e2d             -add word ptr [ecx + 0x1e], 0x2d
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */)) += x86::reg16(x86::sreg16(45 /*0x2d*/));
    // 00456a17  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456a19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_456a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456a21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456a22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456a23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456a24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456a25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456a26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456a28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00456a2b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456a2d  c645f8ff               -mov byte ptr [ebp - 8], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 255 /*0xff*/;
    // 00456a31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00456a33  0f84ff000000           -je 0x456b38
    if (cpu.flags.zf)
    {
        goto L_0x00456b38;
    }
    // 00456a39  66837e4000             +cmp word ptr [esi + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456a3e  745b                   -je 0x456a9b
    if (cpu.flags.zf)
    {
        goto L_0x00456a9b;
    }
    // 00456a40  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 00456a45  e80630feff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00456a4a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00456a4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456a4e  0f8496000000           -je 0x456aea
    if (cpu.flags.zf)
    {
        goto L_0x00456aea;
    }
    // 00456a54  c7465428d36f00         -mov dword ptr [esi + 0x54], 0x6fd328
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = 7328552 /*0x6fd328*/;
    // 00456a5b  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a5e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a60  894660                 -mov dword ptr [esi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00456a63  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a66  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00456a6b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a6d  e81e2dfeff             -call 0x439790
    cpu.esp -= 4;
    sub_439790(app, cpu);
    if (cpu.terminate) return;
    // 00456a72  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456a75  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00456a78  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456a7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a7c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456a7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a80  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456a83  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456a86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a87  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a8a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00456a8f  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456a92  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a94  e8772dfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
    // 00456a99  eb4f                   -jmp 0x456aea
    goto L_0x00456aea;
L_0x00456a9b:
    // 00456a9b  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00456aa0  e8ab2ffeff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00456aa5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00456aa7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456aa9  743f                   -je 0x456aea
    if (cpu.flags.zf)
    {
        goto L_0x00456aea;
    }
    // 00456aab  c74654bcd26f00         -mov dword ptr [esi + 0x54], 0x6fd2bc
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = 7328444 /*0x6fd2bc*/;
    // 00456ab2  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456ab5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ab7  894660                 -mov dword ptr [esi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00456aba  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456abd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456abf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ac1  e8ca2cfeff             -call 0x439790
    cpu.esp -= 4;
    sub_439790(app, cpu);
    if (cpu.terminate) return;
    // 00456ac6  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456ac9  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00456acc  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456acf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456ad0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456ad3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456ad4  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456ad7  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456ada  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456adb  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456ade  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00456ae0  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456ae3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ae5  e8262dfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
L_0x00456aea:
    // 00456aea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00456aec  744a                   -je 0x456b38
    if (cpu.flags.zf)
    {
        goto L_0x00456b38;
    }
    // 00456aee  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456af1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456af3  e8682cfeff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00456af8  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00456afb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456afd  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456b00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456b02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b04  8a45ec                 -mov al, byte ptr [ebp - 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456b07  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b0d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b12  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00456b15  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00456b18  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b1c  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456b1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b24  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00456b27  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b2b  8a45f0                 -mov al, byte ptr [ebp - 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456b2e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b33  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b35  895650                 -mov dword ptr [esi + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.edx;
L_0x00456b38:
    // 00456b38  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456b3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_456b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456b52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456b53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456b55  81ec1c010000           -sub esp, 0x11c
    (cpu.esp) -= x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 00456b5b  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00456b5e  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00456b61  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00456b63  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00456b65  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00456b69  0f849c000000           -je 0x456c0b
    if (cpu.flags.zf)
    {
        goto L_0x00456c0b;
    }
    // 00456b6f  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456b72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b73  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456b76  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456b79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b7a  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456b7d  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456b80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b81  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456b84  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456b87  8b5b3e                 -mov ebx, dword ptr [ebx + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(62) /* 0x3e */);
    // 00456b8a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456b8d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456b90  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456b92  e8792cfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
    // 00456b97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b99  8a45f4                 -mov al, byte ptr [ebp - 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456b9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456b9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456ba0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456ba6  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456ba9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00456bac  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456bb1  81ca000000ff           -or edx, 0xff000000
    cpu.edx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00456bb7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00456bba  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456bbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456bbe  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456bc1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456bc6  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00456bc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456bc9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00456bcb  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00456bd0  40                     -inc eax
    (cpu.eax)++;
    // 00456bd1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00456bd6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00456bd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456bdb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456bdd  e82e1d0800             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 00456be2  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456be6  7407                   -je 0x456bef
    if (cpu.flags.zf)
    {
        goto L_0x00456bef;
    }
    // 00456be8  6840e4ffff             -push 0xffffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 4294960192 /*0xffffe440*/;
    cpu.esp -= 4;
    // 00456bed  eb05                   -jmp 0x456bf4
    goto L_0x00456bf4;
L_0x00456bef:
    // 00456bef  68b58a7bff             -push 0xff7b8ab5
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286286517 /*0xff7b8ab5*/;
    cpu.esp -= 4;
L_0x00456bf4:
    // 00456bf4  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00456bf9  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00456bfe  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00456c01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456c03  e8981e0800             -call 0x4d8aa0
    cpu.esp -= 4;
    sub_4d8aa0(app, cpu);
    if (cpu.terminate) return;
    // 00456c08  83c613                 -add esi, 0x13
    (cpu.esi) += x86::reg32(x86::sreg32(19 /*0x13*/));
L_0x00456c0b:
    // 00456c0b  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00456c0f  740d                   -je 0x456c1e
    if (cpu.flags.zf)
    {
        goto L_0x00456c1e;
    }
    // 00456c11  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456c15  7517                   -jne 0x456c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00456c2e;
    }
    // 00456c17  bafd9d64ff             -mov edx, 0xff649dfd
    cpu.edx = 4284784125 /*0xff649dfd*/;
    // 00456c1c  eb15                   -jmp 0x456c33
    goto L_0x00456c33;
L_0x00456c1e:
    // 00456c1e  e8cd31ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00456c23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456c25  7407                   -je 0x456c2e
    if (cpu.flags.zf)
    {
        goto L_0x00456c2e;
    }
    // 00456c27  ba964a0000             -mov edx, 0x4a96
    cpu.edx = 19094 /*0x4a96*/;
    // 00456c2c  eb05                   -jmp 0x456c33
    goto L_0x00456c33;
L_0x00456c2e:
    // 00456c2e  ba40e4ff00             -mov edx, 0xffe440
    cpu.edx = 16770112 /*0xffe440*/;
L_0x00456c33:
    // 00456c33  f6052feb550040         +test byte ptr [0x55eb2f], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */) & 64 /*0x40*/));
    // 00456c3a  0f858a000000           -jne 0x456cca
    if (!cpu.flags.zf)
    {
        goto L_0x00456cca;
    }
    // 00456c40  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456c43  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456c46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456c48  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456c4b  e8302bfeff             -call 0x439780
    cpu.esp -= 4;
    sub_439780(app, cpu);
    if (cpu.terminate) return;
    // 00456c50  39c8                   +cmp eax, ecx
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
    // 00456c52  7556                   -jne 0x456caa
    if (!cpu.flags.zf)
    {
        goto L_0x00456caa;
    }
    // 00456c54  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00456c57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00456c59  7433                   -je 0x456c8e
    if (cpu.flags.zf)
    {
        goto L_0x00456c8e;
    }
    // 00456c5b  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 00456c60  e8ebab0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00456c65  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456c66  68b09a5300             -push 0x539ab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479088 /*0x539ab0*/;
    cpu.esp -= 4;
    // 00456c6b  8d85e4feffff           -lea eax, [ebp - 0x11c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-284) /* -0x11c */);
    // 00456c71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456c72  e8198a0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456c77  83c40c                 +add esp, 0xc
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
    // 00456c7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456c7b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456c80  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456c82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456c84  8d85e4feffff           -lea eax, [ebp - 0x11c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-284) /* -0x11c */);
    // 00456c8a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456c8c  eb15                   -jmp 0x456ca3
    goto L_0x00456ca3;
L_0x00456c8e:
    // 00456c8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456c8f  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 00456c94  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456c99  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456c9a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456c9c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456c9e  e8adab0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
L_0x00456ca3:
    // 00456ca3  e8e8b4ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00456ca8  eb20                   -jmp 0x456cca
    goto L_0x00456cca;
L_0x00456caa:
    // 00456caa  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456cad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456cae  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456cb0  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456cb3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456cb5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00456cb7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456cb9  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456cbe  e8fd2afeff             -call 0x4397c0
    cpu.esp -= 4;
    sub_4397c0(app, cpu);
    if (cpu.terminate) return;
    // 00456cc3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456cc5  e8c6b4ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00456cca:
    // 00456cca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456ccc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456ccd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456cce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456ccf  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_456ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456ce2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456ce3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456ce4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456ce5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456ce7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456cea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456cec  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00456cee  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00456cf3  e86839ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456cf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456cfa  0f8490010000           -je 0x456e90
    if (cpu.flags.zf)
    {
        goto L_0x00456e90;
    }
    // 00456d00  8b5154                 -mov edx, dword ptr [ecx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00456d03  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00456d05  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456d07  0f8481010000           -je 0x456e8e
    if (cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456d0d  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456d12  7406                   -je 0x456d1a
    if (cpu.flags.zf)
    {
        goto L_0x00456d1a;
    }
    // 00456d14  80490504               +or byte ptr [ecx + 5], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00456d18  eb04                   -jmp 0x456d1e
    goto L_0x00456d1e;
L_0x00456d1a:
    // 00456d1a  806105fb               -and byte ptr [ecx + 5], 0xfb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00456d1e:
    // 00456d1e  8b5654                 -mov edx, dword ptr [esi + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456d21  8b4660                 -mov eax, dword ptr [esi + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00456d24  3b02                   +cmp eax, dword ptr [edx]
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
    // 00456d26  7407                   -je 0x456d2f
    if (cpu.flags.zf)
    {
        goto L_0x00456d2f;
    }
    // 00456d28  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456d2a  e8f1fcffff             -call 0x456a20
    cpu.esp -= 4;
    sub_456a20(app, cpu);
    if (cpu.terminate) return;
L_0x00456d2f:
    // 00456d2f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00456d31  0f842b010000           -je 0x456e62
    if (cpu.flags.zf)
    {
        goto L_0x00456e62;
    }
    // 00456d37  66837e5800             +cmp word ptr [esi + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456d3c  0f8404010000           -je 0x456e46
    if (cpu.flags.zf)
    {
        goto L_0x00456e46;
    }
    // 00456d42  8d461a                 -lea eax, [esi + 0x1a]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456d45  e8a6540400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00456d4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456d4c  7421                   -je 0x456d6f
    if (cpu.flags.zf)
    {
        goto L_0x00456d6f;
    }
    // 00456d4e  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00456d51  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00456d56  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456d59  e862540400             -call 0x49c1c0
    cpu.esp -= 4;
    sub_49c1c0(app, cpu);
    if (cpu.terminate) return;
    // 00456d5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456d60  7c0d                   -jl 0x456d6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00456d6f;
    }
    // 00456d62  3b464c                 +cmp eax, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456d65  7d08                   -jge 0x456d6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456d6f;
    }
    // 00456d67  3b4648                 +cmp eax, dword ptr [esi + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456d6a  7403                   -je 0x456d6f
    if (cpu.flags.zf)
    {
        goto L_0x00456d6f;
    }
    // 00456d6c  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x00456d6f:
    // 00456d6f  68222222d0             -push 0xd0222222
    app->getMemory<x86::reg32>(cpu.esp-4) = 3491897890 /*0xd0222222*/;
    cpu.esp -= 4;
    // 00456d74  8b4e1e                 -mov ecx, dword ptr [esi + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 00456d77  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00456d7a  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00456d7d  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456d80  68222222d0             -push 0xd0222222
    app->getMemory<x86::reg32>(cpu.esp-4) = 3491897890 /*0xd0222222*/;
    cpu.esp -= 4;
    // 00456d85  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456d88  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456d8b  68400000a0             -push 0xa0000040
    app->getMemory<x86::reg32>(cpu.esp-4) = 2684354624 /*0xa0000040*/;
    cpu.esp -= 4;
    // 00456d90  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456d93  68400000a0             -push 0xa0000040
    app->getMemory<x86::reg32>(cpu.esp-4) = 2684354624 /*0xa0000040*/;
    cpu.esp -= 4;
    // 00456d98  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456d9b  e8201d0800             -call 0x4d8ac0
    cpu.esp -= 4;
    sub_4d8ac0(app, cpu);
    if (cpu.terminate) return;
    // 00456da0  668b461a               -mov ax, word ptr [esi + 0x1a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456da4  0505000000             -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00456da9  668945f8               -mov word ptr [ebp - 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
    // 00456dad  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00456db1  050f000000             -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00456db6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456db8  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
L_0x00456dbc:
    // 00456dbc  3b7e4c                 +cmp edi, dword ptr [esi + 0x4c]
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
    // 00456dbf  7d35                   -jge 0x456df6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456df6;
    }
    // 00456dc1  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00456dc4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00456dc6  39d7                   +cmp edi, edx
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
    // 00456dc8  7507                   -jne 0x456dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00456dd1;
    }
    // 00456dca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00456dcf  eb02                   -jmp 0x456dd3
    goto L_0x00456dd3;
L_0x00456dd1:
    // 00456dd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456dd3:
    // 00456dd3  8b4df6                 -mov ecx, dword ptr [ebp - 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00456dd6  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00456dd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456dda  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00456ddc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456ddf  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456de2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456de4  e867fdffff             -call 0x456b50
    cpu.esp -= 4;
    sub_456b50(app, cpu);
    if (cpu.terminate) return;
    // 00456de9  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456dec  83c110                 +add ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00456def  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456df0  66894df8               -mov word ptr [ebp - 8], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.cx;
    // 00456df4  ebc6                   -jmp 0x456dbc
    goto L_0x00456dbc;
L_0x00456df6:
    // 00456df6  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00456dfa  668b5606               -mov dx, word ptr [esi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456dfe  0fbfc8                 -movsx ecx, ax
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456e01  0fbffa                 -movsx edi, dx
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00456e04  8d590d                 -lea ebx, [ecx + 0xd]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00456e07  8b465a                 -mov eax, dword ptr [esi + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(90) /* 0x5a */);
    // 00456e0a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00456e0c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e0f  e87c0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456e14  8d570c                 -lea edx, [edi + 0xc]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00456e17  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00456e1a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00456e1c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e1f  e86c0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456e24  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00456e29  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00456e2c  8b561a                 -mov edx, dword ptr [esi + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456e2f  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00456e32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456e34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456e37  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456e3c  83c20f                 +add edx, 0xf
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00456e3f  e84cb3ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00456e44  eb1c                   -jmp 0x456e62
    goto L_0x00456e62;
L_0x00456e46:
    // 00456e46  668b5608               -mov dx, word ptr [esi + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00456e4a  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00456e4d  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456e51  8d5a0d                 -lea ebx, [edx + 0xd]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00456e54  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456e57  8b465a                 -mov eax, dword ptr [esi + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(90) /* 0x5a */);
    // 00456e5a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e5d  e82e0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00456e62:
    // 00456e62  66837e5800             +cmp word ptr [esi + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456e67  7525                   -jne 0x456e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456e69  8b0d609c5500           -mov ecx, dword ptr [0x559c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
    // 00456e6f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00456e71  751b                   -jne 0x456e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456e73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456e74  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00456e77  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456e7a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456e7b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e7e  8b4e06                 -mov ecx, dword ptr [esi + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456e81  8d5819                 -lea ebx, [eax + 0x19]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(25) /* 0x19 */);
    // 00456e84  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456e87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456e89  e8c2fcffff             -call 0x456b50
    cpu.esp -= 4;
    sub_456b50(app, cpu);
    if (cpu.terminate) return;
L_0x00456e8e:
    // 00456e8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456e90:
    // 00456e90  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456e92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456ea1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456ea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456ea3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456ea5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456ea7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00456eac  e8af37ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456eb1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456eb3  7453                   -je 0x456f08
    if (cpu.flags.zf)
    {
        goto L_0x00456f08;
    }
    // 00456eb5  b8b89a5300             -mov eax, 0x539ab8
    cpu.eax = 5479096 /*0x539ab8*/;
    // 00456eba  66c741580000           -mov word ptr [ecx + 0x58], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456ec0  e8ebee0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00456ec5  6689415c               -mov word ptr [ecx + 0x5c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.ax;
    // 00456ec9  b8c09a5300             -mov eax, 0x539ac0
    cpu.eax = 5479104 /*0x539ac0*/;
    // 00456ece  e8ddee0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00456ed3  c7414400000000         -mov dword ptr [ecx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00456eda  c7414c00000000         -mov dword ptr [ecx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00456ee1  c7415400000000         -mov dword ptr [ecx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00456ee8  c7415000000000         -mov dword ptr [ecx + 0x50], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 00456eef  6689415e               -mov word ptr [ecx + 0x5e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(94) /* 0x5e */) = cpu.ax;
    // 00456ef3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456ef5  c7414800000000         -mov dword ptr [ecx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00456efc  e81ffbffff             -call 0x456a20
    cpu.esp -= 4;
    sub_456a20(app, cpu);
    if (cpu.terminate) return;
    // 00456f01  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456f03  e898faffff             -call 0x4569a0
    cpu.esp -= 4;
    sub_4569a0(app, cpu);
    if (cpu.terminate) return;
L_0x00456f08:
    // 00456f08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456f18  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00456f1b  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00456f1e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00456f21  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f24  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456f26  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00456f29  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00456f2c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00456f31  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00456f34  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00456f36  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00456f38  8b511a                 -mov edx, dword ptr [ecx + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00456f3b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456f40  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00456f42  e879500400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 00456f47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f54  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456f57  66c740580100           -mov word ptr [eax + 0x58], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(88) /* 0x58 */) = 1 /*0x1*/;
    // 00456f5d  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00456f60  e87b020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456f65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f74  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456f77  66c740580000           -mov word ptr [eax + 0x58], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456f7d  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00456f80  e85b020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456f85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456f94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456f95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456f9a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456f9c  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00456f9f  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456fa2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456fa4  39d0                   +cmp eax, edx
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
    // 00456fa6  7405                   -je 0x456fad
    if (cpu.flags.zf)
    {
        goto L_0x00456fad;
    }
    // 00456fa8  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00456fad:
    // 00456fad  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00456fb0  66c741580000           -mov word ptr [ecx + 0x58], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456fb6  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456fb9  8b5948                 -mov ebx, dword ptr [ecx + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00456fbc  8b513e                 -mov edx, dword ptr [ecx + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00456fbf  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00456fc2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456fc5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456fc7  e80428feff             -call 0x4397d0
    cpu.esp -= 4;
    sub_4397d0(app, cpu);
    if (cpu.terminate) return;
    // 00456fcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456fce  e80d020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456fd3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00456fd5  7444                   -je 0x45701b
    if (cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00456fd7  6683794000             +cmp word ptr [ecx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456fdc  751a                   -jne 0x456ff8
    if (!cpu.flags.zf)
    {
        goto L_0x00456ff8;
    }
    // 00456fde  bac89a5300             -mov edx, 0x539ac8
    cpu.edx = 5479112 /*0x539ac8*/;
    // 00456fe3  e8c83effff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00456fe8  e853bafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00456fed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456fef  7407                   -je 0x456ff8
    if (cpu.flags.zf)
    {
        goto L_0x00456ff8;
    }
    // 00456ff1  c680b300000001         -mov byte ptr [eax + 0xb3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = 1 /*0x1*/;
L_0x00456ff8:
    // 00456ff8  668b5940               -mov bx, word ptr [ecx + 0x40]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00456ffc  6683fb01               +cmp bx, 1
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457000  7519                   -jne 0x45701b
    if (!cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00457002  badc9a5300             -mov edx, 0x539adc
    cpu.edx = 5479132 /*0x539adc*/;
    // 00457007  e8a43effff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0045700c  e82fbafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00457011  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457013  7406                   -je 0x45701b
    if (cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00457015  8898b3000000           -mov byte ptr [eax + 0xb3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = cpu.bl;
L_0x0045701b:
    // 0045701b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457020  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457021  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_457030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457034  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457038  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045703d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045703f  e81c36ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457044  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00457046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457048  0f847e010000           -je 0x4571cc
    if (cpu.flags.zf)
    {
        goto L_0x004571cc;
    }
    // 0045704e  83795400               +cmp dword ptr [ecx + 0x54], 0
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
    // 00457052  7507                   -jne 0x45705b
    if (!cpu.flags.zf)
    {
        goto L_0x0045705b;
    }
    // 00457054  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00457056  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457057  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457058  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457059  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045705a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045705b:
    // 0045705b  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457060  7531                   -jne 0x457093
    if (!cpu.flags.zf)
    {
        goto L_0x00457093;
    }
    // 00457062  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457066  740b                   -je 0x457073
    if (cpu.flags.zf)
    {
        goto L_0x00457073;
    }
    // 00457068  6681fb004d             +cmp bx, 0x4d00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045706d  0f8557010000           -jne 0x4571ca
    if (!cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
L_0x00457073:
    // 00457073  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00457075  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045707a  e8d1feffff             -call 0x456f50
    cpu.esp -= 4;
    sub_456f50(app, cpu);
    if (cpu.terminate) return;
    // 0045707f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457084  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457089  e84211fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045708e  e937010000             -jmp 0x4571ca
    goto L_0x004571ca;
L_0x00457093:
    // 00457093  6681fb0048             +cmp bx, 0x4800
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457098  7221                   -jb 0x4570bb
    if (cpu.flags.cf)
    {
        goto L_0x004570bb;
    }
    // 0045709a  7640                   -jbe 0x4570dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004570dc;
    }
    // 0045709c  6681fb004b             +cmp bx, 0x4b00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570a1  0f8223010000           -jb 0x4571ca
    if (cpu.flags.cf)
    {
        goto L_0x004571ca;
    }
    // 004570a7  0f86a5000000           -jbe 0x457152
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457152;
    }
    // 004570ad  6681fb0050             +cmp bx, 0x5000
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570b2  7463                   -je 0x457117
    if (cpu.flags.zf)
    {
        goto L_0x00457117;
    }
    // 004570b4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004570b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004570bb:
    // 004570bb  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570bf  0f8205010000           -jb 0x4571ca
    if (cpu.flags.cf)
    {
        goto L_0x004571ca;
    }
    // 004570c5  0f8687000000           -jbe 0x457152
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457152;
    }
    // 004570cb  6683fb1b               +cmp bx, 0x1b
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570cf  0f84da000000           -je 0x4571af
    if (cpu.flags.zf)
    {
        goto L_0x004571af;
    }
    // 004570d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004570d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004570dc:
    // 004570dc  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004570df  48                     -dec eax
    (cpu.eax)--;
    // 004570e0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004570e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004570e7  7d04                   -jge 0x4570ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004570ed;
    }
    // 004570e9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004570eb  eb0a                   -jmp 0x4570f7
    goto L_0x004570f7;
L_0x004570ed:
    // 004570ed  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004570f0  4a                     -dec edx
    (cpu.edx)--;
    // 004570f1  39d0                   +cmp eax, edx
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
    // 004570f3  7e02                   -jle 0x4570f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004570f7;
    }
    // 004570f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004570f7:
    // 004570f7  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004570fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004570fc  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00457101  e80afeffff             -call 0x456f10
    cpu.esp -= 4;
    sub_456f10(app, cpu);
    if (cpu.terminate) return;
    // 00457106  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045710b  e8c010fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00457110  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00457112  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457113  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457114  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457117:
    // 00457117  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0045711a  40                     -inc eax
    (cpu.eax)++;
    // 0045711b  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457122  7d04                   -jge 0x457128
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457128;
    }
    // 00457124  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457126  eb0a                   -jmp 0x457132
    goto L_0x00457132;
L_0x00457128:
    // 00457128  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0045712b  4a                     -dec edx
    (cpu.edx)--;
    // 0045712c  39d0                   +cmp eax, edx
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
    // 0045712e  7e02                   -jle 0x457132
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00457132;
    }
    // 00457130  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00457132:
    // 00457132  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00457135  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00457137  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045713c  e8cffdffff             -call 0x456f10
    cpu.esp -= 4;
    sub_456f10(app, cpu);
    if (cpu.terminate) return;
    // 00457141  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457146  e88510fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045714b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045714d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045714e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045714f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457150  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457151  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457152:
    // 00457152  8d461a                 -lea eax, [esi + 0x1a]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00457155  e896500400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 0045715a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045715c  7451                   -je 0x4571af
    if (cpu.flags.zf)
    {
        goto L_0x004571af;
    }
    // 0045715e  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00457163  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457168  e86310fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045716d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045716f  e81cfeffff             -call 0x456f90
    cpu.esp -= 4;
    sub_456f90(app, cpu);
    if (cpu.terminate) return;
    // 00457174  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00457177  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00457179  e80226feff             -call 0x439780
    cpu.esp -= 4;
    sub_439780(app, cpu);
    if (cpu.terminate) return;
    // 0045717e  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00457181  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457186  39c8                   +cmp eax, ecx
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
    // 00457188  7540                   -jne 0x4571ca
    if (!cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
    // 0045718a  baf09a5300             -mov edx, 0x539af0
    cpu.edx = 5479152 /*0x539af0*/;
    // 0045718f  e81c3dffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00457194  e8a7b8feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00457199  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045719b  742d                   -je 0x4571ca
    if (cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
    // 0045719d  8b563e                 -mov edx, dword ptr [esi + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 004571a0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004571a3  e8a86bfeff             -call 0x43dd50
    cpu.esp -= 4;
    sub_43dd50(app, cpu);
    if (cpu.terminate) return;
    // 004571a8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004571aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004571af:
    // 004571af  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004571b4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004571b9  e81210fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004571be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004571c0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004571c5  e8a6fdffff             -call 0x456f70
    cpu.esp -= 4;
    sub_456f70(app, cpu);
    if (cpu.terminate) return;
L_0x004571ca:
    // 004571ca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004571cc:
    // 004571cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4571e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004571e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004571e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004571e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004571e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004571e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004571e7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004571ec  e86f34ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004571f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004571f3  7455                   -je 0x45724a
    if (cpu.flags.zf)
    {
        goto L_0x0045724a;
    }
    // 004571f5  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004571fa  742f                   -je 0x45722b
    if (cpu.flags.zf)
    {
        goto L_0x0045722b;
    }
    // 004571fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004571fe  e89df7ffff             -call 0x4569a0
    cpu.esp -= 4;
    sub_4569a0(app, cpu);
    if (cpu.terminate) return;
    // 00457203  668b414c               -mov ax, word ptr [ecx + 0x4c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00457207  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045720a  0505000000             -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0045720f  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00457213  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457217  0530000000             -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0045721c  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457220  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00457224  0511000000             +add eax, 0x11
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00457229  eb1b                   -jmp 0x457246
    goto L_0x00457246;
L_0x0045722b:
    // 0045722b  66c741201b00           -mov word ptr [ecx + 0x20], 0x1b
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 27 /*0x1b*/;
    // 00457231  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457235  66c7411e1e00           -mov word ptr [ecx + 0x1e], 0x1e
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = 30 /*0x1e*/;
    // 0045723b  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0045723e  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457242  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00457246:
    // 00457246  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
L_0x0045724a:
    // 0045724a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_457250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457251  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457253  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457254  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_457260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457260  696e7430008d80         -imul ebp, dword ptr [esi + 0x74], 0x808d0030
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */))) * x86::sreg64(x86::sreg32(2156724272 /*0x808d0030*/)));
    // 00457267  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457269  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045726b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0045726e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
    // 00457270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457273  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457274  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457276  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457278  eb2b                   -jmp 0x4572a5
    goto L_0x004572a5;
L_0x0045727a:
    // 0045727a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0045727c:
    // 0045727c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045727e  8b144582985500         -mov edx, dword ptr [eax*2 + 0x559882]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609602) /* 0x559882 */ + cpu.eax * 2);
    // 00457285  8b1de8e55500           -mov ebx, dword ptr [0x55e5e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0045728b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045728e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457290  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00457292  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00457294  7f02                   -jg 0x457298
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457298;
    }
    // 00457296  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00457298:
    // 00457298  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045729a  83f910                 +cmp ecx, 0x10
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
    // 0045729d  7c25                   -jl 0x4572c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004572c4;
    }
    // 0045729f  40                     -inc eax
    (cpu.eax)++;
    // 004572a0  83f808                 +cmp eax, 8
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
    // 004572a3  7d1a                   -jge 0x4572bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004572bf;
    }
L_0x004572a5:
    // 004572a5  8b144572985500         -mov edx, dword ptr [eax*2 + 0x559872]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609586) /* 0x559872 */ + cpu.eax * 2);
    // 004572ac  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004572b2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004572b5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004572b7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004572b9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004572bb  7ebd                   -jle 0x45727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045727a;
    }
    // 004572bd  ebbd                   -jmp 0x45727c
    goto L_0x0045727c;
L_0x004572bf:
    // 004572bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004572c4:
    // 004572c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_457270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00457270;
    // 00457260  696e7430008d80         -imul ebp, dword ptr [esi + 0x74], 0x808d0030
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */))) * x86::sreg64(x86::sreg32(2156724272 /*0x808d0030*/)));
    // 00457267  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457269  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045726b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0045726e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_entry_0x00457270:
    // 00457270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457273  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457274  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457276  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457278  eb2b                   -jmp 0x4572a5
    goto L_0x004572a5;
L_0x0045727a:
    // 0045727a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0045727c:
    // 0045727c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045727e  8b144582985500         -mov edx, dword ptr [eax*2 + 0x559882]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609602) /* 0x559882 */ + cpu.eax * 2);
    // 00457285  8b1de8e55500           -mov ebx, dword ptr [0x55e5e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0045728b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045728e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457290  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00457292  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00457294  7f02                   -jg 0x457298
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457298;
    }
    // 00457296  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00457298:
    // 00457298  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045729a  83f910                 +cmp ecx, 0x10
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
    // 0045729d  7c25                   -jl 0x4572c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004572c4;
    }
    // 0045729f  40                     -inc eax
    (cpu.eax)++;
    // 004572a0  83f808                 +cmp eax, 8
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
    // 004572a3  7d1a                   -jge 0x4572bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004572bf;
    }
L_0x004572a5:
    // 004572a5  8b144572985500         -mov edx, dword ptr [eax*2 + 0x559872]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609586) /* 0x559872 */ + cpu.eax * 2);
    // 004572ac  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004572b2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004572b5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004572b7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004572b9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004572bb  7ebd                   -jle 0x45727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045727a;
    }
    // 004572bd  ebbd                   -jmp 0x45727c
    goto L_0x0045727c;
L_0x004572bf:
    // 004572bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004572c4:
    // 004572c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4572d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004572d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004572d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004572d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004572d4  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004572d9  2d2f020000             -sub eax, 0x22f
    (cpu.eax) -= x86::reg32(x86::sreg32(559 /*0x22f*/));
    // 004572de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004572e0  7f02                   -jg 0x4572e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004572e4;
    }
    // 004572e2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004572e4:
    // 004572e4  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 004572ea  81ea1b010000           -sub edx, 0x11b
    (cpu.edx) -= x86::reg32(x86::sreg32(283 /*0x11b*/));
    // 004572f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004572f2  7f02                   -jg 0x4572f6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004572f6;
    }
    // 004572f4  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004572f6:
    // 004572f6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004572f8  83f810                 +cmp eax, 0x10
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
    // 004572fb  7d08                   -jge 0x457305
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457305;
    }
    // 004572fd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457302  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457303  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457304  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457305:
    // 00457305  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00457307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457308  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457309  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_457310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457310  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457311  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457313  e858ffffff             -call 0x457270
    cpu.esp -= 4;
    sub_457270(app, cpu);
    if (cpu.terminate) return;
    // 00457318  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_457340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00457340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457343  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457344  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457345  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457346  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457348  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045734b  40                     -inc eax
    (cpu.eax)++;
    // 0045734c  83f808                 +cmp eax, 8
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
    // 0045734f  0f87f2000000           -ja 0x457447
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00457447;
    }
    // 00457355  ff24851c734500         -jmp dword ptr [eax*4 + 0x45731c]
    cpu.ip = app->getMemory<x86::reg32>(4551452 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045735c:
    // 0045735c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045735e  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00457361  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00457364  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00457367  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0045736a  e851e10000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 0045736f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457371  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457372  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457373  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457374  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457375  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457376  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457377  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00457378:
    // 00457378  be0000803f             -mov esi, 0x3f800000
    cpu.esi = 1065353216 /*0x3f800000*/;
    // 0045737d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045737f  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00457382  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00457385  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00457388  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0045738b  e830e10000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00457390  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457392  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457393  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457394  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457395  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457397  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457398  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00457399:
    // 00457399  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 0045739e  bf000080bf             -mov edi, 0xbf800000
    cpu.edi = 3212836864 /*0xbf800000*/;
    // 004573a3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004573a6  e999000000             -jmp 0x457444
    goto L_0x00457444;
  case 0x004573ab:
    // 004573ab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004573ad  ba000080bf             -mov edx, 0xbf800000
    cpu.edx = 3212836864 /*0xbf800000*/;
    // 004573b2  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004573b5  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004573b8  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004573bb  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 004573be  e8fde00000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 004573c3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004573c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573cb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004573cc:
    // 004573cc  bb000080bf             -mov ebx, 0xbf800000
    cpu.ebx = 3212836864 /*0xbf800000*/;
    // 004573d1  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004573d4  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004573d7  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004573da  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 004573dd  e8dee00000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 004573e2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004573e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004573ea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004573eb:
    // 004573eb  b8000080bf             -mov eax, 0xbf800000
    cpu.eax = 3212836864 /*0xbf800000*/;
    // 004573f0  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004573f2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004573f5  eb4d                   -jmp 0x457444
    goto L_0x00457444;
  case 0x004573f7:
    // 004573f7  b9000080bf             -mov ecx, 0xbf800000
    cpu.ecx = 3212836864 /*0xbf800000*/;
    // 004573fc  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 00457401  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00457404  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00457407  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0045740a  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0045740d  e8aee00000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00457412  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457414  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457415  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457416  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457417  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457418  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457419  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045741a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045741b:
    // 0045741b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045741d  bb0000803f             -mov ebx, 0x3f800000
    cpu.ebx = 1065353216 /*0x3f800000*/;
    // 00457422  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00457425  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00457428  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0045742b  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0045742e  e88de00000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00457433  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457435  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457436  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457437  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457438  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045743a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045743b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045743c:
    // 0045743c  bf0000803f             -mov edi, 0x3f800000
    cpu.edi = 1065353216 /*0x3f800000*/;
    // 00457441  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
L_0x00457444:
    // 00457444  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
L_0x00457447:
    // 00457447  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0045744a  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0045744d  e86ee00000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00457452  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457454  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457455  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457456  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457457  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457458  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457459  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045745a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_457460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457461  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457462  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457463  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457464  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457465  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457467  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457469  8915a07d6700           -mov dword ptr [0x677da0], edx
    app->getMemory<x86::reg32>(x86::reg32(6782368) /* 0x677da0 */) = cpu.edx;
    // 0045746f  ba22000000             -mov edx, 0x22
    cpu.edx = 34 /*0x22*/;
    // 00457474  e8e731ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457479  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045747b  0f8419010000           -je 0x45759a
    if (cpu.flags.zf)
    {
        goto L_0x0045759a;
    }
    // 00457481  e8eafdffff             -call 0x457270
    cpu.esp -= 4;
    sub_457270(app, cpu);
    if (cpu.terminate) return;
    // 00457486  83f8ff                 +cmp eax, -1
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
    // 00457489  0f848c000000           -je 0x45751b
    if (cpu.flags.zf)
    {
        goto L_0x0045751b;
    }
    // 0045748f  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00457492  8b963c985500           -mov edx, dword ptr [esi + 0x55983c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5609532) /* 0x55983c */);
    // 00457498  bb12010000             -mov ebx, 0x112
    cpu.ebx = 274 /*0x112*/;
    // 0045749d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004574a0  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004574a2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004574a4  8b5906                 -mov ebx, dword ptr [ecx + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004574a7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004574aa  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004574ac  8b962a985500           -mov edx, dword ptr [esi + 0x55982a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5609514) /* 0x55982a */);
    // 004574b2  bf26020000             -mov edi, 0x226
    cpu.edi = 550 /*0x226*/;
    // 004574b7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004574ba  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004574bc  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004574bf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004574c2  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004574c4  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004574cb  8b87a47d6700           -mov eax, dword ptr [edi + 0x677da4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6782372) /* 0x677da4 */);
    // 004574d1  e8ba040800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 004574d6  ba12010000             -mov edx, 0x112
    cpu.edx = 274 /*0x112*/;
    // 004574db  8b8660985500           -mov eax, dword ptr [esi + 0x559860]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5609568) /* 0x559860 */);
    // 004574e1  8b5906                 -mov ebx, dword ptr [ecx + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004574e4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004574e7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004574ea  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004574ec  8b864e985500           -mov eax, dword ptr [esi + 0x55984e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5609550) /* 0x55984e */);
    // 004574f2  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004574f4  ba26020000             -mov edx, 0x226
    cpu.edx = 550 /*0x226*/;
    // 004574f9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004574fc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004574fe  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00457501  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457504  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457506  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00457508  8b87c87d6700           -mov eax, dword ptr [edi + 0x677dc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6782408) /* 0x677dc8 */);
    // 0045750e  e87d040800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00457513  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00457515  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457516  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457517  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457518  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457519  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045751a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045751b:
    // 0045751b  e8b0fdffff             -call 0x4572d0
    cpu.esp -= 4;
    sub_4572d0(app, cpu);
    if (cpu.terminate) return;
    // 00457520  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457522  7474                   -je 0x457598
    if (cpu.flags.zf)
    {
        goto L_0x00457598;
    }
    // 00457524  ba12010000             -mov edx, 0x112
    cpu.edx = 274 /*0x112*/;
    // 00457529  a14c985500             -mov eax, dword ptr [0x55984c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609548) /* 0x55984c */);
    // 0045752e  8b5906                 -mov ebx, dword ptr [ecx + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457531  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457534  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00457537  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00457539  a13a985500             -mov eax, dword ptr [0x55983a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609530) /* 0x55983a */);
    // 0045753e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457540  ba26020000             -mov edx, 0x226
    cpu.edx = 550 /*0x226*/;
    // 00457545  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457548  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045754a  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045754d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457550  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457552  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00457554  a1c47d6700             -mov eax, dword ptr [0x677dc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782404) /* 0x677dc4 */);
    // 00457559  e832040800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0045755e  ba12010000             -mov edx, 0x112
    cpu.edx = 274 /*0x112*/;
    // 00457563  a170985500             -mov eax, dword ptr [0x559870]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609584) /* 0x559870 */);
    // 00457568  8b5906                 -mov ebx, dword ptr [ecx + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045756b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045756e  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00457571  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00457573  a15e985500             -mov eax, dword ptr [0x55985e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609566) /* 0x55985e */);
    // 00457578  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045757a  ba26020000             -mov edx, 0x226
    cpu.edx = 550 /*0x226*/;
    // 0045757f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457582  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00457584  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00457587  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045758a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045758c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045758e  a1e87d6700             -mov eax, dword ptr [0x677de8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782440) /* 0x677de8 */);
    // 00457593  e8f8030800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00457598:
    // 00457598  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045759a:
    // 0045759a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045759b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045759c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045759d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045759e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045759f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4575a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004575a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004575a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004575a2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004575a4  ba22000000             -mov edx, 0x22
    cpu.edx = 34 /*0x22*/;
    // 004575a9  e8b230ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004575ae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004575b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004575b2  745f                   -je 0x457613
    if (cpu.flags.zf)
    {
        goto L_0x00457613;
    }
    // 004575b4  833da07d670000         +cmp dword ptr [0x677da0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782368) /* 0x677da0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004575bb  7505                   -jne 0x4575c2
    if (!cpu.flags.zf)
    {
        goto L_0x004575c2;
    }
    // 004575bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004575bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004575c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004575c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004575c2:
    // 004575c2  6681fb004b             +cmp bx, 0x4b00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004575c7  7505                   -jne 0x4575ce
    if (!cpu.flags.zf)
    {
        goto L_0x004575ce;
    }
    // 004575c9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x004575ce:
    // 004575ce  6681fb004d             +cmp bx, 0x4d00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004575d3  7505                   -jne 0x4575da
    if (!cpu.flags.zf)
    {
        goto L_0x004575da;
    }
    // 004575d5  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x004575da:
    // 004575da  6683fb20               +cmp bx, 0x20
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004575de  7505                   -jne 0x4575e5
    if (!cpu.flags.zf)
    {
        goto L_0x004575e5;
    }
    // 004575e0  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x004575e5:
    // 004575e5  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004575e9  7526                   -jne 0x457611
    if (!cpu.flags.zf)
    {
        goto L_0x00457611;
    }
    // 004575eb  e880fcffff             -call 0x457270
    cpu.esp -= 4;
    sub_457270(app, cpu);
    if (cpu.terminate) return;
    // 004575f0  83f8ff                 +cmp eax, -1
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
    // 004575f3  740a                   -je 0x4575ff
    if (cpu.flags.zf)
    {
        goto L_0x004575ff;
    }
    // 004575f5  e846fdffff             -call 0x457340
    cpu.esp -= 4;
    sub_457340(app, cpu);
    if (cpu.terminate) return;
    // 004575fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004575fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004575fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004575fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004575ff:
    // 004575ff  e8ccfcffff             -call 0x4572d0
    cpu.esp -= 4;
    sub_4572d0(app, cpu);
    if (cpu.terminate) return;
    // 00457604  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457606  7409                   -je 0x457611
    if (cpu.flags.zf)
    {
        goto L_0x00457611;
    }
    // 00457608  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045760a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045760c  e8afde0000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
L_0x00457611:
    // 00457611  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00457613:
    // 00457613  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457614  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_457620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457620  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457621  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457623  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 00457628  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_457630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457631  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457632  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457633  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457635  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457637  ba22000000             -mov edx, 0x22
    cpu.edx = 34 /*0x22*/;
    // 0045763c  e81f30ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457641  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457643  7424                   -je 0x457669
    if (cpu.flags.zf)
    {
        goto L_0x00457669;
    }
    // 00457645  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457649  66c7411e3d00           -mov word ptr [ecx + 0x1e], 0x3d
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = 61 /*0x3d*/;
    // 0045764f  83e815                 -sub eax, 0x15
    (cpu.eax) -= x86::reg32(x86::sreg32(21 /*0x15*/));
    // 00457652  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457656  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0045765a  66c741203d00           -mov word ptr [ecx + 0x20], 0x3d
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 61 /*0x3d*/;
    // 00457660  83e816                 -sub eax, 0x16
    (cpu.eax) -= x86::reg32(x86::sreg32(22 /*0x16*/));
    // 00457663  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00457667  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00457669:
    // 00457669  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045766a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045766b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045766c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_457670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457670  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457671  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457673  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457674  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_457680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457680  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457683  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457684  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457686  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00457689  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045768c  be60724500             -mov esi, 0x457260
    cpu.esi = 4551264 /*0x457260*/;
    // 00457691  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00457693  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00457694  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00457695  eb05                   -jmp 0x45769c
    goto L_0x0045769c;
L_0x00457697:
    // 00457697  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045769a  7d2f                   -jge 0x4576cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004576cb;
    }
L_0x0045769c:
    // 0045769c  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0045769e  0431                   -add al, 0x31
    (cpu.al) += x86::reg8(x86::sreg8(49 /*0x31*/));
    // 004576a0  8845fb                 -mov byte ptr [ebp - 5], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = cpu.al;
    // 004576a3  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004576a6  e805e70700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004576ab  890495a47d6700         -mov dword ptr [edx*4 + 0x677da4], eax
    app->getMemory<x86::reg32>(x86::reg32(6782372) /* 0x677da4 */ + cpu.edx * 4) = cpu.eax;
    // 004576b2  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004576b4  0461                   +add al, 0x61
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004576b6  8845fb                 -mov byte ptr [ebp - 5], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = cpu.al;
    // 004576b9  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004576bc  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004576bd  e8eee60700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004576c2  890495c47d6700         -mov dword ptr [edx*4 + 0x677dc4], eax
    app->getMemory<x86::reg32>(x86::reg32(6782404) /* 0x677dc4 */ + cpu.edx * 4) = cpu.eax;
    // 004576c9  ebcc                   -jmp 0x457697
    goto L_0x00457697;
L_0x004576cb:
    // 004576cb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004576cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004576ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004576cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004576d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004576d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4576e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004576e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457700  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457702  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457704  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457706  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457708  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457710  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457712  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457714  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457716  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457718  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457720  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457722  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457724  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457726  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457728  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457730  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457732  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457734  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457736  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457738  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457740  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457742  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457744  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457746  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457748  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457750  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457752  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457754  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457756  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457758  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457760  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457762  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457764  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457766  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457768  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457770  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457772  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457774  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457776  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457778  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457780  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457782  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457784  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457786  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457788  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457790  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457792  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457794  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457796  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457798  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457800  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457802  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457804  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457806  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457808  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457810  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457812  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457814  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457816  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457818  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457820  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457822  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457824  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457826  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457828  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457830  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457832  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457834  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457836  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457838  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457840  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457842  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457844  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457846  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457848  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457850  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457852  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457854  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457856  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457858  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457860  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457862  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457864  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457866  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457868  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457870  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457872  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457874  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457876  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457878  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457880  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457882  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457884  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457886  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457888  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457890  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457892  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457894  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457896  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457898  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457900  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457902  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457904  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457906  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457908  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457910  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457912  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457914  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457916  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457918  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457920  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457922  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457924  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457926  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457928  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457930  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457932  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457934  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457936  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457938  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457940  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457942  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457944  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457946  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457948  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457950  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457952  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457954  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457956  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457958  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457960  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457962  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457964  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457966  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457968  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457970  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457972  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457974  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457976  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457978  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457980  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457982  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457984  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457986  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457988  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457990  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457992  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457994  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457996  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457998  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457abc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457abe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457acc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ace  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ada  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457adc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ade  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ae0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457ae1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457ae2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457ae3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457ae5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00457ae8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00457aea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457aec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00457aee  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457af0  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00457af3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00457af5  7c04                   -jl 0x457afb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00457afb;
    }
    // 00457af7  39f8                   +cmp eax, edi
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
    // 00457af9  7f06                   -jg 0x457b01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457b01;
    }
L_0x00457afb:
    // 00457afb  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00457b01:
    // 00457b01  6683f933               +cmp cx, 0x33
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(51 /*0x33*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b05  7238                   -jb 0x457b3f
    if (cpu.flags.cf)
    {
        goto L_0x00457b3f;
    }
    // 00457b07  0f8680000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b0d  6683f937               +cmp cx, 0x37
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(55 /*0x37*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b11  7222                   -jb 0x457b35
    if (cpu.flags.cf)
    {
        goto L_0x00457b35;
    }
    // 00457b13  0f8674000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b19  6683f939               +cmp cx, 0x39
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(57 /*0x39*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b1d  0f826a000000           -jb 0x457b8d
    if (cpu.flags.cf)
    {
        goto L_0x00457b8d;
    }
    // 00457b23  0f8664000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b29  6681f90053             +cmp cx, 0x5300
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21248 /*0x5300*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b2e  7447                   -je 0x457b77
    if (cpu.flags.zf)
    {
        goto L_0x00457b77;
    }
    // 00457b30  e9fa000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b35:
    // 00457b35  6683f935               +cmp cx, 0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(53 /*0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b39  7252                   -jb 0x457b8d
    if (cpu.flags.cf)
    {
        goto L_0x00457b8d;
    }
    // 00457b3b  7650                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b3d  eb4e                   -jmp 0x457b8d
    goto L_0x00457b8d;
L_0x00457b3f:
    // 00457b3f  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b43  7217                   -jb 0x457b5c
    if (cpu.flags.cf)
    {
        goto L_0x00457b5c;
    }
    // 00457b45  7646                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b47  6683f931               +cmp cx, 0x31
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(49 /*0x31*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b4b  7204                   -jb 0x457b51
    if (cpu.flags.cf)
    {
        goto L_0x00457b51;
    }
    // 00457b4d  763e                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b4f  eb3c                   -jmp 0x457b8d
    goto L_0x00457b8d;
L_0x00457b51:
    // 00457b51  6683f930               +cmp cx, 0x30
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(48 /*0x30*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b55  7436                   -je 0x457b8d
    if (cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b57  e9d3000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b5c:
    // 00457b5c  6683f908               +cmp cx, 8
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b60  0f82c9000000           -jb 0x457c2f
    if (cpu.flags.cf)
    {
        goto L_0x00457c2f;
    }
    // 00457b66  760f                   -jbe 0x457b77
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b77;
    }
    // 00457b68  6683f92d               +cmp cx, 0x2d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(45 /*0x2d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b6c  0f849f000000           -je 0x457c11
    if (cpu.flags.zf)
    {
        goto L_0x00457c11;
    }
    // 00457b72  e9b8000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b77:
    // 00457b77  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00457b7d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00457b7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00457b81  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00457b83  e8b88a0800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00457b88  e99d000000             -jmp 0x457c2a
    goto L_0x00457c2a;
L_0x00457b8d:
    // 00457b8d  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b91  750a                   -jne 0x457b9d
    if (!cpu.flags.zf)
    {
        goto L_0x00457b9d;
    }
    // 00457b93  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457b97  0f858d000000           -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
L_0x00457b9d:
    // 00457b9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00457b9f:
    // 00457b9f  39c2                   +cmp edx, eax
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
    // 00457ba1  7d12                   -jge 0x457bb5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457bb5;
    }
    // 00457ba3  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00457ba6  803f2e                 +cmp byte ptr [edi], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457ba9  7507                   -jne 0x457bb2
    if (!cpu.flags.zf)
    {
        goto L_0x00457bb2;
    }
    // 00457bab  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
L_0x00457bb2:
    // 00457bb2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00457bb3  ebea                   -jmp 0x457b9f
    goto L_0x00457b9f;
L_0x00457bb5:
    // 00457bb5  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457bb9  750a                   -jne 0x457bc5
    if (!cpu.flags.zf)
    {
        goto L_0x00457bc5;
    }
    // 00457bbb  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00457bbf  0f8565000000           -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
L_0x00457bc5:
    // 00457bc5  803e2d                 +cmp byte ptr [esi], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457bc8  7507                   -jne 0x457bd1
    if (!cpu.flags.zf)
    {
        goto L_0x00457bd1;
    }
    // 00457bca  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00457bcf  eb05                   -jmp 0x457bd6
    goto L_0x00457bd6;
L_0x00457bd1:
    // 00457bd1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x00457bd6:
    // 00457bd6  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457bda  7406                   -je 0x457be2
    if (cpu.flags.zf)
    {
        goto L_0x00457be2;
    }
    // 00457bdc  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00457be0  7401                   -je 0x457be3
    if (cpu.flags.zf)
    {
        goto L_0x00457be3;
    }
L_0x00457be2:
    // 00457be2  42                     -inc edx
    (cpu.edx)++;
L_0x00457be3:
    // 00457be3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00457be5  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457be7  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00457bea  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457bec  3b7df8                 +cmp edi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457bef  7f04                   -jg 0x457bf5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457bf5;
    }
    // 00457bf1  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00457bf3  880e                   -mov byte ptr [esi], cl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.cl;
L_0x00457bf5:
    // 00457bf5  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457bf7  41                     -inc ecx
    (cpu.ecx)++;
    // 00457bf8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457bfa  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00457bfc  39c8                   +cmp eax, ecx
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
    // 00457bfe  7d2a                   -jge 0x457c2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457c2a;
    }
    // 00457c00  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00457c02  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00457c07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457c09  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457c0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00457c11:
    // 00457c11  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457c13  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00457c15  7513                   -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
    // 00457c17  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00457c19  880c32                 -mov byte ptr [edx + esi], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) = cpu.cl;
    // 00457c1c  ff03                   -inc dword ptr [ebx]
    (app->getMemory<x86::reg32>(cpu.ebx))++;
    // 00457c1e  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00457c21  3b13                   +cmp edx, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457c23  7f05                   -jg 0x457c2a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457c2a;
    }
    // 00457c25  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00457c28  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00457c2a:
    // 00457c2a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00457c2f:
    // 00457c2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457c31  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457c33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c36  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_457ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00457ae0;
    // 004576e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004576fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457700  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457702  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457704  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457706  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457708  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045770e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457710  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457712  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457714  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457716  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457718  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045771e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457720  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457722  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457724  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457726  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457728  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045772e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457730  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457732  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457734  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457736  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457738  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045773e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457740  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457742  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457744  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457746  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457748  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045774e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457750  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457752  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457754  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457756  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457758  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045775e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457760  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457762  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457764  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457766  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457768  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045776e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457770  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457772  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457774  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457776  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457778  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045777e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457780  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457782  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457784  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457786  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457788  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045778e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457790  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457792  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457794  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457796  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457798  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045779e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004577fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457800  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457802  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457804  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457806  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457808  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045780e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457810  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457812  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457814  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457816  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457818  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045781e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457820  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457822  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457824  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457826  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457828  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045782e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457830  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457832  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457834  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457836  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457838  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045783e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457840  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457842  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457844  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457846  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457848  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045784e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457850  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457852  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457854  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457856  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457858  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045785e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457860  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457862  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457864  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457866  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457868  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045786e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457870  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457872  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457874  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457876  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457878  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045787e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457880  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457882  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457884  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457886  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457888  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045788e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457890  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457892  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457894  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457896  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457898  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045789e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004578fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457900  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457902  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457904  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457906  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457908  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045790e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457910  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457912  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457914  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457916  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457918  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045791e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457920  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457922  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457924  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457926  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457928  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045792e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457930  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457932  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457934  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457936  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457938  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045793e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457940  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457942  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457944  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457946  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457948  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045794e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457950  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457952  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457954  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457956  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457958  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045795e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457960  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457962  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457964  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457966  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457968  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045796e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457970  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457972  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457974  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457976  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457978  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045797e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457980  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457982  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457984  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457986  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457988  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045798e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457990  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457992  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457994  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457996  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457998  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045799e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004579fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457a9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aa8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ab8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457abc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457abe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ac8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457aca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457acc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ace  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ad8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ada  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457adc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457ade  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00457ae0:
    // 00457ae0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457ae1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457ae2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457ae3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457ae5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00457ae8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00457aea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457aec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00457aee  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457af0  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00457af3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00457af5  7c04                   -jl 0x457afb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00457afb;
    }
    // 00457af7  39f8                   +cmp eax, edi
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
    // 00457af9  7f06                   -jg 0x457b01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457b01;
    }
L_0x00457afb:
    // 00457afb  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00457b01:
    // 00457b01  6683f933               +cmp cx, 0x33
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(51 /*0x33*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b05  7238                   -jb 0x457b3f
    if (cpu.flags.cf)
    {
        goto L_0x00457b3f;
    }
    // 00457b07  0f8680000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b0d  6683f937               +cmp cx, 0x37
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(55 /*0x37*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b11  7222                   -jb 0x457b35
    if (cpu.flags.cf)
    {
        goto L_0x00457b35;
    }
    // 00457b13  0f8674000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b19  6683f939               +cmp cx, 0x39
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(57 /*0x39*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b1d  0f826a000000           -jb 0x457b8d
    if (cpu.flags.cf)
    {
        goto L_0x00457b8d;
    }
    // 00457b23  0f8664000000           -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b29  6681f90053             +cmp cx, 0x5300
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21248 /*0x5300*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b2e  7447                   -je 0x457b77
    if (cpu.flags.zf)
    {
        goto L_0x00457b77;
    }
    // 00457b30  e9fa000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b35:
    // 00457b35  6683f935               +cmp cx, 0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(53 /*0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b39  7252                   -jb 0x457b8d
    if (cpu.flags.cf)
    {
        goto L_0x00457b8d;
    }
    // 00457b3b  7650                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b3d  eb4e                   -jmp 0x457b8d
    goto L_0x00457b8d;
L_0x00457b3f:
    // 00457b3f  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b43  7217                   -jb 0x457b5c
    if (cpu.flags.cf)
    {
        goto L_0x00457b5c;
    }
    // 00457b45  7646                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b47  6683f931               +cmp cx, 0x31
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(49 /*0x31*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b4b  7204                   -jb 0x457b51
    if (cpu.flags.cf)
    {
        goto L_0x00457b51;
    }
    // 00457b4d  763e                   -jbe 0x457b8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b4f  eb3c                   -jmp 0x457b8d
    goto L_0x00457b8d;
L_0x00457b51:
    // 00457b51  6683f930               +cmp cx, 0x30
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(48 /*0x30*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b55  7436                   -je 0x457b8d
    if (cpu.flags.zf)
    {
        goto L_0x00457b8d;
    }
    // 00457b57  e9d3000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b5c:
    // 00457b5c  6683f908               +cmp cx, 8
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b60  0f82c9000000           -jb 0x457c2f
    if (cpu.flags.cf)
    {
        goto L_0x00457c2f;
    }
    // 00457b66  760f                   -jbe 0x457b77
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457b77;
    }
    // 00457b68  6683f92d               +cmp cx, 0x2d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(45 /*0x2d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b6c  0f849f000000           -je 0x457c11
    if (cpu.flags.zf)
    {
        goto L_0x00457c11;
    }
    // 00457b72  e9b8000000             -jmp 0x457c2f
    goto L_0x00457c2f;
L_0x00457b77:
    // 00457b77  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00457b7d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00457b7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00457b81  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00457b83  e8b88a0800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00457b88  e99d000000             -jmp 0x457c2a
    goto L_0x00457c2a;
L_0x00457b8d:
    // 00457b8d  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457b91  750a                   -jne 0x457b9d
    if (!cpu.flags.zf)
    {
        goto L_0x00457b9d;
    }
    // 00457b93  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457b97  0f858d000000           -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
L_0x00457b9d:
    // 00457b9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00457b9f:
    // 00457b9f  39c2                   +cmp edx, eax
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
    // 00457ba1  7d12                   -jge 0x457bb5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457bb5;
    }
    // 00457ba3  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00457ba6  803f2e                 +cmp byte ptr [edi], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457ba9  7507                   -jne 0x457bb2
    if (!cpu.flags.zf)
    {
        goto L_0x00457bb2;
    }
    // 00457bab  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
L_0x00457bb2:
    // 00457bb2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00457bb3  ebea                   -jmp 0x457b9f
    goto L_0x00457b9f;
L_0x00457bb5:
    // 00457bb5  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457bb9  750a                   -jne 0x457bc5
    if (!cpu.flags.zf)
    {
        goto L_0x00457bc5;
    }
    // 00457bbb  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00457bbf  0f8565000000           -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
L_0x00457bc5:
    // 00457bc5  803e2d                 +cmp byte ptr [esi], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457bc8  7507                   -jne 0x457bd1
    if (!cpu.flags.zf)
    {
        goto L_0x00457bd1;
    }
    // 00457bca  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00457bcf  eb05                   -jmp 0x457bd6
    goto L_0x00457bd6;
L_0x00457bd1:
    // 00457bd1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x00457bd6:
    // 00457bd6  6683f92e               +cmp cx, 0x2e
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457bda  7406                   -je 0x457be2
    if (cpu.flags.zf)
    {
        goto L_0x00457be2;
    }
    // 00457bdc  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00457be0  7401                   -je 0x457be3
    if (cpu.flags.zf)
    {
        goto L_0x00457be3;
    }
L_0x00457be2:
    // 00457be2  42                     -inc edx
    (cpu.edx)++;
L_0x00457be3:
    // 00457be3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00457be5  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457be7  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00457bea  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457bec  3b7df8                 +cmp edi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457bef  7f04                   -jg 0x457bf5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457bf5;
    }
    // 00457bf1  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00457bf3  880e                   -mov byte ptr [esi], cl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.cl;
L_0x00457bf5:
    // 00457bf5  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457bf7  41                     -inc ecx
    (cpu.ecx)++;
    // 00457bf8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457bfa  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00457bfc  39c8                   +cmp eax, ecx
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
    // 00457bfe  7d2a                   -jge 0x457c2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457c2a;
    }
    // 00457c00  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00457c02  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00457c07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457c09  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457c0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c0e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00457c11:
    // 00457c11  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00457c13  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00457c15  7513                   -jne 0x457c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00457c2a;
    }
    // 00457c17  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00457c19  880c32                 -mov byte ptr [edx + esi], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) = cpu.cl;
    // 00457c1c  ff03                   -inc dword ptr [ebx]
    (app->getMemory<x86::reg32>(cpu.ebx))++;
    // 00457c1e  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00457c21  3b13                   +cmp edx, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457c23  7f05                   -jg 0x457c2a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457c2a;
    }
    // 00457c25  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00457c28  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00457c2a:
    // 00457c2a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00457c2f:
    // 00457c2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457c31  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457c33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457c36  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_457c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457c42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457c44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457c45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457c47  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00457c4d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00457c4f  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00457c52  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00457c57  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457c5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00457c5f  bee0764500             -mov esi, 0x4576e0
    cpu.esi = 4552416 /*0x4576e0*/;
    // 00457c64  668955f8               -mov word ptr [ebp - 8], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.dx;
    // 00457c68  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00457c6d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00457c6f  e8ec29ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457c74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457c76  0f846b010000           -je 0x457de7
    if (cpu.flags.zf)
    {
        goto L_0x00457de7;
    }
    // 00457c7c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00457c7e  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457c82  740e                   -je 0x457c92
    if (cpu.flags.zf)
    {
        goto L_0x00457c92;
    }
    // 00457c84  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
    // 00457c89  eb0c                   -jmp 0x457c97
    goto L_0x00457c97;
    // 00457c8b  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 00457c90  eb05                   -jmp 0x457c97
    goto L_0x00457c97;
L_0x00457c92:
    // 00457c92  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
L_0x00457c97:
    // 00457c97  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00457c9b  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 00457c9f  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00457ca3  668945f4               -mov word ptr [ebp - 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ax;
    // 00457ca7  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00457cac  e84fa4ffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00457cb1  8b4e3c                 -mov ecx, dword ptr [esi + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00457cb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00457cb6  7430                   -je 0x457ce8
    if (cpu.flags.zf)
    {
        goto L_0x00457ce8;
    }
    // 00457cb8  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00457cbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00457cbf  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00457cc2  e859a3ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00457cc7  8b55f2                 -mov edx, dword ptr [ebp - 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00457cca  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00457ccf  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00457cd2  8b45f6                 -mov eax, dword ptr [ebp - 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00457cd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457cd6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00457cd9  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00457cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457cdd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00457ce0  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00457ce3  e8a8a4ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00457ce8:
    // 00457ce8  837e5800               +cmp dword ptr [esi + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457cec  0f84f3000000           -je 0x457de5
    if (cpu.flags.zf)
    {
        goto L_0x00457de5;
    }
    // 00457cf2  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 00457cf6  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00457cf9  7658                   -jbe 0x457d53
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457d53;
    }
    // 00457cfb  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457cff  7552                   -jne 0x457d53
    if (!cpu.flags.zf)
    {
        goto L_0x00457d53;
    }
    // 00457d01  8d4660                 -lea eax, [esi + 0x60]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00457d04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457d05  680c9b5300             -push 0x539b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479180 /*0x539b0c*/;
    cpu.esp -= 4;
    // 00457d0a  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457d10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457d11  e87a790800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457d16  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00457d19  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00457d1b  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00457d20  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00457d23  8b55f2                 -mov edx, dword ptr [ebp - 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00457d26  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00457d28  8b7e5c                 -mov edi, dword ptr [esi + 0x5c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00457d2b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00457d30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457d31  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00457d34  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00457d39  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00457d3c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00457d3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00457d41  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00457d43  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457d49  e8d2a4ffff             -call 0x452220
    cpu.esp -= 4;
    sub_452220(app, cpu);
    if (cpu.terminate) return;
    // 00457d4e  e992000000             -jmp 0x457de5
    goto L_0x00457de5;
L_0x00457d53:
    // 00457d53  807e4c01               +cmp byte ptr [esi + 0x4c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457d57  7524                   -jne 0x457d7d
    if (!cpu.flags.zf)
    {
        goto L_0x00457d7d;
    }
    // 00457d59  8b5650                 -mov edx, dword ptr [esi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00457d5c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00457d5e  741d                   -je 0x457d7d
    if (cpu.flags.zf)
    {
        goto L_0x00457d7d;
    }
    // 00457d60  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00457d63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457d64  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00457d66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457d67  68109b5300             -push 0x539b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479184 /*0x539b10*/;
    cpu.esp -= 4;
    // 00457d6c  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457d72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457d73  e818790800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457d78  83c410                 +add esp, 0x10
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
    // 00457d7b  eb44                   -jmp 0x457dc1
    goto L_0x00457dc1;
L_0x00457d7d:
    // 00457d7d  807e4c02               +cmp byte ptr [esi + 0x4c], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00457d81  7524                   -jne 0x457da7
    if (!cpu.flags.zf)
    {
        goto L_0x00457da7;
    }
    // 00457d83  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00457d86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457d88  741d                   -je 0x457da7
    if (cpu.flags.zf)
    {
        goto L_0x00457da7;
    }
    // 00457d8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457d8b  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00457d8e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00457d90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457d91  68109b5300             -push 0x539b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479184 /*0x539b10*/;
    cpu.esp -= 4;
    // 00457d96  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457d9d  e8ee780800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457da2  83c410                 +add esp, 0x10
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
    // 00457da5  eb1a                   -jmp 0x457dc1
    goto L_0x00457dc1;
L_0x00457da7:
    // 00457da7  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00457daa  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00457dac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457dad  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 00457db2  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457db8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457db9  e8d2780800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457dbe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00457dc1:
    // 00457dc1  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00457dc4  8b55f2                 -mov edx, dword ptr [ebp - 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00457dc7  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00457dca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457dcb  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00457dd0  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00457dd6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00457dd8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00457ddb  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00457dde  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00457de0  e8aba3ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00457de5:
    // 00457de5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00457de7:
    // 00457de7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457de9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457dea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457deb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457dec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457ded  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_457df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457df2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457df3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457df5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457df6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457df7  681c9b5300             -push 0x539b1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479196 /*0x539b1c*/;
    cpu.esp -= 4;
    // 00457dfc  6894985500             -push 0x559894
    app->getMemory<x86::reg32>(cpu.esp-4) = 5609620 /*0x559894*/;
    cpu.esp -= 4;
    // 00457e01  e88a780800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457e06  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00457e09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00457e0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00457e0d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00457e0f  b99c995500             -mov ecx, 0x55999c
    cpu.ecx = 5609884 /*0x55999c*/;
    // 00457e14  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00457e19  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00457e1b  ba94995500             -mov edx, 0x559994
    cpu.edx = 5609876 /*0x559994*/;
    // 00457e20  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00457e25  e8a6c8feff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00457e2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457e2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457e2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457e2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_457e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457e31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457e32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457e33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457e34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457e36  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00457e39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457e3b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00457e3d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00457e3f  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00457e44  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00457e47  e81428ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457e4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457e4e  0f8410010000           -je 0x457f64
    if (cpu.flags.zf)
    {
        goto L_0x00457f64;
    }
    // 00457e54  668b4140               -mov ax, word ptr [ecx + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00457e58  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00457e5a  8d5160                 -lea edx, [ecx + 0x60]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 00457e5d  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00457e60  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00457e63  0f86be000000           -jbe 0x457f27
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457f27;
    }
    // 00457e69  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457e6d  0f85ef000000           -jne 0x457f62
    if (!cpu.flags.zf)
    {
        goto L_0x00457f62;
    }
    // 00457e73  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457e77  0f8283000000           -jb 0x457f00
    if (cpu.flags.cf)
    {
        goto L_0x00457f00;
    }
    // 00457e7d  760b                   -jbe 0x457e8a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457e8a;
    }
    // 00457e7f  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457e83  7462                   -je 0x457ee7
    if (cpu.flags.zf)
    {
        goto L_0x00457ee7;
    }
    // 00457e85  e976000000             -jmp 0x457f00
    goto L_0x00457f00;
L_0x00457e8a:
    // 00457e8a  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00457e8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457e8e  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 00457e93  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00457e99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457e9a  89795c                 -mov dword ptr [ecx + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 00457e9d  e8a6860900             -call 0x4f0548
    cpu.esp -= 4;
    sub_4f0548(app, cpu);
    if (cpu.terminate) return;
    // 00457ea2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00457ea4  8a6142                 -mov ah, byte ptr [ecx + 0x42]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(66) /* 0x42 */);
    // 00457ea7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00457eaa  80fc01                 +cmp ah, 1
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
    // 00457ead  751a                   -jne 0x457ec9
    if (!cpu.flags.zf)
    {
        goto L_0x00457ec9;
    }
    // 00457eaf  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00457eb2  3b4144                 +cmp eax, dword ptr [ecx + 0x44]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457eb5  7c05                   -jl 0x457ebc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00457ebc;
    }
    // 00457eb7  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
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
    // 00457eba  7e0d                   -jle 0x457ec9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00457ec9;
    }
L_0x00457ebc:
    // 00457ebc  8b5348                 -mov edx, dword ptr [ebx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00457ebf  8b4344                 -mov eax, dword ptr [ebx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */);
    // 00457ec2  e829ffffff             -call 0x457df0
    cpu.esp -= 4;
    sub_457df0(app, cpu);
    if (cpu.terminate) return;
    // 00457ec7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00457ec9:
    // 00457ec9  83fa01                 +cmp edx, 1
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
    // 00457ecc  7513                   -jne 0x457ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00457ee1;
    }
    // 00457ece  8b5358                 -mov edx, dword ptr [ebx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00457ed1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00457ed4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00457ed6  837b6c00               +cmp dword ptr [ebx + 0x6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(108) /* 0x6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457eda  7405                   -je 0x457ee1
    if (cpu.flags.zf)
    {
        goto L_0x00457ee1;
    }
    // 00457edc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00457ede  ff536c                 -call dword ptr [ebx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00457ee1:
    // 00457ee1  806305fb               +and byte ptr [ebx + 5], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 00457ee5  eb32                   -jmp 0x457f19
    goto L_0x00457f19;
L_0x00457ee7:
    // 00457ee7  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00457eed  8a7105                 -mov dh, byte ptr [ecx + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00457ef0  89795c                 -mov dword ptr [ecx + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 00457ef3  80e6fb                 +and dh, 0xfb
    cpu.clear_co();
    cpu.set_szp((cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 00457ef6  887105                 -mov byte ptr [ecx + 5], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dh;
    // 00457ef9  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457efe  eb62                   -jmp 0x457f62
    goto L_0x00457f62;
L_0x00457f00:
    // 00457f00  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00457f02  8d435c                 -lea eax, [ebx + 0x5c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 00457f05  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00457f0a  8d7b60                 -lea edi, [ebx + 0x60]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 00457f0d  0fbfce                 -movsx ecx, si
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 00457f10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00457f12  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00457f14  e8c7fbffff             -call 0x457ae0
    cpu.esp -= 4;
    sub_457ae0(app, cpu);
    if (cpu.terminate) return;
L_0x00457f19:
    // 00457f19  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457f1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00457f20  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457f22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457f27:
    // 00457f27  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457f2b  7535                   -jne 0x457f62
    if (!cpu.flags.zf)
    {
        goto L_0x00457f62;
    }
    // 00457f2d  83795800               +cmp dword ptr [ecx + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457f31  7509                   -jne 0x457f3c
    if (!cpu.flags.zf)
    {
        goto L_0x00457f3c;
    }
    // 00457f33  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00457f35  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457f37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457f3c:
    // 00457f3c  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00457f41  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00457f44  66c741400100           -mov word ptr [ecx + 0x40], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 00457f4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00457f4c  89795c                 -mov dword ptr [ecx + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 00457f4f  e8ec860800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00457f54  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00457f57  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00457f5a  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457f5f  885905                 -mov byte ptr [ecx + 5], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.bl;
L_0x00457f62:
    // 00457f62  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00457f64:
    // 00457f64  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00457f66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457f6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_457f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457f71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457f72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457f73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457f74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457f75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457f76  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457f78  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00457f7b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457f7d  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00457f82  e8d926ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457f87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457f89  0f8475000000           -je 0x458004
    if (cpu.flags.zf)
    {
        goto L_0x00458004;
    }
    // 00457f8f  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457f93  66c741201d00           -mov word ptr [ecx + 0x20], 0x1d
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 29 /*0x1d*/;
    // 00457f99  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457f9d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00457f9f  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00457fa3  8b513c                 -mov edx, dword ptr [ecx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 00457fa6  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00457faa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00457fac  740e                   -je 0x457fbc
    if (cpu.flags.zf)
    {
        goto L_0x00457fbc;
    }
    // 00457fae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00457fb0  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00457fb5  e866a0ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00457fba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00457fbc:
    // 00457fbc  8b4b58                 -mov ecx, dword ptr [ebx + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00457fbf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00457fc1  7434                   -je 0x457ff7
    if (cpu.flags.zf)
    {
        goto L_0x00457ff7;
    }
    // 00457fc3  66837b4000             +cmp word ptr [ebx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457fc8  740a                   -je 0x457fd4
    if (cpu.flags.zf)
    {
        goto L_0x00457fd4;
    }
    // 00457fca  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00457fcf  8d4360                 -lea eax, [ebx + 0x60]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 00457fd2  eb1c                   -jmp 0x457ff0
    goto L_0x00457ff0;
L_0x00457fd4:
    // 00457fd4  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00457fd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457fd7  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 00457fdc  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00457fdf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00457fe0  e8ab760800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00457fe5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00457fe8  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00457fed  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00457ff0:
    // 00457ff0  e82ba0ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00457ff5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00457ff7:
    // 00457ff7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00457ff9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00457ffb  050a000000             -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00458000  6689431e               -mov word ptr [ebx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x00458004:
    // 00458004  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00458006  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458007  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458008  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458009  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045800a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045800b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045800c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_458010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458011  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458012  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458013  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458014  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458016  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458018  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0045801d  e83e26ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458022  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458024  7423                   -je 0x458049
    if (cpu.flags.zf)
    {
        goto L_0x00458049;
    }
    // 00458026  668b5940               -mov bx, word ptr [ecx + 0x40]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0045802a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045802c  6683fb01               +cmp bx, 1
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00458030  7506                   -jne 0x458038
    if (!cpu.flags.zf)
    {
        goto L_0x00458038;
    }
    // 00458032  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00458038:
    // 00458038  837a6c00               +cmp dword ptr [edx + 0x6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045803c  740b                   -je 0x458049
    if (cpu.flags.zf)
    {
        goto L_0x00458049;
    }
    // 0045803e  837a5800               +cmp dword ptr [edx + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00458042  7405                   -je 0x458049
    if (cpu.flags.zf)
    {
        goto L_0x00458049;
    }
    // 00458044  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00458046  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00458049:
    // 00458049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045804a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045804b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045804c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045804d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_458050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458050  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458051  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458052  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458053  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458055  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458057  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0045805c  e8ff25ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458061  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458063  740d                   -je 0x458072
    if (cpu.flags.zf)
    {
        goto L_0x00458072;
    }
    // 00458065  6683794001             +cmp word ptr [ecx + 0x40], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045806a  7506                   -jne 0x458072
    if (!cpu.flags.zf)
    {
        goto L_0x00458072;
    }
    // 0045806c  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00458072:
    // 00458072  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458073  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458074  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458075  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_458080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458082  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458083  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458085  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458087  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00458089  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0045808e  e8cd25ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458095  740b                   -je 0x4580a2
    if (cpu.flags.zf)
    {
        goto L_0x004580a2;
    }
    // 00458097  89596c                 -mov dword ptr [ecx + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 0045809a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045809f  897158                 -mov dword ptr [ecx + 0x58], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.esi;
L_0x004580a2:
    // 004580a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004580a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004580a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004580a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4580b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004580b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004580b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004580b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004580b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004580b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004580b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004580b7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004580ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004580bc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004580be  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 004580c3  e89825ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004580c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004580ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004580cc  750c                   -jne 0x4580da
    if (!cpu.flags.zf)
    {
        goto L_0x004580da;
    }
    // 004580ce  e913010000             -jmp 0x4581e6
    goto L_0x004581e6;
    // 004580d3  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 004580d8  eb10                   -jmp 0x4580ea
    goto L_0x004580ea;
L_0x004580da:
    // 004580da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004580dc  7407                   -je 0x4580e5
    if (cpu.flags.zf)
    {
        goto L_0x004580e5;
    }
    // 004580de  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
    // 004580e3  eb05                   -jmp 0x4580ea
    goto L_0x004580ea;
L_0x004580e5:
    // 004580e5  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
L_0x004580ea:
    // 004580ea  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004580ee  668945f8               -mov word ptr [ebp - 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
    // 004580f2  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004580f6  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 004580fa  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004580ff  e8fc9fffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00458104  8b563c                 -mov edx, dword ptr [esi + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00458107  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00458109  742d                   -je 0x458138
    if (cpu.flags.zf)
    {
        goto L_0x00458138;
    }
    // 0045810b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045810d  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00458112  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00458117  e8049fffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0045811c  8b55fa                 -mov edx, dword ptr [ebp - 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0045811f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00458122  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458123  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00458126  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458129  8b5df6                 -mov ebx, dword ptr [ebp - 0xa]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0045812c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045812d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458130  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00458133  e858a0ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00458138:
    // 00458138  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0045813b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045813e  050a000000             -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00458143  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00458145  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00458148  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 0045814c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045814e  0f8490000000           -je 0x4581e4
    if (cpu.flags.zf)
    {
        goto L_0x004581e4;
    }
    // 00458154  66837e4000             +cmp word ptr [esi + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00458159  746e                   -je 0x4581c9
    if (cpu.flags.zf)
    {
        goto L_0x004581c9;
    }
    // 0045815b  8b45f6                 -mov eax, dword ptr [ebp - 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0045815e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00458161  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00458166  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00458169  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0045816c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045816d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00458170  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458172  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00458175  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00458178  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0045817b  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0045817e  e80da0ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00458183  8b5640                 -mov edx, dword ptr [esi + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 00458186  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458189  42                     -inc edx
    (cpu.edx)++;
    // 0045818a  bb1e000000             -mov ebx, 0x1e
    cpu.ebx = 30 /*0x1e*/;
    // 0045818f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00458191  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00458194  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00458196  66895642               -mov word ptr [esi + 0x42], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = cpu.dx;
    // 0045819a  6683fa0f               +cmp dx, 0xf
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(15 /*0xf*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045819e  7d44                   -jge 0x4581e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004581e4;
    }
    // 004581a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004581a1  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004581a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004581a8  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004581ab  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004581b0  e86b9effff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004581b5  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004581b8  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004581bb  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004581bd  b8389b5300             -mov eax, 0x539b38
    cpu.eax = 5479224 /*0x539b38*/;
    // 004581c2  e8c99fffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 004581c7  eb1b                   -jmp 0x4581e4
    goto L_0x004581e4;
L_0x004581c9:
    // 004581c9  8b5df6                 -mov ebx, dword ptr [ebp - 0xa]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 004581cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004581cd  8b55fa                 -mov edx, dword ptr [ebp - 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004581d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004581d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004581d4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004581d9  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004581dc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004581df  e8ac9fffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x004581e4:
    // 004581e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004581e6:
    // 004581e6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004581e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004581e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004581ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004581eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004581ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004581ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4581f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004581f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004581f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004581f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004581f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004581f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004581f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004581f8  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 004581fd  e85e24ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458202  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00458204  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458206  0f8421010000           -je 0x45832d
    if (cpu.flags.zf)
    {
        goto L_0x0045832d;
    }
    // 0045820c  668b4140               -mov ax, word ptr [ecx + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00458210  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00458212  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00458215  0f86be000000           -jbe 0x4582d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004582d9;
    }
    // 0045821b  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045821f  0f8506010000           -jne 0x45832b
    if (!cpu.flags.zf)
    {
        goto L_0x0045832b;
    }
    // 00458225  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00458229  721a                   -jb 0x458245
    if (cpu.flags.cf)
    {
        goto L_0x00458245;
    }
    // 0045822b  7620                   -jbe 0x45824d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045824d;
    }
    // 0045822d  6683fb1b               +cmp bx, 0x1b
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00458231  0f8271000000           -jb 0x4582a8
    if (cpu.flags.cf)
    {
        goto L_0x004582a8;
    }
    // 00458237  7643                   -jbe 0x45827c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045827c;
    }
    // 00458239  6681fb0053             +cmp bx, 0x5300
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21248 /*0x5300*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045823e  744d                   -je 0x45828d
    if (cpu.flags.zf)
    {
        goto L_0x0045828d;
    }
    // 00458240  e963000000             -jmp 0x4582a8
    goto L_0x004582a8;
L_0x00458245:
    // 00458245  6683fb08               +cmp bx, 8
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00458249  7442                   -je 0x45828d
    if (cpu.flags.zf)
    {
        goto L_0x0045828d;
    }
    // 0045824b  eb5b                   -jmp 0x4582a8
    goto L_0x004582a8;
L_0x0045824d:
    // 0045824d  8b5144                 -mov edx, dword ptr [ecx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00458250  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00458256  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00458258  7411                   -je 0x45826b
    if (cpu.flags.zf)
    {
        goto L_0x0045826b;
    }
    // 0045825a  8b594a                 -mov ebx, dword ptr [ecx + 0x4a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(74) /* 0x4a */);
    // 0045825d  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00458260  8b4144                 -mov eax, dword ptr [ecx + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00458263  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458266  e8c58b0800             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
L_0x0045826b:
    // 0045826b  837e5000               +cmp dword ptr [esi + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045826f  7405                   -je 0x458276
    if (cpu.flags.zf)
    {
        goto L_0x00458276;
    }
    // 00458271  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00458273  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00458276:
    // 00458276  806605fb               +and byte ptr [esi + 5], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 0045827a  eb51                   -jmp 0x4582cd
    goto L_0x004582cd;
L_0x0045827c:
    // 0045827c  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0045827f  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00458285  80e2fb                 +and dl, 0xfb
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 00458288  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0045828b  eb40                   -jmp 0x4582cd
    goto L_0x004582cd;
L_0x0045828d:
    // 0045828d  8b7e48                 -mov edi, dword ptr [esi + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00458290  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00458292  49                     -dec ecx
    (cpu.ecx)--;
    // 00458293  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00458295  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00458297  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00458299  49                     -dec ecx
    (cpu.ecx)--;
    // 0045829a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045829c  742f                   -je 0x4582cd
    if (cpu.flags.zf)
    {
        goto L_0x004582cd;
    }
    // 0045829e  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004582a1  c64401ff00             -mov byte ptr [ecx + eax - 1], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 004582a6  eb25                   -jmp 0x4582cd
    goto L_0x004582cd;
L_0x004582a8:
    // 004582a8  8b7e48                 -mov edi, dword ptr [esi + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004582ab  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004582ad  49                     -dec ecx
    (cpu.ecx)--;
    // 004582ae  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004582b0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004582b2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004582b4  49                     -dec ecx
    (cpu.ecx)--;
    // 004582b5  8b464a                 -mov eax, dword ptr [esi + 0x4a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(74) /* 0x4a */);
    // 004582b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004582bb  39c1                   +cmp ecx, eax
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
    // 004582bd  7d0e                   -jge 0x4582cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004582cd;
    }
    // 004582bf  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004582c2  881c01                 -mov byte ptr [ecx + eax], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = cpu.bl;
    // 004582c5  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004582c8  c644010100             -mov byte ptr [ecx + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
L_0x004582cd:
    // 004582cd  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004582d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004582d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004582d9:
    // 004582d9  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004582dd  754c                   -jne 0x45832b
    if (!cpu.flags.zf)
    {
        goto L_0x0045832b;
    }
    // 004582df  83794800               +cmp dword ptr [ecx + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004582e3  7507                   -jne 0x4582ec
    if (!cpu.flags.zf)
    {
        goto L_0x004582ec;
    }
    // 004582e5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004582e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004582eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004582ec:
    // 004582ec  8b5144                 -mov edx, dword ptr [ecx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 004582ef  66c741400100           -mov word ptr [ecx + 0x40], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 004582f5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004582f7  7411                   -je 0x45830a
    if (cpu.flags.zf)
    {
        goto L_0x0045830a;
    }
    // 004582f9  8b594a                 -mov ebx, dword ptr [ecx + 0x4a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(74) /* 0x4a */);
    // 004582fc  c1fb10                 +sar ebx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004582ff  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00458302  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00458303  e8288b0800             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00458308  eb05                   -jmp 0x45830f
    goto L_0x0045830f;
L_0x0045830a:
    // 0045830a  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0045830d  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x0045830f:
    // 0045830f  8b564a                 -mov edx, dword ptr [esi + 0x4a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(74) /* 0x4a */);
    // 00458312  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00458315  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458318  c64402ff00             -mov byte ptr [edx + eax - 1], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 0045831d  8a7605                 -mov dh, byte ptr [esi + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00458320  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00458323  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00458328  887605                 -mov byte ptr [esi + 5], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.dh;
L_0x0045832b:
    // 0045832b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0045832d:
    // 0045832d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045832e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045832f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458330  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458331  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_458340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458343  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458344  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458345  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458347  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458349  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0045834e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00458350  e80b23ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458355  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458357  744d                   -je 0x4583a6
    if (cpu.flags.zf)
    {
        goto L_0x004583a6;
    }
    // 00458359  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045835d  66c741201d00           -mov word ptr [ecx + 0x20], 0x1d
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 29 /*0x1d*/;
    // 00458363  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00458367  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0045836b  8b513c                 -mov edx, dword ptr [ecx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 0045836e  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00458372  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00458374  740e                   -je 0x458384
    if (cpu.flags.zf)
    {
        goto L_0x00458384;
    }
    // 00458376  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00458378  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045837d  e89e9cffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00458382  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00458384:
    // 00458384  8b4b44                 -mov ecx, dword ptr [ebx + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */);
    // 00458387  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00458389  740e                   -je 0x458399
    if (cpu.flags.zf)
    {
        goto L_0x00458399;
    }
    // 0045838b  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00458390  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00458392  e8899cffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00458397  eb02                   -jmp 0x45839b
    goto L_0x0045839b;
L_0x00458399:
    // 00458399  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045839b:
    // 0045839b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045839d  050a000000             -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004583a2  6689431e               -mov word ptr [ebx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x004583a6:
    // 004583a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4583b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004583b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004583b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004583b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004583b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004583b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004583b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004583b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004583b9  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 004583be  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004583c0  e89b22ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004583c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004583c7  7432                   -je 0x4583fb
    if (cpu.flags.zf)
    {
        goto L_0x004583fb;
    }
    // 004583c9  6683794001             +cmp word ptr [ecx + 0x40], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004583ce  7506                   -jne 0x4583d6
    if (!cpu.flags.zf)
    {
        goto L_0x004583d6;
    }
    // 004583d0  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x004583d6:
    // 004583d6  66837e4c00             +cmp word ptr [esi + 0x4c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(76) /* 0x4c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004583db  7506                   -jne 0x4583e3
    if (!cpu.flags.zf)
    {
        goto L_0x004583e3;
    }
    // 004583dd  66c7464c0b00           -mov word ptr [esi + 0x4c], 0xb
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(76) /* 0x4c */) = 11 /*0xb*/;
L_0x004583e3:
    // 004583e3  8b464a                 -mov eax, dword ptr [esi + 0x4a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(74) /* 0x4a */);
    // 004583e6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004583e9  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004583ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004583ee  b83c9b5300             -mov eax, 0x539b3c
    cpu.eax = 5479228 /*0x539b3c*/;
    // 004583f3  e828920800             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004583f8  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x004583fb:
    // 004583fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004583ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458400  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_458410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458412  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458413  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458414  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458416  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458418  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0045841d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045841f  e83c22ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458424  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458426  7422                   -je 0x45844a
    if (cpu.flags.zf)
    {
        goto L_0x0045844a;
    }
    // 00458428  6683794001             +cmp word ptr [ecx + 0x40], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045842d  7506                   -jne 0x458435
    if (!cpu.flags.zf)
    {
        goto L_0x00458435;
    }
    // 0045842f  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00458435:
    // 00458435  8b5348                 -mov edx, dword ptr [ebx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00458438  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045843a  740e                   -je 0x45844a
    if (cpu.flags.zf)
    {
        goto L_0x0045844a;
    }
    // 0045843c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045843e  e84d940800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00458443  c7434800000000         -mov dword ptr [ebx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
L_0x0045844a:
    // 0045844a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045844b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045844c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045844d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045844e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_458450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458450  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458451  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458452  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458453  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458455  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00458457  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00458459  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0045845e  e8fd21ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458463  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458465  740f                   -je 0x458476
    if (cpu.flags.zf)
    {
        goto L_0x00458476;
    }
    // 00458467  895e50                 -mov dword ptr [esi + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 0045846a  66894e4c               -mov word ptr [esi + 0x4c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.cx;
    // 0045846e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00458473  897e44                 -mov dword ptr [esi + 0x44], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.edi;
L_0x00458476:
    // 00458476  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458478  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458479  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_458480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458482  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458483  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458484  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458485  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458487  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0045848d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045848f  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00458492  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00458497  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0045849d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045849f  bee0774500             -mov esi, 0x4577e0
    cpu.esi = 4552672 /*0x4577e0*/;
    // 004584a4  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 004584a8  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 004584ad  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004584af  e8ac21ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004584b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004584b6  0f847a010000           -je 0x458636
    if (cpu.flags.zf)
    {
        goto L_0x00458636;
    }
    // 004584bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004584be  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004584c2  740e                   -je 0x4584d2
    if (cpu.flags.zf)
    {
        goto L_0x004584d2;
    }
    // 004584c4  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
    // 004584c9  eb0c                   -jmp 0x4584d7
    goto L_0x004584d7;
    // 004584cb  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 004584d0  eb05                   -jmp 0x4584d7
    goto L_0x004584d7;
L_0x004584d2:
    // 004584d2  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
L_0x004584d7:
    // 004584d7  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004584db  668945f4               -mov word ptr [ebp - 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ax;
    // 004584df  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004584e3  668945f8               -mov word ptr [ebp - 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
    // 004584e7  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004584ec  e80f9cffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004584f1  8b4e3c                 -mov ecx, dword ptr [esi + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004584f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004584f6  7430                   -je 0x458528
    if (cpu.flags.zf)
    {
        goto L_0x00458528;
    }
    // 004584f8  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004584fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004584ff  8b5df2                 -mov ebx, dword ptr [ebp - 0xe]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00458502  e8199bffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00458507  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0045850a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045850f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00458512  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00458515  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458516  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00458519  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0045851c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045851d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458520  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00458523  e8689cffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00458528:
    // 00458528  837e5000               +cmp dword ptr [esi + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045852c  0f8402010000           -je 0x458634
    if (cpu.flags.zf)
    {
        goto L_0x00458634;
    }
    // 00458532  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 00458536  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00458539  7658                   -jbe 0x458593
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00458593;
    }
    // 0045853b  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045853f  7552                   -jne 0x458593
    if (!cpu.flags.zf)
    {
        goto L_0x00458593;
    }
    // 00458541  8d4658                 -lea eax, [esi + 0x58]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00458544  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458545  680c9b5300             -push 0x539b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479180 /*0x539b0c*/;
    cpu.esp -= 4;
    // 0045854a  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458550  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458551  e83a710800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458556  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00458559  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0045855b  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00458560  8b5df2                 -mov ebx, dword ptr [ebp - 0xe]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00458563  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00458566  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00458568  8b7e54                 -mov edi, dword ptr [esi + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0045856b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00458570  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458571  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458574  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00458579  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045857c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0045857f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458581  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00458583  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458589  e8929cffff             -call 0x452220
    cpu.esp -= 4;
    sub_452220(app, cpu);
    if (cpu.terminate) return;
    // 0045858e  e9a1000000             -jmp 0x458634
    goto L_0x00458634;
L_0x00458593:
    // 00458593  807e4501               +cmp byte ptr [esi + 0x45], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(69) /* 0x45 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00458597  7529                   -jne 0x4585c2
    if (!cpu.flags.zf)
    {
        goto L_0x004585c2;
    }
    // 00458599  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0045859c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045859e  7422                   -je 0x4585c2
    if (cpu.flags.zf)
    {
        goto L_0x004585c2;
    }
    // 004585a0  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004585a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004585a4  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004585a6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004585ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004585ac  68109b5300             -push 0x539b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479184 /*0x539b10*/;
    cpu.esp -= 4;
    // 004585b1  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 004585b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004585b8  e8d3700800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004585bd  83c410                 +add esp, 0x10
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
    // 004585c0  eb4e                   -jmp 0x458610
    goto L_0x00458610;
L_0x004585c2:
    // 004585c2  807e4502               +cmp byte ptr [esi + 0x45], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(69) /* 0x45 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004585c6  7529                   -jne 0x4585f1
    if (!cpu.flags.zf)
    {
        goto L_0x004585f1;
    }
    // 004585c8  8b5e4c                 -mov ebx, dword ptr [esi + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004585cb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004585cd  7422                   -je 0x4585f1
    if (cpu.flags.zf)
    {
        goto L_0x004585f1;
    }
    // 004585cf  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004585d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004585d3  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004585d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004585da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004585db  68109b5300             -push 0x539b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479184 /*0x539b10*/;
    cpu.esp -= 4;
    // 004585e0  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 004585e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004585e7  e8a4700800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004585ec  83c410                 +add esp, 0x10
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
    // 004585ef  eb1f                   -jmp 0x458610
    goto L_0x00458610;
L_0x004585f1:
    // 004585f1  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004585f4  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004585f6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004585fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004585fc  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 00458601  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458607  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458608  e883700800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045860d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00458610:
    // 00458610  8b5df2                 -mov ebx, dword ptr [ebp - 0xe]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00458613  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00458616  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458617  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0045861a  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458620  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458622  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458625  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458628  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045862a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045862f  e85c9bffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00458634:
    // 00458634  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00458636:
    // 00458636  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00458638  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045863a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045863b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045863c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045863d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_458640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458642  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458643  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458645  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045864b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045864c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045864e  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00458650  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458651  681c9b5300             -push 0x539b1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479196 /*0x539b1c*/;
    cpu.esp -= 4;
    // 00458656  6894985500             -push 0x559894
    app->getMemory<x86::reg32>(cpu.esp-4) = 5609620 /*0x559894*/;
    cpu.esp -= 4;
    // 0045865b  e830700800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458660  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00458663  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458665  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458667  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00458669  b99c995500             -mov ecx, 0x55999c
    cpu.ecx = 5609884 /*0x55999c*/;
    // 0045866e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00458673  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458675  ba94995500             -mov edx, 0x559994
    cpu.edx = 5609876 /*0x559994*/;
    // 0045867a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045867f  e84cc0feff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00458684  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458686  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458687  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_458690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458691  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458692  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458693  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458694  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458696  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458699  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045869b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045869d  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0045869f  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 004586a4  8865fc                 -mov byte ptr [ebp - 4], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ah;
    // 004586a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004586a9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004586ab  e8b01fffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004586b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004586b2  0f841f010000           -je 0x4587d7
    if (cpu.flags.zf)
    {
        goto L_0x004587d7;
    }
    // 004586b8  668b4140               -mov ax, word ptr [ecx + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004586bc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004586be  8d5158                 -lea edx, [ecx + 0x58]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004586c1  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004586c4  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004586c7  0f86cd000000           -jbe 0x45879a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045879a;
    }
    // 004586cd  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004586d1  0f85fe000000           -jne 0x4587d5
    if (!cpu.flags.zf)
    {
        goto L_0x004587d5;
    }
    // 004586d7  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004586db  0f8292000000           -jb 0x458773
    if (cpu.flags.cf)
    {
        goto L_0x00458773;
    }
    // 004586e1  760b                   -jbe 0x4586ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004586ee;
    }
    // 004586e3  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004586e7  7465                   -je 0x45874e
    if (cpu.flags.zf)
    {
        goto L_0x0045874e;
    }
    // 004586e9  e985000000             -jmp 0x458773
    goto L_0x00458773;
L_0x004586ee:
    // 004586ee  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004586f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004586f2  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 004586f7  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 004586fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004586fe  897954                 -mov dword ptr [ecx + 0x54], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 00458701  e8427e0900             -call 0x4f0548
    cpu.esp -= 4;
    sub_4f0548(app, cpu);
    if (cpu.terminate) return;
    // 00458706  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00458708  8a4142                 -mov al, byte ptr [ecx + 0x42]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(66) /* 0x42 */);
    // 0045870b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045870e  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00458710  751e                   -jne 0x458730
    if (!cpu.flags.zf)
    {
        goto L_0x00458730;
    }
    // 00458712  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00458715  3a4143                 +cmp al, byte ptr [ecx + 0x43]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(67) /* 0x43 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00458718  7205                   -jb 0x45871f
    if (cpu.flags.cf)
    {
        goto L_0x0045871f;
    }
    // 0045871a  3a4144                 +cmp al, byte ptr [ecx + 0x44]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(68) /* 0x44 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045871d  7611                   -jbe 0x458730
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00458730;
    }
L_0x0045871f:
    // 0045871f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00458721  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00458723  8a5344                 -mov dl, byte ptr [ebx + 0x44]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(68) /* 0x44 */);
    // 00458726  8a4343                 -mov al, byte ptr [ebx + 0x43]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(67) /* 0x43 */);
    // 00458729  e812ffffff             -call 0x458640
    cpu.esp -= 4;
    sub_458640(app, cpu);
    if (cpu.terminate) return;
    // 0045872e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00458730:
    // 00458730  83fa01                 +cmp edx, 1
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
    // 00458733  7513                   -jne 0x458748
    if (!cpu.flags.zf)
    {
        goto L_0x00458748;
    }
    // 00458735  8b5350                 -mov edx, dword ptr [ebx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 00458738  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045873b  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0045873d  837b6000               +cmp dword ptr [ebx + 0x60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00458741  7405                   -je 0x458748
    if (cpu.flags.zf)
    {
        goto L_0x00458748;
    }
    // 00458743  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00458745  ff5360                 -call dword ptr [ebx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00458748:
    // 00458748  806305fb               +and byte ptr [ebx + 5], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 0045874c  eb3e                   -jmp 0x45878c
    goto L_0x0045878c;
L_0x0045874e:
    // 0045874e  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00458754  8a7105                 -mov dh, byte ptr [ecx + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00458757  897954                 -mov dword ptr [ecx + 0x54], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 0045875a  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0045875d  8b7960                 -mov edi, dword ptr [ecx + 0x60]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 00458760  887105                 -mov byte ptr [ecx + 5], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dh;
    // 00458763  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00458765  7425                   -je 0x45878c
    if (cpu.flags.zf)
    {
        goto L_0x0045878c;
    }
    // 00458767  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00458769  ff5360                 -call dword ptr [ebx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0045876c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00458771  eb62                   -jmp 0x4587d5
    goto L_0x004587d5;
L_0x00458773:
    // 00458773  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00458775  8d4354                 -lea eax, [ebx + 0x54]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 00458778  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0045877d  8d7b58                 -lea edi, [ebx + 0x58]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00458780  0fbfce                 -movsx ecx, si
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 00458783  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00458785  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00458787  e854f3ffff             -call 0x457ae0
    cpu.esp -= 4;
    sub_457ae0(app, cpu);
    if (cpu.terminate) return;
L_0x0045878c:
    // 0045878c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00458791  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00458793  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00458795  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458796  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458797  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458799  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045879a:
    // 0045879a  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045879e  7535                   -jne 0x4587d5
    if (!cpu.flags.zf)
    {
        goto L_0x004587d5;
    }
    // 004587a0  83795000               +cmp dword ptr [ecx + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004587a4  7509                   -jne 0x4587af
    if (!cpu.flags.zf)
    {
        goto L_0x004587af;
    }
    // 004587a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004587a8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004587aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004587af:
    // 004587af  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004587b4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004587b7  66c741400100           -mov word ptr [ecx + 0x40], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 004587bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004587bf  897954                 -mov dword ptr [ecx + 0x54], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 004587c2  e8797e0800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004587c7  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 004587ca  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004587cd  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004587d2  885905                 -mov byte ptr [ecx + 5], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.bl;
L_0x004587d5:
    // 004587d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004587d7:
    // 004587d7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004587d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004587dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4587e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004587e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004587e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004587e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004587e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004587e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004587e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004587e7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004587ea  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004587ec  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 004587f1  e86a1effff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004587f6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004587f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004587fa  0f8494000000           -je 0x458894
    if (cpu.flags.zf)
    {
        goto L_0x00458894;
    }
    // 00458800  8a6342                 -mov ah, byte ptr [ebx + 0x42]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(66) /* 0x42 */);
    // 00458803  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00458805  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00458807  7410                   -je 0x458819
    if (cpu.flags.zf)
    {
        goto L_0x00458819;
    }
    // 00458809  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045880e  8b433c                 -mov eax, dword ptr [ebx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */);
    // 00458811  e80a98ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00458816  8d700a                 -lea esi, [eax + 0xa]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(10) /* 0xa */);
L_0x00458819:
    // 00458819  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045881d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045881f  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00458823  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00458827  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0045882b  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00458830  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 00458833  66c741201d00           -mov word ptr [ecx + 0x20], 0x1d
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 29 /*0x1d*/;
    // 00458839  e8e297ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0045883e  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00458841  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00458843  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00458845  743e                   -je 0x458885
    if (cpu.flags.zf)
    {
        goto L_0x00458885;
    }
    // 00458847  6683794000             +cmp word ptr [ecx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045884c  740a                   -je 0x458858
    if (cpu.flags.zf)
    {
        goto L_0x00458858;
    }
    // 0045884e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00458853  8d4158                 -lea eax, [ecx + 0x58]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00458856  eb24                   -jmp 0x45887c
    goto L_0x0045887c;
L_0x00458858:
    // 00458858  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0045885b  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0045885d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00458862  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458863  68189b5300             -push 0x539b18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479192 /*0x539b18*/;
    cpu.esp -= 4;
    // 00458868  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045886b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045886c  e81f6e0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458871  83c40c                 +add esp, 0xc
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
    // 00458874  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00458879  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0045887c:
    // 0045887c  e89f97ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00458881  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00458883  eb02                   -jmp 0x458887
    goto L_0x00458887;
L_0x00458885:
    // 00458885  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00458887:
    // 00458887  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00458889  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045888b  050a000000             -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00458890  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x00458894:
    // 00458894  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00458896  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458897  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458898  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458899  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045889a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045889b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4588a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004588a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004588a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004588a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004588a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004588a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004588a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004588a8  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 004588ad  e8ae1dffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004588b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004588b4  7423                   -je 0x4588d9
    if (cpu.flags.zf)
    {
        goto L_0x004588d9;
    }
    // 004588b6  668b5940               -mov bx, word ptr [ecx + 0x40]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004588ba  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004588bc  6683fb01               +cmp bx, 1
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004588c0  7506                   -jne 0x4588c8
    if (!cpu.flags.zf)
    {
        goto L_0x004588c8;
    }
    // 004588c2  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x004588c8:
    // 004588c8  837a6000               +cmp dword ptr [edx + 0x60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004588cc  740b                   -je 0x4588d9
    if (cpu.flags.zf)
    {
        goto L_0x004588d9;
    }
    // 004588ce  837a5000               +cmp dword ptr [edx + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004588d2  7405                   -je 0x4588d9
    if (cpu.flags.zf)
    {
        goto L_0x004588d9;
    }
    // 004588d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004588d6  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004588d9:
    // 004588d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004588da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004588db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004588dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004588dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4588e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004588e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004588e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004588e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004588e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004588e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004588e7  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 004588ec  e86f1dffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004588f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004588f3  740d                   -je 0x458902
    if (cpu.flags.zf)
    {
        goto L_0x00458902;
    }
    // 004588f5  6683794001             +cmp word ptr [ecx + 0x40], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004588fa  7506                   -jne 0x458902
    if (!cpu.flags.zf)
    {
        goto L_0x00458902;
    }
    // 004588fc  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00458902:
    // 00458902  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458903  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458905  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_458910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458910  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458911  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458912  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458913  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458915  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00458917  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00458919  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 0045891e  e83d1dffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458923  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458925  740b                   -je 0x458932
    if (cpu.flags.zf)
    {
        goto L_0x00458932;
    }
    // 00458927  895960                 -mov dword ptr [ecx + 0x60], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.ebx;
    // 0045892a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045892f  897150                 -mov dword ptr [ecx + 0x50], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.esi;
L_0x00458932:
    // 00458932  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458933  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458934  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458935  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_458940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458942  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00458943  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458944  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458945  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458947  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0045894d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045894f  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00458952  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00458957  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0045895d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045895f  bee0784500             -mov esi, 0x4578e0
    cpu.esi = 4552928 /*0x4578e0*/;
    // 00458964  668955f4               -mov word ptr [ebp - 0xc], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.dx;
    // 00458968  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0045896d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045896f  e8ec1cffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00458974  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00458976  0f8492010000           -je 0x458b0e
    if (cpu.flags.zf)
    {
        goto L_0x00458b0e;
    }
    // 0045897c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045897e  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00458982  740e                   -je 0x458992
    if (cpu.flags.zf)
    {
        goto L_0x00458992;
    }
    // 00458984  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
    // 00458989  eb0c                   -jmp 0x458997
    goto L_0x00458997;
    // 0045898b  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 00458990  eb05                   -jmp 0x458997
    goto L_0x00458997;
L_0x00458992:
    // 00458992  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
L_0x00458997:
    // 00458997  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045899b  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 0045899f  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004589a3  668945f8               -mov word ptr [ebp - 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
    // 004589a7  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004589ac  e84f97ffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004589b1  8b4e3c                 -mov ecx, dword ptr [esi + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004589b4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004589b6  7430                   -je 0x4589e8
    if (cpu.flags.zf)
    {
        goto L_0x004589e8;
    }
    // 004589b8  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004589bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004589bf  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004589c2  e85996ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004589c7  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 004589ca  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004589cf  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004589d2  8b45f2                 -mov eax, dword ptr [ebp - 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 004589d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004589d6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004589d9  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004589dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004589dd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004589e0  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004589e3  e8a897ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x004589e8:
    // 004589e8  837e5800               +cmp dword ptr [esi + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004589ec  0f841a010000           -je 0x458b0c
    if (cpu.flags.zf)
    {
        goto L_0x00458b0c;
    }
    // 004589f2  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004589f6  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004589f9  7658                   -jbe 0x458a53
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00458a53;
    }
    // 004589fb  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004589ff  7552                   -jne 0x458a53
    if (!cpu.flags.zf)
    {
        goto L_0x00458a53;
    }
    // 00458a01  8d4664                 -lea eax, [esi + 0x64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 00458a04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458a05  680c9b5300             -push 0x539b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479180 /*0x539b0c*/;
    cpu.esp -= 4;
    // 00458a0a  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458a10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458a11  e87a6c0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458a16  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00458a19  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00458a1b  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00458a20  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00458a23  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00458a26  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00458a28  8b7e5c                 -mov edi, dword ptr [esi + 0x5c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00458a2b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00458a30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458a31  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458a34  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00458a39  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458a3c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00458a3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458a41  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00458a43  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458a49  e8d297ffff             -call 0x452220
    cpu.esp -= 4;
    sub_452220(app, cpu);
    if (cpu.terminate) return;
    // 00458a4e  e9b9000000             -jmp 0x458b0c
    goto L_0x00458b0c;
L_0x00458a53:
    // 00458a53  8b5660                 -mov edx, dword ptr [esi + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00458a56  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00458a58  7e09                   -jle 0x458a63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00458a63;
    }
    // 00458a5a  83fa06                 +cmp edx, 6
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
    // 00458a5d  7f04                   -jg 0x458a63
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00458a63;
    }
    // 00458a5f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00458a61  eb05                   -jmp 0x458a68
    goto L_0x00458a68;
L_0x00458a63:
    // 00458a63  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
L_0x00458a68:
    // 00458a68  807e4c01               +cmp byte ptr [esi + 0x4c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00458a6c  752a                   -jne 0x458a98
    if (!cpu.flags.zf)
    {
        goto L_0x00458a98;
    }
    // 00458a6e  8b5e50                 -mov ebx, dword ptr [esi + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00458a71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00458a73  7423                   -je 0x458a98
    if (cpu.flags.zf)
    {
        goto L_0x00458a98;
    }
    // 00458a75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458a76  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00458a79  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458a7c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00458a7e  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00458a81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458a82  68409b5300             -push 0x539b40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479232 /*0x539b40*/;
    cpu.esp -= 4;
    // 00458a87  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458a8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458a8e  e8fd6b0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458a93  83c418                 +add esp, 0x18
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
    // 00458a96  eb50                   -jmp 0x458ae8
    goto L_0x00458ae8;
L_0x00458a98:
    // 00458a98  807e4c02               +cmp byte ptr [esi + 0x4c], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00458a9c  752a                   -jne 0x458ac8
    if (!cpu.flags.zf)
    {
        goto L_0x00458ac8;
    }
    // 00458a9e  8b4e54                 -mov ecx, dword ptr [esi + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00458aa1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00458aa3  7423                   -je 0x458ac8
    if (cpu.flags.zf)
    {
        goto L_0x00458ac8;
    }
    // 00458aa5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458aa6  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00458aa9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458aac  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00458aae  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00458ab1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458ab2  68409b5300             -push 0x539b40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479232 /*0x539b40*/;
    cpu.esp -= 4;
    // 00458ab7  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458abd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458abe  e8cd6b0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458ac3  83c418                 +add esp, 0x18
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
    // 00458ac6  eb20                   -jmp 0x458ae8
    goto L_0x00458ae8;
L_0x00458ac8:
    // 00458ac8  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00458acb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458ace  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00458ad0  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00458ad3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458ad4  68489b5300             -push 0x539b48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479240 /*0x539b48*/;
    cpu.esp -= 4;
    // 00458ad9  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458adf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00458ae0  e8ab6b0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458ae5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00458ae8:
    // 00458ae8  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00458aeb  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00458aee  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00458af1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00458af2  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00458af7  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00458afd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458aff  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00458b02  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00458b05  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00458b07  e88496ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00458b0c:
    // 00458b0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00458b0e:
    // 00458b0e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00458b10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_458b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00458b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00458b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00458b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00458b23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00458b24  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00458b26  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458b29  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 00458b2c  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00458b2f  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00458b32  d94514                 -fld dword ptr [ebp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 00458b35  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00458b38  68509b5300             -push 0x539b50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479248 /*0x539b50*/;
    cpu.esp -= 4;
    // 00458b3d  6894985500             -push 0x559894
    app->getMemory<x86::reg32>(cpu.esp-4) = 5609620 /*0x559894*/;
    cpu.esp -= 4;
    // 00458b42  e8496b0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00458b47  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00458b4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458b4c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458b4e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00458b50  b99c995500             -mov ecx, 0x55999c
    cpu.ecx = 5609884 /*0x55999c*/;
    // 00458b55  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00458b5a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00458b5c  ba94995500             -mov edx, 0x559994
    cpu.edx = 5609876 /*0x559994*/;
    // 00458b61  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00458b66  e865bbfeff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00458b6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00458b6f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
