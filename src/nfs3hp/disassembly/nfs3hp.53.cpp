#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d1a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d1a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052d1a3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052d1a4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052d1a7  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d1aa  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d1ad  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 0052d1b1  ba0000ff7f             -mov edx, 0x7fff0000
    cpu.edx = 2147418112 /*0x7fff0000*/;
    // 0052d1b6  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 0052d1bb  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052d1be  0f6ee8                 -movd mm5, eax
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0052d1c1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d1c3:
    // 0052d1c3  833e00                 +cmp dword ptr [esi], 0
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
    // 0052d1c6  7e76                   -jle 0x52d23e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d23e;
    }
    // 0052d1c8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d1ca  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d1cc  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052d1cf  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d1d2  83c338                 -add ebx, 0x38
    (cpu.ebx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052d1d5  0f6e0c8570ad5600       -movd mm1, dword ptr [eax*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.eax * 4)) };
    // 0052d1dd  0f6e148580ad5600       -movd mm2, dword ptr [eax*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.eax * 4)) };
    // 0052d1e5  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d1e7  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 0052d1ec  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d1ef  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d1f2  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x0052d1f5:
    // 0052d1f5  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d1f8  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d1fb  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d1fe  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 0052d201  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d209  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d20c  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d210  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d213  0f61f3                 -punpcklwd mm6, mm3
    cpu.mmx.mm6 = { _mm_unpacklo_epi16(cpu.mmx.mm6, cpu.mmx.mm3) };
    // 0052d216  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 0052d219  0f73d620               -psrlq mm6, 0x20
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 32 /*0x20*/) };
    // 0052d21d  0f7ff3                 -movq mm3, mm6
    cpu.mmx.mm3 = cpu.mmx.mm6;
    // 0052d220  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 0052d223  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d22b  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d22e  0f73d608               -psrlq mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d232  0f61de                 -punpcklwd mm3, mm6
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d235  0f7e1c8b               -movd dword ptr [ebx + ecx*4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4), cpu.mmx.mm3);
    // 0052d239  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052d23a  7cb9                   -jl 0x52d1f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d1f5;
    }
    // 0052d23c  eb85                   -jmp 0x52d1c3
    goto L_0x0052d1c3;
L_0x0052d23e:
    // 0052d23e  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 0052d242  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d245  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052d246  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d247  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d251  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052d253  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052d254  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052d257  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d25a  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d25d  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 0052d261  0f625e08               -punpckldq mm3, dword ptr [esi + 8]
    cpu.mmx.mm3 = { _mm_unpacklo_epi32(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */))) };
    // 0052d265  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0052d26a  0f6ef8                 -movd mm7, eax
    cpu.mmx.mm7 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0052d26d  0f62ff                 -punpckldq mm7, mm7
    cpu.mmx.mm7 = { _mm_unpacklo_epi32(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 0052d270  0f7ffd                 -movq mm5, mm7
    cpu.mmx.mm5 = cpu.mmx.mm7;
    // 0052d273  0f72f510               -pslld mm5, 0x10
    cpu.mmx.mm5 = { _mm_slli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 0052d277  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d279:
    // 0052d279  833e00                 +cmp dword ptr [esi], 0
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
    // 0052d27c  0f8edb000000           -jle 0x52d35d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d35d;
    }
    // 0052d282  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d284  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d286  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052d289  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d28b  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d28e  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d291  83c370                 -add ebx, 0x70
    (cpu.ebx) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0052d294  0f6e0c8570ad5600       -movd mm1, dword ptr [eax*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.eax * 4)) };
    // 0052d29c  0f620c9570ad5600       -punpckldq mm1, dword ptr [edx*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_unpacklo_epi32(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.edx * 4))) };
    // 0052d2a4  0f6e148580ad5600       -movd mm2, dword ptr [eax*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.eax * 4)) };
    // 0052d2ac  0f62149580ad5600       -punpckldq mm2, dword ptr [edx*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_unpacklo_epi32(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.edx * 4))) };
    // 0052d2b4  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0052d2b7  b9e4ffffff             -mov ecx, 0xffffffe4
    cpu.ecx = 4294967268 /*0xffffffe4*/;
    // 0052d2bc  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d2be  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d2c1  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d2c4  83c71e                 -add edi, 0x1e
    (cpu.edi) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 0052d2c7  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0052d2ca  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0052d2cd  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052d2cf  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d2d1:
    // 0052d2d1  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d2d4  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d2d7  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d2da  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d2e2  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 0052d2e5  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d2e8  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0052d2eb  0f628495a0bea000       -punpckldq mm0, dword ptr [ebp + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_unpacklo_epi32(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4))) };
    // 0052d2f3  0fdbdd                 -pand mm3, mm5
    cpu.mmx.mm3 = { _mm_and_si128(cpu.mmx.mm3, cpu.mmx.mm5) };
    // 0052d2f6  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d2f9  0f72d608               -psrld mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d2fd  0fdbf7                 -pand mm6, mm7
    cpu.mmx.mm6 = { _mm_and_si128(cpu.mmx.mm6, cpu.mmx.mm7) };
    // 0052d300  0febde                 -por mm3, mm6
    cpu.mmx.mm3 = { _mm_or_si128(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d303  8a543901               -mov dl, byte ptr [ecx + edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 0052d307  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d30a  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d30d  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d315  8a543901               -mov dl, byte ptr [ecx + edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 0052d319  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0052d31c  0f628495a0bea000       -punpckldq mm0, dword ptr [ebp + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_unpacklo_epi32(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4))) };
    // 0052d324  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 0052d327  0fdbdf                 -pand mm3, mm7
    cpu.mmx.mm3 = { _mm_and_si128(cpu.mmx.mm3, cpu.mmx.mm7) };
    // 0052d32a  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d32d  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d331  0fdbf5                 -pand mm6, mm5
    cpu.mmx.mm6 = { _mm_and_si128(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 0052d334  0febde                 -por mm3, mm6
    cpu.mmx.mm3 = { _mm_or_si128(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d337  0f7f1c8b               -movq qword ptr [ebx + ecx*4], mm3
    app->getMemory<x86::reg64>(cpu.ebx + cpu.ecx * 4) = cpu.mmx.mm3;
    // 0052d33b  66ff748b02             -push word ptr [ebx + ecx*4 + 2]
    app->getMemory<x86::reg16>(cpu.esp-4) = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    // 0052d340  66ff748b04             -push word ptr [ebx + ecx*4 + 4]
    app->getMemory<x86::reg16>(cpu.esp-4) = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    // 0052d345  668f448b02             -pop word ptr [ebx + ecx*4 + 2]
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */ + cpu.ecx * 4) = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052d34a  668f448b04             -pop word ptr [ebx + ecx*4 + 4]
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052d34f  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052d352  0f8c79ffffff           -jl 0x52d2d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d2d1;
    }
    // 0052d358  e91cffffff             -jmp 0x52d279
    goto L_0x0052d279;
L_0x0052d35d:
    // 0052d35d  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 0052d361  0f73d320               -psrlq mm3, 0x20
    cpu.mmx.mm3 = { _mm_srli_epi64(cpu.mmx.mm3, 32 /*0x20*/) };
    // 0052d365  0f7e5e08               -movd dword ptr [esi + 8], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */), cpu.mmx.mm3);
    // 0052d369  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052d36c  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052d36d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d36e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52d370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d373  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d374  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d377  8b1c95d0b15600         -mov ebx, dword ptr [edx*4 + 0x56b1d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681616) /* 0x56b1d0 */ + cpu.edx * 4);
    // 0052d37e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d381  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d384  21cb                   -and ebx, ecx
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d386  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d388  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0052d38a  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052d38d  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0052d38f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052d392  83ff08                 +cmp edi, 8
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
    // 0052d395  7c07                   -jl 0x52d39e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d39e;
    }
    // 0052d397  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d39e:
    // 0052d39e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3a0  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052d3a2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d3a8  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3ab  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3ad  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3b0  46                     -inc esi
    (cpu.esi)++;
    // 0052d3b1  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d3b4  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0052d3b6  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d3b8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3bb  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052d3be  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d3c0  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052d3c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d3c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52d3cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d3cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d3cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d3ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d3cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d3d0  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0052d3d2  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3d5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3d8  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0052d3da  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d3dc  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052d3df  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052d3e2  83fe08                 +cmp esi, 8
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
    // 0052d3e5  7c05                   -jl 0x52d3ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d3ec;
    }
    // 0052d3e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d3ec:
    // 0052d3ec  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3ee  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052d3f0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d3f6  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3f9  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3fc  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d3fe  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d401  09d5                   -or ebp, edx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d403  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d406  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d408  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0052d40b  42                     -inc edx
    (cpu.edx)++;
    // 0052d40c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052d40f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052d411  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d412  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d414  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52d428(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052d428  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d429  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d42a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d42b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d42e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d430  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052d432  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0052d434  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052d436  753a                   -jne 0x52d472
    if (!cpu.flags.zf)
    {
        goto L_0x0052d472;
    }
    // 0052d438  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d43a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
L_0x0052d43f:
    // 0052d43f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d442  21d8                   -and eax, ebx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d444  83f803                 +cmp eax, 3
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
    // 0052d447  771b                   -ja 0x52d464
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052d464;
    }
    // 0052d449  ff248518d45200         -jmp dword ptr [eax*4 + 0x52d418]
    cpu.ip = app->getMemory<x86::reg32>(5428248 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052d450:
    // 0052d450  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d455  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d457  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
L_0x0052d45f:
    // 0052d45f  e868ffffff             -call 0x52d3cc
    cpu.esp -= 4;
    sub_52d3cc(app, cpu);
    if (cpu.terminate) return;
L_0x0052d464:
    // 0052d464  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d466  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d469  7cd4                   -jl 0x52d43f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d43f;
    }
    // 0052d46b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d46e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d46f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d470  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d471  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d472:
    // 0052d472  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d474  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d476  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0052d479:
    // 0052d479  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d47c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052d47f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d484  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052d487  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d489  8a9c02f4b25600         -mov bl, byte ptr [edx + eax + 0x56b2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5681908) /* 0x56b2f4 */ + cpu.eax * 1);
    // 0052d490  6bc30c                 -imul eax, ebx, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0052d493  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052d497  8b80f4b45600           -mov eax, dword ptr [eax + 0x56b4f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5682420) /* 0x56b4f4 */);
    // 0052d49d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d4a1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052d4a4  8b92f8b45600           -mov edx, dword ptr [edx + 0x56b4f8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5682424) /* 0x56b4f8 */);
    // 0052d4aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4ac  e81bffffff             -call 0x52d3cc
    cpu.esp -= 4;
    sub_52d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0052d4b1  83fb03                 +cmp ebx, 3
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
    // 0052d4b4  7e1c                   -jle 0x52d4d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d4d2;
    }
    // 0052d4b6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d4ba  8b82fcb45600           -mov eax, dword ptr [edx + 0x56b4fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5682428) /* 0x56b4fc */);
    // 0052d4c0  89448d00               -mov dword ptr [ebp + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = cpu.eax;
    // 0052d4c4  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0052d4c6:
    // 0052d4c6  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d4c9  7cae                   -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d4cb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d4ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d4d2:
    // 0052d4d2  83fb01                 +cmp ebx, 1
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
    // 0052d4d5  7f1a                   -jg 0x52d4f1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052d4f1;
    }
    // 0052d4d7  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
L_0x0052d4dc:
    // 0052d4dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d4e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4e3  e888feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d4e8  83f801                 +cmp eax, 1
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
    // 0052d4eb  7560                   -jne 0x52d54d
    if (!cpu.flags.zf)
    {
        goto L_0x0052d54d;
    }
    // 0052d4ed  01c3                   +add ebx, eax
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
    // 0052d4ef  ebeb                   -jmp 0x52d4dc
    goto L_0x0052d4dc;
L_0x0052d4f1:
    // 0052d4f1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052d4f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4f8  e873feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d4fd  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052d500  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052d504  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0052d507  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d509  83f86c                 +cmp eax, 0x6c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d50c  7e12                   -jle 0x52d520
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d520;
    }
    // 0052d50e  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0052d513  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d515  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052d517  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052d51a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052d51c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0052d520:
    // 0052d520  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052d524  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d526  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d528  7e9c                   -jle 0x52d4c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d4c6;
    }
    // 0052d52a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0052d52e:
    // 0052d52e  40                     -inc eax
    (cpu.eax)++;
    // 0052d52f  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
    // 0052d537  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d539  39d0                   +cmp eax, edx
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
    // 0052d53b  7cf1                   -jl 0x52d52e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d52e;
    }
    // 0052d53d  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d540  0f8c33ffffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d546  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d54d:
    // 0052d54d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d552  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d554  e817feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d559  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0052d560  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052d562  83f801                 +cmp eax, 1
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
    // 0052d565  751c                   -jne 0x52d583
    if (!cpu.flags.zf)
    {
        goto L_0x0052d583;
    }
    // 0052d567  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d56b  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0052d56f  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d571  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d573  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d576  0f8cfdfeffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d57c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d57f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d580  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d581  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d582  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d583:
    // 0052d583  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0052d585  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d589  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0052d58d  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d58f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d591  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d594  0f8cdffeffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d59a  83c410                 +add esp, 0x10
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
    // 0052d59d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d59e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d59f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d5a0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052d5a1:
    // 0052d5a1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052d5a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d5a8  c7448d00000000c0       -mov dword ptr [ebp + ecx*4], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 3221225472 /*0xc0000000*/;
    // 0052d5b0  e9aafeffff             -jmp 0x52d45f
    goto L_0x0052d45f;
  case 0x0052d5b5:
    // 0052d5b5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052d5ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d5bc  c7448d0000000040       -mov dword ptr [ebp + ecx*4], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 1073741824 /*0x40000000*/;
    // 0052d5c4  e996feffff             -jmp 0x52d45f
    goto L_0x0052d45f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d5cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d5cc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052d5cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d5cf  8d90b0010000           -lea edx, [eax + 0x1b0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(432) /* 0x1b0 */);
    // 0052d5d5  dd05fc205500           -fld qword ptr [0x5520fc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579004) /* 0x5520fc */)));
    // 0052d5db  dd05f4205500           -fld qword ptr [0x5520f4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5578996) /* 0x5520f4 */)));
    // 0052d5e1  dd05ec205500           -fld qword ptr [0x5520ec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5578988) /* 0x5520ec */)));
L_0x0052d5e7:
    // 0052d5e7  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 0052d5ea  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0052d5ed  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052d5ef  d940f4                 -fld dword ptr [eax - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */)));
    // 0052d5f2  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 0052d5f5  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0052d5f7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d5f9  d940ec                 -fld dword ptr [eax - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-20) /* -0x14 */)));
    // 0052d5fc  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 0052d5ff  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0052d601  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d603  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d606  d958f8                 -fstp dword ptr [eax - 8]
    app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d609  39d0                   +cmp eax, edx
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
    // 0052d60b  75da                   -jne 0x52d5e7
    if (!cpu.flags.zf)
    {
        goto L_0x0052d5e7;
    }
    // 0052d60d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d60f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d611  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d613  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d614  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d619  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d61a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d61b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d61c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d61d  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052d620  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052d622  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0052d626  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052d62b  8d5528                 -lea edx, [ebp + 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
L_0x0052d62e:
    // 0052d62e  48                     -dec eax
    (cpu.eax)--;
    // 0052d62f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d631  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d634  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d63a  7df2                   -jge 0x52d62e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d62e;
    }
    // 0052d63c  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 0052d641  8b7c2464               -mov edi, dword ptr [esp + 0x64]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0052d645  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052d648  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d64a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052d64c  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0052d650  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0052d654:
    // 0052d654  d9452c                 -fld dword ptr [ebp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 0052d657  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0052d659  d84c245c               -fmul dword ptr [esp + 0x5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */));
    // 0052d65d  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052d662  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0052d666  d9542468               -fst dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
L_0x0052d66a:
    // 0052d66a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d66c  d84c8430               -fmul dword ptr [esp + eax*4 + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 4));
    // 0052d670  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d672  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d674  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052d676  48                     -dec eax
    (cpu.eax)--;
    // 0052d677  d8448434               -fadd dword ptr [esp + eax*4 + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.eax * 4));
    // 0052d67b  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d67e  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d682  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d684  7de4                   -jge 0x52d66a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d66a;
    }
    // 0052d686  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d68a  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0052d68e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d690  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0052d694  890434                 -mov dword ptr [esp + esi], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.esi * 1) = cpu.eax;
    // 0052d697  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d699  7e21                   -jle 0x52d6bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d6bc;
    }
    // 0052d69b  d9442468               -fld dword ptr [esp + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0052d69f  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0052d6a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0052d6a5:
    // 0052d6a5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d6a7  d84c04fc               -fmul dword ptr [esp + eax - 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1));
    // 0052d6ab  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6ae  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6b1  41                     -inc ecx
    (cpu.ecx)++;
    // 0052d6b2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d6b4  39d9                   +cmp ecx, ebx
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
    // 0052d6b6  7ced                   -jl 0x52d6a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d6a5;
    }
    // 0052d6b8  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052d6bc:
    // 0052d6bc  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0052d6c0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6c3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6c6  43                     -inc ebx
    (cpu.ebx)++;
    // 0052d6c7  8947fc                 -mov dword ptr [edi - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052d6ca  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d6cd  7c85                   -jl 0x52d654
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d654;
    }
    // 0052d6cf  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052d6d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52d6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d6d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d6d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d6da  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0052d6dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d6df  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052d6e1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052d6e3  0f859e070000           -jne 0x52de87
    if (!cpu.flags.zf)
    {
        goto L_0x0052de87;
    }
    // 0052d6e9  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
L_0x0052d6ed:
    // 0052d6ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052d6ef  8d8614010000           -lea eax, [esi + 0x114]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 0052d6f5  e81effffff             -call 0x52d618
    cpu.esp -= 4;
    sub_52d618(app, cpu);
    if (cpu.terminate) return;
    // 0052d6fa  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0052d701  8d9684060000           -lea edx, [esi + 0x684]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 0052d707  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d709  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d70b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d70d  0f8e6e070000           -jle 0x52de81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052de81;
    }
L_0x0052d713:
    // 0052d713  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d716  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d71c  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 0052d71e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d722  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d728  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d72a  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d72e  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d734  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d736  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d73a  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d740  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d742  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d746  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d74c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d74e  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d752  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d758  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d75a  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d75e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d764  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d766  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d76a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d770  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d772  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d776  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d77c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d77e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d782  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d788  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d78a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d78e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d794  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d796  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d79a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d7a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7a2  d99670010000           -fst dword ptr [esi + 0x170]
    app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */) = float(cpu.fpu.st(0));
    // 0052d7a8  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052d7ac  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052d7ae  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d7b0  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d7b2  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d7b5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d7bb  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0052d7be  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d7c2  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d7c8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7ca  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d7ce  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d7d4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7d6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d7da  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d7e0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7e2  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d7e6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d7ec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7ee  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d7f2  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d7f8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7fa  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d7fe  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d804  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d806  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d80a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d810  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d812  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d816  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d81c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d81e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d822  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d828  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d82a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d82e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d834  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d836  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d83a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d840  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d842  d9966c010000           -fst dword ptr [esi + 0x16c]
    app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */) = float(cpu.fpu.st(0));
    // 0052d848  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d84a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d84d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d850  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d856  d84008                 -fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 0052d859  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d85d  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d863  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d865  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d869  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d86f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d871  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d875  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d87b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d87d  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d881  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d887  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d889  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d88d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d893  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d895  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d899  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d89f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8a1  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d8a5  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d8ab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8ad  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d8b1  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d8b7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8b9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d8bd  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d8c3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8c5  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d8c9  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d8cf  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8d1  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d8d5  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d8db  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8dd  d99668010000           -fst dword ptr [esi + 0x168]
    app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */) = float(cpu.fpu.st(0));
    // 0052d8e3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8e5  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d8e8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d8eb  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d8f1  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 0052d8f4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d8f8  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d8fe  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d900  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d904  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d90a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d90c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d910  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d916  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d918  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d91c  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d922  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d924  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d928  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d92e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d930  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d934  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d93a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d93c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d940  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d946  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d948  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d94c  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d952  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d954  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d958  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d95e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d960  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d964  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d96a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d96c  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d970  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d976  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d978  d99e64010000           -fstp dword ptr [esi + 0x164]
    app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d97e  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052d982  d98664010000           -fld dword ptr [esi + 0x164]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */)));
    // 0052d988  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d98a  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d98d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d990  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d996  d84010                 -fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 0052d999  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d99d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d9a3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9a5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d9a9  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d9af  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9b1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d9b5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d9bb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9bd  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d9c1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d9c7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9c9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d9cd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d9d3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9d5  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d9d9  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d9df  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9e1  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d9e5  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d9eb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9ed  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d9f1  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d9f7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9f9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d9fd  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052da03  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da05  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052da09  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052da0f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da11  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052da15  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052da1b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da1d  d99660010000           -fst dword ptr [esi + 0x160]
    app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */) = float(cpu.fpu.st(0));
    // 0052da23  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052da25  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052da28  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052da2b  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052da31  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 0052da34  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052da38  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052da3e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da40  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052da44  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052da4a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da4c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052da50  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052da56  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da58  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052da5c  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052da62  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da64  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052da68  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052da6e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da70  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052da74  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052da7a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da7c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052da80  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052da86  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da88  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052da8c  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052da92  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da94  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052da98  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052da9e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daa0  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052daa4  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052daaa  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daac  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dab0  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dab6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dab8  d9965c010000           -fst dword ptr [esi + 0x15c]
    app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 0052dabe  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dac0  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dac3  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dac6  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dacc  d84018                 -fadd dword ptr [eax + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */));
    // 0052dacf  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dad3  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dad9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dadb  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dadf  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dae5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dae7  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052daeb  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052daf1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daf3  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052daf7  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dafd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daff  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052db03  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052db09  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db0b  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052db0f  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052db15  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db17  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052db1b  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052db21  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db23  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052db27  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052db2d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db2f  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052db33  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052db39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db3b  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052db3f  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052db45  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db47  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052db4b  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052db51  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db53  d99658010000           -fst dword ptr [esi + 0x158]
    app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    // 0052db59  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db5b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052db5e  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052db61  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052db67  d8401c                 -fadd dword ptr [eax + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 0052db6a  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052db6e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052db74  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db76  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052db7a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052db80  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db82  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052db86  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052db8c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db8e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052db92  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052db98  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db9a  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052db9e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dba4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dba6  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dbaa  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dbb0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbb2  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dbb6  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dbbc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbbe  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dbc2  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dbc8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbca  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dbce  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dbd4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbd6  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dbda  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dbe0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbe2  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dbe6  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dbec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbee  d99654010000           -fst dword ptr [esi + 0x154]
    app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */) = float(cpu.fpu.st(0));
    // 0052dbf4  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052dbf8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052dbfa  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dbfc  d9581c                 -fstp dword ptr [eax + 0x1c]
    app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dbff  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dc02  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dc08  d84020                 -fadd dword ptr [eax + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */));
    // 0052dc0b  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dc0f  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dc15  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc17  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dc1b  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dc21  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc23  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dc27  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dc2d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc2f  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dc33  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dc39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc3b  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dc3f  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dc45  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc47  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dc4b  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dc51  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc53  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dc57  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dc5d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc5f  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dc63  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dc69  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc6b  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dc6f  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dc75  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc77  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dc7b  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dc81  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc83  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dc87  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dc8d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc8f  d99650010000           -fst dword ptr [esi + 0x150]
    app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */) = float(cpu.fpu.st(0));
    // 0052dc95  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dc97  d95820                 -fstp dword ptr [eax + 0x20]
    app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dc9a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dc9d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dca3  d84024                 -fadd dword ptr [eax + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0052dca6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dcaa  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dcb0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcb2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dcb6  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dcbc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcbe  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dcc2  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dcc8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcca  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dcce  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dcd4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcd6  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dcda  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dce0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dce2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dce6  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dcec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcee  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dcf2  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dcf8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcfa  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dcfe  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dd04  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd06  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dd0a  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dd10  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd12  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dd16  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dd1c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd1e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dd22  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dd28  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd2a  d9964c010000           -fst dword ptr [esi + 0x14c]
    app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */) = float(cpu.fpu.st(0));
    // 0052dd30  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd32  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dd35  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dd38  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dd3e  d84028                 -fadd dword ptr [eax + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0052dd41  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dd45  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dd4b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd4d  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dd51  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dd57  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd59  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dd5d  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dd63  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd65  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dd69  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dd6f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd71  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dd75  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dd7b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd7d  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dd81  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dd87  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd89  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dd8d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dd93  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd95  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dd99  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dd9f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dda1  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dda5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052ddab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddad  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052ddb1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052ddb7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddb9  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052ddbd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052ddc3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddc5  d99e48010000           -fstp dword ptr [esi + 0x148]
    app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052ddcb  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052ddcf  d98648010000           -fld dword ptr [esi + 0x148]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */)));
    // 0052ddd5  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052ddd7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052ddda  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dddd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dde3  d8402c                 -fadd dword ptr [eax + 0x2c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0052dde6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052ddea  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052ddf0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddf2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052ddf6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052ddfc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddfe  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052de02  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052de08  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de0a  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052de0e  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052de14  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de16  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052de1a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052de20  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de22  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052de26  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052de2c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de2e  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052de32  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052de38  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de3a  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052de3e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052de44  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de46  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052de4a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052de50  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de52  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052de56  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052de5c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de5e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052de62  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052de68  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de6a  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0052de6d  d99644010000           -fst dword ptr [esi + 0x144]
    app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    // 0052de73  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de75  42                     -inc edx
    (cpu.edx)++;
    // 0052de76  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052de79  39da                   +cmp edx, ebx
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
    // 0052de7b  0f8c92f8ffff           -jl 0x52d713
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d713;
    }
L_0x0052de81:
    // 0052de81  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052de84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052de85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052de86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052de87:
    // 0052de87  c74424300000404b       -mov dword ptr [esp + 0x30], 0x4b400000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 1262485504 /*0x4b400000*/;
    // 0052de8f  e959f8ffff             -jmp 0x52d6ed
    goto L_0x0052d6ed;
}

/* align: skip  */
void Application::sub_52de94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052de94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052de95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052de96  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052de99  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052de9b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052de9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052de9e  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052dea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052dea6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052deab  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052dead  c7430808000000         -mov dword ptr [ebx + 8], 8
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052deb4  46                     -inc esi
    (cpu.esi)++;
    // 0052deb5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052deb8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052deba  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0052debc  e8aff4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dec1  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052dec6  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052dec9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052decb  e8a0f4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052ded0  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0052ded5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ded7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ded9  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052dedc  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052dee1  e88af4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dee6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052dee8  40                     -inc eax
    (cpu.eax)++;
    // 0052dee9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052deed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052def1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052def3  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052def7  dc0d04215500           -fmul qword ptr [0x552104]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579012) /* 0x552104 */));
    // 0052defd  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052df01  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052df06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df08  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df0b  e860f4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052df10  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052df14  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052df18  dc0d0c215500           -fmul qword ptr [0x55210c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579020) /* 0x55210c */));
    // 0052df1e  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052df21  dc0514215500           -fadd qword ptr [0x552114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5579028) /* 0x552114 */));
    // 0052df27  8d9300010000           -lea edx, [ebx + 0x100]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
    // 0052df2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052df2e:
    // 0052df2e  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0052df31  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052df33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df36  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df39  39d0                   +cmp eax, edx
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
    // 0052df3b  75f1                   -jne 0x52df2e
    if (!cpu.flags.zf)
    {
        goto L_0x0052df2e;
    }
    // 0052df3d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df41  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
L_0x0052df44:
    // 0052df44  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df47  c7801001000000000000   -mov dword ptr [eax + 0x110], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = 0 /*0x0*/;
    // 0052df51  c7804001000000000000   -mov dword ptr [eax + 0x140], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(320) /* 0x140 */) = 0 /*0x0*/;
    // 0052df5b  39d0                   +cmp eax, edx
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
    // 0052df5d  75e5                   -jne 0x52df44
    if (!cpu.flags.zf)
    {
        goto L_0x0052df44;
    }
    // 0052df5f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df61  81c310050000           -add ebx, 0x510
    (cpu.ebx) += x86::reg32(x86::sreg32(1296 /*0x510*/));
L_0x0052df67:
    // 0052df67  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df6a  c7807001000000000000   -mov dword ptr [eax + 0x170], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = 0 /*0x0*/;
    // 0052df74  39d8                   +cmp eax, ebx
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
    // 0052df76  75ef                   -jne 0x52df67
    if (!cpu.flags.zf)
    {
        goto L_0x0052df67;
    }
    // 0052df78  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052df7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052df7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052df7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52df80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052df80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052df81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052df82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052df83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052df84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052df85  81ec30020000           -sub esp, 0x230
    (cpu.esp) -= x86::reg32(x86::sreg32(560 /*0x230*/));
    // 0052df8b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052df8d  89942414020000         -mov dword ptr [esp + 0x214], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.edx;
    // 0052df94  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052df9a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052df9f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052dfa1  e8caf3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dfa6  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052dfa9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052dfab  39c8                   +cmp eax, ecx
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
    // 0052dfad  0f838b020000           -jae 0x52e23e
    if (!cpu.flags.cf)
    {
        goto L_0x0052e23e;
    }
    // 0052dfb3  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0052dfb8:
    // 0052dfb8  d90495f4b15600         -fld dword ptr [edx*4 + 0x56b1f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681652) /* 0x56b1f4 */ + cpu.edx * 4)));
    // 0052dfbf  d8a614010000           -fsub dword ptr [esi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */));
    // 0052dfc5  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052dfcb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052dfd0  8d7e04                 -lea edi, [esi + 4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052dfd3  d99c24d8010000         -fstp dword ptr [esp + 0x1d8]
    app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dfda  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x0052dfdf:
    // 0052dfdf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052dfe1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052dfe3  e888f3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dfe8  d90485f4b15600         -fld dword ptr [eax*4 + 0x56b1f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681652) /* 0x56b1f4 */ + cpu.eax * 4)));
    // 0052dfef  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 0052dff5  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052dffb  41                     -inc ecx
    (cpu.ecx)++;
    // 0052dffc  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052dfff  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e006  83f904                 +cmp ecx, 4
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
    // 0052e009  7cd4                   -jl 0x52dfdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052dfdf;
    }
    // 0052e00b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052e010  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0052e015  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x0052e018:
    // 0052e018  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052e01a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e01c  e84ff3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e021  d9048534b25600         -fld dword ptr [eax*4 + 0x56b234]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681716) /* 0x56b234 */ + cpu.eax * 4)));
    // 0052e028  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 0052e02e  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052e034  41                     -inc ecx
    (cpu.ecx)++;
    // 0052e035  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e038  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e03f  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e042  7cd4                   -jl 0x52e018
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e018;
    }
    // 0052e044  bbd8000000             -mov ebx, 0xd8
    cpu.ebx = 216 /*0xd8*/;
    // 0052e049  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052e04b  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
L_0x0052e052:
    // 0052e052  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0052e057  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e059  e812f3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e05e  8b942420020000         -mov edx, dword ptr [esp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0052e065  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e067  8994242c020000         -mov dword ptr [esp + 0x22c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */) = cpu.edx;
    // 0052e06e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e070  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052e075  e8f6f2ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e07a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e07c  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 0052e083  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 0052e08a  dfac2408020000         -fild qword ptr [esp + 0x208]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(520) /* 0x208 */))));
    // 0052e091  dc0d24215500           -fmul qword ptr [0x552124]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579044) /* 0x552124 */));
    // 0052e097  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e099  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052e09e  d99c2424020000         -fstp dword ptr [esp + 0x224]
    app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e0a5  e8c6f2ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e0aa  8b448614               -mov eax, dword ptr [esi + eax*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4);
    // 0052e0ae  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052e0b1  89842428020000         -mov dword ptr [esp + 0x228], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 0052e0b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052e0ba  0f8585010000           -jne 0x52e245
    if (!cpu.flags.zf)
    {
        goto L_0x0052e245;
    }
    // 0052e0c0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052e0c5  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052e0c9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e0cb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e0cd  e856f3ffff             -call 0x52d428
    cpu.esp -= 4;
    sub_52d428(app, cpu);
    if (cpu.terminate) return;
L_0x0052e0d2:
    // 0052e0d2  8b94242c020000         -mov edx, dword ptr [esp + 0x22c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */);
    // 0052e0d9  8d0c3e                 -lea ecx, [esi + edi]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0052e0dc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052e0df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e0e1  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052e0e3  d9842428020000         -fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 0052e0ea  d9842424020000         -fld dword ptr [esp + 0x224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */)));
L_0x0052e0f1:
    // 0052e0f1  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0052e0f3  d88a74010000           -fmul dword ptr [edx + 0x174]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(372) /* 0x174 */));
    // 0052e0f9  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0052e0fb  d84c0414               -fmul dword ptr [esp + eax + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */ + cpu.eax * 1));
    // 0052e0ff  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e102  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e105  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052e107  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e10a  d99980060000           -fstp dword ptr [ecx + 0x680]
    app->getMemory<float>(cpu.ecx + x86::reg32(1664) /* 0x680 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e110  3db0010000             +cmp eax, 0x1b0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(432 /*0x1b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e115  75da                   -jne 0x52e0f1
    if (!cpu.flags.zf)
    {
        goto L_0x0052e0f1;
    }
    // 0052e117  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e119  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0052e120  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e122  83c36c                 -add ebx, 0x6c
    (cpu.ebx) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052e125  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052e127  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 0052e12e  81ffc0060000           +cmp edi, 0x6c0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1728 /*0x6c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e134  0f8518ffffff           -jne 0x52e052
    if (!cpu.flags.zf)
    {
        goto L_0x0052e052;
    }
    // 0052e13a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e13c  8d9610050000           -lea edx, [esi + 0x510]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1296) /* 0x510 */);
L_0x0052e142:
    // 0052e142  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e145  8b8830080000           -mov ecx, dword ptr [eax + 0x830]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2096) /* 0x830 */);
    // 0052e14b  898870010000           -mov dword ptr [eax + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 0052e151  39d0                   +cmp eax, edx
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
    // 0052e153  75ed                   -jne 0x52e142
    if (!cpu.flags.zf)
    {
        goto L_0x0052e142;
    }
    // 0052e155  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e157  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052e159:
    // 0052e159  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e15c  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 0052e163  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 0052e169  40                     -inc eax
    (cpu.eax)++;
    // 0052e16a  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e170  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e173  7ce4                   -jl 0x52e159
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e159;
    }
    // 0052e175  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e17c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e181  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e183  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e185  e84ef5ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e18a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e18c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052e18e:
    // 0052e18e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e191  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 0052e198  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 0052e19e  42                     -inc edx
    (cpu.edx)++;
    // 0052e19f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e1a5  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e1a8  7ce4                   -jl 0x52e18e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e18e;
    }
    // 0052e1aa  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e1b1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e1b6  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0052e1bb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1bd  e816f5ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e1c2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052e1c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052e1c6:
    // 0052e1c6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e1c9  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 0052e1d0  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 0052e1d6  40                     -inc eax
    (cpu.eax)++;
    // 0052e1d7  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e1dd  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e1e0  7ce4                   -jl 0x52e1c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e1c6;
    }
    // 0052e1e2  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e1e9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e1ee  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0052e1f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1f5  e8def4ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e1fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052e1fe:
    // 0052e1fe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e201  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 0052e208  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 0052e20e  42                     -inc edx
    (cpu.edx)++;
    // 0052e20f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e215  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e218  7ce4                   -jl 0x52e1fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e1fe;
    }
    // 0052e21a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e221  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0052e226  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0052e22b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e22d  e8a6f4ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e232  81c430020000           -add esp, 0x230
    (cpu.esp) += x86::reg32(x86::sreg32(560 /*0x230*/));
    // 0052e238  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e23e:
    // 0052e23e  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0052e240  e973fdffff             -jmp 0x52dfb8
    goto L_0x0052dfb8;
L_0x0052e245:
    // 0052e245  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052e24a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e24c  e81ff1ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e251  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052e256  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052e258  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 0052e25f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e261  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052e265  e806f1ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e26a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052e26d  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0052e274  898c241c020000         -mov dword ptr [esp + 0x21c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.ecx;
    // 0052e27b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e27d  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e27f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052e284  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e286  e89df1ffff             -call 0x52d428
    cpu.esp -= 4;
    sub_52d428(app, cpu);
    if (cpu.terminate) return;
    // 0052e28b  83bc241002000000       +cmp dword ptr [esp + 0x210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e293  7424                   -je 0x52e2b9
    if (cpu.flags.zf)
    {
        goto L_0x0052e2b9;
    }
    // 0052e295  8b94241c020000         -mov edx, dword ptr [esp + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 0052e29c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0052e29e  8d4218                 -lea eax, [edx + 0x18]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0052e2a1  81c2c8010000           -add edx, 0x1c8
    (cpu.edx) += x86::reg32(x86::sreg32(456 /*0x1c8*/));
L_0x0052e2a7:
    // 0052e2a7  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052e2aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e2ac  894c04f8               -mov dword ptr [esp + eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.ecx;
    // 0052e2b0  39d0                   +cmp eax, edx
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
    // 0052e2b2  75f3                   -jne 0x52e2a7
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2a7;
    }
    // 0052e2b4  e919feffff             -jmp 0x52e0d2
    goto L_0x0052e0d2;
L_0x0052e2b9:
    // 0052e2b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052e2bb:
    // 0052e2bb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e2be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e2c0  894c04fc               -mov dword ptr [esp + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 0052e2c4  83f814                 +cmp eax, 0x14
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
    // 0052e2c7  75f2                   -jne 0x52e2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2bb;
    }
    // 0052e2c9  b8c4010000             -mov eax, 0x1c4
    cpu.eax = 452 /*0x1c4*/;
L_0x0052e2ce:
    // 0052e2ce  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e2d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e2d3  895c04fc               -mov dword ptr [esp + eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ebx;
    // 0052e2d7  3dd8010000             +cmp eax, 0x1d8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(472 /*0x1d8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e2dc  75f0                   -jne 0x52e2ce
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2ce;
    }
    // 0052e2de  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0052e2e5  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0052e2e9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052e2ec  29d0                   +sub eax, edx
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
    // 0052e2ee  e8d9f2ffff             -call 0x52d5cc
    cpu.esp -= 4;
    sub_52d5cc(app, cpu);
    if (cpu.terminate) return;
    // 0052e2f3  d9842428020000         +fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 0052e2fa  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0052e2fc  dc0d2c215500           +fmul qword ptr [0x55212c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579052) /* 0x55212c */));
    // 0052e302  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e304  d99c2428020000         +fstp dword ptr [esp + 0x228]
    app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e30b  e9c2fdffff             -jmp 0x52e0d2
    goto L_0x0052e0d2;
}

/* align: skip  */
void Application::sub_52e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e311  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052e318  7421                   -je 0x52e33b
    if (cpu.flags.zf)
    {
        goto L_0x0052e33b;
    }
    // 0052e31a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e31c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e31e  8a9b11b2a000           -mov bl, byte ptr [ebx + 0xa0b211]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052e324  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052e327  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052e32d  740c                   -je 0x52e33b
    if (cpu.flags.zf)
    {
        goto L_0x0052e33b;
    }
    // 0052e32f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e331  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0052e333  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e336  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0052e339  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e33a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e33b:
    // 0052e33b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e33d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0052e33f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e340  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52e350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e353  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e356  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0052e358:
    // 0052e358  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052e35a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e35c  e85f6dffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052e361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e363  7531                   -jne 0x52e396
    if (!cpu.flags.zf)
    {
        goto L_0x0052e396;
    }
    // 0052e365  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e367  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052e369  e8c2090000             -call 0x52ed30
    cpu.esp -= 4;
    sub_52ed30(app, cpu);
    if (cpu.terminate) return;
    // 0052e36e  e8fd090000             -call 0x52ed70
    cpu.esp -= 4;
    sub_52ed70(app, cpu);
    if (cpu.terminate) return;
    // 0052e373  e8680a0000             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052e378  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e37a  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 0052e37c  e82fd2ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052e381  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052e384  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052e386  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e388  e883ffffff             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052e38d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e38f  e86c6dffff             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 0052e394  ebc2                   -jmp 0x52e358
    goto L_0x0052e358;
L_0x0052e396:
    // 0052e396  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e398  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e39b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52e3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e3a2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3a4  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e3a6  7541                   -jne 0x52e3e9
    if (!cpu.flags.zf)
    {
        goto L_0x0052e3e9;
    }
    // 0052e3a8  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052e3af  741f                   -je 0x52e3d0
    if (cpu.flags.zf)
    {
        goto L_0x0052e3d0;
    }
    // 0052e3b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e3b3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3b5  8a9b11b2a000           -mov bl, byte ptr [ebx + 0xa0b211]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052e3bb  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052e3be  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052e3c4  740a                   -je 0x52e3d0
    if (cpu.flags.zf)
    {
        goto L_0x0052e3d0;
    }
    // 0052e3c6  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052e3c9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e3cc  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e3ce  7505                   -jne 0x52e3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e3d5;
    }
L_0x0052e3d0:
    // 0052e3d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e3d5:
    // 0052e3d5  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0052e3d7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e3dc  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0052e3de  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e3e4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e3e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e3e9:
    // 0052e3e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e3eb  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3ef  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e3f1  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3f3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e3f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52e3f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e3f8  e9fd090000             -jmp 0x52edfa
    return sub_52edfa(app, cpu);
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e401  83f803                 +cmp eax, 3
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
    // 0052e404  7604                   -jbe 0x52e40a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052e40a;
    }
    // 0052e406  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e408  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e409  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e40a:
    // 0052e40a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e40c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052e40f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e411  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052e414  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052e416  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052e418  05586f5600             -add eax, 0x566f58
    (cpu.eax) += x86::reg32(x86::sreg32(5664600 /*0x566f58*/));
    // 0052e41d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e41e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52e420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e423  8b0dfc4f5600           -mov ecx, dword ptr [0x564ffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052e429  8b1df84f5600           -mov ebx, dword ptr [0x564ff8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052e42f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e431  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e433  e8c8090000             -call 0x52ee00
    cpu.esp -= 4;
    sub_52ee00(app, cpu);
    if (cpu.terminate) return;
    // 0052e438  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e43a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e43b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52e440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e444  81ecc8000000           -sub esp, 0xc8
    (cpu.esp) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0052e44a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052e44c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e44e  e8ed62fcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 0052e453  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e455  e80624fcff             -call 0x4f0860
    cpu.esp -= 4;
    sub_4f0860(app, cpu);
    if (cpu.terminate) return;
    // 0052e45a  8b1524725600           -mov edx, dword ptr [0x567224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */);
    // 0052e460  a120725600             -mov eax, dword ptr [0x567220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0052e465  8d8c24c4000000         -lea ecx, [esp + 0xc4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0052e46c  e8bf13fcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 0052e471  8d8424c0000000         -lea eax, [esp + 0xc0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0052e478  8d9c24b8000000         -lea ebx, [esp + 0xb8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0052e47f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052e480  8d9424c0000000         -lea edx, [esp + 0xc0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0052e487  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e489  e80228fcff             -call 0x4f0c90
    cpu.esp -= 4;
    sub_4f0c90(app, cpu);
    if (cpu.terminate) return;
    // 0052e48e  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0052e495  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0052e49c  8b1524725600           -mov edx, dword ptr [0x567224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */);
    // 0052e4a2  a1f8715600             -mov eax, dword ptr [0x5671f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 0052e4a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e4a8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e4aa  8b15fc715600           -mov edx, dword ptr [0x5671fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 0052e4b0  8b9c24c8000000         -mov ebx, dword ptr [esp + 0xc8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0052e4b7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e4b9  8b8c24c4000000         -mov ecx, dword ptr [esp + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0052e4c0  e87bf0fcff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052e4c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e4c7  e89462fcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 0052e4cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e4ce  e87d16fcff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
    // 0052e4d3  81c4c8000000           -add esp, 0xc8
    (cpu.esp) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0052e4d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52e4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e4e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e4e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052e4e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052e4e5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052e4e7  e86423fcff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 0052e4ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e4ee  e84dffffff             -call 0x52e440
    cpu.esp -= 4;
    sub_52e440(app, cpu);
    if (cpu.terminate) return;
    // 0052e4f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52e500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052e503  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e506  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052e50a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052e50e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052e510  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052e514  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052e516  7402                   -je 0x52e51a
    if (cpu.flags.zf)
    {
        goto L_0x0052e51a;
    }
    // 0052e518  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0052e51a:
    // 0052e51a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0052e51e:
    // 0052e51e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e520  fec0                   -inc al
    (cpu.al)++;
    // 0052e522  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e527  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0052e52e  7403                   -je 0x52e533
    if (cpu.flags.zf)
    {
        goto L_0x0052e533;
    }
    // 0052e530  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052e531  ebeb                   -jmp 0x52e51e
    goto L_0x0052e51e;
L_0x0052e533:
    // 0052e533  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e535  80fd2b                 +cmp ch, 0x2b
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
    // 0052e538  7405                   -je 0x52e53f
    if (cpu.flags.zf)
    {
        goto L_0x0052e53f;
    }
    // 0052e53a  80fd2d                 +cmp ch, 0x2d
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
    // 0052e53d  7501                   -jne 0x52e540
    if (!cpu.flags.zf)
    {
        goto L_0x0052e540;
    }
L_0x0052e53f:
    // 0052e53f  42                     -inc edx
    (cpu.edx)++;
L_0x0052e540:
    // 0052e540  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052e542  752c                   -jne 0x52e570
    if (!cpu.flags.zf)
    {
        goto L_0x0052e570;
    }
    // 0052e544  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e547  7514                   -jne 0x52e55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052e55d;
    }
    // 0052e549  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e54c  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e54f  7405                   -je 0x52e556
    if (cpu.flags.zf)
    {
        goto L_0x0052e556;
    }
    // 0052e551  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e554  7507                   -jne 0x52e55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052e55d;
    }
L_0x0052e556:
    // 0052e556  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0052e55b  eb33                   -jmp 0x52e590
    goto L_0x0052e590;
L_0x0052e55d:
    // 0052e55d  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e560  7507                   -jne 0x52e569
    if (!cpu.flags.zf)
    {
        goto L_0x0052e569;
    }
    // 0052e562  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0052e567  eb3c                   -jmp 0x52e5a5
    goto L_0x0052e5a5;
L_0x0052e569:
    // 0052e569  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 0052e56e  eb35                   -jmp 0x52e5a5
    goto L_0x0052e5a5;
L_0x0052e570:
    // 0052e570  83fe02                 +cmp esi, 2
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
    // 0052e573  7c05                   -jl 0x52e57a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e57a;
    }
    // 0052e575  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e578  7e11                   -jle 0x52e58b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052e58b;
    }
L_0x0052e57a:
    // 0052e57a  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0052e57f  e8fc42fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052e584  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052e586  e9c1000000             -jmp 0x52e64c
    goto L_0x0052e64c;
L_0x0052e58b:
    // 0052e58b  83fe10                 +cmp esi, 0x10
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
    // 0052e58e  7515                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
L_0x0052e590:
    // 0052e590  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e593  7510                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
    // 0052e595  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e598  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e59b  7405                   -je 0x52e5a2
    if (cpu.flags.zf)
    {
        goto L_0x0052e5a2;
    }
    // 0052e59d  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e5a0  7503                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
L_0x0052e5a2:
    // 0052e5a2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0052e5a5:
    // 0052e5a5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052e5a8  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0052e5af  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0052e5b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0052e5b3:
    // 0052e5b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e5b5  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e5b7  e8b4000000             -call 0x52e670
    cpu.esp -= 4;
    sub_52e670(app, cpu);
    if (cpu.terminate) return;
    // 0052e5bc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052e5be  39f0                   +cmp eax, esi
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
    // 0052e5c0  7d1a                   -jge 0x52e5dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052e5dc;
    }
    // 0052e5c2  3b9d48b65600           +cmp ebx, dword ptr [ebp + 0x56b648]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5682760) /* 0x56b648 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5c8  7602                   -jbe 0x52e5cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052e5cc;
    }
    // 0052e5ca  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x0052e5cc:
    // 0052e5cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e5ce  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052e5d1  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052e5d3  39c3                   +cmp ebx, eax
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
    // 0052e5d5  7302                   -jae 0x52e5d9
    if (!cpu.flags.cf)
    {
        goto L_0x0052e5d9;
    }
    // 0052e5d7  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x0052e5d9:
    // 0052e5d9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052e5da  ebd7                   -jmp 0x52e5b3
    goto L_0x0052e5b3;
L_0x0052e5dc:
    // 0052e5dc  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5df  7504                   -jne 0x52e5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5e5;
    }
    // 0052e5e1  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0052e5e5:
    // 0052e5e5  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052e5e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052e5eb  7402                   -je 0x52e5ef
    if (cpu.flags.zf)
    {
        goto L_0x0052e5ef;
    }
    // 0052e5ed  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x0052e5ef:
    // 0052e5ef  837c240801             +cmp dword ptr [esp + 8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5f4  750f                   -jne 0x52e605
    if (!cpu.flags.zf)
    {
        goto L_0x0052e605;
    }
    // 0052e5f6  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5fc  7207                   -jb 0x52e605
    if (cpu.flags.cf)
    {
        goto L_0x0052e605;
    }
    // 0052e5fe  7509                   -jne 0x52e609
    if (!cpu.flags.zf)
    {
        goto L_0x0052e609;
    }
    // 0052e600  80fd2d                 +cmp ch, 0x2d
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
    // 0052e603  7504                   -jne 0x52e609
    if (!cpu.flags.zf)
    {
        goto L_0x0052e609;
    }
L_0x0052e605:
    // 0052e605  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0052e607  743a                   -je 0x52e643
    if (cpu.flags.zf)
    {
        goto L_0x0052e643;
    }
L_0x0052e609:
    // 0052e609  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0052e60e  e86d42fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052e613  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0052e618  750c                   -jne 0x52e626
    if (!cpu.flags.zf)
    {
        goto L_0x0052e626;
    }
    // 0052e61a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e61f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e626:
    // 0052e626  80fd2d                 +cmp ch, 0x2d
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
    // 0052e629  750c                   -jne 0x52e637
    if (!cpu.flags.zf)
    {
        goto L_0x0052e637;
    }
    // 0052e62b  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 0052e630  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e636  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e637:
    // 0052e637  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 0052e63c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e63f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e640  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e642  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e643:
    // 0052e643  80fd2d                 +cmp ch, 0x2d
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
    // 0052e646  7502                   -jne 0x52e64a
    if (!cpu.flags.zf)
    {
        goto L_0x0052e64a;
    }
    // 0052e648  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0052e64a:
    // 0052e64a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052e64c:
    // 0052e64c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e64f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e650  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e651  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52e654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e654  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e655  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e657  e8a4feffff             -call 0x52e500
    cpu.esp -= 4;
    sub_52e500(app, cpu);
    if (cpu.terminate) return;
    // 0052e65c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e65d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52e660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e661  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052e666  e895feffff             -call 0x52e500
    cpu.esp -= 4;
    sub_52e500(app, cpu);
    if (cpu.terminate) return;
    // 0052e66b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e66c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52e670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e670  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e671  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e673  720e                   -jb 0x52e683
    if (cpu.flags.cf)
    {
        goto L_0x0052e683;
    }
    // 0052e675  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e677  770a                   -ja 0x52e683
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e683;
    }
    // 0052e679  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e67e  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0052e681  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e682  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e683:
    // 0052e683  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e688  e85324fcff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 0052e68d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e68f  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e691  720d                   -jb 0x52e6a0
    if (cpu.flags.cf)
    {
        goto L_0x0052e6a0;
    }
    // 0052e693  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e695  7709                   -ja 0x52e6a0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6a0;
    }
    // 0052e697  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e699  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0052e69b  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e69e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e69f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6a0:
    // 0052e6a0  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6a2  720e                   -jb 0x52e6b2
    if (cpu.flags.cf)
    {
        goto L_0x0052e6b2;
    }
    // 0052e6a4  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6a6  770a                   -ja 0x52e6b2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6b2;
    }
    // 0052e6a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e6ad  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e6b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6b2:
    // 0052e6b2  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6b4  720e                   -jb 0x52e6c4
    if (cpu.flags.cf)
    {
        goto L_0x0052e6c4;
    }
    // 0052e6b6  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6b8  770a                   -ja 0x52e6c4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6c4;
    }
    // 0052e6ba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e6bf  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e6c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6c4:
    // 0052e6c4  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 0052e6c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52e6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e6d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e6d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e6d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e6d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052e6d6  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e6d9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052e6db  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052e6e0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e6e5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052e6e8  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 0052e6ed  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052e6f1  e86a070000             -call 0x52ee60
    cpu.esp -= 4;
    sub_52ee60(app, cpu);
    if (cpu.terminate) return;
    // 0052e6f6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052e6f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e6fa  750a                   -jne 0x52e706
    if (!cpu.flags.zf)
    {
        goto L_0x0052e706;
    }
    // 0052e6fc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e701  e97c010000             -jmp 0x52e882
    goto L_0x0052e882;
L_0x0052e706:
    // 0052e706  39e8                   +cmp eax, ebp
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
    // 0052e708  750f                   -jne 0x52e719
    if (!cpu.flags.zf)
    {
        goto L_0x0052e719;
    }
    // 0052e70a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e70f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e712  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e713  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e715  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e716  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e717  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e718  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e719:
    // 0052e719  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052e71b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052e71f  40                     -inc eax
    (cpu.eax)++;
    // 0052e720  e8db91fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052e725  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e727  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052e72b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e72d  750f                   -jne 0x52e73e
    if (!cpu.flags.zf)
    {
        goto L_0x0052e73e;
    }
    // 0052e72f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e734  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e737  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e739  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e73a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e73b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e73c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e73d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e73e:
    // 0052e73e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052e742  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0052e744  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052e746  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052e747  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052e749  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052e74b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e74c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e74e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052e751  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052e753  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052e755  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052e758  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052e75a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e75b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052e75c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052e760  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052e763  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 0052e767  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e769  e8e298feff             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 0052e76e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052e772  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e774  744b                   -je 0x52e7c1
    if (cpu.flags.zf)
    {
        goto L_0x0052e7c1;
    }
    // 0052e776  40                     -inc eax
    (cpu.eax)++;
    // 0052e777  e88491fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052e77c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052e77e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052e782  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e784  7516                   -jne 0x52e79c
    if (!cpu.flags.zf)
    {
        goto L_0x0052e79c;
    }
    // 0052e786  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052e788  e86392fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052e78d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e792  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e795  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e796  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e797  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e798  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e799  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e79a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e79b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e79c:
    // 0052e79c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052e7a0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052e7a2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052e7a3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052e7a5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052e7a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e7a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e7aa  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052e7ad  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052e7af  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052e7b1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052e7b4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052e7b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7b7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052e7b8  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052e7bc  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 0052e7bf  eb04                   -jmp 0x52e7c5
    goto L_0x0052e7c5;
L_0x0052e7c1:
    // 0052e7c1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0052e7c5:
    // 0052e7c5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052e7c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052e7ca  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052e7ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e7cf  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052e7d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e7d8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052e7dc  e80f92fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052e7e1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052e7e5  e80692fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052e7ea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052e7ec  750f                   -jne 0x52e7fd
    if (!cpu.flags.zf)
    {
        goto L_0x0052e7fd;
    }
    // 0052e7ee  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e7f3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e7f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e7fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e7fd:
    // 0052e7fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052e7ff  e888000000             -call 0x52e88c
    cpu.esp -= 4;
    sub_52e88c(app, cpu);
    if (cpu.terminate) return;
    // 0052e804  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e806  740f                   -je 0x52e817
    if (cpu.flags.zf)
    {
        goto L_0x0052e817;
    }
    // 0052e808  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e80d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e810  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e811  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e812  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e813  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e814  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e815  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e816  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e817:
    // 0052e817  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
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
    // 0052e81e  7462                   -je 0x52e882
    if (cpu.flags.zf)
    {
        goto L_0x0052e882;
    }
    // 0052e820  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052e822  e82998feff             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 0052e827  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052e82a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052e82d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0052e830  e8cb90fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052e835  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052e837  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e839  7519                   -jne 0x52e854
    if (!cpu.flags.zf)
    {
        goto L_0x0052e854;
    }
    // 0052e83b  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0052e840  e84727fdff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 0052e845  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e84a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e84d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e84e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e84f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e850  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e851  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e852  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e853  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e854:
    // 0052e854  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052e859  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e85b  e82098feff             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 0052e860  83f8ff                 +cmp eax, -1
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
    // 0052e863  7516                   -jne 0x52e87b
    if (!cpu.flags.zf)
    {
        goto L_0x0052e87b;
    }
    // 0052e865  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e867  e88491fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052e86c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e871  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e874  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e875  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e877  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e878  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e879  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e87a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e87b:
    // 0052e87b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e87d  e8f6d8ffff             -call 0x52c178
    cpu.esp -= 4;
    sub_52c178(app, cpu);
    if (cpu.terminate) return;
L_0x0052e882:
    // 0052e882  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052e885  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e886  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e887  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e888  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e889  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e88a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e88b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52e88c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e88c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e88d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e88e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e88f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e890  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e891  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052e892  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052e895  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052e899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e89b  750a                   -jne 0x52e8a7
    if (!cpu.flags.zf)
    {
        goto L_0x0052e8a7;
    }
    // 0052e89d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e8a2  e989010000             -jmp 0x52ea30
    goto L_0x0052ea30;
L_0x0052e8a7:
    // 0052e8a7  803800                 +cmp byte ptr [eax], 0
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
    // 0052e8aa  7415                   -je 0x52e8c1
    if (cpu.flags.zf)
    {
        goto L_0x0052e8c1;
    }
    // 0052e8ac  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052e8af  803a00                 +cmp byte ptr [edx], 0
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
    // 0052e8b2  740d                   -je 0x52e8c1
    if (cpu.flags.zf)
    {
        goto L_0x0052e8c1;
    }
L_0x0052e8b4:
    // 0052e8b4  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e8b7  7408                   -je 0x52e8c1
    if (cpu.flags.zf)
    {
        goto L_0x0052e8c1;
    }
    // 0052e8b9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e8bc  42                     -inc edx
    (cpu.edx)++;
    // 0052e8bd  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0052e8bf  75f3                   -jne 0x52e8b4
    if (!cpu.flags.zf)
    {
        goto L_0x0052e8b4;
    }
L_0x0052e8c1:
    // 0052e8c1  803a00                 +cmp byte ptr [edx], 0
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
    // 0052e8c4  750f                   -jne 0x52e8d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e8d5;
    }
    // 0052e8c6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e8cb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052e8ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e8d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e8d5:
    // 0052e8d5  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 0052e8d9  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0052e8dc  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 0052e8df  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052e8e4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052e8e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e8ea  7541                   -jne 0x52e92d
    if (!cpu.flags.zf)
    {
        goto L_0x0052e92d;
    }
    // 0052e8ec  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052e8ee  0f853c010000           -jne 0x52ea30
    if (!cpu.flags.zf)
    {
        goto L_0x0052ea30;
    }
    // 0052e8f4  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0052e8f9  e80290fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052e8fe  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052e902  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e904  750f                   -jne 0x52e915
    if (!cpu.flags.zf)
    {
        goto L_0x0052e915;
    }
    // 0052e906  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e90b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052e90e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e90f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e910  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e913  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e914  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e915:
    // 0052e915  a354b1a000             -mov dword ptr [0xa0b154], eax
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.eax;
    // 0052e91a  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052e91d  8968f8                 -mov dword ptr [eax - 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebp;
    // 0052e920  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 0052e923  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052e928  e9e5000000             -jmp 0x52ea12
    goto L_0x0052ea12;
L_0x0052e92d:
    // 0052e92d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052e931  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e933  e804010000             -call 0x52ea3c
    cpu.esp -= 4;
    sub_52ea3c(app, cpu);
    if (cpu.terminate) return;
    // 0052e938  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052e93a  0f85ee000000           -jne 0x52ea2e
    if (!cpu.flags.zf)
    {
        goto L_0x0052ea2e;
    }
    // 0052e940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e942  0f8fc7000000           -jg 0x52ea0f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ea0f;
    }
    // 0052e948  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052e94a  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0052e94c  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052e94f  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 0052e956  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0052e959  8b3550b1a000           -mov esi, dword ptr [0xa0b150]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052e95f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052e962  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e964  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052e966  754f                   -jne 0x52e9b7
    if (!cpu.flags.zf)
    {
        goto L_0x0052e9b7;
    }
    // 0052e968  e8938ffcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052e96d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e96f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052e973  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e975  750f                   -jne 0x52e986
    if (!cpu.flags.zf)
    {
        goto L_0x0052e986;
    }
    // 0052e977  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e97c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052e97f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e980  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e981  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e982  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e983  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e984  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e985  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e986:
    // 0052e986  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052e98c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052e98e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052e98f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052e991  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052e993  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e994  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e996  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052e999  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052e99b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052e99d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052e9a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052e9a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9a3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052e9a4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052e9a7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052e9a9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052e9ab  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052e9b0  e88b1cfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052e9b5  eb3c                   -jmp 0x52e9f3
    goto L_0x0052e9f3;
L_0x0052e9b7:
    // 0052e9b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e9b9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052e9bd  e8fe9bfeff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0052e9c2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052e9c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e9c8  750f                   -jne 0x52e9d9
    if (!cpu.flags.zf)
    {
        goto L_0x0052e9d9;
    }
    // 0052e9ca  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e9cf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052e9d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e9d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e9d9:
    // 0052e9d9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052e9dc  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052e9e2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052e9e4  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052e9e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e9e8  e8539cfeff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052e9ed  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
L_0x0052e9f3:
    // 0052e9f3  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052e9f7  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0052e9fe  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052ea00  893d54b1a000           -mov dword ptr [0xa0b154], edi
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edi;
    // 0052ea06  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052ea0d  eb03                   -jmp 0x52ea12
    goto L_0x0052ea12;
L_0x0052ea0f:
    // 0052ea0f  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0052ea12:
    // 0052ea12  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ea16  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0052ea1d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ea1f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052ea23  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052ea25  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052ea2a  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x0052ea2e:
    // 0052ea2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052ea30:
    // 0052ea30  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ea33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ea39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52ea3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ea3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ea3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ea3e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ea3f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ea40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ea41  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052ea43  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052ea45  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052ea4b  e9cb000000             -jmp 0x52eb1b
    goto L_0x0052eb1b;
L_0x0052ea50:
    // 0052ea50  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 0052ea52  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052ea54  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052ea56  0f84bc000000           -je 0x52eb18
    if (cpu.flags.zf)
    {
        goto L_0x0052eb18;
    }
L_0x0052ea5c:
    // 0052ea5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ea5e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052ea60  e87b03fcff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ea65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052ea67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ea69  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0052ea6b  e87003fcff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ea70  39c1                   +cmp ecx, eax
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
    // 0052ea72  0f85a0000000           -jne 0x52eb18
    if (!cpu.flags.zf)
    {
        goto L_0x0052eb18;
    }
    // 0052ea78  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052ea7b  0f858a000000           -jne 0x52eb0b
    if (!cpu.flags.zf)
    {
        goto L_0x0052eb0b;
    }
    // 0052ea81  8b1554b1a000           -mov edx, dword ptr [0xa0b154]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052ea87  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0052ea89  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ea8b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0052ea8e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ea90  0f846c000000           -je 0x52eb02
    if (cpu.flags.zf)
    {
        goto L_0x0052eb02;
    }
    // 0052ea96  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052ea98  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052ea9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ea9c  740f                   -je 0x52eaad
    if (cpu.flags.zf)
    {
        goto L_0x0052eaad;
    }
L_0x0052ea9e:
    // 0052ea9e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052eaa1  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052eaa3  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052eaa6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052eaa9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052eaab  75f1                   -jne 0x52ea9e
    if (!cpu.flags.zf)
    {
        goto L_0x0052ea9e;
    }
L_0x0052eaad:
    // 0052eaad  8b3550b1a000           -mov esi, dword ptr [0xa0b150]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052eab3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052eab5  7443                   -je 0x52eafa
    if (cpu.flags.zf)
    {
        goto L_0x0052eafa;
    }
    // 0052eab7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052eab9  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052eabd  7407                   -je 0x52eac6
    if (cpu.flags.zf)
    {
        goto L_0x0052eac6;
    }
    // 0052eabf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052eac1  e82a8ffcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052eac6:
    // 0052eac6  8b2d54b1a000           -mov ebp, dword ptr [0xa0b154]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052eacc  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052eace  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052ead0  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052ead6  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 0052ead9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052eadb  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052eadd  e85e9bfeff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052eae2  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 0052eae8  39f7                   +cmp edi, esi
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
    // 0052eaea  7d0e                   -jge 0x52eafa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052eafa;
    }
    // 0052eaec  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x0052eaef:
    // 0052eaef  40                     -inc eax
    (cpu.eax)++;
    // 0052eaf0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052eaf2  47                     -inc edi
    (cpu.edi)++;
    // 0052eaf3  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0052eaf6  39f7                   +cmp edi, esi
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
    // 0052eaf8  7cf5                   -jl 0x52eaef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052eaef;
    }
L_0x0052eafa:
    // 0052eafa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052eafc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eafd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eafe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eaff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052eb02:
    // 0052eb02  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0052eb05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052eb0b:
    // 0052eb0b  42                     -inc edx
    (cpu.edx)++;
    // 0052eb0c  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052eb0f  43                     -inc ebx
    (cpu.ebx)++;
    // 0052eb10  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0052eb12  0f8544ffffff           -jne 0x52ea5c
    if (!cpu.flags.zf)
    {
        goto L_0x0052ea5c;
    }
L_0x0052eb18:
    // 0052eb18  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052eb1b:
    // 0052eb1b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052eb1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052eb1f  0f852bffffff           -jne 0x52ea50
    if (!cpu.flags.zf)
    {
        goto L_0x0052ea50;
    }
    // 0052eb25  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052eb2a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052eb2c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0052eb2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52eb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eb40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052eb41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052eb42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052eb43  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0052eb46  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052eb48  6639ca                 +cmp dx, cx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052eb4b  7416                   -je 0x52eb63
    if (cpu.flags.zf)
    {
        goto L_0x0052eb63;
    }
L_0x0052eb4d:
    // 0052eb4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052eb4f  668b3a                 -mov di, word ptr [edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx);
    // 0052eb52  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052eb55  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 0052eb58  7407                   -je 0x52eb61
    if (cpu.flags.zf)
    {
        goto L_0x0052eb61;
    }
    // 0052eb5a  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052eb5d  7404                   -je 0x52eb63
    if (cpu.flags.zf)
    {
        goto L_0x0052eb63;
    }
    // 0052eb5f  ebec                   -jmp 0x52eb4d
    goto L_0x0052eb4d;
L_0x0052eb61:
    // 0052eb61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052eb63:
    // 0052eb63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eb66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52eb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052eb71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052eb72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052eb73  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052eb74  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0052eb76  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0052eb78  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052eb79  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052eb7b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052eb7e  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052eb81  8b1520649f00           -mov edx, dword ptr [0x9f6420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */);
    // 0052eb87  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052eb89  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052eb8c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052eb8f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052eb91  7531                   -jne 0x52ebc4
    if (!cpu.flags.zf)
    {
        goto L_0x0052ebc4;
    }
    // 0052eb93  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052eb98  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0052eb9b  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0052eb9d  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052eb9f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0052eba1  8b1d70af5600           -mov ebx, dword ptr [0x56af70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052eba7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052eba9  e8921afbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052ebae  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052ebb3  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 0052ebb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ebbb  e8c8fcfeff             -call 0x51e888
    cpu.esp -= 4;
    sub_51e888(app, cpu);
    if (cpu.terminate) return;
    // 0052ebc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ebc2  7431                   -je 0x52ebf5
    if (cpu.flags.zf)
    {
        goto L_0x0052ebf5;
    }
L_0x0052ebc4:
    // 0052ebc4  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebca  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052ebcd  05de000000             -add eax, 0xde
    (cpu.eax) += x86::reg32(x86::sreg32(222 /*0xde*/));
    // 0052ebd2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ebd3  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052ebd6  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebdd  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0052ebe0  e8eb04ffff             -call 0x51f0d0
    cpu.esp -= 4;
    sub_51f0d0(app, cpu);
    if (cpu.terminate) return;
    // 0052ebe5  ff15a4775600           -call dword ptr [0x5677a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666724) /* 0x5677a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebeb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052ebed  ff55fc                 -call dword ptr [ebp - 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebf0  e827dcffff             -call 0x52c81c
    cpu.esp -= 4;
    sub_52c81c(app, cpu);
    if (cpu.terminate) return;
L_0x0052ebf5:
    // 0052ebf5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052ebf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebf8  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfa  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ec00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ec04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ec04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ec05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ec06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ec07  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052ec08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ec09  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052ec0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052ec0e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052ec10  833d60775600ff         +cmp dword ptr [0x567760], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ec17  7512                   -jne 0x52ec2b
    if (!cpu.flags.zf)
    {
        goto L_0x0052ec2b;
    }
    // 0052ec19  e80afcfeff             -call 0x51e828
    cpu.esp -= 4;
    sub_51e828(app, cpu);
    if (cpu.terminate) return;
    // 0052ec1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ec20  0f84be000000           -je 0x52ece4
    if (cpu.flags.zf)
    {
        goto L_0x0052ece4;
    }
    // 0052ec26  e839fdfeff             -call 0x51e964
    cpu.esp -= 4;
    sub_51e964(app, cpu);
    if (cpu.terminate) return;
L_0x0052ec2b:
    // 0052ec2b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0052ec2d  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052ec31  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0052ec35  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec3c  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0052ec40  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052ec42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ec44  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052ec46  be34215500             -mov esi, 0x552134
    cpu.esi = 5579060 /*0x552134*/;
    // 0052ec4b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0052ec4f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052ec54  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052ec55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052ec56  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052ec57  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec5e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ec62  e885f4feff             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 0052ec67  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ec69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec6a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec6c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec70  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec77  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0052ec7b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0052ec7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec80  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec82  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0052ec86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec87  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0052ec8d  6870eb5200             -push 0x52eb70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5434224 /*0x52eb70*/;
    cpu.esp -= 4;
    // 0052ec92  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0052ec98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ec99  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec9b  2eff15a4445300         -call dword ptr cs:[0x5344a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457060) /* 0x5344a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052eca2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052eca4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052eca6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eca8  750a                   -jne 0x52ecb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052ecb4;
    }
    // 0052ecaa  c7442434ffffffff       -mov dword ptr [esp + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 0052ecb2  eb22                   -jmp 0x52ecd6
    goto L_0x0052ecd6;
L_0x0052ecb4:
    // 0052ecb4  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0052ecb6  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0052ecba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ecbb  2eff1534465300         -call dword ptr cs:[0x534634]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457460) /* 0x534634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ecc2  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0052ecc6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052ecc8  7404                   -je 0x52ecce
    if (cpu.flags.zf)
    {
        goto L_0x0052ecce;
    }
    // 0052ecca  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0052eccc  eb08                   -jmp 0x52ecd6
    goto L_0x0052ecd6;
L_0x0052ecce:
    // 0052ecce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052eccf  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ecd6:
    // 0052ecd6  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0052ecda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ecdb  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ece2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0052ece4:
    // 0052ece4  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052ece7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ece8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ece9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ecea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ecec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ecf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ecf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ecf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ecf2  ff15a8775600           -call dword ptr [0x5677a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666728) /* 0x5677a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ecf8  e81f04ffff             -call 0x51f11c
    cpu.esp -= 4;
    sub_51f11c(app, cpu);
    if (cpu.terminate) return;
    // 0052ecfd  833d20649f0000         +cmp dword ptr [0x9f6420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ed04  750a                   -jne 0x52ed10
    if (!cpu.flags.zf)
    {
        goto L_0x0052ed10;
    }
    // 0052ed06  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ed0b  e8ccfbfeff             -call 0x51e8dc
    cpu.esp -= 4;
    sub_51e8dc(app, cpu);
    if (cpu.terminate) return;
L_0x0052ed10:
    // 0052ed10  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ed12  2eff15c4445300         -call dword ptr cs:[0x5344c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457092) /* 0x5344c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ed19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52ed20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed20  ff1553785600           -call dword ptr [0x567853]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666899) /* 0x567853 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ed26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ed30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ed31  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ed38  7428                   -je 0x52ed62
    if (cpu.flags.zf)
    {
        goto L_0x0052ed62;
    }
    // 0052ed3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed3c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed3e  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052ed44  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052ed47  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052ed4d  7413                   -je 0x52ed62
    if (cpu.flags.zf)
    {
        goto L_0x0052ed62;
    }
    // 0052ed4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed51  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed53  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052ed56  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052ed59  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ed5e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ed62:
    // 0052ed62  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed64  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ed69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ed71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ed72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ed73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ed76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ed78  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ed7a  e861000000             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ed7f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ed81  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052ed83  e828c8ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052ed88  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052ed8b  813db8b05600a4030000   +cmp dword ptr [0x56b0b8], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ed95  7526                   -jne 0x52edbd
    if (!cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052ed97  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ed9e  741d                   -je 0x52edbd
    if (cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052eda0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052eda2  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0052eda5  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052edab  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052edad  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052edb2  7409                   -je 0x52edbd
    if (cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052edb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052edb6  e805010000             -call 0x52eec0
    cpu.esp -= 4;
    sub_52eec0(app, cpu);
    if (cpu.terminate) return;
    // 0052edbb  eb15                   -jmp 0x52edd2
    goto L_0x0052edd2;
L_0x0052edbd:
    // 0052edbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052edbf  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052edc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052edc4  2eff15fc465300         -call dword ptr cs:[0x5346fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457660) /* 0x5346fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052edcb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052edcd  e85effffff             -call 0x52ed30
    cpu.esp -= 4;
    sub_52ed30(app, cpu);
    if (cpu.terminate) return;
L_0x0052edd2:
    // 0052edd2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052edd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ede0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ede1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ede3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ede5  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 0052ede8  740c                   -je 0x52edf6
    if (cpu.flags.zf)
    {
        goto L_0x0052edf6;
    }
    // 0052edea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052edec  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0052edef  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052edf2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0052edf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052edf6:
    // 0052edf6  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0052edf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52edfa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052edfa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052edfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52ee00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ee00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ee01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee03  7c49                   -jl 0x52ee4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee4e;
    }
L_0x0052ee05:
    // 0052ee05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052ee07  7c49                   -jl 0x52ee52
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee52;
    }
L_0x0052ee09:
    // 0052ee09  8b35f84f5600           -mov esi, dword ptr [0x564ff8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052ee0f  39f0                   +cmp eax, esi
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
    // 0052ee11  7e02                   -jle 0x52ee15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee15;
    }
    // 0052ee13  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0052ee15:
    // 0052ee15  39f3                   +cmp ebx, esi
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
    // 0052ee17  7e02                   -jle 0x52ee1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee1b;
    }
    // 0052ee19  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0052ee1b:
    // 0052ee1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ee1d  7c37                   -jl 0x52ee56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee56;
    }
L_0x0052ee1f:
    // 0052ee1f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052ee21  7c37                   -jl 0x52ee5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee5a;
    }
L_0x0052ee23:
    // 0052ee23  8b35fc4f5600           -mov esi, dword ptr [0x564ffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052ee29  39f2                   +cmp edx, esi
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
    // 0052ee2b  7e02                   -jle 0x52ee2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee2f;
    }
    // 0052ee2d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052ee2f:
    // 0052ee2f  39f1                   +cmp ecx, esi
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
    // 0052ee31  7e02                   -jle 0x52ee35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee35;
    }
    // 0052ee33  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052ee35:
    // 0052ee35  891d08505600           -mov dword ptr [0x565008], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */) = cpu.ebx;
    // 0052ee3b  891504505600           -mov dword ptr [0x565004], edx
    app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */) = cpu.edx;
    // 0052ee41  890d0c505600           -mov dword ptr [0x56500c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */) = cpu.ecx;
    // 0052ee47  a300505600             -mov dword ptr [0x565000], eax
    app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */) = cpu.eax;
    // 0052ee4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ee4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ee4e:
    // 0052ee4e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052ee50  ebb3                   -jmp 0x52ee05
    goto L_0x0052ee05;
L_0x0052ee52:
    // 0052ee52  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052ee54  ebb3                   -jmp 0x52ee09
    goto L_0x0052ee09;
L_0x0052ee56:
    // 0052ee56  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052ee58  ebc5                   -jmp 0x52ee1f
    goto L_0x0052ee1f;
L_0x0052ee5a:
    // 0052ee5a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052ee5c  ebc5                   -jmp 0x52ee23
    goto L_0x0052ee23;
}

/* align: skip 0x00 0x00 */
void Application::sub_52ee60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ee60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ee61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ee62  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ee65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ee67  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052ee69  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ee6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ee6d  e86effffff             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee72  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ee74  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052ee76  e835c7ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee7b  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x0052ee7e:
    // 0052ee7e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee80  e83b62ffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee87  7518                   -jne 0x52eea1
    if (!cpu.flags.zf)
    {
        goto L_0x0052eea1;
    }
    // 0052ee89  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ee8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee8d  e80ef5ffff             -call 0x52e3a0
    cpu.esp -= 4;
    sub_52e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee94  740b                   -je 0x52eea1
    if (cpu.flags.zf)
    {
        goto L_0x0052eea1;
    }
    // 0052ee96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee98  e86362ffff             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 0052ee9d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ee9f  ebdd                   -jmp 0x52ee7e
    goto L_0x0052ee7e;
L_0x0052eea1:
    // 0052eea1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052eea3  e81862ffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052eea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeaa  7404                   -je 0x52eeb0
    if (cpu.flags.zf)
    {
        goto L_0x0052eeb0;
    }
    // 0052eeac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052eeae  7504                   -jne 0x52eeb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052eeb4;
    }
L_0x0052eeb0:
    // 0052eeb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052eeb2  eb02                   -jmp 0x52eeb6
    goto L_0x0052eeb6;
L_0x0052eeb4:
    // 0052eeb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052eeb6:
    // 0052eeb6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052eeb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eeba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52eec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eec0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052eec1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052eec3  e818000000             -call 0x52eee0
    cpu.esp -= 4;
    sub_52eee0(app, cpu);
    if (cpu.terminate) return;
    // 0052eec8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeca  7403                   -je 0x52eecf
    if (cpu.flags.zf)
    {
        goto L_0x0052eecf;
    }
    // 0052eecc  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x0052eecf:
    // 0052eecf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052eed1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52eee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052eee1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052eee3  e848000000             -call 0x52ef30
    cpu.esp -= 4;
    sub_52ef30(app, cpu);
    if (cpu.terminate) return;
    // 0052eee8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeea  741f                   -je 0x52ef0b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef0b;
    }
    // 0052eeec  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052eef2  7211                   -jb 0x52ef05
    if (cpu.flags.cf)
    {
        goto L_0x0052ef05;
    }
    // 0052eef4  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052eefa  7709                   -ja 0x52ef05
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052ef05;
    }
    // 0052eefc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052ef01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef05:
    // 0052ef05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ef07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef0b:
    // 0052ef0b  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0052ef0d  fec0                   -inc al
    (cpu.al)++;
    // 0052ef0f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef14  8a80f04e5600           -mov al, byte ptr [eax + 0x564ef0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */);
    // 0052ef1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ef1c  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0052ef1e  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0052ef20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ef30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ef31  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ef38  7431                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052ef3c  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052ef3f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef45  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052ef4b  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052ef4e  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052ef54  7415                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef56  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef5b  e810000000             -call 0x52ef70
    cpu.esp -= 4;
    sub_52ef70(app, cpu);
    if (cpu.terminate) return;
    // 0052ef60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ef62  7407                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef64  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ef69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef6b:
    // 0052ef6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ef6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ef70  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ef77  7429                   -je 0x52efa2
    if (cpu.flags.zf)
    {
        goto L_0x0052efa2;
    }
    // 0052ef79  813db8b05600a4030000   +cmp dword ptr [0x56b0b8], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ef83  740a                   -je 0x52ef8f
    if (cpu.flags.zf)
    {
        goto L_0x0052ef8f;
    }
    // 0052ef85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ef87  741b                   -je 0x52efa4
    if (cpu.flags.zf)
    {
        goto L_0x0052efa4;
    }
    // 0052ef89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ef8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef8f:
    // 0052ef8f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef94  8a80ddb65600           -mov al, byte ptr [eax + 0x56b6dd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5682909) /* 0x56b6dd */);
    // 0052ef9a  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0052ef9c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052efa1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052efa2:
    // 0052efa2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052efa4:
    // 0052efa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 68b956000000000003ffff000000000058b956000400000003ffff000000000048b956000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff80000000001800000010000000020000001000000007000000b0ef5200000000000000000068b956000000000003ffff800001000058b956000400000003ffff800001000048b956000800000003ffff8000010000c8b956000c00000003ffff8000010000b8b956001000000003ffff8000010000a8b956001400000003ffff800001000098b956001800000003ffff800001000098b956001c00000003ffff800001000088b956002000000010ffff800000000088b956002400000010ffff800000000088b956002800000010ffff800000000088b956002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c00000040f05200 */
void Application::sub_52f318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f318  833d2cd1560000         +cmp dword ptr [0x56d12c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f31f  751e                   -jne 0x52f33f
    if (!cpu.flags.zf)
    {
        goto L_0x0052f33f;
    }
    // 0052f321  68d8b95600             -push 0x56b9d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683672 /*0x56b9d8*/;
    cpu.esp -= 4;
    // 0052f326  ff158c455300           -call dword ptr [0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052f32c  a32cd15600             -mov dword ptr [0x56d12c], eax
    app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */) = cpu.eax;
    // 0052f331  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f333  750a                   -jne 0x52f33f
    if (!cpu.flags.zf)
    {
        goto L_0x0052f33f;
    }
    // 0052f335  c7052cd15600ffffffff   -mov dword ptr [0x56d12c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */) = 4294967295 /*0xffffffff*/;
L_0x0052f33f:
    // 0052f33f  833d2cd15600ff         +cmp dword ptr [0x56d12c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f346  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f34b  7420                   -je 0x52f36d
    if (cpu.flags.zf)
    {
        goto L_0x0052f36d;
    }
    // 0052f34d  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f351  ff352cd15600           -push dword ptr [0x56d12c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
    cpu.esp -= 4;
    // 0052f357  ff1558455300           -call dword ptr [0x534558]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052f35d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052f361  83f801                 +cmp eax, 1
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
    // 0052f364  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052f366  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0052f368  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x0052f36d:
    // 0052f36d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f370  833d34d1560000         +cmp dword ptr [0x56d134], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f377  751f                   -jne 0x52f398
    if (!cpu.flags.zf)
    {
        goto L_0x0052f398;
    }
    // 0052f379  6834d15600             -push 0x56d134
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689652 /*0x56d134*/;
    cpu.esp -= 4;
    // 0052f37e  68e4b95600             -push 0x56b9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683684 /*0x56b9e4*/;
    cpu.esp -= 4;
    // 0052f383  e890ffffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f38a  740c                   -je 0x52f398
    if (cpu.flags.zf)
    {
        goto L_0x0052f398;
    }
    // 0052f38c  c70534d15600ffffffff   -mov dword ptr [0x56d134], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */) = 4294967295 /*0xffffffff*/;
    // 0052f396  eb20                   -jmp 0x52f3b8
    goto L_0x0052f3b8;
L_0x0052f398:
    // 0052f398  833d34d15600ff         +cmp dword ptr [0x56d134], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f39f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f3a4  7412                   -je 0x52f3b8
    if (cpu.flags.zf)
    {
        goto L_0x0052f3b8;
    }
    // 0052f3a6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3aa  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3ae  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3b2  ff1534d15600           -call dword ptr [0x56d134]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f3b8:
    // 0052f3b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f3bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f3bb  833d38d1560000         +cmp dword ptr [0x56d138], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f3c2  751f                   -jne 0x52f3e3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f3e3;
    }
    // 0052f3c4  6838d15600             -push 0x56d138
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689656 /*0x56d138*/;
    cpu.esp -= 4;
    // 0052f3c9  68f0b95600             -push 0x56b9f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683696 /*0x56b9f0*/;
    cpu.esp -= 4;
    // 0052f3ce  e845ffffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f3d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f3d5  740c                   -je 0x52f3e3
    if (cpu.flags.zf)
    {
        goto L_0x0052f3e3;
    }
    // 0052f3d7  c70538d15600ffffffff   -mov dword ptr [0x56d138], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */) = 4294967295 /*0xffffffff*/;
    // 0052f3e1  eb20                   -jmp 0x52f403
    goto L_0x0052f403;
L_0x0052f3e3:
    // 0052f3e3  833d38d15600ff         +cmp dword ptr [0x56d138], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f3ea  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f3ef  7412                   -je 0x52f403
    if (cpu.flags.zf)
    {
        goto L_0x0052f403;
    }
    // 0052f3f1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3f5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3f9  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3fd  ff1538d15600           -call dword ptr [0x56d138]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f403:
    // 0052f403  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f406(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f406  833d3cd1560000         +cmp dword ptr [0x56d13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f40d  751f                   -jne 0x52f42e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f42e;
    }
    // 0052f40f  683cd15600             -push 0x56d13c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689660 /*0x56d13c*/;
    cpu.esp -= 4;
    // 0052f414  6800ba5600             -push 0x56ba00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683712 /*0x56ba00*/;
    cpu.esp -= 4;
    // 0052f419  e8fafeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f41e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f420  740c                   -je 0x52f42e
    if (cpu.flags.zf)
    {
        goto L_0x0052f42e;
    }
    // 0052f422  c7053cd15600ffffffff   -mov dword ptr [0x56d13c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */) = 4294967295 /*0xffffffff*/;
    // 0052f42c  eb20                   -jmp 0x52f44e
    goto L_0x0052f44e;
L_0x0052f42e:
    // 0052f42e  833d3cd15600ff         +cmp dword ptr [0x56d13c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f435  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f43a  7412                   -je 0x52f44e
    if (cpu.flags.zf)
    {
        goto L_0x0052f44e;
    }
    // 0052f43c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f440  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f444  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f448  ff153cd15600           -call dword ptr [0x56d13c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f44e:
    // 0052f44e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f451(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f451  833d40d1560000         +cmp dword ptr [0x56d140], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f458  751f                   -jne 0x52f479
    if (!cpu.flags.zf)
    {
        goto L_0x0052f479;
    }
    // 0052f45a  6840d15600             -push 0x56d140
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689664 /*0x56d140*/;
    cpu.esp -= 4;
    // 0052f45f  6814ba5600             -push 0x56ba14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683732 /*0x56ba14*/;
    cpu.esp -= 4;
    // 0052f464  e8affeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f469  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f46b  740c                   -je 0x52f479
    if (cpu.flags.zf)
    {
        goto L_0x0052f479;
    }
    // 0052f46d  c70540d15600ffffffff   -mov dword ptr [0x56d140], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */) = 4294967295 /*0xffffffff*/;
    // 0052f477  eb20                   -jmp 0x52f499
    goto L_0x0052f499;
L_0x0052f479:
    // 0052f479  833d40d15600ff         +cmp dword ptr [0x56d140], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f480  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f485  7412                   -je 0x52f499
    if (cpu.flags.zf)
    {
        goto L_0x0052f499;
    }
    // 0052f487  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f48b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f48f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f493  ff1540d15600           -call dword ptr [0x56d140]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f499:
    // 0052f499  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f49c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f49c  833d44d1560000         +cmp dword ptr [0x56d144], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4a3  751f                   -jne 0x52f4c4
    if (!cpu.flags.zf)
    {
        goto L_0x0052f4c4;
    }
    // 0052f4a5  6844d15600             -push 0x56d144
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689668 /*0x56d144*/;
    cpu.esp -= 4;
    // 0052f4aa  6828ba5600             -push 0x56ba28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683752 /*0x56ba28*/;
    cpu.esp -= 4;
    // 0052f4af  e864feffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f4b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f4b6  740c                   -je 0x52f4c4
    if (cpu.flags.zf)
    {
        goto L_0x0052f4c4;
    }
    // 0052f4b8  c70544d15600ffffffff   -mov dword ptr [0x56d144], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */) = 4294967295 /*0xffffffff*/;
    // 0052f4c2  eb1c                   -jmp 0x52f4e0
    goto L_0x0052f4e0;
L_0x0052f4c4:
    // 0052f4c4  833d44d15600ff         +cmp dword ptr [0x56d144], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4cb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f4d0  740e                   -je 0x52f4e0
    if (cpu.flags.zf)
    {
        goto L_0x0052f4e0;
    }
    // 0052f4d2  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f4d6  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f4da  ff1544d15600           -call dword ptr [0x56d144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f4e0:
    // 0052f4e0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f4e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f4e3  833d48d1560000         +cmp dword ptr [0x56d148], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f4eb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f4ed  751f                   -jne 0x52f50e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f50e;
    }
    // 0052f4ef  6848d15600             -push 0x56d148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689672 /*0x56d148*/;
    cpu.esp -= 4;
    // 0052f4f4  683cba5600             -push 0x56ba3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683772 /*0x56ba3c*/;
    cpu.esp -= 4;
    // 0052f4f9  e81afeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f4fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f500  740c                   -je 0x52f50e
    if (cpu.flags.zf)
    {
        goto L_0x0052f50e;
    }
    // 0052f502  c70548d15600ffffffff   -mov dword ptr [0x56d148], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */) = 4294967295 /*0xffffffff*/;
    // 0052f50c  eb23                   -jmp 0x52f531
    goto L_0x0052f531;
L_0x0052f50e:
    // 0052f50e  833d48d15600ff         +cmp dword ptr [0x56d148], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f515  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f51a  7415                   -je 0x52f531
    if (cpu.flags.zf)
    {
        goto L_0x0052f531;
    }
    // 0052f51c  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f51f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f522  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f525  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f528  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f52b  ff1548d15600           -call dword ptr [0x56d148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f531:
    // 0052f531  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f532  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52f535(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f535  833d4cd1560000         +cmp dword ptr [0x56d14c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f53c  751f                   -jne 0x52f55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052f55d;
    }
    // 0052f53e  684cd15600             -push 0x56d14c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689676 /*0x56d14c*/;
    cpu.esp -= 4;
    // 0052f543  6850ba5600             -push 0x56ba50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683792 /*0x56ba50*/;
    cpu.esp -= 4;
    // 0052f548  e8cbfdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f54d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f54f  740c                   -je 0x52f55d
    if (cpu.flags.zf)
    {
        goto L_0x0052f55d;
    }
    // 0052f551  c7054cd15600ffffffff   -mov dword ptr [0x56d14c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */) = 4294967295 /*0xffffffff*/;
    // 0052f55b  eb20                   -jmp 0x52f57d
    goto L_0x0052f57d;
L_0x0052f55d:
    // 0052f55d  833d4cd15600ff         +cmp dword ptr [0x56d14c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f564  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f569  7412                   -je 0x52f57d
    if (cpu.flags.zf)
    {
        goto L_0x0052f57d;
    }
    // 0052f56b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f56f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f573  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f577  ff154cd15600           -call dword ptr [0x56d14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f57d:
    // 0052f57d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f580  833d50d1560000         +cmp dword ptr [0x56d150], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f587  751f                   -jne 0x52f5a8
    if (!cpu.flags.zf)
    {
        goto L_0x0052f5a8;
    }
    // 0052f589  6850d15600             -push 0x56d150
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689680 /*0x56d150*/;
    cpu.esp -= 4;
    // 0052f58e  685cba5600             -push 0x56ba5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683804 /*0x56ba5c*/;
    cpu.esp -= 4;
    // 0052f593  e880fdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f598  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f59a  740c                   -je 0x52f5a8
    if (cpu.flags.zf)
    {
        goto L_0x0052f5a8;
    }
    // 0052f59c  c70550d15600ffffffff   -mov dword ptr [0x56d150], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */) = 4294967295 /*0xffffffff*/;
    // 0052f5a6  eb20                   -jmp 0x52f5c8
    goto L_0x0052f5c8;
L_0x0052f5a8:
    // 0052f5a8  833d50d15600ff         +cmp dword ptr [0x56d150], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5af  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f5b4  7412                   -je 0x52f5c8
    if (cpu.flags.zf)
    {
        goto L_0x0052f5c8;
    }
    // 0052f5b6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5ba  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5be  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5c2  ff1550d15600           -call dword ptr [0x56d150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f5c8:
    // 0052f5c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f5cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f5cb  833d54d1560000         +cmp dword ptr [0x56d154], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5d2  751f                   -jne 0x52f5f3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f5f3;
    }
    // 0052f5d4  6854d15600             -push 0x56d154
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689684 /*0x56d154*/;
    cpu.esp -= 4;
    // 0052f5d9  6870ba5600             -push 0x56ba70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683824 /*0x56ba70*/;
    cpu.esp -= 4;
    // 0052f5de  e835fdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f5e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f5e5  740c                   -je 0x52f5f3
    if (cpu.flags.zf)
    {
        goto L_0x0052f5f3;
    }
    // 0052f5e7  c70554d15600ffffffff   -mov dword ptr [0x56d154], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */) = 4294967295 /*0xffffffff*/;
    // 0052f5f1  eb20                   -jmp 0x52f613
    goto L_0x0052f613;
L_0x0052f5f3:
    // 0052f5f3  833d54d15600ff         +cmp dword ptr [0x56d154], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5fa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f5ff  7412                   -je 0x52f613
    if (cpu.flags.zf)
    {
        goto L_0x0052f613;
    }
    // 0052f601  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f605  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f609  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f60d  ff1554d15600           -call dword ptr [0x56d154]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f613:
    // 0052f613  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f616(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f616  833d58d1560000         +cmp dword ptr [0x56d158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f61d  751f                   -jne 0x52f63e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f63e;
    }
    // 0052f61f  6858d15600             -push 0x56d158
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689688 /*0x56d158*/;
    cpu.esp -= 4;
    // 0052f624  6884ba5600             -push 0x56ba84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683844 /*0x56ba84*/;
    cpu.esp -= 4;
    // 0052f629  e8eafcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f62e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f630  740c                   -je 0x52f63e
    if (cpu.flags.zf)
    {
        goto L_0x0052f63e;
    }
    // 0052f632  c70558d15600ffffffff   -mov dword ptr [0x56d158], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */) = 4294967295 /*0xffffffff*/;
    // 0052f63c  eb20                   -jmp 0x52f65e
    goto L_0x0052f65e;
L_0x0052f63e:
    // 0052f63e  833d58d15600ff         +cmp dword ptr [0x56d158], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f645  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f64a  7412                   -je 0x52f65e
    if (cpu.flags.zf)
    {
        goto L_0x0052f65e;
    }
    // 0052f64c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f650  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f654  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f658  ff1558d15600           -call dword ptr [0x56d158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f65e:
    // 0052f65e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f661(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f661  833d5cd1560000         +cmp dword ptr [0x56d15c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f668  751f                   -jne 0x52f689
    if (!cpu.flags.zf)
    {
        goto L_0x0052f689;
    }
    // 0052f66a  685cd15600             -push 0x56d15c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689692 /*0x56d15c*/;
    cpu.esp -= 4;
    // 0052f66f  6898ba5600             -push 0x56ba98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683864 /*0x56ba98*/;
    cpu.esp -= 4;
    // 0052f674  e89ffcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f679  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f67b  740c                   -je 0x52f689
    if (cpu.flags.zf)
    {
        goto L_0x0052f689;
    }
    // 0052f67d  c7055cd15600ffffffff   -mov dword ptr [0x56d15c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */) = 4294967295 /*0xffffffff*/;
    // 0052f687  eb18                   -jmp 0x52f6a1
    goto L_0x0052f6a1;
L_0x0052f689:
    // 0052f689  833d5cd15600ff         +cmp dword ptr [0x56d15c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f690  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f695  740a                   -je 0x52f6a1
    if (cpu.flags.zf)
    {
        goto L_0x0052f6a1;
    }
    // 0052f697  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f69b  ff155cd15600           -call dword ptr [0x56d15c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f6a1:
    // 0052f6a1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_52f6a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f6a4  833d60d1560000         +cmp dword ptr [0x56d160], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f6ac  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f6ae  751f                   -jne 0x52f6cf
    if (!cpu.flags.zf)
    {
        goto L_0x0052f6cf;
    }
    // 0052f6b0  6860d15600             -push 0x56d160
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689696 /*0x56d160*/;
    cpu.esp -= 4;
    // 0052f6b5  68a4ba5600             -push 0x56baa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683876 /*0x56baa4*/;
    cpu.esp -= 4;
    // 0052f6ba  e859fcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f6bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f6c1  740c                   -je 0x52f6cf
    if (cpu.flags.zf)
    {
        goto L_0x0052f6cf;
    }
    // 0052f6c3  c70560d15600ffffffff   -mov dword ptr [0x56d160], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */) = 4294967295 /*0xffffffff*/;
    // 0052f6cd  eb20                   -jmp 0x52f6ef
    goto L_0x0052f6ef;
L_0x0052f6cf:
    // 0052f6cf  833d60d15600ff         +cmp dword ptr [0x56d160], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6d6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f6db  7412                   -je 0x52f6ef
    if (cpu.flags.zf)
    {
        goto L_0x0052f6ef;
    }
    // 0052f6dd  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f6e0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f6e3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f6e6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f6e9  ff1560d15600           -call dword ptr [0x56d160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f6ef:
    // 0052f6ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f6f0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52f6f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f6f3  833d64d1560000         +cmp dword ptr [0x56d164], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f6fb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f6fd  751f                   -jne 0x52f71e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f71e;
    }
    // 0052f6ff  6864d15600             -push 0x56d164
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689700 /*0x56d164*/;
    cpu.esp -= 4;
    // 0052f704  68b8ba5600             -push 0x56bab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683896 /*0x56bab8*/;
    cpu.esp -= 4;
    // 0052f709  e80afcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f70e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f710  740c                   -je 0x52f71e
    if (cpu.flags.zf)
    {
        goto L_0x0052f71e;
    }
    // 0052f712  c70564d15600ffffffff   -mov dword ptr [0x56d164], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */) = 4294967295 /*0xffffffff*/;
    // 0052f71c  eb20                   -jmp 0x52f73e
    goto L_0x0052f73e;
L_0x0052f71e:
    // 0052f71e  833d64d15600ff         +cmp dword ptr [0x56d164], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f725  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f72a  7412                   -je 0x52f73e
    if (cpu.flags.zf)
    {
        goto L_0x0052f73e;
    }
    // 0052f72c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f72f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f732  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f735  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f738  ff1564d15600           -call dword ptr [0x56d164]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f73e:
    // 0052f73e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f73f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52f742(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f742  833d68d1560000         +cmp dword ptr [0x56d168], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f749  751f                   -jne 0x52f76a
    if (!cpu.flags.zf)
    {
        goto L_0x0052f76a;
    }
    // 0052f74b  6868d15600             -push 0x56d168
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689704 /*0x56d168*/;
    cpu.esp -= 4;
    // 0052f750  68d0ba5600             -push 0x56bad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683920 /*0x56bad0*/;
    cpu.esp -= 4;
    // 0052f755  e8befbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f75a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f75c  740c                   -je 0x52f76a
    if (cpu.flags.zf)
    {
        goto L_0x0052f76a;
    }
    // 0052f75e  c70568d15600ffffffff   -mov dword ptr [0x56d168], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */) = 4294967295 /*0xffffffff*/;
    // 0052f768  eb20                   -jmp 0x52f78a
    goto L_0x0052f78a;
L_0x0052f76a:
    // 0052f76a  833d68d15600ff         +cmp dword ptr [0x56d168], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f771  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f776  7412                   -je 0x52f78a
    if (cpu.flags.zf)
    {
        goto L_0x0052f78a;
    }
    // 0052f778  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f77c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f780  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f784  ff1568d15600           -call dword ptr [0x56d168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f78a:
    // 0052f78a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f78d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f78d  833d6cd1560000         +cmp dword ptr [0x56d16c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f794  751f                   -jne 0x52f7b5
    if (!cpu.flags.zf)
    {
        goto L_0x0052f7b5;
    }
    // 0052f796  686cd15600             -push 0x56d16c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689708 /*0x56d16c*/;
    cpu.esp -= 4;
    // 0052f79b  68e4ba5600             -push 0x56bae4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683940 /*0x56bae4*/;
    cpu.esp -= 4;
    // 0052f7a0  e873fbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f7a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f7a7  740c                   -je 0x52f7b5
    if (cpu.flags.zf)
    {
        goto L_0x0052f7b5;
    }
    // 0052f7a9  c7056cd15600ffffffff   -mov dword ptr [0x56d16c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */) = 4294967295 /*0xffffffff*/;
    // 0052f7b3  eb20                   -jmp 0x52f7d5
    goto L_0x0052f7d5;
L_0x0052f7b5:
    // 0052f7b5  833d6cd15600ff         +cmp dword ptr [0x56d16c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f7bc  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f7c1  7412                   -je 0x52f7d5
    if (cpu.flags.zf)
    {
        goto L_0x0052f7d5;
    }
    // 0052f7c3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7c7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7cb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7cf  ff156cd15600           -call dword ptr [0x56d16c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f7d5:
    // 0052f7d5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f7d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f7d8  833d70d1560000         +cmp dword ptr [0x56d170], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f7df  751f                   -jne 0x52f800
    if (!cpu.flags.zf)
    {
        goto L_0x0052f800;
    }
    // 0052f7e1  6870d15600             -push 0x56d170
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689712 /*0x56d170*/;
    cpu.esp -= 4;
    // 0052f7e6  68f8ba5600             -push 0x56baf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683960 /*0x56baf8*/;
    cpu.esp -= 4;
    // 0052f7eb  e828fbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f7f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f7f2  740c                   -je 0x52f800
    if (cpu.flags.zf)
    {
        goto L_0x0052f800;
    }
    // 0052f7f4  c70570d15600ffffffff   -mov dword ptr [0x56d170], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */) = 4294967295 /*0xffffffff*/;
    // 0052f7fe  eb20                   -jmp 0x52f820
    goto L_0x0052f820;
L_0x0052f800:
    // 0052f800  833d70d15600ff         +cmp dword ptr [0x56d170], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f807  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f80c  7412                   -je 0x52f820
    if (cpu.flags.zf)
    {
        goto L_0x0052f820;
    }
    // 0052f80e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f812  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f816  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f81a  ff1570d15600           -call dword ptr [0x56d170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f820:
    // 0052f820  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f823(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f823  833d74d1560000         +cmp dword ptr [0x56d174], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f82a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f82b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f82d  751f                   -jne 0x52f84e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f84e;
    }
    // 0052f82f  6874d15600             -push 0x56d174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689716 /*0x56d174*/;
    cpu.esp -= 4;
    // 0052f834  680cbb5600             -push 0x56bb0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683980 /*0x56bb0c*/;
    cpu.esp -= 4;
    // 0052f839  e8dafaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f83e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f840  740c                   -je 0x52f84e
    if (cpu.flags.zf)
    {
        goto L_0x0052f84e;
    }
    // 0052f842  c70574d15600ffffffff   -mov dword ptr [0x56d174], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */) = 4294967295 /*0xffffffff*/;
    // 0052f84c  eb26                   -jmp 0x52f874
    goto L_0x0052f874;
L_0x0052f84e:
    // 0052f84e  833d74d15600ff         +cmp dword ptr [0x56d174], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f855  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f85a  7418                   -je 0x52f874
    if (cpu.flags.zf)
    {
        goto L_0x0052f874;
    }
    // 0052f85c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f85f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f862  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f865  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f868  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f86b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f86e  ff1574d15600           -call dword ptr [0x56d174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f874:
    // 0052f874  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f875  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f878(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f878  833d78d1560000         +cmp dword ptr [0x56d178], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f87f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f880  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f882  751f                   -jne 0x52f8a3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f8a3;
    }
    // 0052f884  6878d15600             -push 0x56d178
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689720 /*0x56d178*/;
    cpu.esp -= 4;
    // 0052f889  6824bb5600             -push 0x56bb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684004 /*0x56bb24*/;
    cpu.esp -= 4;
    // 0052f88e  e885faffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f893  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f895  740c                   -je 0x52f8a3
    if (cpu.flags.zf)
    {
        goto L_0x0052f8a3;
    }
    // 0052f897  c70578d15600ffffffff   -mov dword ptr [0x56d178], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */) = 4294967295 /*0xffffffff*/;
    // 0052f8a1  eb26                   -jmp 0x52f8c9
    goto L_0x0052f8c9;
L_0x0052f8a3:
    // 0052f8a3  833d78d15600ff         +cmp dword ptr [0x56d178], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8aa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f8af  7418                   -je 0x52f8c9
    if (cpu.flags.zf)
    {
        goto L_0x0052f8c9;
    }
    // 0052f8b1  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f8b4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f8b7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f8ba  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f8bd  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f8c0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f8c3  ff1578d15600           -call dword ptr [0x56d178]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f8c9:
    // 0052f8c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f8ca  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f8cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f8cd  833d7cd1560000         +cmp dword ptr [0x56d17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f8d5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f8d7  751f                   -jne 0x52f8f8
    if (!cpu.flags.zf)
    {
        goto L_0x0052f8f8;
    }
    // 0052f8d9  687cd15600             -push 0x56d17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689724 /*0x56d17c*/;
    cpu.esp -= 4;
    // 0052f8de  683cbb5600             -push 0x56bb3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684028 /*0x56bb3c*/;
    cpu.esp -= 4;
    // 0052f8e3  e830faffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f8e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f8ea  740c                   -je 0x52f8f8
    if (cpu.flags.zf)
    {
        goto L_0x0052f8f8;
    }
    // 0052f8ec  c7057cd15600ffffffff   -mov dword ptr [0x56d17c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */) = 4294967295 /*0xffffffff*/;
    // 0052f8f6  eb26                   -jmp 0x52f91e
    goto L_0x0052f91e;
L_0x0052f8f8:
    // 0052f8f8  833d7cd15600ff         +cmp dword ptr [0x56d17c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8ff  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f904  7418                   -je 0x52f91e
    if (cpu.flags.zf)
    {
        goto L_0x0052f91e;
    }
    // 0052f906  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f909  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f90c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f90f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f912  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f915  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f918  ff157cd15600           -call dword ptr [0x56d17c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f91e:
    // 0052f91e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f91f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f922(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f922  833d80d1560000         +cmp dword ptr [0x56d180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f929  751f                   -jne 0x52f94a
    if (!cpu.flags.zf)
    {
        goto L_0x0052f94a;
    }
    // 0052f92b  6880d15600             -push 0x56d180
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689728 /*0x56d180*/;
    cpu.esp -= 4;
    // 0052f930  6854bb5600             -push 0x56bb54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684052 /*0x56bb54*/;
    cpu.esp -= 4;
    // 0052f935  e8def9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f93a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f93c  740c                   -je 0x52f94a
    if (cpu.flags.zf)
    {
        goto L_0x0052f94a;
    }
    // 0052f93e  c70580d15600ffffffff   -mov dword ptr [0x56d180], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */) = 4294967295 /*0xffffffff*/;
    // 0052f948  eb1c                   -jmp 0x52f966
    goto L_0x0052f966;
L_0x0052f94a:
    // 0052f94a  833d80d15600ff         +cmp dword ptr [0x56d180], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f951  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f956  740e                   -je 0x52f966
    if (cpu.flags.zf)
    {
        goto L_0x0052f966;
    }
    // 0052f958  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f95c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f960  ff1580d15600           -call dword ptr [0x56d180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f966:
    // 0052f966  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f969(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f969  833d84d1560000         +cmp dword ptr [0x56d184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f970  751f                   -jne 0x52f991
    if (!cpu.flags.zf)
    {
        goto L_0x0052f991;
    }
    // 0052f972  6884d15600             -push 0x56d184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689732 /*0x56d184*/;
    cpu.esp -= 4;
    // 0052f977  6868bb5600             -push 0x56bb68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684072 /*0x56bb68*/;
    cpu.esp -= 4;
    // 0052f97c  e897f9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f981  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f983  740c                   -je 0x52f991
    if (cpu.flags.zf)
    {
        goto L_0x0052f991;
    }
    // 0052f985  c70584d15600ffffffff   -mov dword ptr [0x56d184], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */) = 4294967295 /*0xffffffff*/;
    // 0052f98f  eb18                   -jmp 0x52f9a9
    goto L_0x0052f9a9;
L_0x0052f991:
    // 0052f991  833d84d15600ff         +cmp dword ptr [0x56d184], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f998  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f99d  740a                   -je 0x52f9a9
    if (cpu.flags.zf)
    {
        goto L_0x0052f9a9;
    }
    // 0052f99f  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f9a3  ff1584d15600           -call dword ptr [0x56d184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f9a9:
    // 0052f9a9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_52f9ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f9ac  833d88d1560000         +cmp dword ptr [0x56d188], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f9b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f9b4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f9b6  751f                   -jne 0x52f9d7
    if (!cpu.flags.zf)
    {
        goto L_0x0052f9d7;
    }
    // 0052f9b8  6888d15600             -push 0x56d188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689736 /*0x56d188*/;
    cpu.esp -= 4;
    // 0052f9bd  687cbb5600             -push 0x56bb7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684092 /*0x56bb7c*/;
    cpu.esp -= 4;
    // 0052f9c2  e851f9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f9c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f9c9  740c                   -je 0x52f9d7
    if (cpu.flags.zf)
    {
        goto L_0x0052f9d7;
    }
    // 0052f9cb  c70588d15600ffffffff   -mov dword ptr [0x56d188], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */) = 4294967295 /*0xffffffff*/;
    // 0052f9d5  eb23                   -jmp 0x52f9fa
    goto L_0x0052f9fa;
L_0x0052f9d7:
    // 0052f9d7  833d88d15600ff         +cmp dword ptr [0x56d188], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f9de  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f9e3  7415                   -je 0x52f9fa
    if (cpu.flags.zf)
    {
        goto L_0x0052f9fa;
    }
    // 0052f9e5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f9e8  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f9eb  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f9ee  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f9f1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f9f4  ff1588d15600           -call dword ptr [0x56d188]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f9fa:
    // 0052f9fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f9fb  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52f9fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f9fe  833d8cd1560000         +cmp dword ptr [0x56d18c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fa06  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fa08  751f                   -jne 0x52fa29
    if (!cpu.flags.zf)
    {
        goto L_0x0052fa29;
    }
    // 0052fa0a  688cd15600             -push 0x56d18c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689740 /*0x56d18c*/;
    cpu.esp -= 4;
    // 0052fa0f  688cbb5600             -push 0x56bb8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684108 /*0x56bb8c*/;
    cpu.esp -= 4;
    // 0052fa14  e8fff8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fa19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fa1b  740c                   -je 0x52fa29
    if (cpu.flags.zf)
    {
        goto L_0x0052fa29;
    }
    // 0052fa1d  c7058cd15600ffffffff   -mov dword ptr [0x56d18c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */) = 4294967295 /*0xffffffff*/;
    // 0052fa27  eb20                   -jmp 0x52fa49
    goto L_0x0052fa49;
L_0x0052fa29:
    // 0052fa29  833d8cd15600ff         +cmp dword ptr [0x56d18c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa30  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fa35  7412                   -je 0x52fa49
    if (cpu.flags.zf)
    {
        goto L_0x0052fa49;
    }
    // 0052fa37  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fa3a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fa3d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa40  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fa43  ff158cd15600           -call dword ptr [0x56d18c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fa49:
    // 0052fa49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fa4a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fa4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fa4d  833d90d1560000         +cmp dword ptr [0x56d190], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa54  751f                   -jne 0x52fa75
    if (!cpu.flags.zf)
    {
        goto L_0x0052fa75;
    }
    // 0052fa56  6890d15600             -push 0x56d190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689744 /*0x56d190*/;
    cpu.esp -= 4;
    // 0052fa5b  68a4bb5600             -push 0x56bba4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684132 /*0x56bba4*/;
    cpu.esp -= 4;
    // 0052fa60  e8b3f8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fa65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fa67  740c                   -je 0x52fa75
    if (cpu.flags.zf)
    {
        goto L_0x0052fa75;
    }
    // 0052fa69  c70590d15600ffffffff   -mov dword ptr [0x56d190], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */) = 4294967295 /*0xffffffff*/;
    // 0052fa73  eb20                   -jmp 0x52fa95
    goto L_0x0052fa95;
L_0x0052fa75:
    // 0052fa75  833d90d15600ff         +cmp dword ptr [0x56d190], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa7c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fa81  7412                   -je 0x52fa95
    if (cpu.flags.zf)
    {
        goto L_0x0052fa95;
    }
    // 0052fa83  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa87  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa8b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa8f  ff1590d15600           -call dword ptr [0x56d190]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fa95:
    // 0052fa95  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fa98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fa98  833d94d1560000         +cmp dword ptr [0x56d194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa9f  751f                   -jne 0x52fac0
    if (!cpu.flags.zf)
    {
        goto L_0x0052fac0;
    }
    // 0052faa1  6894d15600             -push 0x56d194
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689748 /*0x56d194*/;
    cpu.esp -= 4;
    // 0052faa6  68b0bb5600             -push 0x56bbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684144 /*0x56bbb0*/;
    cpu.esp -= 4;
    // 0052faab  e868f8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fab0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fab2  740c                   -je 0x52fac0
    if (cpu.flags.zf)
    {
        goto L_0x0052fac0;
    }
    // 0052fab4  c70594d15600ffffffff   -mov dword ptr [0x56d194], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */) = 4294967295 /*0xffffffff*/;
    // 0052fabe  eb20                   -jmp 0x52fae0
    goto L_0x0052fae0;
L_0x0052fac0:
    // 0052fac0  833d94d15600ff         +cmp dword ptr [0x56d194], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fac7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052facc  7412                   -je 0x52fae0
    if (cpu.flags.zf)
    {
        goto L_0x0052fae0;
    }
    // 0052face  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fad2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fad6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fada  ff1594d15600           -call dword ptr [0x56d194]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fae0:
    // 0052fae0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fae3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fae3  833d98d1560000         +cmp dword ptr [0x56d198], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052faea  751f                   -jne 0x52fb0b
    if (!cpu.flags.zf)
    {
        goto L_0x0052fb0b;
    }
    // 0052faec  6898d15600             -push 0x56d198
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689752 /*0x56d198*/;
    cpu.esp -= 4;
    // 0052faf1  68bcbb5600             -push 0x56bbbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684156 /*0x56bbbc*/;
    cpu.esp -= 4;
    // 0052faf6  e81df8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fafb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fafd  740c                   -je 0x52fb0b
    if (cpu.flags.zf)
    {
        goto L_0x0052fb0b;
    }
    // 0052faff  c70598d15600ffffffff   -mov dword ptr [0x56d198], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */) = 4294967295 /*0xffffffff*/;
    // 0052fb09  eb20                   -jmp 0x52fb2b
    goto L_0x0052fb2b;
L_0x0052fb0b:
    // 0052fb0b  833d98d15600ff         +cmp dword ptr [0x56d198], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb12  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fb17  7412                   -je 0x52fb2b
    if (cpu.flags.zf)
    {
        goto L_0x0052fb2b;
    }
    // 0052fb19  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb1d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb21  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb25  ff1598d15600           -call dword ptr [0x56d198]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fb2b:
    // 0052fb2b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fb2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fb2e  833d9cd1560000         +cmp dword ptr [0x56d19c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb35  751f                   -jne 0x52fb56
    if (!cpu.flags.zf)
    {
        goto L_0x0052fb56;
    }
    // 0052fb37  689cd15600             -push 0x56d19c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689756 /*0x56d19c*/;
    cpu.esp -= 4;
    // 0052fb3c  68c8bb5600             -push 0x56bbc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684168 /*0x56bbc8*/;
    cpu.esp -= 4;
    // 0052fb41  e8d2f7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fb46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fb48  740c                   -je 0x52fb56
    if (cpu.flags.zf)
    {
        goto L_0x0052fb56;
    }
    // 0052fb4a  c7059cd15600ffffffff   -mov dword ptr [0x56d19c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */) = 4294967295 /*0xffffffff*/;
    // 0052fb54  eb20                   -jmp 0x52fb76
    goto L_0x0052fb76;
L_0x0052fb56:
    // 0052fb56  833d9cd15600ff         +cmp dword ptr [0x56d19c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb5d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fb62  7412                   -je 0x52fb76
    if (cpu.flags.zf)
    {
        goto L_0x0052fb76;
    }
    // 0052fb64  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb68  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb6c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb70  ff159cd15600           -call dword ptr [0x56d19c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fb76:
    // 0052fb76  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fb79(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fb79  833da0d1560000         +cmp dword ptr [0x56d1a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fb81  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fb83  751f                   -jne 0x52fba4
    if (!cpu.flags.zf)
    {
        goto L_0x0052fba4;
    }
    // 0052fb85  68a0d15600             -push 0x56d1a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689760 /*0x56d1a0*/;
    cpu.esp -= 4;
    // 0052fb8a  68d4bb5600             -push 0x56bbd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684180 /*0x56bbd4*/;
    cpu.esp -= 4;
    // 0052fb8f  e884f7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fb94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fb96  740c                   -je 0x52fba4
    if (cpu.flags.zf)
    {
        goto L_0x0052fba4;
    }
    // 0052fb98  c705a0d15600ffffffff   -mov dword ptr [0x56d1a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */) = 4294967295 /*0xffffffff*/;
    // 0052fba2  eb29                   -jmp 0x52fbcd
    goto L_0x0052fbcd;
L_0x0052fba4:
    // 0052fba4  833da0d15600ff         +cmp dword ptr [0x56d1a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fbab  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fbb0  741b                   -je 0x52fbcd
    if (cpu.flags.zf)
    {
        goto L_0x0052fbcd;
    }
    // 0052fbb2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fbb5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fbb8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fbbb  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fbbe  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fbc1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fbc4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fbc7  ff15a0d15600           -call dword ptr [0x56d1a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fbcd:
    // 0052fbcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fbce  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fbd1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fbd1  833da4d1560000         +cmp dword ptr [0x56d1a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fbd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fbd9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fbdb  751f                   -jne 0x52fbfc
    if (!cpu.flags.zf)
    {
        goto L_0x0052fbfc;
    }
    // 0052fbdd  68a4d15600             -push 0x56d1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689764 /*0x56d1a4*/;
    cpu.esp -= 4;
    // 0052fbe2  68e0bb5600             -push 0x56bbe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684192 /*0x56bbe0*/;
    cpu.esp -= 4;
    // 0052fbe7  e82cf7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fbec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fbee  740c                   -je 0x52fbfc
    if (cpu.flags.zf)
    {
        goto L_0x0052fbfc;
    }
    // 0052fbf0  c705a4d15600ffffffff   -mov dword ptr [0x56d1a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */) = 4294967295 /*0xffffffff*/;
    // 0052fbfa  eb29                   -jmp 0x52fc25
    goto L_0x0052fc25;
L_0x0052fbfc:
    // 0052fbfc  833da4d15600ff         +cmp dword ptr [0x56d1a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc03  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fc08  741b                   -je 0x52fc25
    if (cpu.flags.zf)
    {
        goto L_0x0052fc25;
    }
    // 0052fc0a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fc0d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fc10  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fc13  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fc16  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fc19  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fc1c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fc1f  ff15a4d15600           -call dword ptr [0x56d1a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fc25:
    // 0052fc25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fc26  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fc29(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fc29  833da8d1560000         +cmp dword ptr [0x56d1a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fc31  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fc33  751f                   -jne 0x52fc54
    if (!cpu.flags.zf)
    {
        goto L_0x0052fc54;
    }
    // 0052fc35  68a8d15600             -push 0x56d1a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689768 /*0x56d1a8*/;
    cpu.esp -= 4;
    // 0052fc3a  68f0bb5600             -push 0x56bbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684208 /*0x56bbf0*/;
    cpu.esp -= 4;
    // 0052fc3f  e8d4f6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fc44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fc46  740c                   -je 0x52fc54
    if (cpu.flags.zf)
    {
        goto L_0x0052fc54;
    }
    // 0052fc48  c705a8d15600ffffffff   -mov dword ptr [0x56d1a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */) = 4294967295 /*0xffffffff*/;
    // 0052fc52  eb29                   -jmp 0x52fc7d
    goto L_0x0052fc7d;
L_0x0052fc54:
    // 0052fc54  833da8d15600ff         +cmp dword ptr [0x56d1a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc5b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fc60  741b                   -je 0x52fc7d
    if (cpu.flags.zf)
    {
        goto L_0x0052fc7d;
    }
    // 0052fc62  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fc65  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fc68  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fc6b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fc6e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fc71  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fc74  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fc77  ff15a8d15600           -call dword ptr [0x56d1a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fc7d:
    // 0052fc7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fc7e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fc81(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fc81  833dacd1560000         +cmp dword ptr [0x56d1ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fc89  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fc8b  751f                   -jne 0x52fcac
    if (!cpu.flags.zf)
    {
        goto L_0x0052fcac;
    }
    // 0052fc8d  68acd15600             -push 0x56d1ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689772 /*0x56d1ac*/;
    cpu.esp -= 4;
    // 0052fc92  6800bc5600             -push 0x56bc00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684224 /*0x56bc00*/;
    cpu.esp -= 4;
    // 0052fc97  e87cf6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fc9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fc9e  740c                   -je 0x52fcac
    if (cpu.flags.zf)
    {
        goto L_0x0052fcac;
    }
    // 0052fca0  c705acd15600ffffffff   -mov dword ptr [0x56d1ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */) = 4294967295 /*0xffffffff*/;
    // 0052fcaa  eb29                   -jmp 0x52fcd5
    goto L_0x0052fcd5;
L_0x0052fcac:
    // 0052fcac  833dacd15600ff         +cmp dword ptr [0x56d1ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fcb3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fcb8  741b                   -je 0x52fcd5
    if (cpu.flags.zf)
    {
        goto L_0x0052fcd5;
    }
    // 0052fcba  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fcbd  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fcc0  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fcc3  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fcc6  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fcc9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fccc  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fccf  ff15acd15600           -call dword ptr [0x56d1ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fcd5:
    // 0052fcd5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fcd6  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fcd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fcd9  833db0d1560000         +cmp dword ptr [0x56d1b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fce0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fce1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fce3  751f                   -jne 0x52fd04
    if (!cpu.flags.zf)
    {
        goto L_0x0052fd04;
    }
    // 0052fce5  68b0d15600             -push 0x56d1b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689776 /*0x56d1b0*/;
    cpu.esp -= 4;
    // 0052fcea  6814bc5600             -push 0x56bc14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684244 /*0x56bc14*/;
    cpu.esp -= 4;
    // 0052fcef  e824f6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fcf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fcf6  740c                   -je 0x52fd04
    if (cpu.flags.zf)
    {
        goto L_0x0052fd04;
    }
    // 0052fcf8  c705b0d15600ffffffff   -mov dword ptr [0x56d1b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */) = 4294967295 /*0xffffffff*/;
    // 0052fd02  eb29                   -jmp 0x52fd2d
    goto L_0x0052fd2d;
L_0x0052fd04:
    // 0052fd04  833db0d15600ff         +cmp dword ptr [0x56d1b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd0b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fd10  741b                   -je 0x52fd2d
    if (cpu.flags.zf)
    {
        goto L_0x0052fd2d;
    }
    // 0052fd12  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fd15  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fd18  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fd1b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fd1e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fd21  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fd24  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fd27  ff15b0d15600           -call dword ptr [0x56d1b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fd2d:
    // 0052fd2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fd2e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fd31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fd31  833db4d1560000         +cmp dword ptr [0x56d1b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fd39  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fd3b  751f                   -jne 0x52fd5c
    if (!cpu.flags.zf)
    {
        goto L_0x0052fd5c;
    }
    // 0052fd3d  68b4d15600             -push 0x56d1b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689780 /*0x56d1b4*/;
    cpu.esp -= 4;
    // 0052fd42  6828bc5600             -push 0x56bc28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684264 /*0x56bc28*/;
    cpu.esp -= 4;
    // 0052fd47  e8ccf5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fd4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fd4e  740c                   -je 0x52fd5c
    if (cpu.flags.zf)
    {
        goto L_0x0052fd5c;
    }
    // 0052fd50  c705b4d15600ffffffff   -mov dword ptr [0x56d1b4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */) = 4294967295 /*0xffffffff*/;
    // 0052fd5a  eb29                   -jmp 0x52fd85
    goto L_0x0052fd85;
L_0x0052fd5c:
    // 0052fd5c  833db4d15600ff         +cmp dword ptr [0x56d1b4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd63  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fd68  741b                   -je 0x52fd85
    if (cpu.flags.zf)
    {
        goto L_0x0052fd85;
    }
    // 0052fd6a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fd6d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fd70  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fd73  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fd76  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fd79  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fd7c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fd7f  ff15b4d15600           -call dword ptr [0x56d1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fd85:
    // 0052fd85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fd86  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fd89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fd89  833db8d1560000         +cmp dword ptr [0x56d1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fd91  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fd93  751f                   -jne 0x52fdb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052fdb4;
    }
    // 0052fd95  68b8d15600             -push 0x56d1b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689784 /*0x56d1b8*/;
    cpu.esp -= 4;
    // 0052fd9a  683cbc5600             -push 0x56bc3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684284 /*0x56bc3c*/;
    cpu.esp -= 4;
    // 0052fd9f  e874f5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fda4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fda6  740c                   -je 0x52fdb4
    if (cpu.flags.zf)
    {
        goto L_0x0052fdb4;
    }
    // 0052fda8  c705b8d15600ffffffff   -mov dword ptr [0x56d1b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */) = 4294967295 /*0xffffffff*/;
    // 0052fdb2  eb20                   -jmp 0x52fdd4
    goto L_0x0052fdd4;
L_0x0052fdb4:
    // 0052fdb4  833db8d15600ff         +cmp dword ptr [0x56d1b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fdbb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fdc0  7412                   -je 0x52fdd4
    if (cpu.flags.zf)
    {
        goto L_0x0052fdd4;
    }
    // 0052fdc2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fdc5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fdc8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fdcb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fdce  ff15b8d15600           -call dword ptr [0x56d1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fdd4:
    // 0052fdd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fdd5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fdd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fdd8  833dbcd1560000         +cmp dword ptr [0x56d1bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fddf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fde0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fde2  751f                   -jne 0x52fe03
    if (!cpu.flags.zf)
    {
        goto L_0x0052fe03;
    }
    // 0052fde4  68bcd15600             -push 0x56d1bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689788 /*0x56d1bc*/;
    cpu.esp -= 4;
    // 0052fde9  6850bc5600             -push 0x56bc50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684304 /*0x56bc50*/;
    cpu.esp -= 4;
    // 0052fdee  e825f5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fdf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fdf5  740c                   -je 0x52fe03
    if (cpu.flags.zf)
    {
        goto L_0x0052fe03;
    }
    // 0052fdf7  c705bcd15600ffffffff   -mov dword ptr [0x56d1bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */) = 4294967295 /*0xffffffff*/;
    // 0052fe01  eb20                   -jmp 0x52fe23
    goto L_0x0052fe23;
L_0x0052fe03:
    // 0052fe03  833dbcd15600ff         +cmp dword ptr [0x56d1bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe0a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fe0f  7412                   -je 0x52fe23
    if (cpu.flags.zf)
    {
        goto L_0x0052fe23;
    }
    // 0052fe11  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fe14  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fe17  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fe1a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fe1d  ff15bcd15600           -call dword ptr [0x56d1bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fe23:
    // 0052fe23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fe24  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fe27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fe27  833dc0d1560000         +cmp dword ptr [0x56d1c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fe2f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fe31  751f                   -jne 0x52fe52
    if (!cpu.flags.zf)
    {
        goto L_0x0052fe52;
    }
    // 0052fe33  68c0d15600             -push 0x56d1c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689792 /*0x56d1c0*/;
    cpu.esp -= 4;
    // 0052fe38  6864bc5600             -push 0x56bc64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684324 /*0x56bc64*/;
    cpu.esp -= 4;
    // 0052fe3d  e8d6f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fe42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fe44  740c                   -je 0x52fe52
    if (cpu.flags.zf)
    {
        goto L_0x0052fe52;
    }
    // 0052fe46  c705c0d15600ffffffff   -mov dword ptr [0x56d1c0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */) = 4294967295 /*0xffffffff*/;
    // 0052fe50  eb20                   -jmp 0x52fe72
    goto L_0x0052fe72;
L_0x0052fe52:
    // 0052fe52  833dc0d15600ff         +cmp dword ptr [0x56d1c0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe59  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fe5e  7412                   -je 0x52fe72
    if (cpu.flags.zf)
    {
        goto L_0x0052fe72;
    }
    // 0052fe60  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fe63  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fe66  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fe69  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fe6c  ff15c0d15600           -call dword ptr [0x56d1c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fe72:
    // 0052fe72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fe73  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fe76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fe76  833dc4d1560000         +cmp dword ptr [0x56d1c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fe7e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fe80  751f                   -jne 0x52fea1
    if (!cpu.flags.zf)
    {
        goto L_0x0052fea1;
    }
    // 0052fe82  68c4d15600             -push 0x56d1c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689796 /*0x56d1c4*/;
    cpu.esp -= 4;
    // 0052fe87  6878bc5600             -push 0x56bc78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684344 /*0x56bc78*/;
    cpu.esp -= 4;
    // 0052fe8c  e887f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fe91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fe93  740c                   -je 0x52fea1
    if (cpu.flags.zf)
    {
        goto L_0x0052fea1;
    }
    // 0052fe95  c705c4d15600ffffffff   -mov dword ptr [0x56d1c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */) = 4294967295 /*0xffffffff*/;
    // 0052fe9f  eb23                   -jmp 0x52fec4
    goto L_0x0052fec4;
L_0x0052fea1:
    // 0052fea1  833dc4d15600ff         +cmp dword ptr [0x56d1c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fea8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fead  7415                   -je 0x52fec4
    if (cpu.flags.zf)
    {
        goto L_0x0052fec4;
    }
    // 0052feaf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052feb2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052feb5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052feb8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052febb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052febe  ff15c4d15600           -call dword ptr [0x56d1c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fec4:
    // 0052fec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fec5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52fec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fec8  833dc8d1560000         +cmp dword ptr [0x56d1c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fecf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fed0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fed2  751f                   -jne 0x52fef3
    if (!cpu.flags.zf)
    {
        goto L_0x0052fef3;
    }
    // 0052fed4  68c8d15600             -push 0x56d1c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689800 /*0x56d1c8*/;
    cpu.esp -= 4;
    // 0052fed9  688cbc5600             -push 0x56bc8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684364 /*0x56bc8c*/;
    cpu.esp -= 4;
    // 0052fede  e835f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fee3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fee5  740c                   -je 0x52fef3
    if (cpu.flags.zf)
    {
        goto L_0x0052fef3;
    }
    // 0052fee7  c705c8d15600ffffffff   -mov dword ptr [0x56d1c8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */) = 4294967295 /*0xffffffff*/;
    // 0052fef1  eb26                   -jmp 0x52ff19
    goto L_0x0052ff19;
L_0x0052fef3:
    // 0052fef3  833dc8d15600ff         +cmp dword ptr [0x56d1c8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fefa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052feff  7418                   -je 0x52ff19
    if (cpu.flags.zf)
    {
        goto L_0x0052ff19;
    }
    // 0052ff01  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ff04  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ff07  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ff0a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ff0d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ff10  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ff13  ff15c8d15600           -call dword ptr [0x56d1c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ff19:
    // 0052ff19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ff1a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ff1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ff1d  833dccd1560000         +cmp dword ptr [0x56d1cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ff25  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ff27  751f                   -jne 0x52ff48
    if (!cpu.flags.zf)
    {
        goto L_0x0052ff48;
    }
    // 0052ff29  68ccd15600             -push 0x56d1cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689804 /*0x56d1cc*/;
    cpu.esp -= 4;
    // 0052ff2e  68a0bc5600             -push 0x56bca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684384 /*0x56bca0*/;
    cpu.esp -= 4;
    // 0052ff33  e8e0f3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ff38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ff3a  740c                   -je 0x52ff48
    if (cpu.flags.zf)
    {
        goto L_0x0052ff48;
    }
    // 0052ff3c  c705ccd15600ffffffff   -mov dword ptr [0x56d1cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */) = 4294967295 /*0xffffffff*/;
    // 0052ff46  eb26                   -jmp 0x52ff6e
    goto L_0x0052ff6e;
L_0x0052ff48:
    // 0052ff48  833dccd15600ff         +cmp dword ptr [0x56d1cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff4f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052ff54  7418                   -je 0x52ff6e
    if (cpu.flags.zf)
    {
        goto L_0x0052ff6e;
    }
    // 0052ff56  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ff59  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ff5c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ff5f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ff62  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ff65  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ff68  ff15ccd15600           -call dword ptr [0x56d1cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ff6e:
    // 0052ff6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ff6f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ff72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ff72  833dd0d1560000         +cmp dword ptr [0x56d1d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff79  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ff7a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ff7c  751f                   -jne 0x52ff9d
    if (!cpu.flags.zf)
    {
        goto L_0x0052ff9d;
    }
    // 0052ff7e  68d0d15600             -push 0x56d1d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689808 /*0x56d1d0*/;
    cpu.esp -= 4;
    // 0052ff83  68b4bc5600             -push 0x56bcb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684404 /*0x56bcb4*/;
    cpu.esp -= 4;
    // 0052ff88  e88bf3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ff8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ff8f  740c                   -je 0x52ff9d
    if (cpu.flags.zf)
    {
        goto L_0x0052ff9d;
    }
    // 0052ff91  c705d0d15600ffffffff   -mov dword ptr [0x56d1d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */) = 4294967295 /*0xffffffff*/;
    // 0052ff9b  eb26                   -jmp 0x52ffc3
    goto L_0x0052ffc3;
L_0x0052ff9d:
    // 0052ff9d  833dd0d15600ff         +cmp dword ptr [0x56d1d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ffa4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052ffa9  7418                   -je 0x52ffc3
    if (cpu.flags.zf)
    {
        goto L_0x0052ffc3;
    }
    // 0052ffab  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ffae  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ffb1  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ffb4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ffb7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ffba  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ffbd  ff15d0d15600           -call dword ptr [0x56d1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ffc3:
    // 0052ffc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ffc4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ffc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ffc7  833dd4d1560000         +cmp dword ptr [0x56d1d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ffce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ffcf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ffd1  751f                   -jne 0x52fff2
    if (!cpu.flags.zf)
    {
        goto L_0x0052fff2;
    }
    // 0052ffd3  68d4d15600             -push 0x56d1d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689812 /*0x56d1d4*/;
    cpu.esp -= 4;
    // 0052ffd8  68c8bc5600             -push 0x56bcc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684424 /*0x56bcc8*/;
    cpu.esp -= 4;
    // 0052ffdd  e836f3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ffe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ffe4  740c                   -je 0x52fff2
    if (cpu.flags.zf)
    {
        goto L_0x0052fff2;
    }
    // 0052ffe6  c705d4d15600ffffffff   -mov dword ptr [0x56d1d4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */) = 4294967295 /*0xffffffff*/;
    // 0052fff0  eb23                   -jmp 0x530015
    goto L_0x00530015;
L_0x0052fff2:
    // 0052fff2  833dd4d15600ff         +cmp dword ptr [0x56d1d4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fff9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fffe  7415                   -je 0x530015
    if (cpu.flags.zf)
    {
        goto L_0x00530015;
    }
    // 00530000  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530003  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530006  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530009  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053000c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053000f  ff15d4d15600           -call dword ptr [0x56d1d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530015:
    // 00530015  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530016  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530019(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530019  833dd8d1560000         +cmp dword ptr [0x56d1d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530020  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530021  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530023  751f                   -jne 0x530044
    if (!cpu.flags.zf)
    {
        goto L_0x00530044;
    }
    // 00530025  68d8d15600             -push 0x56d1d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689816 /*0x56d1d8*/;
    cpu.esp -= 4;
    // 0053002a  68dcbc5600             -push 0x56bcdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684444 /*0x56bcdc*/;
    cpu.esp -= 4;
    // 0053002f  e8e4f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530036  740c                   -je 0x530044
    if (cpu.flags.zf)
    {
        goto L_0x00530044;
    }
    // 00530038  c705d8d15600ffffffff   -mov dword ptr [0x56d1d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */) = 4294967295 /*0xffffffff*/;
    // 00530042  eb23                   -jmp 0x530067
    goto L_0x00530067;
L_0x00530044:
    // 00530044  833dd8d15600ff         +cmp dword ptr [0x56d1d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053004b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530050  7415                   -je 0x530067
    if (cpu.flags.zf)
    {
        goto L_0x00530067;
    }
    // 00530052  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530055  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530058  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053005b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053005e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530061  ff15d8d15600           -call dword ptr [0x56d1d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530067:
    // 00530067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530068  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_53006b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053006b  833ddcd1560000         +cmp dword ptr [0x56d1dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530072  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530073  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530075  751f                   -jne 0x530096
    if (!cpu.flags.zf)
    {
        goto L_0x00530096;
    }
    // 00530077  68dcd15600             -push 0x56d1dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689820 /*0x56d1dc*/;
    cpu.esp -= 4;
    // 0053007c  68f0bc5600             -push 0x56bcf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684464 /*0x56bcf0*/;
    cpu.esp -= 4;
    // 00530081  e892f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530086  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530088  740c                   -je 0x530096
    if (cpu.flags.zf)
    {
        goto L_0x00530096;
    }
    // 0053008a  c705dcd15600ffffffff   -mov dword ptr [0x56d1dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */) = 4294967295 /*0xffffffff*/;
    // 00530094  eb23                   -jmp 0x5300b9
    goto L_0x005300b9;
L_0x00530096:
    // 00530096  833ddcd15600ff         +cmp dword ptr [0x56d1dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053009d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005300a2  7415                   -je 0x5300b9
    if (cpu.flags.zf)
    {
        goto L_0x005300b9;
    }
    // 005300a4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005300a7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005300aa  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005300ad  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300b0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005300b3  ff15dcd15600           -call dword ptr [0x56d1dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005300b9:
    // 005300b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005300ba  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5300bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005300bd  833de0d1560000         +cmp dword ptr [0x56d1e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005300c4  751f                   -jne 0x5300e5
    if (!cpu.flags.zf)
    {
        goto L_0x005300e5;
    }
    // 005300c6  68e0d15600             -push 0x56d1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689824 /*0x56d1e0*/;
    cpu.esp -= 4;
    // 005300cb  6804bd5600             -push 0x56bd04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684484 /*0x56bd04*/;
    cpu.esp -= 4;
    // 005300d0  e843f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005300d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005300d7  740c                   -je 0x5300e5
    if (cpu.flags.zf)
    {
        goto L_0x005300e5;
    }
    // 005300d9  c705e0d15600ffffffff   -mov dword ptr [0x56d1e0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */) = 4294967295 /*0xffffffff*/;
    // 005300e3  eb20                   -jmp 0x530105
    goto L_0x00530105;
L_0x005300e5:
    // 005300e5  833de0d15600ff         +cmp dword ptr [0x56d1e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005300ec  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005300f1  7412                   -je 0x530105
    if (cpu.flags.zf)
    {
        goto L_0x00530105;
    }
    // 005300f3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300f7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300fb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300ff  ff15e0d15600           -call dword ptr [0x56d1e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530105:
    // 00530105  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530108(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530108  833de4d1560000         +cmp dword ptr [0x56d1e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053010f  751f                   -jne 0x530130
    if (!cpu.flags.zf)
    {
        goto L_0x00530130;
    }
    // 00530111  68e4d15600             -push 0x56d1e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689828 /*0x56d1e4*/;
    cpu.esp -= 4;
    // 00530116  681cbd5600             -push 0x56bd1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684508 /*0x56bd1c*/;
    cpu.esp -= 4;
    // 0053011b  e8f8f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530122  740c                   -je 0x530130
    if (cpu.flags.zf)
    {
        goto L_0x00530130;
    }
    // 00530124  c705e4d15600ffffffff   -mov dword ptr [0x56d1e4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */) = 4294967295 /*0xffffffff*/;
    // 0053012e  eb20                   -jmp 0x530150
    goto L_0x00530150;
L_0x00530130:
    // 00530130  833de4d15600ff         +cmp dword ptr [0x56d1e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530137  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053013c  7412                   -je 0x530150
    if (cpu.flags.zf)
    {
        goto L_0x00530150;
    }
    // 0053013e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530142  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530146  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053014a  ff15e4d15600           -call dword ptr [0x56d1e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530150:
    // 00530150  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530153(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530153  833de8d1560000         +cmp dword ptr [0x56d1e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053015a  751f                   -jne 0x53017b
    if (!cpu.flags.zf)
    {
        goto L_0x0053017b;
    }
    // 0053015c  68e8d15600             -push 0x56d1e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689832 /*0x56d1e8*/;
    cpu.esp -= 4;
    // 00530161  6834bd5600             -push 0x56bd34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684532 /*0x56bd34*/;
    cpu.esp -= 4;
    // 00530166  e8adf1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053016b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053016d  740c                   -je 0x53017b
    if (cpu.flags.zf)
    {
        goto L_0x0053017b;
    }
    // 0053016f  c705e8d15600ffffffff   -mov dword ptr [0x56d1e8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */) = 4294967295 /*0xffffffff*/;
    // 00530179  eb20                   -jmp 0x53019b
    goto L_0x0053019b;
L_0x0053017b:
    // 0053017b  833de8d15600ff         +cmp dword ptr [0x56d1e8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530182  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530187  7412                   -je 0x53019b
    if (cpu.flags.zf)
    {
        goto L_0x0053019b;
    }
    // 00530189  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053018d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530191  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530195  ff15e8d15600           -call dword ptr [0x56d1e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053019b:
    // 0053019b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53019e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053019e  833decd1560000         +cmp dword ptr [0x56d1ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301a5  751f                   -jne 0x5301c6
    if (!cpu.flags.zf)
    {
        goto L_0x005301c6;
    }
    // 005301a7  68ecd15600             -push 0x56d1ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689836 /*0x56d1ec*/;
    cpu.esp -= 4;
    // 005301ac  684cbd5600             -push 0x56bd4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684556 /*0x56bd4c*/;
    cpu.esp -= 4;
    // 005301b1  e862f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005301b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005301b8  740c                   -je 0x5301c6
    if (cpu.flags.zf)
    {
        goto L_0x005301c6;
    }
    // 005301ba  c705ecd15600ffffffff   -mov dword ptr [0x56d1ec], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */) = 4294967295 /*0xffffffff*/;
    // 005301c4  eb20                   -jmp 0x5301e6
    goto L_0x005301e6;
L_0x005301c6:
    // 005301c6  833decd15600ff         +cmp dword ptr [0x56d1ec], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301cd  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005301d2  7412                   -je 0x5301e6
    if (cpu.flags.zf)
    {
        goto L_0x005301e6;
    }
    // 005301d4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301d8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301dc  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301e0  ff15ecd15600           -call dword ptr [0x56d1ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005301e6:
    // 005301e6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5301e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005301e9  833df0d1560000         +cmp dword ptr [0x56d1f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301f0  751f                   -jne 0x530211
    if (!cpu.flags.zf)
    {
        goto L_0x00530211;
    }
    // 005301f2  68f0d15600             -push 0x56d1f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689840 /*0x56d1f0*/;
    cpu.esp -= 4;
    // 005301f7  6868bd5600             -push 0x56bd68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684584 /*0x56bd68*/;
    cpu.esp -= 4;
    // 005301fc  e817f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530201  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530203  740c                   -je 0x530211
    if (cpu.flags.zf)
    {
        goto L_0x00530211;
    }
    // 00530205  c705f0d15600ffffffff   -mov dword ptr [0x56d1f0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */) = 4294967295 /*0xffffffff*/;
    // 0053020f  eb20                   -jmp 0x530231
    goto L_0x00530231;
L_0x00530211:
    // 00530211  833df0d15600ff         +cmp dword ptr [0x56d1f0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530218  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053021d  7412                   -je 0x530231
    if (cpu.flags.zf)
    {
        goto L_0x00530231;
    }
    // 0053021f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530223  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530227  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053022b  ff15f0d15600           -call dword ptr [0x56d1f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530231:
    // 00530231  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530234  833df4d1560000         +cmp dword ptr [0x56d1f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053023b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053023c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053023e  751f                   -jne 0x53025f
    if (!cpu.flags.zf)
    {
        goto L_0x0053025f;
    }
    // 00530240  68f4d15600             -push 0x56d1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689844 /*0x56d1f4*/;
    cpu.esp -= 4;
    // 00530245  6884bd5600             -push 0x56bd84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684612 /*0x56bd84*/;
    cpu.esp -= 4;
    // 0053024a  e8c9f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053024f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530251  740c                   -je 0x53025f
    if (cpu.flags.zf)
    {
        goto L_0x0053025f;
    }
    // 00530253  c705f4d15600ffffffff   -mov dword ptr [0x56d1f4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */) = 4294967295 /*0xffffffff*/;
    // 0053025d  eb23                   -jmp 0x530282
    goto L_0x00530282;
L_0x0053025f:
    // 0053025f  833df4d15600ff         +cmp dword ptr [0x56d1f4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530266  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053026b  7415                   -je 0x530282
    if (cpu.flags.zf)
    {
        goto L_0x00530282;
    }
    // 0053026d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530270  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530273  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530276  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530279  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053027c  ff15f4d15600           -call dword ptr [0x56d1f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530282:
    // 00530282  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530283  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530286(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530286  833df8d1560000         +cmp dword ptr [0x56d1f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053028d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053028e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530290  751f                   -jne 0x5302b1
    if (!cpu.flags.zf)
    {
        goto L_0x005302b1;
    }
    // 00530292  68f8d15600             -push 0x56d1f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689848 /*0x56d1f8*/;
    cpu.esp -= 4;
    // 00530297  6898bd5600             -push 0x56bd98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684632 /*0x56bd98*/;
    cpu.esp -= 4;
    // 0053029c  e877f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005302a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005302a3  740c                   -je 0x5302b1
    if (cpu.flags.zf)
    {
        goto L_0x005302b1;
    }
    // 005302a5  c705f8d15600ffffffff   -mov dword ptr [0x56d1f8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */) = 4294967295 /*0xffffffff*/;
    // 005302af  eb23                   -jmp 0x5302d4
    goto L_0x005302d4;
L_0x005302b1:
    // 005302b1  833df8d15600ff         +cmp dword ptr [0x56d1f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005302b8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005302bd  7415                   -je 0x5302d4
    if (cpu.flags.zf)
    {
        goto L_0x005302d4;
    }
    // 005302bf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005302c2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005302c5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005302c8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005302cb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005302ce  ff15f8d15600           -call dword ptr [0x56d1f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005302d4:
    // 005302d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005302d5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5302d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005302d8  833dfcd1560000         +cmp dword ptr [0x56d1fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005302df  751f                   -jne 0x530300
    if (!cpu.flags.zf)
    {
        goto L_0x00530300;
    }
    // 005302e1  68fcd15600             -push 0x56d1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689852 /*0x56d1fc*/;
    cpu.esp -= 4;
    // 005302e6  68acbd5600             -push 0x56bdac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684652 /*0x56bdac*/;
    cpu.esp -= 4;
    // 005302eb  e828f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005302f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005302f2  740c                   -je 0x530300
    if (cpu.flags.zf)
    {
        goto L_0x00530300;
    }
    // 005302f4  c705fcd15600ffffffff   -mov dword ptr [0x56d1fc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */) = 4294967295 /*0xffffffff*/;
    // 005302fe  eb20                   -jmp 0x530320
    goto L_0x00530320;
L_0x00530300:
    // 00530300  833dfcd15600ff         +cmp dword ptr [0x56d1fc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530307  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053030c  7412                   -je 0x530320
    if (cpu.flags.zf)
    {
        goto L_0x00530320;
    }
    // 0053030e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530312  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530316  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053031a  ff15fcd15600           -call dword ptr [0x56d1fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530320:
    // 00530320  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530323(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530323  833d00d2560000         +cmp dword ptr [0x56d200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053032a  751f                   -jne 0x53034b
    if (!cpu.flags.zf)
    {
        goto L_0x0053034b;
    }
    // 0053032c  6800d25600             -push 0x56d200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689856 /*0x56d200*/;
    cpu.esp -= 4;
    // 00530331  68c4bd5600             -push 0x56bdc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684676 /*0x56bdc4*/;
    cpu.esp -= 4;
    // 00530336  e8ddefffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053033b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053033d  740c                   -je 0x53034b
    if (cpu.flags.zf)
    {
        goto L_0x0053034b;
    }
    // 0053033f  c70500d25600ffffffff   -mov dword ptr [0x56d200], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */) = 4294967295 /*0xffffffff*/;
    // 00530349  eb20                   -jmp 0x53036b
    goto L_0x0053036b;
L_0x0053034b:
    // 0053034b  833d00d25600ff         +cmp dword ptr [0x56d200], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530352  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530357  7412                   -je 0x53036b
    if (cpu.flags.zf)
    {
        goto L_0x0053036b;
    }
    // 00530359  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053035d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530361  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530365  ff1500d25600           -call dword ptr [0x56d200]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053036b:
    // 0053036b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53036e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053036e  833d04d2560000         +cmp dword ptr [0x56d204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530375  751f                   -jne 0x530396
    if (!cpu.flags.zf)
    {
        goto L_0x00530396;
    }
    // 00530377  6804d25600             -push 0x56d204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689860 /*0x56d204*/;
    cpu.esp -= 4;
    // 0053037c  68dcbd5600             -push 0x56bddc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684700 /*0x56bddc*/;
    cpu.esp -= 4;
    // 00530381  e892efffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530386  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530388  740c                   -je 0x530396
    if (cpu.flags.zf)
    {
        goto L_0x00530396;
    }
    // 0053038a  c70504d25600ffffffff   -mov dword ptr [0x56d204], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */) = 4294967295 /*0xffffffff*/;
    // 00530394  eb20                   -jmp 0x5303b6
    goto L_0x005303b6;
L_0x00530396:
    // 00530396  833d04d25600ff         +cmp dword ptr [0x56d204], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053039d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005303a2  7412                   -je 0x5303b6
    if (cpu.flags.zf)
    {
        goto L_0x005303b6;
    }
    // 005303a4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303a8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303ac  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303b0  ff1504d25600           -call dword ptr [0x56d204]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005303b6:
    // 005303b6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5303b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005303b9  833d08d2560000         +cmp dword ptr [0x56d208], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005303c0  751f                   -jne 0x5303e1
    if (!cpu.flags.zf)
    {
        goto L_0x005303e1;
    }
    // 005303c2  6808d25600             -push 0x56d208
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689864 /*0x56d208*/;
    cpu.esp -= 4;
    // 005303c7  68f0bd5600             -push 0x56bdf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684720 /*0x56bdf0*/;
    cpu.esp -= 4;
    // 005303cc  e847efffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005303d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005303d3  740c                   -je 0x5303e1
    if (cpu.flags.zf)
    {
        goto L_0x005303e1;
    }
    // 005303d5  c70508d25600ffffffff   -mov dword ptr [0x56d208], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */) = 4294967295 /*0xffffffff*/;
    // 005303df  eb20                   -jmp 0x530401
    goto L_0x00530401;
L_0x005303e1:
    // 005303e1  833d08d25600ff         +cmp dword ptr [0x56d208], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005303e8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005303ed  7412                   -je 0x530401
    if (cpu.flags.zf)
    {
        goto L_0x00530401;
    }
    // 005303ef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303f3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303f7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303fb  ff1508d25600           -call dword ptr [0x56d208]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530401:
    // 00530401  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530404  833d0cd2560000         +cmp dword ptr [0x56d20c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053040b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053040c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053040e  751f                   -jne 0x53042f
    if (!cpu.flags.zf)
    {
        goto L_0x0053042f;
    }
    // 00530410  680cd25600             -push 0x56d20c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689868 /*0x56d20c*/;
    cpu.esp -= 4;
    // 00530415  6804be5600             -push 0x56be04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684740 /*0x56be04*/;
    cpu.esp -= 4;
    // 0053041a  e8f9eeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053041f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530421  740c                   -je 0x53042f
    if (cpu.flags.zf)
    {
        goto L_0x0053042f;
    }
    // 00530423  c7050cd25600ffffffff   -mov dword ptr [0x56d20c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */) = 4294967295 /*0xffffffff*/;
    // 0053042d  eb26                   -jmp 0x530455
    goto L_0x00530455;
L_0x0053042f:
    // 0053042f  833d0cd25600ff         +cmp dword ptr [0x56d20c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530436  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053043b  7418                   -je 0x530455
    if (cpu.flags.zf)
    {
        goto L_0x00530455;
    }
    // 0053043d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530440  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530443  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530446  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530449  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053044c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053044f  ff150cd25600           -call dword ptr [0x56d20c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530455:
    // 00530455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530456  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530459(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530459  833d10d2560000         +cmp dword ptr [0x56d210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530460  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530461  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530463  751f                   -jne 0x530484
    if (!cpu.flags.zf)
    {
        goto L_0x00530484;
    }
    // 00530465  6810d25600             -push 0x56d210
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689872 /*0x56d210*/;
    cpu.esp -= 4;
    // 0053046a  6818be5600             -push 0x56be18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684760 /*0x56be18*/;
    cpu.esp -= 4;
    // 0053046f  e8a4eeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530474  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530476  740c                   -je 0x530484
    if (cpu.flags.zf)
    {
        goto L_0x00530484;
    }
    // 00530478  c70510d25600ffffffff   -mov dword ptr [0x56d210], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */) = 4294967295 /*0xffffffff*/;
    // 00530482  eb26                   -jmp 0x5304aa
    goto L_0x005304aa;
L_0x00530484:
    // 00530484  833d10d25600ff         +cmp dword ptr [0x56d210], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053048b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530490  7418                   -je 0x5304aa
    if (cpu.flags.zf)
    {
        goto L_0x005304aa;
    }
    // 00530492  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530495  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530498  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053049b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053049e  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005304a1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005304a4  ff1510d25600           -call dword ptr [0x56d210]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005304aa:
    // 005304aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005304ab  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5304ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005304ae  833d14d2560000         +cmp dword ptr [0x56d214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005304b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005304b6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005304b8  751f                   -jne 0x5304d9
    if (!cpu.flags.zf)
    {
        goto L_0x005304d9;
    }
    // 005304ba  6814d25600             -push 0x56d214
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689876 /*0x56d214*/;
    cpu.esp -= 4;
    // 005304bf  682cbe5600             -push 0x56be2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684780 /*0x56be2c*/;
    cpu.esp -= 4;
    // 005304c4  e84feeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005304c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005304cb  740c                   -je 0x5304d9
    if (cpu.flags.zf)
    {
        goto L_0x005304d9;
    }
    // 005304cd  c70514d25600ffffffff   -mov dword ptr [0x56d214], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */) = 4294967295 /*0xffffffff*/;
    // 005304d7  eb26                   -jmp 0x5304ff
    goto L_0x005304ff;
L_0x005304d9:
    // 005304d9  833d14d25600ff         +cmp dword ptr [0x56d214], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005304e0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005304e5  7418                   -je 0x5304ff
    if (cpu.flags.zf)
    {
        goto L_0x005304ff;
    }
    // 005304e7  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005304ea  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005304ed  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005304f0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005304f3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005304f6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005304f9  ff1514d25600           -call dword ptr [0x56d214]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005304ff:
    // 005304ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530500  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530503(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530503  833d18d2560000         +cmp dword ptr [0x56d218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053050a  751f                   -jne 0x53052b
    if (!cpu.flags.zf)
    {
        goto L_0x0053052b;
    }
    // 0053050c  6818d25600             -push 0x56d218
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689880 /*0x56d218*/;
    cpu.esp -= 4;
    // 00530511  6840be5600             -push 0x56be40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684800 /*0x56be40*/;
    cpu.esp -= 4;
    // 00530516  e8fdedffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053051b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053051d  740c                   -je 0x53052b
    if (cpu.flags.zf)
    {
        goto L_0x0053052b;
    }
    // 0053051f  c70518d25600ffffffff   -mov dword ptr [0x56d218], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */) = 4294967295 /*0xffffffff*/;
    // 00530529  eb1c                   -jmp 0x530547
    goto L_0x00530547;
L_0x0053052b:
    // 0053052b  833d18d25600ff         +cmp dword ptr [0x56d218], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530532  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530537  740e                   -je 0x530547
    if (cpu.flags.zf)
    {
        goto L_0x00530547;
    }
    // 00530539  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053053d  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530541  ff1518d25600           -call dword ptr [0x56d218]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530547:
    // 00530547  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53054a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053054a  833d1cd2560000         +cmp dword ptr [0x56d21c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530551  751f                   -jne 0x530572
    if (!cpu.flags.zf)
    {
        goto L_0x00530572;
    }
    // 00530553  681cd25600             -push 0x56d21c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689884 /*0x56d21c*/;
    cpu.esp -= 4;
    // 00530558  6850be5600             -push 0x56be50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684816 /*0x56be50*/;
    cpu.esp -= 4;
    // 0053055d  e8b6edffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530562  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530564  740c                   -je 0x530572
    if (cpu.flags.zf)
    {
        goto L_0x00530572;
    }
    // 00530566  c7051cd25600ffffffff   -mov dword ptr [0x56d21c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */) = 4294967295 /*0xffffffff*/;
    // 00530570  eb1c                   -jmp 0x53058e
    goto L_0x0053058e;
L_0x00530572:
    // 00530572  833d1cd25600ff         +cmp dword ptr [0x56d21c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530579  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053057e  740e                   -je 0x53058e
    if (cpu.flags.zf)
    {
        goto L_0x0053058e;
    }
    // 00530580  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530584  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530588  ff151cd25600           -call dword ptr [0x56d21c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053058e:
    // 0053058e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
