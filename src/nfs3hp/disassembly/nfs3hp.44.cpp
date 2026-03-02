#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_509c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509c01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509c02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509c03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509c04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c06  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00509c08:
    // 00509c08  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509c0a  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00509c0d  8b0485c0f59e00         -mov eax, dword ptr [eax*4 + 0x9ef5c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 00509c14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509c16  7410                   -je 0x509c28
    if (cpu.flags.zf)
    {
        goto L_0x00509c28;
    }
    // 00509c18  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00509c1b:
    // 00509c1b  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00509c1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509c20  7513                   -jne 0x509c35
    if (!cpu.flags.zf)
    {
        goto L_0x00509c35;
    }
L_0x00509c22:
    // 00509c22  f64003c0               +test byte ptr [eax + 3], 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 192 /*0xc0*/));
    // 00509c26  741f                   -je 0x509c47
    if (cpu.flags.zf)
    {
        goto L_0x00509c47;
    }
L_0x00509c28:
    // 00509c28  46                     -inc esi
    (cpu.esi)++;
    // 00509c29  83fe0f                 +cmp esi, 0xf
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
    // 00509c2c  7eda                   -jle 0x509c08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509c08;
    }
    // 00509c2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509c30  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c31  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c32  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c33  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509c35:
    // 00509c35  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00509c38  39d1                   +cmp ecx, edx
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
    // 00509c3a  72df                   -jb 0x509c1b
    if (cpu.flags.cf)
    {
        goto L_0x00509c1b;
    }
    // 00509c3c  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00509c3f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509c41  39d9                   +cmp ecx, ebx
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
    // 00509c43  73d6                   -jae 0x509c1b
    if (!cpu.flags.cf)
    {
        goto L_0x00509c1b;
    }
    // 00509c45  ebdb                   -jmp 0x509c22
    goto L_0x00509c22;
L_0x00509c47:
    // 00509c47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509c49  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_509c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c50  43                     -inc ebx
    (cpu.ebx)++;
    // 00509c51  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00509c53  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509c59  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00509c5f  90                     -nop 
    ;
    // 00509c60  e98b08feff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c70  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509c71  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509c72  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509c73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c75  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509c77  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00509c79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509c7b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509c7d  7e2d                   -jle 0x509cac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509cac;
    }
    // 00509c7f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00509c81:
    // 00509c81  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c83  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509c85  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00509c87  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00509c89  7425                   -je 0x509cb0
    if (cpu.flags.zf)
    {
        goto L_0x00509cb0;
    }
    // 00509c8b  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00509c8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509c8f  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509c92  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00509c94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509c96  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00509c98  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x00509c9b:
    // 00509c9b  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509c9d  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00509c9f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509ca1  42                     -inc edx
    (cpu.edx)++;
    // 00509ca2  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509ca4  40                     -inc eax
    (cpu.eax)++;
    // 00509ca5  881c31                 -mov byte ptr [ecx + esi], bl
    *app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 00509ca8  39f8                   +cmp eax, edi
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
    // 00509caa  7cd5                   -jl 0x509c81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509c81;
    }
L_0x00509cac:
    // 00509cac  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cad  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509caf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509cb0:
    // 00509cb0  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00509cb2  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00509cb5  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00509cb7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509cbd  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509cc0  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00509cc6  ebd3                   -jmp 0x509c9b
    goto L_0x00509c9b;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_509cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509cd0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509cd1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509cd2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509cd3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509cd5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509cd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509cd9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509cdb  7e1e                   -jle 0x509cfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509cfb;
    }
L_0x00509cdd:
    // 00509cdd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509cdf  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509ce1  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00509ce3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00509ce5  7418                   -je 0x509cff
    if (cpu.flags.zf)
    {
        goto L_0x00509cff;
    }
    // 00509ce7  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00509ce9  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509cef  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00509cf2  42                     -inc edx
    (cpu.edx)++;
    // 00509cf3  40                     -inc eax
    (cpu.eax)++;
    // 00509cf4  884aff                 -mov byte ptr [edx - 1], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00509cf7  39f0                   +cmp eax, esi
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
    // 00509cf9  7ce2                   -jl 0x509cdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509cdd;
    }
L_0x00509cfb:
    // 00509cfb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509cff:
    // 00509cff  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00509d01  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509d04  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509d0a  42                     -inc edx
    (cpu.edx)++;
    // 00509d0b  40                     -inc eax
    (cpu.eax)++;
    // 00509d0c  884aff                 -mov byte ptr [edx - 1], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00509d0f  39f0                   +cmp eax, esi
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
    // 00509d11  7cca                   -jl 0x509cdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509cdd;
    }
    // 00509d13  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d14  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d15  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_509d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509d20  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509d21  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509d22  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509d23  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509d24  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509d27  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509d29  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509d2b  8b1dc0505600           -mov ebx, dword ptr [0x5650c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 00509d31  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509d33  7563                   -jne 0x509d98
    if (!cpu.flags.zf)
    {
        goto L_0x00509d98;
    }
    // 00509d35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509d37  7e57                   -jle 0x509d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509d90;
    }
L_0x00509d39:
    // 00509d39  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 00509d3c  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00509d41  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509d43  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00509d46  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509d49  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00509d4d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509d4f  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00509d52  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00509d55  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509d58  897c240c               -mov dword ptr [esp + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00509d5c  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00509d60  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00509d64  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00509d67  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00509d6a  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00509d70  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00509d73  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00509d75  42                     -inc edx
    (cpu.edx)++;
    // 00509d76  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00509d78  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509d7b  e8e059feff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00509d80  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00509d84  43                     -inc ebx
    (cpu.ebx)++;
    // 00509d85  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00509d89  8842ff                 -mov byte ptr [edx - 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00509d8c  39f3                   +cmp ebx, esi
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
    // 00509d8e  7ca9                   -jl 0x509d39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509d39;
    }
L_0x00509d90:
    // 00509d90  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509d93  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d94  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d95  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d96  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509d98:
    // 00509d98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509d9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509d9c  7ef2                   -jle 0x509d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509d90;
    }
L_0x00509d9e:
    // 00509d9e  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 00509da1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00509da6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509da8  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00509dab  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509dae  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00509db1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509db3  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00509db6  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509db9  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00509dbc  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00509dc0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00509dc3  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00509dc5  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00509dc8  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 00509dcb  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00509dcd  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00509dd1  8b3dc0505600           -mov edi, dword ptr [0x5650c0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 00509dd7  42                     -inc edx
    (cpu.edx)++;
    // 00509dd8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509ddb  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 00509dde  43                     -inc ebx
    (cpu.ebx)++;
    // 00509ddf  8842ff                 -mov byte ptr [edx - 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00509de2  39f3                   +cmp ebx, esi
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
    // 00509de4  7cb8                   -jl 0x509d9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509d9e;
    }
    // 00509de6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509de9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509dea  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509deb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509dec  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_509df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509df0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509df1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509df2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509df3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509df4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509df6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00509df8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509dfa  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509dfc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509dfe  7e1b                   -jle 0x509e1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509e1b;
    }
L_0x00509e00:
    // 00509e00  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00509e02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509e04  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509e0a  7314                   -jae 0x509e20
    if (!cpu.flags.cf)
    {
        goto L_0x00509e20;
    }
L_0x00509e0c:
    // 00509e0c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509e0f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509e12  47                     -inc edi
    (cpu.edi)++;
    // 00509e13  668941fe               -mov word ptr [ecx - 2], ax
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00509e17  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509e19  7ce5                   -jl 0x509e00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509e00;
    }
L_0x00509e1b:
    // 00509e1b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509e20:
    // 00509e20  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00509e22  7425                   -je 0x509e49
    if (cpu.flags.zf)
    {
        goto L_0x00509e49;
    }
    // 00509e24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e26  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509e2c  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00509e2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509e31  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509e34  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00509e3a  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00509e3d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509e40  01c3                   +add ebx, eax
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
    // 00509e42  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00509e49:
    // 00509e49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e4b  ebbf                   -jmp 0x509e0c
    goto L_0x00509e0c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_509e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509e50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509e51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509e52  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509e53  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509e54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509e56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509e58  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509e5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509e5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509e5e  7e40                   -jle 0x509ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509ea0;
    }
L_0x00509e60:
    // 00509e60  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00509e62  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00509e64  7425                   -je 0x509e8b
    if (cpu.flags.zf)
    {
        goto L_0x00509e8b;
    }
    // 00509e66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e68  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509e6e  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00509e71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509e73  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509e76  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00509e7c  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00509e7f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509e82  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509e84  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00509e8b:
    // 00509e8b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509e8e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509e91  47                     -inc edi
    (cpu.edi)++;
    // 00509e92  66895efe               -mov word ptr [esi - 2], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509e96  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509e98  7cc6                   -jl 0x509e60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509e60;
    }
    // 00509e9a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509ea0:
    // 00509ea0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509eb0  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00509eb2  e93906feff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_509ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509ec0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509ec1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509ec2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509ec4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509ec6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509ec8  7e16                   -jle 0x509ee0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509ee0;
    }
L_0x00509eca:
    // 00509eca  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509ecd  668b18                 -mov bx, word ptr [eax]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00509ed0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509ed3  41                     -inc ecx
    (cpu.ecx)++;
    // 00509ed4  66895afe               -mov word ptr [edx - 2], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509ed8  39f1                   +cmp ecx, esi
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
    // 00509eda  7cee                   -jl 0x509eca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509eca;
    }
    // 00509edc  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509ee0:
    // 00509ee0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ee1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ee2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_509ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509ef0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509ef1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509ef2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509ef3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509ef4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509ef6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00509ef8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509efa  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509efc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509efe  7e1b                   -jle 0x509f1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509f1b;
    }
L_0x00509f00:
    // 00509f00  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00509f02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509f04  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509f0a  7314                   -jae 0x509f20
    if (!cpu.flags.cf)
    {
        goto L_0x00509f20;
    }
L_0x00509f0c:
    // 00509f0c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509f0f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509f12  47                     -inc edi
    (cpu.edi)++;
    // 00509f13  668941fe               -mov word ptr [ecx - 2], ax
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00509f17  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509f19  7ce5                   -jl 0x509f00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509f00;
    }
L_0x00509f1b:
    // 00509f1b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509f20:
    // 00509f20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f22  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509f28  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00509f2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509f2d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509f30  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00509f36  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00509f39  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509f3c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509f3e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509f40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f42  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00509f45  75c5                   -jne 0x509f0c
    if (!cpu.flags.zf)
    {
        goto L_0x00509f0c;
    }
    // 00509f47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00509f4c  ebbe                   -jmp 0x509f0c
    goto L_0x00509f0c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_509f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509f50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509f51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509f52  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509f53  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509f54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509f56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509f58  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509f5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509f5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509f5e  7e40                   -jle 0x509fa0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509fa0;
    }
L_0x00509f60:
    // 00509f60  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00509f62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f64  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509f6a  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00509f6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509f6f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509f72  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00509f78  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00509f7b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509f7e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509f80  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509f82  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509f85  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509f88  47                     -inc edi
    (cpu.edi)++;
    // 00509f89  66895efe               -mov word ptr [esi - 2], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509f8d  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509f8f  7ccf                   -jl 0x509f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509f60;
    }
    // 00509f91  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509f97  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00509f9d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509fa0:
    // 00509fa0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509fb0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509fb1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00509fb4  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00509fb8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509fba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509fbc  7e51                   -jle 0x50a00f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a00f;
    }
    // 00509fbe  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509fbf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00509fc0:
    // 00509fc0  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00509fc4  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00509fc8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509fca  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00509fcd  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00509fd0  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00509fd3  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 00509fd6  897c2410               -mov dword ptr [esp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00509fda  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 00509fdd  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00509fe0  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax));
    // 00509fe3  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00509fe5  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00509fe9  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00509fec  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00509fef  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00509ff3  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00509ff5  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00509ff9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509ffc  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509ffe  41                     -inc ecx
    (cpu.ecx)++;
    // 00509fff  668932                 -mov word ptr [edx], si
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 0050a002  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a006  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a009  39f1                   +cmp ecx, esi
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
    // 0050a00b  7cb3                   -jl 0x509fc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509fc0;
    }
    // 0050a00d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a00e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a00f:
    // 0050a00f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a012  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_50a020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a020  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a021  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a022  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a023  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a024  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a027  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a029  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a02c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050a02f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a031  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a033  7e4f                   -jle 0x50a084
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a084;
    }
L_0x0050a035:
    // 0050a035  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a038  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a03e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a043  39e8                   +cmp eax, ebp
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
    // 0050a045  7445                   -je 0x50a08c
    if (cpu.flags.zf)
    {
        goto L_0x0050a08c;
    }
    // 0050a047  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a049  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a04b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050a04d  c1ff0c                 -sar edi, 0xc
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (12 /*0xc*/ % 32));
    // 0050a050  c1fe07                 -sar esi, 7
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (7 /*0x7*/ % 32));
    // 0050a053  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a056  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a059  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050a05d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a05f  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a062  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050a065  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0050a068  80ccf0                 -or ah, 0xf0
    cpu.ah |= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0050a06b  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a06d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a071  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a073  668932                 -mov word ptr [edx], si
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
L_0x0050a076:
    // 0050a076  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050a079  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a07c  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a07d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a080  39fb                   +cmp ebx, edi
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
    // 0050a082  7cb1                   -jl 0x50a035
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a035;
    }
L_0x0050a084:
    // 0050a084  83c408                 +add esp, 8
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
    // 0050a087  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a088  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a089  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a08a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a08b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a08c:
    // 0050a08c  66c7020000             -mov word ptr [edx], 0
    *app->getMemory<x86::reg16>(cpu.edx) = 0 /*0x0*/;
    // 0050a091  ebe3                   -jmp 0x50a076
    goto L_0x0050a076;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50a0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a0a0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a0a1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a0a2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a0a3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a0a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a0aa  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a0ad  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a0af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a0b1  7e3f                   -jle 0x50a0f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a0f2;
    }
    // 0050a0b3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0050a0b4:
    // 0050a0b4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050a0b6  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0b9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a0bb  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a0c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a0c3  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050a0c9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050a0cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a0ce  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050a0d1  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050a0d7  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050a0da  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a0dd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050a0df  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050a0e1  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a0e3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050a0e4  890f                   -mov dword ptr [edi], ecx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0050a0e6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a0ea  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0ed  39cd                   +cmp ebp, ecx
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
    // 0050a0ef  7cc3                   -jl 0x50a0b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a0b4;
    }
    // 0050a0f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a0f2:
    // 0050a0f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0f5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50a100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a100  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a101  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a102  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a103  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a104  8b2d90835600           -mov ebp, dword ptr [0x568390]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050a10a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a10c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a10e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a110  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a112  7e2c                   -jle 0x50a140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a140;
    }
L_0x0050a114:
    // 0050a114  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a116  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050a118  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0050a11f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0050a122  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a125  885a02                 -mov byte ptr [edx + 2], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050a128  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050a12b  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a12c  885a01                 -mov byte ptr [edx + 1], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0050a12f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a132  8a00                   -mov al, byte ptr [eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050a134  46                     -inc esi
    (cpu.esi)++;
    // 0050a135  8842fd                 -mov byte ptr [edx - 3], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0050a138  39fe                   +cmp esi, edi
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
    // 0050a13a  7cd8                   -jl 0x50a114
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a114;
    }
    // 0050a13c  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0050a140:
    // 0050a140  892d90835600           -mov dword ptr [0x568390], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.ebp;
    // 0050a146  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a147  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a148  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a149  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a14a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50a150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a150  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a151  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a152  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a155  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a157  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a159  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a15b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050a15d  7e52                   -jle 0x50a1b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a1b1;
    }
    // 0050a15f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a160:
    // 0050a160  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a163  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a168  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a16a  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 0050a16d  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a170  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0050a173  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a176  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050a17a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a17c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a17f  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a182  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a185  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a188  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050a18c  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0050a18f  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a193  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050a197  8842fd                 -mov byte ptr [edx - 3], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0050a19a  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a19e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a1a1  8842fe                 -mov byte ptr [edx - 2], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 0050a1a4  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a1a8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a1a9  8842ff                 -mov byte ptr [edx - 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0050a1ac  39fb                   +cmp ebx, edi
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
    // 0050a1ae  7cb0                   -jl 0x50a160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a160;
    }
    // 0050a1b0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a1b1:
    // 0050a1b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a1b4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1b5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a1c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a1c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a1c3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0050a1ca  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1cc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050a1ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a1d0  e81b03feff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0050a1d5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a1e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a1e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a1e2  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a1e5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050a1e7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a1e9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a1eb  7e43                   -jle 0x50a230
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a230;
    }
L_0x0050a1ed:
    // 0050a1ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1ef  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a1f2  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a1f5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1f7  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050a1fa  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a1fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a200  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050a202  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a206  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a209  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a20d  885afd                 -mov byte ptr [edx - 3], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0050a210  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a214  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a217  885afe                 -mov byte ptr [edx - 2], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 0050a21a  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050a21d  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a21e  885aff                 -mov byte ptr [edx - 1], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0050a221  39f1                   +cmp ecx, esi
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
    // 0050a223  7cc8                   -jl 0x50a1ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a1ed;
    }
    // 0050a225  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0050a22b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0050a22e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x0050a230:
    // 0050a230  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a233  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a234  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a235  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50a240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a240  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a241  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a242  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a243  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a244  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a247  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a249  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a24c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050a24f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a251  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a253  7e48                   -jle 0x50a29d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a29d;
    }
L_0x0050a255:
    // 0050a255  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a258  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a25e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a263  39e8                   +cmp eax, ebp
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
    // 0050a265  743e                   -je 0x50a2a5
    if (cpu.flags.zf)
    {
        goto L_0x0050a2a5;
    }
    // 0050a267  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a269  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a26b  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 0050a26e  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a271  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a274  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a277  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a27a  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 0050a27d  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 0050a280  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a286  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a289  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a28b  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a28d  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x0050a28f:
    // 0050a28f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050a292  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a295  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a296  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a299  39fb                   +cmp ebx, edi
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
    // 0050a29b  7cb8                   -jl 0x50a255
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a255;
    }
L_0x0050a29d:
    // 0050a29d  83c404                 +add esp, 4
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
    // 0050a2a0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a2a5:
    // 0050a2a5  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050a2ab  ebe2                   -jmp 0x50a28f
    goto L_0x0050a28f;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50a2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a2b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a2b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a2b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a2b3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a2b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a2b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a2b9  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a2bd  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a2c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a2c3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a2c5  7e50                   -jle 0x50a317
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a317;
    }
L_0x0050a2c7:
    // 0050a2c7  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a2ca  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a2d0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a2d5  39e8                   +cmp eax, ebp
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
    // 0050a2d7  7446                   -je 0x50a31f
    if (cpu.flags.zf)
    {
        goto L_0x0050a31f;
    }
    // 0050a2d9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a2db  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a2dd  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a2e0  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 0050a2e3  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a2e6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a2e9  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a2ec  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050a2ef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a2f1  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a2f4  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 0050a2f7  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 0050a2fa  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a2ff  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a301  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050a304  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a306  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x0050a308:
    // 0050a308  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a30c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a30f  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a310  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a313  39fb                   +cmp ebx, edi
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
    // 0050a315  7cb0                   -jl 0x50a2c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a2c7;
    }
L_0x0050a317:
    // 0050a317  83c408                 +add esp, 8
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
    // 0050a31a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a31f:
    // 0050a31f  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050a325  ebe1                   -jmp 0x50a308
    goto L_0x0050a308;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a330  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a331  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a332  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a333  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a336  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a338  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a33a  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a33d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a33f  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050a343  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a345  7e6a                   -jle 0x50a3b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a3b1;
    }
    // 0050a347  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0050a348:
    // 0050a348  668b07                 -mov ax, word ptr [edi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edi);
    // 0050a34b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a350  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a352  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 0050a355  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a358  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050a35a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a35c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0050a35f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0050a362  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a365  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050a369  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0050a36c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a36f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a371  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a373  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a376  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0050a379  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0050a37c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a37f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050a382  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050a384  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a387  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0050a38a  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a38c  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a38e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050a390  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050a393  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0050a396  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a398  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a39a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a39c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a3a0  8956fc                 -mov dword ptr [esi - 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a3a3  40                     -inc eax
    (cpu.eax)++;
    // 0050a3a4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a3a8  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050a3ac  39d0                   +cmp eax, edx
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
    // 0050a3ae  7c98                   -jl 0x50a348
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a348;
    }
    // 0050a3b0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a3b1:
    // 0050a3b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a3b4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50a3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a3c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a3c1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a3c4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a3c6  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a3ca  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a3ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a3d0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050a3d2  7e5e                   -jle 0x50a432
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a432;
    }
    // 0050a3d4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a3d5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a3d6:
    // 0050a3d6  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0050a3da  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 0050a3dd  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a3e3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a3e5  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 0050a3e8  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3eb  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0050a3ef  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a3f1  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0050a3f4  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3f7  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3fa  897c240c               -mov dword ptr [esp + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0050a3fe  8d3cd500000000         -lea edi, [edx*8]
    cpu.edi = x86::reg32(cpu.edx * 8);
    // 0050a405  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a407  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a40b  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0050a40e  c1e613                 -shl esi, 0x13
    cpu.esi <<= 19 /*0x13*/ % 32;
    // 0050a411  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a413  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a417  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a41a  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0050a41d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a420  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a422  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a423  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a425  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050a429  8951fc                 -mov dword ptr [ecx - 4], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a42c  39f3                   +cmp ebx, esi
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
    // 0050a42e  7ca6                   -jl 0x50a3d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a3d6;
    }
    // 0050a430  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a431  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a432:
    // 0050a432  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a435  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a440  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a441  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a444  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a446  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a44a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a44e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a450  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050a452  7e5c                   -jle 0x50a4b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a4b0;
    }
    // 0050a454  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a455  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a456:
    // 0050a456  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0050a45a  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 0050a45d  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a463  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a465  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 0050a468  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a46b  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050a46f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a471  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a474  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a477  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a47a  8974240c               -mov dword ptr [esp + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050a47e  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 0050a485  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a489  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 0050a48c  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 0050a48f  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a491  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a495  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a498  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 0050a49b  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a49e  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a4a0  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a4a1  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a4a3  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050a4a7  8951fc                 -mov dword ptr [ecx - 4], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a4aa  39f3                   +cmp ebx, esi
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
    // 0050a4ac  7ca8                   -jl 0x50a456
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a456;
    }
    // 0050a4ae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a4af  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a4b0:
    // 0050a4b0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a4b3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a4b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50a4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a4c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a4c1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a4c2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a4c5  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a4c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a4ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a4cc  7e36                   -jle 0x50a504
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a504;
    }
    // 0050a4ce  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a4cf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a4d0:
    // 0050a4d0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a4d2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a4d5  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a4d8  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 0050a4dc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a4de  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax));
    // 0050a4e1  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0050a4e4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a4e6  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a4ec  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0050a4ef  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a4f2  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a4f4  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a4f5  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a4f7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a4fb  895afc                 -mov dword ptr [edx - 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0050a4fe  39f1                   +cmp ecx, esi
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
    // 0050a500  7cce                   -jl 0x50a4d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a4d0;
    }
    // 0050a502  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a503  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a504:
    // 0050a504  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a507  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a508  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a509  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_50a510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a510  c1e302                 +shl ebx, 2
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
    // 0050a513  e9d8fffdff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50a520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a520  83f80f                 +cmp eax, 0xf
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
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a559(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a559;
    // 0050a520  83f80f                 +cmp eax, 0xf
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
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
L_entry_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a550;
    // 0050a520  83f80f                 +cmp eax, 0xf
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
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
L_entry_0x0050a550:
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a543(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a543;
    // 0050a520  83f80f                 +cmp eax, 0xf
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
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
L_entry_0x0050a543:
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50a570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a570  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a573  730f                   -jae 0x50a584
    if (!cpu.flags.cf)
    {
        goto L_0x0050a584;
    }
    // 0050a575  83f842                 +cmp eax, 0x42
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(66 /*0x42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a578  7335                   -jae 0x50a5af
    if (!cpu.flags.cf)
    {
        goto L_0x0050a5af;
    }
    // 0050a57a  83f840                 +cmp eax, 0x40
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
    // 0050a57d  7248                   -jb 0x50a5c7
    if (cpu.flags.cf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a57f  7716                   -ja 0x50a597
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050a597;
    }
L_0x0050a581:
    // 0050a581  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050a583  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a584:
    // 0050a584  76bd                   -jbe 0x50a543
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a543(app, cpu);
    }
    // 0050a586  83f87d                 +cmp eax, 0x7d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a589  7312                   -jae 0x50a59d
    if (!cpu.flags.cf)
    {
        goto L_0x0050a59d;
    }
    // 0050a58b  83f87a                 +cmp eax, 0x7a
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
    // 0050a58e  7237                   -jb 0x50a5c7
    if (cpu.flags.cf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a590  76ef                   -jbe 0x50a581
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a581;
    }
    // 0050a592  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a595  7530                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
L_0x0050a597:
    // 0050a597  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a59c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a59d:
    // 0050a59d  76b1                   -jbe 0x50a550
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a550(app, cpu);
    }
    // 0050a59f  83f87e                 +cmp eax, 0x7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5a2  76b5                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a559(app, cpu);
    }
    // 0050a5a4  83f87f                 +cmp eax, 0x7f
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
    // 0050a5a7  751e                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
L_0x0050a5a9:
    // 0050a5a9  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a5ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5af:
    // 0050a5af  7610                   -jbe 0x50a5c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a5c1;
    }
    // 0050a5b1  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5b4  76f3                   -jbe 0x50a5a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a5a9;
    }
    // 0050a5b6  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5b9  750c                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a5bb  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0050a5c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5c1:
    // 0050a5c1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0050a5c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5c7:
    // 0050a5c7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050a5cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50a5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a5d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a5d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a5d2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a5d3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a5d4  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a5da  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a5dc  e8df2bffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a5e1  bf14a8a000             -mov edi, 0xa0a814
    cpu.edi = 10528788 /*0xa0a814*/;
    // 0050a5e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a5e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a5ea  0f846f000000           -je 0x50a65f
    if (cpu.flags.zf)
    {
        goto L_0x0050a65f;
    }
    // 0050a5f0  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a5f2  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a5f8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a5fb  83fe2a                 +cmp esi, 0x2a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5fe  0f8468000000           -je 0x50a66c
    if (cpu.flags.zf)
    {
        goto L_0x0050a66c;
    }
    // 0050a604  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a607  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 0050a611  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050a613  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a615  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a61b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0050a61e  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a621  744d                   -je 0x50a670
    if (cpu.flags.zf)
    {
        goto L_0x0050a670;
    }
    // 0050a623  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a626  7455                   -je 0x50a67d
    if (cpu.flags.zf)
    {
        goto L_0x0050a67d;
    }
    // 0050a628  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a62b  745b                   -je 0x50a688
    if (cpu.flags.zf)
    {
        goto L_0x0050a688;
    }
    // 0050a62d  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a630  745a                   -je 0x50a68c
    if (cpu.flags.zf)
    {
        goto L_0x0050a68c;
    }
    // 0050a632  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a635  7460                   -je 0x50a697
    if (cpu.flags.zf)
    {
        goto L_0x0050a697;
    }
    // 0050a637  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a63a  7466                   -je 0x50a6a2
    if (cpu.flags.zf)
    {
        goto L_0x0050a6a2;
    }
    // 0050a63c  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a63f  0f8575000000           -jne 0x50a6ba
    if (!cpu.flags.zf)
    {
        goto L_0x0050a6ba;
    }
    // 0050a645  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a64a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a64c  e8739cffff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
    // 0050a651  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a656  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a658:
    // 0050a658  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a65a  e8e1fbffff             -call 0x50a240
    cpu.esp -= 4;
    sub_50a240(app, cpu);
    if (cpu.terminate) return;
L_0x0050a65f:
    // 0050a65f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a661  81c400020000           +add esp, 0x200
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
    // 0050a667  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a668  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a669  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a66a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a66b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a66c:
    // 0050a66c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a66e  ebef                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a670:
    // 0050a670  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a674  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a676  e8e5380100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a67b  ebe2                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a67d:
    // 0050a67d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a67f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a681  e82afcffff             -call 0x50a2b0
    cpu.esp -= 4;
    sub_50a2b0(app, cpu);
    if (cpu.terminate) return;
    // 0050a686  ebd7                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a688:
    // 0050a688  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a68a  ebcc                   -jmp 0x50a658
    goto L_0x0050a658;
L_0x0050a68c:
    // 0050a68c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a68e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a690  e8abfdffff             -call 0x50a440
    cpu.esp -= 4;
    sub_50a440(app, cpu);
    if (cpu.terminate) return;
    // 0050a695  ebc8                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a697:
    // 0050a697  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a699  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a69b  e820fdffff             -call 0x50a3c0
    cpu.esp -= 4;
    sub_50a3c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a6a0  ebbd                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a6a2:
    // 0050a6a2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a6a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a6a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a6a8  e8b3370100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a6ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a6af  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a6b5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a6ba:
    // 0050a6ba  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a6bf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a6c0  bbb8f75400             -mov ebx, 0x54f7b8
    cpu.ebx = 5568440 /*0x54f7b8*/;
    // 0050a6c5  be13030000             -mov esi, 0x313
    cpu.esi = 787 /*0x313*/;
    // 0050a6ca  68c4f75400             -push 0x54f7c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568452 /*0x54f7c4*/;
    cpu.esp -= 4;
    // 0050a6cf  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a6d5  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a6db  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a6e1  e82a69efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a6e6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a6e9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a6eb  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a6f1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50a700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a700  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a701  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a702  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a703  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a704  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a70a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a70c  e8af2affff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a711  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a713  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a715  0f84f3000000           -je 0x50a80e
    if (cpu.flags.zf)
    {
        goto L_0x0050a80e;
    }
    // 0050a71b  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a71d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a723  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a726  83fb29                 +cmp ebx, 0x29
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a729  7452                   -je 0x50a77d
    if (cpu.flags.zf)
    {
        goto L_0x0050a77d;
    }
    // 0050a72b  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a72e  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 0050a737  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050a739  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a73b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a741  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0050a744  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a747  7438                   -je 0x50a781
    if (cpu.flags.zf)
    {
        goto L_0x0050a781;
    }
    // 0050a749  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a74c  744b                   -je 0x50a799
    if (cpu.flags.zf)
    {
        goto L_0x0050a799;
    }
    // 0050a74e  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a751  7451                   -je 0x50a7a4
    if (cpu.flags.zf)
    {
        goto L_0x0050a7a4;
    }
    // 0050a753  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a756  7457                   -je 0x50a7af
    if (cpu.flags.zf)
    {
        goto L_0x0050a7af;
    }
    // 0050a758  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a75b  7431                   -je 0x50a78e
    if (cpu.flags.zf)
    {
        goto L_0x0050a78e;
    }
    // 0050a75d  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a760  7458                   -je 0x50a7ba
    if (cpu.flags.zf)
    {
        goto L_0x0050a7ba;
    }
    // 0050a762  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a765  756b                   -jne 0x50a7d2
    if (!cpu.flags.zf)
    {
        goto L_0x0050a7d2;
    }
    // 0050a767  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a769  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a76b  e8549bffff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
L_0x0050a770:
    // 0050a770  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a772  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050a778  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a779  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a77d:
    // 0050a77d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a77f  ebef                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a781:
    // 0050a781  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a783  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a785  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a787  e8d4370100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a78c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a78e:
    // 0050a78e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a790  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a792  e859f7ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a797  ebd7                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a799:
    // 0050a799  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a79b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a79d  e81ef7ffff             -call 0x509ec0
    cpu.esp -= 4;
    sub_509ec0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7a2  ebcc                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7a4:
    // 0050a7a4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a7a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7a8  e813f7ffff             -call 0x509ec0
    cpu.esp -= 4;
    sub_509ec0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a7af:
    // 0050a7af  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7b1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a7b3  e87b99ffff             -call 0x504133
    cpu.esp -= 4;
    sub_504133(app, cpu);
    if (cpu.terminate) return;
    // 0050a7b8  ebb6                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7ba:
    // 0050a7ba  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a7bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a7be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a7c0  e89b360100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a7c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050a7c7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7c9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a7cb  e820f7ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7d0  eb9e                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7d2:
    // 0050a7d2  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a7d7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a7d8  bbf0f75400             -mov ebx, 0x54f7f0
    cpu.ebx = 5568496 /*0x54f7f0*/;
    // 0050a7dd  be50030000             -mov esi, 0x350
    cpu.esi = 848 /*0x350*/;
    // 0050a7e2  6800f85400             -push 0x54f800
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568512 /*0x54f800*/;
    cpu.esp -= 4;
    // 0050a7e7  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a7ed  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a7f3  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a7f9  e81268efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a7fe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a801  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a803  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a809  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a80e:
    // 0050a80e  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a813  b814a8a000             -mov eax, 0xa0a814
    cpu.eax = 10528788 /*0xa0a814*/;
    // 0050a818  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a81a  e8d1f6ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a81f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a821  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a823  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a829  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50a830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a830  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a831  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a832  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a833  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a834  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a83a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a83c  e87f29ffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a841  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a843  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a845  0f84f3000000           -je 0x50a93e
    if (cpu.flags.zf)
    {
        goto L_0x0050a93e;
    }
    // 0050a84b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a84d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a853  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a856  83f92c                 +cmp ecx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a859  0f8469000000           -je 0x50a8c8
    if (cpu.flags.zf)
    {
        goto L_0x0050a8c8;
    }
    // 0050a85f  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a862  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 0050a86c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050a86e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0050a870  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a876  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050a879  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a87c  744e                   -je 0x50a8cc
    if (cpu.flags.zf)
    {
        goto L_0x0050a8cc;
    }
    // 0050a87e  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a881  7456                   -je 0x50a8d9
    if (cpu.flags.zf)
    {
        goto L_0x0050a8d9;
    }
    // 0050a883  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a886  7457                   -je 0x50a8df
    if (cpu.flags.zf)
    {
        goto L_0x0050a8df;
    }
    // 0050a888  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a88b  745d                   -je 0x50a8ea
    if (cpu.flags.zf)
    {
        goto L_0x0050a8ea;
    }
    // 0050a88d  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a890  7420                   -je 0x50a8b2
    if (cpu.flags.zf)
    {
        goto L_0x0050a8b2;
    }
    // 0050a892  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a895  745e                   -je 0x50a8f5
    if (cpu.flags.zf)
    {
        goto L_0x0050a8f5;
    }
    // 0050a897  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a89a  7566                   -jne 0x50a902
    if (!cpu.flags.zf)
    {
        goto L_0x0050a902;
    }
    // 0050a89c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a89e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a8a0  e81f9affff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
    // 0050a8a5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8a7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0050a8ab:
    // 0050a8ab  e800faffff             -call 0x50a2b0
    cpu.esp -= 4;
    sub_50a2b0(app, cpu);
    if (cpu.terminate) return;
L_0x0050a8b0:
    // 0050a8b0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a8b2:
    // 0050a8b2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a8b6  e8e5f7ffff             -call 0x50a0a0
    cpu.esp -= 4;
    sub_50a0a0(app, cpu);
    if (cpu.terminate) return;
L_0x0050a8bb:
    // 0050a8bb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a8bd  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050a8c3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a8c8:
    // 0050a8c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a8ca  ebef                   -jmp 0x50a8bb
    goto L_0x0050a8bb;
L_0x0050a8cc:
    // 0050a8cc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a8ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a8d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a8d2  e889360100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a8d7  ebd7                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8d9:
    // 0050a8d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8db  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8dd  ebcc                   -jmp 0x50a8ab
    goto L_0x0050a8ab;
L_0x0050a8df:
    // 0050a8df  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8e3  e858f9ffff             -call 0x50a240
    cpu.esp -= 4;
    sub_50a240(app, cpu);
    if (cpu.terminate) return;
    // 0050a8e8  ebc6                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8ea:
    // 0050a8ea  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8ec  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8ee  e8cdfaffff             -call 0x50a3c0
    cpu.esp -= 4;
    sub_50a3c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a8f3  ebbb                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8f5:
    // 0050a8f5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a8f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a8f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a8fb  e860350100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a900  ebae                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a902:
    // 0050a902  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a907  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a908  bb2cf85400             -mov ebx, 0x54f82c
    cpu.ebx = 5568556 /*0x54f82c*/;
    // 0050a90d  be97030000             -mov esi, 0x397
    cpu.esi = 919 /*0x397*/;
    // 0050a912  683cf85400             -push 0x54f83c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568572 /*0x54f83c*/;
    cpu.esp -= 4;
    // 0050a917  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a91d  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a923  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a929  e8e266efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a92e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a931  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a933  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a939  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a93e:
    // 0050a93e  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a943  b814a8a000             -mov eax, 0xa0a814
    cpu.eax = 10528788 /*0xa0a814*/;
    // 0050a948  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a94a  e851f7ffff             -call 0x50a0a0
    cpu.esp -= 4;
    sub_50a0a0(app, cpu);
    if (cpu.terminate) return;
    // 0050a94f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0050a951  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a953  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a959  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a960  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a961  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a962  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a963  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a964  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a967  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050a969  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a96b  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a96f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a971  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a977  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a979  e8f2fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a97e  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050a985  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a987  e8e4fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a98c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050a98e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a990  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a992  8a8194855600           -mov al, byte ptr [ecx + 0x568594]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5670292) /* 0x568594 */);
    // 0050a998  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050a99c  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050a99f  39c6                   +cmp esi, eax
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
    // 0050a9a1  7551                   -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050a9a3  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a9a8  7556                   -jne 0x50aa00
    if (!cpu.flags.zf)
    {
        goto L_0x0050aa00;
    }
    // 0050a9aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a9ac  e8bffbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a9b1  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050a9b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a9ba  e8b1fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a9bf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a9c1  8b048594845600         -mov eax, dword ptr [eax*4 + 0x568494]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5670036) /* 0x568494 */ + cpu.eax * 4);
L_0x0050a9c8:
    // 0050a9c8  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050a9cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050a9ce  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a9d0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050a9d3  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050a9d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a9db  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050a9dd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050a9df  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050a9e2  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050a9e8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a9ea  83f908                 +cmp ecx, 8
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
    // 0050a9ed  7f05                   -jg 0x50a9f4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050a9f4;
    }
    // 0050a9ef  83f808                 +cmp eax, 8
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
    // 0050a9f2  7f2c                   -jg 0x50aa20
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050aa20;
    }
L_0x0050a9f4:
    // 0050a9f4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a9f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a9fb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa00:
    // 0050aa00  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050aa02  e869fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aa07  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050aa0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050aa10  e85bfbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aa15  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050aa17  8b048594835600         -mov eax, dword ptr [eax*4 + 0x568394]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669780) /* 0x568394 */ + cpu.eax * 4);
    // 0050aa1e  eba8                   -jmp 0x50a9c8
    goto L_0x0050a9c8;
L_0x0050aa20:
    // 0050aa20  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050aa27  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050aa2c  e89ffbffff             -call 0x50a5d0
    cpu.esp -= 4;
    sub_50a5d0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa31  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050aa35  a390835600             -mov dword ptr [0x568390], eax
    *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.eax;
    // 0050aa3a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0050aa3c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050aa3e  7451                   -je 0x50aa91
    if (cpu.flags.zf)
    {
        goto L_0x0050aa91;
    }
    // 0050aa40  83fe6d                 +cmp esi, 0x6d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa43  7420                   -je 0x50aa65
    if (cpu.flags.zf)
    {
        goto L_0x0050aa65;
    }
    // 0050aa45  83ff0f                 +cmp edi, 0xf
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa48  7431                   -je 0x50aa7b
    if (cpu.flags.zf)
    {
        goto L_0x0050aa7b;
    }
    // 0050aa4a  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa4d  75a5                   -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050aa4f  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa54  e897f4ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa59  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa60  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa61  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa62  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa63  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa65:
    // 0050aa65  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa6a  e841f5ffff             -call 0x509fb0
    cpu.esp -= 4;
    sub_509fb0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa6f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa73  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa76  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa77  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa78  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa79  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa7b:
    // 0050aa7b  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa80  e86bf3ffff             -call 0x509df0
    cpu.esp -= 4;
    sub_509df0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa85  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa89  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa8c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa91:
    // 0050aa91  83fe6d                 +cmp esi, 0x6d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa94  74cf                   -je 0x50aa65
    if (cpu.flags.zf)
    {
        goto L_0x0050aa65;
    }
    // 0050aa96  83ff0f                 +cmp edi, 0xf
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa99  741f                   -je 0x50aaba
    if (cpu.flags.zf)
    {
        goto L_0x0050aaba;
    }
    // 0050aa9b  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa9e  0f8550ffffff           -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050aaa4  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aaa9  e8a2f4ffff             -call 0x509f50
    cpu.esp -= 4;
    sub_509f50(app, cpu);
    if (cpu.terminate) return;
    // 0050aaae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aab2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aab5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aaba:
    // 0050aaba  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aabf  e88cf3ffff             -call 0x509e50
    cpu.esp -= 4;
    sub_509e50(app, cpu);
    if (cpu.terminate) return;
    // 0050aac4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aac8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aacb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aace  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50aad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050aad0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050aad1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050aad2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050aad3  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0050aad6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050aad8  89542444               -mov dword ptr [esp + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0050aadc  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050aae0  894c242c               -mov dword ptr [esp + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0050aae4  e8d726ffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050aae9  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0050aaee  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0050aaf2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050aaf4  894c2434               -mov dword ptr [esp + 0x34], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 0050aaf8  89542438               -mov dword ptr [esp + 0x38], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
L_0x0050aafc:
    // 0050aafc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050aafe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab03  e868faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ab0a  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab0e  e85dfaffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ab15  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050ab17  0f8c2d030000           -jl 0x50ae4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ae4a;
    }
L_0x0050ab1d:
    // 0050ab1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050ab1f  0f8c60030000           -jl 0x50ae85
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ae85;
    }
L_0x0050ab25:
    // 0050ab25  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ab2a  0f848c030000           -je 0x50aebc
    if (cpu.flags.zf)
    {
        goto L_0x0050aebc;
    }
    // 0050ab30  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab32  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab37  e834faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab3c  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050ab43  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab47  e824faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ab4e  8b048594835600         -mov eax, dword ptr [eax*4 + 0x568394]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669780) /* 0x568394 */ + cpu.eax * 4);
L_0x0050ab55:
    // 0050ab55  8944244c               -mov dword ptr [esp + 0x4c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0050ab59  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab60  e80bfaffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab65  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050ab6c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab70  e8fbf9ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ab77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ab79  8a8294855600           -mov al, byte ptr [edx + 0x568594]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670292) /* 0x568594 */);
    // 0050ab7f  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0050ab83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050ab85  753a                   -jne 0x50abc1
    if (!cpu.flags.zf)
    {
        goto L_0x0050abc1;
    }
    // 0050ab87  b8a8f75400             -mov eax, 0x54f7a8
    cpu.eax = 5568424 /*0x54f7a8*/;
    // 0050ab8c  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab90  a390215500             -mov dword ptr [0x552190], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0050ab95  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab97  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ab98  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab9d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ab9e  ba68f85400             -mov edx, 0x54f868
    cpu.edx = 5568616 /*0x54f868*/;
    // 0050aba3  b909040000             -mov ecx, 0x409
    cpu.ecx = 1033 /*0x409*/;
    // 0050aba8  68fcf85400             -push 0x54f8fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568764 /*0x54f8fc*/;
    cpu.esp -= 4;
    // 0050abad  891594215500           -mov dword ptr [0x552194], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0050abb3  890d98215500           -mov dword ptr [0x552198], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050abb9  e85264efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050abbe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0050abc1:
    // 0050abc1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050abc3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050abc5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050abc8  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050abce  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050abd0  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0050abd4  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050abd8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050abda  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050abdd  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050abe3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050abe5  89442440               -mov dword ptr [esp + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0050abe9  40                     -inc eax
    (cpu.eax)++;
    // 0050abea  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050abec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050abee  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0050abf1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0050abf4  89442450               -mov dword ptr [esp + 0x50], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0050abf8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0050abfb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0050abfe  89442454               -mov dword ptr [esp + 0x54], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0050ac02  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ac04  e8b78a0100             -call 0x5236c0
    cpu.esp -= 4;
    sub_5236c0(app, cpu);
    if (cpu.terminate) return;
    // 0050ac09  89442448               -mov dword ptr [esp + 0x48], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0050ac0d  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ac11  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0050ac14  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050ac17  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0050ac19  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050ac1b  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0050ac1e  83f908                 +cmp ecx, 8
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
    // 0050ac21  7f71                   -jg 0x50ac94
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050ac94;
    }
    // 0050ac23  83fb08                 +cmp ebx, 8
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
    // 0050ac26  7e6c                   -jle 0x50ac94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ac94;
    }
    // 0050ac28  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050ac2d  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050ac31  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0050ac33  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ac35  0f84ab020000           -je 0x50aee6
    if (cpu.flags.zf)
    {
        goto L_0x0050aee6;
    }
    // 0050ac3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ac3d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ac3f  7e1e                   -jle 0x50ac5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ac5f;
    }
    // 0050ac41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050ac43:
    // 0050ac43  0fb6b064ae5600         -movzx esi, byte ptr [eax + 0x56ae64]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680740) /* 0x56ae64 */));
    // 0050ac4a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ac4d  8b34b514a8a000         -mov esi, dword ptr [esi*4 + 0xa0a814]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.esi * 4);
    // 0050ac54  40                     -inc eax
    (cpu.eax)++;
    // 0050ac55  89b110aca000           -mov dword ptr [ecx + 0xa0ac10], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10529808) /* 0xa0ac10 */) = cpu.esi;
    // 0050ac5b  39d8                   +cmp eax, ebx
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
    // 0050ac5d  7ce4                   -jl 0x50ac43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ac43;
    }
L_0x0050ac5f:
    // 0050ac5f  c7059083560014aca000   -mov dword ptr [0x568390], 0xa0ac14
    *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = 10529812 /*0xa0ac14*/;
L_0x0050ac69:
    // 0050ac69  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ac6e  0f84c4020000           -je 0x50af38
    if (cpu.flags.zf)
    {
        goto L_0x0050af38;
    }
    // 0050ac74  837c24446d             +cmp dword ptr [esp + 0x44], 0x6d
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ac79  0f857f020000           -jne 0x50aefe
    if (!cpu.flags.zf)
    {
        goto L_0x0050aefe;
    }
L_0x0050ac7f:
    // 0050ac7f  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050ac84  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050ac89  e822f3ffff             -call 0x509fb0
    cpu.esp -= 4;
    sub_509fb0(app, cpu);
    if (cpu.terminate) return;
L_0x0050ac8e:
    // 0050ac8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ac90  89442428               -mov dword ptr [esp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0050ac94:
    // 0050ac94  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050ac98  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ac99  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ac9d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ac9e  6870f95400             -push 0x54f970
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568880 /*0x54f970*/;
    cpu.esp -= 4;
    // 0050aca3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050aca7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050aca8  e8e349fdff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0050acad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050acb0  8b4c2454               -mov ecx, dword ptr [esp + 0x54]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050acb4  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050acb7  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050acbc  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050acc1  b83e040000             -mov eax, 0x43e
    cpu.eax = 1086 /*0x43e*/;
    // 0050acc6  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050accc  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0050acd2  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050acd7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050acd9  8d5114                 -lea edx, [ecx + 0x14]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0050acdc  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050ace2  e83969fdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0050ace7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050ace9  8944243c               -mov dword ptr [esp + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0050aced  b850485343             -mov eax, 0x43534850
    cpu.eax = 1129531472 /*0x43534850*/;
    // 0050acf2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050acf4  89443110               -mov dword ptr [ecx + esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.esi * 1) = cpu.eax;
    // 0050acf8  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050acfc  c60600                 -mov byte ptr [esi], 0
    *app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0050acff  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ad04  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050ad06  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad08  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ad0c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050ad0e  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0050ad10  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ad16  66894604               -mov word ptr [esi + 4], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0050ad1a  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad1e  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0050ad20  66894606               -mov word ptr [esi + 6], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 0050ad24  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050ad28  66894608               -mov word ptr [esi + 8], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0050ad2c  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0050ad30  668b560c               -mov dx, word ptr [esi + 0xc]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0050ad34  6689460a               -mov word ptr [esi + 0xa], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0050ad38  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0050ad3e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050ad41  6689560c               -mov word ptr [esi + 0xc], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0050ad45  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0050ad4a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0050ad4d  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050ad50  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad52  895efc                 -mov dword ptr [esi - 4], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0050ad55  668b5efe               -mov bx, word ptr [esi - 2]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0050ad59  8d4f10                 -lea ecx, [edi + 0x10]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050ad5c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0050ad62  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050ad65  66895efe               -mov word ptr [esi - 2], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 0050ad69  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 0050ad6e  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ad71  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050ad73  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad75  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad79  8956fc                 -mov dword ptr [esi - 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050ad7c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ad7e  7e1d                   -jle 0x50ad9d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ad9d;
    }
L_0x0050ad80:
    // 0050ad80  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ad84  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050ad86  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ad88  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050ad8c  47                     -inc edi
    (cpu.edi)++;
    // 0050ad8d  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050ad91  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad95  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ad97  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad99  39d7                   +cmp edi, edx
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
    // 0050ad9b  7ce3                   -jl 0x50ad80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ad80;
    }
L_0x0050ad9d:
    // 0050ad9d  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 0050ada2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ada6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ada8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0050adad  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050adb0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050adb2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050adb4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050adb6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0050adbd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0050adbf  3d50485343             +cmp eax, 0x43534850
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1129531472 /*0x43534850*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050adc4  7444                   -je 0x50ae0a
    if (cpu.flags.zf)
    {
        goto L_0x0050ae0a;
    }
    // 0050adc6  8b6c2440               -mov ebp, dword ptr [esp + 0x40]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050adca  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050adcb  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050adcf  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050add0  8b542458               -mov edx, dword ptr [esp + 0x58]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050add4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050add5  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050add9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050adda  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050addb  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050ade0  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050ade5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ade6  bf61040000             -mov edi, 0x461
    cpu.edi = 1121 /*0x461*/;
    // 0050adeb  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050adf1  6878f95400             -push 0x54f978
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568888 /*0x54f978*/;
    cpu.esp -= 4;
    // 0050adf6  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050adfc  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050ae02  e80962efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ae07  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0050ae0a:
    // 0050ae0a  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050ae0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ae10  7407                   -je 0x50ae19
    if (cpu.flags.zf)
    {
        goto L_0x0050ae19;
    }
    // 0050ae12  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ae14  e8776afdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0050ae19:
    // 0050ae19  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ae1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050ae1f  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050ae23  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050ae25  8b6c2444               -mov ebp, dword ptr [esp + 0x44]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ae29  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ae2e  39e8                   +cmp eax, ebp
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
    // 0050ae30  740f                   -je 0x50ae41
    if (cpu.flags.zf)
    {
        goto L_0x0050ae41;
    }
    // 0050ae32  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ae36  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050ae37  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0050ae3b  0f85bbfcffff           -jne 0x50aafc
    if (!cpu.flags.zf)
    {
        goto L_0x0050aafc;
    }
L_0x0050ae41:
    // 0050ae41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ae43  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0050ae46  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae47  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae48  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ae4a:
    // 0050ae4a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050ae4c  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050ae51  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ae56  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050ae5b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ae5c  bdfb030000             -mov ebp, 0x3fb
    cpu.ebp = 1019 /*0x3fb*/;
    // 0050ae61  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050ae67  687cf85400             -push 0x54f87c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568636 /*0x54f87c*/;
    cpu.esp -= 4;
    // 0050ae6c  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050ae72  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050ae78  e89361efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ae7d  83c408                 +add esp, 8
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
    // 0050ae80  e998fcffff             -jmp 0x50ab1d
    goto L_0x0050ab1d;
L_0x0050ae85:
    // 0050ae85  b8a8f75400             -mov eax, 0x54f7a8
    cpu.eax = 5568424 /*0x54f7a8*/;
    // 0050ae8a  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050ae8e  ba68f85400             -mov edx, 0x54f868
    cpu.edx = 5568616 /*0x54f868*/;
    // 0050ae93  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ae94  b9fd030000             -mov ecx, 0x3fd
    cpu.ecx = 1021 /*0x3fd*/;
    // 0050ae99  a390215500             -mov dword ptr [0x552190], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0050ae9e  68b4f85400             -push 0x54f8b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568692 /*0x54f8b4*/;
    cpu.esp -= 4;
    // 0050aea3  891594215500           -mov dword ptr [0x552194], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0050aea9  890d98215500           -mov dword ptr [0x552198], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050aeaf  e85c61efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050aeb4  83c408                 +add esp, 8
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
    // 0050aeb7  e969fcffff             -jmp 0x50ab25
    goto L_0x0050ab25;
L_0x0050aebc:
    // 0050aebc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050aebe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050aec3  e8a8f6ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aec8  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050aecf  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050aed3  e898f6ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aed8  01d0                   +add eax, edx
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
    // 0050aeda  8b048594845600         -mov eax, dword ptr [eax*4 + 0x568494]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5670036) /* 0x568494 */ + cpu.eax * 4);
    // 0050aee1  e96ffcffff             -jmp 0x50ab55
    goto L_0x0050ab55;
L_0x0050aee6:
    // 0050aee6  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aeeb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050aeef  e8dcf6ffff             -call 0x50a5d0
    cpu.esp -= 4;
    sub_50a5d0(app, cpu);
    if (cpu.terminate) return;
    // 0050aef4  a390835600             -mov dword ptr [0x568390], eax
    *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.eax;
    // 0050aef9  e96bfdffff             -jmp 0x50ac69
    goto L_0x0050ac69;
L_0x0050aefe:
    // 0050aefe  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050af02  83f90f                 +cmp ecx, 0xf
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
    // 0050af05  741d                   -je 0x50af24
    if (cpu.flags.zf)
    {
        goto L_0x0050af24;
    }
    // 0050af07  83f910                 +cmp ecx, 0x10
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
    // 0050af0a  0f857efdffff           -jne 0x50ac8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050ac8e;
    }
    // 0050af10  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af15  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af1a  e8d1efffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050af1f  e96afdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af24:
    // 0050af24  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af29  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af2e  e8bdeeffff             -call 0x509df0
    cpu.esp -= 4;
    sub_509df0(app, cpu);
    if (cpu.terminate) return;
    // 0050af33  e956fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af38:
    // 0050af38  837c24446d             +cmp dword ptr [esp + 0x44], 0x6d
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050af3d  0f843cfdffff           -je 0x50ac7f
    if (cpu.flags.zf)
    {
        goto L_0x0050ac7f;
    }
    // 0050af43  8b742440               -mov esi, dword ptr [esp + 0x40]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050af47  83fe0f                 +cmp esi, 0xf
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
    // 0050af4a  741d                   -je 0x50af69
    if (cpu.flags.zf)
    {
        goto L_0x0050af69;
    }
    // 0050af4c  83fe10                 +cmp esi, 0x10
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
    // 0050af4f  0f8539fdffff           -jne 0x50ac8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050ac8e;
    }
    // 0050af55  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af5a  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af5f  e8ecefffff             -call 0x509f50
    cpu.esp -= 4;
    sub_509f50(app, cpu);
    if (cpu.terminate) return;
    // 0050af64  e925fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af69:
    // 0050af69  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af6e  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af73  e8d8eeffff             -call 0x509e50
    cpu.esp -= 4;
    sub_509e50(app, cpu);
    if (cpu.terminate) return;
    // 0050af78  e911fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50af80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050af80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050af81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050af82  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050af87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050af89  e842fbffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050af8e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050af8f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050af90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50afa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050afa0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050afa1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050afa2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050afa3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050afa5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050afa7  e824e9ffff             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 0050afac  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050afb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050afb3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050afb5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050afb7  e814fbffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050afbc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50afc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050afc0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050afc1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050afc2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050afc3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050afc4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0050afc6  8b3db0099f00           -mov edi, dword ptr [0x9f09b0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10422704) /* 0x9f09b0 */);
    // 0050afcc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050afce  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 0050afd4  7420                   -je 0x50aff6
    if (cpu.flags.zf)
    {
        goto L_0x0050aff6;
    }
    // 0050afd6  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050afd9  7818                   -js 0x50aff3
    if (cpu.flags.sf)
    {
        goto L_0x0050aff3;
    }
L_0x0050afdb:
    // 0050afdb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050afdd  80f9ff                 +cmp cl, 0xff
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
    // 0050afe0  7411                   -je 0x50aff3
    if (cpu.flags.zf)
    {
        goto L_0x0050aff3;
    }
    // 0050afe2  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050afe5  66891a                 -mov word ptr [edx], bx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050afe8  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050afeb  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050afee  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050aff1  79e8                   -jns 0x50afdb
    if (!cpu.flags.sf)
    {
        goto L_0x0050afdb;
    }
L_0x0050aff3:
    // 0050aff3  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050aff6:
    // 0050aff6  83ed02                 +sub ebp, 2
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
    // 0050aff9  7859                   -js 0x50b054
    if (cpu.flags.sf)
    {
        goto L_0x0050b054;
    }
L_0x0050affb:
    // 0050affb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050affd  80f9ff                 +cmp cl, 0xff
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
    // 0050b000  7428                   -je 0x50b02a
    if (cpu.flags.zf)
    {
        goto L_0x0050b02a;
    }
    // 0050b002  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b005  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b008  80f9ff                 +cmp cl, 0xff
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
    // 0050b00b  7439                   -je 0x50b046
    if (cpu.flags.zf)
    {
        goto L_0x0050b046;
    }
    // 0050b00d  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b010  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b016  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050b019  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b01b  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x0050b01d:
    // 0050b01d  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b020  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b023  83ed02                 +sub ebp, 2
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
    // 0050b026  79d3                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
    // 0050b028  eb2a                   -jmp 0x50b054
    goto L_0x0050b054;
L_0x0050b02a:
    // 0050b02a  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b02d  80f9ff                 +cmp cl, 0xff
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
    // 0050b030  74eb                   -je 0x50b01d
    if (cpu.flags.zf)
    {
        goto L_0x0050b01d;
    }
    // 0050b032  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b035  66895a02               -mov word ptr [edx + 2], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 0050b039  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b03c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b03f  83ed02                 +sub ebp, 2
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
    // 0050b042  79b7                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
    // 0050b044  eb0e                   -jmp 0x50b054
    goto L_0x0050b054;
L_0x0050b046:
    // 0050b046  66891a                 -mov word ptr [edx], bx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050b049  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b04c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b04f  83ed02                 +sub ebp, 2
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
    // 0050b052  79a7                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
L_0x0050b054:
    // 0050b054  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050b057  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b05a  7818                   -js 0x50b074
    if (cpu.flags.sf)
    {
        goto L_0x0050b074;
    }
L_0x0050b05c:
    // 0050b05c  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050b05e  80f9ff                 +cmp cl, 0xff
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
    // 0050b061  7411                   -je 0x50b074
    if (cpu.flags.zf)
    {
        goto L_0x0050b074;
    }
    // 0050b063  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b066  66891a                 -mov word ptr [edx], bx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050b069  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b06c  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050b06f  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b072  79e8                   -jns 0x50b05c
    if (!cpu.flags.sf)
    {
        goto L_0x0050b05c;
    }
L_0x0050b074:
    // 0050b074  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b075  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b076  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b077  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50b080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b080  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b081  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b082  81ec00190000           -sub esp, 0x1900
    (cpu.esp) -= x86::reg32(x86::sreg32(6400 /*0x1900*/));
    // 0050b088  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050b08a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b08c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050b08e  ff1518b0a000           -call dword ptr [0xa0b018]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b094  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050b096  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050b098  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050b09a  ff1514b0a000           -call dword ptr [0xa0b014]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10530836) /* 0xa0b014 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b0a0  81c400190000           -add esp, 0x1900
    (cpu.esp) += x86::reg32(x86::sreg32(6400 /*0x1900*/));
    // 0050b0a6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b0a7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b0a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50b0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b0b0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b0b1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050b0b2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b0b3  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b0b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b0b8  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050b0bc  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050b0c0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050b0c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050b0c4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050b0c6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050b0c9  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050b0cf  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050b0d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b0d5  0f84d0020000           -je 0x50b3ab
    if (cpu.flags.zf)
    {
        goto L_0x0050b3ab;
    }
L_0x0050b0db:
    // 0050b0db  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050b0de  0fb62d11505600         -movzx ebp, byte ptr [0x565011]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */));
    // 0050b0e5  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050b0e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b0eb  8b5720                 -mov edx, dword ptr [edi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0050b0ee  a318b0a000             -mov dword ptr [0xa0b018], eax
    *app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */) = cpu.eax;
    // 0050b0f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b0f5  7402                   -je 0x50b0f9
    if (cpu.flags.zf)
    {
        goto L_0x0050b0f9;
    }
    // 0050b0f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x0050b0f9:
    // 0050b0f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050b0fb  752e                   -jne 0x50b12b
    if (!cpu.flags.zf)
    {
        goto L_0x0050b12b;
    }
    // 0050b0fd  b9acf95400             -mov ecx, 0x54f9ac
    cpu.ecx = 5568940 /*0x54f9ac*/;
    // 0050b102  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b103  bbbcf95400             -mov ebx, 0x54f9bc
    cpu.ebx = 5568956 /*0x54f9bc*/;
    // 0050b108  b82f000000             -mov eax, 0x2f
    cpu.eax = 47 /*0x2f*/;
    // 0050b10d  68ecf95400             -push 0x54f9ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569004 /*0x54f9ec*/;
    cpu.esp -= 4;
    // 0050b112  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050b118  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050b11e  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050b123  e8e85eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050b128  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0050b12b:
    // 0050b12b  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b130  7540                   -jne 0x50b172
    if (!cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b132  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050b134  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b139  39e8                   +cmp eax, ebp
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
    // 0050b13b  7435                   -je 0x50b172
    if (cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b13d  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b141  0f849f020000           -je 0x50b3e6
    if (cpu.flags.zf)
    {
        goto L_0x0050b3e6;
    }
    // 0050b147  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0050b14c:
    // 0050b14c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b150  e80bf8ffff             -call 0x50a960
    cpu.esp -= 4;
    sub_50a960(app, cpu);
    if (cpu.terminate) return;
    // 0050b155  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050b159  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b15b  0f848c020000           -je 0x50b3ed
    if (cpu.flags.zf)
    {
        goto L_0x0050b3ed;
    }
    // 0050b161  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b165  740b                   -je 0x50b172
    if (cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b167  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b169  a318b0a000             -mov dword ptr [0xa0b018], eax
    *app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */) = cpu.eax;
    // 0050b16e  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x0050b172:
    // 0050b172  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0050b175  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b178  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b17a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050b17d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050b17f  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050b182  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050b188  40                     -inc eax
    (cpu.eax)++;
    // 0050b189  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050b18b  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0050b18e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050b190  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050b192  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b195  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0050b198  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050b19c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b19e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050b1a2  e819850100             -call 0x5236c0
    cpu.esp -= 4;
    sub_5236c0(app, cpu);
    if (cpu.terminate) return;
    // 0050b1a7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1a9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1ad  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0050b1b1  a104505600             -mov eax, dword ptr [0x565004]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050b1b6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1b8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0050b1bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1bd  7e15                   -jle 0x50b1d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b1d4;
    }
    // 0050b1bf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050b1c3  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050b1c6  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1c8  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1cc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b1ce  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b1d0  89742424               -mov dword ptr [esp + 0x24], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0050b1d4:
    // 0050b1d4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1d8  8b350c505600           -mov esi, dword ptr [0x56500c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 0050b1de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b1e0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1e4  7e02                   -jle 0x50b1e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b1e8;
    }
    // 0050b1e6  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b1e8:
    // 0050b1e8  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b1ec  a100505600             -mov eax, dword ptr [0x565000]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050b1f1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1f5  7e20                   -jle 0x50b217
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b217;
    }
    // 0050b1f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b1f9  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b1fc  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0050b1ff  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050b202  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b204  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b208  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b20a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b20c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050b20f  89742410               -mov dword ptr [esp + 0x10], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0050b213  01442420               -add dword ptr [esp + 0x20], eax
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b217:
    // 0050b217  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b21b  8b3508505600           -mov esi, dword ptr [0x565008]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 0050b221  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050b223  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b227  7e0e                   -jle 0x50b237
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b237;
    }
    // 0050b229  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b22b  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b22e  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0050b231  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b233  01742420               -add dword ptr [esp + 0x20], esi
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0050b237:
    // 0050b237  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050b239  0f8e59010000           -jle 0x50b398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b398;
    }
    // 0050b23f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b241  0f8e51010000           -jle 0x50b398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b398;
    }
    // 0050b247  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050b24a  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050b24f  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0050b253  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b255  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b25a  40                     -inc eax
    (cpu.eax)++;
    // 0050b25b  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050b25d  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050b260  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0050b263  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0050b266  895c2418               -mov dword ptr [esp + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0050b26a  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050b26e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b272  8b1d20505600           -mov ebx, dword ptr [0x565020]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b278  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b27b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b27d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b281  8b3524505600           -mov esi, dword ptr [0x565024]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b287  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b28a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b28c  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050b28e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050b290  a11c505600             -mov eax, dword ptr [0x56501c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050b295  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b297  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b29b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b29d  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050b2a1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050b2a5  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0050b2a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b2ab  0f857f010000           -jne 0x50b430
    if (!cpu.flags.zf)
    {
        goto L_0x0050b430;
    }
    // 0050b2b1  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b2b6  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b2b8  0f837b010000           -jae 0x50b439
    if (!cpu.flags.cf)
    {
        goto L_0x0050b439;
    }
    // 0050b2be  3c04                   +cmp al, 4
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
    // 0050b2c0  0f83bb010000           -jae 0x50b481
    if (!cpu.flags.cf)
    {
        goto L_0x0050b481;
    }
L_0x0050b2c6:
    // 0050b2c6  833d18b0a00000         +cmp dword ptr [0xa0b018], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b2cd  0f85cf010000           -jne 0x50b4a2
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4a2;
    }
L_0x0050b2d3:
    // 0050b2d3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b2d7  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0050b2db  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b2df  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0050b2e3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b2e7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b2e9  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0050b2ed:
    // 0050b2ed  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b2f1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050b2f3  745a                   -je 0x50b34f
    if (cpu.flags.zf)
    {
        goto L_0x0050b34f;
    }
    // 0050b2f5  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b2f9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050b2fb  a128505600             -mov eax, dword ptr [0x565028]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */);
    // 0050b300  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0050b302  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050b304  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b308  89542424               -mov dword ptr [esp + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050b30c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b30e  0f84bd010000           -je 0x50b4d1
    if (cpu.flags.zf)
    {
        goto L_0x0050b4d1;
    }
    // 0050b314  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b316  895c243c               -mov dword ptr [esp + 0x3c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x0050b31a:
    // 0050b31a  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b31e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b320  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b322  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b324  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b328  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b32c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b330  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050b334  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b336  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b338  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050b33a  8b1dec435600           -mov ebx, dword ptr [0x5643ec]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653484) /* 0x5643ec */);
    // 0050b340  8954243c               -mov dword ptr [esp + 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0050b344  39da                   +cmp edx, ebx
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
    // 0050b346  0f8f6d010000           -jg 0x50b4b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b4b9;
    }
L_0x0050b34c:
    // 0050b34c  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b34d  75cb                   -jne 0x50b31a
    if (!cpu.flags.zf)
    {
        goto L_0x0050b31a;
    }
L_0x0050b34f:
    // 0050b34f  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b353  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b355  7436                   -je 0x50b38d
    if (cpu.flags.zf)
    {
        goto L_0x0050b38d;
    }
    // 0050b357  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050b35a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b35c  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b360  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b364  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b366  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b368  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b36c  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b370  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b374  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050b378  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b37c  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050b37e  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b382  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b384  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b386  47                     -inc edi
    (cpu.edi)++;
    // 0050b387  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b389  897c2424               -mov dword ptr [esp + 0x24], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x0050b38d:
    // 0050b38d  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b392  0f8f55ffffff           -jg 0x50b2ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b2ed;
    }
L_0x0050b398:
    // 0050b398  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050b39c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b39e  0f858d010000           -jne 0x50b531
    if (!cpu.flags.zf)
    {
        goto L_0x0050b531;
    }
L_0x0050b3a4:
    // 0050b3a4  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b3a7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3a8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3a9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050b3ab:
    // 0050b3ab  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050b3ad  b9acf95400             -mov ecx, 0x54f9ac
    cpu.ecx = 5568940 /*0x54f9ac*/;
    // 0050b3b2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b3b7  bbbcf95400             -mov ebx, 0x54f9bc
    cpu.ebx = 5568956 /*0x54f9bc*/;
    // 0050b3bc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050b3bd  bd26000000             -mov ebp, 0x26
    cpu.ebp = 38 /*0x26*/;
    // 0050b3c2  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050b3c8  68c4f95400             -push 0x54f9c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5568964 /*0x54f9c4*/;
    cpu.esp -= 4;
    // 0050b3cd  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050b3d3  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050b3d9  e8325cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050b3de  83c408                 +add esp, 8
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
    // 0050b3e1  e9f5fcffff             -jmp 0x50b0db
    goto L_0x0050b0db;
L_0x0050b3e6:
    // 0050b3e6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050b3e8  e95ffdffff             -jmp 0x50b14c
    goto L_0x0050b14c;
L_0x0050b3ed:
    // 0050b3ed  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b3f1  7423                   -je 0x50b416
    if (cpu.flags.zf)
    {
        goto L_0x0050b416;
    }
    // 0050b3f3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0050b3f8:
    // 0050b3f8  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0050b3fb  83f801                 +cmp eax, 1
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
    // 0050b3fe  751a                   -jne 0x50b41a
    if (!cpu.flags.zf)
    {
        goto L_0x0050b41a;
    }
    // 0050b400  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050b402  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b404  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b406  e8c5f6ffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050b40b  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050b40f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b411  e95cfdffff             -jmp 0x50b172
    goto L_0x0050b172;
L_0x0050b416:
    // 0050b416  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0050b418  ebde                   -jmp 0x50b3f8
    goto L_0x0050b3f8;
L_0x0050b41a:
    // 0050b41a  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050b41c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b41e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b420  e8abf6ffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050b425  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050b429  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b42b  e942fdffff             -jmp 0x50b172
    goto L_0x0050b172;
L_0x0050b430:
    // 0050b430  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b434  e99afeffff             -jmp 0x50b2d3
    goto L_0x0050b2d3;
L_0x0050b439:
    // 0050b439  770c                   -ja 0x50b447
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b447;
    }
    // 0050b43b  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050b43e  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b442  e97ffeffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b447:
    // 0050b447  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b449  7314                   -jae 0x50b45f
    if (!cpu.flags.cf)
    {
        goto L_0x0050b45f;
    }
    // 0050b44b  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b44d  0f8573feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b453  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050b456  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b45a  e967feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b45f:
    // 0050b45f  770c                   -ja 0x50b46d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b46d;
    }
    // 0050b461  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050b464  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b468  e959feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b46d:
    // 0050b46d  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b46f  0f8551feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b475  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050b478  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b47c  e945feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b481:
    // 0050b481  770b                   -ja 0x50b48e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b48e;
    }
    // 0050b483  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050b485  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b489  e938feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b48e:
    // 0050b48e  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b490  0f8530feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b496  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0050b499  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b49d  e924feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b4a2:
    // 0050b4a2  bb80b05000             -mov ebx, 0x50b080
    cpu.ebx = 5288064 /*0x50b080*/;
    // 0050b4a7  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050b4ab  895c2438               -mov dword ptr [esp + 0x38], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0050b4af  a314b0a000             -mov dword ptr [0xa0b014], eax
    *app->getMemory<x86::reg32>(x86::reg32(10530836) /* 0xa0b014 */) = cpu.eax;
    // 0050b4b4  e91afeffff             -jmp 0x50b2d3
    goto L_0x0050b2d3;
L_0x0050b4b9:
    // 0050b4b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b4bb  8944243c               -mov dword ptr [esp + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0050b4bf  e81cdcfeff             -call 0x4f90e0
    cpu.esp -= 4;
    sub_4f90e0(app, cpu);
    if (cpu.terminate) return;
    // 0050b4c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b4c6  0f84d8feffff           -je 0x50b3a4
    if (cpu.flags.zf)
    {
        goto L_0x0050b3a4;
    }
    // 0050b4cc  e97bfeffff             -jmp 0x50b34c
    goto L_0x0050b34c;
L_0x0050b4d1:
    // 0050b4d1  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b4d6  7422                   -je 0x50b4fa
    if (cpu.flags.zf)
    {
        goto L_0x0050b4fa;
    }
L_0x0050b4d8:
    // 0050b4d8  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b4dc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b4de  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b4e0  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b4e2  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b4e6  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b4ea  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b4ee  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b4f0  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b4f2  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b4f3  75e3                   -jne 0x50b4d8
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b4f5  e955feffff             -jmp 0x50b34f
    goto L_0x0050b34f;
L_0x0050b4fa:
    // 0050b4fa  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b4ff  75d7                   -jne 0x50b4d8
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b501  817c243880b05000       +cmp dword ptr [esp + 0x38], 0x50b080
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5288064 /*0x50b080*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b509  74cd                   -je 0x50b4d8
    if (cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b50b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b50d  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0050b510  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b514  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b516  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b518  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b51c  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b520  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0050b523  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0050b528  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b52a  01f9                   +add ecx, edi
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
    // 0050b52c  e91efeffff             -jmp 0x50b34f
    goto L_0x0050b34f;
L_0x0050b531:
    // 0050b531  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050b533  e85863fdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0050b538  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b53b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_50b540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b540  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b541  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050b542  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050b544  42                     -inc edx
    (cpu.edx)++;
    // 0050b545  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b547  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050b54a  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050b54c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b54e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b54f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50b560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b560  83f820                 +cmp eax, 0x20
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
    // 0050b563  7c12                   -jl 0x50b577
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b577;
    }
    // 0050b565  83f87f                 +cmp eax, 0x7f
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
    // 0050b568  7f0d                   -jg 0x50b577
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b577;
    }
    // 0050b56a  668b044594855600       -mov ax, word ptr [eax*2 + 0x568594]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5670292) /* 0x568594 */ + cpu.eax * 2);
    // 0050b572  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x0050b577:
    // 0050b577  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50b580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b580  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b581  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050b582  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b584  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050b586  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0050b588  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050b58a  42                     -inc edx
    (cpu.edx)++;
    // 0050b58b  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050b58d  7416                   -je 0x50b5a5
    if (cpu.flags.zf)
    {
        goto L_0x0050b5a5;
    }
    // 0050b58f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050b590  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0050b592  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050b595  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050b597  42                     -inc edx
    (cpu.edx)++;
    // 0050b598  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b59a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b59b  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0050b59d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5a2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5a3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050b5a5:
    // 0050b5a5  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5aa  e8b1ffffff             -call 0x50b560
    cpu.esp -= 4;
    sub_50b560(app, cpu);
    if (cpu.terminate) return;
    // 0050b5af  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0050b5b1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5b6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5b7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50b5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b5c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b5c1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050b5c2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b5c3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050b5c6  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050b5ca  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0050b5ce  89542418               -mov dword ptr [esp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0050b5d2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050b5d6  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050b5d9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b5db  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050b5de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050b5e1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b5e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b5e5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050b5e7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050b5e9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0050b5ec  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b5f0  40                     -inc eax
    (cpu.eax)++;
    // 0050b5f1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050b5f3  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050b5f7  8a2512505600           -mov ah, byte ptr [0x565012]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */);
    // 0050b5fd  8b2d80725600           -mov ebp, dword ptr [0x567280]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050b603  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0050b605  0f8585030000           -jne 0x50b990
    if (!cpu.flags.zf)
    {
        goto L_0x0050b990;
    }
    // 0050b60b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b60f  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b615  0f8c75030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b61b  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b621  0f8d69030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b627  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b62b  3b0504505600           +cmp eax, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b631  0f8c59030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b637  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b63d  0f8d4d030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b643  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b647  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b64b  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050b651  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b653  39d8                   +cmp eax, ebx
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
    // 0050b655  0f8c35030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b65b  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b661  0f8d29030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b667  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b66b  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b66f  8b1d04505600           -mov ebx, dword ptr [0x565004]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050b675  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b677  39d8                   +cmp eax, ebx
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
    // 0050b679  0f8c11030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b67f  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b685  0f8d05030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b68b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b68f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b691  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b697  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b699  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b69c  0f8565010000           -jne 0x50b807
    if (!cpu.flags.zf)
    {
        goto L_0x0050b807;
    }
    // 0050b6a2  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0050b6a5:
    // 0050b6a5  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b6a9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b6ad  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b6b3  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0050b6b6  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b6bc  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0050b6bf  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 0050b6c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b6c7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b6cb  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0050b6cf:
    // 0050b6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b6d1  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 0050b6d3  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0050b6d6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b6da  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b6e0  726b                   -jb 0x50b74d
    if (cpu.flags.cf)
    {
        goto L_0x0050b74d;
    }
    // 0050b6e2  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b6e8  7340                   -jae 0x50b72a
    if (!cpu.flags.cf)
    {
        goto L_0x0050b72a;
    }
    // 0050b6ea  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050b6ed  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b6ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b6f1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050b6f4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050b6f7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050b6f9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050b6ff  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050b702  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050b707  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b70a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b70c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b70e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b711  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b713  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050b716  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b718  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b71b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b721  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b726  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b728  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b72a:
    // 0050b72a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b72c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b732  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050b735  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b737  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b73a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050b740  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b743  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b746  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b748  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b74a  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b74d:
    // 0050b74d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b750  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b752  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 0050b754  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b757  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b75b  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b761  726b                   -jb 0x50b7ce
    if (cpu.flags.cf)
    {
        goto L_0x0050b7ce;
    }
    // 0050b763  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b769  7340                   -jae 0x50b7ab
    if (!cpu.flags.cf)
    {
        goto L_0x0050b7ab;
    }
    // 0050b76b  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050b76e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b770  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b772  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050b775  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050b778  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050b77a  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050b780  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050b783  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050b788  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b78b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b78d  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b78f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b792  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b794  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050b797  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b799  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b79c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b7a2  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b7a7  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b7a9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b7ab:
    // 0050b7ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b7ad  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b7b3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050b7b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b7b8  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b7bb  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050b7c1  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b7c4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b7c7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b7c9  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b7cb  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b7ce:
    // 0050b7ce  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b7d1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b7d5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050b7d6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b7d7  895c242c               -mov dword ptr [esp + 0x2c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0050b7db  0f85eefeffff           -jne 0x50b6cf
    if (!cpu.flags.zf)
    {
        goto L_0x0050b6cf;
    }
    // 0050b7e1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b7e5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050b7e8  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b7ec  41                     -inc ecx
    (cpu.ecx)++;
    // 0050b7ed  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b7ef  894c2418               -mov dword ptr [esp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050b7f3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b7f4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0050b7f8  0f85a7feffff           -jne 0x50b6a5
    if (!cpu.flags.zf)
    {
        goto L_0x0050b6a5;
    }
L_0x0050b7fe:
    // 0050b7fe  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050b801  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b802  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b803  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b804  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050b807:
    // 0050b807  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b80a  0f8577010000           -jne 0x50b987
    if (!cpu.flags.zf)
    {
        goto L_0x0050b987;
    }
    // 0050b810  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0050b814:
    // 0050b814  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b818  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b81c  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b822  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0050b825  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b82b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0050b82e  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 0050b834  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b836  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b83a  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x0050b83e:
    // 0050b83e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b840  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 0050b842  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0050b845  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b848  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0050b84b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050b84d  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b853  7273                   -jb 0x50b8c8
    if (cpu.flags.cf)
    {
        goto L_0x0050b8c8;
    }
    // 0050b855  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b85b  7348                   -jae 0x50b8a5
    if (!cpu.flags.cf)
    {
        goto L_0x0050b8a5;
    }
    // 0050b85d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050b860  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b862  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050b867  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050b86a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b86c  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050b872  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050b875  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b877  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b87a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b87c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b87e  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b881  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b887  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b889  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b88c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b88e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b890  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b893  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b899  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b89b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b89e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b8a3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b8a5:
    // 0050b8a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b8a7  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b8ad  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050b8b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b8b2  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b8b5  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050b8bb  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050b8be  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b8c1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b8c3  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b8c5  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b8c8:
    // 0050b8c8  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b8cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b8cd  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 0050b8cf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b8d2  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b8d6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b8dc  7273                   -jb 0x50b951
    if (cpu.flags.cf)
    {
        goto L_0x0050b951;
    }
    // 0050b8de  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b8e4  7348                   -jae 0x50b92e
    if (!cpu.flags.cf)
    {
        goto L_0x0050b92e;
    }
    // 0050b8e6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050b8e9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b8eb  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050b8f0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050b8f3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b8f5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050b8fb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050b8fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b900  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b903  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b905  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b907  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b90a  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b910  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b912  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b915  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b917  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b919  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b91c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b922  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b924  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b927  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b92c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b92e:
    // 0050b92e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b930  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b936  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050b939  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b93b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b93e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050b944  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050b947  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b94a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b94c  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b94e  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b951:
    // 0050b951  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b954  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b958  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050b959  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b95a  894c2430               -mov dword ptr [esp + 0x30], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0050b95e  0f85dafeffff           -jne 0x50b83e
    if (!cpu.flags.zf)
    {
        goto L_0x0050b83e;
    }
    // 0050b964  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b968  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050b96c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b970  40                     -inc eax
    (cpu.eax)++;
    // 0050b971  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b973  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050b977  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b978  8954244c               -mov dword ptr [esp + 0x4c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0050b97c  0f847cfeffff           -je 0x50b7fe
    if (cpu.flags.zf)
    {
        goto L_0x0050b7fe;
    }
    // 0050b982  e98dfeffff             -jmp 0x50b814
    goto L_0x0050b814;
L_0x0050b987:
    // 0050b987  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b98a  0f849c000000           -je 0x50ba2c
    if (cpu.flags.zf)
    {
        goto L_0x0050ba2c;
    }
L_0x0050b990:
    // 0050b990  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b994  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050b996  0f8e62feffff           -jle 0x50b7fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b7fe;
    }
    // 0050b99c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b9a0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b9a4  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050b9a8  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b9aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b9ac  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050b9b0  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050b9b4:
    // 0050b9b4  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b9b8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b9ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050b9bc  7e51                   -jle 0x50ba0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ba0f;
    }
    // 0050b9be  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050b9c2  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b9c6  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050b9ca  46                     -inc esi
    (cpu.esi)++;
    // 0050b9cb  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0050b9cf:
    // 0050b9cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b9d1  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edi);
    // 0050b9d3  47                     -inc edi
    (cpu.edi)++;
    // 0050b9d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b9d6  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b9d9  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0050b9dc  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b9e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b9e2  0f858f000000           -jne 0x50ba77
    if (!cpu.flags.zf)
    {
        goto L_0x0050ba77;
    }
L_0x0050b9e8:
    // 0050b9e8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b9ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b9ee  7411                   -je 0x50ba01
    if (cpu.flags.zf)
    {
        goto L_0x0050ba01;
    }
    // 0050b9f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050b9f2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b9f6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b9fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b9fc  e85f7d0100             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
L_0x0050ba01:
    // 0050ba01  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050ba05  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050ba08  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050ba0b  39c1                   +cmp ecx, eax
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
    // 0050ba0d  7cc0                   -jl 0x50b9cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b9cf;
    }
L_0x0050ba0f:
    // 0050ba0f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050ba13  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050ba17  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050ba1b  46                     -inc esi
    (cpu.esi)++;
    // 0050ba1c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050ba1e  89742414               -mov dword ptr [esp + 0x14], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0050ba22  39d6                   +cmp esi, edx
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
    // 0050ba24  0f8dd4fdffff           -jge 0x50b7fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b7fe;
    }
    // 0050ba2a  eb88                   -jmp 0x50b9b4
    goto L_0x0050b9b4;
L_0x0050ba2c:
    // 0050ba2c  8b1d1c505600           -mov ebx, dword ptr [0x56501c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050ba32  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba34  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba36  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ba37  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba38  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ba3c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ba3d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050ba41  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba42  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050ba46  8b0d20505600           -mov ecx, dword ptr [0x565020]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050ba4c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050ba4f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ba51  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050ba56  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0050ba58  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ba5c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ba5e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba60  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba61  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ba62  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050ba65  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ba66  e8817f0100             -call 0x5239ec
    cpu.esp -= 4;
    sub_5239ec(app, cpu);
    if (cpu.terminate) return;
    // 0050ba6b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0050ba6e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050ba71  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba72  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba73  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba74  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050ba77:
    // 0050ba77  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050ba7b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050ba7f  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050ba83  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ba85  e8d67c0100             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
    // 0050ba8a  e959ffffff             -jmp 0x50b9e8
    goto L_0x0050b9e8;
}

/* align: skip 0x90 */
void Application::sub_50ba90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ba90  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ba91  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ba92  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ba93  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050ba96  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050ba9a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ba9e  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050baa2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050baa4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050baa6  0f8eae000000           -jle 0x50bb5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bb5a;
    }
    // 0050baac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050baae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050bab0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bab3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bab5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050bab7  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0050babb  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050babe  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050bac1  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 0050bac6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050bac9  89742410               -mov dword ptr [esp + 0x10], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0050bacd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bacf  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bad1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050bad3  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050bad7  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050badb:
    // 0050badb  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050badf  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050bae2  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050bae6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bae8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050baea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050baec  7e4d                   -jle 0x50bb3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bb3b;
    }
    // 0050baee  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050baf2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050baf6  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050bafa  46                     -inc esi
    (cpu.esi)++;
    // 0050bafb  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0050baff:
    // 0050baff  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.edi));
    // 0050bb02  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bb04  47                     -inc edi
    (cpu.edi)++;
    // 0050bb05  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0050bb08  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050bb0b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050bb0d  7554                   -jne 0x50bb63
    if (!cpu.flags.zf)
    {
        goto L_0x0050bb63;
    }
L_0x0050bb0f:
    // 0050bb0f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050bb11  741a                   -je 0x50bb2d
    if (cpu.flags.zf)
    {
        goto L_0x0050bb2d;
    }
    // 0050bb13  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 0050bb1a  81c328725600           -add ebx, 0x567228
    (cpu.ebx) += x86::reg32(x86::sreg32(5665320 /*0x567228*/));
    // 0050bb20  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bb24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050bb26  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050bb28  e8d37f0100             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
L_0x0050bb2d:
    // 0050bb2d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050bb31  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050bb34  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050bb37  39e9                   +cmp ecx, ebp
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
    // 0050bb39  7cc4                   -jl 0x50baff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050baff;
    }
L_0x0050bb3b:
    // 0050bb3b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050bb3f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050bb43  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050bb47  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050bb4b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bb4d  41                     -inc ecx
    (cpu.ecx)++;
    // 0050bb4e  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050bb52  894c2410               -mov dword ptr [esp + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050bb56  39d9                   +cmp ecx, ebx
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
    // 0050bb58  7c81                   -jl 0x50badb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050badb;
    }
L_0x0050bb5a:
    // 0050bb5a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050bb5d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb5e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb5f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb60  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050bb63:
    // 0050bb63  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0050bb66  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bb6a  81c328725600           -add ebx, 0x567228
    (cpu.ebx) += x86::reg32(x86::sreg32(5665320 /*0x567228*/));
    // 0050bb70  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050bb74  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050bb76  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050bb78  e8837f0100             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 0050bb7d  eb90                   -jmp 0x50bb0f
    goto L_0x0050bb0f;
}

/* align: skip 0x90 */
void Application::sub_50bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bb80  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bb81  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bb82  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bb83  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0050bb86  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050bb88  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050bb8c  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050bb90  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050bb94  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050bb99  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050bb9b  7347                   -jae 0x50bbe4
    if (!cpu.flags.cf)
    {
        goto L_0x0050bbe4;
    }
    // 0050bb9d  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050bb9f  0f83cd010000           -jae 0x50bd72
    if (!cpu.flags.cf)
    {
        goto L_0x0050bd72;
    }
L_0x0050bba5:
    // 0050bba5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bba7  bb18fa5400             -mov ebx, 0x54fa18
    cpu.ebx = 5569048 /*0x54fa18*/;
    // 0050bbac  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050bbb1  be28fa5400             -mov esi, 0x54fa28
    cpu.esi = 5569064 /*0x54fa28*/;
    // 0050bbb6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050bbb7  bff1000000             -mov edi, 0xf1
    cpu.edi = 241 /*0xf1*/;
    // 0050bbbc  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050bbc2  6834fa5400             -push 0x54fa34
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569076 /*0x54fa34*/;
    cpu.esp -= 4;
    // 0050bbc7  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050bbcd  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050bbd3  e83854efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050bbd8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0050bbdb:
    // 0050bbdb  83c42c                 +add esp, 0x2c
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
    // 0050bbde  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbdf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbe0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbe1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050bbe4:
    // 0050bbe4  0f8762010000           -ja 0x50bd4c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd4c;
    }
L_0x0050bbea:
    // 0050bbea  bf70c25000             -mov edi, 0x50c270
    cpu.edi = 5292656 /*0x50c270*/;
L_0x0050bbef:
    // 0050bbef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050bbf1  74b2                   -je 0x50bba5
    if (cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bbf3  8b2d00505600           -mov ebp, dword ptr [0x565000]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050bbf9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bbfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bbfd  894c2418               -mov dword ptr [esp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050bc01  39ee                   +cmp esi, ebp
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
    // 0050bc03  7d04                   -jge 0x50bc09
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bc09;
    }
    // 0050bc05  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050bc07  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0050bc09:
    // 0050bc09  8b0d04505600           -mov ecx, dword ptr [0x565004]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050bc0f  39ca                   +cmp edx, ecx
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
    // 0050bc11  7d06                   -jge 0x50bc19
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bc19;
    }
    // 0050bc13  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc15  894c2418               -mov dword ptr [esp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x0050bc19:
    // 0050bc19  8b2d08505600           -mov ebp, dword ptr [0x565008]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 0050bc1f  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 0050bc22  39e9                   +cmp ecx, ebp
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
    // 0050bc24  7e04                   -jle 0x50bc2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bc2a;
    }
    // 0050bc26  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bc28  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0050bc2a:
    // 0050bc2a  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050bc2e  8b2d0c505600           -mov ebp, dword ptr [0x56500c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 0050bc34  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc36  39e9                   +cmp ecx, ebp
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
    // 0050bc38  7e08                   -jle 0x50bc42
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bc42;
    }
    // 0050bc3a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0050bc3c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc3e  894c2444               -mov dword ptr [esp + 0x44], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x0050bc42:
    // 0050bc42  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050bc44  7c95                   -jl 0x50bbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc46  837c244400             +cmp dword ptr [esp + 0x44], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bc4b  7c8e                   -jl 0x50bbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc4d  39d8                   +cmp eax, ebx
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
    // 0050bc4f  7d8a                   -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc51  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bc55  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bc59  7d80                   -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc5b  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050bc5f  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0050bc63  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 0050bc68  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050bc6b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050bc6f  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050bc72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050bc74  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 0050bc77  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0050bc7a  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050bc7d  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050bc81  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bc83  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0050bc86  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050bc8a  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050bc8d  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0050bc91  896c241c               -mov dword ptr [esp + 0x1c], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0050bc95  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0050bc99  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0050bc9c  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050bca0  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050bca4  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050bcaa  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bcac  8b2d14505600           -mov ebp, dword ptr [0x565014]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050bcb2  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx)));
    // 0050bcb4  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050bcba  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bcbc  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050bcbf  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050bcc2  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bcc4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050bcc6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050bcc8  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050bccb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050bccd  89542414               -mov dword ptr [esp + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0050bcd1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050bcd4  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0050bcd8  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bcda  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050bcdd  894c2410               -mov dword ptr [esp + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050bce1  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050bce3  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0050bce8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0050bcea  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 0050bcec  88442420               -mov byte ptr [esp + 0x20], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
    // 0050bcf0  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0050bcf4  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0050bcf6  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 0050bcf8  88442424               -mov byte ptr [esp + 0x24], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
L_0x0050bcfc:
    // 0050bcfc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bd00  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050bd03  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050bd07  89542418               -mov dword ptr [esp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0050bd0b  39c8                   +cmp eax, ecx
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
    // 0050bd0d  0f8dc8feffff           -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bd13  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050bd17  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bd1b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050bd1f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bd21  88442428               -mov byte ptr [esp + 0x28], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 0050bd25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050bd27  7562                   -jne 0x50bd8b
    if (!cpu.flags.zf)
    {
        goto L_0x0050bd8b;
    }
L_0x0050bd29:
    // 0050bd29  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bd2e  0f858f000000           -jne 0x50bdc3
    if (!cpu.flags.zf)
    {
        goto L_0x0050bdc3;
    }
L_0x0050bd34:
    // 0050bd34  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050bd38  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bd3c  8b1d1c505600           -mov ebx, dword ptr [0x56501c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050bd42  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bd44  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050bd46  894c241c               -mov dword ptr [esp + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050bd4a  ebb0                   -jmp 0x50bcfc
    goto L_0x0050bcfc;
L_0x0050bd4c:
    // 0050bd4c  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050bd4e  0f8251feffff           -jb 0x50bba5
    if (cpu.flags.cf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd54  770a                   -ja 0x50bd60
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd60;
    }
    // 0050bd56  bfc0c25000             -mov edi, 0x50c2c0
    cpu.edi = 5292736 /*0x50c2c0*/;
    // 0050bd5b  e98ffeffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd60:
    // 0050bd60  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050bd62  0f853dfeffff           -jne 0x50bba5
    if (!cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd68  bf50c35000             -mov edi, 0x50c350
    cpu.edi = 5292880 /*0x50c350*/;
    // 0050bd6d  e97dfeffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd72:
    // 0050bd72  770a                   -ja 0x50bd7e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd7e;
    }
    // 0050bd74  bf20c25000             -mov edi, 0x50c220
    cpu.edi = 5292576 /*0x50c220*/;
    // 0050bd79  e971feffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd7e:
    // 0050bd7e  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050bd80  0f851ffeffff           -jne 0x50bba5
    if (!cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd86  e95ffeffff             -jmp 0x50bbea
    goto L_0x0050bbea;
L_0x0050bd8b:
    // 0050bd8b  8a5c2420               -mov bl, byte ptr [esp + 0x20]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050bd8f  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bd91  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bd97  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 0050bd99  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050bd9e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bda0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bda2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bda4  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0050bda6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050bda7  88442428               -mov byte ptr [esp + 0x28], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x0050bdab:
    // 0050bdab  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050bdac  0f8477ffffff           -je 0x50bd29
    if (cpu.flags.zf)
    {
        goto L_0x0050bd29;
    }
    // 0050bdb2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050bdb4  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bdba  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bdbc  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050bdbd  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bdbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bdc1  ebe8                   -jmp 0x50bdab
    goto L_0x0050bdab;
L_0x0050bdc3:
    // 0050bdc3  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bdc5  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050bdc9  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050bdcd  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 0050bdcf  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bdd5  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 0050bdd7  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050bddc  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bdde  e951ffffff             -jmp 0x50bd34
    goto L_0x0050bd34;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50bdf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bdf0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050bdf1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050bdf2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bdf3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bdf4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bdf5  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0050bdfb  89842400030000         -mov dword ptr [esp + 0x300], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0050be02  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 0050be09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be0b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0050be0d:
    // 0050be0d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050be10  8b8814a8a000           -mov ecx, dword ptr [eax + 0xa0a814]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be16  8b9814a8a000           -mov ebx, dword ptr [eax + 0xa0a814]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be1c  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0050be1f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050be22  884c14fd               -mov byte ptr [esp + edx - 3], cl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 0050be26  885c14fe               -mov byte ptr [esp + edx - 2], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 0050be2a  8a9814a8a000           -mov bl, byte ptr [eax + 0xa0a814]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be30  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050be33  885c14ff               -mov byte ptr [esp + edx - 1], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 0050be37  3d00040000             +cmp eax, 0x400
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
    // 0050be3c  75cf                   -jne 0x50be0d
    if (!cpu.flags.zf)
    {
        goto L_0x0050be0d;
    }
    // 0050be3e  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0050be45  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050be47  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050be4a  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 0050be51  89842408030000         -mov dword ptr [esp + 0x308], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x0050be58:
    // 0050be58  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0050be5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be61  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 0050be64  89842418030000         -mov dword ptr [esp + 0x318], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 0050be6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be6d  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 0050be71  89842410030000         -mov dword ptr [esp + 0x310], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 0050be78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be7a  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0050be81  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 0050be85  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050be87  89842414030000         -mov dword ptr [esp + 0x314], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x0050be8e:
    // 0050be8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050be90  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0050be93  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050be95  754b                   -jne 0x50bee2
    if (!cpu.flags.zf)
    {
        goto L_0x0050bee2;
    }
    // 0050be97  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0050be99:
    // 0050be99  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050be9b  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 0050bea2  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050bea4  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 0050beab  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bead  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050beb0  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0050beb6  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0050beb8  39e9                   +cmp ecx, ebp
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
    // 0050beba  75d2                   -jne 0x50be8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050be8e;
    }
    // 0050bebc  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0050bec3  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050bec6  47                     -inc edi
    (cpu.edi)++;
    // 0050bec7  89842404030000         -mov dword ptr [esp + 0x304], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0050bece  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bed4  7c82                   -jl 0x50be58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050be58;
    }
    // 0050bed6  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0050bedc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bedd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bede  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bedf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bee0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bee1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050bee2:
    // 0050bee2  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0050bee7  89942424030000         -mov dword ptr [esp + 0x324], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 0050beee  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bef0  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 0050bef7  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050befa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050befc  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0050beff  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 0050bf06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bf08  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bf0a  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 0050bf15  89842420030000         -mov dword ptr [esp + 0x320], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 0050bf1c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf1e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf21  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf28  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 0050bf2f  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 0050bf33  3dff000000             +cmp eax, 0xff
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
    // 0050bf38  7e05                   -jle 0x50bf3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf3f;
    }
    // 0050bf3a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050bf3f:
    // 0050bf3f  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 0050bf46  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050bf49  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 0050bf54  89842428030000         -mov dword ptr [esp + 0x328], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 0050bf5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf5d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf60  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf67  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bf69  3dff000000             +cmp eax, 0xff
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
    // 0050bf6e  7e05                   -jle 0x50bf75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf75;
    }
    // 0050bf70  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050bf75:
    // 0050bf75  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0050bf7c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050bf7f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050bf81  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0050bf86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf8b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf8d  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 0050bf94  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bf96  39da                   +cmp edx, ebx
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
    // 0050bf98  7e02                   -jle 0x50bf9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf9c;
    }
    // 0050bf9a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0050bf9c:
    // 0050bf9c  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 0050bfa3  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 0050bfaa  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0050bfad  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050bfb0  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 0050bfb3  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bfb5  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bfb7  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050bfb9  e8a237feff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0050bfbe  e9d6feffff             -jmp 0x50be99
    goto L_0x0050be99;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50bfd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bfd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050bfd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050bfd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050bfd3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bfd4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bfd5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bfd6  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050bfd9  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050bfdf  e8bc030000             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0050bfe4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050bfe6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bfe8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050bfed  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050bff0  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050bff3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050bff6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050bffc  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0050c000  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050c003  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0050c006  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c00c  897c240c               -mov dword ptr [esp + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0050c010  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050c013  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c015  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050c019  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0050c01c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c01e  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0050c022:
    // 0050c022  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c02a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c02c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c02e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c031  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c035  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c03d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050c03f  884103                 -mov byte ptr [ecx + 3], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0050c042  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050c044  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c047  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c04b  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c053  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050c055  884102                 -mov byte ptr [ecx + 2], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0050c058  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c05a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c05d  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c061  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c069  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050c06b  884101                 -mov byte ptr [ecx + 1], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0050c06e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050c070  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c073  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c077  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c07a  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c080  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050c083  8841fc                 -mov byte ptr [ecx - 4], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0050c086  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050c08a  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050c08c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050c090  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050c092  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c096  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050c098  39c1                   +cmp ecx, eax
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
    // 0050c09a  7586                   -jne 0x50c022
    if (!cpu.flags.zf)
    {
        goto L_0x0050c022;
    }
    // 0050c09c  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c0a3  760a                   -jbe 0x50c0af
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c0af;
    }
    // 0050c0a5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050c0a8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c0af:
    // 0050c0af  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c0b5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050c0b9  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050c0bc  e82ffdffff             -call 0x50bdf0
    cpu.esp -= 4;
    sub_50bdf0(app, cpu);
    if (cpu.terminate) return;
    // 0050c0c1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050c0c4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50c0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c0d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c0d1  833d8072560000         +cmp dword ptr [0x567280], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c0d8  754b                   -jne 0x50c125
    if (!cpu.flags.zf)
    {
        goto L_0x0050c125;
    }
    // 0050c0da  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c0db  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c0dc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c0dd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c0de  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 0050c0e3  bb18fa5400             -mov ebx, 0x54fa18
    cpu.ebx = 5569048 /*0x54fa18*/;
    // 0050c0e8  be60fa5400             -mov esi, 0x54fa60
    cpu.esi = 5569120 /*0x54fa60*/;
    // 0050c0ed  bf50010000             -mov edi, 0x150
    cpu.edi = 336 /*0x150*/;
    // 0050c0f2  b870fa5400             -mov eax, 0x54fa70
    cpu.eax = 5569136 /*0x54fa70*/;
    // 0050c0f7  890d84725600           -mov dword ptr [0x567284], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665412) /* 0x567284 */) = cpu.ecx;
    // 0050c0fd  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050c103  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050c109  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050c10b  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0050c111  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050c117  e80455fdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0050c11c  a380725600             -mov dword ptr [0x567280], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */) = cpu.eax;
    // 0050c121  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c122  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c123  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c124  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050c125:
    // 0050c125  e856000000             -call 0x50c180
    cpu.esp -= 4;
    sub_50c180(app, cpu);
    if (cpu.terminate) return;
    // 0050c12a  833d0872560001         +cmp dword ptr [0x567208], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665288) /* 0x567208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c131  7423                   -je 0x50c156
    if (cpu.flags.zf)
    {
        goto L_0x0050c156;
    }
    // 0050c133  833d0c72560000         +cmp dword ptr [0x56720c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c13a  7426                   -je 0x50c162
    if (cpu.flags.zf)
    {
        goto L_0x0050c162;
    }
    // 0050c13c  c70588725600c0b55000   -mov dword ptr [0x567288], 0x50b5c0
    *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5289408 /*0x50b5c0*/;
L_0x0050c146:
    // 0050c146  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0050c148  893590725600           -mov dword ptr [0x567290], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.esi;
    // 0050c14e  89358c725600           -mov dword ptr [0x56728c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.esi;
    // 0050c154  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c155  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c156:
    // 0050c156  c7058872560080bb5000   -mov dword ptr [0x567288], 0x50bb80
    *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5290880 /*0x50bb80*/;
    // 0050c160  ebe4                   -jmp 0x50c146
    goto L_0x0050c146;
L_0x0050c162:
    // 0050c162  c7058872560090ba5000   -mov dword ptr [0x567288], 0x50ba90
    *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5290640 /*0x50ba90*/;
    // 0050c16c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c16e  893590725600           -mov dword ptr [0x567290], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.esi;
    // 0050c174  89358c725600           -mov dword ptr [0x56728c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.esi;
    // 0050c17a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c17b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_50c180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c180  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c181  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c182  833da472560000         +cmp dword ptr [0x5672a4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665444) /* 0x5672a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c189  7515                   -jne 0x50c1a0
    if (!cpu.flags.zf)
    {
        goto L_0x0050c1a0;
    }
    // 0050c18b  833d0c72560000         +cmp dword ptr [0x56720c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c192  7409                   -je 0x50c19d
    if (cpu.flags.zf)
    {
        goto L_0x0050c19d;
    }
    // 0050c194  833d0872560004         +cmp dword ptr [0x567208], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665288) /* 0x567208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c19b  7431                   -je 0x50c1ce
    if (cpu.flags.zf)
    {
        goto L_0x0050c1ce;
    }
L_0x0050c19d:
    // 0050c19d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c19e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c19f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1a0:
    // 0050c1a0  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0050c1a5  b828725600             -mov eax, 0x567228
    cpu.eax = 5665320 /*0x567228*/;
    // 0050c1aa  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1b0  e83be3fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1b5  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c1bc  77df                   -ja 0x50c19d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050c19d;
    }
    // 0050c1be  a180725600             -mov eax, dword ptr [0x567280]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1c3  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0050c1c6  e825fcffff             -call 0x50bdf0
    cpu.esp -= 4;
    sub_50bdf0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1cb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1cc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1ce:
    // 0050c1ce  a120725600             -mov eax, dword ptr [0x567220]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050c1d3  e8f8fdffff             -call 0x50bfd0
    cpu.esp -= 4;
    sub_50bfd0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1d8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1d9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50c1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c1e0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c1e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c1e2  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c1ea  750b                   -jne 0x50c1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0050c1f7;
    }
    // 0050c1ec  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c1ee  893588725600           -mov dword ptr [0x567288], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.esi;
    // 0050c1f4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1f5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1f7:
    // 0050c1f7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c1f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c1fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c1fc  e88f56fdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0050c201  890d80725600           -mov dword ptr [0x567280], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */) = cpu.ecx;
    // 0050c207  890d84725600           -mov dword ptr [0x567284], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665412) /* 0x567284 */) = cpu.ecx;
    // 0050c20d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c20e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c210  893588725600           -mov dword ptr [0x567288], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.esi;
    // 0050c216  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c217  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c218  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50c220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c220  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c222  7532                   -jne 0x50c256
    if (!cpu.flags.zf)
    {
        goto L_0x0050c256;
    }
L_0x0050c224:
    // 0050c224  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c226  7403                   -je 0x50c22b
    if (cpu.flags.zf)
    {
        goto L_0x0050c22b;
    }
    // 0050c228  885301                 -mov byte ptr [ebx + 1], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x0050c22b:
    // 0050c22b  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c22d  7403                   -je 0x50c232
    if (cpu.flags.zf)
    {
        goto L_0x0050c232;
    }
    // 0050c22f  885302                 -mov byte ptr [ebx + 2], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0050c232:
    // 0050c232  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c234  7403                   -je 0x50c239
    if (cpu.flags.zf)
    {
        goto L_0x0050c239;
    }
    // 0050c236  885303                 -mov byte ptr [ebx + 3], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x0050c239:
    // 0050c239  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c23b  7403                   -je 0x50c240
    if (cpu.flags.zf)
    {
        goto L_0x0050c240;
    }
    // 0050c23d  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x0050c240:
    // 0050c240  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c242  7403                   -je 0x50c247
    if (cpu.flags.zf)
    {
        goto L_0x0050c247;
    }
    // 0050c244  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x0050c247:
    // 0050c247  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c249  7403                   -je 0x50c24e
    if (cpu.flags.zf)
    {
        goto L_0x0050c24e;
    }
    // 0050c24b  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x0050c24e:
    // 0050c24e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c250  7508                   -jne 0x50c25a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c25a;
    }
    // 0050c252  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050c255  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c256:
    // 0050c256  8813                   -mov byte ptr [ebx], dl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 0050c258  ebca                   -jmp 0x50c224
    goto L_0x0050c224;
L_0x0050c25a:
    // 0050c25a  885307                 -mov byte ptr [ebx + 7], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 0050c25d  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050c260  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c270  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c271  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050c273  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c275  7539                   -jne 0x50c2b0
    if (!cpu.flags.zf)
    {
        goto L_0x0050c2b0;
    }
L_0x0050c277:
    // 0050c277  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c279  7404                   -je 0x50c27f
    if (cpu.flags.zf)
    {
        goto L_0x0050c27f;
    }
    // 0050c27b  66895102               -mov word ptr [ecx + 2], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x0050c27f:
    // 0050c27f  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c281  7404                   -je 0x50c287
    if (cpu.flags.zf)
    {
        goto L_0x0050c287;
    }
    // 0050c283  66895104               -mov word ptr [ecx + 4], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0050c287:
    // 0050c287  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c289  7404                   -je 0x50c28f
    if (cpu.flags.zf)
    {
        goto L_0x0050c28f;
    }
    // 0050c28b  66895106               -mov word ptr [ecx + 6], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x0050c28f:
    // 0050c28f  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c291  7404                   -je 0x50c297
    if (cpu.flags.zf)
    {
        goto L_0x0050c297;
    }
    // 0050c293  66895108               -mov word ptr [ecx + 8], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x0050c297:
    // 0050c297  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c299  7404                   -je 0x50c29f
    if (cpu.flags.zf)
    {
        goto L_0x0050c29f;
    }
    // 0050c29b  6689510a               -mov word ptr [ecx + 0xa], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x0050c29f:
    // 0050c29f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c2a1  7404                   -je 0x50c2a7
    if (cpu.flags.zf)
    {
        goto L_0x0050c2a7;
    }
    // 0050c2a3  6689510c               -mov word ptr [ecx + 0xc], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x0050c2a7:
    // 0050c2a7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c2a9  750a                   -jne 0x50c2b5
    if (!cpu.flags.zf)
    {
        goto L_0x0050c2b5;
    }
    // 0050c2ab  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050c2ae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c2af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c2b0:
    // 0050c2b0  668913                 -mov word ptr [ebx], dx
    *app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 0050c2b3  ebc2                   -jmp 0x50c277
    goto L_0x0050c277;
L_0x0050c2b5:
    // 0050c2b5  6689510e               -mov word ptr [ecx + 0xe], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0050c2b9  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050c2bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c2bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50c2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c2c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c2c1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c2c4  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c2c7  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050c2ca  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0050c2cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0050c2d0  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 0050c2d2  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050c2d5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c2d7  755a                   -jne 0x50c333
    if (!cpu.flags.zf)
    {
        goto L_0x0050c333;
    }
L_0x0050c2d9:
    // 0050c2d9  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c2db  7409                   -je 0x50c2e6
    if (cpu.flags.zf)
    {
        goto L_0x0050c2e6;
    }
    // 0050c2dd  886304                 -mov byte ptr [ebx + 4], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050c2e0  887305                 -mov byte ptr [ebx + 5], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
    // 0050c2e3  885303                 -mov byte ptr [ebx + 3], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x0050c2e6:
    // 0050c2e6  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c2e8  7409                   -je 0x50c2f3
    if (cpu.flags.zf)
    {
        goto L_0x0050c2f3;
    }
    // 0050c2ea  886307                 -mov byte ptr [ebx + 7], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 0050c2ed  887308                 -mov byte ptr [ebx + 8], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
    // 0050c2f0  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x0050c2f3:
    // 0050c2f3  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c2f5  7409                   -je 0x50c300
    if (cpu.flags.zf)
    {
        goto L_0x0050c300;
    }
    // 0050c2f7  88630a                 -mov byte ptr [ebx + 0xa], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 0050c2fa  88730b                 -mov byte ptr [ebx + 0xb], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
    // 0050c2fd  885309                 -mov byte ptr [ebx + 9], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
L_0x0050c300:
    // 0050c300  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c302  7409                   -je 0x50c30d
    if (cpu.flags.zf)
    {
        goto L_0x0050c30d;
    }
    // 0050c304  88630d                 -mov byte ptr [ebx + 0xd], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 0050c307  88730e                 -mov byte ptr [ebx + 0xe], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
    // 0050c30a  88530c                 -mov byte ptr [ebx + 0xc], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x0050c30d:
    // 0050c30d  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c30f  7409                   -je 0x50c31a
    if (cpu.flags.zf)
    {
        goto L_0x0050c31a;
    }
    // 0050c311  886310                 -mov byte ptr [ebx + 0x10], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 0050c314  887311                 -mov byte ptr [ebx + 0x11], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
    // 0050c317  88530f                 -mov byte ptr [ebx + 0xf], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
L_0x0050c31a:
    // 0050c31a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c31c  7409                   -je 0x50c327
    if (cpu.flags.zf)
    {
        goto L_0x0050c327;
    }
    // 0050c31e  886313                 -mov byte ptr [ebx + 0x13], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 0050c321  887314                 -mov byte ptr [ebx + 0x14], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 0050c324  885312                 -mov byte ptr [ebx + 0x12], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
L_0x0050c327:
    // 0050c327  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c329  7512                   -jne 0x50c33d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c33d;
    }
    // 0050c32b  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050c32e  83c404                 +add esp, 4
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
    // 0050c331  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c332  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c333:
    // 0050c333  884b01                 -mov byte ptr [ebx + 1], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0050c336  887302                 -mov byte ptr [ebx + 2], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 0050c339  8813                   -mov byte ptr [ebx], dl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 0050c33b  eb9c                   -jmp 0x50c2d9
    goto L_0x0050c2d9;
L_0x0050c33d:
    // 0050c33d  886316                 -mov byte ptr [ebx + 0x16], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 0050c340  887317                 -mov byte ptr [ebx + 0x17], dh
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 0050c343  885315                 -mov byte ptr [ebx + 0x15], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 0050c346  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050c349  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c34c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c34d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50c350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c350  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c351  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050c353  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c355  7533                   -jne 0x50c38a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c38a;
    }
L_0x0050c357:
    // 0050c357  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c359  7403                   -je 0x50c35e
    if (cpu.flags.zf)
    {
        goto L_0x0050c35e;
    }
    // 0050c35b  895104                 -mov dword ptr [ecx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0050c35e:
    // 0050c35e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c360  7403                   -je 0x50c365
    if (cpu.flags.zf)
    {
        goto L_0x0050c365;
    }
    // 0050c362  895108                 -mov dword ptr [ecx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0050c365:
    // 0050c365  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c367  7403                   -je 0x50c36c
    if (cpu.flags.zf)
    {
        goto L_0x0050c36c;
    }
    // 0050c369  89510c                 -mov dword ptr [ecx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050c36c:
    // 0050c36c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c36e  7403                   -je 0x50c373
    if (cpu.flags.zf)
    {
        goto L_0x0050c373;
    }
    // 0050c370  895110                 -mov dword ptr [ecx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0050c373:
    // 0050c373  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c375  7403                   -je 0x50c37a
    if (cpu.flags.zf)
    {
        goto L_0x0050c37a;
    }
    // 0050c377  895114                 -mov dword ptr [ecx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0050c37a:
    // 0050c37a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c37c  7403                   -je 0x50c381
    if (cpu.flags.zf)
    {
        goto L_0x0050c381;
    }
    // 0050c37e  895118                 -mov dword ptr [ecx + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0050c381:
    // 0050c381  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c383  7509                   -jne 0x50c38e
    if (!cpu.flags.zf)
    {
        goto L_0x0050c38e;
    }
    // 0050c385  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0050c388  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c38a:
    // 0050c38a  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050c38c  ebc9                   -jmp 0x50c357
    goto L_0x0050c357;
L_0x0050c38e:
    // 0050c38e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0050c391  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0050c394  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c395  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c3a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c3a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c3a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c3a4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c3a5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050c3a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c3a8  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050c3ad  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c3af  7354                   -jae 0x50c405
    if (!cpu.flags.cf)
    {
        goto L_0x0050c405;
    }
L_0x0050c3b1:
    // 0050c3b1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c3b3  7c08                   -jl 0x50c3bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c3bd;
    }
    // 0050c3b5  81fa00010000           +cmp edx, 0x100
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
    // 0050c3bb  7c38                   -jl 0x50c3f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c3f5;
    }
L_0x0050c3bd:
    // 0050c3bd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3be  bb7cfa5400             -mov ebx, 0x54fa7c
    cpu.ebx = 5569148 /*0x54fa7c*/;
    // 0050c3c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c3c5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3c6  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050c3cb  be8cfa5400             -mov esi, 0x54fa8c
    cpu.esi = 5569164 /*0x54fa8c*/;
    // 0050c3d0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c3d1  bfb8000000             -mov edi, 0xb8
    cpu.edi = 184 /*0xb8*/;
    // 0050c3d6  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050c3dc  6854fb5400             -push 0x54fb54
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569364 /*0x54fb54*/;
    cpu.esp -= 4;
    // 0050c3e1  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050c3e7  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050c3ed  e81e4cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c3f2  83c410                 +add esp, 0x10
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
L_0x0050c3f5:
    // 0050c3f5  8b149514a8a000         -mov edx, dword ptr [edx*4 + 0xa0a814]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.edx * 4);
L_0x0050c3fc:
    // 0050c3fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c3fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c3ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c400  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c401  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c402  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c403  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c404  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c405:
    // 0050c405  0f877e000000           -ja 0x50c489
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050c489;
    }
    // 0050c40b  f7c20000ffff           +test edx, 0xffff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4294901760 /*0xffff0000*/));
    // 0050c411  7436                   -je 0x50c449
    if (cpu.flags.zf)
    {
        goto L_0x0050c449;
    }
    // 0050c413  bf7cfa5400             -mov edi, 0x54fa7c
    cpu.edi = 5569148 /*0x54fa7c*/;
    // 0050c418  bd8cfa5400             -mov ebp, 0x54fa8c
    cpu.ebp = 5569164 /*0x54fa8c*/;
    // 0050c41d  b990000000             -mov ecx, 0x90
    cpu.ecx = 144 /*0x90*/;
    // 0050c422  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c423  893d90215500           -mov dword ptr [0x552190], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050c429  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050c42f  890d98215500           -mov dword ptr [0x552198], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050c435  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c436  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c43b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c43c  6894fa5400             -push 0x54fa94
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569172 /*0x54fa94*/;
    cpu.esp -= 4;
    // 0050c441  e8ca4befff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c446  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0050c449:
    // 0050c449  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 0050c44c  0f849d000000           -je 0x50c4ef
    if (cpu.flags.zf)
    {
        goto L_0x0050c4ef;
    }
    // 0050c452  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050c457:
    // 0050c457  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c459  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c45b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c45d  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 0050c460  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0050c463  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c466  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c469  c1e618                 -shl esi, 0x18
    cpu.esi <<= 24 /*0x18*/ % 32;
    // 0050c46c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c46e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c471  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 0050c474  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 0050c477  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c479  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050c47c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c47e  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c480  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c482  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c483  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c484  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c485  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c486  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c487  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c489:
    // 0050c489  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c48b  734b                   -jae 0x50c4d8
    if (!cpu.flags.cf)
    {
        goto L_0x0050c4d8;
    }
    // 0050c48d  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c48f  0f851cffffff           -jne 0x50c3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0050c3b1;
    }
    // 0050c495  f7c20000ffff           +test edx, 0xffff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4294901760 /*0xffff0000*/));
    // 0050c49b  7559                   -jne 0x50c4f6
    if (!cpu.flags.zf)
    {
        goto L_0x0050c4f6;
    }
L_0x0050c49d:
    // 0050c49d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c49f  0f848c000000           -je 0x50c531
    if (cpu.flags.zf)
    {
        goto L_0x0050c531;
    }
    // 0050c4a5  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050c4aa:
    // 0050c4aa  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c4ac  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c4ae  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0050c4b1  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 0050c4b4  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0050c4b7  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c4ba  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c4bd  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050c4c0  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 0050c4c3  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0050c4c6  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c4c8  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050c4cb  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c4cd  09c2                   +or edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c4cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c4d1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c4d8:
    // 0050c4d8  0f861effffff           -jbe 0x50c3fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c3fc;
    }
    // 0050c4de  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c4e0  0f85cbfeffff           -jne 0x50c3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0050c3b1;
    }
    // 0050c4e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c4e8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4eb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ec  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ed  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c4ef:
    // 0050c4ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c4f1  e961ffffff             -jmp 0x50c457
    goto L_0x0050c457;
L_0x0050c4f6:
    // 0050c4f6  b97cfa5400             -mov ecx, 0x54fa7c
    cpu.ecx = 5569148 /*0x54fa7c*/;
    // 0050c4fb  bb8cfa5400             -mov ebx, 0x54fa8c
    cpu.ebx = 5569164 /*0x54fa8c*/;
    // 0050c500  bea4000000             -mov esi, 0xa4
    cpu.esi = 164 /*0xa4*/;
    // 0050c505  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c506  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050c50c  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050c512  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050c518  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c519  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c51e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c51f  68f4fa5400             -push 0x54faf4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569268 /*0x54faf4*/;
    cpu.esp -= 4;
    // 0050c524  e8e74aefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c529  83c410                 +add esp, 0x10
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
    // 0050c52c  e96cffffff             -jmp 0x50c49d
    goto L_0x0050c49d;
L_0x0050c531:
    // 0050c531  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c533  e972ffffff             -jmp 0x50c4aa
    goto L_0x0050c4aa;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c540  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c541  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c542  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c543  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c545  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c547  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0050c54c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050c54e  e8ed40fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0050c553  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050c555  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0050c557  7504                   -jne 0x50c55d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c55d;
    }
    // 0050c559  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c55d:
    // 0050c55d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050c55f  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050c561  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050c564  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0050c566  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c56b  8a8040215500           -mov al, byte ptr [eax + 0x552140]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5579072) /* 0x552140 */);
    // 0050c571  8a2432                 -mov ah, byte ptr [edx + esi]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1);
    // 0050c574  08c4                   -or ah, al
    cpu.ah |= x86::reg8(x86::sreg8(cpu.al));
    // 0050c576  41                     -inc ecx
    (cpu.ecx)++;
    // 0050c577  882432                 -mov byte ptr [edx + esi], ah
    *app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) = cpu.ah;
    // 0050c57a  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050c57c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0050c57e  75dd                   -jne 0x50c55d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c55d;
    }
    // 0050c580  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c581  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c582  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c584  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c585  ff0d9a875600           +dec dword ptr [0x56879a]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c58b  753f                   -jne 0x50c5cc
    if (!cpu.flags.zf)
    {
        goto L_0x0050c5cc;
    }
    // 0050c58d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c58f  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0050c591  7421                   -je 0x50c5b4
    if (cpu.flags.zf)
    {
        goto L_0x0050c5b4;
    }
    // 0050c593  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 0050c596  8a9294865600           -mov dl, byte ptr [edx + 0x568694]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670548) /* 0x568694 */);
L_0x0050c59c:
    // 0050c59c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c59d  7c2d                   -jl 0x50c5cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c5cc;
    }
    // 0050c59f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c5a0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c5a1  ff14959e875600         -call dword ptr [edx*4 + 0x56879e]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5670814) /* 0x56879e */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c5a8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c5ac  ff059a875600           -inc dword ptr [0x56879a]
    (*app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */))++;
    // 0050c5b2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c5b4:
    // 0050c5b4  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0050c5b7  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c5bd  7c05                   -jl 0x50c5c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c5c4;
    }
    // 0050c5bf  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x0050c5c4:
    // 0050c5c4  8a9214875600           -mov dl, byte ptr [edx + 0x568714]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670676) /* 0x568714 */);
    // 0050c5ca  ebd0                   -jmp 0x50c59c
    goto L_0x0050c59c;
L_0x0050c5cc:
    // 0050c5cc  ff059a875600           -inc dword ptr [0x56879a]
    (*app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */))++;
    // 0050c5d2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c5d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c5d4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c5d5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c5d6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c5d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c5d9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050c5db  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050c5dd  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0050c5e2  ba9e875600             -mov edx, 0x56879e
    cpu.edx = 5670814 /*0x56879e*/;
L_0x0050c5e7:
    // 0050c5e7  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c5e9  7412                   -je 0x50c5fd
    if (cpu.flags.zf)
    {
        goto L_0x0050c5fd;
    }
    // 0050c5eb  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0050c5ef  740a                   -je 0x50c5fb
    if (cpu.flags.zf)
    {
        goto L_0x0050c5fb;
    }
    // 0050c5f1  83c204                 +add edx, 4
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
    // 0050c5f4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c5f5  75f0                   -jne 0x50c5e7
    if (!cpu.flags.zf)
    {
        goto L_0x0050c5e7;
    }
    // 0050c5f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5f9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c5fb:
    // 0050c5fb  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0050c5fd:
    // 0050c5fd  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 0050c602  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050c604:
    // 0050c604  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c606  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0050c608  740f                   -je 0x50c619
    if (cpu.flags.zf)
    {
        goto L_0x0050c619;
    }
    // 0050c60a  83fa7f                 +cmp edx, 0x7f
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
    // 0050c60d  7f06                   -jg 0x50c615
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050c615;
    }
    // 0050c60f  888294865600           -mov byte ptr [edx + 0x568694], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670548) /* 0x568694 */) = cpu.al;
L_0x0050c615:
    // 0050c615  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c616  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c617  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c619:
    // 0050c619  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0050c61c  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c622  7ff1                   -jg 0x50c615
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050c615;
    }
    // 0050c624  888214875600           -mov byte ptr [edx + 0x568714], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670676) /* 0x568714 */) = cpu.al;
    // 0050c62a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0050c62e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c62f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c630  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c631  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c633  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050c635  ebcd                   -jmp 0x50c604
    goto L_0x0050c604;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c640  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c641  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c643  ff12                   -call dword ptr [edx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c645  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50c648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c648  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c649  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c64b  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c64e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c64f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c650  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c651  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c652  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c653  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050c654  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050c657  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c659  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c65c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050c65e  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050c662  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0050c665  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050c667  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0050c66a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050c66c  886610                 -mov byte ptr [esi + 0x10], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x0050c66f:
    // 0050c66f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050c672  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0050c675  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c678  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0050c67a  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050c680  0f8462020000           -je 0x50c8e8
    if (cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c686  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050c688  fec0                   -inc al
    (cpu.al)++;
    // 0050c68a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c68f  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050c696  740e                   -je 0x50c6a6
    if (cpu.flags.zf)
    {
        goto L_0x0050c6a6;
    }
    // 0050c698  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c69a  e869030000             -call 0x50ca08
    cpu.esp -= 4;
    sub_50ca08(app, cpu);
    if (cpu.terminate) return;
    // 0050c69f  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050c6a1  e90c020000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c6a6:
    // 0050c6a6  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6a9  7425                   -je 0x50c6d0
    if (cpu.flags.zf)
    {
        goto L_0x0050c6d0;
    }
    // 0050c6ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c6ad  e88effffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050c6b2  39d8                   +cmp eax, ebx
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
    // 0050c6b4  0f84f7010000           -je 0x50c8b1
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b1;
    }
    // 0050c6ba  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c6be  0f8524020000           -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c6c4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c6c6  e87dffffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050c6cb  e918020000             -jmp 0x50c8e8
    goto L_0x0050c8e8;
L_0x0050c6d0:
    // 0050c6d0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050c6d3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c6d5  e82a020000             -call 0x50c904
    cpu.esp -= 4;
    sub_50c904(app, cpu);
    if (cpu.terminate) return;
    // 0050c6da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c6dc  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050c6df  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050c6e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050c6e3  7404                   -je 0x50c6e9
    if (cpu.flags.zf)
    {
        goto L_0x0050c6e9;
    }
    // 0050c6e5  40                     -inc eax
    (cpu.eax)++;
    // 0050c6e6  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0050c6e9:
    // 0050c6e9  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6ec  726e                   -jb 0x50c75c
    if (cpu.flags.cf)
    {
        goto L_0x0050c75c;
    }
    // 0050c6ee  0f86d0000000           -jbe 0x50c7c4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7c4;
    }
    // 0050c6f4  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6f7  723c                   -jb 0x50c735
    if (cpu.flags.cf)
    {
        goto L_0x0050c735;
    }
    // 0050c6f9  0f86f6000000           -jbe 0x50c7f5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7f5;
    }
    // 0050c6ff  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c702  7223                   -jb 0x50c727
    if (cpu.flags.cf)
    {
        goto L_0x0050c727;
    }
    // 0050c704  0f863e010000           -jbe 0x50c848
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c848;
    }
    // 0050c70a  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c70d  0f829f010000           -jb 0x50c8b2
    if (cpu.flags.cf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c713  0f86f3000000           -jbe 0x50c80c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c80c;
    }
    // 0050c719  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c71c  0f84fe000000           -je 0x50c820
    if (cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c722  e98b010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c727:
    // 0050c727  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c72a  0f84f0000000           -je 0x50c820
    if (cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c730  e97d010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c735:
    // 0050c735  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c738  7214                   -jb 0x50c74e
    if (cpu.flags.cf)
    {
        goto L_0x0050c74e;
    }
    // 0050c73a  0f869e000000           -jbe 0x50c7de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7de;
    }
    // 0050c740  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c743  0f843f010000           -je 0x50c888
    if (cpu.flags.zf)
    {
        goto L_0x0050c888;
    }
    // 0050c749  e964010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c74e:
    // 0050c74e  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c751  0f86e0000000           -jbe 0x50c837
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c757  e956010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c75c:
    // 0050c75c  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c75f  723c                   -jb 0x50c79d
    if (cpu.flags.cf)
    {
        goto L_0x0050c79d;
    }
    // 0050c761  0f86d0000000           -jbe 0x50c837
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c767  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c76a  7223                   -jb 0x50c78f
    if (cpu.flags.cf)
    {
        goto L_0x0050c78f;
    }
    // 0050c76c  0f86ae000000           -jbe 0x50c820
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c772  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c775  0f8237010000           -jb 0x50c8b2
    if (cpu.flags.cf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c77b  0f86d4000000           -jbe 0x50c855
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c855;
    }
    // 0050c781  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c784  0f84de000000           -je 0x50c868
    if (cpu.flags.zf)
    {
        goto L_0x0050c868;
    }
    // 0050c78a  e923010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c78f:
    // 0050c78f  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c792  0f84ac000000           -je 0x50c844
    if (cpu.flags.zf)
    {
        goto L_0x0050c844;
    }
    // 0050c798  e915010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c79d:
    // 0050c79d  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7a0  7214                   -jb 0x50c7b6
    if (cpu.flags.cf)
    {
        goto L_0x0050c7b6;
    }
    // 0050c7a2  0f86bc000000           -jbe 0x50c864
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c864;
    }
    // 0050c7a8  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7ab  0f8486000000           -je 0x50c837
    if (cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c7b1  e9fc000000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c7b6:
    // 0050c7b6  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7b9  0f84d8000000           -je 0x50c897
    if (cpu.flags.zf)
    {
        goto L_0x0050c897;
    }
    // 0050c7bf  e9ee000000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c7c4:
    // 0050c7c4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7c9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0050c7ce  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c7d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c7d4  e817090000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c7d9  e995000000             -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c7de:
    // 0050c7de  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7e3  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c7e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c7e9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050c7eb  e800090000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c7f0  e97e000000             -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c7f5:
    // 0050c7f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7fa  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0050c7ff  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c803  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c805  e8e6080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c80a  eb67                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c80c:
    // 0050c80c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0050c811  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c815  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c817  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0050c819  e8d2080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c81e  eb53                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c820:
    // 0050c820  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c825  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0050c82a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c82e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c830  e8bb080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c835  eb3c                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c837:
    // 0050c837  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c83b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c83d  e8d6050000             -call 0x50ce18
    cpu.esp -= 4;
    sub_50ce18(app, cpu);
    if (cpu.terminate) return;
    // 0050c842  eb2f                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c844:
    // 0050c844  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x0050c848:
    // 0050c848  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c84c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c84e  e8dd020000             -call 0x50cb30
    cpu.esp -= 4;
    sub_50cb30(app, cpu);
    if (cpu.terminate) return;
    // 0050c853  eb1e                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c855:
    // 0050c855  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050c857  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c85b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c85d  e8ca040000             -call 0x50cd2c
    cpu.esp -= 4;
    sub_50cd2c(app, cpu);
    if (cpu.terminate) return;
    // 0050c862  eb0f                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c864:
    // 0050c864  804e1020               -or byte ptr [esi + 0x10], 0x20
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0050c868:
    // 0050c868  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c86c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c86e  e8d5010000             -call 0x50ca48
    cpu.esp -= 4;
    sub_50ca48(app, cpu);
    if (cpu.terminate) return;
L_0x0050c873:
    // 0050c873  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050c875  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050c877  0f8e6b000000           -jle 0x50c8e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050c8e8;
    }
    // 0050c87d  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c87f  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050c883  742d                   -je 0x50c8b2
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c885  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050c886  eb2a                   -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c888:
    // 0050c888  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c88c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050c88e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c890  e8f3030000             -call 0x50cc88
    cpu.esp -= 4;
    sub_50cc88(app, cpu);
    if (cpu.terminate) return;
    // 0050c895  eb1b                   -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c897:
    // 0050c897  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c899  e8a2fdffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050c89e  39d8                   +cmp eax, ebx
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
    // 0050c8a0  740f                   -je 0x50c8b1
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b1;
    }
    // 0050c8a2  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8a6  7540                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8a8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c8aa  e899fdffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050c8af  eb37                   -jmp 0x50c8e8
    goto L_0x0050c8e8;
L_0x0050c8b1:
    // 0050c8b1  47                     -inc edi
    (cpu.edi)++;
L_0x0050c8b2:
    // 0050c8b2  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8b6  0f84b3fdffff           -je 0x50c66f
    if (cpu.flags.zf)
    {
        goto L_0x0050c66f;
    }
    // 0050c8bc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050c8bf  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c8c2  7524                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8c4  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c8c7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c8c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c8cb  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050c8ce  e831000000             -call 0x50c904
    cpu.esp -= 4;
    sub_50c904(app, cpu);
    if (cpu.terminate) return;
    // 0050c8d3  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050c8d6  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c8d9  750d                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8db  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c8df  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050c8e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c8e3  e8a0030000             -call 0x50cc88
    cpu.esp -= 4;
    sub_50cc88(app, cpu);
    if (cpu.terminate) return;
L_0x0050c8e8:
    // 0050c8e8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050c8ea  750d                   -jne 0x50c8f9
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8f9;
    }
    // 0050c8ec  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8f0  7407                   -je 0x50c8f9
    if (cpu.flags.zf)
    {
        goto L_0x0050c8f9;
    }
    // 0050c8f2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050c8f7  eb02                   -jmp 0x50c8fb
    goto L_0x0050c8fb;
L_0x0050c8f9:
    // 0050c8f9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0050c8fb:
    // 0050c8fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050c8fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c8ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c900  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c901  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50c904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c904  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c905  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c906  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c907  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c908  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050c90a  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050c90d  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050c910  885710                 -mov byte ptr [edi + 0x10], dl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0050c913  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0050c915  c7470cffffffff         -mov dword ptr [edi + 0xc], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 0050c91c  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0050c91f  887710                 -mov byte ptr [edi + 0x10], dh
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 0050c922  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c925  750a                   -jne 0x50c931
    if (!cpu.flags.zf)
    {
        goto L_0x0050c931;
    }
    // 0050c927  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c92a  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050c92d  40                     -inc eax
    (cpu.eax)++;
    // 0050c92e  887f10                 -mov byte ptr [edi + 0x10], bh
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0050c931:
    // 0050c931  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c933  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050c935  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 0050c937  fec2                   -inc dl
    (cpu.dl)++;
    // 0050c939  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c93f  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050c946  7425                   -je 0x50c96d
    if (cpu.flags.zf)
    {
        goto L_0x0050c96d;
    }
    // 0050c948  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0050c94a:
    // 0050c94a  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0050c94d  83eb30                 -sub ebx, 0x30
    (cpu.ebx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050c950  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c952  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c954  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c957  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0050c959  fec1                   -inc cl
    (cpu.cl)++;
    // 0050c95b  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0050c95e  8aaef04e5600           -mov ch, byte ptr [esi + 0x564ef0]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5656304) /* 0x564ef0 */);
    // 0050c964  40                     -inc eax
    (cpu.eax)++;
    // 0050c965  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0050c968  75e0                   -jne 0x50c94a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c94a;
    }
    // 0050c96a  89570c                 -mov dword ptr [edi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050c96d:
    // 0050c96d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050c96f  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c972  80fb4e                 +cmp bl, 0x4e
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c975  750d                   -jne 0x50c984
    if (!cpu.flags.zf)
    {
        goto L_0x0050c984;
    }
    // 0050c977  8a6f10                 -mov ch, byte ptr [edi + 0x10]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c97a  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0050c97d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c97f  886f10                 -mov byte ptr [edi + 0x10], ch
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0050c982  eb10                   -jmp 0x50c994
    goto L_0x0050c994;
L_0x0050c984:
    // 0050c984  80fb46                 +cmp bl, 0x46
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c987  750b                   -jne 0x50c994
    if (!cpu.flags.zf)
    {
        goto L_0x0050c994;
    }
    // 0050c989  8a4f10                 -mov cl, byte ptr [edi + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c98c  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0050c98f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c991  884f10                 -mov byte ptr [edi + 0x10], cl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.cl;
L_0x0050c994:
    // 0050c994  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050c996  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c999  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c99c  7213                   -jb 0x50c9b1
    if (cpu.flags.cf)
    {
        goto L_0x0050c9b1;
    }
    // 0050c99e  7622                   -jbe 0x50c9c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9c2;
    }
    // 0050c9a0  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9a3  725e                   -jb 0x50ca03
    if (cpu.flags.cf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9a5  7625                   -jbe 0x50c9cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9cc;
    }
    // 0050c9a7  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9aa  7420                   -je 0x50c9cc
    if (cpu.flags.zf)
    {
        goto L_0x0050c9cc;
    }
    // 0050c9ac  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ad  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9af  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9b1:
    // 0050c9b1  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9b4  724d                   -jb 0x50ca03
    if (cpu.flags.cf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9b6  7633                   -jbe 0x50c9eb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9eb;
    }
    // 0050c9b8  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9bb  741e                   -je 0x50c9db
    if (cpu.flags.zf)
    {
        goto L_0x0050c9db;
    }
    // 0050c9bd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9be  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9bf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9c0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9c2:
    // 0050c9c2  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9c5  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0050c9c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c9ca  eb34                   -jmp 0x50ca00
    goto L_0x0050ca00;
L_0x0050c9cc:
    // 0050c9cc  8a5710                 -mov dl, byte ptr [edi + 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9cf  80ca20                 -or dl, 0x20
    cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0050c9d2  40                     -inc eax
    (cpu.eax)++;
    // 0050c9d3  885710                 -mov byte ptr [edi + 0x10], dl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0050c9d6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9db:
    // 0050c9db  8a4f10                 -mov cl, byte ptr [edi + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9de  80c940                 -or cl, 0x40
    cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0050c9e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c9e3  884f10                 -mov byte ptr [edi + 0x10], cl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 0050c9e6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9eb:
    // 0050c9eb  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9ef  7512                   -jne 0x50ca03
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9f1  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c9f5  750c                   -jne 0x50ca03
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9f7  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9fa  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0050c9fd  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0050ca00:
    // 0050ca00  887710                 -mov byte ptr [edi + 0x10], dh
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x0050ca03:
    // 0050ca03  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca04  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca05  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca06  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50ca08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ca08  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ca09  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ca0a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ca0b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ca0c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca0f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ca11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0050ca13:
    // 0050ca13  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ca15  e826fcffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050ca1a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050ca1d  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050ca20  fec1                   -inc cl
    (cpu.cl)++;
    // 0050ca22  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0050ca25  f686f04e560002         +test byte ptr [esi + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050ca2c  7403                   -je 0x50ca31
    if (cpu.flags.zf)
    {
        goto L_0x0050ca31;
    }
    // 0050ca2e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050ca2f  ebe2                   -jmp 0x50ca13
    goto L_0x0050ca13;
L_0x0050ca31:
    // 0050ca31  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050ca35  7505                   -jne 0x50ca3c
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca3c;
    }
    // 0050ca37  e80cfcffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050ca3c:
    // 0050ca3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050ca3e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca41  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca42  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca43  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca44  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50ca48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ca48  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ca49  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ca4a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ca4b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ca4c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050ca4d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ca4e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050ca51  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ca53  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050ca57  7437                   -je 0x50ca90
    if (cpu.flags.zf)
    {
        goto L_0x0050ca90;
    }
    // 0050ca59  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050ca5c  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050ca5f  740c                   -je 0x50ca6d
    if (cpu.flags.zf)
    {
        goto L_0x0050ca6d;
    }
    // 0050ca61  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca63  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ca66  893a                   -mov dword ptr [edx], edi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050ca68  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050ca6b  eb23                   -jmp 0x50ca90
    goto L_0x0050ca90;
L_0x0050ca6d:
    // 0050ca6d  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050ca70  7410                   -je 0x50ca82
    if (cpu.flags.zf)
    {
        goto L_0x0050ca82;
    }
    // 0050ca72  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca74  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ca77  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050ca79  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050ca7b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050ca7d  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ca80  eb0e                   -jmp 0x50ca90
    goto L_0x0050ca90;
L_0x0050ca82:
    // 0050ca82  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca84  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca87  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050ca89  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0050ca8b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050ca8d  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0050ca90:
    // 0050ca90  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050ca93  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ca95  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ca98  7505                   -jne 0x50ca9f
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca9f;
    }
    // 0050ca9a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0050ca9f:
    // 0050ca9f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050caa1  0f8e7c000000           -jle 0x50cb23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050cb23;
    }
    // 0050caa7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050caa9  e892fbffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050caae  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cab1  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0050cab4  0f8569000000           -jne 0x50cb23
    if (!cpu.flags.zf)
    {
        goto L_0x0050cb23;
    }
    // 0050caba  45                     -inc ebp
    (cpu.ebp)++;
    // 0050cabb  4f                     -dec edi
    (cpu.edi)--;
    // 0050cabc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0050cabf  74de                   -je 0x50ca9f
    if (cpu.flags.zf)
    {
        goto L_0x0050ca9f;
    }
    // 0050cac1  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0050cac4  7453                   -je 0x50cb19
    if (cpu.flags.zf)
    {
        goto L_0x0050cb19;
    }
    // 0050cac6  8b1500b2a000           -mov edx, dword ptr [0xa0b200]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
    // 0050cacc  88442404               -mov byte ptr [esp + 4], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0050cad0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cad2  741f                   -je 0x50caf3
    if (cpu.flags.zf)
    {
        goto L_0x0050caf3;
    }
    // 0050cad4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cad9  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0050cadf  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050cae1  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cae6  740b                   -je 0x50caf3
    if (cpu.flags.zf)
    {
        goto L_0x0050caf3;
    }
    // 0050cae8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050caea  e851fbffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050caef  88442405               -mov byte ptr [esp + 5], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0050caf3:
    // 0050caf3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0050caf8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050cafc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050cafe  e8fd700100             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 0050cb03  83f8ff                 +cmp eax, -1
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
    // 0050cb06  7504                   -jne 0x50cb0c
    if (!cpu.flags.zf)
    {
        goto L_0x0050cb0c;
    }
    // 0050cb08  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050cb0a  eb19                   -jmp 0x50cb25
    goto L_0x0050cb25;
L_0x0050cb0c:
    // 0050cb0c  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cb0f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050cb12  66268946fe             -mov word ptr es:[esi - 2], ax
    *app->getMemory<x86::reg16>(cpu.ees + cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0050cb17  eb86                   -jmp 0x50ca9f
    goto L_0x0050ca9f;
L_0x0050cb19:
    // 0050cb19  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050cb1a  268846ff               -mov byte ptr es:[esi - 1], al
    *app->getMemory<x86::reg8>(cpu.ees + cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0050cb1e  e97cffffff             -jmp 0x50ca9f
    goto L_0x0050ca9f;
L_0x0050cb23:
    // 0050cb23  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0050cb25:
    // 0050cb25  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050cb28  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb29  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50cb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cb30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050cb31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cb32  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cb33  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cb34  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cb35  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050cb36  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050cb39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cb3b  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 0050cb3f  7407                   -je 0x50cb48
    if (cpu.flags.zf)
    {
        goto L_0x0050cb48;
    }
    // 0050cb41  c644240802             -mov byte ptr [esp + 8], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 0050cb46  eb09                   -jmp 0x50cb51
    goto L_0x0050cb51;
L_0x0050cb48:
    // 0050cb48  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cb4c  c644240801             -mov byte ptr [esp + 8], 1
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0050cb51:
    // 0050cb51  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cb54  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0050cb57  7434                   -je 0x50cb8d
    if (cpu.flags.zf)
    {
        goto L_0x0050cb8d;
    }
    // 0050cb59  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050cb5c  740c                   -je 0x50cb6a
    if (cpu.flags.zf)
    {
        goto L_0x0050cb6a;
    }
    // 0050cb5e  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb60  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cb63  893a                   -mov dword ptr [edx], edi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050cb65  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050cb68  eb23                   -jmp 0x50cb8d
    goto L_0x0050cb8d;
L_0x0050cb6a:
    // 0050cb6a  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050cb6d  7410                   -je 0x50cb7f
    if (cpu.flags.zf)
    {
        goto L_0x0050cb7f;
    }
    // 0050cb6f  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb71  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cb74  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cb76  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050cb78  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cb7a  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050cb7d  eb0e                   -jmp 0x50cb8d
    goto L_0x0050cb8d;
L_0x0050cb7f:
    // 0050cb7f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb81  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050cb84  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cb86  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0050cb88  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cb8a  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0050cb8d:
    // 0050cb8d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0050cb8f:
    // 0050cb8f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cb91  e8aafaffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cb96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cb98  fec0                   -inc al
    (cpu.al)++;
    // 0050cb9a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cb9f  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050cba6  7403                   -je 0x50cbab
    if (cpu.flags.zf)
    {
        goto L_0x0050cbab;
    }
    // 0050cba8  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050cba9  ebe4                   -jmp 0x50cb8f
    goto L_0x0050cb8f;
L_0x0050cbab:
    // 0050cbab  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050cbaf  7407                   -je 0x50cbb8
    if (cpu.flags.zf)
    {
        goto L_0x0050cbb8;
    }
    // 0050cbb1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050cbb3  e9a4000000             -jmp 0x50cc5c
    goto L_0x0050cc5c;
L_0x0050cbb8:
    // 0050cbb8  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050cbbb  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050cbbe  89510c                 -mov dword ptr [ecx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050cbc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cbc3  0f848a000000           -je 0x50cc53
    if (cpu.flags.zf)
    {
        goto L_0x0050cc53;
    }
L_0x0050cbc9:
    // 0050cbc9  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cbcc  47                     -inc edi
    (cpu.edi)++;
    // 0050cbcd  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050cbcf  7460                   -je 0x50cc31
    if (cpu.flags.zf)
    {
        goto L_0x0050cc31;
    }
    // 0050cbd1  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cbd6  7505                   -jne 0x50cbdd
    if (!cpu.flags.zf)
    {
        goto L_0x0050cbdd;
    }
    // 0050cbd8  26881e                 -mov byte ptr es:[esi], bl
    *app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 0050cbdb  eb4c                   -jmp 0x50cc29
    goto L_0x0050cc29;
L_0x0050cbdd:
    // 0050cbdd  8b2d00b2a000           -mov ebp, dword ptr [0xa0b200]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
    // 0050cbe3  885c2404               -mov byte ptr [esp + 4], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 0050cbe7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050cbe9  741e                   -je 0x50cc09
    if (cpu.flags.zf)
    {
        goto L_0x0050cc09;
    }
    // 0050cbeb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cbed  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cbef  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0050cbf5  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050cbf7  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cbfc  740b                   -je 0x50cc09
    if (cpu.flags.zf)
    {
        goto L_0x0050cc09;
    }
    // 0050cbfe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cc00  e83bfaffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cc05  88442405               -mov byte ptr [esp + 5], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0050cc09:
    // 0050cc09  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0050cc0e  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050cc12  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050cc14  e8e76f0100             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 0050cc19  83f8ff                 +cmp eax, -1
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
    // 0050cc1c  7504                   -jne 0x50cc22
    if (!cpu.flags.zf)
    {
        goto L_0x0050cc22;
    }
    // 0050cc1e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050cc20  eb59                   -jmp 0x50cc7b
    goto L_0x0050cc7b;
L_0x0050cc22:
    // 0050cc22  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050cc25  66268906               -mov word ptr es:[esi], ax
    *app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x0050cc29:
    // 0050cc29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cc2b  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050cc2f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050cc31:
    // 0050cc31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cc33  e800090000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cc38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cc3a  83f8ff                 +cmp eax, -1
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
    // 0050cc3d  741d                   -je 0x50cc5c
    if (cpu.flags.zf)
    {
        goto L_0x0050cc5c;
    }
    // 0050cc3f  fec0                   -inc al
    (cpu.al)++;
    // 0050cc41  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cc46  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050cc4d  0f8476ffffff           -je 0x50cbc9
    if (cpu.flags.zf)
    {
        goto L_0x0050cbc9;
    }
L_0x0050cc53:
    // 0050cc53  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050cc55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050cc57  e8ecf9ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050cc5c:
    // 0050cc5c  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050cc60  7417                   -je 0x50cc79
    if (cpu.flags.zf)
    {
        goto L_0x0050cc79;
    }
    // 0050cc62  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050cc64  7e13                   -jle 0x50cc79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050cc79;
    }
    // 0050cc66  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cc6b  7506                   -jne 0x50cc73
    if (!cpu.flags.zf)
    {
        goto L_0x0050cc73;
    }
    // 0050cc6d  26c60600               -mov byte ptr es:[esi], 0
    *app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 0050cc71  eb06                   -jmp 0x50cc79
    goto L_0x0050cc79;
L_0x0050cc73:
    // 0050cc73  6626c7060000           -mov word ptr es:[esi], 0
    *app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0050cc79:
    // 0050cc79  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0050cc7b:
    // 0050cc7b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050cc7e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc7f  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cc80  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc81  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc82  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc83  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50cc88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cc88  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cc89  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cc8a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cc8b  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cc8c  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050cc8f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0050cc92  744d                   -je 0x50cce1
    if (cpu.flags.zf)
    {
        goto L_0x0050cce1;
    }
    // 0050cc94  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0050cc97  740c                   -je 0x50cca5
    if (cpu.flags.zf)
    {
        goto L_0x0050cca5;
    }
    // 0050cc99  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050cc9b  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cc9e  893a                   -mov dword ptr [edx], edi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050cca0  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050cca3  eb25                   -jmp 0x50ccca
    goto L_0x0050ccca;
L_0x0050cca5:
    // 0050cca5  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0050cca8  7410                   -je 0x50ccba
    if (cpu.flags.zf)
    {
        goto L_0x0050ccba;
    }
    // 0050ccaa  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050ccac  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ccaf  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0050ccb1  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050ccb3  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0050ccb5  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ccb8  eb10                   -jmp 0x50ccca
    goto L_0x0050ccca;
L_0x0050ccba:
    // 0050ccba  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050ccbc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ccbf  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0050ccc1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050ccc3  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0050ccc5  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0050ccc7  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0050ccca:
    // 0050ccca  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050cccd  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0050ccd0  7409                   -je 0x50ccdb
    if (cpu.flags.zf)
    {
        goto L_0x0050ccdb;
    }
    // 0050ccd2  6626891a               -mov word ptr es:[edx], bx
    *app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 0050ccd6  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ccdb:
    // 0050ccdb  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0050ccde  26891a                 -mov dword ptr es:[edx], ebx
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x0050cce1:
    // 0050cce1  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cce2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50cce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cce8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050cce9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ccea  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cceb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cced  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ccef  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0050ccf4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050ccf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ccf8  e84339fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0050ccfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ccff  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050cd01  41                     -inc ecx
    (cpu.ecx)++;
    // 0050cd02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cd04  741f                   -je 0x50cd25
    if (cpu.flags.zf)
    {
        goto L_0x0050cd25;
    }
L_0x0050cd06:
    // 0050cd06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050cd08  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050cd0b  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050cd0e  8a80a0885600           -mov al, byte ptr [eax + 0x5688a0]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5671072) /* 0x5688a0 */);
    // 0050cd14  080432                 -or byte ptr [edx + esi], al
    *app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 0050cd17  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cd19  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050cd1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cd1d  7406                   -je 0x50cd25
    if (cpu.flags.zf)
    {
        goto L_0x0050cd25;
    }
    // 0050cd1f  41                     -inc ecx
    (cpu.ecx)++;
    // 0050cd20  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cd23  75e1                   -jne 0x50cd06
    if (!cpu.flags.zf)
    {
        goto L_0x0050cd06;
    }
L_0x0050cd25:
    // 0050cd25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cd27  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd28  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd29  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50cd2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cd2c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cd2d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cd2e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cd2f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cd30  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050cd31  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050cd34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cd36  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050cd38  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050cd3a  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cd3d  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0050cd40  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cd46  89542424               -mov dword ptr [esp + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050cd4a  7403                   -je 0x50cd4f
    if (cpu.flags.zf)
    {
        goto L_0x0050cd4f;
    }
    // 0050cd4c  40                     -inc eax
    (cpu.eax)++;
    // 0050cd4d  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0050cd4f:
    // 0050cd4f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050cd51  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050cd53  e890ffffff             -call 0x50cce8
    cpu.esp -= 4;
    sub_50cce8(app, cpu);
    if (cpu.terminate) return;
    // 0050cd58  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0050cd5a  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cd5d  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0050cd60  7434                   -je 0x50cd96
    if (cpu.flags.zf)
    {
        goto L_0x0050cd96;
    }
    // 0050cd62  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050cd65  740c                   -je 0x50cd73
    if (cpu.flags.zf)
    {
        goto L_0x0050cd73;
    }
    // 0050cd67  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd69  83c608                 +add esi, 8
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
    // 0050cd6c  8937                   -mov dword ptr [edi], esi
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0050cd6e  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 0050cd71  eb23                   -jmp 0x50cd96
    goto L_0x0050cd96;
L_0x0050cd73:
    // 0050cd73  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050cd76  7410                   -je 0x50cd88
    if (cpu.flags.zf)
    {
        goto L_0x0050cd88;
    }
    // 0050cd78  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd7a  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cd7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cd7f  891f                   -mov dword ptr [edi], ebx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0050cd81  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cd83  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0050cd86  eb0e                   -jmp 0x50cd96
    goto L_0x0050cd96;
L_0x0050cd88:
    // 0050cd88  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd8a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050cd8d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cd8f  8917                   -mov dword ptr [edi], edx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0050cd91  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cd93  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0050cd96:
    // 0050cd96  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050cd99  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050cd9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cd9d  7660                   -jbe 0x50cdff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050cdff;
    }
L_0x0050cd9f:
    // 0050cd9f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cda1  e89af8ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cda6  89442428               -mov dword ptr [esp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0050cdaa  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050cdae  754f                   -jne 0x50cdff
    if (!cpu.flags.zf)
    {
        goto L_0x0050cdff;
    }
    // 0050cdb0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050cdb2  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0050cdb5  0fb63c3c               -movzx edi, byte ptr [esp + edi]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + cpu.edi * 1));
    // 0050cdb9  897c2420               -mov dword ptr [esp + 0x20], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0050cdbd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050cdbf  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050cdc2  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050cdc6  0fb6bfa0885600         -movzx edi, byte ptr [edi + 0x5688a0]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5671072) /* 0x5688a0 */));
    // 0050cdcd  85ef                   +test edi, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.ebp));
    // 0050cdcf  0f9444242c             -sete byte ptr [esp + 0x2c]
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.flags.zf;
    // 0050cdd4  0fb67c242c             -movzx edi, byte ptr [esp + 0x2c]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */));
    // 0050cdd9  3b7c2424               +cmp edi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cddd  7409                   -je 0x50cde8
    if (cpu.flags.zf)
    {
        goto L_0x0050cde8;
    }
    // 0050cddf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050cde1  e862f8ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050cde6  eb17                   -jmp 0x50cdff
    goto L_0x0050cdff;
L_0x0050cde8:
    // 0050cde8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050cde9  8a6110                 -mov ah, byte ptr [ecx + 0x10]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cdec  4a                     -dec edx
    (cpu.edx)--;
    // 0050cded  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0050cdf0  7409                   -je 0x50cdfb
    if (cpu.flags.zf)
    {
        goto L_0x0050cdfb;
    }
    // 0050cdf2  46                     -inc esi
    (cpu.esi)++;
    // 0050cdf3  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050cdf7  268846ff               -mov byte ptr es:[esi - 1], al
    *app->getMemory<x86::reg8>(cpu.ees + cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x0050cdfb:
    // 0050cdfb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cdfd  77a0                   -ja 0x50cd9f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050cd9f;
    }
L_0x0050cdff:
    // 0050cdff  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050ce03  7408                   -je 0x50ce0d
    if (cpu.flags.zf)
    {
        goto L_0x0050ce0d;
    }
    // 0050ce05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ce07  7e04                   -jle 0x50ce0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ce0d;
    }
    // 0050ce09  26c60600               -mov byte ptr es:[esi], 0
    *app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0050ce0d:
    // 0050ce0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050ce0f  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050ce12  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce13  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050ce14  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce15  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce16  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50ce18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ce18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ce19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ce1a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ce1b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ce1c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050ce1d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ce1e  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0050ce21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ce23  89542458               -mov dword ptr [esp + 0x58], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0050ce27  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050ce29  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0050ce2b  897c2468               -mov dword ptr [esp + 0x68], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x0050ce2f:
    // 0050ce2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ce31  e80af8ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050ce36  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050ce38  fec2                   -inc dl
    (cpu.dl)++;
    // 0050ce3a  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 0050ce3d  8a95f04e5600           -mov dl, byte ptr [ebp + 0x564ef0]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5656304) /* 0x564ef0 */);
    // 0050ce43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ce45  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0050ce48  7406                   -je 0x50ce50
    if (cpu.flags.zf)
    {
        goto L_0x0050ce50;
    }
    // 0050ce4a  ff442468               +inc dword ptr [esp + 0x68]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050ce4e  ebdf                   -jmp 0x50ce2f
    goto L_0x0050ce2f;
L_0x0050ce50:
    // 0050ce50  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050ce54  0f85d7010000           -jne 0x50d031
    if (!cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050ce5a  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050ce5d  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050ce60  89690c                 -mov dword ptr [ecx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0050ce63  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050ce65  0f84bd010000           -je 0x50d028
    if (cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
    // 0050ce6b  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ce6e  7405                   -je 0x50ce75
    if (cpu.flags.zf)
    {
        goto L_0x0050ce75;
    }
    // 0050ce70  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ce73  751e                   -jne 0x50ce93
    if (!cpu.flags.zf)
    {
        goto L_0x0050ce93;
    }
L_0x0050ce75:
    // 0050ce75  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0050ce79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ce7b  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050ce7d  46                     -inc esi
    (cpu.esi)++;
    // 0050ce7e  e8b5060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050ce83  45                     -inc ebp
    (cpu.ebp)++;
    // 0050ce84  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ce86  896c2468               -mov dword ptr [esp + 0x68], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 0050ce8a  83f8ff                 +cmp eax, -1
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
    // 0050ce8d  0f849e010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050ce93:
    // 0050ce93  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050ce95  fec0                   -inc al
    (cpu.al)++;
    // 0050ce97  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ce9c  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cea3  7509                   -jne 0x50ceae
    if (!cpu.flags.zf)
    {
        goto L_0x0050ceae;
    }
    // 0050cea5  83fb2e                 +cmp ebx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cea8  0f857a010000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050ceae:
    // 0050ceae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ceb0  89442464               -mov dword ptr [esp + 0x64], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0050ceb4  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050ceb6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ceb8  fec0                   -inc al
    (cpu.al)++;
    // 0050ceba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cebf  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cec6  7441                   -je 0x50cf09
    if (cpu.flags.zf)
    {
        goto L_0x0050cf09;
    }
    // 0050cec8  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0050cecd:
    // 0050cecd  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cecf  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050ced2  46                     -inc esi
    (cpu.esi)++;
    // 0050ced3  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050ced5  740f                   -je 0x50cee6
    if (cpu.flags.zf)
    {
        goto L_0x0050cee6;
    }
    // 0050ced7  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0050cedc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050cede  83eb30                 -sub ebx, 0x30
    (cpu.ebx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050cee1  66895c2466             -mov word ptr [esp + 0x66], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.bx;
L_0x0050cee6:
    // 0050cee6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cee8  47                     -inc edi
    (cpu.edi)++;
    // 0050cee9  e84a060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050ceee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cef0  83f8ff                 +cmp eax, -1
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
    // 0050cef3  0f8438010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cef9  fec0                   -inc al
    (cpu.al)++;
    // 0050cefb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf00  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf07  75c4                   -jne 0x50cecd
    if (!cpu.flags.zf)
    {
        goto L_0x0050cecd;
    }
L_0x0050cf09:
    // 0050cf09  83fb2e                 +cmp ebx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cf0c  0f8598000000           -jne 0x50cfaa
    if (!cpu.flags.zf)
    {
        goto L_0x0050cfaa;
    }
    // 0050cf12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cf14  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cf16  46                     -inc esi
    (cpu.esi)++;
    // 0050cf17  e81c060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cf1c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cf1e  83f8ff                 +cmp eax, -1
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
    // 0050cf21  0f840a010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cf27  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050cf29  7514                   -jne 0x50cf3f
    if (!cpu.flags.zf)
    {
        goto L_0x0050cf3f;
    }
    // 0050cf2b  fec0                   -inc al
    (cpu.al)++;
    // 0050cf2d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf32  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf39  0f84e9000000           -je 0x50d028
    if (cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050cf3f:
    // 0050cf3f  47                     -inc edi
    (cpu.edi)++;
L_0x0050cf40:
    // 0050cf40  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cf42  fec0                   -inc al
    (cpu.al)++;
    // 0050cf44  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf49  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf50  7412                   -je 0x50cf64
    if (cpu.flags.zf)
    {
        goto L_0x0050cf64;
    }
    // 0050cf52  47                     -inc edi
    (cpu.edi)++;
    // 0050cf53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cf55  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cf57  46                     -inc esi
    (cpu.esi)++;
    // 0050cf58  e8db050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cf5d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cf5f  83f8ff                 +cmp eax, -1
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
    // 0050cf62  75dc                   -jne 0x50cf40
    if (!cpu.flags.zf)
    {
        goto L_0x0050cf40;
    }
L_0x0050cf64:
    // 0050cf64  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cf68  7437                   -je 0x50cfa1
    if (cpu.flags.zf)
    {
        goto L_0x0050cfa1;
    }
    // 0050cf6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050cf6c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050cf6e  89542460               -mov dword ptr [esp + 0x60], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x0050cf72:
    // 0050cf72  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0050cf75  4d                     -dec ebp
    (cpu.ebp)--;
    // 0050cf76  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cf78  741e                   -je 0x50cf98
    if (cpu.flags.zf)
    {
        goto L_0x0050cf98;
    }
    // 0050cf7a  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0050cf7c  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 0050cf84  88442462               -mov byte ptr [esp + 0x62], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 0050cf88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050cf8a  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0050cf8e  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0050cf92  89442460               -mov dword ptr [esp + 0x60], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0050cf96  ebda                   -jmp 0x50cf72
    goto L_0x0050cf72;
L_0x0050cf98:
    // 0050cf98  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0050cf9c  6689442464             -mov word ptr [esp + 0x64], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x0050cfa1:
    // 0050cfa1  83fbff                 +cmp ebx, -1
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
    // 0050cfa4  0f8487000000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050cfaa:
    // 0050cfaa  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cfae  0f8574000000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
    // 0050cfb4  83fb65                 +cmp ebx, 0x65
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfb7  7409                   -je 0x50cfc2
    if (cpu.flags.zf)
    {
        goto L_0x0050cfc2;
    }
    // 0050cfb9  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfbc  0f8566000000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050cfc2:
    // 0050cfc2  47                     -inc edi
    (cpu.edi)++;
    // 0050cfc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cfc5  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cfc7  46                     -inc esi
    (cpu.esi)++;
    // 0050cfc8  e86b050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cfcd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cfcf  83f8ff                 +cmp eax, -1
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
    // 0050cfd2  745d                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cfd4  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfd7  7405                   -je 0x50cfde
    if (cpu.flags.zf)
    {
        goto L_0x0050cfde;
    }
    // 0050cfd9  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfdc  7512                   -jne 0x50cff0
    if (!cpu.flags.zf)
    {
        goto L_0x0050cff0;
    }
L_0x0050cfde:
    // 0050cfde  47                     -inc edi
    (cpu.edi)++;
    // 0050cfdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cfe1  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cfe3  46                     -inc esi
    (cpu.esi)++;
    // 0050cfe4  e84f050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cfe9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cfeb  83f8ff                 +cmp eax, -1
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
    // 0050cfee  7441                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050cff0:
    // 0050cff0  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cff2  fec0                   -inc al
    (cpu.al)++;
    // 0050cff4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cff9  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050d000  7504                   -jne 0x50d006
    if (!cpu.flags.zf)
    {
        goto L_0x0050d006;
    }
    // 0050d002  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050d004  eb22                   -jmp 0x50d028
    goto L_0x0050d028;
L_0x0050d006:
    // 0050d006  47                     -inc edi
    (cpu.edi)++;
    // 0050d007  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050d009  881e                   -mov byte ptr [esi], bl
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050d00b  46                     -inc esi
    (cpu.esi)++;
    // 0050d00c  e827050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d011  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050d013  83f8ff                 +cmp eax, -1
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
    // 0050d016  7419                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050d018  fec0                   -inc al
    (cpu.al)++;
    // 0050d01a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d01f  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050d026  75de                   -jne 0x50d006
    if (!cpu.flags.zf)
    {
        goto L_0x0050d006;
    }
L_0x0050d028:
    // 0050d028  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050d02a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d02c  e817f6ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050d031:
    // 0050d031  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050d033  0f8eab000000           -jle 0x50d0e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d0e4;
    }
    // 0050d039  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0050d03d  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050d041  0f849d000000           -je 0x50d0e4
    if (cpu.flags.zf)
    {
        goto L_0x0050d0e4;
    }
    // 0050d047  c60600                 -mov byte ptr [esi], 0
    *app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0050d04a  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050d04e  740c                   -je 0x50d05c
    if (cpu.flags.zf)
    {
        goto L_0x0050d05c;
    }
    // 0050d050  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d054  7512                   -jne 0x50d068
    if (!cpu.flags.zf)
    {
        goto L_0x0050d068;
    }
    // 0050d056  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0050d05a  eb0c                   -jmp 0x50d068
    goto L_0x0050d068;
L_0x0050d05c:
    // 0050d05c  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d060  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050d062  ff1568ac5600           -call dword ptr [0x56ac68]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5680232) /* 0x56ac68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0050d068:
    // 0050d068  8a6110                 -mov ah, byte ptr [ecx + 0x10]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050d06b  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0050d06e  7410                   -je 0x50d080
    if (cpu.flags.zf)
    {
        goto L_0x0050d080;
    }
    // 0050d070  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d074  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d076  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d079  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0050d07b  c45bf8                 -les ebx, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0050d07e  eb2b                   -jmp 0x50d0ab
    goto L_0x0050d0ab;
L_0x0050d080:
    // 0050d080  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0050d083  7414                   -je 0x50d099
    if (cpu.flags.zf)
    {
        goto L_0x0050d099;
    }
    // 0050d085  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d089  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d08b  83c204                 +add edx, 4
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
    // 0050d08e  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d090  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d092  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d094  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d097  eb12                   -jmp 0x50d0ab
    goto L_0x0050d0ab;
L_0x0050d099:
    // 0050d099  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d09d  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d09f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d0a2  8928                   -mov dword ptr [eax], ebp
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 0050d0a4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d0a6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d0a8  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0050d0ab:
    // 0050d0ab  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050d0ae  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0050d0b1  7406                   -je 0x50d0b9
    if (cpu.flags.zf)
    {
        goto L_0x0050d0b9;
    }
    // 0050d0b3  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0050d0b7  eb28                   -jmp 0x50d0e1
    goto L_0x0050d0e1;
L_0x0050d0b9:
    // 0050d0b9  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0050d0bc  7505                   -jne 0x50d0c3
    if (!cpu.flags.zf)
    {
        goto L_0x0050d0c3;
    }
    // 0050d0be  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 0050d0c1  7411                   -je 0x50d0d4
    if (cpu.flags.zf)
    {
        goto L_0x0050d0d4;
    }
L_0x0050d0c3:
    // 0050d0c3  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d0c7  268903                 -mov dword ptr es:[ebx], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 0050d0ca  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050d0ce  26894304               -mov dword ptr es:[ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050d0d2  eb10                   -jmp 0x50d0e4
    goto L_0x0050d0e4;
L_0x0050d0d4:
    // 0050d0d4  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d0d8  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050d0dc  e8bf6b0100             -call 0x523ca0
    cpu.esp -= 4;
    sub_523ca0(app, cpu);
    if (cpu.terminate) return;
L_0x0050d0e1:
    // 0050d0e1  268903                 -mov dword ptr es:[ebx], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x0050d0e4:
    // 0050d0e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d0e6  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0050d0e9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ea  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d0eb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ee  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50d0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d0f0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d0f1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d0f2  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050d0f3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d0f4  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d0f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d0f9  8954241c               -mov dword ptr [esp + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0050d0fd  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050d101  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050d103  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d105  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050d109  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050d10d  89542424               -mov dword ptr [esp + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050d111  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0050d115:
    // 0050d115  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d117  e824f5ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050d11c  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d120  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d124  fec3                   -inc bl
    (cpu.bl)++;
    // 0050d126  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d12c  f683f04e560002         +test byte ptr [ebx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050d133  7406                   -je 0x50d13b
    if (cpu.flags.zf)
    {
        goto L_0x0050d13b;
    }
    // 0050d135  ff442420               +inc dword ptr [esp + 0x20]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050d139  ebda                   -jmp 0x50d115
    goto L_0x0050d115;
L_0x0050d13b:
    // 0050d13b  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050d13f  0f8590020000           -jne 0x50d3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d145  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050d148  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0050d14b  89770c                 -mov dword ptr [edi + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050d14e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050d150  0f8474020000           -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d156  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 0050d15b  895c2418               -mov dword ptr [esp + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0050d15f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050d161  742e                   -je 0x50d191
    if (cpu.flags.zf)
    {
        goto L_0x0050d191;
    }
    // 0050d163  39d8                   +cmp eax, ebx
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
    // 0050d165  7405                   -je 0x50d16c
    if (cpu.flags.zf)
    {
        goto L_0x0050d16c;
    }
    // 0050d167  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d16a  7525                   -jne 0x50d191
    if (!cpu.flags.zf)
    {
        goto L_0x0050d191;
    }
L_0x0050d16c:
    // 0050d16c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d170  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d174  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050d178  41                     -inc ecx
    (cpu.ecx)++;
    // 0050d179  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d17b  894c2420               -mov dword ptr [esp + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050d17f  e8b4030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d184  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d188  83f8ff                 +cmp eax, -1
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
    // 0050d18b  0f8444020000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
L_0x0050d191:
    // 0050d191  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d195  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050d197  0f8569000000           -jne 0x50d206
    if (!cpu.flags.zf)
    {
        goto L_0x0050d206;
    }
    // 0050d19d  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d1a2  7558                   -jne 0x50d1fc
    if (!cpu.flags.zf)
    {
        goto L_0x0050d1fc;
    }
    // 0050d1a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d1a6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0050d1ab  e888030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d1b0  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d1b4  83f8ff                 +cmp eax, -1
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
    // 0050d1b7  0f8418020000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d1bd  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d1c0  7405                   -je 0x50d1c7
    if (cpu.flags.zf)
    {
        goto L_0x0050d1c7;
    }
    // 0050d1c2  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d1c5  752b                   -jne 0x50d1f2
    if (!cpu.flags.zf)
    {
        goto L_0x0050d1f2;
    }
L_0x0050d1c7:
    // 0050d1c7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d1c9  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d1cd  e866030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d1d2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d1d4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d1d7  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d1db  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0050d1df  83f8ff                 +cmp eax, -1
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
    // 0050d1e2  0f84ed010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d1e8  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 0050d1f0  eb64                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d1f2:
    // 0050d1f2  c744242808000000       -mov dword ptr [esp + 0x28], 8
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 0050d1fa  eb5a                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d1fc:
    // 0050d1fc  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 0050d204  eb50                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d206:
    // 0050d206  83fe10                 +cmp esi, 0x10
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
    // 0050d209  754b                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
    // 0050d20b  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d210  7544                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
    // 0050d212  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d214  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0050d219  e81a030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d21e  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d222  83f8ff                 +cmp eax, -1
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
    // 0050d225  0f84aa010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d22b  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d22e  7405                   -je 0x50d235
    if (cpu.flags.zf)
    {
        goto L_0x0050d235;
    }
    // 0050d230  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d233  7521                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
L_0x0050d235:
    // 0050d235  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d237  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d23b  e8f8020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d240  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d242  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d245  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d249  895c2420               -mov dword ptr [esp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0050d24d  83f8ff                 +cmp eax, -1
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
    // 0050d250  0f847f010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
L_0x0050d256:
    // 0050d256  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0050d25a  0f84ff000000           -je 0x50d35f
    if (cpu.flags.zf)
    {
        goto L_0x0050d35f;
    }
    // 0050d260  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d264  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d266  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050d26a  894c2414               -mov dword ptr [esp + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0050d26e:
    // 0050d26e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d272  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d276  e895020000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d27b  39d0                   +cmp eax, edx
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
    // 0050d27d  7d5d                   -jge 0x50d2dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d2dc;
    }
    // 0050d27f  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d283  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d286  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050d288  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d28c  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050d290  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050d294  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d297  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d299  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d29c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d29e  e8496a0100             -call 0x523cec
    cpu.esp -= 4;
    sub_523cec(app, cpu);
    if (cpu.terminate) return;
    // 0050d2a3  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d2a6  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d2a8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d2ac  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050d2ae  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d2b2  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d2b5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d2b7  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d2ba  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d2bc  01d8                   +add eax, ebx
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
    // 0050d2be  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0050d2c0  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d2c3  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d2c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d2c7  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d2c8  e86b020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d2cd  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d2d1  83f8ff                 +cmp eax, -1
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
    // 0050d2d4  0f84fb000000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d2da  eb92                   -jmp 0x50d26e
    goto L_0x0050d26e;
L_0x0050d2dc:
    // 0050d2dc  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d2e1  0f85e3000000           -jne 0x50d3ca
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d2e7  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0050d2eb  0f84d9000000           -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
L_0x0050d2f1:
    // 0050d2f1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d2f3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d2f4  e83f020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d2f9  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d2fd  83f8ff                 +cmp eax, -1
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
    // 0050d300  0f84cf000000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d306  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d30a  e801020000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d30f  39f0                   +cmp eax, esi
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
    // 0050d311  0f8db3000000           -jge 0x50d3ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d3ca;
    }
    // 0050d317  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d31b  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d31e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d320  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050d324  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050d328  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d32c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d32f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d331  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d334  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d336  e8b1690100             -call 0x523cec
    cpu.esp -= 4;
    sub_523cec(app, cpu);
    if (cpu.terminate) return;
    // 0050d33b  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d33e  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d340  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d344  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050d346  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d34a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d34d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d34f  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d352  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d354  01d8                   +add eax, ebx
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
    // 0050d356  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d358  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d35b  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d35d  eb92                   -jmp 0x50d2f1
    goto L_0x0050d2f1;
L_0x0050d35f:
    // 0050d35f  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0050d363:
    // 0050d363  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d367  e8a4010000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d36c  39f0                   +cmp eax, esi
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
    // 0050d36e  7d20                   -jge 0x50d390
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d390;
    }
    // 0050d370  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d374  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d377  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d378  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d37a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d37c  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050d380  e8b3010000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d385  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d389  83f8ff                 +cmp eax, -1
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
    // 0050d38c  7447                   -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d38e  ebd3                   -jmp 0x50d363
    goto L_0x0050d363;
L_0x0050d390:
    // 0050d390  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d395  7533                   -jne 0x50d3ca
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d397  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0050d39b  742d                   -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d39d  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0050d3a1:
    // 0050d3a1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d3a3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d3a4  e88f010000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d3a9  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d3ad  83f8ff                 +cmp eax, -1
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
    // 0050d3b0  7423                   -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d3b2  e859010000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d3b7  39c8                   +cmp eax, ecx
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
    // 0050d3b9  7d0f                   -jge 0x50d3ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d3ca;
    }
    // 0050d3bb  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d3bf  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050d3c2  01c3                   +add ebx, eax
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
    // 0050d3c4  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050d3c8  ebd7                   -jmp 0x50d3a1
    goto L_0x0050d3a1;
L_0x0050d3ca:
    // 0050d3ca  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d3ce  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050d3d0  e873f2ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050d3d5:
    // 0050d3d5  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0050d3d9  0f84a2000000           -je 0x50d481
    if (cpu.flags.zf)
    {
        goto L_0x0050d481;
    }
    // 0050d3df  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d3e4  7524                   -jne 0x50d40a
    if (!cpu.flags.zf)
    {
        goto L_0x0050d40a;
    }
    // 0050d3e6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d3ea  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d3ee  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0050d3f0  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0050d3f2  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050d3f6  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050d3f9  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050d3fd  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050d401  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050d403  7501                   -jne 0x50d406
    if (!cpu.flags.zf)
    {
        goto L_0x0050d406;
    }
    // 0050d405  40                     -inc eax
    (cpu.eax)++;
L_0x0050d406:
    // 0050d406  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050d40a:
    // 0050d40a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050d40c  0f8ef1000000           -jle 0x50d503
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d503;
    }
    // 0050d412  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d416  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d419  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d41b  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0050d41e  0f84df000000           -je 0x50d503
    if (cpu.flags.zf)
    {
        goto L_0x0050d503;
    }
    // 0050d424  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0050d427  7414                   -je 0x50d43d
    if (cpu.flags.zf)
    {
        goto L_0x0050d43d;
    }
    // 0050d429  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d42d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d42f  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d432  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d434  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d438  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0050d43b  eb32                   -jmp 0x50d46f
    goto L_0x0050d46f;
L_0x0050d43d:
    // 0050d43d  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0050d440  741d                   -je 0x50d45f
    if (cpu.flags.zf)
    {
        goto L_0x0050d45f;
    }
    // 0050d442  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d446  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d448  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d44b  8938                   -mov dword ptr [eax], edi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0050d44d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d44f  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0050d452  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d456  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d458  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d459  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d45a  e9a4000000             -jmp 0x50d503
    goto L_0x0050d503;
L_0x0050d45f:
    // 0050d45f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d463  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d465  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d468  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050d46a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d46c  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0050d46f:
    // 0050d46f  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d473  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d475  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d476  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d477  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d479  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d47c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d47d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d47e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d47f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d480  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d481:
    // 0050d481  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d486  7504                   -jne 0x50d48c
    if (!cpu.flags.zf)
    {
        goto L_0x0050d48c;
    }
    // 0050d488  f75c2424               -neg dword ptr [esp + 0x24]
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x0050d48c:
    // 0050d48c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050d48e  0f8e6f000000           -jle 0x50d503
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d503;
    }
    // 0050d494  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d498  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d49b  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d49d  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050d49f  7462                   -je 0x50d503
    if (cpu.flags.zf)
    {
        goto L_0x0050d503;
    }
    // 0050d4a1  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050d4a3  7410                   -je 0x50d4b5
    if (cpu.flags.zf)
    {
        goto L_0x0050d4b5;
    }
    // 0050d4a5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4a9  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4ab  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d4ae  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0050d4b0  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0050d4b3  eb2a                   -jmp 0x50d4df
    goto L_0x0050d4df;
L_0x0050d4b5:
    // 0050d4b5  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050d4b7  7414                   -je 0x50d4cd
    if (cpu.flags.zf)
    {
        goto L_0x0050d4cd;
    }
    // 0050d4b9  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4bd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4bf  83c204                 +add edx, 4
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
    // 0050d4c2  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0050d4c4  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d4c6  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0050d4c8  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d4cb  eb12                   -jmp 0x50d4df
    goto L_0x0050d4df;
L_0x0050d4cd:
    // 0050d4cd  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4d1  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4d3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d4d6  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0050d4d8  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050d4da  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0050d4dc  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0050d4df:
    // 0050d4df  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d4e2  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0050d4e5  7412                   -je 0x50d4f9
    if (cpu.flags.zf)
    {
        goto L_0x0050d4f9;
    }
    // 0050d4e7  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d4eb  66268918               -mov word ptr es:[eax], bx
    *app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 0050d4ef  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d4f1  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d4f4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f5  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d4f9:
    // 0050d4f9  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0050d4fc  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d500  268918                 -mov dword ptr es:[eax], ebx
    *app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x0050d503:
    // 0050d503  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d505  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d508  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d509  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d50a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d50b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d50c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50d510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d510  83f830                 +cmp eax, 0x30
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
    // 0050d513  7c09                   -jl 0x50d51e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d51e;
    }
    // 0050d515  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d518  7f04                   -jg 0x50d51e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050d51e;
    }
    // 0050d51a  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d51d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d51e:
    // 0050d51e  e8bd35feff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 0050d523  83f861                 +cmp eax, 0x61
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
    // 0050d526  7c09                   -jl 0x50d531
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d531;
    }
    // 0050d528  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d52b  7f04                   -jg 0x50d531
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050d531;
    }
    // 0050d52d  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0050d530  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d531:
    // 0050d531  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0050d536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50d538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d538  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050d539  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050d53a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d53c  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050d53f  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050d542  895a0c                 -mov dword ptr [edx + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0050d545  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050d547  740d                   -je 0x50d556
    if (cpu.flags.zf)
    {
        goto L_0x0050d556;
    }
    // 0050d549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050d54b  e8f0f0ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050d550  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050d554  7405                   -je 0x50d55b
    if (cpu.flags.zf)
    {
        goto L_0x0050d55b;
    }
L_0x0050d556:
    // 0050d556  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0050d55b:
    // 0050d55b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d55c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d55d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_50d560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d560  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0050d561  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d562  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0050d567  0f8504010000           -jne 0x50d671
    if (!cpu.flags.zf)
    {
        goto L_0x0050d671;
    }
L_0x0050d56d:
    // 0050d56d  81eb80000000           +sub ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d573  787d                   -js 0x50d5f2
    if (cpu.flags.sf)
    {
        goto L_0x0050d5f2;
    }
L_0x0050d575:
    // 0050d575  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx)));
    // 0050d577  dd4220                 -fld qword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 0050d57a  dd4240                 -fld qword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 0050d57d  dd4260                 -fld qword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 0050d580  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d582  dd4210                 -fld qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(16) /* 0x10 */)));
    // 0050d585  dd4208                 -fld qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050d588  dd4218                 -fld qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050d58b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d58d  dd18                   -fstp qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d58f  dd5808                 -fstp qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d592  dd5810                 -fstp qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d595  dd5818                 -fstp qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d598  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d59a  dd4230                 -fld qword ptr [edx + 0x30]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(48) /* 0x30 */)));
    // 0050d59d  dd4228                 -fld qword ptr [edx + 0x28]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(40) /* 0x28 */)));
    // 0050d5a0  dd4238                 -fld qword ptr [edx + 0x38]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(56) /* 0x38 */)));
    // 0050d5a3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5a5  dd5820                 -fstp qword ptr [eax + 0x20]
    *app->getMemory<double>(cpu.eax + x86::reg32(32) /* 0x20 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5a8  dd5828                 -fstp qword ptr [eax + 0x28]
    *app->getMemory<double>(cpu.eax + x86::reg32(40) /* 0x28 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5ab  dd5830                 -fstp qword ptr [eax + 0x30]
    *app->getMemory<double>(cpu.eax + x86::reg32(48) /* 0x30 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5ae  dd5838                 -fstp qword ptr [eax + 0x38]
    *app->getMemory<double>(cpu.eax + x86::reg32(56) /* 0x38 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5b1  dd4250                 -fld qword ptr [edx + 0x50]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(80) /* 0x50 */)));
    // 0050d5b4  dd4248                 -fld qword ptr [edx + 0x48]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(72) /* 0x48 */)));
    // 0050d5b7  dd4258                 -fld qword ptr [edx + 0x58]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(88) /* 0x58 */)));
    // 0050d5ba  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5bc  dd5840                 -fstp qword ptr [eax + 0x40]
    *app->getMemory<double>(cpu.eax + x86::reg32(64) /* 0x40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5bf  dd5848                 -fstp qword ptr [eax + 0x48]
    *app->getMemory<double>(cpu.eax + x86::reg32(72) /* 0x48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c2  dd5850                 -fstp qword ptr [eax + 0x50]
    *app->getMemory<double>(cpu.eax + x86::reg32(80) /* 0x50 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c5  dd5858                 -fstp qword ptr [eax + 0x58]
    *app->getMemory<double>(cpu.eax + x86::reg32(88) /* 0x58 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c8  dd4270                 -fld qword ptr [edx + 0x70]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(112) /* 0x70 */)));
    // 0050d5cb  dd4268                 -fld qword ptr [edx + 0x68]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(104) /* 0x68 */)));
    // 0050d5ce  dd4278                 -fld qword ptr [edx + 0x78]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(120) /* 0x78 */)));
    // 0050d5d1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5d3  dd5860                 -fstp qword ptr [eax + 0x60]
    *app->getMemory<double>(cpu.eax + x86::reg32(96) /* 0x60 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5d6  dd5868                 -fstp qword ptr [eax + 0x68]
    *app->getMemory<double>(cpu.eax + x86::reg32(104) /* 0x68 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5d9  dd5870                 -fstp qword ptr [eax + 0x70]
    *app->getMemory<double>(cpu.eax + x86::reg32(112) /* 0x70 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5dc  dd5878                 -fstp qword ptr [eax + 0x78]
    *app->getMemory<double>(cpu.eax + x86::reg32(120) /* 0x78 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5df  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050d5e5  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050d5ea  81eb80000000           +sub ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d5f0  7983                   -jns 0x50d575
    if (!cpu.flags.sf)
    {
        goto L_0x0050d575;
    }
L_0x0050d5f2:
    // 0050d5f2  83c360                 +add ebx, 0x60
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d5f5  7825                   -js 0x50d61c
    if (cpu.flags.sf)
    {
        goto L_0x0050d61c;
    }
L_0x0050d5f7:
    // 0050d5f7  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx)));
    // 0050d5f9  dd4208                 -fld qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050d5fc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d5fe  dd18                   -fstp qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d600  dd5808                 -fstp qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d603  dd4210                 -fld qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(16) /* 0x10 */)));
    // 0050d606  dd4218                 -fld qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050d609  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d60b  dd5810                 -fstp qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d60e  dd5818                 -fstp qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d611  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050d614  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050d617  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d61a  79db                   -jns 0x50d5f7
    if (!cpu.flags.sf)
    {
        goto L_0x0050d5f7;
    }
L_0x0050d61c:
    // 0050d61c  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d61f  780f                   -js 0x50d630
    if (cpu.flags.sf)
    {
        goto L_0x0050d630;
    }
L_0x0050d621:
    // 0050d621  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.edx)));
    // 0050d623  dd18                   -fstp qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d625  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050d628  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050d62b  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d62e  79f1                   -jns 0x50d621
    if (!cpu.flags.sf)
    {
        goto L_0x0050d621;
    }
L_0x0050d630:
    // 0050d630  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d633  7502                   -jne 0x50d637
    if (!cpu.flags.zf)
    {
        goto L_0x0050d637;
    }
    // 0050d635  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d636  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d637:
    // 0050d637  83fb04                 +cmp ebx, 4
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
    // 0050d63a  720d                   -jb 0x50d649
    if (cpu.flags.cf)
    {
        goto L_0x0050d649;
    }
    // 0050d63c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050d63e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d641  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050d643  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d646  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050d649:
    // 0050d649  83fb02                 +cmp ebx, 2
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
    // 0050d64c  720f                   -jb 0x50d65d
    if (cpu.flags.cf)
    {
        goto L_0x0050d65d;
    }
    // 0050d64e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx);
    // 0050d651  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d654  668908                 -mov word ptr [eax], cx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0050d657  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d65a  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050d65d:
    // 0050d65d  83fb01                 +cmp ebx, 1
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
    // 0050d660  720d                   -jb 0x50d66f
    if (cpu.flags.cf)
    {
        goto L_0x0050d66f;
    }
    // 0050d662  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050d664  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d667  8808                   -mov byte ptr [eax], cl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050d669  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d66c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050d66f:
    // 0050d66f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d670  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d671:
    // 0050d671  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0050d676  7412                   -je 0x50d68a
    if (cpu.flags.zf)
    {
        goto L_0x0050d68a;
    }
    // 0050d678  83fb01                 +cmp ebx, 1
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
    // 0050d67b  7c0d                   -jl 0x50d68a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d68a;
    }
    // 0050d67d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050d67f  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d682  8808                   -mov byte ptr [eax], cl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050d684  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d687  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050d68a:
    // 0050d68a  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0050d68f  7414                   -je 0x50d6a5
    if (cpu.flags.zf)
    {
        goto L_0x0050d6a5;
    }
    // 0050d691  83fb02                 +cmp ebx, 2
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
    // 0050d694  7c0f                   -jl 0x50d6a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d6a5;
    }
    // 0050d696  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx);
    // 0050d699  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d69c  668908                 -mov word ptr [eax], cx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0050d69f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d6a2  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050d6a5:
    // 0050d6a5  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0050d6aa  7412                   -je 0x50d6be
    if (cpu.flags.zf)
    {
        goto L_0x0050d6be;
    }
    // 0050d6ac  83fb04                 +cmp ebx, 4
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
    // 0050d6af  7c0d                   -jl 0x50d6be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d6be;
    }
    // 0050d6b1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050d6b3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d6b6  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050d6b8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d6bb  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0050d6be:
    // 0050d6be  e9aafeffff             -jmp 0x50d56d
    goto L_0x0050d56d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50d6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d6d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50d6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d6e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d6e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d6e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d6e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d6e4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d6e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d6e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d6eb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050d6ed:
    // 0050d6ed  80790300               +cmp byte ptr [ecx + 3], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d6f1  750f                   -jne 0x50d702
    if (!cpu.flags.zf)
    {
        goto L_0x0050d702;
    }
    // 0050d6f3  46                     -inc esi
    (cpu.esi)++;
    // 0050d6f4  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d6f7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d6f8  75f3                   -jne 0x50d6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0050d6ed;
    }
    // 0050d6fa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d6fd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d6fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d6ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d700  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d701  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d702:
    // 0050d702  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0050d704  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d709  e892ecffff             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0050d70e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d710  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0050d715  0f84a8000000           -je 0x50d7c3
    if (cpu.flags.zf)
    {
        goto L_0x0050d7c3;
    }
    // 0050d71b  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 0050d71d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050d71f  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0050d722  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0050d725  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0050d728  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 0050d72a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d72f  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0050d732  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d738  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d73b  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0050d73d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050d740  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d743  887c240c               -mov byte ptr [esp + 0xc], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 0050d747  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050d74a  88442410               -mov byte ptr [esp + 0x10], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 0050d74e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d750  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0050d752  88742404               -mov byte ptr [esp + 4], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 0050d756  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d759  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d75b  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050d75e  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050d762  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050d765  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050d768  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d76b  88542408               -mov byte ptr [esp + 8], dl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0050d76f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d775  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d777  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050d77c  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050d77f  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d782  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0050d784  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d78a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d78c  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0050d791  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050d794  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0050d797  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d79a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d79c  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050d79f  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d7a3  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d7a5  8844240c               -mov byte ptr [esp + 0xc], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0050d7a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d7ab  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050d7ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050d7af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d7b1  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050d7b4  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050d7b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050d7b8  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050d7bb  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d7bf  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050d7c1  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d7c3:
    // 0050d7c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050d7c5  e8961ffeff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0050d7ca  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0050d7cc  46                     -inc esi
    (cpu.esi)++;
    // 0050d7cd  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d7d0  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d7d1  0f8516ffffff           -jne 0x50d6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0050d6ed;
    }
    // 0050d7d7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d7da  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7db  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7dc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d7e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d7e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d7e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d7e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d7e4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d7e6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d7e8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0050d7ea:
    // 0050d7ea  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050d7ec  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d7f2  7273                   -jb 0x50d867
    if (cpu.flags.cf)
    {
        goto L_0x0050d867;
    }
    // 0050d7f4  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d7fa  7348                   -jae 0x50d844
    if (!cpu.flags.cf)
    {
        goto L_0x0050d844;
    }
    // 0050d7fc  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050d7ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d801  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050d806  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050d809  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050d80b  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050d811  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050d814  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d816  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d819  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d81b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050d81d  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050d820  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d826  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050d828  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050d82b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d82d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d82f  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050d832  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d838  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d83a  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050d83d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050d842  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d844:
    // 0050d844  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d846  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050d84c  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050d84f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d851  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050d854  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050d85a  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050d85d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d860  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d862  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d864  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050d867:
    // 0050d867  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050d86a  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d86d  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d86e  0f8576ffffff           -jne 0x50d7ea
    if (!cpu.flags.zf)
    {
        goto L_0x0050d7ea;
    }
    // 0050d874  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d875  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d876  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d877  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50d880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d880  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d881  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d882  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d883  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d884  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d886  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d888  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0050d88a:
    // 0050d88a  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050d88c  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d892  726b                   -jb 0x50d8ff
    if (cpu.flags.cf)
    {
        goto L_0x0050d8ff;
    }
    // 0050d894  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d89a  7340                   -jae 0x50d8dc
    if (!cpu.flags.cf)
    {
        goto L_0x0050d8dc;
    }
    // 0050d89c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050d89f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050d8a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d8a3  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050d8a6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050d8a9  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050d8ab  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050d8b1  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050d8b4  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050d8b9  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050d8bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8be  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050d8c0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050d8c3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d8c5  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050d8c8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8ca  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050d8cd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d8d3  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050d8d8  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d8da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d8dc:
    // 0050d8dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d8de  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050d8e4  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050d8e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d8e9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050d8ec  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050d8f2  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050d8f5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d8f8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d8fa  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8fc  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050d8ff:
    // 0050d8ff  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050d902  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d905  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d906  7582                   -jne 0x50d88a
    if (!cpu.flags.zf)
    {
        goto L_0x0050d88a;
    }
    // 0050d908  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d909  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50d910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d910  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d911  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d912  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d913  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d914  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d917  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050d919:
    // 0050d919  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d91d  7511                   -jne 0x50d930
    if (!cpu.flags.zf)
    {
        goto L_0x0050d930;
    }
L_0x0050d91f:
    // 0050d91f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050d922  83c004                 +add eax, 4
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
    // 0050d925  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d926  75f1                   -jne 0x50d919
    if (!cpu.flags.zf)
    {
        goto L_0x0050d919;
    }
    // 0050d928  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d92b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d930:
    // 0050d930  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050d933  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 0050d935  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050d938  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0050d93b  886c2410               -mov byte ptr [esp + 0x10], ch
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0050d93f  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 0050d941  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050d946  885c240c               -mov byte ptr [esp + 0xc], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0050d94a  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050d94d  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0050d952  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050d955  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d958  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050d95b  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d95e  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050d960  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d963  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 0050d966  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050d969  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 0050d96c  886c2408               -mov byte ptr [esp + 8], ch
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 0050d970  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d973  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0050d978  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d97b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050d97d  886c2404               -mov byte ptr [esp + 4], ch
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 0050d981  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d984  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050d987  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d98d  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d98f  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0050d994  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050d997  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0050d99a  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050d99d  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050d9a0  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 0050d9a3  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d9a5  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d9a8  884a01                 -mov byte ptr [edx + 1], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0050d9ab  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050d9ae  885a02                 -mov byte ptr [edx + 2], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050d9b1  883a                   -mov byte ptr [edx], bh
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 0050d9b3  e967ffffff             -jmp 0x50d91f
    goto L_0x0050d91f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50d9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d9c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d9c1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d9c2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d9c3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d9c4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050d9c7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0050d9c9:
    // 0050d9c9  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d9cd  7511                   -jne 0x50d9e0
    if (!cpu.flags.zf)
    {
        goto L_0x0050d9e0;
    }
L_0x0050d9cf:
    // 0050d9cf  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d9d2  83c004                 +add eax, 4
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
    // 0050d9d5  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d9d6  75f1                   -jne 0x50d9c9
    if (!cpu.flags.zf)
    {
        goto L_0x0050d9c9;
    }
    // 0050d9d8  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050d9db  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9dc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9dd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9de  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d9e0:
    // 0050d9e0  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050d9e3  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050d9e6  887c2414               -mov byte ptr [esp + 0x14], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 0050d9ea  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax);
    // 0050d9ec  887c2410               -mov byte ptr [esp + 0x10], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 0050d9f0  807a0300               +cmp byte ptr [edx + 3], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d9f4  0f84a1000000           -je 0x50da9b
    if (cpu.flags.zf)
    {
        goto L_0x0050da9b;
    }
    // 0050d9fa  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 0050d9fc  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 0050d9ff  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050da02  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx);
    // 0050da04  887c2408               -mov byte ptr [esp + 8], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 0050da08  886c240c               -mov byte ptr [esp + 0xc], ch
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 0050da0c  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 0050da0f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050da11  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050da15  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da18  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050da1b  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 0050da1e  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da21  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da23  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050da27  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050da2b  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 0050da2e  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da31  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0050da36  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da39  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da3b  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0050da40  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da43  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da46  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050da4a  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0050da4d  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050da52  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0050da55  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da57  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050da5a  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 0050da5e  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0050da63  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0050da65  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050da68  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050da6c  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 0050da71  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0050da74  887c2414               -mov byte ptr [esp + 0x14], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 0050da78  29cf                   +sub edi, ecx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050da7a  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esp);
    // 0050da7d  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050da7f  887c2410               -mov byte ptr [esp + 0x10], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0050da83:
    // 0050da83  884a03                 -mov byte ptr [edx + 3], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0050da86  885a02                 -mov byte ptr [edx + 2], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050da89  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050da8d  885a01                 -mov byte ptr [edx + 1], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0050da90  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050da94  881a                   -mov byte ptr [edx], bl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0050da96  e934ffffff             -jmp 0x50d9cf
    goto L_0x0050d9cf;
L_0x0050da9b:
    // 0050da9b  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0050da9e  ebe3                   -jmp 0x50da83
    goto L_0x0050da83;
}

/* align: skip  */
void Application::sub_50daa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050daa0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050daa1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050daa2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050daa3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050daa4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050daa6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050daa8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050daaa:
    // 0050daaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050daac  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebp);
    // 0050daaf  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0050dab6  8b1d20b0a000           -mov ebx, dword ptr [0xa0b020]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10530848) /* 0xa0b020 */);
    // 0050dabc  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0050dabf  45                     -inc ebp
    (cpu.ebp)++;
    // 0050dac0  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dac6  7250                   -jb 0x50db18
    if (cpu.flags.cf)
    {
        goto L_0x0050db18;
    }
    // 0050dac8  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dace  7345                   -jae 0x50db15
    if (!cpu.flags.cf)
    {
        goto L_0x0050db15;
    }
    // 0050dad0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050dad2  668b06                 -mov ax, word ptr [esi]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi);
    // 0050dad5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050dad7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050dad9  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050dadc  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050dadf  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050dae1  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050dae7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050daea  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050daef  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050daf2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050daf4  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050daf6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050daf9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dafb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0050dafe  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050db04  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0050db07  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050db0c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050db0e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050db11  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050db13  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0050db15:
    // 0050db15  66891e                 -mov word ptr [esi], bx
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050db18:
    // 0050db18  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050db1b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050db1c  758c                   -jne 0x50daaa
    if (!cpu.flags.zf)
    {
        goto L_0x0050daaa;
    }
    // 0050db1e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db1f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db20  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db21  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50db30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050db30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050db31  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050db32  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050db33  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050db34  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050db3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050db3c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050db3e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050db40  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050db43  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050db49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050db4b  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 0050db50  8915c0885600           -mov dword ptr [0x5688c0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5671104) /* 0x5688c0 */) = cpu.edx;
    // 0050db56  890dc8885600           -mov dword ptr [0x5688c8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5671112) /* 0x5688c8 */) = cpu.ecx;
    // 0050db5c  83f808                 +cmp eax, 8
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
    // 0050db5f  752c                   -jne 0x50db8d
    if (!cpu.flags.zf)
    {
        goto L_0x0050db8d;
    }
    // 0050db61  803d1050560010         +cmp byte ptr [0x565010], 0x10
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050db68  7523                   -jne 0x50db8d
    if (!cpu.flags.zf)
    {
        goto L_0x0050db8d;
    }
    // 0050db6a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050db6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050db6e  bda0da5000             -mov ebp, 0x50daa0
    cpu.ebp = 5298848 /*0x50daa0*/;
    // 0050db73  e8b8ccffff             -call 0x50a830
    cpu.esp -= 4;
    sub_50a830(app, cpu);
    if (cpu.terminate) return;
    // 0050db78  a320b0a000             -mov dword ptr [0xa0b020], eax
    *app->getMemory<x86::reg32>(x86::reg32(10530848) /* 0xa0b020 */) = cpu.eax;
    // 0050db7d  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 0050db82  892dc0885600           -mov dword ptr [0x5688c0], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5671104) /* 0x5688c0 */) = cpu.ebp;
    // 0050db88  a3c8885600             -mov dword ptr [0x5688c8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5671112) /* 0x5688c8 */) = cpu.eax;
L_0x0050db8d:
    // 0050db8d  b9a8885600             -mov ecx, 0x5688a8
    cpu.ecx = 5671080 /*0x5688a8*/;
    // 0050db92  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050db94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050db96  e815d5ffff             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 0050db9b  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050dba1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50dbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dbb1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dbb2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050dbb5  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050dbb8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0050dbbb  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0050dbbe  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0050dbc1  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0050dbc4  e867ffffff             -call 0x50db30
    cpu.esp -= 4;
    sub_50db30(app, cpu);
    if (cpu.terminate) return;
    // 0050dbc9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbcb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_50dbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbd0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dbd1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0050dbd4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050dbd7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050dbd9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0050dbdc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050dbdf  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050dbe1  e84affffff             -call 0x50db30
    cpu.esp -= 4;
    sub_50db30(app, cpu);
    if (cpu.terminate) return;
    // 0050dbe6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50dbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50dc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dc00  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050dc04  740c                   -je 0x50dc12
    if (cpu.flags.zf)
    {
        goto L_0x0050dc12;
    }
L_0x0050dc06:
    // 0050dc06  4a                     -dec edx
    (cpu.edx)--;
    // 0050dc07  83faff                 +cmp edx, -1
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
    // 0050dc0a  7406                   -je 0x50dc12
    if (cpu.flags.zf)
    {
        goto L_0x0050dc12;
    }
    // 0050dc0c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050dc10  75f4                   -jne 0x50dc06
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc06;
    }
L_0x0050dc12:
    // 0050dc12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dc20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dc21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dc22  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dc23  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dc24  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dc25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dc27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc29  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dc2b  7441                   -je 0x50dc6e
    if (cpu.flags.zf)
    {
        goto L_0x0050dc6e;
    }
    // 0050dc2d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc2f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050dc31  763b                   -jbe 0x50dc6e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050dc6e;
    }
    // 0050dc33  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0050dc36  39fa                   +cmp edx, edi
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
    // 0050dc38  743c                   -je 0x50dc76
    if (cpu.flags.zf)
    {
        goto L_0x0050dc76;
    }
    // 0050dc3a  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050dc3c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050dc3e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050dc40  740b                   -je 0x50dc4d
    if (cpu.flags.zf)
    {
        goto L_0x0050dc4d;
    }
L_0x0050dc42:
    // 0050dc42  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dc44  7407                   -je 0x50dc4d
    if (cpu.flags.zf)
    {
        goto L_0x0050dc4d;
    }
    // 0050dc46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc48  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dc4b  75f5                   -jne 0x50dc42
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc42;
    }
L_0x0050dc4d:
    // 0050dc4d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050dc51  7417                   -je 0x50dc6a
    if (cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc53  39f2                   +cmp edx, esi
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
    // 0050dc55  7513                   -jne 0x50dc6a
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc57  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050dc5c  2919                   -sub dword ptr [ecx], ebx
    (*app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc5e  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050dc60  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050dc62  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dc65  7503                   -jne 0x50dc6a
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc67  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050dc6a:
    // 0050dc6a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dc6c  7544                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
L_0x0050dc6e:
    // 0050dc6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dc70  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc71  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc72  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc73  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc74  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dc76:
    // 0050dc76  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050dc7b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050dc7d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc7f  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050dc82  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0050dc84  39f7                   +cmp edi, esi
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
    // 0050dc86  7519                   -jne 0x50dca1
    if (!cpu.flags.zf)
    {
        goto L_0x0050dca1;
    }
    // 0050dc88  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dc8f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0050dc92  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050dc95  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dc97  7519                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
    // 0050dc99  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dc9b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dca0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dca1:
    // 0050dca1  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0050dca3  894108                 -mov dword ptr [ecx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050dca6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dca8  7508                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
    // 0050dcaa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dcac  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcad  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcaf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcb0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dcb2:
    // 0050dcb2  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050dcb8  80490401               -or byte ptr [ecx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050dcbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dcbe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcbf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_50dcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dcd0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dcd1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dcd3  e808d6fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0050dcd8  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0050dcde  c7410402000000         -mov dword ptr [ecx + 4], 2
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 2 /*0x2*/;
    // 0050dce5  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dcec  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050dcf3  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050dcf6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dcf8  740f                   -je 0x50dd09
    if (cpu.flags.zf)
    {
        goto L_0x0050dd09;
    }
    // 0050dcfa  895110                 -mov dword ptr [ecx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dcfd  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd00  895914                 -mov dword ptr [ecx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd05  7416                   -je 0x50dd1d
    if (cpu.flags.zf)
    {
        goto L_0x0050dd1d;
    }
    // 0050dd07  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd09:
    // 0050dd09  baf0db5000             -mov edx, 0x50dbf0
    cpu.edx = 5299184 /*0x50dbf0*/;
    // 0050dd0e  895110                 -mov dword ptr [ecx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd11  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd14  895914                 -mov dword ptr [ecx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd17  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd19  7402                   -je 0x50dd1d
    if (cpu.flags.zf)
    {
        goto L_0x0050dd1d;
    }
    // 0050dd1b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd1d:
    // 0050dd1d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dd1e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dd1f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dd20  bec4fb5400             -mov esi, 0x54fbc4
    cpu.esi = 5569476 /*0x54fbc4*/;
    // 0050dd25  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050dd2a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dd2b  bf8b000000             -mov edi, 0x8b
    cpu.edi = 139 /*0x8b*/;
    // 0050dd30  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050dd36  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050dd3b  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050dd41  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050dd47  e8c432efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dd4c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050dd4f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd50  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd51  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dd60  8b4918                 -mov ecx, dword ptr [ecx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd63  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0050dd69  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0050dd70  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dd77  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050dd7e  894818                 -mov dword ptr [eax + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050dd81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd83  740e                   -je 0x50dd93
    if (cpu.flags.zf)
    {
        goto L_0x0050dd93;
    }
    // 0050dd85  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd88  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dd8b  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd8e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd90  7414                   -je 0x50dda6
    if (cpu.flags.zf)
    {
        goto L_0x0050dda6;
    }
    // 0050dd92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd93:
    // 0050dd93  baf0db5000             -mov edx, 0x50dbf0
    cpu.edx = 5299184 /*0x50dbf0*/;
    // 0050dd98  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd9b  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dd9e  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dda1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dda3  7401                   -je 0x50dda6
    if (cpu.flags.zf)
    {
        goto L_0x0050dda6;
    }
    // 0050dda5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dda6:
    // 0050dda6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dda7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050dda8  bbf4fb5400             -mov ebx, 0x54fbf4
    cpu.ebx = 5569524 /*0x54fbf4*/;
    // 0050ddad  b9b8fb5400             -mov ecx, 0x54fbb8
    cpu.ecx = 5569464 /*0x54fbb8*/;
    // 0050ddb2  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ddb3  bec7000000             -mov esi, 0xc7
    cpu.esi = 199 /*0xc7*/;
    // 0050ddb8  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050ddbe  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050ddc3  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050ddc9  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050ddcf  e83c32efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ddd4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050ddd7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ddd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dde0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dde1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050dde3  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dde7  740f                   -je 0x50ddf8
    if (cpu.flags.zf)
    {
        goto L_0x0050ddf8;
    }
    // 0050dde9  f6420402               +test byte ptr [edx + 4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) & 2 /*0x2*/));
    // 0050dded  754e                   -jne 0x50de3d
    if (!cpu.flags.zf)
    {
        goto L_0x0050de3d;
    }
    // 0050ddef  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050ddf6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ddf7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ddf8:
    // 0050ddf8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ddf9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ddfa  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ddfb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ddfc  be00fc5400             -mov esi, 0x54fc00
    cpu.esi = 5569536 /*0x54fc00*/;
    // 0050de01  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050de06  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de07  bff0000000             -mov edi, 0xf0
    cpu.edi = 240 /*0xf0*/;
    // 0050de0c  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050de12  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050de17  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050de1d  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050de23  e8e831efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050de28  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050de2b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2e  f6420402               +test byte ptr [edx + 4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) & 2 /*0x2*/));
    // 0050de32  7509                   -jne 0x50de3d
    if (!cpu.flags.zf)
    {
        goto L_0x0050de3d;
    }
    // 0050de34  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050de3b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050de3d:
    // 0050de3d  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0050de40  e81bd5fdff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0050de45  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050de4c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50de50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050de50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050de51  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050de52  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de53  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050de54  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050de56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050de58  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050de5b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050de5c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050de62  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050de66  742c                   -je 0x50de94
    if (cpu.flags.zf)
    {
        goto L_0x0050de94;
    }
L_0x0050de68:
    // 0050de68  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050de6a  7419                   -je 0x50de85
    if (cpu.flags.zf)
    {
        goto L_0x0050de85;
    }
    // 0050de6c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050de6f  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050de71  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050de73  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050de76  42                     -inc edx
    (cpu.edx)++;
    // 0050de77  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050de79  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050de7c  7503                   -jne 0x50de81
    if (!cpu.flags.zf)
    {
        goto L_0x0050de81;
    }
    // 0050de7e  89730c                 -mov dword ptr [ebx + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0050de81:
    // 0050de81  804b0401               -or byte ptr [ebx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0050de85:
    // 0050de85  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050de88  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de89  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050de8f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de90  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de91  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de92  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050de94:
    // 0050de94  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050de95  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050de96  bd08fc5400             -mov ebp, 0x54fc08
    cpu.ebp = 5569544 /*0x54fc08*/;
    // 0050de9b  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050dea0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dea1  b828010000             -mov eax, 0x128
    cpu.eax = 296 /*0x128*/;
    // 0050dea6  893d90215500           -mov dword ptr [0x552190], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050deac  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050deb1  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050deb7  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050debc  e84f31efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dec1  83c40c                 +add esp, 0xc
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
    // 0050dec4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dec5  eba1                   -jmp 0x50de68
    goto L_0x0050de68;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50ded0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ded0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ded1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ded2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ded3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ded4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ded6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ded8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dedb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dedc  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050dee2  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dee6  742f                   -je 0x50df17
    if (cpu.flags.zf)
    {
        goto L_0x0050df17;
    }
L_0x0050dee8:
    // 0050dee8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050deea  741c                   -je 0x50df08
    if (cpu.flags.zf)
    {
        goto L_0x0050df08;
    }
    // 0050deec  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050deef  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0050def5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050def7  89730c                 -mov dword ptr [ebx + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050defa  42                     -inc edx
    (cpu.edx)++;
    // 0050defb  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050defd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050deff  7549                   -jne 0x50df4a
    if (!cpu.flags.zf)
    {
        goto L_0x0050df4a;
    }
    // 0050df01  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050df04  804b0401               -or byte ptr [ebx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0050df08:
    // 0050df08  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df0b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df0c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df12  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df13  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df14  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df15  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050df17:
    // 0050df17  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050df18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050df19  bd10fc5400             -mov ebp, 0x54fc10
    cpu.ebp = 5569552 /*0x54fc10*/;
    // 0050df1e  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050df23  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050df24  b83c010000             -mov eax, 0x13c
    cpu.eax = 316 /*0x13c*/;
    // 0050df29  893d90215500           -mov dword ptr [0x552190], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050df2f  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050df34  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050df3a  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050df3f  e8cc30efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050df44  83c40c                 +add esp, 0xc
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
    // 0050df47  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df48  eb9e                   -jmp 0x50dee8
    goto L_0x0050dee8;
L_0x0050df4a:
    // 0050df4a  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050df4c  804b0401               -or byte ptr [ebx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050df50  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df53  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df54  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df5a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50df60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050df60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050df61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df62  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050df63  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050df64  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050df65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050df67  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050df6a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050df6b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df71  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050df75  743c                   -je 0x50dfb3
    if (cpu.flags.zf)
    {
        goto L_0x0050dfb3;
    }
L_0x0050df77:
    // 0050df77  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050df7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050df7c  741a                   -je 0x50df98
    if (cpu.flags.zf)
    {
        goto L_0x0050df98;
    }
    // 0050df7e  3b730c                 +cmp esi, dword ptr [ebx + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050df81  7564                   -jne 0x50dfe7
    if (!cpu.flags.zf)
    {
        goto L_0x0050dfe7;
    }
    // 0050df83  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050df8a  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
L_0x0050df8d:
    // 0050df8d  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050df90  ff0b                   -dec dword ptr [ebx]
    (*app->getMemory<x86::reg32>(cpu.ebx))--;
    // 0050df92  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0050df98:
    // 0050df98  8a6304                 -mov ah, byte ptr [ebx + 4]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050df9b  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df9e  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050dfa1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dfa2  886304                 -mov byte ptr [ebx + 4], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050dfa5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050dfab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050dfad  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfaf  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dfb3:
    // 0050dfb3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dfb4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dfb5  bf18fc5400             -mov edi, 0x54fc18
    cpu.edi = 5569560 /*0x54fc18*/;
    // 0050dfba  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050dfbf  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dfc0  bd7b010000             -mov ebp, 0x17b
    cpu.ebp = 379 /*0x17b*/;
    // 0050dfc5  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050dfcb  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050dfd0  893d94215500           -mov dword ptr [0x552194], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0050dfd6  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050dfdc  e82f30efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dfe1  83c40c                 +add esp, 0xc
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
    // 0050dfe4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfe5  eb90                   -jmp 0x50df77
    goto L_0x0050df77;
L_0x0050dfe7:
    // 0050dfe7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0050dfe9  eba2                   -jmp 0x50df8d
    goto L_0x0050df8d;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50dff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dff0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dff1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dff2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dff3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dff4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dff5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dff6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050dff8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dffb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dffc  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e002  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e006  7424                   -je 0x50e02c
    if (cpu.flags.zf)
    {
        goto L_0x0050e02c;
    }
L_0x0050e008:
    // 0050e008  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050e00b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e00d  745b                   -je 0x50e06a
    if (cpu.flags.zf)
    {
        goto L_0x0050e06a;
    }
    // 0050e00f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e011  48                     -dec eax
    (cpu.eax)--;
    // 0050e012  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e015  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0050e017  39d6                   +cmp esi, edx
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
    // 0050e019  746b                   -je 0x50e086
    if (cpu.flags.zf)
    {
        goto L_0x0050e086;
    }
    // 0050e01b  89530c                 -mov dword ptr [ebx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050e01e:
    // 0050e01e  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050e021  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0050e023  39ce                   +cmp esi, ecx
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
    // 0050e025  7437                   -je 0x50e05e
    if (cpu.flags.zf)
    {
        goto L_0x0050e05e;
    }
    // 0050e027  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050e02a  ebf2                   -jmp 0x50e01e
    goto L_0x0050e01e;
L_0x0050e02c:
    // 0050e02c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e02d  bf20fc5400             -mov edi, 0x54fc20
    cpu.edi = 5569568 /*0x54fc20*/;
    // 0050e032  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e037  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e038  bd90010000             -mov ebp, 0x190
    cpu.ebp = 400 /*0x190*/;
    // 0050e03d  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e043  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e048  893d94215500           -mov dword ptr [0x552194], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0050e04e  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050e054  e8b72fefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e059  83c40c                 +add esp, 0xc
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
    // 0050e05c  ebaa                   -jmp 0x50e008
    goto L_0x0050e008;
L_0x0050e05e:
    // 0050e05e  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0050e064:
    // 0050e064  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0050e06a:
    // 0050e06a  8a6304                 -mov ah, byte ptr [ebx + 4]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050e06d  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e070  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0050e073  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e074  886304                 -mov byte ptr [ebx + 4], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050e077  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e07d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e07f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e080  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e081  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e082  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e083  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e084  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e085  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e086:
    // 0050e086  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050e08d  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e090  89430c                 -mov dword ptr [ebx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050e093  ebcf                   -jmp 0x50e064
    goto L_0x0050e064;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e0a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e0a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e0a2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e0a3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e0a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e0a6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050e0a8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e0ab  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e0ac  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0b2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050e0b4  750f                   -jne 0x50e0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0050e0c5;
    }
    // 0050e0b6  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e0b9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e0ba  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0c0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e0c5:
    // 0050e0c5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e0c6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050e0c8  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e0cb  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0ce  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e0d1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e0d3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e0d5  752f                   -jne 0x50e106
    if (!cpu.flags.zf)
    {
        goto L_0x0050e106;
    }
    // 0050e0d7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e0d8  b82cfc5400             -mov eax, 0x54fc2c
    cpu.eax = 5569580 /*0x54fc2c*/;
    // 0050e0dd  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e0e2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e0e3  bad8010000             -mov edx, 0x1d8
    cpu.edx = 472 /*0x1d8*/;
    // 0050e0e8  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e0ee  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e0f3  a394215500             -mov dword ptr [0x552194], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e0f8  891598215500           -mov dword ptr [0x552198], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e0fe  e80d2fefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e103  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0050e106:
    // 0050e106  ff03                   -inc dword ptr [ebx]
    (*app->getMemory<x86::reg32>(cpu.ebx))++;
    // 0050e108  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e10b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050e10d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e10f  7414                   -je 0x50e125
    if (cpu.flags.zf)
    {
        goto L_0x0050e125;
    }
L_0x0050e111:
    // 0050e111  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050e113  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e116  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e119  39f8                   +cmp eax, edi
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
    // 0050e11b  7308                   -jae 0x50e125
    if (!cpu.flags.cf)
    {
        goto L_0x0050e125;
    }
    // 0050e11d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0050e11f  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0050e121  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e123  75ec                   -jne 0x50e111
    if (!cpu.flags.zf)
    {
        goto L_0x0050e111;
    }
L_0x0050e125:
    // 0050e125  894d00                 -mov dword ptr [ebp], ecx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0050e128  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e12a  751e                   -jne 0x50e14a
    if (!cpu.flags.zf)
    {
        goto L_0x0050e14a;
    }
    // 0050e12c  896b08                 -mov dword ptr [ebx + 8], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0050e12f:
    // 0050e12f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e131  7503                   -jne 0x50e136
    if (!cpu.flags.zf)
    {
        goto L_0x0050e136;
    }
    // 0050e133  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x0050e136:
    // 0050e136  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0050e13a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e13b  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e13e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e13f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e145  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e146  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e147  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e148  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e149  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e14a:
    // 0050e14a  892e                   -mov dword ptr [esi], ebp
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0050e14c  ebe1                   -jmp 0x50e12f
    goto L_0x0050e12f;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50e150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e150  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e151  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e152  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e153  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e154  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e155  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e157  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050e159  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e15c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e15d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e163  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e167  7416                   -je 0x50e17f
    if (cpu.flags.zf)
    {
        goto L_0x0050e17f;
    }
L_0x0050e169:
    // 0050e169  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e16b  7543                   -jne 0x50e1b0
    if (!cpu.flags.zf)
    {
        goto L_0x0050e1b0;
    }
    // 0050e16d  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e170  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e171  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e177  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e179  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e17f:
    // 0050e17f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e180  b834fc5400             -mov eax, 0x54fc34
    cpu.eax = 5569588 /*0x54fc34*/;
    // 0050e185  bdb8fb5400             -mov ebp, 0x54fbb8
    cpu.ebp = 5569464 /*0x54fbb8*/;
    // 0050e18a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e18b  ba1c020000             -mov edx, 0x21c
    cpu.edx = 540 /*0x21c*/;
    // 0050e190  892d90215500           -mov dword ptr [0x552190], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0050e196  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e19b  a394215500             -mov dword ptr [0x552194], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e1a0  891598215500           -mov dword ptr [0x552198], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e1a6  e8652eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e1ab  83c40c                 +add esp, 0xc
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
    // 0050e1ae  ebb9                   -jmp 0x50e169
    goto L_0x0050e169;
L_0x0050e1b0:
    // 0050e1b0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050e1b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e1b4  e867faffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e1b9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e1bb  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e1be  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e1bf  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e1c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e1c7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1c8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1c9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1ca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1cb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50e1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e1d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e1d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050e1d3  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e1d7  7404                   -je 0x50e1dd
    if (cpu.flags.zf)
    {
        goto L_0x0050e1dd;
    }
    // 0050e1d9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050e1db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e1dd:
    // 0050e1dd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e1de  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e1df  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e1e0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e1e1  be3cfc5400             -mov esi, 0x54fc3c
    cpu.esi = 5569596 /*0x54fc3c*/;
    // 0050e1e6  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e1eb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e1ec  bf45020000             -mov edi, 0x245
    cpu.edi = 581 /*0x245*/;
    // 0050e1f1  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e1f7  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e1fc  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050e202  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050e208  e8032eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e20d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050e210  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e211  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e212  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e213  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0050e215  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e216  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e220  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e221  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e222  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e223  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e224  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e225  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e228  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e22a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050e22c  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e22f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e230  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e236  8b4f18                 -mov ecx, dword ptr [edi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050e239  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e23b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e23d  744d                   -je 0x50e28c
    if (cpu.flags.zf)
    {
        goto L_0x0050e28c;
    }
L_0x0050e23f:
    // 0050e23f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050e241  742f                   -je 0x50e272
    if (cpu.flags.zf)
    {
        goto L_0x0050e272;
    }
    // 0050e243  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050e246  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050e249  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e24b  0f856c000000           -jne 0x50e2bd
    if (!cpu.flags.zf)
    {
        goto L_0x0050e2bd;
    }
    // 0050e251  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050e253:
    // 0050e253  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050e256  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e258  7414                   -je 0x50e26e
    if (cpu.flags.zf)
    {
        goto L_0x0050e26e;
    }
L_0x0050e25a:
    // 0050e25a  39e9                   +cmp ecx, ebp
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
    // 0050e25c  7410                   -je 0x50e26e
    if (cpu.flags.zf)
    {
        goto L_0x0050e26e;
    }
    // 0050e25e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e260  7464                   -je 0x50e2c6
    if (cpu.flags.zf)
    {
        goto L_0x0050e2c6;
    }
    // 0050e262  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050e264  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050e267  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e269  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e26c  7658                   -jbe 0x50e2c6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050e2c6;
    }
L_0x0050e26e:
    // 0050e26e  39e9                   +cmp ecx, ebp
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
    // 0050e270  7405                   -je 0x50e277
    if (cpu.flags.zf)
    {
        goto L_0x0050e277;
    }
L_0x0050e272:
    // 0050e272  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0050e277:
    // 0050e277  8b4f18                 -mov ecx, dword ptr [edi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050e27a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e27b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e281  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e283  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e286  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e287  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e288  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e289  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e28a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e28b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e28c:
    // 0050e28c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e28d  b844fc5400             -mov eax, 0x54fc44
    cpu.eax = 5569604 /*0x54fc44*/;
    // 0050e292  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e297  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e298  ba71020000             -mov edx, 0x271
    cpu.edx = 625 /*0x271*/;
    // 0050e29d  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e2a3  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e2a8  a394215500             -mov dword ptr [0x552194], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e2ad  891598215500           -mov dword ptr [0x552198], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e2b3  e8582defff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e2b8  83c40c                 +add esp, 0xc
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
    // 0050e2bb  eb82                   -jmp 0x50e23f
    goto L_0x0050e23f;
L_0x0050e2bd:
    // 0050e2bd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050e2bf  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050e2c2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2c4  eb8d                   -jmp 0x50e253
    goto L_0x0050e253;
L_0x0050e2c6:
    // 0050e2c6  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0050e2c8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050e2c9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e2cb  758d                   -jne 0x50e25a
    if (!cpu.flags.zf)
    {
        goto L_0x0050e25a;
    }
    // 0050e2cd  eb9f                   -jmp 0x50e26e
    goto L_0x0050e26e;
}

/* align: skip 0x90 */
void Application::sub_50e2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e2d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e2d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e2d2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e2d3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e2d4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e2d5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e2d7  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e2da  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e2db  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2e1  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e2e4  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0050e2e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e2eb  7418                   -je 0x50e305
    if (cpu.flags.zf)
    {
        goto L_0x0050e305;
    }
L_0x0050e2ed:
    // 0050e2ed  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e2f1  7545                   -jne 0x50e338
    if (!cpu.flags.zf)
    {
        goto L_0x0050e338;
    }
    // 0050e2f3  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e2f6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e2f7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e2ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e300  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e301  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e302  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e303  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e304  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e305:
    // 0050e305  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e306  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e307  bd50fc5400             -mov ebp, 0x54fc50
    cpu.ebp = 5569616 /*0x54fc50*/;
    // 0050e30c  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e311  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e312  b8b9020000             -mov eax, 0x2b9
    cpu.eax = 697 /*0x2b9*/;
    // 0050e317  893d90215500           -mov dword ptr [0x552190], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e31d  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e322  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e328  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e32d  e8de2cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e332  83c40c                 +add esp, 0xc
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
    // 0050e335  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e336  ebb5                   -jmp 0x50e2ed
    goto L_0x0050e2ed;
L_0x0050e338:
    // 0050e338  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e33b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e33e  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e341  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e343  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e346  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e347  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e34d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e34f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e350  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e351  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e352  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e353  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e360  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e361  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e362  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e363  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e364  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e365  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e367  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e36a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e36b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e371  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e374  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0050e379  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e37b  7418                   -je 0x50e395
    if (cpu.flags.zf)
    {
        goto L_0x0050e395;
    }
L_0x0050e37d:
    // 0050e37d  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e381  7545                   -jne 0x50e3c8
    if (!cpu.flags.zf)
    {
        goto L_0x0050e3c8;
    }
    // 0050e383  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e386  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e387  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e38d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e38f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e390  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e391  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e392  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e393  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e394  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e395:
    // 0050e395  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e396  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e397  bd60fc5400             -mov ebp, 0x54fc60
    cpu.ebp = 5569632 /*0x54fc60*/;
    // 0050e39c  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e3a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e3a2  b8c4020000             -mov eax, 0x2c4
    cpu.eax = 708 /*0x2c4*/;
    // 0050e3a7  893d90215500           -mov dword ptr [0x552190], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e3ad  68ccfb5400             -push 0x54fbcc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e3b2  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e3b8  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e3bd  e84e2cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e3c2  83c40c                 +add esp, 0xc
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
    // 0050e3c5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3c6  ebb5                   -jmp 0x50e37d
    goto L_0x0050e37d;
L_0x0050e3c8:
    // 0050e3c8  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e3cb  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e3ce  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e3d1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e3d3  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e3d6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e3d7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e3dd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e3df  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
