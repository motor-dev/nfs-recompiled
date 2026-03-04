#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5fa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5fa4  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 004f5fa9  83c026                 -add eax, 0x26
    (cpu.eax) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 004f5fac  e87faefeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f5fb1  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004f5fb4  e817c80100             -call 0x5127d0
    cpu.esp -= 4;
    sub_5127d0(app, cpu);
    if (cpu.terminate) return;
    // 004f5fb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5fba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5fbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fc0  c6402600               -mov byte ptr [eax + 0x26], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(38) /* 0x26 */) = 0 /*0x0*/;
    // 004f5fc4  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f5fca  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f5fd0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5fe1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5fe2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5fe3  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004f5fe8  8d7b04                 -lea edi, [ebx + 4]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f5feb  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5fee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f5ff0  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f5ff2  7405                   -je 0x4f5ff9
    if (cpu.flags.zf)
    {
        goto L_0x004f5ff9;
    }
    // 004f5ff4  19c0                   +sbb eax, eax
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
    // 004f5ff6  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f5ff9:
    // 004f5ff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5ffb  7509                   -jne 0x4f6006
    if (!cpu.flags.zf)
    {
        goto L_0x004f6006;
    }
    // 004f5ffd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6002  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6003  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6005  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6006:
    // 004f6006  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6008  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6009  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f600a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f600b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f6010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6012  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f6014  8d705c                 -lea esi, [eax + 0x5c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004f6017  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f601c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6020  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6021  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f6030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6033  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f6036  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6038  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004f603d  e88e810100             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 004f6042  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6044  760c                   -jbe 0x4f6052
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6052;
    }
L_0x004f6046:
    // 004f6046  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f604b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f604e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f604f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6050  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6051  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6052:
    // 004f6052  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6056  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6057  687f660440             -push 0x4004667f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1074030207 /*0x4004667f*/;
    cpu.esp -= 4;
    // 004f605c  8b5358                 -mov edx, dword ptr [ebx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004f605f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6060  e8ebdd0300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f6065  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f6068  83f8ff                 +cmp eax, -1
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
    // 004f606b  7410                   -je 0x4f607d
    if (cpu.flags.zf)
    {
        goto L_0x004f607d;
    }
    // 004f606d  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004f6072  77d2                   -ja 0x4f6046
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f6046;
    }
    // 004f6074  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6076  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f6079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f607d:
    // 004f607d  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6084  7c1a                   -jl 0x4f60a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f60a0;
    }
    // 004f6086  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6088  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f608d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6091  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f6093  b874d25400             -mov eax, 0x54d274
    cpu.eax = 5558900 /*0x54d274*/;
    // 004f6098  83c358                 -add ebx, 0x58
    (cpu.ebx) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004f609b  e8e0c00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f60a0:
    // 004f60a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f60a2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f60a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f60b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f60b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f60b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f60b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f60b3  81ec38010000           -sub esp, 0x138
    (cpu.esp) -= x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f60b9  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004f60c0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f60c2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f60c4  899c242c010000         -mov dword ptr [esp + 0x12c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.ebx;
    // 004f60cb  81ff18010000           +cmp edi, 0x118
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(280 /*0x118*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f60d1  7e05                   -jle 0x4f60d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f60d8;
    }
    // 004f60d3  bf18010000             -mov edi, 0x118
    cpu.edi = 280 /*0x118*/;
L_0x004f60d8:
    // 004f60d8  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004f60df  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f60e3  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f60e5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f60e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f60ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f60ec  e8ff43ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f60f1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f60f3  0f84a6000000           -je 0x4f619f
    if (cpu.flags.zf)
    {
        goto L_0x004f619f;
    }
    // 004f60f9  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004f6100  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6102  e8b9f7ffff             -call 0x4f58c0
    cpu.esp -= 4;
    sub_4f58c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f6107:
    // 004f6107  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f610d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f610e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6114  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004f6116  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004f611d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f611e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6120  8d4704                 -lea eax, [edi + 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f6123  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6124  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6128  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6129  8b4d58                 -mov ecx, dword ptr [ebp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    // 004f612c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f612d  e800dd0300             -call 0x533e32
    cpu.esp -= 4;
    sub_533e32(app, cpu);
    if (cpu.terminate) return;
    // 004f6132  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6134  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 004f613b  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6140  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6141  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6147  83fbff                 +cmp ebx, -1
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
    // 004f614a  756a                   -jne 0x4f61b6
    if (!cpu.flags.zf)
    {
        goto L_0x004f61b6;
    }
    // 004f614c  e8e7dc0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f6151  8b0de06d5600           -mov ecx, dword ptr [0x566de0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f6157  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004f615e  83f904                 +cmp ecx, 4
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
    // 004f6161  7c1d                   -jl 0x4f6180
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6180;
    }
    // 004f6163  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6165  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f616a  8d942434010000         -lea edx, [esp + 0x134]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004f6171  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f6173  b884d25400             -mov eax, 0x54d284
    cpu.eax = 5558916 /*0x54d284*/;
    // 004f6178  8d5d58                 -lea ebx, [ebp + 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(88) /* 0x58 */);
L_0x004f617b:
    // 004f617b  e800c00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f6180:
    // 004f6180  8b9c2434010000         -mov ebx, dword ptr [esp + 0x134]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004f6187  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f618a  39df                   +cmp edi, ebx
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
    // 004f618c  754a                   -jne 0x4f61d8
    if (!cpu.flags.zf)
    {
        goto L_0x004f61d8;
    }
    // 004f618e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6193  81c438010000           -add esp, 0x138
    (cpu.esp) += x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f6199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f619f:
    // 004f619f  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 004f61a2  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004f61a9  c1f810                 +sar eax, 0x10
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
    // 004f61ac  e84ff7ffff             -call 0x4f5900
    cpu.esp -= 4;
    sub_4f5900(app, cpu);
    if (cpu.terminate) return;
    // 004f61b1  e951ffffff             -jmp 0x4f6107
    goto L_0x004f6107;
L_0x004f61b6:
    // 004f61b6  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f61bd  7cc1                   -jl 0x4f6180
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6180;
    }
    // 004f61bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f61c1  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f61c6  8d942430010000         -lea edx, [esp + 0x130]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004f61cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f61cf  b890d25400             -mov eax, 0x54d290
    cpu.eax = 5558928 /*0x54d290*/;
    // 004f61d4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f61d6  eba3                   -jmp 0x4f617b
    goto L_0x004f617b;
L_0x004f61d8:
    // 004f61d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f61da  81c438010000           -add esp, 0x138
    (cpu.esp) += x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f61e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f61f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f61f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f61f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f61f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f61f3  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f61f6  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004f61fa  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f61fe  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f6202  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f6206  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f620a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f620c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f620e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f6211  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6215  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6216  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6217  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6218  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6219  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f621a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f621c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f6220  8db08c000000           -lea esi, [eax + 0x8c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004f6226  ba805a4f00             -mov edx, 0x4f5a80
    cpu.edx = 5200512 /*0x4f5a80*/;
    // 004f622b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f622d  e86e830100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f6232  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6234  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6236  745f                   -je 0x4f6297
    if (cpu.flags.zf)
    {
        goto L_0x004f6297;
    }
    // 004f6238  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f623c  83c770                 -add edi, 0x70
    (cpu.edi) += x86::reg32(x86::sreg32(112 /*0x70*/));
L_0x004f623f:
    // 004f623f  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f6244  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6247  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f624a  7d60                   -jge 0x4f62ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f62ac;
    }
    // 004f624c  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6253  7c19                   -jl 0x4f626e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f626e;
    }
    // 004f6255  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6257  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f625c  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f625f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6261  b89cd25400             -mov eax, 0x54d29c
    cpu.eax = 5558940 /*0x54d29c*/;
    // 004f6266  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f6269  e812bf0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f626e:
    // 004f626e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f6270  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6272  e8d97b0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f6277  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f627b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f627d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6280  ba805a4f00             -mov edx, 0x4f5a80
    cpu.edx = 5200512 /*0x4f5a80*/;
    // 004f6285  e8a698feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f628a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f628c  e80f830100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f6291  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6293  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6295  75a8                   -jne 0x4f623f
    if (!cpu.flags.zf)
    {
        goto L_0x004f623f;
    }
L_0x004f6297:
    // 004f6297  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f629b  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004f62a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f62a3  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f62a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f62ac:
    // 004f62ac  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f62af  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f62b2  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004f62b6  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004f62ba  39c8                   +cmp eax, ecx
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
    // 004f62bc  0f8e78000000           -jle 0x4f633a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f633a;
    }
    // 004f62c2  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
L_0x004f62c6:
    // 004f62c6  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f62ca  8d750c                 -lea esi, [ebp + 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f62cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d2  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f62d6  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f62d9  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f62dd  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f62df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f62e1  740e                   -je 0x4f62f1
    if (cpu.flags.zf)
    {
        goto L_0x004f62f1;
    }
    // 004f62e3  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f62e7  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004f62ea  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f62ec  e8ff41ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f62f1:
    // 004f62f1  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f62f8  7c19                   -jl 0x4f6313
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6313;
    }
    // 004f62fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f62fc  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f6301  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f6304  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6306  b8a8d25400             -mov eax, 0x54d2a8
    cpu.eax = 5558952 /*0x54d2a8*/;
    // 004f630b  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f630e  e86dbe0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f6313:
    // 004f6313  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6317  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f6319  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f631c  e82f7b0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f6321  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6325  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6328  e80398feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f632d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f6331  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f6334  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6335  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6336  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6337  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f633a:
    // 004f633a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f633c  7d88                   -jge 0x4f62c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f62c6;
    }
    // 004f633e  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f6340  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004f6344  eb80                   -jmp 0x4f62c6
    goto L_0x004f62c6;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6350  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6351  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f6354  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6356  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f635a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f635d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f635f  7531                   -jne 0x4f6392
    if (!cpu.flags.zf)
    {
        goto L_0x004f6392;
    }
    // 004f6361  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004f6365:
    // 004f6365  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f636c  7d39                   -jge 0x4f63a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f63a7;
    }
L_0x004f636e:
    // 004f636e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f6370  bac05a4f00             -mov edx, 0x4f5ac0
    cpu.edx = 5200576 /*0x4f5ac0*/;
    // 004f6375  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004f637b  e830860100             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 004f6380  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f6383  e8a897feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f6388  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f638d  83c420                 +add esp, 0x20
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
    // 004f6390  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6391  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6392:
    // 004f6392  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6394  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6398  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f639a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f63a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f63a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f63a5  ebbe                   -jmp 0x4f6365
    goto L_0x004f6365;
L_0x004f63a7:
    // 004f63a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f63a9  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f63ae  b8b4d25400             -mov eax, 0x54d2b4
    cpu.eax = 5558964 /*0x54d2b4*/;
    // 004f63b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f63b5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f63b7  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f63bb  e8c0bd0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f63c0  ebac                   -jmp 0x4f636e
    goto L_0x004f636e;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f63d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f63d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f63d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f63d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f63d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f63d4  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f63da  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f63dc  833d8044560000         +cmp dword ptr [0x564480], 0
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
    // 004f63e3  0f8487000000           -je 0x4f6470
    if (cpu.flags.zf)
    {
        goto L_0x004f6470;
    }
L_0x004f63e9:
    // 004f63e9  833d846e560000         +cmp dword ptr [0x566e84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f63f0  7565                   -jne 0x4f6457
    if (!cpu.flags.zf)
    {
        goto L_0x004f6457;
    }
    // 004f63f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f63f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f63f5  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f63fa  e8b1da0300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f63ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6401  7554                   -jne 0x4f6457
    if (!cpu.flags.zf)
    {
        goto L_0x004f6457;
    }
    // 004f6403  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6405  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f6407  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6409  e802f8ffff             -call 0x4f5c10
    cpu.esp -= 4;
    sub_4f5c10(app, cpu);
    if (cpu.terminate) return;
    // 004f640e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6410  743e                   -je 0x4f6450
    if (cpu.flags.zf)
    {
        goto L_0x004f6450;
    }
    // 004f6412  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f6417  891d846e5600           -mov dword ptr [0x566e84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */) = cpu.ebx;
    // 004f641d  e87efaffff             -call 0x4f5ea0
    cpu.esp -= 4;
    sub_4f5ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f6422  a1e46d5600             -mov eax, dword ptr [0x566de4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f6427  bf246e5600             -mov edi, 0x566e24
    cpu.edi = 5664292 /*0x566e24*/;
    // 004f642c  bde8895600             -mov ebp, 0x5689e8
    cpu.ebp = 5671400 /*0x5689e8*/;
    // 004f6431  893c85d0259f00         -mov dword ptr [eax*4 + 0x9f25d0], edi
    app->getMemory<x86::reg32>(x86::reg32(10429904) /* 0x9f25d0 */ + cpu.eax * 4) = cpu.edi;
    // 004f6438  892c85b0259f00         -mov dword ptr [eax*4 + 0x9f25b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(10429872) /* 0x9f25b0 */ + cpu.eax * 4) = cpu.ebp;
    // 004f643f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f6441  a3e46d5600             -mov dword ptr [0x566de4], eax
    app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */) = cpu.eax;
    // 004f6446  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6448  7406                   -je 0x4f6450
    if (cpu.flags.zf)
    {
        goto L_0x004f6450;
    }
    // 004f644a  8935246e5600           -mov dword ptr [0x566e24], esi
    app->getMemory<x86::reg32>(x86::reg32(5664292) /* 0x566e24 */) = cpu.esi;
L_0x004f6450:
    // 004f6450  e849da0300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f6455  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6456  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f6457:
    // 004f6457  833d846e560000         +cmp dword ptr [0x566e84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f645e  741f                   -je 0x4f647f
    if (cpu.flags.zf)
    {
        goto L_0x004f647f;
    }
    // 004f6460  b8286e5600             -mov eax, 0x566e28
    cpu.eax = 5664296 /*0x566e28*/;
    // 004f6465  81c490010000           +add esp, 0x190
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f646b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6470:
    // 004f6470  e86b4effff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6475  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004f647a  e96affffff             -jmp 0x4f63e9
    goto L_0x004f63e9;
L_0x004f647f:
    // 004f647f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6481  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f6487  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6488  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6489  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f648a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f648b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f6490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6491  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6492  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6493  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6494  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6497  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6499  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f649b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f649d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f649f  e806da0300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f64a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f64a6  83f8ff                 +cmp eax, -1
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
    // 004f64a9  750f                   -jne 0x4f64ba
    if (!cpu.flags.zf)
    {
        goto L_0x004f64ba;
    }
    // 004f64ab  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x004f64b0:
    // 004f64b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f64b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f64b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f64ba:
    // 004f64ba  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f64bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f64c1  e846a2feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f64c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f64c8  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 004f64cb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f64d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f64d1  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004f64d6  e86fd90300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f64db  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f64dd  6689442406             -mov word ptr [esp + 6], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004f64e2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f64e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f64e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f64e8  e857d90300             -call 0x533e44
    cpu.esp -= 4;
    sub_533e44(app, cpu);
    if (cpu.terminate) return;
    // 004f64ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f64ef  74bf                   -je 0x4f64b0
    if (cpu.flags.zf)
    {
        goto L_0x004f64b0;
    }
    // 004f64f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f64f2  e8add90300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f64f7  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f64fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f64fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6502  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6504  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6505  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6514  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6517  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6519  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f651b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f651c  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 004f6521  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f6526  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6527  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f652b  e820d90300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f6530  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f6532  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6536  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6537  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f6539  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f653e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f6543  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6544  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004f6548  e809d90300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f654d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f654f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6553  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6554  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6559  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f655a  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004f655c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f655d  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004f6561  e8f0d80300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f6566  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6569  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f6570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6574  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6575  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f6577  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f657a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f657c  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f657e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f6580  83ff01                 +cmp edi, 1
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
    // 004f6583  0f856a000000           -jne 0x4f65f3
    if (!cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f6589  837948ff               +cmp dword ptr [ecx + 0x48], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f658d  7464                   -je 0x4f65f3
    if (cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f658f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f6591  3b4b38                 +cmp ecx, dword ptr [ebx + 0x38]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6594  745d                   -je 0x4f65f3
    if (cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f6596  8b9a10030000           -mov ebx, dword ptr [edx + 0x310]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */);
    // 004f659c  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004f65a3  43                     -inc ebx
    (cpu.ebx)++;
    // 004f65a4  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004f65a7  899a10030000           -mov dword ptr [edx + 0x310], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */) = cpu.ebx;
    // 004f65ad  898c3a14030000         -mov dword ptr [edx + edi + 0x314], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(788) /* 0x314 */ + cpu.edi * 1) = cpu.ecx;
    // 004f65b4  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f65b7  83fb40                 +cmp ebx, 0x40
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
    // 004f65ba  7242                   -jb 0x4f65fe
    if (cpu.flags.cf)
    {
        goto L_0x004f65fe;
    }
L_0x004f65bc:
    // 004f65bc  8bb80c020000           -mov edi, dword ptr [eax + 0x20c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(524) /* 0x20c */);
    // 004f65c2  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f65c5  731a                   -jae 0x4f65e1
    if (!cpu.flags.cf)
    {
        goto L_0x004f65e1;
    }
    // 004f65c7  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f65ce  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004f65d1  89900c020000           -mov dword ptr [eax + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 004f65d7  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f65da  89940110020000         -mov dword ptr [ecx + eax + 0x210], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(528) /* 0x210 */ + cpu.eax * 1) = cpu.edx;
L_0x004f65e1:
    // 004f65e1  66837d0600             +cmp word ptr [ebp + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f65e6  760b                   -jbe 0x4f65f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f65e8  8ba808010000           -mov ebp, dword ptr [eax + 0x108]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */);
    // 004f65ee  83fd40                 +cmp ebp, 0x40
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f65f1  721f                   -jb 0x4f6612
    if (cpu.flags.cf)
    {
        goto L_0x004f6612;
    }
L_0x004f65f3:
    // 004f65f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f65f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f65fe:
    // 004f65fe  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004f6605  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f6606  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f6609  8b4948                 -mov ecx, dword ptr [ecx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004f660c  894c3a08               -mov dword ptr [edx + edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.edi * 1) = cpu.ecx;
    // 004f6610  ebaa                   -jmp 0x4f65bc
    goto L_0x004f65bc;
L_0x004f6612:
    // 004f6612  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 004f6619  8d5501                 -lea edx, [ebp + 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004f661c  899008010000           -mov dword ptr [eax + 0x108], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */) = cpu.edx;
    // 004f6622  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6625  8994010c010000         -mov dword ptr [ecx + eax + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */ + cpu.eax * 1) = cpu.edx;
    // 004f662c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6631  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6632  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6633  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6634  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6635  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6636  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f6640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6642  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6643  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6644  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6645  81ec10040000           -sub esp, 0x410
    (cpu.esp) -= x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 004f664b  8984240c040000         -mov dword ptr [esp + 0x40c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */) = cpu.eax;
    // 004f6652  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f6654  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f6657  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f665d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f665e  8984240c040000         -mov dword ptr [esp + 0x40c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */) = cpu.eax;
    // 004f6665  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f666b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f666d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f666f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6673  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6675  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6676  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6679  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f667a  e8add70300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f667f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6681  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6683  7430                   -je 0x4f66b5
    if (cpu.flags.zf)
    {
        goto L_0x004f66b5;
    }
    // 004f6685  83f8ff                 +cmp eax, -1
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
    // 004f6688  741f                   -je 0x4f66a9
    if (cpu.flags.zf)
    {
        goto L_0x004f66a9;
    }
L_0x004f668a:
    // 004f668a  83fb02                 +cmp ebx, 2
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
    // 004f668d  7d2d                   -jge 0x4f66bc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f66bc;
    }
L_0x004f668f:
    // 004f668f  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6694  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6695  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f669b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f669d  81c410040000           -add esp, 0x410
    (cpu.esp) += x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 004f66a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f66a9:
    // 004f66a9  e88ad70300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f66ae  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f66b3  74d5                   -je 0x4f668a
    if (cpu.flags.zf)
    {
        goto L_0x004f668a;
    }
L_0x004f66b5:
    // 004f66b5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f66ba  ebd3                   -jmp 0x4f668f
    goto L_0x004f668f;
L_0x004f66bc:
    // 004f66bc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f66c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f66c3  8b9c2408040000         -mov ebx, dword ptr [esp + 0x408]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004f66ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f66cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f66ce  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f66d0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f66d2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f66d9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f66db  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f66df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f66e1  39d0                   +cmp eax, edx
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
    // 004f66e3  7e07                   -jle 0x4f66ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f66ec;
    }
    // 004f66e5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f66ea  eba3                   -jmp 0x4f668f
    goto L_0x004f668f;
L_0x004f66ec:
    // 004f66ec  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f66ee  8d5802                 -lea ebx, [eax + 2]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004f66f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f66f2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f66f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f66f7  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f66fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f66fb  e82cd70300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f6700  89842404040000         -mov dword ptr [esp + 0x404], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.eax;
    // 004f6707  39d8                   +cmp eax, ebx
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
    // 004f6709  756a                   -jne 0x4f6775
    if (!cpu.flags.zf)
    {
        goto L_0x004f6775;
    }
    // 004f670b  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6712  7c18                   -jl 0x4f672c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f672c;
    }
    // 004f6714  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6716  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f671b  b8c8d25400             -mov eax, 0x54d2c8
    cpu.eax = 5558984 /*0x54d2c8*/;
    // 004f6720  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6722  8d5e34                 -lea ebx, [esi + 0x34]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f6725  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6727  e854ba0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f672c:
    // 004f672c  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004f6733  83784000               +cmp dword ptr [eax + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6737  7410                   -je 0x4f6749
    if (cpu.flags.zf)
    {
        goto L_0x004f6749;
    }
    // 004f6739  8b9c240c040000         -mov ebx, dword ptr [esp + 0x40c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004f6740  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f6743  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004f6746  ff5340                 -call dword ptr [ebx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f6749:
    // 004f6749  8d542402               -lea edx, [esp + 2]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004f674d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f674f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6751  e89abf0100             -call 0x5126f0
    cpu.esp -= 4;
    sub_5126f0(app, cpu);
    if (cpu.terminate) return;
    // 004f6756  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6758  741b                   -je 0x4f6775
    if (cpu.flags.zf)
    {
        goto L_0x004f6775;
    }
    // 004f675a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f675c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f675f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6760  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6764  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6765  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6768  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6769  e8bed60300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f676e  89842404040000         -mov dword ptr [esp + 0x404], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.eax;
L_0x004f6775:
    // 004f6775  8bb42404040000         -mov esi, dword ptr [esp + 0x404]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 004f677c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f677e  7419                   -je 0x4f6799
    if (cpu.flags.zf)
    {
        goto L_0x004f6799;
    }
    // 004f6780  83feff                 +cmp esi, -1
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
    // 004f6783  0f8506ffffff           -jne 0x4f668f
    if (!cpu.flags.zf)
    {
        goto L_0x004f668f;
    }
    // 004f6789  e8aad60300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f678e  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6793  0f84f6feffff           -je 0x4f668f
    if (cpu.flags.zf)
    {
        goto L_0x004f668f;
    }
L_0x004f6799:
    // 004f6799  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f679e  e9ecfeffff             -jmp 0x4f668f
    goto L_0x004f668f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f67b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f67b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f67b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f67b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f67b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f67b4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f67b6  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f67b9  668b5306               -mov dx, word ptr [ebx + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f67bd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f67bf  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f67c2  7707                   -ja 0x4f67cb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f67cb;
    }
    // 004f67c4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f67c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f67cb:
    // 004f67cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f67cc  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f67d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f67d3  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f67d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f67db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f67dc  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f67e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f67e1  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f67e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f67e5  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f67e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f67e9  e838d60300             -call 0x533e26
    cpu.esp -= 4;
    sub_533e26(app, cpu);
    if (cpu.terminate) return;
    // 004f67ee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f67f0  83f8ff                 +cmp eax, -1
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
    // 004f67f3  7532                   -jne 0x4f6827
    if (!cpu.flags.zf)
    {
        goto L_0x004f6827;
    }
    // 004f67f5  e83ed60300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f67fa  3d47270000             +cmp eax, 0x2747
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10055 /*0x2747*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f67ff  7412                   -je 0x4f6813
    if (cpu.flags.zf)
    {
        goto L_0x004f6813;
    }
    // 004f6801  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6806  740b                   -je 0x4f6813
    if (cpu.flags.zf)
    {
        goto L_0x004f6813;
    }
    // 004f6808  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f680d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
L_0x004f6813:
    // 004f6813  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6818  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6819  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f681f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6820  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6822  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6823  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6824  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6825  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6826  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6827:
    // 004f6827  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6829  7ee8                   -jle 0x4f6813
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f6813;
    }
    // 004f682b  668b4b06               -mov cx, word ptr [ebx + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f682f  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f6832  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6834  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f6836  66894b06               -mov word ptr [ebx + 6], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 004f683a  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004f683d  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6842  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6843  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f684c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6850  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f6860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6860  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6865  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6873  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6875  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6878  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6879  e826d60300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f687e  c74348ffffffff         -mov dword ptr [ebx + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f6885  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f688a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f688c  e8bf780100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f6891  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6893  7504                   -jne 0x4f6899
    if (!cpu.flags.zf)
    {
        goto L_0x004f6899;
    }
    // 004f6895  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6896  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6897  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6899:
    // 004f6899  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f68a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f68a2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f68a4  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f68a7  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f68ac  e89f750100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f68b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f68c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f68c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f68c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f68c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f68c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f68c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f68c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f68c6  81ec30040000           -sub esp, 0x430
    (cpu.esp) -= x86::reg32(x86::sreg32(1072 /*0x430*/));
    // 004f68cc  a1f0379f00             -mov eax, dword ptr [0x9f37f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434544) /* 0x9f37f0 */);
    // 004f68d1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f68d4  c6404701               -mov byte ptr [eax + 0x47], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(71) /* 0x47 */) = 1 /*0x1*/;
    // 004f68d8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68db  80784600               +cmp byte ptr [eax + 0x46], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f68df  0f85b2020000           -jne 0x4f6b97
    if (!cpu.flags.zf)
    {
        goto L_0x004f6b97;
    }
L_0x004f68e5:
    // 004f68e5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68e8  8b503c                 -mov edx, dword ptr [eax + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f68eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f68ed  0f84b8020000           -je 0x4f6bab
    if (cpu.flags.zf)
    {
        goto L_0x004f6bab;
    }
    // 004f68f3  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
L_0x004f68f6:
    // 004f68f6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68f9  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f68fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f68fe  83f9ff                 +cmp ecx, -1
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
    // 004f6901  7431                   -je 0x4f6934
    if (cpu.flags.zf)
    {
        goto L_0x004f6934;
    }
    // 004f6903  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6905  0f84a7020000           -je 0x4f6bb2
    if (cpu.flags.zf)
    {
        goto L_0x004f6bb2;
    }
    // 004f690b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f690e  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f6911  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f6914  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6916  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6918  0f8594020000           -jne 0x4f6bb2
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bb2;
    }
L_0x004f691e:
    // 004f691e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6921  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6924  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6925  e87ad50300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f692a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f692d  c7401cffffffff         -mov dword ptr [eax + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
L_0x004f6934:
    // 004f6934  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6936  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6939  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004f693d  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 004f6944  89bc240c020000         -mov dword ptr [esp + 0x20c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edi;
    // 004f694b  89bc2410030000         -mov dword ptr [esp + 0x310], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.edi;
    // 004f6952  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6956  0f856c020000           -jne 0x4f6bc8
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bc8;
    }
    // 004f695c  c744240401000000       -mov dword ptr [esp + 4], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004f6964  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6967  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004f696b:
    // 004f696b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f696e  8b7038                 -mov esi, dword ptr [eax + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f6971  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6973  744b                   -je 0x4f69c0
    if (cpu.flags.zf)
    {
        goto L_0x004f69c0;
    }
    // 004f6975  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f697c  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f697f  7314                   -jae 0x4f6995
    if (!cpu.flags.cf)
    {
        goto L_0x004f6995;
    }
    // 004f6981  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004f6984  89ac2408010000         -mov dword ptr [esp + 0x108], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebp;
    // 004f698b  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f698e  8984bc0c010000         -mov dword ptr [esp + edi*4 + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */ + cpu.edi * 4) = cpu.eax;
L_0x004f6995:
    // 004f6995  83bc240c02000040       +cmp dword ptr [esp + 0x20c], 0x40
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f699d  7321                   -jae 0x4f69c0
    if (!cpu.flags.cf)
    {
        goto L_0x004f69c0;
    }
    // 004f699f  8b94240c020000         -mov edx, dword ptr [esp + 0x20c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f69a6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f69a9  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004f69ac  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f69af  898c240c020000         -mov dword ptr [esp + 0x20c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.ecx;
    // 004f69b6  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f69b9  89849410020000         -mov dword ptr [esp + edx*4 + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.edx * 4) = cpu.eax;
L_0x004f69c0:
    // 004f69c0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f69c2  ba70654f00             -mov edx, 0x4f6570
    cpu.edx = 5203312 /*0x4f6570*/;
    // 004f69c7  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f69cc  e8df7f0100             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 004f69d1  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f69d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f69d8  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f69de  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f69e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f69e5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f69eb  8d842424040000         -lea eax, [esp + 0x424]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1060) /* 0x424 */);
    // 004f69f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f69f3  8d842410020000         -lea eax, [esp + 0x210]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 004f69fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f69fb  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004f6a02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a03  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a08  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6a0a  bda8610000             -mov ebp, 0x61a8
    cpu.ebp = 25000 /*0x61a8*/;
    // 004f6a0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6a10  89bc2438040000         -mov dword ptr [esp + 0x438], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1080) /* 0x438 */) = cpu.edi;
    // 004f6a17  89ac243c040000         -mov dword ptr [esp + 0x43c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1084) /* 0x43c */) = cpu.ebp;
    // 004f6a1e  e8fdd30300             -call 0x533e20
    cpu.esp -= 4;
    sub_533e20(app, cpu);
    if (cpu.terminate) return;
    // 004f6a23  83f8ff                 +cmp eax, -1
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
    // 004f6a26  0f845e010000           -je 0x4f6b8a
    if (cpu.flags.zf)
    {
        goto L_0x004f6b8a;
    }
    // 004f6a2c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6a30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a31  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6a35  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6a38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6a39  e8dcd30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6a3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6a40  7440                   -je 0x4f6a82
    if (cpu.flags.zf)
    {
        goto L_0x004f6a82;
    }
    // 004f6a42  8d84242c040000         -lea eax, [esp + 0x42c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1068) /* 0x42c */);
    // 004f6a49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a4a  8d842418040000         -lea eax, [esp + 0x418]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 004f6a51  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004f6a56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a57  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6a5b  898c2434040000         -mov dword ptr [esp + 0x434], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1076) /* 0x434 */) = cpu.ecx;
    // 004f6a62  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6a65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6a66  e8a9d30300             -call 0x533e14
    cpu.esp -= 4;
    sub_533e14(app, cpu);
    if (cpu.terminate) return;
    // 004f6a6b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a6e  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f6a71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a74  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6a78  0f8559010000           -jne 0x4f6bd7
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bd7;
    }
    // 004f6a7e  c6404601               -mov byte ptr [eax + 0x46], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */) = 1 /*0x1*/;
L_0x004f6a82:
    // 004f6a82  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a85  8b6d38                 -mov ebp, dword ptr [ebp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 004f6a88  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f6a8a  742a                   -je 0x4f6ab6
    if (cpu.flags.zf)
    {
        goto L_0x004f6ab6;
    }
    // 004f6a8c  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f6a93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a94  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f6a97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a98  e87dd30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6a9f  0f8478010000           -je 0x4f6c1d
    if (cpu.flags.zf)
    {
        goto L_0x004f6c1d;
    }
    // 004f6aa5  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6aac:
    // 004f6aac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6aaf  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
L_0x004f6ab6:
    // 004f6ab6  8b842410030000         -mov eax, dword ptr [esp + 0x310]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004f6abd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6abf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ac1  0f8ec3000000           -jle 0x4f6b8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f6b8a;
    }
    // 004f6ac7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f6ac9:
    // 004f6ac9  8b841c14030000         -mov eax, dword ptr [esp + ebx + 0x314]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6ad0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f6ad2  837848ff               +cmp dword ptr [eax + 0x48], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ad6  0f8485000000           -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6adc  39e8                   +cmp eax, ebp
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
    // 004f6ade  0f847d000000           -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6ae4  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6ae8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6ae9  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6aec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6aed  e828d30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6af4  7411                   -je 0x4f6b07
    if (cpu.flags.zf)
    {
        goto L_0x004f6b07;
    }
    // 004f6af6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6af9  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b00  e83bfbffff             -call 0x4f6640
    cpu.esp -= 4;
    sub_4f6640(app, cpu);
    if (cpu.terminate) return;
    // 004f6b05  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f6b07:
    // 004f6b07  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f6b0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b0f  8b841c18030000         -mov eax, dword ptr [esp + ebx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */ + cpu.ebx * 1);
    // 004f6b16  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6b19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b1a  e8fbd20300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6b1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6b21  7411                   -je 0x4f6b34
    if (cpu.flags.zf)
    {
        goto L_0x004f6b34;
    }
    // 004f6b23  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b26  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b2d  e87efcffff             -call 0x4f67b0
    cpu.esp -= 4;
    sub_4f67b0(app, cpu);
    if (cpu.terminate) return;
    // 004f6b32  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f6b34:
    // 004f6b34  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f6b3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b3c  8b841c18030000         -mov eax, dword ptr [esp + ebx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */ + cpu.ebx * 1);
    // 004f6b43  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6b46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b47  e8ced20300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6b4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6b4e  7411                   -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6b50  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b53  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b5a  e801fdffff             -call 0x4f6860
    cpu.esp -= 4;
    sub_4f6860(app, cpu);
    if (cpu.terminate) return;
    // 004f6b5f  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f6b61:
    // 004f6b61  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6b63  7412                   -je 0x4f6b77
    if (cpu.flags.zf)
    {
        goto L_0x004f6b77;
    }
    // 004f6b65  8bb41c14030000         -mov esi, dword ptr [esp + ebx + 0x314]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6b6e  7407                   -je 0x4f6b77
    if (cpu.flags.zf)
    {
        goto L_0x004f6b77;
    }
    // 004f6b70  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6b72  e8f9fcffff             -call 0x4f6870
    cpu.esp -= 4;
    sub_4f6870(app, cpu);
    if (cpu.terminate) return;
L_0x004f6b77:
    // 004f6b77  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004f6b7e  47                     -inc edi
    (cpu.edi)++;
    // 004f6b7f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6b82  39d7                   +cmp edi, edx
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
    // 004f6b84  0f8c3fffffff           -jl 0x4f6ac9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6ac9;
    }
L_0x004f6b8a:
    // 004f6b8a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b8d  80784600               +cmp byte ptr [eax + 0x46], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f6b91  0f844efdffff           -je 0x4f68e5
    if (cpu.flags.zf)
    {
        goto L_0x004f68e5;
    }
L_0x004f6b97:
    // 004f6b97  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b9a  c6404700               -mov byte ptr [eax + 0x47], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(71) /* 0x47 */) = 0 /*0x0*/;
    // 004f6b9e  81c430040000           -add esp, 0x430
    (cpu.esp) += x86::reg32(x86::sreg32(1072 /*0x430*/));
    // 004f6ba4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6baa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6bab:
    // 004f6bab  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6bad  e944fdffff             -jmp 0x4f68f6
    goto L_0x004f68f6;
L_0x004f6bb2:
    // 004f6bb2  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f6bb7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6bba  3b4234                 +cmp eax, dword ptr [edx + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6bbd  0f8f5bfdffff           -jg 0x4f691e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f691e;
    }
    // 004f6bc3  e96cfdffff             -jmp 0x4f6934
    goto L_0x004f6934;
L_0x004f6bc8:
    // 004f6bc8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6bcd  e80e8dfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6bd2  e994fdffff             -jmp 0x4f696b
    goto L_0x004f696b;
L_0x004f6bd7:
    // 004f6bd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6bd9  6689942414040000       -mov word ptr [esp + 0x414], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(1044) /* 0x414 */) = cpu.dx;
    // 004f6be1  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f6be4  8b9c242c040000         -mov ebx, dword ptr [esp + 0x42c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1068) /* 0x42c */);
    // 004f6beb  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004f6bf2  e8f938ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f6bf7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6bfa  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6bfd  e80ef9ffff             -call 0x4f6510
    cpu.esp -= 4;
    sub_4f6510(app, cpu);
    if (cpu.terminate) return;
    // 004f6c02  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f6c07  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6c0d  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f6c10  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6c13  01d8                   +add eax, ebx
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
    // 004f6c15  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004f6c18  e965feffff             -jmp 0x4f6a82
    goto L_0x004f6a82;
L_0x004f6c1d:
    // 004f6c1d  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f6c24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6c25  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f6c28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6c29  e8ecd10300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6c2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6c30  0f8480feffff           -je 0x4f6ab6
    if (cpu.flags.zf)
    {
        goto L_0x004f6ab6;
    }
    // 004f6c36  c7452401000000         -mov dword ptr [ebp + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004f6c3d  e96afeffff             -jmp 0x4f6aac
    goto L_0x004f6aac;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f6c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6c50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6c51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6c52  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6c55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6c57  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6c59  8d430e                 -lea eax, [ebx + 0xe]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004f6c5c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6c5e  0f84af010000           -je 0x4f6e13
    if (cpu.flags.zf)
    {
        goto L_0x004f6e13;
    }
    // 004f6c64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6c65  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f6c68  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f6c6a  0f84cc000000           -je 0x4f6d3c
    if (cpu.flags.zf)
    {
        goto L_0x004f6d3c;
    }
    // 004f6c70  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004f6c74:
    // 004f6c74  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6c78  0f85fa000000           -jne 0x4f6d78
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d78;
    }
    // 004f6c7e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f6c83:
    // 004f6c83  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6c87  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f6c89  668b15e8379f00         -mov dx, word ptr [0x9f37e8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10434536) /* 0x9f37e8 */);
    // 004f6c90  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f6c93  0f84e6000000           -je 0x4f6d7f
    if (cpu.flags.zf)
    {
        goto L_0x004f6d7f;
    }
    // 004f6c99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6c9b  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004f6c9e  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004f6ca1:
    // 004f6ca1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6ca5  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004f6cab  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f6cb2  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004f6cb6  8b454c                 -mov eax, dword ptr [ebp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 004f6cb9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f6cbc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f6cc0  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f6cc7  668b5d34               -mov bx, word ptr [ebp + 0x34]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6ccb  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004f6cce  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004f6cd1  0f85b2000000           -jne 0x4f6d89
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d89;
    }
    // 004f6cd7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f6cdc:
    // 004f6cdc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6cde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ce0  0f84b3000000           -je 0x4f6d99
    if (cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6ce6  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 004f6ceb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f6ced:
    // 004f6ced  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6cf1  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6cf5  0f859e000000           -jne 0x4f6d99
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6cfb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6cfd  e82e8cfeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6d02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d04  0f8486000000           -je 0x4f6d90
    if (cpu.flags.zf)
    {
        goto L_0x004f6d90;
    }
    // 004f6d0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6d0c  e81f09ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6d11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d13  0f8c80000000           -jl 0x4f6d99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6d99;
    }
L_0x004f6d19:
    // 004f6d19  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6d1b  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6d1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d20  0f8573000000           -jne 0x4f6d99
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6d26  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6d2c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f6d2e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6d30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f6d33  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f6d35  e8a68bfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6d3a  ebb1                   -jmp 0x4f6ced
    goto L_0x004f6ced;
L_0x004f6d3c:
    // 004f6d3c  b9d0d25400             -mov ecx, 0x54d2d0
    cpu.ecx = 5558992 /*0x54d2d0*/;
    // 004f6d41  bbdcd25400             -mov ebx, 0x54d2dc
    cpu.ebx = 5559004 /*0x54d2dc*/;
    // 004f6d46  bfac010000             -mov edi, 0x1ac
    cpu.edi = 428 /*0x1ac*/;
    // 004f6d4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f6d4d  b8f0d25400             -mov eax, 0x54d2f0
    cpu.eax = 5559024 /*0x54d2f0*/;
    // 004f6d52  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f6d58  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f6d5e  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f6d64  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f6d6a  e8b1a8feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f6d6f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f6d73  e9fcfeffff             -jmp 0x4f6c74
    goto L_0x004f6c74;
L_0x004f6d78:
    // 004f6d78  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6d7a  e904ffffff             -jmp 0x4f6c83
    goto L_0x004f6c83;
L_0x004f6d7f:
    // 004f6d7f  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
    // 004f6d84  e918ffffff             -jmp 0x4f6ca1
    goto L_0x004f6ca1;
L_0x004f6d89:
    // 004f6d89  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6d8b  e94cffffff             -jmp 0x4f6cdc
    goto L_0x004f6cdc;
L_0x004f6d90:
    // 004f6d90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6d92  e8498bfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6d97  eb80                   -jmp 0x4f6d19
    goto L_0x004f6d19;
L_0x004f6d99:
    // 004f6d99  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6d9d  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6da1  0f8484000000           -je 0x4f6e2b
    if (cpu.flags.zf)
    {
        goto L_0x004f6e2b;
    }
    // 004f6da7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6da9  746e                   -je 0x4f6e19
    if (cpu.flags.zf)
    {
        goto L_0x004f6e19;
    }
L_0x004f6dab:
    // 004f6dab  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6db0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6db1  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6db7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6dbb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6dbe  894548                 -mov dword ptr [ebp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004f6dc1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6dc5  8d7d34                 -lea edi, [ebp + 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6dc8  8d7620                 -lea esi, [esi + 0x20]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f6dcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dd0  c7452401000000         -mov dword ptr [ebp + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004f6dd7  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6ddd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6de1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6de2  c7401cffffffff         -mov dword ptr [eax + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 004f6de9  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f6def:
    // 004f6def  8b5524                 -mov edx, dword ptr [ebp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f6df2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f6df4  0f850a020000           -jne 0x4f7004
    if (!cpu.flags.zf)
    {
        goto L_0x004f7004;
    }
    // 004f6dfa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6dfe  833800                 +cmp dword ptr [eax], 0
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
    // 004f6e01  0f84fd010000           -je 0x4f7004
    if (cpu.flags.zf)
    {
        goto L_0x004f7004;
    }
    // 004f6e07  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004f6e0a  e881aafeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f6e0f:
    // 004f6e0f  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f6e12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f6e13:
    // 004f6e13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6e16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6e18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6e19:
    // 004f6e19  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f6e1c  8d5534                 -lea edx, [ebp + 0x34]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6e1f  8b454c                 -mov eax, dword ptr [ebp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 004f6e22  e819e2ffff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 004f6e27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e29  7580                   -jne 0x4f6dab
    if (!cpu.flags.zf)
    {
        goto L_0x004f6dab;
    }
L_0x004f6e2b:
    // 004f6e2b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6e2d  75c0                   -jne 0x4f6def
    if (!cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e2f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e33  896838                 -mov dword ptr [eax + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 004f6e36  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f6e38  74b5                   -je 0x4f6def
    if (cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e3a  8d4534                 -lea eax, [ebp + 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6e3d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004f6e41:
    // 004f6e41  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6e43  75aa                   -jne 0x4f6def
    if (!cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6e47  e8e48afeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6e4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e4e  7534                   -jne 0x4f6e84
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e84;
    }
    // 004f6e50  e88b8afeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f6e55:
    // 004f6e55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6e57  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6e5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e5c  7433                   -je 0x4f6e91
    if (cpu.flags.zf)
    {
        goto L_0x004f6e91;
    }
L_0x004f6e5e:
    // 004f6e5e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e62  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6e67  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6e6e  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6e75:
    // 004f6e75  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e79  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6e7d  75c2                   -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6e7f  e96bffffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f6e84:
    // 004f6e84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6e86  e8a507ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6e8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e8d  7ccf                   -jl 0x4f6e5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6e5e;
    }
    // 004f6e8f  ebc4                   -jmp 0x4f6e55
    goto L_0x004f6e55;
L_0x004f6e91:
    // 004f6e91  e8faf5ffff             -call 0x4f6490
    cpu.esp -= 4;
    sub_4f6490(app, cpu);
    if (cpu.terminate) return;
    // 004f6e96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6e98  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f6e9c  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6ea3  8db8e8030000           -lea edi, [eax + 0x3e8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1000) /* 0x3e8 */);
    // 004f6ea9  83fbff                 +cmp ebx, -1
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
    // 004f6eac  0f843a010000           -je 0x4f6fec
    if (cpu.flags.zf)
    {
        goto L_0x004f6fec;
    }
    // 004f6eb2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6eb4  e857f6ffff             -call 0x4f6510
    cpu.esp -= 4;
    sub_4f6510(app, cpu);
    if (cpu.terminate) return;
    // 004f6eb9  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f6ebb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6ebf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6ec1  e848cf0300             -call 0x533e0e
    cpu.esp -= 4;
    sub_533e0e(app, cpu);
    if (cpu.terminate) return;
    // 004f6ec6  e86dcf0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f6ecb  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ed0  0f859f000000           -jne 0x4f6f75
    if (!cpu.flags.zf)
    {
        goto L_0x004f6f75;
    }
    // 004f6ed6  895d48                 -mov dword ptr [ebp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 004f6ed9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6edd  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ee1  744b                   -je 0x4f6f2e
    if (cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
L_0x004f6ee3:
    // 004f6ee3  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6eea  39c7                   +cmp edi, eax
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
    // 004f6eec  7640                   -jbe 0x4f6f2e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6eee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6ef0  e83b8afeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6ef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ef7  745c                   -je 0x4f6f55
    if (cpu.flags.zf)
    {
        goto L_0x004f6f55;
    }
    // 004f6ef9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6efb  e83007ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f02  7c09                   -jl 0x4f6f0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6f0d;
    }
L_0x004f6f04:
    // 004f6f04  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6f06  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6f09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f0b  744f                   -je 0x4f6f5c
    if (cpu.flags.zf)
    {
        goto L_0x004f6f5c;
    }
L_0x004f6f0d:
    // 004f6f0d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f11  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6f16  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6f1d  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6f24:
    // 004f6f24  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f28  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f2c  75b5                   -jne 0x4f6ee3
    if (!cpu.flags.zf)
    {
        goto L_0x004f6ee3;
    }
L_0x004f6f2e:
    // 004f6f2e  837d2400               +cmp dword ptr [ebp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f32  0f853dffffff           -jne 0x4f6e75
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e75;
    }
    // 004f6f38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6f3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6f3d  e862cf0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f6f42  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f46  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f4a  0f85f1feffff           -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6f50  e99afeffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f6f55:
    // 004f6f55  e88689feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6f5a  eba8                   -jmp 0x4f6f04
    goto L_0x004f6f04;
L_0x004f6f5c:
    // 004f6f5c  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004f6f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f6f63  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6f69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f6f6c  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f6f6e  e86d89feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6f73  ebaf                   -jmp 0x4f6f24
    goto L_0x004f6f24;
L_0x004f6f75:
    // 004f6f75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f77  74b5                   -je 0x4f6f2e
    if (cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6f79  3d42270000             +cmp eax, 0x2742
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10050 /*0x2742*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f7e  7329                   -jae 0x4f6fa9
    if (!cpu.flags.cf)
    {
        goto L_0x004f6fa9;
    }
    // 004f6f80  3d3f270000             +cmp eax, 0x273f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10047 /*0x273f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f85  7309                   -jae 0x4f6f90
    if (!cpu.flags.cf)
    {
        goto L_0x004f6f90;
    }
    // 004f6f87  3d1e270000             +cmp eax, 0x271e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10014 /*0x271e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f8c  72a0                   -jb 0x4f6f2e
    if (cpu.flags.cf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6f8e  7750                   -ja 0x4f6fe0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f6fe0;
    }
L_0x004f6f90:
    // 004f6f90  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f94  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6f99  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6fa0  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f6fa7  eb85                   -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fa9:
    // 004f6fa9  76e5                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fab  3d4d270000             +cmp eax, 0x274d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10061 /*0x274d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fb0  7313                   -jae 0x4f6fc5
    if (!cpu.flags.cf)
    {
        goto L_0x004f6fc5;
    }
    // 004f6fb2  3d43270000             +cmp eax, 0x2743
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10051 /*0x2743*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fb7  76d7                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fb9  3d48270000             +cmp eax, 0x2748
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10056 /*0x2748*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fbe  74d0                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fc0  e969ffffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fc5:
    // 004f6fc5  76c9                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fc7  3d50270000             +cmp eax, 0x2750
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10064 /*0x2750*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fcc  0f825cffffff           -jb 0x4f6f2e
    if (cpu.flags.cf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6fd2  76bc                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fd4  3d51270000             +cmp eax, 0x2751
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10065 /*0x2751*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fd9  74b5                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fdb  e94effffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fe0:
    // 004f6fe0  3d26270000             +cmp eax, 0x2726
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10022 /*0x2726*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fe5  74a9                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fe7  e942ffffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fec:
    // 004f6fec  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6ff1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6ff5  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ff9  0f8542feffff           -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6fff  e9ebfdffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f7004:
    // 004f7004  837d2400               +cmp dword ptr [ebp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7008  0f8401feffff           -je 0x4f6e0f
    if (cpu.flags.zf)
    {
        goto L_0x004f6e0f;
    }
    // 004f700e  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f7013  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f7015  e8366e0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f701a  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f701d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f701e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f7021  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f7030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7034  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f7037  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f703b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f703d  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f7040  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f7042  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7044  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7048  39c3                   +cmp ebx, eax
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
    // 004f704a  7711                   -ja 0x4f705d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f705d;
    }
L_0x004f704c:
    // 004f704c  66837e0600             +cmp word ptr [esi + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f7051  7641                   -jbe 0x4f7094
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7094;
    }
    // 004f7053  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7055  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f7058  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7059  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f705d:
    // 004f705d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f705f  bad0d25400             -mov edx, 0x54d2d0
    cpu.edx = 5558992 /*0x54d2d0*/;
    // 004f7064  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7068  b9f8d25400             -mov ecx, 0x54d2f8
    cpu.ecx = 5559032 /*0x54d2f8*/;
    // 004f706d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f706e  bb2e020000             -mov ebx, 0x22e
    cpu.ebx = 558 /*0x22e*/;
    // 004f7073  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f7079  680cd35400             -push 0x54d30c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559052 /*0x54d30c*/;
    cpu.esp -= 4;
    // 004f707e  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f7084  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f708a  e8819ff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f708f  83c408                 +add esp, 8
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
    // 004f7092  ebb8                   -jmp 0x4f704c
    goto L_0x004f704c;
L_0x004f7094:
    // 004f7094  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f7099  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f709a  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f70a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f70a2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f70a4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f70a6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004f70a9  8d560e                 -lea edx, [esi + 0xe]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004f70ac  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004f70b0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f70b4  e83734ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f70b9  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f70bc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f70bf  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f70c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f70c4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f70c6  6689f8                 -mov ax, di
    cpu.ax = cpu.di;
    // 004f70c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f70ca  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f70cd  66897e06               -mov word ptr [esi + 6], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 004f70d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f70d2  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f70d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f70d6  e84bcd0300             -call 0x533e26
    cpu.esp -= 4;
    sub_533e26(app, cpu);
    if (cpu.terminate) return;
    // 004f70db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f70dd  83f8ff                 +cmp eax, -1
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
    // 004f70e0  755d                   -jne 0x4f713f
    if (!cpu.flags.zf)
    {
        goto L_0x004f713f;
    }
    // 004f70e2  e851cd0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f70e7  8b3de06d5600           -mov edi, dword ptr [0x566de0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f70ed  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f70f0  83ff04                 +cmp edi, 4
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
    // 004f70f3  7c1a                   -jl 0x4f710f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f710f;
    }
    // 004f70f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f70f7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f70fc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f7100  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7102  b844d35400             -mov eax, 0x54d344
    cpu.eax = 5559108 /*0x54d344*/;
    // 004f7107  8d5d48                 -lea ebx, [ebp + 0x48]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f710a  e871b00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f710f:
    // 004f710f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7112  81fd47270000           +cmp ebp, 0x2747
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10055 /*0x2747*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7118  7408                   -je 0x4f7122
    if (cpu.flags.zf)
    {
        goto L_0x004f7122;
    }
    // 004f711a  81fd33270000           +cmp ebp, 0x2733
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7120  7556                   -jne 0x4f7178
    if (!cpu.flags.zf)
    {
        goto L_0x004f7178;
    }
L_0x004f7122:
    // 004f7122  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f7128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7129  66c746060000           -mov word ptr [esi + 6], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004f712f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7135  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7137  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f713a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f713f:
    // 004f713f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7141  7e35                   -jle 0x4f7178
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f7178;
    }
    // 004f7143  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004f7147  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f714a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f714c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f714e  66895e06               -mov word ptr [esi + 6], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.bx;
    // 004f7152  8b1de06d5600           -mov ebx, dword ptr [0x566de0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f7158  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f715b  83fb04                 +cmp ebx, 4
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
    // 004f715e  7c18                   -jl 0x4f7178
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f7178;
    }
    // 004f7160  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7162  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f7167  8d5d34                 -lea ebx, [ebp + 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f716a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f716c  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f716e  b850d35400             -mov eax, 0x54d350
    cpu.eax = 5559120 /*0x54d350*/;
    // 004f7173  e808b00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f7178:
    // 004f7178  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f717e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f717f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7185  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f718a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f718d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f718e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f718f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7190  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7191  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f71a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f71a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f71a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f71a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f71a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f71a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f71a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f71a9  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f71ae  e89d6f0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f71b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f71b5  743a                   -je 0x4f71f1
    if (cpu.flags.zf)
    {
        goto L_0x004f71f1;
    }
    // 004f71b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f71b8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f71ba  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004f71bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f71be  e845cc0300             -call 0x533e08
    cpu.esp -= 4;
    sub_533e08(app, cpu);
    if (cpu.terminate) return;
    // 004f71c3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f71c8  e81387feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f71cd  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004f71d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f71d1  e8cecc0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f71d6  c74348ffffffff         -mov dword ptr [ebx + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f71dd  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f71e4  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f71e9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f71eb  e8606c0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f71f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f71f1:
    // 004f71f1  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f71f6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f71f8  e8536f0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f71fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f71ff  7419                   -je 0x4f721a
    if (cpu.flags.zf)
    {
        goto L_0x004f721a;
    }
    // 004f7201  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f7204  833800                 +cmp dword ptr [eax], 0
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
    // 004f7207  740c                   -je 0x4f7215
    if (cpu.flags.zf)
    {
        goto L_0x004f7215;
    }
    // 004f7209  e882a6feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f720e  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004f7215:
    // 004f7215  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f721a:
    // 004f721a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7224  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7226  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7228  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f722a  3b10                   +cmp edx, dword ptr [eax]
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
    // 004f722c  7534                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f722e  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f7232  663b5604               +cmp dx, word ptr [esi + 4]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f7236  752a                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f7238  668b5f06               -mov bx, word ptr [edi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004f723c  663b5e06               +cmp bx, word ptr [esi + 6]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f7240  7520                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f7242  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f7244  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f7247  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7249  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f724c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f724e  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7250  7510                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
L_0x004f7252:
    // 004f7252  40                     -inc eax
    (cpu.eax)++;
    // 004f7253  42                     -inc edx
    (cpu.edx)++;
    // 004f7254  41                     -inc ecx
    (cpu.ecx)++;
    // 004f7255  83fa08                 +cmp edx, 8
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
    // 004f7258  7d0f                   -jge 0x4f7269
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7269;
    }
    // 004f725a  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f725d  3a5908                 +cmp bl, byte ptr [ecx + 8]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7260  74f0                   -je 0x4f7252
    if (cpu.flags.zf)
    {
        goto L_0x004f7252;
    }
L_0x004f7262:
    // 004f7262  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7264  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7265  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7266  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7267  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7268  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7269:
    // 004f7269  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f726e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f726f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7270  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7271  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7272  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7282  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7283  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7285  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7287  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f7289  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f728c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f728f  e88cffffff             -call 0x4f7220
    cpu.esp -= 4;
    sub_4f7220(app, cpu);
    if (cpu.terminate) return;
    // 004f7294  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7296  7506                   -jne 0x4f729e
    if (!cpu.flags.zf)
    {
        goto L_0x004f729e;
    }
L_0x004f7298:
    // 004f7298  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7299  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f729a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f729b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f729e:
    // 004f729e  e88ddfffff             -call 0x4f5230
    cpu.esp -= 4;
    sub_4f5230(app, cpu);
    if (cpu.terminate) return;
    // 004f72a3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72a6  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72a9  a3446f5600             -mov dword ptr [0x566f44], eax
    app->getMemory<x86::reg32>(x86::reg32(5664580) /* 0x566f44 */) = cpu.eax;
    // 004f72ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f72b0  74e6                   -je 0x4f7298
    if (cpu.flags.zf)
    {
        goto L_0x004f7298;
    }
    // 004f72b2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f72b4  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f72b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f72bb  ff551c                 -call dword ptr [ebp + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72be  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f72c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f72c3  74d3                   -je 0x4f7298
    if (cpu.flags.zf)
    {
        goto L_0x004f7298;
    }
    // 004f72c5  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72c8  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004f72cb  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004f72d0  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72d3  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004f72d9  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 004f72e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f72e5  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f72ec  e8ff31ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f72f1  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 004f72f6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f72fa  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004f72fd  e82e9bfeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f7302  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004f7307  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f730b  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004f730e  e81d9bfeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f7313  a1446f5600             -mov eax, dword ptr [0x566f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664580) /* 0x566f44 */);
    // 004f7318  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7319  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f731a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f731b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7322  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f7324  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f7327  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f732c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f732e  7431                   -je 0x4f7361
    if (cpu.flags.zf)
    {
        goto L_0x004f7361;
    }
    // 004f7330  83baa000000000         +cmp dword ptr [edx + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7337  7407                   -je 0x4f7340
    if (cpu.flags.zf)
    {
        goto L_0x004f7340;
    }
    // 004f7339  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f733b  e850dcffff             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
L_0x004f7340:
    // 004f7340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7341  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7344  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7346  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7349  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004f7353  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7356  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f735d  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7360  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f7361:
    // 004f7361  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7363  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f7370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7370  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7372  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7380  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7382  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7384  7406                   -je 0x4f738c
    if (cpu.flags.zf)
    {
        goto L_0x004f738c;
    }
    // 004f7386  66c742280100           -mov word ptr [edx + 0x28], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
L_0x004f738c:
    // 004f738c  ba8c6e5600             -mov edx, 0x566e8c
    cpu.edx = 5664396 /*0x566e8c*/;
    // 004f7391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7392  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f7394  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7396  e895ddffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004f739b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f73a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f73a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f73a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f73a2  833d886e560000         +cmp dword ptr [0x566e88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f73a9  7452                   -je 0x4f73fd
    if (cpu.flags.zf)
    {
        goto L_0x004f73fd;
    }
L_0x004f73ab:
    // 004f73ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f73ad  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f73af  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f73b1  e8f4ca0300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f73b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f73b8  83f8ff                 +cmp eax, -1
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
    // 004f73bb  7410                   -je 0x4f73cd
    if (cpu.flags.zf)
    {
        goto L_0x004f73cd;
    }
    // 004f73bd  b820b1a000             -mov eax, 0xa0b120
    cpu.eax = 10531104 /*0xa0b120*/;
    // 004f73c2  e829dd0100             -call 0x5150f0
    cpu.esp -= 4;
    sub_5150f0(app, cpu);
    if (cpu.terminate) return;
    // 004f73c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f73c8  e8d7ca0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
L_0x004f73cd:
    // 004f73cd  8b0d886e5600           -mov ecx, dword ptr [0x566e88]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
    // 004f73d3  41                     -inc ecx
    (cpu.ecx)++;
    // 004f73d4  668b15e8379f00         -mov dx, word ptr [0x9f37e8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10434536) /* 0x9f37e8 */);
    // 004f73db  890d886e5600           -mov dword ptr [0x566e88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */) = cpu.ecx;
    // 004f73e1  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f73e4  740f                   -je 0x4f73f5
    if (cpu.flags.zf)
    {
        goto L_0x004f73f5;
    }
    // 004f73e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f73e8  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004f73eb  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f73ee  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f73f3  7e05                   -jle 0x4f73fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f73fa;
    }
L_0x004f73f5:
    // 004f73f5  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
L_0x004f73fa:
    // 004f73fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f73fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f73fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f73fd:
    // 004f73fd  6860369f00             -push 0x9f3660
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434144 /*0x9f3660*/;
    cpu.esp -= 4;
    // 004f7402  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f7407  e8a4ca0300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f740c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f740e  749b                   -je 0x4f73ab
    if (cpu.flags.zf)
    {
        goto L_0x004f73ab;
    }
    // 004f7410  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7412  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f7420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7421  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7422  8b15886e5600           -mov edx, dword ptr [0x566e88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
    // 004f7428  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f742a  741e                   -je 0x4f744a
    if (cpu.flags.zf)
    {
        goto L_0x004f744a;
    }
    // 004f742c  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004f742f  890d886e5600           -mov dword ptr [0x566e88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */) = cpu.ecx;
    // 004f7435  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7437  7408                   -je 0x4f7441
    if (cpu.flags.zf)
    {
        goto L_0x004f7441;
    }
L_0x004f7439:
    // 004f7439  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f743e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f743f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7440  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7441:
    // 004f7441  e858ca0300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f7446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7448  74ef                   -je 0x4f7439
    if (cpu.flags.zf)
    {
        goto L_0x004f7439;
    }
L_0x004f744a:
    // 004f744a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f744c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f744d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f744e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f7450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7451  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7452  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7453  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7454  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7457  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f745b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f745d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f745f  bad0d25400             -mov edx, 0x54d2d0
    cpu.edx = 5558992 /*0x54d2d0*/;
    // 004f7464  bb58d35400             -mov ebx, 0x54d358
    cpu.ebx = 5559128 /*0x54d358*/;
    // 004f7469  be1a030000             -mov esi, 0x31a
    cpu.esi = 794 /*0x31a*/;
    // 004f746e  b868d35400             -mov eax, 0x54d368
    cpu.eax = 5559144 /*0x54d368*/;
    // 004f7473  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f7479  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f747f  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 004f7484  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f748a  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f7490  e88ba1feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f7495  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 004f749a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f749c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f749e  e86992feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f74a3  c7431cffffffff         -mov dword ptr [ebx + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 004f74aa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f74ae  e8ddefffff             -call 0x4f6490
    cpu.esp -= 4;
    sub_4f6490(app, cpu);
    if (cpu.terminate) return;
    // 004f74b3  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f74b6  897b3c                 -mov dword ptr [ebx + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 004f74b9  894b40                 -mov dword ptr [ebx + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004f74bc  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f74c0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f74c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f74c4  0f8493000000           -je 0x4f755d
    if (cpu.flags.zf)
    {
        goto L_0x004f755d;
    }
    // 004f74ca  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
L_0x004f74cc:
    // 004f74cc  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f74d3  7c1a                   -jl 0x4f74ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f74ef;
    }
    // 004f74d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f74d7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f74dc  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f74e0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f74e2  b870d35400             -mov eax, 0x54d370
    cpu.eax = 5559152 /*0x54d370*/;
    // 004f74e7  8d5e18                 -lea ebx, [esi + 0x18]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f74ea  e891ac0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f74ef:
    // 004f74ef  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f74f2  83fbff                 +cmp ebx, -1
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
    // 004f74f5  0f849e000000           -je 0x4f7599
    if (cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f74fb  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004f74fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f74fe  e8ffc80300             -call 0x533e02
    cpu.esp -= 4;
    sub_533e02(app, cpu);
    if (cpu.terminate) return;
    // 004f7503  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7505  0f858e000000           -jne 0x4f7599
    if (!cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f750b  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f7510  8935f0379f00           -mov dword ptr [0x9f37f0], esi
    app->getMemory<x86::reg32>(x86::reg32(10434544) /* 0x9f37f0 */) = cpu.esi;
    // 004f7516  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7519  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f751e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f751f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f7521  b8c0684f00             -mov eax, 0x4f68c0
    cpu.eax = 5204160 /*0x4f68c0*/;
    // 004f7526  e87582feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f752b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f752d  746a                   -je 0x4f7599
    if (cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f752f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004f7534  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f7536:
    // 004f7536  8a6647                 -mov ah, byte ptr [esi + 0x47]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
    // 004f7539  38e2                   +cmp dl, ah
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f753b  7558                   -jne 0x4f7595
    if (!cpu.flags.zf)
    {
        goto L_0x004f7595;
    }
    // 004f753d  3a6646                 +cmp ah, byte ptr [esi + 0x46]
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(70) /* 0x46 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7540  7553                   -jne 0x4f7595
    if (!cpu.flags.zf)
    {
        goto L_0x004f7595;
    }
    // 004f7542  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7544  e8e783feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f7549  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f754b  743f                   -je 0x4f758c
    if (cpu.flags.zf)
    {
        goto L_0x004f758c;
    }
    // 004f754d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f754f  e8dc00ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x004f7554:
    // 004f7554  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f7556  e88583feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f755b  ebd9                   -jmp 0x4f7536
    goto L_0x004f7536;
L_0x004f755d:
    // 004f755d  c744241410000000       -mov dword ptr [esp + 0x14], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 16 /*0x10*/;
    // 004f7565  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7569  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f756a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f756e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f756f  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004f7572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7573  e8c6c80300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f7578  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f757a  0f854cffffff           -jne 0x4f74cc
    if (!cpu.flags.zf)
    {
        goto L_0x004f74cc;
    }
    // 004f7580  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004f7585  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f7587  e940ffffff             -jmp 0x4f74cc
    goto L_0x004f74cc;
L_0x004f758c:
    // 004f758c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f758e  e84d83feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f7593  ebbf                   -jmp 0x4f7554
    goto L_0x004f7554;
L_0x004f7595:
    // 004f7595  0fb66e47               -movzx ebp, byte ptr [esi + 0x47]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */));
L_0x004f7599:
    // 004f7599  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f759b  7526                   -jne 0x4f75c3
    if (!cpu.flags.zf)
    {
        goto L_0x004f75c3;
    }
    // 004f759d  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f75a4  7c14                   -jl 0x4f75ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f75ba;
    }
    // 004f75a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f75a8  b880d35400             -mov eax, 0x54d380
    cpu.eax = 5559168 /*0x54d380*/;
    // 004f75ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f75af  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f75b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f75b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f75b5  e8c6ab0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f75ba:
    // 004f75ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f75bc  e80f000000             -call 0x4f75d0
    cpu.esp -= 4;
    sub_4f75d0(app, cpu);
    if (cpu.terminate) return;
    // 004f75c1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f75c3:
    // 004f75c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f75c5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f75c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f75d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f75d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f75d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f75d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f75d3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f75d5  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f75dc  7d4b                   -jge 0x4f7629
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7629;
    }
L_0x004f75de:
    // 004f75de  807e4700               +cmp byte ptr [esi + 0x47], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f75e2  742d                   -je 0x4f7611
    if (cpu.flags.zf)
    {
        goto L_0x004f7611;
    }
    // 004f75e4  8a5647                 -mov dl, byte ptr [esi + 0x47]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
    // 004f75e7  c6464601               -mov byte ptr [esi + 0x46], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(70) /* 0x46 */) = 1 /*0x1*/;
    // 004f75eb  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004f75ed  7422                   -je 0x4f7611
    if (cpu.flags.zf)
    {
        goto L_0x004f7611;
    }
L_0x004f75ef:
    // 004f75ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f75f1  e83a83feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f75f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f75f8  7447                   -je 0x4f7641
    if (cpu.flags.zf)
    {
        goto L_0x004f7641;
    }
    // 004f75fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f75fc  e82f00ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x004f7601:
    // 004f7601  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7606  e8d582feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f760b  807e4700               +cmp byte ptr [esi + 0x47], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f760f  75de                   -jne 0x4f75ef
    if (!cpu.flags.zf)
    {
        goto L_0x004f75ef;
    }
L_0x004f7611:
    // 004f7611  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f7614  83f9ff                 +cmp ecx, -1
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
    // 004f7617  752f                   -jne 0x4f7648
    if (!cpu.flags.zf)
    {
        goto L_0x004f7648;
    }
    // 004f7619  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f761b  e870a2feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f7620  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7625  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7626  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7627  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7628  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7629:
    // 004f7629  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f762a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f762c  b890d35400             -mov eax, 0x54d390
    cpu.eax = 5559184 /*0x54d390*/;
    // 004f7631  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7633  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7635  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7637  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f7639  e842ab0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f763e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f763f  eb9d                   -jmp 0x4f75de
    goto L_0x004f75de;
L_0x004f7641:
    // 004f7641  e89a82feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f7646  ebb9                   -jmp 0x4f7601
    goto L_0x004f7601;
L_0x004f7648:
    // 004f7648  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7649  e856c80300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f764e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7650  e83ba2feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f7655  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f765a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7660  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f7662  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7673  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f7676  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f7679  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f767b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004f767f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f7681  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004f7686  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f768a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f768c  7509                   -jne 0x4f7697
    if (!cpu.flags.zf)
    {
        goto L_0x004f7697;
    }
L_0x004f768e:
    // 004f768e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7690  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f7693  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7694  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7695  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7696  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7697:
    // 004f7697  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7699  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f769b  49                     -dec ecx
    (cpu.ecx)--;
    // 004f769c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f769e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f76a0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f76a2  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f76a5  74e7                   -je 0x4f768e
    if (cpu.flags.zf)
    {
        goto L_0x004f768e;
    }
    // 004f76a7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f76a9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f76ab  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f76ae  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f76b0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f76b2  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76b3  807c31ff2e             +cmp byte ptr [ecx + esi - 1], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.esi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f76b8  74d4                   -je 0x4f768e
    if (cpu.flags.zf)
    {
        goto L_0x004f768e;
    }
    // 004f76ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f76bb  e83cc70300             -call 0x533dfc
    cpu.esp -= 4;
    sub_533dfc(app, cpu);
    if (cpu.terminate) return;
    // 004f76c0  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004f76c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f76c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f76c9  e83e90feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f76ce  66c7030200             -mov word ptr [ebx], 2
    app->getMemory<x86::reg16>(cpu.ebx) = 2 /*0x2*/;
    // 004f76d3  83f9ff                 +cmp ecx, -1
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
    // 004f76d6  755c                   -jne 0x4f7734
    if (!cpu.flags.zf)
    {
        goto L_0x004f7734;
    }
    // 004f76d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f76d9  e818c70300             -call 0x533df6
    cpu.esp -= 4;
    sub_533df6(app, cpu);
    if (cpu.terminate) return;
    // 004f76de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f76e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f76e2  744c                   -je 0x4f7730
    if (cpu.flags.zf)
    {
        goto L_0x004f7730;
    }
    // 004f76e4  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f76e7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004f76ea  83fb04                 +cmp ebx, 4
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
    // 004f76ed  733a                   -jae 0x4f7729
    if (!cpu.flags.cf)
    {
        goto L_0x004f7729;
    }
L_0x004f76ef:
    // 004f76ef  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f76f3  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f76f6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f76f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f76fb  e8f02dffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f7700:
    // 004f7700  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f7702  741c                   -je 0x4f7720
    if (cpu.flags.zf)
    {
        goto L_0x004f7720;
    }
    // 004f7704  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004f7709  742e                   -je 0x4f7739
    if (cpu.flags.zf)
    {
        goto L_0x004f7739;
    }
    // 004f770b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f770d  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004f7712:
    // 004f7712  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7713  e832c70300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f7718  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f771c  66894202               -mov word ptr [edx + 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.ax;
L_0x004f7720:
    // 004f7720  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f7722  83c40c                 +add esp, 0xc
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
    // 004f7725  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7726  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7727  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7728  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7729:
    // 004f7729  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f772e  ebbf                   -jmp 0x4f76ef
    goto L_0x004f76ef;
L_0x004f7730:
    // 004f7730  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004f7732  ebec                   -jmp 0x4f7720
    goto L_0x004f7720;
L_0x004f7734:
    // 004f7734  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f7737  ebc7                   -jmp 0x4f7700
    goto L_0x004f7700;
L_0x004f7739:
    // 004f7739  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f773c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f773e  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004f7741  ebcf                   -jmp 0x4f7712
    goto L_0x004f7712;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7753  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7756  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f7759  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004f775b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f775e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f775f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f7761  e88ac60300             -call 0x533df0
    cpu.esp -= 4;
    sub_533df0(app, cpu);
    if (cpu.terminate) return;
    // 004f7766  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7768  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f7769:
    // 004f7769  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f776b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f776d  3c00                   +cmp al, 0
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
    // 004f776f  7410                   -je 0x4f7781
    if (cpu.flags.zf)
    {
        goto L_0x004f7781;
    }
    // 004f7771  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f7774  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f7777  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f777a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f777d  3c00                   +cmp al, 0
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
    // 004f777f  75e8                   -jne 0x4f7769
    if (!cpu.flags.zf)
    {
        goto L_0x004f7769;
    }
L_0x004f7781:
    // 004f7781  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7782  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f7784  750c                   -jne 0x4f7792
    if (!cpu.flags.zf)
    {
        goto L_0x004f7792;
    }
    // 004f7786  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f778b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f778e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f778f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7791  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7792:
    // 004f7792  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7795  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7797  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004f779b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f779c  e849c60300             -call 0x533dea
    cpu.esp -= 4;
    sub_533dea(app, cpu);
    if (cpu.terminate) return;
    // 004f77a1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f77a6  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004f77a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f77ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f77b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f77c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f77c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f77c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f77c3  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004f77c8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f77ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f77cc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f77ce  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f77d0  7405                   -je 0x4f77d7
    if (cpu.flags.zf)
    {
        goto L_0x004f77d7;
    }
    // 004f77d2  19c0                   +sbb eax, eax
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
    // 004f77d4  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f77d7:
    // 004f77d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f77d9  7509                   -jne 0x4f77e4
    if (!cpu.flags.zf)
    {
        goto L_0x004f77e4;
    }
    // 004f77db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f77e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f77e4:
    // 004f77e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f77e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f77f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f77f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f77f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f77f5  c7042414000000         -mov dword ptr [esp], 0x14
    app->getMemory<x86::reg32>(cpu.esp) = 20 /*0x14*/;
    // 004f77fc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004f77fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7800  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f7803  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7804  e835c60300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f7809  83f8ff                 +cmp eax, -1
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
    // 004f780c  740b                   -je 0x4f7819
    if (cpu.flags.zf)
    {
        goto L_0x004f7819;
    }
    // 004f780e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7813  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7816  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7817  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7818  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7819:
    // 004f7819  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f781b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f781e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f781f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f7830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7833  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7834  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7836  833d8044560000         +cmp dword ptr [0x564480], 0
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
    // 004f783d  0f8499000000           -je 0x4f78dc
    if (cpu.flags.zf)
    {
        goto L_0x004f78dc;
    }
L_0x004f7843:
    // 004f7843  833d486f560000         +cmp dword ptr [0x566f48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f784a  0f8579000000           -jne 0x4f78c9
    if (!cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f7850  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004f7852  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7859  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004f785b  746c                   -je 0x4f78c9
    if (cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f785d  6860369f00             -push 0x9f3660
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434144 /*0x9f3660*/;
    cpu.esp -= 4;
    // 004f7862  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f7867  e844c60300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f786c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f786e  7559                   -jne 0x4f78c9
    if (!cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f7870  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7871  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7872  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7873  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7875  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f7877  e82ec60300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f787c  83f8ff                 +cmp eax, -1
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
    // 004f787f  7441                   -je 0x4f78c2
    if (cpu.flags.zf)
    {
        goto L_0x004f78c2;
    }
    // 004f7881  bee46e5600             -mov esi, 0x566ee4
    cpu.esi = 5664484 /*0x566ee4*/;
    // 004f7886  bfa06e5600             -mov edi, 0x566ea0
    cpu.edi = 5664416 /*0x566ea0*/;
    // 004f788b  8b15e46d5600           -mov edx, dword ptr [0x566de4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f7891  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7892  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004f7895  893495d0259f00         -mov dword ptr [edx*4 + 0x9f25d0], esi
    app->getMemory<x86::reg32>(x86::reg32(10429904) /* 0x9f25d0 */ + cpu.edx * 4) = cpu.esi;
    // 004f789c  893c95b0259f00         -mov dword ptr [edx*4 + 0x9f25b0], edi
    app->getMemory<x86::reg32>(x86::reg32(10429872) /* 0x9f25b0 */ + cpu.edx * 4) = cpu.edi;
    // 004f78a3  892de46d5600           -mov dword ptr [0x566de4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */) = cpu.ebp;
    // 004f78a9  e8f6c50300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f78ae  c705486f560001000000   -mov dword ptr [0x566f48], 1
    app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */) = 1 /*0x1*/;
    // 004f78b8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f78ba  7406                   -je 0x4f78c2
    if (cpu.flags.zf)
    {
        goto L_0x004f78c2;
    }
    // 004f78bc  891de46e5600           -mov dword ptr [0x566ee4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5664484) /* 0x566ee4 */) = cpu.ebx;
L_0x004f78c2:
    // 004f78c2  e8d7c50300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f78c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f78c9:
    // 004f78c9  833d486f560000         +cmp dword ptr [0x566f48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f78d0  7419                   -je 0x4f78eb
    if (cpu.flags.zf)
    {
        goto L_0x004f78eb;
    }
    // 004f78d2  b8e86e5600             -mov eax, 0x566ee8
    cpu.eax = 5664488 /*0x566ee8*/;
    // 004f78d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f78dc:
    // 004f78dc  e8ff39ffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f78e1  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004f78e6  e958ffffff             -jmp 0x4f7843
    goto L_0x004f7843;
L_0x004f78eb:
    // 004f78eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f78ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7905  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f7906  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004f7908  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004f790a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f790b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f790e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f7910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7912  7405                   -je 0x4f7919
    if (cpu.flags.zf)
    {
        goto L_0x004f7919;
    }
    // 004f7914  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7917  7607                   -jbe 0x4f7920
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7920;
    }
L_0x004f7919:
    // 004f7919  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f791b  e9be000000             -jmp 0x4f79de
    goto L_0x004f79de;
L_0x004f7920:
    // 004f7920  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004f7923  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004f7926  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7929  7305                   -jae 0x4f7930
    if (!cpu.flags.cf)
    {
        goto L_0x004f7930;
    }
    // 004f792b  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x004f7930:
    // 004f7930  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7936  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f7938  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f793a  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004f793d:
    // 004f793d  3b2d546f5600           +cmp ebp, dword ptr [0x566f54]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7943  760c                   -jbe 0x4f7951
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7951;
    }
    // 004f7945  8b0d506f5600           -mov ecx, dword ptr [0x566f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f794b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f794d  7510                   -jne 0x4f795f
    if (!cpu.flags.zf)
    {
        goto L_0x004f795f;
    }
    // 004f794f  eb02                   -jmp 0x4f7953
    goto L_0x004f7953;
L_0x004f7951:
    // 004f7951  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f7953:
    // 004f7953  890d546f5600           -mov dword ptr [0x566f54], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.ecx;
    // 004f7959  8b0d4c6f5600           -mov ecx, dword ptr [0x566f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
L_0x004f795f:
    // 004f795f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7961  743c                   -je 0x4f799f
    if (cpu.flags.zf)
    {
        goto L_0x004f799f;
    }
    // 004f7963  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004f7966  890d506f5600           -mov dword ptr [0x566f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.ecx;
    // 004f796c  39fe                   +cmp esi, edi
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
    // 004f796e  721c                   -jb 0x4f798c
    if (cpu.flags.cf)
    {
        goto L_0x004f798c;
    }
    // 004f7970  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 004f7975  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004f7977  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f797d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f797f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7981  e87ad90100             -call 0x515300
    cpu.esp -= 4;
    sub_515300(app, cpu);
    if (cpu.terminate) return;
    // 004f7986  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f7988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f798a  7542                   -jne 0x4f79ce
    if (!cpu.flags.zf)
    {
        goto L_0x004f79ce;
    }
L_0x004f798c:
    // 004f798c  3b35546f5600           +cmp esi, dword ptr [0x566f54]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7992  7606                   -jbe 0x4f799a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f799a;
    }
    // 004f7994  8935546f5600           -mov dword ptr [0x566f54], esi
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.esi;
L_0x004f799a:
    // 004f799a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f799d  ebc0                   -jmp 0x4f795f
    goto L_0x004f795f;
L_0x004f799f:
    // 004f799f  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f79a3  750b                   -jne 0x4f79b0
    if (!cpu.flags.zf)
    {
        goto L_0x004f79b0;
    }
    // 004f79a5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f79a7  e868dc0100             -call 0x515614
    cpu.esp -= 4;
    sub_515614(app, cpu);
    if (cpu.terminate) return;
    // 004f79ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79ae  7515                   -jne 0x4f79c5
    if (!cpu.flags.zf)
    {
        goto L_0x004f79c5;
    }
L_0x004f79b0:
    // 004f79b0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f79b2  e8c9dc0100             -call 0x515680
    cpu.esp -= 4;
    sub_515680(app, cpu);
    if (cpu.terminate) return;
    // 004f79b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79b9  7413                   -je 0x4f79ce
    if (cpu.flags.zf)
    {
        goto L_0x004f79ce;
    }
    // 004f79bb  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004f79bd  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 004f79c0  e978ffffff             -jmp 0x4f793d
    goto L_0x004f793d;
L_0x004f79c5:
    // 004f79c5  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 004f79c9  e96fffffff             -jmp 0x4f793d
    goto L_0x004f793d;
L_0x004f79ce:
    // 004f79ce  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004f79d0  882d40b1a000           -mov byte ptr [0xa0b140], ch
    app->getMemory<x86::reg8>(x86::reg32(10531136) /* 0xa0b140 */) = cpu.ch;
    // 004f79d6  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f79dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f79de:
    // 004f79de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f79e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e2  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e4  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f79f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f79f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f79f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f79f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f79f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f79f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f79f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79f8  0f84f3000000           -je 0x4f7af1
    if (cpu.flags.zf)
    {
        goto L_0x004f7af1;
    }
    // 004f79fe  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7a04  8b0d00389f00           -mov ecx, dword ptr [0x9f3800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */);
    // 004f7a0a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a0c  7440                   -je 0x4f7a4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a0e  39f1                   +cmp ecx, esi
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
    // 004f7a10  770c                   -ja 0x4f7a1e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a1e;
    }
    // 004f7a12  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a14  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a16  39f0                   +cmp eax, esi
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
    // 004f7a18  0f878d000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a1e:
    // 004f7a1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7a20  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f7a23  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a25  7410                   -je 0x4f7a37
    if (cpu.flags.zf)
    {
        goto L_0x004f7a37;
    }
    // 004f7a27  39f1                   +cmp ecx, esi
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
    // 004f7a29  770c                   -ja 0x4f7a37
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a37;
    }
    // 004f7a2b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a2d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a2f  39f0                   +cmp eax, esi
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
    // 004f7a31  0f8774000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a37:
    // 004f7a37  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7a3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a3c  7410                   -je 0x4f7a4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a3e  39f1                   +cmp ecx, esi
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
    // 004f7a40  770c                   -ja 0x4f7a4e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a42  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a44  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a46  39f0                   +cmp eax, esi
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
    // 004f7a48  0f875d000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a4e:
    // 004f7a4e  8b0d506f5600           -mov ecx, dword ptr [0x566f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f7a54  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a56  7434                   -je 0x4f7a8c
    if (cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a58  39f1                   +cmp ecx, esi
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
    // 004f7a5a  7708                   -ja 0x4f7a64
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a64;
    }
    // 004f7a5c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a5e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a60  39f0                   +cmp eax, esi
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
    // 004f7a62  7747                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a64:
    // 004f7a64  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7a66  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f7a69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a6b  740c                   -je 0x4f7a79
    if (cpu.flags.zf)
    {
        goto L_0x004f7a79;
    }
    // 004f7a6d  39f1                   +cmp ecx, esi
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
    // 004f7a6f  7708                   -ja 0x4f7a79
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a79;
    }
    // 004f7a71  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a73  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a75  39f0                   +cmp eax, esi
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
    // 004f7a77  7732                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a79:
    // 004f7a79  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7a7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a7e  740c                   -je 0x4f7a8c
    if (cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a80  39f1                   +cmp ecx, esi
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
    // 004f7a82  7708                   -ja 0x4f7a8c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a84  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a86  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a88  39f0                   +cmp eax, esi
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
    // 004f7a8a  771f                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a8c:
    // 004f7a8c  8b0d4c6f5600           -mov ecx, dword ptr [0x566f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 004f7a92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a94  7455                   -je 0x4f7aeb
    if (cpu.flags.zf)
    {
        goto L_0x004f7aeb;
    }
L_0x004f7a96:
    // 004f7a96  39f1                   +cmp ecx, esi
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
    // 004f7a98  7708                   -ja 0x4f7aa2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aa2;
    }
    // 004f7a9a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a9c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a9e  39f0                   +cmp eax, esi
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
    // 004f7aa0  7709                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7aa2:
    // 004f7aa2  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f7aa5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7aa7  75ed                   -jne 0x4f7a96
    if (!cpu.flags.zf)
    {
        goto L_0x004f7a96;
    }
    // 004f7aa9  eb40                   -jmp 0x4f7aeb
    goto L_0x004f7aeb;
L_0x004f7aab:
    // 004f7aab  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 004f7ab0  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004f7ab2  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f7ab8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f7aba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7abc  e8efd80100             -call 0x5153b0
    cpu.esp -= 4;
    sub_5153b0(app, cpu);
    if (cpu.terminate) return;
    // 004f7ac1  8b15506f5600           -mov edx, dword ptr [0x566f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f7ac7  890d00389f00           -mov dword ptr [0x9f3800], ecx
    app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */) = cpu.ecx;
    // 004f7acd  39d1                   +cmp ecx, edx
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
    // 004f7acf  7312                   -jae 0x4f7ae3
    if (!cpu.flags.cf)
    {
        goto L_0x004f7ae3;
    }
    // 004f7ad1  8b1d546f5600           -mov ebx, dword ptr [0x566f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */);
    // 004f7ad7  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004f7ada  39d8                   +cmp eax, ebx
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
    // 004f7adc  7605                   -jbe 0x4f7ae3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7ae3;
    }
    // 004f7ade  a3546f5600             -mov dword ptr [0x566f54], eax
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.eax;
L_0x004f7ae3:
    // 004f7ae3  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f7ae5  882540b1a000           -mov byte ptr [0xa0b140], ah
    app->getMemory<x86::reg8>(x86::reg32(10531136) /* 0xa0b140 */) = cpu.ah;
L_0x004f7aeb:
    // 004f7aeb  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f7af1:
    // 004f7af1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f7af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7af8  64ff3500000000         -push dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.efs);
    cpu.esp -= 4;
    // 004f7aff  8f00                   -pop dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.eax) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b01  c740042a7b4f00         -mov dword ptr [eax + 4], 0x4f7b2a
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 5208874 /*0x4f7b2a*/;
    // 004f7b08  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004f7b0b  c64010ff               -mov byte ptr [eax + 0x10], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 255 /*0xff*/;
    // 004f7b0f  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004f7b13  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 004f7b19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b1a  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004f7b1c  648f0500000000         -pop dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.efs) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b23  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 004f7b29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b2b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f7b2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7b2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7b31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b32  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b35  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b38  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004f7b3f  740d                   -je 0x4f7b4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7b4e;
    }
    // 004f7b41  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b43  c64512ff               -mov byte ptr [ebp + 0x12], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = 255 /*0xff*/;
    // 004f7b47  e877000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7b4c  eb3e                   -jmp 0x4f7b8c
    return sub_4f7b8c(app, cpu);
L_0x004f7b4e:
    // 004f7b4e  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f7b51  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b54  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f7b57  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b59  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b5c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7b5e  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b61  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b64  7426                   -je 0x4f7b8c
    if (cpu.flags.zf)
    {
        return sub_4f7b8c(app, cpu);
    }
    // 004f7b66  885d12                 -mov byte ptr [ebp + 0x12], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f7b69  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7b6c  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b71  7514                   -jne 0x4f7b87
    if (!cpu.flags.zf)
    {
        return sub_4f7b87(app, cpu);
    }
    // 004f7b73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b76  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b79  ff645f02               -jmp dword ptr [edi + ebx*2 + 2]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.edi + 2 + cpu.ebx * 2), cpu);
}

/* align: skip  */
void Application::sub_4f7b61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b61;
    // 004f7b2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b2b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f7b2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7b2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7b31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b32  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b35  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b38  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004f7b3f  740d                   -je 0x4f7b4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7b4e;
    }
    // 004f7b41  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b43  c64512ff               -mov byte ptr [ebp + 0x12], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = 255 /*0xff*/;
    // 004f7b47  e877000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7b4c  eb3e                   -jmp 0x4f7b8c
    return sub_4f7b8c(app, cpu);
L_0x004f7b4e:
    // 004f7b4e  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f7b51  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b54  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f7b57  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b59  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b5c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7b5e  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_entry_0x004f7b61:
    // 004f7b61  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b64  7426                   -je 0x4f7b8c
    if (cpu.flags.zf)
    {
        return sub_4f7b8c(app, cpu);
    }
    // 004f7b66  885d12                 -mov byte ptr [ebp + 0x12], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f7b69  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7b6c  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b71  7514                   -jne 0x4f7b87
    if (!cpu.flags.zf)
    {
        return sub_4f7b87(app, cpu);
    }
    // 004f7b73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b76  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b79  ff645f02               -jmp dword ptr [edi + ebx*2 + 2]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.edi + 2 + cpu.ebx * 2), cpu);
}

/* align: skip  */
void Application::sub_4f7b7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b8c;
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
L_entry_0x004f7b8c:
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b87;
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
L_entry_0x004f7b87:
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7ba7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7ba7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7ba8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7ba9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7baa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7bab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7bac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7baf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7bb1  68bc7b4f00             -push 0x4f7bbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5209020 /*0x4f7bbc*/;
    cpu.esp -= 4;
    // 004f7bb6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bb7  e828c20300             -call 0x533de4
    cpu.esp -= 4;
    sub_533de4(app, cpu);
    if (cpu.terminate) return;
    // 004f7bbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7bc3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7bc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7bc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7bc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7bc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7bc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bc9  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7bcc  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7bce  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7bd1  c6451101               -mov byte ptr [ebp + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
L_0x004f7bd5:
    // 004f7bd5  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7bd8  7424                   -je 0x4f7bfe
    if (cpu.flags.zf)
    {
        goto L_0x004f7bfe;
    }
    // 004f7bda  3a5d12                 +cmp bl, byte ptr [ebp + 0x12]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7bdd  741f                   -je 0x4f7bfe
    if (cpu.flags.zf)
    {
        goto L_0x004f7bfe;
    }
    // 004f7bdf  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7be2  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7be7  740d                   -je 0x4f7bf6
    if (cpu.flags.zf)
    {
        goto L_0x004f7bf6;
    }
    // 004f7be9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7beb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bec  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7bef  ff545f02               -call dword ptr [edi + ebx*2 + 2]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */ + cpu.ebx * 2);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7bf3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f7bf6:
    // 004f7bf6  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7bf9  885d10                 -mov byte ptr [ebp + 0x10], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.bl;
    // 004f7bfc  ebd7                   -jmp 0x4f7bd5
    goto L_0x004f7bd5;
L_0x004f7bfe:
    // 004f7bfe  c6451100               -mov byte ptr [ebp + 0x11], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004f7c02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7c09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c09  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7c0a  648b2d00000000         -mov ebp, dword ptr fs:[0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.efs);
    // 004f7c11  884512                 -mov byte ptr [ebp + 0x12], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 004f7c14  e8aaffffff             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7c19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7c21  8b1590389f00           -mov edx, dword ptr [0x9f3890]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */);
    // 004f7c27  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7c2a  7d12                   -jge 0x4f7c3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7c3e;
    }
    // 004f7c2c  42                     -inc edx
    (cpu.edx)++;
    // 004f7c2d  8904950c389f00         -mov dword ptr [edx*4 + 0x9f380c], eax
    app->getMemory<x86::reg32>(x86::reg32(10434572) /* 0x9f380c */ + cpu.edx * 4) = cpu.eax;
    // 004f7c34  891590389f00           -mov dword ptr [0x9f3890], edx
    app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */) = cpu.edx;
    // 004f7c3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7c3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7c3e:
    // 004f7c3e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f7c43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f7c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7c49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7c4a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f7c4b  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004f7c4d  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004f7c4f  8b1d90389f00           -mov ebx, dword ptr [0x9f3890]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */);
    // 004f7c55  83fb21                 +cmp ebx, 0x21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7c58  7425                   -je 0x4f7c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f7c7f;
    }
    // 004f7c5a  c70590389f0021000000   -mov dword ptr [0x9f3890], 0x21
    app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */) = 33 /*0x21*/;
    // 004f7c64  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f7c66  7417                   -je 0x4f7c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f7c7f;
    }
    // 004f7c68  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
L_0x004f7c6f:
    // 004f7c6f  8b820c389f00           -mov eax, dword ptr [edx + 0x9f380c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10434572) /* 0x9f380c */);
    // 004f7c75  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7c78  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f7c79  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7c7b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7c7d  75f0                   -jne 0x4f7c6f
    if (!cpu.flags.zf)
    {
        goto L_0x004f7c6f;
    }
L_0x004f7c7f:
    // 004f7c7f  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c81  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c83  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7c91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7c92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7c93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7c94  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7c97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7c99  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7c9b  8a25c0445600           -mov ah, byte ptr [0x5644c0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5653696) /* 0x5644c0 */);
    // 004f7ca1  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004f7ca4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004f7ca6  7426                   -je 0x4f7cce
    if (cpu.flags.zf)
    {
        goto L_0x004f7cce;
    }
    // 004f7ca8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7caa  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004f7cad  9b                     -wait 
    /*nothing*/;
    // 004f7cae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7cb0  741c                   -je 0x4f7cce
    if (cpu.flags.zf)
    {
        goto L_0x004f7cce;
    }
    // 004f7cb2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7cb4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7cb7  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004f7cb9  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7cbb  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004f7cbd  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f7cbf  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7cc1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f7cc4  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004f7cc7  9b                     -wait 
    /*nothing*/;
    // 004f7cc8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7cca  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004f7ccd  9b                     -wait 
    /*nothing*/;
L_0x004f7cce:
    // 004f7cce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7cd0  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004f7cd4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7cd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f7ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7ce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7ce3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7ce6  833de077560000         +cmp dword ptr [0x5677e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7ced  7410                   -je 0x4f7cff
    if (cpu.flags.zf)
    {
        goto L_0x004f7cff;
    }
    // 004f7cef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f7cf1  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cf7  ff15e0775600           -call dword ptr [0x5677e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cfd  eb60                   -jmp 0x4f7d5f
    goto L_0x004f7d5f;
L_0x004f7cff:
    // 004f7cff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d01  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d07  e81cda0100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7d0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004f7d0e:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004f7d0e  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d13  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d15  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d1b  2eff15a0455300         -call dword ptr cs:[0x5345a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457312) /* 0x5345a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d22  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7d27  7421                   -je 0x4f7d4a
    if (cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7d2b  e860d90100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d32  7516                   -jne 0x4f7d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d34  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d39  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d3b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d41  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d48  ebc4                   -jmp 0x4f7d0e
    goto L_0x004f7d0e;
L_0x004f7d4a:
    // 004f7d4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d4c  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d52  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7d57  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7d5a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004f7d5f:
    // 004f7d5f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7d62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d72  0f85e8a90000           -jne 0x502760
    if (!cpu.flags.zf)
    {
        return sub_502760(app, cpu);
    }
    // 004f7d78  e8d3da0100             -call 0x515850
    cpu.esp -= 4;
    sub_515850(app, cpu);
    if (cpu.terminate) return;
    // 004f7d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7d82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7d83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7d84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7d85  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7d87  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f7d89  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f7d8c  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d92  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7d95  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004f7d99  7507                   -jne 0x4f7da2
    if (!cpu.flags.zf)
    {
        goto L_0x004f7da2;
    }
    // 004f7d9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7d9d  e81eac0000             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f7da2:
    // 004f7da2  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7da5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f7da7  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004f7daa  7415                   -je 0x4f7dc1
    if (cpu.flags.zf)
    {
        goto L_0x004f7dc1;
    }
    // 004f7dac  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004f7dae  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7db1  88510d                 -mov byte ptr [ecx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 004f7db4  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004f7db6  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004f7db9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f7dbe  88710d                 -mov byte ptr [ecx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x004f7dc1:
    // 004f7dc1  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f7dc3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f7dc5:
    // 004f7dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7dc7  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004f7dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7dcb  740f                   -je 0x4f7ddc
    if (cpu.flags.zf)
    {
        goto L_0x004f7ddc;
    }
    // 004f7dcd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7dcf  43                     -inc ebx
    (cpu.ebx)++;
    // 004f7dd0  e8db190100             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 004f7dd5  83f8ff                 +cmp eax, -1
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
    // 004f7dd8  75eb                   -jne 0x4f7dc5
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dc5;
    }
    // 004f7dda  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7ddc:
    // 004f7ddc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7dde  741d                   -je 0x4f7dfd
    if (cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7de0  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7de3  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7de5  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004f7de8  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004f7dea  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004f7ded  88610d                 -mov byte ptr [ecx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004f7df0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7df2  7509                   -jne 0x4f7dfd
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7df4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7df6  e865a90000             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 004f7dfb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7dfd:
    // 004f7dfd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7dff  7504                   -jne 0x4f7e05
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e05;
    }
    // 004f7e01  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004f7e03  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004f7e05:
    // 004f7e05  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004f7e08  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7e0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7e10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7e22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7e23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7e25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7e26  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7e29  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
    // 004f7e2f  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7e35  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7e37  a168715600             -mov eax, dword ptr [0x567168]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */);
    // 004f7e3c  83f801                 +cmp eax, 1
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
    // 004f7e3f  7244                   -jb 0x4f7e85
    if (cpu.flags.cf)
    {
        goto L_0x004f7e85;
    }
    // 004f7e41  7607                   -jbe 0x4f7e4a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7e4a;
    }
    // 004f7e43  83f802                 +cmp eax, 2
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
    // 004f7e46  7424                   -je 0x4f7e6c
    if (cpu.flags.zf)
    {
        goto L_0x004f7e6c;
    }
    // 004f7e48  eb3b                   -jmp 0x4f7e85
    goto L_0x004f7e85;
L_0x004f7e4a:
    // 004f7e4a  4e                     -dec esi
    (cpu.esi)--;
    // 004f7e4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7e4d  740c                   -je 0x4f7e5b
    if (cpu.flags.zf)
    {
        goto L_0x004f7e5b;
    }
    // 004f7e4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e51  7512                   -jne 0x4f7e65
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e65;
    }
    // 004f7e53  893568715600           -mov dword ptr [0x567168], esi
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.esi;
    // 004f7e59  eb0a                   -jmp 0x4f7e65
    goto L_0x004f7e65;
L_0x004f7e5b:
    // 004f7e5b  c7056871560002000000   -mov dword ptr [0x567168], 2
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 2 /*0x2*/;
L_0x004f7e65:
    // 004f7e65  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7e67  e9a2000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e6c:
    // 004f7e6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e6e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7e71  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004f7e76  a368715600             -mov dword ptr [0x567168], eax
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.eax;
    // 004f7e7b  a1b0389f00             -mov eax, dword ptr [0x9f38b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */);
    // 004f7e80  e989000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e85:
    // 004f7e85  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7e8b  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
L_0x004f7e91:
    // 004f7e91  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7e95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7e98  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7e9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e9d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e9e  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7ea5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7ea7  7454                   -je 0x4f7efd
    if (cpu.flags.zf)
    {
        goto L_0x004f7efd;
    }
    // 004f7ea9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7eab  e8e0d70100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7eb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7eb2  74dd                   -je 0x4f7e91
    if (cpu.flags.zf)
    {
        goto L_0x004f7e91;
    }
    // 004f7eb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7eb6  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7ebb  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f7ebe  8a642411               -mov ah, byte ptr [esp + 0x11]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 004f7ec2  0fb67c240e             -movzx edi, byte ptr [esp + 0xe]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */));
    // 004f7ec7  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004f7eca  7504                   -jne 0x4f7ed0
    if (!cpu.flags.zf)
    {
        goto L_0x004f7ed0;
    }
    // 004f7ecc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7ece  751b                   -jne 0x4f7eeb
    if (!cpu.flags.zf)
    {
        goto L_0x004f7eeb;
    }
L_0x004f7ed0:
    // 004f7ed0  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004f7ed5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7ed7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f7ed9  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f7ede  892d68715600           -mov dword ptr [0x567168], ebp
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.ebp;
    // 004f7ee4  a3b0389f00             -mov dword ptr [0x9f38b0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */) = cpu.eax;
    // 004f7ee9  eb0e                   -jmp 0x4f7ef9
    goto L_0x004f7ef9;
L_0x004f7eeb:
    // 004f7eeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7eed  740a                   -je 0x4f7ef9
    if (cpu.flags.zf)
    {
        goto L_0x004f7ef9;
    }
    // 004f7eef  c7056871560001000000   -mov dword ptr [0x567168], 1
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 1 /*0x1*/;
L_0x004f7ef9:
    // 004f7ef9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7efb  eb11                   -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7efd:
    // 004f7efd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f7f02  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7f08  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
L_0x004f7f0e:
    // 004f7f0e  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
    // 004f7f14  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7f1a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7f1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7f24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7f27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7f28  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f2b  a128785600             -mov eax, dword ptr [0x567828]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */);
    // 004f7f30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7f32  740a                   -je 0x4f7f3e
    if (cpu.flags.zf)
    {
        goto L_0x004f7f3e;
    }
    // 004f7f34  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f7f36  893528785600           -mov dword ptr [0x567828], esi
    app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */) = cpu.esi;
    // 004f7f3c  eb5a                   -jmp 0x4f7f98
    goto L_0x004f7f98;
L_0x004f7f3e:
    // 004f7f3e  833de477560000         +cmp dword ptr [0x5677e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7f45  7410                   -je 0x4f7f57
    if (cpu.flags.zf)
    {
        goto L_0x004f7f57;
    }
    // 004f7f47  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f4d  ff15e4775600           -call dword ptr [0x5677e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f55  eb3f                   -jmp 0x4f7f96
    goto L_0x004f7f96;
L_0x004f7f57:
    // 004f7f57  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f5d  e8c6d70100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7f62  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7f64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7f66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7f67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f68  2eff15fc445300         -call dword ptr cs:[0x5344fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457148) /* 0x5344fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f6f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7f71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f72  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f79  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f7f7b  e8a0feffff             -call 0x4f7e20
    cpu.esp -= 4;
    sub_4f7e20(app, cpu);
    if (cpu.terminate) return;
    // 004f7f80  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7f83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f87  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7f90  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f7f96:
    // 004f7f96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004f7f98:
    // 004f7f98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7fa0  e9fbd80100             -jmp 0x5158a0
    return sub_5158a0(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e000000000000000000000000 */
void Application::sub_4f8020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8021  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8022  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f8024  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f8026:
    // 004f8026  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f8028  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f802a  740d                   -je 0x4f8039
    if (cpu.flags.zf)
    {
        goto L_0x004f8039;
    }
    // 004f802c  2c61                   -sub al, 0x61
    (cpu.al) -= x86::reg8(x86::sreg8(97 /*0x61*/));
    // 004f802e  3c19                   +cmp al, 0x19
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8030  7704                   -ja 0x4f8036
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f8036;
    }
    // 004f8032  0441                   +add al, 0x41
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8034  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x004f8036:
    // 004f8036  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8037  ebed                   -jmp 0x4f8026
    goto L_0x004f8026;
L_0x004f8039:
    // 004f8039  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f803b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f803c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f803d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f8040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8044  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8046  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f8048  e8dfdb0100             -call 0x515c2c
    cpu.esp -= 4;
    sub_515c2c(app, cpu);
    if (cpu.terminate) return;
    // 004f804d  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004f8052  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 004f8058  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004f805a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f805c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f805e  e83ddf0100             -call 0x515fa0
    cpu.esp -= 4;
    sub_515fa0(app, cpu);
    if (cpu.terminate) return;
    // 004f8063  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8065  e806e20100             -call 0x516270
    cpu.esp -= 4;
    sub_516270(app, cpu);
    if (cpu.terminate) return;
    // 004f806a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f806c  741c                   -je 0x4f808a
    if (cpu.flags.zf)
    {
        goto L_0x004f808a;
    }
    // 004f806e  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004f8073  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 004f8079  8b159c8b5600           -mov edx, dword ptr [0x568b9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 004f807f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f8081  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f8083  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f8085  e816df0100             -call 0x515fa0
    cpu.esp -= 4;
    sub_515fa0(app, cpu);
    if (cpu.terminate) return;
L_0x004f808a:
    // 004f808a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f808c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8090  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8094(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8094  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8095  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8096  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f8098  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f809e  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f80a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f80a3  e898ffffff             -call 0x4f8040
    cpu.esp -= 4;
    sub_4f8040(app, cpu);
    if (cpu.terminate) return;
    // 004f80a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f80ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f80ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80ad  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80af  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80b2  eb31                   -jmp 0x4f80e5
    return sub_4f80e5(app, cpu);
}

/* align: skip  */
void Application::sub_4f80b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f80e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f80e5;
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
L_entry_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f80b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f80b6;
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
L_entry_0x004f80b6:
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f8116(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8116  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004f811a  e895ffffff             -call 0x4f80b4
    cpu.esp -= 4;
    sub_4f80b4(app, cpu);
    if (cpu.terminate) return;
    // 004f811f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4f8122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8123  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f8125  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8126  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8127  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8128  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f812b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f812d  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004f8130  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004f8133:
    // 004f8133  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f8135  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8138  740a                   -je 0x4f8144
    if (cpu.flags.zf)
    {
        goto L_0x004f8144;
    }
    // 004f813a  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f813d  7208                   -jb 0x4f8147
    if (cpu.flags.cf)
    {
        goto L_0x004f8147;
    }
    // 004f813f  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8142  7703                   -ja 0x4f8147
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f8147;
    }
L_0x004f8144:
    // 004f8144  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8145  ebec                   -jmp 0x4f8133
    goto L_0x004f8133;
L_0x004f8147:
    // 004f8147  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f814a  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004f814c  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f814f  7407                   -je 0x4f8158
    if (cpu.flags.zf)
    {
        goto L_0x004f8158;
    }
    // 004f8151  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8154  7504                   -jne 0x4f815a
    if (!cpu.flags.zf)
    {
        goto L_0x004f815a;
    }
    // 004f8156  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004f8158:
    // 004f8158  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004f815a:
    // 004f815a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f815c  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 004f815e  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x004f8161:
    // 004f8161  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f8163  40                     -inc eax
    (cpu.eax)++;
    // 004f8164  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8167  750a                   -jne 0x4f8173
    if (!cpu.flags.zf)
    {
        goto L_0x004f8173;
    }
    // 004f8169  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004f816c  752d                   -jne 0x4f819b
    if (!cpu.flags.zf)
    {
        goto L_0x004f819b;
    }
    // 004f816e  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004f8171  ebee                   -jmp 0x4f8161
    goto L_0x004f8161;
L_0x004f8173:
    // 004f8173  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8176  7223                   -jb 0x4f819b
    if (cpu.flags.cf)
    {
        goto L_0x004f819b;
    }
    // 004f8178  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f817b  771e                   -ja 0x4f819b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f819b;
    }
    // 004f817d  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004f8180  7403                   -je 0x4f8185
    if (cpu.flags.zf)
    {
        goto L_0x004f8185;
    }
    // 004f8182  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x004f8185:
    // 004f8185  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004f8187  80fe30                 +cmp dh, 0x30
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f818a  740a                   -je 0x4f8196
    if (cpu.flags.zf)
    {
        goto L_0x004f8196;
    }
    // 004f818c  83fb13                 +cmp ebx, 0x13
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
    // 004f818f  7d04                   -jge 0x4f8195
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8195;
    }
    // 004f8191  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x004f8195:
    // 004f8195  43                     -inc ebx
    (cpu.ebx)++;
L_0x004f8196:
    // 004f8196  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004f8199  ebc6                   -jmp 0x4f8161
    goto L_0x004f8161;
L_0x004f819b:
    // 004f819b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f819d  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004f81a0  0f8465000000           -je 0x4f820b
    if (cpu.flags.zf)
    {
        goto L_0x004f820b;
    }
    // 004f81a6  80fa65                 +cmp dl, 0x65
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81a9  7405                   -je 0x4f81b0
    if (cpu.flags.zf)
    {
        goto L_0x004f81b0;
    }
    // 004f81ab  80fa45                 +cmp dl, 0x45
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81ae  7557                   -jne 0x4f8207
    if (!cpu.flags.zf)
    {
        goto L_0x004f8207;
    }
L_0x004f81b0:
    // 004f81b0  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f81b3  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004f81b5  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004f81b8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f81bb  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81be  7408                   -je 0x4f81c8
    if (cpu.flags.zf)
    {
        goto L_0x004f81c8;
    }
    // 004f81c0  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81c3  7505                   -jne 0x4f81ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f81ca;
    }
    // 004f81c5  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004f81c8:
    // 004f81c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f81ca:
    // 004f81ca  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x004f81cd:
    // 004f81cd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f81cf  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81d2  7222                   -jb 0x4f81f6
    if (cpu.flags.cf)
    {
        goto L_0x004f81f6;
    }
    // 004f81d4  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81d7  771d                   -ja 0x4f81f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f81f6;
    }
    // 004f81d9  81fee8030000           +cmp esi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f81df  7d0f                   -jge 0x4f81f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f81f0;
    }
    // 004f81e1  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004f81e4  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 004f81e7  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 004f81ea  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004f81ed  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x004f81f0:
    // 004f81f0  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004f81f3  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f81f4  ebd7                   -jmp 0x4f81cd
    goto L_0x004f81cd;
L_0x004f81f6:
    // 004f81f6  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004f81f9  7402                   -je 0x4f81fd
    if (cpu.flags.zf)
    {
        goto L_0x004f81fd;
    }
    // 004f81fb  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x004f81fd:
    // 004f81fd  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004f8200  7506                   -jne 0x4f8208
    if (!cpu.flags.zf)
    {
        goto L_0x004f8208;
    }
    // 004f8202  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004f8205  eb01                   -jmp 0x4f8208
    goto L_0x004f8208;
L_0x004f8207:
    // 004f8207  48                     -dec eax
    (cpu.eax)--;
L_0x004f8208:
    // 004f8208  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004f820b:
    // 004f820b  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f820f  7408                   -je 0x4f8219
    if (cpu.flags.zf)
    {
        goto L_0x004f8219;
    }
    // 004f8211  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8214  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004f8217  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004f8219:
    // 004f8219  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004f821c  83fb13                 +cmp ebx, 0x13
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
    // 004f821f  7e0a                   -jle 0x4f822b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f822b;
    }
    // 004f8221  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 004f8224  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8226  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x004f822b:
    // 004f822b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f822d  7e0b                   -jle 0x4f823a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f823a;
    }
    // 004f822f  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8234  7504                   -jne 0x4f823a
    if (!cpu.flags.zf)
    {
        goto L_0x004f823a;
    }
    // 004f8236  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8237  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f8238  ebf1                   -jmp 0x4f822b
    goto L_0x004f822b;
L_0x004f823a:
    // 004f823a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f823c  7511                   -jne 0x4f824f
    if (!cpu.flags.zf)
    {
        goto L_0x004f824f;
    }
    // 004f823e  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f8244  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f8247  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8249  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004f824b  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f824d  eb5f                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f824f:
    // 004f824f  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004f8251  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004f8254  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 004f8258  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f825b  e878e30100             -call 0x5165d8
    cpu.esp -= 4;
    sub_5165d8(app, cpu);
    if (cpu.terminate) return;
    // 004f8260  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8262  740a                   -je 0x4f826e
    if (cpu.flags.zf)
    {
        goto L_0x004f826e;
    }
    // 004f8264  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8267  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8269  e8ebe40100             -call 0x516759
    cpu.esp -= 4;
    sub_516759(app, cpu);
    if (cpu.terminate) return;
L_0x004f826e:
    // 004f826e  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004f8271  7404                   -je 0x4f8277
    if (cpu.flags.zf)
    {
        goto L_0x004f8277;
    }
    // 004f8273  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004f8277:
    // 004f8277  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004f827a  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004f827e  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004f8281  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8284  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8287  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004f8289  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 004f828d  3d34010000             +cmp eax, 0x134
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(308 /*0x134*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8292  7e07                   -jle 0x4f829b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f829b;
    }
    // 004f8294  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004f8299  eb13                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f829b:
    // 004f829b  3dccfeffff             +cmp eax, 0xfffffecc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966988 /*0xfffffecc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f82a0  7d07                   -jge 0x4f82a9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f82a9;
    }
    // 004f82a2  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004f82a7  eb05                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f82a9:
    // 004f82a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f82ae:
    // 004f82ae  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004f82b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f82b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f82b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f82b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f82b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f82ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f82bb  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f82be  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f82c0  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f82c3  e85afeffff             -call 0x4f8122
    cpu.esp -= 4;
    sub_4f8122(app, cpu);
    if (cpu.terminate) return;
    // 004f82c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f82ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f82cc  750b                   -jne 0x4f82d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f82d9;
    }
    // 004f82ce  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004f82d1:
    // 004f82d1  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004f82d4  e9ad000000             -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f82d9:
    // 004f82d9  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004f82dc  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004f82df  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f82e4  3dff430000             +cmp eax, 0x43ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17407 /*0x43ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f82e9  7c2a                   -jl 0x4f8315
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f8315;
    }
    // 004f82eb  e8b4a50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 004f82f0  f645dd80               +test byte ptr [ebp - 0x23], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) & 128 /*0x80*/));
    // 004f82f4  7410                   -je 0x4f8306
    if (cpu.flags.zf)
    {
        goto L_0x004f8306;
    }
    // 004f82f6  dd057c215500           +fld qword ptr [0x55217c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579132) /* 0x55217c */)));
    // 004f82fc  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004f82fe  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8301  e980000000             -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f8306:
    // 004f8306  a17c215500             -mov eax, dword ptr [0x55217c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579132) /* 0x55217c */);
    // 004f830b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004f830e  a180215500             -mov eax, dword ptr [0x552180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579136) /* 0x552180 */);
    // 004f8313  ebbc                   -jmp 0x4f82d1
    goto L_0x004f82d1;
L_0x004f8315:
    // 004f8315  3dcd3b0000             +cmp eax, 0x3bcd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15309 /*0x3bcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f831a  7d42                   -jge 0x4f835e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f835e;
    }
    // 004f831c  83f8cc                 +cmp eax, -0x34
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-52 /*-0x34*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f831f  7d0f                   -jge 0x4f8330
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8330;
    }
    // 004f8321  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f8323  e87ca50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 004f8328  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004f832b  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 004f832e  eb56                   -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f8330:
    // 004f8330  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8333  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8336  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004f8338  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f833a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f833d  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004f8340  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004f8343  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8346  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004f8349  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 004f834e  7504                   -jne 0x4f8354
    if (!cpu.flags.zf)
    {
        goto L_0x004f8354;
    }
    // 004f8350  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f8352  742d                   -je 0x4f8381
    if (cpu.flags.zf)
    {
        goto L_0x004f8381;
    }
L_0x004f8354:
    // 004f8354  66f745f6f07f           +test word ptr [ebp - 0xa], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) & 32752 /*0x7ff0*/));
    // 004f835a  752a                   -jne 0x4f8386
    if (!cpu.flags.zf)
    {
        goto L_0x004f8386;
    }
    // 004f835c  eb23                   -jmp 0x4f8381
    goto L_0x004f8381;
L_0x004f835e:
    // 004f835e  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8361  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8364  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004f8366  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8368  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f836b  7414                   -je 0x4f8381
    if (cpu.flags.zf)
    {
        goto L_0x004f8381;
    }
    // 004f836d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8370  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004f8373  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004f8376  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004f8379  66f745e6f07f           +test word ptr [ebp - 0x1a], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) & 32752 /*0x7ff0*/));
    // 004f837f  7505                   -jne 0x4f8386
    if (!cpu.flags.zf)
    {
        goto L_0x004f8386;
    }
L_0x004f8381:
    // 004f8381  e81ea50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
L_0x004f8386:
    // 004f8386  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004f8389  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004f838c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f8390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8394  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8395  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004f839b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f839d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f839e  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f83a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f83a7  a36c4a5600             -mov dword ptr [0x564a6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */) = cpu.eax;
    // 004f83ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f83ae  0f8466030000           -je 0x4f871a
    if (cpu.flags.zf)
    {
        goto L_0x004f871a;
    }
L_0x004f83b4:
    // 004f83b4  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f83ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f83bc  0f842c030000           -je 0x4f86ee
    if (cpu.flags.zf)
    {
        goto L_0x004f86ee;
    }
    // 004f83c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f83c3  68a4d35400             -push 0x54d3a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559204 /*0x54d3a4*/;
    cpu.esp -= 4;
    // 004f83c8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f83c9  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f83d0  68b4d35400             -push 0x54d3b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559220 /*0x54d3b4*/;
    cpu.esp -= 4;
    // 004f83d5  8b1d6c4a5600           -mov ebx, dword ptr [0x564a6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f83db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f83dc  a380f99e00             -mov dword ptr [0x9ef980], eax
    app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */) = cpu.eax;
    // 004f83e1  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f83e8  68ccd35400             -push 0x54d3cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559244 /*0x54d3cc*/;
    cpu.esp -= 4;
    // 004f83ed  8b356c4a5600           -mov esi, dword ptr [0x564a6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f83f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f83f4  a370f99e00             -mov dword ptr [0x9ef970], eax
    app->getMemory<x86::reg32>(x86::reg32(10418544) /* 0x9ef970 */) = cpu.eax;
    // 004f83f9  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8400  68dcd35400             -push 0x54d3dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559260 /*0x54d3dc*/;
    cpu.esp -= 4;
    // 004f8405  8b3d6c4a5600           -mov edi, dword ptr [0x564a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f840b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f840c  a32cf99e00             -mov dword ptr [0x9ef92c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418476) /* 0x9ef92c */) = cpu.eax;
    // 004f8411  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8418  68f0d35400             -push 0x54d3f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559280 /*0x54d3f0*/;
    cpu.esp -= 4;
    // 004f841d  8b2d6c4a5600           -mov ebp, dword ptr [0x564a6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8424  a328f99e00             -mov dword ptr [0x9ef928], eax
    app->getMemory<x86::reg32>(x86::reg32(10418472) /* 0x9ef928 */) = cpu.eax;
    // 004f8429  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8430  6808d45400             -push 0x54d408
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559304 /*0x54d408*/;
    cpu.esp -= 4;
    // 004f8435  a30cf99e00             -mov dword ptr [0x9ef90c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418444) /* 0x9ef90c */) = cpu.eax;
    // 004f843a  a16c4a5600             -mov eax, dword ptr [0x564a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f843f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f8440  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8447  6820d45400             -push 0x54d420
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559328 /*0x54d420*/;
    cpu.esp -= 4;
    // 004f844c  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8452  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8453  a308f99e00             -mov dword ptr [0x9ef908], eax
    app->getMemory<x86::reg32>(x86::reg32(10418440) /* 0x9ef908 */) = cpu.eax;
    // 004f8458  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f845f  6834d45400             -push 0x54d434
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559348 /*0x54d434*/;
    cpu.esp -= 4;
    // 004f8464  8b0d6c4a5600           -mov ecx, dword ptr [0x564a6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f846a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f846b  a310f99e00             -mov dword ptr [0x9ef910], eax
    app->getMemory<x86::reg32>(x86::reg32(10418448) /* 0x9ef910 */) = cpu.eax;
    // 004f8470  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8477  6850d45400             -push 0x54d450
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559376 /*0x54d450*/;
    cpu.esp -= 4;
    // 004f847c  8b1d6c4a5600           -mov ebx, dword ptr [0x564a6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8482  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8483  a304f99e00             -mov dword ptr [0x9ef904], eax
    app->getMemory<x86::reg32>(x86::reg32(10418436) /* 0x9ef904 */) = cpu.eax;
    // 004f8488  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f848f  686cd45400             -push 0x54d46c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559404 /*0x54d46c*/;
    cpu.esp -= 4;
    // 004f8494  8b356c4a5600           -mov esi, dword ptr [0x564a6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f849a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f849b  a300f99e00             -mov dword ptr [0x9ef900], eax
    app->getMemory<x86::reg32>(x86::reg32(10418432) /* 0x9ef900 */) = cpu.eax;
    // 004f84a0  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84a7  6880d45400             -push 0x54d480
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559424 /*0x54d480*/;
    cpu.esp -= 4;
    // 004f84ac  8b3d6c4a5600           -mov edi, dword ptr [0x564a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f84b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f84b3  a34cf99e00             -mov dword ptr [0x9ef94c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418508) /* 0x9ef94c */) = cpu.eax;
    // 004f84b8  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84bf  6898d45400             -push 0x54d498
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559448 /*0x54d498*/;
    cpu.esp -= 4;
    // 004f84c4  8b2d6c4a5600           -mov ebp, dword ptr [0x564a6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f84ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f84cb  a330f99e00             -mov dword ptr [0x9ef930], eax
    app->getMemory<x86::reg32>(x86::reg32(10418480) /* 0x9ef930 */) = cpu.eax;
    // 004f84d0  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84d7  68acd45400             -push 0x54d4ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559468 /*0x54d4ac*/;
    cpu.esp -= 4;
    // 004f84dc  a374f99e00             -mov dword ptr [0x9ef974], eax
    app->getMemory<x86::reg32>(x86::reg32(10418548) /* 0x9ef974 */) = cpu.eax;
    // 004f84e1  a16c4a5600             -mov eax, dword ptr [0x564a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f84e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f84e7  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84ee  a360f99e00             -mov dword ptr [0x9ef960], eax
    app->getMemory<x86::reg32>(x86::reg32(10418528) /* 0x9ef960 */) = cpu.eax;
    // 004f84f3  68c4d45400             -push 0x54d4c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559492 /*0x54d4c4*/;
    cpu.esp -= 4;
    // 004f84f8  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f84fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f84ff  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8506  68dcd45400             -push 0x54d4dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559516 /*0x54d4dc*/;
    cpu.esp -= 4;
    // 004f850b  8b0d6c4a5600           -mov ecx, dword ptr [0x564a6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8512  a324f99e00             -mov dword ptr [0x9ef924], eax
    app->getMemory<x86::reg32>(x86::reg32(10418468) /* 0x9ef924 */) = cpu.eax;
    // 004f8517  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f851e  68f4d45400             -push 0x54d4f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559540 /*0x54d4f4*/;
    cpu.esp -= 4;
    // 004f8523  8b1d6c4a5600           -mov ebx, dword ptr [0x564a6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8529  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f852a  a31cf99e00             -mov dword ptr [0x9ef91c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418460) /* 0x9ef91c */) = cpu.eax;
    // 004f852f  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8536  680cd55400             -push 0x54d50c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559564 /*0x54d50c*/;
    cpu.esp -= 4;
    // 004f853b  8b356c4a5600           -mov esi, dword ptr [0x564a6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8541  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8542  a350f99e00             -mov dword ptr [0x9ef950], eax
    app->getMemory<x86::reg32>(x86::reg32(10418512) /* 0x9ef950 */) = cpu.eax;
    // 004f8547  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f854e  681cd55400             -push 0x54d51c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559580 /*0x54d51c*/;
    cpu.esp -= 4;
    // 004f8553  8b3d6c4a5600           -mov edi, dword ptr [0x564a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8559  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f855a  a33cf99e00             -mov dword ptr [0x9ef93c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */) = cpu.eax;
    // 004f855f  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8566  682cd55400             -push 0x54d52c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559596 /*0x54d52c*/;
    cpu.esp -= 4;
    // 004f856b  8b2d6c4a5600           -mov ebp, dword ptr [0x564a6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8571  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8572  a378f99e00             -mov dword ptr [0x9ef978], eax
    app->getMemory<x86::reg32>(x86::reg32(10418552) /* 0x9ef978 */) = cpu.eax;
    // 004f8577  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f857e  683cd55400             -push 0x54d53c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559612 /*0x54d53c*/;
    cpu.esp -= 4;
    // 004f8583  a384f99e00             -mov dword ptr [0x9ef984], eax
    app->getMemory<x86::reg32>(x86::reg32(10418564) /* 0x9ef984 */) = cpu.eax;
    // 004f8588  a16c4a5600             -mov eax, dword ptr [0x564a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f858d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f858e  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8595  6854d55400             -push 0x54d554
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559636 /*0x54d554*/;
    cpu.esp -= 4;
    // 004f859a  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f85a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f85a1  a354f99e00             -mov dword ptr [0x9ef954], eax
    app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */) = cpu.eax;
    // 004f85a6  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f85ad  6868d55400             -push 0x54d568
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559656 /*0x54d568*/;
    cpu.esp -= 4;
    // 004f85b2  8b0d6c4a5600           -mov ecx, dword ptr [0x564a6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f85b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f85b9  a340f99e00             -mov dword ptr [0x9ef940], eax
    app->getMemory<x86::reg32>(x86::reg32(10418496) /* 0x9ef940 */) = cpu.eax;
    // 004f85be  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f85c5  687cd55400             -push 0x54d57c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559676 /*0x54d57c*/;
    cpu.esp -= 4;
    // 004f85ca  8b1d6c4a5600           -mov ebx, dword ptr [0x564a6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f85d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f85d1  a320f99e00             -mov dword ptr [0x9ef920], eax
    app->getMemory<x86::reg32>(x86::reg32(10418464) /* 0x9ef920 */) = cpu.eax;
    // 004f85d6  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f85dd  6890d55400             -push 0x54d590
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559696 /*0x54d590*/;
    cpu.esp -= 4;
    // 004f85e2  8b356c4a5600           -mov esi, dword ptr [0x564a6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f85e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f85e9  a37cf99e00             -mov dword ptr [0x9ef97c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */) = cpu.eax;
    // 004f85ee  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f85f5  68a8d55400             -push 0x54d5a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559720 /*0x54d5a8*/;
    cpu.esp -= 4;
    // 004f85fa  8b3d6c4a5600           -mov edi, dword ptr [0x564a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8600  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8601  a344f99e00             -mov dword ptr [0x9ef944], eax
    app->getMemory<x86::reg32>(x86::reg32(10418500) /* 0x9ef944 */) = cpu.eax;
    // 004f8606  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f860d  68bcd55400             -push 0x54d5bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559740 /*0x54d5bc*/;
    cpu.esp -= 4;
    // 004f8612  8b2d6c4a5600           -mov ebp, dword ptr [0x564a6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8618  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8619  a36cf99e00             -mov dword ptr [0x9ef96c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */) = cpu.eax;
    // 004f861e  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8625  a334f99e00             -mov dword ptr [0x9ef934], eax
    app->getMemory<x86::reg32>(x86::reg32(10418484) /* 0x9ef934 */) = cpu.eax;
    // 004f862a  68d4d55400             -push 0x54d5d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559764 /*0x54d5d4*/;
    cpu.esp -= 4;
    // 004f862f  a16c4a5600             -mov eax, dword ptr [0x564a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8634  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f8635  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f863c  68ecd55400             -push 0x54d5ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559788 /*0x54d5ec*/;
    cpu.esp -= 4;
    // 004f8641  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8647  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8648  a358f99e00             -mov dword ptr [0x9ef958], eax
    app->getMemory<x86::reg32>(x86::reg32(10418520) /* 0x9ef958 */) = cpu.eax;
    // 004f864d  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8654  68fcd55400             -push 0x54d5fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559804 /*0x54d5fc*/;
    cpu.esp -= 4;
    // 004f8659  8b0d6c4a5600           -mov ecx, dword ptr [0x564a6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f865f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8660  a348f99e00             -mov dword ptr [0x9ef948], eax
    app->getMemory<x86::reg32>(x86::reg32(10418504) /* 0x9ef948 */) = cpu.eax;
    // 004f8665  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f866c  6810d65400             -push 0x54d610
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559824 /*0x54d610*/;
    cpu.esp -= 4;
    // 004f8671  8b1d6c4a5600           -mov ebx, dword ptr [0x564a6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f8677  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8678  a368f99e00             -mov dword ptr [0x9ef968], eax
    app->getMemory<x86::reg32>(x86::reg32(10418536) /* 0x9ef968 */) = cpu.eax;
    // 004f867d  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8684  6824d65400             -push 0x54d624
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559844 /*0x54d624*/;
    cpu.esp -= 4;
    // 004f8689  8b356c4a5600           -mov esi, dword ptr [0x564a6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f868f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8690  a318f99e00             -mov dword ptr [0x9ef918], eax
    app->getMemory<x86::reg32>(x86::reg32(10418456) /* 0x9ef918 */) = cpu.eax;
    // 004f8695  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f869c  6838d65400             -push 0x54d638
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559864 /*0x54d638*/;
    cpu.esp -= 4;
    // 004f86a1  8b3d6c4a5600           -mov edi, dword ptr [0x564a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f86a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f86a8  a364f99e00             -mov dword ptr [0x9ef964], eax
    app->getMemory<x86::reg32>(x86::reg32(10418532) /* 0x9ef964 */) = cpu.eax;
    // 004f86ad  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f86b4  6850d65400             -push 0x54d650
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559888 /*0x54d650*/;
    cpu.esp -= 4;
    // 004f86b9  8b2d6c4a5600           -mov ebp, dword ptr [0x564a6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f86bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f86c0  a35cf99e00             -mov dword ptr [0x9ef95c], eax
    app->getMemory<x86::reg32>(x86::reg32(10418524) /* 0x9ef95c */) = cpu.eax;
    // 004f86c5  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f86cc  6864d65400             -push 0x54d664
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559908 /*0x54d664*/;
    cpu.esp -= 4;
    // 004f86d1  a338f99e00             -mov dword ptr [0x9ef938], eax
    app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */) = cpu.eax;
    // 004f86d6  a16c4a5600             -mov eax, dword ptr [0x564a6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f86db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f86dc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f86e1  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f86e8  a314f99e00             -mov dword ptr [0x9ef914], eax
    app->getMemory<x86::reg32>(x86::reg32(10418452) /* 0x9ef914 */) = cpu.eax;
    // 004f86ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f86ee:
    // 004f86ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f86f0  891510445600           -mov dword ptr [0x564410], edx
    app->getMemory<x86::reg32>(x86::reg32(5653520) /* 0x564410 */) = cpu.edx;
    // 004f86f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f86f8  7412                   -je 0x4f870c
    if (cpu.flags.zf)
    {
        goto L_0x004f870c;
    }
    // 004f86fa  833d6cf99e0000         +cmp dword ptr [0x9ef96c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8701  753e                   -jne 0x4f8741
    if (!cpu.flags.zf)
    {
        goto L_0x004f8741;
    }
L_0x004f8703:
    // 004f8703  833d80f99e0000         +cmp dword ptr [0x9ef980], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f870a  7541                   -jne 0x4f874d
    if (!cpu.flags.zf)
    {
        goto L_0x004f874d;
    }
L_0x004f870c:
    // 004f870c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f870e  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004f8714  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8716  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8717  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8718  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8719  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f871a:
    // 004f871a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f871b  68a0d35400             -push 0x54d3a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559200 /*0x54d3a0*/;
    cpu.esp -= 4;
    // 004f8720  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f8725  e8666ffeff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004f872a  83c40c                 +add esp, 0xc
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
    // 004f872d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f872f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f8730  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8737  a36c4a5600             -mov dword ptr [0x564a6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */) = cpu.eax;
    // 004f873c  e973fcffff             -jmp 0x4f83b4
    goto L_0x004f83b4;
L_0x004f8741:
    // 004f8741  6a68                   -push 0x68
    app->getMemory<x86::reg32>(cpu.esp-4) = 104 /*0x68*/;
    cpu.esp -= 4;
    // 004f8743  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 004f8745  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f874b  ebb6                   -jmp 0x4f8703
    goto L_0x004f8703;
L_0x004f874d:
    // 004f874d  ff1580f99e00           -call dword ptr [0x9ef980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8753  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f8755  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8757  74b3                   -je 0x4f870c
    if (cpu.flags.zf)
    {
        goto L_0x004f870c;
    }
    // 004f8759  813858464433           +cmp dword ptr [eax], 0x33444658
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(860112472 /*0x33444658*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f875f  7426                   -je 0x4f8787
    if (cpu.flags.zf)
    {
        goto L_0x004f8787;
    }
L_0x004f8761:
    // 004f8761  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f8764  83f868                 +cmp eax, 0x68
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8767  74a3                   -je 0x4f870c
    if (cpu.flags.zf)
    {
        goto L_0x004f870c;
    }
    // 004f8769  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f876a  687cd65400             -push 0x54d67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559932 /*0x54d67c*/;
    cpu.esp -= 4;
    // 004f876f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8771  e84a6ffeff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 004f8776  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f8779  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f877b  81c400020000           +add esp, 0x200
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8786  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8787:
    // 004f8787  c7051044560001000000   -mov dword ptr [0x564410], 1
    app->getMemory<x86::reg32>(x86::reg32(5653520) /* 0x564410 */) = 1 /*0x1*/;
    // 004f8791  ebce                   -jmp 0x4f8761
    goto L_0x004f8761;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f87a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f87a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f87a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f87a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f87a3  8b156c4a5600           -mov edx, dword ptr [0x564a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
    // 004f87a9  8b1d684a5600           -mov ebx, dword ptr [0x564a68]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5655144) /* 0x564a68 */);
    // 004f87af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f87b1  751a                   -jne 0x4f87cd
    if (!cpu.flags.zf)
    {
        goto L_0x004f87cd;
    }
L_0x004f87b3:
    // 004f87b3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f87b5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f87b7  89356c4a5600           -mov dword ptr [0x564a6c], esi
    app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */) = cpu.esi;
    // 004f87bd  e8aee90100             -call 0x517170
    cpu.esp -= 4;
    sub_517170(app, cpu);
    if (cpu.terminate) return;
    // 004f87c2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f87c4  e8a7eb0100             -call 0x517370
    cpu.esp -= 4;
    sub_517370(app, cpu);
    if (cpu.terminate) return;
    // 004f87c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f87ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f87cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f87cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f87cd:
    // 004f87cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f87ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f87cf  2eff15dc445300         -call dword ptr cs:[0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f87d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f87d7  ebda                   -jmp 0x4f87b3
    goto L_0x004f87b3;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f87e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f87e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f87e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f87e3  803821                 +cmp byte ptr [eax], 0x21
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(33 /*0x21*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f87e6  7526                   -jne 0x4f880e
    if (!cpu.flags.zf)
    {
        goto L_0x004f880e;
    }
    // 004f87e8  42                     -inc edx
    (cpu.edx)++;
L_0x004f87e9:
    // 004f87e9  833d684a560000         +cmp dword ptr [0x564a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5655144) /* 0x564a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f87f0  750a                   -jne 0x4f87fc
    if (!cpu.flags.zf)
    {
        goto L_0x004f87fc;
    }
    // 004f87f2  c705684a560001000000   -mov dword ptr [0x564a68], 1
    app->getMemory<x86::reg32>(x86::reg32(5655144) /* 0x564a68 */) = 1 /*0x1*/;
L_0x004f87fc:
    // 004f87fc  833d6c4a560000         +cmp dword ptr [0x564a6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8803  751b                   -jne 0x4f8820
    if (!cpu.flags.zf)
    {
        goto L_0x004f8820;
    }
    // 004f8805  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8807  e884fbffff             -call 0x4f8390
    cpu.esp -= 4;
    sub_4f8390(app, cpu);
    if (cpu.terminate) return;
    // 004f880c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f880d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f880e:
    // 004f880e  b800d75400             -mov eax, 0x54d700
    cpu.eax = 5560064 /*0x54d700*/;
    // 004f8813  e8b8620100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8818  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f881a  74cd                   -je 0x4f87e9
    if (cpu.flags.zf)
    {
        goto L_0x004f87e9;
    }
    // 004f881c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f881e  ebc9                   -jmp 0x4f87e9
    goto L_0x004f87e9;
L_0x004f8820:
    // 004f8820  e87bffffff             -call 0x4f87a0
    cpu.esp -= 4;
    sub_4f87a0(app, cpu);
    if (cpu.terminate) return;
    // 004f8825  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8827  e864fbffff             -call 0x4f8390
    cpu.esp -= 4;
    sub_4f8390(app, cpu);
    if (cpu.terminate) return;
    // 004f882c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f882d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f8830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8834  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8835  8b0d80f99e00           -mov ecx, dword ptr [0x9ef980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
    // 004f883b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f8840  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8842  743e                   -je 0x4f8882
    if (cpu.flags.zf)
    {
        goto L_0x004f8882;
    }
L_0x004f8844:
    // 004f8844  b880755100             -mov eax, 0x517580
    cpu.eax = 5338496 /*0x517580*/;
    // 004f8849  b920795100             -mov ecx, 0x517920
    cpu.ecx = 5339424 /*0x517920*/;
    // 004f884e  bb90795100             -mov ebx, 0x517990
    cpu.ebx = 5339536 /*0x517990*/;
    // 004f8853  bed0795100             -mov esi, 0x5179d0
    cpu.esi = 5339600 /*0x5179d0*/;
    // 004f8858  bd10765100             -mov ebp, 0x517610
    cpu.ebp = 5338640 /*0x517610*/;
    // 004f885d  a3c47d5600             -mov dword ptr [0x567dc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5668292) /* 0x567dc4 */) = cpu.eax;
    // 004f8862  890dcc7d5600           -mov dword ptr [0x567dcc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */) = cpu.ecx;
    // 004f8868  891dd07d5600           -mov dword ptr [0x567dd0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668304) /* 0x567dd0 */) = cpu.ebx;
    // 004f886e  8935d47d5600           -mov dword ptr [0x567dd4], esi
    app->getMemory<x86::reg32>(x86::reg32(5668308) /* 0x567dd4 */) = cpu.esi;
    // 004f8874  892dc87d5600           -mov dword ptr [0x567dc8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5668296) /* 0x567dc8 */) = cpu.ebp;
    // 004f887a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f887c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f887d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f887e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f887f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8880  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8881  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8882:
    // 004f8882  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8883  bb14d75400             -mov ebx, 0x54d714
    cpu.ebx = 5560084 /*0x54d714*/;
    // 004f8888  be24d75400             -mov esi, 0x54d724
    cpu.esi = 5560100 /*0x54d724*/;
    // 004f888d  bf0e000000             -mov edi, 0xe
    cpu.edi = 14 /*0xe*/;
    // 004f8892  682cd75400             -push 0x54d72c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560108 /*0x54d72c*/;
    cpu.esp -= 4;
    // 004f8897  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f889d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f88a3  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f88a9  e86287f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f88ae  83c404                 +add esp, 4
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
    // 004f88b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f88b2  eb90                   -jmp 0x4f8844
    goto L_0x004f8844;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f88c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f88c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f88c1  833d6443560000         +cmp dword ptr [0x564364], 0
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
    // 004f88c8  7522                   -jne 0x4f88ec
    if (!cpu.flags.zf)
    {
        goto L_0x004f88ec;
    }
L_0x004f88ca:
    // 004f88ca  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f88cc  893dc47d5600           -mov dword ptr [0x567dc4], edi
    app->getMemory<x86::reg32>(x86::reg32(5668292) /* 0x567dc4 */) = cpu.edi;
    // 004f88d2  893dcc7d5600           -mov dword ptr [0x567dcc], edi
    app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */) = cpu.edi;
    // 004f88d8  893dd07d5600           -mov dword ptr [0x567dd0], edi
    app->getMemory<x86::reg32>(x86::reg32(5668304) /* 0x567dd0 */) = cpu.edi;
    // 004f88de  893dd47d5600           -mov dword ptr [0x567dd4], edi
    app->getMemory<x86::reg32>(x86::reg32(5668308) /* 0x567dd4 */) = cpu.edi;
    // 004f88e4  893dc87d5600           -mov dword ptr [0x567dc8], edi
    app->getMemory<x86::reg32>(x86::reg32(5668296) /* 0x567dc8 */) = cpu.edi;
    // 004f88ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f88eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f88ec:
    // 004f88ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f88ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f88ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f88ef  b914d75400             -mov ecx, 0x54d714
    cpu.ecx = 5560084 /*0x54d714*/;
    // 004f88f4  bb68d75400             -mov ebx, 0x54d768
    cpu.ebx = 5560168 /*0x54d768*/;
    // 004f88f9  be1d000000             -mov esi, 0x1d
    cpu.esi = 29 /*0x1d*/;
    // 004f88fe  6874d75400             -push 0x54d774
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560180 /*0x54d774*/;
    cpu.esp -= 4;
    // 004f8903  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f8909  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f890f  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f8915  e8f686f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f891a  83c404                 +add esp, 4
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
    // 004f891d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f891e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f891f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8920  eba8                   -jmp 0x4f88ca
    goto L_0x004f88ca;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f8930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8931  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8932  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8934  e8076efeff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004f8939  833dfc44560000         +cmp dword ptr [0x5644fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8940  0f842d010000           -je 0x4f8a73
    if (cpu.flags.zf)
    {
        goto L_0x004f8a73;
    }
L_0x004f8946:
    // 004f8946  833d6443560000         +cmp dword ptr [0x564364], 0
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
    // 004f894d  0f8514010000           -jne 0x4f8a67
    if (!cpu.flags.zf)
    {
        goto L_0x004f8a67;
    }
    // 004f8953  baacd75400             -mov edx, 0x54d7ac
    cpu.edx = 5560236 /*0x54d7ac*/;
    // 004f8958  b8b0d75400             -mov eax, 0x54d7b0
    cpu.eax = 5560240 /*0x54d7b0*/;
    // 004f895d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f895f  e8ec010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8964  baacd75400             -mov edx, 0x54d7ac
    cpu.edx = 5560236 /*0x54d7ac*/;
    // 004f8969  b8c0d75400             -mov eax, 0x54d7c0
    cpu.eax = 5560256 /*0x54d7c0*/;
    // 004f896e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8970  e8db010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8975  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f897a  bad8d75400             -mov edx, 0x54d7d8
    cpu.edx = 5560280 /*0x54d7d8*/;
    // 004f897f  b8dcd75400             -mov eax, 0x54d7dc
    cpu.eax = 5560284 /*0x54d7dc*/;
    // 004f8984  e8c7010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8989  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f898e  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f8993  b8f4d75400             -mov eax, 0x54d7f4
    cpu.eax = 5560308 /*0x54d7f4*/;
    // 004f8998  e8b3010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f899d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f89a2  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f89a7  b800d85400             -mov eax, 0x54d800
    cpu.eax = 5560320 /*0x54d800*/;
    // 004f89ac  e89f010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f89b1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f89b6  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f89bb  b80cd85400             -mov eax, 0x54d80c
    cpu.eax = 5560332 /*0x54d80c*/;
    // 004f89c0  e88b010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f89c5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f89ca  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f89cf  b818d85400             -mov eax, 0x54d818
    cpu.eax = 5560344 /*0x54d818*/;
    // 004f89d4  e877010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f89d9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f89de  bad8d75400             -mov edx, 0x54d7d8
    cpu.edx = 5560280 /*0x54d7d8*/;
    // 004f89e3  b824d85400             -mov eax, 0x54d824
    cpu.eax = 5560356 /*0x54d824*/;
    // 004f89e8  e863010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f89ed  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f89f2  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f89f7  b834d85400             -mov eax, 0x54d834
    cpu.eax = 5560372 /*0x54d834*/;
    // 004f89fc  e84f010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a01  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8a06  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f8a0b  b844d85400             -mov eax, 0x54d844
    cpu.eax = 5560388 /*0x54d844*/;
    // 004f8a10  e83b010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a15  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8a1a  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f8a1f  b854d85400             -mov eax, 0x54d854
    cpu.eax = 5560404 /*0x54d854*/;
    // 004f8a24  e827010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a29  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8a2e  baf0d75400             -mov edx, 0x54d7f0
    cpu.edx = 5560304 /*0x54d7f0*/;
    // 004f8a33  b864d85400             -mov eax, 0x54d864
    cpu.eax = 5560420 /*0x54d864*/;
    // 004f8a38  e813010000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a3d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8a42  bad8d75400             -mov edx, 0x54d7d8
    cpu.edx = 5560280 /*0x54d7d8*/;
    // 004f8a47  b870d85400             -mov eax, 0x54d870
    cpu.eax = 5560432 /*0x54d870*/;
    // 004f8a4c  e8ff000000             -call 0x4f8b50
    cpu.esp -= 4;
    sub_4f8b50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a51  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 004f8a57  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 004f8a5d  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 004f8a62  e869ff0000             -call 0x5089d0
    cpu.esp -= 4;
    sub_5089d0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8a67:
    // 004f8a67  833d6443560000         +cmp dword ptr [0x564364], 0
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
    // 004f8a6e  750d                   -jne 0x4f8a7d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8a7d;
    }
    // 004f8a70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8a71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8a72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8a73:
    // 004f8a73  e858080000             -call 0x4f92d0
    cpu.esp -= 4;
    sub_4f92d0(app, cpu);
    if (cpu.terminate) return;
    // 004f8a78  e9c9feffff             -jmp 0x4f8946
    goto L_0x004f8946;
L_0x004f8a7d:
    // 004f8a7d  bb308c5600             -mov ebx, 0x568c30
    cpu.ebx = 5671984 /*0x568c30*/;
    // 004f8a82  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004f8a87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8a89  e8c2b30000             -call 0x503e50
    cpu.esp -= 4;
    sub_503e50(app, cpu);
    if (cpu.terminate) return;
    // 004f8a8e  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f8a93  e85865f9ff             -call 0x48eff0
    cpu.esp -= 4;
    sub_48eff0(app, cpu);
    if (cpu.terminate) return;
    // 004f8a98  e8d391ffff             -call 0x4f1c70
    cpu.esp -= 4;
    sub_4f1c70(app, cpu);
    if (cpu.terminate) return;
    // 004f8a9d  e84e94ffff             -call 0x4f1ef0
    cpu.esp -= 4;
    sub_4f1ef0(app, cpu);
    if (cpu.terminate) return;
    // 004f8aa2  e889f00100             -call 0x517b30
    cpu.esp -= 4;
    sub_517b30(app, cpu);
    if (cpu.terminate) return;
    // 004f8aa7  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 004f8aac  e86f6affff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 004f8ab1  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004f8ab6  e8a56cffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004f8abb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8abd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8ac2  e8996cffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004f8ac7  e8646dffff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 004f8acc  e84f080000             -call 0x4f9320
    cpu.esp -= 4;
    sub_4f9320(app, cpu);
    if (cpu.terminate) return;
    // 004f8ad1  833d6843560000         +cmp dword ptr [0x564368], 0
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
    // 004f8ad8  7505                   -jne 0x4f8adf
    if (!cpu.flags.zf)
    {
        goto L_0x004f8adf;
    }
    // 004f8ada  e8f1280000             -call 0x4fb3d0
    cpu.esp -= 4;
    sub_4fb3d0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8adf:
    // 004f8adf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ae0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8ae1  e81a2c0000             -call 0x4fb700
    cpu.esp -= 4;
    sub_4fb700(app, cpu);
    if (cpu.terminate) return;
    // 004f8ae6  e80577ffff             -call 0x4f01f0
    cpu.esp -= 4;
    sub_4f01f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8aeb  e8b0f00100             -call 0x517ba0
    cpu.esp -= 4;
    sub_517ba0(app, cpu);
    if (cpu.terminate) return;
    // 004f8af0  b8fcef4f00             -mov eax, 0x4feffc
    cpu.eax = 5238780 /*0x4feffc*/;
    // 004f8af5  bf607d5100             -mov edi, 0x517d60
    cpu.edi = 5340512 /*0x517d60*/;
    // 004f8afa  e8fd640000             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 004f8aff  b8e0004f00             -mov eax, 0x4f00e0
    cpu.eax = 5177568 /*0x4f00e0*/;
    // 004f8b04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f8b06  e8e575ffff             -call 0x4f00f0
    cpu.esp -= 4;
    sub_4f00f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b0b  893d04445600           -mov dword ptr [0x564404], edi
    app->getMemory<x86::reg32>(x86::reg32(5653508) /* 0x564404 */) = cpu.edi;
    // 004f8b11  e8caf20100             -call 0x517de0
    cpu.esp -= 4;
    sub_517de0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b16  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8b18  e833370000             -call 0x4fc250
    cpu.esp -= 4;
    sub_4fc250(app, cpu);
    if (cpu.terminate) return;
    // 004f8b1d  e81ef50100             -call 0x518040
    cpu.esp -= 4;
    sub_518040(app, cpu);
    if (cpu.terminate) return;
    // 004f8b22  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004f8b27  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 004f8b2c  8b0d88435600           -mov ecx, dword ptr [0x564388]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 004f8b32  8b1d84435600           -mov ebx, dword ptr [0x564384]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 004f8b38  e8b3480000             -call 0x4fd3f0
    cpu.esp -= 4;
    sub_4fd3f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f8b3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8b41  e83a470000             -call 0x4fd280
    cpu.esp -= 4;
    sub_4fd280(app, cpu);
    if (cpu.terminate) return;
    // 004f8b46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8b47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8b48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8b49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8b4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f8b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8b50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8b51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8b52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8b53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8b54  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8b57  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8b59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f8b5b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004f8b5f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f8b64  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8b69  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f8b6d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f8b70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8b72  7419                   -je 0x4f8b8d
    if (cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b74  803e00                 +cmp byte ptr [esi], 0
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
    // 004f8b77  7514                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b79  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b7e  750b                   -jne 0x4f8b8b
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8b;
    }
    // 004f8b80  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b82  e8495f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b89  7502                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
L_0x004f8b8b:
    // 004f8b8b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8b8d:
    // 004f8b8d  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b92  750b                   -jne 0x4f8b9f
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b9f;
    }
    // 004f8b94  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b96  e8355f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b9d  7517                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
L_0x004f8b9f:
    // 004f8b9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8ba0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ba1  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8ba8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8baa  750a                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
    // 004f8bac  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bb1  e927010000             -jmp 0x4f8cdd
    goto L_0x004f8cdd;
L_0x004f8bb6:
    // 004f8bb6  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8bba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8bbc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8bbe  e825010000             -call 0x4f8ce8
    cpu.esp -= 4;
    sub_4f8ce8(app, cpu);
    if (cpu.terminate) return;
    // 004f8bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bc5  740d                   -je 0x4f8bd4
    if (cpu.flags.zf)
    {
        goto L_0x004f8bd4;
    }
    // 004f8bc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bcc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8bcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8bd4:
    // 004f8bd4  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 004f8bd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bdb  0f84fc000000           -je 0x4f8cdd
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdd;
    }
    // 004f8be1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8be3  e868f40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8be8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f8beb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8bef  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004f8bf2  e809edffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8bf7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8bf9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f8bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bfd  7517                   -jne 0x4f8c16
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c16;
    }
    // 004f8bff  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c04  e883830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c09  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c0e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c16:
    // 004f8c16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8c18  743c                   -je 0x4f8c56
    if (cpu.flags.zf)
    {
        goto L_0x004f8c56;
    }
    // 004f8c1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8c1c  e82ff40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8c21  40                     -inc eax
    (cpu.eax)++;
    // 004f8c22  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8c26  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f8c2a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004f8c2d  e8ceecffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8c32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f8c34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8c36  7520                   -jne 0x4f8c58
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c58;
    }
    // 004f8c38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8c3a  e8b1edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c3f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c44  e843830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c49  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c4e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c56:
    // 004f8c56  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f8c58:
    // 004f8c58  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c5c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f8c5e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c60  e81bf40100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c65  83f8ff                 +cmp eax, -1
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
    // 004f8c68  751b                   -jne 0x4f8c85
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c85;
    }
    // 004f8c6a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c6c  e87fedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c73  e878edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c78  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c7d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c85:
    // 004f8c85  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8c87  7431                   -je 0x4f8cba
    if (cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c89  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8c8d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c93  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8c95  e8e6f30100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c9a  83f8ff                 +cmp eax, -1
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
    // 004f8c9d  751b                   -jne 0x4f8cba
    if (!cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c9f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ca1  e84aedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8ca6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8ca8  e843edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8cb2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8cb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8cba:
    // 004f8cba  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8cbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f8cc0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8cc2  e8c9f50100             -call 0x518290
    cpu.esp -= 4;
    sub_518290(app, cpu);
    if (cpu.terminate) return;
    // 004f8cc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8cc9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ccb  e820edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cd0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8cd2  7407                   -je 0x4f8cdb
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdb;
    }
    // 004f8cd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8cd6  e815edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8cdb:
    // 004f8cdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f8cdd:
    // 004f8cdd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8ce0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8ce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8ce8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8ce9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8cea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ceb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8cec  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8cef  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8cf3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f8cf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8cf9  750a                   -jne 0x4f8d05
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d05;
    }
    // 004f8cfb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d00  e928020000             -jmp 0x4f8f2d
    goto L_0x004f8f2d;
L_0x004f8d05:
    // 004f8d05  803800                 +cmp byte ptr [eax], 0
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
    // 004f8d08  750d                   -jne 0x4f8d17
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d17;
    }
    // 004f8d0a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d0f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8d12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8d17:
    // 004f8d17  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8d1c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8d20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d22  754b                   -jne 0x4f8d6f
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d6f;
    }
    // 004f8d24  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004f8d29  0f84fe010000           -je 0x4f8f2d
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2d;
    }
    // 004f8d2f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004f8d34  e8c7ebffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8d39  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8d3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d3f  750d                   -jne 0x4f8d4e
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d4e;
    }
    // 004f8d41  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d46  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8d49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8d4e:
    // 004f8d4e  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004f8d54  a354b1a000             -mov dword ptr [0xa0b154], eax
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.eax;
    // 004f8d59  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004f8d60  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f8d63  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004f8d65  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 004f8d6a  e9f7000000             -jmp 0x4f8e66
    goto L_0x004f8e66;
L_0x004f8d6f:
    // 004f8d6f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8d73  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8d77  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8d7b  e8b8010000             -call 0x4f8f38
    cpu.esp -= 4;
    sub_4f8f38(app, cpu);
    if (cpu.terminate) return;
    // 004f8d80  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8d82  0f84a3010000           -je 0x4f8f2b
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2b;
    }
    // 004f8d88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d8a  0f8fcb000000           -jg 0x4f8e5b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f8e5b;
    }
    // 004f8d90  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f8d92  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f8d94  8b3d50b1a000           -mov edi, dword ptr [0xa0b150]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8d9a  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 004f8da1  40                     -inc eax
    (cpu.eax)++;
    // 004f8da2  8d5908                 -lea ebx, [ecx + 8]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f8da5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f8da8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8daa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8dac  7550                   -jne 0x4f8dfe
    if (!cpu.flags.zf)
    {
        goto L_0x004f8dfe;
    }
    // 004f8dae  e84debffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8db3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8db5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8db9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8dbb  750d                   -jne 0x4f8dca
    if (!cpu.flags.zf)
    {
        goto L_0x004f8dca;
    }
    // 004f8dbd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8dc2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8dc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8dca:
    // 004f8dca  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8dd0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8dd2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8dd3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8dd5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8dd7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8dd8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8dda  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f8ddd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f8ddf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f8de1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f8de4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f8de6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8de7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8de8  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8dea  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f8ded  891550b1a000           -mov dword ptr [0xa0b150], edx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.edx;
    // 004f8df3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8df5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f8df7  e84478feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f8dfc  eb38                   -jmp 0x4f8e36
    goto L_0x004f8e36;
L_0x004f8dfe:
    // 004f8dfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8e00  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e04  e8b7f70100             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 004f8e09  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8e0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8e0f  750d                   -jne 0x4f8e1e
    if (!cpu.flags.zf)
    {
        goto L_0x004f8e1e;
    }
    // 004f8e11  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8e16  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8e19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8e1e:
    // 004f8e1e  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e24  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004f8e27  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f8e29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8e2b  e810f80100             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 004f8e30  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
L_0x004f8e36:
    // 004f8e36  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e3a  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004f8e41  01d0                   +add eax, edx
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
    // 004f8e43  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004f8e4a  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e4f  891554b1a000           -mov dword ptr [0xa0b154], edx
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edx;
    // 004f8e55  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
    // 004f8e59  eb0b                   -jmp 0x4f8e66
    goto L_0x004f8e66;
L_0x004f8e5b:
    // 004f8e5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f8e5d  0f84c8000000           -je 0x4f8f2b
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2b;
    }
    // 004f8e63  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004f8e66:
    // 004f8e66  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8e6a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8e6b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8e6d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8e6f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f8e71  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8e72  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f8e74  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f8e76  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f8e78  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8e79  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8e7a  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e7f  8a3428                 -mov dh, byte ptr [eax + ebp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1);
    // 004f8e82  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f8e84  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004f8e86  7411                   -je 0x4f8e99
    if (cpu.flags.zf)
    {
        goto L_0x004f8e99;
    }
    // 004f8e88  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e8c  8d34ad00000000         -lea esi, [ebp*4]
    cpu.esi = x86::reg32(cpu.ebp * 4);
    // 004f8e93  01ce                   +add esi, ecx
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
    // 004f8e95  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004f8e97  eb02                   -jmp 0x4f8e9b
    goto L_0x004f8e9b;
L_0x004f8e99:
    // 004f8e99  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8e9b:
    // 004f8e9b  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8e9f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8ea0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8ea2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8ea4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f8ea6  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8ea7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f8ea9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f8eab  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f8ead  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8eae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8eaf  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 004f8eb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8eb4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8eb7  e804f70100             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 004f8ebc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8ebe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8ec0  750d                   -jne 0x4f8ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ecf;
    }
    // 004f8ec2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8ec7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8eca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ece  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8ecf:
    // 004f8ecf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8ed3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f8ed5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8ed7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8ed8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8eda  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8edc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8edd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8edf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f8ee2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f8ee4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f8ee6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f8ee9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f8eeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8eec  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8eed  c6041a3d               -mov byte ptr [edx + ebx], 0x3d
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 61 /*0x3d*/;
    // 004f8ef1  43                     -inc ebx
    (cpu.ebx)++;
    // 004f8ef2  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8ef6  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004f8ef9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f8efa:
    // 004f8efa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f8efc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f8efe  3c00                   +cmp al, 0
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
    // 004f8f00  7410                   -je 0x4f8f12
    if (cpu.flags.zf)
    {
        goto L_0x004f8f12;
    }
    // 004f8f02  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f8f05  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8f08  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f8f0b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8f0e  3c00                   +cmp al, 0
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
    // 004f8f10  75e8                   -jne 0x4f8efa
    if (!cpu.flags.zf)
    {
        goto L_0x004f8efa;
    }
L_0x004f8f12:
    // 004f8f12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f13  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8f17  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004f8f1e  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f8f20  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004f8f22  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8f27  c6042801               -mov byte ptr [eax + ebp], 1
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 1 /*0x1*/;
L_0x004f8f2b:
    // 004f8f2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f8f2d:
    // 004f8f2d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8f30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8f38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8f39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8f3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8f3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8f3c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8f3d  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8f40  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f8f43  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f8f47  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8f4c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8f50  e9da000000             -jmp 0x4f902f
    goto L_0x004f902f;
L_0x004f8f55:
    // 004f8f55  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x004f8f58:
    // 004f8f58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8f5c  80383d                 +cmp byte ptr [eax], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8f5f  0f8593000000           -jne 0x4f8ff8
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8f65  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8f69  0f8589000000           -jne 0x4f8ff8
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8f6f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f73  2b3554b1a000           -sub esi, dword ptr [0xa0b154]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */)));
    // 004f8f79  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8f7d  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 004f8f80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8f82  0f856b000000           -jne 0x4f8ff3
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff3;
    }
    // 004f8f88  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f8c  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004f8f8e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8f94  740f                   -je 0x4f8fa5
    if (cpu.flags.zf)
    {
        goto L_0x004f8fa5;
    }
L_0x004f8f96:
    // 004f8f96  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f8f99  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004f8f9b  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f8f9e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f8fa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8fa3  75f1                   -jne 0x4f8f96
    if (!cpu.flags.zf)
    {
        goto L_0x004f8f96;
    }
L_0x004f8fa5:
    // 004f8fa5  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8fab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f8fad  7449                   -je 0x4f8ff8
    if (cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8faf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8fb1  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8fb5  7407                   -je 0x4f8fbe
    if (cpu.flags.zf)
    {
        goto L_0x004f8fbe;
    }
    // 004f8fb7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8fb9  e832eaffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8fbe:
    // 004f8fbe  8b1d54b1a000           -mov ebx, dword ptr [0xa0b154]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8fc4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004f8fc6  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8fc8  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8fce  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004f8fd1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8fd3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f8fd5  e866f60100             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 004f8fda  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 004f8fe0  39fe                   +cmp esi, edi
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
    // 004f8fe2  7d14                   -jge 0x4f8ff8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8ff8;
    }
    // 004f8fe4  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8fe6:
    // 004f8fe6  41                     -inc ecx
    (cpu.ecx)++;
    // 004f8fe7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f8fe9  46                     -inc esi
    (cpu.esi)++;
    // 004f8fea  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004f8fed  39fe                   +cmp esi, edi
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
    // 004f8fef  7d07                   -jge 0x4f8ff8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8ff8;
    }
    // 004f8ff1  ebf3                   -jmp 0x4f8fe6
    goto L_0x004f8fe6;
L_0x004f8ff3:
    // 004f8ff3  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f8ff6  eb57                   -jmp 0x4f904f
    goto L_0x004f904f;
L_0x004f8ff8:
    // 004f8ff8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8ffc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8ffe  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f9000  e8db5dffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f9005  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9007  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9009  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004f900c  e8cf5dffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f9011  39c2                   +cmp edx, eax
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
    // 004f9013  7515                   -jne 0x4f902a
    if (!cpu.flags.zf)
    {
        goto L_0x004f902a;
    }
    // 004f9015  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f9019  740f                   -je 0x4f902a
    if (cpu.flags.zf)
    {
        goto L_0x004f902a;
    }
    // 004f901b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f901f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9020  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9021  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f9025  e92effffff             -jmp 0x4f8f58
    goto L_0x004f8f58;
L_0x004f902a:
    // 004f902a  8344240404             -add dword ptr [esp + 4], 4
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f902f:
    // 004f902f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9033  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f9035  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f9039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f903b  0f8514ffffff           -jne 0x4f8f55
    if (!cpu.flags.zf)
    {
        goto L_0x004f8f55;
    }
    // 004f9041  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9045  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f904a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f904c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004f904f:
    // 004f904f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9052  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9053  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9054  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9055  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9056  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9057  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9060  ff057c715600           -inc dword ptr [0x56717c]
    (app->getMemory<x86::reg32>(x86::reg32(5665148) /* 0x56717c */))++;
    // 004f9066  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f9070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9070  833d0c3d9f0000         +cmp dword ptr [0x9f3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435852) /* 0x9f3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9077  7509                   -jne 0x4f9082
    if (!cpu.flags.zf)
    {
        goto L_0x004f9082;
    }
    // 004f9079  833d8071560000         +cmp dword ptr [0x567180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9080  7406                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        goto L_0x004f9088;
    }
L_0x004f9082:
    // 004f9082  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9088:
    // 004f9088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f908a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9088;
    // 004f9070  833d0c3d9f0000         +cmp dword ptr [0x9f3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435852) /* 0x9f3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9077  7509                   -jne 0x4f9082
    if (!cpu.flags.zf)
    {
        goto L_0x004f9082;
    }
    // 004f9079  833d8071560000         +cmp dword ptr [0x567180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9080  7406                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        goto L_0x004f9088;
    }
L_0x004f9082:
    // 004f9082  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9088:
L_entry_0x004f9088:
    // 004f9088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f908a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f9090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9092  a02f3d9f00             -mov al, byte ptr [0x9f3d2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435887) /* 0x9f3d2f */);
    // 004f9097  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f90a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90a0  803d303d9f0000         +cmp byte ptr [0x9f3d30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435888) /* 0x9f3d30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90a7  74df                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90a9  803d053d9f0000         +cmp byte ptr [0x9f3d05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435845) /* 0x9f3d05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90b0  75d6                   -jne 0x4f9088
    if (!cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90b2  803d043d9f0000         +cmp byte ptr [0x9f3d04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435844) /* 0x9f3d04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90b9  75cd                   -jne 0x4f9088
    if (!cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f90c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f90d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f90d2  a0323d9f00             -mov al, byte ptr [0x9f3d32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435890) /* 0x9f3d32 */);
    // 004f90d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f90e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90e0  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f90e3  833d2850560000         +cmp dword ptr [0x565028], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f90ea  741c                   -je 0x4f9108
    if (cpu.flags.zf)
    {
        goto L_0x004f9108;
    }
    // 004f90ec  833dcc7d560000         +cmp dword ptr [0x567dcc], 0
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
    // 004f90f3  741c                   -je 0x4f9111
    if (cpu.flags.zf)
    {
        goto L_0x004f9111;
    }
    // 004f90f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f90f7  e8d4b5ffff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 004f90fc  e88f1cffff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004f9101  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9103  e8f8b5ffff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
L_0x004f9108:
    // 004f9108  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f910d  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f9110  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9111:
    // 004f9111  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004f9116  e81542ffff             -call 0x4ed330
    cpu.esp -= 4;
    sub_4ed330(app, cpu);
    if (cpu.terminate) return;
    // 004f911b  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f911e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9120  833d4c3d9f0000         +cmp dword ptr [0x9f3d4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9127  0f845bffffff           -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f912d  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
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
    // 004f9134  0f844effffff           -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f913a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f913f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9143  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9145  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9147  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f914e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9150  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f9152  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9159  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f9160  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f9163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9165  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f9170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9170  6880d85400             -push 0x54d880
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560448 /*0x54d880*/;
    cpu.esp -= 4;
    // 004f9175  e87677feff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004f917a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f917f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9182  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f9190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9190  68b8d85400             -push 0x54d8b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560504 /*0x54d8b8*/;
    cpu.esp -= 4;
    // 004f9195  e85677feff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004f919a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f919f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f91a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f91b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f91b0  68f0d85400             -push 0x54d8f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560560 /*0x54d8f0*/;
    cpu.esp -= 4;
    // 004f91b5  e83677feff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004f91ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f91bf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f91c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f91d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f91d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f91d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f91d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f91d3  833da412560000         +cmp dword ptr [0x5612a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f91da  750c                   -jne 0x4f91e8
    if (!cpu.flags.zf)
    {
        goto L_0x004f91e8;
    }
    // 004f91dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f91de  746c                   -je 0x4f924c
    if (cpu.flags.zf)
    {
        goto L_0x004f924c;
    }
    // 004f91e0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004f91e2:
    // 004f91e2  891da4125600           -mov dword ptr [0x5612a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */) = cpu.ebx;
L_0x004f91e8:
    // 004f91e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f91ea  7505                   -jne 0x4f91f1
    if (!cpu.flags.zf)
    {
        goto L_0x004f91f1;
    }
    // 004f91ec  a1a4125600             -mov eax, dword ptr [0x5612a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
L_0x004f91f1:
    // 004f91f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f91f2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f91f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f91f6  2eff15a0445300         -call dword ptr cs:[0x5344a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457056) /* 0x5344a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f91fd  a3403d9f00             -mov dword ptr [0x9f3d40], eax
    app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */) = cpu.eax;
    // 004f9202  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9209  3db7000000             +cmp eax, 0xb7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f920e  7536                   -jne 0x4f9246
    if (!cpu.flags.zf)
    {
        goto L_0x004f9246;
    }
    // 004f9210  8b0da4125600           -mov ecx, dword ptr [0x5612a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
    // 004f9216  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9217  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9219  2eff1534475300         -call dword ptr cs:[0x534734]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457716) /* 0x534734 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9220  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9222  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9224  7412                   -je 0x4f9238
    if (cpu.flags.zf)
    {
        goto L_0x004f9238;
    }
    // 004f9226  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004f9228  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9229  2eff1598475300         -call dword ptr cs:[0x534798]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457816) /* 0x534798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9231  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f9238:
    // 004f9238  833d8871560000         +cmp dword ptr [0x567188], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665160) /* 0x567188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f923f  7415                   -je 0x4f9256
    if (cpu.flags.zf)
    {
        goto L_0x004f9256;
    }
    // 004f9241  e83798ffff             -call 0x4f2a7d
    cpu.esp -= 4;
    sub_4f2a7d(app, cpu);
    if (cpu.terminate) return;
L_0x004f9246:
    // 004f9246  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f9248  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9249  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f924a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f924b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f924c:
    // 004f924c  8b1dc8389f00           -mov ebx, dword ptr [0x9f38c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434760) /* 0x9f38c8 */);
    // 004f9252  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9254  eb8c                   -jmp 0x4f91e2
    goto L_0x004f91e2;
L_0x004f9256:
    // 004f9256  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f925b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f925c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f925d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f925e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f9260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f9270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9272  6860924f00             -push 0x4f9260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5214816 /*0x4f9260*/;
    cpu.esp -= 4;
    // 004f9277  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9279  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9281  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f9283  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f9285  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9287  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f9289  ba2cd95400             -mov edx, 0x54d92c
    cpu.edx = 5560620 /*0x54d92c*/;
    // 004f928e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9290  e89b7ffeff             -call 0x4e1230
    cpu.esp -= 4;
    sub_4e1230(app, cpu);
    if (cpu.terminate) return;
    // 004f9295  8b15c0f59e00           -mov edx, dword ptr [0x9ef5c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */);
    // 004f929b  8915c4f59e00           -mov dword ptr [0x9ef5c4], edx
    app->getMemory<x86::reg32>(x86::reg32(10417604) /* 0x9ef5c4 */) = cpu.edx;
    // 004f92a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f92b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f92b3  e848e6ffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f92b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f92ba  a3fc445600             -mov dword ptr [0x5644fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.eax;
    // 004f92bf  e8acffffff             -call 0x4f9270
    cpu.esp -= 4;
    sub_4f9270(app, cpu);
    if (cpu.terminate) return;
    // 004f92c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f92d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92d1  b800000001             -mov eax, 0x1000000
    cpu.eax = 16777216 /*0x1000000*/;
    // 004f92d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92d8  e8d3ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f92e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92e3  e8c8ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f92f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92f1  8b15fc445600           -mov edx, dword ptr [0x5644fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */);
    // 004f92f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f92f9  7502                   -jne 0x4f92fd
    if (!cpu.flags.zf)
    {
        goto L_0x004f92fd;
    }
    // 004f92fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f92fd:
    // 004f92fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9300  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9302  e8e9e6ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9307  890dfc445600           -mov dword ptr [0x5644fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.ecx;
    // 004f930d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9310  a38c715600             -mov dword ptr [0x56718c], eax
    app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */) = cpu.eax;
    // 004f9315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f9320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9320  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9327  7401                   -je 0x4f932a
    if (cpu.flags.zf)
    {
        goto L_0x004f932a;
    }
    // 004f9329  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f932a:
    // 004f932a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f932b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f932d  e89efc0100             -call 0x518fd0
    cpu.esp -= 4;
    sub_518fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f9332  b864905600             -mov eax, 0x569064
    cpu.eax = 5673060 /*0x569064*/;
    // 004f9337  e8d40b0200             -call 0x519f10
    cpu.esp -= 4;
    sub_519f10(app, cpu);
    if (cpu.terminate) return;
    // 004f933c  a390715600             -mov dword ptr [0x567190], eax
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.eax;
    // 004f9341  b860934f00             -mov eax, 0x4f9360
    cpu.eax = 5215072 /*0x4f9360*/;
    // 004f9346  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f934b  e82897ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f9350  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9356  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9360  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9367  7501                   -jne 0x4f936a
    if (!cpu.flags.zf)
    {
        goto L_0x004f936a;
    }
    // 004f9369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f936a:
    // 004f936a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f936b  a190715600             -mov eax, dword ptr [0x567190]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */);
    // 004f9370  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9372  e8f90d0200             -call 0x51a170
    cpu.esp -= 4;
    sub_51a170(app, cpu);
    if (cpu.terminate) return;
    // 004f9377  890d90715600           -mov dword ptr [0x567190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.ecx;
    // 004f937d  e8befd0100             -call 0x519140
    cpu.esp -= 4;
    sub_519140(app, cpu);
    if (cpu.terminate) return;
    // 004f9382  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9391  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9392  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9393  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f9395  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f9397  e804a0feff             -call 0x4e33a0
    cpu.esp -= 4;
    sub_4e33a0(app, cpu);
    if (cpu.terminate) return;
    // 004f939c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f939e  49                     -dec ecx
    (cpu.ecx)--;
    // 004f939f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f93a1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f93a3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f93a5  49                     -dec ecx
    (cpu.ecx)--;
    // 004f93a6  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f93a8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004f93aa  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f93ab  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f93ad  49                     -dec ecx
    (cpu.ecx)--;
    // 004f93ae  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f93b0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f93b2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f93b4  49                     -dec ecx
    (cpu.ecx)--;
    // 004f93b5  39d9                   +cmp ecx, ebx
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
    // 004f93b7  7606                   -jbe 0x4f93bf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f93bf;
    }
    // 004f93b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f93bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f93bf:
    // 004f93bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f93c0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f93c2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004f93c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f93c5  2bc9                   +sub ecx, ecx
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
    // 004f93c7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f93c8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f93ca  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f93cc  4f                     -dec edi
    (cpu.edi)--;
L_0x004f93cd:
    // 004f93cd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f93cf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f93d1  3c00                   +cmp al, 0
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
    // 004f93d3  7410                   -je 0x4f93e5
    if (cpu.flags.zf)
    {
        goto L_0x004f93e5;
    }
    // 004f93d5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f93d8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f93db  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f93de  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f93e1  3c00                   +cmp al, 0
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
    // 004f93e3  75e8                   -jne 0x4f93cd
    if (!cpu.flags.zf)
    {
        goto L_0x004f93cd;
    }
L_0x004f93e5:
    // 004f93e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f93eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93f0  8078013a               +cmp byte ptr [eax + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f93f4  7406                   -je 0x4f93fc
    if (cpu.flags.zf)
    {
        goto L_0x004f93fc;
    }
    // 004f93f6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f93fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f93fc:
    // 004f93fc  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004f93fe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f9403  e8d859ffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f9408  83e841                 -sub eax, 0x41
    (cpu.eax) -= x86::reg32(x86::sreg32(65 /*0x41*/));
    // 004f940b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f9410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9413  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9414  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9417  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9419  be30d95400             -mov esi, 0x54d930
    cpu.esi = 5560624 /*0x54d930*/;
    // 004f941e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f9420  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f9421:
    // 004f9421  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f9423  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f9425  3c00                   +cmp al, 0
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
    // 004f9427  7410                   -je 0x4f9439
    if (cpu.flags.zf)
    {
        goto L_0x004f9439;
    }
    // 004f9429  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f942c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f942f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f9432  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f9435  3c00                   +cmp al, 0
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
    // 004f9437  75e8                   -jne 0x4f9421
    if (!cpu.flags.zf)
    {
        goto L_0x004f9421;
    }
L_0x004f9439:
    // 004f9439  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f943a  001424                 -add byte ptr [esp], dl
    (app->getMemory<x86::reg8>(cpu.esp)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004f943d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f943f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9440  2eff1518455300         -call dword ptr cs:[0x534518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457176) /* 0x534518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9447  83f805                 +cmp eax, 5
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
    // 004f944a  7515                   -jne 0x4f9461
    if (!cpu.flags.zf)
    {
        goto L_0x004f9461;
    }
    // 004f944c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9451  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9454  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9455  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9456  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9457  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9458  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f945e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
    // 004f9460  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9461:
    // 004f9461  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9463  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9466  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9467  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9468  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9469  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f946a  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
