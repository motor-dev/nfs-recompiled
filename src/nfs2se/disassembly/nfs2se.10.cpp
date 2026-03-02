#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45bc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bc20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045bc21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045bc22  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045bc23  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045bc24  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045bc25  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045bc26  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045bc29  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045bc2b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045bc2d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045bc32  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp);
    // 0045bc35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045bc37  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0045bc3a  39d1                   +cmp ecx, edx
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
    // 0045bc3c  7e2b                   -jle 0x45bc69
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bc69;
    }
L_0x0045bc3e:
    // 0045bc3e  8d342a                 -lea esi, [edx + ebp]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0045bc41  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045bc43  80f9ff                 +cmp cl, 0xff
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
    // 0045bc46  7530                   -jne 0x45bc78
    if (!cpu.flags.zf)
    {
        goto L_0x0045bc78;
    }
    // 0045bc48  0fb67e01               -movzx edi, byte ptr [esi + 1]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0045bc4c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045bc4e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045bc50  7e0f                   -jle 0x45bc61
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bc61;
    }
L_0x0045bc52:
    // 0045bc52  40                     -inc eax
    (cpu.eax)++;
    // 0045bc53  8a5e02                 -mov bl, byte ptr [esi + 2]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0045bc56  41                     -inc ecx
    (cpu.ecx)++;
    // 0045bc57  88988fe94d00           -mov byte ptr [eax + 0x4de98f], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5106063) /* 0x4de98f */) = cpu.bl;
    // 0045bc5d  39f9                   +cmp ecx, edi
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
    // 0045bc5f  7cf1                   -jl 0x45bc52
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bc52;
    }
L_0x0045bc61:
    // 0045bc61  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0045bc64:
    // 0045bc64  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bc67  7cd5                   -jl 0x45bc3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bc3e;
    }
L_0x0045bc69:
    // 0045bc69  b890e94d00             -mov eax, 0x4de990
    cpu.eax = 5106064 /*0x4de990*/;
    // 0045bc6e  83c404                 +add esp, 4
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
    // 0045bc71  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc72  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc73  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc74  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc75  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc76  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bc77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045bc78:
    // 0045bc78  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045bc79  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045bc7a  88888fe94d00           -mov byte ptr [eax + 0x4de98f], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5106063) /* 0x4de98f */) = cpu.cl;
    // 0045bc80  ebe2                   -jmp 0x45bc64
    goto L_0x0045bc64;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45bc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bc90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045bc91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045bc92  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045bc93  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045bc94  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045bc95  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045bc97  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045bc9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045bc9e:
    // 0045bc9e  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0045bca1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045bca3  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi);
L_0x0045bca5:
    // 0045bca5  41                     -inc ecx
    (cpu.ecx)++;
    // 0045bca6  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045bca9  46                     -inc esi
    (cpu.esi)++;
    // 0045bcaa  42                     -inc edx
    (cpu.edx)++;
    // 0045bcab  38df                   +cmp bh, bl
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045bcad  7505                   -jne 0x45bcb4
    if (!cpu.flags.zf)
    {
        goto L_0x0045bcb4;
    }
    // 0045bcaf  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bcb2  7cf1                   -jl 0x45bca5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bca5;
    }
L_0x0045bcb4:
    // 0045bcb4  83fa03                 +cmp edx, 3
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
    // 0045bcb7  7c34                   -jl 0x45bced
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bced;
    }
    // 0045bcb9  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0045bcbc  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 0045bcbe  8898d7d34f00           -mov byte ptr [eax + 0x4fd3d7], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5231575) /* 0x4fd3d7 */) = cpu.bl;
    // 0045bcc4  8890d6d34f00           -mov byte ptr [eax + 0x4fd3d6], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5231574) /* 0x4fd3d6 */) = cpu.dl;
    // 0045bcca  88b0d5d34f00           -mov byte ptr [eax + 0x4fd3d5], dh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5231573) /* 0x4fd3d5 */) = cpu.dh;
L_0x0045bcd0:
    // 0045bcd0  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bcd3  7cc9                   -jl 0x45bc9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bc9e;
    }
    // 0045bcd5  a2d8d34f00             -mov byte ptr [0x4fd3d8], al
    *app->getMemory<x86::reg8>(x86::reg32(5231576) /* 0x4fd3d8 */) = cpu.al;
    // 0045bcda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0045bcdc  8898d8d34f00           -mov byte ptr [eax + 0x4fd3d8], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5231576) /* 0x4fd3d8 */) = cpu.bl;
    // 0045bce2  b8d8d34f00             -mov eax, 0x4fd3d8
    cpu.eax = 5231576 /*0x4fd3d8*/;
    // 0045bce7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bce8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bce9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bcea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bceb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045bcec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045bced:
    // 0045bced  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045bcef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045bcf1  7edd                   -jle 0x45bcd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bcd0;
    }
L_0x0045bcf3:
    // 0045bcf3  40                     -inc eax
    (cpu.eax)++;
    // 0045bcf4  46                     -inc esi
    (cpu.esi)++;
    // 0045bcf5  8898d7d34f00           -mov byte ptr [eax + 0x4fd3d7], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5231575) /* 0x4fd3d7 */) = cpu.bl;
    // 0045bcfb  39d6                   +cmp esi, edx
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
    // 0045bcfd  7cf4                   -jl 0x45bcf3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045bcf3;
    }
    // 0045bcff  ebcf                   -jmp 0x45bcd0
    goto L_0x0045bcd0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45bd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045bd10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045bd11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045bd12  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045bd13  81eca4020000           -sub esp, 0x2a4
    (cpu.esp) -= x86::reg32(x86::sreg32(676 /*0x2a4*/));
    // 0045bd19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045bd1b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045bd1d  8b8424b4020000         -mov eax, dword ptr [esp + 0x2b4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */);
    // 0045bd24  89842484020000         -mov dword ptr [esp + 0x284], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 0045bd2b  8b8424b8020000         -mov eax, dword ptr [esp + 0x2b8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */);
    // 0045bd32  89942490020000         -mov dword ptr [esp + 0x290], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(656) /* 0x290 */) = cpu.edx;
    // 0045bd39  89842498020000         -mov dword ptr [esp + 0x298], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */) = cpu.eax;
    // 0045bd40  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0045bd47  899c2480020000         -mov dword ptr [esp + 0x280], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */) = cpu.ebx;
    // 0045bd4e  89842488020000         -mov dword ptr [esp + 0x288], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(648) /* 0x288 */) = cpu.eax;
    // 0045bd55  8b8424c0020000         -mov eax, dword ptr [esp + 0x2c0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045bd5c  898c2494020000         -mov dword ptr [esp + 0x294], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */) = cpu.ecx;
    // 0045bd63  8984249c020000         -mov dword ptr [esp + 0x29c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */) = cpu.eax;
    // 0045bd6a  8b8424c4020000         -mov eax, dword ptr [esp + 0x2c4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(708) /* 0x2c4 */);
    // 0045bd71  8d8c2440010000         -lea ecx, [esp + 0x140]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 0045bd78  8984248c020000         -mov dword ptr [esp + 0x28c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(652) /* 0x28c */) = cpu.eax;
    // 0045bd7f  8d8424a0020000         -lea eax, [esp + 0x2a0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(672) /* 0x2a0 */);
    // 0045bd86  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0045bd8b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045bd8c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045bd90  8d942484020000         -lea edx, [esp + 0x284]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 0045bd97  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045bd98  8d842498020000         -lea eax, [esp + 0x298]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0045bd9f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045bda1  e87a000000             -call 0x45be20
    cpu.esp -= 4;
    sub_45be20(app, cpu);
    if (cpu.terminate) return;
    // 0045bda6  8b9424c0020000         -mov edx, dword ptr [esp + 0x2c0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045bdad  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0045bdaf  39d5                   +cmp ebp, edx
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
    // 0045bdb1  7f5f                   -jg 0x45be12
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045be12;
    }
    // 0045bdb3  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0045bdb6  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045bdb8  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0045bdba  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0045bdbc:
    // 0045bdbc  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0045bdc3:
    // 0045bdc3  3b9c0c44010000         +cmp ebx, dword ptr [esp + ecx + 0x144]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */ + cpu.ecx * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045bdca  7e06                   -jle 0x45bdd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bdd2;
    }
    // 0045bdcc  46                     -inc esi
    (cpu.esi)++;
    // 0045bdcd  83c104                 +add ecx, 4
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
    // 0045bdd0  ebf1                   -jmp 0x45bdc3
    goto L_0x0045bdc3;
L_0x0045bdd2:
    // 0045bdd2  8b440c04               -mov eax, dword ptr [esp + ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 0045bdd6  8b2c0c                 -mov ebp, dword ptr [esp + ecx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1);
    // 0045bdd9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045bddb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045bddd  8bac0c40010000         -mov ebp, dword ptr [esp + ecx + 0x140]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */ + cpu.ecx * 1);
    // 0045bde4  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045bde6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045bde9  8b840c44010000         -mov eax, dword ptr [esp + ecx + 0x144]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */ + cpu.ecx * 1);
    // 0045bdf0  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045bdf2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045bdf4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045bdf6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045bdf9  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045bdfb  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045bdfe  8b140c                 -mov edx, dword ptr [esp + ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1);
    // 0045be01  43                     -inc ebx
    (cpu.ebx)++;
    // 0045be02  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045be04  8b8c24c0020000         -mov ecx, dword ptr [esp + 0x2c0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0045be0b  8947fc                 -mov dword ptr [edi - 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045be0e  39cb                   +cmp ebx, ecx
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
    // 0045be10  7eaa                   -jle 0x45bdbc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045bdbc;
    }
L_0x0045be12:
    // 0045be12  81c4a4020000           -add esp, 0x2a4
    (cpu.esp) += x86::reg32(x86::sreg32(676 /*0x2a4*/));
    // 0045be18  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be19  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be1a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be1b  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45be20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045be20  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045be21  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045be22  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045be23  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045be26  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045be2a  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045be2e  895c240c               -mov dword ptr [esp + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0045be32  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0045be35  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045be37  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045be39  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045be3b  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045be3f  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045be41  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045be45  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045be4a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045be4c  89542438               -mov dword ptr [esp + 0x38], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0045be50  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0045be54  83fb02                 +cmp ebx, 2
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
    // 0045be57  7f2d                   -jg 0x45be86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045be86;
    }
L_0x0045be59:
    // 0045be59  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045be5d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045be61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045be64  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045be66  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045be6a  3b5afc                 +cmp ebx, dword ptr [edx - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045be6d  0f85fa010000           -jne 0x45c06d
    if (!cpu.flags.zf)
    {
        goto L_0x0045c06d;
    }
    // 0045be73  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0045be77  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045be7b  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045be7d  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045be80  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be81  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be82  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045be83  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0045be86:
    // 0045be86  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0045be8b  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045be8f  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0045be93  39de                   +cmp esi, ebx
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
    // 0045be95  7cc2                   -jl 0x45be59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045be59;
    }
    // 0045be97  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045be9b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045be9e  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045bea2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045bea6  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045bea9  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0045bead:
    // 0045bead  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045beb2  0f8591010000           -jne 0x45c049
    if (!cpu.flags.zf)
    {
        goto L_0x0045c049;
    }
    // 0045beb8  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045bebc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045bec0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0045bec2  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
L_0x0045bec4:
    // 0045bec4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045bec8  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045becc  0f858a010000           -jne 0x45c05c
    if (!cpu.flags.zf)
    {
        goto L_0x0045c05c;
    }
    // 0045bed2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045bed6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045beda  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045bedd  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x0045bee0:
    // 0045bee0  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045bee4  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045bee7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0045beea  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045beed  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bef0  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0045bef3  89442428               -mov dword ptr [esp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0045bef7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045befb  894c2424               -mov dword ptr [esp + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0045beff  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0045bf03  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045bf07  8954241c               -mov dword ptr [esp + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0045bf0b  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0045bf0f  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045bf13  895c2420               -mov dword ptr [esp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0045bf17  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045bf1a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045bf1c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bf1e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045bf20:
    // 0045bf20  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0045bf24  8b819cd44f00           -mov eax, dword ptr [ecx + 0x4fd49c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231772) /* 0x4fd49c */);
    // 0045bf2a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bf2c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf2f  c1e810                 +shr eax, 0x10
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
    // 0045bf32  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bf34  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0045bf38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045bf3a  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045bf3d  8b81ecd44f00           -mov eax, dword ptr [ecx + 0x4fd4ec]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231852) /* 0x4fd4ec */);
    // 0045bf43  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf46  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bf48  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf4b  c1e810                 +shr eax, 0x10
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
    // 0045bf4e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bf50  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0045bf54  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bf56  8b52f8                 -mov edx, dword ptr [edx - 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0045bf59  8b81fcd34f00           -mov eax, dword ptr [ecx + 0x4fd3fc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231612) /* 0x4fd3fc */);
    // 0045bf5f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf62  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bf64  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf67  c1e810                 +shr eax, 0x10
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
    // 0045bf6a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bf6c  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045bf70  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bf72  8b814cd44f00           -mov eax, dword ptr [ecx + 0x4fd44c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231692) /* 0x4fd44c */);
    // 0045bf78  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bf7a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf7d  c1e810                 +shr eax, 0x10
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
    // 0045bf80  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bf82  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045bf86  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bf88  8b819cd44f00           -mov eax, dword ptr [ecx + 0x4fd49c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231772) /* 0x4fd49c */);
    // 0045bf8e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bf90  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bf93  c1e810                 +shr eax, 0x10
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
    // 0045bf96  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bf98  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045bf9c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045bf9e  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045bfa1  8b81ecd44f00           -mov eax, dword ptr [ecx + 0x4fd4ec]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231852) /* 0x4fd4ec */);
    // 0045bfa7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bfaa  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bfac  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bfaf  c1e810                 +shr eax, 0x10
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
    // 0045bfb2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bfb4  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045bfb8  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bfba  8b52f8                 -mov edx, dword ptr [edx - 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0045bfbd  8b81fcd34f00           -mov eax, dword ptr [ecx + 0x4fd3fc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231612) /* 0x4fd3fc */);
    // 0045bfc3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bfc6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bfc8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bfcb  c1e810                 +shr eax, 0x10
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
    // 0045bfce  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bfd0  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045bfd4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045bfd6  8b814cd44f00           -mov eax, dword ptr [ecx + 0x4fd44c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5231692) /* 0x4fd44c */);
    // 0045bfdc  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0045bfdf  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045bfe1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045bfe4  c1e810                 +shr eax, 0x10
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
    // 0045bfe7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045bfe9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045bfeb  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045bfef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045bff2  39eb                   +cmp ebx, ebp
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
    // 0045bff4  7417                   -je 0x45c00d
    if (cpu.flags.zf)
    {
        goto L_0x0045c00d;
    }
    // 0045bff6  891f                   -mov dword ptr [edi], ebx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0045bff8  895c242c               -mov dword ptr [esp + 0x2c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0045bffc  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0045bffe  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045c002  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c005  40                     -inc eax
    (cpu.eax)++;
    // 0045c006  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c009  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
L_0x0045c00d:
    // 0045c00d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c010  83f950                 +cmp ecx, 0x50
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c013  0f8507ffffff           -jne 0x45bf20
    if (!cpu.flags.zf)
    {
        goto L_0x0045bf20;
    }
    // 0045c019  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c01d  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c021  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c025  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c029  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c02c  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c02f  40                     -inc eax
    (cpu.eax)++;
    // 0045c030  897c2414               -mov dword ptr [esp + 0x14], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0045c034  896c2418               -mov dword ptr [esp + 0x18], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0045c038  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045c03c  39d0                   +cmp eax, edx
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
    // 0045c03e  0f8f15feffff           -jg 0x45be59
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045be59;
    }
    // 0045c044  e964feffff             -jmp 0x45bead
    goto L_0x0045bead;
L_0x0045c049:
    // 0045c049  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c04d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c051  8b5bf4                 -mov ebx, dword ptr [ebx - 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-12) /* -0xc */);
    // 0045c054  8b49f4                 -mov ecx, dword ptr [ecx - 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-12) /* -0xc */);
    // 0045c057  e968feffff             -jmp 0x45bec4
    goto L_0x0045bec4;
L_0x0045c05c:
    // 0045c05c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c060  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c064  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c066  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c068  e973feffff             -jmp 0x45bee0
    goto L_0x0045bee0;
L_0x0045c06d:
    // 0045c06d  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045c071  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c074  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c078  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0045c07c  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045c080  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045c083  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0045c086  45                     -inc ebp
    (cpu.ebp)++;
    // 0045c087  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045c089  891419                 -mov dword ptr [ecx + ebx], edx
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1) = cpu.edx;
    // 0045c08c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045c08e  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0045c091  896c2438               -mov dword ptr [esp + 0x38], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 0045c095  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045c097  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0045c09b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0045c09f  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045c0a1  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0045c0a4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c0a5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c0a6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c0a7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c0b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c0b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c0b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c0b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c0b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c0b5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c0b6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c0b9  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045c0be  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0045c0c3  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045c0c4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c0c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c0c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c0ca  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045c0ce  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045c0d1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c0d3  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045c0d6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c0d8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045c0da  bb00000300             -mov ebx, 0x30000
    cpu.ebx = 196608 /*0x30000*/;
    // 0045c0df  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045c0e3  b800000200             -mov eax, 0x20000
    cpu.eax = 131072 /*0x20000*/;
    // 0045c0e8  896c240c               -mov dword ptr [esp + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0045c0ec  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045c0ed  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c0ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c0f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c0f3  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045c0f7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045c0fa  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c0fc  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045c0ff  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c101  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0045c105:
    // 0045c105  bb00001300             -mov ebx, 0x130000
    cpu.ebx = 1245184 /*0x130000*/;
    // 0045c10a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c10e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045c10f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c111  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c113  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c115  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045c119  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045c11c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c11e  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045c121  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c123  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045c128  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045c12a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c12c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045c12e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045c131  c1e810                 +shr eax, 0x10
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
    // 0045c134  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045c136  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045c138  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c13b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045c13d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045c140  c1e810                 +shr eax, 0x10
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
    // 0045c143  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045c145  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045c147  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045c148  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c14a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c14c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c14e  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045c152  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045c155  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c157  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045c15a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c15c  89859cd44f00           -mov dword ptr [ebp + 0x4fd49c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5231772) /* 0x4fd49c */) = cpu.eax;
    // 0045c162  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c165  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0045c167  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045c169  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c16d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045c16f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c171  8985ecd44f00           -mov dword ptr [ebp + 0x4fd4ec], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5231852) /* 0x4fd4ec */) = cpu.eax;
    // 0045c177  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045c179  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c17c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045c17e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c182  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c184  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c186  8985fcd34f00           -mov dword ptr [ebp + 0x4fd3fc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5231612) /* 0x4fd3fc */) = cpu.eax;
    // 0045c18c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045c18e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c191  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0045c193  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0045c198  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c19a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045c19c  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0045c19e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0045c19f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c1a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c1a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c1a5  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0045c1a9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045c1ac  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045c1ae  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0045c1b1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c1b3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c1b7  8b54240e               -mov edx, dword ptr [esp + 0xe]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0045c1bb  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c1bd  42                     -inc edx
    (cpu.edx)++;
    // 0045c1be  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0045c1c1  668954240e             -mov word ptr [esp + 0xe], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0045c1c6  898548d44f00           -mov dword ptr [ebp + 0x4fd448], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5231688) /* 0x4fd448 */) = cpu.eax;
    // 0045c1cc  83fd50                 +cmp ebp, 0x50
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c1cf  0f8530ffffff           -jne 0x45c105
    if (!cpu.flags.zf)
    {
        goto L_0x0045c105;
    }
    // 0045c1d5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c1d8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1d9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1da  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1dc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1dd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c1de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45c1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c1e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c1e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c1e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c1e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045c1e6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c1e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c1ea  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c1ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c1ee  7e21                   -jle 0x45c211
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c211;
    }
L_0x0045c1f0:
    // 0045c1f0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045c1f2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045c1f5  2b4108                 -sub eax, dword ptr [ecx + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0045c1f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c1fa  7e19                   -jle 0x45c215
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c215;
    }
L_0x0045c1fc:
    // 0045c1fc  39c2                   +cmp edx, eax
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
    // 0045c1fe  7e19                   -jle 0x45c219
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c219;
    }
    // 0045c200  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045c203  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c205  39d8                   +cmp eax, ebx
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
    // 0045c207  7d21                   -jge 0x45c22a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c22a;
    }
    // 0045c209  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c20e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c20f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c210  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c211:
    // 0045c211  f7d8                   +neg eax
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
    // 0045c213  ebdb                   -jmp 0x45c1f0
    goto L_0x0045c1f0;
L_0x0045c215:
    // 0045c215  f7d8                   +neg eax
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
    // 0045c217  ebe3                   -jmp 0x45c1fc
    goto L_0x0045c1fc;
L_0x0045c219:
    // 0045c219  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0045c21c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c21e  39d8                   +cmp eax, ebx
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
    // 0045c220  7d08                   -jge 0x45c22a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c22a;
    }
    // 0045c222  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c227  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c228  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c229  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c22a:
    // 0045c22a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c22c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c22d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c22e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45c230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c230  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c231  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c232  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c233  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045c239  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c23b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c23c  b32f                   -mov bl, 0x2f
    cpu.bl = 47 /*0x2f*/;
    // 0045c23e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c240  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045c242:
    // 0045c242  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c244  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 0045c246  e855000000             -call 0x45c2a0
    cpu.esp -= 4;
    sub_45c2a0(app, cpu);
    if (cpu.terminate) return;
    // 0045c24b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0045c24d  7418                   -je 0x45c267
    if (cpu.flags.zf)
    {
        goto L_0x0045c267;
    }
    // 0045c24f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045c250:
    // 0045c250  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c252  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 0045c254  e847000000             -call 0x45c2a0
    cpu.esp -= 4;
    sub_45c2a0(app, cpu);
    if (cpu.terminate) return;
    // 0045c259  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0045c25b  741e                   -je 0x45c27b
    if (cpu.flags.zf)
    {
        goto L_0x0045c27b;
    }
    // 0045c25d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045c25e  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 0045c260  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045c261  88440cff               -mov byte ptr [esp + ecx - 1], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1) = cpu.al;
    // 0045c265  ebe9                   -jmp 0x45c250
    goto L_0x0045c250;
L_0x0045c267:
    // 0045c267  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c269  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax);
    // 0045c26b  42                     -inc edx
    (cpu.edx)++;
    // 0045c26c  38fb                   +cmp bl, bh
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
    // 0045c26e  75d2                   -jne 0x45c242
    if (!cpu.flags.zf)
    {
        goto L_0x0045c242;
    }
L_0x0045c270:
    // 0045c270  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c272  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax);
    // 0045c274  42                     -inc edx
    (cpu.edx)++;
    // 0045c275  38fb                   +cmp bl, bh
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
    // 0045c277  75f7                   -jne 0x45c270
    if (!cpu.flags.zf)
    {
        goto L_0x0045c270;
    }
    // 0045c279  ebc7                   -jmp 0x45c242
    goto L_0x0045c242;
L_0x0045c27b:
    // 0045c27b  88040c                 -mov byte ptr [esp + ecx], al
    *app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1) = cpu.al;
    // 0045c27e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045c280  e8b1f10200             -call 0x48b436
    cpu.esp -= 4;
    sub_48b436(app, cpu);
    if (cpu.terminate) return;
    // 0045c285  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0045c287  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045c28d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c28e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c28f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c290  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c2a0  3c30                   +cmp al, 0x30
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
    // 0045c2a2  7204                   -jb 0x45c2a8
    if (cpu.flags.cf)
    {
        goto L_0x0045c2a8;
    }
    // 0045c2a4  3c39                   +cmp al, 0x39
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
    // 0045c2a6  7608                   -jbe 0x45c2b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045c2b0;
    }
L_0x0045c2a8:
    // 0045c2a8  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045c2aa  7404                   -je 0x45c2b0
    if (cpu.flags.zf)
    {
        goto L_0x0045c2b0;
    }
    // 0045c2ac  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045c2ae  7503                   -jne 0x45c2b3
    if (!cpu.flags.zf)
    {
        goto L_0x0045c2b3;
    }
L_0x0045c2b0:
    // 0045c2b0  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0045c2b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c2b3:
    // 0045c2b3  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0045c2b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c2c0  a13cd54f00             -mov eax, dword ptr [0x4fd53c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c2c5  e802c80100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0045c2ca  a140d54f00             -mov eax, dword ptr [0x4fd540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c2cf  e9f8c70100             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c2e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c2e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c2e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c2e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c2e4  ba10b14b00             -mov edx, 0x4bb110
    cpu.edx = 4960528 /*0x4bb110*/;
    // 0045c2e9  b9d0000000             -mov ecx, 0xd0
    cpu.ecx = 208 /*0xd0*/;
    // 0045c2ee  b830b14b00             -mov eax, 0x4bb130
    cpu.eax = 4960560 /*0x4bb130*/;
    // 0045c2f3  bed1000000             -mov esi, 0xd1
    cpu.esi = 209 /*0xd1*/;
    // 0045c2f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c2fa  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0045c300  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045c305  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0045c30b  e858c30100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0045c310  bb10b14b00             -mov ebx, 0x4bb110
    cpu.ebx = 4960528 /*0x4bb110*/;
    // 0045c315  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045c31a  a33cd54f00             -mov dword ptr [0x4fd53c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */) = cpu.eax;
    // 0045c31f  b848b14b00             -mov eax, 0x4bb148
    cpu.eax = 4960584 /*0x4bb148*/;
    // 0045c324  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 0045c32a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c32c  893590844c00           -mov dword ptr [0x4c8490], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 0045c332  e831c30100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0045c337  a340d54f00             -mov dword ptr [0x4fd540], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */) = cpu.eax;
    // 0045c33c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c33d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c33e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c33f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c340  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c350  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c351  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c352  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c353  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c354  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c355  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c358  8b2d3cd54f00           -mov ebp, dword ptr [0x4fd53c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c35e  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0045c362  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c364  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c366  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045c368:
    // 0045c368  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045c36a  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 0045c36e  752c                   -jne 0x45c39c
    if (!cpu.flags.zf)
    {
        goto L_0x0045c39c;
    }
L_0x0045c370:
    // 0045c370  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c373  3d60130000             +cmp eax, 0x1360
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4960 /*0x1360*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c378  75ee                   -jne 0x45c368
    if (!cpu.flags.zf)
    {
        goto L_0x0045c368;
    }
    // 0045c37a  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c37e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0045c380  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045c384  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045c387  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c388  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c389  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c38d  892d3cd54f00           -mov dword ptr [0x4fd53c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */) = cpu.ebp;
    // 0045c393  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045c396  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c397  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c398  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c399  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c39a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c39b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c39c:
    // 0045c39c  8b1540d54f00           -mov edx, dword ptr [0x4fd540]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c3a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045c3a4  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c3a6  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0045c3a8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c3aa  7502                   -jne 0x45c3ae
    if (!cpu.flags.zf)
    {
        goto L_0x0045c3ae;
    }
    // 0045c3ac  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
L_0x0045c3ae:
    // 0045c3ae  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0045c3b0  8b1c02                 -mov ebx, dword ptr [edx + eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 0045c3b3  ebbb                   -jmp 0x45c370
    goto L_0x0045c370;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c3c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c3c1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c3c2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c3c3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c3c6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c3ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045c3cc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045c3ce  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0045c3d2  81ef00000a00           -sub edi, 0xa0000
    (cpu.edi) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045c3d8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c3da  7442                   -je 0x45c41e
    if (cpu.flags.zf)
    {
        goto L_0x0045c41e;
    }
    // 0045c3dc  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c3de  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045c3e0  0f8eb2000000           -jle 0x45c498
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c498;
    }
    // 0045c3e6  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0045c3e8:
    // 0045c3e8  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c3eb  7e31                   -jle 0x45c41e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c41e;
    }
    // 0045c3ed  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0045c3ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c3f1  0f8eaa000000           -jle 0x45c4a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c4a1;
    }
L_0x0045c3f7:
    // 0045c3f7  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c3fa  7e22                   -jle 0x45c41e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c41e;
    }
    // 0045c3fc  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0045c3fe  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c400  0f8ea2000000           -jle 0x45c4a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c4a8;
    }
L_0x0045c406:
    // 0045c406  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c409  7e13                   -jle 0x45c41e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c41e;
    }
    // 0045c40b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c40d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c40f  0f8e9a000000           -jle 0x45c4af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c4af;
    }
L_0x0045c415:
    // 0045c415  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c418  0f8fad000000           -jg 0x45c4cb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c4cb;
    }
L_0x0045c41e:
    // 0045c41e  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0045c421  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c424  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045c427  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c429  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045c42c  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c42f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c432  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045c435  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c438  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c43a  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045c43d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045c43f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c442  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045c445  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c447  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045c44a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c44d  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045c450  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045c452  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0045c454  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c456  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045c459  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0045c45b  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045c45e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c460  7c69                   -jl 0x45c4cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c4cb;
    }
    // 0045c462  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c467  7f62                   -jg 0x45c4cb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c4cb;
    }
    // 0045c469  8b153cd54f00           -mov edx, dword ptr [0x4fd53c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c46f  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0045c476  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c478  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c47a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c47c  7438                   -je 0x45c4b6
    if (cpu.flags.zf)
    {
        goto L_0x0045c4b6;
    }
    // 0045c47e  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c482  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045c484  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c488  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0045c48a:
    // 0045c48a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c48f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c492  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c493  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c494  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c495  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0045c498:
    // 0045c498  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045c49a  f7d9                   +neg ecx
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
    // 0045c49c  e947ffffff             -jmp 0x45c3e8
    goto L_0x0045c3e8;
L_0x0045c4a1:
    // 0045c4a1  f7d9                   +neg ecx
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
    // 0045c4a3  e94fffffff             -jmp 0x45c3f7
    goto L_0x0045c3f7;
L_0x0045c4a8:
    // 0045c4a8  f7d9                   +neg ecx
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
    // 0045c4aa  e957ffffff             -jmp 0x45c406
    goto L_0x0045c406;
L_0x0045c4af:
    // 0045c4af  f7d9                   +neg ecx
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
    // 0045c4b1  e95fffffff             -jmp 0x45c415
    goto L_0x0045c415;
L_0x0045c4b6:
    // 0045c4b6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c4ba  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045c4bc  a140d54f00             -mov eax, dword ptr [0x4fd540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c4c1  01c1                   +add ecx, eax
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
    // 0045c4c3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045c4c7  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0045c4c9  ebbf                   -jmp 0x45c48a
    goto L_0x0045c48a;
L_0x0045c4cb:
    // 0045c4cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c4cd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c4d0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4d1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4d2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c4d3  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c4e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c4e1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c4e2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c4e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c4e6  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045c4ea  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0045c4ec  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c4f0  81e900000a00           -sub ecx, 0xa0000
    (cpu.ecx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045c4f6  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c4f8  894c2414               -mov dword ptr [esp + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0045c4fc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045c4fe  0f8ead000000           -jle 0x45c5b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c5b1;
    }
    // 0045c504  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0045c506:
    // 0045c506  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c509  7e31                   -jle 0x45c53c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c53c;
    }
    // 0045c50b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c50d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c50f  0f8ea5000000           -jle 0x45c5ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c5ba;
    }
L_0x0045c515:
    // 0045c515  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c518  7e22                   -jle 0x45c53c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c53c;
    }
    // 0045c51a  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0045c51c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c51e  0f8e9d000000           -jle 0x45c5c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c5c1;
    }
L_0x0045c524:
    // 0045c524  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c527  7e13                   -jle 0x45c53c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c53c;
    }
    // 0045c529  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0045c52b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c52d  0f8e95000000           -jle 0x45c5c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c5c8;
    }
L_0x0045c533:
    // 0045c533  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c536  0f8fa1000000           -jg 0x45c5dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c5dd;
    }
L_0x0045c53c:
    // 0045c53c  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0045c53f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c542  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045c545  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c547  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045c54a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c54d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c550  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045c553  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c556  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c558  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045c55b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045c55d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c560  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045c563  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c565  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045c568  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045c56a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c56d  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045c570  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0045c572  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c574  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c578  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0045c57b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c57d  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045c580  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c582  7c59                   -jl 0x45c5dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c5dd;
    }
    // 0045c584  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c589  7f52                   -jg 0x45c5dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c5dd;
    }
    // 0045c58b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045c592  a13cd54f00             -mov eax, dword ptr [0x4fd53c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c597  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045c599  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c59b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c59d  7430                   -je 0x45c5cf
    if (cpu.flags.zf)
    {
        goto L_0x0045c5cf;
    }
    // 0045c59f  890f                   -mov dword ptr [edi], ecx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0045c5a1  8938                   -mov dword ptr [eax], edi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0045c5a3:
    // 0045c5a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045c5a8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c5ab  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5ac  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5ad  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5ae  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0045c5b1:
    // 0045c5b1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045c5b3  f7d9                   +neg ecx
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
    // 0045c5b5  e94cffffff             -jmp 0x45c506
    goto L_0x0045c506;
L_0x0045c5ba:
    // 0045c5ba  f7d9                   +neg ecx
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
    // 0045c5bc  e954ffffff             -jmp 0x45c515
    goto L_0x0045c515;
L_0x0045c5c1:
    // 0045c5c1  f7d9                   +neg ecx
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
    // 0045c5c3  e95cffffff             -jmp 0x45c524
    goto L_0x0045c524;
L_0x0045c5c8:
    // 0045c5c8  f7d9                   +neg ecx
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
    // 0045c5ca  e964ffffff             -jmp 0x45c533
    goto L_0x0045c533;
L_0x0045c5cf:
    // 0045c5cf  890f                   -mov dword ptr [edi], ecx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0045c5d1  8938                   -mov dword ptr [eax], edi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0045c5d3  a140d54f00             -mov eax, dword ptr [0x4fd540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c5d8  893c02                 -mov dword ptr [edx + eax], edi
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = cpu.edi;
    // 0045c5db  ebc6                   -jmp 0x45c5a3
    goto L_0x0045c5a3;
L_0x0045c5dd:
    // 0045c5dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c5df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c5e2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5e3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5e4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c5e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c5f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c5f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c5f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c5f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c5f4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c5f5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c5f6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c5f9  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045c5fd  81ea00000a00           -sub edx, 0xa0000
    (cpu.edx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045c603  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0045c607  8954242c               -mov dword ptr [esp + 0x2c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0045c60b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c60d  7452                   -je 0x45c661
    if (cpu.flags.zf)
    {
        goto L_0x0045c661;
    }
L_0x0045c60f:
    // 0045c60f  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0045c613  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c615  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0045c618  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0045c61b  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045c61e  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045c622  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0045c625  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045c627  0f8450000000           -je 0x45c67d
    if (cpu.flags.zf)
    {
        goto L_0x0045c67d;
    }
    // 0045c62d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0045c62f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c631  7e3a                   -jle 0x45c66d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c66d;
    }
L_0x0045c633:
    // 0045c633  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c636  7e45                   -jle 0x45c67d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c67d;
    }
    // 0045c638  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0045c63a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c63c  7e33                   -jle 0x45c671
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c671;
    }
L_0x0045c63e:
    // 0045c63e  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c641  7e3a                   -jle 0x45c67d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c67d;
    }
    // 0045c643  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi);
    // 0045c645  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c647  7e2c                   -jle 0x45c675
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c675;
    }
L_0x0045c649:
    // 0045c649  3b4f08                 +cmp ecx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c64c  7e2f                   -jle 0x45c67d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c67d;
    }
    // 0045c64e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c650  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c652  7e25                   -jle 0x45c679
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c679;
    }
L_0x0045c654:
    // 0045c654  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c657  7e24                   -jle 0x45c67d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c67d;
    }
L_0x0045c659:
    // 0045c659  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c65d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045c65f  75ae                   -jne 0x45c60f
    if (!cpu.flags.zf)
    {
        goto L_0x0045c60f;
    }
L_0x0045c661:
    // 0045c661  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c664  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c665  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c666  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c667  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c668  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c669  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c66a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0045c66d:
    // 0045c66d  f7d9                   +neg ecx
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
    // 0045c66f  ebc2                   -jmp 0x45c633
    goto L_0x0045c633;
L_0x0045c671:
    // 0045c671  f7d9                   +neg ecx
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
    // 0045c673  ebc9                   -jmp 0x45c63e
    goto L_0x0045c63e;
L_0x0045c675:
    // 0045c675  f7d9                   +neg ecx
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
    // 0045c677  ebd0                   -jmp 0x45c649
    goto L_0x0045c649;
L_0x0045c679:
    // 0045c679  f7d9                   +neg ecx
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
    // 0045c67b  ebd7                   -jmp 0x45c654
    goto L_0x0045c654;
L_0x0045c67d:
    // 0045c67d  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0045c680  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c683  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045c686  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0045c688  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0045c68b  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045c68e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c691  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0045c694  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0045c696  031c24                 -add ebx, dword ptr [esp]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 0045c699  8b4f0a                 -mov ecx, dword ptr [edi + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0045c69c  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0045c69f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c6a2  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0045c6a4  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0045c6a7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045c6aa  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0045c6ad  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045c6af  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0045c6b1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c6b3  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0045c6b7  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0045c6ba  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c6bc  c1fa0f                 -sar edx, 0xf
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (15 /*0xf*/ % 32));
    // 0045c6bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c6c1  7c96                   -jl 0x45c659
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c659;
    }
    // 0045c6c3  81fad7040000           +cmp edx, 0x4d7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c6c9  7f8e                   -jg 0x45c659
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045c659;
    }
    // 0045c6cb  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0045c6d2  8b153cd54f00           -mov edx, dword ptr [0x4fd53c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c6d8  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c6da  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045c6dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045c6de  7409                   -je 0x45c6e9
    if (cpu.flags.zf)
    {
        goto L_0x0045c6e9;
    }
    // 0045c6e0  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045c6e2  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045c6e4  e970ffffff             -jmp 0x45c659
    goto L_0x0045c659;
L_0x0045c6e9:
    // 0045c6e9  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045c6eb  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0045c6ed  8b1540d54f00           -mov edx, dword ptr [0x4fd540]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c6f3  890411                 -mov dword ptr [ecx + edx], eax
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0045c6f6  e95effffff             -jmp 0x45c659
    goto L_0x0045c659;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c700  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c701  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c702  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0045c709  a13cd54f00             -mov eax, dword ptr [0x4fd53c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c70e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c710  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c712  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045c714  7407                   -je 0x45c71d
    if (cpu.flags.zf)
    {
        goto L_0x0045c71d;
    }
    // 0045c716  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0045c718  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045c71a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c71b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c71c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c71d:
    // 0045c71d  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0045c71f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0045c721  a140d54f00             -mov eax, dword ptr [0x4fd540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231936) /* 0x4fd540 */);
    // 0045c726  891401                 -mov dword ptr [ecx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edx;
    // 0045c729  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c72a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c72b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_45c730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c730  0500000a00             -add eax, 0xa0000
    (cpu.eax) += x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0045c735  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0045c738  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c740  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c741  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0045c746  a13cd54f00             -mov eax, dword ptr [0x4fd53c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231932) /* 0x4fd53c */);
    // 0045c74b  e88c290200             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0045c750  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c751  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c760  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c761  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c762  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045c763  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c764  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045c766  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c769  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045c76b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045c76d  7e13                   -jle 0x45c782
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c782;
    }
    // 0045c76f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045c771:
    // 0045c771  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c775  7510                   -jne 0x45c787
    if (!cpu.flags.zf)
    {
        goto L_0x0045c787;
    }
    // 0045c777  41                     -inc ecx
    (cpu.ecx)++;
    // 0045c778  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0045c77b  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c77e  39d9                   +cmp ecx, ebx
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
    // 0045c780  7cef                   -jl 0x45c771
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c771;
    }
L_0x0045c782:
    // 0045c782  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c783  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c784  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c785  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c786  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c787:
    // 0045c787  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0045c789  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045c78c  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0045c78f  41                     -inc ecx
    (cpu.ecx)++;
    // 0045c790  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0045c793  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c796  39d9                   +cmp ecx, ebx
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
    // 0045c798  7cd7                   -jl 0x45c771
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c771;
    }
    // 0045c79a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c79b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c79c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c79d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c79e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45c7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c7a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c7a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c7a2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c7a5  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045c7a8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0045c7aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c7ac  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c7af  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045c7b2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c7b4  0f8481000000           -je 0x45c83b
    if (cpu.flags.zf)
    {
        goto L_0x0045c83b;
    }
    // 0045c7ba  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c7bb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c7bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c7be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c7c0  7e5d                   -jle 0x45c81f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c81f;
    }
L_0x0045c7c2:
    // 0045c7c2  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c7c5  7549                   -jne 0x45c810
    if (!cpu.flags.zf)
    {
        goto L_0x0045c810;
    }
    // 0045c7c7  3b6a10                 +cmp ebp, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045c7ca  7544                   -jne 0x45c810
    if (!cpu.flags.zf)
    {
        goto L_0x0045c810;
    }
    // 0045c7cc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c7d0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045c7d2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c7d5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045c7d8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0045c7da  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0045c7dd  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c7e0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045c7e2:
    // 0045c7e2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c7e6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c7e9  48                     -dec eax
    (cpu.eax)--;
    // 0045c7ea  39c5                   +cmp ebp, eax
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
    // 0045c7ec  7d31                   -jge 0x45c81f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c81f;
    }
    // 0045c7ee  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045c7f3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045c7f5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0045c7f7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c7f8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045c7fa  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045c7fd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c7ff  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045c801  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045c804  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045c806  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c807  45                     -inc ebp
    (cpu.ebp)++;
    // 0045c808  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c80b  83c210                 +add edx, 0x10
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045c80e  ebd2                   -jmp 0x45c7e2
    goto L_0x0045c7e2;
L_0x0045c810:
    // 0045c810  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c814  43                     -inc ebx
    (cpu.ebx)++;
    // 0045c815  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045c818  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c81b  39fb                   +cmp ebx, edi
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
    // 0045c81d  7ca3                   -jl 0x45c7c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c7c2;
    }
L_0x0045c81f:
    // 0045c81f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c823  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c826  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c82a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045c82d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045c82f  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0045c836  ff4f04                 -dec dword ptr [edi + 4]
    (*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))--;
    // 0045c839  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c83a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045c83b:
    // 0045c83b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045c83e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c83f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c850  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c851  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c852  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045c853  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045c856  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045c85a  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045c85e  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045c861  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0045c865  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c868  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c86a  41                     -inc ecx
    (cpu.ecx)++;
    // 0045c86b  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045c86f  894804                 -mov dword ptr [eax + 4], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045c872  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045c874  7e22                   -jle 0x45c898
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c898;
    }
    // 0045c876  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0045c878:
    // 0045c878  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c87c  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0045c87f  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045c883  39f8                   +cmp eax, edi
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
    // 0045c885  7c39                   -jl 0x45c8c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c8c0;
    }
    // 0045c887  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c88b  42                     -inc edx
    (cpu.edx)++;
    // 0045c88c  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c88f  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c892  39f2                   +cmp edx, esi
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
    // 0045c894  7ce2                   -jl 0x45c878
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c878;
    }
    // 0045c896  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0045c898:
    // 0045c898  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c89c  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c8a0  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045c8a3  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c8a5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045c8a9  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045c8ac  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045c8b0  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0045c8b3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045c8b6  894210                 -mov dword ptr [edx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045c8b9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045c8bc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8bd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8be  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045c8c0:
    // 0045c8c0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c8c4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045c8c7  48                     -dec eax
    (cpu.eax)--;
    // 0045c8c8  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045c8cc  39c2                   +cmp edx, eax
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
    // 0045c8ce  7dc8                   -jge 0x45c898
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045c898;
    }
    // 0045c8d0  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c8d4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c8d8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0045c8db  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045c8de  8d2c03                 -lea ebp, [ebx + eax]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0045c8e1  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c8e4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0045c8e6:
    // 0045c8e6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045c8eb  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045c8ed  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0045c8ef  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c8f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045c8f2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045c8f5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045c8f7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045c8f9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045c8fc  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045c8fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c8ff  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c903  83ed10                 -sub ebp, 0x10
    (cpu.ebp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c906  48                     -dec eax
    (cpu.eax)--;
    // 0045c907  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c90a  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0045c90e  39c2                   +cmp edx, eax
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
    // 0045c910  7cd4                   -jl 0x45c8e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c8e6;
    }
    // 0045c912  eb84                   -jmp 0x45c898
    goto L_0x0045c898;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c920  e9a7c10100             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c930  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045c931  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045c932  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c933  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045c935  c7058c844c0060b14b00   -mov dword ptr [0x4c848c], 0x4bb160
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = 4960608 /*0x4bb160*/;
    // 0045c93f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045c941  b956000000             -mov ecx, 0x56
    cpu.ecx = 86 /*0x56*/;
    // 0045c946  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045c949  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045c94b  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045c94e  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0045c954  e80fbd0100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0045c959  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0045c960  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0045c962  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045c964  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045c966  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045c968  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045c96a  7e18                   -jle 0x45c984
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045c984;
    }
L_0x0045c96c:
    // 0045c96c  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0045c973  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0045c97a  42                     -inc edx
    (cpu.edx)++;
    // 0045c97b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0045c97d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045c980  39f2                   +cmp edx, esi
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
    // 0045c982  7ce8                   -jl 0x45c96c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c96c;
    }
L_0x0045c984:
    // 0045c984  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045c986  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c987  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c988  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045c989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45c990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045c990  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045c991  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045c992  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045c994  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045c996  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045c998  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0045c99a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045c99c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045c99f  c1e204                 +shl edx, 4
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
    // 0045c9a2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045c9a4  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0045c9a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045c9a9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045c9ac  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045c9af  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045c9b1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045c9b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045c9b6  83f814                 +cmp eax, 0x14
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
    // 0045c9b9  7c05                   -jl 0x45c9c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045c9c0;
    }
    // 0045c9bb  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x0045c9c0:
    // 0045c9c0  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0045c9c7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045c9c9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045c9cc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045c9ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045c9d0  8a829c6a4c00           -mov al, byte ptr [edx + 0x4c6a9c]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5008028) /* 0x4c6a9c */);
    // 0045c9d6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045c9d9  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045c9dd  8b902c6a4c00           -mov edx, dword ptr [eax + 0x4c6a2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5007916) /* 0x4c6a2c */);
    // 0045c9e3  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045c9e5  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045c9e9  8b90646a4c00           -mov edx, dword ptr [eax + 0x4c6a64]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5007972) /* 0x4c6a64 */);
    // 0045c9ef  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045c9f1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045c9f5  8b90486a4c00           -mov edx, dword ptr [eax + 0x4c6a48]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5007944) /* 0x4c6a48 */);
    // 0045c9fb  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045c9fd  833d84d54f0000         +cmp dword ptr [0x4fd584], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ca04  7525                   -jne 0x45ca2b
    if (!cpu.flags.zf)
    {
        goto L_0x0045ca2b;
    }
    // 0045ca06  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045ca08:
    // 0045ca08  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045ca0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ca0f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ca12  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ca14  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045ca16  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0045ca19  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ca1b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ca1d  39c8                   +cmp eax, ecx
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
    // 0045ca1f  7512                   -jne 0x45ca33
    if (!cpu.flags.zf)
    {
        goto L_0x0045ca33;
    }
    // 0045ca21  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045ca26  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ca27  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ca28  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0045ca2b:
    // 0045ca2b  8b88806a4c00           -mov ecx, dword ptr [eax + 0x4c6a80]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5008000) /* 0x4c6a80 */);
    // 0045ca31  ebd5                   -jmp 0x45ca08
    goto L_0x0045ca08;
L_0x0045ca33:
    // 0045ca33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ca35  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ca36  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ca37  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ca40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ca40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ca41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ca42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ca43  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ca44  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ca45  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ca46  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045ca49  b406                   -mov ah, 6
    cpu.ah = 6 /*0x6*/;
    // 0045ca4b  be2ce04d00             -mov esi, 0x4de02c
    cpu.esi = 5103660 /*0x4de02c*/;
    // 0045ca50  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045ca54  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0045ca59  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045ca5b  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045ca5e  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0045ca63  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045ca67  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045ca68:
    // 0045ca68  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045ca6a  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045ca6c  3c00                   +cmp al, 0
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
    // 0045ca6e  7410                   -je 0x45ca80
    if (cpu.flags.zf)
    {
        goto L_0x0045ca80;
    }
    // 0045ca70  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045ca73  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045ca76  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045ca79  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045ca7c  3c00                   +cmp al, 0
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
    // 0045ca7e  75e8                   -jne 0x45ca68
    if (!cpu.flags.zf)
    {
        goto L_0x0045ca68;
    }
L_0x0045ca80:
    // 0045ca80  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ca81  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ca83  e82832ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045ca88  66833db0e44d0000       +cmp word ptr [0x4de4b0], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104816) /* 0x4de4b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ca90  7517                   -jne 0x45caa9
    if (!cpu.flags.zf)
    {
        goto L_0x0045caa9;
    }
L_0x0045ca92:
    // 0045ca92  e81930ffff             -call 0x44fab0
    cpu.esp -= 4;
    sub_44fab0(app, cpu);
    if (cpu.terminate) return;
    // 0045ca97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ca99  0f85a3000000           -jne 0x45cb42
    if (!cpu.flags.zf)
    {
        goto L_0x0045cb42;
    }
    // 0045ca9f  66833db0e44d0000       +cmp word ptr [0x4de4b0], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104816) /* 0x4de4b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045caa7  74e9                   -je 0x45ca92
    if (cpu.flags.zf)
    {
        goto L_0x0045ca92;
    }
L_0x0045caa9:
    // 0045caa9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045caab  8a15dee44d00           -mov dl, byte ptr [0x4de4de]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */);
    // 0045cab1  66890db0e44d00         -mov word ptr [0x4de4b0], cx
    *app->getMemory<x86::reg16>(x86::reg32(5104816) /* 0x4de4b0 */) = cpu.cx;
    // 0045cab8  80fa02                 +cmp dl, 2
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
    // 0045cabb  0f8509010000           -jne 0x45cbca
    if (!cpu.flags.zf)
    {
        goto L_0x0045cbca;
    }
    // 0045cac1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045cac5  8b1548d54f00           -mov edx, dword ptr [0x4fd548]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231944) /* 0x4fd548 */);
    // 0045cacb  39d0                   +cmp eax, edx
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
    // 0045cacd  7e77                   -jle 0x45cb46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cb46;
    }
    // 0045cacf  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045cad4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045cad6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045cad8  892decd24d00           -mov dword ptr [0x4dd2ec], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */) = cpu.ebp;
L_0x0045cade:
    // 0045cade  66a330e54d00           -mov word ptr [0x4de530], ax
    *app->getMemory<x86::reg16>(x86::reg32(5104944) /* 0x4de530 */) = cpu.ax;
    // 0045cae4  66893dd8e44d00         -mov word ptr [0x4de4d8], di
    *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.di;
L_0x0045caeb:
    // 0045caeb  be4cd54f00             -mov esi, 0x4fd54c
    cpu.esi = 5231948 /*0x4fd54c*/;
    // 0045caf0  bf58e44d00             -mov edi, 0x4de458
    cpu.edi = 5104728 /*0x4de458*/;
    // 0045caf5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045caf6:
    // 0045caf6  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045caf8  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045cafa  3c00                   +cmp al, 0
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
    // 0045cafc  7410                   -je 0x45cb0e
    if (cpu.flags.zf)
    {
        goto L_0x0045cb0e;
    }
    // 0045cafe  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045cb01  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045cb04  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045cb07  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045cb0a  3c00                   +cmp al, 0
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
    // 0045cb0c  75e8                   -jne 0x45caf6
    if (!cpu.flags.zf)
    {
        goto L_0x0045caf6;
    }
L_0x0045cb0e:
    // 0045cb0e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb0f  be2ce04d00             -mov esi, 0x4de02c
    cpu.esi = 5103660 /*0x4de02c*/;
    // 0045cb14  bfe5e44d00             -mov edi, 0x4de4e5
    cpu.edi = 5104869 /*0x4de4e5*/;
    // 0045cb19  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045cb1a:
    // 0045cb1a  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045cb1c  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045cb1e  3c00                   +cmp al, 0
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
    // 0045cb20  7410                   -je 0x45cb32
    if (cpu.flags.zf)
    {
        goto L_0x0045cb32;
    }
    // 0045cb22  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045cb25  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045cb28  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045cb2b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045cb2e  3c00                   +cmp al, 0
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
    // 0045cb30  75e8                   -jne 0x45cb1a
    if (!cpu.flags.zf)
    {
        goto L_0x0045cb1a;
    }
L_0x0045cb32:
    // 0045cb32  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb33  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0045cb38:
    // 0045cb38  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045cb3b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb3c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb3d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb3e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb3f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb40  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cb42:
    // 0045cb42  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045cb44  ebf2                   -jmp 0x45cb38
    goto L_0x0045cb38;
L_0x0045cb46:
    // 0045cb46  7d2d                   -jge 0x45cb75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045cb75;
    }
    // 0045cb48  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045cb4d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045cb52  66890dd8e44d00         -mov word ptr [0x4de4d8], cx
    *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.cx;
    // 0045cb59  893decd24d00           -mov dword ptr [0x4dd2ec], edi
    *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */) = cpu.edi;
    // 0045cb5f  66893530e54d00         -mov word ptr [0x4de530], si
    *app->getMemory<x86::reg16>(x86::reg32(5104944) /* 0x4de530 */) = cpu.si;
    // 0045cb66  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045cb6b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045cb6e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb6f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb70  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb71  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb72  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb73  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cb74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cb75:
    // 0045cb75  ba4cd54f00             -mov edx, 0x4fd54c
    cpu.edx = 5231948 /*0x4fd54c*/;
    // 0045cb7a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045cb7e  e86dad0100             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 0045cb83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045cb85  7c16                   -jl 0x45cb9d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045cb9d;
    }
    // 0045cb87  7eb9                   -jle 0x45cb42
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cb42;
    }
    // 0045cb89  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045cb8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045cb90  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045cb92  891decd24d00           -mov dword ptr [0x4dd2ec], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */) = cpu.ebx;
    // 0045cb98  e941ffffff             -jmp 0x45cade
    goto L_0x0045cade;
L_0x0045cb9d:
    // 0045cb9d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045cba2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045cba7  66890dd8e44d00         -mov word ptr [0x4de4d8], cx
    *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.cx;
    // 0045cbae  8935ecd24d00           -mov dword ptr [0x4dd2ec], esi
    *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */) = cpu.esi;
    // 0045cbb4  66891d30e54d00         -mov word ptr [0x4de530], bx
    *app->getMemory<x86::reg16>(x86::reg32(5104944) /* 0x4de530 */) = cpu.bx;
    // 0045cbbb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045cbc0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045cbc3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cbca:
    // 0045cbca  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045cbd2  0f8513ffffff           -jne 0x45caeb
    if (!cpu.flags.zf)
    {
        goto L_0x0045caeb;
    }
    // 0045cbd8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045cbdd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045cbe0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cbe6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cbf0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cbf1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cbf2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cbf3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cbf4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045cbf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045cbf7  e8e42effff             -call 0x44fae0
    cpu.esp -= 4;
    sub_44fae0(app, cpu);
    if (cpu.terminate) return;
    // 0045cbfc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0045cc01  8a25dee44d00           -mov ah, byte ptr [0x4de4de]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */);
    // 0045cc07  66891d2ee54d00         -mov word ptr [0x4de52e], bx
    *app->getMemory<x86::reg16>(x86::reg32(5104942) /* 0x4de52e */) = cpu.bx;
    // 0045cc0e  80fc01                 +cmp ah, 1
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
    // 0045cc11  0f847e000000           -je 0x45cc95
    if (cpu.flags.zf)
    {
        goto L_0x0045cc95;
    }
    // 0045cc17  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0045cc19  a3b4e14d00             -mov dword ptr [0x4de1b4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104052) /* 0x4de1b4 */) = cpu.eax;
L_0x0045cc1e:
    // 0045cc1e  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0045cc24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045cc26  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cc29  c1e204                 +shl edx, 4
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
    // 0045cc2c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045cc2e  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0045cc31  8a15dee44d00           -mov dl, byte ptr [0x4de4de]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */);
    // 0045cc37  a3a4e14d00             -mov dword ptr [0x4de1a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104036) /* 0x4de1a4 */) = cpu.eax;
    // 0045cc3c  80fa01                 +cmp dl, 1
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
    // 0045cc3f  0f8595000000           -jne 0x45ccda
    if (!cpu.flags.zf)
    {
        goto L_0x0045ccda;
    }
    // 0045cc45  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0045cc4b  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x0045cc50:
    // 0045cc50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045cc52  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045cc55  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045cc57  a3a8e14d00             -mov dword ptr [0x4de1a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104040) /* 0x4de1a8 */) = cpu.eax;
    // 0045cc5c  a3ace14d00             -mov dword ptr [0x4de1ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104044) /* 0x4de1ac */) = cpu.eax;
    // 0045cc61  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 0045cc66  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0045cc6b  b880e14d00             -mov eax, 0x4de180
    cpu.eax = 5104000 /*0x4de180*/;
    // 0045cc70  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045cc72  891dbce14d00           -mov dword ptr [0x4de1bc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5104060) /* 0x4de1bc */) = cpu.ebx;
    // 0045cc78  8935c0e14d00           -mov dword ptr [0x4de1c0], esi
    *app->getMemory<x86::reg32>(x86::reg32(5104064) /* 0x4de1c0 */) = cpu.esi;
    // 0045cc7e  8935c4e14d00           -mov dword ptr [0x4de1c4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5104068) /* 0x4de1c4 */) = cpu.esi;
    // 0045cc84  892dc8e14d00           -mov dword ptr [0x4de1c8], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5104072) /* 0x4de1c8 */) = cpu.ebp;
    // 0045cc8a  e8c12fffff             -call 0x44fc50
    cpu.esp -= 4;
    sub_44fc50(app, cpu);
    if (cpu.terminate) return;
    // 0045cc8f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cc90  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cc91  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cc92  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cc93  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cc94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cc95:
    // 0045cc95  e8d658fcff             -call 0x422570
    cpu.esp -= 4;
    sub_422570(app, cpu);
    if (cpu.terminate) return;
    // 0045cc9a  668b0dd8e44d00         -mov cx, word ptr [0x4de4d8]
    cpu.cx = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 0045cca1  a3b8e14d00             -mov dword ptr [0x4de1b8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104056) /* 0x4de1b8 */) = cpu.eax;
    // 0045cca6  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0045cca9  7413                   -je 0x45ccbe
    if (cpu.flags.zf)
    {
        goto L_0x0045ccbe;
    }
    // 0045ccab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045ccad  8915e0e14d00           -mov dword ptr [0x4de1e0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5104096) /* 0x4de1e0 */) = cpu.edx;
    // 0045ccb3  8915e4e14d00           -mov dword ptr [0x4de1e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5104100) /* 0x4de1e4 */) = cpu.edx;
    // 0045ccb9  e960ffffff             -jmp 0x45cc1e
    goto L_0x0045cc1e;
L_0x0045ccbe:
    // 0045ccbe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ccc0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045ccc3  a3e4e14d00             -mov dword ptr [0x4de1e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104100) /* 0x4de1e4 */) = cpu.eax;
    // 0045ccc8  8b422c                 -mov eax, dword ptr [edx + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0045cccb  05a0000000             +add eax, 0xa0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045ccd0  a3e0e14d00             -mov dword ptr [0x4de1e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5104096) /* 0x4de1e0 */) = cpu.eax;
    // 0045ccd5  e944ffffff             -jmp 0x45cc1e
    goto L_0x0045cc1e;
L_0x0045ccda:
    // 0045ccda  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0045cce0  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0045cce5  e966ffffff             -jmp 0x45cc50
    goto L_0x0045cc50;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ccf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ccf0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ccf1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ccf2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ccf3  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0045ccf8  bf44d54f00             -mov edi, 0x4fd544
    cpu.edi = 5231940 /*0x4fd544*/;
    // 0045ccfd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045ccff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045cd04  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045cd05  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cd07  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045cd0a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045cd0c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045cd0e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045cd11  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045cd13  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd14  668915b0e44d00         -mov word ptr [0x4de4b0], dx
    *app->getMemory<x86::reg16>(x86::reg32(5104816) /* 0x4de4b0 */) = cpu.dx;
    // 0045cd1b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd1c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd1d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45cd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cd20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cd21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cd22  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cd23  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cd24  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045cd26  a089de4d00             -mov al, byte ptr [0x4dde89]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5103241) /* 0x4dde89 */);
    // 0045cd2b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045cd2d  3c02                   +cmp al, 2
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
    // 0045cd2f  726c                   -jb 0x45cd9d
    if (cpu.flags.cf)
    {
        goto L_0x0045cd9d;
    }
    // 0045cd31  775d                   -ja 0x45cd90
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045cd90;
    }
    // 0045cd33  c605dee44d0001         -mov byte ptr [0x4de4de], 1
    *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */) = 1 /*0x1*/;
L_0x0045cd3a:
    // 0045cd3a  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0045cd3f  b800030000             -mov eax, 0x300
    cpu.eax = 768 /*0x300*/;
    // 0045cd44  e86756faff             -call 0x4023b0
    cpu.esp -= 4;
    sub_4023b0(app, cpu);
    if (cpu.terminate) return;
    // 0045cd49  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045cd4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045cd4d  e89efeffff             -call 0x45cbf0
    cpu.esp -= 4;
    sub_45cbf0(app, cpu);
    if (cpu.terminate) return;
    // 0045cd52  a0dee44d00             -mov al, byte ptr [0x4de4de]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */);
    // 0045cd57  3c01                   +cmp al, 1
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
    // 0045cd59  736a                   -jae 0x45cdc5
    if (!cpu.flags.cf)
    {
        goto L_0x0045cdc5;
    }
L_0x0045cd5b:
    // 0045cd5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045cd5d  0f859e000000           -jne 0x45ce01
    if (!cpu.flags.zf)
    {
        goto L_0x0045ce01;
    }
L_0x0045cd63:
    // 0045cd63  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045cd65  0f8560010000           -jne 0x45cecb
    if (!cpu.flags.zf)
    {
        goto L_0x0045cecb;
    }
L_0x0045cd6b:
    // 0045cd6b  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0045cd70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cd72  e8c955faff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0045cd77  e8042dffff             -call 0x44fa80
    cpu.esp -= 4;
    sub_44fa80(app, cpu);
    if (cpu.terminate) return;
    // 0045cd7c  e870a50100             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0045cd81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045cd83  0f8425010000           -je 0x45ceae
    if (cpu.flags.zf)
    {
        goto L_0x0045ceae;
    }
L_0x0045cd89:
    // 0045cd89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045cd8b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd8c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd8d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd8e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cd8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cd90:
    // 0045cd90  3c03                   +cmp al, 3
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
    // 0045cd92  7509                   -jne 0x45cd9d
    if (!cpu.flags.zf)
    {
        goto L_0x0045cd9d;
    }
    // 0045cd94  c605dee44d0002         -mov byte ptr [0x4de4de], 2
    *app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */) = 2 /*0x2*/;
    // 0045cd9b  eb9d                   -jmp 0x45cd3a
    goto L_0x0045cd3a;
L_0x0045cd9d:
    // 0045cd9d  ba98b14b00             -mov edx, 0x4bb198
    cpu.edx = 4960664 /*0x4bb198*/;
    // 0045cda2  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 0045cda7  68b8b14b00             -push 0x4bb1b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4960696 /*0x4bb1b8*/;
    cpu.esp -= 4;
    // 0045cdac  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0045cdb2  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0045cdb8  e803b50100             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0045cdbd  83c404                 +add esp, 4
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
    // 0045cdc0  e975ffffff             -jmp 0x45cd3a
    goto L_0x0045cd3a;
L_0x0045cdc5:
    // 0045cdc5  761f                   -jbe 0x45cde6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045cde6;
    }
    // 0045cdc7  3c02                   +cmp al, 2
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
    // 0045cdc9  7590                   -jne 0x45cd5b
    if (!cpu.flags.zf)
    {
        goto L_0x0045cd5b;
    }
    // 0045cdcb  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0045cdd0  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0045cdd5  b880e14d00             -mov eax, 0x4de180
    cpu.eax = 5104000 /*0x4de180*/;
    // 0045cdda  e8c1e70200             -call 0x48b5a0
    cpu.esp -= 4;
    sub_48b5a0(app, cpu);
    if (cpu.terminate) return;
    // 0045cddf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045cde1  e975ffffff             -jmp 0x45cd5b
    goto L_0x0045cd5b;
L_0x0045cde6:
    // 0045cde6  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0045cdeb  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0045cdf0  b880e14d00             -mov eax, 0x4de180
    cpu.eax = 5104000 /*0x4de180*/;
    // 0045cdf5  e8661cfcff             -call 0x41ea60
    cpu.esp -= 4;
    sub_41ea60(app, cpu);
    if (cpu.terminate) return;
    // 0045cdfa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045cdfc  e95affffff             -jmp 0x45cd5b
    goto L_0x0045cd5b;
L_0x0045ce01:
    // 0045ce01  a1744a4c00             -mov eax, dword ptr [0x4c4a74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999796) /* 0x4c4a74 */);
    // 0045ce06  e8fd210200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045ce0b  e830fcffff             -call 0x45ca40
    cpu.esp -= 4;
    sub_45ca40(app, cpu);
    if (cpu.terminate) return;
    // 0045ce10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ce12  0f8480000000           -je 0x45ce98
    if (cpu.flags.zf)
    {
        goto L_0x0045ce98;
    }
    // 0045ce18  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ce20  7542                   -jne 0x45ce64
    if (!cpu.flags.zf)
    {
        goto L_0x0045ce64;
    }
    // 0045ce22  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ce23  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0045ce25:
    // 0045ce25  668b3da4e44d00         -mov di, word ptr [0x4de4a4]
    cpu.di = *app->getMemory<x86::reg16>(x86::reg32(5104804) /* 0x4de4a4 */);
    // 0045ce2c  6639fe                 +cmp si, di
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ce2f  7523                   -jne 0x45ce54
    if (!cpu.flags.zf)
    {
        goto L_0x0045ce54;
    }
    // 0045ce31  e87a2cffff             -call 0x44fab0
    cpu.esp -= 4;
    sub_44fab0(app, cpu);
    if (cpu.terminate) return;
    // 0045ce36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ce38  743e                   -je 0x45ce78
    if (cpu.flags.zf)
    {
        goto L_0x0045ce78;
    }
    // 0045ce3a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045ce3f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045ce41  668915dae44d00         -mov word ptr [0x4de4da], dx
    *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.dx;
    // 0045ce48  668915dce44d00         -mov word ptr [0x4de4dc], dx
    *app->getMemory<x86::reg16>(x86::reg32(5104860) /* 0x4de4dc */) = cpu.dx;
    // 0045ce4f  e820250200             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
L_0x0045ce54:
    // 0045ce54  a1744a4c00             -mov eax, dword ptr [0x4c4a74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999796) /* 0x4c4a74 */);
    // 0045ce59  e8c2210200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045ce5e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ce5f  e9fffeffff             -jmp 0x45cd63
    goto L_0x0045cd63;
L_0x0045ce64:
    // 0045ce64  a1744a4c00             -mov eax, dword ptr [0x4c4a74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999796) /* 0x4c4a74 */);
    // 0045ce69  e8b2210200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045ce6e  e82d2affff             -call 0x44f8a0
    cpu.esp -= 4;
    sub_44f8a0(app, cpu);
    if (cpu.terminate) return;
    // 0045ce73  e9ebfeffff             -jmp 0x45cd63
    goto L_0x0045cd63;
L_0x0045ce78:
    // 0045ce78  663b3ddae44d00         +cmp di, word ptr [0x4de4da]
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ce7f  74a4                   -je 0x45ce25
    if (cpu.flags.zf)
    {
        goto L_0x0045ce25;
    }
    // 0045ce81  e8ee240200             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0045ce86  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045ce88  a1744a4c00             -mov eax, dword ptr [0x4c4a74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999796) /* 0x4c4a74 */);
    // 0045ce8d  e88e210200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045ce92  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ce93  e9cbfeffff             -jmp 0x45cd63
    goto L_0x0045cd63;
L_0x0045ce98:
    // 0045ce98  e8d7240200             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0045ce9d  a1744a4c00             -mov eax, dword ptr [0x4c4a74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999796) /* 0x4c4a74 */);
    // 0045cea2  e879210200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045cea7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045cea9  e9bdfeffff             -jmp 0x45cd6b
    goto L_0x0045cd6b;
L_0x0045ceae:
    // 0045ceae  e8fd89faff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0045ceb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045ceb5  0f85cefeffff           -jne 0x45cd89
    if (!cpu.flags.zf)
    {
        goto L_0x0045cd89;
    }
    // 0045cebb  e831a40100             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0045cec0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045cec2  74ea                   -je 0x45ceae
    if (cpu.flags.zf)
    {
        goto L_0x0045ceae;
    }
    // 0045cec4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045cec6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cec7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cec8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045cec9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045cecb:
    // 0045cecb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045cecd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045cecf  e86c54faff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0045ced4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ced6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ced7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ced8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ced9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ceda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45cee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045cee0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045cee1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045cee2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045cee3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045cee4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045cee5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045cee6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045cee9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ceeb  8b3578cf4d00           -mov esi, dword ptr [0x4dcf78]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5099384) /* 0x4dcf78 */);
    // 0045cef1  e88ab10100             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0045cef6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045cef8  8b1578cf4d00           -mov edx, dword ptr [0x4dcf78]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099384) /* 0x4dcf78 */);
    // 0045cefe  81c610270000           -add esi, 0x2710
    (cpu.esi) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 0045cf04  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045cf06  0f8e94010000           -jle 0x45d0a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d0a0;
    }
L_0x0045cf0c:
    // 0045cf0c  a11cdb4d00             -mov eax, dword ptr [0x4ddb1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5102364) /* 0x4ddb1c */);
    // 0045cf11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045cf13  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045cf15  a388d54f00             -mov dword ptr [0x4fd588], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */) = cpu.eax;
    // 0045cf1a  e80164fdff             -call 0x433320
    cpu.esp -= 4;
    sub_433320(app, cpu);
    if (cpu.terminate) return;
    // 0045cf1f  e80c64fdff             -call 0x433330
    cpu.esp -= 4;
    sub_433330(app, cpu);
    if (cpu.terminate) return;
    // 0045cf24  e833940100             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0045cf29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045cf2b  e8b03bfcff             -call 0x420ae0
    cpu.esp -= 4;
    sub_420ae0(app, cpu);
    if (cpu.terminate) return;
    // 0045cf30  833d64d54f0000         +cmp dword ptr [0x4fd564], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cf37  0f854c010000           -jne 0x45d089
    if (!cpu.flags.zf)
    {
        goto L_0x0045d089;
    }
L_0x0045cf3d:
    // 0045cf3d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045cf3f  e83cb10100             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0045cf44  a1086b4c00             -mov eax, dword ptr [0x4c6b08]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */);
    // 0045cf49  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045cf4b  a370d54f00             -mov dword ptr [0x4fd570], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */) = cpu.eax;
    // 0045cf50  a178cf4d00             -mov eax, dword ptr [0x4dcf78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5099384) /* 0x4dcf78 */);
    // 0045cf55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045cf57  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0045cf59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045cf5b  8b1570d54f00           -mov edx, dword ptr [0x4fd570]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */);
    // 0045cf61  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045cf63  39d6                   +cmp esi, edx
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
    // 0045cf65  7e06                   -jle 0x45cf6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045cf6d;
    }
    // 0045cf67  ff0570d54f00           -inc dword ptr [0x4fd570]
    (*app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */))++;
L_0x0045cf6d:
    // 0045cf6d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045cf6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045cf71  8b1588d54f00           -mov edx, dword ptr [0x4fd588]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */);
    // 0045cf77  a378d54f00             -mov dword ptr [0x4fd578], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231992) /* 0x4fd578 */) = cpu.eax;
    // 0045cf7c  a11cdb4d00             -mov eax, dword ptr [0x4ddb1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5102364) /* 0x4ddb1c */);
    // 0045cf81  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045cf83  8b0d70d54f00           -mov ecx, dword ptr [0x4fd570]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */);
    // 0045cf89  83f810                 +cmp eax, 0x10
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
    // 0045cf8c  0f8f1d010000           -jg 0x45d0af
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d0af;
    }
L_0x0045cf92:
    // 0045cf92  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 0045cf97  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045cf9c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045cf9e:
    // 0045cf9e  8b151cdb4d00           -mov edx, dword ptr [0x4ddb1c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5102364) /* 0x4ddb1c */);
    // 0045cfa4  3b1588d54f00           +cmp edx, dword ptr [0x4fd588]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfaa  7c0c                   -jl 0x45cfb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045cfb8;
    }
    // 0045cfac  3b1d64d54f00           +cmp ebx, dword ptr [0x4fd564]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfb2  0f8406010000           -je 0x45d0be
    if (cpu.flags.zf)
    {
        goto L_0x0045d0be;
    }
L_0x0045cfb8:
    // 0045cfb8  833d68d54f0000         +cmp dword ptr [0x4fd568], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfbf  0f8507040000           -jne 0x45d3cc
    if (!cpu.flags.zf)
    {
        goto L_0x0045d3cc;
    }
    // 0045cfc5  833d6cd54f0000         +cmp dword ptr [0x4fd56c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfcc  0f85fa030000           -jne 0x45d3cc
    if (!cpu.flags.zf)
    {
        goto L_0x0045d3cc;
    }
    // 0045cfd2  833d64d54f0000         +cmp dword ptr [0x4fd564], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfd9  0f85ed030000           -jne 0x45d3cc
    if (!cpu.flags.zf)
    {
        goto L_0x0045d3cc;
    }
    // 0045cfdf  8b2d70d54f00           -mov ebp, dword ptr [0x4fd570]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */);
    // 0045cfe5  3b2d74d54f00           +cmp ebp, dword ptr [0x4fd574]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045cfeb  0f8cf9020000           -jl 0x45d2ea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d2ea;
    }
L_0x0045cff1:
    // 0045cff1  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0045cff6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0045cffb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045cffd:
    // 0045cffd  8b1570d54f00           -mov edx, dword ptr [0x4fd570]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */);
    // 0045d003  3b1574d54f00           +cmp edx, dword ptr [0x4fd574]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d009  7c0f                   -jl 0x45d01a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d01a;
    }
    // 0045d00b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045d00d  e81e040000             -call 0x45d430
    cpu.esp -= 4;
    sub_45d430(app, cpu);
    if (cpu.terminate) return;
    // 0045d012  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d014  0f84df020000           -je 0x45d2f9
    if (cpu.flags.zf)
    {
        goto L_0x0045d2f9;
    }
L_0x0045d01a:
    // 0045d01a  833d78d54f0000         +cmp dword ptr [0x4fd578], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231992) /* 0x4fd578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d021  750a                   -jne 0x45d02d
    if (!cpu.flags.zf)
    {
        goto L_0x0045d02d;
    }
    // 0045d023  a168d54f00             -mov eax, dword ptr [0x4fd568]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */);
    // 0045d028  e813d9ffff             -call 0x45a940
    cpu.esp -= 4;
    sub_45a940(app, cpu);
    if (cpu.terminate) return;
L_0x0045d02d:
    // 0045d02d  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d034  7517                   -jne 0x45d04d
    if (!cpu.flags.zf)
    {
        goto L_0x0045d04d;
    }
    // 0045d036  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d03d  7f0e                   -jg 0x45d04d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d04d;
    }
    // 0045d03f  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d046  7505                   -jne 0x45d04d
    if (!cpu.flags.zf)
    {
        goto L_0x0045d04d;
    }
    // 0045d048  e803d80000             -call 0x46a850
    cpu.esp -= 4;
    sub_46a850(app, cpu);
    if (cpu.terminate) return;
L_0x0045d04d:
    // 0045d04d  e8eeb4feff             -call 0x448540
    cpu.esp -= 4;
    sub_448540(app, cpu);
    if (cpu.terminate) return;
    // 0045d052  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d054  0f847c030000           -je 0x45d3d6
    if (cpu.flags.zf)
    {
        goto L_0x0045d3d6;
    }
L_0x0045d05a:
    // 0045d05a  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d061  7f11                   -jg 0x45d074
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d074;
    }
    // 0045d063  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045d068  891d106b4c00           -mov dword ptr [0x4c6b10], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ebx;
    // 0045d06e  891d0c6b4c00           -mov dword ptr [0x4c6b0c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ebx;
L_0x0045d074:
    // 0045d074  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d079  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0045d07e  e8bd270000             -call 0x45f840
    cpu.esp -= 4;
    sub_45f840(app, cpu);
    if (cpu.terminate) return;
    // 0045d083  893d64d54f00           -mov dword ptr [0x4fd564], edi
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.edi;
L_0x0045d089:
    // 0045d089  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d090  0f8e79030000           -jle 0x45d40f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d40f;
    }
    // 0045d096  83c404                 +add esp, 4
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
    // 0045d099  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d09f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d0a0:
    // 0045d0a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d0a5  e83be30200             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0045d0aa  e95dfeffff             -jmp 0x45cf0c
    goto L_0x0045cf0c;
L_0x0045d0af:
    // 0045d0af  a11cdb4d00             -mov eax, dword ptr [0x4ddb1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5102364) /* 0x4ddb1c */);
    // 0045d0b4  a388d54f00             -mov dword ptr [0x4fd588], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */) = cpu.eax;
    // 0045d0b9  e9d4feffff             -jmp 0x45cf92
    goto L_0x0045cf92;
L_0x0045d0be:
    // 0045d0be  3b2de8d24d00           +cmp ebp, dword ptr [0x4dd2e8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d0c4  7e05                   -jle 0x45d0cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d0cb;
    }
    // 0045d0c6  e835d8ffff             -call 0x45a900
    cpu.esp -= 4;
    sub_45a900(app, cpu);
    if (cpu.terminate) return;
L_0x0045d0cb:
    // 0045d0cb  3b2dd4d34f00           +cmp ebp, dword ptr [0x4fd3d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d0d1  7547                   -jne 0x45d11a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d11a;
    }
    // 0045d0d3  8b1568d54f00           -mov edx, dword ptr [0x4fd568]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */);
    // 0045d0d9  39d3                   +cmp ebx, edx
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
    // 0045d0db  753d                   -jne 0x45d11a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d11a;
    }
    // 0045d0dd  e8cedfffff             -call 0x45b0b0
    cpu.esp -= 4;
    sub_45b0b0(app, cpu);
    if (cpu.terminate) return;
    // 0045d0e2  833de4ed4d0004         +cmp dword ptr [0x4dede4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d0e9  752f                   -jne 0x45d11a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d11a;
    }
    // 0045d0eb  a1d8ed4d00             -mov eax, dword ptr [0x4dedd8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5107160) /* 0x4dedd8 */);
    // 0045d0f0  8915e4ed4d00           -mov dword ptr [0x4dede4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5107172) /* 0x4dede4 */) = cpu.edx;
    // 0045d0f6  a364d54f00             -mov dword ptr [0x4fd564], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.eax;
    // 0045d0fb  39c2                   +cmp edx, eax
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
    // 0045d0fd  0f848c010000           -je 0x45d28f
    if (cpu.flags.zf)
    {
        goto L_0x0045d28f;
    }
    // 0045d103  3b156cd54f00           +cmp edx, dword ptr [0x4fd56c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d109  0f8480010000           -je 0x45d28f
    if (cpu.flags.zf)
    {
        goto L_0x0045d28f;
    }
    // 0045d10f  89156cd54f00           -mov dword ptr [0x4fd56c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */) = cpu.edx;
    // 0045d115  e8d621fdff             -call 0x42f2f0
    cpu.esp -= 4;
    sub_42f2f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d11a:
    // 0045d11a  8b1564d54f00           -mov edx, dword ptr [0x4fd564]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */);
    // 0045d120  39d3                   +cmp ebx, edx
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
    // 0045d122  7511                   -jne 0x45d135
    if (!cpu.flags.zf)
    {
        goto L_0x0045d135;
    }
    // 0045d124  3b1568d54f00           +cmp edx, dword ptr [0x4fd568]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d12a  0f8494010000           -je 0x45d2c4
    if (cpu.flags.zf)
    {
        goto L_0x0045d2c4;
    }
    // 0045d130  e8ab030000             -call 0x45d4e0
    cpu.esp -= 4;
    sub_45d4e0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d135:
    // 0045d135  3b1d68d54f00           +cmp ebx, dword ptr [0x4fd568]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d13b  0f852b010000           -jne 0x45d26c
    if (!cpu.flags.zf)
    {
        goto L_0x0045d26c;
    }
    // 0045d141  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0045d146  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d148  e883b4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d14d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d14f  7405                   -je 0x45d156
    if (cpu.flags.zf)
    {
        goto L_0x0045d156;
    }
    // 0045d151  e85a1f0100             -call 0x46f0b0
    cpu.esp -= 4;
    sub_46f0b0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d156:
    // 0045d156  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0045d15b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d15d  e86eb4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d162  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d164  7405                   -je 0x45d16b
    if (cpu.flags.zf)
    {
        goto L_0x0045d16b;
    }
    // 0045d166  e8b51f0100             -call 0x46f120
    cpu.esp -= 4;
    sub_46f120(app, cpu);
    if (cpu.terminate) return;
L_0x0045d16b:
    // 0045d16b  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0045d170  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d172  e859b4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d177  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d179  7405                   -je 0x45d180
    if (cpu.flags.zf)
    {
        goto L_0x0045d180;
    }
    // 0045d17b  e89062fdff             -call 0x433410
    cpu.esp -= 4;
    sub_433410(app, cpu);
    if (cpu.terminate) return;
L_0x0045d180:
    // 0045d180  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0045d185  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d187  e844b4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d18c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d18e  7405                   -je 0x45d195
    if (cpu.flags.zf)
    {
        goto L_0x0045d195;
    }
    // 0045d190  e83b450100             -call 0x4716d0
    cpu.esp -= 4;
    sub_4716d0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d195:
    // 0045d195  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0045d19a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d19c  e82fb4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d1a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d1a3  7407                   -je 0x45d1ac
    if (cpu.flags.zf)
    {
        goto L_0x0045d1ac;
    }
    // 0045d1a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045d1a7  e8448ffeff             -call 0x4460f0
    cpu.esp -= 4;
    sub_4460f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d1ac:
    // 0045d1ac  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0045d1b1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d1b3  e818b4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d1b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d1ba  7407                   -je 0x45d1c3
    if (cpu.flags.zf)
    {
        goto L_0x0045d1c3;
    }
    // 0045d1bc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045d1be  e82d8ffeff             -call 0x4460f0
    cpu.esp -= 4;
    sub_4460f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d1c3:
    // 0045d1c3  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0045d1c8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d1ca  e801b4feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d1cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d1d1  7405                   -je 0x45d1d8
    if (cpu.flags.zf)
    {
        goto L_0x0045d1d8;
    }
    // 0045d1d3  e8d88efeff             -call 0x4460b0
    cpu.esp -= 4;
    sub_4460b0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d1d8:
    // 0045d1d8  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0045d1dd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d1df  e8ecb3feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d1e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d1e6  7405                   -je 0x45d1ed
    if (cpu.flags.zf)
    {
        goto L_0x0045d1ed;
    }
    // 0045d1e8  e8a31ffdff             -call 0x42f190
    cpu.esp -= 4;
    sub_42f190(app, cpu);
    if (cpu.terminate) return;
L_0x0045d1ed:
    // 0045d1ed  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0045d1f2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d1f4  e8d7b3feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d1f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d1fb  7405                   -je 0x45d202
    if (cpu.flags.zf)
    {
        goto L_0x0045d202;
    }
    // 0045d1fd  e84e1ffdff             -call 0x42f150
    cpu.esp -= 4;
    sub_42f150(app, cpu);
    if (cpu.terminate) return;
L_0x0045d202:
    // 0045d202  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045d204  e8b7740000             -call 0x4646c0
    cpu.esp -= 4;
    sub_4646c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d209  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d20b  740f                   -je 0x45d21c
    if (cpu.flags.zf)
    {
        goto L_0x0045d21c;
    }
    // 0045d20d  3b2dd4d34f00           +cmp ebp, dword ptr [0x4fd3d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d213  7e07                   -jle 0x45d21c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d21c;
    }
    // 0045d215  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045d217  e814acfdff             -call 0x437e30
    cpu.esp -= 4;
    sub_437e30(app, cpu);
    if (cpu.terminate) return;
L_0x0045d21c:
    // 0045d21c  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045d222  39d7                   +cmp edi, edx
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
    // 0045d224  751a                   -jne 0x45d240
    if (!cpu.flags.zf)
    {
        goto L_0x0045d240;
    }
    // 0045d226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d228  e893740000             -call 0x4646c0
    cpu.esp -= 4;
    sub_4646c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d22d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d22f  740f                   -je 0x45d240
    if (cpu.flags.zf)
    {
        goto L_0x0045d240;
    }
    // 0045d231  3b2dd4d34f00           +cmp ebp, dword ptr [0x4fd3d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d237  7e07                   -jle 0x45d240
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d240;
    }
    // 0045d239  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045d23b  e8f0abfdff             -call 0x437e30
    cpu.esp -= 4;
    sub_437e30(app, cpu);
    if (cpu.terminate) return;
L_0x0045d240:
    // 0045d240  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 0045d245  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045d247  e884b3feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d24c  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045d252  a3a8d94d00             -mov dword ptr [0x4dd9a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101992) /* 0x4dd9a8 */) = cpu.eax;
    // 0045d257  39d7                   +cmp edi, edx
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
    // 0045d259  7511                   -jne 0x45d26c
    if (!cpu.flags.zf)
    {
        goto L_0x0045d26c;
    }
    // 0045d25b  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 0045d260  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045d262  e869b3feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d267  a3acd94d00             -mov dword ptr [0x4dd9ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101996) /* 0x4dd9ac */) = cpu.eax;
L_0x0045d26c:
    // 0045d26c  3b2de8d24d00           +cmp ebp, dword ptr [0x4dd2e8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d272  7e5c                   -jle 0x45d2d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d2d0;
    }
L_0x0045d274:
    // 0045d274  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0045d279  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045d27b  e850b3feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d280  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d282  7556                   -jne 0x45d2da
    if (!cpu.flags.zf)
    {
        goto L_0x0045d2da;
    }
L_0x0045d284:
    // 0045d284  ff0588d54f00           +inc dword ptr [0x4fd588]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d28a  e90ffdffff             -jmp 0x45cf9e
    goto L_0x0045cf9e;
L_0x0045d28f:
    // 0045d28f  8b15d0ed4d00           -mov edx, dword ptr [0x4dedd0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5107152) /* 0x4dedd0 */);
    // 0045d295  3b156cd54f00           +cmp edx, dword ptr [0x4fd56c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d29b  0f8479feffff           -je 0x45d11a
    if (cpu.flags.zf)
    {
        goto L_0x0045d11a;
    }
    // 0045d2a1  89156cd54f00           -mov dword ptr [0x4fd56c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */) = cpu.edx;
    // 0045d2a7  39d3                   +cmp ebx, edx
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
    // 0045d2a9  740f                   -je 0x45d2ba
    if (cpu.flags.zf)
    {
        goto L_0x0045d2ba;
    }
    // 0045d2ab  e834c3fdff             -call 0x4395e4
    cpu.esp -= 4;
    sub_4395e4(app, cpu);
    if (cpu.terminate) return;
    // 0045d2b0  e8cb20fdff             -call 0x42f380
    cpu.esp -= 4;
    sub_42f380(app, cpu);
    if (cpu.terminate) return;
    // 0045d2b5  e960feffff             -jmp 0x45d11a
    goto L_0x0045d11a;
L_0x0045d2ba:
    // 0045d2ba  e8a120fdff             -call 0x42f360
    cpu.esp -= 4;
    sub_42f360(app, cpu);
    if (cpu.terminate) return;
    // 0045d2bf  e956feffff             -jmp 0x45d11a
    goto L_0x0045d11a;
L_0x0045d2c4:
    // 0045d2c4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045d2c6  e865010000             -call 0x45d430
    cpu.esp -= 4;
    sub_45d430(app, cpu);
    if (cpu.terminate) return;
    // 0045d2cb  e965feffff             -jmp 0x45d135
    goto L_0x0045d135;
L_0x0045d2d0:
    // 0045d2d0  3b3df4d24d00           +cmp edi, dword ptr [0x4dd2f4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d2d6  7c9c                   -jl 0x45d274
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d274;
    }
    // 0045d2d8  ebaa                   -jmp 0x45d284
    goto L_0x0045d284;
L_0x0045d2da:
    // 0045d2da  e8d1060000             -call 0x45d9b0
    cpu.esp -= 4;
    sub_45d9b0(app, cpu);
    if (cpu.terminate) return;
    // 0045d2df  ff0588d54f00           +inc dword ptr [0x4fd588]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d2e5  e9b4fcffff             -jmp 0x45cf9e
    goto L_0x0045cf9e;
L_0x0045d2ea:
    // 0045d2ea  c70578d54f0001000000   -mov dword ptr [0x4fd578], 1
    *app->getMemory<x86::reg32>(x86::reg32(5231992) /* 0x4fd578 */) = 1 /*0x1*/;
    // 0045d2f4  e9f8fcffff             -jmp 0x45cff1
    goto L_0x0045cff1;
L_0x0045d2f9:
    // 0045d2f9  a174d54f00             -mov eax, dword ptr [0x4fd574]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
    // 0045d2fe  85c5                   +test ebp, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.eax));
    // 0045d300  7507                   -jne 0x45d309
    if (!cpu.flags.zf)
    {
        goto L_0x0045d309;
    }
    // 0045d302  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045d304  e8c7150000             -call 0x45e8d0
    cpu.esp -= 4;
    sub_45e8d0(app, cpu);
    if (cpu.terminate) return;
L_0x0045d309:
    // 0045d309  8b15d4d34f00           -mov edx, dword ptr [0x4fd3d4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */);
    // 0045d30f  891dec6a4c00           -mov dword ptr [0x4c6aec], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5008108) /* 0x4c6aec */) = cpu.ebx;
    // 0045d315  39d7                   +cmp edi, edx
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
    // 0045d317  0f857d000000           -jne 0x45d39a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d39a;
    }
    // 0045d31d  3b1dd4ed4d00           +cmp ebx, dword ptr [0x4dedd4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5107156) /* 0x4dedd4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d323  752d                   -jne 0x45d352
    if (!cpu.flags.zf)
    {
        goto L_0x0045d352;
    }
    // 0045d325  a174d54f00             -mov eax, dword ptr [0x4fd574]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
    // 0045d32a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045d32c  c7042404000000         -mov dword ptr [esp], 4
    *app->getMemory<x86::reg32>(cpu.esp) = 4 /*0x4*/;
    // 0045d333  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d336  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045d339  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045d33b  7515                   -jne 0x45d352
    if (!cpu.flags.zf)
    {
        goto L_0x0045d352;
    }
L_0x0045d33d:
    // 0045d33d  a174d54f00             -mov eax, dword ptr [0x4fd574]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
    // 0045d342  e8a9020000             -call 0x45d5f0
    cpu.esp -= 4;
    sub_45d5f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d347  ff0574d54f00           +inc dword ptr [0x4fd574]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d34d  e9abfcffff             -jmp 0x45cffd
    goto L_0x0045cffd;
L_0x0045d352:
    // 0045d352  3b2dd4ed4d00           +cmp ebp, dword ptr [0x4dedd4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5107156) /* 0x4dedd4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d358  7510                   -jne 0x45d36a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d36a;
    }
    // 0045d35a  a174d54f00             -mov eax, dword ptr [0x4fd574]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
    // 0045d35f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045d361  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045d364  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045d366  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045d368  74d3                   -je 0x45d33d
    if (cpu.flags.zf)
    {
        goto L_0x0045d33d;
    }
L_0x0045d36a:
    // 0045d36a  a1d4ed4d00             -mov eax, dword ptr [0x4dedd4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5107156) /* 0x4dedd4 */);
    // 0045d36f  39c7                   +cmp edi, eax
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
    // 0045d371  74ca                   -je 0x45d33d
    if (cpu.flags.zf)
    {
        goto L_0x0045d33d;
    }
    // 0045d373  83f803                 +cmp eax, 3
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
    // 0045d376  750c                   -jne 0x45d384
    if (!cpu.flags.zf)
    {
        goto L_0x0045d384;
    }
    // 0045d378  a174d54f00             -mov eax, dword ptr [0x4fd574]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
    // 0045d37d  e86e020000             -call 0x45d5f0
    cpu.esp -= 4;
    sub_45d5f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d382  ebb9                   -jmp 0x45d33d
    goto L_0x0045d33d;
L_0x0045d384:
    // 0045d384  892dec6a4c00           -mov dword ptr [0x4c6aec], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5008108) /* 0x4c6aec */) = cpu.ebp;
    // 0045d38a  e855c2fdff             -call 0x4395e4
    cpu.esp -= 4;
    sub_4395e4(app, cpu);
    if (cpu.terminate) return;
    // 0045d38f  ff0574d54f00           +inc dword ptr [0x4fd574]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045d395  e963fcffff             -jmp 0x45cffd
    goto L_0x0045cffd;
L_0x0045d39a:
    // 0045d39a  83fa04                 +cmp edx, 4
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
    // 0045d39d  759e                   -jne 0x45d33d
    if (!cpu.flags.zf)
    {
        goto L_0x0045d33d;
    }
    // 0045d39f  e81c1efdff             -call 0x42f1c0
    cpu.esp -= 4;
    sub_42f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d3a4  e8b720ffff             -call 0x44f460
    cpu.esp -= 4;
    sub_44f460(app, cpu);
    if (cpu.terminate) return;
    // 0045d3a9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045d3ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045d3b3  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0045d3b5  8915d4d34f00           -mov dword ptr [0x4fd3d4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */) = cpu.edx;
    // 0045d3bb  891d78d54f00           -mov dword ptr [0x4fd578], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5231992) /* 0x4fd578 */) = cpu.ebx;
    // 0045d3c1  893d086b4c00           -mov dword ptr [0x4c6b08], edi
    *app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */) = cpu.edi;
    // 0045d3c7  e961fcffff             -jmp 0x45d02d
    goto L_0x0045d02d;
L_0x0045d3cc:
    // 0045d3cc  e813c2fdff             -call 0x4395e4
    cpu.esp -= 4;
    sub_4395e4(app, cpu);
    if (cpu.terminate) return;
    // 0045d3d1  e944fcffff             -jmp 0x45d01a
    goto L_0x0045d01a;
L_0x0045d3d6:
    // 0045d3d6  66833ddae44d0000       +cmp word ptr [0x4de4da], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045d3de  0f8576fcffff           -jne 0x45d05a
    if (!cpu.flags.zf)
    {
        goto L_0x0045d05a;
    }
    // 0045d3e4  833dd4d34f0003         +cmp dword ptr [0x4fd3d4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d3eb  7510                   -jne 0x45d3fd
    if (!cpu.flags.zf)
    {
        goto L_0x0045d3fd;
    }
    // 0045d3ed  813d84d54f0040020000   +cmp dword ptr [0x4fd584], 0x240
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(576 /*0x240*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d3f7  0f8f5dfcffff           -jg 0x45d05a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045d05a;
    }
L_0x0045d3fd:
    // 0045d3fd  833d64d54f0000         +cmp dword ptr [0x4fd564], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d404  0f8433fbffff           -je 0x45cf3d
    if (cpu.flags.zf)
    {
        goto L_0x0045cf3d;
    }
    // 0045d40a  e97afcffff             -jmp 0x45d089
    goto L_0x0045d089;
L_0x0045d40f:
    // 0045d40f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d414  a3106b4c00             -mov dword ptr [0x4c6b10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.eax;
    // 0045d419  a30c6b4c00             -mov dword ptr [0x4c6b0c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.eax;
    // 0045d41e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045d421  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d422  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d423  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d424  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d425  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d426  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d427  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d430  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d431  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045d432  833d60d54f0000         +cmp dword ptr [0x4fd560], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231968) /* 0x4fd560 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d439  0f8587000000           -jne 0x45d4c6
    if (!cpu.flags.zf)
    {
        goto L_0x0045d4c6;
    }
    // 0045d43f  8b0d84d54f00           -mov ecx, dword ptr [0x4fd584]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045d445  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d448  0f8c78000000           -jl 0x45d4c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d4c6;
    }
    // 0045d44e  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d454  7d09                   -jge 0x45d45f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045d45f;
    }
    // 0045d456  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d45d  7e67                   -jle 0x45d4c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045d4c6;
    }
L_0x0045d45f:
    // 0045d45f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d461  7424                   -je 0x45d487
    if (cpu.flags.zf)
    {
        goto L_0x0045d487;
    }
    // 0045d463  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d464  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d469  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0045d46e  e85db1feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d473  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d478  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045d47a  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0045d47f  e84cb1feff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 0045d484  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d486  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045d487:
    // 0045d487  e8b40e0000             -call 0x45e340
    cpu.esp -= 4;
    sub_45e340(app, cpu);
    if (cpu.terminate) return;
    // 0045d48c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d48e  7433                   -je 0x45d4c3
    if (cpu.flags.zf)
    {
        goto L_0x0045d4c3;
    }
    // 0045d490  833de8d24d0002         +cmp dword ptr [0x4dd2e8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d497  7d32                   -jge 0x45d4cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045d4cb;
    }
    // 0045d499  a17ccf4d00             -mov eax, dword ptr [0x4dcf7c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5099388) /* 0x4dcf7c */);
    // 0045d49e  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045d4a1:
    // 0045d4a1  a37cd54f00             -mov dword ptr [0x4fd57c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231996) /* 0x4fd57c */) = cpu.eax;
    // 0045d4a6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0045d4ab  e8d01efdff             -call 0x42f380
    cpu.esp -= 4;
    sub_42f380(app, cpu);
    if (cpu.terminate) return;
    // 0045d4b0  892d0c6b4c00           -mov dword ptr [0x4c6b0c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ebp;
    // 0045d4b6  892d68d54f00           -mov dword ptr [0x4fd568], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.ebp;
    // 0045d4bc  e85f880000             -call 0x465d20
    cpu.esp -= 4;
    sub_465d20(app, cpu);
    if (cpu.terminate) return;
    // 0045d4c1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0045d4c3:
    // 0045d4c3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4c4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d4c6:
    // 0045d4c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d4c8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4c9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d4cb:
    // 0045d4cb  a17ccf4d00             -mov eax, dword ptr [0x4dcf7c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5099388) /* 0x4dcf7c */);
    // 0045d4d0  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045d4d3  ebcc                   -jmp 0x45d4a1
    goto L_0x0045d4a1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d4e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d4e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d4e2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d4e3  8b157ccf4d00           -mov edx, dword ptr [0x4dcf7c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099388) /* 0x4dcf7c */);
    // 0045d4e9  3b157cd54f00           +cmp edx, dword ptr [0x4fd57c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5231996) /* 0x4fd57c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d4ef  7c0a                   -jl 0x45d4fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d4fb;
    }
    // 0045d4f1  8b0dfc6a4c00           -mov ecx, dword ptr [0x4c6afc]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5008124) /* 0x4c6afc */);
    // 0045d4f7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045d4f9  7404                   -je 0x45d4ff
    if (cpu.flags.zf)
    {
        goto L_0x0045d4ff;
    }
L_0x0045d4fb:
    // 0045d4fb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4fc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4fd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d4fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d4ff:
    // 0045d4ff  e86ce2feff             -call 0x44b770
    cpu.esp -= 4;
    sub_44b770(app, cpu);
    if (cpu.terminate) return;
    // 0045d504  e8c70a0000             -call 0x45dfd0
    cpu.esp -= 4;
    sub_45dfd0(app, cpu);
    if (cpu.terminate) return;
    // 0045d509  83f801                 +cmp eax, 1
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
    // 0045d50c  745c                   -je 0x45d56a
    if (cpu.flags.zf)
    {
        goto L_0x0045d56a;
    }
    // 0045d50e  83f802                 +cmp eax, 2
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
    // 0045d511  0f847f000000           -je 0x45d596
    if (cpu.flags.zf)
    {
        goto L_0x0045d596;
    }
    // 0045d517  83f803                 +cmp eax, 3
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
    // 0045d51a  0f849e000000           -je 0x45d5be
    if (cpu.flags.zf)
    {
        goto L_0x0045d5be;
    }
    // 0045d520  83f804                 +cmp eax, 4
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
    // 0045d523  75d6                   -jne 0x45d4fb
    if (!cpu.flags.zf)
    {
        goto L_0x0045d4fb;
    }
    // 0045d525  e8c61dfdff             -call 0x42f2f0
    cpu.esp -= 4;
    sub_42f2f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d52a  e8198e0100             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0045d52f  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045d534  e8f7900100             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0045d539  e822a90200             -call 0x487e60
    cpu.esp -= 4;
    sub_487e60(app, cpu);
    if (cpu.terminate) return;
    // 0045d53e  e89d870000             -call 0x465ce0
    cpu.esp -= 4;
    sub_465ce0(app, cpu);
    if (cpu.terminate) return;
    // 0045d543  e8485cfdff             -call 0x433190
    cpu.esp -= 4;
    sub_433190(app, cpu);
    if (cpu.terminate) return;
    // 0045d548  e8b33b0000             -call 0x461100
    cpu.esp -= 4;
    sub_461100(app, cpu);
    if (cpu.terminate) return;
    // 0045d54d  e82e1dffff             -call 0x44f280
    cpu.esp -= 4;
    sub_44f280(app, cpu);
    if (cpu.terminate) return;
    // 0045d552  e8e5bf0100             -call 0x47953c
    cpu.esp -= 4;
    sub_47953c(app, cpu);
    if (cpu.terminate) return;
    // 0045d557  e8841fffff             -call 0x44f4e0
    cpu.esp -= 4;
    sub_44f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0045d55c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d561  e87fde0200             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0045d566  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d567  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d568  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d56a:
    // 0045d56a  e8018cfeff             -call 0x446170
    cpu.esp -= 4;
    sub_446170(app, cpu);
    if (cpu.terminate) return;
    // 0045d56f  833d6cd54f0000         +cmp dword ptr [0x4fd56c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d576  7505                   -jne 0x45d57d
    if (!cpu.flags.zf)
    {
        goto L_0x0045d57d;
    }
    // 0045d578  e8e31dfdff             -call 0x42f360
    cpu.esp -= 4;
    sub_42f360(app, cpu);
    if (cpu.terminate) return;
L_0x0045d57d:
    // 0045d57d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d57e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d580  891d0c6b4c00           -mov dword ptr [0x4c6b0c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ebx;
    // 0045d586  891d68d54f00           -mov dword ptr [0x4fd568], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.ebx;
    // 0045d58c  e86f870000             -call 0x465d00
    cpu.esp -= 4;
    sub_465d00(app, cpu);
    if (cpu.terminate) return;
    // 0045d591  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d592  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d593  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d594  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d595  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d596:
    // 0045d596  e8d58bfeff             -call 0x446170
    cpu.esp -= 4;
    sub_446170(app, cpu);
    if (cpu.terminate) return;
    // 0045d59b  e8001dfdff             -call 0x42f2a0
    cpu.esp -= 4;
    sub_42f2a0(app, cpu);
    if (cpu.terminate) return;
    // 0045d5a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045d5a5  890d68d54f00           -mov dword ptr [0x4fd568], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.ecx;
    // 0045d5ab  a364d54f00             -mov dword ptr [0x4fd564], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.eax;
    // 0045d5b0  a360d54f00             -mov dword ptr [0x4fd560], eax
    *app->getMemory<x86::reg32>(x86::reg32(5231968) /* 0x4fd560 */) = cpu.eax;
    // 0045d5b5  e826870000             -call 0x465ce0
    cpu.esp -= 4;
    sub_465ce0(app, cpu);
    if (cpu.terminate) return;
    // 0045d5ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5bb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d5be:
    // 0045d5be  e8ad8bfeff             -call 0x446170
    cpu.esp -= 4;
    sub_446170(app, cpu);
    if (cpu.terminate) return;
    // 0045d5c3  e8281dfdff             -call 0x42f2f0
    cpu.esp -= 4;
    sub_42f2f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d5c8  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045d5cd  890d68d54f00           -mov dword ptr [0x4fd568], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.ecx;
    // 0045d5d3  890d60d54f00           -mov dword ptr [0x4fd560], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231968) /* 0x4fd560 */) = cpu.ecx;
    // 0045d5d9  893564d54f00           -mov dword ptr [0x4fd564], esi
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.esi;
    // 0045d5df  e8fc860000             -call 0x465ce0
    cpu.esp -= 4;
    sub_465ce0(app, cpu);
    if (cpu.terminate) return;
    // 0045d5e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045d5e6  e855220000             -call 0x45f840
    cpu.esp -= 4;
    sub_45f840(app, cpu);
    if (cpu.terminate) return;
    // 0045d5eb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ec  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d5ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45d5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d5f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d5f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d5f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d5f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045d5f4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045d5f5  833d80d54f0000         +cmp dword ptr [0x4fd580], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232000) /* 0x4fd580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d5fc  7550                   -jne 0x45d64e
    if (!cpu.flags.zf)
    {
        goto L_0x0045d64e;
    }
    // 0045d5fe  8b0d84d54f00           -mov ecx, dword ptr [0x4fd584]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045d604  81f900020000           +cmp ecx, 0x200
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d60a  0f8c96000000           -jl 0x45d6a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d6a6;
    }
    // 0045d610  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045d615  8a2d802d4c00           -mov ch, byte ptr [0x4c2d80]
    cpu.ch = *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
    // 0045d61b  893580d54f00           -mov dword ptr [0x4fd580], esi
    *app->getMemory<x86::reg32>(x86::reg32(5232000) /* 0x4fd580 */) = cpu.esi;
    // 0045d621  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0045d623  7429                   -je 0x45d64e
    if (cpu.flags.zf)
    {
        goto L_0x0045d64e;
    }
    // 0045d625  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045d62a  8b3d406b4c00           -mov edi, dword ptr [0x4c6b40]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */);
    // 0045d630  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045d632  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045d634  7469                   -je 0x45d69f
    if (cpu.flags.zf)
    {
        goto L_0x0045d69f;
    }
    // 0045d636  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045d638:
    // 0045d638  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045d63d  a120654d00             -mov eax, dword ptr [0x4d6520]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5072160) /* 0x4d6520 */);
    // 0045d642  e8791dfdff             -call 0x42f3c0
    cpu.esp -= 4;
    sub_42f3c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d647  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0045d649  a2802d4c00             -mov byte ptr [0x4c2d80], al
    *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */) = cpu.al;
L_0x0045d64e:
    // 0045d64e  e81d34feff             -call 0x440a70
    cpu.esp -= 4;
    sub_440a70(app, cpu);
    if (cpu.terminate) return;
    // 0045d653  e898270000             -call 0x45fdf0
    cpu.esp -= 4;
    sub_45fdf0(app, cpu);
    if (cpu.terminate) return;
    // 0045d658  f60584d54f0001         +test byte ptr [0x4fd584], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5232004) /* 0x4fd584 */) & 1 /*0x1*/));
    // 0045d65f  7516                   -jne 0x45d677
    if (!cpu.flags.zf)
    {
        goto L_0x0045d677;
    }
    // 0045d661  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045d663  e818aa0100             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0045d668  a190d54f00             -mov eax, dword ptr [0x4fd590]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232016) /* 0x4fd590 */);
    // 0045d66d  e8eef0ffff             -call 0x45c760
    cpu.esp -= 4;
    sub_45c760(app, cpu);
    if (cpu.terminate) return;
    // 0045d672  e8f9200000             -call 0x45f770
    cpu.esp -= 4;
    sub_45f770(app, cpu);
    if (cpu.terminate) return;
L_0x0045d677:
    // 0045d677  a18cd54f00             -mov eax, dword ptr [0x4fd58c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232012) /* 0x4fd58c */);
    // 0045d67c  e8dff0ffff             -call 0x45c760
    cpu.esp -= 4;
    sub_45c760(app, cpu);
    if (cpu.terminate) return;
    // 0045d681  ff0584d54f00           -inc dword ptr [0x4fd584]
    (*app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */))++;
    // 0045d687  f60584d54f0001         +test byte ptr [0x4fd584], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5232004) /* 0x4fd584 */) & 1 /*0x1*/));
    // 0045d68e  0f84ec000000           -je 0x45d780
    if (cpu.flags.zf)
    {
        goto L_0x0045d780;
    }
    // 0045d694  e897270000             -call 0x45fe30
    cpu.esp -= 4;
    sub_45fe30(app, cpu);
    if (cpu.terminate) return;
    // 0045d699  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d69a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d69b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d69c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d69d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d69e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d69f:
    // 0045d69f  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045d6a4  eb92                   -jmp 0x45d638
    goto L_0x0045d638;
L_0x0045d6a6:
    // 0045d6a6  81f9c0010000           +cmp ecx, 0x1c0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(448 /*0x1c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d6ac  7c3e                   -jl 0x45d6ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d6ec;
    }
    // 0045d6ae  803d802d4c0001         +cmp byte ptr [0x4c2d80], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d6b5  7497                   -je 0x45d64e
    if (cpu.flags.zf)
    {
        goto L_0x0045d64e;
    }
    // 0045d6b7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045d6bc  8b1d406b4c00           -mov ebx, dword ptr [0x4c6b40]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */);
    // 0045d6c2  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045d6c4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045d6c6  741d                   -je 0x45d6e5
    if (cpu.flags.zf)
    {
        goto L_0x0045d6e5;
    }
    // 0045d6c8  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0045d6ca:
    // 0045d6ca  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0045d6cf  a120654d00             -mov eax, dword ptr [0x4d6520]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5072160) /* 0x4d6520 */);
    // 0045d6d4  e8e71cfdff             -call 0x42f3c0
    cpu.esp -= 4;
    sub_42f3c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d6d9  c605802d4c0001         -mov byte ptr [0x4c2d80], 1
    *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */) = 1 /*0x1*/;
    // 0045d6e0  e969ffffff             -jmp 0x45d64e
    goto L_0x0045d64e;
L_0x0045d6e5:
    // 0045d6e5  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045d6ea  ebde                   -jmp 0x45d6ca
    goto L_0x0045d6ca;
L_0x0045d6ec:
    // 0045d6ec  81f980010000           +cmp ecx, 0x180
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d6f2  7c42                   -jl 0x45d736
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d736;
    }
    // 0045d6f4  803d802d4c0002         +cmp byte ptr [0x4c2d80], 2
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d6fb  0f844dffffff           -je 0x45d64e
    if (cpu.flags.zf)
    {
        goto L_0x0045d64e;
    }
    // 0045d701  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045d706  8b15406b4c00           -mov edx, dword ptr [0x4c6b40]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */);
    // 0045d70c  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045d70e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045d710  741d                   -je 0x45d72f
    if (cpu.flags.zf)
    {
        goto L_0x0045d72f;
    }
    // 0045d712  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0045d714:
    // 0045d714  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d719  a120654d00             -mov eax, dword ptr [0x4d6520]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5072160) /* 0x4d6520 */);
    // 0045d71e  e89d1cfdff             -call 0x42f3c0
    cpu.esp -= 4;
    sub_42f3c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d723  c605802d4c0002         -mov byte ptr [0x4c2d80], 2
    *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */) = 2 /*0x2*/;
    // 0045d72a  e91fffffff             -jmp 0x45d64e
    goto L_0x0045d64e;
L_0x0045d72f:
    // 0045d72f  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045d734  ebde                   -jmp 0x45d714
    goto L_0x0045d714;
L_0x0045d736:
    // 0045d736  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d73c  0f8c0cffffff           -jl 0x45d64e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d64e;
    }
    // 0045d742  803d802d4c0003         +cmp byte ptr [0x4c2d80], 3
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045d749  0f84fffeffff           -je 0x45d64e
    if (cpu.flags.zf)
    {
        goto L_0x0045d64e;
    }
    // 0045d74f  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0045d754  a1406b4c00             -mov eax, dword ptr [0x4c6b40]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */);
    // 0045d759  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0045d75b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d75d  741a                   -je 0x45d779
    if (cpu.flags.zf)
    {
        goto L_0x0045d779;
    }
    // 0045d75f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045d761:
    // 0045d761  a120654d00             -mov eax, dword ptr [0x4d6520]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5072160) /* 0x4d6520 */);
    // 0045d766  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045d768  e8531cfdff             -call 0x42f3c0
    cpu.esp -= 4;
    sub_42f3c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d76d  c605802d4c0003         -mov byte ptr [0x4c2d80], 3
    *app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */) = 3 /*0x3*/;
    // 0045d774  e9d5feffff             -jmp 0x45d64e
    goto L_0x0045d64e;
L_0x0045d779:
    // 0045d779  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0045d77e  ebe1                   -jmp 0x45d761
    goto L_0x0045d761;
L_0x0045d780:
    // 0045d780  e88b17fdff             -call 0x42ef10
    cpu.esp -= 4;
    sub_42ef10(app, cpu);
    if (cpu.terminate) return;
    // 0045d785  e8a6260000             -call 0x45fe30
    cpu.esp -= 4;
    sub_45fe30(app, cpu);
    if (cpu.terminate) return;
    // 0045d78a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d78b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d78c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d78d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d78e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d78f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_45d790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d790  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d791  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d792  e809850000             -call 0x465ca0
    cpu.esp -= 4;
    sub_465ca0(app, cpu);
    if (cpu.terminate) return;
    // 0045d797  e854140000             -call 0x45ebf0
    cpu.esp -= 4;
    sub_45ebf0(app, cpu);
    if (cpu.terminate) return;
    // 0045d79c  bae4954300             -mov edx, 0x4395e4
    cpu.edx = 4429284 /*0x4395e4*/;
    // 0045d7a1  a18cd54f00             -mov eax, dword ptr [0x4fd58c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232012) /* 0x4fd58c */);
    // 0045d7a6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d7a8  e8f3efffff             -call 0x45c7a0
    cpu.esp -= 4;
    sub_45c7a0(app, cpu);
    if (cpu.terminate) return;
    // 0045d7ad  e8cec4fcff             -call 0x429c80
    cpu.esp -= 4;
    sub_429c80(app, cpu);
    if (cpu.terminate) return;
    // 0045d7b2  e819e7fdff             -call 0x43bed0
    cpu.esp -= 4;
    sub_43bed0(app, cpu);
    if (cpu.terminate) return;
    // 0045d7b7  e864c3ffff             -call 0x459b20
    cpu.esp -= 4;
    sub_459b20(app, cpu);
    if (cpu.terminate) return;
    // 0045d7bc  e8af150000             -call 0x45ed70
    cpu.esp -= 4;
    sub_45ed70(app, cpu);
    if (cpu.terminate) return;
    // 0045d7c1  e84a450000             -call 0x461d10
    cpu.esp -= 4;
    sub_461d10(app, cpu);
    if (cpu.terminate) return;
    // 0045d7c6  e8c5c4fcff             -call 0x429c90
    cpu.esp -= 4;
    sub_429c90(app, cpu);
    if (cpu.terminate) return;
    // 0045d7cb  e840a8feff             -call 0x448010
    cpu.esp -= 4;
    sub_448010(app, cpu);
    if (cpu.terminate) return;
    // 0045d7d0  a190d54f00             -mov eax, dword ptr [0x4fd590]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232016) /* 0x4fd590 */);
    // 0045d7d5  e846f1ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0045d7da  a18cd54f00             -mov eax, dword ptr [0x4fd58c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232012) /* 0x4fd58c */);
    // 0045d7df  e83cf1ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0045d7e4  e8a789feff             -call 0x446190
    cpu.esp -= 4;
    sub_446190(app, cpu);
    if (cpu.terminate) return;
    // 0045d7e9  e812000000             -call 0x45d800
    cpu.esp -= 4;
    sub_45d800(app, cpu);
    if (cpu.terminate) return;
    // 0045d7ee  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7ef  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d7f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d800  e89b180100             -call 0x46f0a0
    cpu.esp -= 4;
    sub_46f0a0(app, cpu);
    if (cpu.terminate) return;
    // 0045d805  a320d34d00             -mov dword ptr [0x4dd320], eax
    *app->getMemory<x86::reg32>(x86::reg32(5100320) /* 0x4dd320 */) = cpu.eax;
    // 0045d80a  a2aedf4d00             -mov byte ptr [0x4ddfae], al
    *app->getMemory<x86::reg8>(x86::reg32(5103534) /* 0x4ddfae */) = cpu.al;
    // 0045d80f  e83c190100             -call 0x46f150
    cpu.esp -= 4;
    sub_46f150(app, cpu);
    if (cpu.terminate) return;
    // 0045d814  a324d34d00             -mov dword ptr [0x4dd324], eax
    *app->getMemory<x86::reg32>(x86::reg32(5100324) /* 0x4dd324 */) = cpu.eax;
    // 0045d819  a2afdf4d00             -mov byte ptr [0x4ddfaf], al
    *app->getMemory<x86::reg8>(x86::reg32(5103535) /* 0x4ddfaf */) = cpu.al;
    // 0045d81e  a028d34d00             -mov al, byte ptr [0x4dd328]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5100328) /* 0x4dd328 */);
    // 0045d823  a2b1df4d00             -mov byte ptr [0x4ddfb1], al
    *app->getMemory<x86::reg8>(x86::reg32(5103537) /* 0x4ddfb1 */) = cpu.al;
    // 0045d828  e8f35cfdff             -call 0x433520
    cpu.esp -= 4;
    sub_433520(app, cpu);
    if (cpu.terminate) return;
    // 0045d82d  a32cd34d00             -mov dword ptr [0x4dd32c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5100332) /* 0x4dd32c */) = cpu.eax;
    // 0045d832  a2b0df4d00             -mov byte ptr [0x4ddfb0], al
    *app->getMemory<x86::reg8>(x86::reg32(5103536) /* 0x4ddfb0 */) = cpu.al;
    // 0045d837  a12c965100             -mov eax, dword ptr [0x51962c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346860) /* 0x51962c */);
    // 0045d83c  a330d34d00             -mov dword ptr [0x4dd330], eax
    *app->getMemory<x86::reg32>(x86::reg32(5100336) /* 0x4dd330 */) = cpu.eax;
    // 0045d841  a2b2df4d00             -mov byte ptr [0x4ddfb2], al
    *app->getMemory<x86::reg8>(x86::reg32(5103538) /* 0x4ddfb2 */) = cpu.al;
    // 0045d846  e9c5b6faff             -jmp 0x408f10
    return sub_408f10(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d850  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d851  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045d853  a104d34d00             -mov eax, dword ptr [0x4dd304]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100292) /* 0x4dd304 */);
    // 0045d858  891564d54f00           -mov dword ptr [0x4fd564], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.edx;
    // 0045d85e  891568d54f00           -mov dword ptr [0x4fd568], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.edx;
    // 0045d864  89156cd54f00           -mov dword ptr [0x4fd56c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */) = cpu.edx;
    // 0045d86a  891570d54f00           -mov dword ptr [0x4fd570], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */) = cpu.edx;
    // 0045d870  891574d54f00           -mov dword ptr [0x4fd574], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */) = cpu.edx;
    // 0045d876  891580d54f00           -mov dword ptr [0x4fd580], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232000) /* 0x4fd580 */) = cpu.edx;
    // 0045d87c  891584d54f00           -mov dword ptr [0x4fd584], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */) = cpu.edx;
    // 0045d882  e809a7feff             -call 0x447f90
    cpu.esp -= 4;
    sub_447f90(app, cpu);
    if (cpu.terminate) return;
    // 0045d887  e844c3fcff             -call 0x429bd0
    cpu.esp -= 4;
    sub_429bd0(app, cpu);
    if (cpu.terminate) return;
    // 0045d88c  e81fc3ffff             -call 0x459bb0
    cpu.esp -= 4;
    sub_459bb0(app, cpu);
    if (cpu.terminate) return;
    // 0045d891  e89aeefdff             -call 0x43c730
    cpu.esp -= 4;
    sub_43c730(app, cpu);
    if (cpu.terminate) return;
    // 0045d896  e855160000             -call 0x45eef0
    cpu.esp -= 4;
    sub_45eef0(app, cpu);
    if (cpu.terminate) return;
    // 0045d89b  e8d0c1fcff             -call 0x429a70
    cpu.esp -= 4;
    sub_429a70(app, cpu);
    if (cpu.terminate) return;
    // 0045d8a0  e8fbcfffff             -call 0x45a8a0
    cpu.esp -= 4;
    sub_45a8a0(app, cpu);
    if (cpu.terminate) return;
    // 0045d8a5  e816840000             -call 0x465cc0
    cpu.esp -= 4;
    sub_465cc0(app, cpu);
    if (cpu.terminate) return;
    // 0045d8aa  a11cdb4d00             -mov eax, dword ptr [0x4ddb1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5102364) /* 0x4ddb1c */);
    // 0045d8af  a388d54f00             -mov dword ptr [0x4fd588], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232008) /* 0x4fd588 */) = cpu.eax;
    // 0045d8b4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d8b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d8c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d8c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d8c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d8c3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045d8c8  b88cb34b00             -mov eax, 0x4bb38c
    cpu.eax = 4961164 /*0x4bb38c*/;
    // 0045d8cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045d8cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d8d1  891560d54f00           -mov dword ptr [0x4fd560], edx
    *app->getMemory<x86::reg32>(x86::reg32(5231968) /* 0x4fd560 */) = cpu.edx;
    // 0045d8d7  890d64d54f00           -mov dword ptr [0x4fd564], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.ecx;
    // 0045d8dd  890d68d54f00           -mov dword ptr [0x4fd568], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */) = cpu.ecx;
    // 0045d8e3  890d6cd54f00           -mov dword ptr [0x4fd56c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231980) /* 0x4fd56c */) = cpu.ecx;
    // 0045d8e9  890d70d54f00           -mov dword ptr [0x4fd570], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231984) /* 0x4fd570 */) = cpu.ecx;
    // 0045d8ef  890d74d54f00           -mov dword ptr [0x4fd574], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5231988) /* 0x4fd574 */) = cpu.ecx;
    // 0045d8f5  890d80d54f00           -mov dword ptr [0x4fd580], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232000) /* 0x4fd580 */) = cpu.ecx;
    // 0045d8fb  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 0045d900  890d84d54f00           -mov dword ptr [0x4fd584], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */) = cpu.ecx;
    // 0045d906  e825f0ffff             -call 0x45c930
    cpu.esp -= 4;
    sub_45c930(app, cpu);
    if (cpu.terminate) return;
    // 0045d90b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 0045d910  a390d54f00             -mov dword ptr [0x4fd590], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232016) /* 0x4fd590 */) = cpu.eax;
    // 0045d915  b894b34b00             -mov eax, 0x4bb394
    cpu.eax = 4961172 /*0x4bb394*/;
    // 0045d91a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0045d91f  e80cf0ffff             -call 0x45c930
    cpu.esp -= 4;
    sub_45c930(app, cpu);
    if (cpu.terminate) return;
    // 0045d924  bad0bb4300             -mov edx, 0x43bbd0
    cpu.edx = 4438992 /*0x43bbd0*/;
    // 0045d929  a38cd54f00             -mov dword ptr [0x4fd58c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232012) /* 0x4fd58c */) = cpu.eax;
    // 0045d92e  a190d54f00             -mov eax, dword ptr [0x4fd590]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232016) /* 0x4fd590 */);
    // 0045d933  e818efffff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 0045d938  a104d34d00             -mov eax, dword ptr [0x4dd304]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100292) /* 0x4dd304 */);
    // 0045d93d  e84ea6feff             -call 0x447f90
    cpu.esp -= 4;
    sub_447f90(app, cpu);
    if (cpu.terminate) return;
    // 0045d942  e899c2fcff             -call 0x429be0
    cpu.esp -= 4;
    sub_429be0(app, cpu);
    if (cpu.terminate) return;
    // 0045d947  e834c2ffff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 0045d94c  e8df430000             -call 0x461d30
    cpu.esp -= 4;
    sub_461d30(app, cpu);
    if (cpu.terminate) return;
    // 0045d951  e86ae7fdff             -call 0x43c0c0
    cpu.esp -= 4;
    sub_43c0c0(app, cpu);
    if (cpu.terminate) return;
    // 0045d956  e805820000             -call 0x465b60
    cpu.esp -= 4;
    sub_465b60(app, cpu);
    if (cpu.terminate) return;
    // 0045d95b  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0045d960  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0045d965  e886be0000             -call 0x4697f0
    cpu.esp -= 4;
    sub_4697f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d96a  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045d96f  bae4954300             -mov edx, 0x4395e4
    cpu.edx = 4429284 /*0x4395e4*/;
    // 0045d974  e877be0000             -call 0x4697f0
    cpu.esp -= 4;
    sub_4697f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d979  e832c2fcff             -call 0x429bb0
    cpu.esp -= 4;
    sub_429bb0(app, cpu);
    if (cpu.terminate) return;
    // 0045d97e  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0045d983  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045d985  e866be0000             -call 0x4697f0
    cpu.esp -= 4;
    sub_4697f0(app, cpu);
    if (cpu.terminate) return;
    // 0045d98a  e88158fdff             -call 0x433210
    cpu.esp -= 4;
    sub_433210(app, cpu);
    if (cpu.terminate) return;
    // 0045d98f  a18cd54f00             -mov eax, dword ptr [0x4fd58c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232012) /* 0x4fd58c */);
    // 0045d994  e8b7eeffff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 0045d999  e8c2e6fdff             -call 0x43c060
    cpu.esp -= 4;
    sub_43c060(app, cpu);
    if (cpu.terminate) return;
    // 0045d99e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d99f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9a0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45d9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045d9b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045d9b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045d9b2  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045d9b8  833de8d24d0002         +cmp dword ptr [0x4dd2e8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045d9bf  7c09                   -jl 0x45d9ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045d9ca;
    }
L_0x0045d9c1:
    // 0045d9c1  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045d9c7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9c8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045d9c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045d9ca:
    // 0045d9ca  8b0df86a4c00           -mov ecx, dword ptr [0x4c6af8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5008120) /* 0x4c6af8 */);
    // 0045d9d0  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0045d9d5  41                     -inc ecx
    (cpu.ecx)++;
    // 0045d9d6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045d9d8  890df86a4c00           -mov dword ptr [0x4c6af8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008120) /* 0x4c6af8 */) = cpu.ecx;
    // 0045d9de  e87d4b0100             -call 0x472560
    cpu.esp -= 4;
    sub_472560(app, cpu);
    if (cpu.terminate) return;
    // 0045d9e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045d9e5  74da                   -je 0x45d9c1
    if (cpu.flags.zf)
    {
        goto L_0x0045d9c1;
    }
    // 0045d9e7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d9e8  8b1df86a4c00           -mov ebx, dword ptr [0x4c6af8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5008120) /* 0x4c6af8 */);
    // 0045d9ee  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045d9ef  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045d9f3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045d9f4  6850b34b00             -push 0x4bb350
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4961104 /*0x4bb350*/;
    cpu.esp -= 4;
    // 0045d9f9  8d842410020000         -lea eax, [esp + 0x210]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0045da00  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045da01  e81bca0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0045da06  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045da09  e826890100             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 0045da0e  8d842404020000         -lea eax, [esp + 0x204]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0045da15  e87ed80100             -call 0x47b298
    cpu.esp -= 4;
    sub_47b298(app, cpu);
    if (cpu.terminate) return;
    // 0045da1a  e83d890100             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0045da1f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045da20  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0045da26  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045da27  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045da28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45da30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045da30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045da31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045da32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045da34  833d006b4c0000         +cmp dword ptr [0x4c6b00], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5008128) /* 0x4c6b00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045da3b  743b                   -je 0x45da78
    if (cpu.flags.zf)
    {
        goto L_0x0045da78;
    }
    // 0045da3d  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045da45  7534                   -jne 0x45da7b
    if (!cpu.flags.zf)
    {
        goto L_0x0045da7b;
    }
    // 0045da47  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045da4e  752b                   -jne 0x45da7b
    if (!cpu.flags.zf)
    {
        goto L_0x0045da7b;
    }
    // 0045da50  8b0d44d34d00           -mov ecx, dword ptr [0x4dd344]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045da56  49                     -dec ecx
    (cpu.ecx)--;
    // 0045da57  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045da59  7c1d                   -jl 0x45da78
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045da78;
    }
    // 0045da5b  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0045da62  42                     -inc edx
    (cpu.edx)++;
    // 0045da63  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0045da65:
    // 0045da65  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045da67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045da69  e846100000             -call 0x45eab4
    cpu.esp -= 4;
    sub_45eab4(app, cpu);
    if (cpu.terminate) return;
    // 0045da6e  49                     -dec ecx
    (cpu.ecx)--;
    // 0045da6f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045da72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045da74  7def                   -jge 0x45da65
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045da65;
    }
    // 0045da76  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0045da78:
    // 0045da78  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045da79  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045da7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045da7b:
    // 0045da7b  0fbe4201               -movsx eax, byte ptr [edx + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */)));
    // 0045da7f  e86c0c0000             -call 0x45e6f0
    cpu.esp -= 4;
    sub_45e6f0(app, cpu);
    if (cpu.terminate) return;
    // 0045da84  8b3de8d24d00           -mov edi, dword ptr [0x4dd2e8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045da8a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045da8d  83ff04                 +cmp edi, 4
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
    // 0045da90  7416                   -je 0x45daa8
    if (cpu.flags.zf)
    {
        goto L_0x0045daa8;
    }
    // 0045da92  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045da99  7531                   -jne 0x45dacc
    if (!cpu.flags.zf)
    {
        goto L_0x0045dacc;
    }
    // 0045da9b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045daa0  e80f100000             -call 0x45eab4
    cpu.esp -= 4;
    sub_45eab4(app, cpu);
    if (cpu.terminate) return;
    // 0045daa5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045daa6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045daa7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045daa8:
    // 0045daa8  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045daad  e856150200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045dab2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dab4  e8871fffff             -call 0x44fa40
    cpu.esp -= 4;
    sub_44fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045dab9  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045daba  e8c10e0000             -call 0x45e980
    cpu.esp -= 4;
    sub_45e980(app, cpu);
    if (cpu.terminate) return;
    // 0045dabf  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045dac4  e857150200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045dac9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045daca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dacb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045dacc:
    // 0045dacc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dace  e8e10f0000             -call 0x45eab4
    cpu.esp -= 4;
    sub_45eab4(app, cpu);
    if (cpu.terminate) return;
    // 0045dad3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dad4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45dae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dae0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045dae1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dae2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045dae3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dae4  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045dae7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045dae9  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045daf0  755e                   -jne 0x45db50
    if (!cpu.flags.zf)
    {
        goto L_0x0045db50;
    }
    // 0045daf2  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045dafa  7454                   -je 0x45db50
    if (cpu.flags.zf)
    {
        goto L_0x0045db50;
    }
    // 0045dafc  b205                   -mov dl, 5
    cpu.dl = 5 /*0x5*/;
    // 0045dafe  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045db03  881424                 -mov byte ptr [esp], dl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 0045db06  e8fd140200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045db0b  a1ecd24d00             -mov eax, dword ptr [0x4dd2ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 0045db10  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045db12  e89d0f0000             -call 0x45eab4
    cpu.esp -= 4;
    sub_45eab4(app, cpu);
    if (cpu.terminate) return;
    // 0045db17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045db19  7512                   -jne 0x45db2d
    if (!cpu.flags.zf)
    {
        goto L_0x0045db2d;
    }
    // 0045db1b  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045db20  e8fb140200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x0045db25:
    // 0045db25  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045db28  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045db29  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045db2a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045db2b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045db2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045db2d:
    // 0045db2d  8d442401               -lea eax, [esp + 1]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0045db31  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0045db36  e8450c0000             -call 0x45e780
    cpu.esp -= 4;
    sub_45e780(app, cpu);
    if (cpu.terminate) return;
    // 0045db3b  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045db40  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045db42  e8d9140200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045db47  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045db49  e86221ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045db4e  ebd5                   -jmp 0x45db25
    goto L_0x0045db25;
L_0x0045db50:
    // 0045db50  e8bb0b0000             -call 0x45e710
    cpu.esp -= 4;
    sub_45e710(app, cpu);
    if (cpu.terminate) return;
    // 0045db55  8b0de8d24d00           -mov ecx, dword ptr [0x4dd2e8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045db5b  a2b5d54f00             -mov byte ptr [0x4fd5b5], al
    *app->getMemory<x86::reg8>(x86::reg32(5232053) /* 0x4fd5b5 */) = cpu.al;
    // 0045db60  83f904                 +cmp ecx, 4
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
    // 0045db63  7410                   -je 0x45db75
    if (cpu.flags.zf)
    {
        goto L_0x0045db75;
    }
    // 0045db65  a1ecd24d00             -mov eax, dword ptr [0x4dd2ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 0045db6a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045db6c  e8430f0000             -call 0x45eab4
    cpu.esp -= 4;
    sub_45eab4(app, cpu);
    if (cpu.terminate) return;
    // 0045db71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045db73  74b0                   -je 0x45db25
    if (cpu.flags.zf)
    {
        goto L_0x0045db25;
    }
L_0x0045db75:
    // 0045db75  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045db76  b405                   -mov ah, 5
    cpu.ah = 5 /*0x5*/;
    // 0045db78  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045db7d  bfb6d54f00             -mov edi, 0x4fd5b6
    cpu.edi = 5232054 /*0x4fd5b6*/;
    // 0045db82  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0045db87  bab4d54f00             -mov edx, 0x4fd5b4
    cpu.edx = 5232052 /*0x4fd5b4*/;
    // 0045db8c  8825b4d54f00           -mov byte ptr [0x4fd5b4], ah
    *app->getMemory<x86::reg8>(x86::reg32(5232052) /* 0x4fd5b4 */) = cpu.ah;
    // 0045db92  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045db93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045db95  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045db98  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045db9a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045db9c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045db9f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dba1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dba2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dba4  e80721ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045dba9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbaa  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0045dbad  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbae  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbaf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbb0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45dbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dbc0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dbc1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dbc2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dbc3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045dbc5  8b3d98d54f00           -mov edi, dword ptr [0x4fd598]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5232024) /* 0x4fd598 */);
    // 0045dbcb  8b0d94d54f00           -mov ecx, dword ptr [0x4fd594]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5232020) /* 0x4fd594 */);
    // 0045dbd1  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0045dbd4  46                     -inc esi
    (cpu.esi)++;
    // 0045dbd5  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045dbd7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045dbd9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dbda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dbdc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dbdf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dbe1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dbe3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dbe6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dbe8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbe9  011594d54f00           -add dword ptr [0x4fd594], edx
    (*app->getMemory<x86::reg32>(x86::reg32(5232020) /* 0x4fd594 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045dbef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbf0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbf1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dbf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45dc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dc00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045dc01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dc02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045dc03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dc04  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dc05  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045dc06  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0045dc0c  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0045dc11  be14d34d00             -mov esi, 0x4dd314
    cpu.esi = 5100308 /*0x4dd314*/;
    // 0045dc16  8d7c2464               -lea edi, [esp + 0x64]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0045dc1a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dc1b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dc1d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dc20  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dc22  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dc24  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dc27  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dc29  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dc2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045dc2c  b9d8d24d00             -mov ecx, 0x4dd2d8
    cpu.ecx = 5100248 /*0x4dd2d8*/;
    // 0045dc31  b8002d0000             -mov eax, 0x2d00
    cpu.eax = 11520 /*0x2d00*/;
    // 0045dc36  891594d54f00           -mov dword ptr [0x4fd594], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232020) /* 0x4fd594 */) = cpu.edx;
    // 0045dc3c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045dc41  890d98d54f00           -mov dword ptr [0x4fd598], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232024) /* 0x4fd598 */) = cpu.ecx;
    // 0045dc47  e83419ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045dc4c  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045dc54  0f84e0000000           -je 0x45dd3a
    if (cpu.flags.zf)
    {
        goto L_0x0045dd3a;
    }
    // 0045dc5a  8b1d284a4c00           -mov ebx, dword ptr [0x4c4a28]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */);
    // 0045dc60  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045dc62  741c                   -je 0x45dc80
    if (cpu.flags.zf)
    {
        goto L_0x0045dc80;
    }
    // 0045dc64  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045dc69  bfe4d74d00             -mov edi, 0x4dd7e4
    cpu.edi = 5101540 /*0x4dd7e4*/;
    // 0045dc6e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045dc70  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dc71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dc73  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dc76  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dc78  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dc7a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dc7d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dc7f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045dc80:
    // 0045dc80  8b35244a4c00           -mov esi, dword ptr [0x4c4a24]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 0045dc86  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045dc88  0f8587000000           -jne 0x45dd15
    if (!cpu.flags.zf)
    {
        goto L_0x0045dd15;
    }
L_0x0045dc8e:
    // 0045dc8e  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 0045dc93  be64df4d00             -mov esi, 0x4ddf64
    cpu.esi = 5103460 /*0x4ddf64*/;
    // 0045dc98  bff6d74d00             -mov edi, 0x4dd7f6
    cpu.edi = 5101558 /*0x4dd7f6*/;
    // 0045dc9d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dc9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dca0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dca3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dca5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dca7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dcaa  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dcac  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dcad  b404                   -mov ah, 4
    cpu.ah = 4 /*0x4*/;
    // 0045dcaf  bfb0050000             -mov edi, 0x5b0
    cpu.edi = 1456 /*0x5b0*/;
    // 0045dcb4  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045dcb7  89bc2490000000         -mov dword ptr [esp + 0x90], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edi;
L_0x0045dcbe:
    // 0045dcbe  bd62000000             -mov ebp, 0x62
    cpu.ebp = 98 /*0x62*/;
L_0x0045dcc3:
    // 0045dcc3  8d7c2401               -lea edi, [esp + 1]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0045dcc7  8b3598d54f00           -mov esi, dword ptr [0x4fd598]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5232024) /* 0x4fd598 */);
    // 0045dccd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0045dccf  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045dcd1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dcd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dcd4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dcd7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dcd9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dcdb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dcde  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dce0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dce1  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0045dce4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dce6  e8c51fffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045dceb  a198d54f00             -mov eax, dword ptr [0x4fd598]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232024) /* 0x4fd598 */);
    // 0045dcf0  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0045dcf7  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0045dcf9  83ea62                 -sub edx, 0x62
    (cpu.edx) -= x86::reg32(x86::sreg32(98 /*0x62*/));
    // 0045dcfc  a398d54f00             -mov dword ptr [0x4fd598], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232024) /* 0x4fd598 */) = cpu.eax;
    // 0045dd01  89942490000000         -mov dword ptr [esp + 0x90], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0045dd08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045dd0a  7e2e                   -jle 0x45dd3a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dd3a;
    }
    // 0045dd0c  83fa62                 +cmp edx, 0x62
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045dd0f  7dad                   -jge 0x45dcbe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045dcbe;
    }
    // 0045dd11  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045dd13  ebae                   -jmp 0x45dcc3
    goto L_0x0045dcc3;
L_0x0045dd15:
    // 0045dd15  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045dd1a  bfd4d74d00             -mov edi, 0x4dd7d4
    cpu.edi = 5101524 /*0x4dd7d4*/;
    // 0045dd1f  81c6b0020000           -add esi, 0x2b0
    (cpu.esi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 0045dd25  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dd26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dd28  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dd2b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dd2d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dd2f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dd32  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dd34  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd35  e954ffffff             -jmp 0x45dc8e
    goto L_0x0045dc8e;
L_0x0045dd3a:
    // 0045dd3a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045dd3f  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 0045dd44  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 0045dd49  e83218ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045dd4e  8b152ee54d00           -mov edx, dword ptr [0x4de52e]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104942) /* 0x4de52e */);
    // 0045dd54  8d742464               -lea esi, [esp + 0x64]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0045dd58  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045dd5b  bf14d34d00             -mov edi, 0x4dd314
    cpu.edi = 5100308 /*0x4dd314*/;
    // 0045dd60  8915ecd24d00           -mov dword ptr [0x4dd2ec], edx
    *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */) = cpu.edx;
    // 0045dd66  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dd67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dd69  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dd6c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dd6e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dd70  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dd73  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dd75  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dd76  8b35284a4c00           -mov esi, dword ptr [0x4c4a28]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */);
    // 0045dd7c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045dd7e  741c                   -je 0x45dd9c
    if (cpu.flags.zf)
    {
        goto L_0x0045dd9c;
    }
    // 0045dd80  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045dd85  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0045dd87  bee4d74d00             -mov esi, 0x4dd7e4
    cpu.esi = 5101540 /*0x4dd7e4*/;
    // 0045dd8c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dd8d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dd8f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dd92  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045dd94  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045dd96  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045dd99  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045dd9b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045dd9c:
    // 0045dd9c  8b3d244a4c00           -mov edi, dword ptr [0x4c4a24]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 0045dda2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045dda4  752c                   -jne 0x45ddd2
    if (!cpu.flags.zf)
    {
        goto L_0x0045ddd2;
    }
L_0x0045dda6:
    // 0045dda6  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 0045ddab  bef6d74d00             -mov esi, 0x4dd7f6
    cpu.esi = 5101558 /*0x4dd7f6*/;
    // 0045ddb0  bf64df4d00             -mov edi, 0x4ddf64
    cpu.edi = 5103460 /*0x4ddf64*/;
    // 0045ddb5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ddb6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ddb8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045ddbb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045ddbd  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045ddbf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045ddc2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045ddc4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddc5  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0045ddcb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddcc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddcd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddce  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddcf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddd0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ddd2:
    // 0045ddd2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045ddd7  bed4d74d00             -mov esi, 0x4dd7d4
    cpu.esi = 5101524 /*0x4dd7d4*/;
    // 0045dddc  81c7b0020000           -add edi, 0x2b0
    (cpu.edi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 0045dde2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dde3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dde5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045dde8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045ddea  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045ddec  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045ddef  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045ddf1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ddf2  ebb2                   -jmp 0x45dda6
    goto L_0x0045dda6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45de00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045de00  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045de03  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045de0a  7e04                   -jle 0x45de10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045de10;
    }
    // 0045de0c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045de0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045de10:
    // 0045de10  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045de11  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045de12  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045de13  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045de14  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045de15  e82e850100             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0045de1a  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045de1f  e80c880100             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0045de24  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045de29  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045de2d  e8ee87feff             -call 0x446620
    cpu.esp -= 4;
    sub_446620(app, cpu);
    if (cpu.terminate) return;
    // 0045de32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045de34  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045de35:
    // 0045de35  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045de37  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045de39  3c00                   +cmp al, 0
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
    // 0045de3b  7410                   -je 0x45de4d
    if (cpu.flags.zf)
    {
        goto L_0x0045de4d;
    }
    // 0045de3d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045de40  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045de43  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045de46  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045de49  3c00                   +cmp al, 0
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
    // 0045de4b  75e8                   -jne 0x45de35
    if (!cpu.flags.zf)
    {
        goto L_0x0045de35;
    }
L_0x0045de4d:
    // 0045de4d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de4e  be9cb34b00             -mov esi, 0x4bb39c
    cpu.esi = 4961180 /*0x4bb39c*/;
    // 0045de53  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045de57  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045de58  2bc9                   +sub ecx, ecx
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
    // 0045de5a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0045de5b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0045de5d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045de5f  4f                     -dec edi
    (cpu.edi)--;
L_0x0045de60:
    // 0045de60  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0045de62  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045de64  3c00                   +cmp al, 0
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
    // 0045de66  7410                   -je 0x45de78
    if (cpu.flags.zf)
    {
        goto L_0x0045de78;
    }
    // 0045de68  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045de6b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045de6e  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045de71  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045de74  3c00                   +cmp al, 0
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
    // 0045de76  75e8                   -jne 0x45de60
    if (!cpu.flags.zf)
    {
        goto L_0x0045de60;
    }
L_0x0045de78:
    // 0045de78  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045de79  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045de7d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045de7f  49                     -dec ecx
    (cpu.ecx)--;
    // 0045de80  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045de82  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045de84  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0045de86  49                     -dec ecx
    (cpu.ecx)--;
    // 0045de87  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045de89  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0045de8b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045de92  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045de94  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045de96  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045de99  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045de9b  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0045dea0  bbdc000000             -mov ebx, 0xdc
    cpu.ebx = 220 /*0xdc*/;
    // 0045dea5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045dea7  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045deab  e8709d0000             -call 0x467c20
    cpu.esp -= 4;
    sub_467c20(app, cpu);
    if (cpu.terminate) return;
    // 0045deb0  e8ab9f0200             -call 0x487e60
    cpu.esp -= 4;
    sub_487e60(app, cpu);
    if (cpu.terminate) return;
    // 0045deb5  e88e840100             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0045deba  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0045debf  e86c870100             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0045dec4  e893840100             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0045dec9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045deca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045decb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045decc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045decd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dece  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0045ded1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045def0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045def1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045def3  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0045def6  3c03                   +cmp al, 3
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
    // 0045def8  771d                   -ja 0x45df17
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045df17;
    }
    // 0045defa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0045deff  ff2485e0de4500         -jmp dword ptr [eax*4 + 0x45dee0]
    cpu.ip = *app->getMemory<x86::reg32>(4579040 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045df06:
    // 0045df06  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df0d  740a                   -je 0x45df19
    if (cpu.flags.zf)
    {
        goto L_0x0045df19;
    }
    // 0045df0f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0045df12  a3a0d54f00             -mov dword ptr [0x4fd5a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */) = cpu.eax;
L_0x0045df17:
    // 0045df17  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045df19:
    // 0045df19  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045df1e  e8e5100200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045df23  833da0d54f0000         +cmp dword ptr [0x4fd5a0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045df2a  7519                   -jne 0x45df45
    if (!cpu.flags.zf)
    {
        goto L_0x0045df45;
    }
    // 0045df2c  e83f080000             -call 0x45e770
    cpu.esp -= 4;
    sub_45e770(app, cpu);
    if (cpu.terminate) return;
    // 0045df31  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045df36  a3a0d54f00             -mov dword ptr [0x4fd5a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */) = cpu.eax;
    // 0045df3b  894204                 -mov dword ptr [edx + 4], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045df3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045df40  e86b1dffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
L_0x0045df45:
    // 0045df45  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045df4a  e8d1100200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045df4f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df50  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045df51:
    // 0045df51  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045df59  740c                   -je 0x45df67
    if (cpu.flags.zf)
    {
        goto L_0x0045df67;
    }
    // 0045df5b  c7059cd54f0001000000   -mov dword ptr [0x4fd59c], 1
    *app->getMemory<x86::reg32>(x86::reg32(5232028) /* 0x4fd59c */) = 1 /*0x1*/;
    // 0045df65  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045df67:
    // 0045df67  66c705aae44d001200     -mov word ptr [0x4de4aa], 0x12
    *app->getMemory<x86::reg16>(x86::reg32(5104810) /* 0x4de4aa */) = 18 /*0x12*/;
    // 0045df70  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df71  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045df72:
    // 0045df72  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045df7a  759b                   -jne 0x45df17
    if (!cpu.flags.zf)
    {
        goto L_0x0045df17;
    }
    // 0045df7c  66c705aae44d001500     -mov word ptr [0x4de4aa], 0x15
    *app->getMemory<x86::reg16>(x86::reg32(5104810) /* 0x4de4aa */) = 21 /*0x15*/;
    // 0045df85  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df86  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045df87:
    // 0045df87  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045df8f  750b                   -jne 0x45df9c
    if (!cpu.flags.zf)
    {
        goto L_0x0045df9c;
    }
    // 0045df91  66c705aae44d001600     -mov word ptr [0x4de4aa], 0x16
    *app->getMemory<x86::reg16>(x86::reg32(5104810) /* 0x4de4aa */) = 22 /*0x16*/;
    // 0045df9a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045df9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045df9c:
    // 0045df9c  a1784a4c00             -mov eax, dword ptr [0x4c4a78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999800) /* 0x4c4a78 */);
    // 0045dfa1  e862100200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045dfa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045dfa8  e8931affff             -call 0x44fa40
    cpu.esp -= 4;
    sub_44fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045dfad  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045dfae  66c70445b8e44d001600   -mov word ptr [eax*2 + 0x4de4b8], 0x16
    *app->getMemory<x86::reg16>(x86::reg32(5104824) /* 0x4de4b8 */ + cpu.eax * 2) = 22 /*0x16*/;
    // 0045dfb8  a1784a4c00             -mov eax, dword ptr [0x4c4a78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999800) /* 0x4c4a78 */);
    // 0045dfbd  e85e100200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045dfc2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dfc3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45dfd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045dfd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045dfd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045dfd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045dfd3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045dfd4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045dfd5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045dfd6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045dfd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045dfdb  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045dfe1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045dfe3  740e                   -je 0x45dff3
    if (cpu.flags.zf)
    {
        goto L_0x0045dff3;
    }
    // 0045dfe5  83fa01                 +cmp edx, 1
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
    // 0045dfe8  7409                   -je 0x45dff3
    if (cpu.flags.zf)
    {
        goto L_0x0045dff3;
    }
    // 0045dfea  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045dff1  7e0c                   -jle 0x45dfff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045dfff;
    }
L_0x0045dff3:
    // 0045dff3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045dff5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045dff8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dff9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dffa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dffb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dffc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dffd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045dffe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045dfff:
    // 0045dfff  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0045e004  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045e006  e8157f0100             -call 0x475f20
    cpu.esp -= 4;
    sub_475f20(app, cpu);
    if (cpu.terminate) return;
    // 0045e00b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045e00d  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0045e013  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e019  7d09                   -jge 0x45e024
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e024;
    }
    // 0045e01b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e01d  e820c40100             -call 0x47a442
    cpu.esp -= 4;
    sub_47a442(app, cpu);
    if (cpu.terminate) return;
    // 0045e022  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0045e024:
    // 0045e024  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e026  0f84ac000000           -je 0x45e0d8
    if (cpu.flags.zf)
    {
        goto L_0x0045e0d8;
    }
    // 0045e02c  3b0db0d54f00           +cmp ecx, dword ptr [0x4fd5b0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5232048) /* 0x4fd5b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e032  0f8494000000           -je 0x45e0cc
    if (cpu.flags.zf)
    {
        goto L_0x0045e0cc;
    }
L_0x0045e038:
    // 0045e038  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e03d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e03f  e80c1afcff             -call 0x41fa50
    cpu.esp -= 4;
    sub_41fa50(app, cpu);
    if (cpu.terminate) return;
    // 0045e044  3b0db0d54f00           +cmp ecx, dword ptr [0x4fd5b0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5232048) /* 0x4fd5b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e04a  0f849a000000           -je 0x45e0ea
    if (cpu.flags.zf)
    {
        goto L_0x0045e0ea;
    }
    // 0045e050  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x0045e053:
    // 0045e053  8935acd54f00           -mov dword ptr [0x4fd5ac], esi
    *app->getMemory<x86::reg32>(x86::reg32(5232044) /* 0x4fd5ac */) = cpu.esi;
    // 0045e059  890db0d54f00           -mov dword ptr [0x4fd5b0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232048) /* 0x4fd5b0 */) = cpu.ecx;
L_0x0045e05f:
    // 0045e05f  66833dd8e44d0000       +cmp word ptr [0x4de4d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e067  0f8499010000           -je 0x45e206
    if (cpu.flags.zf)
    {
        goto L_0x0045e206;
    }
    // 0045e06d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045e072  3b0d44d34d00           +cmp ecx, dword ptr [0x4dd344]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e078  0f8dce000000           -jge 0x45e14c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e14c;
    }
    // 0045e07e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0045e083:
    // 0045e083  833d9cd54f0000         +cmp dword ptr [0x4fd59c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232028) /* 0x4fd59c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e08a  7466                   -je 0x45e0f2
    if (cpu.flags.zf)
    {
        goto L_0x0045e0f2;
    }
L_0x0045e08c:
    // 0045e08c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045e091  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e096  e8e514ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e09b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045e09d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e0a2  892d106b4c00           -mov dword ptr [0x4c6b10], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ebp;
    // 0045e0a8  892d9cd54f00           -mov dword ptr [0x4fd59c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5232028) /* 0x4fd59c */) = cpu.ebp;
    // 0045e0ae  e88d19fcff             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045e0b3  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e0b8  e8c314ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e0bd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e0c2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e0c5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0c6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0c7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0c8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0c9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0ca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e0cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e0cc:
    // 0045e0cc  3b35acd54f00           +cmp esi, dword ptr [0x4fd5ac]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5232044) /* 0x4fd5ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e0d2  0f8f60ffffff           -jg 0x45e038
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e038;
    }
L_0x0045e0d8:
    // 0045e0d8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045e0da  890db0d54f00           -mov dword ptr [0x4fd5b0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232048) /* 0x4fd5b0 */) = cpu.ecx;
    // 0045e0e0  a3acd54f00             -mov dword ptr [0x4fd5ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232044) /* 0x4fd5ac */) = cpu.eax;
    // 0045e0e5  e975ffffff             -jmp 0x45e05f
    goto L_0x0045e05f;
L_0x0045e0ea:
    // 0045e0ea  83c605                 +add esi, 5
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045e0ed  e961ffffff             -jmp 0x45e053
    goto L_0x0045e053;
L_0x0045e0f2:
    // 0045e0f2  668b82b8e44d00         -mov ax, word ptr [edx + 0x4de4b8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5104824) /* 0x4de4b8 */);
    // 0045e0f9  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0045e0fc  763d                   -jbe 0x45e13b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045e13b;
    }
    // 0045e0fe  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e102  7569                   -jne 0x45e16d
    if (!cpu.flags.zf)
    {
        goto L_0x0045e16d;
    }
    // 0045e104  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e10b  7559                   -jne 0x45e166
    if (!cpu.flags.zf)
    {
        goto L_0x0045e166;
    }
    // 0045e10d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e10f  e84cc60000             -call 0x46a760
    cpu.esp -= 4;
    sub_46a760(app, cpu);
    if (cpu.terminate) return;
L_0x0045e114:
    // 0045e114  a1784a4c00             -mov eax, dword ptr [0x4c4a78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999800) /* 0x4c4a78 */);
    // 0045e119  e8ea0e0200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045e11e  6683bab8e44d0016       +cmp word ptr [edx + 0x4de4b8], 0x16
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5104824) /* 0x4de4b8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e126  7509                   -jne 0x45e131
    if (!cpu.flags.zf)
    {
        goto L_0x0045e131;
    }
    // 0045e128  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045e12a  6689bab8e44d00         -mov word ptr [edx + 0x4de4b8], di
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5104824) /* 0x4de4b8 */) = cpu.di;
L_0x0045e131:
    // 0045e131  a1784a4c00             -mov eax, dword ptr [0x4c4a78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999800) /* 0x4c4a78 */);
    // 0045e136  e8e50e0200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x0045e13b:
    // 0045e13b  a144d34d00             -mov eax, dword ptr [0x4dd344]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e140  41                     -inc ecx
    (cpu.ecx)++;
    // 0045e141  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e144  39c1                   +cmp ecx, eax
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
    // 0045e146  0f8c37ffffff           -jl 0x45e083
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e083;
    }
L_0x0045e14c:
    // 0045e14c  83fb02                 +cmp ebx, 2
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
    // 0045e14f  733b                   -jae 0x45e18c
    if (!cpu.flags.cf)
    {
        goto L_0x0045e18c;
    }
    // 0045e151  83fb01                 +cmp ebx, 1
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
    // 0045e154  0f8432ffffff           -je 0x45e08c
    if (cpu.flags.zf)
    {
        goto L_0x0045e08c;
    }
L_0x0045e15a:
    // 0045e15a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e15c  83c410                 +add esp, 0x10
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
    // 0045e15f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e160  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e161  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e162  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e163  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e164  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e165  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e166:
    // 0045e166  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0045e16b  eba7                   -jmp 0x45e114
    goto L_0x0045e114;
L_0x0045e16d:
    // 0045e16d  a1784a4c00             -mov eax, dword ptr [0x4c4a78]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4999800) /* 0x4c4a78 */);
    // 0045e172  e8910e0200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045e177  6683bab8e44d0016       +cmp word ptr [edx + 0x4de4b8], 0x16
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5104824) /* 0x4de4b8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e17f  74b0                   -je 0x45e131
    if (cpu.flags.zf)
    {
        goto L_0x0045e131;
    }
    // 0045e181  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0045e183  6689b2b8e44d00         -mov word ptr [edx + 0x4de4b8], si
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5104824) /* 0x4de4b8 */) = cpu.si;
    // 0045e18a  eba5                   -jmp 0x45e131
    goto L_0x0045e131;
L_0x0045e18c:
    // 0045e18c  7655                   -jbe 0x45e1e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045e1e3;
    }
    // 0045e18e  83fb03                 +cmp ebx, 3
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
    // 0045e191  75c7                   -jne 0x45e15a
    if (!cpu.flags.zf)
    {
        goto L_0x0045e15a;
    }
    // 0045e193  8b1560cf4d00           -mov edx, dword ptr [0x4dcf60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045e199  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e19b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045e19d  7e21                   -jle 0x45e1c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e1c0;
    }
    // 0045e19f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045e1a1:
    // 0045e1a1  8b8ae8cd4d00           -mov ecx, dword ptr [edx + 0x4dcde8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045e1a7  40                     -inc eax
    (cpu.eax)++;
    // 0045e1a8  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0045e1b2  8b0d60cf4d00           -mov ecx, dword ptr [0x4dcf60]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045e1b8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e1bb  39c8                   +cmp eax, ecx
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
    // 0045e1bd  7ce2                   -jl 0x45e1a1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e1a1;
    }
    // 0045e1bf  90                     -nop 
    ;
L_0x0045e1c0:
    // 0045e1c0  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 0045e1c5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e1ca  e8b113ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e1cf  e86c18fcff             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045e1d4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045e1d9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e1dc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1dd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1de  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1df  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1e0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1e1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e1e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e1e3:
    // 0045e1e3  ba15000000             -mov edx, 0x15
    cpu.edx = 21 /*0x15*/;
    // 0045e1e8  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e1ed  e88e13ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e1f2  e84918fcff             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045e1f7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045e1fc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e1ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e200  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e201  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e202  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e203  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e204  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e205  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e206:
    // 0045e206  66a1aae44d00           -mov ax, word ptr [0x4de4aa]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5104810) /* 0x4de4aa */);
    // 0045e20c  663d1500               +cmp ax, 0x15
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21 /*0x15*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e210  733b                   -jae 0x45e24d
    if (!cpu.flags.cf)
    {
        goto L_0x0045e24d;
    }
    // 0045e212  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e216  0f848b000000           -je 0x45e2a7
    if (cpu.flags.zf)
    {
        goto L_0x0045e2a7;
    }
L_0x0045e21c:
    // 0045e21c  83fb01                 +cmp ebx, 1
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
    // 0045e21f  0f85bc000000           -jne 0x45e2e1
    if (!cpu.flags.zf)
    {
        goto L_0x0045e2e1;
    }
    // 0045e225  b607                   -mov dh, 7
    cpu.dh = 7 /*0x7*/;
    // 0045e227  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0045e229  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e22b  88742408               -mov byte ptr [esp + 8], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dh;
    // 0045e22f  885c2409               -mov byte ptr [esp + 9], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) = cpu.bl;
    // 0045e233  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045e238  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e23c  e86f1affff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
L_0x0045e241:
    // 0045e241  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e243  83c410                 +add esp, 0x10
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
    // 0045e246  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e247  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e248  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e249  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e24a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e24b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e24c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e24d:
    // 0045e24d  7694                   -jbe 0x45e1e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045e1e3;
    }
    // 0045e24f  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e253  75c7                   -jne 0x45e21c
    if (!cpu.flags.zf)
    {
        goto L_0x0045e21c;
    }
    // 0045e255  8b0d60cf4d00           -mov ecx, dword ptr [0x4dcf60]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045e25b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e25d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e25f  7e23                   -jle 0x45e284
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e284;
    }
    // 0045e261  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045e263:
    // 0045e263  8b2d60cf4d00           -mov ebp, dword ptr [0x4dcf60]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045e269  8b8ae8cd4d00           -mov ecx, dword ptr [edx + 0x4dcde8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045e26f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e272  40                     -inc eax
    (cpu.eax)++;
    // 0045e273  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0045e27d  39e8                   +cmp eax, ebp
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
    // 0045e27f  7ce2                   -jl 0x45e263
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e263;
    }
    // 0045e281  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045e284:
    // 0045e284  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 0045e289  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e28e  e8ed12ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e293  e8a817fcff             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045e298  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045e29d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e2a0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e2a7:
    // 0045e2a7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045e2ac  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e2b1  e8ca12ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e2b6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045e2b8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e2bd  8935106b4c00           -mov dword ptr [0x4c6b10], esi
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.esi;
    // 0045e2c3  e87817fcff             -call 0x41fa40
    cpu.esp -= 4;
    sub_41fa40(app, cpu);
    if (cpu.terminate) return;
    // 0045e2c8  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0045e2cd  e8ae12ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e2d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e2d7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e2da  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2db  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2dc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2dd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2de  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2df  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e2e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e2e1:
    // 0045e2e1  83fb03                 +cmp ebx, 3
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
    // 0045e2e4  0f8557ffffff           -jne 0x45e241
    if (!cpu.flags.zf)
    {
        goto L_0x0045e241;
    }
    // 0045e2ea  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 0045e2ec  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0045e2ee  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045e2f3  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045e2f6  88542401               -mov byte ptr [esp + 1], dl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045e2fa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045e2fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e2fe  e8ad19ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045e303  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e30a  0f8531ffffff           -jne 0x45e241
    if (!cpu.flags.zf)
    {
        goto L_0x0045e241;
    }
    // 0045e310  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045e315  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0045e31a  66891ddce44d00         -mov word ptr [0x4de4dc], bx
    *app->getMemory<x86::reg16>(x86::reg32(5104860) /* 0x4de4dc */) = cpu.bx;
    // 0045e321  66891ddae44d00         -mov word ptr [0x4de4da], bx
    *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.bx;
    // 0045e328  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e32b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e32c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e32d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e32e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e32f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e330  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e331  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e340  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e341  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e342  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e343  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e344  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e347  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045e34d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045e34f  0f8477000000           -je 0x45e3cc
    if (cpu.flags.zf)
    {
        goto L_0x0045e3cc;
    }
    // 0045e355  83fa01                 +cmp edx, 1
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
    // 0045e358  0f846e000000           -je 0x45e3cc
    if (cpu.flags.zf)
    {
        goto L_0x0045e3cc;
    }
    // 0045e35e  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e365  7f65                   -jg 0x45e3cc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e3cc;
    }
    // 0045e367  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e369  7456                   -je 0x45e3c1
    if (cpu.flags.zf)
    {
        goto L_0x0045e3c1;
    }
    // 0045e36b  8b35a0d54f00           -mov esi, dword ptr [0x4fd5a0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */);
    // 0045e371  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045e373  754c                   -jne 0x45e3c1
    if (!cpu.flags.zf)
    {
        goto L_0x0045e3c1;
    }
    // 0045e375  833d046b4c0000         +cmp dword ptr [0x4c6b04], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5008132) /* 0x4c6b04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e37c  7543                   -jne 0x45e3c1
    if (!cpu.flags.zf)
    {
        goto L_0x0045e3c1;
    }
    // 0045e37e  8b15a4d54f00           -mov edx, dword ptr [0x4fd5a4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5232036) /* 0x4fd5a4 */);
    // 0045e384  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0045e387  e8d4030000             -call 0x45e760
    cpu.esp -= 4;
    sub_45e760(app, cpu);
    if (cpu.terminate) return;
    // 0045e38c  39c2                   +cmp edx, eax
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
    // 0045e38e  7d31                   -jge 0x45e3c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045e3c1;
    }
    // 0045e390  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 0045e392  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0045e394  8b2decd24d00           -mov ebp, dword ptr [0x4dd2ec]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 0045e39a  88542401               -mov byte ptr [esp + 1], dl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0045e39e  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0045e3a1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045e3a3  742f                   -je 0x45e3d4
    if (cpu.flags.zf)
    {
        goto L_0x0045e3d4;
    }
    // 0045e3a5  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045e3aa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045e3ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e3ae  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0045e3b2  e8f918ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045e3b7  c705046b4c0001000000   -mov dword ptr [0x4c6b04], 1
    *app->getMemory<x86::reg32>(x86::reg32(5008132) /* 0x4c6b04 */) = 1 /*0x1*/;
L_0x0045e3c1:
    // 0045e3c1  833da0d54f0000         +cmp dword ptr [0x4fd5a0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e3c8  753c                   -jne 0x45e406
    if (!cpu.flags.zf)
    {
        goto L_0x0045e406;
    }
L_0x0045e3ca:
    // 0045e3ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045e3cc:
    // 0045e3cc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e3cf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3d0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3d1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e3d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e3d4:
    // 0045e3d4  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0045e3d9  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045e3de  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0045e3e0  e8230c0200             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0045e3e5  e886030000             -call 0x45e770
    cpu.esp -= 4;
    sub_45e770(app, cpu);
    if (cpu.terminate) return;
    // 0045e3ea  a3a0d54f00             -mov dword ptr [0x4fd5a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */) = cpu.eax;
    // 0045e3ef  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045e3f3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045e3f5  e8b618ffff             -call 0x44fcb0
    cpu.esp -= 4;
    sub_44fcb0(app, cpu);
    if (cpu.terminate) return;
    // 0045e3fa  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045e3ff  e81c0c0200             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0045e404  ebbb                   -jmp 0x45e3c1
    goto L_0x0045e3c1;
L_0x0045e406:
    // 0045e406  e855030000             -call 0x45e760
    cpu.esp -= 4;
    sub_45e760(app, cpu);
    if (cpu.terminate) return;
    // 0045e40b  3b05a0d54f00           +cmp eax, dword ptr [0x4fd5a0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e411  75b7                   -jne 0x45e3ca
    if (!cpu.flags.zf)
    {
        goto L_0x0045e3ca;
    }
    // 0045e413  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e414  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045e419  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 0045e41e  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 0045e423  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045e425  89350c6b4c00           -mov dword ptr [0x4c6b0c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.esi;
    // 0045e42b  e85011ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e430  a1a0d54f00             -mov eax, dword ptr [0x4fd5a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */);
    // 0045e435  893d046b4c00           -mov dword ptr [0x4c6b04], edi
    *app->getMemory<x86::reg32>(x86::reg32(5008132) /* 0x4c6b04 */) = cpu.edi;
    // 0045e43b  893d9cd54f00           -mov dword ptr [0x4fd59c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5232028) /* 0x4fd59c */) = cpu.edi;
    // 0045e441  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e443  a3a4d54f00             -mov dword ptr [0x4fd5a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232036) /* 0x4fd5a4 */) = cpu.eax;
    // 0045e448  893da0d54f00           -mov dword ptr [0x4fd5a0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */) = cpu.edi;
    // 0045e44e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045e44f:
    // 0045e44f  e868da0100             -call 0x47bebc
    cpu.esp -= 4;
    sub_47bebc(app, cpu);
    if (cpu.terminate) return;
    // 0045e454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e456  7409                   -je 0x45e461
    if (cpu.flags.zf)
    {
        goto L_0x0045e461;
    }
    // 0045e458  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e45a  e8219c0100             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0045e45f  ebee                   -jmp 0x45e44f
    goto L_0x0045e44f;
L_0x0045e461:
    // 0045e461  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e466  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e469  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e46a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e46b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e46c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e46d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45e470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e470  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e471  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0045e476  b8003c0000             -mov eax, 0x3c00
    cpu.eax = 15360 /*0x3c00*/;
    // 0045e47b  e80011ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045e480  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e482  a1a8d54f00             -mov eax, dword ptr [0x4fd5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */);
    // 0045e487  8915006b4c00           -mov dword ptr [0x4c6b00], edx
    *app->getMemory<x86::reg32>(x86::reg32(5008128) /* 0x4c6b00 */) = cpu.edx;
    // 0045e48d  e8a20b0200             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 0045e492  66833ddae44d0000       +cmp word ptr [0x4de4da], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045e49a  7502                   -jne 0x45e49e
    if (!cpu.flags.zf)
    {
        goto L_0x0045e49e;
    }
    // 0045e49c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e49d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e49e:
    // 0045e49e  e8d10e0200             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0045e4a3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e4b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e4b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e4b2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0045e4b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e4b9  890da4d54f00           -mov dword ptr [0x4fd5a4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232036) /* 0x4fd5a4 */) = cpu.ecx;
    // 0045e4bf  8915a0d54f00           -mov dword ptr [0x4fd5a0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232032) /* 0x4fd5a0 */) = cpu.edx;
    // 0045e4c5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4c6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e4d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e4d1  e8e20a0200             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0045e4d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045e4db  a3a8d54f00             -mov dword ptr [0x4fd5a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5232040) /* 0x4fd5a8 */) = cpu.eax;
    // 0045e4e0  8915006b4c00           -mov dword ptr [0x4c6b00], edx
    *app->getMemory<x86::reg32>(x86::reg32(5008128) /* 0x4c6b00 */) = cpu.edx;
    // 0045e4e6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e4e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e504(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045e504  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e505  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e506  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e507  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e508  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e509  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e50a  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045e510  83fa04                 +cmp edx, 4
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
    // 0045e513  0f8710010000           -ja 0x45e629
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045e629;
    }
    // 0045e519  ff2495f0e44500         -jmp dword ptr [edx*4 + 0x45e4f0]
    cpu.ip = *app->getMemory<x86::reg32>(4580592 + cpu.edx * 4); goto dynamic_jump;
  case 0x0045e520:
L_0x0045e520:
    // 0045e520  8b3de4d54f00           -mov edi, dword ptr [0x4fd5e4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */);
    // 0045e526  a1e8e94f00             -mov eax, dword ptr [0x4fe9e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e52b  8b2dece94f00           -mov ebp, dword ptr [0x4fe9ec]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e531  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045e533  39e8                   +cmp eax, ebp
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
    // 0045e535  0f8fe5000000           -jg 0x45e620
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e620;
    }
L_0x0045e53b:
    // 0045e53b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e540  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e541  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e542  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e543  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e544  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e545  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e546  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e547:
    // 0045e547  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e54e  7532                   -jne 0x45e582
    if (!cpu.flags.zf)
    {
        goto L_0x0045e582;
    }
    // 0045e550  833d106b4c0000         +cmp dword ptr [0x4c6b10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e557  7404                   -je 0x45e55d
    if (cpu.flags.zf)
    {
        goto L_0x0045e55d;
    }
    // 0045e559  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e55b  75de                   -jne 0x45e53b
    if (!cpu.flags.zf)
    {
        goto L_0x0045e53b;
    }
L_0x0045e55d:
    // 0045e55d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e55f  750a                   -jne 0x45e56b
    if (!cpu.flags.zf)
    {
        goto L_0x0045e56b;
    }
    // 0045e561  a00cea4f00             -mov al, byte ptr [0x4fea0c]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */);
    // 0045e566  83f810                 +cmp eax, 0x10
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
    // 0045e569  7f20                   -jg 0x45e58b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e58b;
    }
L_0x0045e56b:
    // 0045e56b  8b3de4d54f00           -mov edi, dword ptr [0x4fd5e4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */);
    // 0045e571  a1e8e94f00             -mov eax, dword ptr [0x4fe9e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e576  8b2dece94f00           -mov ebp, dword ptr [0x4fe9ec]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e57c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045e57e  39e8                   +cmp eax, ebp
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
    // 0045e580  7eb9                   -jle 0x45e53b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e53b;
    }
L_0x0045e582:
    // 0045e582  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e584  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e585  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e586  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e587  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e588  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e589  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e58a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e58b:
    // 0045e58b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0045e58d  88250cea4f00           -mov byte ptr [0x4fea0c], ah
    *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */) = cpu.ah;
    // 0045e593  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e598  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e599  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e59a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e59b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e59c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e59d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e59e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e59f:
    // 0045e59f  3b05ecd24d00           +cmp eax, dword ptr [0x4dd2ec]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e5a5  75db                   -jne 0x45e582
    if (!cpu.flags.zf)
    {
        goto L_0x0045e582;
    }
    // 0045e5a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e5a9  8a150cea4f00           -mov dl, byte ptr [0x4fea0c]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */);
    // 0045e5af  83fa01                 +cmp edx, 1
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
    // 0045e5b2  7f50                   -jg 0x45e604
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e604;
    }
    // 0045e5b4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045e5bb  8b0de0d54f00           -mov ecx, dword ptr [0x4fd5e0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5232096) /* 0x4fd5e0 */);
    // 0045e5c1  a1e8e94f00             -mov eax, dword ptr [0x4fe9e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e5c6  8b9aece94f00           -mov ebx, dword ptr [edx + 0x4fe9ec]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e5cc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045e5ce  39d8                   +cmp eax, ebx
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
    // 0045e5d0  0f8e65ffffff           -jle 0x45e53b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e53b;
    }
    // 0045e5d6  a1f0e94f00             -mov eax, dword ptr [0x4fe9f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237232) /* 0x4fe9f0 */);
    // 0045e5db  8b15ece94f00           -mov edx, dword ptr [0x4fe9ec]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e5e1  39c2                   +cmp edx, eax
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
    // 0045e5e3  7e02                   -jle 0x45e5e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e5e7;
    }
    // 0045e5e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045e5e7:
    // 0045e5e7  8b35e4d54f00           -mov esi, dword ptr [0x4fd5e4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */);
    // 0045e5ed  a1e8e94f00             -mov eax, dword ptr [0x4fe9e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e5f2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045e5f4  39c2                   +cmp edx, eax
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
    // 0045e5f6  7c8a                   -jl 0x45e582
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e582;
    }
    // 0045e5f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e5fd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e5fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e5ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e600  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e601  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e602  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e603  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e604:
    // 0045e604  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0045e606  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045e60b  88150cea4f00           -mov byte ptr [0x4fea0c], dl
    *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */) = cpu.dl;
    // 0045e611  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e612  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e613  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e614  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e615  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e616  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e617  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e618:
    // 0045e618  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e61a  0f8400ffffff           -je 0x45e520
    if (cpu.flags.zf)
    {
        goto L_0x0045e520;
    }
L_0x0045e620:
    // 0045e620  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e622  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e623  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e624  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e625  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e626  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e627  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e628  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e629:
    // 0045e629  baa0b34b00             -mov edx, 0x4bb3a0
    cpu.edx = 4961184 /*0x4bb3a0*/;
    // 0045e62e  b9a1030000             -mov ecx, 0x3a1
    cpu.ecx = 929 /*0x3a1*/;
    // 0045e633  68c4b34b00             -push 0x4bb3c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4961220 /*0x4bb3c4*/;
    cpu.esp -= 4;
    // 0045e638  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0045e63e  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0045e644  e8779c0100             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0045e649  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e64c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045e64e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e64f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e650  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e651  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e652  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e653  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e654  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045e674  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e675  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e676  8b15e4d54f00           -mov edx, dword ptr [0x4fd5e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */);
    // 0045e67c  a1e8d24d00             -mov eax, dword ptr [0x4dd2e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045e681  83f804                 +cmp eax, 4
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
    // 0045e684  770c                   -ja 0x45e692
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045e692;
    }
    // 0045e686  ff248560e64500         -jmp dword ptr [eax*4 + 0x45e660]
    cpu.ip = *app->getMemory<x86::reg32>(4580960 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045e68d:
    // 0045e68d  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x0045e692:
    // 0045e692  8915e4d54f00           -mov dword ptr [0x4fd5e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */) = cpu.edx;
    // 0045e698  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e699  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e69a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e69b:
    // 0045e69b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e69c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e69d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045e6a2  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0045e6a7  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045e6ac  890ddcd54f00           -mov dword ptr [0x4fd5dc], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5232092) /* 0x4fd5dc */) = cpu.ecx;
    // 0045e6b2  891de0d54f00           -mov dword ptr [0x4fd5e0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5232096) /* 0x4fd5e0 */) = cpu.ebx;
    // 0045e6b8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6ba  8915e4d54f00           -mov dword ptr [0x4fd5e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */) = cpu.edx;
    // 0045e6c0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6c2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e6c3:
    // 0045e6c3  bf18000000             -mov edi, 0x18
    cpu.edi = 24 /*0x18*/;
    // 0045e6c8  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0045e6cd  893de0d54f00           -mov dword ptr [0x4fd5e0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5232096) /* 0x4fd5e0 */) = cpu.edi;
    // 0045e6d3  8915e4d54f00           -mov dword ptr [0x4fd5e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */) = cpu.edx;
    // 0045e6d9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6da  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6db  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045e6dc:
    // 0045e6dc  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045e6e1  8915e0d54f00           -mov dword ptr [0x4fd5e0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232096) /* 0x4fd5e0 */) = cpu.edx;
    // 0045e6e7  8915e4d54f00           -mov dword ptr [0x4fd5e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5232100) /* 0x4fd5e4 */) = cpu.edx;
    // 0045e6ed  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6ee  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e6ef  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_45e6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e6f0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e6f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045e6f3  8a150cea4f00           -mov dl, byte ptr [0x4fea0c]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */);
    // 0045e6f9  39d0                   +cmp eax, edx
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
    // 0045e6fb  7e07                   -jle 0x45e704
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e704;
    }
    // 0045e6fd  a20cea4f00             -mov byte ptr [0x4fea0c], al
    *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */) = cpu.al;
    // 0045e702  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e704:
    // 0045e704  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045e706  a20cea4f00             -mov byte ptr [0x4fea0c], al
    *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */) = cpu.al;
    // 0045e70b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e70c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_45e710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e710  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e711  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e718  7424                   -je 0x45e73e
    if (cpu.flags.zf)
    {
        goto L_0x0045e73e;
    }
    // 0045e71a  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045e721  752a                   -jne 0x45e74d
    if (!cpu.flags.zf)
    {
        goto L_0x0045e74d;
    }
    // 0045e723  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0045e728:
    // 0045e728  8b15ecd24d00           -mov edx, dword ptr [0x4dd2ec]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 0045e72e  8a0485ece94f00         -mov al, byte ptr [eax*4 + 0x4fe9ec]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5237228) /* 0x4fe9ec */ + cpu.eax * 4);
    // 0045e735  2a0495ece94f00         -sub al, byte ptr [edx*4 + 0x4fe9ec]
    (cpu.al) -= x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(x86::reg32(5237228) /* 0x4fe9ec */ + cpu.edx * 4)));
    // 0045e73c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e73d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e73e:
    // 0045e73e  8a15e8e94f00           -mov dl, byte ptr [0x4fe9e8]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e744  a0ece94f00             -mov al, byte ptr [0x4fe9ec]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e749  28d0                   -sub al, dl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.dl));
    // 0045e74b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e74c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e74d:
    // 0045e74d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045e74f  ebd7                   -jmp 0x45e728
    goto L_0x0045e728;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e760  a1e8e94f00             -mov eax, dword ptr [0x4fe9e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */);
    // 0045e765  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e770  a1ece94f00             -mov eax, dword ptr [0x4fe9ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e775  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045e778  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e780  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e781  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e782  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e783  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e784  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e785  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e786  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045e789  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045e78b  a1ece94f00             -mov eax, dword ptr [0x4fe9ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e790  48                     -dec eax
    (cpu.eax)--;
    // 0045e791  8b1544d34d00           -mov edx, dword ptr [0x4dd344]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e797  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045e79a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e79c  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045e7a0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045e7a2  0f8ecf000000           -jle 0x45e877
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e877;
    }
    // 0045e7a8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e7ac  4a                     -dec edx
    (cpu.edx)--;
    // 0045e7ad  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045e7b0  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0045e7b3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e7b7  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0045e7bb  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045e7bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045e7c1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045e7c3  81c2e8d54f00           -add edx, 0x4fd5e8
    (cpu.edx) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
L_0x0045e7c9:
    // 0045e7c9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045e7cd  80b8e8e54f0000         +cmp byte ptr [eax + 0x4fe5e8], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5236200) /* 0x4fe5e8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045e7d4  7556                   -jne 0x45e82c
    if (!cpu.flags.zf)
    {
        goto L_0x0045e82c;
    }
    // 0045e7d6  ff049dece94f00         -inc dword ptr [ebx*4 + 0x4fe9ec]
    (*app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */ + cpu.ebx * 4))++;
    // 0045e7dd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045e7e1  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0045e7e3  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045e7e7  88a8e8e54f00           -mov byte ptr [eax + 0x4fe5e8], ch
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5236200) /* 0x4fe5e8 */) = cpu.ch;
    // 0045e7ed  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045e7f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045e7f4  0f848d000000           -je 0x45e887
    if (cpu.flags.zf)
    {
        goto L_0x0045e887;
    }
    // 0045e7fa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
L_0x0045e7fd:
    // 0045e7fd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045e800  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 0045e807  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045e809  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0045e80c  05e8d54f00             -add eax, 0x4fd5e8
    (cpu.eax) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
    // 0045e811  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045e813  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045e815  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e816  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e818  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e81b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e81d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e81f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e822  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e824  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e825  80a5ebd54f00bc         -and byte ptr [ebp + 0x4fd5eb], 0xbc
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5232107) /* 0x4fd5eb */) &= x86::reg8(x86::sreg8(188 /*0xbc*/));
L_0x0045e82c:
    // 0045e82c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045e831  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045e835  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e837  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e838  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e83a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e83d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e83f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e841  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e844  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e846  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e847  81c500020000           -add ebp, 0x200
    (cpu.ebp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045e84d  43                     -inc ebx
    (cpu.ebx)++;
    // 0045e84e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045e852  8d7704                 -lea esi, [edi + 4]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0045e855  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045e85b  8b3d44d34d00           -mov edi, dword ptr [0x4dd344]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e861  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045e867  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0045e86b  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0045e86f  39fb                   +cmp ebx, edi
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
    // 0045e871  0f8c52ffffff           -jl 0x45e7c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e7c9;
    }
L_0x0045e877:
    // 0045e877  ff05086b4c00           -inc dword ptr [0x4c6b08]
    (*app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */))++;
    // 0045e87d  83c410                 +add esp, 0x10
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
    // 0045e880  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e881  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e882  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e883  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e884  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e885  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e886  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045e887:
    // 0045e887  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 0045e88c  e96cffffff             -jmp 0x45e7fd
    goto L_0x0045e7fd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e8a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e8a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e8a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e8a3  bebcd54f00             -mov esi, 0x4fd5bc
    cpu.esi = 5232060 /*0x4fd5bc*/;
    // 0045e8a8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045e8ad  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045e8b0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045e8b2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045e8b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e8b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e8b7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e8ba  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e8bc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e8be  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e8c1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e8c3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e8c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e8d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045e8d1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e8d2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e8d5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045e8d8  8b15f4d24d00           -mov edx, dword ptr [0x4dd2f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
    // 0045e8de  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045e8e1  83fa01                 +cmp edx, 1
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
    // 0045e8e4  0f8f88000000           -jg 0x45e972
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045e972;
    }
    // 0045e8ea  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e8eb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e8ec  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e8ed  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e8ee  8b0d44d34d00           -mov ecx, dword ptr [0x4dd344]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e8f4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045e8f6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045e8f8  7e42                   -jle 0x45e93c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e93c;
    }
    // 0045e8fa  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045e901  bbbcd54f00             -mov ebx, 0x4fd5bc
    cpu.ebx = 5232060 /*0x4fd5bc*/;
    // 0045e906  81c2e8d54f00           -add edx, 0x4fd5e8
    (cpu.edx) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
L_0x0045e90c:
    // 0045e90c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045e911  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045e913  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0045e915  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e916  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045e918  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045e91b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045e91d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045e91f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045e922  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045e924  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e925  45                     -inc ebp
    (cpu.ebp)++;
    // 0045e926  8b3544d34d00           -mov esi, dword ptr [0x4dd344]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e92c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e92f  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045e935  39f5                   +cmp ebp, esi
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
    // 0045e937  7cd3                   -jl 0x45e90c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e90c;
    }
    // 0045e939  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045e93c:
    // 0045e93c  8b3d44d34d00           -mov edi, dword ptr [0x4dd344]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
    // 0045e942  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e944  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045e946  7e20                   -jle 0x45e968
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045e968;
    }
    // 0045e948  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e94c  8b2d44d34d00           -mov ebp, dword ptr [0x4dd344]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5100356) /* 0x4dd344 */);
L_0x0045e952:
    // 0045e952  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045e958  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0045e95a  43                     -inc ebx
    (cpu.ebx)++;
    // 0045e95b  88a268e54f00           -mov byte ptr [edx + 0x4fe568], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5236072) /* 0x4fe568 */) = cpu.ah;
    // 0045e961  39eb                   +cmp ebx, ebp
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
    // 0045e963  7ced                   -jl 0x45e952
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e952;
    }
    // 0045e965  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045e968:
    // 0045e968  ff05e8e94f00           -inc dword ptr [0x4fe9e8]
    (*app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */))++;
    // 0045e96e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e96f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e970  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e971  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045e972:
    // 0045e972  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045e975  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e976  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045e977  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45e980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045e980  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045e981  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045e984  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045e987  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0045e98b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045e992  8baaece94f00           -mov ebp, dword ptr [edx + 0x4fe9ec]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e998  e867fbffff             -call 0x45e504
    cpu.esp -= 4;
    sub_45e504(app, cpu);
    if (cpu.terminate) return;
    // 0045e99d  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045e9a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045e9a2  0f85e5000000           -jne 0x45ea8d
    if (!cpu.flags.zf)
    {
        goto L_0x0045ea8d;
    }
    // 0045e9a8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045e9ab  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0045e9ae  8a8428e8e54f00         -mov al, byte ptr [eax + ebp + 0x4fe5e8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5236200) /* 0x4fe5e8 */ + cpu.ebp * 1);
    // 0045e9b5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0045e9b7  0f85d0000000           -jne 0x45ea8d
    if (!cpu.flags.zf)
    {
        goto L_0x0045ea8d;
    }
    // 0045e9bd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045e9be  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045e9bf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045e9c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045e9c1  8b1ddcd54f00           -mov ebx, dword ptr [0x4fd5dc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5232092) /* 0x4fd5dc */);
    // 0045e9c7  8b0dece94f00           -mov ecx, dword ptr [0x4fe9ec]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e9cd  8bb2ece94f00           -mov esi, dword ptr [edx + 0x4fe9ec]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e9d3  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045e9d5  39f1                   +cmp ecx, esi
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
    // 0045e9d7  7d68                   -jge 0x45ea41
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ea41;
    }
    // 0045e9d9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045e9dd  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0045e9e0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045e9e2  89baece94f00           -mov dword ptr [edx + 0x4fe9ec], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */) = cpu.edi;
    // 0045e9e8  c1e309                 -shl ebx, 9
    cpu.ebx <<= 9 /*0x9*/ % 32;
    // 0045e9eb  8b0dece94f00           -mov ecx, dword ptr [0x4fe9ec]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045e9f1  81c3e8d54f00           -add ebx, 0x4fd5e8
    (cpu.ebx) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
    // 0045e9f7  39f9                   +cmp ecx, edi
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
    // 0045e9f9  7d3d                   -jge 0x45ea38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ea38;
    }
L_0x0045e9fb:
    // 0045e9fb  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0045e9fe  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045ea01  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045ea03  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 0045ea0a  83e67f                 -and esi, 0x7f
    cpu.esi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045ea0d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045ea12  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0045ea15  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ea17  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045ea19  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ea1a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ea1c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045ea1f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045ea21  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045ea23  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045ea26  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045ea28  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea29  8bb5ece94f00           -mov esi, dword ptr [ebp + 0x4fe9ec]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045ea2f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045ea31  39f2                   +cmp edx, esi
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
    // 0045ea33  7cc6                   -jl 0x45e9fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045e9fb;
    }
    // 0045ea35  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0045ea38:
    // 0045ea38  8badece94f00           -mov ebp, dword ptr [ebp + 0x4fe9ec]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045ea3e  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x0045ea41:
    // 0045ea41  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045ea45  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045ea4a  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0045ea4d  8d3cad00000000         -lea edi, [ebp*4]
    cpu.edi = x86::reg32(cpu.ebp * 4);
    // 0045ea54  05e8d54f00             -add eax, 0x4fd5e8
    (cpu.eax) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
    // 0045ea59  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045ea5d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045ea5f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ea60  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ea62  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045ea65  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045ea67  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045ea69  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045ea6c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045ea6e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea6f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045ea73  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0045ea76  c68428e8e54f0001       -mov byte ptr [eax + ebp + 0x4fe5e8], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5236200) /* 0x4fe5e8 */ + cpu.ebp * 1) = 1 /*0x1*/;
    // 0045ea7e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045ea82  ff0485ece94f00         -inc dword ptr [eax*4 + 0x4fe9ec]
    (*app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */ + cpu.eax * 4))++;
    // 0045ea89  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea8a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea8b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea8c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0045ea8d:
    // 0045ea8d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045ea90  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ea91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45eab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045eab4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045eab5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045eab6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045eab7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045eab8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045eab9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045eabb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045eabd  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0045eac4  8bbaece94f00           -mov edi, dword ptr [edx + 0x4fe9ec]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045eaca  668b0ddae44d00         -mov cx, word ptr [0x4de4da]
    cpu.cx = *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */);
    // 0045ead1  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045ead4  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0045ead7  7414                   -je 0x45eaed
    if (cpu.flags.zf)
    {
        goto L_0x0045eaed;
    }
    // 0045ead9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045eade  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045eae0  a30c6b4c00             -mov dword ptr [0x4c6b0c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.eax;
    // 0045eae5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eae7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eae8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eae9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eaea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eaeb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eaec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045eaed:
    // 0045eaed  e812faffff             -call 0x45e504
    cpu.esp -= 4;
    sub_45e504(app, cpu);
    if (cpu.terminate) return;
    // 0045eaf2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045eaf4  752c                   -jne 0x45eb22
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb22;
    }
    // 0045eaf6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0045eaf8  c1e507                 -shl ebp, 7
    cpu.ebp <<= 7 /*0x7*/ % 32;
    // 0045eafb  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045eafd  80bde8e54f0000         +cmp byte ptr [ebp + 0x4fe5e8], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5236200) /* 0x4fe5e8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045eb04  7426                   -je 0x45eb2c
    if (cpu.flags.zf)
    {
        goto L_0x0045eb2c;
    }
    // 0045eb06  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb0d  7e13                   -jle 0x45eb22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045eb22;
    }
    // 0045eb0f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045eb14  668935dce44d00         -mov word ptr [0x4de4dc], si
    *app->getMemory<x86::reg16>(x86::reg32(5104860) /* 0x4de4dc */) = cpu.si;
    // 0045eb1b  668935dae44d00         -mov word ptr [0x4de4da], si
    *app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.si;
L_0x0045eb22:
    // 0045eb22  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045eb24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eb26  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb27  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb28  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb29  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb2a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045eb2c:
    // 0045eb2c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eb2e  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0045eb31  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0045eb34  05e8d54f00             -add eax, 0x4fd5e8
    (cpu.eax) += x86::reg32(x86::sreg32(5232104 /*0x4fd5e8*/));
    // 0045eb39  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0045eb3e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045eb40  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045eb41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045eb43  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0045eb46  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045eb48  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045eb4a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045eb4d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0045eb4f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb50  c685e8e54f0001         -mov byte ptr [ebp + 0x4fe5e8], 1
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5236200) /* 0x4fe5e8 */) = 1 /*0x1*/;
    // 0045eb57  8b8aece94f00           -mov ecx, dword ptr [edx + 0x4fe9ec]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045eb5d  41                     -inc ecx
    (cpu.ecx)++;
    // 0045eb5e  a1e8d24d00             -mov eax, dword ptr [0x4dd2e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0045eb63  898aece94f00           -mov dword ptr [edx + 0x4fe9ec], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237228) /* 0x4fe9ec */) = cpu.ecx;
    // 0045eb69  83f804                 +cmp eax, 4
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
    // 0045eb6c  770d                   -ja 0x45eb7b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045eb7b;
    }
    // 0045eb6e  ff2485a0ea4500         -jmp dword ptr [eax*4 + 0x45eaa0]
    cpu.ip = *app->getMemory<x86::reg32>(4582048 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045eb75:
    // 0045eb75  ff05086b4c00           -inc dword ptr [0x4c6b08]
    (*app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */))++;
L_0x0045eb7b:
    // 0045eb7b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045eb80  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eb82  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb83  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb84  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb85  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb86  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eb87  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045eb88:
    // 0045eb88  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045eb8a  75ef                   -jne 0x45eb7b
    if (!cpu.flags.zf)
    {
        goto L_0x0045eb7b;
    }
    // 0045eb8c  833decd24d0000         +cmp dword ptr [0x4dd2ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eb93  74e6                   -je 0x45eb7b
    if (cpu.flags.zf)
    {
        goto L_0x0045eb7b;
    }
    // 0045eb95  ff05086b4c00           -inc dword ptr [0x4c6b08]
    (*app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */))++;
    // 0045eb9b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045eba0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045eba2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eba3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eba4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eba5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eba6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eba7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045eba8:
    // 0045eba8  8b15f0e94f00           -mov edx, dword ptr [0x4fe9f0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237232) /* 0x4fe9f0 */);
    // 0045ebae  a1ece94f00             -mov eax, dword ptr [0x4fe9ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5237228) /* 0x4fe9ec */);
    // 0045ebb3  39d0                   +cmp eax, edx
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
    // 0045ebb5  7d02                   -jge 0x45ebb9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ebb9;
    }
    // 0045ebb7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0045ebb9:
    // 0045ebb9  4a                     -dec edx
    (cpu.edx)--;
    // 0045ebba  8915086b4c00           -mov dword ptr [0x4c6b08], edx
    *app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */) = cpu.edx;
    // 0045ebc0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045ebc5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ebc7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebc8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebc9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebcb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebcc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0045ebcd:
    // 0045ebcd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045ebcf  74aa                   -je 0x45eb7b
    if (cpu.flags.zf)
    {
        goto L_0x0045eb7b;
    }
    // 0045ebd1  ff05086b4c00           -inc dword ptr [0x4c6b08]
    (*app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */))++;
    // 0045ebd7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045ebdc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045ebde  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebdf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebe0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebe1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebe2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ebe3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ebf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ebf0  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ebf7  7e01                   -jle 0x45ebfa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ebfa;
    }
    // 0045ebf9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ebfa:
    // 0045ebfa  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ebfb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045ec00  890d0c6b4c00           -mov dword ptr [0x4c6b0c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ecx;
    // 0045ec06  890d106b4c00           -mov dword ptr [0x4c6b10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ecx;
    // 0045ec0c  e85ff8ffff             -call 0x45e470
    cpu.esp -= 4;
    sub_45e470(app, cpu);
    if (cpu.terminate) return;
    // 0045ec11  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ec12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ec20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ec20  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ec21  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045ec24  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec2b  0f8f7b000000           -jg 0x45ecac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045ecac;
    }
    // 0045ec31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ec32  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ec33  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ec34  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ec35  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ec36  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045ec3b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045ec3d  890d106b4c00           -mov dword ptr [0x4c6b10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ecx;
    // 0045ec43  8974241c               -mov dword ptr [esp + 0x1c], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0045ec47  89742414               -mov dword ptr [esp + 0x14], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0045ec4b  89742418               -mov dword ptr [esp + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0045ec4f  890d0c6b4c00           -mov dword ptr [0x4c6b0c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ecx;
    // 0045ec55  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x0045ec57:
    // 0045ec57  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045ec5b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045ec5f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ec61  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0045ec63  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x0045ec65:
    // 0045ec65  8d043a                 -lea eax, [edx + edi]
    cpu.eax = x86::reg32(cpu.edx + cpu.edi * 1);
    // 0045ec68  88b8e8e54f00           -mov byte ptr [eax + 0x4fe5e8], bh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5236200) /* 0x4fe5e8 */) = cpu.bh;
    // 0045ec6e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045ec75  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045ec77  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x0045ec7a:
    // 0045ec7a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045ec7d  8898e5d54f00           -mov byte ptr [eax + 0x4fd5e5], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5232101) /* 0x4fd5e5 */) = cpu.bl;
    // 0045ec83  8898e6d54f00           -mov byte ptr [eax + 0x4fd5e6], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5232102) /* 0x4fd5e6 */) = cpu.bl;
    // 0045ec89  41                     -inc ecx
    (cpu.ecx)++;
    // 0045ec8a  8898e7d54f00           -mov byte ptr [eax + 0x4fd5e7], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5232103) /* 0x4fd5e7 */) = cpu.bl;
    // 0045ec90  42                     -inc edx
    (cpu.edx)++;
    // 0045ec91  8898e4d54f00           -mov byte ptr [eax + 0x4fd5e4], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5232100) /* 0x4fd5e4 */) = cpu.bl;
    // 0045ec97  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ec9d  7d19                   -jge 0x45ecb8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ecb8;
    }
    // 0045ec9f  83fa04                 +cmp edx, 4
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
    // 0045eca2  7cc1                   -jl 0x45ec65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045ec65;
    }
    // 0045eca4  8899e8e54f00           -mov byte ptr [ecx + 0x4fe5e8], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5236200) /* 0x4fe5e8 */) = cpu.bl;
    // 0045ecaa  ebce                   -jmp 0x45ec7a
    goto L_0x0045ec7a;
L_0x0045ecac:
    // 0045ecac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ecae  a3086b4c00             -mov dword ptr [0x4c6b08], eax
    *app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */) = cpu.eax;
    // 0045ecb3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045ecb6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ecb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ecb8:
    // 0045ecb8  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0045ecbc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0045ecc0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0045ecc4  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045ecc9  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0045eccf  81c600020000           -add esi, 0x200
    (cpu.esi) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045ecd5  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0045ecd8  8990ece94f00           -mov dword ptr [eax + 0x4fe9ec], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5237228) /* 0x4fe9ec */) = cpu.edx;
    // 0045ecde  894c241c               -mov dword ptr [esp + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0045ece2  89742414               -mov dword ptr [esp + 0x14], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0045ece6  897c2418               -mov dword ptr [esp + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0045ecea  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045eced  0f8564ffffff           -jne 0x45ec57
    if (!cpu.flags.zf)
    {
        goto L_0x0045ec57;
    }
    // 0045ecf3  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0045ecf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045ecfa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045ecfc  a3e8e94f00             -mov dword ptr [0x4fe9e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5237224) /* 0x4fe9e8 */) = cpu.eax;
    // 0045ed01  8915086b4c00           -mov dword ptr [0x4c6b08], edx
    *app->getMemory<x86::reg32>(x86::reg32(5008136) /* 0x4c6b08 */) = cpu.edx;
    // 0045ed07  e8a4f7ffff             -call 0x45e4b0
    cpu.esp -= 4;
    sub_45e4b0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed0c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0045ed0e  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0045ed13  88250cea4f00           -mov byte ptr [0x4fea0c], ah
    *app->getMemory<x86::reg8>(x86::reg32(5237260) /* 0x4fea0c */) = cpu.ah;
    // 0045ed19  b8001e0000             -mov eax, 0x1e00
    cpu.eax = 7680 /*0x1e00*/;
    // 0045ed1e  890d106b4c00           -mov dword ptr [0x4c6b10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ecx;
    // 0045ed24  e85708ffff             -call 0x44f580
    cpu.esp -= 4;
    sub_44f580(app, cpu);
    if (cpu.terminate) return;
    // 0045ed29  890d0c6b4c00           -mov dword ptr [0x4c6b0c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ecx;
    // 0045ed2f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed30  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed31  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed32  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed33  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed34  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045ed37  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ed40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ed40  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ed47  7e01                   -jle 0x45ed4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ed4a;
    }
    // 0045ed49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ed4a:
    // 0045ed4a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ed4b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0045ed50  890d0c6b4c00           -mov dword ptr [0x4c6b0c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008140) /* 0x4c6b0c */) = cpu.ecx;
    // 0045ed56  890d106b4c00           -mov dword ptr [0x4c6b10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5008144) /* 0x4c6b10 */) = cpu.ecx;
    // 0045ed5c  e86ff7ffff             -call 0x45e4d0
    cpu.esp -= 4;
    sub_45e4d0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed61  e80ef9ffff             -call 0x45e674
    cpu.esp -= 4;
    sub_45e674(app, cpu);
    if (cpu.terminate) return;
    // 0045ed66  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ed67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ed70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ed80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ed80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ed81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ed82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ed83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ed84  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ed85  b8a8b44b00             -mov eax, 0x4bb4a8
    cpu.eax = 4961448 /*0x4bb4a8*/;
    // 0045ed8a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045ed8f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ed91  e82a010000             -call 0x45eec0
    cpu.esp -= 4;
    sub_45eec0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed96  e805200000             -call 0x460da0
    cpu.esp -= 4;
    sub_460da0(app, cpu);
    if (cpu.terminate) return;
    // 0045ed9b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ed9d  e87e1f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045eda2  8b0dd0d74d00           -mov ecx, dword ptr [0x4dd7d0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5101520) /* 0x4dd7d0 */);
    // 0045eda8  39c8                   +cmp eax, ecx
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
    // 0045edaa  7e02                   -jle 0x45edae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045edae;
    }
    // 0045edac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0045edae:
    // 0045edae  a3d0d74d00             -mov dword ptr [0x4dd7d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101520) /* 0x4dd7d0 */) = cpu.eax;
    // 0045edb3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045edb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045edb7  7e77                   -jle 0x45ee30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ee30;
    }
    // 0045edb9  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0045edbe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045edc0:
    // 0045edc0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045edc2  e8591f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045edc7  89812cea4f00           -mov dword ptr [ecx + 0x4fea2c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237292) /* 0x4fea2c */) = cpu.eax;
    // 0045edcd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045edcf  89b130ea4f00           -mov dword ptr [ecx + 0x4fea30], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237296) /* 0x4fea30 */) = cpu.esi;
    // 0045edd5  89b934ea4f00           -mov dword ptr [ecx + 0x4fea34], edi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237300) /* 0x4fea34 */) = cpu.edi;
    // 0045eddb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045eddd  89b938ea4f00           -mov dword ptr [ecx + 0x4fea38], edi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237304) /* 0x4fea38 */) = cpu.edi;
    // 0045ede3  e8381f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045ede8  89816cea4f00           -mov dword ptr [ecx + 0x4fea6c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237356) /* 0x4fea6c */) = cpu.eax;
    // 0045edee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045edf0  e82b1f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045edf5  898170ea4f00           -mov dword ptr [ecx + 0x4fea70], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237360) /* 0x4fea70 */) = cpu.eax;
    // 0045edfb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045edfd  e81e1f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045ee02  898174ea4f00           -mov dword ptr [ecx + 0x4fea74], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237364) /* 0x4fea74 */) = cpu.eax;
    // 0045ee08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ee0a  e8111f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045ee0f  898178ea4f00           -mov dword ptr [ecx + 0x4fea78], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237368) /* 0x4fea78 */) = cpu.eax;
    // 0045ee15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ee17  43                     -inc ebx
    (cpu.ebx)++;
    // 0045ee18  e8031f0000             -call 0x460d20
    cpu.esp -= 4;
    sub_460d20(app, cpu);
    if (cpu.terminate) return;
    // 0045ee1d  89817cea4f00           -mov dword ptr [ecx + 0x4fea7c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5237372) /* 0x4fea7c */) = cpu.eax;
    // 0045ee23  a1d0d74d00             -mov eax, dword ptr [0x4dd7d0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101520) /* 0x4dd7d0 */);
    // 0045ee28  83c154                 -add ecx, 0x54
    (cpu.ecx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0045ee2b  39c3                   +cmp ebx, eax
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
    // 0045ee2d  7c91                   -jl 0x45edc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045edc0;
    }
    // 0045ee2f  90                     -nop 
    ;
L_0x0045ee30:
    // 0045ee30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ee32  e8391f0000             -call 0x460d70
    cpu.esp -= 4;
    sub_460d70(app, cpu);
    if (cpu.terminate) return;
    // 0045ee37  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ee38  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ee39  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ee3a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ee3b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ee3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_45ee40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ee40  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ee41  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ee42  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045ee44  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045ee46  8b1540d34d00           -mov edx, dword ptr [0x4dd340]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100352) /* 0x4dd340 */);
    // 0045ee4c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0045ee4f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ee51  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ee53  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ee56  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045ee58  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ee5b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045ee5d  8b14856cea4f00         -mov edx, dword ptr [eax*4 + 0x4fea6c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237356) /* 0x4fea6c */ + cpu.eax * 4);
    // 0045ee64  895114                 -mov dword ptr [ecx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0045ee67  8b148570ea4f00         -mov edx, dword ptr [eax*4 + 0x4fea70]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237360) /* 0x4fea70 */ + cpu.eax * 4);
    // 0045ee6e  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 0045ee74  8b148574ea4f00         -mov edx, dword ptr [eax*4 + 0x4fea74]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237364) /* 0x4fea74 */ + cpu.eax * 4);
    // 0045ee7b  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 0045ee81  8b148578ea4f00         -mov edx, dword ptr [eax*4 + 0x4fea78]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237368) /* 0x4fea78 */ + cpu.eax * 4);
    // 0045ee88  c6818c00000001         -mov byte ptr [ecx + 0x8c], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
    // 0045ee8f  8991a4000000           -mov dword ptr [ecx + 0xa4], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 0045ee95  8b14857cea4f00         -mov edx, dword ptr [eax*4 + 0x4fea7c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5237372) /* 0x4fea7c */ + cpu.eax * 4);
    // 0045ee9c  8d81c4000000           -lea eax, [ecx + 0xc4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0045eea2  e8d9af0200             -call 0x489e80
    cpu.esp -= 4;
    sub_489e80(app, cpu);
    if (cpu.terminate) return;
    // 0045eea7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045eea9  e802f7feff             -call 0x44e5b0
    cpu.esp -= 4;
    sub_44e5b0(app, cpu);
    if (cpu.terminate) return;
    // 0045eeae  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eeaf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eeb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45eec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045eec0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045eec1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045eec2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045eec3  8b15fcd24d00           -mov edx, dword ptr [0x4dd2fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100284) /* 0x4dd2fc */);
    // 0045eec9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045eeca  8b0d68e54d00           -mov ecx, dword ptr [0x4de568]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5105000) /* 0x4de568 */);
    // 0045eed0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045eed1  689cb44b00             -push 0x4bb49c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4961436 /*0x4bb49c*/;
    cpu.esp -= 4;
    // 0045eed6  68d0eb4f00             -push 0x4febd0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5237712 /*0x4febd0*/;
    cpu.esp -= 4;
    // 0045eedb  e841b50100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0045eee0  b8d0eb4f00             -mov eax, 0x4febd0
    cpu.eax = 5237712 /*0x4febd0*/;
    // 0045eee5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045eee8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eee9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045eeea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45eef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045eef0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ef00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ef00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ef01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ef02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ef03  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ef04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045ef06  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045ef0d  756c                   -jne 0x45ef7b
    if (!cpu.flags.zf)
    {
        goto L_0x0045ef7b;
    }
    // 0045ef0f  6683b94c01000000       +cmp word ptr [ecx + 0x14c], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045ef17  7667                   -jbe 0x45ef80
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045ef80;
    }
    // 0045ef19  81b95c01000000800000   +cmp dword ptr [ecx + 0x15c], 0x8000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef23  0f8c0e010000           -jl 0x45f037
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f037;
    }
L_0x0045ef29:
    // 0045ef29  8b15e4d24d00           -mov edx, dword ptr [0x4dd2e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100260) /* 0x4dd2e4 */);
    // 0045ef2f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0045ef36  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ef38  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045ef3b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045ef3d  8b9160010000           -mov edx, dword ptr [ecx + 0x160]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */);
    // 0045ef43  3b148568ce4d00         +cmp edx, dword ptr [eax*4 + 0x4dce68]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5099112) /* 0x4dce68 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef4a  0f8fbe010000           -jg 0x45f10e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045f10e;
    }
    // 0045ef50  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef57  7e15                   -jle 0x45ef6e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045ef6e;
    }
L_0x0045ef59:
    // 0045ef59  8ba978050000           -mov ebp, dword ptr [ecx + 0x578]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
    // 0045ef5f  4d                     -dec ebp
    (cpu.ebp)--;
    // 0045ef60  89a978050000           -mov dword ptr [ecx + 0x578], ebp
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = cpu.ebp;
    // 0045ef66  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045ef68  0f8eb6010000           -jle 0x45f124
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f124;
    }
L_0x0045ef6e:
    // 0045ef6e  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ef75  0f8eba010000           -jle 0x45f135
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f135;
    }
L_0x0045ef7b:
    // 0045ef7b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef7c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef7d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef7e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ef7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ef80:
    // 0045ef80  8b99a8000000           -mov ebx, dword ptr [ecx + 0xa8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0045ef86  69d3e6000000           -imul edx, ebx, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045ef8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045ef8e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ef91  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045ef94  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045ef96  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045ef99  6991ac000000e6000000   -imul edx, dword ptr [ecx + 0xac], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045efa3  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0045efa9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045efab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045efae  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045efb1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045efb3  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045efb6  6991b0000000e6000000   -imul edx, dword ptr [ecx + 0xb0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045efc0  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0045efc6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045efc8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045efcb  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045efce  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045efd0  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045efd3  6991e8000000e6000000   -imul edx, dword ptr [ecx + 0xe8], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045efdd  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 0045efe3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045efe5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045efe8  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045efeb  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045efed  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045eff0  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 0045eff6  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0045effc  69d0e6000000           -imul edx, eax, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045f002  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f004  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f007  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f00a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f00c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f00f  6991f0000000e6000000   -imul edx, dword ptr [ecx + 0xf0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0045f019  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 0045f01f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f021  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f024  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f027  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f029  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045f02c  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 0045f032  e9f2feffff             -jmp 0x45ef29
    goto L_0x0045ef29;
L_0x0045f037:
    // 0045f037  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0045f03d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f040  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f042  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f045  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f047  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f049  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f04c  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f04f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f051  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f054  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0045f05a  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0045f060  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f063  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f065  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f068  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f06a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f06c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f06f  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f072  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f074  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f077  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0045f07d  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0045f083  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f086  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f088  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f08b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f08d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f08f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f092  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f095  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f097  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f09a  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 0045f0a0  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 0045f0a6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f0a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0ab  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f0ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f0b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0b2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f0b5  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f0b8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f0ba  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f0bd  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 0045f0c3  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0045f0c9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f0cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0ce  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f0d1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f0d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0d5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f0d8  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f0db  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f0dd  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0045f0e0  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 0045f0e6  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0045f0ec  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045f0ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0f1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0045f0f4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f0f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f0f8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f0fb  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0045f0fe  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f100  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045f103  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 0045f109  e91bfeffff             -jmp 0x45ef29
    goto L_0x0045ef29;
L_0x0045f10e:
    // 0045f10e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f110  e8db1afeff             -call 0x440bf0
    cpu.esp -= 4;
    sub_440bf0(app, cpu);
    if (cpu.terminate) return;
    // 0045f115  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 0045f11f  e935feffff             -jmp 0x45ef59
    goto L_0x0045ef59;
L_0x0045f124:
    // 0045f124  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f126  e835010000             -call 0x45f260
    cpu.esp -= 4;
    sub_45f260(app, cpu);
    if (cpu.terminate) return;
    // 0045f12b  c7817805000000000000   -mov dword ptr [ecx + 0x578], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 0 /*0x0*/;
L_0x0045f135:
    // 0045f135  8b9984010000           -mov ebx, dword ptr [ecx + 0x184]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */);
    // 0045f13b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045f13d  7412                   -je 0x45f151
    if (cpu.flags.zf)
    {
        goto L_0x0045f151;
    }
    // 0045f13f  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f142  740d                   -je 0x45f151
    if (cpu.flags.zf)
    {
        goto L_0x0045f151;
    }
    // 0045f144  83b97c01000000         +cmp dword ptr [ecx + 0x17c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(380) /* 0x17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f14b  0f842afeffff           -je 0x45ef7b
    if (cpu.flags.zf)
    {
        goto L_0x0045ef7b;
    }
L_0x0045f151:
    // 0045f151  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 0045f15b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f15c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f15d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f15e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f15f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_45f160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f160  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f161  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045f163  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f16a  7402                   -je 0x45f16e
    if (cpu.flags.zf)
    {
        goto L_0x0045f16e;
    }
    // 0045f16c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f16d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f16e:
    // 0045f16e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f16f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f170  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0045f176  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0045f17c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f17e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f181  c1e810                 +shr eax, 0x10
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
    // 0045f184  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f186  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045f188  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 0045f18e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0045f194  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f196  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f199  c1e810                 +shr eax, 0x10
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
    // 0045f19c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f19e  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0045f1a4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f1a6  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0045f1ac  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f1ae  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f1b1  c1e810                 +shr eax, 0x10
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
    // 0045f1b4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f1b6  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0045f1bc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f1be  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0045f1c4  8999b0020000           -mov dword ptr [ecx + 0x2b0], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(688) /* 0x2b0 */) = cpu.ebx;
    // 0045f1ca  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f1cc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f1cf  c1e810                 +shr eax, 0x10
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
    // 0045f1d2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f1d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045f1d6  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0045f1dc  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0045f1e2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f1e4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f1e7  c1e810                 +shr eax, 0x10
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
    // 0045f1ea  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f1ec  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0045f1f2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f1f4  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0045f1fa  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f1fc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f1ff  c1e810                 +shr eax, 0x10
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
    // 0045f202  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f204  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0045f20a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f20c  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0045f212  8999b4020000           -mov dword ptr [ecx + 0x2b4], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */) = cpu.ebx;
    // 0045f218  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f21a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f21d  c1e810                 +shr eax, 0x10
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
    // 0045f220  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f222  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045f224  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0045f22a  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0045f230  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f232  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f235  c1e810                 +shr eax, 0x10
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
    // 0045f238  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f23a  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 0045f240  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f242  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0045f248  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f24a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f24d  c1e810                 +shr eax, 0x10
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
    // 0045f250  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f252  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f254  8999b8020000           -mov dword ptr [ecx + 0x2b8], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.ebx;
    // 0045f25a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f25b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f25c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f25d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45f260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f260  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f261  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f262  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f263  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f264  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f265  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045f267  c780a800000000000000   -mov dword ptr [eax + 0xa8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 0045f271  c780ac00000000000000   -mov dword ptr [eax + 0xac], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 0045f27b  c780b000000000000000   -mov dword ptr [eax + 0xb0], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 0045f285  8db83c010000           -lea edi, [eax + 0x13c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(316) /* 0x13c */);
    // 0045f28b  c780e800000000000000   -mov dword ptr [eax + 0xe8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 0045f295  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 0045f29b  c780ec00000000000000   -mov dword ptr [eax + 0xec], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 0045f2a5  059c000000             -add eax, 0x9c
    (cpu.eax) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 0045f2aa  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0045f2ac  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045f2ae  c7405400000000         -mov dword ptr [eax + 0x54], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 0045f2b5  e836f9feff             -call 0x44ebf0
    cpu.esp -= 4;
    sub_44ebf0(app, cpu);
    if (cpu.terminate) return;
    // 0045f2ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0045f2bc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045f2be  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0045f2c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f2c6  e8a5f6feff             -call 0x44e970
    cpu.esp -= 4;
    sub_44e970(app, cpu);
    if (cpu.terminate) return;
    // 0045f2cb  89815c010000           -mov dword ptr [ecx + 0x15c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = cpu.eax;
    // 0045f2d1  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0045f2d7  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 0045f2e1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f2e3  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 0045f2e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2eb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2ec  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2ed  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f2ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_45f2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f2f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f300  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f301  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045f306  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f308  a3e8fd4f00             -mov dword ptr [0x4ffde8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5242344) /* 0x4ffde8 */) = cpu.eax;
    // 0045f30d  8915e0fd4f00           -mov dword ptr [0x4ffde0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5242336) /* 0x4ffde0 */) = cpu.edx;
    // 0045f313  8915e4fd4f00           -mov dword ptr [0x4ffde4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */) = cpu.edx;
    // 0045f319  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f31a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f320  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f321  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045f326  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f328  a3e8fd4f00             -mov dword ptr [0x4ffde8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5242344) /* 0x4ffde8 */) = cpu.eax;
    // 0045f32d  8915e0fd4f00           -mov dword ptr [0x4ffde0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5242336) /* 0x4ffde0 */) = cpu.edx;
    // 0045f333  8915e4fd4f00           -mov dword ptr [0x4ffde4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */) = cpu.edx;
    // 0045f339  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f33a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f340  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f341  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f342  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f343  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f344  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f345  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f346  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045f349  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0045f34d  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0045f352  a1e4fd4f00             -mov eax, dword ptr [0x4ffde4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f357  e8241b0100             -call 0x470e80
    cpu.esp -= 4;
    sub_470e80(app, cpu);
    if (cpu.terminate) return;
    // 0045f35c  8b15e4fd4f00           -mov edx, dword ptr [0x4ffde4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f362  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0045f364  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045f366  7e53                   -jle 0x45f3bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f3bb;
    }
    // 0045f368  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f36c  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0045f36f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045f372  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f376  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0045f379  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045f37d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f381  be10ec4f00             -mov esi, 0x4fec10
    cpu.esi = 5237776 /*0x4fec10*/;
    // 0045f386  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045f389  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045f38c  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0045f390:
    // 0045f390  6bfd4c                 -imul edi, ebp, 0x4c
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(76 /*0x4c*/)));
    // 0045f393  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0045f398  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045f39c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045f39e  e83dceffff             -call 0x45c1e0
    cpu.esp -= 4;
    sub_45c1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045f3a3  81c710ec4f00           -add edi, 0x4fec10
    (cpu.edi) += x86::reg32(x86::sreg32(5237776 /*0x4fec10*/));
    // 0045f3a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f3ab  7518                   -jne 0x45f3c5
    if (!cpu.flags.zf)
    {
        goto L_0x0045f3c5;
    }
L_0x0045f3ad:
    // 0045f3ad  8b0de4fd4f00           -mov ecx, dword ptr [0x4ffde4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f3b3  45                     -inc ebp
    (cpu.ebp)++;
    // 0045f3b4  83c64c                 -add esi, 0x4c
    (cpu.esi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0045f3b7  39cd                   +cmp ebp, ecx
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
    // 0045f3b9  7cd5                   -jl 0x45f390
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f390;
    }
L_0x0045f3bb:
    // 0045f3bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045f3be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f3c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f3c5:
    // 0045f3c5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045f3ca  8d4728                 -lea eax, [edi + 0x28]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0045f3cd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045f3d0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045f3d1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0045f3d3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045f3d7  e884ea0000             -call 0x46de60
    cpu.esp -= 4;
    sub_46de60(app, cpu);
    if (cpu.terminate) return;
    // 0045f3dc  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f3df  74cc                   -je 0x45f3ad
    if (cpu.flags.zf)
    {
        goto L_0x0045f3ad;
    }
    // 0045f3e1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f3e5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0045f3e7  e888320100             -call 0x472674
    cpu.esp -= 4;
    sub_472674(app, cpu);
    if (cpu.terminate) return;
    // 0045f3ec  ebbf                   -jmp 0x45f3ad
    goto L_0x0045f3ad;
}

/* align: skip 0x00 0x00 */
void Application::sub_45f3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f3f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f3f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f3f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f3f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f3f4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f3f5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f3f6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045f3f9  8b2de4fd4f00           -mov ebp, dword ptr [0x4ffde4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f3ff  8b15e8fd4f00           -mov edx, dword ptr [0x4ffde8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5242344) /* 0x4ffde8 */);
    // 0045f405  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045f40a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f40c  83f803                 +cmp eax, 3
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
    // 0045f40f  0f8ea4000000           -jle 0x45f4b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f4b9;
    }
    // 0045f415  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045f41a  a3e8fd4f00             -mov dword ptr [0x4ffde8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5242344) /* 0x4ffde8 */) = cpu.eax;
    // 0045f41f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f421  0f85a2000000           -jne 0x45f4c9
    if (!cpu.flags.zf)
    {
        goto L_0x0045f4c9;
    }
L_0x0045f427:
    // 0045f427  8b2de4fd4f00           -mov ebp, dword ptr [0x4ffde4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f42d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f42f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f431  7e6b                   -jle 0x45f49e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f49e;
    }
    // 0045f433  ba10ec4f00             -mov edx, 0x4fec10
    cpu.edx = 5237776 /*0x4fec10*/;
L_0x0045f438:
    // 0045f438  8a6202                 -mov ah, byte ptr [edx + 2]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0045f43b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045f43d  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0045f43f  0f840a010000           -je 0x45f54f
    if (cpu.flags.zf)
    {
        goto L_0x0045f54f;
    }
    // 0045f445  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045f448  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0045f44b  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045f44e  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045f450  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f452  897210                 -mov dword ptr [edx + 0x10], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0045f455  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045f459  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0045f45c  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0045f45f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0045f461  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f463  897214                 -mov dword ptr [edx + 0x14], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0045f466  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0045f46a  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0045f46d  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0045f470  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0045f472:
    // 0045f472  01c6                   +add esi, eax
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
    // 0045f474  892de4fd4f00           -mov dword ptr [0x4ffde4], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */) = cpu.ebp;
    // 0045f47a  897218                 -mov dword ptr [edx + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0045f47d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f47f  e84c020000             -call 0x45f6d0
    cpu.esp -= 4;
    sub_45f6d0(app, cpu);
    if (cpu.terminate) return;
    // 0045f484  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0045f487  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0045f488  897904                 -mov dword ptr [ecx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0045f48b  7503                   -jne 0x45f490
    if (!cpu.flags.zf)
    {
        goto L_0x0045f490;
    }
    // 0045f48d  c60100                 -mov byte ptr [ecx], 0
    *app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x0045f490:
    // 0045f490  8b2de4fd4f00           -mov ebp, dword ptr [0x4ffde4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f496  43                     -inc ebx
    (cpu.ebx)++;
    // 0045f497  83c24c                 -add edx, 0x4c
    (cpu.edx) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0045f49a  39eb                   +cmp ebx, ebp
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
    // 0045f49c  7c9a                   -jl 0x45f438
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f438;
    }
L_0x0045f49e:
    // 0045f49e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f4a0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f4a2  7e15                   -jle 0x45f4b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f4b9;
    }
L_0x0045f4a4:
    // 0045f4a4  6bf04c                 -imul esi, eax, 0x4c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(76 /*0x4c*/)));
    // 0045f4a7  80be10ec4f0000         +cmp byte ptr [esi + 0x4fec10], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5237776) /* 0x4fec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045f4ae  0f84bc000000           -je 0x45f570
    if (cpu.flags.zf)
    {
        goto L_0x0045f570;
    }
L_0x0045f4b4:
    // 0045f4b4  40                     -inc eax
    (cpu.eax)++;
    // 0045f4b5  39e8                   +cmp eax, ebp
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
    // 0045f4b7  7ceb                   -jl 0x45f4a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f4a4;
    }
L_0x0045f4b9:
    // 0045f4b9  892de4fd4f00           -mov dword ptr [0x4ffde4], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */) = cpu.ebp;
    // 0045f4bf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045f4c2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f4c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f4c9:
    // 0045f4c9  8b0de0fd4f00           -mov ecx, dword ptr [0x4ffde0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5242336) /* 0x4ffde0 */);
    // 0045f4cf  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f4d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045f4d4  890de0fd4f00           -mov dword ptr [0x4ffde0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5242336) /* 0x4ffde0 */) = cpu.ecx;
    // 0045f4da  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0045f4e0  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0045f4e3  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f4e5  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045f4e7  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0045f4e9  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f4eb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045f4f0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f4f2  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0045f4f9  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f4fb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f4fd  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 0045f502  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f504  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f507  c1e810                 +shr eax, 0x10
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
    // 0045f50a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f50c  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0045f50f  a1e0fd4f00             -mov eax, dword ptr [0x4ffde0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242336) /* 0x4ffde0 */);
    // 0045f514  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f516  c0e407                 +shl ah, 7
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
    // 0045f519  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0045f51b  00e4                   +add ah, ah
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
    // 0045f51d  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0045f51f  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f521  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045f526  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f528  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0045f52f  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f531  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045f533  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 0045f538  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0045f53c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0045f53e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0045f541  c1e810                 +shr eax, 0x10
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
    // 0045f544  11d0                   +adc eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045f546  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045f54a  e9d8feffff             -jmp 0x45f427
    goto L_0x0045f427;
L_0x0045f54f:
    // 0045f54f  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045f552  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0045f555  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f557  897210                 -mov dword ptr [edx + 0x10], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0045f55a  8b7a14                 -mov edi, dword ptr [edx + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0045f55d  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0045f560  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0045f563  01c7                   +add edi, eax
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
    // 0045f565  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0045f568  897a14                 -mov dword ptr [edx + 0x14], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0045f56b  e902ffffff             -jmp 0x45f472
    goto L_0x0045f472;
L_0x0045f570:
    // 0045f570  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0045f573  6bda4c                 +imul ebx, edx, 0x4c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(76 /*0x4c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0045f576  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 0045f57b  8dbe10ec4f00           -lea edi, [esi + 0x4fec10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5237776) /* 0x4fec10 */);
    // 0045f581  8db310ec4f00           -lea esi, [ebx + 0x4fec10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(5237776) /* 0x4fec10 */);
    // 0045f587  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0045f588  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045f58a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f58c  e923ffffff             -jmp 0x45f4b4
    goto L_0x0045f4b4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f5c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0045f5c4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f5c5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f5c6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f5c7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f5c8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045f5cb  8b2de4fd4f00           -mov ebp, dword ptr [0x4ffde4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f5d1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045f5d3  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0045f5d7  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0045f5db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f5dd  83fd3c                 +cmp ebp, 0x3c
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f5e0  0f85b3000000           -jne 0x45f699
    if (!cpu.flags.zf)
    {
        goto L_0x0045f699;
    }
    // 0045f5e6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045f5eb  8b0d14ec4f00           -mov ecx, dword ptr [0x4fec14]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5237780) /* 0x4fec14 */);
    // 0045f5f1  39c5                   +cmp ebp, eax
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
    // 0045f5f3  7e1b                   -jle 0x45f610
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f610;
    }
    // 0045f5f5  ba4c000000             -mov edx, 0x4c
    cpu.edx = 76 /*0x4c*/;
L_0x0045f5fa:
    // 0045f5fa  8bba14ec4f00           -mov edi, dword ptr [edx + 0x4fec14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5237780) /* 0x4fec14 */);
    // 0045f600  39f9                   +cmp ecx, edi
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
    // 0045f602  7e04                   -jle 0x45f608
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f608;
    }
    // 0045f604  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0045f606  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0045f608:
    // 0045f608  40                     -inc eax
    (cpu.eax)++;
    // 0045f609  83c24c                 -add edx, 0x4c
    (cpu.edx) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0045f60c  39e8                   +cmp eax, ebp
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
    // 0045f60e  7cea                   -jl 0x45f5fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f5fa;
    }
L_0x0045f610:
    // 0045f610  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0045f617  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f619  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045f61c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f61e  ba10ec4f00             -mov edx, 0x4fec10
    cpu.edx = 5237776 /*0x4fec10*/;
    // 0045f623  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045f626  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045f628  8d7a10                 -lea edi, [edx + 0x10]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0045f62b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f62c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f62d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045f62e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f632  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0045f639  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0045f63b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045f63f  885a01                 -mov byte ptr [edx + 1], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0045f642  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f644  7513                   -jne 0x45f659
    if (!cpu.flags.zf)
    {
        goto L_0x0045f659;
    }
    // 0045f646  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0045f648  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f64a  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0045f64e  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0045f651  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045f655  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x0045f659:
    // 0045f659  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0045f65d  48                     -dec eax
    (cpu.eax)--;
    // 0045f65e  892de4fd4f00           -mov dword ptr [0x4ffde4], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */) = cpu.ebp;
    // 0045f664  83f808                 +cmp eax, 8
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
    // 0045f667  7719                   -ja 0x45f682
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0045f682;
    }
    // 0045f669  ff2485a0f54500         -jmp dword ptr [eax*4 + 0x45f5a0]
    cpu.ip = *app->getMemory<x86::reg32>(4584864 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045f670:
    // 0045f670  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f672  e8b9000000             -call 0x45f730
    cpu.esp -= 4;
    sub_45f730(app, cpu);
    if (cpu.terminate) return;
    // 0045f677  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f679  c6420201               -mov byte ptr [edx + 2], 1
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 1 /*0x1*/;
L_0x0045f67d:
    // 0045f67d  e88e000000             -call 0x45f710
    cpu.esp -= 4;
    sub_45f710(app, cpu);
    if (cpu.terminate) return;
L_0x0045f682:
    // 0045f682  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f684  e87b2f0100             -call 0x472604
    cpu.esp -= 4;
    sub_472604(app, cpu);
    if (cpu.terminate) return;
    // 0045f689  8b2de4fd4f00           -mov ebp, dword ptr [0x4ffde4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5242340) /* 0x4ffde4 */);
    // 0045f68f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f691  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045f694  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f695  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f696  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f697  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f698  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f699:
    // 0045f699  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0045f69b  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045f69c  e96fffffff             -jmp 0x45f610
    goto L_0x0045f610;
  case 0x0045f6a1:
    // 0045f6a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045f6a5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045f6a7  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0045f6aa  89421c                 -mov dword ptr [edx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0045f6ad  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045f6b1  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0045f6b4  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0045f6b7  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0045f6ba  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0045f6be  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045f6c1  c1f805                 +sar eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0045f6c4  894224                 -mov dword ptr [edx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0045f6c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f6c9  c6420200               -mov byte ptr [edx + 2], 0
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0045f6cd  ebae                   -jmp 0x45f67d
    goto L_0x0045f67d;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_45f6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f6d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f6d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f6d2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f6d3  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0045f6d6  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0045f6d9  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0045f6dc  894808                 -mov dword ptr [eax + 8], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0045f6df  83fbfd                 +cmp ebx, -3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f6e2  7c09                   -jl 0x45f6ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f6ed;
    }
    // 0045f6e4  83fb03                 +cmp ebx, 3
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
    // 0045f6e7  7f0e                   -jg 0x45f6f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045f6f7;
    }
    // 0045f6e9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f6ed:
    // 0045f6ed  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0045f6f0  89680c                 -mov dword ptr [eax + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0045f6f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6f4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6f5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f6f7:
    // 0045f6f7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f6f8  8d7bff                 -lea edi, [ebx - 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0045f6fb  89780c                 -mov dword ptr [eax + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0045f6fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f6ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f700  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f701  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f710  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f711  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f713  e858d50100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0045f718  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0045f71b  e850d50100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0045f720  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0045f723  83e83f                 -sub eax, 0x3f
    (cpu.eax) -= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0045f726  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0045f729  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f72a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f730  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f731  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045f733  e838d50100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0045f738  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0045f73d  89421c                 -mov dword ptr [edx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0045f740  e82bd50100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0045f745  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0045f74a  894224                 -mov dword ptr [edx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0045f74d  e81ed50100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0045f752  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0045f757  05ff070000             -add eax, 0x7ff
    (cpu.eax) += x86::reg32(x86::sreg32(2047 /*0x7ff*/));
    // 0045f75c  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0045f75f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f760  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f770  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f771  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f772  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f773  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f774  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f775  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f776  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f779  8b1564d54f00           -mov edx, dword ptr [0x4fd564]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */);
    // 0045f77f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045f781  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045f783  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045f785  0f8565000000           -jne 0x45f7f0
    if (!cpu.flags.zf)
    {
        goto L_0x0045f7f0;
    }
    // 0045f78b  833d60cf4d0000         +cmp dword ptr [0x4dcf60], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f792  7e4d                   -jle 0x45f7e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f7e1;
    }
    // 0045f794  8b1560cf4d00           -mov edx, dword ptr [0x4dcf60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045f79a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045f79c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045f79e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045f7a0  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0045f7a3:
    // 0045f7a3  8b91e8cd4d00           -mov edx, dword ptr [ecx + 0x4dcde8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f7a9  8bba1c020000           -mov edi, dword ptr [edx + 0x21c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(540) /* 0x21c */);
    // 0045f7af  833f24                 +cmp dword ptr [edi], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f7b2  745b                   -je 0x45f80f
    if (cpu.flags.zf)
    {
        goto L_0x0045f80f;
    }
    // 0045f7b4  83ba8002000002         +cmp dword ptr [edx + 0x280], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f7bb  753d                   -jne 0x45f7fa
    if (!cpu.flags.zf)
    {
        goto L_0x0045f7fa;
    }
    // 0045f7bd  8b9224020000           -mov edx, dword ptr [edx + 0x224]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */);
    // 0045f7c3  8b2d84d54f00           -mov ebp, dword ptr [0x4fd584]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045f7c9  81c240010000           -add edx, 0x140
    (cpu.edx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0045f7cf  39ea                   +cmp edx, ebp
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
    // 0045f7d1  7d27                   -jge 0x45f7fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045f7fa;
    }
L_0x0045f7d3:
    // 0045f7d3  43                     -inc ebx
    (cpu.ebx)++;
L_0x0045f7d4:
    // 0045f7d4  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045f7d7  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045f7da  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f7dd  39f8                   +cmp eax, edi
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
    // 0045f7df  7cc2                   -jl 0x45f7a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f7a3;
    }
L_0x0045f7e1:
    // 0045f7e1  a160cf4d00             -mov eax, dword ptr [0x4dcf60]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045f7e6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0045f7e8  39c3                   +cmp ebx, eax
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
    // 0045f7ea  7504                   -jne 0x45f7f0
    if (!cpu.flags.zf)
    {
        goto L_0x0045f7f0;
    }
    // 0045f7ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045f7ee  7f22                   -jg 0x45f812
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045f812;
    }
L_0x0045f7f0:
    // 0045f7f0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f7f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f7f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f7fa:
    // 0045f7fa  833de8d24d0004         +cmp dword ptr [0x4dd2e8], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f801  75d1                   -jne 0x45f7d4
    if (!cpu.flags.zf)
    {
        goto L_0x0045f7d4;
    }
    // 0045f803  6683b8c8e44d0000       +cmp word ptr [eax + 0x4de4c8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5104840) /* 0x4de4c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045f80b  75c6                   -jne 0x45f7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0045f7d3;
    }
    // 0045f80d  ebc5                   -jmp 0x45f7d4
    goto L_0x0045f7d4;
L_0x0045f80f:
    // 0045f80f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045f810  ebc2                   -jmp 0x45f7d4
    goto L_0x0045f7d4;
L_0x0045f812:
    // 0045f812  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0045f817  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0045f81c  892d64d54f00           -mov dword ptr [0x4fd564], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5231972) /* 0x4fd564 */) = cpu.ebp;
    // 0045f822  e819000000             -call 0x45f840
    cpu.esp -= 4;
    sub_45f840(app, cpu);
    if (cpu.terminate) return;
    // 0045f827  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f82a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f82b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f82c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f82d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f82e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f82f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f830  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45f840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045f840  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045f841  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045f842  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045f843  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045f844  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045f845  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045f846  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f849  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045f84b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045f850  8b0d60cf4d00           -mov ecx, dword ptr [0x4dcf60]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045f856  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045f858  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0045f85b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045f85d  0f8e7b000000           -jle 0x45f8de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f8de;
    }
    // 0045f863  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045f865:
    // 0045f865  8b15d0c94d00           -mov edx, dword ptr [0x4dc9d0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 0045f86b  0faf15dcd24d00         -imul edx, dword ptr [0x4dd2dc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100252) /* 0x4dd2dc */))));
    // 0045f872  8b99e8cd4d00           -mov ebx, dword ptr [ecx + 0x4dcde8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f878  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 0045f87e  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f881  0f85ec000000           -jne 0x45f973
    if (!cpu.flags.zf)
    {
        goto L_0x0045f973;
    }
    // 0045f887  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0045f88d  39ea                   +cmp edx, ebp
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
    // 0045f88f  7e16                   -jle 0x45f8a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f8a7;
    }
    // 0045f891  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f893  0f85c0000000           -jne 0x45f959
    if (!cpu.flags.zf)
    {
        goto L_0x0045f959;
    }
    // 0045f899  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045f89b:
    // 0045f89b  8b91e8cd4d00           -mov edx, dword ptr [ecx + 0x4dcde8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f8a1  898234020000           -mov dword ptr [edx + 0x234], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
L_0x0045f8a7:
    // 0045f8a7  8b81e8cd4d00           -mov eax, dword ptr [ecx + 0x4dcde8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f8ad  89b880020000           -mov dword ptr [eax + 0x280], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x0045f8b3:
    // 0045f8b3  83ff01                 +cmp edi, 1
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
    // 0045f8b6  7518                   -jne 0x45f8d0
    if (!cpu.flags.zf)
    {
        goto L_0x0045f8d0;
    }
    // 0045f8b8  3b3dd8d24d00           +cmp edi, dword ptr [0x4dd2d8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100248) /* 0x4dd2d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f8be  0f8418010000           -je 0x45f9dc
    if (cpu.flags.zf)
    {
        goto L_0x0045f9dc;
    }
    // 0045f8c4  8b81e8cd4d00           -mov eax, dword ptr [ecx + 0x4dcde8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
L_0x0045f8ca:
    // 0045f8ca  89b880020000           -mov dword ptr [eax + 0x280], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x0045f8d0:
    // 0045f8d0  8b1d60cf4d00           -mov ebx, dword ptr [0x4dcf60]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045f8d6  46                     -inc esi
    (cpu.esi)++;
    // 0045f8d7  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f8da  39de                   +cmp esi, ebx
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
    // 0045f8dc  7c87                   -jl 0x45f865
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f865;
    }
L_0x0045f8de:
    // 0045f8de  8b2d50cf4d00           -mov ebp, dword ptr [0x4dcf50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5099344) /* 0x4dcf50 */);
    // 0045f8e4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045f8e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f8e8  7e65                   -jle 0x45f94f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045f94f;
    }
    // 0045f8ea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045f8ec:
    // 0045f8ec  8b99a8cc4d00           -mov ebx, dword ptr [ecx + 0x4dcca8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098664) /* 0x4dcca8 */);
    // 0045f8f2  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f8f9  7435                   -je 0x45f930
    if (cpu.flags.zf)
    {
        goto L_0x0045f930;
    }
    // 0045f8fb  83bb2002000000         +cmp dword ptr [ebx + 0x220], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f902  0f85f8000000           -jne 0x45fa00
    if (!cpu.flags.zf)
    {
        goto L_0x0045fa00;
    }
    // 0045f908  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045f90a:
    // 0045f90a  8b91a8cc4d00           -mov edx, dword ptr [ecx + 0x4dcca8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098664) /* 0x4dcca8 */);
    // 0045f910  898234020000           -mov dword ptr [edx + 0x234], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 0045f916  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f91a  0f840d010000           -je 0x45fa2d
    if (cpu.flags.zf)
    {
        goto L_0x0045fa2d;
    }
    // 0045f920  8b81a8cc4d00           -mov eax, dword ptr [ecx + 0x4dcca8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098664) /* 0x4dcca8 */);
    // 0045f926  c7808002000002000000   -mov dword ptr [eax + 0x280], 2
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
L_0x0045f930:
    // 0045f930  83ff01                 +cmp edi, 1
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
    // 0045f933  750c                   -jne 0x45f941
    if (!cpu.flags.zf)
    {
        goto L_0x0045f941;
    }
    // 0045f935  8b81a8cc4d00           -mov eax, dword ptr [ecx + 0x4dcca8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098664) /* 0x4dcca8 */);
    // 0045f93b  89b880020000           -mov dword ptr [eax + 0x280], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x0045f941:
    // 0045f941  8b2d50cf4d00           -mov ebp, dword ptr [0x4dcf50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5099344) /* 0x4dcf50 */);
    // 0045f947  46                     -inc esi
    (cpu.esi)++;
    // 0045f948  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f94b  39ee                   +cmp esi, ebp
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
    // 0045f94d  7c9d                   -jl 0x45f8ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045f8ec;
    }
L_0x0045f94f:
    // 0045f94f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045f952  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f953  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f954  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f955  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f956  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f957  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045f958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045f959:
    // 0045f959  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 0045f95f  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045f964  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045f967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f969  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f96c  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045f96e  e928ffffff             -jmp 0x45f89b
    goto L_0x0045f89b;
L_0x0045f973:
    // 0045f973  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f97a  0f8433ffffff           -je 0x45f8b3
    if (cpu.flags.zf)
    {
        goto L_0x0045f8b3;
    }
    // 0045f980  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0045f986  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045f988  7531                   -jne 0x45f9bb
    if (!cpu.flags.zf)
    {
        goto L_0x0045f9bb;
    }
    // 0045f98a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045f98c:
    // 0045f98c  8b91e8cd4d00           -mov edx, dword ptr [ecx + 0x4dcde8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f992  898234020000           -mov dword ptr [edx + 0x234], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 0045f998  833dd8d24d0001         +cmp dword ptr [0x4dd2d8], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100248) /* 0x4dd2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f99f  7431                   -je 0x45f9d2
    if (cpu.flags.zf)
    {
        goto L_0x0045f9d2;
    }
L_0x0045f9a1:
    // 0045f9a1  8b81e8cd4d00           -mov eax, dword ptr [ecx + 0x4dcde8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f9a7  c7808002000001000000   -mov dword ptr [eax + 0x280], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
L_0x0045f9b1:
    // 0045f9b1  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0045f9b3  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0045f9b6  e9f8feffff             -jmp 0x45f8b3
    goto L_0x0045f8b3;
L_0x0045f9bb:
    // 0045f9bb  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 0045f9c1  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045f9c6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045f9c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045f9cb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045f9ce  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045f9d0  ebba                   -jmp 0x45f98c
    goto L_0x0045f98c;
L_0x0045f9d2:
    // 0045f9d2  3b35ecd24d00           +cmp esi, dword ptr [0x4dd2ec]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f9d8  75d7                   -jne 0x45f9b1
    if (!cpu.flags.zf)
    {
        goto L_0x0045f9b1;
    }
    // 0045f9da  ebc5                   -jmp 0x45f9a1
    goto L_0x0045f9a1;
L_0x0045f9dc:
    // 0045f9dc  8b81e8cd4d00           -mov eax, dword ptr [ecx + 0x4dcde8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045f9e2  83b88002000002         +cmp dword ptr [eax + 0x280], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f9e9  0f84e1feffff           -je 0x45f8d0
    if (cpu.flags.zf)
    {
        goto L_0x0045f8d0;
    }
    // 0045f9ef  3b35ecd24d00           +cmp esi, dword ptr [0x4dd2ec]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045f9f5  0f85d5feffff           -jne 0x45f8d0
    if (!cpu.flags.zf)
    {
        goto L_0x0045f8d0;
    }
    // 0045f9fb  e9cafeffff             -jmp 0x45f8ca
    goto L_0x0045f8ca;
L_0x0045fa00:
    // 0045fa00  8b15d0c94d00           -mov edx, dword ptr [0x4dc9d0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 0045fa06  0faf15dcd24d00         -imul edx, dword ptr [0x4dd2dc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100252) /* 0x4dd2dc */))));
    // 0045fa0d  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 0045fa13  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045fa18  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045fa1b  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0045fa21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fa23  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045fa26  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045fa28  e9ddfeffff             -jmp 0x45f90a
    goto L_0x0045f90a;
L_0x0045fa2d:
    // 0045fa2d  8b81a8cc4d00           -mov eax, dword ptr [ecx + 0x4dcca8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5098664) /* 0x4dcca8 */);
    // 0045fa33  89b880020000           -mov dword ptr [eax + 0x280], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
    // 0045fa39  e9f2feffff             -jmp 0x45f930
    goto L_0x0045f930;
}

/* align: skip 0x00 0x00 */
void Application::sub_45fa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fa40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fa41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fa42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fa43  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045fa44  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045fa45  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045fa46  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045fa49  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0045fa4b  8b9030020000           -mov edx, dword ptr [eax + 0x230]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 0045fa51  83fa08                 +cmp edx, 8
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
    // 0045fa54  7d73                   -jge 0x45fac9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fac9;
    }
    // 0045fa56  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045fa5d  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0045fa60  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0045fa66  3b8258020000           +cmp eax, dword ptr [edx + 0x258]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fa6c  7e5b                   -jle 0x45fac9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fac9;
    }
    // 0045fa6e  f685f401000008         +test byte ptr [ebp + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 0045fa75  0f8494020000           -je 0x45fd0f
    if (cpu.flags.zf)
    {
        goto L_0x0045fd0f;
    }
    // 0045fa7b  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0045fa81  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045fa83  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fa86  0f8d83020000           -jge 0x45fd0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fd0f;
    }
    // 0045fa8c  833de8d24d0002         +cmp dword ptr [0x4dd2e8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fa93  0f8c2c020000           -jl 0x45fcc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fcc5;
    }
    // 0045fa99  6985e801000099190000   -imul eax, dword ptr [ebp + 0x1e8], 0x1999
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */))) * x86::sreg64(x86::sreg32(6553 /*0x1999*/)));
    // 0045faa3  8b149de0324c00         -mov edx, dword ptr [ebx*4 + 0x4c32e0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(4993760) /* 0x4c32e0 */ + cpu.ebx * 4);
    // 0045faaa  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045faac  8b9db8020000           -mov ebx, dword ptr [ebp + 0x2b8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0045fab2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fab4  39da                   +cmp edx, ebx
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
    // 0045fab6  0f8d02020000           -jge 0x45fcbe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fcbe;
    }
L_0x0045fabc:
    // 0045fabc  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0045fac2  89849558020000         -mov dword ptr [ebp + edx*4 + 0x258], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(600) /* 0x258 */ + cpu.edx * 4) = cpu.eax;
L_0x0045fac9:
    // 0045fac9  8bb5f8010000           -mov esi, dword ptr [ebp + 0x1f8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 0045facf  3bb530020000           +cmp esi, dword ptr [ebp + 0x230]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fad5  0f8491000000           -je 0x45fb6c
    if (cpu.flags.zf)
    {
        goto L_0x0045fb6c;
    }
    // 0045fadb  83bd8002000002         +cmp dword ptr [ebp + 0x280], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fae2  0f8484000000           -je 0x45fb6c
    if (cpu.flags.zf)
    {
        goto L_0x0045fb6c;
    }
    // 0045fae8  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045faed  8b9534020000           -mov edx, dword ptr [ebp + 0x234]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 0045faf3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045faf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045faf7  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0045fafd  89948538020000         -mov dword ptr [ebp + eax*4 + 0x238], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(568) /* 0x238 */ + cpu.eax * 4) = cpu.edx;
    // 0045fb04  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045fb09  898534020000           -mov dword ptr [ebp + 0x234], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 0045fb0f  8b85f8010000           -mov eax, dword ptr [ebp + 0x1f8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 0045fb15  8b0ddcd24d00           -mov ecx, dword ptr [0x4dd2dc]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5100252) /* 0x4dd2dc */);
    // 0045fb1b  898530020000           -mov dword ptr [ebp + 0x230], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 0045fb21  39c8                   +cmp eax, ecx
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
    // 0045fb23  7547                   -jne 0x45fb6c
    if (!cpu.flags.zf)
    {
        goto L_0x0045fb6c;
    }
    // 0045fb25  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0045fb2b  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb2e  743c                   -je 0x45fb6c
    if (cpu.flags.zf)
    {
        goto L_0x0045fb6c;
    }
    // 0045fb30  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0045fb36  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045fb3b  42                     -inc edx
    (cpu.edx)++;
    // 0045fb3c  898524020000           -mov dword ptr [ebp + 0x224], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 0045fb42  a1d0c94d00             -mov eax, dword ptr [0x4dc9d0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 0045fb47  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0045fb4a  8bb534020000           -mov esi, dword ptr [ebp + 0x234]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 0045fb50  c7858002000002000000   -mov dword ptr [ebp + 0x280], 2
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
    // 0045fb5a  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0045fb60  89b534020000           -mov dword ptr [ebp + 0x234], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.esi;
    // 0045fb66  899520020000           -mov dword ptr [ebp + 0x220], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.edx;
L_0x0045fb6c:
    // 0045fb6c  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0045fb6f  3bbd28020000           +cmp edi, dword ptr [ebp + 0x228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fb75  7455                   -je 0x45fbcc
    if (cpu.flags.zf)
    {
        goto L_0x0045fbcc;
    }
    // 0045fb77  8b8580020000           -mov eax, dword ptr [ebp + 0x280]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
    // 0045fb7d  89bd28020000           -mov dword ptr [ebp + 0x228], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */) = cpu.edi;
    // 0045fb83  83f802                 +cmp eax, 2
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
    // 0045fb86  7444                   -je 0x45fbcc
    if (cpu.flags.zf)
    {
        goto L_0x0045fbcc;
    }
    // 0045fb88  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0045fb8d  8b1508d34d00           -mov edx, dword ptr [0x4dd308]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100296) /* 0x4dd308 */);
    // 0045fb93  898524020000           -mov dword ptr [ebp + 0x224], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 0045fb99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045fb9b  0f848b010000           -je 0x45fd2c
    if (cpu.flags.zf)
    {
        goto L_0x0045fd2c;
    }
    // 0045fba1  8b15d0c94d00           -mov edx, dword ptr [0x4dc9d0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 0045fba7  2b9528020000           -sub edx, dword ptr [ebp + 0x228]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
L_0x0045fbad:
    // 0045fbad  8b9dfc010000           -mov ebx, dword ptr [ebp + 0x1fc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(508) /* 0x1fc */);
    // 0045fbb3  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0045fbb9  8b35d0c94d00           -mov esi, dword ptr [0x4dc9d0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 0045fbbf  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045fbc1  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0045fbc4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045fbc6  898520020000           -mov dword ptr [ebp + 0x220], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0045fbcc:
    // 0045fbcc  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0045fbd2  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fbd5  0f84d9000000           -je 0x45fcb4
    if (cpu.flags.zf)
    {
        goto L_0x0045fcb4;
    }
    // 0045fbdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fbdd  8b1564cf4d00           -mov edx, dword ptr [0x4dcf64]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fbe3  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0045fbe7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045fbe9  0f8ec5000000           -jle 0x45fcb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fcb4;
    }
    // 0045fbef  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 0045fbf2  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0045fbf5:
    // 0045fbf5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045fbf9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045fbfc  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 0045fc02  8bb0f0fd4f00           -mov esi, dword ptr [eax + 0x4ffdf0]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242352) /* 0x4ffdf0 */);
    // 0045fc08  39f2                   +cmp edx, esi
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
    // 0045fc0a  0f8e27010000           -jle 0x45fd37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fd37;
    }
L_0x0045fc10:
    // 0045fc10  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0045fc13  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045fc17  39d8                   +cmp eax, ebx
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
    // 0045fc19  7c3f                   -jl 0x45fc5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fc5a;
    }
    // 0045fc1b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0045fc1d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045fc20  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
L_0x0045fc23:
    // 0045fc23  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fc26  8bb0fcfd4f00           -mov esi, dword ptr [eax + 0x4ffdfc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242364) /* 0x4ffdfc */);
    // 0045fc2c  8b9000fe4f00           -mov edx, dword ptr [eax + 0x4ffe00]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242368) /* 0x4ffe00 */);
    // 0045fc32  89b00cfe4f00           -mov dword ptr [eax + 0x4ffe0c], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242380) /* 0x4ffe0c */) = cpu.esi;
    // 0045fc38  899010fe4f00           -mov dword ptr [eax + 0x4ffe10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242384) /* 0x4ffe10 */) = cpu.edx;
    // 0045fc3e  8b9804fe4f00           -mov ebx, dword ptr [eax + 0x4ffe04]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242372) /* 0x4ffe04 */);
    // 0045fc44  8b8808fe4f00           -mov ecx, dword ptr [eax + 0x4ffe08]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242376) /* 0x4ffe08 */);
    // 0045fc4a  899814fe4f00           -mov dword ptr [eax + 0x4ffe14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242388) /* 0x4ffe14 */) = cpu.ebx;
    // 0045fc50  898818fe4f00           -mov dword ptr [eax + 0x4ffe18], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242392) /* 0x4ffe18 */) = cpu.ecx;
    // 0045fc56  39f8                   +cmp eax, edi
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
    // 0045fc58  7dc9                   -jge 0x45fc23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fc23;
    }
L_0x0045fc5a:
    // 0045fc5a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045fc5e  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 0045fc64  8b8d24020000           -mov ecx, dword ptr [ebp + 0x224]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */);
    // 0045fc6a  8bb5e8010000           -mov esi, dword ptr [ebp + 0x1e8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */);
    // 0045fc70  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045fc73  8b9df4010000           -mov ebx, dword ptr [ebp + 0x1f4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(500) /* 0x1f4 */);
    // 0045fc79  89b0ecfd4f00           -mov dword ptr [eax + 0x4ffdec], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242348) /* 0x4ffdec */) = cpu.esi;
    // 0045fc7f  8990f0fd4f00           -mov dword ptr [eax + 0x4ffdf0], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242352) /* 0x4ffdf0 */) = cpu.edx;
    // 0045fc85  83e304                 -and ebx, 4
    cpu.ebx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045fc88  8988f4fd4f00           -mov dword ptr [eax + 0x4ffdf4], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242356) /* 0x4ffdf4 */) = cpu.ecx;
    // 0045fc8e  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 0045fc93  8998f8fd4f00           -mov dword ptr [eax + 0x4ffdf8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242360) /* 0x4ffdf8 */) = cpu.ebx;
    // 0045fc99  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x0045fc9d:
    // 0045fc9d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0045fca1  41                     -inc ecx
    (cpu.ecx)++;
    // 0045fca2  8b1d64cf4d00           -mov ebx, dword ptr [0x4dcf64]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fca8  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0045fcac  39d9                   +cmp ecx, ebx
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
    // 0045fcae  0f8c41ffffff           -jl 0x45fbf5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fbf5;
    }
L_0x0045fcb4:
    // 0045fcb4  83c408                 +add esp, 8
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
    // 0045fcb7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcb8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcb9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcba  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcbb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcbc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fcbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fcbe:
    // 0045fcbe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045fcc0  e9f7fdffff             -jmp 0x45fabc
    goto L_0x0045fabc;
L_0x0045fcc5:
    // 0045fcc5  e8a5a90200             -call 0x48a66f
    cpu.esp -= 4;
    sub_48a66f(app, cpu);
    if (cpu.terminate) return;
    // 0045fcca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045fccc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045fccf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fcd1  8b149de0324c00         -mov edx, dword ptr [ebx*4 + 0x4c32e0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(4993760) /* 0x4c32e0 */ + cpu.ebx * 4);
    // 0045fcd8  8bbdb8020000           -mov edi, dword ptr [ebp + 0x2b8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0045fcde  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fce0  39fa                   +cmp edx, edi
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
    // 0045fce2  7d24                   -jge 0x45fd08
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045fd08;
    }
    // 0045fce4  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0045fcea  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0045fcec  e87ea90200             -call 0x48a66f
    cpu.esp -= 4;
    sub_48a66f(app, cpu);
    if (cpu.terminate) return;
    // 0045fcf1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045fcf3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045fcf6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fcf8  8b148de0324c00         -mov edx, dword ptr [ecx*4 + 0x4c32e0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(4993760) /* 0x4c32e0 */ + cpu.ecx * 4);
    // 0045fcff  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045fd01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fd03  e9b4fdffff             -jmp 0x45fabc
    goto L_0x0045fabc;
L_0x0045fd08:
    // 0045fd08  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045fd0a  e9adfdffff             -jmp 0x45fabc
    goto L_0x0045fabc;
L_0x0045fd0f:
    // 0045fd0f  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0045fd15  c1e002                 +shl eax, 2
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
    // 0045fd18  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0045fd1b  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0045fd21  898258020000           -mov dword ptr [edx + 0x258], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */) = cpu.eax;
    // 0045fd27  e99dfdffff             -jmp 0x45fac9
    goto L_0x0045fac9;
L_0x0045fd2c:
    // 0045fd2c  8b9528020000           -mov edx, dword ptr [ebp + 0x228]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */);
    // 0045fd32  e976feffff             -jmp 0x45fbad
    goto L_0x0045fbad;
L_0x0045fd37:
    // 0045fd37  0f8560ffffff           -jne 0x45fc9d
    if (!cpu.flags.zf)
    {
        goto L_0x0045fc9d;
    }
    // 0045fd3d  8b88f4fd4f00           -mov ecx, dword ptr [eax + 0x4ffdf4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242356) /* 0x4ffdf4 */);
    // 0045fd43  3b8d24020000           +cmp ecx, dword ptr [ebp + 0x224]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fd49  0f8fc1feffff           -jg 0x45fc10
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045fc10;
    }
    // 0045fd4f  e949ffffff             -jmp 0x45fc9d
    goto L_0x0045fc9d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fd60  83f801                 +cmp eax, 1
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
    // 0045fd63  7e11                   -jle 0x45fd76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fd76;
    }
    // 0045fd65  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045fd68  8b80ccfd4f00           -mov eax, dword ptr [eax + 0x4ffdcc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242316) /* 0x4ffdcc */);
    // 0045fd6e  8b0485e8cb4d00         -mov eax, dword ptr [eax*4 + 0x4dcbe8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5098472) /* 0x4dcbe8 */ + cpu.eax * 4);
    // 0045fd75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045fd76:
    // 0045fd76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fd78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fd80  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fd81  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fd82  8b0d64cf4d00           -mov ecx, dword ptr [0x4dcf64]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fd88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fd8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045fd8c  7e16                   -jle 0x45fda4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fda4;
    }
    // 0045fd8e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0045fd91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045fd93:
    // 0045fd93  83b8ecfd4f00ff         +cmp dword ptr [eax + 0x4ffdec], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242348) /* 0x4ffdec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fd9a  7401                   -je 0x45fd9d
    if (cpu.flags.zf)
    {
        goto L_0x0045fd9d;
    }
    // 0045fd9c  42                     -inc edx
    (cpu.edx)++;
L_0x0045fd9d:
    // 0045fd9d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fda0  39c8                   +cmp eax, ecx
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
    // 0045fda2  7cef                   -jl 0x45fd93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fd93;
    }
L_0x0045fda4:
    // 0045fda4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045fda6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fda7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fda8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fdb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fdb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fdb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fdb2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fdb3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045fdb4  8b3564cf4d00           -mov esi, dword ptr [0x4dcf64]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fdba  8b98e8010000           -mov ebx, dword ptr [eax + 0x1e8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0045fdc0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045fdc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045fdc4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045fdc6  7e15                   -jle 0x45fddd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fddd;
    }
    // 0045fdc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0045fdca:
    // 0045fdca  3b9aecfd4f00           +cmp ebx, dword ptr [edx + 0x4ffdec]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5242348) /* 0x4ffdec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fdd0  7503                   -jne 0x45fdd5
    if (!cpu.flags.zf)
    {
        goto L_0x0045fdd5;
    }
    // 0045fdd2  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x0045fdd5:
    // 0045fdd5  40                     -inc eax
    (cpu.eax)++;
    // 0045fdd6  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fdd9  39f0                   +cmp eax, esi
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
    // 0045fddb  7ced                   -jl 0x45fdca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fdca;
    }
L_0x0045fddd:
    // 0045fddd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045fddf  893564cf4d00           -mov dword ptr [0x4dcf64], esi
    *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */) = cpu.esi;
    // 0045fde5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fde9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fdf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fdf0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fdf1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fdf2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fdf3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0045fdf8  b96179feff             -mov ecx, 0xfffe7961
    cpu.ecx = 4294867297 /*0xfffe7961*/;
    // 0045fdfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045fdff:
    // 0045fdff  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fe02  8988e0fd4f00           -mov dword ptr [eax + 0x4ffde0], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242336) /* 0x4ffde0 */) = cpu.ecx;
    // 0045fe08  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045fe0a  8990dcfd4f00           -mov dword ptr [eax + 0x4ffddc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242332) /* 0x4ffddc */) = cpu.edx;
    // 0045fe10  8998e4fd4f00           -mov dword ptr [eax + 0x4ffde4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242340) /* 0x4ffde4 */) = cpu.ebx;
    // 0045fe16  8998e8fd4f00           -mov dword ptr [eax + 0x4ffde8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5242344) /* 0x4ffde8 */) = cpu.ebx;
    // 0045fe1c  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fe21  75dc                   -jne 0x45fdff
    if (!cpu.flags.zf)
    {
        goto L_0x0045fdff;
    }
    // 0045fe23  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe24  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe25  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045fe26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45fe30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045fe30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045fe31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045fe32  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045fe33  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045fe34  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045fe35  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045fe36  8b2d60cf4d00           -mov ebp, dword ptr [0x4dcf60]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045fe3c  bf63000000             -mov edi, 0x63
    cpu.edi = 99 /*0x63*/;
    // 0045fe41  8b0d64cf4d00           -mov ecx, dword ptr [0x4dcf64]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fe47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045fe49  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0045fe4b  7e54                   -jle 0x45fea1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fea1;
    }
    // 0045fe4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045fe4f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0045fe51:
    // 0045fe51  8b8328cd4d00           -mov eax, dword ptr [ebx + 0x4dcd28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5098792) /* 0x4dcd28 */);
    // 0045fe57  e854ffffff             -call 0x45fdb0
    cpu.esp -= 4;
    sub_45fdb0(app, cpu);
    if (cpu.terminate) return;
    // 0045fe5c  8bb328cd4d00           -mov esi, dword ptr [ebx + 0x4dcd28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5098792) /* 0x4dcd28 */);
    // 0045fe62  898678020000           -mov dword ptr [esi + 0x278], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(632) /* 0x278 */) = cpu.eax;
    // 0045fe68  83b9f8fd4f0000         +cmp dword ptr [ecx + 0x4ffdf8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5242360) /* 0x4ffdf8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fe6f  741f                   -je 0x45fe90
    if (cpu.flags.zf)
    {
        goto L_0x0045fe90;
    }
    // 0045fe71  83ff63                 +cmp edi, 0x63
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fe74  751a                   -jne 0x45fe90
    if (!cpu.flags.zf)
    {
        goto L_0x0045fe90;
    }
    // 0045fe76  8b81ecfd4f00           -mov eax, dword ptr [ecx + 0x4ffdec]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5242348) /* 0x4ffdec */);
    // 0045fe7c  8b048528cd4d00         -mov eax, dword ptr [eax*4 + 0x4dcd28]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5098792) /* 0x4dcd28 */ + cpu.eax * 4);
    // 0045fe83  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0045fe89  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fe8c  7402                   -je 0x45fe90
    if (cpu.flags.zf)
    {
        goto L_0x0045fe90;
    }
    // 0045fe8e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x0045fe90:
    // 0045fe90  8b3564cf4d00           -mov esi, dword ptr [0x4dcf64]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5099364) /* 0x4dcf64 */);
    // 0045fe96  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045fe99  42                     -inc edx
    (cpu.edx)++;
    // 0045fe9a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045fe9d  39f2                   +cmp edx, esi
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
    // 0045fe9f  7cb0                   -jl 0x45fe51
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045fe51;
    }
L_0x0045fea1:
    // 0045fea1  a1f0d24d00             -mov eax, dword ptr [0x4dd2f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100272) /* 0x4dd2f0 */);
    // 0045fea6  8b2d60cf4d00           -mov ebp, dword ptr [0x4dcf60]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */);
    // 0045feac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045feae  744b                   -je 0x45fefb
    if (cpu.flags.zf)
    {
        goto L_0x0045fefb;
    }
    // 0045feb0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045feb2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0045feb4  7e45                   -jle 0x45fefb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045fefb;
    }
    // 0045feb6  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0045feb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0045febb:
    // 0045febb  8b83e8cd4d00           -mov eax, dword ptr [ebx + 0x4dcde8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5098984) /* 0x4dcde8 */);
    // 0045fec1  8b901c020000           -mov edx, dword ptr [eax + 0x21c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0045fec7  833a24                 +cmp dword ptr [edx], 0x24
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045feca  741d                   -je 0x45fee9
    if (cpu.flags.zf)
    {
        goto L_0x0045fee9;
    }
    // 0045fecc  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045fed2  8b8ff0fd4f00           -mov ecx, dword ptr [edi + 0x4ffdf0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5242352) /* 0x4ffdf0 */);
    // 0045fed8  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045feda  6b15e4d24d0074         -imul edx, dword ptr [0x4dd2e4], 0x74
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5100260) /* 0x4dd2e4 */))) * x86::sreg64(x86::sreg32(116 /*0x74*/)));
    // 0045fee1  3b8abcce4d00           +cmp ecx, dword ptr [edx + 0x4dcebc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099196) /* 0x4dcebc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045fee7  7d1f                   -jge 0x45ff08
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ff08;
    }
L_0x0045fee9:
    // 0045fee9  c7801802000000000100   -mov dword ptr [eax + 0x218], 0x10000
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = 65536 /*0x10000*/;
L_0x0045fef3:
    // 0045fef3  46                     -inc esi
    (cpu.esi)++;
    // 0045fef4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045fef7  39ee                   +cmp esi, ebp
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
    // 0045fef9  7cc0                   -jl 0x45febb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0045febb;
    }
L_0x0045fefb:
    // 0045fefb  892d60cf4d00           -mov dword ptr [0x4dcf60], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5099360) /* 0x4dcf60 */) = cpu.ebp;
    // 0045ff01  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff02  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff03  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff04  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff05  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff06  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ff07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045ff08:
    // 0045ff08  3b8ac0ce4d00           +cmp ecx, dword ptr [edx + 0x4dcec0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099200) /* 0x4dcec0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ff0e  7d0e                   -jge 0x45ff1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ff1e;
    }
    // 0045ff10  8b92ccce4d00           -mov edx, dword ptr [edx + 0x4dcecc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099212) /* 0x4dcecc */);
    // 0045ff16  899018020000           -mov dword ptr [eax + 0x218], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 0045ff1c  ebd5                   -jmp 0x45fef3
    goto L_0x0045fef3;
L_0x0045ff1e:
    // 0045ff1e  3b8ac4ce4d00           +cmp ecx, dword ptr [edx + 0x4dcec4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099204) /* 0x4dcec4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ff24  7d0e                   -jge 0x45ff34
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ff34;
    }
    // 0045ff26  8b92d0ce4d00           -mov edx, dword ptr [edx + 0x4dced0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099216) /* 0x4dced0 */);
    // 0045ff2c  899018020000           -mov dword ptr [eax + 0x218], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 0045ff32  ebbf                   -jmp 0x45fef3
    goto L_0x0045fef3;
L_0x0045ff34:
    // 0045ff34  3b8ac8ce4d00           +cmp ecx, dword ptr [edx + 0x4dcec8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099208) /* 0x4dcec8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045ff3a  7d0e                   -jge 0x45ff4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045ff4a;
    }
    // 0045ff3c  8b92d4ce4d00           -mov edx, dword ptr [edx + 0x4dced4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099220) /* 0x4dced4 */);
    // 0045ff42  899018020000           -mov dword ptr [eax + 0x218], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 0045ff48  eba9                   -jmp 0x45fef3
    goto L_0x0045fef3;
L_0x0045ff4a:
    // 0045ff4a  8b92d8ce4d00           -mov edx, dword ptr [edx + 0x4dced8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5099224) /* 0x4dced8 */);
    // 0045ff50  899018020000           -mov dword ptr [eax + 0x218], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 0045ff56  eb9b                   -jmp 0x45fef3
    goto L_0x0045fef3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 04000000080000000a0000000c00000010000000400000001800000000000000 */
void Application::sub_45ff80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ff80  030570ff4500           -add eax, dword ptr [0x45ff70]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(4587376) /* 0x45ff70 */)));
    // 0045ff86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_45ff90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ff90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ff91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ff92  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ff93  8b0d6cff4500           -mov ecx, dword ptr [0x45ff6c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(4587372) /* 0x45ff6c */);
    // 0045ff99  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045ff9b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045ff9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ff9f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ffa2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ffa4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045ffa6  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0045ffaa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45ffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ffb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ffb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ffb2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045ffb3  8b0d68ff4500           -mov ecx, dword ptr [0x45ff68]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(4587368) /* 0x45ff68 */);
    // 0045ffb9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045ffbb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045ffbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045ffbf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ffc2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ffc4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045ffc6  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0045ffca  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffcb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffcc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045ffcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_45ffd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045ffd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045ffd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045ffd2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045ffd3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045ffd4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0045ffd5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045ffd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045ffda  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0045ffdc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ffde  a164ff4500             -mov eax, dword ptr [0x45ff64]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4587364) /* 0x45ff64 */);
    // 0045ffe3  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0045ffe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045ffe8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045ffeb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045ffed  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045ffef  0fbf3c46               -movsx edi, word ptr [esi + eax*2]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 0045fff3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045fff5  7427                   -je 0x46001e
    if (cpu.flags.zf)
    {
        goto L_0x0046001e;
    }
    // 0045fff7  a174ff4500             -mov eax, dword ptr [0x45ff74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4587380) /* 0x45ff74 */);
    // 0045fffc  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045fffe  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00460000  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460004  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00460006  7e16                   -jle 0x46001e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046001e;
    }
L_0x00460008:
    // 00460008  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046000a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046000c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046000e  668b5904               -mov bx, word ptr [ecx + 4]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00460012  39eb                   +cmp ebx, ebp
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
    // 00460014  7414                   -je 0x46002a
    if (cpu.flags.zf)
    {
        goto L_0x0046002a;
    }
    // 00460016  40                     -inc eax
    (cpu.eax)++;
    // 00460017  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046001a  39f8                   +cmp eax, edi
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
    // 0046001c  7cea                   -jl 0x460008
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460008;
    }
L_0x0046001e:
    // 0046001e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00460021  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460024  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460025  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460026  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460027  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460028  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460029  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046002a:
    // 0046002a  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046002d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00460030  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460033  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460034  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460035  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460036  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460037  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460038  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460040  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460041  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460042  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460044  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00460046  668b480a               -mov cx, word ptr [eax + 0xa]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0046004a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00460051  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00460053  8b0d78ff4500           -mov ecx, dword ptr [0x45ff78]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(4587384) /* 0x45ff78 */);
    // 00460059  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046005b  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046005d  668b5204               -mov dx, word ptr [edx + 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00460061  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460063  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00460069  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00460070  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460072  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460074  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00460076  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460077  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460080  030578ff4500           -add eax, dword ptr [0x45ff78]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(4587384) /* 0x45ff78 */)));
    // 00460086  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460090  030574ff4500           -add eax, dword ptr [0x45ff74]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(4587380) /* 0x45ff74 */)));
    // 00460096  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4600a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004600a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004600a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004600a3  3b05c8fe4f00           +cmp eax, dword ptr [0x4ffec8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004600a9  730b                   -jae 0x4600b6
    if (!cpu.flags.cf)
    {
        goto L_0x004600b6;
    }
    // 004600ab  a11c6b4c00             -mov eax, dword ptr [0x4c6b1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5008156) /* 0x4c6b1c */);
    // 004600b0  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 004600b4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004600b6:
    // 004600b6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004600b7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004600b8  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 004600bd  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 004600c2  b810b54b00             -mov eax, 0x4bb510
    cpu.eax = 4961552 /*0x4bb510*/;
    // 004600c7  e800a60200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 004600cc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600cd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600ce  a11c6b4c00             -mov eax, dword ptr [0x4c6b1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5008156) /* 0x4c6b1c */);
    // 004600d3  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 004600d7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4600e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004600e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004600e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004600e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004600e4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004600e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004600e8  668b4104               -mov ax, word ptr [ecx + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004600ec  39c2                   +cmp edx, eax
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
    // 004600ee  7d0b                   -jge 0x4600fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004600fb;
    }
    // 004600f0  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004600f3  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004600f6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004600f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600f9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004600fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004600fb:
    // 004600fb  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004600fc  bbf7000000             -mov ebx, 0xf7
    cpu.ebx = 247 /*0xf7*/;
    // 00460101  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 00460106  b8ecb44b00             -mov eax, 0x4bb4ec
    cpu.eax = 4961516 /*0x4bb4ec*/;
    // 0046010b  e8bca50200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 00460110  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460111  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00460114  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00460117  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00460119  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046011a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046011b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_460120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460120  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460121  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460123  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460126  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460128  8b15186b4c00           -mov edx, dword ptr [0x4c6b18]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5008152) /* 0x4c6b18 */);
    // 0046012e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460131  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00460133  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460134  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460140  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460141  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460142  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00460149  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046014b  8b35186b4c00           -mov esi, dword ptr [0x4c6b18]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5008152) /* 0x4c6b18 */);
    // 00460151  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460154  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00460156  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460158  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460159  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046015a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046015b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046015d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_460160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460160  3b05ccfe4f00           +cmp eax, dword ptr [0x4ffecc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460166  7506                   -jne 0x46016e
    if (!cpu.flags.zf)
    {
        goto L_0x0046016e;
    }
    // 00460168  a1b8fe4f00             -mov eax, dword ptr [0x4ffeb8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242552) /* 0x4ffeb8 */);
    // 0046016d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046016e:
    // 0046016e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046016f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460170  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 00460175  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 0046017a  b8d0b44b00             -mov eax, 0x4bb4d0
    cpu.eax = 4961488 /*0x4bb4d0*/;
    // 0046017f  e848a50200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 00460184  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460185  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460186  a1b8fe4f00             -mov eax, dword ptr [0x4ffeb8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242552) /* 0x4ffeb8 */);
    // 0046018b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_460190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460190  3b05ccfe4f00           +cmp eax, dword ptr [0x4ffecc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460196  7506                   -jne 0x46019e
    if (!cpu.flags.zf)
    {
        goto L_0x0046019e;
    }
    // 00460198  a1b4fe4f00             -mov eax, dword ptr [0x4ffeb4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242548) /* 0x4ffeb4 */);
    // 0046019d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046019e:
    // 0046019e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046019f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004601a0  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 004601a5  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 004601aa  b8d0b44b00             -mov eax, 0x4bb4d0
    cpu.eax = 4961488 /*0x4bb4d0*/;
    // 004601af  e818a50200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 004601b4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601b5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601b6  a1b4fe4f00             -mov eax, dword ptr [0x4ffeb4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242548) /* 0x4ffeb4 */);
    // 004601bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4601c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004601c0  3b05ccfe4f00           +cmp eax, dword ptr [0x4ffecc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004601c6  7506                   -jne 0x4601ce
    if (!cpu.flags.zf)
    {
        goto L_0x004601ce;
    }
    // 004601c8  a1c4fe4f00             -mov eax, dword ptr [0x4ffec4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242564) /* 0x4ffec4 */);
    // 004601cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004601ce:
    // 004601ce  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004601cf  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004601d0  bb76000000             -mov ebx, 0x76
    cpu.ebx = 118 /*0x76*/;
    // 004601d5  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 004601da  b8d0b44b00             -mov eax, 0x4bb4d0
    cpu.eax = 4961488 /*0x4bb4d0*/;
    // 004601df  e8e8a40200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 004601e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601e5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004601e6  a1c4fe4f00             -mov eax, dword ptr [0x4ffec4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5242564) /* 0x4ffec4 */);
    // 004601eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
