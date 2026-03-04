#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9b20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9b21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e9b23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9b25  7436                   -je 0x4e9b5d
    if (cpu.flags.zf)
    {
        goto L_0x004e9b5d;
    }
L_0x004e9b27:
    // 004e9b27  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004e9b2d  c64204ff               -mov byte ptr [edx + 4], 0xff
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) = 255 /*0xff*/;
    // 004e9b31  c642053c               -mov byte ptr [edx + 5], 0x3c
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5) /* 0x5 */) = 60 /*0x3c*/;
    // 004e9b35  c642067f               -mov byte ptr [edx + 6], 0x7f
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */) = 127 /*0x7f*/;
    // 004e9b39  c6420740               -mov byte ptr [edx + 7], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 004e9b3d  c642087f               -mov byte ptr [edx + 8], 0x7f
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004e9b41  c6420940               -mov byte ptr [edx + 9], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */) = 64 /*0x40*/;
    // 004e9b45  c6420a7f               -mov byte ptr [edx + 0xa], 0x7f
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */) = 127 /*0x7f*/;
    // 004e9b49  c6420b00               -mov byte ptr [edx + 0xb], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 004e9b4d  66c7420c0000           -mov word ptr [edx + 0xc], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004e9b53  66c7420e0000           -mov word ptr [edx + 0xe], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004e9b59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9b5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9b5d:
    // 004e9b5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9b5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9b5f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9b60  b990b35400             -mov ecx, 0x54b390
    cpu.ecx = 5550992 /*0x54b390*/;
    // 004e9b65  bba0b35400             -mov ebx, 0x54b3a0
    cpu.ebx = 5551008 /*0x54b3a0*/;
    // 004e9b6a  be37000000             -mov esi, 0x37
    cpu.esi = 55 /*0x37*/;
    // 004e9b6f  68b0b35400             -push 0x54b3b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551024 /*0x54b3b0*/;
    cpu.esp -= 4;
    // 004e9b74  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e9b7a  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e9b80  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e9b86  e88574f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9b8b  83c404                 +add esp, 4
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
    // 004e9b8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9b91  eb94                   -jmp 0x4e9b27
    goto L_0x004e9b27;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9ba1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9ba3  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004e9baa  7443                   -je 0x4e9bef
    if (cpu.flags.zf)
    {
        goto L_0x004e9bef;
    }
    // 004e9bac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9bad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e9baf  7532                   -jne 0x4e9be3
    if (!cpu.flags.zf)
    {
        goto L_0x004e9be3;
    }
    // 004e9bb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9bb2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9bb3  badcb35400             -mov edx, 0x54b3dc
    cpu.edx = 5551068 /*0x54b3dc*/;
    // 004e9bb8  bbe8b35400             -mov ebx, 0x54b3e8
    cpu.ebx = 5551080 /*0x54b3e8*/;
    // 004e9bbd  be9f000000             -mov esi, 0x9f
    cpu.esi = 159 /*0x9f*/;
    // 004e9bc2  68f0b35400             -push 0x54b3f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551088 /*0x54b3f0*/;
    cpu.esp -= 4;
    // 004e9bc7  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e9bcd  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e9bd3  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e9bd9  e83274f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9bde  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e9be1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9be2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e9be3:
    // 004e9be3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e9be5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9be7  e80c000000             -call 0x4e9bf8
    cpu.esp -= 4;
    sub_4e9bf8(app, cpu);
    if (cpu.terminate) return;
    // 004e9bec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9bed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9bee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9bef:
    // 004e9bef  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e9bf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9bf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e9bf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9bf8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9bf9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9bfa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9bfc  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e9bff  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004e9c02  e869890100             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 004e9c07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9c09  7c3e                   -jl 0x4e9c49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9c49;
    }
    // 004e9c0b  8b5101                 -mov edx, dword ptr [ecx + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004e9c0e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004e9c11  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e9c18  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9c1a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e9c1c  8b04853ca1a000         -mov eax, dword ptr [eax*4 + 0xa0a13c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4);
    // 004e9c23  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9c25  7c22                   -jl 0x4e9c49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9c49;
    }
    // 004e9c27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9c29  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004e9c2b  668b5006               -mov dx, word ptr [eax + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004e9c2f  39da                   +cmp edx, ebx
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
    // 004e9c31  7e16                   -jle 0x4e9c49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9c49;
    }
    // 004e9c33  80780404               +cmp byte ptr [eax + 4], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9c37  7518                   -jne 0x4e9c51
    if (!cpu.flags.zf)
    {
        goto L_0x004e9c51;
    }
    // 004e9c39  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e9c3b  8b449014               -mov eax, dword ptr [eax + edx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 4);
    // 004e9c3f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e9c41  e8a2810100             -call 0x501de8
    cpu.esp -= 4;
    sub_501de8(app, cpu);
    if (cpu.terminate) return;
    // 004e9c46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9c49:
    // 004e9c49  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004e9c4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9c51:
    // 004e9c51  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e9c53  8b44900c               -mov eax, dword ptr [eax + edx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 004e9c57  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e9c59  e88a810100             -call 0x501de8
    cpu.esp -= 4;
    sub_501de8(app, cpu);
    if (cpu.terminate) return;
    // 004e9c5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9c60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9c70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9c71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9c72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9c73  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e9c75  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e9c77  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e9c79  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e9c7b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e9c7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9c81  7c05                   -jl 0x4e9c88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9c88;
    }
    // 004e9c83  83f801                 +cmp eax, 1
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
    // 004e9c86  7c2e                   -jl 0x4e9cb6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9cb6;
    }
L_0x004e9c88:
    // 004e9c88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9c89  ba1cb45400             -mov edx, 0x54b41c
    cpu.edx = 5551132 /*0x54b41c*/;
    // 004e9c8e  b82cb45400             -mov eax, 0x54b42c
    cpu.eax = 5551148 /*0x54b42c*/;
    // 004e9c93  683cb45400             -push 0x54b43c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551164 /*0x54b43c*/;
    cpu.esp -= 4;
    // 004e9c98  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e9c9e  ba52000000             -mov edx, 0x52
    cpu.edx = 82 /*0x52*/;
    // 004e9ca3  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e9ca8  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e9cae  e85d73f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9cb3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e9cb6:
    // 004e9cb6  83fbff                 +cmp ebx, -1
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
    // 004e9cb9  7558                   -jne 0x4e9d13
    if (!cpu.flags.zf)
    {
        goto L_0x004e9d13;
    }
    // 004e9cbb  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
L_0x004e9cc0:
    // 004e9cc0  83f9ff                 +cmp ecx, -1
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
    // 004e9cc3  0f8585000000           -jne 0x4e9d4e
    if (!cpu.flags.zf)
    {
        goto L_0x004e9d4e;
    }
    // 004e9cc9  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
L_0x004e9cce:
    // 004e9cce  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9cd0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004e9cd3  055ca2a000             -add eax, 0xa0a25c
    (cpu.eax) += x86::reg32(x86::sreg32(10527324 /*0xa0a25c*/));
    // 004e9cd8  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004e9cda  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e9cdd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e9cdf  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e9ce2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9ce4  e8c3930100             -call 0x5030ac
    cpu.esp -= 4;
    sub_5030ac(app, cpu);
    if (cpu.terminate) return;
    // 004e9ce9  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004e9cf0  0f84cb000000           -je 0x4e9dc1
    if (cpu.flags.zf)
    {
        goto L_0x004e9dc1;
    }
    // 004e9cf6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9cf8  0f8c90000000           -jl 0x4e9d8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9d8e;
    }
L_0x004e9cfe:
    // 004e9cfe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e9d00  7502                   -jne 0x4e9d04
    if (!cpu.flags.zf)
    {
        goto L_0x004e9d04;
    }
    // 004e9d02  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004e9d04:
    // 004e9d04  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e9d06  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e9d08  e8ef000000             -call 0x4e9dfc
    cpu.esp -= 4;
    sub_4e9dfc(app, cpu);
    if (cpu.terminate) return;
    // 004e9d0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9d0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9d0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9d10  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004e9d13:
    // 004e9d13  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e9d15  7c05                   -jl 0x4e9d1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9d1c;
    }
    // 004e9d17  83fb7f                 +cmp ebx, 0x7f
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
    // 004e9d1a  7ea4                   -jle 0x4e9cc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9cc0;
    }
L_0x004e9d1c:
    // 004e9d1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9d1d  b81cb45400             -mov eax, 0x54b41c
    cpu.eax = 5551132 /*0x54b41c*/;
    // 004e9d22  ba2cb45400             -mov edx, 0x54b42c
    cpu.edx = 5551148 /*0x54b42c*/;
    // 004e9d27  6868b45400             -push 0x54b468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551208 /*0x54b468*/;
    cpu.esp -= 4;
    // 004e9d2c  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e9d31  b85a000000             -mov eax, 0x5a
    cpu.eax = 90 /*0x5a*/;
    // 004e9d36  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e9d3c  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e9d41  e8ca72f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9d46  83c408                 +add esp, 8
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
    // 004e9d49  e972ffffff             -jmp 0x4e9cc0
    goto L_0x004e9cc0;
L_0x004e9d4e:
    // 004e9d4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e9d50  7c09                   -jl 0x4e9d5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9d5b;
    }
    // 004e9d52  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e9d55  0f8e73ffffff           -jle 0x4e9cce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9cce;
    }
L_0x004e9d5b:
    // 004e9d5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9d5c  ba1cb45400             -mov edx, 0x54b41c
    cpu.edx = 5551132 /*0x54b41c*/;
    // 004e9d61  b82cb45400             -mov eax, 0x54b42c
    cpu.eax = 5551148 /*0x54b42c*/;
    // 004e9d66  688cb45400             -push 0x54b48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551244 /*0x54b48c*/;
    cpu.esp -= 4;
    // 004e9d6b  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e9d71  ba62000000             -mov edx, 0x62
    cpu.edx = 98 /*0x62*/;
    // 004e9d76  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e9d7b  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e9d81  e88a72f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9d86  83c408                 +add esp, 8
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
    // 004e9d89  e940ffffff             -jmp 0x4e9cce
    goto L_0x004e9cce;
L_0x004e9d8e:
    // 004e9d8e  ba1cb45400             -mov edx, 0x54b41c
    cpu.edx = 5551132 /*0x54b41c*/;
    // 004e9d93  b92cb45400             -mov ecx, 0x54b42c
    cpu.ecx = 5551148 /*0x54b42c*/;
    // 004e9d98  bb74000000             -mov ebx, 0x74
    cpu.ebx = 116 /*0x74*/;
    // 004e9d9d  68b0b45400             -push 0x54b4b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551280 /*0x54b4b0*/;
    cpu.esp -= 4;
    // 004e9da2  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e9da8  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e9dae  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e9db4  e85772f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9db9  83c404                 +add esp, 4
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
    // 004e9dbc  e93dffffff             -jmp 0x4e9cfe
    goto L_0x004e9cfe;
L_0x004e9dc1:
    // 004e9dc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9dc3  0f8d35ffffff           -jge 0x4e9cfe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e9cfe;
    }
    // 004e9dc9  b91cb45400             -mov ecx, 0x54b41c
    cpu.ecx = 5551132 /*0x54b41c*/;
    // 004e9dce  bb2cb45400             -mov ebx, 0x54b42c
    cpu.ebx = 5551148 /*0x54b42c*/;
    // 004e9dd3  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 004e9dd8  68f8b45400             -push 0x54b4f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551352 /*0x54b4f8*/;
    cpu.esp -= 4;
    // 004e9ddd  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e9de3  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e9de9  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e9dee  e81d72f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9df3  83c404                 +add esp, 4
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
    // 004e9df6  e903ffffff             -jmp 0x4e9cfe
    goto L_0x004e9cfe;
}

/* align: skip 0x90 */
void Application::sub_4e9dfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9dfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9dfe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9dff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9e00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9e01  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e9e03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9e05  7c05                   -jl 0x4e9e0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9e0c;
    }
    // 004e9e07  83f801                 +cmp eax, 1
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
    // 004e9e0a  7c2f                   -jl 0x4e9e3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9e3b;
    }
L_0x004e9e0c:
    // 004e9e0c  b91cb45400             -mov ecx, 0x54b41c
    cpu.ecx = 5551132 /*0x54b41c*/;
    // 004e9e11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9e12  bb40b55400             -mov ebx, 0x54b540
    cpu.ebx = 5551424 /*0x54b540*/;
    // 004e9e17  bec2000000             -mov esi, 0xc2
    cpu.esi = 194 /*0xc2*/;
    // 004e9e1c  6854b55400             -push 0x54b554
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551444 /*0x54b554*/;
    cpu.esp -= 4;
    // 004e9e21  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e9e27  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e9e2d  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e9e33  e8d871f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9e38  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e9e3b:
    // 004e9e3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e9e3d  7c05                   -jl 0x4e9e44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9e44;
    }
    // 004e9e3f  83fa7f                 +cmp edx, 0x7f
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
    // 004e9e42  7e2e                   -jle 0x4e9e72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e9e72;
    }
L_0x004e9e44:
    // 004e9e44  bd1cb45400             -mov ebp, 0x54b41c
    cpu.ebp = 5551132 /*0x54b41c*/;
    // 004e9e49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9e4a  b840b55400             -mov eax, 0x54b540
    cpu.eax = 5551424 /*0x54b540*/;
    // 004e9e4f  b9c8000000             -mov ecx, 0xc8
    cpu.ecx = 200 /*0xc8*/;
    // 004e9e54  687cb55400             -push 0x54b57c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551484 /*0x54b57c*/;
    cpu.esp -= 4;
    // 004e9e59  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e9e5f  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e9e64  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004e9e6a  e8a171f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9e6f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e9e72:
    // 004e9e72  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e9e74  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004e9e77  899060a2a000           -mov dword ptr [eax + 0xa0a260], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10527328) /* 0xa0a260 */) = cpu.edx;
    // 004e9e7d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e9e7f  e840920100             -call 0x5030c4
    cpu.esp -= 4;
    sub_5030c4(app, cpu);
    if (cpu.terminate) return;
    // 004e9e84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9e86  7c28                   -jl 0x4e9eb0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9eb0;
    }
    // 004e9e88  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004e9e8a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e9e8c:
    // 004e9e8c  6bc160                 -imul eax, ecx, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004e9e8f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e9e91  8b9e729ba000           -mov ebx, dword ptr [esi + 0xa09b72]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10525554) /* 0xa09b72 */);
    // 004e9e97  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004e9e9a  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004e9e9d  8b803c9ba000           -mov eax, dword ptr [eax + 0xa09b3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525500) /* 0xa09b3c */);
    // 004e9ea3  41                     -inc ecx
    (cpu.ecx)++;
    // 004e9ea4  e827920100             -call 0x5030d0
    cpu.esp -= 4;
    sub_5030d0(app, cpu);
    if (cpu.terminate) return;
    // 004e9ea9  83f910                 +cmp ecx, 0x10
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
    // 004e9eac  7cde                   -jl 0x4e9e8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e9e8c;
    }
    // 004e9eae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e9eb0:
    // 004e9eb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9eb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9eb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9eb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9ec1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004e9ec3:
    // 004e9ec3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004e9ec5  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004e9ec7  3c41                   +cmp al, 0x41
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9ec9  7206                   -jb 0x4e9ed1
    if (cpu.flags.cf)
    {
        goto L_0x004e9ed1;
    }
    // 004e9ecb  3c5a                   +cmp al, 0x5a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9ecd  7702                   -ja 0x4e9ed1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e9ed1;
    }
    // 004e9ecf  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004e9ed1:
    // 004e9ed1  80fc41                 +cmp ah, 0x41
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9ed4  7208                   -jb 0x4e9ede
    if (cpu.flags.cf)
    {
        goto L_0x004e9ede;
    }
    // 004e9ed6  80fc5a                 +cmp ah, 0x5a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9ed9  7703                   -ja 0x4e9ede
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e9ede;
    }
    // 004e9edb  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004e9ede:
    // 004e9ede  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e9ee0  7508                   -jne 0x4e9eea
    if (!cpu.flags.zf)
    {
        goto L_0x004e9eea;
    }
    // 004e9ee2  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004e9ee4  7404                   -je 0x4e9eea
    if (cpu.flags.zf)
    {
        goto L_0x004e9eea;
    }
    // 004e9ee6  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e9ee7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e9ee8  ebd9                   -jmp 0x4e9ec3
    goto L_0x004e9ec3;
L_0x004e9eea:
    // 004e9eea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9eec  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004e9eee  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 004e9ef0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e9ef5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004e9ef7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9ef9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9efa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e9f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e9f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9f03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e9f04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e9f05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e9f06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e9f08  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e9f0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e9f0c  7537                   -jne 0x4e9f45
    if (!cpu.flags.zf)
    {
        goto L_0x004e9f45;
    }
    // 004e9f0e  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e9f15  742e                   -je 0x4e9f45
    if (cpu.flags.zf)
    {
        goto L_0x004e9f45;
    }
    // 004e9f17  bea4b55400             -mov esi, 0x54b5a4
    cpu.esi = 5551524 /*0x54b5a4*/;
    // 004e9f1c  bfb4b55400             -mov edi, 0x54b5b4
    cpu.edi = 5551540 /*0x54b5b4*/;
    // 004e9f21  bd11000000             -mov ebp, 0x11
    cpu.ebp = 17 /*0x11*/;
    // 004e9f26  68c4b55400             -push 0x54b5c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551556 /*0x54b5c4*/;
    cpu.esp -= 4;
    // 004e9f2b  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e9f31  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e9f37  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e9f3d  e8ce70f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9f42  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004e9f45:
    // 004e9f45  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004e9f4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9f4c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e9f4e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e9f50  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e9f52  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e9f59  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e9f5b  3dfbc00000             +cmp eax, 0xc0fb
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
    // 004e9f60  750e                   -jne 0x4e9f70
    if (!cpu.flags.zf)
    {
        goto L_0x004e9f70;
    }
    // 004e9f62  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004e9f67:
    // 004e9f67  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9f69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9f6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9f70:
    // 004e9f70  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e9f75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9f77  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e9f79  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e9f7b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e9f7d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e9f84  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e9f86  3d46474942             +cmp eax, 0x42494746
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
    // 004e9f8b  7445                   -je 0x4e9fd2
    if (cpu.flags.zf)
    {
        goto L_0x004e9fd2;
    }
    // 004e9f8d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e9f8f  75d6                   -jne 0x4e9f67
    if (!cpu.flags.zf)
    {
        goto L_0x004e9f67;
    }
    // 004e9f91  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e9f98  74cd                   -je 0x4e9f67
    if (cpu.flags.zf)
    {
        goto L_0x004e9f67;
    }
    // 004e9f9a  b9a4b55400             -mov ecx, 0x54b5a4
    cpu.ecx = 5551524 /*0x54b5a4*/;
    // 004e9f9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9fa0  beb4b55400             -mov esi, 0x54b5b4
    cpu.esi = 5551540 /*0x54b5b4*/;
    // 004e9fa5  bf21000000             -mov edi, 0x21
    cpu.edi = 33 /*0x21*/;
    // 004e9faa  68f4b55400             -push 0x54b5f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551604 /*0x54b5f4*/;
    cpu.esp -= 4;
    // 004e9faf  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e9fb5  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e9fbb  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e9fc1  e84a70f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e9fc6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e9fc9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9fcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9fd2:
    // 004e9fd2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004e9fd7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e9fd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9fdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e9fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e9fe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e9fe1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e9fe2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e9fe4  e817ffffff             -call 0x4e9f00
    cpu.esp -= 4;
    sub_4e9f00(app, cpu);
    if (cpu.terminate) return;
    // 004e9fe9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e9feb  83f801                 +cmp eax, 1
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
    // 004e9fee  7207                   -jb 0x4e9ff7
    if (cpu.flags.cf)
    {
        goto L_0x004e9ff7;
    }
    // 004e9ff0  760a                   -jbe 0x4e9ffc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e9ffc;
    }
    // 004e9ff2  83f802                 +cmp eax, 2
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
    // 004e9ff5  7424                   -je 0x4ea01b
    if (cpu.flags.zf)
    {
        goto L_0x004ea01b;
    }
L_0x004e9ff7:
    // 004e9ff7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e9ff9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9ffa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e9ffb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e9ffc:
    // 004e9ffc  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004e9fff  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ea004  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea006  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea008  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea00a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea011  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea013  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ea016  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea018  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea019  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea01a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea01b:
    // 004ea01b  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ea01e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ea023  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea025  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea027  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea029  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea030  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea032  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea034  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea036  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea037  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea038  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ea040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea041  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea043  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ea046  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ea048  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ea04a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004ea04e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ea051  e88affffff             -call 0x4e9fe0
    cpu.esp -= 4;
    sub_4e9fe0(app, cpu);
    if (cpu.terminate) return;
    // 004ea056  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ea058  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ea05a  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ea05e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ea060  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ea062  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004ea066  e895feffff             -call 0x4e9f00
    cpu.esp -= 4;
    sub_4e9f00(app, cpu);
    if (cpu.terminate) return;
    // 004ea06b  83f801                 +cmp eax, 1
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
    // 004ea06e  7327                   -jae 0x4ea097
    if (!cpu.flags.cf)
    {
        goto L_0x004ea097;
    }
L_0x004ea070:
    // 004ea070  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea073  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ea075  7406                   -je 0x4ea07d
    if (cpu.flags.zf)
    {
        goto L_0x004ea07d;
    }
    // 004ea077  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x004ea07d:
    // 004ea07d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ea081  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea083  7407                   -je 0x4ea08c
    if (cpu.flags.zf)
    {
        goto L_0x004ea08c;
    }
    // 004ea085  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x004ea08c:
    // 004ea08c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ea08e  83c410                 +add esp, 0x10
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
    // 004ea091  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea092  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea093  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea094  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ea097:
    // 004ea097  0f8773000000           -ja 0x4ea110
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ea110;
    }
    // 004ea09d  8d5f06                 -lea ebx, [edi + 6]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004ea0a0  39cb                   +cmp ebx, ecx
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
    // 004ea0a2  73cc                   -jae 0x4ea070
    if (!cpu.flags.cf)
    {
        goto L_0x004ea070;
    }
L_0x004ea0a4:
    // 004ea0a4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea0a6  0f85dc000000           -jne 0x4ea188
    if (!cpu.flags.zf)
    {
        goto L_0x004ea188;
    }
L_0x004ea0ac:
    // 004ea0ac  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea0ae  0f8554010000           -jne 0x4ea208
    if (!cpu.flags.zf)
    {
        goto L_0x004ea208;
    }
    // 004ea0b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea0b8  3b442404               +cmp eax, dword ptr [esp + 4]
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
    // 004ea0bc  0f8546010000           -jne 0x4ea208
    if (!cpu.flags.zf)
    {
        goto L_0x004ea208;
    }
L_0x004ea0c2:
    // 004ea0c2  833c2400               +cmp dword ptr [esp], 0
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
    // 004ea0c6  741b                   -je 0x4ea0e3
    if (cpu.flags.zf)
    {
        goto L_0x004ea0e3;
    }
    // 004ea0c8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004ea0cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ea0cf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea0d1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea0d3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea0d5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea0dc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea0de  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea0e1  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004ea0e3:
    // 004ea0e3  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ea0e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ea0e9  7419                   -je 0x4ea104
    if (cpu.flags.zf)
    {
        goto L_0x004ea104;
    }
    // 004ea0eb  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004ea0f0  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004ea0f3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea0f5  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea0f7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea0f9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea100  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea102  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004ea104:
    // 004ea104  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004ea107  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ea10a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea10b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea10c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea10d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ea110:
    // 004ea110  83f802                 +cmp eax, 2
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
    // 004ea113  0f8557ffffff           -jne 0x4ea070
    if (!cpu.flags.zf)
    {
        goto L_0x004ea070;
    }
    // 004ea119  8d5f10                 -lea ebx, [edi + 0x10]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004ea11c  39cb                   +cmp ebx, ecx
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
    // 004ea11e  0f834cffffff           -jae 0x4ea070
    if (!cpu.flags.cf)
    {
        goto L_0x004ea070;
    }
L_0x004ea124:
    // 004ea124  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea126  0f851e010000           -jne 0x4ea24a
    if (!cpu.flags.zf)
    {
        goto L_0x004ea24a;
    }
    // 004ea12c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea130  3b442404               +cmp eax, dword ptr [esp + 4]
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
    // 004ea134  0f8510010000           -jne 0x4ea24a
    if (!cpu.flags.zf)
    {
        goto L_0x004ea24a;
    }
L_0x004ea13a:
    // 004ea13a  833c2400               +cmp dword ptr [esp], 0
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
    // 004ea13e  741b                   -je 0x4ea15b
    if (cpu.flags.zf)
    {
        goto L_0x004ea15b;
    }
    // 004ea140  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ea145  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ea147  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea149  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea14b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea14d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea154  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea156  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea159  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004ea15b:
    // 004ea15b  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ea15f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ea161  7419                   -je 0x4ea17c
    if (cpu.flags.zf)
    {
        goto L_0x004ea17c;
    }
    // 004ea163  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ea168  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004ea16b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea16d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea16f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea171  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea178  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea17a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004ea17c:
    // 004ea17c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ea17f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ea182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea183  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea184  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea185  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ea188:
    // 004ea188  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ea18c  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004ea18e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ea190  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004ea192  81ce20202020           -or esi, 0x20202020
    cpu.esi |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
L_0x004ea198:
    // 004ea198  39d7                   +cmp edi, edx
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
    // 004ea19a  7d65                   -jge 0x4ea201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ea201;
    }
    // 004ea19c  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004ea19f  0d20202020             -or eax, 0x20202020
    cpu.eax |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
    // 004ea1a4  39f0                   +cmp eax, esi
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
    // 004ea1a6  7459                   -je 0x4ea201
    if (cpu.flags.zf)
    {
        goto L_0x004ea201;
    }
    // 004ea1a8  8b470a                 -mov eax, dword ptr [edi + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004ea1ab  8d7f0e                 -lea edi, [edi + 0xe]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 004ea1ae  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 004ea1b3  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ea1b8  7522                   -jne 0x4ea1dc
    if (!cpu.flags.zf)
    {
        goto L_0x004ea1dc;
    }
    // 004ea1ba  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004ea1bc  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ea1bf  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 004ea1c4  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ea1c9  7511                   -jne 0x4ea1dc
    if (!cpu.flags.zf)
    {
        goto L_0x004ea1dc;
    }
L_0x004ea1cb:
    // 004ea1cb  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004ea1cd  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ea1d0  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 004ea1d5  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ea1da  74ef                   -je 0x4ea1cb
    if (cpu.flags.zf)
    {
        goto L_0x004ea1cb;
    }
L_0x004ea1dc:
    // 004ea1dc  8a47fc                 -mov al, byte ptr [edi - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004ea1df  8d7ffd                 -lea edi, [edi - 3]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-3) /* -0x3 */);
    // 004ea1e2  3c00                   +cmp al, 0
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
    // 004ea1e4  74b2                   -je 0x4ea198
    if (cpu.flags.zf)
    {
        goto L_0x004ea198;
    }
    // 004ea1e6  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004ea1e8  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004ea1eb  3c00                   +cmp al, 0
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
    // 004ea1ed  74a9                   -je 0x4ea198
    if (cpu.flags.zf)
    {
        goto L_0x004ea198;
    }
    // 004ea1ef  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004ea1f1  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004ea1f4  3c00                   +cmp al, 0
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
    // 004ea1f6  74a0                   -je 0x4ea198
    if (cpu.flags.zf)
    {
        goto L_0x004ea198;
    }
    // 004ea1f8  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004ea1fa  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004ea1fd  3c00                   +cmp al, 0
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
    // 004ea1ff  7497                   -je 0x4ea198
    if (cpu.flags.zf)
    {
        goto L_0x004ea198;
    }
L_0x004ea201:
    // 004ea201  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ea203  e9a4feffff             -jmp 0x4ea0ac
    goto L_0x004ea0ac;
L_0x004ea208:
    // 004ea208  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea20a  7412                   -je 0x4ea21e
    if (cpu.flags.zf)
    {
        goto L_0x004ea21e;
    }
    // 004ea20c  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004ea20f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ea211  e8aafcffff             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 004ea216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea218  0f84a4feffff           -je 0x4ea0c2
    if (cpu.flags.zf)
    {
        goto L_0x004ea0c2;
    }
L_0x004ea21e:
    // 004ea21e  8d7b06                 -lea edi, [ebx + 6]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004ea221  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea223  49                     -dec ecx
    (cpu.ecx)--;
    // 004ea224  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ea226  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ea228  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ea22a  49                     -dec ecx
    (cpu.ecx)--;
    // 004ea22b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea22f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ea233  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea235  47                     -inc edi
    (cpu.edi)++;
    // 004ea236  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004ea239  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ea23d  39c3                   +cmp ebx, eax
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
    // 004ea23f  0f825ffeffff           -jb 0x4ea0a4
    if (cpu.flags.cf)
    {
        goto L_0x004ea0a4;
    }
    // 004ea245  e926feffff             -jmp 0x4ea070
    goto L_0x004ea070;
L_0x004ea24a:
    // 004ea24a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ea24c  7412                   -je 0x4ea260
    if (cpu.flags.zf)
    {
        goto L_0x004ea260;
    }
    // 004ea24e  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ea251  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ea253  e868fcffff             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 004ea258  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea25a  0f84dafeffff           -je 0x4ea13a
    if (cpu.flags.zf)
    {
        goto L_0x004ea13a;
    }
L_0x004ea260:
    // 004ea260  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ea263  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea265  49                     -dec ecx
    (cpu.ecx)--;
    // 004ea266  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ea268  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ea26a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ea26c  49                     -dec ecx
    (cpu.ecx)--;
    // 004ea26d  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea271  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ea275  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea277  47                     -inc edi
    (cpu.edi)++;
    // 004ea278  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004ea27b  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ea27f  39c3                   +cmp ebx, eax
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
    // 004ea281  0f829dfeffff           -jb 0x4ea124
    if (cpu.flags.cf)
    {
        goto L_0x004ea124;
    }
    // 004ea287  e9e4fdffff             -jmp 0x4ea070
    goto L_0x004ea070;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ea290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea290  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea291  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea292  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea293  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ea295  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ea297  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ea29b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea29c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ea29e  e89dfdffff             -call 0x4ea040
    cpu.esp -= 4;
    sub_4ea040(app, cpu);
    if (cpu.terminate) return;
    // 004ea2a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ea2a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea2a7  753c                   -jne 0x4ea2e5
    if (!cpu.flags.zf)
    {
        goto L_0x004ea2e5;
    }
    // 004ea2a9  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004ea2b0  7433                   -je 0x4ea2e5
    if (cpu.flags.zf)
    {
        goto L_0x004ea2e5;
    }
    // 004ea2b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ea2b4  7437                   -je 0x4ea2ed
    if (cpu.flags.zf)
    {
        goto L_0x004ea2ed;
    }
    // 004ea2b6  baa4b55400             -mov edx, 0x54b5a4
    cpu.edx = 5551524 /*0x54b5a4*/;
    // 004ea2bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea2bc  bb20b65400             -mov ebx, 0x54b620
    cpu.ebx = 5551648 /*0x54b620*/;
    // 004ea2c1  bfef000000             -mov edi, 0xef
    cpu.edi = 239 /*0xef*/;
    // 004ea2c6  6830b65400             -push 0x54b630
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551664 /*0x54b630*/;
    cpu.esp -= 4;
    // 004ea2cb  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004ea2d1  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ea2d7  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004ea2dd  e82e6df1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ea2e2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004ea2e5:
    // 004ea2e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ea2e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea2e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea2e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea2ea  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ea2ed:
    // 004ea2ed  bea4b55400             -mov esi, 0x54b5a4
    cpu.esi = 5551524 /*0x54b5a4*/;
    // 004ea2f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea2f3  bd20b65400             -mov ebp, 0x54b620
    cpu.ebp = 5551648 /*0x54b620*/;
    // 004ea2f8  b8f1000000             -mov eax, 0xf1
    cpu.eax = 241 /*0xf1*/;
    // 004ea2fd  6858b65400             -push 0x54b658
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551704 /*0x54b658*/;
    cpu.esp -= 4;
    // 004ea302  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004ea308  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004ea30e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004ea313  e8f86cf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ea318  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea31b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ea31d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea31f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea320  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ea330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea330  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea331  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea334  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea336  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ea339  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ea33b  7508                   -jne 0x4ea345
    if (!cpu.flags.zf)
    {
        goto L_0x004ea345;
    }
    // 004ea33d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea340  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea343  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea344  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea345:
    // 004ea345  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea346  68f0f89e00             -push 0x9ef8f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10418416 /*0x9ef8f0*/;
    cpu.esp -= 4;
    // 004ea34b  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ea34f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ea351  e83affffff             -call 0x4ea290
    cpu.esp -= 4;
    sub_4ea290(app, cpu);
    if (cpu.terminate) return;
    // 004ea356  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea357  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea35a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea35d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea35e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ea360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea362  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea363  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea366  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ea368  68f0f89e00             -push 0x9ef8f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10418416 /*0x9ef8f0*/;
    cpu.esp -= 4;
    // 004ea36d  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ea371  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004ea373  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ea375  e816ffffff             -call 0x4ea290
    cpu.esp -= 4;
    sub_4ea290(app, cpu);
    if (cpu.terminate) return;
    // 004ea37a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea37c  7405                   -je 0x4ea383
    if (cpu.flags.zf)
    {
        goto L_0x004ea383;
    }
    // 004ea37e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ea381  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004ea383:
    // 004ea383  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea386  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea388  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ea390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea392  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ea394  e897ffffff             -call 0x4ea330
    cpu.esp -= 4;
    sub_4ea330(app, cpu);
    if (cpu.terminate) return;
    // 004ea399  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ea39b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea39d  7403                   -je 0x4ea3a2
    if (cpu.flags.zf)
    {
        goto L_0x004ea3a2;
    }
    // 004ea39f  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
L_0x004ea3a2:
    // 004ea3a2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ea3a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea3a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea3a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ea3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea3b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea3b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea3b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea3b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea3b4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ea3b6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x004ea3b8:
    // 004ea3b8  b22c                   -mov dl, 0x2c
    cpu.dl = 44 /*0x2c*/;
    // 004ea3ba  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004ea3bc:
    // 004ea3bc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ea3be  3ac2                   +cmp al, dl
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
    // 004ea3c0  7412                   -je 0x4ea3d4
    if (cpu.flags.zf)
    {
        goto L_0x004ea3d4;
    }
    // 004ea3c2  3c00                   +cmp al, 0
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
    // 004ea3c4  740c                   -je 0x4ea3d2
    if (cpu.flags.zf)
    {
        goto L_0x004ea3d2;
    }
    // 004ea3c6  46                     -inc esi
    (cpu.esi)++;
    // 004ea3c7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ea3c9  3ac2                   +cmp al, dl
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
    // 004ea3cb  7407                   -je 0x4ea3d4
    if (cpu.flags.zf)
    {
        goto L_0x004ea3d4;
    }
    // 004ea3cd  46                     -inc esi
    (cpu.esi)++;
    // 004ea3ce  3c00                   +cmp al, 0
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
    // 004ea3d0  75ea                   -jne 0x4ea3bc
    if (!cpu.flags.zf)
    {
        goto L_0x004ea3bc;
    }
L_0x004ea3d2:
    // 004ea3d2  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ea3d4:
    // 004ea3d4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004ea3d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ea3d8  7403                   -je 0x4ea3dd
    if (cpu.flags.zf)
    {
        goto L_0x004ea3dd;
    }
    // 004ea3da  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
L_0x004ea3dd:
    // 004ea3dd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ea3df  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ea3e1  e8aaffffff             -call 0x4ea390
    cpu.esp -= 4;
    sub_4ea390(app, cpu);
    if (cpu.terminate) return;
    // 004ea3e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ea3e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea3ea  7536                   -jne 0x4ea422
    if (!cpu.flags.zf)
    {
        goto L_0x004ea422;
    }
    // 004ea3ec  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004ea3f3  742d                   -je 0x4ea422
    if (cpu.flags.zf)
    {
        goto L_0x004ea422;
    }
    // 004ea3f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea3f6  b8a4b55400             -mov eax, 0x54b5a4
    cpu.eax = 5551524 /*0x54b5a4*/;
    // 004ea3fb  ba80b65400             -mov edx, 0x54b680
    cpu.edx = 5551744 /*0x54b680*/;
    // 004ea400  688cb65400             -push 0x54b68c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551756 /*0x54b68c*/;
    cpu.esp -= 4;
    // 004ea405  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004ea40a  b8c3010000             -mov eax, 0x1c3
    cpu.eax = 451 /*0x1c3*/;
    // 004ea40f  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004ea415  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004ea41a  e8f16bf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ea41f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004ea422:
    // 004ea422  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ea425  8973fc                 -mov dword ptr [ebx - 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004ea428  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ea42a  7406                   -je 0x4ea432
    if (cpu.flags.zf)
    {
        goto L_0x004ea432;
    }
    // 004ea42c  c6012c                 -mov byte ptr [ecx], 0x2c
    app->getMemory<x86::reg8>(cpu.ecx) = 44 /*0x2c*/;
    // 004ea42f  41                     -inc ecx
    (cpu.ecx)++;
    // 004ea430  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004ea432:
    // 004ea432  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ea434  7582                   -jne 0x4ea3b8
    if (!cpu.flags.zf)
    {
        goto L_0x004ea3b8;
    }
    // 004ea436  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea437  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea438  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea43a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ea440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea441  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea442  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ea444  e8b7faffff             -call 0x4e9f00
    cpu.esp -= 4;
    sub_4e9f00(app, cpu);
    if (cpu.terminate) return;
    // 004ea449  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ea44b  83f801                 +cmp eax, 1
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
    // 004ea44e  7207                   -jb 0x4ea457
    if (cpu.flags.cf)
    {
        goto L_0x004ea457;
    }
    // 004ea450  760a                   -jbe 0x4ea45c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ea45c;
    }
    // 004ea452  83f802                 +cmp eax, 2
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
    // 004ea455  7423                   -je 0x4ea47a
    if (cpu.flags.zf)
    {
        goto L_0x004ea47a;
    }
L_0x004ea457:
    // 004ea457  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea459  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea45a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea45b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea45c:
    // 004ea45c  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004ea45f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ea464  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea466  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea468  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea46a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea471  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea473  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea475  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea477  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea478  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea479  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea47a:
    // 004ea47a  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ea47d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ea482  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ea484  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ea486  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ea488  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ea48f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ea491  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea493  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea495  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea496  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea497  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ea4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea4a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea4a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea4a2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004ea4a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ea4a6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004ea4a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea4aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ea4ac  e8dffdffff             -call 0x4ea290
    cpu.esp -= 4;
    sub_4ea290(app, cpu);
    if (cpu.terminate) return;
    // 004ea4b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea4b3  7507                   -jne 0x4ea4bc
    if (!cpu.flags.zf)
    {
        goto L_0x004ea4bc;
    }
    // 004ea4b5  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 004ea4b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea4bc:
    // 004ea4bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea4bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea4be  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ea4c0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ea4c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004ea4c3:
    // 004ea4c3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ea4c5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004ea4c7  3c00                   +cmp al, 0
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
    // 004ea4c9  7410                   -je 0x4ea4db
    if (cpu.flags.zf)
    {
        goto L_0x004ea4db;
    }
    // 004ea4cb  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ea4ce  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ea4d1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ea4d4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ea4d7  3c00                   +cmp al, 0
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
    // 004ea4d9  75e8                   -jne 0x4ea4c3
    if (!cpu.flags.zf)
    {
        goto L_0x004ea4c3;
    }
L_0x004ea4db:
    // 004ea4db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4dc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ea4de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea4e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ea4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea4f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea4f1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ea4f3  39c2                   +cmp edx, eax
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
    // 004ea4f5  771d                   -ja 0x4ea514
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ea514;
    }
L_0x004ea4f7:
    // 004ea4f7  833db443560000         +cmp dword ptr [0x5643b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ea4fe  752f                   -jne 0x4ea52f
    if (!cpu.flags.zf)
    {
        goto L_0x004ea52f;
    }
    // 004ea500  833dac43560000         +cmp dword ptr [0x5643ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ea507  7433                   -je 0x4ea53c
    if (cpu.flags.zf)
    {
        goto L_0x004ea53c;
    }
    // 004ea509  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea50b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ea50d  e86f8d0100             -call 0x503281
    cpu.esp -= 4;
    sub_503281(app, cpu);
    if (cpu.terminate) return;
L_0x004ea512:
    // 004ea512  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea513  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea514:
    // 004ea514  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004ea517  39d1                   +cmp ecx, edx
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
    // 004ea519  73dc                   -jae 0x4ea4f7
    if (!cpu.flags.cf)
    {
        goto L_0x004ea4f7;
    }
    // 004ea51b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea51d  8d1419                 -lea edx, [ecx + ebx]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebx * 1);
L_0x004ea520:
    // 004ea520  4b                     -dec ebx
    (cpu.ebx)--;
    // 004ea521  83fbff                 +cmp ebx, -1
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
    // 004ea524  74ec                   -je 0x4ea512
    if (cpu.flags.zf)
    {
        goto L_0x004ea512;
    }
    // 004ea526  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ea527  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004ea52a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ea52b  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004ea52d  ebf1                   -jmp 0x4ea520
    goto L_0x004ea520;
L_0x004ea52f:
    // 004ea52f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea531  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ea533  e8ad8e0100             -call 0x5033e5
    cpu.esp -= 4;
    sub_5033e5(app, cpu);
    if (cpu.terminate) return;
    // 004ea538  0f77                   -emms 
    cpu.mmx.init();
    // 004ea53a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea53b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea53c:
    // 004ea53c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ea53e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ea540  e828900100             -call 0x50356d
    cpu.esp -= 4;
    sub_50356d(app, cpu);
    if (cpu.terminate) return;
    // 004ea545  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea546  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ea570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004ea570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea571  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea572  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea575  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ea577  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ea579  7c1f                   -jl 0x4ea59a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ea59a;
    }
L_0x004ea57b:
    // 004ea57b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ea57d  7c24                   -jl 0x4ea5a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ea5a3;
    }
L_0x004ea57f:
    // 004ea57f  39d0                   +cmp eax, edx
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
    // 004ea581  7527                   -jne 0x4ea5aa
    if (!cpu.flags.zf)
    {
        goto L_0x004ea5aa;
    }
    // 004ea583  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004ea588  83f907                 +cmp ecx, 7
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
    // 004ea58b  7707                   -ja 0x4ea594
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ea594;
    }
    // 004ea58d  ff248d50a54e00         -jmp dword ptr [ecx*4 + 0x4ea550]
    cpu.ip = app->getMemory<x86::reg32>(5154128 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004ea594:
L_0x004ea594:
    // 004ea594  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea597  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea598  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea599  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea59a:
    // 004ea59a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ea59f  f7da                   +neg edx
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
    // 004ea5a1  ebd8                   -jmp 0x4ea57b
    goto L_0x004ea57b;
L_0x004ea5a3:
    // 004ea5a3  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ea5a5  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004ea5a8  ebd5                   -jmp 0x4ea57f
    goto L_0x004ea57f;
L_0x004ea5aa:
    // 004ea5aa  39c2                   +cmp edx, eax
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
    // 004ea5ac  7d09                   -jge 0x4ea5b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ea5b7;
    }
    // 004ea5ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ea5b0  80c901                 -or cl, 1
    cpu.cl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004ea5b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ea5b5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004ea5b7:
    // 004ea5b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea5b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea5b9  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ea5bd  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004ea5c2  e839950100             -call 0x503b00
    cpu.esp -= 4;
    sub_503b00(app, cpu);
    if (cpu.terminate) return;
    // 004ea5c7  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea5cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea5cc  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ea5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea5d1  e88a910100             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 004ea5d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ea5d8  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004ea5db  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004ea5e2  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 004ea5e5  8b82bc795600           -mov eax, dword ptr [edx + 0x5679bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5667260) /* 0x5679bc */);
    // 004ea5eb  8b92c0795600           -mov edx, dword ptr [edx + 0x5679c0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5667264) /* 0x5679c0 */);
    // 004ea5f1  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ea5f7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ea5f9  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004ea5fc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004ea5ff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ea601  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea602  83f907                 +cmp ecx, 7
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
    // 004ea605  778d                   -ja 0x4ea594
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ea594;
    }
    // 004ea607  ff248d50a54e00         -jmp dword ptr [ecx*4 + 0x4ea550]
    cpu.ip = app->getMemory<x86::reg32>(5154128 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004ea60e:
    // 004ea60e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
  [[fallthrough]];
  case 0x004ea610:
    // 004ea610  0500400000             -add eax, 0x4000
    (cpu.eax) += x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004ea615  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea61a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004ea61b:
    // 004ea61b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ea61d  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004ea622  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea625  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea626  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea627  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004ea628:
    // 004ea628  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ea62a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea62d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea62e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea62f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004ea630:
    // 004ea630  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004ea635  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea638  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea639  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea63a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004ea63b:
    // 004ea63b  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 004ea640  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea643  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea644  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea645  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004ea646:
    // 004ea646  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ea648  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004ea64d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea650  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea651  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea652  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_4ea654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea654  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ea657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ea658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea658  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ea65b  7305                   -jae 0x4ea662
    if (!cpu.flags.cf)
    {
        goto L_0x004ea662;
    }
    // 004ea65d  0344d014               -add eax, dword ptr [eax + edx*8 + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 8)));
    // 004ea661  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea662:
    // 004ea662  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ea664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ea665(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea665  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ea668  7307                   -jae 0x4ea671
    if (!cpu.flags.cf)
    {
        goto L_0x004ea671;
    }
    // 004ea66a  8b44d010               -mov eax, dword ptr [eax + edx*8 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */ + cpu.edx * 8);
    // 004ea66e  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ea670  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ea671:
    // 004ea671  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004ea677  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ea680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea683  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea684  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea685  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea686  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ea689  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004ea68d  39e8                   +cmp eax, ebp
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
    // 004ea68f  0f84a2000000           -je 0x4ea737
    if (cpu.flags.zf)
    {
        goto L_0x004ea737;
    }
    // 004ea695  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ea697:
    // 004ea697  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004ea69b  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ea69f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004ea6a3  e8c8020000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004ea6a8  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ea6aa  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004ea6ad  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004ea6b0  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ea6b3  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ea6b6  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ea6b9  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004ea6bc  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea6c0  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004ea6c3  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea6c7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea6c9  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea6cc  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004ea6cf  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea6d3  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004ea6d6  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea6da  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea6dc  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea6df  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004ea6e2  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea6e6  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004ea6e9  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea6ed  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea6ef  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea6f2  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004ea6f5  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea6f9  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004ea6fc  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea700  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea702  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea705  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004ea708  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea70c  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004ea70f  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea713  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea715  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea718  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004ea71b  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea71f  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004ea722  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea726  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea728  d95d20                 -fstp dword ptr [ebp + 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea72b  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ea72e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea72f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea730  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea731  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea733  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea734  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ea737:
    // 004ea737  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004ea73c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004ea73e  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004ea740  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ea742  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ea744  e94effffff             -jmp 0x4ea697
    goto L_0x004ea697;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ea750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea756  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ea759  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004ea75d  39e8                   +cmp eax, ebp
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
    // 004ea75f  0f84a1000000           -je 0x4ea806
    if (cpu.flags.zf)
    {
        goto L_0x004ea806;
    }
    // 004ea765  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ea767:
    // 004ea767  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004ea76b  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ea76f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004ea773  e8f8010000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004ea778  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004ea77b  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea77f  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004ea781  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea785  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea787  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea78a  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004ea78d  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea791  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004ea794  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea798  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea79a  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea79d  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004ea7a0  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea7a4  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004ea7a7  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea7ab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea7ad  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea7b0  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004ea7b3  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ea7b6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ea7b9  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ea7bc  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004ea7bf  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ea7c2  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004ea7c5  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea7c9  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004ea7cb  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea7cf  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004ea7d1  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea7d4  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004ea7d7  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea7db  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004ea7de  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea7e2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea7e4  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea7e7  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004ea7ea  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea7ee  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004ea7f1  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea7f5  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea7f7  d95d20                 -fstp dword ptr [ebp + 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea7fa  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ea7fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea7fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea7ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea800  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea802  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea803  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ea806:
    // 004ea806  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004ea80b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004ea80d  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004ea80f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ea811  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ea813  e94fffffff             -jmp 0x4ea767
    goto L_0x004ea767;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ea820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea823  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea824  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea825  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea826  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ea829  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004ea82d  39e8                   +cmp eax, ebp
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
    // 004ea82f  0f84a1000000           -je 0x4ea8d6
    if (cpu.flags.zf)
    {
        goto L_0x004ea8d6;
    }
    // 004ea835  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ea837:
    // 004ea837  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004ea83b  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ea83f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004ea843  e828010000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004ea848  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004ea84b  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea84f  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004ea851  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea855  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004ea857  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea85a  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004ea85d  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea861  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004ea864  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea868  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea86a  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea86d  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004ea870  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea874  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004ea877  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea87b  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea87d  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea880  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004ea883  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea887  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004ea889  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea88d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea88f  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea892  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004ea895  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea899  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004ea89c  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea8a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea8a2  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea8a5  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004ea8a8  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004ea8ac  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004ea8af  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004ea8b3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ea8b5  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea8b8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004ea8bb  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ea8be  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004ea8c1  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ea8c4  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004ea8c7  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004ea8ca  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ea8cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea8d3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ea8d6:
    // 004ea8d6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004ea8db  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004ea8dd  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004ea8df  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ea8e1  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ea8e3  e94fffffff             -jmp 0x4ea837
    goto L_0x004ea837;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ea8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea8f0  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004ea8f4  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004ea8f8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ea900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea900  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004ea904  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004ea908  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ea910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea910  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004ea912  d8742404               -fdiv dword ptr [esp + 4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 004ea916  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ea920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea920  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ea921  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ea925  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 004ea927  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea928  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ea930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea930  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ea931  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ea935  dc0db0b65400           -fmul qword ptr [0x54b6b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5551792) /* 0x54b6b0 */));
    // 004ea93b  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 004ea93d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea93e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4ea950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea950  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ea951  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ea955  dc0db8b65400           -fmul qword ptr [0x54b6b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5551800) /* 0x54b6b8 */));
    // 004ea95b  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 004ea95d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea95e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4ea970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea970  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea971  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ea973  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004ea975  e8b6ffffff             -call 0x4ea930
    cpu.esp -= 4;
    sub_4ea930(app, cpu);
    if (cpu.terminate) return;
    // 004ea97a  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea97c  ff31                   -push dword ptr [ecx]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    // 004ea97e  e8cdffffff             -call 0x4ea950
    cpu.esp -= 4;
    sub_4ea950(app, cpu);
    if (cpu.terminate) return;
    // 004ea983  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ea985  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ea990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea990  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ea991  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea992  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea993  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea996  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ea99a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ea99c  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ea9a0  e8cbffffff             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004ea9a5  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004ea9a9  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004ea9ad  e84effffff             -call 0x4ea900
    cpu.esp -= 4;
    sub_4ea900(app, cpu);
    if (cpu.terminate) return;
    // 004ea9b2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ea9b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea9b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea9b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea9b8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ea9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea9c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ea9c1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004ea9c5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ea9c9  e80b5dffff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004ea9ce  dc0dc0b65400           -fmul qword ptr [0x54b6c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5551808) /* 0x54b6c0 */));
    // 004ea9d4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ea9d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ea9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ea9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ea9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ea9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ea9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ea9e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ea9e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ea9e6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ea9e9  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004ea9ed  39e8                   +cmp eax, ebp
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
    // 004ea9ef  0f84a2000000           -je 0x4eaa97
    if (cpu.flags.zf)
    {
        goto L_0x004eaa97;
    }
    // 004ea9f5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ea9f7:
    // 004ea9f7  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004ea9fb  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ea9ff  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004eaa03  e868ffffff             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004eaa08  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004eaa0a  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004eaa0d  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004eaa10  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004eaa13  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004eaa16  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004eaa19  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004eaa1c  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa20  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004eaa23  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa27  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa29  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa2c  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004eaa2f  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa33  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004eaa36  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa3a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa3c  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa3f  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004eaa42  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa46  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004eaa49  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa4d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa4f  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa52  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004eaa55  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa59  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004eaa5c  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa60  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa62  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa65  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004eaa68  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa6c  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004eaa6f  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa73  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa75  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa78  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004eaa7b  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaa7f  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004eaa82  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaa86  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaa88  d95d20                 -fstp dword ptr [ebp + 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaa8b  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004eaa8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaa94  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004eaa97:
    // 004eaa97  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004eaa9c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004eaa9e  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004eaaa0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004eaaa2  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004eaaa4  e94effffff             -jmp 0x4ea9f7
    goto L_0x004ea9f7;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4eaab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eaab0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eaab1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eaab2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eaab3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eaab4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eaab5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eaab6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004eaab9  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004eaabd  39e8                   +cmp eax, ebp
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
    // 004eaabf  0f84a1000000           -je 0x4eab66
    if (cpu.flags.zf)
    {
        goto L_0x004eab66;
    }
    // 004eaac5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004eaac7:
    // 004eaac7  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004eaacb  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eaacf  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004eaad3  e898feffff             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004eaad8  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004eaadb  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaadf  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004eaae1  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaae5  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004eaae7  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaaea  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004eaaed  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eaaf1  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004eaaf4  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eaaf8  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eaafa  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eaafd  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004eab00  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eab04  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004eab07  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eab0b  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eab0d  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eab10  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004eab13  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004eab16  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004eab19  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004eab1c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004eab1f  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004eab22  d94118                 -fld dword ptr [ecx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 004eab25  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eab29  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004eab2b  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eab2f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eab31  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eab34  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004eab37  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eab3b  d9411c                 -fld dword ptr [ecx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 004eab3e  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eab42  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eab44  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eab47  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004eab4a  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eab4e  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004eab51  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eab55  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eab57  d95d20                 -fstp dword ptr [ebp + 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eab5a  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004eab5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eab63  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004eab66:
    // 004eab66  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004eab6b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004eab6d  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004eab6f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004eab71  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004eab73  e94fffffff             -jmp 0x4eaac7
    goto L_0x004eaac7;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4eab80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eab80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eab81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eab82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eab83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eab84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eab85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eab86  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004eab89  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004eab8d  39e8                   +cmp eax, ebp
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
    // 004eab8f  0f84a1000000           -je 0x4eac36
    if (cpu.flags.zf)
    {
        goto L_0x004eac36;
    }
    // 004eab95  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004eab97:
    // 004eab97  8d5c2428               -lea ebx, [esp + 0x28]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004eab9b  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eab9f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004eaba3  e8c8fdffff             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004eaba8  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004eabab  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eabaf  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004eabb1  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eabb5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eabb7  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eabba  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004eabbd  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eabc1  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004eabc4  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eabc8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eabca  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eabcd  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004eabd0  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eabd4  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004eabd7  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eabdb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eabdd  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eabe0  d9410c                 -fld dword ptr [ecx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 004eabe3  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eabe7  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004eabe9  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eabed  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eabef  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eabf2  d94110                 -fld dword ptr [ecx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004eabf5  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eabf9  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004eabfc  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eac00  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eac02  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eac05  d94114                 -fld dword ptr [ecx + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 004eac08  d84c2428               -fmul dword ptr [esp + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 004eac0c  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004eac0f  d84c2424               -fmul dword ptr [esp + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 004eac13  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004eac15  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004eac18  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004eac1b  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004eac1e  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004eac21  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004eac24  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004eac27  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004eac2a  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004eac2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac33  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004eac36:
    // 004eac36  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004eac3b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004eac3d  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004eac3f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004eac41  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004eac43  e94fffffff             -jmp 0x4eab97
    goto L_0x004eab97;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eac60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004eac60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eac61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eac62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eac64  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004eac67  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004eac6a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004eac6f  83f903                 +cmp ecx, 3
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
    // 004eac72  7720                   -ja 0x4eac94
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004eac94;
    }
    // 004eac74  ff248d50ac4e00         -jmp dword ptr [ecx*4 + 0x4eac50]
    cpu.ip = app->getMemory<x86::reg32>(5155920 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004eac7b:
    // 004eac7b  8b0c85ac725600         -mov ecx, dword ptr [eax*4 + 0x5672ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004eac82  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004eac84  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004eac89  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eac8b  8b0495ac725600         -mov eax, dword ptr [edx*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.edx * 4);
    // 004eac92  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004eac94:
    // 004eac94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eac96  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004eac97:
    // 004eac97  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 004eac9c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eac9e  8b0c8dac725600         -mov ecx, dword ptr [ecx*4 + 0x5672ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.ecx * 4);
    // 004eaca5  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004eaca7  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004eacae  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004eacb0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004eacb2  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004eacb4  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004eacb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eacb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eacb8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004eacb9:
    // 004eacb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eacba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eacbb  8b0c85ac725600         -mov ecx, dword ptr [eax*4 + 0x5672ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004eacc2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004eacc4  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004eacc6  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004eacc8  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004eacca  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004eaccf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eacd1  8b0495ac725600         -mov eax, dword ptr [edx*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.edx * 4);
    // 004eacd8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004eacda  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004eacdc  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004eacde  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004eace0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eace1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eace2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eace3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eace4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004eace5:
    // 004eace5  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 004eacea  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eacec  8b0c8dac725600         -mov ecx, dword ptr [ecx*4 + 0x5672ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.ecx * 4);
    // 004eacf3  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004eacf5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004eacf7  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004eacf9  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004ead00  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ead02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ead03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ead04  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ead10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ead10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4ead20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ead20  803d2f3d9f0000         +cmp byte ptr [0x9f3d2f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435887) /* 0x9f3d2f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ead27  750a                   -jne 0x4ead33
    if (!cpu.flags.zf)
    {
        goto L_0x004ead33;
    }
    // 004ead29  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 004ead2e  e96d000000             -jmp 0x4eada0
    return sub_4eada0(app, cpu);
L_0x004ead33:
    // 004ead33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ead34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ead35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ead36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ead38  bac8b65400             -mov edx, 0x54b6c8
    cpu.edx = 5551816 /*0x54b6c8*/;
    // 004ead3d  a02f3d9f00             -mov al, byte ptr [0x9f3d2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435887) /* 0x9f3d2f */);
    // 004ead42  b9d8b65400             -mov ecx, 0x54b6d8
    cpu.ecx = 5551832 /*0x54b6d8*/;
    // 004ead47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ead48  bb5d000000             -mov ebx, 0x5d
    cpu.ebx = 93 /*0x5d*/;
    // 004ead4d  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004ead53  68e8b65400             -push 0x54b6e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551848 /*0x54b6e8*/;
    cpu.esp -= 4;
    // 004ead58  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004ead5e  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004ead64  e8a762f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ead69  83c408                 +add esp, 8
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
    // 004ead6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ead6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ead6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ead6f  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 004ead74  eb2a                   -jmp 0x4eada0
    return sub_4eada0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ead80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ead80  b864505600             -mov eax, 0x565064
    cpu.eax = 5656676 /*0x565064*/;
    // 004ead85  eb19                   -jmp 0x4eada0
    return sub_4eada0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ead90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ead90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ead92  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ead98  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ead9e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004eada0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eada1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eada2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eada3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eada4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eada5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eada6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eada8  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004eadad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eadaf  7552                   -jne 0x4eae03
    if (!cpu.flags.zf)
    {
        goto L_0x004eae03;
    }
L_0x004eadb1:
    // 004eadb1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004eadb3  7445                   -je 0x4eadfa
    if (cpu.flags.zf)
    {
        goto L_0x004eadfa;
    }
    // 004eadb5  833dcc7d560000         +cmp dword ptr [0x567dcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eadbc  754e                   -jne 0x4eae0c
    if (!cpu.flags.zf)
    {
        goto L_0x004eae0c;
    }
    // 004eadbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eadc0  7454                   -je 0x4eae16
    if (cpu.flags.zf)
    {
        goto L_0x004eae16;
    }
    // 004eadc2  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004eadc7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004eadc9  8b5634                 -mov edx, dword ptr [esi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004eadcc  e81f230000             -call 0x4ed0f0
    cpu.esp -= 4;
    sub_4ed0f0(app, cpu);
    if (cpu.terminate) return;
L_0x004eadd1:
    // 004eadd1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004eadd3:
    // 004eadd3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eadd5  0f8472000000           -je 0x4eae4d
    if (cpu.flags.zf)
    {
        goto L_0x004eae4d;
    }
    // 004eaddb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004eaddd  7543                   -jne 0x4eae22
    if (!cpu.flags.zf)
    {
        goto L_0x004eae22;
    }
    // 004eaddf  833df043560000         +cmp dword ptr [0x5643f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eade6  7446                   -je 0x4eae2e
    if (cpu.flags.zf)
    {
        goto L_0x004eae2e;
    }
L_0x004eade8:
    // 004eade8  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004eaded  bff44f5600             -mov edi, 0x564ff4
    cpu.edi = 5656564 /*0x564ff4*/;
    // 004eadf2  8b35f0435600           -mov esi, dword ptr [0x5643f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
L_0x004eadf8:
    // 004eadf8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004eadfa:
    // 004eadfa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eadfc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eae03:
    // 004eae03  e8789c0000             -call 0x4f4a80
    cpu.esp -= 4;
    sub_4f4a80(app, cpu);
    if (cpu.terminate) return;
    // 004eae08  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004eae0a  eba5                   -jmp 0x4eadb1
    goto L_0x004eadb1;
L_0x004eae0c:
    // 004eae0c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eae0e  ff15cc7d5600           -call dword ptr [0x567dcc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eae14  ebbb                   -jmp 0x4eadd1
    goto L_0x004eadd1;
L_0x004eae16:
    // 004eae16  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004eae1b  e880240000             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
    // 004eae20  ebb1                   -jmp 0x4eadd3
    goto L_0x004eadd3;
L_0x004eae22:
    // 004eae22  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004eae27  bff44f5600             -mov edi, 0x564ff4
    cpu.edi = 5656564 /*0x564ff4*/;
    // 004eae2c  ebca                   -jmp 0x4eadf8
    goto L_0x004eadf8;
L_0x004eae2e:
    // 004eae2e  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004eae33  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004eae39  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 004eae3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eae41  e84a430000             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 004eae46  a3f0435600             -mov dword ptr [0x5643f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.eax;
    // 004eae4b  eb9b                   -jmp 0x4eade8
    goto L_0x004eade8;
L_0x004eae4d:
    // 004eae4d  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004eae52  b8f44f5600             -mov eax, 0x564ff4
    cpu.eax = 5656564 /*0x564ff4*/;
    // 004eae57  e8b058ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004eae5c  a048505600             -mov al, byte ptr [0x565048]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656648) /* 0x565048 */);
    // 004eae61  a210505600             -mov byte ptr [0x565010], al
    app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */) = cpu.al;
    // 004eae66  a049505600             -mov al, byte ptr [0x565049]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656649) /* 0x565049 */);
    // 004eae6b  a211505600             -mov byte ptr [0x565011], al
    app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */) = cpu.al;
    // 004eae70  a04a505600             -mov al, byte ptr [0x56504a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656650) /* 0x56504a */);
    // 004eae75  a212505600             -mov byte ptr [0x565012], al
    app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */) = cpu.al;
    // 004eae7a  a15c505600             -mov eax, dword ptr [0x56505c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656668) /* 0x56505c */);
    // 004eae7f  a324505600             -mov dword ptr [0x565024], eax
    app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */) = cpu.eax;
    // 004eae84  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eae86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4eada0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004eada0;
    // 004ead90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ead92  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ead98  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ead9e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004eada0:
    // 004eada0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eada1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eada2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eada3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eada4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eada5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eada6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eada8  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004eadad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eadaf  7552                   -jne 0x4eae03
    if (!cpu.flags.zf)
    {
        goto L_0x004eae03;
    }
L_0x004eadb1:
    // 004eadb1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004eadb3  7445                   -je 0x4eadfa
    if (cpu.flags.zf)
    {
        goto L_0x004eadfa;
    }
    // 004eadb5  833dcc7d560000         +cmp dword ptr [0x567dcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eadbc  754e                   -jne 0x4eae0c
    if (!cpu.flags.zf)
    {
        goto L_0x004eae0c;
    }
    // 004eadbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eadc0  7454                   -je 0x4eae16
    if (cpu.flags.zf)
    {
        goto L_0x004eae16;
    }
    // 004eadc2  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004eadc7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004eadc9  8b5634                 -mov edx, dword ptr [esi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004eadcc  e81f230000             -call 0x4ed0f0
    cpu.esp -= 4;
    sub_4ed0f0(app, cpu);
    if (cpu.terminate) return;
L_0x004eadd1:
    // 004eadd1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004eadd3:
    // 004eadd3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eadd5  0f8472000000           -je 0x4eae4d
    if (cpu.flags.zf)
    {
        goto L_0x004eae4d;
    }
    // 004eaddb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004eaddd  7543                   -jne 0x4eae22
    if (!cpu.flags.zf)
    {
        goto L_0x004eae22;
    }
    // 004eaddf  833df043560000         +cmp dword ptr [0x5643f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eade6  7446                   -je 0x4eae2e
    if (cpu.flags.zf)
    {
        goto L_0x004eae2e;
    }
L_0x004eade8:
    // 004eade8  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004eaded  bff44f5600             -mov edi, 0x564ff4
    cpu.edi = 5656564 /*0x564ff4*/;
    // 004eadf2  8b35f0435600           -mov esi, dword ptr [0x5643f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
L_0x004eadf8:
    // 004eadf8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004eadfa:
    // 004eadfa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eadfc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eadff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eae03:
    // 004eae03  e8789c0000             -call 0x4f4a80
    cpu.esp -= 4;
    sub_4f4a80(app, cpu);
    if (cpu.terminate) return;
    // 004eae08  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004eae0a  eba5                   -jmp 0x4eadb1
    goto L_0x004eadb1;
L_0x004eae0c:
    // 004eae0c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eae0e  ff15cc7d5600           -call dword ptr [0x567dcc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eae14  ebbb                   -jmp 0x4eadd1
    goto L_0x004eadd1;
L_0x004eae16:
    // 004eae16  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004eae1b  e880240000             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
    // 004eae20  ebb1                   -jmp 0x4eadd3
    goto L_0x004eadd3;
L_0x004eae22:
    // 004eae22  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004eae27  bff44f5600             -mov edi, 0x564ff4
    cpu.edi = 5656564 /*0x564ff4*/;
    // 004eae2c  ebca                   -jmp 0x4eadf8
    goto L_0x004eadf8;
L_0x004eae2e:
    // 004eae2e  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004eae33  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004eae39  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 004eae3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eae41  e84a430000             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 004eae46  a3f0435600             -mov dword ptr [0x5643f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.eax;
    // 004eae4b  eb9b                   -jmp 0x4eade8
    goto L_0x004eade8;
L_0x004eae4d:
    // 004eae4d  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004eae52  b8f44f5600             -mov eax, 0x564ff4
    cpu.eax = 5656564 /*0x564ff4*/;
    // 004eae57  e8b058ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004eae5c  a048505600             -mov al, byte ptr [0x565048]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656648) /* 0x565048 */);
    // 004eae61  a210505600             -mov byte ptr [0x565010], al
    app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */) = cpu.al;
    // 004eae66  a049505600             -mov al, byte ptr [0x565049]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656649) /* 0x565049 */);
    // 004eae6b  a211505600             -mov byte ptr [0x565011], al
    app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */) = cpu.al;
    // 004eae70  a04a505600             -mov al, byte ptr [0x56504a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656650) /* 0x56504a */);
    // 004eae75  a212505600             -mov byte ptr [0x565012], al
    app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */) = cpu.al;
    // 004eae7a  a15c505600             -mov eax, dword ptr [0x56505c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656668) /* 0x56505c */);
    // 004eae7f  a324505600             -mov dword ptr [0x565024], eax
    app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */) = cpu.eax;
    // 004eae84  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eae86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eae8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4eae90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eae90  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 004eae95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4eaea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eaea0  b864505600             -mov eax, 0x565064
    cpu.eax = 5656676 /*0x565064*/;
    // 004eaea5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eaeb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eaeb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eaeb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eaeb2  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eaeb5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004eaeb7  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004eaebb  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004eaebf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004eaec1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eaec3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004eaec6  8a1d10505600           -mov bl, byte ptr [0x565010]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004eaecc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eaece  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004eaed1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004eaed5  80e3f8                 -and bl, 0xf8
    cpu.bl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
L_0x004eaed8:
    // 004eaed8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eaedc  4a                     -dec edx
    (cpu.edx)--;
    // 004eaedd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004eaee1  83faff                 +cmp edx, -1
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
    // 004eaee4  0f846e000000           -je 0x4eaf58
    if (cpu.flags.zf)
    {
        goto L_0x004eaf58;
    }
    // 004eaeea  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eaeee  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004eaef1  39d6                   +cmp esi, edx
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
    // 004eaef3  7d22                   -jge 0x4eaf17
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004eaf17;
    }
L_0x004eaef5:
    // 004eaef5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004eaef7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eaef9  e8c28c0100             -call 0x503bc0
    cpu.esp -= 4;
    sub_503bc0(app, cpu);
    if (cpu.terminate) return;
    // 004eaefe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eaf00  83fb10                 +cmp ebx, 0x10
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
    // 004eaf03  7315                   -jae 0x4eaf1a
    if (!cpu.flags.cf)
    {
        goto L_0x004eaf1a;
    }
    // 004eaf05  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eaf08  7504                   -jne 0x4eaf0e
    if (!cpu.flags.zf)
    {
        goto L_0x004eaf0e;
    }
    // 004eaf0a  41                     -inc ecx
    (cpu.ecx)++;
L_0x004eaf0b:
    // 004eaf0b  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004eaf0e:
    // 004eaf0e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eaf12  46                     -inc esi
    (cpu.esi)++;
    // 004eaf13  39c6                   +cmp esi, eax
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
    // 004eaf15  7cde                   -jl 0x4eaef5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eaef5;
    }
L_0x004eaf17:
    // 004eaf17  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eaf18  ebbe                   -jmp 0x4eaed8
    goto L_0x004eaed8;
L_0x004eaf1a:
    // 004eaf1a  7713                   -ja 0x4eaf2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004eaf2f;
    }
    // 004eaf1c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004eaf1f  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004eaf23  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eaf27  46                     -inc esi
    (cpu.esi)++;
    // 004eaf28  39c6                   +cmp esi, eax
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
    // 004eaf2a  7cc9                   -jl 0x4eaef5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eaef5;
    }
    // 004eaf2c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eaf2d  eba9                   -jmp 0x4eaed8
    goto L_0x004eaed8;
L_0x004eaf2f:
    // 004eaf2f  83fb18                 +cmp ebx, 0x18
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eaf32  72da                   -jb 0x4eaf0e
    if (cpu.flags.cf)
    {
        goto L_0x004eaf0e;
    }
    // 004eaf34  770b                   -ja 0x4eaf41
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004eaf41;
    }
    // 004eaf36  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
    // 004eaf39  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004eaf3c  c1e810                 +shr eax, 0x10
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
    // 004eaf3f  ebca                   -jmp 0x4eaf0b
    goto L_0x004eaf0b;
L_0x004eaf41:
    // 004eaf41  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eaf44  75c8                   -jne 0x4eaf0e
    if (!cpu.flags.zf)
    {
        goto L_0x004eaf0e;
    }
    // 004eaf46  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eaf49  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004eaf4c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eaf50  46                     -inc esi
    (cpu.esi)++;
    // 004eaf51  39c6                   +cmp esi, eax
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
    // 004eaf53  7ca0                   -jl 0x4eaef5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eaef5;
    }
    // 004eaf55  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eaf56  eb80                   -jmp 0x4eaed8
    goto L_0x004eaed8;
L_0x004eaf58:
    // 004eaf58  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eaf5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaf5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eaf5d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4eaf60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eaf60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eaf61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eaf62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eaf63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eaf65  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004eaf6a  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004eaf6d  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004eaf6f  8b1500505600           -mov edx, dword ptr [0x565000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004eaf75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eaf77  a108505600             -mov eax, dword ptr [0x565008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 004eaf7c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004eaf7e  8b1d04505600           -mov ebx, dword ptr [0x565004]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 004eaf84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eaf86  a10c505600             -mov eax, dword ptr [0x56500c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 004eaf8b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eaf8d  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004eaf90  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004eaf93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eaf95  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004eaf98  c1e203                 +shl edx, 3
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
    // 004eaf9b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004eaf9d  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004eafa0  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 004eafa3  83f908                 +cmp ecx, 8
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
    // 004eafa6  7505                   -jne 0x4eafad
    if (!cpu.flags.zf)
    {
        goto L_0x004eafad;
    }
    // 004eafa8  0500030000             -add eax, 0x300
    (cpu.eax) += x86::reg32(x86::sreg32(768 /*0x300*/));
L_0x004eafad:
    // 004eafad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eafae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eafaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eafb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4eafc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eafc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eafc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eafc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eafc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eafc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eafc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eafc6  81ec08030000           -sub esp, 0x308
    (cpu.esp) -= x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004eafcc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eafce  8b0d08505600           -mov ecx, dword ptr [0x565008]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 004eafd4  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004eafda  8b3d04505600           -mov edi, dword ptr [0x565004]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 004eafe0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004eafe3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eafe5  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eafe7  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004eafed  898c2400030000         -mov dword ptr [esp + 0x300], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.ecx;
    // 004eaff4  8b0d0c505600           -mov ecx, dword ptr [0x56500c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 004eaffa  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004eaffd  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004eafff  80e2f8                 -and dl, 0xf8
    cpu.dl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004eb002  898c2404030000         -mov dword ptr [esp + 0x304], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.ecx;
    // 004eb009  83fa08                 +cmp edx, 8
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
    // 004eb00c  0f85fd000000           -jne 0x4eb10f
    if (!cpu.flags.zf)
    {
        goto L_0x004eb10f;
    }
    // 004eb012  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004eb017:
    // 004eb017  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004eb01a  83fa08                 +cmp edx, 8
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
    // 004eb01d  0f85f3000000           -jne 0x4eb116
    if (!cpu.flags.zf)
    {
        goto L_0x004eb116;
    }
    // 004eb023  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004eb028:
    // 004eb028  66c740030000           -mov word ptr [eax + 3], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004eb02e  884802                 -mov byte ptr [eax + 2], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004eb031  0f85e9000000           -jne 0x4eb120
    if (!cpu.flags.zf)
    {
        goto L_0x004eb120;
    }
    // 004eb037  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
L_0x004eb03c:
    // 004eb03c  66894805               -mov word ptr [eax + 5], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.cx;
    // 004eb040  83fa08                 +cmp edx, 8
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
    // 004eb043  0f85de000000           -jne 0x4eb127
    if (!cpu.flags.zf)
    {
        goto L_0x004eb127;
    }
    // 004eb049  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
L_0x004eb04e:
    // 004eb04e  c6401120               -mov byte ptr [eax + 0x11], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 32 /*0x20*/;
    // 004eb052  668b1d00505600         -mov bx, word ptr [0x565000]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5656576) /* 0x565000 */);
    // 004eb059  884807                 -mov byte ptr [eax + 7], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = cpu.cl;
    // 004eb05c  668b0d0c505600         -mov cx, word ptr [0x56500c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5656588) /* 0x56500c */);
    // 004eb063  66895808               -mov word ptr [eax + 8], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 004eb067  668b1dfc4f5600         -mov bx, word ptr [0x564ffc]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5656572) /* 0x564ffc */);
    // 004eb06e  885010                 -mov byte ptr [eax + 0x10], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004eb071  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eb073  6689580a               -mov word ptr [eax + 0xa], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 004eb077  8b9c2400030000         -mov ebx, dword ptr [esp + 0x300]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004eb07e  6689580c               -mov word ptr [eax + 0xc], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 004eb082  8b9c2404030000         -mov ebx, dword ptr [esp + 0x304]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004eb089  83c612                 -add esi, 0x12
    (cpu.esi) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 004eb08c  6689580e               -mov word ptr [eax + 0xe], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 004eb090  83fa08                 +cmp edx, 8
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
    // 004eb093  753b                   -jne 0x4eb0d0
    if (!cpu.flags.zf)
    {
        goto L_0x004eb0d0;
    }
    // 004eb095  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004eb097  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004eb09c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb09e  e81d8e0100             -call 0x503ec0
    cpu.esp -= 4;
    sub_503ec0(app, cpu);
    if (cpu.terminate) return;
    // 004eb0a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004eb0a5:
    // 004eb0a5  46                     -inc esi
    (cpu.esi)++;
    // 004eb0a6  46                     -inc esi
    (cpu.esi)++;
    // 004eb0a7  8a4c0401               -mov cl, byte ptr [esp + eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004eb0ab  46                     -inc esi
    (cpu.esi)++;
    // 004eb0ac  8a540402               -mov dl, byte ptr [esp + eax + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 004eb0b0  8a1c04                 -mov bl, byte ptr [esp + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 004eb0b3  8856fd                 -mov byte ptr [esi - 3], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */) = cpu.dl;
    // 004eb0b6  884efe                 -mov byte ptr [esi - 2], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.cl;
    // 004eb0b9  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004eb0bc  885eff                 -mov byte ptr [esi - 1], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004eb0bf  3d00030000             +cmp eax, 0x300
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
    // 004eb0c4  75df                   -jne 0x4eb0a5
    if (!cpu.flags.zf)
    {
        goto L_0x004eb0a5;
    }
    // 004eb0c6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004eb0cc  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x004eb0d0:
    // 004eb0d0  8b0d0c505600           -mov ecx, dword ptr [0x56500c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 004eb0d6  8b2d04505600           -mov ebp, dword ptr [0x565004]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 004eb0dc  8b1d08505600           -mov ebx, dword ptr [0x565008]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 004eb0e2  8b1500505600           -mov edx, dword ptr [0x565000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004eb0e8  a100505600             -mov eax, dword ptr [0x565000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004eb0ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb0ee  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004eb0f0  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb0f2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004eb0f4  e8b7fdffff             -call 0x4eaeb0
    cpu.esp -= 4;
    sub_4eaeb0(app, cpu);
    if (cpu.terminate) return;
    // 004eb0f9  803d1050560010         +cmp byte ptr [0x565010], 0x10
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
    // 004eb100  742c                   -je 0x4eb12e
    if (cpu.flags.zf)
    {
        goto L_0x004eb12e;
    }
    // 004eb102  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004eb108  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb109  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb10a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb10b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb10c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb10d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb10e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb10f:
    // 004eb10f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004eb111  e901ffffff             -jmp 0x4eb017
    goto L_0x004eb017;
L_0x004eb116:
    // 004eb116  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004eb11b  e908ffffff             -jmp 0x4eb028
    goto L_0x004eb028;
L_0x004eb120:
    // 004eb120  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004eb122  e915ffffff             -jmp 0x4eb03c
    goto L_0x004eb03c;
L_0x004eb127:
    // 004eb127  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004eb129  e920ffffff             -jmp 0x4eb04e
    goto L_0x004eb04e;
L_0x004eb12e:
    // 004eb12e  8b9c2400030000         -mov ebx, dword ptr [esp + 0x300]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004eb135  0faf9c2404030000       -imul ebx, dword ptr [esp + 0x304]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */))));
    // 004eb13d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004eb13f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb141  e8728f0100             -call 0x5040b8
    cpu.esp -= 4;
    sub_5040b8(app, cpu);
    if (cpu.terminate) return;
    // 004eb146  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004eb14c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb14d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb14e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb14f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb150  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb151  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb152  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4eb160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb165  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004eb168  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004eb16a  e8f1fdffff             -call 0x4eaf60
    cpu.esp -= 4;
    sub_4eaf60(app, cpu);
    if (cpu.terminate) return;
    // 004eb16f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb170  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb172  e85968ffff             -call 0x4e19d0
    cpu.esp -= 4;
    sub_4e19d0(app, cpu);
    if (cpu.terminate) return;
    // 004eb177  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004eb179  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eb17b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb17d  750b                   -jne 0x4eb18a
    if (!cpu.flags.zf)
    {
        goto L_0x004eb18a;
    }
    // 004eb17f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb181  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004eb184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb186  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb189  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb18a:
    // 004eb18a  e831feffff             -call 0x4eafc0
    cpu.esp -= 4;
    sub_4eafc0(app, cpu);
    if (cpu.terminate) return;
    // 004eb18f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004eb191  e83a950000             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 004eb196  e8f5fbffff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004eb19b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004eb19d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004eb19f  e83c390000             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 004eb1a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eb1a6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004eb1a8  e853950000             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 004eb1ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb1ae  e83d68ffff             -call 0x4e19f0
    cpu.esp -= 4;
    sub_4e19f0(app, cpu);
    if (cpu.terminate) return;
    // 004eb1b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb1b5  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004eb1b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4eb1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb1c0  0fb68018485600         -movzx eax, byte ptr [eax + 0x564818]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5654552) /* 0x564818 */));
    // 004eb1c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eb1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb1d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb1d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb1d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb1d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb1d5  2eff1590445300         -call dword ptr cs:[0x534490]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457040) /* 0x534490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb1dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb1de  7508                   -jne 0x4eb1e8
    if (!cpu.flags.zf)
    {
        goto L_0x004eb1e8;
    }
    // 004eb1e0  e80f5e0100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004eb1e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb1e8:
    // 004eb1e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb1ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb1ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4eb1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb1f0  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb1f6  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb1f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4eb1fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb1fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb1fd  e8eeffffff             -call 0x4eb1f0
    cpu.esp -= 4;
    sub_4eb1f0(app, cpu);
    if (cpu.terminate) return;
    // 004eb202  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb204  7418                   -je 0x4eb21e
    if (cpu.flags.zf)
    {
        goto L_0x004eb21e;
    }
    // 004eb206  69106d4ec641           -imul edx, dword ptr [eax], 0x41c64e6d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))) * x86::sreg64(x86::sreg32(1103515245 /*0x41c64e6d*/)));
    // 004eb20c  81c239300000           -add edx, 0x3039
    (cpu.edx) += x86::reg32(x86::sreg32(12345 /*0x3039*/));
    // 004eb212  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004eb214  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eb216  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004eb219  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
L_0x004eb21e:
    // 004eb21e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb21f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4eb220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eb223  e8c8ffffff             -call 0x4eb1f0
    cpu.esp -= 4;
    sub_4eb1f0(app, cpu);
    if (cpu.terminate) return;
    // 004eb228  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb22a  7402                   -je 0x4eb22e
    if (cpu.flags.zf)
    {
        goto L_0x004eb22e;
    }
    // 004eb22c  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004eb22e:
    // 004eb22e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb22f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4eb230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb230  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb231  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb232  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb235  e84e5bffff             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 004eb23a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb23c  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb241  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004eb245  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004eb248  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004eb24b  dc0d34b75400           -fmul qword ptr [0x54b734]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5551924) /* 0x54b734 */));
    // 004eb251  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb254  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb255  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb256  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eb260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb262  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb263  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb266  8b1d644a5600           -mov ebx, dword ptr [0x564a64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */);
    // 004eb26c  8b35604a5600           -mov esi, dword ptr [0x564a60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655136) /* 0x564a60 */);
    // 004eb272  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb274  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004eb277  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004eb27a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004eb27c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004eb27e  e88d5e0100             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004eb283  8b35604a5600           -mov esi, dword ptr [0x564a60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655136) /* 0x564a60 */);
    // 004eb289  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb28b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb28d  7434                   -je 0x4eb2c3
    if (cpu.flags.zf)
    {
        goto L_0x004eb2c3;
    }
    // 004eb28f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb290  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb294  c1ee05                 -shr esi, 5
    cpu.esi >>= 5 /*0x5*/ % 32;
    // 004eb297  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb299  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eb29b  7e23                   -jle 0x4eb2c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004eb2c0;
    }
L_0x004eb29d:
    // 004eb29d  c7431c45455246         -mov dword ptr [ebx + 0x1c], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1179796805 /*0x46524545*/;
    // 004eb2a4  42                     -inc edx
    (cpu.edx)++;
    // 004eb2a5  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004eb2a8  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004eb2aa  83c320                 -add ebx, 0x20
    (cpu.ebx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004eb2ad  39f2                   +cmp edx, esi
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
    // 004eb2af  7cec                   -jl 0x4eb29d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eb29d;
    }
    // 004eb2b1  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004eb2b7  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004eb2bd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004eb2c0:
    // 004eb2c0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004eb2c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004eb2c3:
    // 004eb2c3  8935604a5600           -mov dword ptr [0x564a60], esi
    app->getMemory<x86::reg32>(x86::reg32(5655136) /* 0x564a60 */) = cpu.esi;
    // 004eb2c9  891d644a5600           -mov dword ptr [0x564a64], ebx
    app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */) = cpu.ebx;
    // 004eb2cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb2d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb2d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb2d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb2d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4eb2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb2e1  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb2e8  741c                   -je 0x4eb306
    if (cpu.flags.zf)
    {
        goto L_0x004eb306;
    }
L_0x004eb2ea:
    // 004eb2ea  833d644a560000         +cmp dword ptr [0x564a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb2f1  7505                   -jne 0x4eb2f8
    if (!cpu.flags.zf)
    {
        goto L_0x004eb2f8;
    }
    // 004eb2f3  e868ffffff             -call 0x4eb260
    cpu.esp -= 4;
    sub_4eb260(app, cpu);
    if (cpu.terminate) return;
L_0x004eb2f8:
    // 004eb2f8  8b1d644a5600           -mov ebx, dword ptr [0x564a64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */);
    // 004eb2fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eb300  750d                   -jne 0x4eb30f
    if (!cpu.flags.zf)
    {
        goto L_0x004eb30f;
    }
    // 004eb302  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb305  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb306:
    // 004eb306  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004eb308  e83344ffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004eb30d  ebdb                   -jmp 0x4eb2ea
    goto L_0x004eb2ea;
L_0x004eb30f:
    // 004eb30f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb310  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb311  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004eb314  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004eb319  a3644a5600             -mov dword ptr [0x564a64], eax
    app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */) = cpu.eax;
    // 004eb31e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb320  e8e753ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004eb325  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb326  2eff1584455300         -call dword ptr cs:[0x534584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457284) /* 0x534584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb32d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb32f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb330  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb331  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb332  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4eb340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb340  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb341  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb342  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb343  2eff15b8445300         -call dword ptr cs:[0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb34a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb34b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb34c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4eb350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb352  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb353  2eff1588455300         -call dword ptr cs:[0x534588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb35a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb35b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb35c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4eb360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb361  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb363  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb365  7502                   -jne 0x4eb369
    if (!cpu.flags.zf)
    {
        goto L_0x004eb369;
    }
    // 004eb367  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb368  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb369:
    // 004eb369  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb36a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb36b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb36c  2eff15ac445300         -call dword ptr cs:[0x5344ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457068) /* 0x5344ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb373  a1644a5600             -mov eax, dword ptr [0x564a64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */);
    // 004eb378  c7431c45455246         -mov dword ptr [ebx + 0x1c], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1179796805 /*0x46524545*/;
    // 004eb37f  891d644a5600           -mov dword ptr [0x564a64], ebx
    app->getMemory<x86::reg32>(x86::reg32(5655140) /* 0x564a64 */) = cpu.ebx;
    // 004eb385  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004eb388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb389  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb38a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb38b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4eb390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb391  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eb393  7504                   -jne 0x4eb399
    if (!cpu.flags.zf)
    {
        goto L_0x004eb399;
    }
L_0x004eb395:
    // 004eb395  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb397  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb398  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb399:
    // 004eb399  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004eb39b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004eb39d  38e9                   +cmp cl, ch
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004eb39f  740e                   -je 0x4eb3af
    if (cpu.flags.zf)
    {
        goto L_0x004eb3af;
    }
    // 004eb3a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eb3a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb3a5  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 004eb3a7  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 004eb3a9  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb3ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb3ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb3ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb3af:
    // 004eb3af  803800                 +cmp byte ptr [eax], 0
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
    // 004eb3b2  7504                   -jne 0x4eb3b8
    if (!cpu.flags.zf)
    {
        goto L_0x004eb3b8;
    }
    // 004eb3b4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004eb3b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb3b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb3b8:
    // 004eb3b8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eb3b9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eb3ba  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004eb3bb  74d8                   -je 0x4eb395
    if (cpu.flags.zf)
    {
        goto L_0x004eb395;
    }
    // 004eb3bd  ebda                   -jmp 0x4eb399
    goto L_0x004eb399;
}

/* align: skip 0x00 */
void Application::sub_4eb3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb3c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb3c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb3c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb3c3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb3c6  8b15d04e5600           -mov edx, dword ptr [0x564ed0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656272) /* 0x564ed0 */);
    // 004eb3cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eb3ce  7542                   -jne 0x4eb412
    if (!cpu.flags.zf)
    {
        goto L_0x004eb412;
    }
    // 004eb3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb3d1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004eb3d6  891590f99e00           -mov dword ptr [0x9ef990], edx
    app->getMemory<x86::reg32>(x86::reg32(10418576) /* 0x9ef990 */) = cpu.edx;
    // 004eb3dc  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004eb3e0  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004eb3e5  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004eb3e9  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb3ed  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb3f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004eb3f2:
    // 004eb3f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb3f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb3f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb3f5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb3f8  e863830100             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 004eb3fd  40                     -inc eax
    (cpu.eax)++;
    // 004eb3fe  89828cf99e00           -mov dword ptr [edx + 0x9ef98c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418572) /* 0x9ef98c */) = cpu.eax;
    // 004eb404  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb40a  75e6                   -jne 0x4eb3f2
    if (!cpu.flags.zf)
    {
        goto L_0x004eb3f2;
    }
    // 004eb40c  ff05d04e5600           -inc dword ptr [0x564ed0]
    (app->getMemory<x86::reg32>(x86::reg32(5656272) /* 0x564ed0 */))++;
L_0x004eb412:
    // 004eb412  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb415  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb416  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb417  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb418  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eb420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb420  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb422  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb424  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb426  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb428  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb433  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb436  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004eb438  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb43a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb43b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb43f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb441  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004eb445  e83c8a0400             -call 0x533e86
    cpu.esp -= 4;
    sub_533e86(app, cpu);
    if (cpu.terminate) return;
    // 004eb44a  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb44f  8b0d3c3d9f00           -mov ecx, dword ptr [0x9f3d3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */);
    // 004eb455  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb456  41                     -inc ecx
    (cpu.ecx)++;
    // 004eb457  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb458  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb45c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb45d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb45e  683cb75400             -push 0x54b73c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551932 /*0x54b73c*/;
    cpu.esp -= 4;
    // 004eb463  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004eb465  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb46a  890d3c3d9f00           -mov dword ptr [0x9f3d3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */) = cpu.ecx;
    // 004eb470  e8db5b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb475  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004eb478  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004eb47b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb47e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb47f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb480  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb481  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4eb430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004eb430;
    // 004eb420  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb422  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb424  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb426  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb428  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004eb42e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004eb430:
    // 004eb430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb433  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb436  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004eb438  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb43a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb43b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb43f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb441  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004eb445  e83c8a0400             -call 0x533e86
    cpu.esp -= 4;
    sub_533e86(app, cpu);
    if (cpu.terminate) return;
    // 004eb44a  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb44f  8b0d3c3d9f00           -mov ecx, dword ptr [0x9f3d3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */);
    // 004eb455  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb456  41                     -inc ecx
    (cpu.ecx)++;
    // 004eb457  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb458  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb45c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb45d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb45e  683cb75400             -push 0x54b73c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551932 /*0x54b73c*/;
    cpu.esp -= 4;
    // 004eb463  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004eb465  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb46a  890d3c3d9f00           -mov dword ptr [0x9f3d3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */) = cpu.ecx;
    // 004eb470  e8db5b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb475  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004eb478  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004eb47b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004eb47e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb47f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb480  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb481  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4eb490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb491  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb492  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb493  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb494  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb495  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb498  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eb49a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004eb49d  687cb75400             -push 0x54b77c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5551996 /*0x54b77c*/;
    cpu.esp -= 4;
    // 004eb4a2  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004eb4a4  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb4a9  e8a25b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb4ae  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb4b1  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb4b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb4b5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb4b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb4bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb4bc  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004eb4bf  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004eb4c5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb4c7  48                     -dec eax
    (cpu.eax)--;
    // 004eb4c8  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004eb4cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb4cc  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004eb4cf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb4d1  e8aa1f0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 004eb4d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb4d8  7409                   -je 0x4eb4e3
    if (cpu.flags.zf)
    {
        goto L_0x004eb4e3;
    }
L_0x004eb4da:
    // 004eb4da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb4dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb4de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb4df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb4e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb4e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb4e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb4e3:
    // 004eb4e3  68a8b75400             -push 0x54b7a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552040 /*0x54b7a8*/;
    cpu.esp -= 4;
    // 004eb4e8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb4ec  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004eb4ee  80e4b7                 -and ah, 0xb7
    cpu.ah &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 004eb4f1  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb4f6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004eb4fa  e8515b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb4ff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb502  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb505  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb506  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb50a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb50c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb50d  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004eb510  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004eb516  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb518  48                     -dec eax
    (cpu.eax)--;
    // 004eb519  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004eb51c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb51d  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004eb520  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb522  e8591f0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 004eb527  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb529  7549                   -jne 0x4eb574
    if (!cpu.flags.zf)
    {
        goto L_0x004eb574;
    }
    // 004eb52b  f644240140             +test byte ptr [esp + 1], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 64 /*0x40*/));
    // 004eb530  0f849f000000           -je 0x4eb5d5
    if (cpu.flags.zf)
    {
        goto L_0x004eb5d5;
    }
    // 004eb536  804c240508             -or byte ptr [esp + 5], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004eb53b:
    // 004eb53b  68ccb75400             -push 0x54b7cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552076 /*0x54b7cc*/;
    cpu.esp -= 4;
    // 004eb540  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004eb542  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb547  e8045b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb54c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb54f  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb552  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb553  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb557  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb558  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb55a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004eb55d  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004eb563  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb565  48                     -dec eax
    (cpu.eax)--;
    // 004eb566  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004eb569  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb56a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004eb56d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb56f  e80c1f0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
L_0x004eb574:
    // 004eb574  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb576  0f855effffff           -jne 0x4eb4da
    if (!cpu.flags.zf)
    {
        goto L_0x004eb4da;
    }
    // 004eb57c  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004eb583  0f8651ffffff           -jbe 0x4eb4da
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004eb4da;
    }
    // 004eb589  68fcb75400             -push 0x54b7fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552124 /*0x54b7fc*/;
    cpu.esp -= 4;
    // 004eb58e  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004eb590  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb595  e8b65a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb59a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb59d  8a7c2405               -mov bh, byte ptr [esp + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 004eb5a1  80e7b7                 -and bh, 0xb7
    cpu.bh &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 004eb5a4  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb5a7  887c2405               -mov byte ptr [esp + 5], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.bh;
    // 004eb5ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb5ac  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eb5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb5b1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eb5b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb5b5  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004eb5b8  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004eb5bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb5bd  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004eb5c0  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 004eb5c7  e8b41e0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 004eb5cc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb5cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb5d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb5d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb5d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb5d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb5d5:
    // 004eb5d5  804c240540             +or byte ptr [esp + 5], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004eb5da  e95cffffff             -jmp 0x4eb53b
    goto L_0x004eb53b;
}

/* align: skip 0x90 */
void Application::sub_4eb5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb5e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb5e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb5e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb5e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb5e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eb5e6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004eb5e8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004eb5ea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb5ec  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004eb5ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb5ef  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 004eb5f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb5f7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004eb5f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb5fa  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb5fd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb5ff  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb605  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eb607  7408                   -je 0x4eb611
    if (cpu.flags.zf)
    {
        goto L_0x004eb611;
    }
    // 004eb609  81fbc2010000           +cmp ebx, 0x1c2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(450 /*0x1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb60f  7407                   -je 0x4eb618
    if (cpu.flags.zf)
    {
        goto L_0x004eb618;
    }
L_0x004eb611:
    // 004eb611  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb613  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb616  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb617  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb618:
    // 004eb618  6824b85400             -push 0x54b824
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552164 /*0x54b824*/;
    cpu.esp -= 4;
    // 004eb61d  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004eb61f  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb624  e8275a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb629  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb62c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004eb62e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb62f  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb632  8b9644040000           -mov edx, dword ptr [esi + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004eb638  39d7                   +cmp edi, edx
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
    // 004eb63a  7416                   -je 0x4eb652
    if (cpu.flags.zf)
    {
        goto L_0x004eb652;
    }
    // 004eb63c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb63d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004eb63f  ff5360                 -call dword ptr [ebx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb642  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb644  740c                   -je 0x4eb652
    if (cpu.flags.zf)
    {
        goto L_0x004eb652;
    }
    // 004eb646  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004eb64c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb64d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004eb64f  ff536c                 -call dword ptr [ebx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004eb652:
    // 004eb652  8b8e48040000           -mov ecx, dword ptr [esi + 0x448]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004eb658  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004eb65a  741a                   -je 0x4eb676
    if (cpu.flags.zf)
    {
        goto L_0x004eb676;
    }
    // 004eb65c  39cf                   +cmp edi, ecx
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
    // 004eb65e  7416                   -je 0x4eb676
    if (cpu.flags.zf)
    {
        goto L_0x004eb676;
    }
    // 004eb660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb661  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004eb663  ff5360                 -call dword ptr [ebx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb666  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb668  740c                   -je 0x4eb676
    if (cpu.flags.zf)
    {
        goto L_0x004eb676;
    }
    // 004eb66a  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004eb670  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb671  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004eb673  ff536c                 -call dword ptr [ebx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004eb676:
    // 004eb676  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb677  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004eb679  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb67c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb67e  0f8575010000           -jne 0x4eb7f9
    if (!cpu.flags.zf)
    {
        goto L_0x004eb7f9;
    }
    // 004eb684  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb686  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004eb688  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb689  c745006c000000         -mov dword ptr [ebp], 0x6c
    app->getMemory<x86::reg32>(cpu.ebp) = 108 /*0x6c*/;
    // 004eb690  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb692  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004eb694  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb695  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb698  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb69a  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb6a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb6a1  6848b85400             -push 0x54b848
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552200 /*0x54b848*/;
    cpu.esp -= 4;
    // 004eb6a6  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004eb6a8  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb6ad  e89e590100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb6b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004eb6b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eb6b7  7463                   -je 0x4eb71c
    if (cpu.flags.zf)
    {
        goto L_0x004eb71c;
    }
    // 004eb6b9  6860b85400             -push 0x54b860
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552224 /*0x54b860*/;
    cpu.esp -= 4;
    // 004eb6be  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004eb6c0  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb6c5  e886590100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb6ca  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb6cd  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004eb6d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb6d3  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb6d9  e802ce0100             -call 0x5084e0
    cpu.esp -= 4;
    sub_5084e0(app, cpu);
    if (cpu.terminate) return;
    // 004eb6de  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004eb6e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb6e5  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb6eb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb6ed  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004eb6ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb6f0  c745006c000000         -mov dword ptr [ebp], 0x6c
    app->getMemory<x86::reg32>(cpu.ebp) = 108 /*0x6c*/;
    // 004eb6f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb6f9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004eb6fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb6fc  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb6ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb701  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb707  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb708  6884b85400             -push 0x54b884
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552260 /*0x54b884*/;
    cpu.esp -= 4;
    // 004eb70d  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004eb70f  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb714  e837590100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb719  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004eb71c:
    // 004eb71c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eb71e  0f85edfeffff           -jne 0x4eb611
    if (!cpu.flags.zf)
    {
        goto L_0x004eb611;
    }
    // 004eb724  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004eb72b  0f85a8000000           -jne 0x4eb7d9
    if (!cpu.flags.zf)
    {
        goto L_0x004eb7d9;
    }
L_0x004eb731:
    // 004eb731  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 004eb735  7474                   -je 0x4eb7ab
    if (cpu.flags.zf)
    {
        goto L_0x004eb7ab;
    }
    // 004eb737  8d7e30                 -lea edi, [esi + 0x30]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004eb73a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb73b  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004eb740  66c78632040000ffff     -mov word ptr [esi + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 004eb749  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb74b  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb74e  66c786300400000001     -mov word ptr [esi + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004eb757  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004eb759  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004eb75b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb75c  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb75f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb761  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb767  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb768  68a0b85400             -push 0x54b8a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552288 /*0x54b8a0*/;
    cpu.esp -= 4;
    // 004eb76d  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 004eb76f  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb774  e8d7580100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb779  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004eb77c  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004eb77f  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004eb785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb786  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004eb788  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eb789  ff537c                 -call dword ptr [ebx + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb78c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eb78e  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004eb794  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb795  68c4b85400             -push 0x54b8c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552324 /*0x54b8c4*/;
    cpu.esp -= 4;
    // 004eb79a  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 004eb79c  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb7a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eb7a3  e8a8580100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb7a8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004eb7ab:
    // 004eb7ab  68e0b85400             -push 0x54b8e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552352 /*0x54b8e0*/;
    cpu.esp -= 4;
    // 004eb7b0  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004eb7b2  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eb7b7  e894580100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eb7bc  a184715600             -mov eax, dword ptr [0x567184]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    // 004eb7c1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eb7c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb7c6  0f8445feffff           -je 0x4eb611
    if (cpu.flags.zf)
    {
        goto L_0x004eb611;
    }
    // 004eb7cc  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb7d2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb7d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb7d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb7d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb7d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb7d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb7d9:
    // 004eb7d9  e842d90000             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 004eb7de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb7e0  0f854bffffff           -jne 0x4eb731
    if (!cpu.flags.zf)
    {
        goto L_0x004eb731;
    }
    // 004eb7e6  8b8e54040000           -mov ecx, dword ptr [esi + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 004eb7ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eb7ed  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eb7f4  e938ffffff             -jmp 0x4eb731
    goto L_0x004eb731;
L_0x004eb7f9:
    // 004eb7f9  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 004eb7fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eb800  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb801  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb802  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb803  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb804  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4eb810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb810  3b05143d9f00           +cmp eax, dword ptr [0x9f3d14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10435860) /* 0x9f3d14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb816  7401                   -je 0x4eb819
    if (cpu.flags.zf)
    {
        goto L_0x004eb819;
    }
    // 004eb818  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb819:
    // 004eb819  a1343d9f00             -mov eax, dword ptr [0x9f3d34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */);
    // 004eb81e  0102                   -add dword ptr [edx], eax
    (app->getMemory<x86::reg32>(cpu.edx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb820  a1383d9f00             -mov eax, dword ptr [0x9f3d38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */);
    // 004eb825  0103                   -add dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb827  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4eb830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb831  3b05143d9f00           +cmp eax, dword ptr [0x9f3d14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10435860) /* 0x9f3d14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb837  7402                   -je 0x4eb83b
    if (cpu.flags.zf)
    {
        goto L_0x004eb83b;
    }
    // 004eb839  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb83a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb83b:
    // 004eb83b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb83c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb83d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eb83e  a1343d9f00             -mov eax, dword ptr [0x9f3d34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */);
    // 004eb843  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004eb845  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004eb848  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004eb84b  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004eb84e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb850  a1383d9f00             -mov eax, dword ptr [0x9f3d38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */);
    // 004eb855  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004eb857  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb859  a1343d9f00             -mov eax, dword ptr [0x9f3d34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */);
    // 004eb85e  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004eb861  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb863  a1383d9f00             -mov eax, dword ptr [0x9f3d38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */);
    // 004eb868  897a08                 -mov dword ptr [edx + 8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004eb86b  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb86d  896a0c                 -mov dword ptr [edx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004eb870  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb871  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb872  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb873  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb874  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4eb880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb880  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eb881  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eb883  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb885  740f                   -je 0x4eb896
    if (cpu.flags.zf)
    {
        goto L_0x004eb896;
    }
    // 004eb887  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x004eb888:
    // 004eb888  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eb88a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004eb88c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004eb88e  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eb890  42                     -inc edx
    (cpu.edx)++;
    // 004eb891  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eb893  75f3                   -jne 0x4eb888
    if (!cpu.flags.zf)
    {
        goto L_0x004eb888;
    }
    // 004eb895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004eb896:
    // 004eb896  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eb898  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb899  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4eb8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eb8a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eb8a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eb8a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eb8a3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb8a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eb8a8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004eb8aa  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 004eb8ae  0f844a010000           -je 0x4eb9fe
    if (cpu.flags.zf)
    {
        goto L_0x004eb9fe;
    }
    // 004eb8b4  837b5410               +cmp dword ptr [ebx + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eb8b8  0f8440010000           -je 0x4eb9fe
    if (cpu.flags.zf)
    {
        goto L_0x004eb9fe;
    }
    // 004eb8be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eb8c0  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004eb8c3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004eb8c7:
    // 004eb8c7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eb8c9  0f8cdd000000           -jl 0x4eb9ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eb9ac;
    }
    // 004eb8cf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb8d6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eb8d8  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb8db  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004eb8de  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004eb8e1  890c28                 -mov dword ptr [eax + ebp], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1) = cpu.ecx;
    // 004eb8e4  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb8e7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb8e9  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004eb8ec  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004eb8ef  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004eb8f2  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004eb8f5  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb8f8  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb8fa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004eb8fd  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004eb900  8a4b54                 -mov cl, byte ptr [ebx + 0x54]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004eb903  884d12                 -mov byte ptr [ebp + 0x12], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.cl;
    // 004eb906  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb909  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb90d  884c2813               -mov byte ptr [eax + ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */ + cpu.ebp * 1) = cpu.cl;
    // 004eb911  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb914  66c74401100100         -mov word ptr [ecx + eax + 0x10], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 004eb91b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb91e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb920  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004eb923  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004eb926  8b0dd84e5600           -mov ecx, dword ptr [0x564ed8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656280) /* 0x564ed8 */);
    // 004eb92c  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004eb92f  f6430604               +test byte ptr [ebx + 6], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) & 4 /*0x4*/));
    // 004eb933  740b                   -je 0x4eb940
    if (cpu.flags.zf)
    {
        goto L_0x004eb940;
    }
    // 004eb935  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb938  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eb93a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004eb93d  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004eb940:
    // 004eb940  f6430420               +test byte ptr [ebx + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 004eb944  741b                   -je 0x4eb961
    if (cpu.flags.zf)
    {
        goto L_0x004eb961;
    }
    // 004eb946  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb94d  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004eb950  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004eb953  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb956  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004eb958  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004eb95a  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004eb95d  66014810               -add word ptr [eax + 0x10], cx
    (app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.cx));
L_0x004eb961:
    // 004eb961  f6430480               +test byte ptr [ebx + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 004eb965  7411                   -je 0x4eb978
    if (cpu.flags.zf)
    {
        goto L_0x004eb978;
    }
    // 004eb967  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb96e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb971  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eb973  804c810c01             -or byte ptr [ecx + eax*4 + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004eb978:
    // 004eb978  f6430440               +test byte ptr [ebx + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 64 /*0x40*/));
    // 004eb97c  7411                   -je 0x4eb98f
    if (cpu.flags.zf)
    {
        goto L_0x004eb98f;
    }
    // 004eb97e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb985  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb988  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eb98a  804c810c02             -or byte ptr [ecx + eax*4 + 0xc], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004eb98f:
    // 004eb98f  f6430401               +test byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 004eb993  7417                   -je 0x4eb9ac
    if (cpu.flags.zf)
    {
        goto L_0x004eb9ac;
    }
    // 004eb995  f6436a20               +test byte ptr [ebx + 0x6a], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(106) /* 0x6a */) & 32 /*0x20*/));
    // 004eb999  7411                   -je 0x4eb9ac
    if (cpu.flags.zf)
    {
        goto L_0x004eb9ac;
    }
    // 004eb99b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb9a2  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb9a5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eb9a7  804c810c04             -or byte ptr [ecx + eax*4 + 0xc], 4
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004eb9ac:
    // 004eb9ac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004eb9ae  7447                   -je 0x4eb9f7
    if (cpu.flags.zf)
    {
        goto L_0x004eb9f7;
    }
    // 004eb9b0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eb9b2  7c1e                   -jl 0x4eb9d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eb9d2;
    }
    // 004eb9b4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004eb9bb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eb9bd  8a9660040000           -mov dl, byte ptr [esi + 0x460]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
    // 004eb9c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004eb9c6  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004eb9c8  755b                   -jne 0x4eba25
    if (!cpu.flags.zf)
    {
        goto L_0x004eba25;
    }
    // 004eb9ca  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eb9cd  8064020cef             -and byte ptr [edx + eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x004eb9d2:
    // 004eb9d2  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004eb9d9  740c                   -je 0x4eb9e7
    if (cpu.flags.zf)
    {
        goto L_0x004eb9e7;
    }
    // 004eb9db  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004eb9de  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004eb9e1  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004eb9e4  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004eb9e7:
    // 004eb9e7  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004eb9ea  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004eb9ed  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eb9f1  88865c040000           -mov byte ptr [esi + 0x45c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */) = cpu.al;
L_0x004eb9f7:
    // 004eb9f7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004eb9fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb9fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb9fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eb9fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eb9fe:
    // 004eb9fe  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004eba01  e87afeffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004eba06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eba08  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 004eba0b  e870feffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004eba10  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004eba12  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 004eba15  e866feffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004eba1a  01c1                   +add ecx, eax
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
    // 004eba1c  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004eba20  e9a2feffff             -jmp 0x4eb8c7
    goto L_0x004eb8c7;
L_0x004eba25:
    // 004eba25  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004eba28  804c020c10             +or byte ptr [edx + eax + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004eba2d  eba3                   -jmp 0x4eb9d2
    goto L_0x004eb9d2;
}

/* align: skip 0x90 */
void Application::sub_4eba30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eba30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eba31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eba32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eba33  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004eba36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eba38  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004eba3a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004eba3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eba3d  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004eba43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eba44  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eba4b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eba4f  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004eba52  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eba54  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004eba56  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004eba5a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eba5e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004eba60  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004eba62  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004eba65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eba66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eba67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eba68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4eba70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eba70  a1243d9f00             -mov eax, dword ptr [0x9f3d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004eba75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4eba80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eba80  a13c3d9f00             -mov eax, dword ptr [0x9f3d3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */);
    // 004eba85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4eba90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eba90  a1d0389f00             -mov eax, dword ptr [0x9f38d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 004eba95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ebaa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ebaa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebaa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebaa2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebaa4  7414                   -je 0x4ebaba
    if (cpu.flags.zf)
    {
        goto L_0x004ebaba;
    }
    // 004ebaa6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ebaa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebaa9  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004ebaaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebab0  2eff1598475300         -call dword ptr cs:[0x534798]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457816) /* 0x534798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebab7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebab9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ebaba:
    // 004ebaba  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004ebabf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebac0  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004ebac6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebac7  2eff1598475300         -call dword ptr cs:[0x534798]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457816) /* 0x534798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebace  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebacf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebad0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4ebae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ebae0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebae1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebae2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebae3  6880db4e00             -push 0x4edb80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5168000 /*0x4edb80*/;
    cpu.esp -= 4;
    // 004ebae8  e893830400             -call 0x533e80
    cpu.esp -= 4;
    sub_533e80(app, cpu);
    if (cpu.terminate) return;
    // 004ebaed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebaee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebaef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ebaf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ebaf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ebaf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebaf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebaf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebaf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ebaf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ebaf6  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebafc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ebafe  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ebb00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebb02  7505                   -jne 0x4ebb09
    if (!cpu.flags.zf)
    {
        goto L_0x004ebb09;
    }
    // 004ebb04  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x004ebb09:
    // 004ebb09  833d8044560000         +cmp dword ptr [0x564480], 0
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
    // 004ebb10  750a                   -jne 0x4ebb1c
    if (!cpu.flags.zf)
    {
        goto L_0x004ebb1c;
    }
    // 004ebb12  e8c9f7ffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004ebb17  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
L_0x004ebb1c:
    // 004ebb1c  ba90099f00             -mov edx, 0x9f0990
    cpu.edx = 10422672 /*0x9f0990*/;
    // 004ebb21  a190099f00             -mov eax, dword ptr [0x9f0990]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10422672) /* 0x9f0990 */);
    // 004ebb26  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ebb29  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ebb2c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ebb2e  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004ebb31  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004ebb33  8a1590435600           -mov dl, byte ptr [0x564390]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 004ebb39  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ebb3b  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 004ebb3e  7549                   -jne 0x4ebb89
    if (!cpu.flags.zf)
    {
        goto L_0x004ebb89;
    }
    // 004ebb40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebb42  7422                   -je 0x4ebb66
    if (cpu.flags.zf)
    {
        goto L_0x004ebb66;
    }
    // 004ebb44  68f8b85400             -push 0x54b8f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552376 /*0x54b8f8*/;
    cpu.esp -= 4;
    // 004ebb49  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebb4b  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebb50  e8fb540100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebb55  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ebb58  ba90099f00             -mov edx, 0x9f0990
    cpu.edx = 10422672 /*0x9f0990*/;
    // 004ebb5d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ebb5f  e8ccf8ffff             -call 0x4eb430
    cpu.esp -= 4;
    sub_4eb430(app, cpu);
    if (cpu.terminate) return;
    // 004ebb64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ebb66:
    // 004ebb66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ebb68  751f                   -jne 0x4ebb89
    if (!cpu.flags.zf)
    {
        goto L_0x004ebb89;
    }
    // 004ebb6a  6818b95400             -push 0x54b918
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552408 /*0x54b918*/;
    cpu.esp -= 4;
    // 004ebb6f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebb71  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebb76  e8d5540100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebb7b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ebb7e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ebb80  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ebb82  e8a9f8ffff             -call 0x4eb430
    cpu.esp -= 4;
    sub_4eb430(app, cpu);
    if (cpu.terminate) return;
    // 004ebb87  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ebb89:
    // 004ebb89  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ebb8b  0f845e010000           -je 0x4ebcef
    if (cpu.flags.zf)
    {
        goto L_0x004ebcef;
    }
L_0x004ebb91:
    // 004ebb91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ebb92  6828b95600             -push 0x56b928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683496 /*0x56b928*/;
    cpu.esp -= 4;
    // 004ebb97  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebb99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebb9a  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebb9c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ebb9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebb9f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebba1  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ebba7  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebbaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ebbab  6860b95400             -push 0x54b960
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552480 /*0x54b960*/;
    cpu.esp -= 4;
    // 004ebbb0  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004ebbb2  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebbb7  e894540100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebbbc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ebbbf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ebbc1  0f856e010000           -jne 0x4ebd35
    if (!cpu.flags.zf)
    {
        goto L_0x004ebd35;
    }
    // 004ebbc7  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 004ebbcc  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004ebbce  8994246c010000         -mov dword ptr [esp + 0x16c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.edx;
    // 004ebbd5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ebbd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebbd9  8db42470010000         -lea esi, [esp + 0x170]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004ebbe0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ebbe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebbe3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ebbe5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebbe6  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebbe9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ebbee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebbef  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ebbf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebbf4  8bbc2478010000         -mov edi, dword ptr [esp + 0x178]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 004ebbfb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ebbfc  688cb95400             -push 0x54b98c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552524 /*0x54b98c*/;
    cpu.esp -= 4;
    // 004ebc01  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004ebc03  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebc08  e843540100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebc0d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ebc10  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ebc12  8ab42473010000         -mov dh, byte ptr [esp + 0x173]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */);
    // 004ebc19  892dd84e5600           -mov dword ptr [0x564ed8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5656280) /* 0x564ed8 */) = cpu.ebp;
    // 004ebc1f  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 004ebc22  740a                   -je 0x4ebc2e
    if (cpu.flags.zf)
    {
        goto L_0x004ebc2e;
    }
    // 004ebc24  c705d84e560008000000   -mov dword ptr [0x564ed8], 8
    app->getMemory<x86::reg32>(x86::reg32(5656280) /* 0x564ed8 */) = 8 /*0x8*/;
L_0x004ebc2e:
    // 004ebc2e  f684247201000008       +test byte ptr [esp + 0x172], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(370) /* 0x172 */) & 8 /*0x8*/));
    // 004ebc36  7407                   -je 0x4ebc3f
    if (cpu.flags.zf)
    {
        goto L_0x004ebc3f;
    }
    // 004ebc38  800dd94e560008         -or byte ptr [0x564ed9], 8
    app->getMemory<x86::reg8>(x86::reg32(5656281) /* 0x564ed9 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004ebc3f:
    // 004ebc3f  f684247001000001       +test byte ptr [esp + 0x170], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 1 /*0x1*/));
    // 004ebc47  7407                   -je 0x4ebc50
    if (cpu.flags.zf)
    {
        goto L_0x004ebc50;
    }
    // 004ebc49  800dd84e560020         -or byte ptr [0x564ed8], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5656280) /* 0x564ed8 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004ebc50:
    // 004ebc50  8a942470010000         -mov dl, byte ptr [esp + 0x170]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004ebc57  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004ebc5a  0f85c7000000           -jne 0x4ebd27
    if (!cpu.flags.zf)
    {
        goto L_0x004ebd27;
    }
L_0x004ebc60:
    // 004ebc60  f684247001000040       +test byte ptr [esp + 0x170], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 64 /*0x40*/));
    // 004ebc68  7407                   -je 0x4ebc71
    if (cpu.flags.zf)
    {
        goto L_0x004ebc71;
    }
    // 004ebc6a  800dd84e560040         -or byte ptr [0x564ed8], 0x40
    app->getMemory<x86::reg8>(x86::reg32(5656280) /* 0x564ed8 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004ebc71:
    // 004ebc71  f684247301000004       +test byte ptr [esp + 0x173], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 4 /*0x4*/));
    // 004ebc79  7407                   -je 0x4ebc82
    if (cpu.flags.zf)
    {
        goto L_0x004ebc82;
    }
    // 004ebc7b  800dd84e560080         -or byte ptr [0x564ed8], 0x80
    app->getMemory<x86::reg8>(x86::reg32(5656280) /* 0x564ed8 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004ebc82:
    // 004ebc82  f684247101000002       +test byte ptr [esp + 0x171], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(369) /* 0x171 */) & 2 /*0x2*/));
    // 004ebc8a  7407                   -je 0x4ebc93
    if (cpu.flags.zf)
    {
        goto L_0x004ebc93;
    }
    // 004ebc8c  800dd94e560001         -or byte ptr [0x564ed9], 1
    app->getMemory<x86::reg8>(x86::reg32(5656281) /* 0x564ed9 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004ebc93:
    // 004ebc93  f684247301000080       +test byte ptr [esp + 0x173], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 128 /*0x80*/));
    // 004ebc9b  7407                   -je 0x4ebca4
    if (cpu.flags.zf)
    {
        goto L_0x004ebca4;
    }
    // 004ebc9d  800dd94e560004         -or byte ptr [0x564ed9], 4
    app->getMemory<x86::reg8>(x86::reg32(5656281) /* 0x564ed9 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004ebca4:
    // 004ebca4  f684247301000001       +test byte ptr [esp + 0x173], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 1 /*0x1*/));
    // 004ebcac  7411                   -je 0x4ebcbf
    if (cpu.flags.zf)
    {
        goto L_0x004ebcbf;
    }
    // 004ebcae  f684247901000002       +test byte ptr [esp + 0x179], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(377) /* 0x179 */) & 2 /*0x2*/));
    // 004ebcb6  7407                   -je 0x4ebcbf
    if (cpu.flags.zf)
    {
        goto L_0x004ebcbf;
    }
    // 004ebcb8  800dd94e560002         -or byte ptr [0x564ed9], 2
    app->getMemory<x86::reg8>(x86::reg32(5656281) /* 0x564ed9 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004ebcbf:
    // 004ebcbf  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 004ebcc7  7407                   -je 0x4ebcd0
    if (cpu.flags.zf)
    {
        goto L_0x004ebcd0;
    }
    // 004ebcc9  800dd84e560010         -or byte ptr [0x564ed8], 0x10
    app->getMemory<x86::reg8>(x86::reg32(5656280) /* 0x564ed8 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004ebcd0:
    // 004ebcd0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ebcd2  89155c825600           -mov dword ptr [0x56825c], edx
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edx;
L_0x004ebcd8:
    // 004ebcd8  833b00                 +cmp dword ptr [ebx], 0
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
    // 004ebcdb  7464                   -je 0x4ebd41
    if (cpu.flags.zf)
    {
        goto L_0x004ebd41;
    }
    // 004ebcdd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ebce2:
    // 004ebce2  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebce8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebce9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebcea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebceb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebcec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebced  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebcee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ebcef:
    // 004ebcef  6834b95400             -push 0x54b934
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552436 /*0x54b934*/;
    cpu.esp -= 4;
    // 004ebcf4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebcf6  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebcfb  e850530100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebd00  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ebd03  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ebd08  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ebd0a  e821f7ffff             -call 0x4eb430
    cpu.esp -= 4;
    sub_4eb430(app, cpu);
    if (cpu.terminate) return;
    // 004ebd0f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ebd11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebd13  0f8578feffff           -jne 0x4ebb91
    if (!cpu.flags.zf)
    {
        goto L_0x004ebb91;
    }
    // 004ebd19  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ebd1b  c7055c82560048b95400   -mov dword ptr [0x56825c], 0x54b948
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = 5552456 /*0x54b948*/;
    // 004ebd25  ebbb                   -jmp 0x4ebce2
    goto L_0x004ebce2;
L_0x004ebd27:
    // 004ebd27  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004ebd2a  0f8430ffffff           -je 0x4ebc60
    if (cpu.flags.zf)
    {
        goto L_0x004ebc60;
    }
    // 004ebd30  e96fffffff             -jmp 0x4ebca4
    goto L_0x004ebca4;
L_0x004ebd35:
    // 004ebd35  c7055c825600bcb95400   -mov dword ptr [0x56825c], 0x54b9bc
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = 5552572 /*0x54b9bc*/;
    // 004ebd3f  7497                   -je 0x4ebcd8
    if (cpu.flags.zf)
    {
        goto L_0x004ebcd8;
    }
L_0x004ebd41:
    // 004ebd41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ebd43  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebd49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ebd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ebd50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebd51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ebd52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ebd53  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebd59  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ebd5b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ebd5d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004ebd5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebd61  7505                   -jne 0x4ebd68
    if (!cpu.flags.zf)
    {
        goto L_0x004ebd68;
    }
    // 004ebd63  bed0389f00             -mov esi, 0x9f38d0
    cpu.esi = 10434768 /*0x9f38d0*/;
L_0x004ebd68:
    // 004ebd68  833e00                 +cmp dword ptr [esi], 0
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
    // 004ebd6b  750e                   -jne 0x4ebd7b
    if (!cpu.flags.zf)
    {
        goto L_0x004ebd7b;
    }
L_0x004ebd6d:
    // 004ebd6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ebd6f  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebd75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebd78  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ebd7b:
    // 004ebd7b  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 004ebd80  898c246c010000         -mov dword ptr [esp + 0x16c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ecx;
    // 004ebd87  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ebd8a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ebd8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebd8d  8d8c2470010000         -lea ecx, [esp + 0x170]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004ebd94  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebd96  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebd97  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ebd99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebd9a  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebd9d  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004ebda1  75ca                   -jne 0x4ebd6d
    if (!cpu.flags.zf)
    {
        goto L_0x004ebd6d;
    }
    // 004ebda3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ebda5  740a                   -je 0x4ebdb1
    if (cpu.flags.zf)
    {
        goto L_0x004ebdb1;
    }
    // 004ebda7  8b8424a8010000         -mov eax, dword ptr [esp + 0x1a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 004ebdae  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004ebdb1:
    // 004ebdb1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ebdb3  7409                   -je 0x4ebdbe
    if (cpu.flags.zf)
    {
        goto L_0x004ebdbe;
    }
    // 004ebdb5  8b8424ac010000         -mov eax, dword ptr [esp + 0x1ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 004ebdbc  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004ebdbe:
    // 004ebdbe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ebdc0  7411                   -je 0x4ebdd3
    if (cpu.flags.zf)
    {
        goto L_0x004ebdd3;
    }
    // 004ebdc2  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 004ebdca  7477                   -je 0x4ebe43
    if (cpu.flags.zf)
    {
        goto L_0x004ebe43;
    }
    // 004ebdcc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ebdd1:
    // 004ebdd1  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004ebdd3:
    // 004ebdd3  83bc24e802000000       +cmp dword ptr [esp + 0x2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ebddb  7448                   -je 0x4ebe25
    if (cpu.flags.zf)
    {
        goto L_0x004ebe25;
    }
    // 004ebddd  68c0db4e00             -push 0x4edbc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5168064 /*0x4edbc0*/;
    cpu.esp -= 4;
    // 004ebde2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ebde4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebde5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebde6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebde8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebdea  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ebdec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebded  890da0099f00           -mov dword ptr [0x9f09a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */) = cpu.ecx;
    // 004ebdf3  890da4099f00           -mov dword ptr [0x9f09a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(10422692) /* 0x9f09a4 */) = cpu.ecx;
    // 004ebdf9  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebdfc  8b35a0099f00           -mov esi, dword ptr [0x9f09a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004ebe02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebe03  68e0b95400             -push 0x54b9e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552608 /*0x54b9e0*/;
    cpu.esp -= 4;
    // 004ebe08  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004ebe0a  8b9424f4020000         -mov edx, dword ptr [esp + 0x2f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(756) /* 0x2f4 */);
    // 004ebe11  a1a4099f00             -mov eax, dword ptr [0x9f09a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10422692) /* 0x9f09a4 */);
    // 004ebe16  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebe1b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ebe1d  e82e520100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebe22  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ebe25:
    // 004ebe25  833da0099f0000         +cmp dword ptr [0x9f09a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ebe2c  0f8e3bffffff           -jle 0x4ebd6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ebd6d;
    }
    // 004ebe32  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ebe37  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004ebe3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebe3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebe3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebe40  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ebe43:
    // 004ebe43  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ebe45  eb8a                   -jmp 0x4ebdd1
    goto L_0x004ebdd1;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ebe50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ebe50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ebe51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ebe52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebe53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebe54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ebe55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ebe56  8b3d5c825600           -mov edi, dword ptr [0x56825c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */);
    // 004ebe5c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ebe5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebe60  7505                   -jne 0x4ebe67
    if (!cpu.flags.zf)
    {
        goto L_0x004ebe67;
    }
    // 004ebe62  bed0389f00             -mov esi, 0x9f38d0
    cpu.esi = 10434768 /*0x9f38d0*/;
L_0x004ebe67:
    // 004ebe67  833e00                 +cmp dword ptr [esi], 0
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
    // 004ebe6a  0f848e000000           -je 0x4ebefe
    if (cpu.flags.zf)
    {
        goto L_0x004ebefe;
    }
    // 004ebe70  83be5404000000         +cmp dword ptr [esi + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ebe77  0f8488000000           -je 0x4ebf05
    if (cpu.flags.zf)
    {
        goto L_0x004ebf05;
    }
    // 004ebe7d  8aa65d040000           -mov ah, byte ptr [esi + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 004ebe83  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ebe89  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004ebe8b  0f847b000000           -je 0x4ebf0c
    if (cpu.flags.zf)
    {
        goto L_0x004ebf0c;
    }
    // 004ebe91  6834ba5400             -push 0x54ba34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552692 /*0x54ba34*/;
    cpu.esp -= 4;
    // 004ebe96  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004ebe98  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebe9d  e8ae510100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebea2  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 004ebea7  8b1ddc4e5600           -mov ebx, dword ptr [0x564edc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656284) /* 0x564edc */);
    // 004ebead  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ebeb0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ebeb2  7405                   -je 0x4ebeb9
    if (cpu.flags.zf)
    {
        goto L_0x004ebeb9;
    }
    // 004ebeb4  b851000000             -mov eax, 0x51
    cpu.eax = 81 /*0x51*/;
L_0x004ebeb9:
    // 004ebeb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebeba  8bae54040000           -mov ebp, dword ptr [esi + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 004ebec0  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebec2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ebec3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ebec5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebec6  ff5350                 -call dword ptr [ebx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebec9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ebecb  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ebed1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebed2  689cba5400             -push 0x54ba9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552796 /*0x54ba9c*/;
    cpu.esp -= 4;
    // 004ebed7  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ebed9  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebede  e86d510100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebee3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ebee6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ebee8  743d                   -je 0x4ebf27
    if (cpu.flags.zf)
    {
        goto L_0x004ebf27;
    }
    // 004ebeea  bfacbb5400             -mov edi, 0x54bbac
    cpu.edi = 5553068 /*0x54bbac*/;
L_0x004ebeef:
    // 004ebeef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ebef1  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ebef7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebef8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebef9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebefa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebefb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebefc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ebefd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ebefe:
    // 004ebefe  bff8b95400             -mov edi, 0x54b9f8
    cpu.edi = 5552632 /*0x54b9f8*/;
    // 004ebf03  ebea                   -jmp 0x4ebeef
    goto L_0x004ebeef;
L_0x004ebf05:
    // 004ebf05  bf18ba5400             -mov edi, 0x54ba18
    cpu.edi = 5552664 /*0x54ba18*/;
    // 004ebf0a  ebe3                   -jmp 0x4ebeef
    goto L_0x004ebeef;
L_0x004ebf0c:
    // 004ebf0c  6868ba5400             -push 0x54ba68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552744 /*0x54ba68*/;
    cpu.esp -= 4;
    // 004ebf11  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 004ebf13  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebf18  e833510100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebf1d  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004ebf22  83c40c                 +add esp, 0xc
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
    // 004ebf25  eb92                   -jmp 0x4ebeb9
    goto L_0x004ebeb9;
L_0x004ebf27:
    // 004ebf27  68ccba5400             -push 0x54bacc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552844 /*0x54bacc*/;
    cpu.esp -= 4;
    // 004ebf2c  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004ebf2e  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebf33  8915a0099f00           -mov dword ptr [0x9f09a0], edx
    app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */) = cpu.edx;
    // 004ebf39  e812510100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebf3e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ebf41  68c0db4e00             -push 0x4edbc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5168064 /*0x4edbc0*/;
    cpu.esp -= 4;
    // 004ebf46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebf47  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ebf49  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebf4b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebf4d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ebf4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebf50  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ebf53  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004ebf58  0f852a010000           -jne 0x4ec088
    if (!cpu.flags.zf)
    {
        goto L_0x004ec088;
    }
    // 004ebf5e  8b15a0099f00           -mov edx, dword ptr [0x9f09a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004ebf64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ebf65  6810bb5400             -push 0x54bb10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5552912 /*0x54bb10*/;
    cpu.esp -= 4;
    // 004ebf6a  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004ebf6c  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ebf71  e8da500100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ebf76  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ebf79  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ebf7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ebf7e  740e                   -je 0x4ebf8e
    if (cpu.flags.zf)
    {
        goto L_0x004ebf8e;
    }
    // 004ebf80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ebf82  e80959ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004ebf87  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004ebf8e:
    // 004ebf8e  a1a0099f00             -mov eax, dword ptr [0x9f09a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004ebf93  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ebf96  83f810                 +cmp eax, 0x10
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
    // 004ebf99  7d07                   -jge 0x4ebfa2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ebfa2;
    }
    // 004ebf9b  c7460810000000         -mov dword ptr [esi + 8], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 16 /*0x10*/;
L_0x004ebfa2:
    // 004ebfa2  bd1cbb5400             -mov ebp, 0x54bb1c
    cpu.ebp = 5552924 /*0x54bb1c*/;
    // 004ebfa7  bac5010000             -mov edx, 0x1c5
    cpu.edx = 453 /*0x1c5*/;
    // 004ebfac  b828bb5400             -mov eax, 0x54bb28
    cpu.eax = 5552936 /*0x54bb28*/;
    // 004ebfb1  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004ebfb7  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ebfba  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004ebfbf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004ebfc6  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004ebfcc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ebfce  b83cbb5400             -mov eax, 0x54bb3c
    cpu.eax = 5552956 /*0x54bb3c*/;
    // 004ebfd3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ebfd6  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004ebfdc  e83f56ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004ebfe1  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ebfe4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ebfe6  0f84b0000000           -je 0x4ec09c
    if (cpu.flags.zf)
    {
        goto L_0x004ec09c;
    }
    // 004ebfec  68c0db4e00             -push 0x4edbc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5168064 /*0x4edbc0*/;
    cpu.esp -= 4;
    // 004ebff1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ebff2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ebff4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ebff5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ebff7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ebff9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ebffb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ebffc  891da8099f00           -mov dword ptr [0x9f09a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10422696) /* 0x9f09a8 */) = cpu.ebx;
    // 004ec002  891da0099f00           -mov dword ptr [0x9f09a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */) = cpu.ebx;
    // 004ec008  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec00b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec00c  a1a8099f00             -mov eax, dword ptr [0x9f09a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10422696) /* 0x9f09a8 */);
    // 004ec011  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec012  8b15a0099f00           -mov edx, dword ptr [0x9f09a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004ec018  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec019  6870bb5400             -push 0x54bb70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553008 /*0x54bb70*/;
    cpu.esp -= 4;
    // 004ec01e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ec020  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec025  e826500100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec02a  c7462800030000         -mov dword ptr [esi + 0x28], 0x300
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 768 /*0x300*/;
    // 004ec031  a1a0099f00             -mov eax, dword ptr [0x9f09a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004ec036  c7462c00010000         -mov dword ptr [esi + 0x2c], 0x100
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 256 /*0x100*/;
    // 004ec03d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ec040  8a965d040000           -mov dl, byte ptr [esi + 0x45d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 004ec046  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ec049  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004ec04b  7561                   -jne 0x4ec0ae
    if (!cpu.flags.zf)
    {
        goto L_0x004ec0ae;
    }
    // 004ec04d  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ec050  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ec052  755a                   -jne 0x4ec0ae
    if (!cpu.flags.zf)
    {
        goto L_0x004ec0ae;
    }
    // 004ec054  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec055  8d5e04                 -lea ebx, [esi + 4]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ec058  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec059  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ec05b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec05c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec05e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec05f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec062  8b9e54040000           -mov ebx, dword ptr [esi + 0x454]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 004ec068  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec069  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ec06c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec06e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec070  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec071  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec074  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ec079  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ec07b  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ec081  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec082  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec083  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec084  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec085  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec086  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec088:
    // 004ec088  bfecba5400             -mov edi, 0x54baec
    cpu.edi = 5552876 /*0x54baec*/;
    // 004ec08d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ec08f  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ec095  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec096  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec097  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec098  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec099  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec09a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec09b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec09c:
    // 004ec09c  bf48bb5400             -mov edi, 0x54bb48
    cpu.edi = 5552968 /*0x54bb48*/;
    // 004ec0a1  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ec0a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec0ae:
    // 004ec0ae  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ec0b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ec0ba  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ec0bc  893d5c825600           -mov dword ptr [0x56825c], edi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edi;
    // 004ec0c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec0c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ec0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ec0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec0d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec0d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec0d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec0d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec0d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec0d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ec0d8  68ccbb5400             -push 0x54bbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553100 /*0x54bbcc*/;
    cpu.esp -= 4;
    // 004ec0dd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ec0df  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec0e4  e8674f0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec0e9  8b9344040000           -mov edx, dword ptr [ebx + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 004ec0ef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ec0f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ec0f4  740c                   -je 0x4ec102
    if (cpu.flags.zf)
    {
        goto L_0x004ec102;
    }
    // 004ec0f6  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ec0f8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ec0fa  7406                   -je 0x4ec102
    if (cpu.flags.zf)
    {
        goto L_0x004ec102;
    }
    // 004ec0fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec0fd  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ec0ff  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ec102:
    // 004ec102  8bb350040000           -mov esi, dword ptr [ebx + 0x450]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */);
    // 004ec108  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec10a  7407                   -je 0x4ec113
    if (cpu.flags.zf)
    {
        goto L_0x004ec113;
    }
    // 004ec10c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ec10e  e85dcd0100             -call 0x508e70
    cpu.esp -= 4;
    sub_508e70(app, cpu);
    if (cpu.terminate) return;
L_0x004ec113:
    // 004ec113  8bbb4c040000           -mov edi, dword ptr [ebx + 0x44c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */);
    // 004ec119  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ec11b  7407                   -je 0x4ec124
    if (cpu.flags.zf)
    {
        goto L_0x004ec124;
    }
    // 004ec11d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ec11f  e84ccd0100             -call 0x508e70
    cpu.esp -= 4;
    sub_508e70(app, cpu);
    if (cpu.terminate) return;
L_0x004ec124:
    // 004ec124  c7834c04000000000000   -mov dword ptr [ebx + 0x44c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */) = 0 /*0x0*/;
    // 004ec12e  8bab48040000           -mov ebp, dword ptr [ebx + 0x448]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */);
    // 004ec134  c7835004000000000000   -mov dword ptr [ebx + 0x450], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */) = 0 /*0x0*/;
    // 004ec13e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ec140  7409                   -je 0x4ec14b
    if (cpu.flags.zf)
    {
        goto L_0x004ec14b;
    }
    // 004ec142  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ec144  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ec146  e8e5150000             -call 0x4ed730
    cpu.esp -= 4;
    sub_4ed730(app, cpu);
    if (cpu.terminate) return;
L_0x004ec14b:
    // 004ec14b  8b8344040000           -mov eax, dword ptr [ebx + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 004ec151  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ec153  7534                   -jne 0x4ec189
    if (!cpu.flags.zf)
    {
        goto L_0x004ec189;
    }
L_0x004ec155:
    // 004ec155  68fcbb5400             -push 0x54bbfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553148 /*0x54bbfc*/;
    cpu.esp -= 4;
    // 004ec15a  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004ec15c  c7834804000000000000   -mov dword ptr [ebx + 0x448], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */) = 0 /*0x0*/;
    // 004ec166  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec16b  c7834404000000000000   -mov dword ptr [ebx + 0x444], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */) = 0 /*0x0*/;
    // 004ec175  e8d64e0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec17a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ec17f  83c40c                 +add esp, 0xc
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
    // 004ec182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec183  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec184  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec185  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec186  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec187  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec188  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec189:
    // 004ec189  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ec18b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ec18d  e89e150000             -call 0x4ed730
    cpu.esp -= 4;
    sub_4ed730(app, cpu);
    if (cpu.terminate) return;
    // 004ec192  ebc1                   -jmp 0x4ec155
    goto L_0x004ec155;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4ec1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ec1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec1a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec1a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec1a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec1a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec1a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ec1a8  81ec48030000           -sub esp, 0x348
    (cpu.esp) -= x86::reg32(x86::sreg32(840 /*0x348*/));
    // 004ec1ae  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ec1b1  6820bc5400             -push 0x54bc20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553184 /*0x54bc20*/;
    cpu.esp -= 4;
    // 004ec1b6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ec1b8  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec1bd  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec1c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ec1c2  e8894e0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec1c7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ec1ca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ec1cc  0f841e040000           -je 0x4ec5f0
    if (cpu.flags.zf)
    {
        goto L_0x004ec5f0;
    }
L_0x004ec1d2:
    // 004ec1d2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec1d5  83b84004000000         +cmp dword ptr [eax + 0x440], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1088) /* 0x440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec1dc  742d                   -je 0x4ec20b
    if (cpu.flags.zf)
    {
        goto L_0x004ec20b;
    }
    // 004ec1de  bf1cbb5400             -mov edi, 0x54bb1c
    cpu.edi = 5552924 /*0x54bb1c*/;
    // 004ec1e3  b83cbc5400             -mov eax, 0x54bc3c
    cpu.eax = 5553212 /*0x54bc3c*/;
    // 004ec1e8  ba01020000             -mov edx, 0x201
    cpu.edx = 513 /*0x201*/;
    // 004ec1ed  6850bc5400             -push 0x54bc50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553232 /*0x54bc50*/;
    cpu.esp -= 4;
    // 004ec1f2  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004ec1f8  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004ec1fd  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004ec203  e8084ef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ec208  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ec20b:
    // 004ec20b  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ec211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec212  be6c010000             -mov esi, 0x16c
    cpu.esi = 364 /*0x16c*/;
    // 004ec217  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec21d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec220  8d9524feffff           -lea edx, [ebp - 0x1dc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-476) /* -0x1dc */);
    // 004ec226  e8a5feffff             -call 0x4ec0d0
    cpu.esp -= 4;
    sub_4ec0d0(app, cpu);
    if (cpu.terminate) return;
    // 004ec22b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec22e  89b5b8fcffff           -mov dword ptr [ebp - 0x348], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-840) /* -0x348 */) = cpu.esi;
    // 004ec234  89b524feffff           -mov dword ptr [ebp - 0x1dc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-476) /* -0x1dc */) = cpu.esi;
    // 004ec23a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec23b  8d95b8fcffff           -lea edx, [ebp - 0x348]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-840) /* -0x348 */);
    // 004ec241  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec243  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec244  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec246  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec247  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec24a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec24d  8a9037040000           -mov dl, byte ptr [eax + 0x437]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */);
    // 004ec253  80fa01                 +cmp dl, 1
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
    // 004ec256  0f83a0030000           -jae 0x4ec5fc
    if (!cpu.flags.cf)
    {
        goto L_0x004ec5fc;
    }
    // 004ec25c  c6803704000001         -mov byte ptr [eax + 0x437], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */) = 1 /*0x1*/;
L_0x004ec263:
    // 004ec263  f6853cfdffff10         +test byte ptr [ebp - 0x2c4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-708) /* -0x2c4 */) & 16 /*0x10*/));
    // 004ec26a  0f84b7030000           -je 0x4ec627
    if (cpu.flags.zf)
    {
        goto L_0x004ec627;
    }
    // 004ec270  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004ec272:
    // 004ec272  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec275  888260040000           -mov byte ptr [edx + 0x460], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1120) /* 0x460 */) = cpu.al;
    // 004ec27b  f685bffcffff08         +test byte ptr [ebp - 0x341], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-833) /* -0x341 */) & 8 /*0x8*/));
    // 004ec282  0f84a6030000           -je 0x4ec62e
    if (cpu.flags.zf)
    {
        goto L_0x004ec62e;
    }
    // 004ec288  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004ec28a:
    // 004ec28a  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec28d  888262040000           -mov byte ptr [edx + 0x462], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1122) /* 0x462 */) = cpu.al;
    // 004ec293  80ba5e04000000         +cmp byte ptr [edx + 0x45e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec29a  0f8595030000           -jne 0x4ec635
    if (!cpu.flags.zf)
    {
        goto L_0x004ec635;
    }
    // 004ec2a0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec2a3  80b83604000000         +cmp byte ptr [eax + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec2aa  740e                   -je 0x4ec2ba
    if (cpu.flags.zf)
    {
        goto L_0x004ec2ba;
    }
    // 004ec2ac  c6803404000001         -mov byte ptr [eax + 0x434], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1076) /* 0x434 */) = 1 /*0x1*/;
    // 004ec2b3  c6803504000001         -mov byte ptr [eax + 0x435], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
L_0x004ec2ba:
    // 004ec2ba  817dfcd0389f00         +cmp dword ptr [ebp - 4], 0x9f38d0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10434768 /*0x9f38d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec2c1  7503                   -jne 0x4ec2c6
    if (!cpu.flags.zf)
    {
        goto L_0x004ec2c6;
    }
    // 004ec2c3  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004ec2c6:
    // 004ec2c6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec2c9  80b86304000001         +cmp byte ptr [eax + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec2d0  7632                   -jbe 0x4ec304
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec304;
    }
    // 004ec2d2  80b83504000000         +cmp byte ptr [eax + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec2d9  0f847d030000           -je 0x4ec65c
    if (cpu.flags.zf)
    {
        goto L_0x004ec65c;
    }
L_0x004ec2df:
    // 004ec2df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ec2e4:
    // 004ec2e4  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec2e7  80ba6004000000         +cmp byte ptr [edx + 0x460], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1120) /* 0x460 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec2ee  0f857c030000           -jne 0x4ec670
    if (!cpu.flags.zf)
    {
        goto L_0x004ec670;
    }
    // 004ec2f4  80ba6204000000         +cmp byte ptr [edx + 0x462], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1122) /* 0x462 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec2fb  0f846f030000           -je 0x4ec670
    if (cpu.flags.zf)
    {
        goto L_0x004ec670;
    }
L_0x004ec301:
    // 004ec301  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004ec304:
    // 004ec304  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec307  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec30a  8b7024                 -mov esi, dword ptr [eax + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ec30d  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004ec310  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec312  0f8575030000           -jne 0x4ec68d
    if (!cpu.flags.zf)
    {
        goto L_0x004ec68d;
    }
    // 004ec318  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec31b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec31d  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004ec320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec322  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec324  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 004ec326  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec328  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec329  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ec32c:
    // 004ec32c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec32f  66c78032040000ff00     -mov word ptr [eax + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
    // 004ec338  c6805f04000000         -mov byte ptr [eax + 0x45f], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1119) /* 0x45f */) = 0 /*0x0*/;
    // 004ec33f  8aa836040000           -mov ch, byte ptr [eax + 0x436]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1078) /* 0x436 */);
    // 004ec345  66c780300400000000     -mov word ptr [eax + 0x430], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 004ec34e  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004ec350  0f844c030000           -je 0x4ec6a2
    if (cpu.flags.zf)
    {
        goto L_0x004ec6a2;
    }
    // 004ec356  b8b8bc5400             -mov eax, 0x54bcb8
    cpu.eax = 5553336 /*0x54bcb8*/;
L_0x004ec35b:
    // 004ec35b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec35c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec35f  80b86304000001         +cmp byte ptr [eax + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec366  0f864f030000           -jbe 0x4ec6bb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec6bb;
    }
    // 004ec36c  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 004ec36f  0f8546030000           -jne 0x4ec6bb
    if (!cpu.flags.zf)
    {
        goto L_0x004ec6bb;
    }
    // 004ec375  b8d0bc5400             -mov eax, 0x54bcd0
    cpu.eax = 5553360 /*0x54bcd0*/;
L_0x004ec37a:
    // 004ec37a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec37b  68ecbc5400             -push 0x54bcec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553388 /*0x54bcec*/;
    cpu.esp -= 4;
    // 004ec380  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004ec382  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec387  e8c44c0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec38c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004ec38f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ec391  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec394  e8f7f0ffff             -call 0x4eb490
    cpu.esp -= 4;
    sub_4eb490(app, cpu);
    if (cpu.terminate) return;
    // 004ec399  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ec39b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ec39d  0f8522030000           -jne 0x4ec6c5
    if (!cpu.flags.zf)
    {
        goto L_0x004ec6c5;
    }
    // 004ec3a3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3a6  c6805f04000001         -mov byte ptr [eax + 0x45f], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1119) /* 0x45f */) = 1 /*0x1*/;
L_0x004ec3ad:
    // 004ec3ad  6810bd5400             -push 0x54bd10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553424 /*0x54bd10*/;
    cpu.esp -= 4;
    // 004ec3b2  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ec3b4  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec3b9  e8924c0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec3be  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3c1  c6803704000002         -mov byte ptr [eax + 0x437], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 004ec3c8  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3cb  8a8037040000           -mov al, byte ptr [eax + 0x437]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */);
    // 004ec3d1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ec3d4  888263040000           -mov byte ptr [edx + 0x463], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1123) /* 0x463 */) = cpu.al;
    // 004ec3da  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec3dc  740a                   -je 0x4ec3e8
    if (cpu.flags.zf)
    {
        goto L_0x004ec3e8;
    }
    // 004ec3de  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3e1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ec3e3  e848130000             -call 0x4ed730
    cpu.esp -= 4;
    sub_4ed730(app, cpu);
    if (cpu.terminate) return;
L_0x004ec3e8:
    // 004ec3e8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3eb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ec3ed  e89ef0ffff             -call 0x4eb490
    cpu.esp -= 4;
    sub_4eb490(app, cpu);
    if (cpu.terminate) return;
    // 004ec3f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ec3f4:
    // 004ec3f4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec3f6  0f84fd020000           -je 0x4ec6f9
    if (cpu.flags.zf)
    {
        goto L_0x004ec6f9;
    }
    // 004ec3fc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec3ff  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004ec403  7416                   -je 0x4ec41b
    if (cpu.flags.zf)
    {
        goto L_0x004ec41b;
    }
    // 004ec405  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec40c  750d                   -jne 0x4ec41b
    if (!cpu.flags.zf)
    {
        goto L_0x004ec41b;
    }
    // 004ec40e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec411  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ec414  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec415  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ec417  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec418  ff5070                 -call dword ptr [eax + 0x70]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ec41b:
    // 004ec41b  8d5590                 -lea edx, [ebp - 0x70]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-112) /* -0x70 */);
    // 004ec41e  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 004ec423  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec424  895d90                 -mov dword ptr [ebp - 0x70], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-112) /* -0x70 */) = cpu.ebx;
    // 004ec427  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec428  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ec42a  8d5d90                 -lea ebx, [ebp - 0x70]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-112) /* -0x70 */);
    // 004ec42d  ff5058                 -call dword ptr [eax + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec430  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec433  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ec438  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec43b  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004ec43e  e85df4ffff             -call 0x4eb8a0
    cpu.esp -= 4;
    sub_4eb8a0(app, cpu);
    if (cpu.terminate) return;
    // 004ec443  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec446  8a9063040000           -mov dl, byte ptr [eax + 0x463]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1123) /* 0x463 */);
    // 004ec44c  89b044040000           -mov dword ptr [eax + 0x444], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */) = cpu.esi;
    // 004ec452  80fa01                 +cmp dl, 1
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
    // 004ec455  0f86c1020000           -jbe 0x4ec71c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec71c;
    }
    // 004ec45b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ec45d  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec460  e80b130000             -call 0x4ed770
    cpu.esp -= 4;
    sub_4ed770(app, cpu);
    if (cpu.terminate) return;
L_0x004ec465:
    // 004ec465  898248040000           -mov dword ptr [edx + 0x448], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x004ec46b:
    // 004ec46b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec46e  83b84404000000         +cmp dword ptr [eax + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec475  7452                   -je 0x4ec4c9
    if (cpu.flags.zf)
    {
        goto L_0x004ec4c9;
    }
    // 004ec477  c745906c000000         -mov dword ptr [ebp - 0x70], 0x6c
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-112) /* -0x70 */) = 108 /*0x6c*/;
    // 004ec47e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec481  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ec484  8d4d90                 -lea ecx, [ebp - 0x70]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-112) /* -0x70 */);
    // 004ec487  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 004ec48a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec48d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec48e  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 004ec494  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec495  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec497  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec49a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec49d  8b9044040000           -mov edx, dword ptr [eax + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 004ec4a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec4a4  8b4db4                 -mov ecx, dword ptr [ebp - 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004ec4a7  8b5da0                 -mov ebx, dword ptr [ebp - 0x60]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 004ec4aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec4ab  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ec4ae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ec4b0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004ec4b2  8a885c040000           -mov cl, byte ptr [eax + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1116) /* 0x45c */);
    // 004ec4b8  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ec4bb  e8b0c70100             -call 0x508c70
    cpu.esp -= 4;
    sub_508c70(app, cpu);
    if (cpu.terminate) return;
    // 004ec4c0  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec4c3  89824c040000           -mov dword ptr [edx + 0x44c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1100) /* 0x44c */) = cpu.eax;
L_0x004ec4c9:
    // 004ec4c9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec4cc  8b9848040000           -mov ebx, dword ptr [eax + 0x448]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1096) /* 0x448 */);
    // 004ec4d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ec4d4  0f84ff020000           -je 0x4ec7d9
    if (cpu.flags.zf)
    {
        goto L_0x004ec7d9;
    }
    // 004ec4da  c745906c000000         -mov dword ptr [ebp - 0x70], 0x6c
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-112) /* -0x70 */) = 108 /*0x6c*/;
    // 004ec4e1  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ec4e4  8d5590                 -lea edx, [ebp - 0x70]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-112) /* -0x70 */);
    // 004ec4e7  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 004ec4ea  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec4ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec4ee  8b8048040000           -mov eax, dword ptr [eax + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1096) /* 0x448 */);
    // 004ec4f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec4f5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec4f7  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec4fa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec4fd  8bb848040000           -mov edi, dword ptr [eax + 0x448]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1096) /* 0x448 */);
    // 004ec503  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec504  8b45b4                 -mov eax, dword ptr [ebp - 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004ec507  8b5da0                 -mov ebx, dword ptr [ebp - 0x60]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 004ec50a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec50b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec50e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ec510  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 004ec512  8a885c040000           -mov cl, byte ptr [eax + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1116) /* 0x45c */);
    // 004ec518  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ec51b  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ec51e  e84dc70100             -call 0x508c70
    cpu.esp -= 4;
    sub_508c70(app, cpu);
    if (cpu.terminate) return;
    // 004ec523  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec526  898250040000           -mov dword ptr [edx + 0x450], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1104) /* 0x450 */) = cpu.eax;
L_0x004ec52c:
    // 004ec52c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec52f  80b86304000001         +cmp byte ptr [eax + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec536  0f86f4020000           -jbe 0x4ec830
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec830;
    }
    // 004ec53c  b846000000             -mov eax, 0x46
    cpu.eax = 70 /*0x46*/;
L_0x004ec541:
    // 004ec541  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec542  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec545  80b83404000000         +cmp byte ptr [eax + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec54c  0f84e8020000           -je 0x4ec83a
    if (cpu.flags.zf)
    {
        goto L_0x004ec83a;
    }
    // 004ec552  b842000000             -mov eax, 0x42
    cpu.eax = 66 /*0x42*/;
L_0x004ec557:
    // 004ec557  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec558  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec55b  80b83604000000         +cmp byte ptr [eax + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec562  0f84dc020000           -je 0x4ec844
    if (cpu.flags.zf)
    {
        goto L_0x004ec844;
    }
    // 004ec568  b84c000000             -mov eax, 0x4c
    cpu.eax = 76 /*0x4c*/;
L_0x004ec56d:
    // 004ec56d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec56e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec571  80b85f04000000         +cmp byte ptr [eax + 0x45f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec578  0f84e3020000           -je 0x4ec861
    if (cpu.flags.zf)
    {
        goto L_0x004ec861;
    }
    // 004ec57e  b858000000             -mov eax, 0x58
    cpu.eax = 88 /*0x58*/;
L_0x004ec583:
    // 004ec583  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec586  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec587  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ec589  8a8237040000           -mov al, byte ptr [edx + 0x437]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1079) /* 0x437 */);
    // 004ec58f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec590  8b824c040000           -mov eax, dword ptr [edx + 0x44c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1100) /* 0x44c */);
    // 004ec596  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004ec599  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec59a  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec59d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ec59f  8a825c040000           -mov al, byte ptr [edx + 0x45c]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1116) /* 0x45c */);
    // 004ec5a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec5a6  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004ec5a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec5aa  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004ec5ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec5ae  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ec5b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec5b2  68d8bd5400             -push 0x54bdd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553624 /*0x54bdd8*/;
    cpu.esp -= 4;
    // 004ec5b7  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004ec5b9  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec5be  e88d4a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec5c3  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004ec5c6  8b3d80445600           -mov edi, dword ptr [0x564480]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ec5cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec5cd  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec5d3  833d8471560000         +cmp dword ptr [0x567184], 0
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
    // 004ec5da  7406                   -je 0x4ec5e2
    if (cpu.flags.zf)
    {
        goto L_0x004ec5e2;
    }
    // 004ec5dc  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ec5e2:
    // 004ec5e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ec5e7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ec5e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec5ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec5f0:
    // 004ec5f0  c745fcd0389f00         -mov dword ptr [ebp - 4], 0x9f38d0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 10434768 /*0x9f38d0*/;
    // 004ec5f7  e9d6fbffff             -jmp 0x4ec1d2
    goto L_0x004ec1d2;
L_0x004ec5fc:
    // 004ec5fc  80fa02                 +cmp dl, 2
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec5ff  0f865efcffff           -jbe 0x4ec263
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec263;
    }
    // 004ec605  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ec60b  b894bc5400             -mov eax, 0x54bc94
    cpu.eax = 5553300 /*0x54bc94*/;
    // 004ec610  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec611  a35c825600             -mov dword ptr [0x56825c], eax
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.eax;
    // 004ec616  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec61c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ec61e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ec620  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec622  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec623  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec624  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec625  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec626  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec627:
    // 004ec627  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ec629  e944fcffff             -jmp 0x4ec272
    goto L_0x004ec272;
L_0x004ec62e:
    // 004ec62e  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ec630  e955fcffff             -jmp 0x4ec28a
    goto L_0x004ec28a;
L_0x004ec635:
    // 004ec635  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec638  c6803604000000         -mov byte ptr [eax + 0x436], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1078) /* 0x436 */) = 0 /*0x0*/;
    // 004ec63f  c6803504000001         -mov byte ptr [eax + 0x435], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 004ec646  c6803704000002         -mov byte ptr [eax + 0x437], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 004ec64d  80cf2a                 +or bh, 0x2a
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(42 /*0x2a*/))));
    // 004ec650  c6806304000001         -mov byte ptr [eax + 0x463], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 004ec657  e95efcffff             -jmp 0x4ec2ba
    goto L_0x004ec2ba;
L_0x004ec65c:
    // 004ec65c  80b83404000000         +cmp byte ptr [eax + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec663  0f8576fcffff           -jne 0x4ec2df
    if (!cpu.flags.zf)
    {
        goto L_0x004ec2df;
    }
    // 004ec669  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ec66b  e974fcffff             -jmp 0x4ec2e4
    goto L_0x004ec2e4;
L_0x004ec670:
    // 004ec670  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec673  80ba5e04000000         +cmp byte ptr [edx + 0x45e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec67a  7408                   -je 0x4ec684
    if (cpu.flags.zf)
    {
        goto L_0x004ec684;
    }
L_0x004ec67c:
    // 004ec67c  80cf40                 +or bh, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004ec67f  e980fcffff             -jmp 0x4ec304
    goto L_0x004ec304;
L_0x004ec684:
    // 004ec684  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ec686  74f4                   -je 0x4ec67c
    if (cpu.flags.zf)
    {
        goto L_0x004ec67c;
    }
    // 004ec688  e974fcffff             -jmp 0x4ec301
    goto L_0x004ec301;
L_0x004ec68d:
    // 004ec68d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec68e  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004ec693  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec695  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec697  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004ec699  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec69a  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec69d  e98afcffff             -jmp 0x4ec32c
    goto L_0x004ec32c;
L_0x004ec6a2:
    // 004ec6a2  f6c740                 +test bh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 64 /*0x40*/));
    // 004ec6a5  740a                   -je 0x4ec6b1
    if (cpu.flags.zf)
    {
        goto L_0x004ec6b1;
    }
    // 004ec6a7  b8c0bc5400             -mov eax, 0x54bcc0
    cpu.eax = 5553344 /*0x54bcc0*/;
    // 004ec6ac  e9aafcffff             -jmp 0x4ec35b
    goto L_0x004ec35b;
L_0x004ec6b1:
    // 004ec6b1  b8c8bc5400             -mov eax, 0x54bcc8
    cpu.eax = 5553352 /*0x54bcc8*/;
    // 004ec6b6  e9a0fcffff             -jmp 0x4ec35b
    goto L_0x004ec35b;
L_0x004ec6bb:
    // 004ec6bb  b8dcbc5400             -mov eax, 0x54bcdc
    cpu.eax = 5553372 /*0x54bcdc*/;
    // 004ec6c0  e9b5fcffff             -jmp 0x4ec37a
    goto L_0x004ec37a;
L_0x004ec6c5:
    // 004ec6c5  8d4d90                 -lea ecx, [ebp - 0x70]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-112) /* -0x70 */);
    // 004ec6c8  bf6c000000             -mov edi, 0x6c
    cpu.edi = 108 /*0x6c*/;
    // 004ec6cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec6ce  897d90                 -mov dword ptr [ebp - 0x70], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-112) /* -0x70 */) = cpu.edi;
    // 004ec6d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec6d2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec6d4  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec6d7  f645fa20               +test byte ptr [ebp - 6], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) & 32 /*0x20*/));
    // 004ec6db  7418                   -je 0x4ec6f5
    if (cpu.flags.zf)
    {
        goto L_0x004ec6f5;
    }
    // 004ec6dd  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004ec6df:
    // 004ec6df  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec6e2  88825f040000           -mov byte ptr [edx + 0x45f], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 004ec6e8  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004ec6ea  0f85bdfcffff           -jne 0x4ec3ad
    if (!cpu.flags.zf)
    {
        goto L_0x004ec3ad;
    }
    // 004ec6f0  e9fffcffff             -jmp 0x4ec3f4
    goto L_0x004ec3f4;
L_0x004ec6f5:
    // 004ec6f5  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ec6f7  ebe6                   -jmp 0x4ec6df
    goto L_0x004ec6df;
L_0x004ec6f9:
    // 004ec6f9  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ec6ff  ba38bd5400             -mov edx, 0x54bd38
    cpu.edx = 5553464 /*0x54bd38*/;
    // 004ec704  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec705  89155c825600           -mov dword ptr [0x56825c], edx
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edx;
    // 004ec70b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec711  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ec713  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ec715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec716  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec718  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec719  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec71a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ec71b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ec71c:
    // 004ec71c  80b83604000000         +cmp byte ptr [eax + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec723  0f8542fdffff           -jne 0x4ec46b
    if (!cpu.flags.zf)
    {
        goto L_0x004ec46b;
    }
    // 004ec729  80b83704000001         +cmp byte ptr [eax + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec730  0f8635fdffff           -jbe 0x4ec46b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec46b;
    }
    // 004ec736  80b83504000000         +cmp byte ptr [eax + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec73d  754b                   -jne 0x4ec78a
    if (!cpu.flags.zf)
    {
        goto L_0x004ec78a;
    }
    // 004ec73f  80b83404000000         +cmp byte ptr [eax + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec746  7542                   -jne 0x4ec78a
    if (!cpu.flags.zf)
    {
        goto L_0x004ec78a;
    }
    // 004ec748  685cbd5400             -push 0x54bd5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553500 /*0x54bd5c*/;
    cpu.esp -= 4;
    // 004ec74d  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ec74f  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec754  e8f7480100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec759  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ec75c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec75e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec761  6840400000             -push 0x4040
    app->getMemory<x86::reg32>(cpu.esp-4) = 16448 /*0x4040*/;
    cpu.esp -= 4;
    // 004ec766  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec769  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec76c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec76e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec771  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004ec774  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec776  8b5b18                 -mov ebx, dword ptr [ebx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ec779  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ec77c  e8ff0c0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 004ec781  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec784  898248040000           -mov dword ptr [edx + 0x448], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x004ec78a:
    // 004ec78a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec78d  8bb048040000           -mov esi, dword ptr [eax + 0x448]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1096) /* 0x448 */);
    // 004ec793  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec795  0f85d0fcffff           -jne 0x4ec46b
    if (!cpu.flags.zf)
    {
        goto L_0x004ec46b;
    }
    // 004ec79b  6884bd5400             -push 0x54bd84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553540 /*0x54bd84*/;
    cpu.esp -= 4;
    // 004ec7a0  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ec7a2  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec7a7  e8a4480100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec7ac  83c40c                 +add esp, 0xc
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
    // 004ec7af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec7b0  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7b3  6840080000             -push 0x840
    app->getMemory<x86::reg32>(cpu.esp-4) = 2112 /*0x840*/;
    cpu.esp -= 4;
    // 004ec7b8  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7bb  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec7bf  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7c2  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004ec7c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec7c6  8b5b18                 -mov ebx, dword ptr [ebx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ec7c9  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ec7cc  e8af0c0000             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 004ec7d1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7d4  e98cfcffff             -jmp 0x4ec465
    goto L_0x004ec465;
L_0x004ec7d9:
    // 004ec7d9  80b83704000001         +cmp byte ptr [eax + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec7e0  0f8646fdffff           -jbe 0x4ec52c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ec52c;
    }
    // 004ec7e6  68acbd5400             -push 0x54bdac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553580 /*0x54bdac*/;
    cpu.esp -= 4;
    // 004ec7eb  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ec7ed  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec7f2  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7f5  e856480100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec7fa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec7fd  83c40c                 +add esp, 0xc
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
    // 004ec800  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004ec803  8a985c040000           -mov bl, byte ptr [eax + 0x45c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1116) /* 0x45c */);
    // 004ec809  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ec80c  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ec80f  bf64505600             -mov edi, 0x565064
    cpu.edi = 5656676 /*0x565064*/;
    // 004ec814  e877290000             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 004ec819  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ec81c  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004ec821  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ec823  898250040000           -mov dword ptr [edx + 0x450], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1104) /* 0x450 */) = cpu.eax;
    // 004ec829  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ec82b  e9fcfcffff             -jmp 0x4ec52c
    goto L_0x004ec52c;
L_0x004ec830:
    // 004ec830  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004ec835  e907fdffff             -jmp 0x4ec541
    goto L_0x004ec541;
L_0x004ec83a:
    // 004ec83a  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004ec83f  e913fdffff             -jmp 0x4ec557
    goto L_0x004ec557;
L_0x004ec844:
    // 004ec844  80b83504000000         +cmp byte ptr [eax + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ec84b  740a                   -je 0x4ec857
    if (cpu.flags.zf)
    {
        goto L_0x004ec857;
    }
    // 004ec84d  b844000000             -mov eax, 0x44
    cpu.eax = 68 /*0x44*/;
    // 004ec852  e916fdffff             -jmp 0x4ec56d
    goto L_0x004ec56d;
L_0x004ec857:
    // 004ec857  b856000000             -mov eax, 0x56
    cpu.eax = 86 /*0x56*/;
    // 004ec85c  e90cfdffff             -jmp 0x4ec56d
    goto L_0x004ec56d;
L_0x004ec861:
    // 004ec861  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004ec866  e918fdffff             -jmp 0x4ec583
    goto L_0x004ec583;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ec870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ec870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ec871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec872  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec873  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec874  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec875  81ec8c040000           -sub esp, 0x48c
    (cpu.esp) -= x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 004ec87b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ec87d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ec87f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ec880  6818be5400             -push 0x54be18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553688 /*0x54be18*/;
    cpu.esp -= 4;
    // 004ec885  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ec887  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ec889  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec88e  89942494040000         -mov dword ptr [esp + 0x494], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */) = cpu.edx;
    // 004ec895  e8b6470100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec89a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ec89d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ec89f  7505                   -jne 0x4ec8a6
    if (!cpu.flags.zf)
    {
        goto L_0x004ec8a6;
    }
    // 004ec8a1  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x004ec8a6:
    // 004ec8a6  c78424000400006c000000 -mov dword ptr [esp + 0x400], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = 108 /*0x6c*/;
    // 004ec8b1  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004ec8b8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ec8ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec8bb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec8be  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec8c1  8bac2454040000         -mov ebp, dword ptr [esp + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 004ec8c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec8c9  8b94240c040000         -mov edx, dword ptr [esp + 0x40c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004ec8d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec8d1  8b8c2414040000         -mov ecx, dword ptr [esp + 0x414]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004ec8d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec8d9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ec8db  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ec8e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec8e1  6838be5400             -push 0x54be38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553720 /*0x54be38*/;
    cpu.esp -= 4;
    // 004ec8e6  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ec8e8  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec8ed  e85e470100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec8f2  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 004ec8f8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ec8fb  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004ec8fd  0f8476020000           -je 0x4ecb79
    if (cpu.flags.zf)
    {
        goto L_0x004ecb79;
    }
    // 004ec903  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec907  0f849f010000           -je 0x4ecaac
    if (cpu.flags.zf)
    {
        goto L_0x004ecaac;
    }
    // 004ec90d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ec90f  0f8cb9010000           -jl 0x4ecace
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ecace;
    }
    // 004ec915  3b7308                 +cmp esi, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec918  7c02                   -jl 0x4ec91c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ec91c;
    }
    // 004ec91a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ec91c:
    // 004ec91c  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ec923  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ec925  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ec928  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ec92b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ec92d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ec92f  8a5012                 -mov dl, byte ptr [eax + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004ec932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ec933  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ec936  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec937  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec939  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec93a  6898be5400             -push 0x54be98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553816 /*0x54be98*/;
    cpu.esp -= 4;
    // 004ec93f  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ec941  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ec944  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec949  899424a0040000         -mov dword ptr [esp + 0x4a0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1184) /* 0x4a0 */) = cpu.edx;
    // 004ec950  89842494040000         -mov dword ptr [esp + 0x494], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */) = cpu.eax;
    // 004ec957  e8f4460100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec95c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x004ec95f:
    // 004ec95f  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ec963  7433                   -je 0x4ec998
    if (cpu.flags.zf)
    {
        goto L_0x004ec998;
    }
    // 004ec965  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 004ec96a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ec96c  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ec96e  e8993dffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004ec973  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec974  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004ec979  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec97b  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004ec97e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec980  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec982  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec983  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec986  66c783300400000000     -mov word ptr [ebx + 0x430], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 004ec98f  66c78332040000ff00     -mov word ptr [ebx + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
L_0x004ec998:
    // 004ec998  68ecbe5400             -push 0x54beec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553900 /*0x54beec*/;
    cpu.esp -= 4;
    // 004ec99d  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004ec99f  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec9a4  e8a7460100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec9a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ec9ac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ec9ae  8b8c2480040000         -mov ecx, dword ptr [esp + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
    // 004ec9b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec9b6  8b8c2490040000         -mov ecx, dword ptr [esp + 0x490]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1168) /* 0x490 */);
    // 004ec9bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec9be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ec9bf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ec9c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ec9c2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ec9c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec9c5  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ec9c8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ec9cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ec9ce  681cbf5400             -push 0x54bf1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553948 /*0x54bf1c*/;
    cpu.esp -= 4;
    // 004ec9d3  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 004ec9d5  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ec9da  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004ec9df  89842490040000         -mov dword ptr [esp + 0x490], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1168) /* 0x490 */) = cpu.eax;
    // 004ec9e6  e865460100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ec9eb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ec9ee  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004ec9f5  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 004ec9fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ec9fd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ec9ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eca00  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004eca02  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eca05  8b8c240c040000         -mov ecx, dword ptr [esp + 0x40c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004eca0c  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eca0e  0f82f2000000           -jb 0x4ecb06
    if (cpu.flags.cf)
    {
        goto L_0x004ecb06;
    }
    // 004eca14  894b14                 -mov dword ptr [ebx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004eca17:
    // 004eca17  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004eca1e  39c7                   +cmp edi, eax
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
    // 004eca20  0f82f9000000           -jb 0x4ecb1f
    if (cpu.flags.cf)
    {
        goto L_0x004ecb1f;
    }
    // 004eca26  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004eca29:
    // 004eca29  83bc248004000000       +cmp dword ptr [esp + 0x480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eca31  0f8501010000           -jne 0x4ecb38
    if (!cpu.flags.zf)
    {
        goto L_0x004ecb38;
    }
    // 004eca37  8b842488040000         -mov eax, dword ptr [esp + 0x488]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 004eca3e  3b842454040000         +cmp eax, dword ptr [esp + 0x454]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eca45  0f85ed000000           -jne 0x4ecb38
    if (!cpu.flags.zf)
    {
        goto L_0x004ecb38;
    }
    // 004eca4b  c784248404000001000000 -mov dword ptr [esp + 0x484], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = 1 /*0x1*/;
L_0x004eca56:
    // 004eca56  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 004eca5d  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004eca60  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 004eca65  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004eca68  2eff1568445300         -call dword ptr cs:[0x534468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457000) /* 0x534468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eca6f  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004eca72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eca73  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004eca76  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eca77  8b7314                 -mov esi, dword ptr [ebx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004eca7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eca7b  8b842494040000         -mov eax, dword ptr [esp + 0x494]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */);
    // 004eca82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eca83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eca84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eca85  684cbf5400             -push 0x54bf4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553996 /*0x54bf4c*/;
    cpu.esp -= 4;
    // 004eca8a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004eca8c  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004eca91  e8ba450100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004eca96  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004eca99  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 004ecaa0  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 004ecaa6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecaac:
    // 004ecaac  6870be5400             -push 0x54be70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553776 /*0x54be70*/;
    cpu.esp -= 4;
    // 004ecab1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ecab3  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecab8  e893450100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecabd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecac0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ecac2  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 004ecac8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecac9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecaca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecacb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecacc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecacd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecace:
    // 004ecace  68c0be5400             -push 0x54bec0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5553856 /*0x54bec0*/;
    cpu.esp -= 4;
    // 004ecad3  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004ecad5  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecada  bd80020000             -mov ebp, 0x280
    cpu.ebp = 640 /*0x280*/;
    // 004ecadf  bfe0010000             -mov edi, 0x1e0
    cpu.edi = 480 /*0x1e0*/;
    // 004ecae4  e867450100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecae9  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004ecaee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecaf1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ecaf3  89842488040000         -mov dword ptr [esp + 0x488], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.eax;
    // 004ecafa  8994247c040000         -mov dword ptr [esp + 0x47c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.edx;
    // 004ecb01  e959feffff             -jmp 0x4ec95f
    goto L_0x004ec95f;
L_0x004ecb06:
    // 004ecb06  896b14                 -mov dword ptr [ebx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004ecb09  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004ecb10  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ecb12  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004ecb14  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004ecb1a  e9f8feffff             -jmp 0x4eca17
    goto L_0x004eca17;
L_0x004ecb1f:
    // 004ecb1f  897b18                 -mov dword ptr [ebx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004ecb22  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004ecb29  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ecb2b  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004ecb2d  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004ecb33  e9f1feffff             -jmp 0x4eca29
    goto L_0x004eca29;
L_0x004ecb38:
    // 004ecb38  81bc2480040000e1000000 +cmp dword ptr [esp + 0x480], 0xe1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecb43  7510                   -jne 0x4ecb55
    if (!cpu.flags.zf)
    {
        goto L_0x004ecb55;
    }
    // 004ecb45  c7842484040000ffffffff -mov dword ptr [esp + 0x484], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = 4294967295 /*0xffffffff*/;
    // 004ecb50  e901ffffff             -jmp 0x4eca56
    goto L_0x004eca56;
L_0x004ecb55:
    // 004ecb55  83bc248404000000       +cmp dword ptr [esp + 0x484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecb5d  0f85f3feffff           -jne 0x4eca56
    if (!cpu.flags.zf)
    {
        goto L_0x004eca56;
    }
    // 004ecb63  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ecb6a  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ecb6d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ecb6f  804c820f80             +or byte ptr [edx + eax*4 + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004ecb74  e9ddfeffff             -jmp 0x4eca56
    goto L_0x004eca56;
L_0x004ecb79:
    // 004ecb79  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004ecb80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecb81  8bab54040000           -mov ebp, dword ptr [ebx + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecb87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ecb88  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecb8f  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004ecb96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecb97  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecb9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecb9e  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecba5  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004ecbac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecbad  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecbb3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecbb4  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecbbb  81bb6404000078ecffff   +cmp dword ptr [ebx + 0x464], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecbc5  7d1e                   -jge 0x4ecbe5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ecbe5;
    }
    // 004ecbc7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ecbc9  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecbd0  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004ecbd3  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ecbd5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ecbd7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ecbda  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ecbdc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ecbde  8984246c040000         -mov dword ptr [esp + 0x46c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */) = cpu.eax;
L_0x004ecbe5:
    // 004ecbe5  81bb6804000078ecffff   +cmp dword ptr [ebx + 0x468], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecbef  7d1e                   -jge 0x4ecc0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ecc0f;
    }
    // 004ecbf1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ecbf3  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecbfa  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ecbfd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ecbff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ecc01  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ecc04  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ecc06  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ecc08  89842470040000         -mov dword ptr [esp + 0x470], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */) = cpu.eax;
L_0x004ecc0f:
    // 004ecc0f  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004ecc16  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004ecc19  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ecc1b  89842474040000         -mov dword ptr [esp + 0x474], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */) = cpu.eax;
    // 004ecc22  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004ecc29  034318                 -add eax, dword ptr [ebx + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004ecc2c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ecc2e  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
    // 004ecc35  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004ecc37  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecc3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc3e  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecc45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc46  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004ecc4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc4e  2eff15ec465300         -call dword ptr cs:[0x5346ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457644) /* 0x5346ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecc55  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 004ecc5c  8b942470040000         -mov edx, dword ptr [esp + 0x470]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004ecc63  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 004ecc65  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ecc67  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004ecc6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc6f  8b84247c040000         -mov eax, dword ptr [esp + 0x47c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */);
    // 004ecc76  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ecc78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc79  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecc7a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecc7b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ecc7d  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecc83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecc84  2eff158c475300         -call dword ptr cs:[0x53478c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457804) /* 0x53478c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecc8b  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004ecc92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecc93  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ecc99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecc9a  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecca1  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004ecca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecca9  8bab54040000           -mov ebp, dword ptr [ebx + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004eccaf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eccb0  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eccb7  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004eccbe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eccbf  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004eccc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eccc6  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecccd  8b842474040000         -mov eax, dword ptr [esp + 0x474]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004eccd4  8b94246c040000         -mov edx, dword ptr [esp + 0x46c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004eccdb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004eccdd  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ecce0  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 004ecce7  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004eccee  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eccf0  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004eccf3  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004eccfa  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004ecd00  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004ecd07  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004ecd0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ecd0f  752b                   -jne 0x4ecd3c
    if (!cpu.flags.zf)
    {
        goto L_0x004ecd3c;
    }
    // 004ecd11  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
L_0x004ecd18:
    // 004ecd18  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ecd1b  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004ecd1e  c784248404000001000000 -mov dword ptr [esp + 0x484], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = 1 /*0x1*/;
    // 004ecd29  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 004ecd30  81c48c040000           +add esp, 0x48c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1164 /*0x48c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ecd36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecd37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecd38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecd39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecd3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecd3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecd3c:
    // 004ecd3c  a18c435600             -mov eax, dword ptr [0x56438c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 004ecd41  ebd5                   -jmp 0x4ecd18
    goto L_0x004ecd18;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ecd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ecd50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ecd51  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ecd53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ecd55  7505                   -jne 0x4ecd5c
    if (!cpu.flags.zf)
    {
        goto L_0x004ecd5c;
    }
    // 004ecd57  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x004ecd5c:
    // 004ecd5c  833b00                 +cmp dword ptr [ebx], 0
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
    // 004ecd5f  0f8496000000           -je 0x4ecdfb
    if (cpu.flags.zf)
    {
        goto L_0x004ecdfb;
    }
    // 004ecd65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ecd66  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ecd67  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecd68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecd69  688cbf5400             -push 0x54bf8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554060 /*0x54bf8c*/;
    cpu.esp -= 4;
    // 004ecd6e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ecd70  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecd75  e8d6420100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecd7a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecd7d  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ecd83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecd84  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecd8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ecd8c  e83ff3ffff             -call 0x4ec0d0
    cpu.esp -= 4;
    sub_4ec0d0(app, cpu);
    if (cpu.terminate) return;
    // 004ecd91  68a8bf5400             -push 0x54bfa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554088 /*0x54bfa8*/;
    cpu.esp -= 4;
    // 004ecd96  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004ecd98  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecd9d  e8ae420100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecda2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecda5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ecda7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecda8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecdaa  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecdad  68c8bf5400             -push 0x54bfc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554120 /*0x54bfc8*/;
    cpu.esp -= 4;
    // 004ecdb2  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004ecdb4  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecdb9  e892420100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecdbe  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ecdc1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecdc4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ecdc6  7407                   -je 0x4ecdcf
    if (cpu.flags.zf)
    {
        goto L_0x004ecdcf;
    }
    // 004ecdc8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ecdca  e8c14affff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004ecdcf:
    // 004ecdcf  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004ecdd6  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ecddd  8b3d80445600           -mov edi, dword ptr [0x564480]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ecde3  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004ecdea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ecdeb  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004ecdf1  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecdf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecdf8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecdf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecdfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ecdfb:
    // 004ecdfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecdfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ece00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ece00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ece01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ece02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ece04  7505                   -jne 0x4ece0b
    if (!cpu.flags.zf)
    {
        goto L_0x004ece0b;
    }
    // 004ece06  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ece0b:
    // 004ece0b  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 004ece11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ece12  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ece19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ece20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ece20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ece21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ece22  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ece25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ece27  7505                   -jne 0x4ece2e
    if (!cpu.flags.zf)
    {
        goto L_0x004ece2e;
    }
    // 004ece29  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ece2e:
    // 004ece2e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ece30  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ece32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ece33  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ece35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ece36  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ece39  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004ece3d  7509                   -jne 0x4ece48
    if (!cpu.flags.zf)
    {
        goto L_0x004ece48;
    }
    // 004ece3f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ece42  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ece45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ece48:
    // 004ece48  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ece4d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ece50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ece60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ece60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ece61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ece62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ece64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ece66  7505                   -jne 0x4ece6d
    if (!cpu.flags.zf)
    {
        goto L_0x004ece6d;
    }
    // 004ece68  b9d0389f00             -mov ecx, 0x9f38d0
    cpu.ecx = 10434768 /*0x9f38d0*/;
L_0x004ece6d:
    // 004ece6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ece6f  e82c040000             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
    // 004ece74  8b9944040000           -mov ebx, dword ptr [ecx + 0x444]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004ece7a  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ece7c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ece7e  7420                   -je 0x4ecea0
    if (cpu.flags.zf)
    {
        goto L_0x004ecea0;
    }
    // 004ece80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ece85:
    // 004ece85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ece86  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ece88  8b9144040000           -mov edx, dword ptr [ecx + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004ece8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ece8f  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ece92  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004ece96  750c                   -jne 0x4ecea4
    if (!cpu.flags.zf)
    {
        goto L_0x004ecea4;
    }
    // 004ece98  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ece9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ece9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecea0:
    // 004ecea0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ecea2  ebe1                   -jmp 0x4ece85
    goto L_0x004ece85;
L_0x004ecea4:
    // 004ecea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ecea6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecea7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecea8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4eceb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eceb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eceb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eceb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eceb4  7505                   -jne 0x4ecebb
    if (!cpu.flags.zf)
    {
        goto L_0x004ecebb;
    }
    // 004eceb6  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ecebb:
    // 004ecebb  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ecebd  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 004ecec3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecec4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecec6  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecec9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ecece  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eced3  7408                   -je 0x4ecedd
    if (cpu.flags.zf)
    {
        goto L_0x004ecedd;
    }
    // 004eced5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004eceda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecedb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecedc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecedd:
    // 004ecedd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ecedf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecee0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecee1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4ecef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ecef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecef1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecef2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ecef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ecef7  7505                   -jne 0x4ecefe
    if (!cpu.flags.zf)
    {
        goto L_0x004ecefe;
    }
    // 004ecef9  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ecefe:
    // 004ecefe  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ecf00  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecf03  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecf06  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecf09  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ecf0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ecf0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecf10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecf11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4ecf20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ecf20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecf21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ecf23  7505                   -jne 0x4ecf2a
    if (!cpu.flags.zf)
    {
        goto L_0x004ecf2a;
    }
    // 004ecf25  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ecf2a:
    // 004ecf2a  83fa02                 +cmp edx, 2
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
    // 004ecf2d  7512                   -jne 0x4ecf41
    if (!cpu.flags.zf)
    {
        goto L_0x004ecf41;
    }
    // 004ecf2f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004ecf34  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ecf36  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecf39  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecf3c  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecf3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecf40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ecf41:
    // 004ecf41  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ecf46  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ecf48  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecf4b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ecf4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ecf4e  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ecf51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ecf52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ecf60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ecf60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ecf61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ecf62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ecf63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ecf64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ecf65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ecf67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ecf69  7505                   -jne 0x4ecf70
    if (!cpu.flags.zf)
    {
        goto L_0x004ecf70;
    }
    // 004ecf6b  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x004ecf70:
    // 004ecf70  83bb3c04000000         +cmp dword ptr [ebx + 0x43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecf77  742e                   -je 0x4ecfa7
    if (cpu.flags.zf)
    {
        goto L_0x004ecfa7;
    }
    // 004ecf79  b91cbb5400             -mov ecx, 0x54bb1c
    cpu.ecx = 5552924 /*0x54bb1c*/;
    // 004ecf7e  bed4bf5400             -mov esi, 0x54bfd4
    cpu.esi = 5554132 /*0x54bfd4*/;
    // 004ecf83  bf7e030000             -mov edi, 0x37e
    cpu.edi = 894 /*0x37e*/;
    // 004ecf88  68e4bf5400             -push 0x54bfe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554148 /*0x54bfe4*/;
    cpu.esp -= 4;
    // 004ecf8d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ecf93  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004ecf99  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004ecf9f  e86c40f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ecfa4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ecfa7:
    // 004ecfa7  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecfab  0f84a8000000           -je 0x4ed059
    if (cpu.flags.zf)
    {
        goto L_0x004ed059;
    }
    // 004ecfb1  837b1c08               +cmp dword ptr [ebx + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ecfb5  0f8f9e000000           -jg 0x4ed059
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ed059;
    }
    // 004ecfbb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ecfbc  6824c05400             -push 0x54c024
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554212 /*0x54c024*/;
    cpu.esp -= 4;
    // 004ecfc1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ecfc3  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ecfc8  e883400100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ecfcd  8bb32e040000           -mov esi, dword ptr [ebx + 0x42e]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1070) /* 0x42e */);
    // 004ecfd3  8b8330040000           -mov eax, dword ptr [ebx + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1072) /* 0x430 */);
    // 004ecfd9  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004ecfdc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ecfdf  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ecfe1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ecfe4  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ecfe7  81fe00010000           +cmp esi, 0x100
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
    // 004ecfed  7d57                   -jge 0x4ed046
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ed046;
    }
    // 004ecfef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ecff1  7e53                   -jle 0x4ed046
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ed046;
    }
    // 004ecff3  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ecffa  8d6b30                 -lea ebp, [ebx + 0x30]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004ecffd  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ecfff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed000  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed002  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004ed005  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed007  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed009  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed00a  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed00d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ed012  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed013  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed014  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed015  683cc05400             -push 0x54c03c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554236 /*0x54c03c*/;
    cpu.esp -= 4;
    // 004ed01a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ed01c  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed021  e82a400100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed026  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 004ed02c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ed02f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004ed031  7513                   -jne 0x4ed046
    if (!cpu.flags.zf)
    {
        goto L_0x004ed046;
    }
    // 004ed033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed034  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004ed039  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed03b  8b7324                 -mov esi, dword ptr [ebx + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004ed03e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed040  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ed042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed043  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ed046:
    // 004ed046  66c78332040000ffff     -mov word ptr [ebx + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 004ed04f  66c783300400000001     -mov word ptr [ebx + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004ed058  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ed059:
    // 004ed059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed05a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed05b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed05c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed05d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed05e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ed060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed061  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004ed067  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004ed069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed06b  7505                   -jne 0x4ed072
    if (!cpu.flags.zf)
    {
        goto L_0x004ed072;
    }
    // 004ed06d  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ed072:
    // 004ed072  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ed075  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed077  7459                   -je 0x4ed0d2
    if (cpu.flags.zf)
    {
        goto L_0x004ed0d2;
    }
    // 004ed079  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed07a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed07b  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed07f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed080  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004ed085  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed087  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed089  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ed08b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ed08d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed08e  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed091  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ed093  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ed095:
    // 004ed095  0fb6748408             -movzx esi, byte ptr [esp + eax*4 + 8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.eax * 4));
    // 004ed09a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed09c  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004ed09f  8a5c8409               -mov bl, byte ptr [esp + eax*4 + 9]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */ + cpu.eax * 4);
    // 004ed0a3  81ce000000ff           -or esi, 0xff000000
    cpu.esi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004ed0a9  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ed0ac  8a54840a               -mov dl, byte ptr [esp + eax*4 + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */ + cpu.eax * 4);
    // 004ed0b0  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed0b2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ed0b8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed0bb  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004ed0bd  40                     -inc eax
    (cpu.eax)++;
    // 004ed0be  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004ed0c1  3d00010000             +cmp eax, 0x100
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
    // 004ed0c6  7ccd                   -jl 0x4ed095
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ed095;
    }
    // 004ed0c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed0c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed0ca  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004ed0d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed0d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed0d2:
    // 004ed0d2  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 004ed0d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ed0d9  e82e36ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004ed0de  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004ed0e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed0e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ed0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed0f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed0f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed0f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed0f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed0f4  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed0f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ed0f9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ed0fb  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004ed0fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed0ff  7505                   -jne 0x4ed106
    if (!cpu.flags.zf)
    {
        goto L_0x004ed106;
    }
    // 004ed101  bed0389f00             -mov esi, 0x9f38d0
    cpu.esi = 10434768 /*0x9f38d0*/;
L_0x004ed106:
    // 004ed106  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ed108  7408                   -je 0x4ed112
    if (cpu.flags.zf)
    {
        goto L_0x004ed112;
    }
    // 004ed10a  3bbe3c040000           +cmp edi, dword ptr [esi + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed110  7429                   -je 0x4ed13b
    if (cpu.flags.zf)
    {
        goto L_0x004ed13b;
    }
L_0x004ed112:
    // 004ed112  83be3c04000000         +cmp dword ptr [esi + 0x43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed119  7407                   -je 0x4ed122
    if (cpu.flags.zf)
    {
        goto L_0x004ed122;
    }
    // 004ed11b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ed11d  e87e010000             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
L_0x004ed122:
    // 004ed122  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ed124  751c                   -jne 0x4ed142
    if (!cpu.flags.zf)
    {
        goto L_0x004ed142;
    }
L_0x004ed126:
    // 004ed126  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ed128  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed12d  892de8435600           -mov dword ptr [0x5643e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.ebp;
L_0x004ed133:
    // 004ed133  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ed136  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed137  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed138  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed139  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed13a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed13b:
    // 004ed13b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed140  ebf1                   -jmp 0x4ed133
    goto L_0x004ed133;
L_0x004ed142:
    // 004ed142  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed148  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed149  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed14f  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ed156  0f8588000000           -jne 0x4ed1e4
    if (!cpu.flags.zf)
    {
        goto L_0x004ed1e4;
    }
L_0x004ed15c:
    // 004ed15c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004ed15e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ed160  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ed162  e879e4ffff             -call 0x4eb5e0
    cpu.esp -= 4;
    sub_4eb5e0(app, cpu);
    if (cpu.terminate) return;
    // 004ed167  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ed169:
    // 004ed169  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed170  a3ec4e5600             -mov dword ptr [0x564eec], eax
    app->getMemory<x86::reg32>(x86::reg32(5656300) /* 0x564eec */) = cpu.eax;
    // 004ed175  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ed177  0f849a000000           -je 0x4ed217
    if (cpu.flags.zf)
    {
        goto L_0x004ed217;
    }
    // 004ed17d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ed182  8b15e84e5600           -mov edx, dword ptr [0x564ee8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656296) /* 0x564ee8 */);
    // 004ed188  a3e04e5600             -mov dword ptr [0x564ee0], eax
    app->getMemory<x86::reg32>(x86::reg32(5656288) /* 0x564ee0 */) = cpu.eax;
    // 004ed18d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed18f  741d                   -je 0x4ed1ae
    if (cpu.flags.zf)
    {
        goto L_0x004ed1ae;
    }
    // 004ed191  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed192  6864c05400             -push 0x54c064
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554276 /*0x54c064*/;
    cpu.esp -= 4;
    // 004ed197  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ed199  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed19e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ed1a0  e8ab3e0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed1a5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ed1a8  890de84e5600           -mov dword ptr [0x564ee8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656296) /* 0x564ee8 */) = cpu.ecx;
L_0x004ed1ae:
    // 004ed1ae  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed1b4  c7864004000000000000   -mov dword ptr [esi + 0x440], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 004ed1be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed1bf  c7863c04000000000000   -mov dword ptr [esi + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 004ed1c9  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004ed1ce  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed1d4  8935e8435600           -mov dword ptr [0x5643e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.esi;
    // 004ed1da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed1dc  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed1df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed1e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed1e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed1e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed1e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed1e4:
    // 004ed1e4  e837bf0000             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 004ed1e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed1eb  750a                   -jne 0x4ed1f7
    if (!cpu.flags.zf)
    {
        goto L_0x004ed1f7;
    }
    // 004ed1ed  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 004ed1f2  e972ffffff             -jmp 0x4ed169
    goto L_0x004ed169;
L_0x004ed1f7:
    // 004ed1f7  8b8654040000           -mov eax, dword ptr [esi + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 004ed1fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed1fe  2eff155c475300         -call dword ptr cs:[0x53475c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457756) /* 0x53475c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed205  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed207  0f844fffffff           -je 0x4ed15c
    if (cpu.flags.zf)
    {
        goto L_0x004ed15c;
    }
    // 004ed20d  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 004ed212  e952ffffff             -jmp 0x4ed169
    goto L_0x004ed169;
L_0x004ed217:
    // 004ed217  833de84e560000         +cmp dword ptr [0x564ee8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5656296) /* 0x564ee8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed21e  751f                   -jne 0x4ed23f
    if (!cpu.flags.zf)
    {
        goto L_0x004ed23f;
    }
    // 004ed220  689cc05400             -push 0x54c09c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554332 /*0x54c09c*/;
    cpu.esp -= 4;
    // 004ed225  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ed227  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed22c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ed231  e81a3e0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed236  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ed239  890de84e5600           -mov dword ptr [0x564ee8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656296) /* 0x564ee8 */) = cpu.ecx;
L_0x004ed23f:
    // 004ed23f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed243  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 004ed249  898640040000           -mov dword ptr [esi + 0x440], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.eax;
    // 004ed24f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ed251  0f84cffeffff           -je 0x4ed126
    if (cpu.flags.zf)
    {
        goto L_0x004ed126;
    }
    // 004ed257  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ed25b  8a8e5d040000           -mov cl, byte ptr [esi + 0x45d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 004ed261  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed265  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004ed267  7529                   -jne 0x4ed292
    if (!cpu.flags.zf)
    {
        goto L_0x004ed292;
    }
    // 004ed269  3bbe44040000           +cmp edi, dword ptr [esi + 0x444]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed26f  7521                   -jne 0x4ed292
    if (!cpu.flags.zf)
    {
        goto L_0x004ed292;
    }
    // 004ed271  8b9e68040000           -mov ebx, dword ptr [esi + 0x468]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1128) /* 0x468 */);
    // 004ed277  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004ed27a  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004ed27e  8b8e64040000           -mov ecx, dword ptr [esi + 0x464]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1124) /* 0x464 */);
    // 004ed284  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ed287  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ed28a  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed28e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ed290  01fb                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004ed292:
    // 004ed292  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ed294  e807bb0100             -call 0x508da0
    cpu.esp -= 4;
    sub_508da0(app, cpu);
    if (cpu.terminate) return;
    // 004ed299  e988feffff             -jmp 0x4ed126
    goto L_0x004ed126;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ed2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed2a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed2a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed2a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ed2a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed2a7  7505                   -jne 0x4ed2ae
    if (!cpu.flags.zf)
    {
        goto L_0x004ed2ae;
    }
    // 004ed2a9  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x004ed2ae:
    // 004ed2ae  8b933c040000           -mov edx, dword ptr [ebx + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
    // 004ed2b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed2b6  750c                   -jne 0x4ed2c4
    if (!cpu.flags.zf)
    {
        goto L_0x004ed2c4;
    }
    // 004ed2b8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ed2ba  893de8435600           -mov dword ptr [0x5643e8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.edi;
    // 004ed2c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed2c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed2c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed2c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed2c4:
    // 004ed2c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed2c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed2c6  8b8b40040000           -mov ecx, dword ptr [ebx + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */);
    // 004ed2cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed2cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ed2cf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ed2d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed2d2  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed2d8  c7833c04000000000000   -mov dword ptr [ebx + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 004ed2e2  c7834004000000000000   -mov dword ptr [ebx + 0x440], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 004ed2ec  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed2f3  8b1dec4e5600           -mov ebx, dword ptr [0x564eec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656300) /* 0x564eec */);
    // 004ed2f9  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed2fb  8b1de44e5600           -mov ebx, dword ptr [0x564ee4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656292) /* 0x564ee4 */);
    // 004ed301  a3e04e5600             -mov dword ptr [0x564ee0], eax
    app->getMemory<x86::reg32>(x86::reg32(5656288) /* 0x564ee0 */) = cpu.eax;
    // 004ed306  39d8                   +cmp eax, ebx
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
    // 004ed308  7e05                   -jle 0x4ed30f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ed30f;
    }
    // 004ed30a  a3e44e5600             -mov dword ptr [0x564ee4], eax
    app->getMemory<x86::reg32>(x86::reg32(5656292) /* 0x564ee4 */) = cpu.eax;
L_0x004ed30f:
    // 004ed30f  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed315  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed316  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed31c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed31d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed31e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ed320  893de8435600           -mov dword ptr [0x5643e8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.edi;
    // 004ed326  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed327  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed328  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ed330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed332  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed333  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed334  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed335  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed336  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed339  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ed33b  8b903c040000           -mov edx, dword ptr [eax + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */);
    // 004ed341  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed343  750f                   -jne 0x4ed354
    if (!cpu.flags.zf)
    {
        goto L_0x004ed354;
    }
    // 004ed345  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed34a  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed34d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed34e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed34f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed350  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed351  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed352  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed353  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed354:
    // 004ed354  8b8e40040000           -mov ecx, dword ptr [esi + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */);
    // 004ed35a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed35b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ed35d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed35e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ed360  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed366  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed36d  8b1dec4e5600           -mov ebx, dword ptr [0x564eec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656300) /* 0x564eec */);
    // 004ed373  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed375  8b1de44e5600           -mov ebx, dword ptr [0x564ee4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656292) /* 0x564ee4 */);
    // 004ed37b  a3e04e5600             -mov dword ptr [0x564ee0], eax
    app->getMemory<x86::reg32>(x86::reg32(5656288) /* 0x564ee0 */) = cpu.eax;
    // 004ed380  39d8                   +cmp eax, ebx
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
    // 004ed382  7e05                   -jle 0x4ed389
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ed389;
    }
    // 004ed384  a3e44e5600             -mov dword ptr [0x564ee4], eax
    app->getMemory<x86::reg32>(x86::reg32(5656292) /* 0x564ee4 */) = cpu.eax;
L_0x004ed389:
    // 004ed389  8b2d80445600           -mov ebp, dword ptr [0x564480]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed38f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed390  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed396  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed39b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed39c  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed3a0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed3a6  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed3ad  a3ec4e5600             -mov dword ptr [0x564eec], eax
    app->getMemory<x86::reg32>(x86::reg32(5656300) /* 0x564eec */) = cpu.eax;
    // 004ed3b2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ed3b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ed3b6  e825e2ffff             -call 0x4eb5e0
    cpu.esp -= 4;
    sub_4eb5e0(app, cpu);
    if (cpu.terminate) return;
    // 004ed3bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed3bd  7516                   -jne 0x4ed3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004ed3d5;
    }
    // 004ed3bf  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed3c3  3b9640040000           +cmp edx, dword ptr [esi + 0x440]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed3c9  7455                   -je 0x4ed420
    if (cpu.flags.zf)
    {
        goto L_0x004ed420;
    }
    // 004ed3cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed3cc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004ed3ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed3cf  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ed3d5:
    // 004ed3d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed3d7  899e40040000           -mov dword ptr [esi + 0x440], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.ebx;
    // 004ed3dd  899e3c040000           -mov dword ptr [esi + 0x43c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.ebx;
    // 004ed3e3  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed3e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed3ea  891de04e5600           -mov dword ptr [0x564ee0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656288) /* 0x564ee0 */) = cpu.ebx;
    // 004ed3f0  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed3f6  a1f0435600             -mov eax, dword ptr [0x5643f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
    // 004ed3fb  e8a0d9ffff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 004ed400  68bcc05400             -push 0x54c0bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554364 /*0x54c0bc*/;
    cpu.esp -= 4;
    // 004ed405  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004ed407  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed40c  e83f3c0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed411  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ed414  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed416  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed419  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed41f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed420:
    // 004ed420  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed425  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 004ed42b  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed42e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed42f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed432  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed433  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4ed440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed443  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed446  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ed448  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004ed44a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ed44c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed44e  e88de1ffff             -call 0x4eb5e0
    cpu.esp -= 4;
    sub_4eb5e0(app, cpu);
    if (cpu.terminate) return;
    // 004ed453  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed455  7507                   -jne 0x4ed45e
    if (!cpu.flags.zf)
    {
        goto L_0x004ed45e;
    }
    // 004ed457  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed45a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed45b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed45c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed45d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed45e:
    // 004ed45e  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed462  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed463  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ed465  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed466  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed46c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed471  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed474  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed476  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ed480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed480  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed481  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed482  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed483  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ed486  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ed488  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ed48a  894c2478               -mov dword ptr [esp + 0x78], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.ecx;
    // 004ed48e  8b8c2490000000         -mov ecx, dword ptr [esp + 0x90]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004ed495  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed497  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ed499  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ed49b  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004ed49f  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004ed4a4  e86332ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004ed4a9  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 004ed4ae  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ed4b3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ed4b6  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004ed4bd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ed4c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed4c3  7e1e                   -jle 0x4ed4e3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ed4e3;
    }
    // 004ed4c5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ed4c9  8aa42494000000         -mov ah, byte ptr [esp + 0x94]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004ed4d0  ba21000000             -mov edx, 0x21
    cpu.edx = 33 /*0x21*/;
    // 004ed4d5  80cc18                 -or ah, 0x18
    cpu.ah |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 004ed4d8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ed4dc  88a42494000000         -mov byte ptr [esp + 0x94], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ah;
L_0x004ed4e3:
    // 004ed4e3  8a942495000000         -mov dl, byte ptr [esp + 0x95]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */);
    // 004ed4ea  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004ed4ed  7478                   -je 0x4ed567
    if (cpu.flags.zf)
    {
        goto L_0x004ed567;
    }
L_0x004ed4ef:
    // 004ed4ef  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004ed4f6  40                     -inc eax
    (cpu.eax)++;
    // 004ed4f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed4f8  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004ed4fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed4fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed4fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed4ff  6820c15400             -push 0x54c120
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554464 /*0x54c120*/;
    cpu.esp -= 4;
    // 004ed504  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004ed506  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed50b  e8403b0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed510  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ed513  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004ed51a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed51c  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 004ed520  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed525  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed52a  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ed52d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed52e  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed531  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ed533  81e3ffff0000           +and ebx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004ed539  0f84a5000000           -je 0x4ed5e4
    if (cpu.flags.zf)
    {
        goto L_0x004ed5e4;
    }
    // 004ed53f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ed541  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
L_0x004ed545:
    // 004ed545  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed546  6894c15400             -push 0x54c194
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554580 /*0x54c194*/;
    cpu.esp -= 4;
    // 004ed54b  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004ed54d  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed552  e8f93a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed557  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ed55a  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed55e  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ed561  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed562  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed563  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed564  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004ed567:
    // 004ed567  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004ed56a  7583                   -jne 0x4ed4ef
    if (!cpu.flags.zf)
    {
        goto L_0x004ed4ef;
    }
    // 004ed56c  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed570  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ed574  0c06                   -or al, 6
    cpu.al |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 004ed576  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ed57a  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004ed57e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ed580  7f30                   -jg 0x4ed5b2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ed5b2;
    }
    // 004ed582  0f8567ffffff           -jne 0x4ed4ef
    if (!cpu.flags.zf)
    {
        goto L_0x004ed4ef;
    }
    // 004ed588  8a642405               -mov ah, byte ptr [esp + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 004ed58c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004ed591  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004ed595  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004ed598  894c2448               -mov dword ptr [esp + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ecx;
    // 004ed59c  88642405               -mov byte ptr [esp + 5], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.ah;
    // 004ed5a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed5a1  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004ed5a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed5a8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed5aa  ff5154                 -call dword ptr [ecx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed5ad  e93dffffff             -jmp 0x4ed4ef
    goto L_0x004ed4ef;
L_0x004ed5b2:
    // 004ed5b2  b81cbb5400             -mov eax, 0x54bb1c
    cpu.eax = 5552924 /*0x54bb1c*/;
    // 004ed5b7  bad4c05400             -mov edx, 0x54c0d4
    cpu.edx = 5554388 /*0x54c0d4*/;
    // 004ed5bc  b958040000             -mov ecx, 0x458
    cpu.ecx = 1112 /*0x458*/;
    // 004ed5c1  68e0c05400             -push 0x54c0e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554400 /*0x54c0e0*/;
    cpu.esp -= 4;
    // 004ed5c6  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004ed5cb  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004ed5d1  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004ed5d7  e8343af1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ed5dc  83c404                 +add esp, 4
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
    // 004ed5df  e90bffffff             -jmp 0x4ed4ef
    goto L_0x004ed4ef;
L_0x004ed5e4:
    // 004ed5e4  684cc15400             -push 0x54c14c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554508 /*0x54c14c*/;
    cpu.esp -= 4;
    // 004ed5e9  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004ed5eb  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed5f0  e85b3a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed5f5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ed5f8  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed5fd  7518                   -jne 0x4ed617
    if (!cpu.flags.zf)
    {
        goto L_0x004ed617;
    }
L_0x004ed5ff:
    // 004ed5ff  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed604  0f843bffffff           -je 0x4ed545
    if (cpu.flags.zf)
    {
        goto L_0x004ed545;
    }
    // 004ed60a  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed60e  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ed611  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed612  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed613  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed614  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004ed617:
    // 004ed617  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed61d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed61e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed624  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004ed626  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed62a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed62c  e8afdfffff             -call 0x4eb5e0
    cpu.esp -= 4;
    sub_4eb5e0(app, cpu);
    if (cpu.terminate) return;
    // 004ed631  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ed633  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed635  0f84af000000           -je 0x4ed6ea
    if (cpu.flags.zf)
    {
        goto L_0x004ed6ea;
    }
    // 004ed63b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed63c  6868c15400             -push 0x54c168
    app->getMemory<x86::reg32>(cpu.esp-4) = 5554536 /*0x54c168*/;
    cpu.esp -= 4;
    // 004ed641  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 004ed643  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004ed648  e8033a0100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004ed64d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ed650:
    // 004ed650  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ed655  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed656  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed65c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ed65e  740d                   -je 0x4ed66d
    if (cpu.flags.zf)
    {
        goto L_0x004ed66d;
    }
    // 004ed660  80be5f04000000         +cmp byte ptr [esi + 0x45f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ed667  0f84a4000000           -je 0x4ed711
    if (cpu.flags.zf)
    {
        goto L_0x004ed711;
    }
L_0x004ed66d:
    // 004ed66d  be6c000000             -mov esi, 0x6c
    cpu.esi = 108 /*0x6c*/;
    // 004ed672  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed676  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004ed679  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed67b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ed67d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed67e  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed683  bd20000000             -mov ebp, 0x20
    cpu.ebp = 32 /*0x20*/;
    // 004ed688  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed68b  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed68f  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004ed693  896c2448               -mov dword ptr [esp + 0x48], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebp;
    // 004ed697  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed698  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed69c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed69e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed69f  ff5054                 -call dword ptr [eax + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed6a2  837c245408             +cmp dword ptr [esp + 0x54], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed6a7  775c                   -ja 0x4ed705
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ed705;
    }
    // 004ed6a9  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004ed6ae  8b942498000000         -mov edx, dword ptr [esp + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004ed6b5  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 004ed6b9  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 004ed6bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed6bf  740f                   -je 0x4ed6d0
    if (cpu.flags.zf)
    {
        goto L_0x004ed6d0;
    }
    // 004ed6c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed6c2  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed6c6  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed6ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed6cb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed6cd  ff507c                 -call dword ptr [eax + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ed6d0:
    // 004ed6d0  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004ed6d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed6d5  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed6d9  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004ed6db  8b7c247c               -mov edi, dword ptr [esp + 0x7c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004ed6df  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004ed6e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed6e2  ff5674                 -call dword ptr [esi + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed6e5  e915ffffff             -jmp 0x4ed5ff
    goto L_0x004ed5ff;
L_0x004ed6ea:
    // 004ed6ea  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed6ee  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed6f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed6f3  8b6c2478               -mov ebp, dword ptr [esp + 0x78]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ed6f7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed6f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed6fa  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed700  e94bffffff             -jmp 0x4ed650
    goto L_0x004ed650;
L_0x004ed705:
    // 004ed705  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004ed707  89742470               -mov dword ptr [esp + 0x70], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.esi;
    // 004ed70b  8974246c               -mov dword ptr [esp + 0x6c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.esi;
    // 004ed70f  ebbf                   -jmp 0x4ed6d0
    goto L_0x004ed6d0;
L_0x004ed711:
    // 004ed711  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed715  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed719  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed71a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed71c  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed71f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004ed721  894c2474               -mov dword ptr [esp + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 004ed725  e91bfeffff             -jmp 0x4ed545
    goto L_0x004ed545;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ed730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed731  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ed733  7505                   -jne 0x4ed73a
    if (!cpu.flags.zf)
    {
        goto L_0x004ed73a;
    }
    // 004ed735  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
L_0x004ed73a:
    // 004ed73a  3b903c040000           +cmp edx, dword ptr [eax + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ed740  7408                   -je 0x4ed74a
    if (cpu.flags.zf)
    {
        goto L_0x004ed74a;
    }
    // 004ed742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed743  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ed745  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed748  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed749  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed74a:
    // 004ed74a  e851fbffff             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
    // 004ed74f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed750  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ed752  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed755  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed756  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ed760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed761  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed762  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed763  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed765  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed768  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed769  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed76a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ed770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed770  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed771  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed772  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed775  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ed777  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ed77a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ed77c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ed781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed782  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed786  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004ed78a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed78b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed78d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed78e  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed791  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ed794  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed799  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ed7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed7a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed7a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7a2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed7a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ed7a7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ed7aa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ed7ac  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ed7b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7b2  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed7b6  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004ed7ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7bb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed7bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed7be  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed7c1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ed7c4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed7c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed7c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed7c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ed7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed7d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed7d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7d2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed7d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ed7d7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ed7da  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ed7dc  b900000200             -mov ecx, 0x20000
    cpu.ecx = 131072 /*0x20000*/;
    // 004ed7e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7e2  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed7e6  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004ed7ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed7eb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ed7ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed7ee  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed7f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ed7f4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ed7f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed7f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed7f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
