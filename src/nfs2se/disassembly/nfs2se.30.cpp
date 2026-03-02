#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 */
void Application::sub_4a73d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a73d0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a73d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a73d3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a73d4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a73d5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a73d8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a73db  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a73de  c70017744a00           -mov dword ptr [eax], 0x4a7417
    *app->getMemory<x86::reg32>(cpu.eax) = 4879383 /*0x4a7417*/;
    // 004a73e4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a73e7  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a73ea  c700f4734a00           -mov dword ptr [eax], 0x4a73f4
    *app->getMemory<x86::reg32>(cpu.eax) = 4879348 /*0x4a73f4*/;
    // 004a73f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73f1  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73f2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a73f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a73f4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a73f5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a73f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a73f8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a73f9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a73fa  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a73fd  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7400  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a7403  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7406  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a7409  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a740d  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a740f  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7412  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7413  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7414  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7415  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7417(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7417  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7418  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a741a  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a741b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a741e  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7421  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7424  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi));
    // 004a7427  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a742a  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a742c  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a742f  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7432  7405                   -je 0x4a7439
    if (cpu.flags.zf)
    {
        goto L_0x004a7439;
    }
    // 004a7434  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7437  7c4e                   -jl 0x4a7487
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7487;
    }
L_0x004a7439:
    // 004a7439  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004a743c  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a743f  0f6fd8                 -movq mm3, mm0
    cpu.mmx.mm3 = cpu.mmx.mm0;
    // 004a7442  0f6fe0                 -movq mm4, mm0
    cpu.mmx.mm4 = cpu.mmx.mm0;
    // 004a7445  0fe50f                 -pmulhw mm1, qword ptr [edi]
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.edi))) };
    // 004a7448  0fe55708               -pmulhw mm2, qword ptr [edi + 8]
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */))) };
    // 004a744c  0fe55f10               -pmulhw mm3, qword ptr [edi + 0x10]
    cpu.mmx.mm3 = { _mm_mulhi_epi16(cpu.mmx.mm3, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */))) };
    // 004a7450  0fe56718               -pmulhw mm4, qword ptr [edi + 0x18]
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */))) };
    // 004a7454  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a7458  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a745c  0fed5d10               -paddsw mm3, qword ptr [ebp + 0x10]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */))) };
    // 004a7460  0fed6518               -paddsw mm4, qword ptr [ebp + 0x18]
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */))) };
    // 004a7464  0f7f4d00               -movq qword ptr [ebp], mm1
    *app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004a7468  0f7f5508               -movq qword ptr [ebp + 8], mm2
    *app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004a746c  0f7f5d10               -movq qword ptr [ebp + 0x10], mm3
    *app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm3;
    // 004a7470  0f7f6518               -movq qword ptr [ebp + 0x18], mm4
    *app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm4;
    // 004a7474  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a7477  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a747a  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a747d  7fba                   -jg 0x4a7439
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7439;
    }
    // 004a747f  83f900                 +cmp ecx, 0
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
    // 004a7482  7503                   -jne 0x4a7487
    if (!cpu.flags.zf)
    {
        goto L_0x004a7487;
    }
    // 004a7484  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a7485  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7486  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7487:
    // 004a7487  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a748a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a748c  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
L_0x004a748f:
    // 004a748f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004a7491  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a7494  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a7497  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&*app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a749b  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004a749e  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&*app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004a74a2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a74a5  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a74a8  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a74ab  7ce2                   -jl 0x4a748f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a748f;
    }
    // 004a74ad  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a74ae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a74b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a74b0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a74b1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a74b3  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a74b4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a74b7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a74ba  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a74bd:
    // 004a74bd  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004a74c2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a74c5  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004a74ca  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a74cd  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004a74d0  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004a74d3  3500800000             -xor eax, 0x8000
    cpu.eax ^= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004a74d8  886439ff               -mov byte ptr [ecx + edi - 1], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1) = cpu.ah;
    // 004a74dc  83e901                 +sub ecx, 1
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
    // 004a74df  7fdc                   -jg 0x4a74bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a74bd;
    }
    // 004a74e1  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a74e2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a74e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a74e4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a74e5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a74e7  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a74e8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a74eb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a74ee  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 004a74f0  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a74f3  bb7cd54c00             -mov ebx, 0x4cd57c
    cpu.ebx = 5035388 /*0x4cd57c*/;
L_0x004a74f8:
    // 004a74f8  0f6f444ef8             -movq mm0, qword ptr [esi + ecx*2 - 8]
    cpu.mmx.mm0 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 2));
    // 004a74fd  0f6f4c4ef0             -movq mm1, qword ptr [esi + ecx*2 - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 2));
    // 004a7502  0f6f544ee8             -movq mm2, qword ptr [esi + ecx*2 - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 2));
    // 004a7507  0f6f5c4ee0             -movq mm3, qword ptr [esi + ecx*2 - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-32) /* -0x20 */ + cpu.ecx * 2));
    // 004a750c  0f6f644ed8             -movq mm4, qword ptr [esi + ecx*2 - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-40) /* -0x28 */ + cpu.ecx * 2));
    // 004a7511  0f6f6c4ed0             -movq mm5, qword ptr [esi + ecx*2 - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.ecx * 2));
    // 004a7516  0f6f744ec8             -movq mm6, qword ptr [esi + ecx*2 - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-56) /* -0x38 */ + cpu.ecx * 2));
    // 004a751b  0f6f7c4ec0             -movq mm7, qword ptr [esi + ecx*2 - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-64) /* -0x40 */ + cpu.ecx * 2));
    // 004a7520  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a7523  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004a7526  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004a7529  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004a752c  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004a752f  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004a7532  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004a7535  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004a7538  0f71d008               -psrlw mm0, 8
    cpu.mmx.mm0 = { _mm_srli_epi16(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a753c  0f71d108               -psrlw mm1, 8
    cpu.mmx.mm1 = { _mm_srli_epi16(cpu.mmx.mm1, 8 /*0x8*/) };
    // 004a7540  0f71d208               -psrlw mm2, 8
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 8 /*0x8*/) };
    // 004a7544  0f71d308               -psrlw mm3, 8
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 8 /*0x8*/) };
    // 004a7548  0f71d408               -psrlw mm4, 8
    cpu.mmx.mm4 = { _mm_srli_epi16(cpu.mmx.mm4, 8 /*0x8*/) };
    // 004a754c  0f71d508               -psrlw mm5, 8
    cpu.mmx.mm5 = { _mm_srli_epi16(cpu.mmx.mm5, 8 /*0x8*/) };
    // 004a7550  0f71d608               -psrlw mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi16(cpu.mmx.mm6, 8 /*0x8*/) };
    // 004a7554  0f71d708               -psrlw mm7, 8
    cpu.mmx.mm7 = { _mm_srli_epi16(cpu.mmx.mm7, 8 /*0x8*/) };
    // 004a7558  0f67c8                 -packuswb mm1, mm0
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm1, cpu.mmx.mm0); cpu.mmx.mm1 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a755b  0f67da                 -packuswb mm3, mm2
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm3, cpu.mmx.mm2); cpu.mmx.mm3 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a755e  0f67ec                 -packuswb mm5, mm4
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm5, cpu.mmx.mm4); cpu.mmx.mm5 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a7561  0f67fe                 -packuswb mm7, mm6
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm7, cpu.mmx.mm6); cpu.mmx.mm7 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a7564  0f6f03                 -movq mm0, qword ptr [ebx]
    cpu.mmx.mm0 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebx));
    // 004a7567  0fefc8                 -pxor mm1, mm0
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a756a  0fefd8                 -pxor mm3, mm0
    cpu.mmx.mm3 = { _mm_xor_si128(cpu.mmx.mm3, cpu.mmx.mm0) };
    // 004a756d  0fefe8                 -pxor mm5, mm0
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm0) };
    // 004a7570  0feff8                 -pxor mm7, mm0
    cpu.mmx.mm7 = { _mm_xor_si128(cpu.mmx.mm7, cpu.mmx.mm0) };
    // 004a7573  0f7f4c39f8             -movq qword ptr [ecx + edi - 8], mm1
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004a7578  0f7f5c39f0             -movq qword ptr [ecx + edi - 0x10], mm3
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004a757d  0f7f6c39e8             -movq qword ptr [ecx + edi - 0x18], mm5
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004a7582  0f7f7c39e0             -movq qword ptr [ecx + edi - 0x20], mm7
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004a7587  83e920                 +sub ecx, 0x20
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a758a  0f8f68ffffff           -jg 0x4a74f8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a74f8;
    }
    // 004a7590  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a7591  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a7594(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7594  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7595  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7597  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a7598  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a759b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a759e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a75a1:
    // 004a75a1  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004a75a6  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a75a9  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004a75ae  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a75b1  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004a75b4  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004a75b7  6689444ffe             -mov word ptr [edi + ecx*2 - 2], ax
    *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.ax;
    // 004a75bc  83e901                 +sub ecx, 1
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
    // 004a75bf  7fe0                   -jg 0x4a75a1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a75a1;
    }
    // 004a75c1  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a75c2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a75c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a75c4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a75c5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a75c7  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a75c8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a75cb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a75ce  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a75d1  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a75d4:
    // 004a75d4  0f6f4431f8             -movq mm0, qword ptr [ecx + esi - 8]
    cpu.mmx.mm0 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1));
    // 004a75d9  0f6f4c31f0             -movq mm1, qword ptr [ecx + esi - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.esi * 1));
    // 004a75de  0f6f5431e8             -movq mm2, qword ptr [ecx + esi - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.esi * 1));
    // 004a75e3  0f6f5c31e0             -movq mm3, qword ptr [ecx + esi - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.esi * 1));
    // 004a75e8  0f6f6431d8             -movq mm4, qword ptr [ecx + esi - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.esi * 1));
    // 004a75ed  0f6f6c31d0             -movq mm5, qword ptr [ecx + esi - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.esi * 1));
    // 004a75f2  0f6f7431c8             -movq mm6, qword ptr [ecx + esi - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.esi * 1));
    // 004a75f7  0f6f7c31c0             -movq mm7, qword ptr [ecx + esi - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.esi * 1));
    // 004a75fc  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a75ff  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004a7602  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004a7605  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004a7608  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004a760b  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004a760e  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004a7611  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004a7614  0f7f4439f8             -movq qword ptr [ecx + edi - 8], mm0
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm0;
    // 004a7619  0f7f4c39f0             -movq qword ptr [ecx + edi - 0x10], mm1
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004a761e  0f7f5439e8             -movq qword ptr [ecx + edi - 0x18], mm2
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm2;
    // 004a7623  0f7f5c39e0             -movq qword ptr [ecx + edi - 0x20], mm3
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004a7628  0f7f6439d8             -movq qword ptr [ecx + edi - 0x28], mm4
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.edi * 1) = cpu.mmx.mm4;
    // 004a762d  0f7f6c39d0             -movq qword ptr [ecx + edi - 0x30], mm5
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004a7632  0f7f7439c8             -movq qword ptr [ecx + edi - 0x38], mm6
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.edi * 1) = cpu.mmx.mm6;
    // 004a7637  0f7f7c39c0             -movq qword ptr [ecx + edi - 0x40], mm7
    *app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004a763c  83e940                 +sub ecx, 0x40
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a763f  7f93                   -jg 0x4a75d4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a75d4;
    }
    // 004a7641  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a7642  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7643  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7644(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7644  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7645  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7647  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7648  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7649  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a764c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a764f  0fefc0                 -pxor mm0, mm0
    cpu.mmx.mm0 = { _mm_xor_si128(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a7652  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7655  7e2d                   -jle 0x4a7684
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7684;
    }
    // 004a7657  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a765a:
    // 004a765a  0f7f07                 -movq qword ptr [edi], mm0
    *app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm0;
    // 004a765d  0f7f4708               -movq qword ptr [edi + 8], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm0;
    // 004a7661  0f7f4710               -movq qword ptr [edi + 0x10], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm0;
    // 004a7665  0f7f4718               -movq qword ptr [edi + 0x18], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm0;
    // 004a7669  0f7f4720               -movq qword ptr [edi + 0x20], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm0;
    // 004a766d  0f7f4728               -movq qword ptr [edi + 0x28], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm0;
    // 004a7671  0f7f4730               -movq qword ptr [edi + 0x30], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm0;
    // 004a7675  0f7f4738               -movq qword ptr [edi + 0x38], mm0
    *app->getMemory<x86::reg64>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm0;
    // 004a7679  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a767c  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a767f  7fd9                   -jg 0x4a765a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a765a;
    }
    // 004a7681  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a7684:
    // 004a7684  83f900                 +cmp ecx, 0
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
    // 004a7687  7e0b                   -jle 0x4a7694
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7694;
    }
    // 004a7689  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&*app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004a768c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a768f  83e901                 +sub ecx, 1
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
    // 004a7692  7ff0                   -jg 0x4a7684
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7684;
    }
L_0x004a7694:
    // 004a7694  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7695  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7696  0f77                   -emms 
    cpu.mmx.init();
    // 004a7698  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7699  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a76a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a76a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a76a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a76a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a76a3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a76a7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a76ab  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a76ae  48                     -dec eax
    (cpu.eax)--;
    // 004a76af  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a76b2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a76b5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a76b8  8b5a0d                 -mov ebx, dword ptr [edx + 0xd]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004a76bb  40                     -inc eax
    (cpu.eax)++;
    // 004a76bc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a76bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a76c1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a76c3  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a76c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a76c8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a76ca  7501                   -jne 0x4a76cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a76cd;
    }
    // 004a76cc  40                     -inc eax
    (cpu.eax)++;
L_0x004a76cd:
    // 004a76cd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a76d1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a76d4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a76d7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a76da  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a76dd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a76df  885110                 -mov byte ptr [ecx + 0x10], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004a76e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a76e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a76e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a76e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a76e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a76e8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a76ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a76f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a76f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a76f1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a76f5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a76f9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a76fc  48                     -dec eax
    (cpu.eax)--;
    // 004a76fd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a7700  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a7703  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7705  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7708  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a770b  40                     -inc eax
    (cpu.eax)++;
    // 004a770c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a770e  7501                   -jne 0x4a7711
    if (!cpu.flags.zf)
    {
        goto L_0x004a7711;
    }
    // 004a7710  40                     -inc eax
    (cpu.eax)++;
L_0x004a7711:
    // 004a7711  8b510b                 -mov edx, dword ptr [ecx + 0xb]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(11) /* 0xb */);
    // 004a7714  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7717  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7719  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a771a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a771c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a771c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a771d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a771e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a771f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7720  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7723  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7727  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a772b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a772f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7731  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a7734  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7736  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7738  7572                   -jne 0x4a77ac
    if (!cpu.flags.zf)
    {
        goto L_0x004a77ac;
    }
L_0x004a773a:
    // 004a773a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a773e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7741  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7742  7572                   -jne 0x4a77b6
    if (!cpu.flags.zf)
    {
        goto L_0x004a77b6;
    }
L_0x004a7744:
    // 004a7744  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7746  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a774b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a774e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004a7752  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7754  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a7757  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a775a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a775c  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004a7761  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7764  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a7767  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a776a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a776d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a776f  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a7772  88042f                 -mov byte ptr [edi + ebp], al
    *app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004a7775  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7777  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004a777b  88430d                 -mov byte ptr [ebx + 0xd], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a777e  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7781  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a7784  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7786  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7788  897304                 -mov dword ptr [ebx + 4], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a778b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a778e  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a7794  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7796  8b430d                 -mov eax, dword ptr [ebx + 0xd]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004a7799  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a779b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a779e  c6430f01               -mov byte ptr [ebx + 0xf], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a77a2  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a77a4  83c404                 +add esp, 4
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
    // 004a77a7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77a8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77a9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77aa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a77ac:
    // 004a77ac  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a77af  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a77b2  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a77b4  eb84                   -jmp 0x4a773a
    goto L_0x004a773a;
L_0x004a77b6:
    // 004a77b6  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a77b9  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a77bc  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a77bf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a77c2  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a77c5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a77c6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a77c9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a77ca  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a77ce  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a77d2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a77d3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a77d4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a77d5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a77d6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a77d7  e8404c0000             -call 0x4ac41c
    cpu.esp -= 4;
    sub_4ac41c(app, cpu);
    if (cpu.terminate) return;
    // 004a77dc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a77df  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a77e2  c1e810                 +shr eax, 0x10
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
    // 004a77e5  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a77e8  e957ffffff             -jmp 0x4a7744
    goto L_0x004a7744;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a77f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a77f0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a77f4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a77f8  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a77fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a77fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a77fc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a77fd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a77fe  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a77ff  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7800  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7803  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7807  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a780b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a780f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7811  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a7814  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7816  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7818  0f85c7000000           -jne 0x4a78e5
    if (!cpu.flags.zf)
    {
        goto L_0x004a78e5;
    }
L_0x004a781e:
    // 004a781e  807b0e00               +cmp byte ptr [ebx + 0xe], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7822  7406                   -je 0x4a782a
    if (cpu.flags.zf)
    {
        goto L_0x004a782a;
    }
    // 004a7824  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7825  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a7828  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004a782a:
    // 004a782a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a782e  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a7834  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7837  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7838  7432                   -je 0x4a786c
    if (cpu.flags.zf)
    {
        goto L_0x004a786c;
    }
    // 004a783a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a783d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7840  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7843  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a7846  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a7849  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a784a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a784d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a784e  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7852  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7856  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7857  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7858  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7859  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a785a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a785b  e8bc4b0000             -call 0x4ac41c
    cpu.esp -= 4;
    sub_4ac41c(app, cpu);
    if (cpu.terminate) return;
    // 004a7860  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a7863  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a7866  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7869  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a786c:
    // 004a786c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a786e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004a7872  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7875  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7877  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a787c  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a787f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7881  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7884  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7886  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004a788b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a788e  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a7891  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7894  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7897  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7899  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a789c  88042f                 -mov byte ptr [edi + ebp], al
    *app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004a789f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a78a1  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004a78a5  88430d                 -mov byte ptr [ebx + 0xd], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a78a8  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a78ab  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a78ae  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a78b0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a78b2  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a78b5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a78b7  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a78ba  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a78bd  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a78c3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a78c5  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a78c8  892b                   -mov dword ptr [ebx], ebp
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004a78ca  39d0                   +cmp eax, edx
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
    // 004a78cc  7224                   -jb 0x4a78f2
    if (cpu.flags.cf)
    {
        goto L_0x004a78f2;
    }
    // 004a78ce  0333                   -add esi, dword ptr [ebx]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx)));
    // 004a78d0  c6430e01               -mov byte ptr [ebx + 0xe], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
    // 004a78d4  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004a78d6  88430c                 -mov byte ptr [ebx + 0xc], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004a78d9  c6430f01               -mov byte ptr [ebx + 0xf], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a78dd  83c404                 +add esp, 4
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
    // 004a78e0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78e1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78e2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78e3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a78e5:
    // 004a78e5  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a78e8  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a78eb  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a78ed  e92cffffff             -jmp 0x4a781e
    goto L_0x004a781e;
L_0x004a78f2:
    // 004a78f2  c6430e00               -mov byte ptr [ebx + 0xe], 0
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a78f6  c6430f01               -mov byte ptr [ebx + 0xf], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a78fa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a78fd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7900  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7901  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7904  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7905  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7906  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a790a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a790e  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a7911  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7913  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7919  732c                   -jae 0x4a7947
    if (!cpu.flags.cf)
    {
        goto L_0x004a7947;
    }
    // 004a791b  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7921  7324                   -jae 0x4a7947
    if (!cpu.flags.cf)
    {
        goto L_0x004a7947;
    }
L_0x004a7923:
    // 004a7923  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a7926  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a792c  724b                   -jb 0x4a7979
    if (cpu.flags.cf)
    {
        goto L_0x004a7979;
    }
    // 004a792e  7660                   -jbe 0x4a7990
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7990;
    }
    // 004a7930  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a7933  c702a0764a00           -mov dword ptr [edx], 0x4a76a0
    *app->getMemory<x86::reg32>(cpu.edx) = 4880032 /*0x4a76a0*/;
    // 004a7939  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a793c  c7001c774a00           -mov dword ptr [eax], 0x4a771c
    *app->getMemory<x86::reg32>(cpu.eax) = 4880156 /*0x4a771c*/;
    // 004a7942  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7944  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7945  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7946  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7947:
    // 004a7947  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a794a  39f2                   +cmp edx, esi
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
    // 004a794c  74d5                   -je 0x4a7923
    if (cpu.flags.zf)
    {
        goto L_0x004a7923;
    }
    // 004a794e  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7954  7608                   -jbe 0x4a795e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a795e;
    }
    // 004a7956  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a795c  77c5                   -ja 0x4a7923
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7923;
    }
L_0x004a795e:
    // 004a795e  c6400e00               -mov byte ptr [eax + 0xe], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a7962  c6400f00               -mov byte ptr [eax + 0xf], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004a7966  c6401000               -mov byte ptr [eax + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a796a  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a7971  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a7977  ebaa                   -jmp 0x4a7923
    goto L_0x004a7923;
L_0x004a7979:
    // 004a7979  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a797c  c702f0764a00           -mov dword ptr [edx], 0x4a76f0
    *app->getMemory<x86::reg32>(cpu.edx) = 4880112 /*0x4a76f0*/;
    // 004a7982  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a7985  c700fc774a00           -mov dword ptr [eax], 0x4a77fc
    *app->getMemory<x86::reg32>(cpu.eax) = 4880380 /*0x4a77fc*/;
    // 004a798b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a798d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a798e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a798f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7990:
    // 004a7990  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a7993  c702e8764a00           -mov dword ptr [edx], 0x4a76e8
    *app->getMemory<x86::reg32>(cpu.edx) = 4880104 /*0x4a76e8*/;
    // 004a7999  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a799c  c700f0774a00           -mov dword ptr [eax], 0x4a77f0
    *app->getMemory<x86::reg32>(cpu.eax) = 4880368 /*0x4a77f0*/;
    // 004a79a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a79a4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a79a5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a79a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a79a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a79a8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a79ac  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a79b2  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a79b9  c6400e00               -mov byte ptr [eax + 0xe], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a79bd  c6400d00               -mov byte ptr [eax + 0xd], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 004a79c1  c6400f00               -mov byte ptr [eax + 0xf], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004a79c5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a79c9  c6401001               -mov byte ptr [eax + 0x10], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a79cd  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a79d0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a79d4  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a79d7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a79db  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a79de  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a79e1  c70004794a00           -mov dword ptr [eax], 0x4a7904
    *app->getMemory<x86::reg32>(cpu.eax) = 4880644 /*0x4a7904*/;
    // 004a79e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a79e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a79f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a79f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a79f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a79f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a79f3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a79f7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a79fb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a79fe  48                     -dec eax
    (cpu.eax)--;
    // 004a79ff  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a7a02  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a7a05  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7a08  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a7a0b  40                     -inc eax
    (cpu.eax)++;
    // 004a7a0c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a7a0f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a7a11  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7a13  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a7a16  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7a18  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a7a1a  7501                   -jne 0x4a7a1d
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a1d;
    }
    // 004a7a1c  40                     -inc eax
    (cpu.eax)++;
L_0x004a7a1d:
    // 004a7a1d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a7a21  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a7a24  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a7a27  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a7a2a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7a2d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7a2f  885112                 -mov byte ptr [ecx + 0x12], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a7a32  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a33  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a34  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7a38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7a38  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7a40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7a41  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7a45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7a49  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a7a4c  48                     -dec eax
    (cpu.eax)--;
    // 004a7a4d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a7a50  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a7a53  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7a55  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7a58  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a7a5b  40                     -inc eax
    (cpu.eax)++;
    // 004a7a5c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a7a5e  7501                   -jne 0x4a7a61
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a61;
    }
    // 004a7a60  40                     -inc eax
    (cpu.eax)++;
L_0x004a7a61:
    // 004a7a61  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a7a64  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7a67  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7a69  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7a6c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7a6d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7a6e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7a6f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7a70  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7a73  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7a77  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a7a7b  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7a7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7a81  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a7a84  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7a86  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7a88  0f85b9000000           -jne 0x4a7b47
    if (!cpu.flags.zf)
    {
        goto L_0x004a7b47;
    }
L_0x004a7a8e:
    // 004a7a8e  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a7a92  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7a95  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7a96  0f85be000000           -jne 0x4a7b5a
    if (!cpu.flags.zf)
    {
        goto L_0x004a7b5a;
    }
L_0x004a7a9c:
    // 004a7a9c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7a9e  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004a7aa2  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a7aa5  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7aa8  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7aac  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a7ab1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7ab3  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a7ab8  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004a7abd  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7ac0  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004a7ac4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7ac7  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7aca  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7acc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7ace  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7ad0  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a7ad3  884500                 -mov byte ptr [ebp], al
    *app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a7ad6  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7ad8  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a7add  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7ae0  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004a7ae5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7ae7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7aea  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7aed  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004a7af0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7af3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7af6  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a7af9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7afc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7aff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7b01  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a7b04  884501                 -mov byte ptr [ebp + 1], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a7b07  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7b09  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a7b0d  88430e                 -mov byte ptr [ebx + 0xe], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a7b10  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7b12  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004a7b16  88430f                 -mov byte ptr [ebx + 0xf], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a7b19  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7b1c  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a7b1f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7b21  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a7b23  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a7b26  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7b29  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a7b2f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7b31  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004a7b34  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a7b36  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a7b39  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a7b3d  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a7b3f  83c408                 +add esp, 8
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
    // 004a7b42  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b43  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b44  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b45  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7b46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7b47:
    // 004a7b47  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a7b4a  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a7b4d  8816                   -mov byte ptr [esi], dl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004a7b4f  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7b50  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a7b53  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a7b55  e934ffffff             -jmp 0x4a7a8e
    goto L_0x004a7a8e;
L_0x004a7b5a:
    // 004a7b5a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7b5d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7b60  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7b63  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a7b66  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a7b69  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7b6a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a7b6d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7b6e  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7b72  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7b76  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7b77  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7b78  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7b79  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7b7a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7b7b  e81c490000             -call 0x4ac49c
    cpu.esp -= 4;
    sub_4ac49c(app, cpu);
    if (cpu.terminate) return;
    // 004a7b80  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a7b83  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a7b86  c1e810                 +shr eax, 0x10
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
    // 004a7b89  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7b8c  e90bffffff             -jmp 0x4a7a9c
    goto L_0x004a7a9c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7b94  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a7b98  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7b9c  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a7b9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7ba0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7ba1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7ba2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7ba3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7ba4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7ba7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7bab  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7baf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a7bb3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7bb5  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a7bb8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7bba  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7bbc  0f8510010000           -jne 0x4a7cd2
    if (!cpu.flags.zf)
    {
        goto L_0x004a7cd2;
    }
L_0x004a7bc2:
    // 004a7bc2  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7bc6  740c                   -je 0x4a7bd4
    if (cpu.flags.zf)
    {
        goto L_0x004a7bd4;
    }
    // 004a7bc8  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7bc9  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004a7bcc  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a7bce  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7bcf  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a7bd2  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004a7bd4:
    // 004a7bd4  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7bd8  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a7bde  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7be1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7be2  7432                   -je 0x4a7c16
    if (cpu.flags.zf)
    {
        goto L_0x004a7c16;
    }
    // 004a7be4  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7be7  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7bea  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7bed  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a7bf0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a7bf3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7bf4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a7bf7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7bf8  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7bfc  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7c00  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7c01  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7c02  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7c03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7c04  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7c05  e892480000             -call 0x4ac49c
    cpu.esp -= 4;
    sub_4ac49c(app, cpu);
    if (cpu.terminate) return;
    // 004a7c0a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a7c0d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a7c10  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7c13  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a7c16:
    // 004a7c16  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7c18  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004a7c1d  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004a7c21  2b4b04                 -sub ecx, dword ptr [ebx + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004a7c24  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a7c27  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a7c2a  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004a7c2f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7c32  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004a7c36  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7c39  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7c3c  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7c3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7c40  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7c42  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a7c45  884500                 -mov byte ptr [ebp], al
    *app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a7c48  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7c4a  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a7c4f  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7c52  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004a7c57  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7c59  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7c5c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7c5f  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004a7c62  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7c65  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a7c68  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a7c6b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7c6e  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7c71  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7c73  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a7c76  884501                 -mov byte ptr [ebp + 1], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a7c79  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7c7b  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a7c7f  88430e                 -mov byte ptr [ebx + 0xe], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a7c82  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7c84  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004a7c88  88430f                 -mov byte ptr [ebx + 0xf], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a7c8b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7c8e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7c91  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7c93  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7c95  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7c98  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a7c9a  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a7c9d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7ca0  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a7ca6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7ca8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7cab  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a7cad  39c8                   +cmp eax, ecx
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
    // 004a7caf  7234                   -jb 0x4a7ce5
    if (cpu.flags.cf)
    {
        goto L_0x004a7ce5;
    }
    // 004a7cb1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7cb3  c6431001               -mov byte ptr [ebx + 0x10], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a7cb7  8a0446                 -mov al, byte ptr [esi + eax*2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 2);
    // 004a7cba  88430c                 -mov byte ptr [ebx + 0xc], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004a7cbd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7cbf  8a444601               -mov al, byte ptr [esi + eax*2 + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 2);
    // 004a7cc3  88430d                 -mov byte ptr [ebx + 0xd], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a7cc6  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a7cca  83c404                 +add esp, 4
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
    // 004a7ccd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cce  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ccf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cd0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7cd2:
    // 004a7cd2  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a7cd5  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a7cd8  8816                   -mov byte ptr [esi], dl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004a7cda  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7cdb  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a7cde  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a7ce0  e9ddfeffff             -jmp 0x4a7bc2
    goto L_0x004a7bc2;
L_0x004a7ce5:
    // 004a7ce5  c6431000               -mov byte ptr [ebx + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a7ce9  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a7ced  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7cf0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cf1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cf2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cf3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cf4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7cf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7cf8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7cf9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7cfa  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7cfe  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a7d02  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a7d05  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7d07  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d0d  732c                   -jae 0x4a7d3b
    if (!cpu.flags.cf)
    {
        goto L_0x004a7d3b;
    }
    // 004a7d0f  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d15  7324                   -jae 0x4a7d3b
    if (!cpu.flags.cf)
    {
        goto L_0x004a7d3b;
    }
L_0x004a7d17:
    // 004a7d17  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a7d1a  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d20  724b                   -jb 0x4a7d6d
    if (cpu.flags.cf)
    {
        goto L_0x004a7d6d;
    }
    // 004a7d22  7660                   -jbe 0x4a7d84
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7d84;
    }
    // 004a7d24  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a7d27  c702f0794a00           -mov dword ptr [edx], 0x4a79f0
    *app->getMemory<x86::reg32>(cpu.edx) = 4880880 /*0x4a79f0*/;
    // 004a7d2d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a7d30  c7006c7a4a00           -mov dword ptr [eax], 0x4a7a6c
    *app->getMemory<x86::reg32>(cpu.eax) = 4881004 /*0x4a7a6c*/;
    // 004a7d36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7d38  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d39  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7d3b:
    // 004a7d3b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7d3e  39f2                   +cmp edx, esi
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
    // 004a7d40  74d5                   -je 0x4a7d17
    if (cpu.flags.zf)
    {
        goto L_0x004a7d17;
    }
    // 004a7d42  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d48  7608                   -jbe 0x4a7d52
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7d52;
    }
    // 004a7d4a  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d50  77c5                   -ja 0x4a7d17
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7d17;
    }
L_0x004a7d52:
    // 004a7d52  c6401000               -mov byte ptr [eax + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a7d56  c6401100               -mov byte ptr [eax + 0x11], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a7d5a  c6401200               -mov byte ptr [eax + 0x12], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004a7d5e  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a7d65  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a7d6b  ebaa                   -jmp 0x4a7d17
    goto L_0x004a7d17;
L_0x004a7d6d:
    // 004a7d6d  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a7d70  c702407a4a00           -mov dword ptr [edx], 0x4a7a40
    *app->getMemory<x86::reg32>(cpu.edx) = 4880960 /*0x4a7a40*/;
    // 004a7d76  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a7d79  c700a07b4a00           -mov dword ptr [eax], 0x4a7ba0
    *app->getMemory<x86::reg32>(cpu.eax) = 4881312 /*0x4a7ba0*/;
    // 004a7d7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7d81  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d82  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7d84:
    // 004a7d84  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a7d87  c702387a4a00           -mov dword ptr [edx], 0x4a7a38
    *app->getMemory<x86::reg32>(cpu.edx) = 4880952 /*0x4a7a38*/;
    // 004a7d8d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a7d90  c700947b4a00           -mov dword ptr [eax], 0x4a7b94
    *app->getMemory<x86::reg32>(cpu.eax) = 4881300 /*0x4a7b94*/;
    // 004a7d96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7d98  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d99  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7d9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7d9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7d9c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a7da0  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a7da6  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a7dad  c6401000               -mov byte ptr [eax + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a7db1  c6401100               -mov byte ptr [eax + 0x11], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a7db5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7db9  c6401200               -mov byte ptr [eax + 0x12], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004a7dbd  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a7dc0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7dc4  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a7dc7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a7dcb  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a7dce  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a7dd1  c700f87c4a00           -mov dword ptr [eax], 0x4a7cf8
    *app->getMemory<x86::reg32>(cpu.eax) = 4881656 /*0x4a7cf8*/;
    // 004a7dd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7dd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7de0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7de1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7de2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7de3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a7de7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a7deb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a7dee  48                     -dec eax
    (cpu.eax)--;
    // 004a7def  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a7df2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a7df5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7df8  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a7dfb  40                     -inc eax
    (cpu.eax)++;
    // 004a7dfc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a7dff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a7e01  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7e03  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a7e06  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7e08  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a7e0a  7501                   -jne 0x4a7e0d
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e0d;
    }
    // 004a7e0c  40                     -inc eax
    (cpu.eax)++;
L_0x004a7e0d:
    // 004a7e0d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a7e11  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a7e14  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a7e17  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a7e1a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a7e1d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7e1f  885112                 -mov byte ptr [ecx + 0x12], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a7e22  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e23  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e24  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7e28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e28  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7e2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7e31  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7e35  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7e39  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a7e3c  48                     -dec eax
    (cpu.eax)--;
    // 004a7e3d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a7e40  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a7e43  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7e45  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7e48  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a7e4b  40                     -inc eax
    (cpu.eax)++;
    // 004a7e4c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a7e4e  7501                   -jne 0x4a7e51
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e51;
    }
    // 004a7e50  40                     -inc eax
    (cpu.eax)++;
L_0x004a7e51:
    // 004a7e51  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a7e54  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a7e57  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7e59  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7e5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e5c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7e5d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7e5e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7e5f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7e60  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7e63  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7e67  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7e6b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a7e6f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7e71  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a7e74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7e76  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7e78  0f8581000000           -jne 0x4a7eff
    if (!cpu.flags.zf)
    {
        goto L_0x004a7eff;
    }
L_0x004a7e7e:
    // 004a7e7e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7e82  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7e85  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7e86  0f8582000000           -jne 0x4a7f0e
    if (!cpu.flags.zf)
    {
        goto L_0x004a7f0e;
    }
L_0x004a7e8c:
    // 004a7e8c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7e8e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a7e93  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7e96  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004a7e9a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7e9c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7e9f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7ea2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7ea4  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004a7ea7  66891428               -mov word ptr [eax + ebp], dx
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a7eab  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7ead  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004a7eb0  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7eb3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a7eb6  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7eb9  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a7ebc  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004a7ec0  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7ec2  66891428               -mov word ptr [eax + ebp], dx
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a7ec6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7ec8  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a7ecd  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004a7ed1  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7ed4  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a7ed7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7ed9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a7edb  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a7ede  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7ee1  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a7ee7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7ee9  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004a7eec  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a7eee  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a7ef1  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a7ef5  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a7ef7  83c404                 +add esp, 4
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
    // 004a7efa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7efb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7efc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7efd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7efe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7eff:
    // 004a7eff  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004a7f02  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a7f06  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a7f09  e970ffffff             -jmp 0x4a7e7e
    goto L_0x004a7e7e;
L_0x004a7f0e:
    // 004a7f0e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7f11  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7f14  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7f17  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a7f1a  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a7f1d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7f1e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a7f21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7f22  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7f26  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7f2a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7f2b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7f2c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7f2d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7f2e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7f2f  e808460000             -call 0x4ac53c
    cpu.esp -= 4;
    sub_4ac53c(app, cpu);
    if (cpu.terminate) return;
    // 004a7f34  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a7f37  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a7f3a  c1e810                 +shr eax, 0x10
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
    // 004a7f3d  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7f40  e947ffffff             -jmp 0x4a7e8c
    goto L_0x004a7e8c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7f48  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a7f4c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a7f50  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a7f52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7f54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7f54  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7f55  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7f56  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7f57  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7f58  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7f5b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7f5f  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7f63  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a7f67  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7f69  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a7f6c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7f6e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a7f70  0f85d5000000           -jne 0x4a804b
    if (!cpu.flags.zf)
    {
        goto L_0x004a804b;
    }
L_0x004a7f76:
    // 004a7f76  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7f7a  740a                   -je 0x4a7f86
    if (cpu.flags.zf)
    {
        goto L_0x004a7f86;
    }
    // 004a7f7c  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7f7f  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a7f83  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004a7f86:
    // 004a7f86  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a7f8a  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a7f90  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a7f93  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a7f94  7432                   -je 0x4a7fc8
    if (cpu.flags.zf)
    {
        goto L_0x004a7fc8;
    }
    // 004a7f96  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7f99  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a7f9c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7f9f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a7fa2  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a7fa5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7fa6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a7fa9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7faa  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7fae  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7fb2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7fb3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7fb4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7fb5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7fb6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7fb7  e880450000             -call 0x4ac53c
    cpu.esp -= 4;
    sub_4ac53c(app, cpu);
    if (cpu.terminate) return;
    // 004a7fbc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a7fbf  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a7fc2  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7fc5  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a7fc8:
    // 004a7fc8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7fca  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7fcd  0fbf1446               -movsx edx, word ptr [esi + eax*2]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004a7fd1  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a7fd6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7fd8  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a7fdb  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004a7fde  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a7fe1  6689042a               -mov word ptr [edx + ebp], ax
    *app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004a7fe5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a7fe7  8b0446                 -mov eax, dword ptr [esi + eax*2]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 004a7fea  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a7fed  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a7ff0  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a7ff3  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a7ff6  0fbf042a               -movsx eax, word ptr [edx + ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1)));
    // 004a7ffa  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a7ffc  6689042a               -mov word ptr [edx + ebp], ax
    *app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004a8000  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8002  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a8007  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004a800b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a800e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8011  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8013  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8015  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8018  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a801a  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a801d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8020  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8026  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8028  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a802b  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a802d  39c8                   +cmp eax, ecx
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
    // 004a802f  7229                   -jb 0x4a805a
    if (cpu.flags.cf)
    {
        goto L_0x004a805a;
    }
    // 004a8031  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8033  c6431001               -mov byte ptr [ebx + 0x10], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a8037  668b0446               -mov ax, word ptr [esi + eax*2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2);
    // 004a803b  6689430c               -mov word ptr [ebx + 0xc], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004a803f  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a8043  83c404                 +add esp, 4
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
    // 004a8046  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8047  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8048  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8049  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a804a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a804b:
    // 004a804b  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004a804e  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a8052  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a8055  e91cffffff             -jmp 0x4a7f76
    goto L_0x004a7f76;
L_0x004a805a:
    // 004a805a  c6431000               -mov byte ptr [ebx + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a805e  c6431101               -mov byte ptr [ebx + 0x11], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a8062  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8065  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8066  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8067  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8068  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a806c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a806c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a806d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a806e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8072  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8076  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a8079  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a807b  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8081  732c                   -jae 0x4a80af
    if (!cpu.flags.cf)
    {
        goto L_0x004a80af;
    }
    // 004a8083  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8089  7324                   -jae 0x4a80af
    if (!cpu.flags.cf)
    {
        goto L_0x004a80af;
    }
L_0x004a808b:
    // 004a808b  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a808e  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8094  724b                   -jb 0x4a80e1
    if (cpu.flags.cf)
    {
        goto L_0x004a80e1;
    }
    // 004a8096  7660                   -jbe 0x4a80f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a80f8;
    }
    // 004a8098  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a809b  c702e07d4a00           -mov dword ptr [edx], 0x4a7de0
    *app->getMemory<x86::reg32>(cpu.edx) = 4881888 /*0x4a7de0*/;
    // 004a80a1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a80a4  c7005c7e4a00           -mov dword ptr [eax], 0x4a7e5c
    *app->getMemory<x86::reg32>(cpu.eax) = 4882012 /*0x4a7e5c*/;
    // 004a80aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a80ac  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a80af:
    // 004a80af  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a80b2  39f2                   +cmp edx, esi
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
    // 004a80b4  74d5                   -je 0x4a808b
    if (cpu.flags.zf)
    {
        goto L_0x004a808b;
    }
    // 004a80b6  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a80bc  7608                   -jbe 0x4a80c6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a80c6;
    }
    // 004a80be  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a80c4  77c5                   -ja 0x4a808b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a808b;
    }
L_0x004a80c6:
    // 004a80c6  c6401000               -mov byte ptr [eax + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a80ca  c6401100               -mov byte ptr [eax + 0x11], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a80ce  c6401200               -mov byte ptr [eax + 0x12], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004a80d2  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a80d9  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a80df  ebaa                   -jmp 0x4a808b
    goto L_0x004a808b;
L_0x004a80e1:
    // 004a80e1  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a80e4  c702307e4a00           -mov dword ptr [edx], 0x4a7e30
    *app->getMemory<x86::reg32>(cpu.edx) = 4881968 /*0x4a7e30*/;
    // 004a80ea  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a80ed  c700547f4a00           -mov dword ptr [eax], 0x4a7f54
    *app->getMemory<x86::reg32>(cpu.eax) = 4882260 /*0x4a7f54*/;
    // 004a80f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a80f5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80f6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a80f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a80f8:
    // 004a80f8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a80fb  c702287e4a00           -mov dword ptr [edx], 0x4a7e28
    *app->getMemory<x86::reg32>(cpu.edx) = 4881960 /*0x4a7e28*/;
    // 004a8101  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a8104  c700487f4a00           -mov dword ptr [eax], 0x4a7f48
    *app->getMemory<x86::reg32>(cpu.eax) = 4882248 /*0x4a7f48*/;
    // 004a810a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a810c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a810d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a810e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8110  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8114  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a811a  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8121  c6401000               -mov byte ptr [eax + 0x10], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a8125  66c7400e0000           -mov word ptr [eax + 0xe], 0
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a812b  c6401100               -mov byte ptr [eax + 0x11], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a812f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8133  c6401201               -mov byte ptr [eax + 0x12], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 1 /*0x1*/;
    // 004a8137  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a813a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a813e  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a8141  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8145  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a8148  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a814b  c7006c804a00           -mov dword ptr [eax], 0x4a806c
    *app->getMemory<x86::reg32>(cpu.eax) = 4882540 /*0x4a806c*/;
    // 004a8151  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8153  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8160  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8161  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8162  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8163  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8167  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a816b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a816e  48                     -dec eax
    (cpu.eax)--;
    // 004a816f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a8172  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a8175  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8178  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004a817b  40                     -inc eax
    (cpu.eax)++;
    // 004a817c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a817f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8181  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8183  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a8186  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a8188  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a818a  7501                   -jne 0x4a818d
    if (!cpu.flags.zf)
    {
        goto L_0x004a818d;
    }
    // 004a818c  40                     -inc eax
    (cpu.eax)++;
L_0x004a818d:
    // 004a818d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8191  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a8194  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a8197  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a819a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a819d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a819f  885116                 -mov byte ptr [ecx + 0x16], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004a81a2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a81a3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a81a4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a81a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a81a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a81a8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a81ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a81b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a81b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a81b1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a81b5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a81b9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a81bc  48                     -dec eax
    (cpu.eax)--;
    // 004a81bd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a81c0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a81c3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a81c5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a81c8  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a81cb  40                     -inc eax
    (cpu.eax)++;
    // 004a81cc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a81ce  7501                   -jne 0x4a81d1
    if (!cpu.flags.zf)
    {
        goto L_0x004a81d1;
    }
    // 004a81d0  40                     -inc eax
    (cpu.eax)++;
L_0x004a81d1:
    // 004a81d1  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004a81d4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a81d7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a81d9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a81da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a81dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a81dc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a81dd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a81de  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a81df  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a81e0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a81e3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a81e7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a81eb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a81ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a81f1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a81f4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a81f6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a81f8  0f85d1000000           -jne 0x4a82cf
    if (!cpu.flags.zf)
    {
        goto L_0x004a82cf;
    }
L_0x004a81fe:
    // 004a81fe  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a8202  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a8205  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8206  0f85dc000000           -jne 0x4a82e8
    if (!cpu.flags.zf)
    {
        goto L_0x004a82e8;
    }
L_0x004a820c:
    // 004a820c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a820e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a8213  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8216  0fbf0486               -movsx eax, word ptr [esi + eax*4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004a821a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a821c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a821f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8222  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8224  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004a822b  66891428               -mov word ptr [eax + ebp], dx
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a822f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8231  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004a8235  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a8237  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a823a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a823d  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a8240  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004a8244  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a8247  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8249  66891428               -mov word ptr [eax + ebp], dx
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a824d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a824f  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004a8254  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8257  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004a825a  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a825c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a825f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a8262  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a8265  6689542802             -mov word ptr [eax + ebp + 2], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004a826a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a826c  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004a8270  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a8272  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8275  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004a8278  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a827b  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004a827e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a8281  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a8284  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a8286  6689542802             -mov word ptr [eax + ebp + 2], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004a828b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a828d  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004a8292  66894310               -mov word ptr [ebx + 0x10], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a8296  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8298  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004a829d  66894312               -mov word ptr [ebx + 0x12], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004a82a1  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a82a4  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a82a7  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a82a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a82ab  897304                 -mov dword ptr [ebx + 4], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a82ae  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a82b1  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a82b7  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a82b9  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004a82bc  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a82be  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a82c1  c6431501               -mov byte ptr [ebx + 0x15], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a82c5  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a82c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a82ca  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82cb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82cc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82cd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a82cf:
    // 004a82cf  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004a82d2  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004a82d6  668916                 -mov word ptr [esi], dx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004a82d9  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a82dc  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a82e0  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a82e3  e916ffffff             -jmp 0x4a81fe
    goto L_0x004a81fe;
L_0x004a82e8:
    // 004a82e8  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a82eb  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a82ee  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a82f1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a82f4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a82f7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a82f8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a82fb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a82fc  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a8300  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8304  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8305  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8306  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8307  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8308  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8309  e8ae420000             -call 0x4ac5bc
    cpu.esp -= 4;
    sub_4ac5bc(app, cpu);
    if (cpu.terminate) return;
    // 004a830e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8311  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a8314  c1e810                 +shr eax, 0x10
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
    // 004a8317  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a831a  e9edfeffff             -jmp 0x4a820c
    goto L_0x004a820c;
}

/* align: skip 0x90 */
void Application::sub_4a8320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8320  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8324  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8328  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a832a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a832c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a832c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a832d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a832e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a832f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8330  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8333  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8337  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a833b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a833f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8341  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a8344  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8346  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a8348  0f8538010000           -jne 0x4a8486
    if (!cpu.flags.zf)
    {
        goto L_0x004a8486;
    }
L_0x004a834e:
    // 004a834e  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8352  7414                   -je 0x4a8368
    if (cpu.flags.zf)
    {
        goto L_0x004a8368;
    }
    // 004a8354  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8357  668b430e               -mov ax, word ptr [ebx + 0xe]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004a835b  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a835e  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8361  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a8365  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004a8368:
    // 004a8368  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a836c  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a8372  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004a8375  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8376  7432                   -je 0x4a83aa
    if (cpu.flags.zf)
    {
        goto L_0x004a83aa;
    }
    // 004a8378  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a837b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a837e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8381  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8384  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a8387  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8388  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a838b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a838c  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a8390  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8394  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8395  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8396  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8397  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8398  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8399  e81e420000             -call 0x4ac5bc
    cpu.esp -= 4;
    sub_4ac5bc(app, cpu);
    if (cpu.terminate) return;
    // 004a839e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a83a1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a83a4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a83a7  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a83aa:
    // 004a83aa  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a83ac  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a83af  0fbf1486               -movsx edx, word ptr [esi + eax*4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004a83b3  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a83b8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a83ba  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a83bd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a83c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a83c2  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004a83c9  66891428               -mov word ptr [eax + ebp], dx
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a83cd  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a83cf  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004a83d3  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a83d6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a83d9  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a83dc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a83df  0fbf3c28               -movsx edi, word ptr [eax + ebp]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004a83e3  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a83e5  66893c28               -mov word ptr [eax + ebp], di
    *app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.di;
    // 004a83e9  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a83eb  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a83ee  8b3c96                 -mov edi, dword ptr [esi + edx*4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004a83f1  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a83f6  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004a83f9  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a83fb  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a83fe  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a8401  66897c2802             -mov word ptr [eax + ebp + 2], di
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004a8406  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8408  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004a840c  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a840f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a8412  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a8415  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004a8418  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a841b  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004a841e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8420  66897c2802             -mov word ptr [eax + ebp + 2], di
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004a8425  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8427  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004a842c  66894310               -mov word ptr [ebx + 0x10], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a8430  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8432  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004a8437  66894312               -mov word ptr [ebx + 0x12], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004a843b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a843e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8441  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8443  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8445  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8448  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a844a  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a844d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8450  66c743060000           -mov word ptr [ebx + 6], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8456  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8458  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a845b  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a845d  39c8                   +cmp eax, ecx
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
    // 004a845f  723e                   -jb 0x4a849f
    if (cpu.flags.cf)
    {
        goto L_0x004a849f;
    }
    // 004a8461  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8463  c6431401               -mov byte ptr [ebx + 0x14], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004a8467  668b0486               -mov ax, word ptr [esi + eax*4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4);
    // 004a846b  6689430c               -mov word ptr [ebx + 0xc], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004a846f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8471  668b448602             -mov ax, word ptr [esi + eax*4 + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 004a8476  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004a847a  c6431501               -mov byte ptr [ebx + 0x15], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a847e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8481  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8482  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8483  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8484  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8485  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8486:
    // 004a8486  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004a8489  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004a848d  668916                 -mov word ptr [esi], dx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004a8490  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8493  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a8497  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a849a  e9affeffff             -jmp 0x4a834e
    goto L_0x004a834e;
L_0x004a849f:
    // 004a849f  c6431400               -mov byte ptr [ebx + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a84a3  c6431501               -mov byte ptr [ebx + 0x15], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a84a7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a84aa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ab  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ac  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a84b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a84b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a84b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a84b2  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a84b6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a84ba  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a84bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a84bf  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a84c5  732c                   -jae 0x4a84f3
    if (!cpu.flags.cf)
    {
        goto L_0x004a84f3;
    }
    // 004a84c7  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a84cd  7324                   -jae 0x4a84f3
    if (!cpu.flags.cf)
    {
        goto L_0x004a84f3;
    }
L_0x004a84cf:
    // 004a84cf  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a84d2  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a84d8  724b                   -jb 0x4a8525
    if (cpu.flags.cf)
    {
        goto L_0x004a8525;
    }
    // 004a84da  7660                   -jbe 0x4a853c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a853c;
    }
    // 004a84dc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a84df  c70260814a00           -mov dword ptr [edx], 0x4a8160
    *app->getMemory<x86::reg32>(cpu.edx) = 4882784 /*0x4a8160*/;
    // 004a84e5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a84e8  c700dc814a00           -mov dword ptr [eax], 0x4a81dc
    *app->getMemory<x86::reg32>(cpu.eax) = 4882908 /*0x4a81dc*/;
    // 004a84ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a84f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84f1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a84f3:
    // 004a84f3  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a84f6  39f2                   +cmp edx, esi
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
    // 004a84f8  74d5                   -je 0x4a84cf
    if (cpu.flags.zf)
    {
        goto L_0x004a84cf;
    }
    // 004a84fa  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8500  7608                   -jbe 0x4a850a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a850a;
    }
    // 004a8502  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8508  77c5                   -ja 0x4a84cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a84cf;
    }
L_0x004a850a:
    // 004a850a  c6401400               -mov byte ptr [eax + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a850e  c6401500               -mov byte ptr [eax + 0x15], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a8512  c6401600               -mov byte ptr [eax + 0x16], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004a8516  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a851d  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8523  ebaa                   -jmp 0x4a84cf
    goto L_0x004a84cf;
L_0x004a8525:
    // 004a8525  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a8528  c702b0814a00           -mov dword ptr [edx], 0x4a81b0
    *app->getMemory<x86::reg32>(cpu.edx) = 4882864 /*0x4a81b0*/;
    // 004a852e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8531  c7002c834a00           -mov dword ptr [eax], 0x4a832c
    *app->getMemory<x86::reg32>(cpu.eax) = 4883244 /*0x4a832c*/;
    // 004a8537  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8539  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a853a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a853b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a853c:
    // 004a853c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a853f  c702a8814a00           -mov dword ptr [edx], 0x4a81a8
    *app->getMemory<x86::reg32>(cpu.edx) = 4882856 /*0x4a81a8*/;
    // 004a8545  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8548  c70020834a00           -mov dword ptr [eax], 0x4a8320
    *app->getMemory<x86::reg32>(cpu.eax) = 4883232 /*0x4a8320*/;
    // 004a854e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8550  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8551  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8554(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8554  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8558  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a855e  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8565  c6401400               -mov byte ptr [eax + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a8569  c6401500               -mov byte ptr [eax + 0x15], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a856d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8571  c6401600               -mov byte ptr [eax + 0x16], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004a8575  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a8578  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a857c  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a857f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8583  895020                 -mov dword ptr [eax + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a8586  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a8589  c700b0844a00           -mov dword ptr [eax], 0x4a84b0
    *app->getMemory<x86::reg32>(cpu.eax) = 4883632 /*0x4a84b0*/;
    // 004a858f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8591  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a8594(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8594  0f77                   -emms 
    cpu.mmx.init();
    // 004a8596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a85a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a85a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a85a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a85a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a85a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a85a4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a85a5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a85a6  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85ad  744b                   -je 0x4a85fa
    if (cpu.flags.zf)
    {
        goto L_0x004a85fa;
    }
    // 004a85af  ba60c64a00             -mov edx, 0x4ac660
    cpu.edx = 4900448 /*0x4ac660*/;
    // 004a85b4  b980c64a00             -mov ecx, 0x4ac680
    cpu.ecx = 4900480 /*0x4ac680*/;
    // 004a85b9  bbb0c64a00             -mov ebx, 0x4ac6b0
    cpu.ebx = 4900528 /*0x4ac6b0*/;
    // 004a85be  bed0c64a00             -mov esi, 0x4ac6d0
    cpu.esi = 4900560 /*0x4ac6d0*/;
    // 004a85c3  bff0c64a00             -mov edi, 0x4ac6f0
    cpu.edi = 4900592 /*0x4ac6f0*/;
    // 004a85c8  bd20c74a00             -mov ebp, 0x4ac720
    cpu.ebp = 4900640 /*0x4ac720*/;
    // 004a85cd  89150cb24c00           -mov dword ptr [0x4cb20c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5026316) /* 0x4cb20c */) = cpu.edx;
    // 004a85d3  890d10b24c00           -mov dword ptr [0x4cb210], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026320) /* 0x4cb210 */) = cpu.ecx;
    // 004a85d9  891d14b24c00           -mov dword ptr [0x4cb214], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026324) /* 0x4cb214 */) = cpu.ebx;
    // 004a85df  893518b24c00           -mov dword ptr [0x4cb218], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026328) /* 0x4cb218 */) = cpu.esi;
    // 004a85e5  893d1cb24c00           -mov dword ptr [0x4cb21c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026332) /* 0x4cb21c */) = cpu.edi;
    // 004a85eb  892d20b24c00           -mov dword ptr [0x4cb220], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026336) /* 0x4cb220 */) = cpu.ebp;
    // 004a85f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a85f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a85fa:
    // 004a85fa  e841410000             -call 0x4ac740
    cpu.esp -= 4;
    sub_4ac740(app, cpu);
    if (cpu.terminate) return;
    // 004a85ff  b970c74a00             -mov ecx, 0x4ac770
    cpu.ecx = 4900720 /*0x4ac770*/;
    // 004a8604  bb90c74a00             -mov ebx, 0x4ac790
    cpu.ebx = 4900752 /*0x4ac790*/;
    // 004a8609  bec0c74a00             -mov esi, 0x4ac7c0
    cpu.esi = 4900800 /*0x4ac7c0*/;
    // 004a860e  bfe0c74a00             -mov edi, 0x4ac7e0
    cpu.edi = 4900832 /*0x4ac7e0*/;
    // 004a8613  bd00c84a00             -mov ebp, 0x4ac800
    cpu.ebp = 4900864 /*0x4ac800*/;
    // 004a8618  b830c84a00             -mov eax, 0x4ac830
    cpu.eax = 4900912 /*0x4ac830*/;
    // 004a861d  890d0cb24c00           -mov dword ptr [0x4cb20c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026316) /* 0x4cb20c */) = cpu.ecx;
    // 004a8623  891d10b24c00           -mov dword ptr [0x4cb210], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026320) /* 0x4cb210 */) = cpu.ebx;
    // 004a8629  893514b24c00           -mov dword ptr [0x4cb214], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026324) /* 0x4cb214 */) = cpu.esi;
    // 004a862f  893d18b24c00           -mov dword ptr [0x4cb218], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026328) /* 0x4cb218 */) = cpu.edi;
    // 004a8635  892d1cb24c00           -mov dword ptr [0x4cb21c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026332) /* 0x4cb21c */) = cpu.ebp;
    // 004a863b  a320b24c00             -mov dword ptr [0x4cb220], eax
    *app->getMemory<x86::reg32>(x86::reg32(5026336) /* 0x4cb220 */) = cpu.eax;
    // 004a8640  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8642  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8643  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8644  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8645  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8646  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8647  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8648  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8650  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8651  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8652  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8653  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8654  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8655  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a865c  744c                   -je 0x4a86aa
    if (cpu.flags.zf)
    {
        goto L_0x004a86aa;
    }
    // 004a865e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a865f  ba50c84a00             -mov edx, 0x4ac850
    cpu.edx = 4900944 /*0x4ac850*/;
    // 004a8664  b970c84a00             -mov ecx, 0x4ac870
    cpu.ecx = 4900976 /*0x4ac870*/;
    // 004a8669  bba0c84a00             -mov ebx, 0x4ac8a0
    cpu.ebx = 4901024 /*0x4ac8a0*/;
    // 004a866e  bec0c84a00             -mov esi, 0x4ac8c0
    cpu.esi = 4901056 /*0x4ac8c0*/;
    // 004a8673  bfe0c84a00             -mov edi, 0x4ac8e0
    cpu.edi = 4901088 /*0x4ac8e0*/;
    // 004a8678  bd10c94a00             -mov ebp, 0x4ac910
    cpu.ebp = 4901136 /*0x4ac910*/;
    // 004a867d  891524b24c00           -mov dword ptr [0x4cb224], edx
    *app->getMemory<x86::reg32>(x86::reg32(5026340) /* 0x4cb224 */) = cpu.edx;
    // 004a8683  890d28b24c00           -mov dword ptr [0x4cb228], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026344) /* 0x4cb228 */) = cpu.ecx;
    // 004a8689  891d2cb24c00           -mov dword ptr [0x4cb22c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026348) /* 0x4cb22c */) = cpu.ebx;
    // 004a868f  893530b24c00           -mov dword ptr [0x4cb230], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026352) /* 0x4cb230 */) = cpu.esi;
    // 004a8695  893d34b24c00           -mov dword ptr [0x4cb234], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026356) /* 0x4cb234 */) = cpu.edi;
    // 004a869b  892d38b24c00           -mov dword ptr [0x4cb238], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026360) /* 0x4cb238 */) = cpu.ebp;
    // 004a86a1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a86a4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a86aa:
    // 004a86aa  b930c94a00             -mov ecx, 0x4ac930
    cpu.ecx = 4901168 /*0x4ac930*/;
    // 004a86af  bb50c94a00             -mov ebx, 0x4ac950
    cpu.ebx = 4901200 /*0x4ac950*/;
    // 004a86b4  be80c94a00             -mov esi, 0x4ac980
    cpu.esi = 4901248 /*0x4ac980*/;
    // 004a86b9  bfa0c94a00             -mov edi, 0x4ac9a0
    cpu.edi = 4901280 /*0x4ac9a0*/;
    // 004a86be  bdc0c94a00             -mov ebp, 0x4ac9c0
    cpu.ebp = 4901312 /*0x4ac9c0*/;
    // 004a86c3  b8f0c94a00             -mov eax, 0x4ac9f0
    cpu.eax = 4901360 /*0x4ac9f0*/;
    // 004a86c8  890d24b24c00           -mov dword ptr [0x4cb224], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026340) /* 0x4cb224 */) = cpu.ecx;
    // 004a86ce  891d28b24c00           -mov dword ptr [0x4cb228], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026344) /* 0x4cb228 */) = cpu.ebx;
    // 004a86d4  89352cb24c00           -mov dword ptr [0x4cb22c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026348) /* 0x4cb22c */) = cpu.esi;
    // 004a86da  893d30b24c00           -mov dword ptr [0x4cb230], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026352) /* 0x4cb230 */) = cpu.edi;
    // 004a86e0  892d34b24c00           -mov dword ptr [0x4cb234], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026356) /* 0x4cb234 */) = cpu.ebp;
    // 004a86e6  a338b24c00             -mov dword ptr [0x4cb238], eax
    *app->getMemory<x86::reg32>(x86::reg32(5026360) /* 0x4cb238 */) = cpu.eax;
    // 004a86eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a86ed  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86ee  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86ef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86f0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86f1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8700  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8701  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8702  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8703  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8704  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8707  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004a870c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a870e:
    // 004a870e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8710  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a8712  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a8714  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8716  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004a8719:
    // 004a8719  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a871b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004a871e  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004a8720  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8723  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a8726  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004a872c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 004a872f  d99810615400           -fstp dword ptr [eax + 0x546110]
    *app->getMemory<float>(cpu.eax + x86::reg32(5529872) /* 0x546110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8735  39f8                   +cmp eax, edi
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
    // 004a8737  75e0                   -jne 0x4a8719
    if (!cpu.flags.zf)
    {
        goto L_0x004a8719;
    }
    // 004a8739  43                     -inc ebx
    (cpu.ebx)++;
    // 004a873a  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a873d  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8740  7ccc                   -jl 0x4a870e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a870e;
    }
    // 004a8742  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8745  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8746  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8747  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8748  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8749  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a874c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a874c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a874d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a874e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a874f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8750  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004a8755  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a8757:
    // 004a8757  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8759  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a875b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a875d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a875f  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004a8762:
    // 004a8762  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8764  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004a8767  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004a8769  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a876c  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a876f  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004a8775  89b010655400           -mov dword ptr [eax + 0x546510], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5530896) /* 0x546510 */) = cpu.esi;
    // 004a877b  39f8                   +cmp eax, edi
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
    // 004a877d  75e3                   -jne 0x4a8762
    if (!cpu.flags.zf)
    {
        goto L_0x004a8762;
    }
    // 004a877f  43                     -inc ebx
    (cpu.ebx)++;
    // 004a8780  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a8783  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8786  7ccf                   -jl 0x4a8757
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8757;
    }
    // 004a8788  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8789  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a878a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a878b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a878c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a8790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8790  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8791  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8792  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8793  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8794  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8795  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8796  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a879d  7450                   -je 0x4a87ef
    if (cpu.flags.zf)
    {
        goto L_0x004a87ef;
    }
    // 004a879f  e8a8ffffff             -call 0x4a874c
    cpu.esp -= 4;
    sub_4a874c(app, cpu);
    if (cpu.terminate) return;
    // 004a87a4  ba98cb4a00             -mov edx, 0x4acb98
    cpu.edx = 4901784 /*0x4acb98*/;
    // 004a87a9  b9e8cf4a00             -mov ecx, 0x4acfe8
    cpu.ecx = 4902888 /*0x4acfe8*/;
    // 004a87ae  bb30d24a00             -mov ebx, 0x4ad230
    cpu.ebx = 4903472 /*0x4ad230*/;
    // 004a87b3  be44d44a00             -mov esi, 0x4ad444
    cpu.esi = 4904004 /*0x4ad444*/;
    // 004a87b8  bf48d94a00             -mov edi, 0x4ad948
    cpu.edi = 4905288 /*0x4ad948*/;
    // 004a87bd  bd5cdb4a00             -mov ebp, 0x4adb5c
    cpu.ebp = 4905820 /*0x4adb5c*/;
    // 004a87c2  89153cb24c00           -mov dword ptr [0x4cb23c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5026364) /* 0x4cb23c */) = cpu.edx;
    // 004a87c8  890d40b24c00           -mov dword ptr [0x4cb240], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.ecx;
    // 004a87ce  891d44b24c00           -mov dword ptr [0x4cb244], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */) = cpu.ebx;
    // 004a87d4  893548b24c00           -mov dword ptr [0x4cb248], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026376) /* 0x4cb248 */) = cpu.esi;
    // 004a87da  893d4cb24c00           -mov dword ptr [0x4cb24c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */) = cpu.edi;
    // 004a87e0  892d50b24c00           -mov dword ptr [0x4cb250], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.ebp;
    // 004a87e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a87e8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87eb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87ec  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87ed  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a87ef:
    // 004a87ef  e80cffffff             -call 0x4a8700
    cpu.esp -= 4;
    sub_4a8700(app, cpu);
    if (cpu.terminate) return;
    // 004a87f4  b938dd4a00             -mov ecx, 0x4add38
    cpu.ecx = 4906296 /*0x4add38*/;
    // 004a87f9  bb6ce14a00             -mov ebx, 0x4ae16c
    cpu.ebx = 4907372 /*0x4ae16c*/;
    // 004a87fe  be84e34a00             -mov esi, 0x4ae384
    cpu.esi = 4907908 /*0x4ae384*/;
    // 004a8803  bf78e54a00             -mov edi, 0x4ae578
    cpu.edi = 4908408 /*0x4ae578*/;
    // 004a8808  bd54ea4a00             -mov ebp, 0x4aea54
    cpu.ebp = 4909652 /*0x4aea54*/;
    // 004a880d  b860ec4a00             -mov eax, 0x4aec60
    cpu.eax = 4910176 /*0x4aec60*/;
    // 004a8812  890d3cb24c00           -mov dword ptr [0x4cb23c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026364) /* 0x4cb23c */) = cpu.ecx;
    // 004a8818  891d40b24c00           -mov dword ptr [0x4cb240], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.ebx;
    // 004a881e  893544b24c00           -mov dword ptr [0x4cb244], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */) = cpu.esi;
    // 004a8824  893d48b24c00           -mov dword ptr [0x4cb248], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026376) /* 0x4cb248 */) = cpu.edi;
    // 004a882a  892d4cb24c00           -mov dword ptr [0x4cb24c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */) = cpu.ebp;
    // 004a8830  a350b24c00             -mov dword ptr [0x4cb250], eax
    *app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.eax;
    // 004a8835  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8837  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8838  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8839  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a883a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a883b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a883c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a883d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a8840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8840  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8841  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8848  741f                   -je 0x4a8869
    if (cpu.flags.zf)
    {
        goto L_0x004a8869;
    }
    // 004a884a  bf34ee4a00             -mov edi, 0x4aee34
    cpu.edi = 4910644 /*0x4aee34*/;
    // 004a884f  b808f04a00             -mov eax, 0x4af008
    cpu.eax = 4911112 /*0x4af008*/;
    // 004a8854  893d6cb24c00           -mov dword ptr [0x4cb26c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026412) /* 0x4cb26c */) = cpu.edi;
    // 004a885a  893d78b24c00           -mov dword ptr [0x4cb278], edi
    *app->getMemory<x86::reg32>(x86::reg32(5026424) /* 0x4cb278 */) = cpu.edi;
    // 004a8860  a380b24c00             -mov dword ptr [0x4cb280], eax
    *app->getMemory<x86::reg32>(x86::reg32(5026432) /* 0x4cb280 */) = cpu.eax;
    // 004a8865  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8867  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8869:
    // 004a8869  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a886a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a886b  b9a8f14a00             -mov ecx, 0x4af1a8
    cpu.ecx = 4911528 /*0x4af1a8*/;
    // 004a8870  beb0f34a00             -mov esi, 0x4af3b0
    cpu.esi = 4912048 /*0x4af3b0*/;
    // 004a8875  890d6cb24c00           -mov dword ptr [0x4cb26c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026412) /* 0x4cb26c */) = cpu.ecx;
    // 004a887b  890d78b24c00           -mov dword ptr [0x4cb278], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5026424) /* 0x4cb278 */) = cpu.ecx;
    // 004a8881  893580b24c00           -mov dword ptr [0x4cb280], esi
    *app->getMemory<x86::reg32>(x86::reg32(5026432) /* 0x4cb280 */) = cpu.esi;
    // 004a8887  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8888  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8889  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a888b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a888c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a8890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8890  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8891  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8893  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a8894  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8897  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a889a  8b15e02b5400           -mov edx, dword ptr [0x542be0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516256) /* 0x542be0 */);
    // 004a88a0  a180d25300             -mov eax, dword ptr [0x53d280]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5493376) /* 0x53d280 */);
    // 004a88a5  8b1da02b5400           -mov ebx, dword ptr [0x542ba0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516192) /* 0x542ba0 */);
    // 004a88ab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a88ae  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a88b1:
    // 004a88b1  3bc2                   +cmp eax, edx
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
    // 004a88b3  7c05                   -jl 0x4a88ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a88ba;
    }
    // 004a88b5  a1b02b5400             -mov eax, dword ptr [0x542bb0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516208) /* 0x542bb0 */);
L_0x004a88ba:
    // 004a88ba  3bda                   +cmp ebx, edx
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
    // 004a88bc  7c06                   -jl 0x4a88c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a88c4;
    }
    // 004a88be  8b1db02b5400           -mov ebx, dword ptr [0x542bb0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516208) /* 0x542bb0 */);
L_0x004a88c4:
    // 004a88c4  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edi)));
    // 004a88c6  d805d02b5400           -fadd dword ptr [0x542bd0]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(5516240) /* 0x542bd0 */));
    // 004a88cc  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 004a88ce  a380d25300             -mov dword ptr [0x53d280], eax
    *app->getMemory<x86::reg32>(x86::reg32(5493376) /* 0x53d280 */) = cpu.eax;
    // 004a88d3  891da02b5400           -mov dword ptr [0x542ba0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5516192) /* 0x542ba0 */) = cpu.ebx;
    // 004a88d9  d80d10bf4c00           -fmul dword ptr [0x4cbf10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029648) /* 0x4cbf10 */));
    // 004a88df  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a88e1  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004a88e3  d80d10bf4c00           -fmul dword ptr [0x4cbf10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029648) /* 0x4cbf10 */));
    // 004a88e9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a88eb  d91dd02b5400           -fstp dword ptr [0x542bd0]
    *app->getMemory<float>(x86::reg32(5516240) /* 0x542bd0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a88f1  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 004a88f3  8b15e42b5400           -mov edx, dword ptr [0x542be4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516260) /* 0x542be4 */);
    // 004a88f9  a184d25300             -mov eax, dword ptr [0x53d284]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5493380) /* 0x53d284 */);
    // 004a88fe  8b1da42b5400           -mov ebx, dword ptr [0x542ba4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516196) /* 0x542ba4 */);
    // 004a8904  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8907  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a890a  3bc2                   +cmp eax, edx
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
    // 004a890c  7c05                   -jl 0x4a8913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8913;
    }
    // 004a890e  a1b42b5400             -mov eax, dword ptr [0x542bb4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516212) /* 0x542bb4 */);
L_0x004a8913:
    // 004a8913  3bda                   +cmp ebx, edx
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
    // 004a8915  7c06                   -jl 0x4a891d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a891d;
    }
    // 004a8917  8b1db42b5400           -mov ebx, dword ptr [0x542bb4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516212) /* 0x542bb4 */);
L_0x004a891d:
    // 004a891d  d805d42b5400           -fadd dword ptr [0x542bd4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(5516244) /* 0x542bd4 */));
    // 004a8923  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 004a8925  a384d25300             -mov dword ptr [0x53d284], eax
    *app->getMemory<x86::reg32>(x86::reg32(5493380) /* 0x53d284 */) = cpu.eax;
    // 004a892a  891da42b5400           -mov dword ptr [0x542ba4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5516196) /* 0x542ba4 */) = cpu.ebx;
    // 004a8930  d80d14bf4c00           -fmul dword ptr [0x4cbf14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029652) /* 0x4cbf14 */));
    // 004a8936  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8938  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004a893a  d80d14bf4c00           -fmul dword ptr [0x4cbf14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029652) /* 0x4cbf14 */));
    // 004a8940  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8942  d91dd42b5400           -fstp dword ptr [0x542bd4]
    *app->getMemory<float>(x86::reg32(5516244) /* 0x542bd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8948  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 004a894a  d905e4be4c00           -fld dword ptr [0x4cbee4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5029604) /* 0x4cbee4 */)));
    // 004a8950  d80df4be4c00           -fmul dword ptr [0x4cbef4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029620) /* 0x4cbef4 */));
    // 004a8956  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8958  d80d04bf4c00           -fmul dword ptr [0x4cbf04]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029636) /* 0x4cbf04 */));
    // 004a895e  a188d25300             -mov eax, dword ptr [0x53d288]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5493384) /* 0x53d288 */);
    // 004a8963  8b1da82b5400           -mov ebx, dword ptr [0x542ba8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516200) /* 0x542ba8 */);
    // 004a8969  8b15e82b5400           -mov edx, dword ptr [0x542be8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516264) /* 0x542be8 */);
    // 004a896f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8971  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8974  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8977  3bc2                   +cmp eax, edx
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
    // 004a8979  7c05                   -jl 0x4a8980
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8980;
    }
    // 004a897b  a1b82b5400             -mov eax, dword ptr [0x542bb8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516216) /* 0x542bb8 */);
L_0x004a8980:
    // 004a8980  3bda                   +cmp ebx, edx
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
    // 004a8982  7c06                   -jl 0x4a898a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a898a;
    }
    // 004a8984  8b1db82b5400           -mov ebx, dword ptr [0x542bb8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516216) /* 0x542bb8 */);
L_0x004a898a:
    // 004a898a  d915e4be4c00           -fst dword ptr [0x4cbee4]
    *app->getMemory<float>(x86::reg32(5029604) /* 0x4cbee4 */) = float(cpu.fpu.st(0));
    // 004a8990  d805d82b5400           -fadd dword ptr [0x542bd8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(5516248) /* 0x542bd8 */));
    // 004a8996  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 004a8998  a388d25300             -mov dword ptr [0x53d288], eax
    *app->getMemory<x86::reg32>(x86::reg32(5493384) /* 0x53d288 */) = cpu.eax;
    // 004a899d  891da82b5400           -mov dword ptr [0x542ba8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5516200) /* 0x542ba8 */) = cpu.ebx;
    // 004a89a3  d80d18bf4c00           -fmul dword ptr [0x4cbf18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029656) /* 0x4cbf18 */));
    // 004a89a9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a89ab  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004a89ad  d80d18bf4c00           -fmul dword ptr [0x4cbf18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029656) /* 0x4cbf18 */));
    // 004a89b3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a89b5  d91dd82b5400           -fstp dword ptr [0x542bd8]
    *app->getMemory<float>(x86::reg32(5516248) /* 0x542bd8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a89bb  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 004a89bd  8b15ec2b5400           -mov edx, dword ptr [0x542bec]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516268) /* 0x542bec */);
    // 004a89c3  a18cd25300             -mov eax, dword ptr [0x53d28c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5493388) /* 0x53d28c */);
    // 004a89c8  8b1dac2b5400           -mov ebx, dword ptr [0x542bac]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516204) /* 0x542bac */);
    // 004a89ce  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a89d1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a89d4  3bc2                   +cmp eax, edx
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
    // 004a89d6  7c05                   -jl 0x4a89dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a89dd;
    }
    // 004a89d8  a1bc2b5400             -mov eax, dword ptr [0x542bbc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516220) /* 0x542bbc */);
L_0x004a89dd:
    // 004a89dd  3bda                   +cmp ebx, edx
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
    // 004a89df  7c06                   -jl 0x4a89e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a89e7;
    }
    // 004a89e1  8b1dbc2b5400           -mov ebx, dword ptr [0x542bbc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516220) /* 0x542bbc */);
L_0x004a89e7:
    // 004a89e7  d805dc2b5400           -fadd dword ptr [0x542bdc]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(5516252) /* 0x542bdc */));
    // 004a89ed  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 004a89ef  a38cd25300             -mov dword ptr [0x53d28c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5493388) /* 0x53d28c */) = cpu.eax;
    // 004a89f4  891dac2b5400           -mov dword ptr [0x542bac], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5516204) /* 0x542bac */) = cpu.ebx;
    // 004a89fa  d80d1cbf4c00           -fmul dword ptr [0x4cbf1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029660) /* 0x4cbf1c */));
    // 004a8a00  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8a02  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004a8a04  d80d1cbf4c00           -fmul dword ptr [0x4cbf1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029660) /* 0x4cbf1c */));
    // 004a8a0a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8a0c  d91ddc2b5400           -fstp dword ptr [0x542bdc]
    *app->getMemory<float>(x86::reg32(5516252) /* 0x542bdc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8a12  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 004a8a14  d905ecbe4c00           -fld dword ptr [0x4cbeec]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5029612) /* 0x4cbeec */)));
    // 004a8a1a  d80dfcbe4c00           -fmul dword ptr [0x4cbefc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029628) /* 0x4cbefc */));
    // 004a8a20  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8a22  d80d0cbf4c00           -fmul dword ptr [0x4cbf0c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5029644) /* 0x4cbf0c */));
    // 004a8a28  8b15e02b5400           -mov edx, dword ptr [0x542be0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516256) /* 0x542be0 */);
    // 004a8a2e  a180d25300             -mov eax, dword ptr [0x53d280]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5493376) /* 0x53d280 */);
    // 004a8a33  8b1da02b5400           -mov ebx, dword ptr [0x542ba0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5516192) /* 0x542ba0 */);
    // 004a8a39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8a3b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a3e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a41  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a44  d915ecbe4c00           -fst dword ptr [0x4cbeec]
    *app->getMemory<float>(x86::reg32(5029612) /* 0x4cbeec */) = float(cpu.fpu.st(0));
    // 004a8a4a  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8a4d  83e901                 +sub ecx, 1
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
    // 004a8a50  0f8f5bfeffff           -jg 0x4a88b1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a88b1;
    }
    // 004a8a56  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004a8a57  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a60  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8a64  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8a68  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8a6c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a8a6f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8a71  39c8                   +cmp eax, ecx
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
    // 004a8a73  7313                   -jae 0x4a8a88
    if (!cpu.flags.cf)
    {
        goto L_0x004a8a88;
    }
L_0x004a8a75:
    // 004a8a75  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 004a8a77  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a7a  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004a8a7d  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8a80  d958fc                 -fstp dword ptr [eax - 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8a83  39c8                   +cmp eax, ecx
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
    // 004a8a85  72ee                   -jb 0x4a8a75
    if (cpu.flags.cf)
    {
        goto L_0x004a8a75;
    }
    // 004a8a87  90                     -nop 
    ;
L_0x004a8a88:
    // 004a8a88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a90  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8a91  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8a92  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8a95  c704240000803f         -mov dword ptr [esp], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.esp) = 1065353216 /*0x3f800000*/;
    // 004a8a9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8a9e  7e2f                   -jle 0x4a8acf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8acf;
    }
    // 004a8aa0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a8aa5  39d0                   +cmp eax, edx
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
    // 004a8aa7  7c0f                   -jl 0x4a8ab8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8ab8;
    }
    // 004a8aa9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a8aab:
    // 004a8aab  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004a8aad  7512                   -jne 0x4a8ac1
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ac1;
    }
L_0x004a8aaf:
    // 004a8aaf  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8ab1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8ab4  39c2                   +cmp edx, eax
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
    // 004a8ab6  7ef3                   -jle 0x4a8aab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8aab;
    }
L_0x004a8ab8:
    // 004a8ab8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004a8abb  83c404                 +add esp, 4
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
    // 004a8abe  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8abf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ac0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8ac1:
    // 004a8ac1  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004a8ac4  d889c4d54c00           +fmul dword ptr [ecx + 0x4cd5c4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(5035460) /* 0x4cd5c4 */));
    // 004a8aca  d91c24                 +fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8acd  ebe0                   -jmp 0x4a8aaf
    goto L_0x004a8aaf;
L_0x004a8acf:
    // 004a8acf  6bc0ff                 -imul eax, eax, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a8ad2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a8ad7  39d0                   +cmp eax, edx
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
    // 004a8ad9  7cdd                   -jl 0x4a8ab8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8ab8;
    }
    // 004a8adb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a8add:
    // 004a8add  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004a8adf  750b                   -jne 0x4a8aec
    if (!cpu.flags.zf)
    {
        goto L_0x004a8aec;
    }
    // 004a8ae1  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8ae3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8ae6  39c2                   +cmp edx, eax
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
    // 004a8ae8  7fce                   -jg 0x4a8ab8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8ab8;
    }
    // 004a8aea  ebf1                   -jmp 0x4a8add
    goto L_0x004a8add;
L_0x004a8aec:
    // 004a8aec  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004a8aef  d8b1c4d54c00           -fdiv dword ptr [ecx + 0x4cd5c4]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(5035460) /* 0x4cd5c4 */));
    // 004a8af5  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8af8  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8afa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8afd  39c2                   +cmp edx, eax
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
    // 004a8aff  7fb7                   -jg 0x4a8ab8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8ab8;
    }
    // 004a8b01  ebda                   -jmp 0x4a8add
    goto L_0x004a8add;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8b10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8b11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8b12  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a8b14  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a8b16  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a8b19  c0e407                 +shl ah, 7
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
    // 004a8b1c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a8b1e  00e4                   +add ah, ah
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
    // 004a8b20  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a8b22  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8b24  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a8b29  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8b2b  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004a8b32  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b34  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b36  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 004a8b3b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8b3d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8b3f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8b41  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a8b44  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8b47  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a8b49  83f87f                 +cmp eax, 0x7f
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
    // 004a8b4c  7f16                   -jg 0x4a8b64
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8b64;
    }
L_0x004a8b4e:
    // 004a8b4e  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004a8b54  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a8b57  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a8b5a  893e                   -mov dword ptr [esi], edi
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004a8b5c  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8b5f  7f0b                   -jg 0x4a8b6c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8b6c;
    }
    // 004a8b61  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b62  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8b64:
    // 004a8b64  c7037f000000           -mov dword ptr [ebx], 0x7f
    *app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 004a8b6a  ebe2                   -jmp 0x4a8b4e
    goto L_0x004a8b4e;
L_0x004a8b6c:
    // 004a8b6c  c7067f000000           -mov dword ptr [esi], 0x7f
    *app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 004a8b72  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b73  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8b75(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8b75  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8b76  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8b77  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8b78  8a2571bf4c00           -mov ah, byte ptr [0x4cbf71]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5029745) /* 0x4cbf71 */);
    // 004a8b7e  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a8b81  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004a8b83  882571bf4c00           -mov byte ptr [0x4cbf71], ah
    *app->getMemory<x86::reg8>(x86::reg32(5029745) /* 0x4cbf71 */) = cpu.ah;
    // 004a8b89  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004a8b8c  bb30bf4c00             -mov ebx, 0x4cbf30
    cpu.ebx = 5029680 /*0x4cbf30*/;
    // 004a8b91  881571bf4c00           -mov byte ptr [0x4cbf71], dl
    *app->getMemory<x86::reg8>(x86::reg32(5029745) /* 0x4cbf71 */) = cpu.dl;
    // 004a8b97  eb5d                   -jmp 0x4a8bf6
    goto L_0x004a8bf6;
L_0x004a8b99:
    // 004a8b99  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004a8b9e  e8b0cffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a8ba3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8ba5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8ba7  751f                   -jne 0x4a8bc8
    if (!cpu.flags.zf)
    {
        goto L_0x004a8bc8;
    }
    // 004a8ba9  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004a8bae  e8a0cffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a8bb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8bb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8bb7  750f                   -jne 0x4a8bc8
    if (!cpu.flags.zf)
    {
        goto L_0x004a8bc8;
    }
    // 004a8bb9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a8bbe  b854f64b00             -mov eax, 0x4bf654
    cpu.eax = 4978260 /*0x4bf654*/;
    // 004a8bc3  e869140000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
L_0x004a8bc8:
    // 004a8bc8  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 004a8bcd  895904                 -mov dword ptr [ecx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a8bd0  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a8bd2  894b08                 -mov dword ptr [ebx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a8bd5  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004a8bdc  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8bdf  c6401400               -mov byte ptr [eax + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a8be3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8be6  890df42b5400           -mov dword ptr [0x542bf4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */) = cpu.ecx;
    // 004a8bec  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 004a8bef  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004a8bf6:
    // 004a8bf6  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a8bf9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8bfb  759c                   -jne 0x4a8b99
    if (!cpu.flags.zf)
    {
        goto L_0x004a8b99;
    }
    // 004a8bfd  8915f82b5400           -mov dword ptr [0x542bf8], edx
    *app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */) = cpu.edx;
    // 004a8c03  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c04  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c05  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8c07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c07  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a8c09  e80a000000             -call 0x4a8c18
    cpu.esp -= 4;
    sub_4a8c18(app, cpu);
    if (cpu.terminate) return;
    // 004a8c0e  e96e06ffff             -jmp 0x499281
    return sub_499281(app, cpu);
}

/* align: skip  */
void Application::sub_4a8c13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c13  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a8c18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8c1a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8c1b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8c1c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8c1e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8c21  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c23  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8c26  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c28  be30bf4c00             -mov esi, 0x4cbf30
    cpu.esi = 5029680 /*0x4cbf30*/;
    // 004a8c2d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c2f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8c31  01c6                   +add esi, eax
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
    // 004a8c33  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 004a8c38  eb2b                   -jmp 0x4a8c65
    goto L_0x004a8c65;
L_0x004a8c3a:
    // 004a8c3a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a8c3c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a8c3f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a8c44  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004a8c48  7513                   -jne 0x4a8c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c4a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004a8c4e  750d                   -jne 0x4a8c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c50  39f0                   +cmp eax, esi
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
    // 004a8c52  720f                   -jb 0x4a8c63
    if (cpu.flags.cf)
    {
        goto L_0x004a8c63;
    }
    // 004a8c54  3d7ebf4c00             +cmp eax, 0x4cbf7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5029758 /*0x4cbf7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c59  7302                   -jae 0x4a8c5d
    if (!cpu.flags.cf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c5b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a8c5d:
    // 004a8c5d  e8546cfdff             -call 0x47f8b6
    cpu.esp -= 4;
    sub_47f8b6(app, cpu);
    if (cpu.terminate) return;
    // 004a8c62  43                     -inc ebx
    (cpu.ebx)++;
L_0x004a8c63:
    // 004a8c63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a8c65:
    // 004a8c65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8c67  75d1                   -jne 0x4a8c3a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c3a;
    }
    // 004a8c69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8c6b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8c18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a8c18;
    // 004a8c13  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_entry_0x004a8c18:
    // 004a8c18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8c1a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8c1b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8c1c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8c1e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8c21  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c23  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8c26  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c28  be30bf4c00             -mov esi, 0x4cbf30
    cpu.esi = 5029680 /*0x4cbf30*/;
    // 004a8c2d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c2f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8c31  01c6                   +add esi, eax
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
    // 004a8c33  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 004a8c38  eb2b                   -jmp 0x4a8c65
    goto L_0x004a8c65;
L_0x004a8c3a:
    // 004a8c3a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a8c3c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a8c3f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a8c44  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004a8c48  7513                   -jne 0x4a8c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c4a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004a8c4e  750d                   -jne 0x4a8c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c50  39f0                   +cmp eax, esi
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
    // 004a8c52  720f                   -jb 0x4a8c63
    if (cpu.flags.cf)
    {
        goto L_0x004a8c63;
    }
    // 004a8c54  3d7ebf4c00             +cmp eax, 0x4cbf7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5029758 /*0x4cbf7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c59  7302                   -jae 0x4a8c5d
    if (!cpu.flags.cf)
    {
        goto L_0x004a8c5d;
    }
    // 004a8c5b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a8c5d:
    // 004a8c5d  e8546cfdff             -call 0x47f8b6
    cpu.esp -= 4;
    sub_47f8b6(app, cpu);
    if (cpu.terminate) return;
    // 004a8c62  43                     -inc ebx
    (cpu.ebx)++;
L_0x004a8c63:
    // 004a8c63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a8c65:
    // 004a8c65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8c67  75d1                   -jne 0x4a8c3a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8c3a;
    }
    // 004a8c69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8c6b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c70  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c71  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8c72  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8c73  8b0df8d54c00           -mov ecx, dword ptr [0x4cd5f8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8c79  a1fcd54c00             -mov eax, dword ptr [0x4cd5fc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8c7e  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c84  7304                   -jae 0x4a8c8a
    if (!cpu.flags.cf)
    {
        goto L_0x004a8c8a;
    }
L_0x004a8c86:
    // 004a8c86  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a8c88  eb21                   -jmp 0x4a8cab
    goto L_0x004a8cab;
L_0x004a8c8a:
    // 004a8c8a  8b1dfcd54c00           -mov ebx, dword ptr [0x4cd5fc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8c90  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a8c92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c94  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a8c97  eb09                   -jmp 0x4a8ca2
    goto L_0x004a8ca2;
L_0x004a8c99:
    // 004a8c99  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c9d  74e7                   -je 0x4a8c86
    if (cpu.flags.zf)
    {
        goto L_0x004a8c86;
    }
    // 004a8c9f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a8ca2:
    // 004a8ca2  39d8                   +cmp eax, ebx
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
    // 004a8ca4  7cf3                   -jl 0x4a8c99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8c99;
    }
    // 004a8ca6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a8cab:
    // 004a8cab  890df8d54c00           -mov dword ptr [0x4cd5f8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */) = cpu.ecx;
    // 004a8cb1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8cb5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8cb5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8cb6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8cb7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8cb8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8cb9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8cbb  ff1578c14c00           -call dword ptr [0x4cc178]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030264) /* 0x4cc178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8cc1  8b0dfcd54c00           -mov ecx, dword ptr [0x4cd5fc]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8cc7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8cc9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8ccb  c1e102                 +shl ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a8cce  eb20                   -jmp 0x4a8cf0
    goto L_0x004a8cf0;
L_0x004a8cd0:
    // 004a8cd0  8b15f8d54c00           -mov edx, dword ptr [0x4cd5f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8cd6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8cd8  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8cdb  750f                   -jne 0x4a8cec
    if (!cpu.flags.zf)
    {
        goto L_0x004a8cec;
    }
    // 004a8cdd  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a8cdf  ff157cc14c00           -call dword ptr [0x4cc17c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030268) /* 0x4cc17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8ce5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8ce7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ce8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ce9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cea  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ceb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8cec:
    // 004a8cec  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8cef  43                     -inc ebx
    (cpu.ebx)++;
L_0x004a8cf0:
    // 004a8cf0  39c8                   +cmp eax, ecx
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
    // 004a8cf2  7cdc                   -jl 0x4a8cd0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8cd0;
    }
    // 004a8cf4  8b15fcd54c00           -mov edx, dword ptr [0x4cd5fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8cfa  42                     -inc edx
    (cpu.edx)++;
    // 004a8cfb  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8d00  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a8d03  e8ec660000             -call 0x4af3f4
    cpu.esp -= 4;
    sub_4af3f4(app, cpu);
    if (cpu.terminate) return;
    // 004a8d08  8b15fcd54c00           -mov edx, dword ptr [0x4cd5fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8d0e  a3f8d54c00             -mov dword ptr [0x4cd5f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */) = cpu.eax;
    // 004a8d13  893490                 -mov dword ptr [eax + edx*4], esi
    *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 004a8d16  42                     -inc edx
    (cpu.edx)++;
    // 004a8d17  8915fcd54c00           -mov dword ptr [0x4cd5fc], edx
    *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */) = cpu.edx;
    // 004a8d1d  ff157cc14c00           -call dword ptr [0x4cc17c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030268) /* 0x4cc17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8d23  a1fcd54c00             -mov eax, dword ptr [0x4cd5fc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8d28  48                     -dec eax
    (cpu.eax)--;
    // 004a8d29  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d2a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d2b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d2c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8d2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8d2e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8d2f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8d30  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8d31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d32  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a8d34  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8d36  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8d38  0f8c90000000           -jl 0x4a8dce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8dce;
    }
    // 004a8d3e  ff1578c14c00           -call dword ptr [0x4cc178]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030264) /* 0x4cc178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8d44  83fa01                 +cmp edx, 1
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
    // 004a8d47  7209                   -jb 0x4a8d52
    if (cpu.flags.cf)
    {
        goto L_0x004a8d52;
    }
    // 004a8d49  7610                   -jbe 0x4a8d5b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8d5b;
    }
    // 004a8d4b  83fa02                 +cmp edx, 2
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
    // 004a8d4e  7410                   -je 0x4a8d60
    if (cpu.flags.zf)
    {
        goto L_0x004a8d60;
    }
    // 004a8d50  eb18                   -jmp 0x4a8d6a
    goto L_0x004a8d6a;
L_0x004a8d52:
    // 004a8d52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8d54  7514                   -jne 0x4a8d6a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8d6a;
    }
    // 004a8d56  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d57  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004a8d59  eb08                   -jmp 0x4a8d63
    goto L_0x004a8d63;
L_0x004a8d5b:
    // 004a8d5b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d5c  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004a8d5e  eb03                   -jmp 0x4a8d63
    goto L_0x004a8d63;
L_0x004a8d60:
    // 004a8d60  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d61  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x004a8d63:
    // 004a8d63  2eff1568554b00         -call dword ptr cs:[0x4b5568]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937064) /* 0x4b5568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a8d6a:
    // 004a8d6a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a8d6c  8b15fcd54c00           -mov edx, dword ptr [0x4cd5fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8d72  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a8d75  39d6                   +cmp esi, edx
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
    // 004a8d77  7d0a                   -jge 0x4a8d83
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8d83;
    }
    // 004a8d79  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8d7e  893c01                 -mov dword ptr [ecx + eax], edi
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edi;
    // 004a8d81  eb45                   -jmp 0x4a8dc8
    goto L_0x004a8dc8;
L_0x004a8d83:
    // 004a8d83  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8d88  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a8d8b  e864660000             -call 0x4af3f4
    cpu.esp -= 4;
    sub_4af3f4(app, cpu);
    if (cpu.terminate) return;
    // 004a8d90  8b1dfcd54c00           -mov ebx, dword ptr [0x4cd5fc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */);
    // 004a8d96  a3f8d54c00             -mov dword ptr [0x4cd5f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */) = cpu.eax;
    // 004a8d9b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8d9d  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a8da0  eb11                   -jmp 0x4a8db3
    goto L_0x004a8db3;
L_0x004a8da2:
    // 004a8da2  8b15f8d54c00           -mov edx, dword ptr [0x4cd5f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8da8  43                     -inc ebx
    (cpu.ebx)++;
    // 004a8da9  c7040200000000         -mov dword ptr [edx + eax], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004a8db0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a8db3:
    // 004a8db3  39c8                   +cmp eax, ecx
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
    // 004a8db5  7ceb                   -jl 0x4a8da2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8da2;
    }
    // 004a8db7  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8dbc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a8dbe  46                     -inc esi
    (cpu.esi)++;
    // 004a8dbf  893c90                 -mov dword ptr [eax + edx*4], edi
    *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.edi;
    // 004a8dc2  8935fcd54c00           -mov dword ptr [0x4cd5fc], esi
    *app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */) = cpu.esi;
L_0x004a8dc8:
    // 004a8dc8  ff157cc14c00           -call dword ptr [0x4cc17c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030268) /* 0x4cc17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a8dce:
    // 004a8dce  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dcf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dd0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dd1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8dd3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8dd3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8dd4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8dd6  ff1578c14c00           -call dword ptr [0x4cc178]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030264) /* 0x4cc178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8ddc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8dde  7e17                   -jle 0x4a8df7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8df7;
    }
    // 004a8de0  3b15fcd54c00           +cmp edx, dword ptr [0x4cd5fc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5035516) /* 0x4cd5fc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8de6  7d0f                   -jge 0x4a8df7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8df7;
    }
    // 004a8de8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8dea  8b15f8d54c00           -mov edx, dword ptr [0x4cd5f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8df0  c7048200000000         -mov dword ptr [edx + eax*4], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
L_0x004a8df7:
    // 004a8df7  ff157cc14c00           -call dword ptr [0x4cc17c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030268) /* 0x4cc17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8dfd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8dff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8dff  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8e00  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8e01  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004a8e03  2eff15e8544b00         -call dword ptr cs:[0x4b54e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936936) /* 0x4b54e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8e0a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8e0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8e0e  7405                   -je 0x4a8e15
    if (cpu.flags.zf)
    {
        goto L_0x004a8e15;
    }
    // 004a8e10  83f8ff                 +cmp eax, -1
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
    // 004a8e13  7505                   -jne 0x4a8e1a
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e1a;
    }
L_0x004a8e15:
    // 004a8e15  e844000000             -call 0x4a8e5e
    cpu.esp -= 4;
    sub_4a8e5e(app, cpu);
    if (cpu.terminate) return;
L_0x004a8e1a:
    // 004a8e1a  e896feffff             -call 0x4a8cb5
    cpu.esp -= 4;
    sub_4a8cb5(app, cpu);
    if (cpu.terminate) return;
    // 004a8e1f  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004a8e21  2eff15e8544b00         -call dword ptr cs:[0x4b54e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936936) /* 0x4b54e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8e28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8e2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8e2c  7405                   -je 0x4a8e33
    if (cpu.flags.zf)
    {
        goto L_0x004a8e33;
    }
    // 004a8e2e  83f8ff                 +cmp eax, -1
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
    // 004a8e31  7505                   -jne 0x4a8e38
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e38;
    }
L_0x004a8e33:
    // 004a8e33  e826000000             -call 0x4a8e5e
    cpu.esp -= 4;
    sub_4a8e5e(app, cpu);
    if (cpu.terminate) return;
L_0x004a8e38:
    // 004a8e38  e878feffff             -call 0x4a8cb5
    cpu.esp -= 4;
    sub_4a8cb5(app, cpu);
    if (cpu.terminate) return;
    // 004a8e3d  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 004a8e3f  2eff15e8544b00         -call dword ptr cs:[0x4b54e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936936) /* 0x4b54e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8e46  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8e48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8e4a  7405                   -je 0x4a8e51
    if (cpu.flags.zf)
    {
        goto L_0x004a8e51;
    }
    // 004a8e4c  83f8ff                 +cmp eax, -1
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
    // 004a8e4f  7505                   -jne 0x4a8e56
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e56;
    }
L_0x004a8e51:
    // 004a8e51  e808000000             -call 0x4a8e5e
    cpu.esp -= 4;
    sub_4a8e5e(app, cpu);
    if (cpu.terminate) return;
L_0x004a8e56:
    // 004a8e56  e85afeffff             -call 0x4a8cb5
    cpu.esp -= 4;
    sub_4a8cb5(app, cpu);
    if (cpu.terminate) return;
    // 004a8e5b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e5c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8e5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e5e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8e5f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8e60  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8e62  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8e64  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8e66  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8e68  2eff1528544b00         -call dword ptr cs:[0x4b5428]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936744) /* 0x4b5428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8e6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8e71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8e73  750d                   -jne 0x4a8e82
    if (!cpu.flags.zf)
    {
        goto L_0x004a8e82;
    }
    // 004a8e75  8b1500d64c00           -mov edx, dword ptr [0x4cd600]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035520) /* 0x4cd600 */);
    // 004a8e7b  42                     -inc edx
    (cpu.edx)++;
    // 004a8e7c  891500d64c00           -mov dword ptr [0x4cd600], edx
    *app->getMemory<x86::reg32>(x86::reg32(5035520) /* 0x4cd600 */) = cpu.edx;
L_0x004a8e82:
    // 004a8e82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8e84  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e85  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8e87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e87  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a8e89  740e                   -je 0x4a8e99
    if (cpu.flags.zf)
    {
        goto L_0x004a8e99;
    }
    // 004a8e8b  c70200000080           -mov dword ptr [edx], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004a8e91  c70301000000           -mov dword ptr [ebx], 1
    *app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004a8e97  eb0c                   -jmp 0x4a8ea5
    goto L_0x004a8ea5;
L_0x004a8e99:
    // 004a8e99  c702000000c0           -mov dword ptr [edx], 0xc0000000
    *app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 004a8e9f  c70380000000           -mov dword ptr [ebx], 0x80
    *app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x004a8ea5:
    // 004a8ea5  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a8ea7  7403                   -je 0x4a8eac
    if (cpu.flags.zf)
    {
        goto L_0x004a8eac;
    }
    // 004a8ea9  800b02                 -or byte ptr [ebx], 2
    *app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004a8eac:
    // 004a8eac  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a8eae  7403                   -je 0x4a8eb3
    if (cpu.flags.zf)
    {
        goto L_0x004a8eb3;
    }
    // 004a8eb0  800b04                 -or byte ptr [ebx], 4
    *app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004a8eb3:
    // 004a8eb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8eb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8eb4  83f802                 +cmp eax, 2
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
    // 004a8eb7  750d                   -jne 0x4a8ec6
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ec6;
    }
    // 004a8eb9  c702000000c0           -mov dword ptr [edx], 0xc0000000
    *app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
L_0x004a8ebf:
    // 004a8ebf  c70380000000           -mov dword ptr [ebx], 0x80
    *app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 004a8ec5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8ec6:
    // 004a8ec6  83f801                 +cmp eax, 1
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
    // 004a8ec9  7508                   -jne 0x4a8ed3
    if (!cpu.flags.zf)
    {
        goto L_0x004a8ed3;
    }
    // 004a8ecb  c70200000040           -mov dword ptr [edx], 0x40000000
    *app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 004a8ed1  ebec                   -jmp 0x4a8ebf
    goto L_0x004a8ebf;
L_0x004a8ed3:
    // 004a8ed3  c70200000080           -mov dword ptr [edx], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004a8ed9  c70301000000           -mov dword ptr [ebx], 1
    *app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004a8edf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ee0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8ee1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8ee3  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a8ee6  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a8ee9  83f820                 +cmp eax, 0x20
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
    // 004a8eec  7210                   -jb 0x4a8efe
    if (cpu.flags.cf)
    {
        goto L_0x004a8efe;
    }
    // 004a8eee  7638                   -jbe 0x4a8f28
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8f28;
    }
    // 004a8ef0  83f830                 +cmp eax, 0x30
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
    // 004a8ef3  7241                   -jb 0x4a8f36
    if (cpu.flags.cf)
    {
        goto L_0x004a8f36;
    }
    // 004a8ef5  7629                   -jbe 0x4a8f20
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8f20;
    }
    // 004a8ef7  83f840                 +cmp eax, 0x40
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
    // 004a8efa  7434                   -je 0x4a8f30
    if (cpu.flags.zf)
    {
        goto L_0x004a8f30;
    }
    // 004a8efc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8efd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8efe:
    // 004a8efe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8f00  7607                   -jbe 0x4a8f09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8f09;
    }
    // 004a8f02  83f810                 +cmp eax, 0x10
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
    // 004a8f05  7411                   -je 0x4a8f18
    if (cpu.flags.zf)
    {
        goto L_0x004a8f18;
    }
    // 004a8f07  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f09:
    // 004a8f09  c70201000000           -mov dword ptr [edx], 1
    *app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004a8f0f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8f11  7523                   -jne 0x4a8f36
    if (!cpu.flags.zf)
    {
        goto L_0x004a8f36;
    }
    // 004a8f13  800a02                 -or byte ptr [edx], 2
    *app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a8f16  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f18:
    // 004a8f18  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004a8f1e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f20:
    // 004a8f20  c70202000000           -mov dword ptr [edx], 2
    *app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 004a8f26  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f28:
    // 004a8f28  c70201000000           -mov dword ptr [edx], 1
    *app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004a8f2e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f30:
    // 004a8f30  c70203000000           -mov dword ptr [edx], 3
    *app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x004a8f36:
    // 004a8f36  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8f38  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8f39  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8f3a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8f3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8f3d  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8f43  7206                   -jb 0x4a8f4b
    if (cpu.flags.cf)
    {
        goto L_0x004a8f4b;
    }
    // 004a8f45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8f47  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f48  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f49  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f4b:
    // 004a8f4b  83f803                 +cmp eax, 3
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
    // 004a8f4e  7d31                   -jge 0x4a8f81
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8f81;
    }
    // 004a8f50  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8f52  a15cd64c00             -mov eax, dword ptr [0x4cd65c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035612) /* 0x4cd65c */);
    // 004a8f57  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004a8f5a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8f5c  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a8f5f  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004a8f62  751d                   -jne 0x4a8f81
    if (!cpu.flags.zf)
    {
        goto L_0x004a8f81;
    }
    // 004a8f64  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004a8f66  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a8f69  886801                 -mov byte ptr [eax + 1], ch
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 004a8f6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8f6e  e83b000000             -call 0x4a8fae
    cpu.esp -= 4;
    sub_4a8fae(app, cpu);
    if (cpu.terminate) return;
    // 004a8f73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8f75  740a                   -je 0x4a8f81
    if (cpu.flags.zf)
    {
        goto L_0x004a8f81;
    }
    // 004a8f77  a15cd64c00             -mov eax, dword ptr [0x4cd65c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035612) /* 0x4cd65c */);
    // 004a8f7c  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004a8f81:
    // 004a8f81  a15cd64c00             -mov eax, dword ptr [0x4cd65c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035612) /* 0x4cd65c */);
    // 004a8f86  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a8f89  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f8a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f8b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8f8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8f8d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8f8e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8f91  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8f93  740e                   -je 0x4a8fa3
    if (cpu.flags.zf)
    {
        goto L_0x004a8fa3;
    }
    // 004a8f95  8b1d5cd64c00           -mov ebx, dword ptr [0x4cd65c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5035612) /* 0x4cd65c */);
    // 004a8f9b  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a8f9e  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004a8fa1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fa2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8fa3:
    // 004a8fa3  8b1d5cd64c00           -mov ebx, dword ptr [0x4cd65c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5035612) /* 0x4cd65c */);
    // 004a8fa9  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004a8fac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8fae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8fae  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8faf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8fb0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8fb1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8fb3  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8fb9  833d90c14c0000         +cmp dword ptr [0x4cc190], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030288) /* 0x4cc190 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8fc0  741d                   -je 0x4a8fdf
    if (cpu.flags.zf)
    {
        goto L_0x004a8fdf;
    }
    // 004a8fc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8fc4  ff1590c14c00           -call dword ptr [0x4cc190]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030288) /* 0x4cc190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8fca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8fcc  7411                   -je 0x4a8fdf
    if (cpu.flags.zf)
    {
        goto L_0x004a8fdf;
    }
L_0x004a8fce:
    // 004a8fce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8fd0  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8fd6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8fdb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fdc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fdd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8fdf:
    // 004a8fdf  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a8fe4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a8fe6  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a8fe9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8fea  2eff15b8544b00         -call dword ptr cs:[0x4b54b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936888) /* 0x4b54b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8ff1  83f802                 +cmp eax, 2
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
    // 004a8ff4  74d8                   -je 0x4a8fce
    if (cpu.flags.zf)
    {
        goto L_0x004a8fce;
    }
    // 004a8ff6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8ff8  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a8ffe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9000  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9001  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9002  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9003  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9004(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9004  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9005  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9006  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9007  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9009  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a900b  7c08                   -jl 0x4a9015
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9015;
    }
    // 004a900d  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9013  7613                   -jbe 0x4a9028
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9028;
    }
L_0x004a9015:
    // 004a9015  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a901a  e821ccfeff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 004a901f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9024  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9025  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9026  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9027  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9028:
    // 004a9028  8b15f8d54c00           -mov edx, dword ptr [0x4cd5f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a902e  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a9031  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9037  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a9039  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a903b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a903d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a903e  2eff1560554b00         -call dword ptr cs:[0x4b5560]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937056) /* 0x4b5560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9045  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9047  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9049  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a904f  83faff                 +cmp edx, -1
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
    // 004a9052  7505                   -jne 0x4a9059
    if (!cpu.flags.zf)
    {
        goto L_0x004a9059;
    }
    // 004a9054  e8e9cafeff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
L_0x004a9059:
    // 004a9059  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a905b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a905c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a905d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a905e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a905f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a905f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9060  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9061  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9062  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9063  8b15746a5400           -mov edx, dword ptr [0x546a74]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5532276) /* 0x546a74 */);
    // 004a9069  83fa40                 +cmp edx, 0x40
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
    // 004a906c  7d1c                   -jge 0x4a908a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a908a;
    }
    // 004a906e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9070  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a9073  bb786a5400             -mov ebx, 0x546a78
    cpu.ebx = 5532280 /*0x546a78*/;
    // 004a9078  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a907a  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a907d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a9080  890d746a5400           -mov dword ptr [0x546a74], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5532276) /* 0x546a74 */) = cpu.ecx;
    // 004a9086  01c3                   +add ebx, eax
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
    // 004a9088  eb24                   -jmp 0x4a90ae
    goto L_0x004a90ae;
L_0x004a908a:
    // 004a908a  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004a908f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9094  e8d5630000             -call 0x4af46e
    cpu.esp -= 4;
    sub_4af46e(app, cpu);
    if (cpu.terminate) return;
    // 004a9099  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a909b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a909d  750f                   -jne 0x4a90ae
    if (!cpu.flags.zf)
    {
        goto L_0x004a90ae;
    }
    // 004a909f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a90a4  b884f64b00             -mov eax, 0x4bf684
    cpu.eax = 4978308 /*0x4bf684*/;
    // 004a90a9  e8830f0000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
L_0x004a90ae:
    // 004a90ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a90b0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90b1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90b2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a90b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90b4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a90b5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a90b6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a90b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a90b9  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a90bd  740a                   -je 0x4a90c9
    if (cpu.flags.zf)
    {
        goto L_0x004a90c9;
    }
    // 004a90bf  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a90c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a90c2  2eff1540544b00         -call dword ptr cs:[0x4b5440]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936768) /* 0x4b5440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a90c9:
    // 004a90c9  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a90d0  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004a90d7  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a90de  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a90e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90e2  b814695400             -mov eax, 0x546914
    cpu.eax = 5531924 /*0x546914*/;
    // 004a90e7  e97d000000             -jmp 0x4a9169
    return sub_4a9169(app, cpu);
}

/* align: skip  */
void Application::sub_4a90ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90ec  b814695400             -mov eax, 0x546914
    cpu.eax = 5531924 /*0x546914*/;
    // 004a90f1  e9d9000000             -jmp 0x4a91cf
    return sub_4a91cf(app, cpu);
}

/* align: skip  */
void Application::sub_4a90f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90f6  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a90f9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a90fc  0534695400             +add eax, 0x546934
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5531956 /*0x546934*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9101  eb66                   -jmp 0x4a9169
    return sub_4a9169(app, cpu);
}

/* align: skip  */
void Application::sub_4a9103(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9103  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a9106  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a9109  0534695400             +add eax, 0x546934
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5531956 /*0x546934*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a910e  e9bc000000             -jmp 0x4a91cf
    return sub_4a91cf(app, cpu);
}

/* align: skip  */
void Application::sub_4a9113(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9113  e99dfbffff             -jmp 0x4a8cb5
    return sub_4a8cb5(app, cpu);
}

/* align: skip  */
void Application::sub_4a9118(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9118  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9119  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a911b  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a911e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a9121  0534695400             -add eax, 0x546934
    (cpu.eax) += x86::reg32(x86::sreg32(5531956 /*0x546934*/));
    // 004a9126  e889ffffff             -call 0x4a90b4
    cpu.esp -= 4;
    sub_4a90b4(app, cpu);
    if (cpu.terminate) return;
    // 004a912b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a912d  e8a1fcffff             -call 0x4a8dd3
    cpu.esp -= 4;
    sub_4a8dd3(app, cpu);
    if (cpu.terminate) return;
    // 004a9132  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9133  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9134  b8346a5400             -mov eax, 0x546a34
    cpu.eax = 5532212 /*0x546a34*/;
    // 004a9139  eb2e                   -jmp 0x4a9169
    return sub_4a9169(app, cpu);
}

/* align: skip  */
void Application::sub_4a913b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a913b  b8346a5400             -mov eax, 0x546a34
    cpu.eax = 5532212 /*0x546a34*/;
    // 004a9140  e98a000000             -jmp 0x4a91cf
    return sub_4a91cf(app, cpu);
}

/* align: skip  */
void Application::sub_4a9145(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9145  b824695400             -mov eax, 0x546924
    cpu.eax = 5531940 /*0x546924*/;
    // 004a914a  eb1d                   -jmp 0x4a9169
    return sub_4a9169(app, cpu);
}

/* align: skip  */
void Application::sub_4a914c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a914c  b824695400             -mov eax, 0x546924
    cpu.eax = 5531940 /*0x546924*/;
    // 004a9151  e979000000             -jmp 0x4a91cf
    return sub_4a91cf(app, cpu);
}

/* align: skip  */
void Application::sub_4a9156(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9156  b8546a5400             -mov eax, 0x546a54
    cpu.eax = 5532244 /*0x546a54*/;
    // 004a915b  eb0c                   -jmp 0x4a9169
    return sub_4a9169(app, cpu);
}

/* align: skip  */
void Application::sub_4a915d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a915d  b8546a5400             -mov eax, 0x546a54
    cpu.eax = 5532244 /*0x546a54*/;
    // 004a9162  eb6b                   -jmp 0x4a91cf
    return sub_4a91cf(app, cpu);
}

/* align: skip  */
void Application::sub_4a9164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9164  b8646a5400             -mov eax, 0x546a64
    cpu.eax = 5532260 /*0x546a64*/;
    // 004a9169  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a916a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a916b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a916c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a916d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a916f  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9176  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9179  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a917b  39d0                   +cmp eax, edx
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
    // 004a917d  7443                   -je 0x4a91c2
    if (cpu.flags.zf)
    {
        goto L_0x004a91c2;
    }
    // 004a917f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9183  7530                   -jne 0x4a91b5
    if (!cpu.flags.zf)
    {
        goto L_0x004a91b5;
    }
    // 004a9185  b8446a5400             -mov eax, 0x546a44
    cpu.eax = 5532228 /*0x546a44*/;
    // 004a918a  e8daffffff             -call 0x4a9169
    cpu.esp -= 4;
    sub_4a9169(app, cpu);
    if (cpu.terminate) return;
    // 004a918f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9193  7516                   -jne 0x4a91ab
    if (!cpu.flags.zf)
    {
        goto L_0x004a91ab;
    }
    // 004a9195  e8c6feffff             -call 0x4a9060
    cpu.esp -= 4;
    sub_4a9060(app, cpu);
    if (cpu.terminate) return;
    // 004a919a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a919b  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a919d  2eff150c554b00         -call dword ptr cs:[0x4b550c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936972) /* 0x4b550c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a91a4  c7430401000000         -mov dword ptr [ebx + 4], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004a91ab:
    // 004a91ab  b8446a5400             -mov eax, 0x546a44
    cpu.eax = 5532228 /*0x546a44*/;
    // 004a91b0  e81a000000             -call 0x4a91cf
    cpu.esp -= 4;
    sub_4a91cf(app, cpu);
    if (cpu.terminate) return;
L_0x004a91b5:
    // 004a91b5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a91b7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a91b8  2eff154c544b00         -call dword ptr cs:[0x4b544c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936780) /* 0x4b544c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a91bf  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004a91c2:
    // 004a91c2  ff430c                 -inc dword ptr [ebx + 0xc]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004a91c5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9169;
    // 004a9164  b8646a5400             -mov eax, 0x546a64
    cpu.eax = 5532260 /*0x546a64*/;
L_entry_0x004a9169:
    // 004a9169  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a916a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a916b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a916c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a916d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a916f  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9176  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9179  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a917b  39d0                   +cmp eax, edx
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
    // 004a917d  7443                   -je 0x4a91c2
    if (cpu.flags.zf)
    {
        goto L_0x004a91c2;
    }
    // 004a917f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9183  7530                   -jne 0x4a91b5
    if (!cpu.flags.zf)
    {
        goto L_0x004a91b5;
    }
    // 004a9185  b8446a5400             -mov eax, 0x546a44
    cpu.eax = 5532228 /*0x546a44*/;
    // 004a918a  e8daffffff             -call 0x4a9169
    cpu.esp -= 4;
    sub_4a9169(app, cpu);
    if (cpu.terminate) return;
    // 004a918f  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9193  7516                   -jne 0x4a91ab
    if (!cpu.flags.zf)
    {
        goto L_0x004a91ab;
    }
    // 004a9195  e8c6feffff             -call 0x4a9060
    cpu.esp -= 4;
    sub_4a9060(app, cpu);
    if (cpu.terminate) return;
    // 004a919a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a919b  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a919d  2eff150c554b00         -call dword ptr cs:[0x4b550c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936972) /* 0x4b550c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a91a4  c7430401000000         -mov dword ptr [ebx + 4], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004a91ab:
    // 004a91ab  b8446a5400             -mov eax, 0x546a44
    cpu.eax = 5532228 /*0x546a44*/;
    // 004a91b0  e81a000000             -call 0x4a91cf
    cpu.esp -= 4;
    sub_4a91cf(app, cpu);
    if (cpu.terminate) return;
L_0x004a91b5:
    // 004a91b5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a91b7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a91b8  2eff154c544b00         -call dword ptr cs:[0x4b544c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936780) /* 0x4b544c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a91bf  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004a91c2:
    // 004a91c2  ff430c                 -inc dword ptr [ebx + 0xc]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004a91c5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a91ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a91ca  b8646a5400             -mov eax, 0x546a64
    cpu.eax = 5532260 /*0x546a64*/;
    // 004a91cf  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a91d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a91d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a91d2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91d3  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a91d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a91d8  7617                   -jbe 0x4a91f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a91f1;
    }
    // 004a91da  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a91dd  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a91e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a91e2  750d                   -jne 0x4a91f1
    if (!cpu.flags.zf)
    {
        goto L_0x004a91f1;
    }
    // 004a91e4  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a91e6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91e7  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a91ea  2eff1510554b00         -call dword ptr cs:[0x4b5510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936976) /* 0x4b5510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a91f1:
    // 004a91f1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a91cf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a91cf;
    // 004a91ca  b8646a5400             -mov eax, 0x546a64
    cpu.eax = 5532260 /*0x546a64*/;
L_entry_0x004a91cf:
    // 004a91cf  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a91d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a91d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a91d2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91d3  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a91d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a91d8  7617                   -jbe 0x4a91f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a91f1;
    }
    // 004a91da  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a91dd  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a91e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a91e2  750d                   -jne 0x4a91f1
    if (!cpu.flags.zf)
    {
        goto L_0x004a91f1;
    }
    // 004a91e4  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a91e6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91e7  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a91ea  2eff1510554b00         -call dword ptr cs:[0x4b5510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936976) /* 0x4b5510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a91f1:
    // 004a91f1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a91f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a91f6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a91f7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a91f8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a91f9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91fa  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9201  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a9207  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9208  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a920a  2eff1584554b00         -call dword ptr cs:[0x4b5584]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937092) /* 0x4b5584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9211  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9213  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9215  7507                   -jne 0x4a921e
    if (!cpu.flags.zf)
    {
        goto L_0x004a921e;
    }
    // 004a9217  e86a620000             -call 0x4af486
    cpu.esp -= 4;
    sub_4af486(app, cpu);
    if (cpu.terminate) return;
    // 004a921c  eb0b                   -jmp 0x4a9229
    goto L_0x004a9229;
L_0x004a921e:
    // 004a921e  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9222  7407                   -je 0x4a922b
    if (cpu.flags.zf)
    {
        goto L_0x004a922b;
    }
    // 004a9224  e896620000             -call 0x4af4bf
    cpu.esp -= 4;
    sub_4af4bf(app, cpu);
    if (cpu.terminate) return;
L_0x004a9229:
    // 004a9229  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a922b:
    // 004a922b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a922c  2eff1564554b00         -call dword ptr cs:[0x4b5564]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937060) /* 0x4b5564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9233  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9235  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9236  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9237  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9238  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9239  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a923a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a923a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a923b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a923c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a923e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9240  7526                   -jne 0x4a9268
    if (!cpu.flags.zf)
    {
        goto L_0x004a9268;
    }
    // 004a9242  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9247  8b1590d64c00           -mov edx, dword ptr [0x4cd690]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004a924d  e81c620000             -call 0x4af46e
    cpu.esp -= 4;
    sub_4af46e(app, cpu);
    if (cpu.terminate) return;
    // 004a9252  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9254  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9256  7410                   -je 0x4a9268
    if (cpu.flags.zf)
    {
        goto L_0x004a9268;
    }
    // 004a9258  8b1d90d64c00           -mov ebx, dword ptr [0x4cd690]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004a925e  c6405201               -mov byte ptr [eax + 0x52], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004a9262  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x004a9268:
    // 004a9268  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a926a  e81b640000             -call 0x4af68a
    cpu.esp -= 4;
    sub_4af68a(app, cpu);
    if (cpu.terminate) return;
    // 004a926f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9271  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9272  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9273  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9274  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9275  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9276  2eff157c554b00         -call dword ptr cs:[0x4b557c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937084) /* 0x4b557c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a927d  668b1505ac4c00         -mov dx, word ptr [0x4cac05]
    cpu.dx = *app->getMemory<x86::reg16>(x86::reg32(5024773) /* 0x4cac05 */);
    // 004a9284  a340c14c00             -mov dword ptr [0x4cc140], eax
    *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */) = cpu.eax;
    // 004a9289  6681fa0080             +cmp dx, 0x8000
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a928e  7227                   -jb 0x4a92b7
    if (cpu.flags.cf)
    {
        goto L_0x004a92b7;
    }
    // 004a9290  803d03ac4c0004         +cmp byte ptr [0x4cac03], 4
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5024771) /* 0x4cac03 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9297  731e                   -jae 0x4a92b7
    if (!cpu.flags.cf)
    {
        goto L_0x004a92b7;
    }
L_0x004a9299:
    // 004a9299  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a929f  83faff                 +cmp edx, -1
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
    // 004a92a2  7413                   -je 0x4a92b7
    if (cpu.flags.zf)
    {
        goto L_0x004a92b7;
    }
    // 004a92a4  83fa02                 +cmp edx, 2
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
    // 004a92a7  770e                   -ja 0x4a92b7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a92b7;
    }
    // 004a92a9  2eff157c554b00         -call dword ptr cs:[0x4b557c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937084) /* 0x4b557c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a92b0  a340c14c00             -mov dword ptr [0x4cc140], eax
    *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */) = cpu.eax;
    // 004a92b5  ebe2                   -jmp 0x4a9299
    goto L_0x004a9299;
L_0x004a92b7:
    // 004a92b7  833d40c14c00ff         +cmp dword ptr [0x4cc140], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a92be  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004a92c1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a92c6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92c7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a92c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a92c9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a92ca  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a92cb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a92cc  833d40c14c00ff         +cmp dword ptr [0x4cc140], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a92d3  7506                   -jne 0x4a92db
    if (!cpu.flags.zf)
    {
        goto L_0x004a92db;
    }
L_0x004a92d5:
    // 004a92d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a92d7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92d8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92d9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a92db:
    // 004a92db  e85affffff             -call 0x4a923a
    cpu.esp -= 4;
    sub_4a923a(app, cpu);
    if (cpu.terminate) return;
    // 004a92e0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a92e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a92e4  742e                   -je 0x4a9314
    if (cpu.flags.zf)
    {
        goto L_0x004a9314;
    }
    // 004a92e6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a92e8  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004a92ee  e8a0620000             -call 0x4af593
    cpu.esp -= 4;
    sub_4af593(app, cpu);
    if (cpu.terminate) return;
    // 004a92f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a92f5  7509                   -jne 0x4a9300
    if (!cpu.flags.zf)
    {
        goto L_0x004a9300;
    }
    // 004a92f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a92f9  e84b19ffff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004a92fe  ebd5                   -jmp 0x4a92d5
    goto L_0x004a92d5;
L_0x004a9300:
    // 004a9300  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9301  8b1d40c14c00           -mov ebx, dword ptr [0x4cc140]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a9307  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9308  2eff1588554b00         -call dword ptr cs:[0x4b5588]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937096) /* 0x4b5588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a930f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a9314:
    // 004a9314  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9315  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9316  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9317  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9318  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9319  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a931a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a931b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a931c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a931d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a931f  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a9325  83faff                 +cmp edx, -1
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
    // 004a9328  743d                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a932a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a932b  2eff1584554b00         -call dword ptr cs:[0x4b5584]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937092) /* 0x4b5584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9332  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9334  7431                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a9336  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004a933c  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004a9342  e8ad620000             -call 0x4af5f4
    cpu.esp -= 4;
    sub_4af5f4(app, cpu);
    if (cpu.terminate) return;
    // 004a9347  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a9349  8b3d40c14c00           -mov edi, dword ptr [0x4cc140]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a934f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9350  2eff1588554b00         -call dword ptr cs:[0x4b5588]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937096) /* 0x4b5588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9357  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9359  740c                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a935b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a935d  7408                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a935f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9360  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9367:
    // 004a9367  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9368  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9369  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9367(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9367;
    // 004a9318  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9319  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a931a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a931b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a931c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a931d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a931f  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a9325  83faff                 +cmp edx, -1
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
    // 004a9328  743d                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a932a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a932b  2eff1584554b00         -call dword ptr cs:[0x4b5584]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937092) /* 0x4b5584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9332  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9334  7431                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a9336  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004a933c  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004a9342  e8ad620000             -call 0x4af5f4
    cpu.esp -= 4;
    sub_4af5f4(app, cpu);
    if (cpu.terminate) return;
    // 004a9347  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a9349  8b3d40c14c00           -mov edi, dword ptr [0x4cc140]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a934f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9350  2eff1588554b00         -call dword ptr cs:[0x4b5588]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937096) /* 0x4b5588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9357  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9359  740c                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a935b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a935d  7408                   -je 0x4a9367
    if (cpu.flags.zf)
    {
        goto L_0x004a9367;
    }
    // 004a935f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9360  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9367:
L_entry_0x004a9367:
    // 004a9367  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9368  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9369  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a936c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a936d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a936d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9372  e8a1ffffff             -call 0x4a9318
    cpu.esp -= 4;
    sub_4a9318(app, cpu);
    if (cpu.terminate) return;
    // 004a9377  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9378  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9379  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a937f  83faff                 +cmp edx, -1
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
    // 004a9382  7412                   -je 0x4a9396
    if (cpu.flags.zf)
    {
        goto L_0x004a9396;
    }
    // 004a9384  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9385  2eff1580554b00         -call dword ptr cs:[0x4b5580]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937088) /* 0x4b5580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a938c  c70540c14c00ffffffff   -mov dword ptr [0x4cc140], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */) = 4294967295 /*0xffffffff*/;
L_0x004a9396:
    // 004a9396  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9397  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9377(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9377;
    // 004a936d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9372  e8a1ffffff             -call 0x4a9318
    cpu.esp -= 4;
    sub_4a9318(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004a9377:
    // 004a9377  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9378  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9379  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a937f  83faff                 +cmp edx, -1
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
    // 004a9382  7412                   -je 0x4a9396
    if (cpu.flags.zf)
    {
        goto L_0x004a9396;
    }
    // 004a9384  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9385  2eff1580554b00         -call dword ptr cs:[0x4b5580]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937088) /* 0x4b5580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a938c  c70540c14c00ffffffff   -mov dword ptr [0x4cc140], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */) = 4294967295 /*0xffffffff*/;
L_0x004a9396:
    // 004a9396  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9397  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9399(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9399  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a939a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a939b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a939c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a939d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a939e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a939f  baf6904a00             -mov edx, 0x4a90f6
    cpu.edx = 4886774 /*0x4a90f6*/;
    // 004a93a4  bb03914a00             -mov ebx, 0x4a9103
    cpu.ebx = 4886787 /*0x4a9103*/;
    // 004a93a9  b913914a00             -mov ecx, 0x4a9113
    cpu.ecx = 4886803 /*0x4a9113*/;
    // 004a93ae  be18914a00             -mov esi, 0x4a9118
    cpu.esi = 4886808 /*0x4a9118*/;
    // 004a93b3  bfe2904a00             -mov edi, 0x4a90e2
    cpu.edi = 4886754 /*0x4a90e2*/;
    // 004a93b8  bdec904a00             -mov ebp, 0x4a90ec
    cpu.ebp = 4886764 /*0x4a90ec*/;
    // 004a93bd  b856914a00             -mov eax, 0x4a9156
    cpu.eax = 4886870 /*0x4a9156*/;
    // 004a93c2  891548c14c00           -mov dword ptr [0x4cc148], edx
    *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */) = cpu.edx;
    // 004a93c8  891d4cc14c00           -mov dword ptr [0x4cc14c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */) = cpu.ebx;
    // 004a93ce  890d50c14c00           -mov dword ptr [0x4cc150], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5030224) /* 0x4cc150 */) = cpu.ecx;
    // 004a93d4  893554c14c00           -mov dword ptr [0x4cc154], esi
    *app->getMemory<x86::reg32>(x86::reg32(5030228) /* 0x4cc154 */) = cpu.esi;
    // 004a93da  893d58c14c00           -mov dword ptr [0x4cc158], edi
    *app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */) = cpu.edi;
    // 004a93e0  892d5cc14c00           -mov dword ptr [0x4cc15c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */) = cpu.ebp;
    // 004a93e6  a370c14c00             -mov dword ptr [0x4cc170], eax
    *app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */) = cpu.eax;
    // 004a93eb  ba5d914a00             -mov edx, 0x4a915d
    cpu.edx = 4886877 /*0x4a915d*/;
    // 004a93f0  bb69914a00             -mov ebx, 0x4a9169
    cpu.ebx = 4886889 /*0x4a9169*/;
    // 004a93f5  b9cf914a00             -mov ecx, 0x4a91cf
    cpu.ecx = 4886991 /*0x4a91cf*/;
    // 004a93fa  beb4904a00             -mov esi, 0x4a90b4
    cpu.esi = 4886708 /*0x4a90b4*/;
    // 004a93ff  bf34914a00             -mov edi, 0x4a9134
    cpu.edi = 4886836 /*0x4a9134*/;
    // 004a9404  bd45914a00             -mov ebp, 0x4a9145
    cpu.ebp = 4886853 /*0x4a9145*/;
    // 004a9409  b83b914a00             -mov eax, 0x4a913b
    cpu.eax = 4886843 /*0x4a913b*/;
    // 004a940e  891574c14c00           -mov dword ptr [0x4cc174], edx
    *app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */) = cpu.edx;
    // 004a9414  891d60d64c00           -mov dword ptr [0x4cd660], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5035616) /* 0x4cd660 */) = cpu.ebx;
    // 004a941a  890d64d64c00           -mov dword ptr [0x4cd664], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5035620) /* 0x4cd664 */) = cpu.ecx;
    // 004a9420  893568d64c00           -mov dword ptr [0x4cd668], esi
    *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */) = cpu.esi;
    // 004a9426  893d60c14c00           -mov dword ptr [0x4cc160], edi
    *app->getMemory<x86::reg32>(x86::reg32(5030240) /* 0x4cc160 */) = cpu.edi;
    // 004a942c  892d64c14c00           -mov dword ptr [0x4cc164], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5030244) /* 0x4cc164 */) = cpu.ebp;
    // 004a9432  a368c14c00             -mov dword ptr [0x4cc168], eax
    *app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */) = cpu.eax;
    // 004a9437  ba4c914a00             -mov edx, 0x4a914c
    cpu.edx = 4886860 /*0x4a914c*/;
    // 004a943c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a9441  beca914a00             -mov esi, 0x4a91ca
    cpu.esi = 4886986 /*0x4a91ca*/;
    // 004a9446  89156cc14c00           -mov dword ptr [0x4cc16c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5030252) /* 0x4cc16c */) = cpu.edx;
    // 004a944c  e80ffcffff             -call 0x4a9060
    cpu.esp -= 4;
    sub_4a9060(app, cpu);
    if (cpu.terminate) return;
    // 004a9451  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9452  bf6d934a00             -mov edi, 0x4a936d
    cpu.edi = 4887405 /*0x4a936d*/;
    // 004a9457  a3446a5400             -mov dword ptr [0x546a44], eax
    *app->getMemory<x86::reg32>(x86::reg32(5532228) /* 0x546a44 */) = cpu.eax;
    // 004a945c  2eff150c554b00         -call dword ptr cs:[0x4b550c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936972) /* 0x4b550c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9463  b964914a00             -mov ecx, 0x4a9164
    cpu.ecx = 4886884 /*0x4a9164*/;
    // 004a9468  8b15002c5400           -mov edx, dword ptr [0x542c00]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516288) /* 0x542c00 */);
    // 004a946e  891d486a5400           -mov dword ptr [0x546a48], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5532232) /* 0x546a48 */) = cpu.ebx;
    // 004a9474  89357cc14c00           -mov dword ptr [0x4cc17c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5030268) /* 0x4cc17c */) = cpu.esi;
    // 004a947a  893d80c14c00           -mov dword ptr [0x4cc180], edi
    *app->getMemory<x86::reg32>(x86::reg32(5030272) /* 0x4cc180 */) = cpu.edi;
    // 004a9480  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 004a9486  890d78c14c00           -mov dword ptr [0x4cc178], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5030264) /* 0x4cc178 */) = cpu.ecx;
    // 004a948c  e802610000             -call 0x4af593
    cpu.esp -= 4;
    sub_4af593(app, cpu);
    if (cpu.terminate) return;
    // 004a9491  8b2d002c5400           -mov ebp, dword ptr [0x542c00]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5516288) /* 0x542c00 */);
    // 004a9497  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9498  a140c14c00             -mov eax, dword ptr [0x4cc140]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004a949d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a949e  2eff1588554b00         -call dword ptr cs:[0x4b5588]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937096) /* 0x4b5588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a94a5  c70544c14c00f6914a00   -mov dword ptr [0x4cc144], 0x4a91f6
    *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */) = 4887030 /*0x4a91f6*/;
    // 004a94af  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94b0  e9b2feffff             -jmp 0x4a9367
    return sub_4a9367(app, cpu);
}

/* align: skip  */
void Application::sub_4a94b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a94b5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a94b6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a94b7  b814695400             -mov eax, 0x546914
    cpu.eax = 5531924 /*0x546914*/;
    // 004a94bc  ba34695400             -mov edx, 0x546934
    cpu.edx = 5531956 /*0x546934*/;
    // 004a94c1  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a94c7  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x004a94cd:
    // 004a94cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a94cf  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a94d2  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a94d8  39da                   +cmp edx, ebx
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
    // 004a94da  75f1                   -jne 0x4a94cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a94cd;
    }
    // 004a94dc  b8646a5400             -mov eax, 0x546a64
    cpu.eax = 5532260 /*0x546a64*/;
    // 004a94e1  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a94e7  e8c6610000             -call 0x4af6b2
    cpu.esp -= 4;
    sub_4af6b2(app, cpu);
    if (cpu.terminate) return;
    // 004a94ec  b8346a5400             -mov eax, 0x546a34
    cpu.eax = 5532212 /*0x546a34*/;
    // 004a94f1  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a94f7  b824695400             -mov eax, 0x546924
    cpu.eax = 5531940 /*0x546924*/;
    // 004a94fc  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9502  b8546a5400             -mov eax, 0x546a54
    cpu.eax = 5532244 /*0x546a54*/;
    // 004a9507  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a950d  b8446a5400             -mov eax, 0x546a44
    cpu.eax = 5532228 /*0x546a44*/;
    // 004a9512  ff1568d64c00           -call dword ptr [0x4cd668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035624) /* 0x4cd668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9518  e85afeffff             -call 0x4a9377
    cpu.esp -= 4;
    sub_4a9377(app, cpu);
    if (cpu.terminate) return;
    // 004a951d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a951e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a951f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::strdup(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9520  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9521  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9522  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9523  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9524  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9526  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9528  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a9529  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a952b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a952d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a952f  49                     -dec ecx
    (cpu.ecx)--;
    // 004a9530  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9532  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
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
    // 004a9534  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a9536  49                     -dec ecx
    (cpu.ecx)--;
    // 004a9537  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a9538  41                     -inc ecx
    (cpu.ecx)++;
    // 004a9539  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a953b  e813c6feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a9540  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9542  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9544  7418                   -je 0x4a955e
    if (cpu.flags.zf)
    {
        goto L_0x004a955e;
    }
    // 004a9546  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9548  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a9549  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a954b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a954d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a954e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9550  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a9553  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 004a9555  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a9557  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a955a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 004a955c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a955d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004a955e:
    // 004a955e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9560  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9561  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9562  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9563  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9565(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9565  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9566  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9567  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9568  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9569  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a956b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a956d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a956f  2eff15fc544b00         -call dword ptr cs:[0x4b54fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936956) /* 0x4b54fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9576  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9579  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a957e  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9582  730f                   -jae 0x4a9593
    if (!cpu.flags.cf)
    {
        goto L_0x004a9593;
    }
    // 004a9584  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9585  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9586  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9587  2eff15d4544b00         -call dword ptr cs:[0x4b54d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936916) /* 0x4b54d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a958e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a958f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9590  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9591  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9592  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9593:
    // 004a9593  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 004a9598  e8b6c5feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a959d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a959f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a95a1  744d                   -je 0x4a95f0
    if (cpu.flags.zf)
    {
        goto L_0x004a95f0;
    }
    // 004a95a3  6808020000             -push 0x208
    *app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 004a95a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a95a9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a95aa  2eff15d0544b00         -call dword ptr cs:[0x4b54d0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936912) /* 0x4b54d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a95b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a95b3  750e                   -jne 0x4a95c3
    if (!cpu.flags.zf)
    {
        goto L_0x004a95c3;
    }
    // 004a95b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a95b7  e88d16ffff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004a95bc:
    // 004a95bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a95be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95c1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a95c3:
    // 004a95c3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a95c4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a95c5  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a95c7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a95c8  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a95ca  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a95cc  2eff1520554b00         -call dword ptr cs:[0x4b5520]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936992) /* 0x4b5520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a95d3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a95d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a95d7  e86d16ffff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004a95dc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a95de  74dc                   -je 0x4a95bc
    if (cpu.flags.zf)
    {
        goto L_0x004a95bc;
    }
    // 004a95e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a95e2  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 004a95e9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a95eb  e889610000             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
L_0x004a95f0:
    // 004a95f0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a95f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a95f5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a95f6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a95f7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a95f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a95fa  e87a610000             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004a95ff  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a9602  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9604  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9606  e848c5feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a960b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a960d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a960f  7405                   -je 0x4a9616
    if (cpu.flags.zf)
    {
        goto L_0x004a9616;
    }
    // 004a9611  e876610000             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
L_0x004a9616:
    // 004a9616  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9618  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9619  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a961a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a961b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
