#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_49a823(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a823  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a824  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a825  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a826  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a827  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a828  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 0049a82e  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a834  bdf9f24b00             -mov ebp, 0x4bf2f9
    cpu.ebp = 4977401 /*0x4bf2f9*/;
    // 0049a839  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a83c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049a83e:
    // 0049a83e  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049a845  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a847  e88b50feff             -call 0x47f8d7
    cpu.esp -= 4;
    sub_47f8d7(app, cpu);
    if (cpu.terminate) return;
    // 0049a84c  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049a851  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049a858  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a859  e83af40000             -call 0x4a9c98
    cpu.esp -= 4;
    sub_4a9c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a85e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a860  74dc                   -je 0x49a83e
    if (cpu.flags.zf)
    {
        goto L_0x0049a83e;
    }
    // 0049a862  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049a869  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049a86b  e8ee4dfeff             -call 0x47f65e
    cpu.esp -= 4;
    sub_47f65e(app, cpu);
    if (cpu.terminate) return;
    // 0049a870  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a872  751b                   -jne 0x49a88f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a88f;
    }
    // 0049a874  e853f40000             -call 0x4a9ccc
    cpu.esp -= 4;
    sub_4a9ccc(app, cpu);
    if (cpu.terminate) return;
    // 0049a879  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a87c  740a                   -je 0x49a888
    if (cpu.flags.zf)
    {
        goto L_0x0049a888;
    }
    // 0049a87e  e849f40000             -call 0x4a9ccc
    cpu.esp -= 4;
    sub_4a9ccc(app, cpu);
    if (cpu.terminate) return;
    // 0049a883  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a886  75b6                   -jne 0x49a83e
    if (!cpu.flags.zf)
    {
        goto L_0x0049a83e;
    }
L_0x0049a888:
    // 0049a888  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049a88a  e97d000000             -jmp 0x49a90c
    goto L_0x0049a90c;
L_0x0049a88f:
    // 0049a88f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a891  e8e14ffeff             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 0049a896  8a1d38c14c00           -mov bl, byte ptr [0x4cc138]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5030200) /* 0x4cc138 */);
L_0x0049a89c:
    // 0049a89c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a89e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049a8a0  e83250feff             -call 0x47f8d7
    cpu.esp -= 4;
    sub_47f8d7(app, cpu);
    if (cpu.terminate) return;
    // 0049a8a5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049a8a7  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049a8ae  e82df40000             -call 0x4a9ce0
    cpu.esp -= 4;
    sub_4a9ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049a8b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a8b5  7539                   -jne 0x49a8f0
    if (!cpu.flags.zf)
    {
        goto L_0x0049a8f0;
    }
    // 0049a8b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a8b9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049a8bb  e89e4dfeff             -call 0x47f65e
    cpu.esp -= 4;
    sub_47f65e(app, cpu);
    if (cpu.terminate) return;
    // 0049a8c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a8c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a8c4  7420                   -je 0x49a8e6
    if (cpu.flags.zf)
    {
        goto L_0x0049a8e6;
    }
    // 0049a8c6  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0049a8c9  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0049a8cc  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 0049a8cf  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049a8d2  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 0049a8d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a8d7  881d38c14c00           -mov byte ptr [0x4cc138], bl
    app->getMemory<x86::reg8>(x86::reg32(5030200) /* 0x4cc138 */) = cpu.bl;
    // 0049a8dd  e85eb3ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049a8e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a8e4  eb26                   -jmp 0x49a90c
    goto L_0x0049a90c;
L_0x0049a8e6:
    // 0049a8e6  e8e1f30000             -call 0x4a9ccc
    cpu.esp -= 4;
    sub_4a9ccc(app, cpu);
    if (cpu.terminate) return;
    // 0049a8eb  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a8ee  7498                   -je 0x49a888
    if (cpu.flags.zf)
    {
        goto L_0x0049a888;
    }
L_0x0049a8f0:
    // 0049a8f0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049a8f5  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049a8fc  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a8fd  e896f30000             -call 0x4a9c98
    cpu.esp -= 4;
    sub_4a9c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a902  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a904  0f8534ffffff           -jne 0x49a83e
    if (!cpu.flags.zf)
    {
        goto L_0x0049a83e;
    }
    // 0049a90a  eb90                   -jmp 0x49a89c
    goto L_0x0049a89c;
L_0x0049a90c:
    // 0049a90c  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 0049a912  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a913  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a914  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a915  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a916  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a917  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a918(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a918  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a919  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a91a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a91b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a91c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a91d  803df0c14c0000         +cmp byte ptr [0x4cc1f0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030384) /* 0x4cc1f0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a924  0f85ab000000           -jne 0x49a9d5
    if (!cpu.flags.zf)
    {
        goto L_0x0049a9d5;
    }
    // 0049a92a  bbdcc14c00             -mov ebx, 0x4cc1dc
    cpu.ebx = 5030364 /*0x4cc1dc*/;
    // 0049a92f  eb39                   -jmp 0x49a96a
    goto L_0x0049a96a;
L_0x0049a931:
    // 0049a931  e8c3f30000             -call 0x4a9cf9
    cpu.esp -= 4;
    sub_4a9cf9(app, cpu);
    if (cpu.terminate) return;
    // 0049a936  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a938  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a93a  742b                   -je 0x49a967
    if (cpu.flags.zf)
    {
        goto L_0x0049a967;
    }
    // 0049a93c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a93e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a93f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a941  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a943  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a945  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a946  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049a948  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049a94a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049a94c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a94d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a94e  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a954  7711                   -ja 0x49a967
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049a967;
    }
    // 0049a956  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 0049a95b  b8f0c14c00             -mov eax, 0x4cc1f0
    cpu.eax = 5030384 /*0x4cc1f0*/;
    // 0049a960  e8eef30000             -call 0x4a9d53
    cpu.esp -= 4;
    sub_4a9d53(app, cpu);
    if (cpu.terminate) return;
    // 0049a965  eb0a                   -jmp 0x49a971
    goto L_0x0049a971;
L_0x0049a967:
    // 0049a967  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049a96a:
    // 0049a96a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a96c  803800                 +cmp byte ptr [eax], 0
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
    // 0049a96f  75c0                   -jne 0x49a931
    if (!cpu.flags.zf)
    {
        goto L_0x0049a931;
    }
L_0x0049a971:
    // 0049a971  803df0c14c0000         +cmp byte ptr [0x4cc1f0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030384) /* 0x4cc1f0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a978  752a                   -jne 0x49a9a4
    if (!cpu.flags.zf)
    {
        goto L_0x0049a9a4;
    }
    // 0049a97a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a97c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a97e  bff0c14c00             -mov edi, 0x4cc1f0
    cpu.edi = 5030384 /*0x4cc1f0*/;
    // 0049a983  e8ddfffdff             -call 0x47a965
    cpu.esp -= 4;
    sub_47a965(app, cpu);
    if (cpu.terminate) return;
    // 0049a988  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a98a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049a98b:
    // 0049a98b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a98d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049a98f  3c00                   +cmp al, 0
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
    // 0049a991  7410                   -je 0x49a9a3
    if (cpu.flags.zf)
    {
        goto L_0x0049a9a3;
    }
    // 0049a993  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a996  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049a999  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049a99c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049a99f  3c00                   +cmp al, 0
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
    // 0049a9a1  75e8                   -jne 0x49a98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049a98b;
    }
L_0x0049a9a3:
    // 0049a9a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049a9a4:
    // 0049a9a4  bff0c14c00             -mov edi, 0x4cc1f0
    cpu.edi = 5030384 /*0x4cc1f0*/;
    // 0049a9a9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a9aa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a9ac  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a9ae  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a9b0  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a9b1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049a9b3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049a9b5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049a9b7  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a9b8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a9b9  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049a9bc  05f0c14c00             -add eax, 0x4cc1f0
    (cpu.eax) += x86::reg32(x86::sreg32(5030384 /*0x4cc1f0*/));
    // 0049a9c1  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049a9c3  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a9c6  740d                   -je 0x49a9d5
    if (cpu.flags.zf)
    {
        goto L_0x0049a9d5;
    }
    // 0049a9c8  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a9cb  7408                   -je 0x49a9d5
    if (cpu.flags.zf)
    {
        goto L_0x0049a9d5;
    }
    // 0049a9cd  40                     -inc eax
    (cpu.eax)++;
    // 0049a9ce  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 0049a9d1  40                     -inc eax
    (cpu.eax)++;
    // 0049a9d2  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0049a9d5:
    // 0049a9d5  b8f0c14c00             -mov eax, 0x4cc1f0
    cpu.eax = 5030384 /*0x4cc1f0*/;
    // 0049a9da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a9e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a9e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a9e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a9e8  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049a9eb  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a9f1  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0049a9f4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a9f6  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0049a9f9  0f8478000000           -je 0x49aa77
    if (cpu.flags.zf)
    {
        goto L_0x0049aa77;
    }
    // 0049a9ff  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 0049aa01  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049aa04  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049aa07  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0049aa0a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0049aa0c  0f84a0000000           -je 0x49aab2
    if (cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa12  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049aa15  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049aa18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049aa1a  0f8492000000           -je 0x49aab2
    if (cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa20  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049aa22  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x0049aa25:
    // 0049aa25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049aa27  0f8485000000           -je 0x49aab2
    if (cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa2d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049aa2f  0f857d000000           -jne 0x49aab2
    if (!cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa35  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049aa37  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049aa39  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aa3c  e861420000             -call 0x49eca2
    cpu.esp -= 4;
    sub_49eca2(app, cpu);
    if (cpu.terminate) return;
    // 0049aa41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049aa43  83f8ff                 +cmp eax, -1
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
    // 0049aa46  750d                   -jne 0x49aa55
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa55;
    }
    // 0049aa48  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049aa4b  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049aa4e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049aa50  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0049aa53  eb1c                   -jmp 0x49aa71
    goto L_0x0049aa71;
L_0x0049aa55:
    // 0049aa55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049aa57  7518                   -jne 0x49aa71
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa71;
    }
    // 0049aa59  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0049aa5e  e8ddb1ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049aa63  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049aa66  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049aa69  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0049aa6e  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x0049aa71:
    // 0049aa71  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049aa73  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049aa75  ebae                   -jmp 0x49aa25
    goto L_0x0049aa25;
L_0x0049aa77:
    // 0049aa77  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049aa7a  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049aa7e  7432                   -je 0x49aab2
    if (cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa80  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049aa84  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 0049aa88  7528                   -jne 0x49aab2
    if (!cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aa8a  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049aa8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049aa8f  7411                   -je 0x49aaa2
    if (cpu.flags.zf)
    {
        goto L_0x0049aaa2;
    }
    // 0049aa91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049aa93  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049aa98  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049aa9a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aa9d  e8a6000000             -call 0x49ab48
    cpu.esp -= 4;
    sub_49ab48(app, cpu);
    if (cpu.terminate) return;
L_0x0049aaa2:
    // 0049aaa2  83f8ff                 +cmp eax, -1
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
    // 0049aaa5  750b                   -jne 0x49aab2
    if (!cpu.flags.zf)
    {
        goto L_0x0049aab2;
    }
    // 0049aaa7  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049aaaa  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049aaad  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049aaaf  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x0049aab2:
    // 0049aab2  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049aab5  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049aab8  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049aabf  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049aac1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049aac3  7518                   -jne 0x49aadd
    if (!cpu.flags.zf)
    {
        goto L_0x0049aadd;
    }
    // 0049aac5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049aac8  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049aacc  740f                   -je 0x49aadd
    if (cpu.flags.zf)
    {
        goto L_0x0049aadd;
    }
    // 0049aace  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aad1  e80ef30000             -call 0x4a9de4
    cpu.esp -= 4;
    sub_4a9de4(app, cpu);
    if (cpu.terminate) return;
    // 0049aad6  83f8ff                 +cmp eax, -1
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
    // 0049aad9  7502                   -jne 0x49aadd
    if (!cpu.flags.zf)
    {
        goto L_0x0049aadd;
    }
    // 0049aadb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0049aadd:
    // 0049aadd  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aae0  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aae6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049aae8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aae9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aaea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aaeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aaec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aaed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aaee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49aaef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aaef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aaf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aaf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049aaf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049aaf3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049aaf5  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 0049aaf9  740d                   -je 0x49ab08
    if (cpu.flags.zf)
    {
        goto L_0x0049ab08;
    }
    // 0049aafb  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049aaff  7407                   -je 0x49ab08
    if (cpu.flags.zf)
    {
        goto L_0x0049ab08;
    }
    // 0049ab01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ab03  e8103b0000             -call 0x49e618
    cpu.esp -= 4;
    sub_49e618(app, cpu);
    if (cpu.terminate) return;
L_0x0049ab08:
    // 0049ab08  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ab0b  e8f4e40000             -call 0x4a9004
    cpu.esp -= 4;
    sub_4a9004(app, cpu);
    if (cpu.terminate) return;
    // 0049ab10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ab12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ab14  83f8ff                 +cmp eax, -1
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
    // 0049ab17  742a                   -je 0x49ab43
    if (cpu.flags.zf)
    {
        goto L_0x0049ab43;
    }
    // 0049ab19  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ab1c  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ab22  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ab25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ab27  740f                   -je 0x49ab38
    if (cpu.flags.zf)
    {
        goto L_0x0049ab38;
    }
    // 0049ab29  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049ab2d  7405                   -je 0x49ab34
    if (cpu.flags.zf)
    {
        goto L_0x0049ab34;
    }
    // 0049ab2f  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 0049ab32  eb04                   -jmp 0x49ab38
    goto L_0x0049ab38;
L_0x0049ab34:
    // 0049ab34  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049ab36  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049ab38:
    // 0049ab38  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ab3b  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ab41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049ab43:
    // 0049ab43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ab48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ab48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ab49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ab4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ab4c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049ab4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ab50  7c08                   -jl 0x49ab5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ab5a;
    }
    // 0049ab52  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ab58  7612                   -jbe 0x49ab6c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049ab6c;
    }
L_0x0049ab5a:
    // 0049ab5a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049ab5f  e8dcb0ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049ab64  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049ab69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ab6c:
    // 0049ab6c  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ab72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ab74  e8bfe30000             -call 0x4a8f38
    cpu.esp -= 4;
    sub_4a8f38(app, cpu);
    if (cpu.terminate) return;
    // 0049ab79  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ab7b  7e10                   -jle 0x49ab8d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ab8d;
    }
    // 0049ab7d  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0049ab7f  750c                   -jne 0x49ab8d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab8d;
    }
    // 0049ab81  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0049ab84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ab86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ab88  e800e40000             -call 0x4a8f8d
    cpu.esp -= 4;
    sub_4a8f8d(app, cpu);
    if (cpu.terminate) return;
L_0x0049ab8d:
    // 0049ab8d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ab8e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049ab90  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 0049ab95  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ab97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ab98  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0049ab9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ab9c  2eff1560554b00         -call dword ptr cs:[0x4b5560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937056) /* 0x4b5560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aba3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aba5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049aba7  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049abad  83f9ff                 +cmp ecx, -1
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
    // 0049abb0  7505                   -jne 0x49abb7
    if (!cpu.flags.zf)
    {
        goto L_0x0049abb7;
    }
    // 0049abb2  e88bafffff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
L_0x0049abb7:
    // 0049abb7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049abb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49abbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049abbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049abbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049abbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049abbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049abc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049abc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049abc2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049abc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049abc6  7c08                   -jl 0x49abd0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049abd0;
    }
    // 0049abc8  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049abce  7611                   -jbe 0x49abe1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049abe1;
    }
L_0x0049abd0:
    // 0049abd0  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049abd5  e866b0ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049abda  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049abdf  eb61                   -jmp 0x49ac42
    goto L_0x0049ac42;
L_0x0049abe1:
    // 0049abe1  8b15f8d54c00           -mov edx, dword ptr [0x4cd5f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 0049abe7  8b2d9cc14c00           -mov ebp, dword ptr [0x4cc19c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5030300) /* 0x4cc19c */);
    // 0049abed  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049abef  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049abf1  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0049abf4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049abf6  741e                   -je 0x49ac16
    if (cpu.flags.zf)
    {
        goto L_0x0049ac16;
    }
    // 0049abf8  ff1590c14c00           -call dword ptr [0x4cc190]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030288) /* 0x4cc190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049abfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ac00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ac02  7412                   -je 0x49ac16
    if (cpu.flags.zf)
    {
        goto L_0x0049ac16;
    }
    // 0049ac04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ac06  ff1594c14c00           -call dword ptr [0x4cc194]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030292) /* 0x4cc194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ac0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ac0e  ff159cc14c00           -call dword ptr [0x4cc19c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030300) /* 0x4cc19c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ac14  eb21                   -jmp 0x49ac37
    goto L_0x0049ac37;
L_0x0049ac16:
    // 0049ac16  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ac18  751d                   -jne 0x49ac37
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac37;
    }
    // 0049ac1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ac1b  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ac22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ac24  7511                   -jne 0x49ac37
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac37;
    }
    // 0049ac26  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049ac2b  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0049ac30  e80bb0ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049ac35  eb09                   -jmp 0x49ac40
    goto L_0x0049ac40;
L_0x0049ac37:
    // 0049ac37  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ac39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ac3b  e84de30000             -call 0x4a8f8d
    cpu.esp -= 4;
    sub_4a8f8d(app, cpu);
    if (cpu.terminate) return;
L_0x0049ac40:
    // 0049ac40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049ac42:
    // 0049ac42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ac49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ac49  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ac4a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ac4b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ac4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ac4d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ac4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ac51  0f84f1000000           -je 0x49ad48
    if (cpu.flags.zf)
    {
        goto L_0x0049ad48;
    }
    // 0049ac57  ff1560c14c00           -call dword ptr [0x4cc160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030240) /* 0x4cc160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ac5d  8b0d042c5400           -mov ecx, dword ptr [0x542c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5516292) /* 0x542c04 */);
    // 0049ac63  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ac65  7440                   -je 0x49aca7
    if (cpu.flags.zf)
    {
        goto L_0x0049aca7;
    }
    // 0049ac67  39f1                   +cmp ecx, esi
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
    // 0049ac69  770c                   -ja 0x49ac77
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ac77;
    }
    // 0049ac6b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ac6d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ac6f  39f0                   +cmp eax, esi
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
    // 0049ac71  0f878b000000           -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049ac77:
    // 0049ac77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ac79  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049ac7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ac7e  7410                   -je 0x49ac90
    if (cpu.flags.zf)
    {
        goto L_0x0049ac90;
    }
    // 0049ac80  39f1                   +cmp ecx, esi
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
    // 0049ac82  770c                   -ja 0x49ac90
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ac90;
    }
    // 0049ac84  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ac86  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ac88  39f2                   +cmp edx, esi
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
    // 0049ac8a  0f8772000000           -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049ac90:
    // 0049ac90  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049ac93  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ac95  7410                   -je 0x49aca7
    if (cpu.flags.zf)
    {
        goto L_0x0049aca7;
    }
    // 0049ac97  39f1                   +cmp ecx, esi
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
    // 0049ac99  770c                   -ja 0x49aca7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049aca7;
    }
    // 0049ac9b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ac9d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ac9f  39f0                   +cmp eax, esi
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
    // 0049aca1  0f875b000000           -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049aca7:
    // 0049aca7  8b0d34ac4c00           -mov ecx, dword ptr [0x4cac34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */);
    // 0049acad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049acaf  7434                   -je 0x49ace5
    if (cpu.flags.zf)
    {
        goto L_0x0049ace5;
    }
    // 0049acb1  39f1                   +cmp ecx, esi
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
    // 0049acb3  7708                   -ja 0x49acbd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049acbd;
    }
    // 0049acb5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049acb7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049acb9  39f0                   +cmp eax, esi
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
    // 0049acbb  7745                   -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049acbd:
    // 0049acbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049acbf  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049acc2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049acc4  740c                   -je 0x49acd2
    if (cpu.flags.zf)
    {
        goto L_0x0049acd2;
    }
    // 0049acc6  39f1                   +cmp ecx, esi
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
    // 0049acc8  7708                   -ja 0x49acd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049acd2;
    }
    // 0049acca  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049accc  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049acce  39f2                   +cmp edx, esi
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
    // 0049acd0  7730                   -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049acd2:
    // 0049acd2  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049acd5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049acd7  740c                   -je 0x49ace5
    if (cpu.flags.zf)
    {
        goto L_0x0049ace5;
    }
    // 0049acd9  39f1                   +cmp ecx, esi
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
    // 0049acdb  7708                   -ja 0x49ace5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ace5;
    }
    // 0049acdd  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049acdf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ace1  39f0                   +cmp eax, esi
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
    // 0049ace3  771d                   -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049ace5:
    // 0049ace5  8b0d30ac4c00           -mov ecx, dword ptr [0x4cac30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 0049aceb  eb0f                   -jmp 0x49acfc
    goto L_0x0049acfc;
L_0x0049aced:
    // 0049aced  39f1                   +cmp ecx, esi
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
    // 0049acef  7708                   -ja 0x49acf9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049acf9;
    }
    // 0049acf1  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049acf3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049acf5  39f0                   +cmp eax, esi
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
    // 0049acf7  7709                   -ja 0x49ad02
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ad02;
    }
L_0x0049acf9:
    // 0049acf9  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x0049acfc:
    // 0049acfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049acfe  75ed                   -jne 0x49aced
    if (!cpu.flags.zf)
    {
        goto L_0x0049aced;
    }
    // 0049ad00  eb40                   -jmp 0x49ad42
    goto L_0x0049ad42;
L_0x0049ad02:
    // 0049ad02  b830ac4c00             -mov eax, 0x4cac30
    cpu.eax = 5024816 /*0x4cac30*/;
    // 0049ad07  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049ad09  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049ad0f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049ad11  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ad13  e878a30000             -call 0x4a5090
    cpu.esp -= 4;
    sub_4a5090(app, cpu);
    if (cpu.terminate) return;
    // 0049ad18  8b1534ac4c00           -mov edx, dword ptr [0x4cac34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */);
    // 0049ad1e  890d042c5400           -mov dword ptr [0x542c04], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516292) /* 0x542c04 */) = cpu.ecx;
    // 0049ad24  39d1                   +cmp ecx, edx
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
    // 0049ad26  7312                   -jae 0x49ad3a
    if (!cpu.flags.cf)
    {
        goto L_0x0049ad3a;
    }
    // 0049ad28  8b1d38ac4c00           -mov ebx, dword ptr [0x4cac38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */);
    // 0049ad2e  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049ad31  39d8                   +cmp eax, ebx
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
    // 0049ad33  7605                   -jbe 0x49ad3a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049ad3a;
    }
    // 0049ad35  a338ac4c00             -mov dword ptr [0x4cac38], eax
    app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */) = cpu.eax;
L_0x0049ad3a:
    // 0049ad3a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049ad3c  882510615400           -mov byte ptr [0x546110], ah
    app->getMemory<x86::reg8>(x86::reg32(5529872) /* 0x546110 */) = cpu.ah;
L_0x0049ad42:
    // 0049ad42  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ad48:
    // 0049ad48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ad4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ad4d  e9bc09feff             -jmp 0x47b70e
    return sub_47b70e(app, cpu);
}

/* align: skip  */
void Application::sub_49ad52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ad52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ad53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad54  ba419e4a00             -mov edx, 0x4a9e41
    cpu.edx = 4890177 /*0x4a9e41*/;
    // 0049ad59  bb559f4a00             -mov ebx, 0x4a9f55
    cpu.ebx = 4890453 /*0x4a9f55*/;
    // 0049ad5e  891588d64c00           -mov dword ptr [0x4cd688], edx
    app->getMemory<x86::reg32>(x86::reg32(5035656) /* 0x4cd688 */) = cpu.edx;
    // 0049ad64  891d8cd64c00           -mov dword ptr [0x4cd68c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035660) /* 0x4cd68c */) = cpu.ebx;
    // 0049ad6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ad70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ad71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ad72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ad74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ad75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ad76  ba00f34b00             -mov edx, 0x4bf300
    cpu.edx = 4977408 /*0x4bf300*/;
    // 0049ad7b  e8de48feff             -call 0x47f65e
    cpu.esp -= 4;
    sub_47f65e(app, cpu);
    if (cpu.terminate) return;
    // 0049ad80  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049ad82  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ad84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ad86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ad88  7509                   -jne 0x49ad93
    if (!cpu.flags.zf)
    {
        goto L_0x0049ad93;
    }
L_0x0049ad8a:
    // 0049ad8a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ad8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ad93:
    // 0049ad93  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049ad98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad9a  e855e5ffff             -call 0x4992f4
    cpu.esp -= 4;
    sub_4992f4(app, cpu);
    if (cpu.terminate) return;
    // 0049ad9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ada1  75e7                   -jne 0x49ad8a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ad8a;
    }
    // 0049ada3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ada5  e845fdffff             -call 0x49aaef
    cpu.esp -= 4;
    sub_49aaef(app, cpu);
    if (cpu.terminate) return;
    // 0049adaa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049adac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049adae  7eda                   -jle 0x49ad8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ad8a;
    }
    // 0049adb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049adb2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049adb4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049adb6  e839e5ffff             -call 0x4992f4
    cpu.esp -= 4;
    sub_4992f4(app, cpu);
    if (cpu.terminate) return;
    // 0049adbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049adbd  75cb                   -jne 0x49ad8a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ad8a;
    }
    // 0049adbf  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 0049adc4  e807eefeff             -call 0x489bd0
    cpu.esp -= 4;
    sub_489bd0(app, cpu);
    if (cpu.terminate) return;
    // 0049adc9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049adcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049adcd  74bb                   -je 0x49ad8a
    if (cpu.flags.zf)
    {
        goto L_0x0049ad8a;
    }
    // 0049adcf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049add1  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049add4  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049add7  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049adda  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 0049ade0  89b818100000           -mov dword ptr [eax + 0x1018], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = cpu.edi;
    // 0049ade6  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049ade9  898810100000           -mov dword ptr [eax + 0x1010], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ecx;
    // 0049adef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049adf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49adf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049adf8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049adf9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049adfa  ba04f34b00             -mov edx, 0x4bf304
    cpu.edx = 4977412 /*0x4bf304*/;
    // 0049adff  e85a48feff             -call 0x47f65e
    cpu.esp -= 4;
    sub_47f65e(app, cpu);
    if (cpu.terminate) return;
    // 0049ae04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ae06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ae08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ae0a  7505                   -jne 0x49ae11
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae11;
    }
L_0x0049ae0c:
    // 0049ae0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ae0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae11:
    // 0049ae11  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 0049ae16  e8b5edfeff             -call 0x489bd0
    cpu.esp -= 4;
    sub_489bd0(app, cpu);
    if (cpu.terminate) return;
    // 0049ae1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ae1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ae1f  74eb                   -je 0x49ae0c
    if (cpu.flags.zf)
    {
        goto L_0x0049ae0c;
    }
    // 0049ae21  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049ae28  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0049ae2f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049ae36  c7801410000000000000   -mov dword ptr [eax + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049ae40  c7801810000001000000   -mov dword ptr [eax + 0x1018], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = 1 /*0x1*/;
    // 0049ae4a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049ae4c  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049ae4f  899010100000           -mov dword ptr [eax + 0x1010], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.edx;
    // 0049ae55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ae57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49ae5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ae5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ae5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ae5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ae61  7507                   -jne 0x49ae6a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae6a;
    }
    // 0049ae63  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ae68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae6a:
    // 0049ae6a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ae6c  e8064afeff             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 0049ae71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ae73  e8c0edfeff             -call 0x489c38
    cpu.esp -= 4;
    sub_489c38(app, cpu);
    if (cpu.terminate) return;
    // 0049ae78  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ae7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ae80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ae80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ae81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ae82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ae83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ae84  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ae87  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049ae89  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ae8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ae8d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ae8f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049ae93  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ae95  0f8eae000000           -jle 0x49af49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049af49;
    }
    // 0049ae9b  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049ae9e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0049aea1:
    // 0049aea1  8b8e14100000           -mov ecx, dword ptr [esi + 0x1014]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 0049aea7  39cf                   +cmp edi, ecx
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
    // 0049aea9  7d02                   -jge 0x49aead
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049aead;
    }
    // 0049aeab  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x0049aead:
    // 0049aead  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049aeaf  7e41                   -jle 0x49aef2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049aef2;
    }
    // 0049aeb1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049aeb3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049aeb5  8b8610100000           -mov eax, dword ptr [esi + 0x1010]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 0049aebb  e89058feff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0049aec0  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aec2  8b9e10100000           -mov ebx, dword ptr [esi + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 0049aec8  8b8614100000           -mov eax, dword ptr [esi + 0x1014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 0049aece  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049aed1  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aed3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aed5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aed7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aed9  899e10100000           -mov dword ptr [esi + 0x1010], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.ebx;
    // 0049aedf  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049aee3  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
    // 0049aee9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aeeb  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049aeee  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0049aef2:
    // 0049aef2  83be1410000000         +cmp dword ptr [esi + 0x1014], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aef9  7546                   -jne 0x49af41
    if (!cpu.flags.zf)
    {
        goto L_0x0049af41;
    }
    // 0049aefb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049aefd  7442                   -je 0x49af41
    if (cpu.flags.zf)
    {
        goto L_0x0049af41;
    }
    // 0049aeff  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049af02  898610100000           -mov dword ptr [esi + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
    // 0049af08  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049af0b  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049af0e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049af10  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049af15  7e3e                   -jle 0x49af55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049af55;
    }
    // 0049af17  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
L_0x0049af1c:
    // 0049af1c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049af1e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049af20  7e1b                   -jle 0x49af3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049af3d;
    }
    // 0049af22  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049af27  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049af2a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049af2c  e8005dffff             -call 0x490c31
    cpu.esp -= 4;
    sub_490c31(app, cpu);
    if (cpu.terminate) return;
    // 0049af31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049af33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049af35  7e06                   -jle 0x49af3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049af3d;
    }
    // 0049af37  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
L_0x0049af3d:
    // 0049af3d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049af3f  7408                   -je 0x49af49
    if (cpu.flags.zf)
    {
        goto L_0x0049af49;
    }
L_0x0049af41:
    // 0049af41  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049af43  0f8f58ffffff           -jg 0x49aea1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049aea1;
    }
L_0x0049af49:
    // 0049af49  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049af4d  83c408                 +add esp, 8
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
    // 0049af50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049af55:
    // 0049af55  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049af57  ebc3                   -jmp 0x49af1c
    goto L_0x0049af1c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49af5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049af5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049af5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049af5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049af5f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049af61  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049af64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049af66  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049af68  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049af6b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049af6e  39fa                   +cmp edx, edi
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
    // 0049af70  7e03                   -jle 0x49af75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049af75;
    }
    // 0049af72  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0049af75:
    // 0049af75  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049af7a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049af7c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049af7e  e8cc08ffff             -call 0x48b84f
    cpu.esp -= 4;
    sub_48b84f(app, cpu);
    if (cpu.terminate) return;
    // 0049af83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049af88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49af8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049af8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049af8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049af8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049af8f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049af90  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049af95  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049af97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049af99  0f8c8d000000           -jl 0x49b02c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b02c;
    }
    // 0049af9f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049afa2  39da                   +cmp edx, ebx
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
    // 0049afa4  0f8e8b000000           -jle 0x49b035
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b035;
    }
    // 0049afaa  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049afac  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049afae:
    // 0049afae  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049afb8  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049afbb  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049afbe  898110100000           -mov dword ptr [ecx + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
L_0x0049afc4:
    // 0049afc4  83b91810000000         +cmp dword ptr [ecx + 0x1018], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4120) /* 0x1018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afcb  0f8596000000           -jne 0x49b067
    if (!cpu.flags.zf)
    {
        goto L_0x0049b067;
    }
    // 0049afd1  8b9914100000           -mov ebx, dword ptr [ecx + 0x1014]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */);
    // 0049afd7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049afd9  7e0c                   -jle 0x49afe7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049afe7;
    }
    // 0049afdb  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afe1  0f8eab000000           -jle 0x49b092
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b092;
    }
L_0x0049afe7:
    // 0049afe7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049afe9  0f8cbd000000           -jl 0x49b0ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b0ac;
    }
    // 0049afef  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aff2  0f8fb4000000           -jg 0x49b0ac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b0ac;
    }
    // 0049aff8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049affb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049affd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049afff  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b001  e8eee2ffff             -call 0x4992f4
    cpu.esp -= 4;
    sub_4992f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b006  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b008  0f859e000000           -jne 0x49b0ac
    if (!cpu.flags.zf)
    {
        goto L_0x0049b0ac;
    }
    // 0049b00e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049b010  0f8496000000           -je 0x49b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0049b0ac;
    }
    // 0049b016  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049b01b  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049b025  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b027  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b029  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b02a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b02b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b02c:
    // 0049b02c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b02e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049b030  e979ffffff             -jmp 0x49afae
    goto L_0x0049afae;
L_0x0049b035:
    // 0049b035  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b036  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049b038  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b03b  8ba810100000           -mov ebp, dword ptr [eax + 0x1010]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */);
    // 0049b041  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b043  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b045  8bb814100000           -mov edi, dword ptr [eax + 0x1014]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */);
    // 0049b04b  89a810100000           -mov dword ptr [eax + 0x1010], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ebp;
    // 0049b051  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b053  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b056  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 0049b05c  01dd                   +add ebp, ebx
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
    // 0049b05e  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0049b061  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b062  e95dffffff             -jmp 0x49afc4
    goto L_0x0049afc4;
L_0x0049b067:
    // 0049b067  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b06a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b06c  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b06e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b070  e87fe2ffff             -call 0x4992f4
    cpu.esp -= 4;
    sub_4992f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b075  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b077  7510                   -jne 0x49b089
    if (!cpu.flags.zf)
    {
        goto L_0x0049b089;
    }
    // 0049b079  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049b07b  740c                   -je 0x49b089
    if (cpu.flags.zf)
    {
        goto L_0x0049b089;
    }
    // 0049b07d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049b082  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b084  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b085  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b088  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b089:
    // 0049b089  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b08b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b08d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b08e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b08f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b090  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b091  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b092:
    // 0049b092  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049b095  8b9910100000           -mov ebx, dword ptr [ecx + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */);
    // 0049b09b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b09d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b09f  0f8c42ffffff           -jl 0x49afe7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049afe7;
    }
    // 0049b0a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b0a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b0ac:
    // 0049b0ac  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b0ae  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049b0b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b0ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b0be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0c0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b0c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b0c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0c4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b0c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b0c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0c8  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049b0c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b0ca  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049b0cf  757f                   -jne 0x49b150
    if (!cpu.flags.zf)
    {
        goto L_0x0049b150;
    }
L_0x0049b0d1:
    // 0049b0d1  83eb20                 +sub ebx, 0x20
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
    // 0049b0d4  7825                   -js 0x49b0fb
    if (cpu.flags.sf)
    {
        goto L_0x0049b0fb;
    }
L_0x0049b0d6:
    // 0049b0d6  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049b0d8  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0049b0db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b0dd  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0df  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0e2  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 0049b0e5  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 0049b0e8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b0ea  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0ed  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0f0  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049b0f3  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b0f6  83eb20                 +sub ebx, 0x20
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
    // 0049b0f9  79db                   -jns 0x49b0d6
    if (!cpu.flags.sf)
    {
        goto L_0x0049b0d6;
    }
L_0x0049b0fb:
    // 0049b0fb  83c318                 +add ebx, 0x18
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
    // 0049b0fe  780f                   -js 0x49b10f
    if (cpu.flags.sf)
    {
        goto L_0x0049b10f;
    }
L_0x0049b100:
    // 0049b100  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049b102  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b104  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049b107  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b10a  83eb08                 +sub ebx, 8
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
    // 0049b10d  79f1                   -jns 0x49b100
    if (!cpu.flags.sf)
    {
        goto L_0x0049b100;
    }
L_0x0049b10f:
    // 0049b10f  83c308                 +add ebx, 8
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
    // 0049b112  7502                   -jne 0x49b116
    if (!cpu.flags.zf)
    {
        goto L_0x0049b116;
    }
    // 0049b114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b115  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b116:
    // 0049b116  83fb04                 +cmp ebx, 4
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
    // 0049b119  720d                   -jb 0x49b128
    if (cpu.flags.cf)
    {
        goto L_0x0049b128;
    }
    // 0049b11b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b11d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b120  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b122  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b125  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049b128:
    // 0049b128  83fb02                 +cmp ebx, 2
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
    // 0049b12b  720f                   -jb 0x49b13c
    if (cpu.flags.cf)
    {
        goto L_0x0049b13c;
    }
    // 0049b12d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b130  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b133  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b136  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b139  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b13c:
    // 0049b13c  83fb01                 +cmp ebx, 1
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
    // 0049b13f  720d                   -jb 0x49b14e
    if (cpu.flags.cf)
    {
        goto L_0x0049b14e;
    }
    // 0049b141  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b143  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b146  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b148  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b14b  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b14e:
    // 0049b14e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b14f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b150:
    // 0049b150  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049b155  7412                   -je 0x49b169
    if (cpu.flags.zf)
    {
        goto L_0x0049b169;
    }
    // 0049b157  83fb01                 +cmp ebx, 1
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
    // 0049b15a  7c0d                   -jl 0x49b169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b169;
    }
    // 0049b15c  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b15e  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b161  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b163  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b166  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b169:
    // 0049b169  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049b16e  7414                   -je 0x49b184
    if (cpu.flags.zf)
    {
        goto L_0x0049b184;
    }
    // 0049b170  83fb02                 +cmp ebx, 2
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
    // 0049b173  7c0f                   -jl 0x49b184
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b184;
    }
    // 0049b175  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b178  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b17b  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b17e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b181  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b184:
    // 0049b184  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049b189  7412                   -je 0x49b19d
    if (cpu.flags.zf)
    {
        goto L_0x0049b19d;
    }
    // 0049b18b  83fb04                 +cmp ebx, 4
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
    // 0049b18e  7c0d                   -jl 0x49b19d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b19d;
    }
    // 0049b190  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b192  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b195  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b197  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b19a  83eb04                 +sub ebx, 4
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
L_0x0049b19d:
    // 0049b19d  e92fffffff             -jmp 0x49b0d1
    goto L_0x0049b0d1;
}

/* align: skip  */
void Application::sub_49b0c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049b0c9;
    // 0049b0c8  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0049b0c9:
    // 0049b0c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b0ca  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049b0cf  757f                   -jne 0x49b150
    if (!cpu.flags.zf)
    {
        goto L_0x0049b150;
    }
L_0x0049b0d1:
    // 0049b0d1  83eb20                 +sub ebx, 0x20
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
    // 0049b0d4  7825                   -js 0x49b0fb
    if (cpu.flags.sf)
    {
        goto L_0x0049b0fb;
    }
L_0x0049b0d6:
    // 0049b0d6  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049b0d8  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0049b0db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b0dd  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0df  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0e2  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 0049b0e5  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 0049b0e8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b0ea  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0ed  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b0f0  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049b0f3  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b0f6  83eb20                 +sub ebx, 0x20
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
    // 0049b0f9  79db                   -jns 0x49b0d6
    if (!cpu.flags.sf)
    {
        goto L_0x0049b0d6;
    }
L_0x0049b0fb:
    // 0049b0fb  83c318                 +add ebx, 0x18
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
    // 0049b0fe  780f                   -js 0x49b10f
    if (cpu.flags.sf)
    {
        goto L_0x0049b10f;
    }
L_0x0049b100:
    // 0049b100  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049b102  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049b104  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049b107  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b10a  83eb08                 +sub ebx, 8
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
    // 0049b10d  79f1                   -jns 0x49b100
    if (!cpu.flags.sf)
    {
        goto L_0x0049b100;
    }
L_0x0049b10f:
    // 0049b10f  83c308                 +add ebx, 8
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
    // 0049b112  7502                   -jne 0x49b116
    if (!cpu.flags.zf)
    {
        goto L_0x0049b116;
    }
    // 0049b114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b115  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b116:
    // 0049b116  83fb04                 +cmp ebx, 4
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
    // 0049b119  720d                   -jb 0x49b128
    if (cpu.flags.cf)
    {
        goto L_0x0049b128;
    }
    // 0049b11b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b11d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b120  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b122  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b125  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049b128:
    // 0049b128  83fb02                 +cmp ebx, 2
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
    // 0049b12b  720f                   -jb 0x49b13c
    if (cpu.flags.cf)
    {
        goto L_0x0049b13c;
    }
    // 0049b12d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b130  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b133  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b136  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b139  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b13c:
    // 0049b13c  83fb01                 +cmp ebx, 1
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
    // 0049b13f  720d                   -jb 0x49b14e
    if (cpu.flags.cf)
    {
        goto L_0x0049b14e;
    }
    // 0049b141  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b143  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b146  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b148  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b14b  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b14e:
    // 0049b14e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b14f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b150:
    // 0049b150  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049b155  7412                   -je 0x49b169
    if (cpu.flags.zf)
    {
        goto L_0x0049b169;
    }
    // 0049b157  83fb01                 +cmp ebx, 1
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
    // 0049b15a  7c0d                   -jl 0x49b169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b169;
    }
    // 0049b15c  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b15e  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b161  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b163  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b166  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b169:
    // 0049b169  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049b16e  7414                   -je 0x49b184
    if (cpu.flags.zf)
    {
        goto L_0x0049b184;
    }
    // 0049b170  83fb02                 +cmp ebx, 2
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
    // 0049b173  7c0f                   -jl 0x49b184
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b184;
    }
    // 0049b175  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b178  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b17b  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b17e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b181  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b184:
    // 0049b184  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049b189  7412                   -je 0x49b19d
    if (cpu.flags.zf)
    {
        goto L_0x0049b19d;
    }
    // 0049b18b  83fb04                 +cmp ebx, 4
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
    // 0049b18e  7c0d                   -jl 0x49b19d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b19d;
    }
    // 0049b190  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b192  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b195  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b197  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b19a  83eb04                 +sub ebx, 4
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
L_0x0049b19d:
    // 0049b19d  e92fffffff             -jmp 0x49b0d1
    goto L_0x0049b0d1;
}

/* align: skip 0x00 0x00 */
void Application::sub_49b1a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b1a4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049b1a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b1a6  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049b1ab  0f8585000000           -jne 0x49b236
    if (!cpu.flags.zf)
    {
        goto L_0x0049b236;
    }
L_0x0049b1b1:
    // 0049b1b1  83eb20                 +sub ebx, 0x20
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
    // 0049b1b4  7829                   -js 0x49b1df
    if (cpu.flags.sf)
    {
        goto L_0x0049b1df;
    }
L_0x0049b1b6:
    // 0049b1b6  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049b1b9  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049b1bd  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049b1c1  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049b1c5  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049b1c8  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0049b1cc  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 0049b1d0  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 0049b1d4  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049b1d7  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b1da  83eb20                 +sub ebx, 0x20
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
    // 0049b1dd  79d7                   -jns 0x49b1b6
    if (!cpu.flags.sf)
    {
        goto L_0x0049b1b6;
    }
L_0x0049b1df:
    // 0049b1df  83c318                 +add ebx, 0x18
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
    // 0049b1e2  7811                   -js 0x49b1f5
    if (cpu.flags.sf)
    {
        goto L_0x0049b1f5;
    }
L_0x0049b1e4:
    // 0049b1e4  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049b1e7  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049b1ea  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049b1ed  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b1f0  83eb08                 +sub ebx, 8
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
    // 0049b1f3  79ef                   -jns 0x49b1e4
    if (!cpu.flags.sf)
    {
        goto L_0x0049b1e4;
    }
L_0x0049b1f5:
    // 0049b1f5  83c308                 +add ebx, 8
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
    // 0049b1f8  7502                   -jne 0x49b1fc
    if (!cpu.flags.zf)
    {
        goto L_0x0049b1fc;
    }
    // 0049b1fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b1fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b1fc:
    // 0049b1fc  83fb04                 +cmp ebx, 4
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
    // 0049b1ff  720d                   -jb 0x49b20e
    if (cpu.flags.cf)
    {
        goto L_0x0049b20e;
    }
    // 0049b201  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b203  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b206  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b208  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b20b  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049b20e:
    // 0049b20e  83fb02                 +cmp ebx, 2
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
    // 0049b211  720f                   -jb 0x49b222
    if (cpu.flags.cf)
    {
        goto L_0x0049b222;
    }
    // 0049b213  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b216  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b219  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b21c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b21f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b222:
    // 0049b222  83fb01                 +cmp ebx, 1
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
    // 0049b225  720d                   -jb 0x49b234
    if (cpu.flags.cf)
    {
        goto L_0x0049b234;
    }
    // 0049b227  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b229  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b22c  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b22e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b231  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b234:
    // 0049b234  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b235  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b236:
    // 0049b236  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049b23b  7412                   -je 0x49b24f
    if (cpu.flags.zf)
    {
        goto L_0x0049b24f;
    }
    // 0049b23d  83fb01                 +cmp ebx, 1
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
    // 0049b240  7c0d                   -jl 0x49b24f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b24f;
    }
    // 0049b242  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b244  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b247  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b249  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b24c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b24f:
    // 0049b24f  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049b254  7414                   -je 0x49b26a
    if (cpu.flags.zf)
    {
        goto L_0x0049b26a;
    }
    // 0049b256  83fb02                 +cmp ebx, 2
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
    // 0049b259  7c0f                   -jl 0x49b26a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b26a;
    }
    // 0049b25b  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b25e  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b261  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b264  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b267  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b26a:
    // 0049b26a  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049b26f  7412                   -je 0x49b283
    if (cpu.flags.zf)
    {
        goto L_0x0049b283;
    }
    // 0049b271  83fb04                 +cmp ebx, 4
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
    // 0049b274  7c0d                   -jl 0x49b283
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b283;
    }
    // 0049b276  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b278  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b27b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b27d  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b280  83eb04                 +sub ebx, 4
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
L_0x0049b283:
    // 0049b283  e929ffffff             -jmp 0x49b1b1
    goto L_0x0049b1b1;
}

/* align: skip  */
void Application::sub_49b1a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049b1a5;
    // 0049b1a4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0049b1a5:
    // 0049b1a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b1a6  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049b1ab  0f8585000000           -jne 0x49b236
    if (!cpu.flags.zf)
    {
        goto L_0x0049b236;
    }
L_0x0049b1b1:
    // 0049b1b1  83eb20                 +sub ebx, 0x20
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
    // 0049b1b4  7829                   -js 0x49b1df
    if (cpu.flags.sf)
    {
        goto L_0x0049b1df;
    }
L_0x0049b1b6:
    // 0049b1b6  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049b1b9  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049b1bd  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049b1c1  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049b1c5  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049b1c8  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0049b1cc  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 0049b1d0  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 0049b1d4  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049b1d7  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b1da  83eb20                 +sub ebx, 0x20
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
    // 0049b1dd  79d7                   -jns 0x49b1b6
    if (!cpu.flags.sf)
    {
        goto L_0x0049b1b6;
    }
L_0x0049b1df:
    // 0049b1df  83c318                 +add ebx, 0x18
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
    // 0049b1e2  7811                   -js 0x49b1f5
    if (cpu.flags.sf)
    {
        goto L_0x0049b1f5;
    }
L_0x0049b1e4:
    // 0049b1e4  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049b1e7  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049b1ea  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049b1ed  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b1f0  83eb08                 +sub ebx, 8
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
    // 0049b1f3  79ef                   -jns 0x49b1e4
    if (!cpu.flags.sf)
    {
        goto L_0x0049b1e4;
    }
L_0x0049b1f5:
    // 0049b1f5  83c308                 +add ebx, 8
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
    // 0049b1f8  7502                   -jne 0x49b1fc
    if (!cpu.flags.zf)
    {
        goto L_0x0049b1fc;
    }
    // 0049b1fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b1fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b1fc:
    // 0049b1fc  83fb04                 +cmp ebx, 4
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
    // 0049b1ff  720d                   -jb 0x49b20e
    if (cpu.flags.cf)
    {
        goto L_0x0049b20e;
    }
    // 0049b201  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b203  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b206  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b208  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b20b  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049b20e:
    // 0049b20e  83fb02                 +cmp ebx, 2
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
    // 0049b211  720f                   -jb 0x49b222
    if (cpu.flags.cf)
    {
        goto L_0x0049b222;
    }
    // 0049b213  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b216  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b219  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b21c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b21f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b222:
    // 0049b222  83fb01                 +cmp ebx, 1
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
    // 0049b225  720d                   -jb 0x49b234
    if (cpu.flags.cf)
    {
        goto L_0x0049b234;
    }
    // 0049b227  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b229  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b22c  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b22e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b231  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b234:
    // 0049b234  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b235  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b236:
    // 0049b236  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049b23b  7412                   -je 0x49b24f
    if (cpu.flags.zf)
    {
        goto L_0x0049b24f;
    }
    // 0049b23d  83fb01                 +cmp ebx, 1
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
    // 0049b240  7c0d                   -jl 0x49b24f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b24f;
    }
    // 0049b242  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049b244  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049b247  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049b249  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049b24c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049b24f:
    // 0049b24f  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049b254  7414                   -je 0x49b26a
    if (cpu.flags.zf)
    {
        goto L_0x0049b26a;
    }
    // 0049b256  83fb02                 +cmp ebx, 2
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
    // 0049b259  7c0f                   -jl 0x49b26a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b26a;
    }
    // 0049b25b  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049b25e  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b261  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049b264  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b267  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049b26a:
    // 0049b26a  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049b26f  7412                   -je 0x49b283
    if (cpu.flags.zf)
    {
        goto L_0x0049b283;
    }
    // 0049b271  83fb04                 +cmp ebx, 4
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
    // 0049b274  7c0d                   -jl 0x49b283
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b283;
    }
    // 0049b276  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b278  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b27b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049b27d  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b280  83eb04                 +sub ebx, 4
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
L_0x0049b283:
    // 0049b283  e929ffffff             -jmp 0x49b1b1
    goto L_0x0049b1b1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b290  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b291  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b292  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b293  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b296  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b298  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049b29a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049b29c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b2a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b2a2  7506                   -jne 0x49b2aa
    if (!cpu.flags.zf)
    {
        goto L_0x0049b2aa;
    }
    // 0049b2a4  8b0dec814c00           -mov ecx, dword ptr [0x4c81ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
L_0x0049b2aa:
    // 0049b2aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b2ac  7505                   -jne 0x49b2b3
    if (!cpu.flags.zf)
    {
        goto L_0x0049b2b3;
    }
    // 0049b2ae  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x0049b2b3:
    // 0049b2b3  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049b2b6  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049b2b8  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 0049b2bd  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049b2c0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b2c2  e8153efeff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0049b2c7  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 0049b2cd  c6461eff               -mov byte ptr [esi + 0x1e], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = 255 /*0xff*/;
    // 0049b2d1  896e28                 -mov dword ptr [esi + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0049b2d4  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049b2d7  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049b2da  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0049b2dd  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b2e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b2e2  884e1c                 -mov byte ptr [esi + 0x1c], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cl;
    // 0049b2e5  e816b2ffff             -call 0x496500
    cpu.esp -= 4;
    sub_496500(app, cpu);
    if (cpu.terminate) return;
    // 0049b2ea  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b2ec  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 0049b2ef  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b2f3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049b2f5  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049b2f8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b2fc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b2fe  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049b301  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b303  e8bc7dffff             -call 0x4930c4
    cpu.esp -= 4;
    sub_4930c4(app, cpu);
    if (cpu.terminate) return;
    // 0049b308  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049b30d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b310  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049b312  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049b315  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b317  e8a87dffff             -call 0x4930c4
    cpu.esp -= 4;
    sub_4930c4(app, cpu);
    if (cpu.terminate) return;
    // 0049b31c  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0049b31f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b322  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b323  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b324  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b325  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_49b328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b328  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b329  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b32a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b32b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b32e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049b330  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b332  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049b335  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b339  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b33b  7c26                   -jl 0x49b363
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b363;
    }
    // 0049b33d  3d00050000             +cmp eax, 0x500
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1280 /*0x500*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b342  7f1f                   -jg 0x49b363
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b363;
    }
    // 0049b344  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b346  7c1b                   -jl 0x49b363
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b363;
    }
    // 0049b348  81fa00040000           +cmp edx, 0x400
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b34e  7f13                   -jg 0x49b363
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b363;
    }
    // 0049b350  83fbff                 +cmp ebx, -1
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
    // 0049b353  7519                   -jne 0x49b36e
    if (!cpu.flags.zf)
    {
        goto L_0x0049b36e;
    }
    // 0049b355  be08854c00             -mov esi, 0x4c8508
    cpu.esi = 5014792 /*0x4c8508*/;
L_0x0049b35a:
    // 0049b35a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049b35c  752f                   -jne 0x49b38d
    if (!cpu.flags.zf)
    {
        goto L_0x0049b38d;
    }
    // 0049b35e  e8a9d9fdff             -call 0x478d0c
    cpu.esp -= 4;
    sub_478d0c(app, cpu);
    if (cpu.terminate) return;
L_0x0049b363:
    // 0049b363  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b365  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b368  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b36a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b36b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049b36e:
    // 0049b36e  83fbfe                 +cmp ebx, -2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b371  7507                   -jne 0x49b37a
    if (!cpu.flags.zf)
    {
        goto L_0x0049b37a;
    }
    // 0049b373  be40854c00             -mov esi, 0x4c8540
    cpu.esi = 5014848 /*0x4c8540*/;
    // 0049b378  ebe0                   -jmp 0x49b35a
    goto L_0x0049b35a;
L_0x0049b37a:
    // 0049b37a  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 0049b37f  b890f34b00             -mov eax, 0x4bf390
    cpu.eax = 4977552 /*0x4bf390*/;
    // 0049b384  e8dfd2fdff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0049b389  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b38b  ebcd                   -jmp 0x49b35a
    goto L_0x0049b35a;
L_0x0049b38d:
    // 0049b38d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b391  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b392  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b396  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b399  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049b39b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b39c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049b39e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b3a2  e8e9feffff             -call 0x49b290
    cpu.esp -= 4;
    sub_49b290(app, cpu);
    if (cpu.terminate) return;
    // 0049b3a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b3a9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b3ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3af  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b3b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b3b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b3b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b3b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b3b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b3ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b3bc  7505                   -jne 0x49b3c3
    if (!cpu.flags.zf)
    {
        goto L_0x0049b3c3;
    }
    // 0049b3be  bed0844c00             -mov esi, 0x4c84d0
    cpu.esi = 5014736 /*0x4c84d0*/;
L_0x0049b3c3:
    // 0049b3c3  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0049b3c6  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049b3c9  39ca                   +cmp edx, ecx
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
    // 0049b3cb  7420                   -je 0x49b3ed
    if (cpu.flags.zf)
    {
        goto L_0x0049b3ed;
    }
    // 0049b3cd  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0049b3d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b3d2  7407                   -je 0x49b3db
    if (cpu.flags.zf)
    {
        goto L_0x0049b3db;
    }
    // 0049b3d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b3d6  e8c17dffff             -call 0x49319c
    cpu.esp -= 4;
    sub_49319c(app, cpu);
    if (cpu.terminate) return;
L_0x0049b3db:
    // 0049b3db  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b3de  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b3e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b3e2  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049b3e5  e8da7cffff             -call 0x4930c4
    cpu.esp -= 4;
    sub_4930c4(app, cpu);
    if (cpu.terminate) return;
    // 0049b3ea  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049b3ed:
    // 0049b3ed  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b3f0  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b3f3  39f8                   +cmp eax, edi
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
    // 0049b3f5  7e03                   -jle 0x49b3fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b3fa;
    }
    // 0049b3f7  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0049b3fa:
    // 0049b3fa  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049b3fd  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b400  39e8                   +cmp eax, ebp
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
    // 0049b402  7e03                   -jle 0x49b407
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b407;
    }
    // 0049b404  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x0049b407:
    // 0049b407  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049b40a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b40d  39d0                   +cmp eax, edx
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
    // 0049b40f  7e19                   -jle 0x49b42a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b42a;
    }
    // 0049b411  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0049b414:
    // 0049b414  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b417  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b41a  39d8                   +cmp eax, ebx
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
    // 0049b41c  7f18                   -jg 0x49b436
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049b436;
    }
    // 0049b41e  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049b421  39f8                   +cmp eax, edi
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
    // 0049b423  7c19                   -jl 0x49b43e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b43e;
    }
    // 0049b425  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b426  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b427  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b428  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b42a:
    // 0049b42a  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b42d  39c8                   +cmp eax, ecx
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
    // 0049b42f  7de3                   -jge 0x49b414
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b414;
    }
    // 0049b431  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049b434  ebde                   -jmp 0x49b414
    goto L_0x0049b414;
L_0x0049b436:
    // 0049b436  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b439  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b43e:
    // 0049b43e  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0049b441  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b443  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b448  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b449  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b44a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b44b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b44d  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0049b450  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b452  7529                   -jne 0x49b47d
    if (!cpu.flags.zf)
    {
        goto L_0x0049b47d;
    }
L_0x0049b454:
    // 0049b454  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0049b457  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049b459  740e                   -je 0x49b469
    if (cpu.flags.zf)
    {
        goto L_0x0049b469;
    }
    // 0049b45b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b45d  e83a7dffff             -call 0x49319c
    cpu.esp -= 4;
    sub_49319c(app, cpu);
    if (cpu.terminate) return;
    // 0049b462  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
L_0x0049b469:
    // 0049b469  81fa08854c00           +cmp edx, 0x4c8508
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5014792 /*0x4c8508*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b46f  7408                   -je 0x49b479
    if (cpu.flags.zf)
    {
        goto L_0x0049b479;
    }
    // 0049b471  81fa40854c00           +cmp edx, 0x4c8540
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5014848 /*0x4c8540*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b477  7514                   -jne 0x49b48d
    if (!cpu.flags.zf)
    {
        goto L_0x0049b48d;
    }
L_0x0049b479:
    // 0049b479  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b47a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b47b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b47c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b47d:
    // 0049b47d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b47f  e8187dffff             -call 0x49319c
    cpu.esp -= 4;
    sub_49319c(app, cpu);
    if (cpu.terminate) return;
    // 0049b484  c7422c00000000         -mov dword ptr [edx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 0049b48b  ebc7                   -jmp 0x49b454
    goto L_0x0049b454;
L_0x0049b48d:
    // 0049b48d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b48f  e838d6fdff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0049b494  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b495  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b496  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b497  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b498(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b498  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b499  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049b49c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b49e  7502                   -jne 0x49b4a2
    if (!cpu.flags.zf)
    {
        goto L_0x0049b4a2;
    }
    // 0049b4a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b4a2:
    // 0049b4a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b4a4  e89b89feff             -call 0x483e44
    cpu.esp -= 4;
    sub_483e44(app, cpu);
    if (cpu.terminate) return;
    // 0049b4a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b4ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b4ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b4ad  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049b4b0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b4b2  7502                   -jne 0x49b4b6
    if (!cpu.flags.zf)
    {
        goto L_0x0049b4b6;
    }
    // 0049b4b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b4b6:
    // 0049b4b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b4b8  e8c789feff             -call 0x483e84
    cpu.esp -= 4;
    sub_483e84(app, cpu);
    if (cpu.terminate) return;
    // 0049b4bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b4c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b4c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b4c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b4c3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b4c6  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049b4c8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b4ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b4cb  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049b4cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b4d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b4d1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049b4d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b4d4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049b4d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b4d8  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0049b4dd  e8b285feff             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 0049b4e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b4e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b4e6  750b                   -jne 0x49b4f3
    if (!cpu.flags.zf)
    {
        goto L_0x0049b4f3;
    }
L_0x0049b4e8:
    // 0049b4e8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b4ea  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b4ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4f0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049b4f3:
    // 0049b4f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b4f5  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b4f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b4fa  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b4fe  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b502  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b503  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b507  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b509  e85288feff             -call 0x483d60
    cpu.esp -= 4;
    sub_483d60(app, cpu);
    if (cpu.terminate) return;
    // 0049b50e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b50f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b513  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b514  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b518  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b51c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b51d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b521  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b525  e8fefdffff             -call 0x49b328
    cpu.esp -= 4;
    sub_49b328(app, cpu);
    if (cpu.terminate) return;
    // 0049b52a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049b52c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b52e  75b8                   -jne 0x49b4e8
    if (!cpu.flags.zf)
    {
        goto L_0x0049b4e8;
    }
    // 0049b530  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0049b535  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049b537  e84c87feff             -call 0x483c88
    cpu.esp -= 4;
    sub_483c88(app, cpu);
    if (cpu.terminate) return;
    // 0049b53c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b53e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b541  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b542  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b543  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b544  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b550  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b552  742c                   -je 0x49b580
    if (cpu.flags.zf)
    {
        goto L_0x0049b580;
    }
    // 0049b554  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x0049b556:
    // 0049b556  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0049b558  7409                   -je 0x49b563
    if (cpu.flags.zf)
    {
        goto L_0x0049b563;
    }
    // 0049b55a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049b55c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049b55d  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 0049b560  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b561  75f3                   -jne 0x49b556
    if (!cpu.flags.zf)
    {
        goto L_0x0049b556;
    }
L_0x0049b563:
    // 0049b563  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b564  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049b567  e81b000000             -call 0x49b587
    cpu.esp -= 4;
    sub_49b587(app, cpu);
    if (cpu.terminate) return;
    // 0049b56c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b56d  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049b570  740e                   -je 0x49b580
    if (cpu.flags.zf)
    {
        goto L_0x0049b580;
    }
    // 0049b572  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049b574  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b575  7409                   -je 0x49b580
    if (cpu.flags.zf)
    {
        goto L_0x0049b580;
    }
    // 0049b577  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 0049b57a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b57b  7403                   -je 0x49b580
    if (cpu.flags.zf)
    {
        goto L_0x0049b580;
    }
    // 0049b57d  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0049b580:
    // 0049b580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b582(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b582  90                     -nop 
    ;
    // 0049b583  90                     -nop 
    ;
    // 0049b584  90                     -nop 
    ;
    // 0049b585  90                     -nop 
    ;
    // 0049b586  90                     -nop 
    ;
    // 0049b587  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b589  7467                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
L_0x0049b58b:
    // 0049b58b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0049b58d  7408                   -je 0x49b597
    if (cpu.flags.zf)
    {
        goto L_0x0049b597;
    }
    // 0049b58f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b591  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b594  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b595  75f4                   -jne 0x49b58b
    if (!cpu.flags.zf)
    {
        goto L_0x0049b58b;
    }
L_0x0049b597:
    // 0049b597  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b598  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049b59b  743a                   -je 0x49b5d7
    if (cpu.flags.zf)
    {
        goto L_0x0049b5d7;
    }
    // 0049b59d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b59e  7429                   -je 0x49b5c9
    if (cpu.flags.zf)
    {
        goto L_0x0049b5c9;
    }
L_0x0049b5a0:
    // 0049b5a0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5a2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b5a5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5a6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049b5a9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b5ac  7418                   -je 0x49b5c6
    if (cpu.flags.zf)
    {
        goto L_0x0049b5c6;
    }
    // 0049b5ae  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049b5b1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049b5b4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049b5b7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5b8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049b5bb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049b5be  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b5c1  75dd                   -jne 0x49b5a0
    if (!cpu.flags.zf)
    {
        goto L_0x0049b5a0;
    }
    // 0049b5c3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0049b5c6:
    // 0049b5c6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049b5c9:
    // 0049b5c9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5cb  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b5ce  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049b5d1  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b5d4  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049b5d7:
    // 0049b5d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5d8  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049b5db  7415                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5dd  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5df  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b5e2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5e3  740d                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5e5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5e7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b5ea  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5eb  7405                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5ed  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5ef  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0049b5f2:
    // 0049b5f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b587(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049b587;
    // 0049b582  90                     -nop 
    ;
    // 0049b583  90                     -nop 
    ;
    // 0049b584  90                     -nop 
    ;
    // 0049b585  90                     -nop 
    ;
    // 0049b586  90                     -nop 
    ;
L_entry_0x0049b587:
    // 0049b587  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b589  7467                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
L_0x0049b58b:
    // 0049b58b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0049b58d  7408                   -je 0x49b597
    if (cpu.flags.zf)
    {
        goto L_0x0049b597;
    }
    // 0049b58f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b591  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b594  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b595  75f4                   -jne 0x49b58b
    if (!cpu.flags.zf)
    {
        goto L_0x0049b58b;
    }
L_0x0049b597:
    // 0049b597  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b598  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049b59b  743a                   -je 0x49b5d7
    if (cpu.flags.zf)
    {
        goto L_0x0049b5d7;
    }
    // 0049b59d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b59e  7429                   -je 0x49b5c9
    if (cpu.flags.zf)
    {
        goto L_0x0049b5c9;
    }
L_0x0049b5a0:
    // 0049b5a0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5a2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b5a5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5a6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049b5a9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b5ac  7418                   -je 0x49b5c6
    if (cpu.flags.zf)
    {
        goto L_0x0049b5c6;
    }
    // 0049b5ae  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049b5b1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049b5b4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049b5b7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5b8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049b5bb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049b5be  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b5c1  75dd                   -jne 0x49b5a0
    if (!cpu.flags.zf)
    {
        goto L_0x0049b5a0;
    }
    // 0049b5c3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0049b5c6:
    // 0049b5c6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049b5c9:
    // 0049b5c9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5cb  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b5ce  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049b5d1  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b5d4  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049b5d7:
    // 0049b5d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5d8  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049b5db  7415                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5dd  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5df  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b5e2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5e3  740d                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5e5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5e7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b5ea  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5eb  7405                   -je 0x49b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f2;
    }
    // 0049b5ed  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049b5ef  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0049b5f2:
    // 0049b5f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49b5f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b5f4  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049b5f7  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b5fa  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b5fd  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049b600  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b602  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b604  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b607  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b60a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b60c  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b60e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049b611  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b613  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b615  0f8410010000           -je 0x49b72b
    if (cpu.flags.zf)
    {
        goto L_0x0049b72b;
    }
    // 0049b61b  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b61e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049b621  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049b624  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b626  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b629  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b62b  891d68f74c00           -mov dword ptr [0x4cf768], ebx
    app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */) = cpu.ebx;
    // 0049b631  890d6cf74c00           -mov dword ptr [0x4cf76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */) = cpu.ecx;
    // 0049b637  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 0049b63a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b63c  db0568f74c00           -fild dword ptr [0x4cf768]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */))));
    // 0049b642  db056cf74c00           -fild dword ptr [0x4cf76c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */))));
    // 0049b648  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049b64a  d80d80f74c00           -fmul dword ptr [0x4cf780]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044096) /* 0x4cf780 */));
    // 0049b650  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049b652  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049b654  d80d7cf74c00           -fmul dword ptr [0x4cf77c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044092) /* 0x4cf77c */));
    // 0049b65a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b65c  d80d84f74c00           -fmul dword ptr [0x4cf784]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044100) /* 0x4cf784 */));
    // 0049b662  f72d78f74c00           -imul dword ptr [0x4cf778]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044088) /* 0x4cf778 */))));
    // 0049b668  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049b66a  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b66c  d80588f74c00           -fadd dword ptr [0x4cf788]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5044104) /* 0x4cf788 */));
    // 0049b672  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b674  d80588f74c00           -fadd dword ptr [0x4cf788]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5044104) /* 0x4cf788 */));
    // 0049b67a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b67d  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b680  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049b682  dd1d70f74c00           -fstp qword ptr [0x4cf770]
    app->getMemory<double>(x86::reg32(5044080) /* 0x4cf770 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b688  dd1d68f74c00           -fstp qword ptr [0x4cf768]
    app->getMemory<double>(x86::reg32(5044072) /* 0x4cf768 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b68e  8b0d68f74c00           -mov ecx, dword ptr [0x4cf768]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */);
    // 0049b694  8b3d70f74c00           -mov edi, dword ptr [0x4cf770]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */);
    // 0049b69a  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b69c  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049b69e  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b6a0  890d6cf74c00           -mov dword ptr [0x4cf76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */) = cpu.ecx;
    // 0049b6a6  891570f74c00           -mov dword ptr [0x4cf770], edx
    app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */) = cpu.edx;
    // 0049b6ac  893d74f74c00           -mov dword ptr [0x4cf774], edi
    app->getMemory<x86::reg32>(x86::reg32(5044084) /* 0x4cf774 */) = cpu.edi;
    // 0049b6b2  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049b6b4  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049b6b7  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049b6ba  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b6bc  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b6bf  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b6c1  f72d78f74c00           -imul dword ptr [0x4cf778]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044088) /* 0x4cf778 */))));
    // 0049b6c7  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049b6c9  8b3d64f74c00           -mov edi, dword ptr [0x4cf764]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b6cf  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b6d1  8b2d6cf74c00           -mov ebp, dword ptr [0x4cf76c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */);
    // 0049b6d7  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b6da  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b6dc  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 0049b6df  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b6e1  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049b6e4  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b6e6  8b2d68f74c00           -mov ebp, dword ptr [0x4cf768]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */);
    // 0049b6ec  897748                 -mov dword ptr [edi + 0x48], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 0049b6ef  8b3570f74c00           -mov esi, dword ptr [0x4cf770]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */);
    // 0049b6f5  898fb4000000           -mov dword ptr [edi + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0049b6fb  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0049b6fe  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b700  8b2d74f74c00           -mov ebp, dword ptr [0x4cf774]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044084) /* 0x4cf774 */);
    // 0049b706  894f6c                 -mov dword ptr [edi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0049b709  899f90000000           -mov dword ptr [edi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
    // 0049b70f  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0049b712  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b714  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049b717  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b719  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049b71b  895f24                 -mov dword ptr [edi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049b71e  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0049b724  8997fc000000           -mov dword ptr [edi + 0xfc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.edx;
    // 0049b72a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b72b:
    // 0049b72b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049b72d  8b3d64f74c00           -mov edi, dword ptr [0x4cf764]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b733  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049b735  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049b738  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049b73b  89476c                 -mov dword ptr [edi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0049b73e  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0049b744  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0049b74a  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0049b750  8987fc000000           -mov dword ptr [edi + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.eax;
    // 0049b756  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b757(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b757  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049b75a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b75d  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b760  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049b763  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049b766  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b768  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b76b  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b76d  891d68f74c00           -mov dword ptr [0x4cf768], ebx
    app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */) = cpu.ebx;
    // 0049b773  890d6cf74c00           -mov dword ptr [0x4cf76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */) = cpu.ecx;
    // 0049b779  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 0049b77c  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b77e  db0568f74c00           -fild dword ptr [0x4cf768]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */))));
    // 0049b784  db056cf74c00           -fild dword ptr [0x4cf76c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */))));
    // 0049b78a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049b78c  d80d80f74c00           -fmul dword ptr [0x4cf780]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044096) /* 0x4cf780 */));
    // 0049b792  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049b794  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049b796  d80d7cf74c00           -fmul dword ptr [0x4cf77c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044092) /* 0x4cf77c */));
    // 0049b79c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b79e  d80d84f74c00           -fmul dword ptr [0x4cf784]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5044100) /* 0x4cf784 */));
    // 0049b7a4  f72d78f74c00           -imul dword ptr [0x4cf778]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044088) /* 0x4cf778 */))));
    // 0049b7aa  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049b7ac  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049b7ae  d80588f74c00           -fadd dword ptr [0x4cf788]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5044104) /* 0x4cf788 */));
    // 0049b7b4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b7b6  d80588f74c00           -fadd dword ptr [0x4cf788]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5044104) /* 0x4cf788 */));
    // 0049b7bc  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b7bf  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049b7c2  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049b7c4  dd1d70f74c00           -fstp qword ptr [0x4cf770]
    app->getMemory<double>(x86::reg32(5044080) /* 0x4cf770 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b7ca  dd1d68f74c00           -fstp qword ptr [0x4cf768]
    app->getMemory<double>(x86::reg32(5044072) /* 0x4cf768 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049b7d0  8b0d68f74c00           -mov ecx, dword ptr [0x4cf768]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */);
    // 0049b7d6  8b3d70f74c00           -mov edi, dword ptr [0x4cf770]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */);
    // 0049b7dc  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b7de  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049b7e0  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b7e2  890d6cf74c00           -mov dword ptr [0x4cf76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */) = cpu.ecx;
    // 0049b7e8  891570f74c00           -mov dword ptr [0x4cf770], edx
    app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */) = cpu.edx;
    // 0049b7ee  893d74f74c00           -mov dword ptr [0x4cf774], edi
    app->getMemory<x86::reg32>(x86::reg32(5044084) /* 0x4cf774 */) = cpu.edi;
    // 0049b7f4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049b7f6  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049b7f9  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049b7fc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b7fe  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b801  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b803  f72d78f74c00           -imul dword ptr [0x4cf778]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044088) /* 0x4cf778 */))));
    // 0049b809  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049b80b  8b3d64f74c00           -mov edi, dword ptr [0x4cf764]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b811  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b813  8b2d6cf74c00           -mov ebp, dword ptr [0x4cf76c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044076) /* 0x4cf76c */);
    // 0049b819  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049b81c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b81e  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 0049b821  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b823  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049b826  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b828  8b2d68f74c00           -mov ebp, dword ptr [0x4cf768]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044072) /* 0x4cf768 */);
    // 0049b82e  897708                 -mov dword ptr [edi + 8], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049b831  8b3570f74c00           -mov esi, dword ptr [0x4cf770]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5044080) /* 0x4cf770 */);
    // 0049b837  894f14                 -mov dword ptr [edi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049b83a  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0049b83d  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b83f  8b2d74f74c00           -mov ebp, dword ptr [0x4cf774]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044084) /* 0x4cf774 */);
    // 0049b845  894f0c                 -mov dword ptr [edi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049b848  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049b84b  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0049b84e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b850  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049b853  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b855  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049b857  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049b85a  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049b85d  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049b860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b861(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b861  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b862  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b865  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b866  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b867  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b86a  891560f74c00           -mov dword ptr [0x4cf760], edx
    app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */) = cpu.edx;
    // 0049b870  beacf84c00             -mov esi, 0x4cf8ac
    cpu.esi = 5044396 /*0x4cf8ac*/;
    // 0049b875  c70564f74c008cf74c00   -mov dword ptr [0x4cf764], 0x4cf78c
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044108 /*0x4cf78c*/;
    // 0049b87f  e870fdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b884  beccf84c00             -mov esi, 0x4cf8cc
    cpu.esi = 5044428 /*0x4cf8cc*/;
    // 0049b889  c70564f74c0090f74c00   -mov dword ptr [0x4cf764], 0x4cf790
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044112 /*0x4cf790*/;
    // 0049b893  e85cfdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b898  beecf84c00             -mov esi, 0x4cf8ec
    cpu.esi = 5044460 /*0x4cf8ec*/;
    // 0049b89d  c70564f74c0094f74c00   -mov dword ptr [0x4cf764], 0x4cf794
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044116 /*0x4cf794*/;
    // 0049b8a7  e848fdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b8ac  be0cf94c00             -mov esi, 0x4cf90c
    cpu.esi = 5044492 /*0x4cf90c*/;
    // 0049b8b1  c70564f74c0098f74c00   -mov dword ptr [0x4cf764], 0x4cf798
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044120 /*0x4cf798*/;
    // 0049b8bb  e834fdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b8c0  be2cf94c00             -mov esi, 0x4cf92c
    cpu.esi = 5044524 /*0x4cf92c*/;
    // 0049b8c5  c70564f74c009cf74c00   -mov dword ptr [0x4cf764], 0x4cf79c
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044124 /*0x4cf79c*/;
    // 0049b8cf  e820fdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b8d4  be4cf94c00             -mov esi, 0x4cf94c
    cpu.esi = 5044556 /*0x4cf94c*/;
    // 0049b8d9  c70564f74c00a0f74c00   -mov dword ptr [0x4cf764], 0x4cf7a0
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044128 /*0x4cf7a0*/;
    // 0049b8e3  e80cfdffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b8e8  be6cf94c00             -mov esi, 0x4cf96c
    cpu.esi = 5044588 /*0x4cf96c*/;
    // 0049b8ed  c70564f74c00a4f74c00   -mov dword ptr [0x4cf764], 0x4cf7a4
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044132 /*0x4cf7a4*/;
    // 0049b8f7  e8f8fcffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b8fc  be8cf94c00             -mov esi, 0x4cf98c
    cpu.esi = 5044620 /*0x4cf98c*/;
    // 0049b901  c70564f74c00a8f74c00   -mov dword ptr [0x4cf764], 0x4cf7a8
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = 5044136 /*0x4cf7a8*/;
    // 0049b90b  e8e4fcffff             -call 0x49b5f4
    cpu.esp -= 4;
    sub_49b5f4(app, cpu);
    if (cpu.terminate) return;
    // 0049b910  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b911  be8cf74c00             -mov esi, 0x4cf78c
    cpu.esi = 5044108 /*0x4cf78c*/;
    // 0049b916  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b91b  e837feffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b920  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b925  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b92b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b92d  beb0f74c00             -mov esi, 0x4cf7b0
    cpu.esi = 5044144 /*0x4cf7b0*/;
    // 0049b932  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b937  e81bfeffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b93c  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b941  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b947  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b949  bed4f74c00             -mov esi, 0x4cf7d4
    cpu.esi = 5044180 /*0x4cf7d4*/;
    // 0049b94e  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b953  e8fffdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b958  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b95d  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b963  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b965  bef8f74c00             -mov esi, 0x4cf7f8
    cpu.esi = 5044216 /*0x4cf7f8*/;
    // 0049b96a  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b96f  e8e3fdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b974  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b979  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b97f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b981  be1cf84c00             -mov esi, 0x4cf81c
    cpu.esi = 5044252 /*0x4cf81c*/;
    // 0049b986  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b98b  e8c7fdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b990  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b995  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b99b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b99d  be40f84c00             -mov esi, 0x4cf840
    cpu.esi = 5044288 /*0x4cf840*/;
    // 0049b9a2  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b9a7  e8abfdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b9ac  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b9b1  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b9b7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b9b9  be64f84c00             -mov esi, 0x4cf864
    cpu.esi = 5044324 /*0x4cf864*/;
    // 0049b9be  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b9c3  e88ffdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b9c8  a164f74c00             -mov eax, dword ptr [0x4cf764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */);
    // 0049b9cd  8b1560f74c00           -mov edx, dword ptr [0x4cf760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044064) /* 0x4cf760 */);
    // 0049b9d3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b9d5  be88f84c00             -mov esi, 0x4cf888
    cpu.esi = 5044360 /*0x4cf888*/;
    // 0049b9da  a364f74c00             -mov dword ptr [0x4cf764], eax
    app->getMemory<x86::reg32>(x86::reg32(5044068) /* 0x4cf764 */) = cpu.eax;
    // 0049b9df  e873fdffff             -call 0x49b757
    cpu.esp -= 4;
    sub_49b757(app, cpu);
    if (cpu.terminate) return;
    // 0049b9e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49b9ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b9ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b9ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b9ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b9ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b9f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b9f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b9f4  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049b9f7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049b9f9  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049b9fc  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 0049ba01  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ba04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049ba06:
    // 0049ba06  c1e816                 -shr eax, 0x16
    cpu.eax >>= 22 /*0x16*/ % 32;
    // 0049ba09  3dff010000             +cmp eax, 0x1ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ba0e  0f84de000000           -je 0x49baf2
    if (cpu.flags.zf)
    {
        goto L_0x0049baf2;
    }
    // 0049ba14  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049ba17  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ba1a  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0049ba1d  83ed0a                 -sub ebp, 0xa
    (cpu.ebp) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0049ba20  83fd10                 +cmp ebp, 0x10
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
    // 0049ba23  7d16                   -jge 0x49ba3b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ba3b;
    }
    // 0049ba25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba27  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049ba2c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049ba2f  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ba31  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049ba33  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ba36  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba38  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049ba3b:
    // 0049ba3b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049ba3d:
    // 0049ba3d  c1ea13                 -shr edx, 0x13
    cpu.edx >>= 19 /*0x13*/ % 32;
    // 0049ba40  8b04959cbd5100         -mov eax, dword ptr [edx*4 + 0x51bd9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356956) /* 0x51bd9c */ + cpu.edx * 4);
    // 0049ba47  a900002000             +test eax, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2097152 /*0x200000*/));
    // 0049ba4c  7461                   -je 0x49baaf
    if (cpu.flags.zf)
    {
        goto L_0x0049baaf;
    }
    // 0049ba4e  a900000100             +test eax, 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 65536 /*0x10000*/));
    // 0049ba53  742d                   -je 0x49ba82
    if (cpu.flags.zf)
    {
        goto L_0x0049ba82;
    }
    // 0049ba55  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 0049ba58  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0049ba5b  83fd10                 +cmp ebp, 0x10
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
    // 0049ba5e  7d16                   -jge 0x49ba76
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ba76;
    }
    // 0049ba60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba62  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049ba67  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049ba6a  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ba6c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049ba6e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ba71  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba73  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049ba76:
    // 0049ba76  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ba78  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049ba7b  0d00001000             +or eax, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 0049ba80  eb2d                   -jmp 0x49baaf
    goto L_0x0049baaf;
L_0x0049ba82:
    // 0049ba82  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049ba85  83ed08                 -sub ebp, 8
    (cpu.ebp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ba88  83fd10                 +cmp ebp, 0x10
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
    // 0049ba8b  7d16                   -jge 0x49baa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049baa3;
    }
    // 0049ba8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba8f  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049ba94  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049ba97  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ba99  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049ba9b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ba9e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049baa0  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049baa3:
    // 0049baa3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049baa5  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0049baa8  8b04959c3d5200         -mov eax, dword ptr [edx*4 + 0x523d9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5389724) /* 0x523d9c */ + cpu.edx * 4);
L_0x0049baaf:
    // 0049baaf  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049bab2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bab4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049bab7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049baba  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049babc  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049babe  83fd10                 +cmp ebp, 0x10
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
    // 0049bac1  7d16                   -jge 0x49bad9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bad9;
    }
    // 0049bac3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bac5  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049baca  668b16                 -mov dx, word ptr [esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi);
    // 0049bacd  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049bacf  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049bad1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049bad4  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bad6  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049bad9:
    // 0049bad9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049bade  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049bae0  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bae5  0f8552ffffff           -jne 0x49ba3d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ba3d;
    }
    // 0049baeb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049baed  e914ffffff             -jmp 0x49ba06
    goto L_0x0049ba06;
L_0x0049baf2:
    // 0049baf2  66c70700fe             -mov word ptr [edi], 0xfe00
    app->getMemory<x86::reg16>(cpu.edi) = 65024 /*0xfe00*/;
    // 0049baf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049baf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049baf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bafa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bafb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49bafc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bafc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bafd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bafe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049baff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bb00  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bb01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bb02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049bb04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bb06  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049bb09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bb0b  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 0049bb0e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049bb13  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 0049bb16  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 0049bb1b  f72d9c455200           -imul dword ptr [0x52459c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5391772) /* 0x52459c */))));
    // 0049bb21  a3acf84c00             -mov dword ptr [0x4cf8ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5044396) /* 0x4cf8ac */) = cpu.eax;
    // 0049bb26  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049bb28:
    // 0049bb28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bb2a  668b044e               -mov ax, word ptr [esi + ecx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ecx * 2);
    // 0049bb2e  41                     -inc ecx
    (cpu.ecx)++;
    // 0049bb2f  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bb34  7436                   -je 0x49bb6c
    if (cpu.flags.zf)
    {
        goto L_0x0049bb6c;
    }
    // 0049bb36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bb38  8a9ff4c24c00           -mov bl, byte ptr [edi + 0x4cc2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5030644) /* 0x4cc2f4 */);
    // 0049bb3e  c1ea0a                 +shr edx, 0xa
    {
        x86::reg8 tmp = 10 /*0xa*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049bb41  7412                   -je 0x49bb55
    if (cpu.flags.zf)
    {
        goto L_0x0049bb55;
    }
L_0x0049bb43:
    // 0049bb43  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049bb44  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049bb45  892c9dacf84c00         -mov dword ptr [ebx*4 + 0x4cf8ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5044396) /* 0x4cf8ac */ + cpu.ebx * 4) = cpu.ebp;
    // 0049bb4c  90                     -nop 
    ;
    // 0049bb4d  8a9ff4c24c00           -mov bl, byte ptr [edi + 0x4cc2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5030644) /* 0x4cc2f4 */);
    // 0049bb53  75ee                   -jne 0x49bb43
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb43;
    }
L_0x0049bb55:
    // 0049bb55  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 0049bb58  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 0049bb5b  4f                     -dec edi
    (cpu.edi)--;
    // 0049bb5c  f72c9d9c455200         +imul dword ptr [ebx*4 + 0x52459c]
    {
        cpu.edx_eax = x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5391772) /* 0x52459c */ + cpu.ebx * 4)));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg64>(cpu.edx_eax) != x86::sreg64(static_cast<x86::sreg32>(cpu.eax)));
    }
    // 0049bb63  89049dacf84c00         -mov dword ptr [ebx*4 + 0x4cf8ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5044396) /* 0x4cf8ac */ + cpu.ebx * 4) = cpu.eax;
    // 0049bb6a  ebbc                   -jmp 0x49bb28
    goto L_0x0049bb28;
L_0x0049bb6c:
    // 0049bb6c  8a9ff4c24c00           -mov bl, byte ptr [edi + 0x4cc2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5030644) /* 0x4cc2f4 */);
L_0x0049bb72:
    // 0049bb72  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049bb73  7810                   -js 0x49bb85
    if (cpu.flags.sf)
    {
        goto L_0x0049bb85;
    }
    // 0049bb75  892c9dacf84c00         -mov dword ptr [ebx*4 + 0x4cf8ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5044396) /* 0x4cf8ac */ + cpu.ebx * 4) = cpu.ebp;
    // 0049bb7c  90                     -nop 
    ;
    // 0049bb7d  8a9ff4c24c00           -mov bl, byte ptr [edi + 0x4cc2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5030644) /* 0x4cc2f4 */);
    // 0049bb83  ebed                   -jmp 0x49bb72
    goto L_0x0049bb72;
L_0x0049bb85:
    // 0049bb85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bb87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49bb8e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bb8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bb8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bb90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bb91  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bb92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049bb94  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049bb96  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049bb98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bb9a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bb9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bb9e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bba0  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049bba3  8a9f02010000           -mov bl, byte ptr [edi + 0x102]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(258) /* 0x102 */);
    // 0049bba9  8a4e06                 -mov cl, byte ptr [esi + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049bbac  8a5702                 -mov dl, byte ptr [edi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049bbaf  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbb5  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbbb  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bbbe  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbc4  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bbc7  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbcd  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bbcf  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bbd1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bbd4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bbd6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bbd8  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0049bbdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bbdd  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0049bbe0  8a9f06010000           -mov bl, byte ptr [edi + 0x106]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(262) /* 0x106 */);
    // 0049bbe6  8a4e0e                 -mov cl, byte ptr [esi + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 0049bbe9  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049bbec  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbf2  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bbf8  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bbfb  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc01  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bc04  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc0a  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bc0c  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bc0e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bc11  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc13  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc15  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049bc18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bc1a  8a4612                 -mov al, byte ptr [esi + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0049bc1d  8a9f0a010000           -mov bl, byte ptr [edi + 0x10a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(266) /* 0x10a */);
    // 0049bc23  8a4e16                 -mov cl, byte ptr [esi + 0x16]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0049bc26  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0049bc29  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc2f  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc35  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bc38  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc3e  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bc41  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc47  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bc49  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bc4b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bc4e  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc52  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049bc55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bc57  8a461a                 -mov al, byte ptr [esi + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 0049bc5a  8a9f0e010000           -mov bl, byte ptr [edi + 0x10e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(270) /* 0x10e */);
    // 0049bc60  8a4e1e                 -mov cl, byte ptr [esi + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 0049bc63  8a570e                 -mov dl, byte ptr [edi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0049bc66  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc6c  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc72  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bc75  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc7b  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bc7e  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bc84  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bc86  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bc88  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bc8b  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bc8f  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049bc92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bc94  8a4622                 -mov al, byte ptr [esi + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 0049bc97  8a9f12010000           -mov bl, byte ptr [edi + 0x112]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(274) /* 0x112 */);
    // 0049bc9d  8a4e26                 -mov cl, byte ptr [esi + 0x26]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 0049bca0  8a5712                 -mov dl, byte ptr [edi + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 0049bca3  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bca9  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcaf  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bcb2  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcb8  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bcbb  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcc1  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bcc3  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bcc5  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bcc8  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bcca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bccc  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049bccf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bcd1  8a462a                 -mov al, byte ptr [esi + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 0049bcd4  8a9f16010000           -mov bl, byte ptr [edi + 0x116]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(278) /* 0x116 */);
    // 0049bcda  8a4e2e                 -mov cl, byte ptr [esi + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0049bcdd  8a5716                 -mov dl, byte ptr [edi + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0049bce0  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bce6  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcec  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bcef  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcf5  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bcf8  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bcfe  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bd00  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bd02  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bd05  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd09  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049bd0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bd0e  8a4632                 -mov al, byte ptr [esi + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 0049bd11  8a9f1a010000           -mov bl, byte ptr [edi + 0x11a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(282) /* 0x11a */);
    // 0049bd17  8a4e36                 -mov cl, byte ptr [esi + 0x36]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(54) /* 0x36 */);
    // 0049bd1a  8a571a                 -mov dl, byte ptr [edi + 0x1a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 0049bd1d  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd23  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd29  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bd2c  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd32  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bd35  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd3b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bd3d  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bd3f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bd42  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd44  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd46  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049bd49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bd4b  8a463a                 -mov al, byte ptr [esi + 0x3a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 0049bd4e  8a9f1e010000           -mov bl, byte ptr [edi + 0x11e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(286) /* 0x11e */);
    // 0049bd54  8a4e3e                 -mov cl, byte ptr [esi + 0x3e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 0049bd57  8a571e                 -mov dl, byte ptr [edi + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(30) /* 0x1e */);
    // 0049bd5a  8a809c465200           -mov al, byte ptr [eax + 0x52469c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd60  8a9b9c465200           -mov bl, byte ptr [ebx + 0x52469c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd66  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049bd69  8a899c465200           -mov cl, byte ptr [ecx + 0x52469c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd6f  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bd72  8a929c465200           -mov dl, byte ptr [edx + 0x52469c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */);
    // 0049bd78  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bd7a  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bd7c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049bd7f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd83  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049bd86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bd88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bd89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bd8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bd8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bd8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49bd90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bd90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bd91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bd92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bd93  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bd96  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049bd98  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bd9a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049bd9d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049bd9f  e8bc54ffff             -call 0x491260
    cpu.esp -= 4;
    sub_491260(app, cpu);
    if (cpu.terminate) return;
    // 0049bda4  e8df54ffff             -call 0x491288
    cpu.esp -= 4;
    sub_491288(app, cpu);
    if (cpu.terminate) return;
    // 0049bda9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bdab  7428                   -je 0x49bdd5
    if (cpu.flags.zf)
    {
        goto L_0x0049bdd5;
    }
    // 0049bdad  833d34c34c0000         +cmp dword ptr [0x4cc334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030708) /* 0x4cc334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bdb4  741f                   -je 0x49bdd5
    if (cpu.flags.zf)
    {
        goto L_0x0049bdd5;
    }
    // 0049bdb6  ba01120000             -mov edx, 0x1201
    cpu.edx = 4609 /*0x1201*/;
L_0x0049bdbb:
    // 0049bdbb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049bdbd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bdbf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bdc1  e84ab4faff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0049bdc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bdc8  7512                   -jne 0x49bddc
    if (!cpu.flags.zf)
    {
        goto L_0x0049bddc;
    }
    // 0049bdca  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049bdcc  83c404                 +add esp, 4
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
    // 0049bdcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bdd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bdd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bdd2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049bdd5:
    // 0049bdd5  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 0049bdda  ebdf                   -jmp 0x49bdbb
    goto L_0x0049bdbb;
L_0x0049bddc:
    // 0049bddc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049bdde  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049bde2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049bde4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049bde6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bde8  e8e3b2faff             -call 0x4470d0
    cpu.esp -= 4;
    sub_4470d0(app, cpu);
    if (cpu.terminate) return;
    // 0049bded  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bdef  7417                   -je 0x49be08
    if (cpu.flags.zf)
    {
        goto L_0x0049be08;
    }
    // 0049bdf1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049bdf4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049bdfa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049bdff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049be02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be05  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049be08:
    // 0049be08  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049be0a  e821aafaff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0049be0f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0049be15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049be17  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049be1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be1d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_49be20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be21  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049be23  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049be27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be28  e863ffffff             -call 0x49bd90
    cpu.esp -= 4;
    sub_49bd90(app, cpu);
    if (cpu.terminate) return;
    // 0049be2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be2e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49be34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049be37  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049be3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be3c  e84fffffff             -call 0x49bd90
    cpu.esp -= 4;
    sub_49bd90(app, cpu);
    if (cpu.terminate) return;
    // 0049be41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be42  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49be48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049be4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49be4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be4c  e9dfa9faff             -jmp 0x446830
    return sub_446830(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49be54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049be56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049be57  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049be5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049be5c  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049be60  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049be62  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049be66  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049be68  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049be6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049be6b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049be6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049be6f  e85cb2faff             -call 0x4470d0
    cpu.esp -= 4;
    sub_4470d0(app, cpu);
    if (cpu.terminate) return;
    // 0049be74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049be76  7509                   -jne 0x49be81
    if (!cpu.flags.zf)
    {
        goto L_0x0049be81;
    }
L_0x0049be78:
    // 0049be78  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049be7a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049be7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049be81:
    // 0049be81  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049be84  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049be87  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049be8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049be8d  e88eaefaff             -call 0x446d20
    cpu.esp -= 4;
    sub_446d20(app, cpu);
    if (cpu.terminate) return;
    // 0049be92  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049be96  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049be98  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049be9a  74dc                   -je 0x49be78
    if (cpu.flags.zf)
    {
        goto L_0x0049be78;
    }
    // 0049be9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049be9e  75d8                   -jne 0x49be78
    if (!cpu.flags.zf)
    {
        goto L_0x0049be78;
    }
    // 0049bea0  85ed                   -test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049bea2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bea4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bea7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bea8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bea9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49beac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049beac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bead  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049beb2  e89dffffff             -call 0x49be54
    cpu.esp -= 4;
    sub_49be54(app, cpu);
    if (cpu.terminate) return;
    // 0049beb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49bebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bebc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bebd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bebf  e890ffffff             -call 0x49be54
    cpu.esp -= 4;
    sub_49be54(app, cpu);
    if (cpu.terminate) return;
    // 0049bec4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bec5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bec8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bec9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049becb  e840abfaff             -call 0x446a10
    cpu.esp -= 4;
    sub_446a10(app, cpu);
    if (cpu.terminate) return;
    // 0049bed0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bed2  e889aafaff             -call 0x446960
    cpu.esp -= 4;
    sub_446960(app, cpu);
    if (cpu.terminate) return;
    // 0049bed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bed8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49bedc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bedc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bedd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bedf  e82cabfaff             -call 0x446a10
    cpu.esp -= 4;
    sub_446a10(app, cpu);
    if (cpu.terminate) return;
    // 0049bee4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bee6  e875aafaff             -call 0x446960
    cpu.esp -= 4;
    sub_446960(app, cpu);
    if (cpu.terminate) return;
    // 0049beeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49bef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bef1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bef3  e818abfaff             -call 0x446a10
    cpu.esp -= 4;
    sub_446a10(app, cpu);
    if (cpu.terminate) return;
    // 0049bef8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049befa  e861aafaff             -call 0x446960
    cpu.esp -= 4;
    sub_446960(app, cpu);
    if (cpu.terminate) return;
    // 0049beff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49bf10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf11  8d480c                 -lea ecx, [eax + 0xc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049bf14  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049bf17  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bf19  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0049bf1c  8a482d                 -mov cl, byte ptr [eax + 0x2d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */);
    // 0049bf1f  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0049bf22  8a482f                 -mov cl, byte ptr [eax + 0x2f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 0049bf25  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 0049bf28  8a482e                 -mov cl, byte ptr [eax + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 0049bf2b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0049bf2e  668b4032               -mov ax, word ptr [eax + 0x32]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(50) /* 0x32 */);
    // 0049bf32  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049bf37  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049bf3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bf3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bf40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bf42  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049bf44  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bf4a  7445                   -je 0x49bf91
    if (cpu.flags.zf)
    {
        goto L_0x0049bf91;
    }
    // 0049bf4c  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0049bf50  7449                   -je 0x49bf9b
    if (cpu.flags.zf)
    {
        goto L_0x0049bf9b;
    }
    // 0049bf52  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x0049bf55:
    // 0049bf55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bf56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bf57  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 0049bf5a  c6470100               -mov byte ptr [edi + 1], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 0049bf5e  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0049bf62  c6470300               -mov byte ptr [edi + 3], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 0049bf66  c7470400000000         -mov dword ptr [edi + 4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049bf6d  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bf70  7418                   -je 0x49bf8a
    if (cpu.flags.zf)
    {
        goto L_0x0049bf8a;
    }
L_0x0049bf72:
    // 0049bf72  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049bf74  80fffe                 +cmp bh, 0xfe
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bf77  7411                   -je 0x49bf8a
    if (cpu.flags.zf)
    {
        goto L_0x0049bf8a;
    }
    // 0049bf79  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 0049bf7c  41                     -inc ecx
    (cpu.ecx)++;
    // 0049bf7d  81fefd000000           +cmp esi, 0xfd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bf83  751b                   -jne 0x49bfa0
    if (!cpu.flags.zf)
    {
        goto L_0x0049bfa0;
    }
L_0x0049bf85:
    // 0049bf85  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bf88  75e8                   -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
L_0x0049bf8a:
    // 0049bf8a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049bf8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bf91:
    // 0049bf91  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049bf93  e878ffffff             -call 0x49bf10
    cpu.esp -= 4;
    sub_49bf10(app, cpu);
    if (cpu.terminate) return;
    // 0049bf98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bf9b:
    // 0049bf9b  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049bf9e  ebb5                   -jmp 0x49bf55
    goto L_0x0049bf55;
L_0x0049bfa0:
    // 0049bfa0  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bfa6  74dd                   -je 0x49bf85
    if (cpu.flags.zf)
    {
        goto L_0x0049bf85;
    }
    // 0049bfa8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bfaa  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049bfac  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bfb2  7512                   -jne 0x49bfc6
    if (!cpu.flags.zf)
    {
        goto L_0x0049bfc6;
    }
    // 0049bfb4  41                     -inc ecx
    (cpu.ecx)++;
    // 0049bfb5  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049bfba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bfbc  e86fc1ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049bfc1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049bfc3  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0049bfc6:
    // 0049bfc6  41                     -inc ecx
    (cpu.ecx)++;
    // 0049bfc7  81fe82000000           +cmp esi, 0x82
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bfcd  7313                   -jae 0x49bfe2
    if (!cpu.flags.cf)
    {
        goto L_0x0049bfe2;
    }
    // 0049bfcf  83fe13                 +cmp esi, 0x13
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bfd2  7332                   -jae 0x49c006
    if (!cpu.flags.cf)
    {
        goto L_0x0049c006;
    }
L_0x0049bfd4:
    // 0049bfd4  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bfd6  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bfd9  7597                   -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
    // 0049bfdb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049bfdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfe0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfe1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bfe2:
    // 0049bfe2  7667                   -jbe 0x49c04b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c04b;
    }
    // 0049bfe4  81fe83000000           +cmp esi, 0x83
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bfea  0f8679000000           -jbe 0x49c069
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c069;
    }
    // 0049bff0  81fe84000000           +cmp esi, 0x84
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bff6  75dc                   -jne 0x49bfd4
    if (!cpu.flags.zf)
    {
        goto L_0x0049bfd4;
    }
    // 0049bff8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049bffa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bffc  e82fc1ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049c001  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c004  ebce                   -jmp 0x49bfd4
    goto L_0x0049bfd4;
L_0x0049c006:
    // 0049c006  7626                   -jbe 0x49c02e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c02e;
    }
    // 0049c008  81fe81000000           +cmp esi, 0x81
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c00e  75c4                   -jne 0x49bfd4
    if (!cpu.flags.zf)
    {
        goto L_0x0049bfd4;
    }
    // 0049c010  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c012  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c014  e817c1ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049c019  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049c01c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c01e  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c021  0f854bffffff           -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
    // 0049c027  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c029  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c02a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c02b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c02c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c02d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c02e:
    // 0049c02e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c030  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c032  e8f9c0ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049c037  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049c039  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c03b  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c03e  0f852effffff           -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
    // 0049c044  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c046  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c047  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c049  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c04a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c04b:
    // 0049c04b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c04d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c04f  e8dcc0ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049c054  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0049c057  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c059  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c05c  0f8510ffffff           -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
    // 0049c062  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c064  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c065  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c068  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c069:
    // 0049c069  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c06b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c06d  e8bec0ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0049c072  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0049c075  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c077  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c07a  0f85f2feffff           -jne 0x49bf72
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf72;
    }
    // 0049c080  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c083  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c084  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c085  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c086  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c090  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c091  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c092  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c093  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c096  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049c098  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049c09c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049c0a0  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c0a3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c0a7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c0aa  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049c0ac  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c0ae  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0049c0b4  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c0b6  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c0b8  39d3                   +cmp ebx, edx
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
    // 0049c0ba  7c3c                   -jl 0x49c0f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0bc  3b1de4844c00           +cmp ebx, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0c2  7d34                   -jge 0x49c0f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0c4  3b0de0844c00           +cmp ecx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0ca  7c2c                   -jl 0x49c0f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0cc  3b0de8844c00           +cmp ecx, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0d2  7d24                   -jge 0x49c0f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0d4  3b35dc844c00           +cmp esi, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0da  7c1c                   -jl 0x49c0f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0dc  3b35e4844c00           +cmp esi, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0e2  7d14                   -jge 0x49c0f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0e4  3b3de0844c00           +cmp edi, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0ea  7c0c                   -jl 0x49c0f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c0f8;
    }
    // 0049c0ec  3b3de8844c00           +cmp edi, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0f2  0f8c60010000           -jl 0x49c258
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c258;
    }
L_0x0049c0f8:
    // 0049c0f8  8b15e4844c00           -mov edx, dword ptr [0x4c84e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0049c0fe  39d3                   +cmp ebx, edx
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
    // 0049c100  7c08                   -jl 0x49c10a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c10a;
    }
    // 0049c102  39d6                   +cmp esi, edx
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
    // 0049c104  0f8d5a010000           -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
L_0x0049c10a:
    // 0049c10a  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0049c110  39d3                   +cmp ebx, edx
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
    // 0049c112  7d08                   -jge 0x49c11c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c11c;
    }
    // 0049c114  39d6                   +cmp esi, edx
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
    // 0049c116  0f8c48010000           -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
L_0x0049c11c:
    // 0049c11c  8b15e8844c00           -mov edx, dword ptr [0x4c84e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0049c122  39d1                   +cmp ecx, edx
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
    // 0049c124  7c08                   -jl 0x49c12e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c12e;
    }
    // 0049c126  39d7                   +cmp edi, edx
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
    // 0049c128  0f8d36010000           -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
L_0x0049c12e:
    // 0049c12e  8b15e0844c00           -mov edx, dword ptr [0x4c84e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0049c134  39d1                   +cmp ecx, edx
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
    // 0049c136  7d08                   -jge 0x49c140
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c140;
    }
    // 0049c138  39d7                   +cmp edi, edx
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
    // 0049c13a  0f8c24010000           -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
L_0x0049c140:
    // 0049c140  39f3                   +cmp ebx, esi
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
    // 0049c142  7e0c                   -jle 0x49c150
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c150;
    }
    // 0049c144  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c146  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049c148  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c14a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c14c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049c14e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049c150:
    // 0049c150  8b15dc844c00           -mov edx, dword ptr [0x4c84dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0049c156  39d3                   +cmp ebx, edx
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
    // 0049c158  7d24                   -jge 0x49c17e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c17e;
    }
    // 0049c15a  39f3                   +cmp ebx, esi
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
    // 0049c15c  7420                   -je 0x49c17e
    if (cpu.flags.zf)
    {
        goto L_0x0049c17e;
    }
    // 0049c15e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c160  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c162  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c164  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c166  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c169  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c16b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c16d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c16f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c171  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c174  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c176  8b1ddc844c00           -mov ebx, dword ptr [0x4c84dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0049c17c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c17e:
    // 0049c17e  8b15e4844c00           -mov edx, dword ptr [0x4c84e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0049c184  39d6                   +cmp esi, edx
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
    // 0049c186  7c22                   -jl 0x49c1aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c1aa;
    }
    // 0049c188  39f3                   +cmp ebx, esi
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
    // 0049c18a  741e                   -je 0x49c1aa
    if (cpu.flags.zf)
    {
        goto L_0x0049c1aa;
    }
    // 0049c18c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c18e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c190  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c192  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c194  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c197  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c199  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c19b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c19e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c1a0  8b35e4844c00           -mov esi, dword ptr [0x4c84e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0049c1a6  8d3c08                 -lea edi, [eax + ecx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 0049c1a9  4e                     -dec esi
    (cpu.esi)--;
L_0x0049c1aa:
    // 0049c1aa  39f9                   +cmp ecx, edi
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
    // 0049c1ac  7e0c                   -jle 0x49c1ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c1ba;
    }
    // 0049c1ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c1b0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049c1b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c1b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c1b6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049c1b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049c1ba:
    // 0049c1ba  a1e0844c00             -mov eax, dword ptr [0x4c84e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0049c1bf  39c1                   +cmp ecx, eax
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
    // 0049c1c1  7d22                   -jge 0x49c1e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c1e5;
    }
    // 0049c1c3  39f9                   +cmp ecx, edi
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
    // 0049c1c5  741e                   -je 0x49c1e5
    if (cpu.flags.zf)
    {
        goto L_0x0049c1e5;
    }
    // 0049c1c7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c1c9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1cb  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c1cd  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c1d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c1d2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c1d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c1d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c1db  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c1dd  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0049c1e3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c1e5:
    // 0049c1e5  8b15e8844c00           -mov edx, dword ptr [0x4c84e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0049c1eb  39d7                   +cmp edi, edx
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
    // 0049c1ed  7c1e                   -jl 0x49c20d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c20d;
    }
    // 0049c1ef  39f9                   +cmp ecx, edi
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
    // 0049c1f1  741a                   -je 0x49c20d
    if (cpu.flags.zf)
    {
        goto L_0x0049c20d;
    }
    // 0049c1f3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1f5  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c1f7  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c1fa  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c1fe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c201  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c203  8b3de8844c00           -mov edi, dword ptr [0x4c84e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0049c209  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049c20c  4f                     -dec edi
    (cpu.edi)--;
L_0x0049c20d:
    // 0049c20d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c211  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 0049c214  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0049c216  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c21a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049c21c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c21f  8b2ddc844c00           -mov ebp, dword ptr [0x4c84dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0049c225  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0049c227  39eb                   +cmp ebx, ebp
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
    // 0049c229  7c39                   -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c22b  a1e4844c00             -mov eax, dword ptr [0x4c84e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0049c230  39c3                   +cmp ebx, eax
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
    // 0049c232  7d30                   -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c234  8b15e0844c00           -mov edx, dword ptr [0x4c84e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0049c23a  39d1                   +cmp ecx, edx
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
    // 0049c23c  7c26                   -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c23e  8b1de8844c00           -mov ebx, dword ptr [0x4c84e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0049c244  39d9                   +cmp ecx, ebx
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
    // 0049c246  7d1c                   -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c248  39ee                   +cmp esi, ebp
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
    // 0049c24a  7c18                   -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c24c  39c6                   +cmp esi, eax
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
    // 0049c24e  7d14                   -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c250  39d7                   +cmp edi, edx
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
    // 0049c252  7c10                   -jl 0x49c264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c264;
    }
    // 0049c254  39df                   +cmp edi, ebx
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
    // 0049c256  7d0c                   -jge 0x49c264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c264;
    }
L_0x0049c258:
    // 0049c258  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049c25d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c260  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c261  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c262  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c263  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c264:
    // 0049c264  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c266  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c271  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c272  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c275  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c278  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c27a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c27c  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c282  7c5c                   -jl 0x49c2e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c2e0;
    }
    // 0049c284  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c28a  7d54                   -jge 0x49c2e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c2e0;
    }
    // 0049c28c  3b0de0844c00           +cmp ecx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c292  7c4c                   -jl 0x49c2e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c2e0;
    }
    // 0049c294  3b0de8844c00           +cmp ecx, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c29a  7d44                   -jge 0x49c2e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c2e0;
    }
    // 0049c29c  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0049c2a1  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049c2a4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c2a6  8b1d00854c00           -mov ebx, dword ptr [0x4c8500]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0049c2ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c2af  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049c2b1  8b3483                 -mov esi, dword ptr [ebx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 4);
    // 0049c2b4  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0049c2b9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c2bb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c2bd  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0049c2c2  3c0f                   +cmp al, 0xf
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
    // 0049c2c4  7320                   -jae 0x49c2e6
    if (!cpu.flags.cf)
    {
        goto L_0x0049c2e6;
    }
    // 0049c2c6  3c04                   +cmp al, 4
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
    // 0049c2c8  7216                   -jb 0x49c2e0
    if (cpu.flags.cf)
    {
        goto L_0x0049c2e0;
    }
    // 0049c2ca  7733                   -ja 0x49c2ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049c2ff;
    }
    // 0049c2cc  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 0049c2d0  7435                   -je 0x49c307
    if (cpu.flags.zf)
    {
        goto L_0x0049c307;
    }
    // 0049c2d2  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049c2d4  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049c2d7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0049c2d9  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 0049c2dc  08c6                   -or dh, al
    cpu.dh |= x86::reg8(x86::sreg8(cpu.al));
    // 0049c2de  8831                   -mov byte ptr [ecx], dh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dh;
L_0x0049c2e0:
    // 0049c2e0  83c404                 +add esp, 4
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
    // 0049c2e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c2e6:
    // 0049c2e6  7608                   -jbe 0x49c2f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c2f0;
    }
    // 0049c2e8  3c18                   +cmp al, 0x18
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
    // 0049c2ea  7309                   -jae 0x49c2f5
    if (!cpu.flags.cf)
    {
        goto L_0x0049c2f5;
    }
    // 0049c2ec  3c10                   +cmp al, 0x10
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
    // 0049c2ee  75f0                   -jne 0x49c2e0
    if (!cpu.flags.zf)
    {
        goto L_0x0049c2e0;
    }
L_0x0049c2f0:
    // 0049c2f0  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 0049c2f3  ebeb                   -jmp 0x49c2e0
    goto L_0x0049c2e0;
L_0x0049c2f5:
    // 0049c2f5  761e                   -jbe 0x49c315
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c315;
    }
    // 0049c2f7  3c20                   +cmp al, 0x20
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
    // 0049c2f9  75e5                   -jne 0x49c2e0
    if (!cpu.flags.zf)
    {
        goto L_0x0049c2e0;
    }
    // 0049c2fb  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0049c2fd  ebe1                   -jmp 0x49c2e0
    goto L_0x0049c2e0;
L_0x0049c2ff:
    // 0049c2ff  3c08                   +cmp al, 8
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
    // 0049c301  75dd                   -jne 0x49c2e0
    if (!cpu.flags.zf)
    {
        goto L_0x0049c2e0;
    }
    // 0049c303  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0049c305  ebd9                   -jmp 0x49c2e0
    goto L_0x0049c2e0;
L_0x0049c307:
    // 0049c307  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049c309  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0049c30b  08d0                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 0049c30d  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0049c30f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c314  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c315:
    // 0049c315  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049c31a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c31c  e88a9bffff             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0049c321  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c324  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c325  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c326  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c327(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c327  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c328  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c329  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c32a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c32c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c32e  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0049c333  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049c335  e8857efeff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 0049c33a  eb1f                   -jmp 0x49c35b
    goto L_0x0049c35b;
L_0x0049c33c:
    // 0049c33c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c33e  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0049c340  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049c343  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0049c346  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c34c  8a9298fc4b00           -mov dl, byte ptr [edx + 0x4bfc98]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4979864) /* 0x4bfc98 */);
    // 0049c352  8a3406                 -mov dh, byte ptr [esi + eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 0049c355  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 0049c357  41                     -inc ecx
    (cpu.ecx)++;
    // 0049c358  883406                 -mov byte ptr [esi + eax], dh
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dh;
L_0x0049c35b:
    // 0049c35b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049c35d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0049c35f  75db                   -jne 0x49c33c
    if (!cpu.flags.zf)
    {
        goto L_0x0049c33c;
    }
    // 0049c361  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c363  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c364  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49c366(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c366  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c367  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c36b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049c36d  e8dee0fdff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0049c372  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 0049c374  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049c378  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c37a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c37b  9b                     -wait 
    /*nothing*/;
    // 0049c37c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_49c380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c380  d1fb                   +sar ebx, 1
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
    // 0049c382  e91deeffff             -jmp 0x49b1a4
    return sub_49b1a4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_49c388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c388  01db                   +add ebx, ebx
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
    // 0049c38a  e915eeffff             -jmp 0x49b1a4
    return sub_49b1a4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_49c390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c391  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c393  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049c39a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c39c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c39e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c3a0  e8ffedffff             -call 0x49b1a4
    cpu.esp -= 4;
    sub_49b1a4(app, cpu);
    if (cpu.terminate) return;
    // 0049c3a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c3a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3a8  c1e302                 +shl ebx, 2
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
    // 0049c3ab  e9f4edffff             -jmp 0x49b1a4
    return sub_49b1a4(app, cpu);
}

/* align: skip  */
void Application::sub_49c3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c3b1  b938c34c00             -mov ecx, 0x4cc338
    cpu.ecx = 5030712 /*0x4cc338*/;
    // 0049c3b6  e86168ffff             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0049c3bb  0f77                   -emms 
    cpu.mmx.init();
    // 0049c3bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c3c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c3c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c3c3  b938c34c00             -mov ecx, 0x4cc338
    cpu.ecx = 5030712 /*0x4cc338*/;
    // 0049c3c8  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049c3cb  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049c3ce  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0049c3d1  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0049c3d4  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0049c3d7  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0049c3da  e83d68ffff             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0049c3df  0f77                   -emms 
    cpu.mmx.init();
    // 0049c3e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c3e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c3e9  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049c3ec  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049c3ef  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c3f1  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0049c3f4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049c3f7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c3f9  b938c34c00             -mov ecx, 0x4cc338
    cpu.ecx = 5030712 /*0x4cc338*/;
    // 0049c3fe  e81968ffff             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0049c403  0f77                   -emms 
    cpu.mmx.init();
    // 0049c405  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c406  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c411  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c412  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c413  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c416  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c418  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049c41a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049c41c  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 0049c422  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c424  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049c426  7415                   -je 0x49c43d
    if (cpu.flags.zf)
    {
        goto L_0x0049c43d;
    }
    // 0049c428  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c42b  7d04                   -jge 0x49c431
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c431;
    }
    // 0049c42d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049c42f  7d13                   -jge 0x49c444
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c444;
    }
L_0x0049c431:
    // 0049c431  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0049c436:
    // 0049c436  83c408                 +add esp, 8
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
    // 0049c439  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c43a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c43b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c43c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c43d:
    // 0049c43d  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049c442  ebf2                   -jmp 0x49c436
    goto L_0x0049c436;
L_0x0049c444:
    // 0049c444  e8a784ffff             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 0049c449  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c44b  e8ac88ffff             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0049c450  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c452  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c454  0f8ca9000000           -jl 0x49c503
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c503;
    }
    // 0049c45a  83fb7f                 +cmp ebx, 0x7f
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
    // 0049c45d  0f8fa0000000           -jg 0x49c503
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c503;
    }
    // 0049c463  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c465  0f8c98000000           -jl 0x49c503
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c503;
    }
    // 0049c46b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c46c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c46f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049c471  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049c474  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 0049c479  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c47b  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 0049c47e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049c482  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049c484  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c488  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0049c48b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049c48d  0f8481000000           -je 0x49c514
    if (cpu.flags.zf)
    {
        goto L_0x0049c514;
    }
    // 0049c493  be00845200             -mov esi, 0x528400
    cpu.esi = 5407744 /*0x528400*/;
    // 0049c498  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049c49c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049c49e:
    // 0049c49e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c4a0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c4a4  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 0049c4a7  39d8                   +cmp eax, ebx
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
    // 0049c4a9  7540                   -jne 0x49c4eb
    if (!cpu.flags.zf)
    {
        goto L_0x0049c4eb;
    }
    // 0049c4ab  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c4af  753a                   -jne 0x49c4eb
    if (!cpu.flags.zf)
    {
        goto L_0x0049c4eb;
    }
    // 0049c4b1  833e00                 +cmp dword ptr [esi], 0
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
    // 0049c4b4  7c35                   -jl 0x49c4eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c4eb;
    }
    // 0049c4b6  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0049c4b9  8b5035                 -mov edx, dword ptr [eax + 0x35]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */);
    // 0049c4bc  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049c4bf  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c4c2  884839                 -mov byte ptr [eax + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */) = cpu.cl;
    // 0049c4c5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c4c9  0faf90f4835200         -imul edx, dword ptr [eax + 0x5283f4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407732) /* 0x5283f4 */))));
    // 0049c4d0  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 0049c4d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c4d7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c4da  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c4dc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c4de  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c4e0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049c4e2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c4e4  e8231ffeff             -call 0x47e40c
    cpu.esp -= 4;
    sub_47e40c(app, cpu);
    if (cpu.terminate) return;
    // 0049c4e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049c4eb:
    // 0049c4eb  47                     -inc edi
    (cpu.edi)++;
    // 0049c4ec  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049c4ef  83ff10                 +cmp edi, 0x10
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
    // 0049c4f2  7caa                   -jl 0x49c49e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c49e;
    }
    // 0049c4f4  e80b84ffff             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0049c4f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c4fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c4fc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c4ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c500  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c502  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c503:
    // 0049c503  e8fc83ffff             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0049c508  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049c50d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c510  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c511  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c512  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c513  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c514:
    // 0049c514  884c2839               -mov byte ptr [eax + ebp + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */ + cpu.ebp * 1) = cpu.cl;
    // 0049c518  8b442835               -mov eax, dword ptr [eax + ebp + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */ + cpu.ebp * 1);
    // 0049c51c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049c51f  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c522  8b93f4835200           -mov edx, dword ptr [ebx + 0x5283f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5407732) /* 0x5283f4 */);
    // 0049c528  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c52b  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 0049c530  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c532  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c535  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c537  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c539  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049c53b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c53d  e8ca1efeff             -call 0x47e40c
    cpu.esp -= 4;
    sub_47e40c(app, cpu);
    if (cpu.terminate) return;
    // 0049c542  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c544  e8bb83ffff             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0049c549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c54b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c54c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c54f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c550  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c551  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c563  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c565  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c568  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c56a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049c56d  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 0049c572  8b500e                 -mov edx, dword ptr [eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0049c575  668b5842               -mov bx, word ptr [eax + 0x42]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 0049c579  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049c57c  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 0049c57f  7424                   -je 0x49c5a5
    if (cpu.flags.zf)
    {
        goto L_0x0049c5a5;
    }
    // 0049c581  8b4854                 -mov ecx, dword ptr [eax + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0049c584  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c586  7446                   -je 0x49c5ce
    if (cpu.flags.zf)
    {
        goto L_0x0049c5ce;
    }
    // 0049c588  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c58a  8b5854                 -mov ebx, dword ptr [eax + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0049c58d  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 0049c590  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
L_0x0049c594:
    // 0049c594  8b5840                 -mov ebx, dword ptr [eax + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0049c597  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049c59a  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049c59d  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049c5a0  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 0049c5a3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049c5a5:
    // 0049c5a5  8b585c                 -mov ebx, dword ptr [eax + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0049c5a8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c5aa  741a                   -je 0x49c5c6
    if (cpu.flags.zf)
    {
        goto L_0x0049c5c6;
    }
    // 0049c5ac  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c5ae  8a483f                 -mov cl, byte ptr [eax + 0x3f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */);
    // 0049c5b1  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
    // 0049c5b5  8b583e                 -mov ebx, dword ptr [eax + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 0049c5b8  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049c5bb  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049c5be  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049c5c1  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 0049c5c4  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0049c5c6:
    // 0049c5c6  66895012               -mov word ptr [eax + 0x12], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 0049c5ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c5ce:
    // 0049c5ce  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 0049c5d1  ebc1                   -jmp 0x49c594
    goto L_0x0049c594;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c5e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c5e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c5e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c5e7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049c5e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c5eb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049c5ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c5ef  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049c5f4  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049c5fa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c5fc  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c5ff  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c601  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0049c604  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c608  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c60a  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049c60d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0049c610  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c614  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049c617  0fafef                 -imul ebp, edi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049c61a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c61c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c61e  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 0049c621  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049c627  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c629  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c62b  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049c631  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c633  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c635  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0049c638  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 0049c63b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c63d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c63f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049c642  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0049c645  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0049c648  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c64a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c64c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049c64f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049c651  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049c653  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c655  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c657  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c65b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c65c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c65d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c65f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c663  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c664  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c665  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c666  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c668  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c669  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c66a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c66b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c66e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049c670  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c672  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c674  7c23                   -jl 0x49c699
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c699;
    }
L_0x0049c676:
    // 0049c676  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c678  7d05                   -jge 0x49c67f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c67f;
    }
    // 0049c67a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049c67c  80f301                 -xor bl, 1
    cpu.bl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0049c67f:
    // 0049c67f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c681  e85affffff             -call 0x49c5e0
    cpu.esp -= 4;
    sub_49c5e0(app, cpu);
    if (cpu.terminate) return;
    // 0049c686  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c688  7518                   -jne 0x49c6a2
    if (!cpu.flags.zf)
    {
        goto L_0x0049c6a2;
    }
    // 0049c68a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c68c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049c68e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c68f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c692  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c695  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c696  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c697  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c698  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c699:
    // 0049c699  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c69e  f7d8                   +neg eax
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
    // 0049c6a0  ebd4                   -jmp 0x49c676
    goto L_0x0049c676;
L_0x0049c6a2:
    // 0049c6a2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c6a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c6a7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c6ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c6ac  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c6b0  e833030000             -call 0x49c9e8
    cpu.esp -= 4;
    sub_49c9e8(app, cpu);
    if (cpu.terminate) return;
    // 0049c6b5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c6b7  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049c6b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c6ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c6bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c6bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c6c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c6c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c6c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c6c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c6c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c6c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c6c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c6c9  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c6cd  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c6d1  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c6d5  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0049c6da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049c6dc:
    // 0049c6dc  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049c6de  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049c6df  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c6e1  c1ee1f                 -shr esi, 0x1f
    cpu.esi >>= 31 /*0x1f*/ % 32;
    // 0049c6e4  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c6e6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c6e8  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c6ea  39f8                   +cmp eax, edi
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
    // 0049c6ec  7203                   -jb 0x49c6f1
    if (cpu.flags.cf)
    {
        goto L_0x0049c6f1;
    }
    // 0049c6ee  42                     -inc edx
    (cpu.edx)++;
    // 0049c6ef  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049c6f1:
    // 0049c6f1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c6f3  75e7                   -jne 0x49c6dc
    if (!cpu.flags.zf)
    {
        goto L_0x0049c6dc;
    }
    // 0049c6f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c6f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6fc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c703  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c704  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c708  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c70c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c70e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c710  7c28                   -jl 0x49c73a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c73a;
    }
L_0x0049c712:
    // 0049c712  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c714  7d05                   -jge 0x49c71b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c71b;
    }
    // 0049c716  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049c718  80f201                 -xor dl, 1
    cpu.dl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0049c71b:
    // 0049c71b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c71c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c720  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c721  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c725  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c726  e899ffffff             -call 0x49c6c4
    cpu.esp -= 4;
    sub_49c6c4(app, cpu);
    if (cpu.terminate) return;
    // 0049c72b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c72d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c72f  7402                   -je 0x49c733
    if (cpu.flags.zf)
    {
        goto L_0x0049c733;
    }
    // 0049c731  f7d8                   +neg eax
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
L_0x0049c733:
    // 0049c733  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c734  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c735  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c736  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c737  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049c73a:
    // 0049c73a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c73b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c73c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c73d  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c741  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c742  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c746  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049c74b  e898020000             -call 0x49c9e8
    cpu.esp -= 4;
    sub_49c9e8(app, cpu);
    if (cpu.terminate) return;
    // 0049c750  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c751  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c752  ebbe                   -jmp 0x49c712
    goto L_0x0049c712;
}

/* align: skip  */
void Application::sub_49c754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c754  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c756  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c757  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c758  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c759  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c75a  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c75d  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c761  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c762  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c766  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c767  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c76b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c76c  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c770  e84fffffff             -call 0x49c6c4
    cpu.esp -= 4;
    sub_49c6c4(app, cpu);
    if (cpu.terminate) return;
    // 0049c775  e866feffff             -call 0x49c5e0
    cpu.esp -= 4;
    sub_49c5e0(app, cpu);
    if (cpu.terminate) return;
    // 0049c77a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c77e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c77f  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c783  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c784  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c788  e85b020000             -call 0x49c9e8
    cpu.esp -= 4;
    sub_49c9e8(app, cpu);
    if (cpu.terminate) return;
    // 0049c78d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c791  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c792  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c796  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c797  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c798  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c799  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c79d  e872000000             -call 0x49c814
    cpu.esp -= 4;
    sub_49c814(app, cpu);
    if (cpu.terminate) return;
    // 0049c7a2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c7a6  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c7a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7af  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c7b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c7b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c7b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c7b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c7b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c7b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c7b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c7ba  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c7bd  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c7c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c7c2  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c7c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c7c7  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049c7cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c7cc  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c7d0  e82bffffff             -call 0x49c700
    cpu.esp -= 4;
    sub_49c700(app, cpu);
    if (cpu.terminate) return;
    // 0049c7d5  e88efeffff             -call 0x49c668
    cpu.esp -= 4;
    sub_49c668(app, cpu);
    if (cpu.terminate) return;
    // 0049c7da  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c7de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c7df  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c7e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c7e4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c7e8  e8fb010000             -call 0x49c9e8
    cpu.esp -= 4;
    sub_49c9e8(app, cpu);
    if (cpu.terminate) return;
    // 0049c7ed  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c7f2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049c7f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c7f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c7f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c7f9  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c7fd  e812000000             -call 0x49c814
    cpu.esp -= 4;
    sub_49c814(app, cpu);
    if (cpu.terminate) return;
    // 0049c802  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c806  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c809  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c80f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c814(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c814  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c815  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c816  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c817  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c81a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c81c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c820  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0049c824  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c828  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c82b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c82f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c831  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c835  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c839  3b3424                 +cmp esi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c83c  7711                   -ja 0x49c84f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049c84f;
    }
    // 0049c83e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c840  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c842  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c843  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c844  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c846  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c849  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c84a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c84b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c84c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049c84f:
    // 0049c84f  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 0049c853  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c855  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c857  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c858  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c859  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c85b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c85e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c85f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c860  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c861  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_49c864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c864  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c865  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c866  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c867  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c86a  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c86e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c870  83f820                 +cmp eax, 0x20
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
    // 0049c873  7d46                   -jge 0x49c8bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c8bb;
    }
    // 0049c875  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c877  7458                   -je 0x49c8d1
    if (cpu.flags.zf)
    {
        goto L_0x0049c8d1;
    }
    // 0049c879  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c87a  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c87e  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c880  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049c882  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049c886  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c88a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049c88c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049c891  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c893  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c897  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049c899  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c89b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049c89f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049c8a0:
    // 0049c8a0  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c8a4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x0049c8a6:
    // 0049c8a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c8a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c8a8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c8ac  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c8ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c8af  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c8b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c8b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c8b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049c8bb:
    // 0049c8bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8bd  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049c8c0  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8c3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c8c5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c8c9  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049c8cb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c8cf  ebcf                   -jmp 0x49c8a0
    goto L_0x0049c8a0;
L_0x0049c8d1:
    // 0049c8d1  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c8d5  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c8d9  ebcb                   -jmp 0x49c8a6
    goto L_0x0049c8a6;
}

/* align: skip 0x90 */
void Application::sub_49c8dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c8dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c8dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c8de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8df  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c8e2  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c8e6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c8e8  83f820                 +cmp eax, 0x20
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
    // 0049c8eb  7d4a                   -jge 0x49c937
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c937;
    }
    // 0049c8ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c8ef  745c                   -je 0x49c94d
    if (cpu.flags.zf)
    {
        goto L_0x0049c94d;
    }
    // 0049c8f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c8f2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049c8f7  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c8fb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c8fd  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c901  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049c903  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c905  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0049c907  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049c909  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c90b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049c90f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c911  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c915  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049c917  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c91b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049c91c:
    // 0049c91c  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c920  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x0049c922:
    // 0049c922  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c923  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c924  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c928  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c92a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c92b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c92c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c92e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c931  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c932  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c934  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049c937:
    // 0049c937  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049c93a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c93c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c940  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049c942  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049c944  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c947  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049c94b  ebcf                   -jmp 0x49c91c
    goto L_0x0049c91c;
L_0x0049c94d:
    // 0049c94d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c951  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c955  ebcb                   -jmp 0x49c922
    goto L_0x0049c922;
}

/* align: skip 0x90 */
void Application::sub_49c958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c958  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c959  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c95a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c95b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c95e  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c962  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c964  83f820                 +cmp eax, 0x20
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
    // 0049c967  7d48                   -jge 0x49c9b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c9b1;
    }
    // 0049c969  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c96b  7460                   -je 0x49c9cd
    if (cpu.flags.zf)
    {
        goto L_0x0049c9cd;
    }
    // 0049c96d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c96e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049c973  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c977  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c979  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c97d  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049c97f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c981  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0049c983  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049c985  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c987  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049c98b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c98d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049c991  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049c993  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049c997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049c998:
    // 0049c998  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049c99a  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c99e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c99f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9a0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c9a2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c9a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9a5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c9a8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c9ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9ae  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049c9b1:
    // 0049c9b1  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049c9b4  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049c9b6  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c9ba  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049c9bc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c9c0  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c9c4  c1f81f                 +sar eax, 0x1f
    {
        x86::reg8 tmp = 31 /*0x1f*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0049c9c7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049c9cb  ebcb                   -jmp 0x49c998
    goto L_0x0049c998;
L_0x0049c9cd:
    // 0049c9cd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049c9cf  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c9d3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9d5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049c9d7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c9d9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c9db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c9dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c9e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9e3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c9e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c9e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c9e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c9ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c9eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c9ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c9ed  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c9f0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c9f2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c9f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c9f8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c9fb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049c9fd  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ca01  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049ca04  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ca06  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ca0a  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 0049ca0c  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049ca0f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049ca13  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0049ca16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ca18  7413                   -je 0x49ca2d
    if (cpu.flags.zf)
    {
        goto L_0x0049ca2d;
    }
    // 0049ca1a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049ca1c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ca1e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca1f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ca22  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ca25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca2a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ca2d:
    // 0049ca2d  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049ca30  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049ca34  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049ca36  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ca38  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca39  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca3a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ca3c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ca3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca44  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ca48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ca48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ca49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ca4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ca4b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ca4e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049ca50  83fa20                 +cmp edx, 0x20
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
    // 0049ca53  7d29                   -jge 0x49ca7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ca7e;
    }
    // 0049ca55  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049ca57  7433                   -je 0x49ca8c
    if (cpu.flags.zf)
    {
        goto L_0x0049ca8c;
    }
    // 0049ca59  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0049ca5b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ca5d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049ca5f  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049ca64  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ca66  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049ca68  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x0049ca6b:
    // 0049ca6b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ca6f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049ca71  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ca73  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca74  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca75  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ca77  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ca7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ca7e:
    // 0049ca7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ca80  83ea20                 -sub edx, 0x20
    (cpu.edx) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049ca83  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049ca86  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0049ca88  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049ca8a  ebdf                   -jmp 0x49ca6b
    goto L_0x0049ca6b;
L_0x0049ca8c:
    // 0049ca8c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049ca8f  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 0049ca92  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ca96  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0049ca98  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ca9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca9b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ca9c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ca9e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049caa1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49caa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049caa8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049caa9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049caaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049caab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049caac  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049caaf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cab1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049cab3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cab4  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cab8  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049cabd  e886ffffff             -call 0x49ca48
    cpu.esp -= 4;
    sub_49ca48(app, cpu);
    if (cpu.terminate) return;
    // 0049cac2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cac6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cac7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cacb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cacc  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049cad1  e8defcffff             -call 0x49c7b4
    cpu.esp -= 4;
    sub_49c7b4(app, cpu);
    if (cpu.terminate) return;
    // 0049cad6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cada  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cadb  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049cadd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cadf  e864ffffff             -call 0x49ca48
    cpu.esp -= 4;
    sub_49ca48(app, cpu);
    if (cpu.terminate) return;
    // 0049cae4  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049cae8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cae9  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049caed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049caee  e80dfcffff             -call 0x49c700
    cpu.esp -= 4;
    sub_49c700(app, cpu);
    if (cpu.terminate) return;
    // 0049caf3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049caf6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cafa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49cb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb03  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cb06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cb08  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049cb0a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049cb0c  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cb10  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049cb12  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049cb15  83e13f                 -and ecx, 0x3f
    cpu.ecx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049cb18  e8c3d6feff             -call 0x48a1e0
    cpu.esp -= 4;
    sub_48a1e0(app, cpu);
    if (cpu.terminate) return;
    // 0049cb1d  69c17e480600           -imul eax, ecx, 0x6487e
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0049cb23  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cb27  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 0049cb2a  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049cb2d  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049cb30  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049cb33  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0049cb36  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cb38  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0049cb3a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049cb3d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cb3f  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0049cb42  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049cb45  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cb49  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0049cb4c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cb4e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049cb50  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cb53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49cb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cb60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cb64  81ec44050000           -sub esp, 0x544
    (cpu.esp) -= x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 0049cb6a  899424c4040000         -mov dword ptr [esp + 0x4c4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */) = cpu.edx;
    // 0049cb71  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 0049cb78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cb7a  899424cc040000         -mov dword ptr [esp + 0x4cc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.edx;
    // 0049cb81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb83  0f8437120000           -je 0x49ddc0
    if (cpu.flags.zf)
    {
        goto L_0x0049ddc0;
    }
    // 0049cb89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cb8b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049cb8d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049cb90  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049cb93  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cb95  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cb98  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049cb9f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049cba1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cba3  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0049cbaa  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049cbac  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cbb3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049cbb5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049cbb8  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cbbf  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cbc1  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049cbc4  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049cbcb  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cbd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cbd4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cbd7  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049cbda  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cbe1  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 0049cbe4  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049cbe7  89b424c8040000         -mov dword ptr [esp + 0x4c8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */) = cpu.esi;
    // 0049cbee  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cbf0  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049cbf7  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0049cbfe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cc00  8aa424c9040000         -mov ah, byte ptr [esp + 0x4c9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 0049cc07  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049cc0a  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0049cc0d  0f85e8010000           -jne 0x49cdfb
    if (!cpu.flags.zf)
    {
        goto L_0x0049cdfb;
    }
L_0x0049cc13:
    // 0049cc13  8a9424c9040000         -mov dl, byte ptr [esp + 0x4c9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 0049cc1a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049cc1c  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cc1f  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049cc22  c1ed18                 -shr ebp, 0x18
    cpu.ebp >>= 24 /*0x18*/ % 32;
    // 0049cc25  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049cc28  889424c9040000         -mov byte ptr [esp + 0x4c9], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */) = cpu.dl;
    // 0049cc2f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cc31  0f8c39020000           -jl 0x49ce70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ce70;
    }
L_0x0049cc37:
    // 0049cc37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cc39  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cc3c  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049cc3f  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049cc42  898424cc040000         -mov dword ptr [esp + 0x4cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.eax;
    // 0049cc49  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cc4b  0f8c7d020000           -jl 0x49cece
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cece;
    }
L_0x0049cc51:
    // 0049cc51  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc53  8b8c24cc040000         -mov ecx, dword ptr [esp + 0x4cc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0049cc5a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049cc5d  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cc5f  898c24cc040000         -mov dword ptr [esp + 0x4cc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.ecx;
    // 0049cc66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049cc68  0f85be020000           -jne 0x49cf2c
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf2c;
    }
L_0x0049cc6e:
    // 0049cc6e  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0049cc75  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049cc7c  89842400050000         -mov dword ptr [esp + 0x500], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */) = cpu.eax;
L_0x0049cc83:
    // 0049cc83  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cc85  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049cc88  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0049cc8b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cc90  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cc92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cc94  0f8cce000000           -jl 0x49cd68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd68;
    }
L_0x0049cc9a:
    // 0049cc9a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cc9c  8b8c2400050000         -mov ecx, dword ptr [esp + 0x500]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 0049cca3  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0049cca6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cca8  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049ccaa  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049ccac  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049ccb3  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049ccb5  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 0049ccb7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ccb9  8bac24d4040000         -mov ebp, dword ptr [esp + 0x4d4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049ccc0  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0049ccc3  45                     -inc ebp
    (cpu.ebp)++;
    // 0049ccc4  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0049ccc7  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0049ccce  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ccd0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ccd5  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ccd7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ccd9  0f8c89000000           -jl 0x49cd68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd68;
    }
    // 0049ccdf  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0049cce6  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049cce8  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049ccea  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049ccec  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ccee  45                     -inc ebp
    (cpu.ebp)++;
    // 0049ccef  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0049ccf2  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 0049ccf5  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0049ccf8  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0049ccff  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049cd01  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cd06  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd08  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd0a  7c5c                   -jl 0x49cd68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd68;
    }
    // 0049cd0c  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0049cd13  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049cd15  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049cd17  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049cd19  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cd1b  45                     -inc ebp
    (cpu.ebp)++;
    // 0049cd1c  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0049cd1f  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 0049cd22  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0049cd25  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0049cd2c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049cd2e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cd33  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd35  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd37  7c2f                   -jl 0x49cd68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd68;
    }
    // 0049cd39  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0049cd40  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049cd42  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049cd44  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049cd46  886500                 -mov byte ptr [ebp], ah
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.ah;
    // 0049cd49  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cd4b  45                     -inc ebp
    (cpu.ebp)++;
    // 0049cd4c  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049cd4f  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0049cd56  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0049cd59  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cd5e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd60  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd62  0f8d32ffffff           -jge 0x49cc9a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cc9a;
    }
L_0x0049cd68:
    // 0049cd68  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cd6b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd6d  0f8c420b0000           -jl 0x49d8b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d8b5;
    }
    // 0049cd73  8b842400050000         -mov eax, dword ptr [esp + 0x500]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 0049cd7a  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 0049cd7d  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049cd84  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 0049cd87  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049cd89  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cd90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd92  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0049cd94  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cd9b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049cd9e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cda0  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0049cda7  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cdae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cdb0  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049cdb3  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cdba  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049cdbf  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049cdc2  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049cdc4  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cdc6  8b8424d4040000         -mov eax, dword ptr [esp + 0x4d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049cdcd  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049cdd4  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cddb  40                     -inc eax
    (cpu.eax)++;
    // 0049cddc  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cde3  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 0049cdea  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cded  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049cdef  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 0049cdf6  e988feffff             -jmp 0x49cc83
    goto L_0x0049cc83;
L_0x0049cdfb:
    // 0049cdfb  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049ce02  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce04  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049ce07  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049ce09  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce0b  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ce12  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce14  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049ce17  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049ce1a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce1c  8d7102                 -lea esi, [ecx + 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0049ce1f  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0049ce26  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce28  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049ce2b  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049ce2d  89b42430050000         -mov dword ptr [esp + 0x530], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.esi;
    // 0049ce34  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce36  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049ce38  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ce3f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ce42  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049ce49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce4b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049ce4e  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049ce51  89bc2430050000         -mov dword ptr [esp + 0x530], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edi;
    // 0049ce58  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce5a  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 0049ce5f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049ce61  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ce68  c1e608                 +shl esi, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049ce6b  e9a3fdffff             -jmp 0x49cc13
    goto L_0x0049cc13;
L_0x0049ce70:
    // 0049ce70  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ce77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce79  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ce7b  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049ce82  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049ce85  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce87  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ce8e  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ce95  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce97  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049ce99  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049ce9c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cea3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049cea5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049cea8  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049ceab  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cead  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ceb4  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049cebb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049cebd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cec0  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049cec2  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0049cec9  e969fdffff             -jmp 0x49cc37
    goto L_0x0049cc37;
L_0x0049cece:
    // 0049cece  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ced5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ced7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ced9  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cee0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049cee3  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cee5  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ceec  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cef3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cef5  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049cef7  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049cefa  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cf01  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049cf03  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049cf06  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049cf09  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cf0b  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cf12  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0049cf19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cf1b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cf1e  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049cf20  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 0049cf27  e925fdffff             -jmp 0x49cc51
    goto L_0x0049cc51;
L_0x0049cf2c:
    // 0049cf2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cf2e  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049cf31  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049cf34  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049cf37  88842440050000         -mov byte ptr [esp + 0x540], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */) = cpu.al;
    // 0049cf3e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cf40  0f8ce4030000           -jl 0x49d32a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d32a;
    }
L_0x0049cf46:
    // 0049cf46  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049cf4b  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0049cf50  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049cf52  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049cf57  89ac24e4040000         -mov dword ptr [esp + 0x4e4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebp;
    // 0049cf5e  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 0049cf65  89942418050000         -mov dword ptr [esp + 0x518], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.edx;
    // 0049cf6c  898c241c050000         -mov dword ptr [esp + 0x51c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ecx;
L_0x0049cf73:
    // 0049cf73  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049cf75  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0049cf7c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cf7e  8b94241c050000         -mov edx, dword ptr [esp + 0x51c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0049cf85  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cf87  89841480040000         -mov dword ptr [esp + edx + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.edx * 1) = cpu.eax;
    // 0049cf8e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cf90  0f8cf2030000           -jl 0x49d388
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d388;
    }
    // 0049cf96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cf98  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049cf9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cf9d  0f84be040000           -je 0x49d461
    if (cpu.flags.zf)
    {
        goto L_0x0049d461;
    }
    // 0049cfa3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0049cfa8:
    // 0049cfa8  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cfaa  40                     -inc eax
    (cpu.eax)++;
    // 0049cfab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049cfad  7df9                   -jge 0x49cfa8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cfa8;
    }
    // 0049cfaf  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049cfb2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cfb4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cfb6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cfb8  0f8c40040000           -jl 0x49d3fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d3fe;
    }
L_0x0049cfbe:
    // 0049cfbe  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049cfc5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049cfc8  89942410050000         -mov dword ptr [esp + 0x510], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */) = cpu.edx;
    // 0049cfcf  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049cfd6  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049cfd9  89942428050000         -mov dword ptr [esp + 0x528], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */) = cpu.edx;
    // 0049cfe0  83f810                 +cmp eax, 0x10
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
    // 0049cfe3  0f8ec5050000           -jle 0x49d5ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d5ae;
    }
    // 0049cfe9  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049cfee  8d58f0                 -lea ebx, [eax - 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 0049cff1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cff3  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cff5  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0049cff7  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049cff9  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cffb  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049cffd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cfff  0f8cd9040000           -jl 0x49d4de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d4de;
    }
L_0x0049d005:
    // 0049d005  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049d007  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d00a  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0049d00d  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049d010  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d012  0f8c1e050000           -jl 0x49d536
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d536;
    }
L_0x0049d018:
    // 0049d018  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049d01b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d01d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d022  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049d024:
    // 0049d024  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049d026  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049d028:
    // 0049d028  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d02b  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0049d032  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0049d039  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d03b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d03d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d03f  89940400040000         -mov dword ptr [esp + eax + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1) = cpu.edx;
    // 0049d046  899c24e4040000         -mov dword ptr [esp + 0x4e4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebx;
    // 0049d04d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d04f  7413                   -je 0x49d064
    if (cpu.flags.zf)
    {
        goto L_0x0049d064;
    }
    // 0049d051  8a8c2418050000         -mov cl, byte ptr [esp + 0x518]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0049d058  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049d05a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049d05c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d05e  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x0049d064:
    // 0049d064  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0049d06b  898c0440040000         -mov dword ptr [esp + eax + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 1) = cpu.ecx;
    // 0049d072  8b842418050000         -mov eax, dword ptr [esp + 0x518]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0049d079  48                     -dec eax
    (cpu.eax)--;
    // 0049d07a  8b9c241c050000         -mov ebx, dword ptr [esp + 0x51c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0049d081  89842418050000         -mov dword ptr [esp + 0x518], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.eax;
    // 0049d088  8b8424d8040000         -mov eax, dword ptr [esp + 0x4d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */);
    // 0049d08f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d092  40                     -inc eax
    (cpu.eax)++;
    // 0049d093  899c241c050000         -mov dword ptr [esp + 0x51c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ebx;
    // 0049d09a  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 0049d0a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d0a3  0f84cafeffff           -je 0x49cf73
    if (cpu.flags.zf)
    {
        goto L_0x0049cf73;
    }
    // 0049d0a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d0ab  0f85c2feffff           -jne 0x49cf73
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf73;
    }
    // 0049d0b1  48                     -dec eax
    (cpu.eax)--;
    // 0049d0b2  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0049d0b7  898424dc040000         -mov dword ptr [esp + 0x4dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */) = cpu.eax;
    // 0049d0be  89948440040000         -mov dword ptr [esp + eax*4 + 0x440], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 4) = cpu.edx;
    // 0049d0c5  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049d0ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0049d0cc:
    // 0049d0cc  83c010                 +add eax, 0x10
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d0cf  8948f0                 -mov dword ptr [eax - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0049d0d2  8948f4                 -mov dword ptr [eax - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0049d0d5  8948f8                 -mov dword ptr [eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0049d0d8  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049d0db  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049d0dc  75ee                   -jne 0x49d0cc
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0cc;
    }
    // 0049d0de  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0049d0e0  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0049d0e7  899424e0040000         -mov dword ptr [esp + 0x4e0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.edx;
    // 0049d0ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d0f0  0f8efc000000           -jle 0x49d1f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d1f2;
    }
L_0x0049d0f6:
    // 0049d0f6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d0f8  0f8c30050000           -jl 0x49d62e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d62e;
    }
    // 0049d0fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d100  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0049d103  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d105  0f84f7050000           -je 0x49d702
    if (cpu.flags.zf)
    {
        goto L_0x0049d702;
    }
    // 0049d10b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0049d110:
    // 0049d110  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d112  42                     -inc edx
    (cpu.edx)++;
    // 0049d113  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d115  7df9                   -jge 0x49d110
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d110;
    }
    // 0049d117  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049d11a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d11c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d11e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d120  0f8c7e050000           -jl 0x49d6a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d6a4;
    }
L_0x0049d126:
    // 0049d126  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d12d  8bac2434050000         -mov ebp, dword ptr [esp + 0x534]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d134  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d137  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 0049d13a  898c242c050000         -mov dword ptr [esp + 0x52c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */) = cpu.ecx;
    // 0049d141  83fa10                 +cmp edx, 0x10
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
    // 0049d144  0f8ecf060000           -jle 0x49d819
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d819;
    }
    // 0049d14a  8d4af0                 -lea ecx, [edx - 0x10]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-16) /* -0x10 */);
    // 0049d14d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0049d154  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049d159  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0049d160  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049d162  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0049d164  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0049d16b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d16d  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0049d174  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d176  0f8c03060000           -jl 0x49d77f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d77f;
    }
L_0x0049d17c:
    // 0049d17c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049d17e  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d181  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049d184  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049d187  898c24e8040000         -mov dword ptr [esp + 0x4e8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */) = cpu.ecx;
    // 0049d18e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d190  0f8c29060000           -jl 0x49d7bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d7bf;
    }
L_0x0049d196:
    // 0049d196  8b8c24e8040000         -mov ecx, dword ptr [esp + 0x4e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */);
    // 0049d19d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049d1a0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049d1a2:
    // 0049d1a2  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0049d1a4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049d1a9  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049d1ab  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049d1ad:
    // 0049d1ad  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d1b0  43                     -inc ebx
    (cpu.ebx)++;
    // 0049d1b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049d1b3:
    // 0049d1b3  fec0                   -inc al
    (cpu.al)++;
    // 0049d1b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d1b7  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049d1b9  3a0c14                 +cmp cl, byte ptr [esp + edx]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d1bc  7501                   -jne 0x49d1bf
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1bf;
    }
    // 0049d1be  4b                     -dec ebx
    (cpu.ebx)--;
L_0x0049d1bf:
    // 0049d1bf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d1c1  75f0                   -jne 0x49d1b3
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1b3;
    }
    // 0049d1c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d1c5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049d1c7  c6041401               -mov byte ptr [esp + edx], 1
    app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1) = 1 /*0x1*/;
    // 0049d1cb  8b9424e0040000         -mov edx, dword ptr [esp + 0x4e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */);
    // 0049d1d2  8b8c24e4040000         -mov ecx, dword ptr [esp + 0x4e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0049d1d9  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d1dc  88841400030000         -mov byte ptr [esp + edx + 0x300], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.edx * 1) = cpu.al;
    // 0049d1e3  89ac24e0040000         -mov dword ptr [esp + 0x4e0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.ebp;
    // 0049d1ea  39cd                   +cmp ebp, ecx
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
    // 0049d1ec  0f8c04ffffff           -jl 0x49d0f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d0f6;
    }
L_0x0049d1f2:
    // 0049d1f2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049d1f7  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049d1fe  bb40404040             -mov ebx, 0x40404040
    cpu.ebx = 1077952576 /*0x40404040*/;
L_0x0049d203:
    // 0049d203  83c210                 +add edx, 0x10
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
    // 0049d206  895af0                 -mov dword ptr [edx - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0049d209  895af4                 -mov dword ptr [edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049d20c  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0049d20f  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0049d212  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049d213  75ee                   -jne 0x49d203
    if (!cpu.flags.zf)
    {
        goto L_0x0049d203;
    }
    // 0049d215  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0049d21c  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0049d223  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049d22a  898424fc040000         -mov dword ptr [esp + 0x4fc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.eax;
    // 0049d231  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d236  8b8c24dc040000         -mov ecx, dword ptr [esp + 0x4dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 0049d23d  898424ec040000         -mov dword ptr [esp + 0x4ec], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.eax;
    // 0049d244  39c1                   +cmp ecx, eax
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
    // 0049d246  0f8c22faffff           -jl 0x49cc6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cc6e;
    }
    // 0049d24c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049d251  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0049d256  89842420050000         -mov dword ptr [esp + 0x520], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.eax;
    // 0049d25d  898c2424050000         -mov dword ptr [esp + 0x524], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.ecx;
L_0x0049d264:
    // 0049d264  8b842420050000         -mov eax, dword ptr [esp + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 0049d26b  8b840400040000         -mov eax, dword ptr [esp + eax + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1);
    // 0049d272  8bac24ec040000         -mov ebp, dword ptr [esp + 0x4ec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0049d279  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 0049d280  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d283  0f8de5f9ffff           -jge 0x49cc6e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cc6e;
    }
    // 0049d289  8a8c2424050000         -mov cl, byte ptr [esp + 0x524]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 0049d290  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049d295  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
L_0x0049d297:
    // 0049d297  8b8424f0040000         -mov eax, dword ptr [esp + 0x4f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */);
    // 0049d29e  48                     -dec eax
    (cpu.eax)--;
    // 0049d29f  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 0049d2a6  83f8ff                 +cmp eax, -1
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
    // 0049d2a9  0f84c3050000           -je 0x49d872
    if (cpu.flags.zf)
    {
        goto L_0x0049d872;
    }
    // 0049d2af  8b8c24fc040000         -mov ecx, dword ptr [esp + 0x4fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */);
    // 0049d2b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d2b8  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d2ba  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d2bb  898424f4040000         -mov dword ptr [esp + 0x4f4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */) = cpu.eax;
    // 0049d2c2  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0049d2c9  898c24fc040000         -mov dword ptr [esp + 0x4fc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.ecx;
    // 0049d2d0  898424f8040000         -mov dword ptr [esp + 0x4f8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = cpu.eax;
    // 0049d2d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d2d9  8b8c24f4040000         -mov ecx, dword ptr [esp + 0x4f4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 0049d2e0  8a842440050000         -mov al, byte ptr [esp + 0x540]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 0049d2e7  39c8                   +cmp eax, ecx
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
    // 0049d2e9  7519                   -jne 0x49d304
    if (!cpu.flags.zf)
    {
        goto L_0x0049d304;
    }
    // 0049d2eb  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0049d2f2  898424d0040000         -mov dword ptr [esp + 0x4d0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */) = cpu.eax;
    // 0049d2f9  c78424f804000060000000 -mov dword ptr [esp + 0x4f8], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = 96 /*0x60*/;
L_0x0049d304:
    // 0049d304  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d306  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d308  7e8d                   -jle 0x49d297
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d297;
    }
L_0x0049d30a:
    // 0049d30a  43                     -inc ebx
    (cpu.ebx)++;
    // 0049d30b  8a8c24f4040000         -mov cl, byte ptr [esp + 0x4f4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 0049d312  42                     -inc edx
    (cpu.edx)++;
    // 0049d313  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049d316  8a8c24f8040000         -mov cl, byte ptr [esp + 0x4f8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1272) /* 0x4f8 */);
    // 0049d31d  40                     -inc eax
    (cpu.eax)++;
    // 0049d31e  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049d321  39e8                   +cmp eax, ebp
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
    // 0049d323  7ce5                   -jl 0x49d30a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d30a;
    }
    // 0049d325  e96dffffff             -jmp 0x49d297
    goto L_0x0049d297;
L_0x0049d32a:
    // 0049d32a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d331  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d333  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d335  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d33c  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d343  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049d346  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d348  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d34a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d351  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049d358  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d35a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d35c  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d35f  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d366  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d369  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049d36c  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d36f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d371  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0049d378  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d37a  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049d381  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d383  e9befbffff             -jmp 0x49cf46
    goto L_0x0049cf46;
L_0x0049d388:
    // 0049d388  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d38a  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049d38d  c1ea1d                 -shr edx, 0x1d
    cpu.edx >>= 29 /*0x1d*/ % 32;
    // 0049d390  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0049d393  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d395  0f8d8dfcffff           -jge 0x49d028
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d028;
    }
    // 0049d39b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d3a2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d3a4  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d3a6  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d3ad  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049d3b0  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3b2  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d3b9  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d3c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d3c2  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d3c5  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d3cc  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049d3cf  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3d1  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d3d8  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d3df  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d3e6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d3e8  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d3eb  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d3ed  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0049d3f4  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d3f7  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d3f9  e92afcffff             -jmp 0x49d028
    goto L_0x0049d028;
L_0x0049d3fe:
    // 0049d3fe  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d405  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d407  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d409  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d410  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d413  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d415  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d41c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d423  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d425  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d428  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d42f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d436  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d439  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d43c  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d43e  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0049d445  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d44c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d44e  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d455  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d457  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d45a  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d45c  e95dfbffff             -jmp 0x49cfbe
    goto L_0x0049cfbe;
L_0x0049d461:
    // 0049d461  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0049d466:
    // 0049d466  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d468  40                     -inc eax
    (cpu.eax)++;
    // 0049d469  4f                     -dec edi
    (cpu.edi)--;
    // 0049d46a  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0049d46d  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d46f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d471  7c09                   -jl 0x49d47c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d47c;
    }
    // 0049d473  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d475  74ef                   -je 0x49d466
    if (cpu.flags.zf)
    {
        goto L_0x0049d466;
    }
    // 0049d477  e942fbffff             -jmp 0x49cfbe
    goto L_0x0049cfbe;
L_0x0049d47c:
    // 0049d47c  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d483  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d485  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049d487  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d48e  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049d491  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d493  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d49a  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d4a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d4a3  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049d4a6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d4ad  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d4b0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d4b2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d4b4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d4b6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d4b8  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d4ba  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d4c1  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d4c8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d4cb  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d4ce  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d4d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d4d7  748d                   -je 0x49d466
    if (cpu.flags.zf)
    {
        goto L_0x0049d466;
    }
    // 0049d4d9  e9e0faffff             -jmp 0x49cfbe
    goto L_0x0049cfbe;
L_0x0049d4de:
    // 0049d4de  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d4e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d4e7  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049d4e9  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 0049d4f0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d4f2  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d4f9  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d500  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d502  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049d505  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d50c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d50f  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d511  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d513  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d515  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d517  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d51e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d520  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 0049d527  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d52a  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d531  e9cffaffff             -jmp 0x49d005
    goto L_0x0049d005;
L_0x0049d536:
    // 0049d536  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d53d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d53f  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d541  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0049d548  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d54f  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0049d556  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d559  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d55b  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d562  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d569  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d56b  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d56e  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0049d575  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d57c  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0049d583  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d586  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d588  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d58a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d58c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d593  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d595  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d59c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d59f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d5a2  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d5a9  e96afaffff             -jmp 0x49d018
    goto L_0x0049d018;
L_0x0049d5ae:
    // 0049d5ae  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049d5b3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d5b5  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d5b7  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0049d5b9  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d5bb  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d5bd  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d5bf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d5c1  7c0c                   -jl 0x49d5cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d5cf;
    }
    // 0049d5c3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d5c5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d5ca  e955faffff             -jmp 0x49d024
    goto L_0x0049d024;
L_0x0049d5cf:
    // 0049d5cf  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d5d6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d5d8  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049d5da  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 0049d5e1  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d5e3  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d5ea  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d5f1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d5f3  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049d5f6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d5fd  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d600  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d602  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d604  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d606  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d608  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d60f  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d611  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 0049d618  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d61b  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d622  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d624  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d629  e9f6f9ffff             -jmp 0x49d024
    goto L_0x0049d024;
L_0x0049d62e:
    // 0049d62e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049d630  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049d633  c1eb1d                 -shr ebx, 0x1d
    cpu.ebx >>= 29 /*0x1d*/ % 32;
    // 0049d636  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0049d639  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d63b  0f8d6cfbffff           -jge 0x49d1ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d1ad;
    }
    // 0049d641  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d648  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d64a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d64c  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d653  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d656  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d658  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d65f  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d666  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d668  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d66b  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d672  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d679  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d67c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d67f  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d681  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049d688  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d68f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d691  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d698  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d69a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d69d  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d69f  e909fbffff             -jmp 0x49d1ad
    goto L_0x0049d1ad;
L_0x0049d6a4:
    // 0049d6a4  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d6ab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d6ad  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049d6af  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d6b6  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049d6b9  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d6bb  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d6c2  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d6c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d6cb  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049d6ce  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d6d5  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d6dc  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d6df  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d6e2  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d6e4  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049d6eb  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d6f2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d6f4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d6f6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d6f8  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d6fb  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d6fd  e924faffff             -jmp 0x49d126
    goto L_0x0049d126;
L_0x0049d702:
    // 0049d702  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0049d707:
    // 0049d707  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049d709  42                     -inc edx
    (cpu.edx)++;
    // 0049d70a  4f                     -dec edi
    (cpu.edi)--;
    // 0049d70b  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 0049d70e  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d710  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d712  7c09                   -jl 0x49d71d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d71d;
    }
    // 0049d714  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d716  74ef                   -je 0x49d707
    if (cpu.flags.zf)
    {
        goto L_0x0049d707;
    }
    // 0049d718  e909faffff             -jmp 0x49d126
    goto L_0x0049d126;
L_0x0049d71d:
    // 0049d71d  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d724  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d726  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d728  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d72f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d732  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d734  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d73b  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d742  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d744  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049d747  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d74e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d751  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d753  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0049d75a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d75c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d75e  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d765  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d767  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d76a  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d76d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d76f  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0049d776  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d778  748d                   -je 0x49d707
    if (cpu.flags.zf)
    {
        goto L_0x0049d707;
    }
    // 0049d77a  e9a7f9ffff             -jmp 0x49d126
    goto L_0x0049d126;
L_0x0049d77f:
    // 0049d77f  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d786  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d788  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d78a  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049d78c  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049d790  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d797  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d79a  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d79c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d79e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d7a0  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d7a7  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d7a9  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 0049d7b0  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d7b3  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d7ba  e9bdf9ffff             -jmp 0x49d17c
    goto L_0x0049d17c;
L_0x0049d7bf:
    // 0049d7bf  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d7c6  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d7cd  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d7d0  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0049d7d3  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d7d5  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d7dc  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d7e3  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d7e6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d7ed  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d7f4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d7f7  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049d7fb  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049d802  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d804  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d806  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d80d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d80f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d812  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d814  e97df9ffff             -jmp 0x49d196
    goto L_0x0049d196;
L_0x0049d819:
    // 0049d819  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049d81e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049d820  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d822  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0049d824  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0049d826  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d828  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d82a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d82c  0f8d70f9ffff           -jge 0x49d1a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d1a2;
    }
    // 0049d832  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d839  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d83b  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d83d  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049d83f  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049d843  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d84a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d84d  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d84f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d851  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d853  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049d85a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d85c  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 0049d863  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d866  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049d86d  e930f9ffff             -jmp 0x49d1a2
    goto L_0x0049d1a2;
L_0x0049d872:
    // 0049d872  8bac2420050000         -mov ebp, dword ptr [esp + 0x520]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 0049d879  8b842424050000         -mov eax, dword ptr [esp + 0x524]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 0049d880  8b8c24ec040000         -mov ecx, dword ptr [esp + 0x4ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0049d887  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d88a  48                     -dec eax
    (cpu.eax)--;
    // 0049d88b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d88c  89ac2420050000         -mov dword ptr [esp + 0x520], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.ebp;
    // 0049d893  89842424050000         -mov dword ptr [esp + 0x524], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.eax;
    // 0049d89a  8bac24dc040000         -mov ebp, dword ptr [esp + 0x4dc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 0049d8a1  898c24ec040000         -mov dword ptr [esp + 0x4ec], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.ecx;
    // 0049d8a8  39e9                   +cmp ecx, ebp
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
    // 0049d8aa  0f8eb4f9ffff           -jle 0x49d264
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d264;
    }
    // 0049d8b0  e9b9f3ffff             -jmp 0x49cc6e
    goto L_0x0049cc6e;
L_0x0049d8b5:
    // 0049d8b5  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d8b8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d8ba  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d8bd  7468                   -je 0x49d927
    if (cpu.flags.zf)
    {
        goto L_0x0049d927;
    }
    // 0049d8bf  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0049d8c4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d8c6  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049d8cb  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
L_0x0049d8ce:
    // 0049d8ce  8bac0c44040000         -mov ebp, dword ptr [esp + ecx + 0x444]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1092) /* 0x444 */ + cpu.ecx * 1);
    // 0049d8d5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d8d8  40                     -inc eax
    (cpu.eax)++;
    // 0049d8d9  39ea                   +cmp edx, ebp
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
    // 0049d8db  73f1                   -jae 0x49d8ce
    if (!cpu.flags.cf)
    {
        goto L_0x0049d8ce;
    }
L_0x0049d8dd:
    // 0049d8dd  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049d8e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d8e4  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d8e6  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0049d8e8  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d8ea  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d8ec  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049d8ee  8b8c8480040000         -mov ecx, dword ptr [esp + eax*4 + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.eax * 4);
    // 0049d8f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d8f7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d8f9  8a942440050000         -mov dl, byte ptr [esp + 0x540]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 0049d900  8a840400030000         -mov al, byte ptr [esp + eax + 0x300]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.eax * 1);
    // 0049d907  38d0                   +cmp al, dl
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
    // 0049d909  7425                   -je 0x49d930
    if (cpu.flags.zf)
    {
        goto L_0x0049d930;
    }
    // 0049d90b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d90d  7c21                   -jl 0x49d930
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d930;
    }
    // 0049d90f  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049d916  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049d918  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d91b  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 0049d922  e95cf3ffff             -jmp 0x49cc83
    goto L_0x0049cc83;
L_0x0049d927:
    // 0049d927  8b8424d0040000         -mov eax, dword ptr [esp + 0x4d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */);
    // 0049d92e  ebad                   -jmp 0x49d8dd
    goto L_0x0049d8dd;
L_0x0049d930:
    // 0049d930  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d932  7c21                   -jl 0x49d955
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d955;
    }
L_0x0049d934:
    // 0049d934  3a842440050000         +cmp al, byte ptr [esp + 0x540]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d93b  747b                   -je 0x49d9b8
    if (cpu.flags.zf)
    {
        goto L_0x0049d9b8;
    }
    // 0049d93d  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049d944  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d947  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049d949  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0049d950  e92ef3ffff             -jmp 0x49cc83
    goto L_0x0049cc83;
L_0x0049d955:
    // 0049d955  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d95c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d95e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d960  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d967  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d96a  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d96c  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d973  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d97a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d97c  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d97f  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d986  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049d98d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d990  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d993  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d995  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049d99c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049d9a3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049d9a5  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d9ac  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049d9ae  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d9b1  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049d9b3  e97cffffff             -jmp 0x49d934
    goto L_0x0049d934;
L_0x0049d9b8:
    // 0049d9b8  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049d9bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d9c1  0f8cf7000000           -jl 0x49dabe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dabe;
    }
    // 0049d9c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d9c9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049d9cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d9ce  0f84c9010000           -je 0x49db9d
    if (cpu.flags.zf)
    {
        goto L_0x0049db9d;
    }
    // 0049d9d4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0049d9d9:
    // 0049d9d9  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d9db  40                     -inc eax
    (cpu.eax)++;
    // 0049d9dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d9de  7df9                   -jge 0x49d9d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d9d9;
    }
    // 0049d9e0  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049d9e3  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d9e5  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d9e7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d9e9  0f8c5a010000           -jl 0x49db49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049db49;
    }
L_0x0049d9ef:
    // 0049d9ef  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049d9f6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049d9f9  898c2414050000         -mov dword ptr [esp + 0x514], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */) = cpu.ecx;
    // 0049da00  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049da07  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049da0a  898c24c0040000         -mov dword ptr [esp + 0x4c0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */) = cpu.ecx;
    // 0049da11  83f810                 +cmp eax, 0x10
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
    // 0049da14  0f8ec6020000           -jle 0x49dce0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049dce0;
    }
    // 0049da1a  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 0049da1d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0049da24  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049da29  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0049da30  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049da32  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 0049da34  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0049da3b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049da3d  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0049da44  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 0049da4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049da4d  0f8cd6010000           -jl 0x49dc29
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dc29;
    }
L_0x0049da53:
    // 0049da53  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049da55  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049da58  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049da5b  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0049da5e  898c2408050000         -mov dword ptr [esp + 0x508], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */) = cpu.ecx;
    // 0049da65  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049da67  0f8c11020000           -jl 0x49dc7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dc7e;
    }
L_0x0049da6d:
    // 0049da6d  8b8c2404050000         -mov ecx, dword ptr [esp + 0x504]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 0049da74  8bac2408050000         -mov ebp, dword ptr [esp + 0x508]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */);
    // 0049da7b  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049da7e  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049da80  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049da82  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049da87  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049da89  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049da8b:
    // 0049da8b  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049da8e  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
L_0x0049da95:
    // 0049da95  8bac2404050000         -mov ebp, dword ptr [esp + 0x504]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 0049da9c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049da9e  0f84c7020000           -je 0x49dd6b
    if (cpu.flags.zf)
    {
        goto L_0x0049dd6b;
    }
    // 0049daa4  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049daa7  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x0049daaa:
    // 0049daaa  42                     -inc edx
    (cpu.edx)++;
    // 0049daab  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049daae  39c2                   +cmp edx, eax
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
    // 0049dab0  72f8                   -jb 0x49daaa
    if (cpu.flags.cf)
    {
        goto L_0x0049daaa;
    }
    // 0049dab2  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 0049dab9  e9c5f1ffff             -jmp 0x49cc83
    goto L_0x0049cc83;
L_0x0049dabe:
    // 0049dabe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dac0  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049dac3  c1e81d                 -shr eax, 0x1d
    cpu.eax >>= 29 /*0x1d*/ % 32;
    // 0049dac6  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0049dac9  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
    // 0049dad0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049dad2  7c0a                   -jl 0x49dade
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dade;
    }
    // 0049dad4  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049dadc  ebb7                   -jmp 0x49da95
    goto L_0x0049da95;
L_0x0049dade:
    // 0049dade  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dae5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dae7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049dae9  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049daf0  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049daf3  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049daf5  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0049dafc  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049db03  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049db05  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049db08  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049db0f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049db12  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db14  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049db1b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049db22  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049db29  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049db2b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049db2e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049db30  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0049db37  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049db3a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049db3c  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049db44  e94cffffff             -jmp 0x49da95
    goto L_0x0049da95;
L_0x0049db49:
    // 0049db49  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049db50  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049db52  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049db54  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049db5b  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049db62  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049db65  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049db68  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049db6a  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049db71  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049db78  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049db7b  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049db7f  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049db86  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049db88  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049db8a  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049db91  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049db93  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049db96  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049db98  e952feffff             -jmp 0x49d9ef
    goto L_0x0049d9ef;
L_0x0049db9d:
    // 0049db9d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049dba2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049dba4:
    // 0049dba4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049dba6  40                     -inc eax
    (cpu.eax)++;
    // 0049dba7  4f                     -dec edi
    (cpu.edi)--;
    // 0049dba8  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0049dbab  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049dbad  898c2438050000         -mov dword ptr [esp + 0x538], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */) = cpu.ecx;
    // 0049dbb4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049dbb6  7c0e                   -jl 0x49dbc6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dbc6;
    }
    // 0049dbb8  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dbbf  74e3                   -je 0x49dba4
    if (cpu.flags.zf)
    {
        goto L_0x0049dba4;
    }
    // 0049dbc1  e929feffff             -jmp 0x49d9ef
    goto L_0x0049d9ef;
L_0x0049dbc6:
    // 0049dbc6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dbcd  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dbd4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049dbd7  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0049dbda  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dbdc  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dbe3  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dbea  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dbf1  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049dbf4  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049dbf8  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dbfa  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049dbfc  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dbfe  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dc05  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049dc07  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dc0e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049dc11  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049dc14  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049dc1b  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dc22  7480                   -je 0x49dba4
    if (cpu.flags.zf)
    {
        goto L_0x0049dba4;
    }
    // 0049dc24  e9c6fdffff             -jmp 0x49d9ef
    goto L_0x0049d9ef;
L_0x0049dc29:
    // 0049dc29  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dc30  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dc32  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049dc34  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 0049dc3b  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dc3d  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dc44  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dc4b  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dc52  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049dc55  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0049dc59  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dc5b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049dc5d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dc5f  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dc66  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049dc68  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 0049dc6f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049dc72  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049dc79  e9d5fdffff             -jmp 0x49da53
    goto L_0x0049da53;
L_0x0049dc7e:
    // 0049dc7e  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dc85  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dc8c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049dc8f  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0049dc92  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dc94  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dc9b  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dca2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dca4  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049dca7  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dcae  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dcb5  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049dcb8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049dcbb  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049dcbd  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0049dcc4  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049dccb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049dccd  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dcd4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dcd6  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049dcd9  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049dcdb  e98dfdffff             -jmp 0x49da6d
    goto L_0x0049da6d;
L_0x0049dce0:
    // 0049dce0  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0049dce5  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049dce7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dce9  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dceb  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 0049dced  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049dcef  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 0049dcf6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049dcf8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049dcfa  7c15                   -jl 0x49dd11
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049dd11;
    }
L_0x0049dcfc:
    // 0049dcfc  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049dcfe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049dd03  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049dd05  03842404050000         +add eax, dword ptr [esp + 0x504]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049dd0c  e97afdffff             -jmp 0x49da8b
    goto L_0x0049da8b;
L_0x0049dd11:
    // 0049dd11  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dd18  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd1a  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049dd1c  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 0049dd23  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd25  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0049dd2c  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049dd33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049dd35  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049dd38  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dd3f  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049dd42  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049dd44  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0049dd4b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049dd4d  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dd54  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dd56  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049dd58  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 0049dd5f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049dd62  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0049dd69  eb91                   -jmp 0x49dcfc
    goto L_0x0049dcfc;
L_0x0049dd6b:
    // 0049dd6b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049dd6d  4f                     -dec edi
    (cpu.edi)--;
    // 0049dd6e  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 0049dd71  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049dd73  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049dd75  7c5b                   -jl 0x49ddd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ddd2;
    }
L_0x0049dd77:
    // 0049dd77  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049dd79  0f84b1000000           -je 0x49de30
    if (cpu.flags.zf)
    {
        goto L_0x0049de30;
    }
    // 0049dd7f  8bbc24c4040000         -mov edi, dword ptr [esp + 0x4c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 0049dd86  8b9c24cc040000         -mov ebx, dword ptr [esp + 0x4cc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0049dd8d  8bb424c8040000         -mov esi, dword ptr [esp + 0x4c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */);
    // 0049dd94  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dd96  81fefb320000           +cmp esi, 0x32fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13051 /*0x32fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dd9c  0f851e010000           -jne 0x49dec0
    if (!cpu.flags.zf)
    {
        goto L_0x0049dec0;
    }
    // 0049dda2  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 0049dda9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049ddab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ddad  39c7                   +cmp edi, eax
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
    // 0049ddaf  760f                   -jbe 0x49ddc0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049ddc0;
    }
L_0x0049ddb1:
    // 0049ddb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ddb3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ddb5  40                     -inc eax
    (cpu.eax)++;
    // 0049ddb6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ddb8  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049ddbb  39d8                   +cmp eax, ebx
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
    // 0049ddbd  72f2                   -jb 0x49ddb1
    if (cpu.flags.cf)
    {
        goto L_0x0049ddb1;
    }
    // 0049ddbf  90                     -nop 
    ;
L_0x0049ddc0:
    // 0049ddc0  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0049ddc7  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 0049ddcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ddd2:
    // 0049ddd2  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ddd9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dddb  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dddd  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049dde4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049dde7  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dde9  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049ddf0  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049ddf7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ddf9  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049ddfb  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049ddfe  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049de05  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049de07  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049de0a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049de0d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049de0f  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049de16  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049de1d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049de1f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049de22  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049de24  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0049de2b  e947ffffff             -jmp 0x49dd77
    goto L_0x0049dd77;
L_0x0049de30:
    // 0049de30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049de32  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049de35  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0049de38  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0049de3b  8884243c050000         -mov byte ptr [esp + 0x53c], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */) = cpu.al;
    // 0049de42  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049de44  7c1f                   -jl 0x49de65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049de65;
    }
L_0x0049de46:
    // 0049de46  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0049de4d  8a84243c050000         -mov al, byte ptr [esp + 0x53c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */);
    // 0049de54  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049de57  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049de59  898c24d4040000         -mov dword ptr [esp + 0x4d4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ecx;
    // 0049de60  e91eeeffff             -jmp 0x49cc83
    goto L_0x0049cc83;
L_0x0049de65:
    // 0049de65  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049de6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049de6e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049de70  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049de77  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049de7a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049de7c  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049de83  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049de8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049de8c  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049de8f  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0049de96  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049de99  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049de9b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049de9d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049de9f  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0049dea6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049dea8  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0049deaf  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049deb2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049deb5  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049deb7  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 0049debe  eb86                   -jmp 0x49de46
    goto L_0x0049de46;
L_0x0049dec0:
    // 0049dec0  81fefb340000           +cmp esi, 0x34fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13563 /*0x34fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dec6  0f85f4feffff           -jne 0x49ddc0
    if (!cpu.flags.zf)
    {
        goto L_0x0049ddc0;
    }
    // 0049decc  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 0049ded3  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0049ded5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ded7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ded9  39c7                   +cmp edi, eax
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
    // 0049dedb  0f86dffeffff           -jbe 0x49ddc0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049ddc0;
    }
L_0x0049dee1:
    // 0049dee1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dee3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dee5  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dee7  40                     -inc eax
    (cpu.eax)++;
    // 0049dee8  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049deea  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0049deed  39f0                   +cmp eax, esi
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
    // 0049deef  72f0                   -jb 0x49dee1
    if (cpu.flags.cf)
    {
        goto L_0x0049dee1;
    }
    // 0049def1  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0049def8  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 0049defe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049deff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49df20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049df20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049df21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049df22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049df23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049df24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049df25  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049df28  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049df2a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049df2c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049df31  88642410               -mov byte ptr [esp + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 0049df35  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049df37  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049df3b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049df3d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049df3f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049df41  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049df48  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049df4a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049df4c  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0049df4f  81fa314b0000           +cmp edx, 0x4b31
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19249 /*0x4b31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df55  0f8498000000           -je 0x49dff3
    if (cpu.flags.zf)
    {
        goto L_0x0049dff3;
    }
    // 0049df5b  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049df60  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049df62  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049df64  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049df66  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049df6d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049df6f  83c505                 -add ebp, 5
    (cpu.ebp) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x0049df72:
    // 0049df72  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049df76  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0049df79  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049df7d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049df81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049df83  7e61                   -jle 0x49dfe6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049dfe6;
    }
L_0x0049df85:
    // 0049df85  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049df88  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049df8a  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 0049df8c  80e43f                 -and ah, 0x3f
    cpu.ah &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049df8f  0fb6ec                 -movzx ebp, ah
    cpu.ebp = x86::reg32(cpu.ah);
    // 0049df92  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049df95  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049df9a  43                     -inc ebx
    (cpu.ebx)++;
    // 0049df9b  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049df9e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049dfa1  83f803                 +cmp eax, 3
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
    // 0049dfa4  7739                   -ja 0x49dfdf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049dfdf;
    }
    // 0049dfa6  ff248510df4900         -jmp dword ptr [eax*4 + 0x49df10]
    cpu.ip = app->getMemory<x86::reg32>(4841232 + cpu.eax * 4); goto dynamic_jump;
  case 0x0049dfad:
    // 0049dfad  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049dfb1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049dfb3  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049dfb5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049dfb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dfba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049dfbc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049dfbf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049dfc1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049dfc3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049dfc6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049dfc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfc9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049dfcd  8d3c2b                 -lea edi, [ebx + ebp]
    cpu.edi = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0049dfd0  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049dfd2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049dfd5  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049dfd7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049dfdb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049dfdf:
    // 0049dfdf  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0049dfe4  7f9f                   -jg 0x49df85
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049df85;
    }
L_0x0049dfe6:
    // 0049dfe6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfea  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049dfed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dfef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dff2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dff3:
    // 0049dff3  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049dff8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049dffa  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049dffc  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049dffe  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049e005  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049e007  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e00a  e963ffffff             -jmp 0x49df72
    goto L_0x0049df72;
  case 0x0049e00f:
    // 0049e00f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049e011  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e014  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 0049e018  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
  [[fallthrough]];
  case 0x0049e01b:
    // 0049e01b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e01f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e021  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049e023  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e027  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e02b  e88f61feff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 0049e030  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e034  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e036  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e038  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049e03c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049e040  eb9d                   -jmp 0x49dfdf
    goto L_0x0049dfdf;
  case 0x0049e042:
    // 0049e042  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e046  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e049  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049e04b  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0049e04e  8d7a01                 -lea edi, [edx + 1]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e051  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 0049e053  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e057  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0049e05a  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049e05e  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e060  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049e061  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049e065  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e067  0f8e72ffffff           -jle 0x49dfdf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049dfdf;
    }
L_0x0049e06d:
    // 0049e06d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e070  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0049e072  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e074  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e076  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049e078  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e07a  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0049e07d  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e07f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e083  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e087  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049e088  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0049e08a  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e08d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e08e  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e08f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049e093  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049e096  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e098  7e0e                   -jle 0x49e0a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e0a8;
    }
    // 0049e09a  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049e09c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e09f  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049e0a0  08e0                   -or al, ah
    cpu.al |= x86::reg8(x86::sreg8(cpu.ah));
    // 0049e0a2  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049e0a6  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
L_0x0049e0a8:
    // 0049e0a8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e0aa  7fc1                   -jg 0x49e06d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e06d;
    }
    // 0049e0ac  e92effffff             -jmp 0x49dfdf
    goto L_0x0049dfdf;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49e0b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e0b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e0b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e0b7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e0ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e0bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e0bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e0bd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049e0bf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e0c1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049e0c3  c745fc00000000         -mov dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 0049e0ca  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049e0cc  0f84d8000000           -je 0x49e1aa
    if (cpu.flags.zf)
    {
        return sub_49e1aa(app, cpu);
    }
    // 0049e0d2  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049e0d5  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e0d8  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0049e0da  7403                   -je 0x49e0df
    if (cpu.flags.zf)
    {
        goto L_0x0049e0df;
    }
    // 0049e0dc  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
L_0x0049e0df:
    // 0049e0df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e0e1  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049e0e3  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049e0e6  8a6301                 -mov ah, byte ptr [ebx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e0e9  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e0ec  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e0ef  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049e0f2  83f900                 +cmp ecx, 0
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
    // 0049e0f5  0f84af000000           -je 0x49e1aa
    if (cpu.flags.zf)
    {
        return sub_49e1aa(app, cpu);
    }
    // 0049e0fb  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049e0fd  eb46                   -jmp 0x49e145
    return sub_49e145(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_49e100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0049e100:
    // 0049e100  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e103  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e105  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e107  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e109  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e10b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e10e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e111  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e114  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e116  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e11a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e11d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e11f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e121  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e123  7826                   -js 0x49e14b
    if (cpu.flags.sf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e125:
    // 0049e125  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049e128  75d6                   -jne 0x49e100
    if (!cpu.flags.zf)
    {
        goto L_0x0049e100;
    }
    // 0049e12a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e12d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e12f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e131  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e134  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e137  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e13a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e13c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e140  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e143  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e145  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e147  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e149  79da                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
L_0x0049e14b:
    // 0049e14b  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e14d  7831                   -js 0x49e180
    if (cpu.flags.sf)
    {
        goto L_0x0049e180;
    }
    // 0049e14f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e151  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e154  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0049e157  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e15a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e15c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e15e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e160  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049e163  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 0049e165  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049e168  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e16a  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e16e  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049e171  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049e174  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e176  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e178  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e17a  79a9                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e17c  ebcd                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e17e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e180:
    // 0049e180  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e182  7930                   -jns 0x49e1b4
    if (!cpu.flags.sf)
    {
        goto L_0x0049e1b4;
    }
    // 0049e184  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e187  7317                   -jae 0x49e1a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049e1a0;
    }
    // 0049e189  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049e18c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e18f  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e192  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e194  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e196  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0049e198  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e19a  7989                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e19c  ebad                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e19e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e1a0:
    // 0049e1a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1a2  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e1a5  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1b4:
    // 0049e1b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1b6  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e1b9  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1bc  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1be  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e1c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1c4  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1c7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049e1ca  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0049e1cd  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e1cf  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 0049e1d1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e1d3  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e1d7  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0049e1da  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 0049e1dd  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0049e1e3  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1e6  7d24                   -jge 0x49e20c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49e20c(app, cpu);
    }
    // 0049e1e8  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1eb  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e1f1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1f4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e1f6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1f8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1fa  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e1fc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e1fe  0f8921ffffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e204  e942ffffff             -jmp 0x49e14b
    goto L_0x0049e14b;
}

/* align: skip  */
void Application::sub_49e14b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e14b;
L_0x0049e100:
    // 0049e100  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e103  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e105  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e107  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e109  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e10b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e10e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e111  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e114  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e116  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e11a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e11d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e11f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e121  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e123  7826                   -js 0x49e14b
    if (cpu.flags.sf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e125:
    // 0049e125  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049e128  75d6                   -jne 0x49e100
    if (!cpu.flags.zf)
    {
        goto L_0x0049e100;
    }
    // 0049e12a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e12d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e12f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e131  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e134  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e137  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e13a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e13c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e140  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e143  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e145  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e147  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e149  79da                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
L_0x0049e14b:
L_entry_0x0049e14b:
    // 0049e14b  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e14d  7831                   -js 0x49e180
    if (cpu.flags.sf)
    {
        goto L_0x0049e180;
    }
    // 0049e14f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e151  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e154  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0049e157  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e15a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e15c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e15e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e160  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049e163  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 0049e165  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049e168  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e16a  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e16e  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049e171  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049e174  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e176  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e178  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e17a  79a9                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e17c  ebcd                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e17e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e180:
    // 0049e180  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e182  7930                   -jns 0x49e1b4
    if (!cpu.flags.sf)
    {
        goto L_0x0049e1b4;
    }
    // 0049e184  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e187  7317                   -jae 0x49e1a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049e1a0;
    }
    // 0049e189  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049e18c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e18f  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e192  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e194  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e196  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0049e198  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e19a  7989                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e19c  ebad                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e19e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e1a0:
    // 0049e1a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1a2  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e1a5  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1b4:
    // 0049e1b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1b6  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e1b9  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1bc  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1be  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e1c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1c4  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1c7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049e1ca  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0049e1cd  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e1cf  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 0049e1d1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e1d3  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e1d7  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0049e1da  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 0049e1dd  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0049e1e3  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1e6  7d24                   -jge 0x49e20c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49e20c(app, cpu);
    }
    // 0049e1e8  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1eb  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e1f1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1f4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e1f6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1f8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1fa  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e1fc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e1fe  0f8921ffffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e204  e942ffffff             -jmp 0x49e14b
    goto L_0x0049e14b;
}

/* align: skip  */
void Application::sub_49e145(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e145;
L_0x0049e100:
    // 0049e100  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e103  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e105  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e107  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e109  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e10b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e10e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e111  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e114  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e116  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e11a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e11d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e11f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e121  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e123  7826                   -js 0x49e14b
    if (cpu.flags.sf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e125:
    // 0049e125  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049e128  75d6                   -jne 0x49e100
    if (!cpu.flags.zf)
    {
        goto L_0x0049e100;
    }
    // 0049e12a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e12d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e12f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e131  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e134  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e137  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e13a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e13c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e140  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e143  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
L_entry_0x0049e145:
    // 0049e145  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e147  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e149  79da                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
L_0x0049e14b:
    // 0049e14b  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e14d  7831                   -js 0x49e180
    if (cpu.flags.sf)
    {
        goto L_0x0049e180;
    }
    // 0049e14f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e151  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e154  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0049e157  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e15a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e15c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e15e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e160  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049e163  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 0049e165  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049e168  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e16a  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e16e  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049e171  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049e174  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e176  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e178  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e17a  79a9                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e17c  ebcd                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e17e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e180:
    // 0049e180  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e182  7930                   -jns 0x49e1b4
    if (!cpu.flags.sf)
    {
        goto L_0x0049e1b4;
    }
    // 0049e184  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e187  7317                   -jae 0x49e1a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049e1a0;
    }
    // 0049e189  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049e18c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e18f  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e192  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e194  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e196  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0049e198  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e19a  7989                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e19c  ebad                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e19e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e1a0:
    // 0049e1a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1a2  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e1a5  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1b4:
    // 0049e1b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1b6  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e1b9  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1bc  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1be  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e1c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1c4  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1c7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049e1ca  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0049e1cd  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e1cf  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 0049e1d1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e1d3  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e1d7  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0049e1da  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 0049e1dd  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0049e1e3  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1e6  7d24                   -jge 0x49e20c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49e20c(app, cpu);
    }
    // 0049e1e8  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1eb  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e1f1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1f4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e1f6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1f8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1fa  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e1fc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e1fe  0f8921ffffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e204  e942ffffff             -jmp 0x49e14b
    goto L_0x0049e14b;
}

/* align: skip  */
void Application::sub_49e1aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e1aa;
L_0x0049e100:
    // 0049e100  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e103  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e105  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e107  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e109  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e10b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e10e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e111  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e114  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e116  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e11a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e11d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e11f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e121  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e123  7826                   -js 0x49e14b
    if (cpu.flags.sf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e125:
    // 0049e125  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049e128  75d6                   -jne 0x49e100
    if (!cpu.flags.zf)
    {
        goto L_0x0049e100;
    }
    // 0049e12a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e12d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e12f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e131  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e134  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e137  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e13a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e13c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e140  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e143  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e145  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e147  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e149  79da                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
L_0x0049e14b:
    // 0049e14b  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e14d  7831                   -js 0x49e180
    if (cpu.flags.sf)
    {
        goto L_0x0049e180;
    }
    // 0049e14f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e151  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e154  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0049e157  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e15a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e15c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e15e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e160  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049e163  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 0049e165  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049e168  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e16a  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e16e  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049e171  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049e174  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e176  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e178  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e17a  79a9                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e17c  ebcd                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e17e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e180:
    // 0049e180  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e182  7930                   -jns 0x49e1b4
    if (!cpu.flags.sf)
    {
        goto L_0x0049e1b4;
    }
    // 0049e184  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e187  7317                   -jae 0x49e1a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049e1a0;
    }
    // 0049e189  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049e18c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e18f  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e192  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e194  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e196  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0049e198  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e19a  7989                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e19c  ebad                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e19e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e1a0:
    // 0049e1a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1a2  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e1a5  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
L_entry_0x0049e1aa:
    // 0049e1aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1b4:
    // 0049e1b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1b6  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e1b9  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1bc  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1be  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e1c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1c4  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1c7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049e1ca  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0049e1cd  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e1cf  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 0049e1d1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e1d3  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e1d7  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0049e1da  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 0049e1dd  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0049e1e3  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1e6  7d24                   -jge 0x49e20c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49e20c(app, cpu);
    }
    // 0049e1e8  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1eb  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e1f1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1f4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e1f6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1f8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1fa  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e1fc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e1fe  0f8921ffffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e204  e942ffffff             -jmp 0x49e14b
    goto L_0x0049e14b;
}

/* align: skip  */
void Application::sub_49e125(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e125;
L_0x0049e100:
    // 0049e100  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e103  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e105  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e107  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e109  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e10b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e10e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e111  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e114  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e116  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e11a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e11d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e11f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e121  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e123  7826                   -js 0x49e14b
    if (cpu.flags.sf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e125:
L_entry_0x0049e125:
    // 0049e125  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049e128  75d6                   -jne 0x49e100
    if (!cpu.flags.zf)
    {
        goto L_0x0049e100;
    }
    // 0049e12a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0049e12d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 0049e12f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e131  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049e134  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 0049e137  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0049e13a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e13c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e140  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0049e143  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e145  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e147  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e149  79da                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
L_0x0049e14b:
    // 0049e14b  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e14d  7831                   -js 0x49e180
    if (cpu.flags.sf)
    {
        goto L_0x0049e180;
    }
    // 0049e14f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0049e151  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0049e154  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0049e157  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e15a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e15c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e15e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e160  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049e163  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 0049e165  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049e168  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e16a  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e16e  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049e171  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049e174  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e176  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e178  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e17a  79a9                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e17c  ebcd                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e17e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e180:
    // 0049e180  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e182  7930                   -jns 0x49e1b4
    if (!cpu.flags.sf)
    {
        goto L_0x0049e1b4;
    }
    // 0049e184  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e187  7317                   -jae 0x49e1a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049e1a0;
    }
    // 0049e189  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049e18c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e18f  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049e192  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e194  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e196  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0049e198  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e19a  7989                   -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e19c  ebad                   -jmp 0x49e14b
    goto L_0x0049e14b;
    // 0049e19e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049e1a0:
    // 0049e1a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1a2  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049e1a5  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1a8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e1b4:
    // 0049e1b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1b6  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e1b9  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1bc  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1be  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049e1c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e1c4  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1c7  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0049e1ca  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 0049e1cd  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0049e1cf  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 0049e1d1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049e1d3  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0049e1d7  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0049e1da  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 0049e1dd  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 0049e1e3  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1e6  7d24                   -jge 0x49e20c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49e20c(app, cpu);
    }
    // 0049e1e8  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1eb  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e1ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e1f1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e1f4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e1f6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049e1f8  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e1fa  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e1fc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e1fe  0f8921ffffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        goto L_0x0049e125;
    }
    // 0049e204  e942ffffff             -jmp 0x49e14b
    goto L_0x0049e14b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e20c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e20c  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 0049e20f  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 0049e211  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0049e213  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e215  0f890affffff           -jns 0x49e125
    if (!cpu.flags.sf)
    {
        return sub_49e125(app, cpu);
    }
    // 0049e21b  e92bffffff             -jmp 0x49e14b
    return sub_49e14b(app, cpu);
}

/* align: skip  */
void Application::sub_49e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e221  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0049e222:
    // 0049e222  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e224  8b0d202c5400           -mov ecx, dword ptr [0x542c20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5516320) /* 0x542c20 */);
    // 0049e22a  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049e22c  803c1100               +cmp byte ptr [ecx + edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e230  7513                   -jne 0x49e245
    if (!cpu.flags.zf)
    {
        goto L_0x0049e245;
    }
    // 0049e232  8b15102c5400           -mov edx, dword ptr [0x542c10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */);
    // 0049e238  42                     -inc edx
    (cpu.edx)++;
    // 0049e239  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0049e23c  8915102c5400           -mov dword ptr [0x542c10], edx
    app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */) = cpu.edx;
    // 0049e242  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e243  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e245:
    // 0049e245  a1142c5400             -mov eax, dword ptr [0x542c14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516308) /* 0x542c14 */);
    // 0049e24a  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049e24d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e252  e8c9ffffff             -call 0x49e220
    cpu.esp -= 4;
    sub_49e220(app, cpu);
    if (cpu.terminate) return;
    // 0049e257  a11c2c5400             -mov eax, dword ptr [0x542c1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516316) /* 0x542c1c */);
    // 0049e25c  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049e25f  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e264  ebbc                   -jmp 0x49e222
    goto L_0x0049e222;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e268(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e268  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e269  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e26a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e26b  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0049e271  8915102c5400           -mov dword ptr [0x542c10], edx
    app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */) = cpu.edx;
    // 0049e277  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e279  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 0049e280  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049e287  8915202c5400           -mov dword ptr [0x542c20], edx
    app->getMemory<x86::reg32>(x86::reg32(5516320) /* 0x542c20 */) = cpu.edx;
    // 0049e28d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049e28f  8915142c5400           -mov dword ptr [0x542c14], edx
    app->getMemory<x86::reg32>(x86::reg32(5516308) /* 0x542c14 */) = cpu.edx;
    // 0049e295  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0049e29c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e29e  89151c2c5400           -mov dword ptr [0x542c1c], edx
    app->getMemory<x86::reg32>(x86::reg32(5516316) /* 0x542c1c */) = cpu.edx;
    // 0049e2a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e2a6  0f8445010000           -je 0x49e3f1
    if (cpu.flags.zf)
    {
        goto L_0x0049e3f1;
    }
    // 0049e2ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2ae  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049e2b1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049e2b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2b5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049e2b8  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e2ba  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2bc  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e2bd  81fafb470000           +cmp edx, 0x47fb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18427 /*0x47fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e2c3  0f84d0000000           -je 0x49e399
    if (cpu.flags.zf)
    {
        goto L_0x0049e399;
    }
L_0x0049e2c9:
    // 0049e2c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2cd  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e2cf  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049e2d2  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0049e2d9  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049e2dc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2de  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0049e2e5  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e2e6  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0049e2ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2ef  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049e2f2  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049e2f5  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e2f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2f8  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e2f9  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 0049e300  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e302:
    // 0049e302  a1202c5400             -mov eax, dword ptr [0x542c20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516320) /* 0x542c20 */);
    // 0049e307  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049e30a  42                     -inc edx
    (cpu.edx)++;
    // 0049e30b  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0049e30e  81fa00010000           +cmp edx, 0x100
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
    // 0049e314  7cec                   -jl 0x49e302
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e302;
    }
    // 0049e316  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e317  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e318  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e319  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e31b  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049e31e  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e31f  c6040201               -mov byte ptr [edx + eax], 1
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 1 /*0x1*/;
    // 0049e323  0fb669ff               -movzx ebp, byte ptr [ecx - 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 0049e327  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e329  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e32b  7e37                   -jle 0x49e364
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e364;
    }
L_0x0049e32d:
    // 0049e32d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e32f  8b1d142c5400           -mov ebx, dword ptr [0x542c14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5516308) /* 0x542c14 */);
    // 0049e335  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e337  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049e33a  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0049e33d  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e340  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e342  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e344  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0049e346  8b3d1c2c5400           -mov edi, dword ptr [0x542c1c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5516316) /* 0x542c1c */);
    // 0049e34c  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e34e  881c3a                 -mov byte ptr [edx + edi], bl
    app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1) = cpu.bl;
    // 0049e351  8b1d202c5400           -mov ebx, dword ptr [0x542c20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5516320) /* 0x542c20 */);
    // 0049e357  40                     -inc eax
    (cpu.eax)++;
    // 0049e358  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e359  c6041aff               -mov byte ptr [edx + ebx], 0xff
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 255 /*0xff*/;
    // 0049e35d  39e8                   +cmp eax, ebp
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
    // 0049e35f  7ccc                   -jl 0x49e32d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e32d;
    }
    // 0049e361  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049e364:
    // 0049e364  890d182c5400           -mov dword ptr [0x542c18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */) = cpu.ecx;
    // 0049e36a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e36b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e36c:
    // 0049e36c  8b0d182c5400           -mov ecx, dword ptr [0x542c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */);
    // 0049e372  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e374  a1202c5400             -mov eax, dword ptr [0x542c20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516320) /* 0x542c20 */);
    // 0049e379  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e37b  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049e37e  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e37f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0049e381  751e                   -jne 0x49e3a1
    if (!cpu.flags.zf)
    {
        goto L_0x0049e3a1;
    }
    // 0049e383  a1102c5400             -mov eax, dword ptr [0x542c10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */);
    // 0049e388  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e389  890d182c5400           -mov dword ptr [0x542c18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */) = cpu.ecx;
    // 0049e38f  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0049e392  a3102c5400             -mov dword ptr [0x542c10], eax
    app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */) = cpu.eax;
    // 0049e397  ebd3                   -jmp 0x49e36c
    goto L_0x0049e36c;
L_0x0049e399:
    // 0049e399  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e39c  e928ffffff             -jmp 0x49e2c9
    goto L_0x0049e2c9;
L_0x0049e3a1:
    // 0049e3a1  890d182c5400           -mov dword ptr [0x542c18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */) = cpu.ecx;
    // 0049e3a7  7c1f                   -jl 0x49e3c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e3c8;
    }
    // 0049e3a9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e3ab  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e3ad  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e3ae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e3b0  743f                   -je 0x49e3f1
    if (cpu.flags.zf)
    {
        goto L_0x0049e3f1;
    }
    // 0049e3b2  a1102c5400             -mov eax, dword ptr [0x542c10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */);
    // 0049e3b7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e3b8  890d182c5400           -mov dword ptr [0x542c18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */) = cpu.ecx;
    // 0049e3be  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0049e3c1  a3102c5400             -mov dword ptr [0x542c10], eax
    app->getMemory<x86::reg32>(x86::reg32(5516304) /* 0x542c10 */) = cpu.eax;
    // 0049e3c6  eba4                   -jmp 0x49e36c
    goto L_0x0049e36c;
L_0x0049e3c8:
    // 0049e3c8  a1142c5400             -mov eax, dword ptr [0x542c14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516308) /* 0x542c14 */);
    // 0049e3cd  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049e3d0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e3d5  e846feffff             -call 0x49e220
    cpu.esp -= 4;
    sub_49e220(app, cpu);
    if (cpu.terminate) return;
    // 0049e3da  a11c2c5400             -mov eax, dword ptr [0x542c1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516316) /* 0x542c1c */);
    // 0049e3df  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049e3e2  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e3e7  e834feffff             -call 0x49e220
    cpu.esp -= 4;
    sub_49e220(app, cpu);
    if (cpu.terminate) return;
    // 0049e3ec  e97bffffff             -jmp 0x49e36c
    goto L_0x0049e36c;
L_0x0049e3f1:
    // 0049e3f1  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0049e3f8  890d182c5400           -mov dword ptr [0x542c18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516312) /* 0x542c18 */) = cpu.ecx;
    // 0049e3fe  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0049e404  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e405  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e406  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e407  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e413  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e414  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e415  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e418  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049e41a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e41c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e41e  0f8ee6000000           -jle 0x49e50a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e50a;
    }
L_0x0049e424:
    // 0049e424  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e427  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e429  0f8ee2000000           -jle 0x49e511
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e511;
    }
L_0x0049e42f:
    // 0049e42f  39d1                   +cmp ecx, edx
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
    // 0049e431  7e0d                   -jle 0x49e440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e440;
    }
    // 0049e433  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e436  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e438  0f8eda000000           -jle 0x49e518
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e518;
    }
    // 0049e43e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0049e440:
    // 0049e440  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049e443  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e445  0f8ed6000000           -jle 0x49e521
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e521;
    }
    // 0049e44b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x0049e44d:
    // 0049e44d  39d1                   +cmp ecx, edx
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
    // 0049e44f  7e0d                   -jle 0x49e45e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e45e;
    }
    // 0049e451  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049e454  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e456  0f8ece000000           -jle 0x49e52a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e52a;
    }
    // 0049e45c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x0049e45e:
    // 0049e45e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e460  0f84cd000000           -je 0x49e533
    if (cpu.flags.zf)
    {
        goto L_0x0049e533;
    }
    // 0049e466  81fa00008000           +cmp edx, 0x800000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388608 /*0x800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e46c  0f8ed6000000           -jle 0x49e548
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e548;
    }
    // 0049e472  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0049e477  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0049e47a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x0049e47d:
    // 0049e47d  81fa00002000           +cmp edx, 0x200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2097152 /*0x200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e483  7e0c                   -jle 0x49e491
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e491;
    }
    // 0049e485  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e488  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e48b  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0049e48e  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
L_0x0049e491:
    // 0049e491  81fa00001000           +cmp edx, 0x100000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048576 /*0x100000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e497  7e0c                   -jle 0x49e4a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e4a5;
    }
    // 0049e499  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e49c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e49f  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0049e4a2  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
L_0x0049e4a5:
    // 0049e4a5  81fa00800000           +cmp edx, 0x8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e4ab  7e04                   -jle 0x49e4b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e4b1;
    }
    // 0049e4ad  83042402               -add dword ptr [esp], 2
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049e4b1:
    // 0049e4b1  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049e4b4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e4b6  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0049e4b8  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0049e4ba  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e4bd  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0049e4bf  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e4c2  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049e4c5  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049e4c7  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049e4ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e4cc  e89fba0000             -call 0x4a9f70
    cpu.esp -= 4;
    sub_4a9f70(app, cpu);
    if (cpu.terminate) return;
    // 0049e4d1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e4d3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e4d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e4d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e4da  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049e4dd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049e4df  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e4e2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e4e5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049e4e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e4e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049e4ec  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049e4ee  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049e4f1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049e4f4  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049e4f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e4f9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049e4fc  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049e4fe  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049e501  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e504  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e505  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e506  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e507  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e508  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e509  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e50a:
    // 0049e50a  f7da                   +neg edx
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
    // 0049e50c  e913ffffff             -jmp 0x49e424
    goto L_0x0049e424;
L_0x0049e511:
    // 0049e511  f7d9                   +neg ecx
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
    // 0049e513  e917ffffff             -jmp 0x49e42f
    goto L_0x0049e42f;
L_0x0049e518:
    // 0049e518  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049e51a  f7da                   +neg edx
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
    // 0049e51c  e91fffffff             -jmp 0x49e440
    goto L_0x0049e440;
L_0x0049e521:
    // 0049e521  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049e523  f7d9                   +neg ecx
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
    // 0049e525  e923ffffff             -jmp 0x49e44d
    goto L_0x0049e44d;
L_0x0049e52a:
    // 0049e52a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049e52c  f7da                   +neg edx
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
    // 0049e52e  e92bffffff             -jmp 0x49e45e
    goto L_0x0049e45e;
L_0x0049e533:
    // 0049e533  c70300000100           -mov dword ptr [ebx], 0x10000
    app->getMemory<x86::reg32>(cpu.ebx) = 65536 /*0x10000*/;
    // 0049e539  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049e53c  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e53f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e542  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e543  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e544  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e545  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e546  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e547  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e548:
    // 0049e548  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049e54a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049e54d  e92bffffff             -jmp 0x49e47d
    goto L_0x0049e47d;
}

/* align: skip  */
void Application::sub_49e552(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e552  e97aba0000             -jmp 0x4a9fd1
    return sub_4a9fd1(app, cpu);
}

/* align: skip  */
void Application::sub_49e557(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e557  803d68c84c0000         +cmp byte ptr [0x4cc868], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5032040) /* 0x4cc868 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e55e  741a                   -je 0x49e57a
    if (cpu.flags.zf)
    {
        goto L_0x0049e57a;
    }
    // 0049e560  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0049e566  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e567  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e568  cc                     -int3 
    NFS2_ASSERT(false);
    // 0049e569  eb06                   -jmp 0x49e571
    goto L_0x0049e571;
    // 0049e56b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e56c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e56d  49                     -dec ecx
    (cpu.ecx)--;
    // 0049e56e  44                     -inc esp
    (cpu.esp)++;
    // 0049e56f  45                     -inc ebp
    (cpu.ebp)++;
    // 0049e570  4f                     -dec edi
    (cpu.edi)--;
L_0x0049e571:
    // 0049e571  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e576  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e57a:
    // 0049e57a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e57c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e57d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e57d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e57e  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e584  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e586  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e588  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049e58a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e58b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e58c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e58c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e58d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e58d  87442404               -xchg dword ptr [esp + 4], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049e591  e807000000             -call 0x49e59d
    cpu.esp -= 4;
    sub_49e59d(app, cpu);
    if (cpu.terminate) return;
    // 0049e596  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e59a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49e59d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e59d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e59e  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5a0  731a                   -jae 0x49e5bc
    if (!cpu.flags.cf)
    {
        goto L_0x0049e5bc;
    }
    // 0049e5a2  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 0049e5a4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049e5a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e5a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5a8  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e5ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e5b0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5b1  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5b4  7606                   -jbe 0x49e5bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e5bc;
    }
    // 0049e5b6  e811000000             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 0049e5bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e5bc:
    // 0049e5bc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5bd  b86cc84c00             -mov eax, 0x4cc86c
    cpu.eax = 5032044 /*0x4cc86c*/;
    // 0049e5c2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e5c7  e865ba0000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
    // 0049e5cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e5ce  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e5d2  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x0049e5d7:
    // 0049e5d7  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 0049e5da  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0049e5e0  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e5e5  7ff0                   -jg 0x49e5d7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e5d7;
    }
    // 0049e5e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5e8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5e9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49e5cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e5cc;
    // 0049e59d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e59e  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5a0  731a                   -jae 0x49e5bc
    if (!cpu.flags.cf)
    {
        goto L_0x0049e5bc;
    }
    // 0049e5a2  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 0049e5a4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049e5a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e5a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5a8  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e5ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e5b0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5b1  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5b4  7606                   -jbe 0x49e5bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e5bc;
    }
    // 0049e5b6  e811000000             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 0049e5bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e5bc:
    // 0049e5bc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5bd  b86cc84c00             -mov eax, 0x4cc86c
    cpu.eax = 5032044 /*0x4cc86c*/;
    // 0049e5c2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e5c7  e865ba0000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
L_entry_0x0049e5cc:
    // 0049e5cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e5ce  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e5d2  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x0049e5d7:
    // 0049e5d7  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 0049e5da  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0049e5e0  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e5e5  7ff0                   -jg 0x49e5d7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e5d7;
    }
    // 0049e5e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5e8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5e9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49e5ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e5ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5ed  e8daffffff             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 0049e5f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e5f3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e5f7  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e5fa  94                     -xchg esp, eax
    {
        x86::reg32 tmp = cpu.esp;
        cpu.esp = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049e5fb  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e5fe  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_49e600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e600  ff1580c84c00           -call dword ptr [0x4cc880]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032064) /* 0x4cc880 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e606  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e607  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049e60c  b820f54b00             -mov eax, 0x4bf520
    cpu.eax = 4977952 /*0x4bf520*/;
    // 0049e611  e81bba0000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
    // 0049e616  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e606(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e606;
    // 0049e600  ff1580c84c00           -call dword ptr [0x4cc880]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032064) /* 0x4cc880 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x0049e606:
    // 0049e606  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e607  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049e60c  b820f54b00             -mov eax, 0x4bf520
    cpu.eax = 4977952 /*0x4bf520*/;
    // 0049e611  e81bba0000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
    // 0049e616  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e618  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e61a  0f85c0c3ffff           -jne 0x49a9e0
    if (!cpu.flags.zf)
    {
        return sub_49a9e0(app, cpu);
    }
    // 0049e620  e8eeb40000             -call 0x4a9b13
    cpu.esp -= 4;
    sub_4a9b13(app, cpu);
    if (cpu.terminate) return;
    // 0049e625  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e627  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
